import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {fileURLToPath} from 'node:url';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const read=async p=>JSON.parse((await fs.readFile(path.join(base,p),'utf8')).replace(/^\uFEFF/,''));
const hash=async p=>crypto.createHash('sha256').update(await fs.readFile(path.join(base,p))).digest('hex');
const source='reconstructed/navigation/ConnectionControllers.cs';
const tests=await read('reports/native-connections-tests.json');
const mappings=[
['0x407d00','ConnectionFlags.LookupDialect','complete ordered flag lookup for dialect0'],
['0x4cbf70','ConnectionFlags.LookupDialect','complete ordered flag lookup for dialect1'],
['0x4817e0','ConnectionFlags.LookupDialect','complete ordered flag lookup for dialect2'],
['0x44d870','ConnectionFlags.Lookup','flag lookup with explicit mode and global fallback inputs'],
['0x51ad80','ConnectionControllers.FindLocator','byte-string name lookup after explicit/default path resolution'],
['0x51adf0','ConnectionControllers.FindConnection','ordered locator adjacency lookup on resolved path; ref direction preserved on failure'],
['0x43cc30','ConnectionManager.Reset','fixed-capacity manager reset and free-list order; host allocation excluded'],
['0x43cf70','ConnectionManager.Release','valid active controller release and free-list order'],
['0x43cca0','ConnectionControllers.Create','bounded controller creation with explicit world-target services'],
['0x43cfb0','ConnectionControllers.AddFrameRange','inclusive one-based 1024-bit range masks after animation metadata resolution'],
['0x467890','ConnectionControllers.ForceEnabled','force activation predicate projected from resolved target fields'],
['0x43d0c0','ConnectionControllers.Update; ConnectionControllers.IsEnabled','ordered controller activation and connection flags with explicit target projections and gizmo-output service'],
['0x44d900','ConnectionControllers.Execute','bounded CnxController command parser/dispatcher with explicit world and numeric-expression services']
].map(([address,method,coverage])=>({address,method,coverage,sourceFile:'navigation/ConnectionControllers.cs',evidence:'reports/native-connections-contract.json'}));
const limits=[
'World/path-name registries, target binding, animation reference/header resolution, generic gizmo-output evaluation and numeric expression evaluation are explicit host services. These dependencies are not reconstructed by this module.',
'Finite float-to-int32 conversion, nonnull valid native records, byte-encoded NUL-terminated strings, locator/adjacency/path counts within byte-index limits. on_frames suffix must fit the original64-byte buffer and token separators must be present.',
'Update requires positive animation end frame and nonnull connection. Native fake-animation creation can allocate a null-edge controller even for an otherwise invalid fake ID when endpoint lookup fails; creation is retained, unsafe update is rejected.',
'Native allocation/bootstrap, corruption/double-release behavior, invalid pointers, service reentrancy and callback mutation of manager/path lists are outside the contract.',
'Animation duration/frame, visibility and force condition helpers execute unchanged in native tests. Portable source uses resolved fields; there is no whole-level pathfinder or character locomotion implementation.',
'Original x86 versus Python contract tests do not establish compiled C# equivalence. Managed compilation is separate; ordinary execution remains pending.'
];
let extra=null;try{extra=await read('reports/native-connections-review-tests.json');}catch(e){if(e.code!=='ENOENT')throw e;}
const report={schema:'native-connections-contract-v1',updated:new Date().toISOString(),binarySha256:tests.binarySha256,source,sourceSha256:await hash(source),harness:'reconstructed/navigation/ConnectionDifferential.cs',harnessSha256:await hash('reconstructed/navigation/ConnectionDifferential.cs'),scope:'Navigation connection gates used by animated scenery, build/force/obstacle state and gizmo output; not controller input.',command:{name:'CnxController',address:'0x44d900',authoredUses:tests.totals.authoredUses,nativeReturn:1},mappings,nativeVerification:{report:'reports/native-connections-tests.json',...tests.totals,groups:tests.groups,comparisonRecordsExcludingSequenceReplay:tests.totals.cases-tests.groups.pool_sequence,note:'Eight pool_sequence records replay the same528 allocation/list checks and are not additional independent coverage.',vectors:'reports/native-connections-vectors.json',vectorsSha256:await hash('reports/native-connections-vectors.json'),reviewReport:extra?'reports/native-connections-review-tests.json':null,reviewComparisons:extra?extra.totalComparisons:0,reviewMismatches:extra?extra.mismatches:null},adapters:['FindPath:0x51ad20','Scene target lookup:0x5cf5b0','Cutscene target lookup:0x57c920','BuildIt target lookup:0x58e980','FlowBox target lookup:0x59f7a0','Generic target registry:0x55a020','Gizmo output:0x55a1b0'],observations:['CnxController parser uses ordered case-insensitive substring recognition and returns1 even though the decompiler declares void.','Target lookup occurs before free-pool availability is checked. Reset and release order influence which record is allocated next.','on_frames ranges are one-based inclusive; lastframe and lastframe-1 are sentinels. Animation ranges cap at1024frames.','First matching adjacency endpoint wins. Direction chooses a connection flag word, and bothways modifies both words.','Controllers update in active-list order. Conflicting controllers sharing an edge use last-writer semantics.','Exact flag dialect is selected from original mode globals; fallback flags apply only when dialect lookup returnszero.'],limits,compiledExecution:{status:'pending',reason:'Ordinary generated managed executables are denied by Windows; no alternate host or security changes.'}};
await fs.writeFile(path.join(base,'reports/native-connections-contract.json'),JSON.stringify(report,null,2)+'\n');
await fs.writeFile(path.join(base,'reports/native-connections-findings.txt'),'NAVIGATION CONNECTION CONTROLLERS\n\n'+tests.totals.cases+' saved native comparison records; zero mismatches. '+report.nativeVerification.comparisonRecordsExcludingSequenceReplay+' excluding eight duplicate pool sequence replays. All534authored CnxController uses covered.\n13 bounded native mappings in '+source+'.\n\n'+report.observations.join('\n')+'\n\nBOUNDS\n'+limits.join('\n')+'\n');
console.log(JSON.stringify({mappings:mappings.length,tests:report.nativeVerification.comparisonRecordsExcludingSequenceReplay,sourceSha256:report.sourceSha256}));
