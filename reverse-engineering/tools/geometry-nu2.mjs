// Read-only Nu2 PC parser. Format references: BrickBench/BrickBench commit
// 3d149673e1f70dc04425ff30fcc00ec2194d2743, scene/SceneFileLoader.java,
// blocks/GameSceneHeaderBlock.java, MaterialBlock.java, DisplaySetBlock.java.
// Fields are checked against the supplied game carriers; no source mutations.
import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {fileURLToPath} from 'node:url';

export const identity = [1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1];
export function declaration(bits, textured=false) {
  if(textured && !(bits&0x3800)) bits=(bits&0xffffcfff)|0x800;
  const fields=[];let offset=0;
  const add=(name,type,size)=>{fields.push({name,type,offset,size});offset+=size;};
  add('position','float3',12);
  let norm=(bits&(8|0x880000))?2:(bits>>>2)&1;
  let tan=(bits&(0x20|0x1000000))?2:(bits>>>4)&1;
  let bitan=(bits&0x2000080)?2:(bits>>>6)&1;
  for(const [name,mode] of [['normal',norm],['tangent',tan],['bitangent',bitan]])
    if(mode) add(name,mode===1?'float3':'ubyte4',mode===1?12:4);
  if(bits&0x100)add('color','ubyte4',4);
  if(bits&0x600)add('color2','ubyte4',4);
  for(let i=0;i<Math.min((bits>>>11)&7,4);i++)add('uv'+i,bits&0x8000000?'half2':'float2',bits&0x8000000?4:8);
  let weight=(bits&0x8000)?2:(bits>>>14)&1;
  let bone=(bits&0x20000)?2:(bits>>>16)&1;
  if(weight)add('weights',weight===1?'float2':'ubyte4',weight===1?8:4);
  if(bone)add('joints',bone===1?'float3':'ubyte4',bone===1?12:4);
  if(bits&0x4000000){add('lightDir','ubyte4',4);add('lightColor','ubyte4',4);}
  return {bits:bits>>>0,stride:offset,fields};
}

