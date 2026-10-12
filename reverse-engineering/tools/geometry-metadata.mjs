import fs from 'node:fs/promises';import path from 'node:path';import {parseNu2} from './geometry-nu2.mjs';
const root=path.resolve('reverse-engineering'),extracted=path.join(root,'extracted'),out=path.join(root,'reports/geometry-scene-data');
async function walk(dir){let a=[];for(let e of await fs.readdir(dir,{withFileTypes:true})){let p=path.join(dir,e.name);if(e.isDirectory())a.push(...await walk(p));else if(/\.(gsc|ghg)$/i.test(e.name))a.push(p);}return a;}
let rows=[],errors=[];
for(const input of (await walk(extracted)).sort()){
  let relative=path.relative(extracted,input),output=path.join(out,relative+'.json');
  try{let s=parseNu2(await fs.readFile(input),relative);await fs.mkdir(path.dirname(output),{recursive:true});await fs.writeFile(output,JSON.stringify(s));rows.push({source:relative,report:path.relative(root,output),sha256:s.sha256,meshes:s.meshes.length,billboards:s.billboards.length,billboardFaces:s.billboards.reduce((n,b)=>n+b.faceCount,0),materials:s.materials.length,textures:s.textures.filter(t=>t.size).length,splines:s.splines.length,splinePoints:s.splines.reduce((n,s)=>n+s.points.length,0),unnamedSplines:s.splines.filter(s=>!s.name).length,bounds:s.bounds.length,rooms:s.portalData?.rooms.length??0,portals:s.portalData?.portals.length??0,objects:s.specialObjects.length});}catch(e){errors.push({source:relative,error:e.message});}
  if(rows.length%50===0)console.log(JSON.stringify({done:rows.length,errors:errors.length,last:relative}));
}
const report={date:new Date().toISOString(),rows,errors,totals:{}};for(const key of ['meshes','billboards','billboardFaces','materials','textures','splines','splinePoints','unnamedSplines','bounds','rooms','portals','objects'])report.totals[key]=rows.reduce((n,r)=>n+r[key],0);
await fs.writeFile(path.join(root,'reports/geometry-scene-data-index.json'),JSON.stringify(report,null,2));console.log(JSON.stringify({files:rows.length,errors,totals:report.totals},null,2));
