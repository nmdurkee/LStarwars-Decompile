"""Stable ordinary dynamic mesh packet source/evidence handoff."""
import json,hashlib,importlib.util
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 data=(B/path).read_bytes();return {'file':path,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);assembly={}
for address,size in [(0x5f7610,0x100),(0x603580,0x90),(0x5e0200,0xb0),(0x5e02b0,0xe0)]:
 rows=[]
 for ins in c.disasm(n.read(address,size),address):
  rows.append({'address':hex(ins.address),'bytes':ins.bytes.hex(),'mnemonic':ins.mnemonic,'operands':ins.op_str})
  if ins.mnemonic=='ret':break
 assembly[hex(address)]=rows
(R/'geometry-ordinary-packets-assembly.json').write_text(json.dumps(assembly,indent=2)+'\n')
core='reconstructed/geometry/OrdinaryMeshPackets.cs';native=json.loads((R/'geometry-ordinary-packets-native-validation.json').read_text());managed=json.loads((R/'geometry-ordinary-packets-managed-check.json').read_text())
rows=[('0x5f7610','Transpose','Ordered pair copies preserve in-place and partial-overlap behavior. Input float words may be finite,infinite or quiet NaN; signaling NaNs excluded.'),('0x603580','BuildTransform','Allocator aligns to4 and reserves64 bytes. Explicit globals80e258..80e264 plus scratch destinations2857230/28571f0. Three trailing original arguments ignored; getter results unused. Scratch/metadata storage disjoint; transpose supports overlap.'),('0x5e0200','BuildOrdinary','Complete finite ordinary writer with two8c/82 commands, cache/output pointers, alpha and signed metadata. Original EAX record/EDI output become parameters; global allocator and scratch states explicit.'),('0x5e02b0','BuildWithPrefix','Complete finite prefix writer copying command-32 opcode/resource then8c/82. Alpha patched; metadata lane remains source transpose value. Original dispatcher restricts prefix opcode to b0/ae/af; direct helper itself copies any byte. Cases use those three authored-family opcodes.')]
report={'schema':'recovered-geometry-ordinary-packets-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':a,'method':'OrdinaryMeshPackets.'+m,'sourceFile':core,'coverage':'bounded-whole-helper-projection','limitations':limits+' Valid finite allocated memory; no pointer overflow. Managed comparison pending.','evidence':'geometry-ordinary-packets-native-validation.json'}for a,m,limits in rows],'dependencies':['RenderPacketMemory','DynamicCommandSupport.Reserve','DynamicCommandSupport.StoreAlpha','DynamicCommandSupport.StoreSignedMetadata'],'native':{'report':'geometry-ordinary-packets-native-validation.json','passed':native['passed'],'counts':native['counts'],'sources':len(native['sources']),'binarySHA256':native['binarySHA256'],'assembly':info('reports/geometry-ordinary-packets-assembly.json'),'modelDependency':info('tools/geometry-dynamic-command-native.py')},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.OrdinaryPackets.dll'),'harness':info('reconstructed/geometry/harness/OrdinaryMeshPacketsHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.DynamicSupport.dll /out:Recovered.Geometry.OrdinaryPackets.dll OrdinaryMeshPackets.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.OrdinaryPackets.dll /out:OrdinaryMeshPacketsHarness.exe harness\\OrdinaryMeshPacketsHarness.cs'},'observations':['603580 does not multiply scratch scale or translation into output: the payload is caller matrix transpose only.','5d6190/5d6180 merely return original context addresses and have unused results in this producer; no native-entry coverage is separately claimed for them.','5b45a0/5b4500 produce scratch diagonal scale and translation matrices. These effects are included in603580 checks; this batch does not claim their arbitrary standalone pointer alias domain.','The ordinary path writes payload+56 as signed integer converted tofloat32 and payload+60 as clamped alpha, after the transpose. Prefix path changes only alpha.','Diagnostic returned call lists are adapters, not native return values.'], 'remainingGaps':[{'id':'dynamic-caller','address':'0x5f0f00','status':'Material selection, transformed visibility,LOD and full shader+packet caller integration remain separate.'},{'id':'billboard-packets','addresses':['0x603610','0x603970','0x5e0490'],'status':'View-dependent billboard payload and complete writer remain separate.'},{'id':'deformed-packets','addresses':['0x603710','0x5e0390'],'status':'Animation worker owns deformation payload investigation; complete writer integration pending.'},{'id':'signaling-nan','status':'Rejected due isolated emulator-vs-physical-PC load/store uncertainty documented in dynamic command report.'},{'id':'managed-execution','status':'Compile passed; saved-output comparison pending.'},{'id':'gpu-command-consumption','status':'CPU packet state verified; GPU output unclaimed.'}]}
(R/'geometry-ordinary-packets-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-ordinary-packets-findings.txt').write_text('''Ordinary dynamic mesh packets

Original603580 writes a64-byte transposed caller matrix after4-byte alignment.
Its material,mesh and prior-payload arguments are unused. The two context
getters return addresses that are ignored. It constructs scale/translation
scratch matrices at2857230/28571f0 from80e258..80e264 but does not multiply them
into the payload. Both scratch effects and the allocator result are retained.

5f7610 copies transpose pairs in a fixed instruction order. In-place operation
works; partially overlapping views preserve that original ordered read/write
behavior rather than copying the whole matrix first.128 fixtures cover source
offsets-60/-16/-4/0/4/16/60/128 with finite/subnormal/signed-zero/infinite and
quiet-NaN words. Signaling NaNs remain outside this portable domain.

5e0200 reserves two commands and writes8c(transform payload),82(mesh resource),
cache and output pointers, clamped alpha and signed-int metadata at payload
offsets60/56.5e02b0 reserves three commands: it first copies the opcode/resource
from source command32bytes earlier, then writes8c/82 and patches only alpha.
Original reserve,constructor,transpose,alpha and signed-int helpers all run
unchanged in these tests; hooks merely record entry addresses.

1,568 original-vs-Python cases pass, comparing6,422,528 complete snapshot bytes.
480 authored matrices sampled across60 source scenes each run through the
standalone producer, ordinary packet writer and prefix packet writer; the128
overlap cases are additional. Source hashes and selected special indexes are
preserved. GPU interpretation and the complete5f0f00 caller are not implied.

OrdinaryMeshPackets.cs and Main OrdinaryMeshPacketsHarness compile with default
AnyCPU. The63,710-byte gzip fixture takes compressedInputFixture/outputFile.
geometry-ordinary-packets-check.py prepares or compares saved output and never
launches it. Compiled equality remains pending. Billboard/deformed packet
families and the full caller remain explicit next dependencies.
''')
print(json.dumps({'mappings':len(rows),'cases':managed['caseCount'],'managed':managed['status']}))
