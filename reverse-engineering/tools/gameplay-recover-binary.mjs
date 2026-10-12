import fs from 'node:fs';
import path from 'node:path';
import zlib from 'node:zlib';
import {decodeAI2,decodeTerrain,decodeGiz,reference} from './gameplay-binary.mjs';
const root=process.cwd(),base=path.join(root,'reverse-engineering/extracted'),output=path.join(root,'reverse-engineering/reports/gameplay-binary');
fs.mkdirSync(output,{recursive:true});
const walk=p=>fs.readdirSync(p,{withFileTypes:true}).flatMap(x=>x.isDirectory()?walk(path.join(p,x.name)):[path.join(p,x.name)]);
const relative=p=>path.relative(root,p).replaceAll('\\','/');
const files=walk(base).filter(p=>/\.(AI2|TER|GIZ)$/i.test(p));
const index={generatedAt:new Date().toISOString(),reference,scope:'All extracted AI2/TER/GIZ. Layout decoding is separate from native behavior verification. Unknown bytes preserved in carrier and decoded raw regions.',entries:[],totals:{},errors:[]};
for(const p of files){
 const type=path.extname(p).slice(1).toUpperCase(),name=path.relative(base,p),b=fs.readFileSync(p),entry={source:relative(p),type,bytes:b.length};
 try{const d=({AI2:decodeAI2,TER:decodeTerrain,GIZ:decodeGiz}[type])(b);d.source=relative(p);const target=path.join(output,'data',name+'.json.gz');fs.mkdirSync(path.dirname(target),{recursive:true});fs.writeFileSync(target,zlib.gzipSync(Buffer.from(JSON.stringify(d)),{level:6}));entry.output=relative(target);entry.sha256=d.sha256;entry.unknownTailBytes=d.unknownTail?.length??0;entry.warnings=d.warnings?.length??0;
  if(type==='AI2')Object.assign(entry,{version:d.version,paths:d.paths.length,points:d.paths.reduce((s,x)=>s+x.points.length,0),connections:d.paths.reduce((s,x)=>s+x.connections.length,0),triggers:d.triggers.length,locators:d.locators.length,locatorSets:d.locatorSets.length,creatures:d.creatures.length,additionalSpatialRecords:d.additionalSpatialRecords?.count??0,candidateError:d.additionalSpatialCandidateError});
  if(type==='TER')Object.assign(entry,{objects:d.objects.length,movingPlatforms:d.objects.filter(x=>x.kind===1).length,infiniteWalls:d.objects.filter(x=>x.kind===2).length,faces:d.objects.reduce((s,x)=>s+(x.blocks??[]).reduce((s,y)=>s+y.faces.length,0),0),objectTailBytes:d.objects.reduce((s,x)=>s+(x.unknownTail?.length??0),0),contentGapBytes:d.contentGap?.length??0});
  if(type==='GIZ'){entry.zeroFilledPlaceholder=d.zeroFilledPlaceholder??false;entry.truncatedChunk=d.truncatedChunk;entry.chunks=d.chunks.map(x=>({name:x.name,version:x.version,count:x.declaredCount,decodedRecords:x.records.length,instances:x.instances?.length??0,unknownBytes:x.unknownTail?.length??0,error:x.error,status:x.decoderStatus}));}
 }catch(e){entry.error=e.message;index.errors.push({source:entry.source,error:e.message});}
 index.entries.push(entry);
}
for(const type of ['AI2','TER','GIZ']){const entries=index.entries.filter(x=>x.type===type),ok=entries.filter(x=>!x.error);const s={files:entries.length,decoded:ok.length,failed:entries.length-ok.length};for(const k of ['points','connections','triggers','locators','locatorSets','creatures','additionalSpatialRecords','objects','movingPlatforms','infiniteWalls','faces','unknownTailBytes','objectTailBytes','contentGapBytes']){const n=ok.reduce((s,x)=>s+(x[k]??0),0);if(n)s[k]=n;}if(type==='GIZ'){s.records=ok.reduce((s,x)=>s+x.chunks.reduce((s,c)=>s+c.decodedRecords,0),0);s.instances=ok.reduce((s,x)=>s+x.chunks.reduce((s,c)=>s+c.instances,0),0);s.payloadFailures=ok.flatMap(x=>x.chunks).filter(x=>x.error).length;s.opaquePayloadBytes=ok.flatMap(x=>x.chunks).reduce((s,x)=>s+x.unknownBytes,0);}index.totals[type]=s;}
fs.writeFileSync(path.join(output,'index.json'),JSON.stringify(index,null,2));console.log(JSON.stringify({files:files.length,totals:index.totals,errors:index.errors.slice(0,15)},null,2));
