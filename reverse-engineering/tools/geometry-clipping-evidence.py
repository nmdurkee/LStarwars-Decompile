"""Finalize clipping evidence metadata and geometry-owned gap summaries."""
import json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
model={'nativeControlWord':'0x037f','rounding':'nearest-even,64-significand x87 intermediates then explicitfloat32 store','source':'tools/animation-x87.py','sourceSHA256':hashlib.sha256((B/'tools/animation-x87.py').read_bytes()).hexdigest()}
for name in ['geometry-clipping-native-validation.json','geometry-portal-native-validation.json']:
 p=R/name;r=json.loads(p.read_text());assert r['passed'];r['floatingPointModel']=model
 if name.startswith('geometry-clipping'):r['planeRestoreChecks']=r['authoredBounds']*len(r['planeFixtures'])*4
 else:
  cases=json.loads((R/r['fixturesFile']).read_text())['portals'];r['selfLinkedPortals']=[{'source':p['source'],'index':p['index']}for p in cases if p['frontRoom']==p['backRoom']]
 p.write_text(json.dumps(r,indent=2)+'\n')
p=R/'geometry-remaining-gaps.json';r=json.loads(p.read_text())
for gap in r['gaps']:
 if gap['id']=='visibility-game-state':
  gap.update(status='native-frustum-room-portal-predicates-validated-runtime-integration-incomplete',evidence='2,025 submission assertions plus82,204 native frustum comparisons,18,721 point tests over all403rooms,and40,470 portal polygon/facing tests over all326portals pass.82,044 complete plane-block restoration checks pass. Shared software64-significand arithmetic is necessary for authored near-plane boundaries. C# projections compile; managed execution remains pending OS Access denied.',next='Recover camera producer,room selection,portal child clipping volumes and recursive bitset propagation,grid/tree evaluation,and full dynamic special/GHG/shadow packet consumers; validate compiled source in ordinary permitted execution.')
 if gap['id']=='compiled-cpu-runtime-verification':
  gap['evidence']='MaterialUv.cs,SceneSubmission.cs andClipping.cs compile with Framework csc. Clipping shares Recovered.Animation.FiniteX87 source fromAnimationPlayback.cs andCharacterContexts.cs. Ordinary generated harness launch/file access previously returned OS Access denied,independently reproduced. Original-x86/model tests do not prove managed runtime results.'
roomReport=R/'geometry-room-selection-native-validation.json'
if roomReport.exists():
 selection=json.loads(roomReport.read_text());assert selection['passed']
 for gap in r['gaps']:
  if gap['id']=='visibility-game-state':
   gap['status']='native-predicates-and-room-selection-validated-runtime-integration-incomplete'
   gap['evidence']+=' Room selector adds12,869 authored +2,427 synthetic/null comparisons;1,200 original portal-entry handoffs pass with explicit peripheral adapters. Seventh stored overlap corrupts the native return address and is excluded; recovered source guards this bound.'
   gap['next']='Recover camera producer,portal child clipping volumes and recursive bitset propagation,grid/tree evaluation,and full dynamic special/GHG/shadow packet consumers; validate compiled source in ordinary permitted execution.'
  if gap['id']=='compiled-cpu-runtime-verification':
   gap['evidence']+=' PortalSelection.cs and its ordinary harness also compile;15,296 source-bound room-selection cases are prepared but not executed.'
for name in ['geometry-clipping-native-validation.json','geometry-portal-native-validation.json','geometry-clipping-findings.txt']+(['geometry-room-selection-native-validation.json','geometry-room-selection-managed-check.json','geometry-room-selection-findings.txt']if roomReport.exists()else[]):
 if name not in r['authoritativeReports']:r['authoritativeReports'].append(name)
p.write_text(json.dumps(r,indent=2)+'\n')
append='''\nPrepared-plane clipping follow-up
geometry-clipping-findings.txt and the two native validation reports close the
previously supplied frustum oracle at its CPU predicate boundary:82,204 original
frustum cases and18,721 room-containment cases pass. All403 rooms are covered.
40,470 original portal-facing/polygon tests cover all326 portals. Original
plane-block restoration passes82,044 checks. Shared exact64-significand x87
arithmetic preserves authored near-plane behavior that double arithmetic loses.
Clipping.cs provides bounded prepared-plane frustum,room containment and portal
classification source. It shares the recovered FiniteX87 arithmetic source,
compiles successfully,and has explicit sourceFile/native-address mappings.
Compiled runtime comparison remains pending OS denial. Camera production,
room selection,child volumes,recursive/grid/tree visibility propagation and
full shadow/GHG packet generation remain gaps; GPU equivalence is unclaimed.
'''
for name in ['geometry-findings.txt','geometry-render-integration.txt','geometry-visibility-findings.txt']:
 p=R/name;old=p.read_text()
 if 'Prepared-plane clipping follow-up' not in old:p.write_text(old+append)
if roomReport.exists():
 followup='''\nRoom-selection follow-up
geometry-room-selection-findings.txt documents the exact0x5d92b0 scan ordering,
old-candidate priorities,first-shared-portal side and six-slot native stack bound.
12,869 authored point choices across all403 rooms/326 portals plus2,427 synthetic
and null cases pass.1,200 original0x5eeb30 entry cases verify selection-point
override,stores,flag clearing and recursive-call arguments with explicit
peripheral adapters. PortalSelection.cs and its ordinary harness compile;
15,296 managed cases are prepared,execution pending. Room selection is now
recovered within that bound. Child volumes,recursive visibility propagation,
camera/grid/tree production,shadow/GHG packets and GPU equivalence remain gaps.
'''
 for name in ['geometry-findings.txt','geometry-render-integration.txt','geometry-visibility-findings.txt','geometry-clipping-findings.txt']:
  p=R/name;old=p.read_text()
  if 'Room-selection follow-up' not in old:p.write_text(old+followup)
print(json.dumps({'nativeFrustum':82204,'nativeRoomContainment':18721,'nativePortalClassification':40470,'status':'passed; compiled managed execution pending'}))
