"""Publish material refresh CPU services with exact factory boundary."""
import json,hashlib,importlib.util
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 b=(B/path).read_bytes();return {'file':path,'bytes':len(b),'sha256':hashlib.sha256(b).hexdigest()}
sp=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
windows=[]
for start,end in[(0x601030,0x601210),(0x741620,0x741640),(0x7415b0,0x7415c0),(0x6e27d0,0x6e2810),(0x741770,0x7417b0)]:windows.append({'start':hex(start),'end':hex(end),'kind':'explicit instruction window, may include adjacent padding','instructions':[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(start,end-start),start)]})
(R/'geometry-material-refresh-assembly.json').write_text(json.dumps({'binarySHA256':n.sha256,'windows':windows},indent=2)+'\n')
native=json.loads((R/'geometry-material-refresh-native-validation.json').read_text());managed=json.loads((R/'geometry-material-refresh-managed-check.json').read_text());core='reconstructed/geometry/MaterialRefresh.cs';rows=[('0x601030','Refresh','bounded-zero-lock-service-composition','CPU field/reference/color operations and shader dispatch;7416a0 factory explicit, declaration resolution verified on original cached branch. Old positive IDs1..400; finite usedRGB*255 inInt32 range. Zero lock token.'),('0x741620','ProgramByIndex','bounded-whole-helper-projection','Unsigned0..400 index maps manager+4+index*1240; other indices return0. No pointer wrapping.'),('0x7415b0','Release','bounded-whole-helper-projection','Valid program image; DWORD reference subtraction wraps.'),('0x6e27d0','FirstMode','bounded-whole-helper-projection','Device+654 bit20 produces16 or0; native ECX becomes explicit.'),('0x6e27f0','SecondMode','bounded-whole-helper-projection','Device+654 bit20 produces1 or0; native ECX becomes explicit.'),('0x741770','RequestDefault','bounded-service-wrapper','Exact manager/runtime/material/mode0/trailing0/0 forwarding to explicit7416a0 factory; wrapper arguments and native thiscall stack cleanup verified.'),('0x741790','RequestMode','bounded-service-wrapper','Exact manager/runtime/material/suppliedmode/trailing0/0 forwarding to explicit7416a0 factory; shader program generation excluded.')]
report={'schema':'recovered-geometry-material-refresh-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':a,'method':'MaterialRefresh.'+method,'sourceFile':core,'coverage':coverage,'limitations':limit+' Managed comparison pending.','evidence':'geometry-material-refresh-native-validation.json'}for a,method,coverage,limit in rows],'dependencies':['RenderPacketMemory','MaterialProgramFactory (original7416a0 shader-service boundary)','MaterialRefreshServices.ResolveDeclaration (original cached declaration result)'],'native':{'report':'geometry-material-refresh-native-validation.json','passed':native['passed'],'counts':native['counts'],'sources':len(native['sources']),'binarySHA256':native['binarySHA256'],'limits':native['limits'],'assembly':info('reports/geometry-material-refresh-assembly.json'),'pseudocode':[info('decompiled/corpus-expanded/FUN_'+a[2:]+'.c')for a,_,_,_ in rows]},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.MaterialRefresh.dll'),'harness':info('reconstructed/geometry/harness/MaterialRefreshHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /out:Recovered.Geometry.MaterialRefresh.dll MaterialRefresh.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.MaterialRefresh.dll /out:MaterialRefreshHarness.exe harness\\MaterialRefreshHarness.cs'},'observations':['Positive signed texture count updates+b8 and ensures byte15c nonzero, adding layout800 only if mask3800 absent. Unregistered bit800000 withcontrol+3c0 adds layout40000.','Both positive old signed shader indices+1f4/+1f6 release references before requesting replacements. Duplicate IDs release the same count twice; DWORD subtraction wraps.','Unregistered material branch requests one default program and overwrites only+1f4. Secondary+1f6 remains unchanged even though its reference was released.','Normal branch requests modes16/1 when devicebit20 ison, otherwise0/0. It re-reads mode for the second call, preserving callback changes to device state.','First program WORD index is read only after the second factory call. Aliased results and changes to the first result during the second call are retained.','Declaration resolution reads live layout after factory callbacks. Packed color refresh occurs only for textureCount exactly0; negative values preserve existing color, unlike default initializer600f20.','Native7416a0 factory uses thiscall cleanup of20argumentbytes. Wrapper741770/741790 remain original during tests; only factory is bypassed with explicit mutable service.'], 'remainingGaps':[{'id':'shader-factory','address':'0x7416a0','status':'Explicit mutable program-factory service; shader compiler/cache allocation and device creation not ported by this batch.'},{'id':'declaration-cache-miss','address':'0x7418c0','status':'Original cached-hit resolver verified; missing-key declaration creation separate.'},{'id':'shader-locks','status':'Original zero-lock branch only; OS synchronization excluded.'},{'id':'invalid-reference-or-color','status':'Valid old positive program IDs and finiteInt32 color products; malformed IDs/invalid floating-point conversion excluded.'},{'id':'clone-refresh-composition','status':'Pool/clone and refresh now separately buildable and verified; their joined native miss chain with this new factory boundary is the next integration slice.'},{'id':'managed-execution','status':'Core/replay compile; no launch.'}]}
(R/'geometry-material-refresh-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-material-refresh-findings.txt').write_text('''Material refresh and shader-service dispatch

MaterialRefresh recovers601030 CPU refresh plus741620 lookup,7415b0 release,
6e27d0/6e27f0 device mode getters and741770/741790 factory wrappers.2,209
original-x86 checks pass:1,280refresh cases,406index lookups,6reference
wrapping cases,512mode-byte cases and5wrapper calls.480 authored materials
from60scenes are included.144,769,024 full-image bytes and2,005 factory
argument sequences match the Python model with0errors.

The original caller/helpers/wrappers and cached declaration resolver execute
unchanged. Only7416a0 shader factory is a controlled mutable service. It can
alias returned programs, modify the first result during the second call,
change device flags or texture count. These mutations are deliberately
retained to verify read ordering, not to imitate a full shader compiler.

Both positive old shader IDs release references before requests. The default
unregistered branch writes primary only: secondary retains its oldWORD even
after release. Normal branch obtains mode16/1 or0/0 from devicebit20, re-reading
before the second request. It reads the first result's WORD only after the
second call. TextureCount==0 repacks color; negative counts preserve color,
unlike600f20 default initialization. RGB packing truncates and wraps bytes.

Zero locks, valid indices and finiteInt32-range color products bound this
module. Shader factory/declaration creation,OS synchronization and invalid
conversions remain separate. Core and Main MaterialRefreshHarness compile;
compressedInputFixture/outputFile replay is prepared, not launched. The
geometry-material-refresh-check.py tool only prepares/compares saved output.
Native/model equality does not claim compiled execution or GPU output.
''')
print(json.dumps({'nativeMappings':len(rows),'cases':managed['caseCount'],'managed':managed['status']}))
