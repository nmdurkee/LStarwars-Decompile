"""Stable sorted CPU packet source snapshot for shared integration."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(p):
 d=(B/p).read_bytes();return {'file':p,'bytes':len(d),'sha256':hashlib.sha256(d).hexdigest()}
native=json.loads((R/'geometry-sorted-packets-native-validation.json').read_text());managed=json.loads((R/'geometry-sorted-packets-managed-check.json').read_text());core='reconstructed/geometry/SortedPackets.cs'
report={'schema':'recovered-geometry-sorted-packets-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':'0x5e0d00','method':'SortedPackets.Complete','sourceFile':core,'coverage':'bounded-caller-contract-projection','limitations':'Finite acyclic sort list, valid ushort material ranges/nonnegative indices and0/1 packet slots. Packet and metadata storage valid/nonoverlapping except explicit pointer aliases. Shader emission remains an explicit callback; only original already-current context branch verified. Partial overlap between shader/global images excluded. Registered count0..256. Managed execution pending.','evidence':'geometry-sorted-packets-native-validation.json'},{'address':'0x6034b0','method':'SortedPackets.Append','sourceFile':core,'coverage':'bounded-whole-helper-projection','limitations':'Finite writable packet arena, valid record/current-tail/saved-command pointers, no allocation/address wrap or metadata-overlap corruption. Preserves untouched packet padding. Managed execution pending.','evidence':'geometry-sorted-packets-native-validation.json'}],'adaptersWithoutNativeEntry':['RenderPacketMemory is a checked finite memory-image adapter preserving pointer identities.','RequireCurrentShader is a validation guard for the native607590 early-return domain; it does not reconstruct mutating shader emission.','Diagnostic uint-array call rows preserve observed helper entry/argument order.','Literal-ret callbacks5fca70/5fca80 have no CPU memory side effects; local context padding is never read by them.'],'dependencies':['FrameReset.ResetShaderContext'],'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.SortedPackets.dll'),'harness':info('reconstructed/geometry/harness/SortedPacketsHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.FrameReset.dll /out:Recovered.Geometry.SortedPackets.dll SortedPackets.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.FrameReset.dll /reference:Recovered.Geometry.SortedPackets.dll /out:SortedPacketsHarness.exe harness/SortedPacketsHarness.cs'},'native':{'report':'geometry-sorted-packets-native-validation.json','passed':native['passed'],'counts':native['counts']},'managed':managed,'fields':{'sort node+0x1c':'Owner display, or null for original empty5fca80 branch','sort node+0x20/+0x22':'Unsigned16 material count/start index; earlier geometry metadata boundsCount/firstBounds names were misleading','material record+0x10/+0x14/+0x18':'Initial command pointer,current tail pointer,saved destination command pointer','material record+0x28/+0x2c/+0x30/+0x34':'Two packet starts,current packet cursor,selected buffer slot','material record+0x0c/+0x04':'Control command and material-bit index','display flags shifted5 lowbyte':'Filter mask, AND with material+0x44 shifted14 lowbyte; match disables command and clears material bit','global0x9736e0':'Pointer to writable packet arena cursor variable','Append return':'Pointer to allocator cursor variable when payload0, otherwise0; not packet pointer'},'sourceCoverage':{'scenes':len(native['sources']),'materialEntries':sum(s['materials']for s in native['sources']),'sortRecords':sum(s['sortRecords']for s in native['sources'])},'remainingGaps':[{'id':'shader-emission','address':'0x607590','status':'Original early-return branch only; mutating cached shader command generation separate'},{'id':'dynamic-list-flush','address':'0x5de440','status':'not part of this batch'},{'id':'live-frame-state','status':'Authored material metadata with controlled valid cursor/link state; no captured live-frame proof'},{'id':'managed-execution','status':'Compiled only; fixture prepared; no launch/bypass'},{'id':'gpu-backend','status':'not claimed'}]}
(R/'geometry-sorted-packets-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-sorted-packets-findings.txt').write_text('''Sorted CPU command completion

Original0x5e0d00 follows linked sort records and uses unsigned16 material
count/start at+0x20/+0x22. These fields index material pointer tables; previous
metadata names boundsCount/firstBounds are misleading. Active command records
are linked through their initial command,current tail,saved command,and two
packet buffers. Dirty bit4 distinguishes command-tail handling. The original
filter combines only the low bytes of displayFlags>>5 and materialFlags>>14;
a match disables the material control and clears its current parity bit.
Inactive commands do not reset the cached last-shader identity.

The two callbacks5fca70/5fca80 are literal returns in this PC binary. The
local52-byte context is initialized then only passed to those empty callbacks;
its undefined padding therefore has no CPU effect. Shader607590 is a real
separate emitter. This batch calls its original already-current branch without
replacement, and source requires an explicit callback for changed contexts.
Registered nonnull shader contexts are reset after all sorted work.

432 original checks pass:240 authored cases across60 portal scenes,
64 boundary cases and128 aligned append cases.19,701 active material visits,
156 unchanged original shader early returns and22,109,459 compared state/call
bytes match. Authored material flags,index maps and sort ranges are used with
controlled valid runtime packet cursors; this is not a live captured frame.

Original6034b0 aligns the allocator cursor16, links the previous tail, emits a
type/control3 command followed by an0x8d/control1 link, updates the record tail
and advances32bytes. Its unusual return is the allocator-control pointer for
inline payload allocation,or0 for explicit payload. Packet padding remains
unchanged. All16 starting alignments,low-byte type truncation and payload modes
are checked against original instructions.

SortedPackets.cs and harness compile against FrameReset. The4,929,338-byte
gzip input contains every native fixture. Main SortedPacketsHarness takes
compressedInputFixture/outputFile; the checker prepares/compares only.
Managed execution remains pending. Finite valid pointers,acyclic lists,
nonnegative material indices and0/1 slots define the supported domain.
Partial shader/global memory overlap is excluded. No GPU work is claimed.
''')
print(json.dumps({'mappings':2,'native':native['passed'],'managed':managed['status'],'sourceCoverage':report['sourceCoverage']}))

