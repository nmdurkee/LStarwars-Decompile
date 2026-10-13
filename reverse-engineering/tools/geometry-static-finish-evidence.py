"""Durable source handoff for the bounded static finishing phase."""
import hashlib,json
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(p):
 d=(B/p).read_bytes();return {'file':p,'bytes':len(d),'sha256':hashlib.sha256(d).hexdigest()}
core='reconstructed/geometry/StaticFinalization.cs'
native=json.loads((R/'geometry-static-finish-native-validation.json').read_text())
managed=json.loads((R/'geometry-static-finish-managed-check.json').read_text())
mappings=[('0x5df880','PatchAlpha','bounded-whole-helper-projection','Valid decoded command and clip records; preceding transforms retain reference aliasing. Original NaN payload and signed-zero clamp semantics retained.'),('0x5e0bd0','PatchMaterials','bounded-whole-helper-projection','Valid material/command arrays and parity buffers; raw gate bytes retain unresolved broader semantic names.'),('0x5f0d70','Finish','bounded-caller-contract-projection','Up to 256 registered scenes; dynamic-list flush, sorted packet completion and nonzero locking remain explicit external callbacks. Tests use the unchanged original zero-lock path and empty orchestration tables; populated patchers tested separately.')]
report={'schema':'recovered-geometry-static-finish-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':a,'method':'StaticFinalization.'+m,'sourceFile':core,'coverage':c,'limitations':l+' Compiled C# execution pending.','evidence':'geometry-static-finish-native-validation.json'} for a,m,c,l in mappings],'adaptersWithoutNativeEntry':['StaticFinishScene and MaterialControlTarget decode original pointer arrays and preserve item-to-matrix aliasing.','StaticFinishCallbacks explicitly delimit unresolved dynamic/sorted packet side effects and locking. Returned address list is diagnostic evidence, not a native data structure.'],'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.StaticFinish.dll'),'harness':info('reconstructed/geometry/harness/StaticFinalizationHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.dll /out:Recovered.Geometry.StaticFinish.dll StaticFinalization.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.dll /reference:Recovered.Geometry.StaticFinish.dll /out:StaticFinalizationHarness.exe harness/StaticFinalizationHarness.cs'},'native':{'report':'geometry-static-finish-native-validation.json','passed':native['passed'],'counts':native['counts']},'managed':managed,'dependencies':['SceneSubmission.PatchClipControls','SceneSubmission.ClampInstanceAlpha','SceneVisibility'],'fieldSemantics':{'DISP+0x68':'Per-clip alpha floats; null suppresses alpha patcher','mesh item byte0/byte1':'Type0x82 and nonzero control select alpha patch','preceding item+4 -> matrix+0x3c':'Alpha target, shared across items where authored','DISP+0x4c/+0x50/+0x54':'Material count, material pointer table, control record pointer table','material record+4/+0x0c':'Selected material index and target command pointer','material+0xf8/+0xf9/+0xfa':'Three raw gate bytes; do not infer RGB semantics','DISP+0x58/+0x5c':'Material parity bitsets; flags bit15 chooses current','global0x9739b8/0x9739bc':'Registered scene count and up-to-256 pointer slots','global0x973ed4 -> 0x973f34':'Copy 24 DWORD counters before sorted completion'},'remainingGaps':[{'id':'dynamic-list-flush','address':'0x5de440','status':'explicit callback; original internals not reconstructed here'},{'id':'sorted-packet-completion','address':'0x5e0d00','status':'explicit callback; original internals not reconstructed here'},{'id':'material-gate-byte-meaning','offsets':['0xf8','0xf9','0xfa'],'status':'exact branch behavior recovered; semantic labels unresolved'},{'id':'managed-execution','status':'compiled only; compressed fixture prepared; no execution or bypass attempted'},{'id':'gpu-backend','status':'not claimed'}]}
(R/'geometry-static-finish-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-static-finish-findings.txt').write_text('''Static display finishing: native CPU behavior and portable source

Original 0x5df880 patches matrix alpha only for active mesh commands (type
0x82, nonzero control byte). The target is float+0x3c of the preceding
command's transform. Shared matrices retain aliasing and last-write order.
The original clamp preserves signed zero and unordered NaN, including the
tested NaN payload; positive/negative infinity clamp to one/zero.

Original 0x5e0bd0 skips an equal parity byte as a group of eight records and
bounds the partial last byte by the material count. Missing scene, missing
material table, or null first table entry suppresses the entire helper.
A later null selected material only bypasses its gate. Three raw material
bytes at +0xf8/+0xf9/+0xfa and the global mode control activation; their
broader meaning remains unresolved and is not called RGB or color here.

All 60 authored portal scenes pass: 240 alpha cases, 720 material cases,
288 synthetic material boundaries and 20 finish orchestration cases.
Comparisons include 4,584,192 alpha-matrix DWORDs and 55,078,912 command
bytes. Full transforms and untouched command bytes are checked, not just
the changed fields. There are zero mismatches.

Original 0x5f0d70 enters its lock, flushes dynamic lists, executes an empty
callback, patches global materials, visits registered displays in source
order, patches clips/alpha when flag4 is set and materials when flags6
are set, copies 24 counters, finishes sorted packets and leaves the lock.
Registry sizes 0/1/2/7/256 are covered. The native flush (0x5de440) and
sorted completion (0x5e0d00) are recorded no-op boundaries in orchestration
tests. Their side effects are not claimed; source requires callbacks.
The zero-lock original branch and original empty 0x603920 run unchanged.

StaticFinalization.cs and its harness compile as a separate assembly.
The 1,480,609-byte gzip fixture covers all 1,268 cases; harness arguments
are compressedInputFixture/outputFile. The checker prepares or compares
saved output only. No managed executable was launched. Native-versus-model
verification is distinct from still-pending compiled C# comparison.
The machine-readable source report contains three address mappings,
source hashes, build commands and explicit remaining boundaries.
''')
print(json.dumps({'mappings':len(mappings),'nativePassed':native['passed'],'managed':managed['status']}))

