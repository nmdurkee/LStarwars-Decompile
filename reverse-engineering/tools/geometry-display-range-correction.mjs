import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {parseNu2} from './geometry-nu2.mjs';
const base=path.resolve(import.meta.dirname,'..'),native=JSON.parse(await fs.readFile(path.join(base,'reports/geometry-sorted-packets-native-validation.json'),'utf8'));
let count=0;const samples=[];
for(const row of [native.sources[0],native.sources[native.sources.length-1]]){
 const raw=await fs.readFile(path.join(base,'extracted',row.source)),parsed=parseNu2(raw,row.source);
 if(parsed.displayLists.length!==row.sortRecords)throw Error('Sort record count changed');
 for(let i=0;i<parsed.displayLists.length;i++){
  const r=parsed.displayLists[i],expected=row.ranges[i];
  if(r.firstMaterial!==expected[0]||r.materialCount!==expected[1]||r.firstMaterial!==(r.firstBounds&65535)||r.materialCount!==(r.boundsCount&65535))throw Error('Range alias mismatch');
  count++;
 }
 samples.push(row.source);
}
const report={schema:'geometry-display-range-correction-v1',appliesTo:'displayLists entries in prior geometry metadata',evidence:['decompiled/corpus-expanded/FUN_5e0d00.c','reports/geometry-sorted-packets-native-validation.json','reports/geometry-sorted-shader-native-validation.json'],offsets:{'sort+0x20':'unsigned16 material count','sort+0x22':'unsigned16 first material index'},legacyMapping:{boundsCount:'materialCount = boundsCount & 65535',firstBounds:'firstMaterial = firstBounds & 65535'},futureParser:{path:'tools/geometry-nu2.mjs',sha256:crypto.createHash('sha256').update(await fs.readFile(path.join(base,'tools/geometry-nu2.mjs'))).digest('hex'),fields:['firstMaterial','materialCount','legacyRangeFieldSemantics']},existingMetadataRewritten:false,authoredNativeCoverage:{scenes:native.sources.length,sortRecords:native.sources.reduce((v,r)=>v+r.sortRecords,0),allRangesWithinMaterialTables:true},parserValidation:{passed:true,sources:samples,sortRecords:count},limits:['Semantic naming correction only; original metadata bytes preserved and no geometry re-export.','Legacy values were decoded signed16; reinterpret with&65535 before using them as material indices/counts.']};
await fs.writeFile(path.join(base,'reports/geometry-display-range-semantic-correction.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report.parserValidation));

