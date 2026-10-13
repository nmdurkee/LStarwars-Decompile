import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {fileURLToPath} from 'node:url';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const read=async p=>JSON.parse((await fs.readFile(path.join(base,p),'utf8')).replace(/^\uFEFF/,''));
const write=async(p,v)=>fs.writeFile(path.join(base,p),JSON.stringify(v,null,2)+'\n');
const hash=async p=>crypto.createHash('sha256').update(await fs.readFile(path.join(base,p))).digest('hex');
const tests=await read('reports/native-obstacle-tests.json');
if(tests.mismatches||tests.failures)throw Error('Native obstacle comparisons must pass before reporting recovery');
const review=await read('reports/native-obstacle-review-tests.json');
if(review.mismatches||review.failures)throw Error('Obstacle review comparisons must pass before reporting recovery');
const entries=[
['0x5a0670','SceneAnimationControls.Refresh','SceneAnimationControls.cs','group endpoint state from ordered resolved members'],
['0x5a1030','SceneAnimationControls.Play','SceneAnimationControls.cs','play flags, per-member limits/rates and ordered queue insertion'],
['0x5a1170','SceneAnimationControls.Stop','SceneAnimationControls.cs','state-guarded stop flags'],
['0x5a11b0','SceneAnimationControls.SetLoop','SceneAnimationControls.cs','low-bit loop flag update'],
['0x5a11f0','SceneAnimationControls.JumpToEnd','SceneAnimationControls.cs','member endpoint and playing-flag writes'],
['0x5a1230','SceneAnimationControls.JumpToStart','SceneAnimationControls.cs','member start point and playing-flag writes'],
['0x5a1270','SceneAnimationControls.Seek','SceneAnimationControls.cs','finite x87 interpolation, float32 store and ordered clamp'],
['0x4408b0','ObstacleCommands.Initialize','ObstacleCommands.cs','obstacle gizmo initializer with named lookup service'],
['0x4408e0','ObstacleCommands.Initialize','ObstacleCommands.cs','special gizmo initializer with named lookup service'],
['0x4409b0','ObstacleCommands.InitializeObject','ObstacleCommands.cs','object initializer after named gizmo lookup'],
['0x440910','ObstacleCommands.AtStart','ObstacleCommands.cs','whole condition after registry/gizmo binding'],
['0x440940','ObstacleCommands.AtEnd','ObstacleCommands.cs','whole condition after registry/gizmo binding'],
['0x440970','ObstacleCommands.LockedShut','ObstacleCommands.cs','whole condition with nonnull initialized object'],
['0x55a1b0','SceneryRegistry.Output','ObstacleCommands.cs','whole guarded output dispatch after global type-table binding'],
['0x558780','ObstacleCommands.ObstacleOutput','ObstacleCommands.cs','all five obstacle output predicates on resolved records'],
['0x5ae3a0','ObstacleCommands.SpecialOutput','ObstacleCommands.cs','special output guard and state refresh with explicit reference-validity projection'],
['0x557960','ObstacleCommands.Play','ObstacleCommands.cs','forward playback including recovered scene controls'],
['0x5579d0','ObstacleCommands.Play','ObstacleCommands.cs','reverse playback including recovered scene controls'],
['0x558970','ObstacleCommands.Snap','ObstacleCommands.cs','snap backward including recovered scene controls'],
['0x558990','ObstacleCommands.Snap','ObstacleCommands.cs','snap forward including recovered scene controls'],
['0x44ea70','ObstacleCommands.ExecuteScript','ObstacleCommands.cs','bounded SCP command parser and complete recovered playback chain'],
['0x465590','ObstacleCommands.ExecuteGraph','ObstacleCommands.cs','bounded GIT obstacle parser and recovered playback chain'],
['0x465720','ObstacleCommands.ExecuteGraph','ObstacleCommands.cs','bounded GIT special parser and recovered playback chain']
];
const qualification='Finite scene fields and effective playback rates, valid acyclic member lists, explicit registry/world/reference bindings. Membership/target aliases preserve iteration order. No animation tick, rendering, collision world or reference lifetime implementation. Missing-name null dereference in LockedShut and malformed missing-operand source line are outside the contract.';
const mappings=[];
for(const[address,method,file,coverage]of entries){const relative='reconstructed/gameplay/'+file;const text=await fs.readFile(path.join(base,relative),'utf8');const name=method.split('.').pop();const line=text.split('\n').findIndex(x=>x.includes(' '+name+'('))+1;if(!line)throw Error('Missing source method '+method);mappings.push({address,sourceFile:'reverse-engineering/'+relative,methods:[{name:method,line}],coverage,qualification,comparisonStatus:'Original PC/Python differential verified; portable core and harness compile, managed behavior pending.',nativeEvidence:'reverse-engineering/reports/native-obstacle-tests.json',sourceSha256:await hash(relative)});}
const sources=[...new Set(mappings.map(m=>m.sourceFile.replace('reverse-engineering/','')))];
const report={schema:'native-obstacle-contract-v1',updated:new Date().toISOString(),binarySha256:tests.binarySha256,nativeEvidence:'reports/native-obstacle-tests.json',assemblyEvidence:'reports/native-obstacle-assembly.json',vectors:'reports/native-obstacle-vectors.json',vectorsSha256:await hash('reports/native-obstacle-vectors.json'),primaryNativeEntryPoints:mappings.length,sources:await Promise.all(sources.map(async p=>({path:p,sha256:await hash(p)}))),harness:{path:'tools/native-obstacle-portable-verify.cs',sha256:await hash('tools/native-obstacle-portable-verify.cs'),main:'ObstacleDifferential',arguments:['reports/native-obstacle-vectors.json','reports/native-obstacle-csharp-validation.json','reports/native-obstacle-review-tests.json'],execution:'Pending; no generated managed executable launched.'},native:{comparisonRecords:tests.comparisonRecords,mismatches:tests.mismatches,failures:tests.failures,groups:tests.groups},independentReview:{path:'reports/native-obstacle-review-tests.json',sha256:await hash('reports/native-obstacle-review-tests.json'),nativeCases:review.checks,mismatches:review.mismatches,failures:review.failures},commands:Object.entries(tests.authoredCounts).map(([key,uses])=>{const[kind,name]=key.split(':');return{kind,name,uses};}),catalogUses:tests.catalogUses,validAuthoredUsesExercised:tests.authoredUses,sourceFormOmissions:tests.sourceFormOmissions,adapters:tests.adapters,limits:[qualification,'SCP retains a previously found target when a later named lookup fails; GIT performs only one lookup for its last name token.','SCP stayshut forces reverse playback; GIT stayshut changes the stay flag without overriding the final FORWARD/BACKWARD choice.','AtStart is true for a nonnull gizmo whose output callback is unavailable (outputzero), while a null gizmo yieldsfalse.','Snap changes member frames without refreshing group state or list membership. Special-output reads may refresh the group state.','Native x87 seek tests include signed zero, subnormal and extreme finite values; exact float input bits are retained in replay fixtures.','Compilation does not establish C# runtime equivalence. Original-source comments/names and complete game behavior are not recovered by these contracts.']};
await write('reports/native-obstacle-contract.json',report);
await write('reports/native-obstacle-source-map.json',{binarySha256:tests.binarySha256,scope:'Obstacle and scene-animation fragment for integration into gameplay map.',primaryNativeEntryPoints:mappings.length,mappings,nativeEvidence:report.nativeEvidence,portable:{core:sources,harness:report.harness}});
await fs.writeFile(path.join(base,'reports/native-obstacle-findings.txt'),'OBSTACLE AND SCENE-ANIMATION CONTROLS\n\n'+tests.comparisonRecords+' native comparisons, zero mismatches; '+tests.authoredUses+' valid authored uses exercised from '+tests.catalogUses+' cataloged occurrences.\n'+mappings.length+' bounded portable mappings; generated managed execution pending.\n\n'+report.limits.join('\n')+'\n');
console.log(JSON.stringify({mappings:mappings.length,native:report.native,validAuthoredUses:tests.authoredUses,sourceFormOmissions:tests.sourceFormOmissions.length}));
