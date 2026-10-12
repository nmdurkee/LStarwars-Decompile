import assert from 'node:assert/strict';import fs from 'node:fs';
import {PC_SAVE,pcSaveChecksum,pcSaveRegions,decodePcSavePayload,decodePcSave} from './gameplay-save-format.mjs';
const checks=[];function test(name,fn){fn();checks.push({name,passed:true});}
function raw(){const b=Buffer.alloc(PC_SAVE.payloadBytes+4);b[1]=5;b.writeUInt32LE(123456,0x7c14);b.writeUInt16LE(42,0x7c18);b.writeFloatLE(120.5,0x7c20);b.write('Synthetic only',0x7c38,'latin1');b.writeUInt32LE(pcSaveChecksum(b,PC_SAVE.payloadBytes),PC_SAVE.payloadBytes);return b;}
function framed(blob=Buffer.alloc(0)){const h=Buffer.alloc(PC_SAVE.headerBytes);h.writeUInt32LE(PC_SAVE.magic);h.writeUInt32LE(1,4);h.writeUInt32LE(h.length,8);h.writeUInt32LE(blob.length,0x14);h.write('Synthetic fixture',0x28,'utf16le');return Buffer.concat([h,blob,raw(),Buffer.from([0x78,0x56,0x34,0x12])]);}
test('zero-length checksum seed',()=>assert.equal(pcSaveChecksum(Buffer.alloc(0)),0x5c0999));
test('checksum wraps modulo 2^32',()=>assert.equal(pcSaveChecksum(Buffer.from([255,255,255,255,2,0,0,0])),0x5c099a));
test('checksum ignores incomplete trailing word, matching native',()=>assert.equal(pcSaveChecksum(Buffer.from([3,0,0,0,99])),0x5c099c));
test('all payload bytes assigned once',()=>{let at=0;for(const r of pcSaveRegions){assert.equal(r.offset,at);at+=r.size;}assert.equal(at,PC_SAVE.payloadBytes);});
test('decode raw payload plus checksum',()=>{const d=decodePcSave(raw(),{format:'payload-with-checksum',strictChecksum:true});assert(d.checksum.valid);assert.equal(d.payload.coins,123456);assert.equal(d.payload.completion,42);assert.equal(d.payload.gameplaySeconds,120.5);assert.equal(d.payload.customizers[0].name,'Synthetic only');assert.equal(d.payload.purchaseBits.hintCompletion.length,3);assert.equal(d.payload.characterFlags.length,340);assert(d.trailer.expectedLength);});
test('decode HMGR with optional blob and separate trailer',()=>{const d=decodePcSave(framed(Buffer.from([1,2,3])),{strictChecksum:true});assert.equal(d.blob.size,3);assert.equal(d.payloadOffset,PC_SAVE.headerBytes+3);assert.equal(d.header.title,'Synthetic fixture');assert.equal(d.trailer.value,0x12345678);assert(d.trailer.expectedLength);});
test('bad checksum is observable and optionally strict',()=>{const b=raw();b[200]^=1;assert.equal(decodePcSave(b,{format:'payload-with-checksum'}).checksum.valid,false);assert.throws(()=>decodePcSave(b,{format:'payload-with-checksum',strictChecksum:true}),/checksum/);});
test('short header rejected',()=>assert.throws(()=>decodePcSave(Buffer.alloc(2)),/header/));
test('bad magic rejected',()=>{const b=framed();b[0]=0;assert.throws(()=>decodePcSave(b),/HMGR/);});
test('unknown header version rejected',()=>{const b=framed();b.writeUInt32LE(2,4);assert.throws(()=>decodePcSave(b),/version/);});
test('unknown header length rejected',()=>{const b=framed();b.writeUInt32LE(4,8);assert.throws(()=>decodePcSave(b),/header length/);});
test('oversized metadata blob rejected',()=>{const b=framed();b.writeUInt32LE(0xffffffff,0x14);assert.throws(()=>decodePcSave(b),/blob/);});
test('truncated payload or checksum rejected',()=>{for(const n of [0,4,PC_SAVE.payloadBytes,PC_SAVE.payloadBytes+3])assert.throws(()=>decodePcSave(raw().subarray(0,n),{format:'payload-with-checksum'}),/payload/);});
test('missing writer trailer recorded rather than invented',()=>{const b=framed(),d=decodePcSave(b.subarray(0,b.length-4));assert.equal(d.trailer.size,0);assert.equal(d.trailer.expectedLength,false);assert(d.checksum.valid);});
test('unknown payload version retained',()=>{const b=raw();b[1]=9;assert.equal(decodePcSavePayload(b.subarray(0,PC_SAVE.payloadBytes)).versionMatches,false);});
const result={generatedAt:new Date().toISOString(),passed:true,tests:checks.length,checks,scope:'Synthetic in-memory fixtures only. No user save paths searched, no user saves read or written. These test decoder behavior; they do not establish runtime or real-save roundtrip equivalence.'};
fs.writeFileSync('reverse-engineering/reports/gameplay-save-format-tests.json',JSON.stringify(result,null,2));console.log(JSON.stringify(result,null,2));