export function parseNu2(b,source='buffer') {
  function range(p,n,label='range'){if(!Number.isInteger(p)||!Number.isInteger(n)||p<0||n<0||p+n>b.length)throw Error(`${label}: out of bounds ${p}+${n}/${b.length}`);return p;}
  const u=p=>b.readUInt32LE(range(p,4)),i=p=>b.readInt32LE(range(p,4)),s=p=>b.readUInt16LE(range(p,2)),f=p=>b.readFloatLE(range(p,4));
  const rel=p=>{let v=i(p);return v?range(p+v,0,'relative pointer'):0;};
  const mat=p=>Array.from({length:16},(_,j)=>f(p+j*4));
  const nu=u(0)+4;range(nu,32);if(b.toString('ascii',nu,nu+4)!=='NU20')throw Error('Not TCS PC NU20');
  const pn=rel(nu+24),header=rel(nu+28),relocations=new Set();
  const pnCount=u(pn);range(pn+4,pnCount*4,'PNTR list');
  // PNTR also names unused/runtime fields whose saved values are not file offsets.
  // Validate all relocation locations here and targets only when consumed.
  for(let j=0;j<pnCount;j++){const a=rel(pn+4+j*4);range(a,4,'PNTR field');relocations.add(a);}
  const ptr=p=>relocations.has(p)?rel(p):u(p);
  const chunks=[];let cursor=nu+16;
  while(cursor+8<=b.length){let tag=b.toString('ascii',cursor,cursor+4),size=u(cursor+4);if(!/^[A-Z0-9]{4}$/.test(tag)||size<8||cursor+size>b.length)break;chunks.push({tag,offset:cursor,payload:cursor+8,size});cursor+=size;}
  const chunk=tag=>{let v=chunks.find(x=>x.tag===tag);if(!v)throw Error('Required chunk '+tag+' absent from bounded chain');return v;};
  if(b.toString('ascii',header-8,header-4)!=='GSNH')throw Error('Unsupported scene header');
  const warnings=[];
  const texCount=u(header+4),texTable=ptr(header+8);range(texTable,texCount*4,'texture descriptor list');
  const textures=[];let p=6;
  for(let index=0;index<texCount;index++){
    const descriptor=ptr(texTable+index*4);range(descriptor,8);let width=u(descriptor),height=u(descriptor+4);
    const t={index,descriptor,width,height};
    if(width&&height){range(p,24,'texture allocation');let w=u(p),h=u(p+4),size=u(p+20);range(p+24,size,'texture payload');if(w!==width||h!==height)warnings.push(`Texture ${index} allocation ${w}x${h} differs from descriptor ${width}x${height}`);Object.assign(t,{allocation:p,offset:p+24,size,allocationWidth:w,allocationHeight:h,magic:b.toString('ascii',p+24,p+28)});p+=24+size;}
    textures.push(t);
  }
  const readBuffers=label=>{let count=s(p);p+=2;let a=[];for(let index=0;index<count;index++){let size=u(p);range(p+4,size,label);a.push({index,offset:p+4,size});p+=size+4;}return a;};
  const vertexBuffers=readBuffers('vertex buffer'),indexBuffers=readBuffers('index buffer');
  if(p>nu)throw Error(`Binary data exceeds NU20: ${p} vs ${nu}`);
  const binaryTail={offset:p,size:nu-p};
  const mblock=chunk('MS00'),materialCount=u(mblock.payload),materials=[],materialTable=ptr(header+12);
  range(materialTable,materialCount*4,'material pointer table');
  const materialStride=materialCount>1?ptr(materialTable+4)-ptr(materialTable):0x2c4;
  if(materialCount&&![0x2c4,0x274].includes(materialStride))throw Error('Unknown material stride '+materialStride);
  range(mblock.payload+8,materialCount*materialStride,'materials');
  if(mblock.payload+8+materialCount*materialStride>mblock.offset+mblock.size)throw Error('Materials exceed MS00');
  for(let index=0;index<materialCount;index++){
    let a=mblock.payload+8+index*materialStride;
    if(ptr(materialTable+index*4)!==a)throw Error('MS00 differs from material pointer table');
    let diffuse=b.readInt16LE(a+0x74),bits=u(a+0x1f0);
    materials.push({index,address:a,recordSize:materialStride,id:u(a+0x38),alpha:u(a+0x40),color:[f(a+0x54),f(a+0x58),f(a+0x5c),f(a+0x60)],opacity:f(a+0x70),diffuse,specular:i(a+0xfc),normal:i(a+0x100),textureFlags:u(a+0xb4),formatBits:bits,shaderFlags:materialStride===0x2c4?u(a+0x26c):null,inputFlags:materialStride===0x2c4?u(a+0x268):null,uvSetCoords:materialStride===0x2c4?u(a+0x270):null,declaration:declaration(bits,!!textures[diffuse]?.size)});
  }
  const renderHeader=ptr(header+0x1d0),meshTable=ptr(renderHeader+0x10),meshCount=u(renderHeader+0x14),meshes=[];range(meshTable,meshCount*4,'meshes');
  for(let index=0;index<meshCount;index++){
    const a=ptr(meshTable+index*4);range(a,0x38,'mesh');
    const legacy=materialStride===0x274,delta=legacy?-4:0;
    const mesh={index,address:a,type:u(a),legacy,triangleCount:legacy?s(a+4):u(a+4),stride:s(a+(legacy?6:8)),vertexOffset:u(a+0x14+delta),vertexCount:u(a+0x18+delta),indexOffset:u(a+0x1c+delta),indexBuffer:u(a+0x20+delta),vertexBuffer:u(a+0x24),dynamic:legacy?0:u(a+0x28),dynamicBuffer:legacy?0:u(a+0x34)};
    const vb=vertexBuffers[mesh.vertexBuffer],ib=indexBuffers[mesh.indexBuffer];
    if(!vb||!ib)throw Error(`Mesh ${index} missing buffers`);
    if((mesh.vertexOffset+mesh.vertexCount)*mesh.stride>vb.size)throw Error(`Mesh ${index} vertex range exceeds buffer`);
    const indices=mesh.type===6?mesh.triangleCount+2:mesh.type===5?mesh.triangleCount*3:0;
    if(mesh.type!==6&&mesh.type!==5)warnings.push(`Mesh ${index}: primitive type ${mesh.type} unsupported`);
    if((mesh.indexOffset+indices)*2>ib.size)throw Error(`Mesh ${index} index range exceeds buffer`);
    meshes.push(mesh);
  }
  const byMesh=new Map(meshes.map(m=>[m.address,m.index])),byMat=new Map(materials.map(m=>[m.address,m.index]));
  const commands=[],displayLists=[],models=[],specialObjects=[],billboards=[],billboardMap=new Map();
  const displayChunk=chunks.find(c=>c.tag==='DISP'),cdata=chunks.find(c=>c.tag==='CDAT');
  const characterDisplay=!displayChunk&&cdata?ptr(header+0x110):0;
  const d=displayChunk??(characterDisplay?{payload:characterDisplay,size:cdata.size}:undefined);
  if(d){
    const a=d.payload,start=ptr(a+8),limit=Math.floor(d.size/16);let done=false;
    for(let index=0;index<limit;index++){
      let c=start+index*16;range(c,16,'command');let type=b[c],flags=b[c+1],resource=ptr(c+4),command={index,address:c,type,flags,resource};
      if(type===0x80)command.material=byMat.get(resource);
      if(type===0x82)command.mesh=byMesh.get(resource);
      if(type===0x83)command.matrix=mat(resource);
      if(type===0x8f){
        if(!billboardMap.has(resource)){range(resource,16,'billboard packet');let faceCount=u(resource+4),bufferIndex=u(resource+8),firstVertex=u(resource+12),vb=vertexBuffers[bufferIndex];if(!vb||(firstVertex+faceCount*6)*32>vb.size)throw Error('Billboard vertices exceed buffer');let vertices=Array.from({length:faceCount*6},(_,j)=>{let p=vb.offset+(firstVertex+j)*32;return{center:[f(p),f(p+4),f(p+8)],color:[...b.subarray(p+12,p+16)],uv:[f(p+16),f(p+20)],corner:[f(p+24),f(p+28)]};});let bi=billboards.length;billboards.push({index:bi,address:resource,flags:u(resource),faceCount,bufferIndex,firstVertex,vertices});billboardMap.set(resource,bi);}
        command.billboard=billboardMap.get(resource);
      }
      commands.push(command);if(type===0x8e){done=true;break;}
    }
    if(!done)throw Error('No command END within bounded DISP');
    const dc=u(a+0x60),dp=ptr(a+0x64);range(dp,dc*0x24,'display lists');
    for(let index=0;index<dc;index++){
      let addr=dp+index*0x24,first=(ptr(addr+4)-start)/16,last=first;
      if(!Number.isInteger(first)||first<0||first>=commands.length)throw Error('Display start not a command');
      while(last<commands.length&&commands[last].flags!==4)last++;
      if(last>=commands.length)throw Error('No display terminator');
      displayLists.push({index,address:addr,order:u(addr),first,last,firstBounds:s(addr+0x22),boundsCount:s(addr+0x20)});
    }
    const mc=u(a+0x10),mp=ptr(a+0x14);range(mp,mc*12,'game models');
    for(let index=0;index<mc;index++){
      let addr=mp+index*12,count=u(addr),mt=ptr(addr+4),ct=ptr(addr+8);range(mt,count*4);range(ct,count*4);
      models.push({index,address:addr,parts:Array.from({length:count},(_,j)=>({material:u(mt+j*4),command:u(ct+j*4)}))});
    }
    const sc=u(a+0x6c),sp=ptr(a+0x70);range(sp,sc*0xd0,'special objects');
    const modelIndex=new Map(models.map(m=>[m.address,m.index]));
    for(let index=0;index<sc;index++){
      let addr=sp+index*0xd0,namePtr=ptr(addr+0xb4),end=b.indexOf(0,namePtr);if(end<0||end-namePtr>4096)throw Error('Unterminated special object name');
      specialObjects.push({index,address:addr,name:b.toString('utf8',namePtr,end),model:modelIndex.get(ptr(addr+0xb0)),initialMatrix:mat(addr),matrix:mat(addr+64),boundsCenter:[f(addr+128),f(addr+132),f(addr+136)],boundsExtent:[f(addr+144),f(addr+148),f(addr+152)],boundsIndex:u(addr+0xc0),remoteIABL:u(addr+0xc4),visibilityFunction:u(addr+0xb8)});
    }
  }
  const inid=chunks.find(c=>c.tag==='INID');let dynamicInstanceIndices=[];
  if(inid){let count=u(inid.payload);range(inid.payload+8,count*2,'INID');dynamicInstanceIndices=Array.from({length:count},(_,j)=>s(inid.payload+8+j*2));}
  const boundsChunk=chunks.find(c=>c.tag==='BNDS'),bounds=[];
  if(boundsChunk){let a=boundsChunk.payload,flags=u(a),count=u(a+4),start=flags&0x80000000?a+8:a+16+count*16;range(start,count*32,'bounding boxes');if(start+count*32>boundsChunk.offset+boundsChunk.size)throw Error('Bounds exceed BNDS');for(let j=0;j<count;j++){let p=start+j*32;bounds.push({index:j,address:p,center:[f(p),f(p+4),f(p+8)],extent:[f(p+16),f(p+20),f(p+24)]});}}
  const splineChunk=chunks.find(c=>c.tag==='SST0'),names=chunk('NTBL'),splines=[];
  if(splineChunk){let count=u(splineChunk.payload),p=splineChunk.payload+8;for(let j=0;j<count;j++){let a=p,n=s(p),pointSize=s(p+2),rawName=relocations.has(p+4)?i(p+4)?p+4+i(p+4):0:u(p+4),nameAddress=names.payload+((rawName-names.payload+0x2c)&0xffff);range(p+8,n*12,'spline points');if(p+8+n*12>splineChunk.offset+splineChunk.size)throw Error('Spline exceeds SST0');let end=b.indexOf(0,nameAddress),name=null;if(nameAddress>=names.payload+4&&end<names.offset+names.size&&end>=nameAddress)name=b.toString('utf8',nameAddress,end);splines.push({index:j,address:a,name,nameAddress,rawName,pointSize,points:Array.from({length:n},(_,k)=>[f(p+8+k*12),f(p+12+k*12),f(p+16+k*12)])});p+=8+n*12;}}
  const portalChunk=chunks.find(c=>c.tag==='PORT');let portalData=null;
  if(portalChunk){
    let a=portalChunk.payload,counts=Array.from({length:6},(_,j)=>s(a+4+j*2)),[na,nb,nc,nd,ne,nf]=counts,p=a+16;
    const take=(count,size,reader)=>{range(p,count*size,'portal array');if(p+count*size>portalChunk.offset+portalChunk.size)throw Error('Portal array exceeds PORT');let start=p;p+=count*size;return Array.from({length:count},(_,j)=>reader(start+j*size));};
    let objectIndices=take(nc,2,s),planes=take(nd,16,p=>[f(p),f(p+4),f(p+8),f(p+12)]),links=take(nf,2,s),points=take(ne,12,p=>[f(p),f(p+4),f(p+8)]);
    // The actual PC room stride is 24, corroborated by OpenSaga nuportal.h;
    // BrickBench's incomplete reader advances only 20 and misaligns portals.
    let rooms=take(nb,24,p=>{let instances=ptr(p),plane=ptr(p+4),ports=ptr(p+8),ni=s(p+12),np=b[p+14],nl=b[p+15];range(instances,ni*2);range(plane,np*16);range(ports,nl*2);return{address:p,flags:b[p+16],priority:b[p+20],instanceIndices:Array.from({length:ni},(_,j)=>s(instances+j*2)),planeEquations:Array.from({length:np},(_,j)=>Array.from({length:4},(_,k)=>f(plane+j*16+k*4))),portalIndices:Array.from({length:nl},(_,j)=>s(ports+j*2))};});
    let portals=take(na,32,p=>{let vertices=ptr(p+16),count=s(p+20),frontRoom=s(p+22),backRoom=s(p+24);range(vertices,count*12);if(frontRoom>=nb||backRoom>=nb)throw Error('Portal references unknown room');return{address:p,plane:[f(p),f(p+4),f(p+8),f(p+12)],frontRoom,backRoom,id:b.readInt8(p+26),activeFlags:u(p+28),vertices:Array.from({length:count},(_,j)=>[f(vertices+j*12),f(vertices+j*12+4),f(vertices+j*12+8)])};});
    portalData={counts,objectIndices,planes,links,points,rooms,portals,unparsedTailBytes:portalChunk.offset+portalChunk.size-p};
  }
  return {source,sha256:crypto.createHash('sha256').update(b).digest('hex'),bytes:b.length,nu20:nu,pntr:pn,relocationCount:pnCount,header,binaryTail,chunkChainEnd:cursor,chunks,textures,vertexBuffers,indexBuffers,materials,meshes,commands,displayLists,models,specialObjects,dynamicInstanceIndices,bounds,splines,portalData,billboards,warnings};
}

