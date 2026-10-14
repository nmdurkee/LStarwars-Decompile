// Validated local recovery descriptor registration. No Git operations.
import fs from 'node:fs/promises';import path from 'node:path';import crypto from 'node:crypto';import {fileURLToPath}from'node:url';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const [batch,...descriptors]=process.argv.slice(2);if(!batch||!descriptors.length||!/^[a-z0-9-]+$/.test(batch))throw Error('Usage: recovery-integrate.mjs batch-name descriptor...');
const read=async p=>JSON.parse((await fs.readFile(path.join(base,p),'utf8')).replace(/^\uFEFF/,''));const write=async(p,v)=>fs.writeFile(path.join(base,p),JSON.stringify(v,null,2)+'\n');
const manifest=await read('reconstructed/source-manifest.json'),aliases=await read('reports/native-contract-aliases.json'),ledger=await read('reports/gameplay-command-semantic-coverage.json'),index=await read('reports/gameplay-native-index.json');
const prepared=[];const availableCores=new Set(manifest.modules.flatMap(m=>m.files));
for(const descriptor of descriptors){const candidate=await read(descriptor);for(const f of candidate.files??[])availableCores.add(f);}
for(const descriptor of descriptors){
 const d=await read(descriptor);if(d.dependsOn)d.dependsOn=d.dependsOn.map(f=>f==='gameplay/SoundSetup.cs'?'gameplay/SoundInitialization.cs':f);const module=manifest.modules.find(m=>m.name===d.module);if(!module)throw Error('Unknown source module '+d.module);
 const mappings=d.mappings??d.functions?.map(f=>({address:f.address,method:f.method,coverage:f.scope,sourceFile:f.sourceFile??f.file??d.files[0],coverage:f.coverage??f.scope}));if(!mappings)throw Error('No mappings '+descriptor);
 if(!mappings.length){if(!d.files.length&&!d.dependsOn?.length||d.commandCoverage?.length)throw Error('Harness-only descriptor requires explicit existing core dependencies and zero command credit '+descriptor);for(const f of d.dependsOn??[])if(!availableCores.has(f))throw Error('Unregistered composition dependency '+f);}
 for(const file of d.files){if(!file||path.isAbsolute(file)||file.includes('..'))throw Error('Invalid core path');await fs.access(path.join(base,'reconstructed',file));availableCores.add(file);}
 for(const m of mappings){if(!d.files.includes(m.sourceFile)||!/^0x[0-9a-f]+$/i.test(m.address)||!m.method||!m.coverage)throw Error('Invalid mapping '+JSON.stringify(m));}
 for(const p of d.evidence??[])await fs.access(path.join(base,p));
 const harness=d.harnessFile??d.harnessFiles?.[0];const harnessText=harness?await fs.readFile(path.join(base,'reconstructed',harness),'utf8'):'';
 const cls=d.verifierClass??harnessText.match(/public\s+(?:static\s+)?class\s+([A-Za-z0-9_]+)/)?.[1];if(harness&&!cls)throw Error('No verifier class '+descriptor);
 const name=d.verifierModule??path.basename(descriptor).replace(/-(source|source-map|integration)\.json$/,'');const fixture=d.fixture;if(harness&&!fixture)throw Error('No fixture '+descriptor);if(fixture)await fs.access(path.join(base,fixture));
 const output=d.managedReport??d.managedOutput??'reports/'+name+'-csharp-validation.json';
 for(const c of d.commandCoverage??[]){const r=ledger.rows.find(r=>r.kind===c.kind&&r.name===c.name);if(!r||r.function!==c.function||r.sourceUses!==c.sourceUses)throw Error('Command binding/count mismatch '+c.name);}
 const testsPath=(d.evidence??[]).find(p=>/tests\.json$|native-validation\.json$/.test(p));const tests=testsPath?await read(testsPath):null;
 prepared.push({descriptor,d,module,mappings,harness,cls,name,fixture,output,testsPath,tests});
}
let entry=await fs.readFile(path.join(base,'reconstructed/RecoveredSourceVerify.cs'),'utf8');let verify=await fs.readFile(path.join(base,'reconstructed/verify.ps1'),'utf8');
const before=new Set(manifest.modules.flatMap(m=>m.mappings.map(x=>x.address))),oldFileCount=manifest.modules.reduce((n,m)=>n+m.files.length,0),registrations=[];
for(const p of prepared){const{d,module,mappings}=p;
 for(const f of d.files)if(!module.files.includes(f))module.files.push(f);
 const replaced=module.mappings.filter(m=>mappings.some(n=>n.address===m.address&&n.sourceFile===m.sourceFile));
 module.mappings=module.mappings.filter(m=>!mappings.some(n=>n.address===m.address&&n.sourceFile===m.sourceFile));module.mappings.push(...mappings);
 for(const old of replaced)if(!mappings.some(n=>n.address===old.address&&n.method===old.method))aliases.entries=aliases.entries.filter(a=>!(a.address===old.address&&a.name===old.method&&a.evidence===d.evidence[0]));
 for(const m of mappings){const a=aliases.entries.find(a=>a.address===m.address&&a.name===m.method);if(!a)aliases.entries.push({address:m.address,name:m.method,evidence:d.evidence[0],status:'bounded-portable-reconstruction-build-pending',scope:m.coverage});}
 for(const e of d.evidence)if(!module.evidence.includes(e))module.evidence.push(e);if(p.harness&&!manifest.harnessFiles.includes(p.harness))manifest.harnessFiles.push(p.harness);
 if(p.harness&&!entry.includes('case "'+p.name+'":'))entry=entry.replace('switch(args[0])\n        {','switch(args[0])\n        {\n            case "'+p.name+'":return '+p.cls+'.Main(rest);');
 if(p.harness&&!verify.split('\n')[0].includes("'"+p.name+"'"))verify=verify.replace("ValidateSet('all',","ValidateSet('all','"+p.name+"',");
 if(p.harness&&!verify.includes(" '"+p.name+"'=@("))verify=verify.replace('$cases=[ordered]@{','$cases=[ordered]@{\n '+"'"+p.name+"'=@('"+p.fixture+"','"+p.output+"')");
 for(const c of d.commandCoverage??[]){const r=ledger.rows.find(r=>r.kind===c.kind&&r.name===c.name);r.status='bounded-native-contract';r.semanticContract={report:c.report,scope:c.scope};}
 if(d.commandCoverage?.length){const tests=p.tests??{};const external={name:d.commandCoverage.map(c=>c.name).join(', '),owner:p.name,report:'reverse-engineering/'+d.evidence[0],tests:p.testsPath?'reverse-engineering/'+p.testsPath:null,source:'reverse-engineering/reconstructed/'+d.files[0],checks:tests.checks??tests.assertions??tests.cases??d.nativeChecks??d.nativeCases,checkUnit:tests.checks!==undefined?'recorded suite assertion/case groups':tests.assertions!==undefined?'assertion groups':'native cases',sourceUses:d.commandCoverage.reduce((n,c)=>n+c.sourceUses,0),includedInGameplayTotals:false,countQualification:'Primary suite units are explicit in linked reports, with authored checks included. Excluded from historical gameplay suite totals; not a whole-game or managed-equivalence count.',scope:d.commandCoverage.map(c=>c.scope).join(' ')};const old=index.externalCommandContracts.find(c=>c.owner===external.owner);if(old)Object.assign(old,external);else index.externalCommandContracts.push(external);}
 registrations.push({name:p.name,cls:p.cls,fixture:p.fixture,output:p.output,descriptor:p.descriptor,evidence:d.evidence,mappings,coreFiles:d.files,harnessFile:p.harness});
}
ledger.totals={};for(const r of ledger.rows){const t=ledger.totals[r.status]??={names:0,sourceUses:0};t.names++;t.sourceUses+=r.sourceUses;}
ledger.largestWithoutSemanticContracts=ledger.rows.filter(r=>r.status!=='bounded-native-contract').sort((a,b)=>b.sourceUses-a.sourceUses).slice(0,30).map(r=>({kind:r.kind,name:r.name,sourceUses:r.sourceUses,address:r.function,status:r.status}));
const now=new Date().toISOString();manifest.updated=now;ledger.generatedAt=now;aliases.updated=now;index.generatedAt=now;aliases.entries.sort((a,b)=>parseInt(a.address,16)-parseInt(b.address,16)||a.name.localeCompare(b.name));
await write('reconstructed/source-manifest.json',manifest);await write('reports/native-contract-aliases.json',aliases);await write('reports/gameplay-command-semantic-coverage.json',ledger);await write('reports/gameplay-native-index.json',index);await fs.writeFile(path.join(base,'reconstructed/RecoveredSourceVerify.cs'),entry);await fs.writeFile(path.join(base,'reconstructed/verify.ps1'),verify);
const after=new Set(manifest.modules.flatMap(m=>m.mappings.map(x=>x.address)));const registration={updated:now,batch,descriptors,registrations,newDistinctEntries:[...after].filter(a=>!before.has(a)),newCoreFiles:manifest.modules.reduce((n,m)=>n+m.files.length,0)-oldFileCount,policy:'Local descriptor registration. New core/alias compilation status remains pending until recorded build; native and managed evidence separate.'};await write('reports/'+batch+'-registration.json',registration);
console.log(JSON.stringify({batch,newDistinctEntries:registration.newDistinctEntries.length,newCoreFiles:registration.newCoreFiles,mappedEntries:after.size,coreFiles:manifest.modules.reduce((n,m)=>n+m.files.length,0),harnessFiles:manifest.harnessFiles.length,commandCoverage:ledger.totals}));
