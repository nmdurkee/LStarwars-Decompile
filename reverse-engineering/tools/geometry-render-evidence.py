"""Assemble the evidence-backed PC frame/render integration map, without guessing a full engine."""
import json,hashlib,re
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';C=B/'decompiled/corpus-expanded'
def file_record(path):
 p=B/path;data=p.read_bytes();return {'file':path,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()}
def artifact_record(path):
 try:return file_record(path)
 except PermissionError as e:return {'file':path,'readStatus':'OS access denied','error':str(e),'sha256':None}
roles={
 '492b40':'Outer area/frame loop; conditionally calls update and render production, later replaces/caps world delta.',
 '491d50':'World update; calls scene animation on world+0x13c with worldDelta*60. Not the display-list consumer.',
 '4927f0':'Conditional game render-production path; invokes many effect/UI callbacks and finalizes several view contexts.',
 '4fd050':'Platform frame completion/pump; advances UV/ATS using previous platform delta, submits frame, then measures next delta.',
 '601330':'UV wrapper: speed-scaled primary advance, then unscaled secondary clock/reset.',
 '5dfbd0':'Membership-ordered UV evaluator, already exhaustively checked for authored configurations.',
 '6012a0':'Secondary UV time accumulation and one-shot eligible-scene offset reset.',
 '5d34a0':'Texture animation script scheduler called with previous platform delta; evaluator contracts separately verified.',
 '5ddc80':'Optional state/parameter time update invoked with previous platform delta.',
 '60b5b0':'Invokes optional caller callback, then frame renderer 60aff0.',
 '60aff0':'Consumes pending 536-byte view contexts, establishes pass state, plays buckets, recycles lists, presents.',
 '5f3950':'Finalizes current display bucket and snapshots 536-byte view context; optional nested capture.',
 '5f39e0':'Second entry with same observed finalization/copy contract.',
 '5efff0':'Collects eligible sorted scene-list nodes and dynamic tail into a submission bucket, returns bucket ID or -1.',
 '5f0d70':'Prepares dynamic/material lists and snapshots 24 producer bucket pointers into consumer slots.',
 '5e0bd0':'Patches per-material display-item control bytes based on current/previous enable bitsets.',
 '5f02e0':'Plays each scene stream in a prepared bucket, then its inline tail stream.',
 '6033d0':'Invokes generic display interpreter with selected callback table.',
 '6033f0':'Alternative direct scene playback: walks scene+0x60 records at scene+0x64, stride36, stream+4.',
 '5e0f90':'16-byte display-item interpreter; byte1 controls advance/jump/callback/return.',
 '603aa0':'Selects callback table 0 or 1; unsupported selectors assert.',
 '608000':'Primary material callback: selects shader via material+0x1f4, binds uniforms/state/declaration, handles special shader paths.',
 '6083d0':'Secondary material callback: selects shader via material+0x1f6 and uses a reduced state path.',
 '607880':'Mesh callback: validates current shader and vertex count, binds streams/indices, issues topology-specific draw.',
 '5fd6b0':'Primary matrix callback: alpha/fog metadata handling, normalized world-matrix upload, restores source slots.',
 '5fd9f0':'Billboard mesh callback: stream0 stride32 then nonindexed triangle-list draw.',
 '5fda20':'Billboard transform callback; previously validated center/view/magnitude shader constant uploads.',
 '742730':'Original material uniform binder; prior full current-layout contract validation.',
 '741620':'Shader lookup from signed material shader index.',
 '741640':'Shader binding state setter.',
 '601360':'Material render-state setup (separate from feature emission and uniform binding).',
 '6e48e0':'Forwards six indexed-draw arguments through device vtable+0x148 and increments draw counter.',
 '6e49b0':'Forwards four user-memory-draw arguments through device vtable+0x14c and resets stream cache.',
 '5dfab0':'Flips frame/list bit0x8000, resets registered scene list state, clears queue counters/used flags.',
 '5ddd10':'Resets per-scene active material/instance bits and per-material list-buffer selection.',
 '5fd450':'Flips a two-buffer transient allocation arena; records high-water usage and checks capacity.',
 '6dfd40':'Calls device-present wrapper and subsequent platform helper.',
 '6e41a0':'Calls device vtable+0x44 with four arguments; handles HRESULT failure/lost-device path.',
 '6dd390':'Windows message pump, returns0 for WM_QUIT.',
 '6d3420':'Empty function in this PC build; not a presentation implementation.'
}
roles.update({
 '55f650':'World-scene draw bridge: world+0x13c GSNH, fallback legacy path, then601df0.',
 '57d0a0':'Conditional secondary world-scene rendering call through601df0.',
 '601df0':'Assembly-confirmed adapter: replace stack argument with[GSNH+0x110], tail-jump5f5830. Pseudocode omits this dereference.',
 '5f5830':'Scene submission orchestrator: visibility evaluation, normal/shadow branch, clipped flag and eligible special-object dispatch.',
 '5f5380':'Normal scene visibility: tree/portal gating, squared-distance LOD, far limit, fade, material/clip bit writes.',
 '5f0ac0':'Shadow visibility path; static anchor only, not independently replayed here.',
 '5f0f00':'Special-object submission with LOD/material variants and dynamic per-material list generation; static anchor.',
 '5e0530':'Dynamic geometry/display packet generation endpoint used by special submission; static anchor.',
 '5df7b0':'Distance fade with original rounded sqrt, forward/reverse ranges and observed degenerate NaN behavior.',
 '603ad0':'Clamps alpha into preceding transform packet+0x3c, preserving NaN and signed zero.',
 '5df910':'Patches paired geometry/transform item controls from changed32-bit clip-state words.',
 '5df880':'Applies per-clip alpha to enabled opcode82 mesh items via603ad0.',
 '5ded80':'Registers display scene, inserts biased sort records, prepends UV set, resets scene flags/alpha scratch.',
 '5de060':'Signed ascending linked-list insertion; equal keys insert before existing entries.',
 '5dee40':'Unregisters scene, removes sort records/UV set and compacts registry.'
})
roles.update({
 '5f3c80':'Visibility context producer: clears flags/scratch, optional grid visibility, portal or tree evaluation.',
 '5d69a0':'Native prepared-plane AABB predicate; returns0 outside,1 accepted,2 side clip required; far override restored.',
 '5d5500':'Produces outer/scissor/near/far planes from camera globals; external D3DX product separately adapted in fixtures.',
 '5d9220':'Room containment: outward plane dot(point)+constant <=0 for every plane; zero planes accepts.',
 '5d9ce0':'Portal priority-dependent facing gate, then vertex/clip-plane classification0/1/2 with x87 float32 stores.',
 '5d92b0':'Native-verified bounded room selection: first candidates, exact old-priority ordering and first shared portal side.',
 '5eeb30':'Portal entry with verified selection/gating/camera-copy/room-flag/handoff; child volume and recursive propagation adapted.',
 '5ee940':'Recursive portal traversal with depth/cycle guards and room marking; end-to-end propagation remains unverified.',
 '5d6f30':'Grid visibility producer: camera XZ cell and RLE bitset selection; static observation only.',
 '5d8fb0':'Visibility tree evaluator entry selected when portal path disabled; static observation only.'
})
edges=[
 ('492b40','491d50','conditional world update'),('492b40','4927f0','conditional render-production branch'),('492b40','4fd050','platform completion returns next delta'),
 ('4927f0','5f3950','two observed direct calls'),('4927f0','5f39e0','final context call'),
 ('5f3950','5efff0','returns current bucket ID'),('5f39e0','5efff0','returns current bucket ID'),
 ('4fd050','601330','previous platform delta'),('4fd050','5d34a0','previous platform delta'),('4fd050','5ddc80','previous platform delta'),('4fd050','60b5b0','frame submission'),
 ('601330','5dfbd0','delta multiplied by float at0x80bac4'),('601330','6012a0','original unscaled delta'),
 ('60b5b0','60aff0','after optional callback'),('60aff0','5f0d70','prepare/snapshot queues'),('60aff0','5fd450','flip transient arena'),
 ('60aff0','5f02e0','once per context whose bucket ID is not -1'),('60aff0','5dfab0','recycle frame display-list state'),('60aff0','6dfd40','final presentation path'),
 ('5f0d70','5e0bd0','patch global and dirty registered scene material lists'),
 ('5f02e0','6033d0','prepared scene-list streams then inline tail'),('6033d0','5e0f90','selected table at0x80e794'),('6033f0','5e0f90','direct scene sort-record streams'),
 ('608000','741620','material signed16+0x1f4'),('6083d0','741620','material signed16+0x1f6'),
 ('608000','742730','uniforms before binding eligible shader'),('608000','741640','bind selected shader or dedicated path'),('608000','601360','material state'),
 ('607880','6e48e0','kind6 indexed triangle strip'),('607880','6e49b0','kinds12/13/14/15/17/18 immediate topology'),
 ('5dfab0','5ddd10','global and registered-scene list reset'),('6dfd40','6e41a0','four null presentation arguments')
]
edges.extend([
 ('4927f0','55f650','world scene rendering'),('4927f0','57d0a0','conditional later scene pass'),('55f650','601df0','world+0x13c'),('57d0a0','601df0','world+0x13c under extra-pass condition'),
 ('601df0','5f5830','assembly-confirmed GSNH+0x110 tail adapter'),('5f5830','5f5380','normal path when current capture object is null'),('5f5830','5f0ac0','shadow path when current capture object is nonnull'),('5f5830','5f0f00','visible named specials after portal/suppression gates'),
 ('5f5380','5df7b0','distance-fade flag0x40'),('5f0f00','5df7b0','special instance distance fade'),('5f0f00','5e0530','dynamic per-material geometry packet production'),
 ('5f0d70','5df910','dirty scene clip control patch'),('5f0d70','5df880','dirty scene alpha patch'),('5df880','603ad0','enabled opcode82 items'),('5ded80','5de060','each36-byte sort record after signed priority bias')
])
edges.extend([
 ('5f5830','5f3c80','owning GSNH visibility context before normal/shadow submission'),
 ('5f5380','5d69a0','per-bound center,extent and distance-fade far override'),
 ('5f3c80','5d6f30','enabled authored grid'),('5f3c80','5eeb30','enabled portal data'),('5f3c80','5d8fb0','tree fallback'),
 ('5eeb30','5d92b0','camera room selection'),('5eeb30','5ee940','initial portal traversal'),
 ('5d92b0','5d9220','room plane containment'),('5ee940','5d9ce0','active portal facing/clip classification'),('5ee940','5ee940','recursive eligible-room traversal')
])
nodes=[]
for address,role in roles.items():
 path='decompiled/corpus-expanded/FUN_'+address+'.c';f=file_record(path);source=(B/path).read_text();ev=re.search(r'ev_[a-f0-9]+',source)
 nodes.append({'address':'0x'+address,'label':'FUN_'+address,'role':role,'roleStatus':'reconstructed-description-from-original-PC','evidenceId':ev.group(0) if ev else None,**f})
