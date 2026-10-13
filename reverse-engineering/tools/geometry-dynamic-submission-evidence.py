"""Publish bounded normal dynamic caller source and exact evidence boundaries."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 b=(B/path).read_bytes();return {'file':path,'bytes':len(b),'sha256':hashlib.sha256(b).hexdigest()}
native=json.loads((R/'geometry-dynamic-submission-native-validation.json').read_text());managed=json.loads((R/'geometry-dynamic-submission-managed-check.json').read_text());core='reconstructed/geometry/DynamicSubmission.cs'
dependencies=['DynamicBounds.Classify','DynamicBounds.TransformPoints','DynamicSelection.SelectLod','DynamicSelection.ChooseMaterial','DynamicSelection.FilterChain','DynamicCommandSupport.SetOverride','DynamicCommandSupport.SelectPacketRoutine','ShaderContextEmission.Emit','OrdinaryMeshPackets.BuildOrdinary','OrdinaryMeshPackets.BuildWithPrefix','Recovered.Animation.PlaybackWide','RenderPacketMemory']
report={'schema':'recovered-geometry-dynamic-submission-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':'0x5f0f00','method':'DynamicObjectSubmission.Submit','sourceFile':core,'coverage':'bounded-normal-branch-composition','limitations':'Normal path only: zero shadows/sway, inactive fade, null skin/morph inputs, ordinary/prefix commands, same-layout overrides, finite math and bounded valid disjoint metadata/arena images. No clone/cache, billboard, SIMD clipping, shadow or GPU behavior. Fixed globals and native stack scratch become explicit inputs. Managed comparison pending.','evidence':'geometry-dynamic-submission-native-validation.json'}],'dependencies':dependencies,'native':{'report':'geometry-dynamic-submission-native-validation.json','passed':native['passed'],'counts':native['counts'],'returnClasses':native['returnClasses'],'sources':len(native['sources']),'binarySHA256':native['binarySHA256'],'limits':native['limits'],'pseudocode':info('decompiled/corpus-expanded/FUN_5f0f00.c'),'modelDependencies':[info('tools/'+f)for f in['geometry-dynamic-bounds-native.py','geometry-dynamic-command-native.py','geometry-ordinary-packets-native.py','geometry-shader-emission-native.py','animation-x87.py']]},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.DynamicSubmission.dll'),'harness':info('reconstructed/geometry/harness/DynamicSubmissionHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.ShaderEmission.dll /reference:Recovered.Geometry.DynamicSupport.dll /reference:Recovered.Geometry.OrdinaryPackets.dll /reference:Recovered.Geometry.DynamicSelection.dll /out:Recovered.Geometry.DynamicSubmission.dll DynamicSubmission.cs DynamicBounds.cs ..\\animation\\CharacterContexts.cs ..\\animation\\AnimationPlayback.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.DynamicSubmission.dll /out:DynamicSubmissionHarness.exe harness\\DynamicSubmissionHarness.cs'},'observations':['Null handle and invisible zero-shadow cases return before final shader/reset mutation; existing shadow mask is preserved.','Bounds result is returned unchanged, including a supplied negative forced visibility other than-1; any nonzero result submits normal draws.','Center adds min/max with float32 stores, multiplies0.5 with a float32 store, then transforms. Camera subtraction stores each float32 difference before extended squared-distance accumulation.','Current material owner+74 gainsmask0x2. Its bit15 chooses material bitset+58/+5c; record+4 selects byte/bit. Same-layout override precedence and linked gate order compose existing recovered branches.','Every accepted material sets global shader overrides then performs real607590 emission before actual5e0530 ordinary/prefix writer dispatch.','Source command array contains indexes into16-byte commands. Flag+b4 highbit, signed commandindex>1 and preceding command-32 opcodeb0/ae/af select prefix writer.','Instanceflag20 plus shadowmetadata-disable0 selects metadata1 even when shadow count is0. Ordinary writer patches it; prefix writer preserves source transpose lane.','Final5fd220 zeros override inputs and increments context counters even when no materials pass filtering. Zero-shadow normal path then clears9715a0.'], 'remainingGaps':[{'id':'dynamic-shadow-submission','status':'Zero-shadow branch only; shadow bounds and per-light packet schedules remain separate.'},{'id':'dynamic-sway','address':'0x5ec590','status':'Nonzero special+ca rejected.'},{'id':'dynamic-active-fade-integration','address':'0x5df7b0','status':'Existing standalone fade helper is not integrated into this composed branch.'},{'id':'material-clone-cache','address':'0x5e5020','status':'Different-layout override rejected by missing callback; allocation/cache not invented.'},{'id':'morph-skin-caller-integration','address':'0x5e0390','status':'Animation-owned MorphMeshPackets is separately verified; this caller exposes only null skin/morph inputs.'},{'id':'billboard-packets','address':'0x5e0490','status':'Unsupported by this caller.'},{'id':'managed-execution','status':'Source and replay compile; no managed launch.'},{'id':'gpu-backend','status':'CPU packet memory only; GPU interpretation, final imagery and performance unclaimed.'}]}
(R/'geometry-dynamic-submission-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-dynamic-submission-findings.txt').write_text('''Normal dynamic submission composition (PC0x5f0f00)

DynamicObjectSubmission.Submit connects scalar transformed bounds, center/distance,
LOD and same-layout override selection, material visibility marking, mutable
shader-context emission, and ordinary/prefix mesh packet production. It is a
bounded normal branch, not the full renderer. Existing small5f0f00 mappings
are superseded for this supported domain without adding extra address credit.

All original nested functions execute unchanged in1,568 differential cases.
480 authored special-object bounds, transforms and LOD arrays from60 scenes
are combined with controlled relocated runtime records.1,413 actual packet
writers execute (781ordinary,632prefix), alongside504 original scalar bounds
calls and1,413 shader emissions.102,710,272 persistent bytes, return values,
shadow-mask state and material/index/writer sequences compare with0 errors.
This is native-versus-Python evidence, not an executed C# comparison.

The original transient stack cache/output window is represented by32 bytes
of explicit portable scratch and excluded from persistent-image hashing.
Shader context, matrix scratch and bounds globals are mirrored into the
compact image after native execution; their values are fully compared.
No hooks replace original instructions or return values in this batch.

Early invisible/null returns preserve shader and shadow-mask state. Reached
normal completion resets shader overrides and clears the mask even when
filtering emits no draw. Material bitset parity comes from owner+74 bit15;
owner+74 mask0x2 is set. Instanceflag20 can request metadata1 even with no shadow
lights; the prefix writer still preserves the original matrix metadata lane.

Excluded paths: shadows, sway, active fade, material clone/cache, SIMD bounds,
morph/skinned and billboard commands. Animation-owned MorphMeshPackets is
separately recovered but is not yet composed here. Finite valid disjoint
metadata/arena images, acyclic chains, terminated LOD arrays and nonnegative
material IDs bound the portable implementation. These guards do not claim
the original handles arbitrary malformed inputs safely.

Core and Main DynamicSubmissionHarness compile with default AnyCPU. Use
compressedInputFixture/outputFile; geometry-dynamic-submission-check.py
prepares fixtures or compares a saved result only. Managed execution stays
deferred. CPU packet equality does not establish GPU output or performance.
''')
print(json.dumps({'source':core,'nativeMappings':1,'cases':native['counts']['cases'],'managed':managed['status']}))
