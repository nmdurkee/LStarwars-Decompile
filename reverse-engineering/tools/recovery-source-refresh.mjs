import fs from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const read=async p=>JSON.parse((await fs.readFile(path.join(base,p),'utf8')).replace(/^\uFEFF/,''));
const write=async(p,v)=>fs.writeFile(path.join(base,p),JSON.stringify(v,null,2)+'\n');
const manifest=await read('reconstructed/source-manifest.json');
const byName=Object.fromEntries(manifest.modules.map(m=>[m.name,m]));
const animation=await read('reports/animation-source-function-map.json');
byName.animation.mappings=animation.records.map(r=>({address:r.nativeAddress,method:r.csharpMethod,coverage:r.coverage,limits:r.limits,sourceFile:r.source.replace(/^reconstructed\//,''),evidence:r.nativeEvidenceReport}));
const gameplay=await read('reports/gameplay-source-function-map.json');
byName.gameplay.mappings=gameplay.mappings.map(r=>({address:r.address,method:r.methods.map(x=>x.name).join('; '),coverage:r.coverage,limits:[r.qualification],sourceFile:r.sourceFile.replace(/^reverse-engineering\/reconstructed\//,''),evidence:r.address==='0x456c10'?'reports/gameplay-createcreatures-contract.json':'reports/gameplay-source-function-map.json'}));
const geometry=await read('reports/geometry-recovered-source.json');
byName.geometry.mappings=geometry.nativeMappings.map(r=>({address:r.address,method:r.method,coverage:r.coverage,limits:[r.limitations],sourceFile:(r.sourceFile||('geometry/'+(r.method.startsWith('MaterialUv.')?'MaterialUv.cs':'SceneSubmission.cs'))).replace(/^reconstructed\//,''),evidence:r.sourceFile?.endsWith('PortalVisibility.cs')?'reports/geometry-portal-visibility-native-validation.json':r.sourceFile?.endsWith('PortalVolumes.cs')?'reports/geometry-portal-volume-native-validation.json':'reports/geometry-recovered-source.json'}));
for(const m of manifest.modules){m.evidence=[...new Set([...(m.evidence||[]),...m.mappings.map(r=>r.evidence).filter(Boolean)])];m.files=[...new Set(m.mappings.map(r=>r.sourceFile))];for(const f of m.files)await fs.access(path.join(base,'reconstructed',f));}
manifest.updated=new Date().toISOString();
await write('reconstructed/source-manifest.json',manifest);
const investigation=await read('INVESTIGATION.json');
const tracks=[
{name:'Portable recovered source',status:'bounded-fragments-game-incomplete',evidence:['reconstructed/source-manifest.json','reports/source-completion.json','reports/reconstructed-build.json','reports/reconstructed-execution-status.json']},
{name:'Combat and economy',status:'bounded-native-contracts-portable-source-partial',evidence:['reports/native-combat-contract.json','reports/native-combat-economy.json','reports/native-combat-scenarios.json']},
{name:'Character contexts and reset',status:'bounded-native-contracts-portable-source-partial',evidence:['reports/animation-source-function-map.json','reports/animation-portable-findings.txt','reports/animation-reset-moves-native-verification.json']},
{name:'World frame dispatcher',status:'bounded-control-flow-subsystems-adapted',coverage:'384 native call-order cases and 9600 state assertions; subsystem callees are no-op adapters, not an executed whole frame.',evidence:['reports/native-frame-dispatch.json']}
];
for(const t of tracks){const i=investigation.tracks.findIndex(x=>x.name===t.name);if(i<0)investigation.tracks.push(t);else investigation.tracks[i]=t;}
investigation.updated=manifest.updated;await write('INVESTIGATION.json',investigation);
const architecture=await read('reports/native-architecture.json');
const frame=await read('reports/native-frame-dispatch.json');
const anchor=architecture.anchors.find(x=>x.address==='0x491d50');
anchor.role='World/frame update dispatcher; bounded control flow verified';
anchor.observations=['384 original dispatcher call-order cases and 9600 own-state assertions match; all direct subsystem callees are explicit no-op adapters.','The original takes a world pointer AND a separate output/state pointer; Ghidra conflates the second parameter.','Pause/force/override/cutscene/audio/level-flag branches have synthetic native fixtures. Positive timers subtract delta without clamping at zero.','No complete world-frame, live subsystem, menu, populated player or level-transition equivalence is claimed.'];
anchor.nativeVerification='reports/native-frame-dispatch.json';anchor.evidence=frame.sourceEvidence;
const branches=await read('reports/native-frame-branches.json');
anchor.observations.push(branches.totals.cases+' additional player/menu/transition/native-state cases and '+branches.totals.assertions+' assertions pass; see native-frame-branches.json. Only the two transition state helpers execute as original subsystem callees there.');
anchor.additionalVerification='reports/native-frame-branches.json';
await write('reports/native-architecture.json',architecture);
await fs.writeFile(path.join(base,'reports/native-architecture.txt'),'PC STARTUP AND FRAME FLOW\n\n'+architecture.anchors.map(x=>x.address+' '+x.role+'\n'+x.observations.map(s=>'  '+s).join('\n')+'\n  Evidence: '+x.evidence.file).join('\n\n')+'\n\nGLOBAL CATALOGS\n'+architecture.catalogCalls.map(x=>x.path+' -> '+x.callee).join('\n')+'\n');
let text=await fs.readFile(path.join(base,'README.txt'),'utf8');
text=text.replace(/(?:Portable C# fragments are available in reconstructed\/; they are not a complete game\.\n)+/g,'');
text=text.replace('pseudocode, reproducible parsers, behavior checks and preserved evidence.','pseudocode, reproducible parsers, behavior checks and preserved evidence.\nPortable C# fragments are available in reconstructed/; they are not a complete game.');
text=text.replace(/4,567,137 uniform scalar comparisons pass\. 46 legacy material layouts retain\n  a preprocessing gap\./,'4,567,137 uniform scalar comparisons pass. The ordinary PC loader does not expand\n  the 46 legacy layouts into the current material format; they remain separate.');
const gi=await read('reports/gameplay-native-index.json');
// Keep aggregate fixture counts in their maintained subsystem ledger rather than duplicating stale totals.
text=text.replace(/Gameplay\n?suites pass [\s\S]*?fixture counts, not percentages of recovered game behavior\./,'Gameplay totals and suite boundaries are maintained in\nreports/gameplay-native-index.json. Fixture counts do not measure recovered behavior.');
text=text.replace('legacy material preprocessing, visibility/LOD scheduling and native GPU pixel','alternate legacy material consumers, complete visibility scheduling and native GPU pixel');
if(!text.includes('PORTABLE SOURCE CHECKPOINT'))text+='\nPORTABLE SOURCE CHECKPOINT\nBuild: & .\\reconstructed\\build.ps1 (from this directory).\nSource map: reconstructed/source-manifest.json and reports/source-completion.json.\nCurrent compile and execution evidence: reports/reconstructed-build.json and\nreports/reconstructed-execution-status.json. Compilation is not behavioral proof.\nDetailed new work: native-combat-contract.json, animation-source-function-map.json,\ngameplay-scp-transition-contract.json, geometry-visibility-native-validation.json,\nand native-frame-dispatch.json in reports/. All are bounded contracts.\n';
await fs.writeFile(path.join(base,'README.txt'),text);
console.log(JSON.stringify({modules:manifest.modules.length,files:manifest.modules.reduce((n,m)=>n+m.files.length,0),mappings:manifest.modules.reduce((n,m)=>n+m.mappings.length,0)}));
