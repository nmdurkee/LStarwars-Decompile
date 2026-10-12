// Corrupt independent in-memory copies; never write to the input carriers.
import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {parseNu2,decodeMesh} from './geometry-nu2.mjs';
import {decodeDDS} from './geometry-textures.mjs';
const root=path.resolve('reverse-engineering'),input=path.join(root,'extracted/LEVELS/EPISODE_I/NEGOTIATIONS/NEGOTIATIONS_A/NEGOTIATIONS_A_PC.GSC');
const original=await fs.readFile(input),sha=b=>crypto.createHash('sha256').update(b).digest('hex'),before=sha(original),scene=parseNu2(original,input),results=[];
function check(name,mutation,operation=parseNu2){let copy=Buffer.from(original);mutation(copy);try{operation(copy);results.push({name,rejected:false});}catch(e){results.push({name,rejected:true,reason:e.message});}}
check('Wrong NU20 signature',b=>b.write('BAD!',scene.nu20,'ascii'));
check('NU20 address beyond EOF',b=>b.writeUInt32LE(0xffffffff,0));
check('Relocation target beyond EOF',b=>b.writeInt32LE(0x7fffffff,scene.pntr+4));
check('Texture allocation length beyond EOF',b=>b.writeUInt32LE(0xffffffff,scene.textures.find(t=>t.size).allocation+20));
check('Vertex count exceeds its selected buffer',b=>b.writeUInt32LE(0xffffffff,scene.meshes[0].address+0x18));
check('Index count exceeds its selected buffer',b=>b.writeUInt32LE(0xffffffff,scene.meshes[0].address+4));
check('Unknown vertex buffer ID',b=>b.writeUInt32LE(0xffffffff,scene.meshes[0].address+0x24));
check('Nonfinite vertex coordinate',b=>b.writeFloatLE(Infinity,scene.vertexBuffers[scene.meshes[0].vertexBuffer].offset+scene.meshes[0].vertexOffset*scene.meshes[0].stride),b=>decodeMesh(b,scene,0));
check('Triangle index outside vertex count',b=>b.writeUInt16LE(65535,scene.indexBuffers[scene.meshes[0].indexBuffer].offset+scene.meshes[0].indexOffset*2),b=>decodeMesh(b,scene,0));
const t=scene.textures.find(t=>t.size),dds=Buffer.from(original.subarray(t.offset,t.offset+t.size));
for(let [name,bytes] of [['Truncated DDS base mip',dds.subarray(0,130)],['Invalid DDS dimensions',(()=>{let b=Buffer.from(dds);b.writeUInt32LE(0xffffffff,16);return b;})()]]){try{decodeDDS(bytes);results.push({name,rejected:false});}catch(e){results.push({name,rejected:true,reason:e.message});}}
const after=sha(await fs.readFile(input));
const report={source:input,sourceSHA256:before,sourceUnchanged:before===after,inMemoryOriginalUnchanged:before===sha(original),results,allRejected:results.every(r=>r.rejected)};
await fs.writeFile(path.join(root,'reports/geometry-boundary-checks.json'),JSON.stringify(report,null,2));console.log(JSON.stringify(report,null,2));
if(!report.allRejected||!report.sourceUnchanged||!report.inMemoryOriginalUnchanged)process.exitCode=1;
