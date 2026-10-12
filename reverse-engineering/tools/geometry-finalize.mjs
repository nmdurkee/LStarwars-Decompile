// Final pass over completed exports: include newly decoded billboard packets,
// synchronize metadata, prune optional empty arrays, and validate independently.
import fs from 'node:fs/promises';
import path from 'node:path';
import {exportGeometry} from './geometry-export.mjs';
import validator from './geometry-validation/node_modules/gltf-validator/index.js';
const root=path.resolve('reverse-engineering'), reportPath=path.join(root,'reports/geometry-finalized-gsc.json');
const batch=JSON.parse(await fs.readFile(path.join(root,'reports/geometry-batch-gsc.json'),'utf8'));
const metadata=JSON.parse(await fs.readFile(path.join(root,'reports/geometry-scene-data-index.json'),'utf8'));
const index=new Map(metadata.rows.map(r=>[r.source,r]));
let results=[],errors=[];
try{let old=JSON.parse(await fs.readFile(reportPath,'utf8'));results=old.results;}catch(e){if(e.code!=='ENOENT')throw e;}
const done=new Set(results.map(r=>r.source));
async function save(){let totals={files:results.length,meshes:0,exportedUniqueMeshes:0,meshMaterialPairs:0,billboards:0,triangles:0,textures:0,convertedTextures:0,errors:0,warnings:0,infos:0};for(let r of results){for(let k of Object.keys(totals)){if(k==='files')continue;totals[k]+=r.validation?.[k]??r[k]??0;}}await fs.writeFile(reportPath,JSON.stringify({timestamp:new Date().toISOString(),complete:batch.complete&&results.length===batch.total,total:batch.total,validator:validator.version(),totals,results,errors},null,2));}
for(let row of batch.results){
  if(done.has(row.source))continue;
  try{
    const mr=index.get(row.source),out=row.output;
    let regenerated=false;
    if(mr.billboards||row.problems.length){row={...await exportGeometry(path.join(root,'extracted',row.source),out,path.join(root,'exports/geometry/textures')),source:row.source};regenerated=true;}
    const file=path.join(out,'scene.gltf'),gltf=JSON.parse(await fs.readFile(file,'utf8'));
    for(let key of ['images','textures','materials','meshes','accessors','bufferViews','buffers','animations','skins'])if(gltf[key]?.length===0)delete gltf[key];
    if(!gltf.textures)delete gltf.samplers;
    for(let n of gltf.nodes??[]){if(n.children?.length===0)delete n.children;}
    for(let s of gltf.scenes??[]){if(s.nodes?.length===0)delete s.nodes;}
    await fs.writeFile(file,JSON.stringify(gltf));
    if(!regenerated){
      const mp=path.join(out,'source-metadata.json'),old=JSON.parse(await fs.readFile(mp,'utf8'));
      const current=JSON.parse(await fs.readFile(path.join(root,mr.report),'utf8'));
      if(current.sha256!==old.sha256)throw Error('Source metadata hash mismatch');
      await fs.writeFile(mp,JSON.stringify({...old,...current,billboardExports:old.billboardExports??[]},null,2));
    }
    const validation=await validator.validateBytes(new Uint8Array(await fs.readFile(file)),{uri:'scene.gltf',maxIssues:0,externalResourceFunction:async uri=>new Uint8Array(await fs.readFile(path.resolve(out,decodeURIComponent(uri))))});
    const issueCounts={};for(let m of validation.issues.messages)issueCounts[m.code]=(issueCounts[m.code]??0)+1;
    const vr={errors:validation.issues.numErrors,warnings:validation.issues.numWarnings,infos:validation.issues.numInfos,truncated:validation.issues.truncated,issueCounts,problems:validation.issues.messages.filter(m=>m.severity<2)};
    results.push({...row,regenerated,validation:vr});done.add(row.source);
    if(vr.errors||vr.warnings)console.log(JSON.stringify({source:row.source,errors:vr.errors,warnings:vr.warnings,problems:vr.problems.slice(0,3)}));
    if(results.length%10===0){await save();console.log(JSON.stringify({finalized:results.length,available:batch.results.length,total:batch.total,source:row.source}));}
  }catch(e){errors.push({source:row.source,error:e.message,stack:e.stack});console.log(JSON.stringify(errors.at(-1)));}
}
await save();console.log(JSON.stringify({finalized:results.length,total:batch.total,errors:errors.length}));
