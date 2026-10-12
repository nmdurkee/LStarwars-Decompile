// Refresh only PNGs where independent decoding found endpoint rounding drift.
// Raw DDS carriers are read-only; atomic replacement avoids partial PNG reads.
import fs from 'node:fs/promises';import path from 'node:path';
import {decodeDDS,png} from './geometry-textures.mjs';
const root=path.resolve('reverse-engineering'),report=JSON.parse(await fs.readFile(path.join(root,'reports/geometry-images-independent.json'),'utf8'));
if(!report.complete)throw Error('Independent comparison must finish before refresh');
const results=[],errors=[];
for(let row of report.checks){if(!row.maxChannelDifference)continue;
  try{let raw=path.resolve(root,row.dds),output=path.resolve(root,row.png);if(!output.startsWith(path.join(root,'exports/geometry')+path.sep))throw Error('Output outside geometry exports');
    let d=decodeDDS(await fs.readFile(raw)),temp=output+'.'+process.pid+'.tmp';await fs.writeFile(temp,png(d.width,d.height,d.rgba));await fs.rename(temp,output);results.push({dds:row.dds,png:row.png,previousMaxChannelDifference:row.maxChannelDifference});
  }catch(e){errors.push({dds:row.dds,error:e.message});}
  if((results.length+errors.length)%100===0)console.log(JSON.stringify({refreshed:results.length,errors:errors.length}));
}
await fs.writeFile(path.join(root,'reports/geometry-textures-refresh.json'),JSON.stringify({results,errors},null,2));console.log(JSON.stringify({refreshed:results.length,errors:errors.length}));
