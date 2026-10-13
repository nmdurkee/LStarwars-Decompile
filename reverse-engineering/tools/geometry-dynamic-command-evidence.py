"""Stable helper and branch-projection handoff for dynamic geometry commands."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 data=(B/path).read_bytes();return {'file':path,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
core='reconstructed/geometry/DynamicCommandSupport.cs';native=json.loads((R/'geometry-dynamic-command-native-validation.json').read_text());managed=json.loads((R/'geometry-dynamic-command-managed-check.json').read_text())
rows=[('0x603530','Reserve','bounded-whole-helper-projection','Finite nonnegative command count<=1000000, valid disjoint record/control/arena memory, no address wrap. Native cases cover counts0/1/2/3/8/16/255/512 and all16 cursor alignments; EAX allocator-control return verified.'),('0x603ad0','StoreAlpha','bounded-whole-helper-projection','Complete command.resource+0x3c store extends existing SceneSubmission.ClampInstanceAlpha pure-result projection; same native entry, not new address credit. Quiet-NaN payload/sign and signed zero retained; signaling NaNs rejected.'),('0x603b10','StoreSignedMetadata','bounded-whole-helper-projection','Signed32 integer converted to float32 at command.resource+0x38. Finite valid pointers; original second argument unused.'),('0x5fd220','SetOverride','bounded-whole-helper-projection','Explicit shader pointer replaces global0x9868a0. Original second/fourth arguments ignored. Raw scalar word preserves non-NaN and quiet-NaN payload; signaling NaNs rejected. Identifier DWORD and WORD increments wrap.'),('0x5e0530','SelectPacketRoutine','small-extracted-branch','Only exact routine-selection predicate; selected packet writer and ABI forwarding are not executed by the portable projection. Native downstream targets are recorded then skipped.')]
report={'schema':'recovered-geometry-dynamic-command-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':a,'method':'DynamicCommandSupport.'+m,'sourceFile':core,'coverage':coverage,'limitations':limits+' Managed comparison pending.','evidence':'geometry-dynamic-command-native-validation.json'}for a,m,coverage,limits in rows],'dependencies':['RenderPacketMemory'],'native':{'report':'geometry-dynamic-command-native-validation.json','passed':native['passed'],'counts':native['counts'],'binarySHA256':native['binarySHA256'],'excludedSignalingNanCount':native['excludedSignalingNanCount'],'assembly':info('reports/geometry-dynamic-command-assembly.json')},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.DynamicSupport.dll'),'harness':info('reconstructed/geometry/harness/DynamicCommandSupportHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /out:Recovered.Geometry.DynamicSupport.dll DynamicCommandSupport.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.DynamicSupport.dll /out:DynamicCommandSupportHarness.exe harness\\DynamicCommandSupportHarness.cs'},'fields':{'record+0x14/+0x18/+0x24':'Current command tail/saved link/current reserved command cursor','shader+0x20/+0x1e':'Wrapping DWORD identifier and WORD scalar-key identifier','shader+0xf4/+0xf8/+0xfc':'First override argument/raw float scalar/material pointer','shader+0x180':'Cached optional scalar payload reset to0','material+0xb4':'High bit gates special preceding command packet path','selected command byte0':'0x8f selects5e0490 first regardless other mode flags','command-0x20 byte0':'0xb0/0xae/0xaf allow5e02b0 when material high bit and signed count>1'},'remainingGaps':[{'id':'full-dynamic-submission','address':'0x5f0f00','status':'Dependency work; transformed-bound visibility,LOD and full material/mesh submission remain separate.'},{'id':'dynamic-packet-writers','addresses':['0x5e0200','0x5e02b0','0x5e0390','0x5e0490'],'status':'Selection verified; writer bodies and matrix/morph/billboard payloads still separate.'},{'id':'signaling-nan','status':'17 raw original-instruction Unicorn observations preserved separately. Emulator retains signaling bit; physical-PC behavior not established, domain rejected in source.'},{'id':'managed-execution','status':'Core and replay compile; comparison pending; no launch/bypass.'},{'id':'gpu-command-consumption','status':'CPU helper data only; GPU output unclaimed.'}]}
(R/'geometry-dynamic-command-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-dynamic-command-findings.txt').write_text('''Dynamic geometry command support

Four complete finite helpers and one bounded dispatcher predicate are now
ported.603530 aligns the arena cursor to16, patches the previous tail link,
reserves count16-byte commands, writes an8d/control1 terminator pointing to
saved+16, updates record tail/current cursor and returns the allocator-control
pointer.603ad0 clamps/stores alpha at command.resource+3c;603b10 stores signed32
integer converted to float32 at resource+38.5fd220 updates explicit shader
override fields, increments DWORD/WORD identifiers with wrapping and clears
the cached scalar payload. Its second/fourth native arguments are unused.

5e0530 first selects5e0490 for command0x8f. Otherwise a nonzero mode selects
5e0390. Zero mode selects5e02b0 only when material+b4 high bit is set, signed
command count>1 and the preceding command32bytes earlier is0xb0/0xae/0xaf;
otherwise5e0200. These selected writer bodies are explicit skipped boundaries
in the dispatcher test. No complete packet-writer claim follows from this.

Original-vs-Python comparisons pass1,251 complete-helper cases plus1,696
dispatcher cases, with40,992,768 state bytes checked. Counts:128 reservation,
524 alpha,543 signed-integer store and56 override cases. The signed-integer
set includes Int32 extremes and values adjacent to2^24 float32 rounding ties.
Every opcode byte and signed count/mode boundaries are covered in selection.

17 signaling-NaN inputs are separately preserved with unchanged-original
instruction observations. Unicorn retained the signaling quiet-bit in FLD/
FSTP cases. Physical-PC signaling behavior is not established by that result;
the portable helpers reject signaling NaNs. Compared inputs include finite
values, subnormals, signed zeros,infinities and quiet NaNs. Quiet payload/sign
bits are retained directly rather than relying on host NaN arithmetic.

DynamicCommandSupport.cs and Main DynamicCommandSupportHarness compile with
ordinary AnyCPU. The2,831,946-byte gzip fixture takes compressedInputFixture
and outputFile; geometry-dynamic-command-check.py only prepares or compares
saved results. Managed equivalence remains pending.603ad0 upgrades an existing
pure-result mapping and must not be counted as a new native address.
''')
print(json.dumps({'mappings':len(rows),'newAddresses':4,'wholeHelperCases':managed['caseCount'],'branchCases':managed['dispatchCases'],'managed':managed['status']}))
