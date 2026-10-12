import fs from 'node:fs/promises';import path from 'node:path';import{createHash}from'node:crypto';import{fileURLToPath}from'node:url';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');const binary=await fs.readFile(path.join(base,'binary/LEGOStarWarsSaga.packed.exe.unpacked.exe'));const sha256=createHash('sha256').update(binary).digest('hex');
if(sha256!=='6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb')throw Error('Different binary: fixed offsets require re-analysis');
const offset=4380400,bytes=158575,source=binary.subarray(offset,offset+bytes);if(binary[offset+bytes]!==0||!source.toString('ascii').startsWith('#if defined(_SHADERBUILDER_DEBUG)'))throw Error('Embedded source boundary mismatch');
const file='exports/shaders/nu2-embedded-template.hlsl';await fs.mkdir(path.join(base,'exports/shaders'),{recursive:true});await fs.writeFile(path.join(base,file),source);
const previous=JSON.parse(await fs.readFile(path.join(base,'reports/native-shader-source.json'),'utf8'));
const report={...previous,binarySha256:sha256,file,offset,va:'0x82d6f0',bytes,sha256:createHash('sha256').update(source).digest('hex'),method:'Exact PC executable bytes; pointer and158575-byte length corroborated by original instructions0x7460a7/0x7460ac in constructor0x746020. Includes Nu2 preprocessor extensions; not standalone HLSL.'};
await fs.writeFile(path.join(base,'reports/native-shader-source.json'),JSON.stringify(report,null,2)+'\n');console.log(JSON.stringify({file,bytes,sha256:report.sha256}));
