// Independent glTF reader and simple z-buffer rasterizer for export inspection.
// Orthographic preview only: not a recreation of Nu2 rendering.
import fs from 'node:fs/promises';import path from 'node:path';import zlib from 'node:zlib';
import {png} from './geometry-textures.mjs';import {identity} from './geometry-nu2.mjs';
const file=path.resolve(process.argv[2]),out=process.argv[3],sceneNumber=Number(process.argv[4]??0),g=JSON.parse(await fs.readFile(file,'utf8')),dir=path.dirname(file),buffers=await Promise.all(g.buffers.map(b=>fs.readFile(path.join(dir,b.uri))));
const width=1400,height=1000;
function attr(id){let a=g.accessors[id],v=g.bufferViews[a.bufferView],b=buffers[v.buffer],p=(v.byteOffset??0)+(a.byteOffset??0),components=({SCALAR:1,VEC2:2,VEC3:3,VEC4:4,MAT4:16}[a.type]),n=a.count*components,size={5121:1,5123:2,5125:4,5126:4}[a.componentType];return Array.from({length:n},(_,j)=>{let off=p+Math.floor(j/components)*(v.byteStride??components*size)+(j%components)*size;return a.componentType===5125?b.readUInt32LE(off):a.componentType===5123?b.readUInt16LE(off):a.componentType===5121?b[off]:b.readFloatLE(off);});}
function multiply(a,b){return Array.from({length:16},(_,i)=>{let r=i%4,c=Math.floor(i/4);return a[r]*b[c*4]+a[r+4]*b[c*4+1]+a[r+8]*b[c*4+2]+a[r+12]*b[c*4+3];});}
function point(m,p){return [0,1,2].map(r=>m[r]*p[0]+m[r+4]*p[1]+m[r+8]*p[2]+m[r+12]);}
function dot(a,b){return a.reduce((v,x,i)=>v+x*b[i],0);}
function imagePng(buf){let p=8,parts=[],w,h;while(p+12<=buf.length){let len=buf.readUInt32BE(p),tag=buf.toString('ascii',p+4,p+8);if(tag==='IHDR'){w=buf.readUInt32BE(p+8);h=buf.readUInt32BE(p+12);if(buf[p+16]!==8||buf[p+17]!==6)return null;}if(tag==='IDAT')parts.push(buf.subarray(p+8,p+8+len));p+=len+12;}
  let scan=zlib.inflateSync(Buffer.concat(parts)),rgba=Buffer.alloc(w*h*4);for(let y=0;y<h;y++){let off=y*(w*4+1);if(scan[off]!==0)return null;scan.copy(rgba,y*w*4,off+1,off+1+w*4);}return{width:w,height:h,rgba};}
let tex=[];for(let im of g.images??[]){try{tex.push(imagePng(await fs.readFile(path.resolve(dir,im.uri))));}catch{tex.push(null);}}
const calls=[];let bbox={min:[Infinity,Infinity,Infinity],max:[-Infinity,-Infinity,-Infinity]};
if(process.argv[5]!==undefined){let animation=g.animations.find(a=>a.name.toLowerCase()===String(process.argv[6]??'jump').toLowerCase());if(!animation)throw Error('Animation not found');let time=Number(process.argv[5]);for(let c of animation.channels){let s=animation.samplers[c.sampler],times=attr(s.input),values=attr(s.output),size=values.length/times.length,lo=0;while(lo+1<times.length&&times[lo+1]<=time)lo++;let hi=Math.min(lo+1,times.length-1),t=lo===hi?0:Math.max(0,Math.min(1,(time-times[lo])/(times[hi]-times[lo]))),a=values.slice(lo*size,(lo+1)*size),b=values.slice(hi*size,(hi+1)*size);if(c.target.path==='rotation'&&dot(a,b)<0)b=b.map(v=>-v);let v=a.map((x,i)=>x+(b[i]-x)*t);if(c.target.path==='rotation'){let norm=Math.hypot(...v);v=v.map(x=>x/norm);}g.nodes[c.target.node][c.target.path]=v;}}
function local(n){if(n.matrix)return n.matrix;let [x,y,z,w]=n.rotation??[0,0,0,1],s=n.scale??[1,1,1],t=n.translation??[0,0,0];return[(1-2*y*y-2*z*z)*s[0],(2*x*y+2*z*w)*s[0],(2*x*z-2*y*w)*s[0],0,(2*x*y-2*z*w)*s[1],(1-2*x*x-2*z*z)*s[1],(2*y*z+2*x*w)*s[1],0,(2*x*z+2*y*w)*s[2],(2*y*z-2*x*w)*s[2],(1-2*x*x-2*y*y)*s[2],0,...t,1];}
const globalMatrices=new Map();function matrices(index,parent){let n=g.nodes[index],m=multiply(parent,local(n));globalMatrices.set(index,m);for(let c of n.children??[])matrices(c,m);}for(let n of g.scenes[sceneNumber].nodes)matrices(n,identity);
function visit(index,parent){let n=g.nodes[index],matrix=globalMatrices.get(index);if(n.mesh!==undefined)for(let p of g.meshes[n.mesh].primitives){let ps=attr(p.attributes.POSITION),world=[],skin=n.skin===undefined?null:g.skins[n.skin],js=skin?attr(p.attributes.JOINTS_0):null,ws=skin?attr(p.attributes.WEIGHTS_0):null,ib=skin?attr(skin.inverseBindMatrices):null,jms=skin?skin.joints.map((ji,j)=>multiply(globalMatrices.get(ji),ib.slice(j*16,j*16+16))):null;
  for(let j=0;j<ps.length;j+=3){let source=ps.slice(j,j+3),pt;if(skin){pt=[0,0,0];for(let k=0;k<4;k++){let weight=ws[j/3*4+k];if(!weight)continue;let v=point(jms[js[j/3*4+k]],source);for(let q=0;q<3;q++)pt[q]+=v[q]*weight;}}else pt=point(matrix,source);world.push(pt);for(let k=0;k<3;k++){bbox.min[k]=Math.min(bbox.min[k],pt[k]);bbox.max[k]=Math.max(bbox.max[k],pt[k]);}}calls.push({world,indices:attr(p.indices),uv:p.attributes.TEXCOORD_0===undefined?null:attr(p.attributes.TEXCOORD_0),color:p.attributes.COLOR_0===undefined?null:attr(p.attributes.COLOR_0),material:g.materials[p.material]});}for(let c of n.children??[])visit(c,matrix);}
