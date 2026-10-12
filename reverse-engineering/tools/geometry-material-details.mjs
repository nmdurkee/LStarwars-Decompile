// Additional source-derived shader settings, separate from approximate glTF PBR.
// Original bytes/ranges are retained so interpretations can be revised.
import fs from 'node:fs/promises';import path from 'node:path';import crypto from 'node:crypto';
const root=path.resolve('reverse-engineering'),idx=JSON.parse(await fs.readFile(path.join(root,'reports/geometry-scene-data-index.json'),'utf8'));
const rows=[],errors=[],blendCounts={},surfaceCounts={},strideCounts={};let materialCount=0;
for(let row of idx.rows){
  let handle;
  try{
    const scene=JSON.parse(await fs.readFile(path.join(root,row.report),'utf8')),materials=[];
    if(scene.materials.length){
      const first=scene.materials[0],last=scene.materials.at(-1),offset=first.address,size=last.address+last.recordSize-offset;
      handle=await fs.open(path.join(root,'extracted',row.source),'r');let data=Buffer.alloc(size);const read=await handle.read(data,0,size,offset);if(read.bytesRead!==size)throw Error('Truncated material records');await handle.close();handle=null;
      for(let m of scene.materials){let b=data.subarray(m.address-offset,m.address-offset+m.recordSize),alpha=m.alpha,bits=m.shaderFlags;
        const blend={0:'none',1:'source-alpha over',2:'source-alpha additive',3:'reverse subtract',10:'fixed alpha test'}[alpha&15]??'unknown';
        const surface=bits===null?'unknown':bits&2?'parallax':bits&1?'normal map':'smooth';
        blendCounts[blend]=(blendCounts[blend]??0)+1;surfaceCounts[surface]=(surfaceCounts[surface]??0)+1;strideCounts[m.recordSize]=(strideCounts[m.recordSize]??0)+1;
        const float=p=>{let value=b.readFloatLE(p);return Number.isFinite(value)?value:{rawFloatBits:b.readUInt32LE(p),nonfinite:true};};
        materials.push({...m,recordSHA256:crypto.createHash('sha256').update(b).digest('hex'),rawRecordBase64:b.toString('base64'),additionalParameters:{reflectionPower:float(0x12c),specularExponent:float(0x130),fresnelMultiplier:float(0x144),fresnelCoefficient:float(0x148),vertexFormatBits2:b.readUInt32LE(0x1f4),uvSetIndices:{lightmap:b[0x15c],surface:b[0x15d],specular:b[0x15e],layer1:b[0x15f],layer2:b[0x160],layer3:b[0x161],vertexFetch:b[0x162]}},referenceInterpretation:{blend,blendCode:alpha&15,depth:['normal','no depth write','always pass','ignore depth'][(alpha>>>14)&3],surface,additionalLayers:bits===null?null:[!!(bits&0x40),!!(bits&0x80),!!(bits&0x100)],fresnel:bits===null?null:!!(bits&4),specularOrReflective:bits===null?null:!!(bits&0x18),refraction:bits===null?null:!!(bits&0x400),lighting:bits===null?'unknown':bits&0x1000?(bits&0x80000000?bits&8?'prelit phong':'prelit lambert':'disabled'):bits&0x20000?'gooch':bits&0x80000?'environment':bits&16?'anisotropic':bits&8?'phong':'lambert'}});
      }
    }
    let output=path.join(root,'reports/geometry-material-data',row.source+'.json');await fs.mkdir(path.dirname(output),{recursive:true});await fs.writeFile(output,JSON.stringify({source:row.source,sourceSHA256:row.sha256,evidence:'Offsets and interpretation from BrickBench MaterialBlock.java/FileMaterial.java, commit 3d149673e1f70dc04425ff30fcc00ec2194d2743. PC record ranges and material declarations validated separately. Shader labels remain reference-derived; UV indices +0x15c..+0x162 are corrected using native current-layout feature-builder evidence. See geometry-material-shader-map.json for original PC semantics.',materials},null,2));
    materialCount+=materials.length;rows.push({source:row.source,materials:materials.length,report:path.relative(root,output)});
  }catch(e){errors.push({source:row.source,error:e.message});}finally{if(handle)await handle.close();}
  if((rows.length+errors.length)%100===0)console.log(JSON.stringify({files:rows.length,materials:materialCount,errors:errors.length}));
}
await fs.writeFile(path.join(root,'reports/geometry-material-data-index.json'),JSON.stringify({files:rows.length,materialCount,blendCounts,surfaceCounts,strideCounts,rows,errors},null,2));console.log(JSON.stringify({files:rows.length,materialCount,blendCounts,surfaceCounts,strideCounts,errors},null,2));
