import fs from 'node:fs/promises';
import path from 'node:path';
import {exportGeometry} from './geometry-export.mjs';
import {parseNu2} from './geometry-nu2.mjs';
const root=path.resolve('reverse-engineering'),extracted=path.join(root,'extracted'),out=path.join(root,'exports/geometry');
async function walk(dir){let a=[];for(let e of await fs.readdir(dir,{withFileTypes:true})){let p=path.join(dir,e.name);if(e.isDirectory())a.push(...await walk(p));else if(/\.(gsc|ghg)$/i.test(e.name))a.push(p);}return a;}
const kind=process.argv.find(x=>x.startsWith('--kind='))?.split('=')[1];
let files=(await walk(extracted)).sort().filter(f=>!kind||f.toLowerCase().endsWith('.'+kind)),results=[],errors=[];const survey=process.argv.includes('--survey');
const reportPath=path.join(root,'reports',(survey?'geometry-survey':'geometry-batch')+(kind?'-'+kind:'')+'.json');
const finished=new Map();if(process.argv.includes('--resume')){try{const previous=JSON.parse(await fs.readFile(reportPath,'utf8'));for(let r of previous.results)finished.set(r.source,r);}catch(e){if(e.code!=='ENOENT')throw e;}}
for(let j=0;j<files.length;j++){
  const file=files[j],relative=path.relative(extracted,file);
  if(finished.has(relative)){results.push(finished.get(relative));continue;}
  try{
    if(survey){let s=parseNu2(await fs.readFile(file),relative);results.push({source:relative,meshes:s.meshes.length,textures:s.textures.filter(t=>t.size).length,materials:s.materials.length,staticLists:s.displayLists.length,specialObjects:s.specialObjects.length,warnings:s.warnings});}
    else{let output=path.join(out,relative.replace(/\.[^.]+$/,''));results.push({...await exportGeometry(file,output,path.join(out,'textures')),source:relative});}
  }catch(e){errors.push({source:relative,error:e.message,stack:e.stack});}
  if((j+1)%10===0||j===files.length-1){console.log(JSON.stringify({processed:j+1,total:files.length,successful:results.length,failed:errors.length,last:relative}));await fs.writeFile(reportPath,JSON.stringify({timestamp:new Date().toISOString(),complete:j===files.length-1,total:files.length,results,errors},null,2));}
}
