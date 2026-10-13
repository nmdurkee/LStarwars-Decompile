// Verify corrected field aliases against original source bytes; no exports rewritten.
import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {parseNu2} from './geometry-nu2.mjs';
const base=path.resolve(import.meta.dirname,'..');
const index=JSON.parse(await fs.readFile(path.join(base,'reports/geometry-scene-data-index.json'),'utf8')).rows;
const samples=[index.find(x=>x.source.includes('QUIGONJINN_PC.GHG')),index.find(x=>x.source.endsWith('2_1B_LR_PC.GHG')),index.find(x=>x.source.endsWith('NEGOTIATIONS_A_PC.GSC')),index.find(x=>x.source.endsWith('MAP_PC.GSC'))];
let objects=0,bounds=0;const cases=[];
for(const row of samples){
 if(!row)throw Error('Missing selected sample');
 const raw=await fs.readFile(path.join(base,'extracted',row.source)),parsed=parseNu2(raw,row.source),old=JSON.parse(await fs.readFile(path.join(base,row.report),'utf8'));
 if(JSON.stringify(parsed.bounds)!==JSON.stringify(old.bounds))throw Error('BNDS data unexpectedly changed');
 for(const s of parsed.specialObjects){
  for(let axis=0;axis<3;axis++){
   const lo=raw.readFloatLE(s.address+128+axis*4),hi=raw.readFloatLE(s.address+144+axis*4);
   if(!Object.is(lo,s.boundsMinimum[axis])||!Object.is(hi,s.boundsMaximum[axis]))throw Error('Incorrect local bound alias');
  }
  if(s.boundsCenter!==s.boundsMinimum||s.boundsExtent!==s.boundsMaximum)throw Error('Compatibility alias failed');
 }
 objects+=parsed.specialObjects.length;bounds+=parsed.bounds.length;
 cases.push({source:row.source,sha256:crypto.createHash('sha256').update(raw).digest('hex'),specialObjects:parsed.specialObjects.length,bounds:parsed.bounds.length});
}
const report={schema:'special-bounds-semantic-correction-v1',appliesTo:'specialObjects only; separate bounds/BNDS records unchanged',originalEvidence:['decompiled/corpus-expanded/FUN_5df480.c','reports/scene-animation-bounds-contract.json','reports/scene-animation-bounds-tests.json'],offsets:{'special+0x80':'local minimum XYZ','special+0x90':'local maximum XYZ'},legacyAliases:{boundsCenter:'boundsMinimum',boundsExtent:'boundsMaximum'},existingMetadata:{rewritten:false,index:'reports/geometry-scene-data-index.json',carriers:index.length,carrierKinds:{GHG:index.filter(x=>x.source.endsWith('.GHG')).length,GSC:index.filter(x=>x.source.endsWith('.GSC')).length},specialObjects:index.reduce((n,x)=>n+x.objects,0),interpretation:'Existing specialObjects.boundsCenter and boundsExtent retain original bytes but must be interpreted as local minimum and maximum, respectively.'},futureParser:{path:'tools/geometry-nu2.mjs',sha256:crypto.createHash('sha256').update(await fs.readFile(path.join(base,'tools/geometry-nu2.mjs'))).digest('hex'),fields:['boundsMinimum','boundsMaximum','legacyBoundsFieldSemantics'],compatibilityAliasesPreserved:true},validation:{passed:true,carriers:samples.length,specialObjects:objects,unchangedBNDS:bounds,cases},limits:['No bulk geometry or scene metadata regeneration performed.','Padding W lanes are not given local bound semantic names.','The animated native bounds producer and its numerical validation remain owned by the animation source contract.']};
await fs.writeFile(path.join(base,'reports/geometry-special-bounds-semantic-correction.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report.validation));

