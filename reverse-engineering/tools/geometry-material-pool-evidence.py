"""Durable pool/default source mappings and clone-composition evidence."""
import json,hashlib,importlib.util
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 b=(B/path).read_bytes();return {'file':path,'bytes':len(b),'sha256':hashlib.sha256(b).hexdigest()}
sp=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
windows=[]
for start,end in[(0x5e5140,0x5e51c0),(0x600f20,0x601030),(0x5e4b20,0x5e4c80)]:windows.append({'start':hex(start),'end':hex(end),'kind':'explicit instruction window, may include adjacent padding','instructions':[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(start,end-start),start)]})
(R/'geometry-material-pool-assembly.json').write_text(json.dumps({'binarySHA256':n.sha256,'colorScaleDouble':n.unpack('<d',0x7531f8)[0],'windows':windows},indent=2)+'\n')
native=json.loads((R/'geometry-material-pool-native-validation.json').read_text());managed=json.loads((R/'geometry-material-pool-managed-check.json').read_text());core='reconstructed/geometry/MaterialPool.cs';rows=[('0x5e5140','ResetRuntime','bounded-whole-helper-projection','Valid520-byte runtime destination ornull. Exact defaults and untouched surrounding bytes.'),('0x600f20','Initialize','bounded-whole-helper-projection','Valid material image; signed texture count. Used RGB*255 products finite and within signedInt32 range, native truncate-toward-zero packing. Invalid/overflow FISTP behavior excluded.'),('0x5e4b20','Allocate','bounded-positive-count-zero-lock-branch','Positive count and sufficient free708-byte slots; valid disjoint pending queue with at most600entries; original lock token0. Fatal exhaustion/overflow and uninitialized nonpositive-count branch excluded.')]
report={'schema':'recovered-geometry-material-pool-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':a,'method':'MaterialPool.'+m,'sourceFile':core,'coverage':coverage,'limitations':limit+' Managed comparison pending.','evidence':'geometry-material-pool-native-validation.json'}for a,m,coverage,limit in rows],'compositionMappings':[{'address':'0x5e5020','method':'MaterialCloneCache.Merge with MaterialPool.Allocate constructor service','sourceFile':'reconstructed/geometry/MaterialCloneCache.cs','coverage':'supporting-composition-no-new-address-credit','limitations':'480 authored clone misses use original constructor; only shader refresh601030 remains controlled. Declaration lookup is prepopulated cache-hit branch. See replay composition in MaterialPoolHarness.'}],'dependencies':['RenderPacketMemory'],'native':{'report':'geometry-material-pool-native-validation.json','passed':native['passed'],'counts':native['counts'],'sources':len(native['sources']),'binarySHA256':native['binarySHA256'],'limits':native['limits'],'assembly':info('reports/geometry-material-pool-assembly.json'),'pseudocode':[info('decompiled/corpus-expanded/FUN_'+a[2:]+'.c')for a,_,_,_ in rows],'cloneModelDependency':info('tools/geometry-material-clone-native.py')},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.MaterialPool.dll'),'harness':info('reconstructed/geometry/harness/MaterialPoolHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /out:Recovered.Geometry.MaterialPool.dll MaterialPool.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.MaterialClone.dll /reference:Recovered.Geometry.MaterialPool.dll /out:MaterialPoolHarness.exe harness\\MaterialPoolHarness.cs'},'observations':['Pool scan chooses first slot with flagsbyte bit0 clear AND material+3c0; it restarts at pool base for each allocation.','Each chosen708-byte slot iszeroed; defaultRGB/alpha are1, flags include type lowbyte shifted4 and5, material+40=3f962010 and+44=10. Unregistered allocation adds+44 mask800000.','Registered allocations append pointers in allocation order to the600-entry queue. Link+30 prepends each new material, so returned head is reverse allocation order.','Only the final returned head invokes600f20; earlier chained materials retain basic defaults without520-byte runtime initialization.','Runtime reset sets layout101, runtimeflags1000, parameterdefaults andfourffffffff words. Positive signed texture count sets+b8, byte15c andlayout901; registration0 adds layout40000.','Color branch explicitly switches x87 rounding totruncate, multiplies sourcefloat by double255, stores signedInt32 then masks lowbyte. ResultARGB has alpha255, sourceR atlowbyte, sourceG atbits8, sourceB atbits16. Colors outside0..1 wrap rather than clamp.','Full clone composition uses these real defaults/registration effects and preserves allocated+28/+2c zero before authored copy. Original cache helper/declaration hits run; only shader refresh iscontrolled.'],'remainingGaps':[{'id':'shader-material-refresh','address':'0x601030','status':'Remaining mutable service in clone integration; shader manager/device program behavior separate.'},{'id':'material-pool-failures','address':'0x5e4b20','status':'Sufficient capacity only; originalfatal diagnostics and invalid nonpositive-count stack reads not ported.'},{'id':'material-pool-locks','status':'Locktoken0 branch; OS synchronization excluded.'},{'id':'color-invalid-products','address':'0x600f20','status':'NaN/infinite/out-of-Int32 FISTP products excluded; finite successful integer products verified.'},{'id':'dynamic-caller-material-services','status':'Stable DynamicObjectSubmission still same-layout only; constructor/clone integration established separately.'},{'id':'managed-execution','status':'Compile passed; prepared replay not launched.'}]}
(R/'geometry-material-pool-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-material-pool-findings.txt').write_text('''Material pool and default initialization

MaterialPool.Allocate recovers successful positive-count5e4b20 with locktoken0;
ResetRuntime and Initialize recover5e5140 and600f20 in their bounded domains.
1,747 original-x86 cases compare78,712,832 full-image bytes with0differences:
17reset,1,080initializer,170pool and480complete clone-miss integrations.
480 authored708-byte materials from60scenes supply preserved source fields.
650 original constructor calls execute, including all480clone paths; only
shader refresh601030 remains a controlled service in those chains. Original
declaration-cache hits execute unchanged. This is native/Python evidence.

The pool scans first-free using BOTH first-byte bit0 and+3c==0. It zeroes708
bytes, writes defaults, appends registered allocations to a600-pointer queue,
and prepends link+30. Returnedhead is reverse allocation order. Only that
finalhead receives600f20 runtime initialization; earlier chain members retain
basic defaults. Unregistered allocation adds+44 mask800000 andlayout40000.

5e5140 resets exactly520 bytes. Positive signed texture count selects901
layout after reset and sets+b8/byte15c. Otherwise original600f20 temporarily
forces x87 truncation toward zero, convertsRGB*255 toInt32 and retains each
lowbyte. It does not round or clamp colors; .5 produces127 and out-of-range
finite colors wrap. Products are bounded to finite signedInt32 range here.

Core and Main MaterialPoolHarness compile with defaultAnyCPU. Replay takes
compressedInputFixture/outputFile; geometry-material-pool-check.py prepares
or compares saved output and does not launch it. Managed equality remains
pending. Pool exhaustion,queue overflow,nonpositive allocator counts,OSlocks,
invalid floating-point products and GPU program/device behavior are excluded.
''')
print(json.dumps({'nativeMappings':len(rows),'supportingComposition':1,'cases':managed['caseCount'],'managed':managed['status']}))