for(let n of g.scenes[sceneNumber].nodes)visit(n,identity);
const yaw=Number(process.env.PREVIEW_YAW??45)*Math.PI/180,pitch=Number(process.env.PREVIEW_PITCH??50)*Math.PI/180;
const right=[Math.cos(yaw),0,-Math.sin(yaw)],up=[-Math.sin(yaw)*Math.sin(pitch),Math.cos(pitch),-Math.cos(yaw)*Math.sin(pitch)],forward=[Math.sin(yaw)*Math.cos(pitch),Math.sin(pitch),Math.cos(yaw)*Math.cos(pitch)];
let xmin=Infinity,xmax=-Infinity,ymin=Infinity,ymax=-Infinity;
for(let c of calls){c.screen=c.world.map(p=>{let a=[dot(p,right),dot(p,up),dot(p,forward)];xmin=Math.min(xmin,a[0]);xmax=Math.max(xmax,a[0]);ymin=Math.min(ymin,a[1]);ymax=Math.max(ymax,a[1]);return a;});}
const scale=Math.min((width-60)/(xmax-xmin),(height-60)/(ymax-ymin)),cx=(xmin+xmax)/2,cy=(ymin+ymax)/2;
for(let c of calls)c.screen=c.screen.map(p=>[(p[0]-cx)*scale+width/2,height/2-(p[1]-cy)*scale,p[2]]);
let rgba=Buffer.alloc(width*height*4),depth=new Float32Array(width*height).fill(-Infinity);for(let j=0;j<width*height;j++){rgba[j*4]=22;rgba[j*4+1]=28;rgba[j*4+2]=40;rgba[j*4+3]=255;}
let triangleCount=0,pixels=0;const edge=(a,b,x,y)=>(x-a[0])*(b[1]-a[1])-(y-a[1])*(b[0]-a[0]);
for(let c of calls){let material=c.material,pbr=material?.pbrMetallicRoughness,factor=pbr?.baseColorFactor??[.7,.75,.8,1],texture=pbr?.baseColorTexture===undefined?null:tex[g.textures[pbr.baseColorTexture.index].source];
  for(let j=0;j<c.indices.length;j+=3){let ids=c.indices.slice(j,j+3),p=ids.map(i=>c.screen[i]),area=edge(p[0],p[1],p[2][0],p[2][1]);if(Math.abs(area)<1e-8)continue;triangleCount++;
    let xa=Math.max(0,Math.floor(Math.min(...p.map(v=>v[0])))),xb=Math.min(width-1,Math.ceil(Math.max(...p.map(v=>v[0])))),ya=Math.max(0,Math.floor(Math.min(...p.map(v=>v[1])))),yb=Math.min(height-1,Math.ceil(Math.max(...p.map(v=>v[1]))));
    let pts=ids.map(i=>c.world[i]),ab=pts[1].map((v,k)=>v-pts[0][k]),ac=pts[2].map((v,k)=>v-pts[0][k]),normal=[ab[1]*ac[2]-ab[2]*ac[1],ab[2]*ac[0]-ab[0]*ac[2],ab[0]*ac[1]-ab[1]*ac[0]],len=Math.hypot(...normal),light=.45+.55*Math.abs(dot(normal,[.3,.8,.45])/Math.max(1e-12,len));
    for(let y=ya;y<=yb;y++)for(let x=xa;x<=xb;x++){let w0=edge(p[1],p[2],x+.5,y+.5)/area,w1=edge(p[2],p[0],x+.5,y+.5)/area,w2=1-w0-w1;if(w0<0||w1<0||w2<0)continue;let ws=[w0,w1,w2],z=ws.reduce((n,w,k)=>n+w*p[k][2],0),idx=y*width+x;if(z<=depth[idx])continue;
      let col=[...factor];if(texture&&c.uv){let u=ws.reduce((n,w,k)=>n+w*c.uv[ids[k]*2],0),v=ws.reduce((n,w,k)=>n+w*c.uv[ids[k]*2+1],0),tx=Math.floor(((u%1+1)%1)*texture.width),ty=Math.floor(((v%1+1)%1)*texture.height),ti=(ty*texture.width+tx)*4;for(let k=0;k<4;k++)col[k]*=texture.rgba[ti+k]/255;}
      if(c.color)for(let k=0;k<4;k++)col[k]*=ws.reduce((n,w,q)=>n+w*c.color[ids[q]*4+k],0);if(col[3]<.08)continue;for(let k=0;k<3;k++)rgba[idx*4+k]=Math.round(Math.max(0,Math.min(1,col[k]*light))*255);depth[idx]=z;pixels++;
    }
  }
}
await fs.writeFile(out,png(width,height,rgba));console.log(JSON.stringify({out,sceneNumber,drawCalls:calls.length,triangleCount,pixels,bbox,projection:{yaw,pitch,scale}},null,2));
