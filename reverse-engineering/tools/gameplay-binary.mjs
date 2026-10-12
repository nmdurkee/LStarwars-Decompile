// Read-only NU2 gameplay decoders. Layout reference: BrickBench revision
// 3d149673e1f70dc04425ff30fcc00ec2194d2743, AI2Loader/TerrainLoader/GizLoader.
// Unknown fields retain numeric/byte values and source offsets; coordinates stay native.
import crypto from 'node:crypto';
export const reference='https://github.com/BrickBench/BrickBench/tree/3d149673e1f70dc04425ff30fcc00ec2194d2743/src/com/opengg/loader/game/nu2';
export const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
export class Reader {
  constructor(b,start=0,end=b.length){this.b=b;this.o=start;this.end=end;this.opaque=[];}
  need(n){if(!Number.isInteger(n)||n<0||this.o+n>this.end)throw Error(`Out of bounds at ${this.o}, need ${n}, end ${this.end}`);}
  count(n,max=1000000){if(n<0||n>max)throw Error(`Implausible count ${n} at ${this.o}`);return n;}
  u8(){this.need(1);return this.b[this.o++];} i8(){this.need(1);return this.b.readInt8(this.o++);}
  u16(){this.need(2);const n=this.b.readUInt16LE(this.o);this.o+=2;return n;}
  i16(){this.need(2);const n=this.b.readInt16LE(this.o);this.o+=2;return n;}
  u32(){this.need(4);const n=this.b.readUInt32LE(this.o);this.o+=4;return n;}
  i32(){this.need(4);const n=this.b.readInt32LE(this.o);this.o+=4;return n;}
  f(){this.need(4);const n=this.b.readFloatLE(this.o);this.o+=4;return Number.isFinite(n)?n:{nonfiniteBits:this.b.subarray(this.o-4,this.o).toString('hex')};}
  vec(){return [this.f(),this.f(),this.f()];}
  floats(n){return Array.from({length:this.count(n)},()=>this.f());}
  str(n){this.need(n);const s=this.b.toString('latin1',this.o,this.o+n).split('\0')[0];this.o+=n;return s;}
  s8(){return this.str(this.u8());}s32(){return this.str(this.count(this.u32(),1048576));}
  raw(n,label='unknown'){this.need(n);const x={offset:this.o,length:n,label,hex:this.b.subarray(this.o,this.o+n).toString('hex')};this.o+=n;return x;}
  skip(n,label){const x=this.raw(n,label);this.opaque.push(x);return x;}
  tail(){return this.o<this.end?this.raw(this.end-this.o,'unparsed tail'):null;}
}
const angle=r=>{const raw=r.i16();return {raw,degrees:raw*180/32767,conversion:'BrickBench short angle convention'};};
export function decodeAI2(b){
 const r=new Reader(b);const version=r.u32(),pathCount=r.count(r.u32(),10000);if(version<1||version>20)throw Error(`Unsupported AI2 version ${version}`);
 const out={format:'AI2',version,bytes:b.length,sha256:sha(b),reference:reference+'/ai/AI2Loader.java',paths:[],triggers:[],locators:[],locatorSets:[],creatures:[],unknownRegions:r.opaque,warnings:[]};
 for(let p=0;p<pathCount;p++){
  const x={offset:r.o,name:r.str(16),pointCount:r.u8(),unknownByte:r.u8(),connections:[],points:[]};const n=r.count(version===1?r.u8():r.u16(),65535);
  for(let i=0;i<n;i++){const offset=r.o,to=r.u8(),from=r.u8();const flags=()=>version<9?r.u8():version<12?r.u16():r.u32();x.connections.push({offset,to,from,toFlags:flags(),fromFlags:flags(),unknownShorts:[r.u16(),r.u16()],distanceCandidates:[r.f(),r.f()]});}
  if(version===1)r.skip(1,'version1 path byte');
  for(let i=0;i<x.pointCount;i++){
   const q={offset:r.o,index:i,name:r.s32(),position:r.vec(),xzSize:r.f()};q.minY=version<8?q.position[1]-0.2:r.f();q.maxY=version<8?q.position[1]+0.2:r.f();const cn=r.u8();q.unknownBytes=[r.u8(),r.u8(),r.u8()];q.unknownShort=r.u16();q.unknownSignedByte=r.i8();q.specialObject=r.s8();if(q.specialObject)q.specialObjectPosition=r.vec();q.connectionIndices=Array.from({length:cn},()=>r.u16());if(cn%2)q.oddConnectionPadding=r.u16();if(version>4)q.unknownShortPair=[r.u16(),r.u16()];q.length=r.o-q.offset;for(const id of q.connectionIndices)if(id>=n)out.warnings.push({offset:q.offset,problem:'connection index out of range',id});x.points.push(q);
  }
  x.routingMatrix=r.raw(x.pointCount*x.pointCount,'uninterpreted point routing matrix');
  if(version>4){x.routingGroups=[];const count=r.u8();for(let i=0;i<count;i++){const g={offset:r.o},len=r.u8();if(len){g.name=r.str(len);g.count3=r.u8();g.count4=r.u8();g.unknown=[r.u8(),r.u8()];if(x.pointCount&&g.count3){g.pointMap=r.raw(x.pointCount);g.indices=r.raw(g.count3);g.matrix=r.raw(g.count3*g.count3);if(g.count4)g.list4=r.raw(g.count4);}}const extra=r.u8();g.extraLists=Array.from({length:extra},()=>r.raw(r.u8()));x.routingGroups.push(g);}}
  if(version>18){const count=r.u8();x.extraTriples=Array.from({length:count},()=>[r.u8(),r.u16()]);}
  x.length=r.o-x.offset;out.paths.push(x);
 }
 if(version>18){const n=r.u16();out.globalRoutingLists=Array.from({length:n},()=>r.raw(r.u8(),'unknown global routing list'));}
 const triggerCount=r.count(r.u32(),100000);for(let i=0;i<triggerCount;i++){const x={offset:r.o,name:r.str(16),position:r.vec(),halfSize:r.vec(),angle:angle(r),unknownBytes:[r.u8(),r.u8()]};x.length=r.o-x.offset;out.triggers.push(x);}
 if(pathCount){
  if(version>=6){const n=r.count(r.u32(),100000);for(let i=0;i<n;i++){const x={offset:r.o,index:i,name:r.str(16),position:r.vec(),angle:angle(r),pathIdCandidate:r.u8(),unknownByte:r.u8(),connectionCandidate:r.u16(),unknownFloats:[r.f(),r.f()]};if(version>=15)x.unknownInt=r.u32();x.length=r.o-x.offset;out.locators.push(x);}
   if(version>=18){const n=r.count(r.u32(),100000);for(let i=0;i<n;i++){const x={offset:r.o,name:r.str(16)};x.locatorIndices=Array.from({length:r.count(r.u32(),100000)},()=>r.u8());x.locatorNames=x.locatorIndices.map(j=>out.locators[j]?.name??null);if(x.locatorNames.includes(null))out.warnings.push({offset:x.offset,problem:'locator-set index out of range'});x.length=r.o-x.offset;out.locatorSets.push(x);}}
  }
  const n=r.count(r.u32(),100000);for(let i=0;i<n;i++){
   const x={offset:r.o,name:r.str(16),script:r.str(16),characterType:r.str(version>=14?32:16),position:r.vec(),angle:angle(r)};
   if(version>=16)x.unknownV16Byte=r.u8();x.unknownLeadingBytes=[r.u8(),r.u8()];x.unknownInt1=r.u32();x.unknownFloats1=r.floats(2);x.unknownInt2=r.u32();x.unknownBytes2=[r.u8(),r.u8()];x.unknownShort=r.u16();if(version>=3)x.unknownFloats3=r.floats(4);
   if(version>=4){x.hasTrigger1=r.u32();if(x.hasTrigger1)x.trigger1=r.str(16);}
   if(version>=6){x.hasLocator1=r.u32();if(x.hasLocator1)x.locator1=r.str(16);}
   if(version>=17){x.hasLocator2=r.u32();if(x.hasLocator2)x.locator2=r.str(16);}
   if(version>=8){x.unknownBytes3=[r.u8(),r.u8(),r.u8()];x.hasTrigger2=r.u8();x.unknownFloats4=r.floats(2);if(version>=10)x.unknownFloat10=r.f();if(x.hasTrigger2===1)x.trigger2=r.str(16);if(version>=11){x.unknownFloats11=r.floats(4);x.unknownInt11=r.u32();}}
   x.length=r.o-x.offset;out.creatures.push(x);
  }
 }
 if(pathCount&&version>12&&r.o<r.end){
  const start=r.o,candidate=new Reader(b,start);try{const count=candidate.count(candidate.u32(),100000),records=[];for(let i=0;i<count;i++){const q={offset:candidate.o,position:candidate.vec(),unknownFloats1:candidate.floats(3)};if(version<15)q.unknownBytes1=[candidate.u8(),candidate.u8(),candidate.u8()];else{q.unknownInt=candidate.u32();q.unknownFloats2=candidate.floats(2);q.unknownBytes1=[candidate.u8(),candidate.u8(),candidate.u8()];}q.unknownByte2=candidate.u8();q.specialObject=candidate.s8();if(q.specialObject){q.specialObjectPosition=candidate.vec();if(version>14)q.unknownInt2=candidate.u32();}q.length=candidate.o-q.offset;records.push(q);}out.additionalSpatialRecords={offset:start,count,records,interpretation:'Layout candidate from commented BrickBench object6 block; field semantics unresolved'};r.o=candidate.o;}catch(e){out.additionalSpatialCandidateError={offset:start,error:e.message};}
 }
 const remaining=r.end-r.o;
 if(remaining>=13&&b.subarray(r.o,r.o+13).equals(Buffer.from('050000004c45474f0001000000','hex'))){out.labelFooter={offset:r.o,length:13,nameLength:r.u32(),name:r.str(5),unknownWord:r.u32()};}
 if(r.end-r.o===4&&b.readUInt32LE(r.o)===0)out.zeroTrailer={offset:r.o,value:r.u32()};
 out.parsedBytes=r.o;out.unknownTail=r.tail();out.completeStructuralParse=out.unknownTail===null;return out;
}
export function decodeTerrain(b){
 const h=new Reader(b),contentEnd=h.u32()*2;if(contentEnd<4||contentEnd+2>b.length)throw Error('Invalid terrain object table offset');const t=new Reader(b,contentEnd),objectCount=t.u16();t.o=contentEnd;t.need(objectCount*52);
 const out={format:'TER',bytes:b.length,sha256:sha(b),reference:reference+'/terrain/TerrainLoader.java',contentEnd,objectCount,objects:[],warnings:[],faceSchema:['offset','minX','maxX','minY','maxY','minZ','maxZ','p1x','p1y','p1z','p2x','p2y','p2z','p3x','p3y','p3z','p4x','p4y','p4z','normal1x','normal1y','normal1z','normal2x','normal2y','normal2z','property1','property2','flag1','flag2']};
 let dataOffset=4;for(let i=0;i<objectCount;i++){
  const q=new Reader(b,t.o,t.o+52),x={index:i,tableOffset:t.o,tableHeader:q.raw(4),dataOffset};x.dataLength=q.u32()*2;x.position=q.vec();x.kind=q.u16();x.platformIndex=q.u16();x.unknownDefinition=q.raw(20);x.unknownInt=q.u32();x.unknownShorts=[q.u16(),q.u16()];
  if(x.dataLength<0||dataOffset+x.dataLength>contentEnd)throw Error(`Terrain content range overlaps object table at object ${i}`);const r=new Reader(b,dataOffset,dataOffset+x.dataLength);
  if(x.kind===0||x.kind===1){x.blocks=[];while(r.o<r.end){const offset=r.o,marker=r.i8();if(marker<0){x.terminator={offset,marker};if(marker===-1&&r.end-r.o===3&&r.b.subarray(r.o,r.end).every(x=>x===255)){x.terminator.word=0xffffffff;r.o=r.end;}break;}const block={offset,marker,unknownByte:r.u8(),faceCount:r.u16(),xzBounds:r.floats(4),faces:[]};r.need(block.faceCount*100);for(let j=0;j<block.faceCount;j++)block.faces.push([r.o,...r.floats(24),r.u8(),r.u8(),r.u8(),r.u8()]);x.blocks.push(block);}}
  else if(x.kind===2){x.magic=r.u32();if(x.magic!==0x12345678)out.warnings.push({index:i,problem:'unexpected wall magic',value:x.magic});x.wallPointCount=r.u16();x.wallUnknown=r.u16();r.need(x.wallPointCount*12);x.wallPoints=Array.from({length:x.wallPointCount},()=>r.vec());}
  else out.warnings.push({index:i,problem:'unknown terrain object kind',kind:x.kind});
  x.parsedBytes=r.o-dataOffset;x.unknownTail=r.tail();out.objects.push(x);dataOffset+=x.dataLength;t.o+=52;
 }
 out.contentCoverageEnd=dataOffset;out.contentGap=dataOffset<contentEnd?new Reader(b,dataOffset,contentEnd).tail():null;out.tableEnd=t.o;
 if(t.end-t.o>=4&&b.readUInt32LE(t.o)===0){out.tableTerminator={offset:t.o,value:t.u32()};if(t.end-t.o>=4){const count=b.readUInt32LE(t.o);if(t.end-t.o===4+68*count){out.auxiliaryRecords={offset:t.o,count:t.u32(),recordLength:68,interpretation:'Observed fixed-width tail records; field semantics unresolved',records:Array.from({length:count},()=>t.raw(68,'unknown terrain auxiliary record'))};}}}
 out.unknownTail=t.tail();return out;
}

