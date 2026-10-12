import assert from 'node:assert/strict';import{decodeLz2k,decodePayload}from'./tt-lz2k.mjs';import fs from'node:fs/promises';import path from'node:path';import{fileURLToPath}from'node:url';import{deflateSync}from'node:zlib';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..'),results=[];
function bitstream(fields){let str=fields.map(([n,v])=>v.toString(2).padStart(n,'0')).join('');str=str.padEnd(Math.ceil(str.length/8)*8,'0');return Buffer.from(str.match(/.{8}/g).map(x=>parseInt(x,2)));}
function block(count,literal,offset=0){return [[16,count],[5,0],[5,0],[9,0],[9,literal],[4,0],[4,offset]];}
function check(name,fn){fn();results.push({name,passed:true});}
const constant=bitstream(block(1024,65)),overlap=bitstream([...block(1,65),...block(1,258)]);
check('Constant Huffman literal block',()=>assert.deepEqual(decodeLz2k(constant,1024).data,Buffer.alloc(1024,65)));
check('Overlapping distance-one LZ copy',()=>assert.deepEqual(decodeLz2k(overlap,6).data,Buffer.alloc(6,65)));
check('Truncated Huffman header rejected',()=>assert.throws(()=>decodeLz2k(constant.subarray(0,3),1024),/Truncated/));
check('Uninitialized backward reference rejected',()=>assert.throws(()=>decodeLz2k(bitstream(block(1,258)),5),/window/));
check('Expanded extent overflow rejected',()=>assert.throws(()=>decodeLz2k(overlap,5),/expanded/));
check('Illegal constant literal rejected',()=>assert.throws(()=>decodeLz2k(bitstream(block(1,511)),5),/symbol/));
check('Zero-size Huffman block rejected',()=>assert.throws(()=>decodeLz2k(bitstream(block(0,65)),5),/Empty/));
check('Excess output allocation rejected',()=>assert.throws(()=>decodeLz2k(constant,2**31),/size/));
function frame(magic,payload,expanded){const b=Buffer.alloc(12+payload.length);b.write(magic);b.writeUInt32LE(magic==='DFLT'?payload.length:expanded,4);b.writeUInt32LE(magic==='DFLT'?expanded:payload.length,8);payload.copy(b,12);return b;}
const framed=frame('LZ2K',constant,1024);
check('Chunk framing',()=>assert.deepEqual([...decodePayload(framed,1024)][0].data,Buffer.alloc(1024,65)));
check('Truncated chunk rejected',()=>assert.throws(()=>[...decodePayload(framed.subarray(0,15),1024)],/extent/));
check('Wrong aggregate size rejected',()=>assert.throws(()=>[...decodePayload(framed,1025)],/total/));
check('Unknown codec rejected',()=>assert.throws(()=>[...decodePayload(frame('NOPE',constant,1024),1024)],/Unsupported/));
check('Raw equal-length chunk',()=>assert.deepEqual([...decodePayload(frame('LZ2K',Buffer.from('abc'),3),3)][0].data,Buffer.from('abc')));
check('DFLT framing (synthetic, not claimed present in this game)',()=>assert.deepEqual([...decodePayload(frame('DFLT',deflateSync(Buffer.alloc(1024,65)),1024),1024)][0].data,Buffer.alloc(1024,65)));
const report={tests:results.length,passed:results.length,results};await fs.writeFile(path.join(base,'reports/archive-codec-tests.json'),JSON.stringify(report,null,2)+'\n');console.log(JSON.stringify(report));
