import fs from 'node:fs/promises';
import path from 'node:path';
import {parseAnimation,parseSkeleton,sampleAni4,sha256} from './animation-formats.mjs';
const root=path.resolve('reverse-engineering'),input=path.join(root,'extracted'),output=path.join(root,'exports/animation');
const files=(await fs.readdir(input,{recursive:true})).filter(x=>/\.(AN3|GHG)$/i.test(x)).sort();
const report={generated:new Date().toISOString(),scope:'All extracted AN3 files and GHG skeletons',success:[],failures:[]};
for(const rel of files){
 try{
  const b=await fs.readFile(path.join(input,rel));const a=/\.AN3$/i.test(rel)?parseAnimation(b):parseSkeleton(b);a.sourcePath=rel.replaceAll('\\','/');
  const dest=path.join(output,rel+'.json');await fs.mkdir(path.dirname(dest),{recursive:true});await fs.writeFile(dest,JSON.stringify(a));
  const summary={path:a.sourcePath,sha256:a.sourceSha256,bytes:a.sourceBytes,format:a.format,output:path.relative(root,dest).replaceAll('\\','/'),...a.validation};
  if(a.header){summary.nodes=a.header.nodeCount;summary.frames=a.header.frameCount;summary.keys=a.header.keyCount;summary.flagSet=[...new Set(a.nodes.map(n=>n.flags))];summary.samples=a.nodes.reduce((s,n)=>s+n.curves.reduce((x,c)=>x+(c.values?.length??1),0),0);sampleAni4(a,a.header.firstFrame);sampleAni4(a,a.header.firstFrame+a.header.frameCount-1);}
  else {summary.joints=a.jointCount;summary.pointsOfInterest=a.pointsOfInterest.length;}
  report.success.push(summary);
 }catch(error){const b=await fs.readFile(path.join(input,rel));report.failures.push({path:rel.replaceAll('\\','/'),bytes:b.length,sha256:sha256(b),error:error.message});}
 if((report.success.length+report.failures.length)%250===0)console.log(`${report.success.length} decoded, ${report.failures.length} unhandled`);
}
report.totals={files:files.length,decoded:report.success.length,failed:report.failures.length,animations:report.success.filter(x=>x.format.startsWith('ANI')).length,skeletons:report.success.filter(x=>x.format==='GHG-PC-hierarchy').length,keySampleValues:report.success.reduce((s,x)=>s+(x.samples??0),0),jointCount:report.success.reduce((s,x)=>s+(x.joints??0),0),maxInverseIdentityError:Math.max(...report.success.map(x=>x.maxInverseIdentityError??0))};
await fs.mkdir(path.join(root,'reports'),{recursive:true});await fs.writeFile(path.join(root,'reports/animation-export.json'),JSON.stringify(report,null,2));console.log(JSON.stringify(report.totals,null,2));console.log('Failure examples:',report.failures.slice(0,15));
