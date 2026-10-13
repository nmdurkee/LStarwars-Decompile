// Register the second independently evidenced 2026-10-13 bounded recovery batch.
// Run from any directory; idempotent source/fixture/coverage registration only.
import fs from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const read=async p=>JSON.parse((await fs.readFile(path.join(base,p),'utf8')).replace(/^\uFEFF/,''));
const write=async(p,v)=>fs.writeFile(path.join(base,p),JSON.stringify(v,null,2)+'\n');
const manifest=await read('reconstructed/source-manifest.json');
const descriptors=['reports/actor-next-20261013-source.json','reports/script-next-20261013-source-map.json','reports/world-next-20261013-integration.json','reports/scene-next-20261013-source.json'];
const registrations=[];
const aliases=await read('reports/native-contract-aliases.json');
const ledger=await read('reports/gameplay-command-semantic-coverage.json');
for(const descriptor of descriptors){
 const d=await read(descriptor),module=manifest.modules.find(m=>m.name===d.module);
 if(!module)throw Error('Unknown source module '+d.module);
 const mappings=d.mappings??d.functions.map(f=>({address:f.address,method:f.method,coverage:f.scope,sourceFile:f.file}));
 for(const file of d.files){await fs.access(path.join(base,'reconstructed',file));if(!module.files.includes(file))module.files.push(file);}
 for(const mapping of mappings){
  const previous=module.mappings.find(m=>m.address===mapping.address&&m.sourceFile===mapping.sourceFile);
  if(previous){if(previous.method!==mapping.method)aliases.entries=aliases.entries.filter(a=>!(a.address===mapping.address&&a.name===previous.method&&a.evidence===d.evidence[0]));Object.assign(previous,mapping);}else module.mappings.push(mapping);
  if(!aliases.entries.some(a=>a.address===mapping.address&&a.name===mapping.method))aliases.entries.push({address:mapping.address,name:mapping.method,evidence:d.evidence[0],status:'bounded-portable-reconstruction-compiled-execution-pending',scope:mapping.coverage});
 }
 for(const evidence of d.evidence){await fs.access(path.join(base,evidence));if(!module.evidence.includes(evidence))module.evidence.push(evidence);}
 const harness=d.harnessFile??d.harnessFiles[0];await fs.access(path.join(base,'reconstructed',harness));
 if(!manifest.harnessFiles.includes(harness))manifest.harnessFiles.push(harness);
 const name=d.verifierModule??'grid-visibility-20261013',cls=d.verifierClass??'GridVisibility20261013Harness';
 const fixture=(d.fixture??'reports/scene-visibility-20261013-native-fixtures.json.gz').replace(/^(?!reports\/)/,'reports/');
 const output=d.managedReport??d.managedOutput??'reports/'+name+'-csharp-validation.json';
 registrations.push({name,cls,fixture,output,descriptor});
 for(const command of d.commandCoverage??[]){
  const row=ledger.rows.find(r=>r.kind===command.kind&&r.name===command.name);
  if(!row||row.function!==command.function||row.sourceUses!==command.sourceUses)throw Error('Command binding/count mismatch '+command.name);
  row.status='bounded-native-contract';row.semanticContract={report:command.report,scope:command.scope};
 }
}
ledger.totals={};for(const r of ledger.rows){const t=ledger.totals[r.status]??={names:0,sourceUses:0};t.names++;t.sourceUses+=r.sourceUses;}
ledger.largestWithoutSemanticContracts=ledger.rows.filter(r=>r.status!=='bounded-native-contract').sort((a,b)=>b.sourceUses-a.sourceUses).slice(0,30).map(r=>({kind:r.kind,name:r.name,sourceUses:r.sourceUses,address:r.function,status:r.status}));
const now=new Date().toISOString();ledger.generatedAt=now;manifest.updated=now;aliases.updated=now;
aliases.entries.sort((a,b)=>parseInt(a.address,16)-parseInt(b.address,16)||a.name.localeCompare(b.name));
let entry=await fs.readFile(path.join(base,'reconstructed/RecoveredSourceVerify.cs'),'utf8');
let verify=await fs.readFile(path.join(base,'reconstructed/verify.ps1'),'utf8');
for(const r of registrations){
 if(!entry.includes('case "'+r.name+'":'))entry=entry.replace('switch(args[0])\n        {','switch(args[0])\n        {\n            case "'+r.name+'":return '+r.cls+'.Main(rest);');
 if(!verify.includes("'all','"+r.name+"'")){
  // ValidateSet and fixture registration are independently idempotent.
  const firstLine=verify.split('\n')[0];if(!firstLine.includes("'"+r.name+"'"))verify=verify.replace("ValidateSet('all',","ValidateSet('all','"+r.name+"',");
 }
 if(!verify.includes(" '"+r.name+"'=@("))verify=verify.replace('$cases=[ordered]@{','$cases=[ordered]@{\n '+"'"+r.name+"'=@('"+r.fixture+"','"+r.output+"')");
}
const index=await read('reports/gameplay-native-index.json');
const externalContracts=[
 {name:'Three actor state/Sock commands recovered 2026-10-13',report:'reverse-engineering/reports/actor-next-20261013-contract.json',tests:'reverse-engineering/reports/actor-next-20261013-native-tests.json',source:'reverse-engineering/reconstructed/gameplay/actor-next-20261013-Commands.cs',owner:'actor-next-20261013',checks:1233,sourceUses:115,includedInGameplayTotals:false,countQualification:'1233 case groups include115 authored commands; no independent authored count is added to checks. Excluded from historical gameplay suite totals.',scope:'Three first-call actor/Sock command handlers and fixed64-entry name/index/bit helpers. Full takeover release, raw-world population and Sock consumers remain external.'},
 {name:'Eight script conditions recovered in second 2026-10-13 batch',report:'reverse-engineering/reports/script-next-20261013-contract.json',tests:'reverse-engineering/reports/script-next-20261013-tests.json',source:'reverse-engineering/reconstructed/gameplay/script-next-20261013-Conditions.cs',owner:'script-next-20261013',checks:8471,sourceUses:110,includedInGameplayTotals:false,countQualification:'Assertion groups include110 authored body checks and110 original comparisons; initializers/helpers recorded separately. Excluded from historical gameplay suite totals.',scope:'Threat,Force use/completion,category,context and hint readers/initializers within prepared domains; registry/world/state producers external.'}
];
for(const external of externalContracts){const prior=index.externalCommandContracts.find(c=>c.owner===external.owner);if(prior)Object.assign(prior,external);else index.externalCommandContracts.push(external);}index.generatedAt=now;
await write('reconstructed/source-manifest.json',manifest);await write('reports/native-contract-aliases.json',aliases);await write('reports/gameplay-command-semantic-coverage.json',ledger);await write('reports/gameplay-native-index.json',index);
await fs.writeFile(path.join(base,'reconstructed/RecoveredSourceVerify.cs'),entry);await fs.writeFile(path.join(base,'reconstructed/verify.ps1'),verify);
await write('reports/reverse-next-20261013-registration.json',{updated:now,descriptors,registrations,policy:'Bounded mappings; compilation and original native evidence do not establish managed execution or whole-game equivalence.'});
console.log(JSON.stringify({registrations,files:manifest.modules.reduce((n,m)=>n+m.files.length,0),mappedEntries:new Set(manifest.modules.flatMap(m=>m.mappings.map(x=>x.address))).size,commands:ledger.totals}));
