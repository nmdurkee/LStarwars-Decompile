"""Separate normal-scheduling source snapshot for root integration."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(p):
 data=(B/p).read_bytes();return {'file':p,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
core='reconstructed/geometry/SceneScheduling.cs';native=json.loads((R/'geometry-scene-scheduling-native-validation.json').read_text());boundary=json.loads((R/'geometry-scheduling-boundaries-native-validation.json').read_text());managed=json.loads((R/'geometry-scene-scheduling-managed-check.json').read_text())
limits='Normal modern display0x4000; prepared camera/frustum,grid/tree/shadow/alternate camera branches excluded. Real portal and static frustum/LOD calls. Dynamic5f0f00 packet generation represented only by recorded selected handle/transform handoff. Native16-volume capacity and finite projection domain retained; compiled execution pending.'
report={'schema':'recovered-geometry-scene-scheduling-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':'0x5f3c80','method':'SceneScheduling.PrepareVisibility','sourceFile':core,'coverage':'bounded-caller-contract-projection','limitations':limits+' Preserves disabled/null-workspace gates,legacy/alternate instance count selection,context clearing and flag mask; normal camera mode0 only.','evidence':'geometry-scene-scheduling-native-validation.json'},{'address':'0x5f5830','method':'SceneScheduling.Run','sourceFile':core,'coverage':'bounded-caller-contract-projection','limitations':limits+' Preserves call order,dirty/global skip,zero-clip behavior,source-order dynamic filtering and0/-1/valid transform-pointer selection.','evidence':'geometry-scene-scheduling-native-validation.json'},{'address':'0x5fd0d0','method':'SceneScheduling.CopyShaderContext','sourceFile':core,'coverage':'bounded-whole-helper-projection','limitations':'Copies105uint values,then clears slots0x5a/0x44/0xd/0x60. Caller-supplied template/output replace original fixed global/object pointers; managed execution pending.','evidence':'geometry-scene-scheduling-native-validation.json'}],'adaptersWithoutNativeEntry':['SchedulingScene/SchedulingOptions/SchedulingState/ScheduledSpecial are typed decoded record/global projections.','DynamicSubmission and diagnostic Calls represent observed original5f0f00 call boundaries,not material packets or GPU draws.'],'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.Scheduling.dll'),'harness':info('reconstructed/geometry/harness/SceneSchedulingHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','coreCommand':'csc /nologo /target:library /out:Recovered.Geometry.Scheduling.dll MaterialUv.cs SceneSubmission.cs Clipping.cs PortalSelection.cs PortalVisibility.cs PortalVolumes.cs PortalTraversal.cs PortalRoomOutputs.cs PortalEntry.cs SceneScheduling.cs ..\\animation\\AnimationPlayback.cs ..\\animation\\CharacterContexts.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.Scheduling.dll /out:SceneSchedulingHarness.exe harness\\SceneSchedulingHarness.cs','workdir':'reconstructed/geometry'},'native':native,'boundary':{'report':'geometry-scheduling-boundaries-native-validation.json','passed':boundary['passed'],'counts':boundary['counts']},'managed':managed,'dependencyCore':['SceneSubmission.cs','Clipping.cs','PortalEntry.cs','PortalTraversal.cs','PortalSelection.cs','PortalVisibility.cs','PortalVolumes.cs','MaterialUv.cs','../animation/AnimationPlayback.cs','../animation/CharacterContexts.cs'],'stateFields':{'GSNH+0x120':'Visibility context return pointer;offset0legacy/alternate instance count','GSNH+0x128':'Optional alternate count owner whose+0x1c is used','GSNH+0x12c/+0x134':'Optional grid/tree owners;excluded active branches','GSNH+0x138/+0x13c':'Portal marker and625-byte visibility-bit pointer,context+0x18/+0x1c','GSNH+0x140/+0x144/+0x148':'Scratch/tree bits/context flags;reset0/0/flags&0xffffffea','DISP+0x74':'Dirty bit4 prevents repeat normal scheduling;bit16 suppresses dynamic iteration;bit15selects static parity','DISP+0x78/+0x80':'Owner GSNH and420-byte shader context target','DISP+0x6c/+0x70':'Dynamic special count and208-byte records','special+0xb8/+0xc0/+0xc4':'Active bit2,bounds index,override transform pointer;0/-1 falls back to special+0x40','globals0x973fcc/0x973fd0/0x9718dc':'Global scheduler skip,dynamic skip,shadow mode','globals0x80b6f4/0x80b6f8/0x80ba14/0x80bab4':'Visibility/grid/tree/dynamic-portal filter enables'},'remainingGaps':[{'id':'grid-tree-producers','addresses':['0x5d6f30','0x5d8fb0'],'status':'excluded active branches'},{'id':'shadow-scheduler','addresses':['0x5f0ac0'],'status':'excluded'},{'id':'dynamic-packet-builder','addresses':['0x5f0f00'],'status':'recorded boundary only'},{'id':'static-finalization','addresses':['0x5f0d70','0x5df880'],'status':'earlier clip-control patcher recovered;alpha item patch and full frame finish remain separate'},{'id':'alternate-camera','addresses':['0x5d6900','0x603cc0'],'status':'mode0 original no-switch branch only;live producer and D3D state changes not ported'}],'additionalLimits':['All integration alpha outputs happen to be1.0; prior independent fade tests cover nontrivial fades,not this batch.','Room mask/query helpers have no direct recognized callers in the exported corpus; normal scheduling consumes instance bits,not per-room output masks.','Finite CPU numerical/state expectations are independently checked against original x86. Generated managed assemblies only compile; none was launched.']}
(R/'geometry-scene-scheduling-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-scene-scheduling-findings.txt').write_text('''Original normal scene scheduling

The recognized normal chain is601df0 ->5f5830 ->5f3c80 ->5eeb30,
followed by5f5380 static LOD/frustum selection and source-order5f0f00 dynamic
handoffs.5f0d70 later consumes display dirty bit4 through5df910/5df880.
The per-room mask/query helpers have no direct recognized calls in the corpus;
scheduling reads the625-byte instance mask atGSNH+13c/context+1c instead.

240 integrated native cases across all60 portal scenes pass,plus480 repeated/
global-skip calls. Source data includes38,202 bounds,38,432 static clip records,
15,960 dynamic special records,403 room definitions and326 portals. The original
chain made47,552 frustum calls,selected34,556 static clips and issued40,970
ordered dynamic handoffs. Static parity/material bits,clip bits,shader context,
context flags,portal results,call order and exact selected transform bytes agree.
All34,556 defined alpha outputs are1.0; nontrivial fades remain covered by the
earlier independent fade suite,not newly established here.

128 synthetic scheduler gate cases and12 direct preparation cases pass. They
cover dirty/global skip,zero static clips,dynamic skip/bit16,inactive specials,
portal filtering/bypass,0/-1/valid matrix pointers,disabled/null workspace and
legacy versus alternate instance-count ownership. Empty static clips do not
set dirty bit4. Repeated dirty calls execute the original empty debug callback;
global skip returns before that callback.

Boundaries are explicit.5f0f00 receives the actual original-selected handle and
matrix,which are recorded before returning0; its packet/material/GPU effects
are outside this batch. Original portal traversal,static visibility,frustum,
LOD and normal scheduling execute unchanged. The external D3DX multiplication
used only while preparing frustum fixtures is a declared scalar adapter. Camera
world/projection data are prepared inputs. Grid/tree/shadow/alternate-camera
branches remain excluded. The original16-volume limit is unchanged; safe cases
were selected from the prior complete-entry suite.

SceneScheduling.cs reconstructs the bounded caller contracts and105-DWORD
shader-context copy helper. Core and SceneSchedulingHarness compile in a
separate assembly without altering the stable geometry map/assembly. The
4,081,901-byte fixture covers240 authored cases plus128+12 boundaries. Checker
tools/geometry-scene-scheduling-check.py prepares or compares saved output only.
Harness arguments are inputFixture/originalSineTable/outputFile. Managed
execution remains pending; no operating-system bypass or GPU claim is made.
Three source mappings,hashes,field offsets and remaining gaps are in the separate
geometry-scene-scheduling-source.json for shared integration.
''')
print(json.dumps({'mappings':len(report['nativeMappings']),'build':report['build']['status'],'managed':managed['status'],'nativePassed':native['passed'],'boundaryPassed':boundary['passed']}))
