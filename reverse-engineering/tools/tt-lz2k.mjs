import fs from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {inflateSync} from 'node:zlib';
import {createHash} from 'node:crypto';
// Independent bounded decoder, algorithm cross-check: pinned OpenSaga implode.cpp
// ab97911d162d896d8f4b20e9df8e7d23a2f81557; archive framing: ttgames.bms 0.9.11a.
// Canonical Huffman tables + 8 KiB LZ window. Not PKWARE DCL/ZIP implode.
class Bits {
  constructor(b){this.b=b;this.p=0;this.v=0;this.n=0;this.used=0;}
  peek(n){while(this.n<n){this.v=this.v*256+(this.p<this.b.length?this.b[this.p]:0);this.p++;this.n+=8;}return Math.floor(this.v/2**(this.n-n));}
  drop(n){this.used+=n;if(this.used>this.b.length*8)throw Error('Truncated LZ2K bitstream');this.n-=n;this.v%=2**this.n;}
  get(n){if(!n)return 0;const v=this.peek(n);this.drop(n);return v;}
}
function huffman(lengths,constant){
  if(constant!==undefined){if(constant<0||constant>=lengths.length)throw Error('Invalid constant symbol');return {constant};}
  const max=Math.max(...lengths);if(!max||max>16)throw Error('Invalid code length');
  const counts=new Uint32Array(max+1),next=new Uint32Array(max+1);for(const n of lengths)counts[n]++;
  let code=0;for(let n=1;n<=max;n++){code=(code+(n===1?0:counts[n-1]))*2;next[n]=code;}
  if(code+counts[max]!==2**max)throw Error('Incomplete/oversubscribed Huffman tree');
  const table=new Uint32Array(2**max);
  for(let s=0;s<lengths.length;s++){const n=lengths[s];if(!n)continue;const start=next[n]++*2**(max-n);table.fill((n<<16)|s,start,start+2**(max-n));}
  return {table,max};
}
function symbol(bits,t){if(t.constant!==undefined)return t.constant;const v=t.table[bits.peek(t.max)];if(!(v>>>16))throw Error('Unmapped symbol');bits.drop(v>>>16);return v&65535;}
function readLengths(bits,count,width,zeroAt){
  const n=bits.get(width),len=new Uint8Array(count);if(!n)return huffman(len,bits.get(width));if(n>count)throw Error('Code-length count exceeds table');
  let i=0;while(i<n){let v=bits.get(3);if(v===7){while(bits.get(1)){v++;if(v>16)throw Error('Code length exceeds16');}}len[i++]=v;if(i===zeroAt){const z=bits.get(2);if(i+z>count)throw Error('Zero run exceeds offset table');i+=z;}}
  return huffman(len);
}
function readLiterals(bits,t){
  const n=bits.get(9),len=new Uint8Array(510);if(!n)return huffman(len,bits.get(9));if(n>510)throw Error('Literal length count exceeds table');
  let i=0;while(i<n){const v=symbol(bits,t);if(v<3){const run=v===0?1:v===1?bits.get(4)+3:bits.get(9)+20;if(i+run>510)throw Error('Zero run exceeds literal table');i+=run;}else{len[i++]=v-2;}}
  return huffman(len);
}
export function decodeLz2k(data,expanded){
  if(!Number.isInteger(expanded)||expanded<0||expanded>256*1024*1024)throw Error('Invalid expanded size');
  const out=Buffer.allocUnsafe(expanded),bits=new Bits(data);let pos=0,remaining=0,literal,offset;
  while(pos<expanded){if(!remaining){remaining=bits.get(16);if(!remaining)throw Error('Empty Huffman block');const temp=readLengths(bits,19,5,3);literal=readLiterals(bits,temp);offset=readLengths(bits,14,4,-1);}
    remaining--;const s=symbol(bits,literal);if(s<256){out[pos++]=s;continue;}
    const length=s-253,p=symbol(bits,offset),distance=(p?2**(p-1)+bits.get(p-1):0)+1;
    if(distance>8192||distance>pos)throw Error('Back-reference outside initialized window');if(pos+length>expanded)throw Error('Back-reference exceeds expanded size');
    for(let i=0;i<length;i++){out[pos]=out[pos-distance];pos++;}
  }
  return {data:out,consumedBits:bits.used,paddingBits:data.length*8-bits.used,remainingBlockSymbols:remaining};
}
export function* decodePayload(stored,expected){
  let at=0,out=0;
  while(at<stored.length){if(at+12>stored.length)throw Error('Truncated chunk header');const magic=stored.toString('ascii',at,at+4);let expanded,compressed;
    if(magic==='LZ2K'){expanded=stored.readUInt32LE(at+4);compressed=stored.readUInt32LE(at+8);}else if(magic==='DFLT'){compressed=stored.readUInt32LE(at+4);expanded=stored.readUInt32LE(at+8);}else throw Error('Unsupported chunk '+JSON.stringify(magic));
    if(!expanded||!compressed||expanded>256*1024*1024||at+12+compressed>stored.length||out+expanded>expected)throw Error('Invalid chunk extent');
    const raw=stored.subarray(at+12,at+12+compressed);let decoded,paddingBits=null;
    if(compressed===expanded)decoded=raw;else if(magic==='LZ2K'){const r=decodeLz2k(raw,expanded);decoded=r.data;paddingBits=r.paddingBits;}else decoded=inflateSync(raw,{maxOutputLength:expanded});
    if(decoded.length!==expanded)throw Error('Wrong decoded extent');yield {magic,offset:at,expanded,compressed,raw:compressed===expanded,data:decoded,paddingBits};at+=12+compressed;out+=expanded;
  }
  if(out!==expected)throw Error('Payload total differs from index');
}
async function main(){
 const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..'),game=path.resolve(base,'../Lego Star Wars Saga');
 const list=JSON.parse(await fs.readFile(path.join(base,'reports/all-assets.json'),'utf8'));const handles=new Map();
 const report={version:1,started:new Date().toISOString(),method:'Independent bounded JS canonical-Huffman/LZ decoder compared byte-for-byte with QuickBMS extraction; originals read-only.',reference:'opensagadev/saga@ab97911d162d896d8f4b20e9df8e7d23a2f81557 src/nu2api/nucore/implode.cpp; ttgames.bms0.9.11a chunk framing',files:0,rawFiles:0,compressedFiles:0,chunks:0,bytes:0,storedBytes:0,magic:{},paddingBits:{},archives:{},failures:[],records:[]};
 const limit=process.argv.includes('--all')?Infinity:Number(process.argv[2]??50);
 try{for(const a of list.slice(0,limit)){
   let h=handles.get(a.archive);if(!h){h=await fs.open(path.join(game,a.archive),'r');handles.set(a.archive,h);}
   const stored=Buffer.allocUnsafe(a.storedSize);let done=0;while(done<stored.length){const r=await h.read(stored,done,stored.length-done,a.offset+done);if(!r.bytesRead)throw Error('Unexpected archive EOF');done+=r.bytesRead;}
   const extracted=await fs.open(path.join(base,'extracted',...a.path.split('/')),'r');const hash=createHash('sha256');let p=0,chunks=0;
   try{const stream=a.flags===0?[{data:stored,magic:'raw',paddingBits:null}]:a.flags===2?decodePayload(stored,a.size):(()=>{throw Error('Unexpected index flags')})();
    for(const c of stream){const compare=Buffer.allocUnsafe(c.data.length);let n=0;while(n<compare.length){const r=await extracted.read(compare,n,compare.length-n,p+n);if(!r.bytesRead)throw Error('Unexpected extracted EOF');n+=r.bytesRead;}
      if(!compare.equals(c.data))throw Error('Byte mismatch at chunk output '+p);hash.update(c.data);p+=c.data.length;chunks++;report.magic[c.magic]=(report.magic[c.magic]??0)+1;if(c.paddingBits!==null)report.paddingBits[c.paddingBits]=(report.paddingBits[c.paddingBits]??0)+1;
    }
    if(p!==a.size||(await extracted.stat()).size!==p)throw Error('Final output size mismatch');
    report.files++;report[a.flags===0?'rawFiles':'compressedFiles']++;report.chunks+=chunks;report.bytes+=p;report.storedBytes+=a.storedSize;report.archives[a.archive]=(report.archives[a.archive]??0)+1;report.records.push({archive:a.archive,path:a.path,bytes:p,chunks,sha256:hash.digest('hex')});
   }catch(e){report.failures.push({archive:a.archive,path:a.path,error:e.message});}finally{await extracted.close();}
   if((report.files+report.failures.length)%250===0){console.log(JSON.stringify({files:report.files,failures:report.failures.length,bytes:report.bytes}));await fs.writeFile(path.join(base,'reports/archive-codec-progress.json'),JSON.stringify({...report,records:undefined},null,2));}
 }}finally{for(const h of handles.values())await h.close();}
 report.finished=new Date().toISOString();report.complete=report.files===list.length&&!report.failures.length;await fs.writeFile(path.join(base,'reports',process.argv.includes('--all')?'archive-codec-validation.json':'archive-codec-pilot.json'),JSON.stringify(report,null,2)+'\n');console.log(JSON.stringify({...report,records:undefined}));if(report.failures.length)process.exitCode=1;
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url))await main();
