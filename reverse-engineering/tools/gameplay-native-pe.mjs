// Minimal bounded PE32 reader for static analysis of the preserved analysis copy.
import fs from 'node:fs';import {createHash} from 'node:crypto';
export function readPe(file){
 const bytes=fs.readFileSync(file),need=(o,n)=>{if(!Number.isSafeInteger(o)||o<0||n<0||o>bytes.length-n)throw Error('PE range outside file');};
 need(0,64);if(bytes.toString('ascii',0,2)!=='MZ')throw Error('Not MZ');const pe=bytes.readUInt32LE(0x3c);need(pe,24);if(bytes.readUInt32LE(pe)!==0x4550)throw Error('Not PE');const opt=pe+24,optsize=bytes.readUInt16LE(pe+20),count=bytes.readUInt16LE(pe+6);need(opt,optsize);if(bytes.readUInt16LE(opt)!==0x10b)throw Error('Only PE32 supported');const imageBase=bytes.readUInt32LE(opt+28),sections=[];
 for(let i=0;i<count;i++){const o=opt+optsize+i*40;need(o,40);sections.push({name:bytes.toString('ascii',o,o+8).replace(/\0.*$/s,''),virtualSize:bytes.readUInt32LE(o+8),rva:bytes.readUInt32LE(o+12),rawSize:bytes.readUInt32LE(o+16),rawOffset:bytes.readUInt32LE(o+20),flags:bytes.readUInt32LE(o+36)});}
 const section=va=>sections.find(x=>va-imageBase>=x.rva&&va-imageBase<x.rva+Math.max(x.virtualSize,x.rawSize));
 function offset(va,size=1){const s=section(va);if(!s)throw Error('VA has no section '+va.toString(16));const delta=va-imageBase-s.rva;if(delta>s.rawSize-size)throw Error('VA points outside on-disk section '+va.toString(16));const o=s.rawOffset+delta;need(o,size);return o;}
 const u32=va=>bytes.readUInt32LE(offset(va,4));
 function string(va,max=512){const o=offset(va),s=section(va),limit=Math.min(o+max,s.rawOffset+s.rawSize,bytes.length);let end=o;while(end<limit&&bytes[end])end++;if(end===limit)throw Error('Unterminated PE string '+va.toString(16));return bytes.toString('latin1',o,end);}
 return{bytes,imageBase,sections,section,offset,u32,string,sha256:createHash('sha256').update(bytes).digest('hex')};
}
