import fs from 'node:fs/promises';
import path from 'node:path';
const root=path.resolve('reverse-engineering');
const files=(await fs.readdir(path.join(root,'extracted'),{recursive:true})).filter(x=>/\.AN3$/i.test(x));
const headers=[];
for(const rel of files){
 const b=await fs.readFile(path.join(root,'extracted',rel));
 const h={path:rel,bytes:b.length,magic:b.subarray(0,4).toString('ascii'),nodes:b.readUInt16LE(4),keys:b.readUInt16LE(6),stride:b.readUInt16LE(8),frames:b.readUInt16LE(10),curves:b.readUInt16LE(12),first:b.readUInt16LE(14),end:b[16],constantIndex:b[17],format:b[19],next:b.readUInt16LE(20),declared:b.readUInt16LE(22),offsets:[36,40,44,48,52,56].map(o=>b.readUInt32LE(o))};
 if(h.magic==='4INA'&&h.offsets[2]+h.nodes*h.curves*2<=b.length){h.types={};for(let o=h.offsets[2];o<h.offsets[2]+h.nodes*h.curves*2;o+=2){const t=b.readUInt16LE(o);h.types[t]=(h.types[t]??0)+1;}}
 headers.push(h);
}
const group=k=>Object.fromEntries([...new Set(headers.map(x=>x[k]))].map(v=>[v,headers.filter(x=>x[k]===v).length]));
await fs.writeFile(path.join(root,'reports/animation-headers.json'),JSON.stringify(headers,null,2));
console.log(JSON.stringify({count:headers.length,magic:group('magic'),curves:group('curves'),format:group('format'),constantIndex:group('constantIndex'),next:group('next'),dynamicTypes:headers.reduce((a,h)=>{for(const[t,c]of Object.entries(h.types??{}))if(+t<16)a[t]=(a[t]??0)+c;return a;},{})},null,2));
