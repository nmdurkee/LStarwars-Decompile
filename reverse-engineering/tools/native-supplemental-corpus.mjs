import fs from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const queue=path.join(base,'rea-queue'),rea=path.join(base,'reports/rea'),out=path.join(base,'decompiled/corpus-supplemental');
await fs.mkdir(out,{recursive:true});
const pause=ms=>new Promise(r=>setTimeout(r,ms));
async function result(id){try{const r=JSON.parse(await fs.readFile(path.join(rea,id+'.result.json'),'utf8'));return r.structuredContent??r;}catch(e){if(e.code==='ENOENT')return null;if(e instanceof SyntaxError && await fs.access(path.join(queue,id+'.running.json')).then(()=>true,()=>false))return null;throw e;}}
async function waitResult(id){for(let i=0;i<2100;i++){const r=await result(id);if(r)return r;await pause(1000);}throw Error('Timed out waiting for '+id);}
const inventory=await waitResult('075-supplemental-inventory');
if(!Array.isArray(inventory.normalized_result))throw Error('Expanded inventory unavailable: '+JSON.stringify(inventory).slice(0,1000));
const prior=[JSON.parse(await fs.readFile(path.join(base,'reports/native-corpus-index.json'),'utf8')),JSON.parse(await fs.readFile(path.join(base,'reports/native-expanded-corpus-index.json'),'utf8'))];
const known=new Set(prior.flatMap(r=>r.items.filter(i=>i.status==='ok').map(i=>i.address)));
const procedures=inventory.normalized_result.filter(p=>!p.procedure?.external&&/^0x/.test(p.address)&&!known.has(p.address));
const items=[];
for(let offset=0,batch=0;offset<procedures.length;offset+=32,batch++){
 const selected=procedures.slice(offset,offset+32);const id=String(660+batch)+'-supplemental-corpus';
 let ev=await result(id);if(!ev){const running=path.join(queue,id+'.running.json');if(!await fs.access(running).then(()=>true,()=>false))await fs.writeFile(path.join(queue,id+'.request.json'),JSON.stringify({name:'batch_decompile',arguments:{addresses:selected.map(x=>x.address)}},null,2));ev=await waitResult(id);}
 if(!ev.normalized_result?.items){await fs.writeFile(path.join(base,'reports/native-supplemental-corpus-interruption.json'),JSON.stringify({batch:id,offset,error:ev},null,2));throw Error('Batch needs inspection: '+id);}
 for(const item of ev.normalized_result.items){const canonical=item.procedure?.address??item.address;const row={address:canonical,selector:item.address,name:item.procedure?.name??null,status:item.status,evidence:ev.evidence_id,resultFile:'reports/rea/'+id+'.result.json'};if(item.status==='ok'){row.file='decompiled/corpus-supplemental/'+canonical.toLowerCase().replace('0x','FUN_')+'.c';await fs.writeFile(path.join(base,row.file),'/* Ghidra pseudocode, not original source.\n * '+ev.evidence_id+'\n * Entry: '+canonical+'; label: '+row.name+'\n * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.\n */\n'+item.pseudocode);row.characters=item.pseudocode.length;}else row.error=item.error;items.push(row);}
 const progress={inventoryEvidence:inventory.evidence_id,provider:'Ghidra with expanded boundary hypotheses plus inspected RTTI entries; see native-supplemental-entry-inspection.json',expected:procedures.length,processed:items.length,succeeded:items.filter(i=>i.status==='ok').length,failed:items.filter(i=>i.status!=='ok').length,items};
 await fs.writeFile(path.join(base,'reports/native-supplemental-corpus-index.json'),JSON.stringify(progress,null,2));
 if(batch%10===0||offset+32>=procedures.length)await fs.appendFile(path.join(base,'reports/native-supplemental-corpus-progress.log'),JSON.stringify({batch:id,processed:progress.processed,expected:progress.expected,succeeded:progress.succeeded,failed:progress.failed})+'\n');
}
console.log('Supplemental native corpus complete. Function boundaries remain analysis hypotheses.');
