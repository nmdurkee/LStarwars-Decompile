"""Stable normal-submission material lifecycle extension, no new address."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 b=(B/path).read_bytes();return {'file':path,'bytes':len(b),'sha256':hashlib.sha256(b).hexdigest()}
native=json.loads((R/'geometry-dynamic-material-native-validation.json').read_text());managed=json.loads((R/'geometry-dynamic-material-managed-check.json').read_text());core='reconstructed/geometry/DynamicSubmission.cs'
report={'schema':'recovered-geometry-dynamic-material-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[],'compositionMappings':[{'address':'0x5f0f00','method':'DynamicObjectSubmission.SubmitWithMaterialMerge','sourceFile':core,'coverage':'supporting-normal-branch-refinement-no-new-address-credit','limitations':'Normal ordinary/prefix caller with MaterialLifecycle merge callback. Zero shadows/sway/fade, null skin/morph, successful capacities and same-thread zero-lock services. Shader factory7416a0 remains explicit; original declaration-cache hits. Managed equality pending.','evidence':'geometry-dynamic-material-native-validation.json'}],'dependencies':[info('reconstructed/geometry/'+f)for f in['MaterialLifecycle.cs','MaterialCloneCache.cs','MaterialPool.cs','MaterialRefresh.cs','DynamicSelection.cs','ShaderContextEmission.cs','OrdinaryMeshPackets.cs']],'native':{'report':'geometry-dynamic-material-native-validation.json','passed':native['passed'],'counts':native['counts'],'normalCounts':native['normalCounts'],'sourceObjects':native['sourceObjects'],'sources':len(native['sources']),'binarySHA256':native['binarySHA256'],'limits':native['limits'],'modelDependencies':[info('tools/'+f)for f in['geometry-dynamic-submission-native.py','geometry-material-clone-native.py','geometry-material-pool-native.py','geometry-material-refresh-native.py']]},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.DynamicSubmission.dll'),'harness':info('reconstructed/geometry/harness/DynamicMaterialHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'See geometry-dynamic-submission-source.json: same core dependencies; Submit delegates to new overload with null callback.','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.DynamicSubmission.dll /reference:Recovered.Geometry.MaterialClone.dll /reference:Recovered.Geometry.MaterialPool.dll /reference:Recovered.Geometry.MaterialRefresh.dll /reference:Recovered.Geometry.MaterialLifecycle.dll /out:DynamicMaterialHarness.exe harness\\DynamicMaterialHarness.cs','compatibility':'Existing DynamicSubmissionHarness recompiled against the changed core; original1568 native fixture set retained unchanged. No managed launch.'},'observations':['Different-layout override is now an explicit callback at the original5e5020 point. Default Submit preserves its prior null-callback/same-layout behavior.','360 full original caller cases exercise120 authored objects across60scenes andthree override policies, producing600 merge calls,480 actual constructors/refreshes and393 actual packet writes.','480 clone misses plus120 cache reuses occur inside the same normal caller.960 shader-factory calls remain controlled;960 original declaration-cache hits execute.','Material bitsets, shader-context state, command buffers, pool/cache nodes, pending registration queue and program reference state compare together:70,767,360 persistent bytes, zero differences.','Present tagged empty override keeps source and suppresses global fallback while other parts still use global replacement; selection order and linked material gates remain native.'],'remainingGaps':[{'id':'shader-factory-device','address':'0x7416a0','status':'Explicit mutable factory only; compiler/device program generation separate.'},{'id':'declaration-cache-miss','address':'0x7418c0','status':'Original cache-hit branch only.'},{'id':'dynamic-remaining-branches','address':'0x5f0f00','status':'Skin/morph, billboard, active fade, sway, shadows and SIMD clipping remain outside this extension.'},{'id':'managed-execution','status':'Core andboth old/new harnesses compile; prepared output comparison pending.'},{'id':'gpu-output','status':'CPU state/packet proof only; GPU interpretation/rendering/performance unclaimed.'}]}
(R/'geometry-dynamic-material-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-dynamic-material-findings.txt').write_text('''Normal submission with material lifecycle

DynamicObjectSubmission.SubmitWithMaterialMerge adds the original5e5020
service point to the stable normal caller. Default Submit delegates withnull
and preserves its previous same-layout domain. MaterialLifecycle supplies
the joined cache/constructor/refresh service. No new native address credit.

360 complete original5f0f00 cases cover120 authored objects across60scenes:
global override, tagged table override and empty tagged entry suppressing
global fallback.600 merge calls include480 real clone constructors/refreshes
and120cache reuses.960 actual declaration-cache lookups execute; only960
shader-factory7416a0 calls are controlled mutable services.393 actual packet
writers run (204ordinary,189prefix).70,767,360 persistent bytes compare with
zero differences, including shader state, pool/cache/program state, pending
queue, visibility bits, matrices and command buffers.

Fixed global shader/scratch/bounds and queue count are mirrored into a compact
image; the established32-byte portable transient stack window is excluded.
No other native helper is skipped. This extends normal CPU behavior but does
not claim shader factory/device creation, skin/morph, billboards, active fade,
sway, shadow submission, SIMD clipping or GPU output.

Core andboth original DynamicSubmissionHarness andnew DynamicMaterialHarness
compile. New replay takes compressedInputFixture/outputFile; checker only
prepares or compares saved output. Original1,568 native fixtures are retained
unchanged. Native/model equality remains distinct from pending managed runs.
''')
print(json.dumps({'nativeMappings':0,'compositionMappings':1,'cases':managed['caseCount'],'managed':managed['status']}))
