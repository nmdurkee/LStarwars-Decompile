"""Prepare ordinary managed room-selection fixtures; execute only if --harness supplied."""
import argparse,json,struct,hashlib,subprocess
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';D=B/'reconstructed/geometry/fixtures';D.mkdir(exist_ok=True)
ap=argparse.ArgumentParser();ap.add_argument('--harness',type=Path);ap.add_argument('--compare',type=Path);ap.add_argument('--module');args=ap.parse_args()
fixtures=json.loads((R/'geometry-room-selection-fixtures.json').read_text());index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
scenes=[];cases=[];expected=[]
for row in fixtures['authored']:
 data=json.loads((B/index[row['source']]['report']).read_text())['portalData'];si=len(scenes);scenes.append(data)
 for point,native in zip(row['points'],row['nativeResults']):cases.append((si,point));expected.append(native)
for fixture in fixtures['synthetic']:
 si=len(scenes);scenes.append(fixture);cases.append((si,fixture['point']));expected.append(fixture['native'])
cases.extend([(-1,[0.,0.,0.]),(0,None),(-1,None)]);expected.extend([-1,-1,-1])
buffer=bytearray(b'RMS1'+struct.pack('<I',len(scenes)))
for scene in scenes:
 rooms=scene['rooms'];portals=scene['portals'];buffer.extend(struct.pack('<2I',len(rooms),len(portals)))
 for room in rooms:
  planes=room['planeEquations'];indices=room['portalIndices'];buffer.extend(struct.pack('<IBBBB',room['flags'],room['priority'],len(planes),len(indices),0))
  for plane in planes:buffer.extend(struct.pack('<4f',*plane))
  for index in indices:buffer.extend(struct.pack('<h',index))
 for portal in portals:buffer.extend(struct.pack('<4f2h',*portal['plane'],portal['frontRoom'],portal['backRoom']))
buffer.extend(struct.pack('<I',len(cases)))
for scene,point in cases:
 buffer.extend(struct.pack('<i?',scene,point is not None))
 if point is not None:buffer.extend(struct.pack('<3f',*point))
inputPath=D/'room-selection.bin';outputPath=D/'room-selection-output.bin';inputPath.write_bytes(buffer)
report={'schema':'room-selection-managed-check-v1','nativeEvidence':'geometry-room-selection-native-validation.json','fixtureCount':len(cases),'sceneCount':len(scenes),'fixtureBytes':len(buffer),'fixtureSHA256':hashlib.sha256(buffer).hexdigest(),'status':'prepared-not-executed','resultClaim':'No compiled-source equivalence claimed until ordinary harness output is compared.','nativeExpectedSHA256':hashlib.sha256(struct.pack('<'+'h'*len(expected),*expected)).hexdigest()}
try:
 if args.harness:
  result=subprocess.run([str(args.harness.resolve())]+([args.module]if args.module else[])+[str(inputPath),str(outputPath)],capture_output=True,text=True,check=True);report['stdout']=result.stdout;report['stderr']=result.stderr;args.compare=outputPath
 if args.compare:
  actual=args.compare.read_bytes()
  if len(actual)!=8+2*len(expected) or actual[:4]!=b'RMSO' or struct.unpack_from('<I',actual,4)[0]!=len(expected):raise ValueError('Wrong compiled fixture output header/length')
  values=struct.unpack_from('<'+'h'*len(expected),actual,8);errors=[{'index':i,'native':e,'managed':a}for i,(e,a)in enumerate(zip(expected,values))if e!=a]
  report.update(status='passed'if not errors else'failed',mismatches=len(errors),examples=errors[:40],outputSHA256=hashlib.sha256(actual).hexdigest(),resultClaim='Ordinary compiled output compared to saved original-PC results.')
except Exception as e:report.update(status='execution-or-comparison-failed',error=str(e))
(R/'geometry-room-selection-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
if report['status']in['failed','execution-or-comparison-failed']:raise SystemExit(1)
