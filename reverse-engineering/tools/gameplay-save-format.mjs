// Read-only PC save format decoder. Takes caller-supplied bytes; never searches for saves.
// Layout is reconstructed from the PC executable. Android source field names are candidates.
import {createHash} from 'node:crypto';
export const PC_SAVE = Object.freeze({payloadBytes:0x7e4c, checksumBytes:4, headerBytes:0x2028, magic:0x52474d48, headerVersion:1, saveVersion:5, slots:6, checksumSeed:0x5c0999});
const sha=b=>createHash('sha256').update(b).digest('hex');
const hex=n=>'0x'+n.toString(16);
function requireBytes(b,o,n,label){if(!Buffer.isBuffer(b)||!Number.isSafeInteger(o)||!Number.isSafeInteger(n)||o<0||n<0||o>b.length-n)throw Error(`Truncated or invalid ${label} at ${hex(o)}: need ${n} bytes`);}
export function pcSaveChecksum(bytes,size=bytes.length){requireBytes(bytes,0,size,'checksum input');let sum=PC_SAVE.checksumSeed;for(let o=0;o+4<=size;o+=4)sum=(sum+bytes.readUInt32LE(o))>>>0;return sum;}
const cstr=b=>b.subarray(0,b.indexOf(0)<0?b.length:b.indexOf(0)).toString('latin1');
function wstr(b){let end=0;while(end+1<b.length&&b.readUInt16LE(end)!==0)end+=2;return b.subarray(0,end).toString('utf16le');}
const words=(b,o,n)=>Array.from({length:n},(_,i)=>b.readUInt32LE(o+4*i));
export const pcSaveRegions = Object.freeze([
  {name:'prefix',offset:0,size:4,confidence:'PC save-version byte +1 confirmed; other bytes unknown'},
  {name:'options',offset:4,size:13,confidence:'PC base and size; individual field names cross-build candidates'},
  {name:'levelRecords',offset:0x11,count:366,stride:0x54,size:366*0x54,confidence:'PC base; count/stride and field names cross-build candidates'},
  {name:'levelPadding',offset:0x7829,size:3,confidence:'Cross-build candidate padding'},
  {name:'areaRecords',offset:0x782c,count:72,stride:12,size:72*12,confidence:'PC base/stride; count and field names cross-build candidates'},
  {name:'episodeRecords',offset:0x7b8c,count:6,stride:12,size:72,confidence:'PC base/stride/count, reset time/score values corroborated'},
  {name:'shopHints',offset:0x7bd4,size:12,confidence:'PC category-0 purchase bitset base'},
  {name:'shopCharacters',offset:0x7be0,size:16,confidence:'PC category-1 purchase bitset base'},
  {name:'unlockedExtras',offset:0x7bf0,size:8,confidence:'Cross-build field-name candidate; PC intervening addresses consistent'},
  {name:'shopGoldBricks',offset:0x7bf8,size:4,confidence:'PC category-2 purchase bitset base'},
  {name:'suitOrStoreFlags',offset:0x7bfc,size:4,confidence:'Cross-build field-name candidate'},
  {name:'purchasedExtras',offset:0x7c00,size:8,confidence:'PC category-4 purchase bitset base'},
  {name:'hintCompletion',offset:0x7c08,size:12,confidence:'PC passes this pointer and THREE words to hint registration; Android has six'},
  {name:'coins',offset:0x7c14,size:4,confidence:'PC purchase code subtracts price here'},
  {name:'completion',offset:0x7c18,size:2,confidence:'PC reset and accumulation'},
  {name:'goldBricks',offset:0x7c1a,size:1,confidence:'PC progression reset/accumulation'},
  {name:'rewardFlags',offset:0x7c1b,size:1,confidence:'Cross-build field-name candidate'},
  {name:'hubBuildFlags',offset:0x7c1c,size:1,confidence:'PC hub-build bit accesses corroborated'},
  {name:'indyFlag',offset:0x7c1d,size:1,confidence:'Cross-build field-name candidate'},
  {name:'reserved',offset:0x7c1e,size:2,confidence:'Unknown'},
  {name:'gameplaySeconds',offset:0x7c20,size:4,confidence:'PC frame-delta accumulation'},
  {name:'customizers',offset:0x7c24,count:2,stride:0x38,size:0x70,confidence:'PC base, name positions and flag positions; pieces interpretation cross-build'},
  {name:'missions',offset:0x7c94,size:0x64,confidence:'PC pointer; internal fields cross-build candidates'},
  {name:'characterFlags',offset:0x7cf8,size:0x154,confidence:'PC pointer and initial OR-3; per-bit labels not asserted'}
]);
export function decodePcSavePayload(b){
  requireBytes(b,0,PC_SAVE.payloadBytes,'PC game payload');if(b.length!==PC_SAVE.payloadBytes)throw Error('Expected exactly one PC payload');
  const optionsNames=['player1Rumble','player2Rumble','surround','sfxVolume','musicVolume','masterVolume','musicEnabled','unknown7','unknown8','unknown9','unknown10','widescreen','brightness'];
  const regions=pcSaveRegions.map(x=>({...x,end:x.offset+x.size,rawHex:b.subarray(x.offset,x.offset+x.size).toString('hex')}));
  return {bytes:b.length,sha256:sha(b),version:b[1],versionExpected:PC_SAVE.saveVersion,versionMatches:b[1]===PC_SAVE.saveVersion,regions,
    optionsCandidate:Object.fromEntries(optionsNames.map((s,i)=>[s,b[4+i]])),
    levelRecordsCandidate:Array.from({length:366},(_,index)=>{const offset=0x11+index*0x54;return{index,offset,minikitNames:Array.from({length:10},(_,i)=>cstr(b.subarray(offset+i*8,offset+i*8+8))),count:b[offset+0x50],reservedHex:b.subarray(offset+0x51,offset+0x53).toString('hex'),arcadeFlags:b[offset+0x53]};}),
    areaRecordsCandidate:Array.from({length:72},(_,index)=>{const offset=0x782c+index*12;return{index,offset,flags:[...b.subarray(offset,offset+8)],challengeTime:b.readFloatLE(offset+8)};}),
    episodeRecords:Array.from({length:6},(_,index)=>{const offset=0x7b8c+index*12;return{index,offset,timeLimit:b.readFloatLE(offset),scoreTarget:b.readInt32LE(offset+4),flags:b.readUInt32LE(offset+8)};}),
    purchaseBits:{shopHints:words(b,0x7bd4,3),shopCharacters:words(b,0x7be0,4),unlockedExtrasCandidate:words(b,0x7bf0,2),shopGoldBricks:words(b,0x7bf8,1),suitOrStoreCandidate:words(b,0x7bfc,1),purchasedExtras:words(b,0x7c00,2),hintCompletion:words(b,0x7c08,3)},
    coins:b.readUInt32LE(0x7c14),completion:b.readUInt16LE(0x7c18),goldBricks:b[0x7c1a],rewardFlagsCandidate:b[0x7c1b],hubBuildFlags:b[0x7c1c],indyFlagCandidate:b[0x7c1d],gameplaySeconds:b.readFloatLE(0x7c20),
    customizers:Array.from({length:2},(_,index)=>{const offset=0x7c24+index*0x38;return{index,offset,piecesCandidate:Array.from({length:9},(_,i)=>b.readUInt16LE(offset+i*2)),name:cstr(b.subarray(offset+0x14,offset+0x34)),useSavedNameCandidate:b[offset+0x34]};}),
    missionsCandidate:{times:Array.from({length:20},(_,i)=>b.readFloatLE(0x7c94+i*4)),completed:[...b.subarray(0x7ce4,0x7cf8)]},characterFlags:[...b.subarray(0x7cf8,0x7e4c)],
    caveat:'Every byte preserved by regions. Candidate fields borrow Android x86 semantic names only; no PC runtime equivalence or actual save-file validation claimed.'};
}
export function decodePcSave(bytes,{format='hmgr',strictChecksum=false}={}){
  if(!Buffer.isBuffer(bytes))throw Error('Input must be a Buffer');
  let header=null,payloadOffset=0,blob=null;
  if(format==='hmgr'){
    requireBytes(bytes,0,PC_SAVE.headerBytes,'HMGR header');
    if(bytes.readUInt32LE(0)!==PC_SAVE.magic)throw Error('Not a PC HMGR container');
    if(bytes.readUInt32LE(4)!==PC_SAVE.headerVersion)throw Error('Unsupported HMGR version');
    if(bytes.readUInt32LE(8)!==PC_SAVE.headerBytes)throw Error('Unsupported HMGR header length');
    const blobBytes=bytes.readUInt32LE(0x14);requireBytes(bytes,PC_SAVE.headerBytes,blobBytes,'optional metadata blob');
    payloadOffset=PC_SAVE.headerBytes+blobBytes;
    header={offset:0,size:PC_SAVE.headerBytes,magic:'HMGR',version:1,declaredHeaderBytes:bytes.readUInt32LE(8),words0c10:words(bytes,0xc,2),blobBytes,identifierHex:bytes.subarray(0x18,0x28).toString('hex'),title:wstr(bytes.subarray(0x28,0x828)),slotLabel:wstr(bytes.subarray(0x828,0x1028)),thirdText:wstr(bytes.subarray(0x1028,0x1828)),timestamp:wstr(bytes.subarray(0x1828,0x2028)),rawHex:bytes.subarray(0,PC_SAVE.headerBytes).toString('hex')};
    blob={offset:PC_SAVE.headerBytes,size:blobBytes,sha256:sha(bytes.subarray(PC_SAVE.headerBytes,payloadOffset)),rawHex:bytes.subarray(PC_SAVE.headerBytes,payloadOffset).toString('hex')};
  } else if(format!=='payload-with-checksum')throw Error('Unknown save framing');
  requireBytes(bytes,payloadOffset,PC_SAVE.payloadBytes+4,'payload and checksum');
  const payload=bytes.subarray(payloadOffset,payloadOffset+PC_SAVE.payloadBytes),checksumOffset=payloadOffset+PC_SAVE.payloadBytes,computed=pcSaveChecksum(payload),stored=bytes.readUInt32LE(checksumOffset),valid=computed===stored;
  if(strictChecksum&&!valid)throw Error('PC payload checksum mismatch');
  const tailOffset=checksumOffset+4,tail=bytes.subarray(tailOffset);
  return {format,sourceBytes:bytes.length,sha256:sha(bytes),header,blob,payloadOffset,payload:decodePcSavePayload(payload),checksum:{offset:checksumOffset,seed:PC_SAVE.checksumSeed,computed,stored,valid},trailer:{offset:tailOffset,size:tail.length,value:tail.length>=4?tail.readUInt32LE(0):null,rawHex:tail.toString('hex'),expectedWriterBytes:format==='hmgr'?4:0,expectedLength:tail.length===(format==='hmgr'?4:0),meaning:'Additional writer argument after checksum; callback semantics recorded separately. Extra or missing bytes retained.'}};
}
