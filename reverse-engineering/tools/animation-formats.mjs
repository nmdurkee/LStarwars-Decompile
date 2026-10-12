// Read-only parsers for this PC game's ANI4, legacy animation, and GHG hierarchy.
// Cross-version reference: opensagadev/saga ab97911d162d896d8f4b20e9df8e7d23a2f81557.
// Every pointer/range is checked against the actual PC carrier. No source mutation.
import crypto from 'node:crypto';
export const sha256=b=>crypto.createHash('sha256').update(b).digest('hex');
function need(test,message){if(!test)throw Error(message);}
function range(b,o,n,label){need(Number.isInteger(o)&&o>=0&&n>=0&&o+n<=b.length,`${label}: out of bounds ${o}+${n}/${b.length}`);}
const floats=(b,o,n)=>{range(b,o,n*4,'float array');return Array.from({length:n},(_,i)=>{const x=b.readFloatLE(o+i*4);need(Number.isFinite(x),`nonfinite float at ${o+i*4}`);return x;});};
const zstr=(b,o,max=256)=>{range(b,o,1,'string');const e=b.indexOf(0,o);need(e>=o&&e<o+max,'unterminated string');return b.toString('utf8',o,e);};
export const multiply=(a,b)=>Array.from({length:16},(_,p)=>{let s=0;for(let k=0;k<4;k++)s+=a[Math.floor(p/4)*4+k]*b[k*4+p%4];return s;});
export function parseAni4(b,options={}){
 range(b,0,60,'ANI4 header');need(b.readUInt32LE(0)===0x414e4934,'not ANI4');
 const h={nodeCount:b.readUInt16LE(4),keyCount:b.readUInt16LE(6),keyStride:b.readUInt16LE(8),frameCount:b.readUInt16LE(10),curveCount:b.readUInt16LE(12),firstFrame:b.readUInt16LE(14),endFrame:b[16],constantIndex:b[17],format:b[19],nextBlock:b.readUInt16LE(20),declaredEndFrame:b.readUInt16LE(22),minimum:b.readFloatLE(28),scale:b.readFloatLE(32),scaleMinOffset:b.readUInt32LE(36),constantsOffset:b.readUInt32LE(40),typesOffset:b.readUInt32LE(44),keysOffset:b.readUInt32LE(48),flagsOffset:b.readUInt32LE(52),extraPointer:b.readUInt32LE(56)};
 need((h.format===0||options.generic&&h.format<=3)&&h.nextBlock===0&&(h.curveCount===9||options.generic)&&(h.constantIndex===0||options.generic),'unsupported ANI4 variant');
 need(h.nodeCount>0&&h.nodeCount<=256&&h.keyCount>0&&h.frameCount>0,'invalid counts');
 need(Number.isFinite(h.minimum)&&Number.isFinite(h.scale),'invalid global scaling');
 const count=h.nodeCount*h.curveCount, mask=h.typesOffset+count*2;
 range(b,h.typesOffset,count*3,'types and interpolation masks');range(b,h.flagsOffset,h.nodeCount,'node flags');
 need(h.constantsOffset>=60&&h.constantsOffset<=h.typesOffset&&h.typesOffset<=h.flagsOffset,'unordered regions');
 if(h.keyStride)need((!h.scaleMinOffset&&options.generic||h.typesOffset<=h.scaleMinOffset&&h.scaleMinOffset<=h.keysOffset)&&h.keysOffset<=h.flagsOffset,'unordered dynamic regions');
 const constants=[];for(let p=h.constantsOffset;p<h.typesOffset;p+=2)constants.push(b.readUInt16LE(p));
 const nodes=Array.from({length:h.nodeCount},(_,i)=>({index:i,flags:b[h.flagsOffset+i],curves:[]}));let dynamic=0,keyBytes=0,scaledDynamic=0;let activeDynamic=0;
 for(let i=0;i<count;i++){
  const t=b.readUInt16LE(h.typesOffset+i*2), n=Math.floor(i/h.curveCount), c=i%h.curveCount, active=h.curveCount!==9?true:!!(nodes[n].flags&[2,1,8][Math.floor(c/3)]);
  const curve={channel:h.curveCount===9?(h.format&1?['tx','ty','tz','qx','qy','qz','sx','sy','sz']:['tx','ty','tz','rx','ry','rz','sx','sy','sz'])[c]:('curve_'+c),type:t,active,interpolation:(b[mask+i]&1)?'STEP':'LINEAR'};
  if(t>=16){const ci=t-16+h.constantIndex;need(ci<constants.length,'constant index beyond constant pool');curve.value=constants[ci]*h.scale+h.minimum;}
  else{
   need(t===6||(options.generic&&[7,8,9,10].includes(t)),`unsupported dynamic curve ${t}`);const bytes=t===7||t===9?8:4,scaled=t===6||t===7||t===9;
   if(scaled){const p=h.scaleMinOffset+scaledDynamic*8;range(b,p,8,'curve scale/min');curve.scale=b.readFloatLE(p);curve.minimum=b.readFloatLE(p+4);need(Number.isFinite(curve.scale)&&Number.isFinite(curve.minimum),'invalid curve scaling');scaledDynamic++;}
   curve.keyByteOffset=keyBytes;curve.values=[];if(t===8||t===10)curve.interpolation='STEP';if(t===10){curve.rawBits=[];curve.valueInterpretation='Raw packed float32 bits; nonfinite sentinels retained in rawBits and represented as null in values';}
   for(let key=0;key<h.keyCount;key++){
    const q=key&3,k=h.keysOffset+(key>>>2)*h.keyStride+keyBytes;range(b,k,bytes,'packed key');let value;
    if(t===6){range(b,k+h.keyStride,1,'next packed endpoint');const word=b.readUInt32LE(k),a=word&255,z=b[k+h.keyStride],weight=(word>>>(8+q*6))&63;value=(a+(z-a)*(weight/63))*curve.scale+curve.minimum;}
    else if(t===7){range(b,k+h.keyStride,2,'next packed16 endpoint');const a=b.readUInt16LE(k),z=b.readUInt16LE(k+h.keyStride),v1=b.readUInt16LE(k+2),v2=b.readUInt16LE(k+4),v3=b.readUInt16LE(k+6),weight=q===3?((v2&0xf000)>>>8)|((v3&0xf000)>>>4)|(v1>>>12):[v1,v2,v3][q]&4095;value=(a+(z-a)*weight/4095)*curve.scale+curve.minimum;}
    else if(t===9){value=b.readUInt16LE(k+q*2)*curve.scale+curve.minimum;}
    else{const ci=b[k+q];need(ci+(t===10?1:0)<constants.length,'table key beyond constant pool');if(t===8)value=constants[ci]>=32768?constants[ci]-65536:constants[ci];else{const tmp=Buffer.alloc(4),hi=constants[ci]>=32768?constants[ci]-65536:constants[ci],lo=constants[ci+1]>=32768?constants[ci+1]-65536:constants[ci+1];const bits=((hi<<16)|lo)>>>0;curve.rawBits.push(bits);tmp.writeUInt32LE(bits);value=tmp.readFloatLE(0);}}
    need(Number.isFinite(value)||t===10,'nonfinite decoded value');curve.values.push(Number.isFinite(value)?value:null);
   }
   keyBytes+=bytes;
   dynamic++;if(active)activeDynamic++;
  }
  nodes[n].curves.push(curve);
 }
 need(keyBytes===h.keyStride,'dynamic curve count does not match packed stride');
 need((scaledDynamic===0&&h.scaleMinOffset===0)||h.scaleMinOffset+scaledDynamic*8===h.keysOffset,'scale/min count does not match key offset');
 need(h.flagsOffset+h.nodeCount<=b.length,'flag count');
 return {format:'ANI4-PC',sourceSha256:sha256(b),sourceBytes:b.length,name:h.constantsOffset===60&&options.generic?null:zstr(b,60,h.constantsOffset-60),header:h,keyFramePositions:Array.from({length:h.keyCount},(_,i)=>h.firstFrame+(h.keyCount===1?0:i*(h.frameCount-1)/(h.keyCount-1))),nodes,validation:{dynamicCurves:dynamic,activeDynamicCurves:activeDynamic,constantPoolValues:constants.length,tailBytes:b.length-h.flagsOffset-h.nodeCount},limitations:['Channel values in source coordinates, rotation radians inferred from matching engine evaluator. Frame-to-seconds timing belongs to character configuration. No runtime pose validation.']};
}
export function parseAnimation(b){
 if(b.readUInt32LE(0)===0x414e4934)return parseAni4(b);
 range(b,0,64,'wrapped ANI5 header');need(b.readUInt32LE(4)===0x414e4935,'not ANI4 or wrapped ANI5');
 const table=b.readUInt32LE(0);range(b,table,4,'pointer table');const count=b.readUInt32LE(table);range(b,table+4,count*4,'pointer list');
 const copy=Buffer.from(b.subarray(4)),relocations=[];
 for(let i=0;i<count;i++){const field=table+4+i*4+b.readInt32LE(table+4+i*4);range(b,field,4,'relocated field');const v=b.readInt32LE(field);const target=v?field+v:0;if(v)range(b,target,1,'relocated target');copy.writeUInt32LE(target?target-4:0,field-4);relocations.push({field,target});}
 copy.writeUInt32LE(0x414e4934,0);const a=parseAni4(copy);a.format='ANI5-PC-pointer-block';a.sourceSha256=sha256(b);a.sourceBytes=b.length;a.wrapper={tableOffset:table,relocations,payloadOffset:4};return a;
}
export function sampleAni4(anim,frame){
 const h=anim.header,k=h.keyCount===1?0:Math.min(h.keyCount-1,Math.max(0,(frame-h.firstFrame)*(h.keyCount-1)/(h.frameCount-1))),i=Math.floor(k),f=k-i;
 return anim.nodes.map(n=>n.curves.map(c=>c.type>=16?c.value:c.values[i]+((c.values[Math.min(i+1,h.keyCount-1)]-c.values[i])*(c.interpolation==='STEP'?0:f))));
}
export function parseSkeleton(b){
 range(b,0,4,'GHG header');const nu20=b.readUInt32LE(0)+4;range(b,nu20,32,'NU20');need(b.toString('ascii',nu20,nu20+4)==='NU20','missing NU20');
 const ptr=o=>{range(b,o,4,'relative pointer');const v=b.readInt32LE(o);return v===0?0:o+v;};
 const header=ptr(nu20+28);range(b,header,0x1c4,'hierarchy header');need(b.toString('ascii',header-8,header-4)==='GSNH','not GSNH');
 const count=b.readUInt32LE(header+0x168),joints=ptr(header+0x16c),bind=ptr(header+0x170),inverse=ptr(header+0x174);
 need(count>0&&count<=256,`invalid joint count ${count}`);range(b,joints,count*96,'joints');range(b,bind,count*64,'bind matrices');range(b,inverse,count*64,'inverse bind matrices');
 const result=[];let maxInverseError=0;
 for(let i=0;i<count;i++){
  const o=joints+i*96,p=b[o+0x50];need(p===255||p<i,'non-topological joint parent');
  const local=floats(b,bind+i*64,16),inv=floats(b,inverse+i*64,16),world=p===255?local:multiply(local,result[p].worldBindMatrix);
  const product=multiply(world,inv);let error=0;for(let j=0;j<16;j++)error=Math.max(error,Math.abs(product[j]-(j%5===0?1:0)));
  maxInverseError=Math.max(maxInverseError,error);
  result.push({index:i,name:zstr(b,ptr(o+0x4c)),parent:p===255?null:p,flags:b[o+0x51],sourceOffset:o,animationBindMatrix:floats(b,o,16),localBindMatrix:local,inverseBindMatrix:inv,worldBindMatrix:world,inverseIdentityError:error});
 }
 const poiCount=b.readUInt32LE(header+0x180),poi=ptr(header+0x184),pois=[];range(b,poi,poiCount*80,'POI records');
 for(let i=0;i<poiCount;i++){const o=poi+i*80;need(b[o+68]===255||b[o+68]<count,'POI joint outside skeleton');pois.push({index:i,sourceOffset:o,matrix:floats(b,o,16),joint:b[o+68]===255?null:b[o+68],unknownWord:b.readUInt32LE(o+64),tailHex:b.subarray(o+69,o+80).toString('hex')});}
 const layerCount=b.readUInt32LE(header+0x190),layerPointer=ptr(header+0x194),layers=[];range(b,layerPointer,layerCount*20,'render layers');
 const special=p=>{if(!p)return null;range(b,p,12,'special handle');const display=ptr(p+8);if(display)range(b,display,208,'display special');return{handle:p,scene:ptr(p),legacySpecial:ptr(p+4),displaySpecial:display};};
 for(let i=0;i<layerCount;i++){const o=layerPointer+i*20,rigid=ptr(o+4),alternate=ptr(o+12);const arr=p=>{if(!p)return null;range(b,p,count*4,'per-joint render array');return Array.from({length:count},(_,j)=>special(ptr(p+j*4)));};layers.push({index:i,name:zstr(b,ptr(o)),sourceOffset:o,rigid:arr(rigid),smooth:special(ptr(o+8)),alternateRigid:arr(alternate),alternateSmooth:special(ptr(o+16))});}
 return {format:'GHG-PC-hierarchy',sourceSha256:sha256(b),sourceBytes:b.length,offsets:{nu20,header,joints,bind,inverse,poi,layerPointer},jointCount:count,joints:result,pointsOfInterest:pois,renderLayers:layers,validation:{maxInverseIdentityError:maxInverseError},matrixConvention:'Row-vector matrices in row-major order. local * parent = world; world * inverseBind approximates identity. Source coordinate units retained.'};
}
const identity=()=>[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1];
function rotateXYZ(x,y,z){const cx=Math.cos(x),sx=Math.sin(x),cy=Math.cos(y),sy=Math.sin(y),cz=Math.cos(z),sz=Math.sin(z);return[cy*cz,cy*sz,-sy,0,sx*sy*cz-cx*sz,sx*sy*sz+cx*cz,sx*cy,0,cx*sy*cz+sx*sz,cx*sy*sz-sx*cz,cx*cy,0,0,0,0,1];}
// Source-assisted reference evaluator. PC opcode validation and runtime remain separate.
// Continuous trigonometry approximates the engine's 16-bit-angle lookup tables.
export function evaluatePose(skeleton,animation,frame){
 const samples=sampleAni4(animation,frame),out=[],scales=[];
 for(let i=0;i<skeleton.jointCount;i++){
  if(i>=animation.header.nodeCount){out.push({local:identity(),world:identity()});scales.push([1,1,1]);continue;}
  const joint=skeleton.joints[i],v=samples[i],flags=animation.nodes[i].flags,parent=joint.parent,ps=parent===null?[1,1,1]:scales[parent];
  let m=flags&1?rotateXYZ(v[3],v[4],v[5]):identity();if(flags&32)m=multiply(m,joint.animationBindMatrix);
  const rotationMatrix=[...m],localScale=flags&8?v.slice(6,9):[1,1,1],compensation=[1,1,1];for(const k of [2,6,8,9,11,14])rotationMatrix[k]*=-1;
  let scale=[...ps];if(flags&8){for(let r=0;r<3;r++)for(let c=0;c<3;c++)m[r*4+c]*=v[6+r];scale=ps.map((x,j)=>x*v[6+j]);}
  if(flags&16){const inv=ps.every(x=>x!==0)?ps.map(x=>1/x):[0,0,0];compensation.splice(0,3,...inv);for(let r=0;r<3;r++)for(let c=0;c<3;c++)m[r*4+c]*=inv[c];scale=scale.map((x,j)=>x*inv[j]);}
  if(flags&2){m[12]=v[0];m[13]=v[1];m[14]=v[2];}
  for(const k of [2,6,8,9,11,14])m[k]*=-1;
  if(parent===null&&(flags&64))scale=[1,1,1];scales.push(scale);out.push({local:m,world:parent===null?m:multiply(m,out[parent].world),translation:m.slice(12,15),rotationMatrix,localScale,compensation});
 }
 return out;
}
function popcnt(v){v>>>=0;let n=0;while(v){v=(v&(v-1))>>>0;n++;}return n;}
export function parseBsa(b){
 range(b,0,12,'BSA carrier');need(b.readUInt32LE(0)===2,'unsupported legacy carrier');
 const base=b.readUInt32LE(4),abs=o=>{range(b,o,4,'legacy pointer');const v=b.readUInt32LE(o);return v?v-base:0;};
 const h=abs(8);range(b,h,24,'legacy animation header');
 const duration=b.readFloatLE(h),nodeCount=b.readUInt16LE(h+4),curveCount=b.readUInt16LE(h+6),chunkCount=b.readUInt16LE(h+8),curves=abs(h+12),types=abs(h+16),flags=abs(h+20),count=nodeCount*curveCount;
 need(Number.isFinite(duration)&&duration>=1&&nodeCount>0&&curveCount>0&&chunkCount>0,'invalid legacy dimensions');range(b,curves,count*4,'legacy curves');range(b,types,count,'legacy types');range(b,flags,nodeCount,'legacy flags');
 const result=[];let dynamic=0,keyCount=0,maxMaskTimeDifference=0;
 for(let i=0;i<count;i++){
  const type=b[types+i],entry={node:Math.floor(i/curveCount),curve:i%curveCount,type};
  if(type===0){entry.value=b.readFloatLE(curves+i*4);need(Number.isFinite(entry.value),'nonfinite constant');}
  else{
   need(type===1||type===2,`unsupported legacy type ${type}`);const p=abs(curves+i*4);range(b,p,12,'legacy key descriptor');const mp=abs(p),op=abs(p+4),kp=abs(p+8);range(b,mp,chunkCount*4,'key masks');range(b,op,chunkCount*2,'key offsets');
   const masks=[],offsets=[],maskFrames=[];let n=0;
   for(let chunk=0;chunk<chunkCount;chunk++){const mask=b.readUInt32LE(mp+chunk*4),offset=b.readUInt16LE(op+chunk*2);masks.push(mask);offsets.push(offset);need(offset===n,`key-mask offset mismatch ${offset}/${n}`);n+=popcnt(mask);for(let bit=0;bit<32;bit++)if((mask>>>bit)&1)maskFrames.push(chunk*32+bit+1);}
   need(n>0,'empty animated curve');const storedCount=(mp-kp-(type===2?8:0))/(type===1?16:4);need(storedCount===n||storedCount===n+1,'unexpected legacy key storage extent');entry.maskedKeyCount=n;entry.terminalKeyCount=storedCount-n;range(b,kp,(type===1?16*storedCount:8+4*storedCount),'legacy key data');const keys=[];const tangentScale=type===2?b.readFloatLE(kp):null,valueScale=type===2?b.readFloatLE(kp+4):null;
   for(let k=0;k<storedCount;k++){
    const q=kp+(type===1?16*k:8+4*k),key=type===1?{frame:b.readFloatLE(q),reciprocalSpan:b.readFloatLE(q+4),value:b.readFloatLE(q+8),tangent:b.readFloatLE(q+12)}:{frame:b[q+3]+1,value:b.readInt16LE(q)*valueScale,tangent:b.readInt8(q+2)*tangentScale};
    for(const v of Object.values(key))need(Number.isFinite(v),'nonfinite legacy key');if(k)need(key.frame>=keys[k-1].frame,'unordered legacy keys');if(k<n)maxMaskTimeDifference=Math.max(maxMaskTimeDifference,Math.abs(key.frame-maskFrames[k]));else key.unmarkedTerminal=true;keys.push(key);
   }
   entry.keys=keys;entry.interpolation='CUBIC_HERMITE';entry.sourceOffsets={descriptor:p,keyMasks:mp,keyOffsets:op,keyData:kp};entry.masks=masks;entry.chunkKeyOffsets=offsets;if(type===2)entry.quantization={valueScale,tangentScale};dynamic++;keyCount+=storedCount;
  }
  result.push(entry);
 }
 return {format:'BSA-legacy-v2',sourceSha256:sha256(b),sourceBytes:b.length,header:{originalPointerBase:base,headerOffset:h,duration,nodeCount,curveCount,chunkCount,curveOffset:curves,typeOffset:types,flagOffset:flags},nodeFlags:[...b.subarray(flags,flags+nodeCount)],curves:result,validation:{dynamicCurves:dynamic,keyCount,maxMaskTimeDifference},limitations:['Decoded blendshape weights by node and curve index. Association to character morph target names/buffers is not yet recovered. Frame domain begins at 1.']};
}
export function sampleLegacyCurve(c,frame){
 if(c.type===0)return c.value;const keys=c.keys;if(frame<=keys[0].frame)return keys[0].value;if(frame>=keys.at(-1).frame)return keys.at(-1).value;
 let i=0;while(i+1<keys.length&&keys[i+1].frame<=frame)i++;const a=keys[i],b=keys[i+1],span=b.frame-a.frame,t=(frame-a.frame)/span,t2=t*t,t3=t2*t;
 return (2*t3-3*t2+1)*a.value+(t3-2*t2+t)*span*a.tangent+(-2*t3+3*t2)*b.value+(t3-t2)*span*b.tangent;
}
