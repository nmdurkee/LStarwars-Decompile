// Decode remaining texture-animation/descriptor tables and preserve auxiliary
// runtime chunks with exact bytes; unknown semantics are not guessed.
import fs from 'node:fs/promises';import path from 'node:path';import crypto from 'node:crypto';
import {readRenderState} from './geometry-render-state.mjs';
const root=path.resolve('reverse-engineering'),idx=JSON.parse(await fs.readFile(path.join(root,'reports/geometry-scene-data-index.json'),'utf8'));
const programs=JSON.parse(await fs.readFile(path.join(root,'reports/geometry-texture-programs.json'),'utf8')).programs,byProgram=new Map(programs.map(p=>[p.name.toLowerCase(),p]));
const rows=[],errors=[],programCounts={},auxiliaryCounts={};let totalAnimations=0,frameReferences=0,linked=0,descriptors=0,negativeWidths=0,negativeWidthCubeMatches=0;
for(let row of idx.rows){let handle;
  try{
    const scene=JSON.parse(await fs.readFile(path.join(root,row.report),'utf8'));handle=await fs.open(path.join(root,'extracted',row.source),'r');
    async function read(p,size){if(!Number.isInteger(p)||!Number.isInteger(size)||p<0||size<0||p+size>scene.bytes)throw Error('Scene runtime read outside source bounds');let b=Buffer.alloc(size);let r=await handle.read(b,0,size,p);if(r.bytesRead!==size)throw Error('Truncated scene read');return b;}
    const header=await read(scene.header,0x70),count=header.readUInt32LE(0x60),ap=header.readInt32LE(0x64)?scene.header+0x64+header.readInt32LE(0x64):0,tp=header.readInt32LE(0x68)?scene.header+0x68+header.readInt32LE(0x68):0;
    let textureAnimations=[],declaredFrameTableCount=0;
    if(count){
      let tas=scene.chunks.find(c=>c.tag==='TAS0');if(!tas||ap<tas.payload||ap+count*32>tas.offset+tas.size)throw Error('Animation records exceed TAS0');
      const data=await read(tas.offset,tas.size),offset=ap-tas.offset;
      if(tp<tas.payload+4||tp>tas.offset+tas.size)throw Error('Texture frame table outside TAS0');declaredFrameTableCount=data.readUInt32LE(tp-tas.offset-4);if(tp+declaredFrameTableCount*2>tas.offset+tas.size)throw Error('Texture frame table exceeds TAS0');
      const nc=scene.chunks.find(c=>c.tag==='NTBL'),names=await read(nc.offset,nc.size);
      const name=address=>{let p=address-nc.offset,end=names.indexOf(0,p);if(p<8||p>=names.length||end<0)throw Error('Texture animation name outside NTBL');return names.toString('utf8',p,end);};
      for(let i=0;i<count;i++){
        let p=offset+i*32,addr=ap+i*32,first=data.readUInt32LE(p+8),n=data.readInt16LE(p+12),material=data.readUInt32LE(p+16),na=addr+24+data.readInt32LE(p+24),pr=addr+28+data.readInt32LE(p+28);
        if(n<0||first+n>declaredFrameTableCount||material>=scene.materials.length)throw Error('Invalid texture animation table reference');
        let textureIDs=Array.from({length:n},(_,j)=>data.readUInt16LE(tp-tas.offset+(first+j)*2));if(textureIDs.some(t=>t>=scene.textures.length))throw Error('Texture animation selects invalid descriptor');
        const programName=name(pr),program=byProgram.get(programName.toLowerCase());
        textureAnimations.push({index:i,address:addr,name:name(na),programName,material,firstTextureIndex:first,textureIDs,rawRecord:data.subarray(p,p+32).toString('base64'),program:program?.output??null,programStatus:program?'resolved':programName?'unresolved':'empty stored program name',programMaximumTextureIndex:program?.maximumTextureIndex??null,sequenceRangeCompatible:program?program.maximumTextureIndex<n:null});
        programCounts[programName]=(programCounts[programName]??0)+1;totalAnimations++;frameReferences+=n;if(program)linked++;
      }
    }
    const tc=scene.chunks.find(c=>c.tag==='TST0'),tb=await read(tc.offset,tc.size),textureDescriptors=[];
    for(let t of scene.textures){let p=t.descriptor-tc.offset;if(p<8||p+40>tb.length)throw Error('Texture descriptor outside TST0');let d=tb.subarray(p,p+40);if(d.readUInt32LE(0)!==t.width||d.readUInt32LE(4)!==t.height)throw Error('Descriptor dimensions disagree');
      let allocation=null;
      if(t.size){const a=await read(t.allocation,24);allocation={signedWidth:a.readInt32LE(0),height:a.readInt32LE(4),rawHeader:a.toString('base64')};if(allocation.signedWidth<0){negativeWidths++;let dds=await read(t.offset,128);allocation.ddsCubemap=dds.toString('ascii',0,4)==='DDS '&&!!(dds.readUInt32LE(112)&0x200);allocation.negativeWidthMatchesCubemap=allocation.ddsCubemap&&-allocation.signedWidth===t.width;if(allocation.negativeWidthMatchesCubemap)negativeWidthCubeMatches++;}}
      textureDescriptors.push({index:t.index,address:t.descriptor,width:t.width,height:t.height,checksum:d.subarray(8,24).toString('hex'),refCount:d.readInt32LE(24),serializedImagePointerValue:d.readUInt32LE(28),serializedSize:d.readUInt32LE(32),serializedPlatformValue:d.readUInt32LE(36),rawRecord:d.toString('base64'),allocation});descriptors++;
    }
    const renderState=await readRenderState(read,scene);
    const auxiliary=[];
    for(let tag of ['FDNS','SALI','DYNO','TREF','VBIB']){let c=scene.chunks.find(c=>c.tag===tag);if(!c)continue;let data=await read(c.payload,c.size-8),allZero=data.every(n=>n===0),record={tag,address:c.payload,length:data.length,sha256:crypto.createHash('sha256').update(data).digest('hex'),rawBase64:data.toString('base64'),allZero,firstWords:Array.from({length:Math.min(16,Math.floor(data.length/4))},(_,i)=>data.readUInt32LE(i*4)),semanticStatus:tag==='FDNS'?'Decoded as per-instance fade distance pairs in renderState.instances.':tag==='SALI'?'State animation list; decoded separately by animation-scene exporter.':'Preserved exact auxiliary/runtime bytes; full field semantics unresolved.'};auxiliary.push(record);let a=auxiliaryCounts[tag]??={files:0,allZero:0,bytes:0,uniqueHashes:new Set()};a.files++;a.allZero+=allZero?1:0;a.bytes+=data.length;a.uniqueHashes.add(record.sha256);}
    const report={source:row.source,sourceSHA256:row.sha256,textureAnimations,declaredFrameTableCount,textureDescriptors,renderState,auxiliary,evidence:'TAS0 and 40-byte NUNATIVETEX records matched supplied PC offsets and OpenSaga nu3d/nutexanm.h, nutex.h; renderer relocation at legoapi/render/core/render.cpp. Unused runtime pointers are preserved raw, not followed.'};
    const out=path.join(root,'exports/geometry/scene-runtime',row.source+'.json');await fs.mkdir(path.dirname(out),{recursive:true});await fs.writeFile(out,JSON.stringify(report,null,2));rows.push({source:row.source,textureAnimations:count,textureDescriptors:textureDescriptors.length,renderInstances:renderState?.instanceCount??0,lodGroups:renderState?.lodGroups.length??0,lodGroupCountMatchesBounds:renderState?.lodGroupCountMatchesBounds??null,animatedMaterialCount:renderState?.animatedMaterials?.materialIndices.length??0,emptyProgramNames:textureAnimations.filter(x=>!x.programName).length,unresolvedPrograms:textureAnimations.filter(x=>!x.program&&x.programName).map(x=>x.programName),outOfRangePrograms:textureAnimations.filter(x=>x.sequenceRangeCompatible===false).map(x=>({name:x.programName,count:x.textureIDs.length,max:x.programMaximumTextureIndex})),report:path.relative(root,out)});
  }catch(e){errors.push({source:row.source,error:e.message});}finally{if(handle)await handle.close();}
  if((rows.length+errors.length)%100===0)console.log(JSON.stringify({files:rows.length,errors:errors.length,animations:totalAnimations}));
}
for(let a of Object.values(auxiliaryCounts))a.uniqueHashes=[...a.uniqueHashes];
const summary={files:rows.length,textureDescriptors:descriptors,textureAnimations:totalAnimations,frameReferences,linkedPrograms:linked,negativeWidths,negativeWidthCubeMatches};
await fs.writeFile(path.join(root,'reports/geometry-scene-runtime.json'),JSON.stringify({summary,programCounts,auxiliaryCounts,rows,errors},null,2));console.log(JSON.stringify({summary,errors},null,2));