const commonRefs=r=>{const version=r.u8(),count=r.u8();return {version,items:Array.from({length:count},()=>{const x={offset:r.o,name:r.s8(),values:[r.f(),r.f()]};if(version>=2)x.unknownInt=r.u32();return x;})};};
export function decodeGiz(b){
 const r=new Reader(b),header=r.u32();const out={format:'GIZ',header,bytes:b.length,sha256:sha(b),reference:reference+'/gizmo/GizLoader.java',chunks:[]};if(header===0&&b.every(x=>x===0)){out.zeroFilledPlaceholder=true;out.placeholderBytes=b.length;return out;}if(header!==1)throw Error(`Unsupported GIZ header ${header}`);let terminated=false;
 while(r.o+4<=r.end){const offset=r.o,nameLength=r.count(r.u32(),256);if(nameLength===0){terminated=true;break;}const name=r.str(nameLength),length=r.u32();if(r.o+length>r.end){out.truncatedChunk={offset,name,payloadOffset:r.o,declaredLength:length,availableLength:r.end-r.o};out.unknownTail=r.tail();return out;}const c=new Reader(b,r.o,r.o+length),x={offset,name,payloadOffset:r.o,payloadLength:length,records:[]};
  try{decodeGizmoPayload(c,x);x.parsedBytes=c.o-x.payloadOffset;x.unknownTail=c.tail();}catch(e){x.error=e.message;x.parsedBytes=c.o-x.payloadOffset;x.unknownTail=c.tail();}out.chunks.push(x);r.o+=length;
 }
 if(!terminated)throw Error('Missing GIZ terminator');out.unknownTail=r.tail();return out;
}
export function decodePak(b){
 const r=new Reader(b),magic=r.u32();if(magic!==0x1234567a)throw Error(`Unsupported PAK magic ${magic.toString(16)}`);const count=r.count(r.u32(),100000),declaredSize=r.u32();if(declaredSize!==b.length)throw Error('PAK declared size differs from carrier');const headerWords=[r.u32(),r.u32(),r.u32()],out={format:'PAK',magic,bytes:b.length,sha256:sha(b),headerWords,count,entries:[]};r.need(count*28);
 for(let i=0;i<count;i++){const x={index:i,recordOffset:r.o,nameOffset:r.u32(),dataOffset:r.u32(),size:r.u32(),flags:r.u32(),unknownWords:[r.u32(),r.u32(),r.u32()]};if(x.nameOffset<24+count*28||x.nameOffset>=b.length||x.dataOffset+x.size>b.length)throw Error(`PAK member bounds invalid at ${i}`);const end=b.indexOf(0,x.nameOffset);if(end<0||end-x.nameOffset>4096)throw Error('Unterminated PAK member name');x.name=b.toString('latin1',x.nameOffset,end);x.sha256=sha(b.subarray(x.dataOffset,x.dataOffset+x.size));out.entries.push(x);}
 return out;
}
function decodeGizmoPayload(r,x){
 const saga='https://github.com/opensagadev/saga/tree/ab97911d162d896d8f4b20e9df8e7d23a2f81557/src/legoapi';
 if(x.name==='ShadowEditor'){x.layoutReference=saga+'/gizmos/fx/edgizshadowmachine.cpp';x.version=r.u8();x.declaredCount=r.u8();const v=x.version;for(let i=0;i<x.declaredCount;i++){const q={offset:r.o,direction:r.vec(),field0c:r.f()};if(v>1)q.fields10_14=r.floats(2);if(v>2)q.fields18_1c=r.floats(2);if(v>3)q.field20=r.f();if(v>4)q.discardedFloats=r.floats(2);if(v>5)q.fields24_2c=r.floats(3);if(v>6)q.field30=r.f();if(v>7)q.preset=r.u32();q.length=r.o-q.offset;x.records.push(q);}x.decoderStatus=r.o===r.end?'records consume full payload':'records parsed with unknown tail';return;}
 const supported=['GizForce','GizObstacle','GizBuildit','GizTurret','BombGenerator','GizmoPickup','Panel','HatMachine','Lever','ZipUp','Tube','Torp Machine','GizTimer','PushBlocks','MiniCut','blowup','Spinner','Grapple','Plug','Techno'];if(!supported.includes(x.name)){x.decoderStatus='opaque payload; no field interpretation';return;}
 const compact=['GizForce','GizObstacle','GizBuildit','GizTurret','BombGenerator'].includes(x.name);x.version=compact?r.u8():r.u32();x.declaredCount=compact?r.u16():r.u32();const v=x.version,n=r.count(x.declaredCount,100000);
 const record=fn=>{for(let i=0;i<n;i++){const start=r.o,q=fn(i)||{};q.offset=start;q.length=r.o-start;x.records.push(q);}};
 const animSet=(callbackBytes=0)=>{const version=r.u8(),count=r.u8();return{version,records:Array.from({length:count},()=>{const q={offset:r.o,name:r.s8(),startFrame:r.f(),endFrame:r.f()};if(version>1)q.flags=r.u32();if(q.name&&callbackBytes)q.callbackData=Array.from({length:callbackBytes},()=>r.u8());q.length=r.o-q.offset;return q;})};};
 if(x.name==='GizTurret'){
  x.layoutReference=saga+'/gizmos/traps/gizturret.cpp';record(()=>{const q={name:r.str(16),animationSet:animSet(v>2?2:0),position:r.vec(),field30:r.vec(),field3c:r.vec(),field48:r.vec(),integerFields:Array.from({length:6},()=>r.i32())};if(v>1)q.behaviorFlags=r.u32();q.field74Vectors=Array.from({length:r.u8()},()=>r.vec());q.fieldec=r.f();q.fieldf0=r.f();q.reflectionAlpha=r.f();q.fireInterval=r.f();q.pitchTurnSpeed=r.f();q.yawTurnSpeed=r.f();q.shortFields=[r.i16(),r.i16(),r.i16()];q.field114=r.vec();if(v>5)q.field120=r.f();q.field12f=r.u8();if(v>3){q.field131=r.u8();q.baseRotation=angle(r);}q.boltType=r.s8();q.sound1=r.s8();q.sound2=r.s8();if(v>6)q.sound3=r.s8();q.blowupType=r.s8();q.field134=r.i16();return q;});
 }else if(x.name==='BombGenerator'){
  x.layoutReference=saga+'/gizmos/traps/gizbombgen.cpp';record(()=>({name:r.str(16),position:r.vec(),interval:r.i32(),animationSet:animSet()}));
 }else if(x.name==='Spinner'){
  x.layoutReference=saga+'/gizmos/door/gizspinner.cpp';record(()=>{const q={name:r.s8(),position:r.vec(),initialRotation:angle(r),specialObject:r.s8(),outputCount:r.u8()};if(v>1)q.type=r.u8();if(v>2){q.stateFlags=r.u32();q.field2d8=r.f();}if(v>3)q.animationSpeed=r.f();if(v>5)q.flags=r.u8();if(v>4)q.animationSet=animSet();else q.legacyObjects=Array.from({length:r.u8()},()=>{const z={name:r.s8()};if(v>2)z.frames=r.floats(2);return z;});if(v>6)q.animationPoints=r.floats(q.outputCount);if(v>7)q.field98=r.f();if(v>8)q.initialAnimationPoint=r.f();return q;});
 }else if(['Grapple','Plug','Techno'].includes(x.name)&&n===0){x.emptyCollection=true;
 }else if(x.name==='blowup'){
  if(v<2)throw Error('blowup version below 2 is not supported');x.instanceCount=r.count(r.u32(),100000);record(()=>{
   const q={name:r.s8(),specialObject:r.s8()};q.particleReferences=v<17?[v<5?r.u16():r.s8()]:[r.s8(),r.s8()];if(v>3)q.ptlReferences=[r.s8(),r.s8(),r.s8()];if(v>25)q.references26=[r.s8(),r.s8()];if(v>26)q.references27=[r.s8(),r.s8()];q.unknownInt=r.u32();if(v>=7){q.studCount=r.u32();q.unknownByte7=r.u8();q.unknownFloat7=r.f();}if(v>8)q.decalReference=r.s8();if(v>=14)q.values14=r.floats(2);if(v>=15)q.bytes15=[r.u8(),r.u8()];if(v>=16){q.hasExtra16=r.u8();if(q.hasExtra16)q.extra16={position:r.vec(),values:r.floats(5),short:r.u16(),bytes:[r.u8(),r.u8()]};}if(v>=18){q.emitterReferences=v<22?[r.s8()]:[r.s8(),r.s8(),r.s8(),r.s8()];q.emitterByte=r.u8();q.emitterFloats=r.floats(2);}if(v>18)q.shadowReference=r.s8();if(v>19)q.swapReference=r.s8();if(v>22)q.value23=r.f();if(v>23)q.value24=r.f();return q;
  });x.instances=[];for(let i=0;i<x.instanceCount;i++){
   const q={offset:r.o,name:r.s8(),reference:r.s8(),position:r.vec(),shorts:[r.u16(),r.u16(),r.u16()]};q.unknownA=v<20?r.u16():r.u32();if(v===28)q.unknownPadding28=r.u32();if(v>29)q.unknownInt30=r.u32();q.unknownInt=r.u32();q.bytes=[r.u8(),r.u8()];if(v>3)q.byte4=r.u8();if(v>5)q.value6=r.f();if(v>=8)q.values8=r.floats(2);if(v>8){q.shorts9=[r.u16(),r.u16(),r.u16()];q.values9=r.floats(3);}if(v>=10)q.value10=r.f();if(v>=11)q.values11=r.floats(3);if(v>=12)q.byte12=r.u8();if(v>=13)q.shorts13=[r.u16(),r.u16()];if(v>18){q.shorts19=[r.u16(),r.u16(),r.u16()];q.values19=r.floats(4);}if(v>20)q.value21=r.f();if(v>22)q.value23=r.f();if(v>30)q.value31=r.f();q.length=r.o-q.offset;x.instances.push(q);
  }
 }else if(x.name==='GizmoPickup'){
  if(v>=3)x.unknownInt=r.u32();if(v>=5)x.unknownFloats=r.floats(2);const types={s:'silver_stud',g:'gold_stud',b:'blue_stud',p:'purple_stud',u:'powerup',m:'minikit',c:'challenge_minikit',r:'red_brick',h:'heart',t:'torpedo'};
  record(()=>{const q={name:r.str(8),position:r.vec(),typeCode:r.u8()};q.typeLabel=types[String.fromCharCode(q.typeCode)]??'unknown';if(v>=2)q.unknownByte2=r.u8();if(v>=3)q.unknownByte3=r.u8();return q;});
 }else if(x.name==='Panel'||x.name==='HatMachine'){
  record(()=>{const q={name:r.s32(),position:r.vec(),angle:angle(r),type:r.u8()};if(x.name==='Panel'){q.typeLabel=['astromech','protocol_droid','bounty_hunter','stormtrooper'][q.type]??'unknown';if(v>=3)q.frontInvisible=r.u8();if(v>=4){q.activationOffset=r.vec();q.activationRange=r.f();}if(v>=5)q.floorInvisible=r.u8();if(v>=6){q.alternativeFace=r.u8();q.alternativeBody=r.u8();}if(v>=7)q.unknown7=r.u8();if(v>=8)q.unknown8=r.u8();}else{q.typeLabel=['random','leia','fedora','top_hat','baseball_cap','stormtrooper','bounty_hunter','droid_panel'][q.type]??'unknown';if(v>=3)q.studColor=r.u8();if(v>=4){q.activationOffset=r.vec();q.activationRange=r.f();}if(v>=5)q.floorInvisible=r.u8();}return q;});
 }else if(x.name==='Lever'){
  record(()=>{const q={name:r.str(16),position:r.vec(),angle:angle(r),color:r.u8()};if(v>=2)q.multiplePulls=r.u8();if(v>=3)q.pullTime=r.f();if(v>=4)q.invisible=r.u8();if(v>=5){q.activationOffset=r.vec();q.activationRange=r.f();}if(v>=6)q.floorInvisible=r.u8();return q;});
 }else if(x.name==='ZipUp'){
  record(()=>{const q={name:r.str(16),start:r.vec(),axis:r.vec(),end:r.vec(),unknownShorts:[r.u16(),r.u16()],swing:r.u8(),unknownByte:r.u8(),twoWay:r.u8()};if(v>=2)q.hookVisible=r.u8();if(v>=3)q.unknown3=r.u8();if(v>=4)q.floorVisible=r.u8();return q;});
 }else if(x.name==='Tube'){
  record(()=>{const q={name:r.str(16),position:r.vec(),height:r.f(),radius:r.f()};if(v>=2)q.unknown2=r.u8();if(v>=3)q.specialObject=r.s8();return q;});
 }else if(x.name==='Torp Machine'){
  if(v>=3)x.unknownFloat=r.f();record(()=>{const q={name:r.s32(),position:r.vec(),angle:angle(r)};if(v>=2)q.unknown2=r.u8();return q;});
 }else if(x.name==='GizTimer')record(()=>({name:r.s32(),time:r.f(),unknownShort:r.u16(),position:r.vec()}));
 else if(x.name==='PushBlocks')record(()=>{const q={name:r.s8(),unknownFloat:r.f(),unknownBytes:[r.u8(),r.u8(),r.u8(),r.u8()]};if(v>=4)q.unknown4=[r.u8(),r.u8()];if(v>=5)q.unknown5=[r.u8(),r.u8()];if(v>2)q.linkedObjects=Array.from({length:r.u8()},()=>r.s8());return q;});
 else if(x.name==='MiniCut')record(()=>({name:r.s8(),values:r.floats(5),references:Array.from({length:r.u8()},()=>({name:r.s8(),values1:r.floats(4),shorts:[r.u16(),r.u16(),r.u16()],values2:r.floats(2)}))}));
 else if(x.name==='GizForce')record(()=>{
  const q={name:r.str(16),position:r.vec()};if(v===1)q.unknownVector1=r.vec();q.value1=r.f();if(v>=8)q.value8=r.f();q.value2=r.f();if(v===1){q.unknownVector2=r.vec();q.unknownShort1=r.u16();}q.unknownInt=r.u32();q.byte1=r.u8();if(v>10)q.byte11=r.u8();q.byte2=r.u8();if(v===1)q.byteV1=r.u8();const iv=r.u8(),cnt=r.u8();q.references={version:iv,items:Array.from({length:cnt},()=>{const o={name:r.s8(),values:r.floats(2)};if(iv>=2)o.unknownInt=r.u32();if(o.name&&v>8)o.unknownShort=r.u16();return o;})};q.values=r.floats(2);if(v>5)q.value6=r.f();if(v>=7)q.value7=r.f();if(v>2)q.value3=r.f();if(v>3){q.refOrShort=v<5?r.u16():r.s8();q.studNumber=r.u16();q.unknownShorts=[r.u16(),r.u16()];q.unknownVector=r.vec();}if(v>=10)q.value10=r.f();if(v>13)q.referenceStrings=[r.s8(),r.s8(),r.s8()];return q;
 });
 else if(x.name==='GizObstacle')record(()=>{
  const q={name:r.str(16),position:r.vec()};if(v>=2)q.vector2=r.vec();q.values=r.floats(2);if(v>=3){q.vector3=r.vec();q.short3=r.u16();}q.int1=r.u32();if(v>11)q.int12=r.u32();if(v===6)q.extra6=[r.u16(),r.u8()];q.bytes=[r.u8(),r.u8()];if(v>=7)q.byte7=r.u8();const iv=r.u8(),cnt=r.u8();q.references={version:iv,items:Array.from({length:cnt},()=>{const z={name:r.s8(),values:r.floats(2)};if(iv>=2)z.int=r.u32();if(z.name&&v>=8)z.short=r.u16();return z;})};if(v>=4)q.value4=r.f();if(v>=5)q.value5=r.f();if(v>7)q.value8=r.f();if(v>8){q.refOrShort=v<10?r.u16():r.s8();q.shorts=[r.u16(),r.u16(),r.u16()];q.vector4=r.vec();}if(v>=11)q.value11=r.f();if(v>=13)q.reference13=r.s8();if(v>13)q.reference14=r.s8();return q;
 });
 else if(x.name==='GizBuildit')record(()=>{
  const q={name:r.str(16),position:r.vec()},iv=r.u8();q.references={version:iv,items:[]};if(iv){const cnt=r.u8();q.references.items=Array.from({length:cnt},()=>{const z={name:r.s8(),values:r.floats(2)};if(iv>=2)z.int=r.u32();return z;});}q.value=r.f();if(v<7)q.oldFloat=r.f();q.studCount=r.u16();q.short1=r.u16();q.bytes=[r.u8(),r.u8()];if(v>5)q.float6=r.f();if(v>6){q.refOrShort=v<8?r.u16():r.s8();q.shorts=[r.u16(),r.u16()];q.vector=r.vec();}if(v>=9)q.float9=r.f();if(v<4){q.oldBytes=[r.u8()];if(v>1)q.oldBytes.push(r.u8());if(v>2)q.oldBytes.push(r.u8());}else q.short4=r.u16();if(v>4){q.short5=r.u16();q.reference5=r.s8();}return q;
 });
 else{x.decoderStatus='opaque payload; only header fields interpreted';return;}
 x.decoderStatus=r.o===r.end?'records consume full payload':'records parsed with unknown tail';
}
