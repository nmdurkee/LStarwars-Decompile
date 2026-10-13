"""Supporting composition manifest, deliberately no new address credit."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(path):
 b=(B/path).read_bytes();return {'file':path,'bytes':len(b),'sha256':hashlib.sha256(b).hexdigest()}
native=json.loads((R/'geometry-material-lifecycle-native-validation.json').read_text());managed=json.loads((R/'geometry-material-lifecycle-managed-check.json').read_text());core='reconstructed/geometry/MaterialLifecycle.cs'
report={'schema':'recovered-geometry-material-lifecycle-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[],'compositionMappings':[{'address':'0x5e5020','method':'MaterialLifecycle.Merge','sourceFile':core,'coverage':'supporting-composition-no-new-address-credit','limitations':'Composes stable MaterialCloneCache,MaterialPool,MaterialRefresh. Successful finite capacities, same-thread cache, zero locks; only shader7416a0 factory remains controlled, declaration resolver uses original cache hits. Managed execution pending.','evidence':'geometry-material-lifecycle-native-validation.json'}],'dependencies':[info('reconstructed/geometry/'+f)for f in['MaterialCloneCache.cs','MaterialPool.cs','MaterialRefresh.cs']],'native':{'report':'geometry-material-lifecycle-native-validation.json','passed':native['passed'],'counts':native['counts'],'sources':len(native['sources']),'binarySHA256':native['binarySHA256'],'limits':native['limits'],'modelDependencies':[info('tools/'+f)for f in['geometry-material-clone-native.py','geometry-material-pool-native.py','geometry-material-refresh-native.py']]},'managed':managed,'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.MaterialLifecycle.dll'),'harness':info('reconstructed/geometry/harness/MaterialLifecycleHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','workdir':'reconstructed/geometry','coreCommand':'csc /nologo /target:library /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.MaterialClone.dll /reference:Recovered.Geometry.MaterialPool.dll /reference:Recovered.Geometry.MaterialRefresh.dll /out:Recovered.Geometry.MaterialLifecycle.dll MaterialLifecycle.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.SortedPackets.dll /reference:Recovered.Geometry.MaterialClone.dll /reference:Recovered.Geometry.MaterialPool.dll /reference:Recovered.Geometry.MaterialRefresh.dll /reference:Recovered.Geometry.MaterialLifecycle.dll /out:MaterialLifecycleHarness.exe harness\\MaterialLifecycleHarness.cs'},'observations':['576 full native misses and480 cache hits preserve all compact-image bytes and original return/pending-queue behavior.480 authored material records come from60scenes.','Original constructor and refresh each execute576times; original declaration lookup1152times. Only1104 shader-factory calls are controlled mutable services.','64 synthetic misses create a clone whose layout is then changed by real601030 refresh, so5e5020 final lookup returns0. The adapter preserves this behavior rather than returning the allocated pointer directly.','Factory callbacks may alias/mutate program results,device modes and texture count. State effects propagate through real original parent routines and composed Python model.'],'remainingGaps':[{'id':'shader-factory-device','address':'0x7416a0','status':'Only remaining controlled factory in this joined chain; compiler/device creation separate.'},{'id':'declaration-cache-miss','address':'0x7418c0','status':'Cache-hit branch only.'},{'id':'dynamic-caller-link','address':'0x5f0f00','status':'Stable DynamicObjectSubmission same-layout domain remains unchanged; lifecycle can next supply its material-merge service.'},{'id':'locks-capacity-invalid','status':'Original lock/error/invalid-pointer branches remain excluded by dependencies.'},{'id':'managed-execution','status':'Core/replay compile; no launch.'}]}
(R/'geometry-material-lifecycle-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-material-lifecycle-findings.txt').write_text('''Joined material lifecycle

MaterialLifecycle.Merge connects the stable cache, pool and CPU refresh
modules with no new native address credit.1,056 original5e5020 chains pass:
576misses and480hits, using480 authored708-byte materials from60scenes.
103,809,024 compact-image bytes, returns, pending counts, factory calls and
declaration requests match the composed Python model exactly.

The original constructor/default initializer/registration queue and refresh
execute576times each. Original declaration-cache lookup executes1,152times.
Only1,104 shader-factory7416a0 calls remain a controlled mutable boundary.
This closes the previously separate constructor and refresh callbacks in
the parent clone chain, without claiming shader compiler/device behavior.

64 synthetic misses intentionally exercise real refresh changing the clone
layout. Original final lookup then returns0; the portable composition keeps
that result. Author material misses all subsequently hit the cache. Program
aliasing, delayed index reads, device-mode and texture mutations flow through
the full parent chain. Same-thread lists, zero locks, finite valid capacities
and images bound the proof; invalid/error paths remain excluded.

Core and Main MaterialLifecycleHarness compile. Replay takes compressedInput
fixture/outputFile; geometry-material-lifecycle-check.py prepares or compares
saved output, never launches. Managed equality and GPU output remain unclaimed.
''')
print(json.dumps({'nativeMappings':0,'compositionMappings':1,'cases':managed['caseCount'],'managed':managed['status']}))
