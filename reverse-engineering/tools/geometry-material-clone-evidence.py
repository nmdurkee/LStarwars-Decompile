"""Publish cache/copy reconstruction with constructor/device limits explicit."""
import json,hashlib,importlib.util
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 data=(B/path).read_bytes();return {'file':path,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
sp=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
assembly=[]
for start,end in[(0x547580,0x5475c0),(0x5471c0,0x547270),(0x5e4ee0,0x5e4f30),(0x5e4f30,0x5e5020),(0x5e5020,0x5e50a0)]:assembly.append({'start':hex(start),'end':hex(end),'kind':'explicit instruction window, may include adjacent padding','instructions':[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(start,end-start),start)]})
(R/'geometry-material-clone-assembly.json').write_text(json.dumps({'binarySHA256':n.sha256,'windows':assembly},indent=2)+'\n')
native=json.loads((R/'geometry-material-clone-native-validation.json').read_text());managed=json.loads((R/'geometry-material-clone-managed-check.json').read_text());core='reconstructed/geometry/MaterialCloneCache.cs';rows=[('0x547580','Next','bounded-whole-helper-projection','Valid prefix16-byte node pointers; container+8 selects first active node and previous-12 selects next.'),('0x5471c0','AllocateNode','bounded-same-thread-branch','Only matching current-thread token; cross-thread lock callbacks excluded. Empty free list returns0 unchanged, active/free links and16-bit count/flag wrapping preserved.'),('0x5e4ee0','Find','bounded-whole-helper-projection','Native EDI replacement becomes explicit argument; finite acyclic list; match reads clone+1f0 rather than cached payload+8.'),('0x5e4f30','EnsureLayouts','bounded-service-composition','Original constructor5e4b20 and refresh601030 remain explicit mutable services; declaration7418c0 represented by resolver with original cached-hit validation. Finite successful allocations, disjoint708-byte templates/clones; nonpositivecount is no-op.'),('0x5e5020','Merge','bounded-service-composition','Cache hit complete; miss composes bounded EnsureLayouts then repeats original lookup after mutable refresh. Device creation and cross-thread behavior excluded.')]
report={'schema':'recovered-geometry-material-clone-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':address,'method':'MaterialCloneCache.'+method,'sourceFile':core,'coverage':coverage,'limitations':limit+' Managed comparison pending.','evidence':'geometry-material-clone-native-validation.json'}for address,method,coverage,limit in rows],'dependencies':['RenderPacketMemory','MaterialCloneServices.AllocateMaterial (constructor boundary)','MaterialCloneServices.ResolveDeclaration (cached native declaration result)','MaterialCloneServices.RefreshMaterial (mutable shader refresh boundary)'],'native':{'report':'geometry-material-clone-native-validation.json','passed':native['passed'],'counts':native['counts'],'sources':len(native['sources']),'binarySHA256':native['binarySHA256'],'limits':native['limits'],'assembly':info('reports/geometry-material-clone-assembly.json'),'pseudocode':[info('decompiled/corpus-expanded/FUN_'+address[2:]+'.c')for address,_,_,_ in rows]},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.MaterialClone.dll'),'harness':info('reconstructed/geometry/harness/MaterialCloneCacheHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /out:Recovered.Geometry.MaterialClone.dll MaterialCloneCache.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.MaterialClone.dll /out:MaterialCloneCacheHarness.exe harness\\MaterialCloneCacheHarness.cs'},'observations':['Cache-node insertion removes first free node and prepends it to active list, maintaining backward pointers/tails and wrapping WORD active count; prefix flags OR1.','Lookup identity is replacement pointer plus live clone+1f0. Cached payload+8 is written but not used by these lookup paths; stale-key fixtures confirm.','Miss copies177 DWORDs/708bytes exactly, preserves allocated+28/+2c, clears two signed shader slots+1f4/+1f6, ORs firstWORD1, installs requested layout, resolves+2bc, invokes refresh then incrementsWORD+2c0.','Refresh may change live layout; Merge repeats lookup and can return0 instead of blindly returning the newly allocated clone.','Stack audit: after pushes at5e4f70/5e4f7d,5e4f9a [esp+18] addresses entryESP-4 local, not the first argument. Replacement remains constant across layouts; explicit zero-preserved28 multi-layout regression passes.','Original declaration lookup7418c0/741860 runs unchanged with all needed keys prepopulated. Constructor5e4b20 and refresh601030 alone are skipped controlled services; argument order and mutations compare.'], 'remainingGaps':[{'id':'material-constructor','address':'0x5e4b20','status':'Explicit successful-allocation callback; pool scan, registration queue and full initializer not ported here.'},{'id':'shader-material-refresh','address':'0x601030','status':'Explicit mutable callback; shader-manager/device program creation not ported.'},{'id':'declaration-device-creation','address':'0x7418c0','status':'Only original cache-hit behavior exercised; missing-key D3D declaration creation excluded.'},{'id':'thread-synchronization','address':'0x5471c0','status':'Same-thread branch only; lock callbacks excluded.'},{'id':'dynamic-caller-clone-composition','address':'0x5f0f00','status':'DynamicObjectSubmission stable core still restricts to matching layouts; this new service composition is not silently enabled there.'},{'id':'managed-execution','status':'Core/replay compile and compact fixture prepared; no launch.'}]}
(R/'geometry-material-clone-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-material-clone-findings.txt').write_text('''Material override clone/cache CPU reconstruction

MaterialCloneCache ports iterator547580, same-thread node allocation5471c0,
lookup5e4ee0, copy orchestration5e4f30 and wrapper5e5020. Constructor5e4b20
and shader refresh601030 are explicit mutable services. Vertex declaration
7418c0/741860 executes its original cached branch during native validation;
the portable resolver returns those captured logical handles. No device
creation or general material-pool allocation is claimed.

1,638 cases compare73,801,728 full-image bytes with0 differences:72iterator,
27node-allocation,540lookup,31multi-layout,968merge cases.480 authored708-byte
materials from60scenes feed exact copy tests.527 constructor and refresh
service sequences run, alongside527 original declaration-cache calls.
Core and replay compile; native-versus-Python pass is not managed execution.

Lookup uses replacement identity plus LIVE clone+1f0, not cached node+8.
Creation copies177DWORDs, preserves allocated+28/+2c, clears+1f4/+1f6,
ORsflagsWORD1, installs layout, resolves+2bc, calls refresh, then increments
WORD+2c0. Callback changes to layout and counter are retained; Merge's final
lookup may return0 after a refresh changes the requested layout. Same-thread
list updates and16-bit count/flag wrapping are tested, including empty lists.

An initial stack-offset suspicion was disproved by native tests. At5e4f9a,
two outstanding pushed arguments make [esp+18] the local at entryESP-4;
it does not replace the earlier template argument. Multi-layout requests
keep the same template, including the tested case allocator+28 iszero.
The published source and fixtures reflect this verified behavior.

Valid finite disjoint template/clone images and successful miss allocations
bound this module. Synchronization callbacks, cache exhaustion during clone
creation, shader compilation/device allocation and malformed pointers remain
outside it. Main MaterialCloneCacheHarness takes compressedInputFixture and
outputFile. geometry-material-clone-check.py prepares or compares a saved
result only. No managed executable, original game process or GPU was launched.
''')
print(json.dumps({'mappedEntries':len(rows),'cases':managed['caseCount'],'managed':managed['status']}))
