import fs from 'node:fs/promises';
import {createReadStream} from 'node:fs';
import path from 'node:path';
import {createHash} from 'node:crypto';
import assert from 'node:assert/strict';
import {fileURLToPath} from 'node:url';
import {readArchive,readExactly,parseIndex} from './ttdat.mjs';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const game=path.resolve(base,'../Lego Star Wars Saga');
const reports=path.join(base,'reports');
const hashFile=async filename=>{const h=createHash('sha256');for await(const c of createReadStream(filename))h.update(c);return h.digest('hex');};
const full=process.argv.includes('--all');
const previousHashes=JSON.parse(await fs.readFile(path.join(reports,'source-sha256.json'),'utf8').catch(e=>{if(e.code==='ENOENT')return '[]';throw e;}));
const archives=[];const sourceHashes=[];const allAssets=[];
for(const name of (await fs.readdir(game)).filter(f=>f.endsWith('.DAT')).sort()){
 const filename=path.join(game,name);const index=await readArchive(filename);archives.push(index);
 await fs.writeFile(path.join(reports,name+'.index.json'),JSON.stringify(index,null,2));
 sourceHashes.push({path:name,bytes:index.archiveSize,sha256:await hashFile(filename)});
 allAssets.push(...index.entries.map(e=>({archive:name,...e})));
 console.log(name+': '+index.count+' verified index entries');
}
sourceHashes.push({path:'LEGOStarWarsSaga.exe',sha256:await hashFile(path.join(game,'LEGOStarWarsSaga.exe'))});
for(const old of previousHashes){const now=sourceHashes.find(x=>x.path===old.path);assert.equal(now?.sha256,old.sha256,'Original source changed: '+old.path);}
await fs.writeFile(path.join(reports,'source-sha256.json'),JSON.stringify(sourceHashes,null,2));
await fs.writeFile(path.join(reports,'all-assets.json'),JSON.stringify(allAssets,null,2));
const selected=full?allAssets:allAssets.filter(e=>e.archive==='GAME.DAT'||e.archive==='EPISODE_I.DAT'&&e.path.includes('/NEGOTIATIONS/'));
const missing=[],wrongSizes=[];
for(const entry of selected){try{const s=await fs.stat(path.join(base,'extracted',entry.path));if(s.size!==entry.size)wrongSizes.push({path:entry.path,expected:entry.size,actual:s.size});}catch(e){if(e.code!=='ENOENT')throw e;missing.push(entry.path);}}
const rawSamples=selected.filter(e=>e.archive==='GAME.DAT'&&e.flags===0&&e.size===e.storedSize&&e.size>0).filter((e,i)=>i%137===0).slice(0,40);
const rawComparisons=[];const handle=await fs.open(path.join(game,'GAME.DAT'),'r');
try{for(const e of rawSamples){const raw=await readExactly(handle,e.size,e.offset);const output=await fs.readFile(path.join(base,'extracted',e.path));assert.deepEqual(output,raw,e.path);rawComparisons.push({path:e.path,offset:e.offset,size:e.size,sha256:createHash('sha256').update(raw).digest('hex'),match:true});}}finally{await handle.close();}
const target=archives.find(a=>a.archive==='EPISODE_II.DAT');const h=await fs.open(path.join(game,target.archive),'r');const indexBytes=await readExactly(h,target.indexSize,target.indexOffset);await h.close();
const negativeTests=[];
const test=(name,buffer)=>{assert.throws(()=>parseIndex(buffer,target.archiveSize,target.indexOffset));negativeTests.push({name,passed:true});};
const badType=Buffer.from(indexBytes);badType.writeInt32LE(-99,0);test('Unsupported index type',badType);
test('Truncated index',indexBytes.subarray(0,64));
const badOffset=Buffer.from(indexBytes);badOffset.writeUInt32LE(0x7fffffff,8);test('Out-of-range payload',badOffset);
const badHash=Buffer.from(indexBytes);const ns=8+target.count*16;const pool=ns+4+target.nodeCount*8+4;const ho=pool+indexBytes.readUInt32LE(pool-4);badHash.writeUInt32LE(0,ho);test('Unresolved path hash',badHash);
const result={scope:full?'all-archives':'initial-sample',sourceHashesCompared:previousHashes.length,indexed:allAssets.length,filenameHashesMatched:allAssets.length,payloadBoundsPassed:allAssets.length,expectedExtracted:selected.length,missing,wrongSizes,rawComparisons,negativeTests,archiveSummary:archives.map(a=>({archive:a.archive,count:a.count,storedBytes:a.archiveSize,expandedBytes:a.entries.reduce((v,e)=>v+e.size,0)}))};
await fs.writeFile(path.join(reports,full?'verification-full.json':'verification.json'),JSON.stringify(result,null,2));
assert.equal(missing.length,0,'Some extraction outputs are missing');assert.equal(wrongSizes.length,0,'Some extraction sizes differ');
console.log(JSON.stringify({indexed:result.indexed,extracted:result.expectedExtracted,rawSamples:rawComparisons.length,negativeTests:negativeTests.length}));