fields=[
 ('global','0x297dbfc','float32 previous platform delta used by UV/ATS before replacement in4fd050'),
 ('global','0x925018','float32 world delta replaced from4fd050 result then capped separately'),
 ('global','0x925054','world delta cap, conditional on0x951be0==0'),
 ('global','0x9718a0','current536-byte view context; +0 bucket ID'),
 ('global','0x9640f0','queued536-byte context array; count0x95fbb8'),
 ('view-context','+0x08','clear flag word ORed by5ebd80 and consumed by60aff0'),
 ('view-context','+0x0c','clear color word'),('view-context','+0x10','clear depth float'),
 ('view-context','+0x38','nested capture enable'),('view-context','+0x3c','nested capture object pointer'),('view-context','+0x40','nested capture ordinal'),
 ('global','0x973ed4','24 producer bucket pointers'),('global','0x973f34','24 consumer bucket pointers'),
 ('global','0x973ed0','next producer bucket index; reset by5dfab0'),
 ('global','0x973ecc','head of sorted36-byte scene-list records; +8 next'),('global','0x973ec8','scene-list record count'),
 ('bucket','+0x00','scene stream count'),('bucket','+0x04','pointer array of36-byte sort records'),('bucket','+0x08','inline16-byte tail display item'),
 ('sort-record','+0x00','signed sort key'),('sort-record','+0x04','display stream pointer'),('sort-record','+0x08','next sorted node'),
 ('sort-record','+0x14','used flag bit1'),('sort-record','+0x1c','owning display scene pointer'),('sort-record','+0x20','u16 material count'),('sort-record','+0x22','u16 material base index'),
 ('display-scene','+0x4c','material count'),('display-scene','+0x50','material pointer array'),('display-scene','+0x54','per-material runtime display-list pointers'),
 ('display-scene','+0x58/+0x5c','two material-enable bitsets'),('display-scene','+0x60','sort-record count'),('display-scene','+0x64','sort-record array'),
 ('display-scene','+0x74','dirty/mode flags; bit15 list-buffer parity'),('display-scene','+0x78','owning GSNH header'),
 ('display-item','+0x00','opcode; callback table index opcode-0x80'),('display-item','+0x01','control:0 advance,1 jump,3 callback+advance,4 return'),('display-item','+0x04','relocated pointer used as jump target or callback argument'),
 ('global','0x80e794','selected callback table pointer'),('global','0x2854c20','current material pointer shared by material/mesh/matrix callbacks'),
 ('material','+0x1f4/+0x1f6','signed16 primary/secondary shader indices'),('material','+0x2bc','vertex declaration handle'),
 ('mesh','+0x00','primitive kind'),('mesh','+0x04','indexed primitive count for kind6'),('mesh','+0x08','u16 stride'),('mesh','+0x14','base vertex index'),
 ('mesh','+0x18','vertex count'),('mesh','+0x1c','start index'),('mesh','+0x20','index buffer handle'),('mesh','+0x24','static vertex buffer handle'),
 ('mesh','+0x28/+0x30/+0x34','deformer count / dynamic vertex buffer / dynamic vertex data'),
 ('matrix-packet','+0x2c/+0x3c','extra metadata uploaded separately; temporarily0/1 for normalized world-matrix upload')
]
fields.extend([
 ('global','0x963fa0/0x963fe0','prepared outer/scissor clip-plane matrices'),
 ('global','0x964020','far/near signed plane columns0/1 and absolute normals columns2/3'),
 ('global','0x964070/0x9640b0','absolute outer/scissor plane matrices'),
 ('global','0x973734','camera far limit used by temporary per-bound far override'),
 ('GSNH','+0x120','visibility context returned to display-scene submission'),
 ('GSNH','+0x140/+0x144/+0x148','visibility scratch pointers and gate flags'),
 ('GSNH','+0x74/+0x78','room count and24-byte room array'),
 ('room','+0x04/+0x0e','outward plane pointer and unsigned-byte plane count'),
 ('room','+0x08/+0x0f','signed16 portal-index list and unsigned-byte length'),
 ('room','+0x10/+0x14','runtime flags and priority byte'),
 ('portal','+0x00/+0x10/+0x14','plane equation / vertex pointer / signed16 vertex count'),
 ('portal','+0x16/+0x18/+0x1c','front/back room IDs and active flags'),
 ('portal-clip-context','+0x80/+0x9c','clip-plane pointer and signed16 count'),
 ('global','0x971894/0x971898/0x97189c','cached camera position used by portal facing')
])
validation=json.loads((R/'geometry-render-native-validation.json').read_text())
report={'schema':'pc-frame-render-integration-v1','binarySHA256':validation['binarySHA256'],'nodes':nodes,
 'directEdges':[{'from':'0x'+a,'to':'0x'+b,'meaning':m,'evidence':'decompiled/corpus-expanded/FUN_'+a+'.c'}for a,b,m in edges],
 'callbackTables':validation['callbackTables'],'fields':[{'owner':a,'offsetOrAddress':b,'meaning':c}for a,b,c in fields],
 'originalInstructionValidation':{'report':'geometry-render-native-validation.json','tests':validation['tests'],'meshCases':validation['meshSubmissionCases'],'matrixCases':validation['matrixSubmissionCases'],'passed':validation['passed']},
 'observations':[
  '4fd050 advances UV and ATS with the previous platform delta before computing the next platform delta; world delta is separately capped in492b40.',
  'Display-item opcode does not independently determine control flow: byte1 does. Native producers write opcode0x84 with control4 as terminator and0x8d/control1 as link.',
  'Primary table has material608000, mesh607880 for opcodes82/8b/98, matrix5fd6b0, billboard5fd9f0 and billboard transform5fda20. Secondary table changes or suppresses callbacks.',
  '5f02e0 preserves prepared bucket pointer order and always plays inline tail after scene streams.',
  'Kind6 packet+4 is submitted as primitive count, not raw index count; baseVertex+14, vertexCount+18 and startIndex+1c are passed directly.',
  'Primary matrix callback temporarily writes slots+2c=0 and+3c=1 for semantic0x11 then restores the source; extra slots can carry rendering metadata.',
  '5dece0/5ded40 are optional HTML display-list logging hooks;5decd0 and6d3420 are empty in this build.'
 ],'inferences':[
  'Device slot+0x148 with six draw arguments matches IDirect3DDevice9::DrawIndexedPrimitive; +0x14c with four arguments matches DrawPrimitiveUP.',
  'Device slot+0x44 with four null arguments and HRESULT lost-device handling matches IDirect3DDevice9::Present.',
  'Primary/secondary table labels describe observed selection only; exact gameplay pass names are not assigned here.'
 ],'primaryApiReferences':[
  'https://learn.microsoft.com/en-us/windows/win32/api/d3d9/nf-d3d9-idirect3ddevice9-drawindexedprimitive',
  'https://learn.microsoft.com/en-us/windows/win32/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitiveup',
  'https://learn.microsoft.com/en-us/windows/win32/api/d3d9/nf-d3d9-idirect3ddevice9-present'
 ],'unknowns':[
  'World-scene and named-special submission edges are now traced and dispatch tested, but GHG-layer/dynamic-packet generation is not reconstructed end to end.',
  'Native geometric frustum, room containment/selection and portal facing/clip predicates are verified separately. Camera system, portal child-volume construction/traversal, visibility-bit production, shadow extrusion and synchronization remain incomplete.',
  'No original GPU pixel comparison, shader execution or full-frame device emulation; CPU helper tests are not a working renderer.',
  'Dynamic morph-buffer upload branch remains a static observation in this report.',
  'Original requests for UV resets and changes to speed scale remain separate runtime-owner work.'
 ]}
