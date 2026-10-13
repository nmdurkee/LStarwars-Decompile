"""Stable frame-reset source snapshot, separate from shared manifests."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(p):
 d=(B/p).read_bytes();return {'file':p,'bytes':len(d),'sha256':hashlib.sha256(d).hexdigest()}
native=json.loads((R/'geometry-frame-reset-native-validation.json').read_text());managed=json.loads((R/'geometry-frame-reset-managed-check.json').read_text());core='reconstructed/geometry/FrameReset.cs'
rows=[('0x5fca40','ResetCommandContext','bounded-whole-helper-projection','Seven original sentinel writes. Caller-provided byte image replaces original context pointer; untouched bytes retained.'),('0x5fd100','ResetShaderContext','bounded-whole-helper-projection','Seven object DWORD cache clears, then command sentinels in caller-supplied global template. Whole-object/template alias case covered.'),('0x5fd160','ResetGlobalShaderContext','bounded-whole-helper-projection','Same seven cache clears and sentinel writes to one global template image.'),('0x5ddd10','ResetDisplay','bounded-whole-helper-projection','Valid decoded material-reference table and padded buffers. Repeated record/shared context aliases preserved. Finite counts at most1,000,000; native arithmetic overflow, arbitrary partial memory overlap and invalid pointers excluded.'),('0x5dfab0','Advance','bounded-caller-contract-projection','Registered display count0..256, finite acyclic sort list. Original zero-lock branch verified; nonzero synchronization remains explicit callbacks. Template/owner/list images preserve unaffected bytes and source order.')]
report={'schema':'recovered-geometry-frame-reset-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':a,'method':'FrameReset.'+m,'sourceFile':core,'coverage':c,'limitations':l+' Managed execution pending.','evidence':'geometry-frame-reset-native-validation.json'}for a,m,c,l in rows],'adaptersWithoutNativeEntry':['DisplayResetState,MaterialResetRecord,SortedResetNode,FrameResetState are decoded CPU memory projections, not native layout replacements.','MaterialBufferBytes/ClipBufferBytes bound count arithmetic and expose native padded write sizes.','Returned address lists are diagnostic call traces.','Enter/leave delegates isolate synchronization; no OS locking emulation is claimed.'],'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.FrameReset.dll'),'harness':info('reconstructed/geometry/harness/FrameResetHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /out:Recovered.Geometry.FrameReset.dll FrameReset.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.FrameReset.dll /out:FrameResetHarness.exe harness/FrameResetHarness.cs'},'native':{'report':'geometry-frame-reset-native-validation.json','assembly':'geometry-frame-reset-assembly.json','passed':native['passed'],'counts':native['counts']},'managed':managed,'fieldSemantics':{'DISP+0x74':'Flag bit15 parity; gate bits1/2; post-reset clears bits1/2/3','DISP+0x30/+0x34':'Padded two-bit-per-clip parity buffers; selected zero; force also previous0xff','DISP+0x58/+0x5c':'Padded one-bit-per-material parity buffers; selected zero only','material record+0x14':'Reset from opaque word+0x10','material record+0x34':'Force0 or normalized old==0 result, not bitwise XOR','material record+0x30':'Selected opaque word from+0x28/+0x2c','material record+0x08':'Command-context pointer; reset sentinel fields','GSNH+0x44':'Registered owner word cleared by frame advance; global owner is not handled by this loop','sort node+0x08/+0x14':'Next pointer; flags bit1 cleared','global0x973ed0':'Pending count reset0','global0x9868a0':'420-byte shader template; selected cache words and command sentinels reset'},'sourceCoverage':{'scenes':len(native['sources']),'materialReferences':sum(s['materialReferences']for s in native['sources']),'uniqueMaterialRecords':sum(s['uniqueRecords']for s in native['sources']),'uniqueContexts':sum(s['uniqueContexts']for s in native['sources']),'clipRecords':sum(s['clips']for s in native['sources'])},'remainingGaps':[{'id':'managed-execution','status':'compile passed; fixture prepared; no managed launch/bypass'},{'id':'normal-render-integration','status':'Standalone decoded CPU phase; caller adapters must connect shared display records without losing aliases'},{'id':'nonzero-lock','status':'explicit callback; zero-lock original branch verified'},{'id':'dynamic-flush','address':'0x5de440','status':'not part of frame reset; previous finish callback remains'},{'id':'sorted-completion','address':'0x5e0d00','status':'next separate phase'},{'id':'gpu-backend','status':'not claimed'}]}
(R/'geometry-frame-reset-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-frame-reset-findings.txt').write_text('''Frame reset and parity advance

Original 0x5dfab0 flips display parity for the global and registered displays,
runs 0x5ddd10 in order, clears registered owner+0x44, resets the pending count,
clears each sorted node flag bit1, resets the global shader template and leaves
the lock. Registered counts0/1/2/7/256 and populated reset tables are covered.

Original 0x5ddd10 acts only when forced or display flags&6 are nonzero. It
clears selected material and clip buffers using native padded16-byte blocks.
Forced reset also fills the previous clip buffer0xff; previous material bits
remain untouched. A material's opaque+0x14 becomes+0x10; slot+0x34 becomes0
when forced or otherwise the result of old==0, then+0x30 selects+0x28/+0x2c.
This is not an XOR toggle for arbitrary old values. Repeated table pointers
retain repeated updates and shared command-context references retain aliasing.
Flags clear bits1/2/3 only after the active work completes.

The command reset0x5fca40 performs seven sized sentinel writes. Shader reset
0x5fd100 clears seven DWORD caches in an object and resets global command
sentinels.0x5fd160 applies both to the same global template. Randomized opaque
bytes and exact unchanged-byte checks establish the scope of each write.

1,668 original cases pass:720 authored display resets across60 scenes,
832 padding/gate/alias boundaries,32 cases for each of three context helpers,
and20 integrated original frame advances.28,381,684 state/call bytes compare
without mismatch. The original block-fill and CRT code run unchanged; hook
callbacks only observe entries. No internal native implementation is replaced.
The zero-lock original branch runs unchanged; OS synchronization is excluded.

FrameReset.cs and its harness compile independently. A322,118-byte gzip input
contains every case. FrameResetHarness arguments are compressedInputFixture
and outputFile. The checker prepares or compares saved output only. Compiled
managed behavior remains pending; no managed executable was launched.
Five mappings and current source hashes are in geometry-frame-reset-source.
Counts are bounded to1,000,000 as a portable validation domain, not a recovered
native cap. Malformed pointers, arithmetic-overflow counts and partial memory
overlap are outside this module. Dynamic flush/sorted completion and GPU work
remain distinct phases.
''')
print(json.dumps({'mappings':len(rows),'native':native['passed'],'managed':managed['status'],'sourceCoverage':report['sourceCoverage']}))

