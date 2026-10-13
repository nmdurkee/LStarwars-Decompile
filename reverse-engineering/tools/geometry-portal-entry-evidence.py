"""Separate full portal-entry source handoff; existing shared maps remain stable."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def info(p):
 data=(B/p).read_bytes();return {'file':p,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
core='reconstructed/geometry/PortalEntry.cs';native=json.loads((R/'geometry-portal-entry-native-validation.json').read_text());managed=json.loads((R/'geometry-portal-entry-managed-check.json').read_text())
report={'schema':'recovered-geometry-portal-entry-source-v1','namespace':'Recovered.Geometry','coreModules':[info(core)],'nativeMappings':[{'address':'0x5eeb30','method':'PortalEntry.Run','coverage':'bounded-caller-contract-projection','sourceFile':core,'limitations':'Modern display0x4000; finite prepared world/projection/FOV/aspect/near input and safe native selection/16-volume bounds. Original gate order,visibility/root/camera caches,near/eye planes,real child recursion and room flags preserved. Managed allocation replaces native arena; inverse-cache side effect and disabled debug drawing omitted. Live camera producer and GPU excluded; compiled execution pending.','evidence':'geometry-portal-entry-native-validation.json'}],'adaptersWithoutNativeEntry':['PortalEntryCamera and PortalEntryState represent explicit caller/global state; diagnostic Entries is instrumentation.','PortalEntry.Offset/Constant project the x87 sequence inside5eeb30, not separate native functions.'],'dependencies':['reconstructed/geometry/PortalTraversal.cs','reconstructed/geometry/PortalSelection.cs','reconstructed/geometry/PortalRoomOutputs.cs','reconstructed/animation/AnimationPlayback.cs','reconstructed/animation/CharacterContexts.cs'],'coreAssembly':info('reconstructed/geometry/Recovered.Geometry.Entry.dll'),'harness':info('reconstructed/geometry/harness/PortalEntryHarness.cs'),'build':{'status':'passed','compiler':'C:/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe','platform':'default AnyCPU','coreCommand':'csc /nologo /target:library /out:Recovered.Geometry.Entry.dll MaterialUv.cs SceneSubmission.cs Clipping.cs PortalSelection.cs PortalVisibility.cs PortalVolumes.cs PortalTraversal.cs PortalRoomOutputs.cs PortalEntry.cs ..\\animation\\AnimationPlayback.cs ..\\animation\\CharacterContexts.cs','harnessCommand':'csc /nologo /reference:Recovered.Geometry.Entry.dll /out:GeometryEntryHarness.exe harness\\PortalEntryHarness.cs','workdir':'reconstructed/geometry'},'managed':managed,'native':native,'stateFieldMapping':{'VisibilityAttached':'GSNH+0x13c -> global625-byte visibility mask0x280a2f0; Boolean represents pointer attachment','VisibilityBits':'global0x280a2f0..0x280a560','SelectedGlobal':'signed16 global0x971abc','SelectedHeader':'signed32 GSNH+0xe0','Volumes':'GSNH+0x9c pointer list and+0xdc count','RoomFlags':'room record+0x10,bit4 cleared before successful recursion','CameraCopy':'global0x95fb78,16floats copied from0x9736e8','CameraBound':'global0x96e564 -> original camera0x9736e8; Boolean represents active binding','CachedPosition':'global0x971894/98/9c','CameraPlane':'global0x963f78..84','NearPlane':'global0x971860..6c','Path':'global0x963f54,16signed16 ancestor slots'},'limits':native['limits'],'remainingIntegration':['Prepared camera inputs still need an original live producer/update path.','Original inverse-projection cache side effect is not ported.','Debug drawing and GPU submission remain separate.','Full entry coverage uses400 unique selected roots; all403 authored room definitions are loaded and earlier direct traversal covered all403 roots.','All C# modules compile; no generated managed code was launched.']}
(R/'geometry-portal-entry-source.json').write_text(json.dumps(report,indent=2)+'\n')
(R/'geometry-portal-entry-findings.txt').write_text('''Original PC portal entry: 0x5eeb30

The complete unchanged entry routine executes its original CPU chain: visibility
attachment/reset, room selection, camera/plane setup, initial FOV rectangle,
recursive child construction, instance bits, room flags and debug-disabled exit.
Successful results then execute the two original room-output consumers. There
are no return-value adapters or code patches. Hooks record calls and stop an
invalid seventeenth header allocation before any write.

2,797 native entry cases pass with zero numeric/state mismatches: 1,597 success,
240 no room, and 240 each disabled/no portals/no rooms/no bounds. These compare
331,482 child-volume scalars and 19,915 post-entry room query/mask calls. Raw
native float bytes are preserved; 22 signed-zero-only differences are recorded
against the Python model and are not claimed bit-equivalent. All 60 scenes,
403 room definitions and 326 portal definitions are present. Prepared selector
points reach 400 distinct roots. Missing point outcomes are DEATHSTARRESCUE_A
room4 and ENDORBATTLE_A rooms2/3; earlier direct traversal covered these roots.

Three widened-FOV/forced-active cases would allocate a seventeenth header:
DEATHSTARRESCUE_B roots4/8 and CLOUDCITYESCAPE_C root10. They are explicitly
excluded before original execution. Native storage has only 16 pointer slots.
The model is not extended by silently increasing that original capacity.

Gate/state behavior
Attachment always happens first. Disabled portal visibility fills all625 bytes
withFF but returns0. Missing portal,room or bounds counts returns0 preserving
prior visibility,root,clip and camera state. Eligible calls clear625 bytes and
clip count, copy the camera and cache its position before selection. No room
stores root-1 and returns0 while preserving prior room flags and plane caches.
Success constructs near/eye planes, builds the initial room-2 clip, clears room
flag4 and traverses from the selected root. Override selection point affects
room choice, while actual camera position still controls planes/projection.

The near-plane position components storefloat32 after position+normal*near;
the following dot preserves original64-significand x87 intermediates. Native
camera inputs are at9736e8(world),973728(FOV),97372c(aspect),973730(near).
Debug branches execute normally with97398c=0 and80ba5c=-1. Projection inverse
cache updates execute in native replay but remain absent from portable source.

Portable source and remaining limits
PortalEntry.cs, PortalEntryHarness.cs and a separate Recovered.Geometry.Entry.dll
compile successfully without changing the stable geometry assembly or ledger.
The1,425,652-byte fixture has2,797 cases and1,477 deduplicated camera records.
tools/geometry-portal-entry-check.py prepares or compares saved output only; it
does not launch managed code. The harness Main type is PortalEntryHarness,
arguments inputFixture/originalSineTable/outputFile. Compiled C# execution is
pending. No live camera-producer, GPU, game loop or complete game equivalence
is claimed. Source hashes,mapping and explicit fields are in the separate
geometry-portal-entry-source.json for central integration.
''')
print(json.dumps({'mappings':len(report['nativeMappings']),'build':report['build']['status'],'managed':managed['status'],'nativePassed':native['passed']}))
