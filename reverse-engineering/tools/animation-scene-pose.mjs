// Scene-specific PC pose consumer, reconstructed from 0x5ea390 and 0x5b5300.
// This deliberately does not use the character pose evaluator or ANI5 flag-byte
// quaternion assumptions. Native scene animation replaces the linear transform.
import {sampleAni4} from './animation-formats.mjs';
import {readFileSync} from 'node:fs';
const nativeTable=readFileSync(new URL('../references/native-animation-sine-table.f32',import.meta.url));
if(nativeTable.length!==32768*4)throw Error('Invalid recovered native trig table');
const lut=Float32Array.from({length:32768},(_,i)=>nativeTable.readFloatLE(i*4));
const identity=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1];
export function quaternion(m){
 const a=m[0],b=m[4],c=m[8],d=m[1],e=m[5],f=m[9],g=m[2],h=m[6],i=m[10],tr=a+e+i;let x,y,z,w,s;
 if(tr>0){s=2*Math.sqrt(tr+1);w=s/4;x=(h-f)/s;y=(c-g)/s;z=(d-b)/s;}
 else if(a>e&&a>i){s=2*Math.sqrt(1+a-e-i);w=(h-f)/s;x=s/4;y=(b+d)/s;z=(c+g)/s;}
 else if(e>i){s=2*Math.sqrt(1+e-a-i);w=(c-g)/s;x=(b+d)/s;y=s/4;z=(f+h)/s;}
 else{s=2*Math.sqrt(1+i-a-e);w=(d-b)/s;x=(c+g)/s;y=(f+h)/s;z=s/4;}
 const len=Math.hypot(x,y,z,w);return[x/len,y/len,z/len,w/len];
}
export function scenePoseFromValues(values,flags,baseTranslation=[0,0,0]){
 const v=values.map(Math.fround);let rotation=[...identity];
 if(flags&1){
  const angles=v.slice(3,6).map(x=>Math.trunc(x*Math.fround(10430.378))),sin=a=>lut[(a>>1)&32767],cos=a=>lut[((a+16384)>>1)&32767];
  const [x,y,z]=angles,cx=cos(x),sx=sin(x),cy=cos(y),sy=sin(y),cz=cos(z),sz=sin(z);
  rotation=[cy*cz,cy*sz,-sy,0,sx*sy*cz-cx*sz,sx*sy*sz+cx*cz,sx*cy,0,cx*sy*cz+sx*sz,cx*sy*sz-sx*cz,cx*cy,0,0,0,0,1].map(Math.fround);
 }
 for(const i of[2,6,8,9,11])rotation[i]=-rotation[i];
 const scale=flags&8?v.slice(6,9):[1,1,1],translation=[v[0]+baseTranslation[0],v[1]+baseTranslation[1],-v[2]+baseTranslation[2]],matrix=[...rotation];
 for(let r=0;r<3;r++)for(let c=0;c<3;c++)matrix[r*4+c]=Math.fround(rotation[r*4+c]*scale[r]);
 matrix.splice(12,3,...translation);
 return{translation,rotation:quaternion(rotation),scale,matrix};
}
// Match the original type-6/type-7 arithmetic grouping. The fourth packed key
// uses a float32 intermediate before applying channel scale/minimum; this can
// change a later integer angle by one unit at a quantization boundary.
export function sceneScalarValues(animation,frame,raw){
 if(!raw)return sampleAni4(animation,frame)[0];
 const h=animation.header,key=h.keyCount===1?0:Math.max(0,Math.min(h.keyCount-1,(frame-h.firstFrame)*(h.keyCount-1)/(h.frameCount-1))),whole=Math.floor(key),sub=whole&3;
 return animation.nodes[0].curves.map(c=>{
  if(c.type>=16)return Math.fround(c.value);
  const fraction=c.interpolation==='STEP'?0:Math.fround(key-whole),p=animation.sourceOffset+h.keysOffset+(whole>>>2)*h.keyStride+c.keyByteOffset;
  if(c.type===7){
   const endpoint=o=>raw.readUInt16LE(o),factor=(o,q)=>{const a=endpoint(o+2),b=endpoint(o+4),c=endpoint(o+6);return q===3?((b&61440)>>>8)|((c&61440)>>>4)|(a>>>12):[a,b,c][q]&4095;},a=endpoint(p),b=endpoint(p+h.keyStride);let value;
   if(sub<3)value=a+(b-a)*(factor(p,sub)+fraction*(factor(p,sub+1)-factor(p,sub)))/4095;
   else{const first=Math.fround(a+(b-a)*factor(p,3)/4095),next=b+(endpoint(p+2*h.keyStride)-b)*factor(p+h.keyStride,0)/4095;value=first+fraction*(next-first);}
   return Math.fround(value*c.scale+c.minimum);
  }
  if(c.type===6){
   // Original qword constant at 0x764540 is not exactly 1/63.
   const factor=(o,q)=>((raw.readUInt32LE(o)>>>(8+q*6))&63)*0.015873020514845848,a=raw[p],b=raw[p+h.keyStride];let value;
   if(sub<3){const first=Math.fround(factor(p,sub));value=a+(b-a)*(first+fraction*(factor(p,sub+1)-first));}
   else{const first=Math.fround(a+Math.fround(factor(p,3))*(b-a)),next=b+(raw[p+2*h.keyStride]-b)*factor(p+h.keyStride,0);value=first+fraction*(next-first);}
   return Math.fround(value*c.scale+c.minimum);
  }
  throw Error(`Scene packed sampler unsupported curve ${c.type}`);
 });
}
export function scenePose(animation,frame,baseTranslation=[0,0,0],raw){
 if(animation.header.nodeCount!==1||animation.header.curveCount!==9)throw Error('Unsupported scene pose shape');
 return scenePoseFromValues(sceneScalarValues(animation,frame,raw),animation.nodes[0].flags,baseTranslation);
}
