import fs from 'node:fs/promises';import path from'node:path';import{fileURLToPath}from'node:url';import{readArchive,readExactly}from'./ttdat.mjs';import{decodePayload}from'./tt-lz2k.mjs';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const [archive,filter,out]=process.argv.slice(2);if(!archive||!filter||!out)throw Error('Usage: node tt-extract.mjs GAME.DAT path-substring output-directory (existing files are never overwritten)');
if(!/^(GAME|EPISODE_I|EPISODE_II|EPISODE_III|EPISODE_IV|EPISODE_V|EPISODE_VI)\.DAT$/i.test(archive))throw Error('Choose one installed archive basename');
const source=path.join(base,'../Lego Star Wars Saga',archive),destination=path.resolve(out),index=await readArchive(source);
const game=path.resolve(base,'../Lego Star Wars Saga');if(destination.toLowerCase()===game.toLowerCase()||destination.toLowerCase().startsWith(game.toLowerCase()+path.sep))throw Error('Output cannot be inside original game directory');
const selected=index.entries.filter(a=>filter==='*'||a.path.toLowerCase().includes(filter.toLowerCase()));if(!selected.length)throw Error('No matching entries');
for(const a of selected){const target=path.resolve(destination,...a.path.split('/'));if(!target.toLowerCase().startsWith(destination.toLowerCase()+path.sep))throw Error('Unsafe output path');if(await fs.stat(target).then(()=>true,e=>{if(e.code==='ENOENT')return false;throw e;}))throw Error('Output already exists: '+target);}
await fs.mkdir(destination,{recursive:true});const handle=await fs.open(source,'r');let bytes=0;
try{for(const a of selected){const stored=await readExactly(handle,a.storedSize,a.offset),target=path.join(destination,...a.path.split('/'));const chunks=a.flags===0?[{data:stored}]:a.flags===2?decodePayload(stored,a.size):(()=>{throw Error('Unknown index flags')})();
 const decoded=[...chunks].map(c=>c.data);if(decoded.reduce((n,b)=>n+b.length,0)!==a.size)throw Error('Output extent mismatch');await fs.mkdir(path.dirname(target),{recursive:true});const outHandle=await fs.open(target,'wx');try{for(const b of decoded)await outHandle.writeFile(b);}finally{await outHandle.close();}bytes+=a.size;}
}finally{await handle.close();}console.log(JSON.stringify({archive,files:selected.length,bytes,output:destination,decoder:'independent LZ2K; no QuickBMS required'}));
