"""Conservative per-entry portable source inventory. Not a source-completion percentage."""
import json,sqlite3,hashlib,datetime
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent
load=lambda p:json.loads((BASE/p).read_text(encoding='utf-8-sig'))
manifest=load('reconstructed/source-manifest.json');aliases=load('reports/native-contract-aliases.json')['entries'];mapping={}
for module in manifest['modules']:
 for entry in module['mappings']:
  mapping.setdefault(entry['address'],[]).append({'module':module['name'],**entry,'sourceSha256':hashlib.sha256((BASE/'reconstructed'/entry['sourceFile']).read_bytes()).hexdigest()})
byalias={}
for alias in aliases:byalias.setdefault(alias['address'],[]).append(alias)
db=sqlite3.connect('file:'+str(BASE/'reports/native-catalog.sqlite')+'?mode=ro',uri=True);db.row_factory=sqlite3.Row
rows=[]
for row in db.execute('SELECT address,name,path,evidence,sha256 FROM functions ORDER BY address'):
 r=dict(row);addr=r['address'];r['portableMappings']=mapping.get(addr,[]);r['contractLabels']=byalias.get(addr,[])
 r['status']='bounded-portable-source-mapped'if r['portableMappings']else'contract-labeled-no-portable-mapping'if r['contractLabels']else'pseudocode-no-portable-mapping-recorded';rows.append(r)
known={r['address']for r in rows};missing=[addr for addr in mapping if addr not in known]
build=load('reports/reconstructed-build.json')
compiled={str(Path(r['path']).resolve()).casefold():r['sha256']for r in build.get('sources',[])}
current={str((BASE/'reconstructed'/f).resolve()).casefold():hashlib.sha256((BASE/'reconstructed'/f).read_bytes()).hexdigest()for m in manifest['modules']for f in m['files']}
build_mismatches=[p for p,h in current.items()if compiled.get(p)!=h]
harness_compiled={str(Path(r['path']).resolve()).casefold():r['sha256']for r in build.get('harnessSources',[])}
harness_current={str((BASE/'reconstructed'/f).resolve()).casefold():hashlib.sha256((BASE/'reconstructed'/f).read_bytes()).hexdigest()for f in manifest['harnessFiles']}
harness_mismatches=[p for p,h in harness_current.items()if harness_compiled.get(p)!=h]
def artifact_matches(relative,key):
 p=BASE/relative
 return bool(build.get(key))and p.is_file()and hashlib.sha256(p.read_bytes()).hexdigest()==build[key]
compilation={'allManifestHarnessHashesMatchBuild':not harness_mismatches and len(harness_current)==len(harness_compiled),'harnessHashMismatches':harness_mismatches,'buildHarnessCount':len(harness_compiled),'manifestHarnessCount':len(harness_current),'libraryHashMatchesBuild':artifact_matches('reconstructed/bin/Recovered.Runtime.dll','librarySha256'),'unifiedVerifierHashMatchesBuild':artifact_matches('reconstructed/bin/RecoveredSourceVerify.exe','unifiedVerifierSha256'),'report':'reports/reconstructed-build.json','allManifestSourceHashesMatchBuild':not build_mismatches and len(current)==len(compiled),'sourceHashMismatches':build_mismatches,'buildSourceCount':len(compiled),'manifestSourceCount':len(current),'executionStatus':'reports/reconstructed-execution-status.json'}
result={'updated':datetime.datetime.now(datetime.timezone.utc).isoformat(),'binarySha256':manifest['binarySha256'],'scope':'Every cataloged native entry and its explicit C# mapping/semantic labels. This does not inventory every recovered JavaScript parser or exact original HLSL source artifact.','summary':{'recognizedEntries':len(rows),'entriesWithPortableMappings':sum(bool(r['portableMappings'])for r in rows),'entriesWithContractLabels':sum(bool(r['contractLabels'])for r in rows),'portableModules':len(manifest['modules']),'portableSourceFiles':sum(len(m['files'])for m in manifest['modules']),'mappedEntriesOutsideCatalog':missing,'wholeGameBuildable':False,'wholeGameEquivalenceEstablished':False},'rules':['A mapped entry may cover only one branch or a managed projection; read each coverage qualification.','A contract label is not proof that the entire function or its dependencies are understood.','No mapping recorded does not prove no prior analysis; detailed subsystem reports remain authoritative.','Recognized entry boundaries are Ghidra analysis hypotheses, not a proven original function count.','Counts do not establish a source reconstruction percentage.','Windows denies newly built managed verifier execution; source compiles, native original-function checks continue.'],'compilation':compilation,'functions':rows}
(BASE/'reports/source-completion.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'summary':result['summary'],'compilation':compilation}))

lines=['RECOVERED SOURCE STATUS', '', 'Recognized native entries: '+str(len(rows)), 'Entries with bounded C# mappings: '+str(result['summary']['entriesWithPortableMappings']), 'Portable core files: '+str(len(current))+' across '+str(len(manifest['modules']))+' modules', 'Current source hashes match compiled build: '+str(compilation['allManifestSourceHashesMatchBuild']), 'Current harness hashes match compiled build: '+str(compilation['allManifestHarnessHashesMatchBuild']), 'Library and verifier hashes match build: '+str(compilation['libraryHashMatchesBuild']and compilation['unifiedVerifierHashMatchesBuild']), '', 'These are function-entry mappings, not a source-completion percentage. A mapping can cover only a branch or a helper with explicit adapters.', '', 'MODULES']
for module in manifest['modules']:
 lines.append(module['name']+': '+str(len(module['files']))+' source files, '+str(len(module['mappings']))+' bounded mappings')
lines+=['', 'VALIDATION', 'Original PC functions are tested in isolated Unicorn memory. Independent Python/JS contracts are separate from compiled C# comparisons.', 'Initial combat C# subset passed14553 comparisons. Later generated executables receive Windows Access denied; extended compiled-source equivalence remains pending.', '', 'REMAINING', 'Most recognized native entries have no portable implementation recorded. Full world orchestration, remaining script commands/conditions, collision/AI integration, vehicle behavior, full renderer/camera/portal traversal, level loading, audio and game bootstrap remain incomplete.', 'There is no complete playable game or Unity project. Optimized binaries do not retain all original source names, comments or code removed by the compiler.', '', 'DETAIL', 'source-completion.json contains the per-entry mapping and coverage qualifications.', 'reconstructed-build.json and reconstructed-execution-status.json record compile/execution evidence.', 'gameplay-next-command-priorities.json ranks the remaining authored command work.']
(BASE/'reports/source-completion.txt').write_text('\n'.join(lines)+'\n')