visibility=json.loads((R/'geometry-visibility-native-validation.json').read_text())
report['visibilityValidation']={k:visibility[k]for k in ['assertions','visibilityCases','clipPatchCases','registrationCases','fadeHelperCases','alphaClampCases','specialDispatchCases','passed']}
report['visibilityValidation']['report']='geometry-visibility-native-validation.json'
clipping=json.loads((R/'geometry-clipping-native-validation.json').read_text())
report['clippingValidation']={k:clipping[k]for k in ['passed','counts','authoredBounds','authoredRooms','planeRestoreFailures']}
report['clippingValidation']['report']='geometry-clipping-native-validation.json'
portal=json.loads((R/'geometry-portal-native-validation.json').read_text())
report['portalPredicateValidation']={k:portal[k]for k in ['passed','tests','authoredPortals','classificationCounts']}
report['portalPredicateValidation']['report']='geometry-portal-native-validation.json'
roomSelection=json.loads((R/'geometry-room-selection-native-validation.json').read_text())
report['roomSelectionValidation']={k:roomSelection[k]for k in ['passed','counts','sourceCounts']}
report['roomSelectionValidation']['report']='geometry-room-selection-native-validation.json'
(R/'geometry-render-integration.json').write_text(json.dumps(report,indent=2)+'\n')
sourceStatus={'schema':'recovered-geometry-source-status-v1','namespace':'Recovered.Geometry','core':file_record('reconstructed/geometry/MaterialUv.cs'),'harness':file_record('reconstructed/geometry/harness/Program.cs'),'coreAssembly':artifact_record('reconstructed/geometry/Recovered.Geometry.dll'),'harnessAssembly':artifact_record('reconstructed/geometry/GeometryUvHarness.exe'),'build':{'status':'passed','compiler':r'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe','platform':'compiler default AnyCPU','dependencies':'System/System.Core framework only; no Unity or original game linking'},'compiledDifferentialCheck':{'status':'blocked-os-access-denied','log':'geometry-recovered-uv-validation.log','reason':'Ordinary generated harness launch returns WinError5. Reproduced by root using central combined-library build. No security or ACL modifications; no alternate host execution.','resultClaim':'pending; existing JS/Python native results do not establish compiled C# equivalence','runner':'tools/geometry-recovered-uv-check.py','optionalArguments':['--harness','--assembly']},'independentContractEvidence':'geometry-uv-native-validation.json','frameIntegrationEvidence':'geometry-render-integration.json','limits':['Core covers bounded current708-byte material UV evaluation and reset state only.','Signed32 conversion domain only; nonfinite/overflow conversions rejected.','No renderer, scene scheduler, game loop, or Unity implementation.']}
sourceStatus['additionalCore']=file_record('reconstructed/geometry/SceneSubmission.cs')
sourceStatus['coreModules']=[file_record('reconstructed/geometry/'+name)for name in ['MaterialUv.cs','SceneSubmission.cs','Clipping.cs','PortalSelection.cs']]
sourceStatus['sharedSourceDependency']=file_record('reconstructed/animation/AnimationPlayback.cs')
sourceStatus['sharedSourceDependency']['api']='Recovered.Animation.FiniteX87.Dot3PlusConstant; exact64-significand finite arithmetic, not a game-native function.'
sourceStatus['additionalContractEvidence']='geometry-visibility-native-validation.json'
sourceStatus['clippingContractEvidence']=['geometry-clipping-native-validation.json','geometry-portal-native-validation.json','geometry-room-selection-native-validation.json']
sourceStatus['roomSelectionHarness']=file_record('reconstructed/geometry/harness/PortalSelectionHarness.cs')
sourceStatus['roomSelectionManagedCheck']={'runner':'tools/geometry-room-selection-check.py','report':'geometry-room-selection-managed-check.json','status':'prepared-not-executed','fixtureCount':15296,'harness':'reconstructed/geometry/GeometryRoomHarness.exe','build':'passed','execution':'not attempted; existing Windows execution denial remains separate'}
sourceStatus['limits'][0]='Core covers current708-byte material UV evaluation/reset, bounded CPU visibility/LOD/fade/clip-control/sort projections, prepared-plane frustum/room/portal predicates and bounded room selection. Caller supplies camera planes, portal/tree bitsets and runtime integration.'
sourceStatus['nativeMappings']=[
 {'address':'0x5dfbd0','method':'MaterialUv.Advance','coverage':'bounded-whole-helper-projection','limitations':'Managed memberships replace pointer chain; mutex excluded; finite signed32 conversion domain.'},
 {'address':'0x601330','method':'MaterialUv.Tick','coverage':'whole-wrapper-contract','limitations':'Caller-owned state replaces globals; includes recovered6012a0 tail.'},
 {'address':'0x6012a0','method':'MaterialUv.Tick reset/time tail','coverage':'bounded-whole-helper-projection','limitations':'Managed registered scenes replace global pointer array.'},
 {'address':'0x5f5380','method':'SceneSubmission.EvaluateVisibility / SelectLod','coverage':'bounded-helper-projection','limitations':'Transient allocator replaced by managed alpha array; frustum supplied by caller; optional debug occlusion excluded; finite input domain. Does not implement scene visibility evaluation.'},
 {'address':'0x5df7b0','method':'SceneSubmission.DistanceFade','coverage':'bounded-whole-helper-projection','limitations':'Finite nonnegative distance input domain; host sqrt roundedfloat32; original degenerate output NaN retained; compiled CLR equivalence pending.'},
 {'address':'0x5df910','method':'SceneSubmission.PatchClipControls','coverage':'whole-helper-contract-projection','limitations':'Decoded clip indices and managed item byte array replace pointers; bounds checks added.'},
 {'address':'0x5de060','method':'SceneSubmission.InsertSortRecord','coverage':'whole-helper-contract-projection','limitations':'Managed ordered collection replaces linked list/counter; tie order retained.'},
 {'address':'0x5ded80','method':'SceneSubmission.ApplyPriorityBias','coverage':'small-extracted-branch','limitations':'Only wrapped key bias arithmetic; registration helper is not reconstructed in C#.'},
 {'address':'0x603ad0','method':'SceneSubmission.ClampInstanceAlpha','coverage':'extracted-pure-result','limitations':'Exact clamp result; pointer dereference/store moved to caller.'}
]
sourceStatus['nativeMappings'].extend([
 {'address':'0x5d69a0','method':'NativeFrustum.Classify','coverage':'bounded-whole-helper-projection','limitations':'Prepared native plane block replaces globals; far override local instead of temporary global store; finite inputs, nonnegative extents. Shared software x87, compiled execution pending.'},
 {'address':'0x5d9220','method':'PortalPredicates.ContainsPoint','coverage':'bounded-whole-helper-projection','limitations':'Managed finite plane list/point replace room pointers; maximum255planes; shared software x87, compiled execution pending.'},
 {'address':'0x5d9ce0','method':'PortalPredicates.ClassifyPortal','coverage':'bounded-helper-projection','limitations':'Uses recovered recursive caller contract: current room is endpoint, target is other endpoint. Managed finite vertex/plane/priority arrays; count signed16; active bit belongs to caller. Compiled execution pending.'}
])
sourceStatus['nativeMappings'].append({'address':'0x5d92b0','method':'PortalSelection.SelectRoom','coverage':'bounded-whole-helper-projection','limitations':'Managed finite room/link arrays replace pointers; preserves native old-candidate priority/flag ordering and first-shared-portal side. At most six stored overlaps: seventh native store corrupts return address, so managed code throws. Empty debug hook has no effect; compiled execution pending.'})
for mapping in sourceStatus['nativeMappings']:
 mapping['sourceFile']='reconstructed/geometry/'+('MaterialUv.cs'if mapping['method'].startswith('MaterialUv.')else 'SceneSubmission.cs'if mapping['method'].startswith('SceneSubmission.')else 'PortalSelection.cs'if mapping['method'].startswith('PortalSelection.')else 'Clipping.cs')
sourceStatus['adaptersWithoutNativeEntry']=['UvMaterial.DecodeCurrentRecord','NativeSineTable.DecodeLittleEndian','UvLayer/UvMaterial/UvScene/UvAnimationSet/UvClock','Point3/ClipBounds/ClipObject/SceneVisibility/VisibilityInputs/SortRecord','MaterialUv.EvaluateAxis is an extracted internal branch of5dfbd0, not a separate entry.','TruncateToNativeInt32 is a bounded integer-conversion adapter, not full6e6b90 reconstruction.']
sourceStatus['adaptersWithoutNativeEntry'].extend(['NativeFrustum.DecodeNativePlaneBlock','PortalPlane','Shared Recovered.Animation.FiniteX87 arithmetic is an instruction-semantics adapter, not a native entry.'])
sourceStatus['adaptersWithoutNativeEntry'].extend(['PortalRoom','PortalLink','PortalSelectionHarness is fixture I/O, not a native runtime helper.'])
(R/'geometry-recovered-source.json').write_text(json.dumps(sourceStatus,indent=2)+'\n')
print(json.dumps({'nodes':len(nodes),'directEdges':len(edges),'fields':len(fields),'nativeTests':validation['tests'],'compiledCore':'build passed; execution blocked'}))
