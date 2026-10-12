import fs from 'node:fs/promises';
import path from 'node:path';
import {createHash} from 'node:crypto';
const [filename,outdir]=process.argv.slice(2);
if(!filename||!outdir)throw Error('Usage: node inspect-pe.mjs FILE OUTPUT-DIRECTORY');
const b=await fs.readFile(filename);if(b.toString('ascii',0,2)!=='MZ')throw Error('Not MZ');
const p=b.readUInt32LE(0x3c);if(b.readUInt32LE(p)!==0x4550)throw Error('Not PE');
const opt=p+24;if(b.readUInt16LE(opt)!==0x10b)throw Error('Only PE32 supported');
const imageBase=b.readUInt32LE(opt+28);const sections=[];
for(let i=0;i<b.readUInt16LE(p+6);i++){const q=opt+b.readUInt16LE(p+20)+i*40;const s={name:b.toString('ascii',q,q+8).replaceAll('\0',''),rva:b.readUInt32LE(q+12),virtualSize:b.readUInt32LE(q+8),size:b.readUInt32LE(q+16),offset:b.readUInt32LE(q+20),flags:b.readUInt32LE(q+36)};if(s.offset+s.size>b.length)throw Error('Section exceeds file');const counts=new Array(256).fill(0);for(const x of b.subarray(s.offset,s.offset+s.size))counts[x]++;s.entropy=counts.reduce((a,n)=>n?a-n/s.size*Math.log2(n/s.size):a,0);sections.push(s);}
const rvaOff=r=>{const s=sections.find(s=>r>=s.rva&&r<s.rva+s.size);if(s)return s.offset+r-s.rva;if(r<b.readUInt32LE(opt+60))return r;throw Error('RVA unmapped '+r.toString(16));};
const z=o=>{const e=b.indexOf(0,o);if(e<o)throw Error('Missing string terminator');return b.toString('latin1',o,e);};
const imports=[];const ir=b.readUInt32LE(opt+104);if(ir){for(let i=rvaOff(ir);b.readUInt32LE(i+12);i+=20){const dll=z(rvaOff(b.readUInt32LE(i+12)));const first=b.readUInt32LE(i+16);const thunk=b.readUInt32LE(i)||first;const symbols=[];for(let q=rvaOff(thunk),j=0;b.readUInt32LE(q);q+=4,j++){const v=b.readUInt32LE(q);symbols.push({iatVa:imageBase+first+j*4,...(v&0x80000000?{ordinal:v&0xffff}:{name:z(rvaOff(v)+2)})});}imports.push({dll,symbols});}}
const strings=[];for(const m of b.toString('latin1').matchAll(/[\x20-\x7e]{5,}/g)){const s=sections.find(s=>m.index>=s.offset&&m.index<s.offset+s.size);strings.push({offset:m.index,va:s?imageBase+s.rva+m.index-s.offset:null,section:s?.name??null,text:m[0]});}
const byVa=new Map(strings.map(s=>[s.va,s]));const data=sections.find(s=>s.name==='.data'),code=sections.find(s=>s.name==='.text');const dispatch=[];
if(data&&code)for(let q=data.offset;q+12<=data.offset+data.size;q+=4){const st=byVa.get(b.readUInt32LE(q)),fn=b.readUInt32LE(q+4);if(st&&/^[A-Za-z_][A-Za-z0-9_ ]{2,79}$/.test(st.text)&&fn>=imageBase+code.rva&&fn<imageBase+code.rva+code.virtualSize)dispatch.push({name:st.text,tableVa:imageBase+data.rva+q-data.offset,functionVa:fn,stringVa:st.va,thirdField:b.readUInt32LE(q+8)});}
await fs.mkdir(outdir,{recursive:true});const report={path:path.resolve(filename),sha256:createHash('sha256').update(b).digest('hex'),size:b.length,machine:b.readUInt16LE(p+4),imageBase,entryVa:imageBase+b.readUInt32LE(opt+16),clrDirectoryRva:b.readUInt32LE(opt+96+14*8),sections,imports};
await fs.writeFile(path.join(outdir,'pe.json'),JSON.stringify(report,null,2));await fs.writeFile(path.join(outdir,'strings.json'),JSON.stringify(strings,null,2));await fs.writeFile(path.join(outdir,'dispatch-candidates.json'),JSON.stringify({warning:'Candidate data layout, not proof of function behavior. Validate in a disassembler.',entries:dispatch},null,2));console.log(JSON.stringify({sha256:report.sha256,entryVa:report.entryVa,strings:strings.length,dispatchCandidates:dispatch.length}));