export function decodeMesh(b,scene,meshIndex,materialIndex) {
  const m=scene.meshes[meshIndex],mat=scene.materials[materialIndex];if(!m)throw Error('Unknown mesh');
  const vb=scene.vertexBuffers[m.vertexBuffer],ib=scene.indexBuffers[m.indexBuffer];
  let decl=mat?.declaration;if(decl&&decl.stride!==m.stride)throw Error(`Declaration stride ${decl.stride} != mesh ${m.stride} (${meshIndex}, material ${materialIndex})`);
  const positions=[],uv=[],normals=[],colors=[],weights=[],joints=[];
  const half=v=>{let sign=v&0x8000?-1:1,ex=(v>>>10)&31,mant=v&1023;return sign*(ex===0?mant*2**-24:ex===31?(mant?NaN:Infinity):(1+mant/1024)*2**(ex-15));};
  for(let j=0;j<m.vertexCount;j++){
    let base=vb.offset+(m.vertexOffset+j)*m.stride;
    let pos=[0,4,8].map(o=>b.readFloatLE(base+o));if(pos.some(x=>!Number.isFinite(x)))throw Error(`Nonfinite vertex ${meshIndex}:${j}`);positions.push(...pos);
    for(const d of decl?.fields??[]){let p=base+d.offset;
      if(d.name==='uv0'){let vals=d.type==='half2'?[half(b.readUInt16LE(p)),half(b.readUInt16LE(p+2))]:[b.readFloatLE(p),b.readFloatLE(p+4)];if(vals.some(x=>!Number.isFinite(x)))throw Error('Nonfinite UV');uv.push(...vals);}
      if(d.name==='normal')normals.push(...(d.type==='float3'?[0,4,8].map(o=>b.readFloatLE(p+o)):[0,1,2].map(o=>b[p+o]/127.5-1)));
      if(d.name==='color')colors.push(...[0,1,2,3].map(o=>b[p+o]/255));
      if(d.name==='joints')joints.push(...(d.type==='float3'?[0,4,8].map(o=>b.readFloatLE(p+o)):[0,1,2,3].map(o=>b[p+o])));
      if(d.name==='weights')weights.push(...(d.type==='float2'?[0,4].map(o=>b.readFloatLE(p+o)):[0,1,2,3].map(o=>b[p+o]/255)));
    }
  }
  let count=m.type===6?m.triangleCount+2:m.type===5?m.triangleCount*3:0,indices=[];
  let input=Array.from({length:count},(_,j)=>b.readUInt16LE(ib.offset+(m.indexOffset+j)*2));
  if(input.some(x=>x>=m.vertexCount))throw Error(`Index outside vertex range mesh ${meshIndex}`);
  if(m.type===6)for(let j=2;j<input.length;j++){let tri=j%2?[input[j-1],input[j-2],input[j]]:[input[j-2],input[j-1],input[j]];if(new Set(tri).size===3)indices.push(...tri);}
  if(m.type===5)for(let j=0;j<input.length;j+=3){let tri=input.slice(j,j+3);if(new Set(tri).size===3)indices.push(...tri);}
  return {positions,uv,normals,colors,weights,joints,indices,sourceIndexCount:input.length};
}

if(typeof process!=='undefined'&&process.argv[1]&&fileURLToPath(import.meta.url)===path.resolve(process.argv[1])){
  const input=process.argv[2];if(!input)throw Error('Usage: node geometry-nu2.mjs input.GSC [report.json]');
  const data=parseNu2(await fs.readFile(input),input);let output=process.argv[3];if(output)await fs.writeFile(output,JSON.stringify(data,null,2));
  console.log(JSON.stringify({file:input,textures:data.textures.filter(t=>t.size).length,materials:data.materials.length,meshes:data.meshes.length,displayLists:data.displayLists.length,specialObjects:data.specialObjects.length,warnings:data.warnings},null,2));
}
