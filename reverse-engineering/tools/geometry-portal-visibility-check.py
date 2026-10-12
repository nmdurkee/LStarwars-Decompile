"""Compact shared-scene replay of saved original authored visibility bitset hashes."""
import argparse,gzip,json,struct,hashlib,subprocess
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';D=B/'reconstructed/geometry/fixtures';D.mkdir(exist_ok=True)
ap=argparse.ArgumentParser();ap.add_argument('--harness',type=Path);ap.add_argument('--compare',type=Path);ap.add_argument('--module');args=ap.parse_args()
with gzip.open(R/'geometry-portal-visibility-fixtures.json.gz','rt',encoding='utf8')as f:fixtures=json.load(f)
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
buffer=bytearray(b'PVIS'+struct.pack('<I',len(fixtures['sources'])));sourceIds={}
for si,row in enumerate(fixtures['sources']):
 sourceIds[row['source']]=si;entry=index[row['source']]
 if entry['sha256']!=row['sha256']:raise ValueError('Source metadata hash changed')
 data=json.loads((B/entry['report']).read_text());render=json.loads((B/'exports/geometry/scene-runtime'/(row['source']+'.json')).read_text())['renderState'];bounds=data['bounds'];rooms=data['portalData']['rooms']
 buffer.extend(struct.pack('<II',len(bounds),len(rooms)))
 for bound in bounds:buffer.extend(struct.pack('<6f',*bound['center'],*bound['extent']))
 buffer.extend(bytes(i['flags']for i in render['instances']));overrides=bytearray(625)
 for i in render['instances']:
  if i['portalVisibilityOverride']:overrides[i['index']>>3]|=1<<(i['index']&7)
 buffer.extend(overrides)
 for room in rooms:
  ids=room['instanceIndices'];buffer.extend(struct.pack('<I',len(ids)))
  for i in ids:buffer.extend(struct.pack('<h',i))
buffer.extend(struct.pack('<I',len(fixtures['clipSets'])))
for clip in fixtures['clipSets']:
 buffer.extend(struct.pack('<I',len(clip['planes'])))
 for plane in clip['planes']:buffer.extend(struct.pack('<4f',*plane))
 buffer.extend(struct.pack('<4f',*clip['cameraPlane']))
cases=fixtures['cases'];buffer.extend(struct.pack('<I',len(cases)));expected=bytearray()
for c in cases:
 buffer.extend(struct.pack('<IIIB',sourceIds[c['source']],c['room'],c['clipSet'],c['mode']));expected.extend(bytes.fromhex(c['nativeBitsSHA256']))
inputPath=D/'portal-visibility.bin';outputPath=D/'portal-visibility-output.bin';inputPath.write_bytes(buffer)
report={'schema':'portal-visibility-managed-check-v1','nativeEvidence':'geometry-portal-visibility-native-validation.json','fixtureCount':len(cases),'sceneCount':len(fixtures['sources']),'fixtureBytes':len(buffer),'fixtureSHA256':hashlib.sha256(buffer).hexdigest(),'nativeExpectedSHA256':hashlib.sha256(expected).hexdigest(),'status':'prepared-not-executed','scope':'All authored modern-mode propagation fixtures; alternate-mode and initializer tests remain native/Python evidence.','resultClaim':'No compiled-source equivalence claimed until ordinary harness output is compared.'}
try:
 if args.harness:
  result=subprocess.run([str(args.harness.resolve())]+([args.module]if args.module else[])+[str(inputPath),str(outputPath)],capture_output=True,text=True,check=True);report['stdout']=result.stdout;report['stderr']=result.stderr;args.compare=outputPath
 if args.compare:
  actual=args.compare.read_bytes()
  if len(actual)!=8+len(expected)or actual[:4]!=b'PVIO'or struct.unpack_from('<I',actual,4)[0]!=len(cases):raise ValueError('Incorrect compiled output header or length')
  errors=[i for i in range(len(cases))if actual[8+32*i:8+32*(i+1)]!=expected[32*i:32*(i+1)]]
  report.update(status='passed'if not errors else'failed',mismatches=len(errors),examples=[cases[i]for i in errors[:20]],outputSHA256=hashlib.sha256(actual).hexdigest(),resultClaim='Ordinary compiled bitset hashes compared to saved original-PC results.')
except Exception as e:report.update(status='execution-or-comparison-failed',error=str(e))
(R/'geometry-portal-visibility-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
if report['status']in['failed','execution-or-comparison-failed']:raise SystemExit(1)
