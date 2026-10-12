import fs from 'node:fs/promises';import path from 'node:path';
import validator from './geometry-validation/node_modules/gltf-validator/index.js';
const root=path.resolve('reverse-engineering'),rp=path.join(root,'reports/geometry-finalized-gsc.json'),report=JSON.parse(await fs.readFile(rp,'utf8'));
let count=0;
for(let row of report.results){
  if(!row.validation.errors&&!row.validation.warnings&&!process.argv.includes('--all'))continue;
  let file=path.join(row.output,'scene.gltf');
  const v=await validator.validateBytes(new Uint8Array(await fs.readFile(file)),{uri:'scene.gltf',maxIssues:0,externalResourceFunction:async uri=>new Uint8Array(await fs.readFile(path.resolve(row.output,decodeURIComponent(uri))))});
  const issueCounts={};for(let m of v.issues.messages)issueCounts[m.code]=(issueCounts[m.code]??0)+1;
  row.validation={errors:v.issues.numErrors,warnings:v.issues.numWarnings,infos:v.issues.numInfos,truncated:v.issues.truncated,issueCounts,problems:v.issues.messages.filter(m=>m.severity<2)};
  count++;console.log(JSON.stringify({source:row.source,errors:row.validation.errors,warnings:row.validation.warnings,firstProblems:row.validation.problems.slice(0,2)}));
}
for(let k of ['errors','warnings','infos'])report.totals[k]=report.results.reduce((n,r)=>n+r.validation[k],0);
report.timestamp=new Date().toISOString();await fs.writeFile(rp,JSON.stringify(report,null,2));console.log(JSON.stringify({revalidated:count,totals:report.totals}));
