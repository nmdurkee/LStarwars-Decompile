"""Prepare bounded edge-volume managed fixtures. No execution unless --harness supplied."""
import argparse,gzip,json,struct,hashlib,subprocess
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';D=B/'reconstructed/geometry/fixtures';D.mkdir(exist_ok=True)
ap=argparse.ArgumentParser();ap.add_argument('--harness',type=Path);ap.add_argument('--compare',type=Path);ap.add_argument('--module');args=ap.parse_args()
with gzip.open(R/'geometry-portal-volume-fixtures.json.gz','rt',encoding='utf8')as f:fixtures=json.load(f)
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};portals=[];portalIds={}
for source in fixtures['sources']:
 entry=index[source['source']]
 if entry['sha256']!=source['sha256']:raise ValueError('Source metadata hash changed')
 pd=json.loads((B/entry['report']).read_text())['portalData']
 for pi,p in enumerate(pd['portals']):portalIds[(source['source'],pi)]=len(portals);portals.append(p)
buffer=bytearray(b'PVOL'+struct.pack('<I',len(portals)))
for p in portals:
 buffer.extend(struct.pack('<I4fh',len(p['vertices']),*p['plane'],p['backRoom']))
 for v in p['vertices']:buffer.extend(struct.pack('<3f',*v))
cases=fixtures['cases'];buffer.extend(struct.pack('<I',len(cases)));expected=[];f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
for c in cases:
 pi=portalIds[(c['source'],c['portal'])];p=portals[pi];ci=c['camera']
 camera=fixtures['cameras'][ci]if ci<len(fixtures['cameras'])else [f32(sum(v[k]for v in p['vertices'])/len(p['vertices']))for k in range(3)]if ci==len(fixtures['cameras'])else p['vertices'][0]
 buffer.extend(struct.pack('<I13f',pi,*camera,0.,0.,1.,f32(-camera[2]),*c['nativeProjectedMinMax']));expected.extend(c['nativePlanes']+c['nativePacked'])
inputPath=D/'portal-volumes.bin';outputPath=D/'portal-volumes-output.bin';inputPath.write_bytes(buffer)
report={'schema':'portal-volumes-managed-check-v1','nativeEvidence':'geometry-portal-volume-native-validation.json','fixtureCount':len(cases),'portalCount':len(portals),'expectedScalars':len(expected),'fixtureBytes':len(buffer),'fixtureSHA256':hashlib.sha256(buffer).hexdigest(),'status':'prepared-not-executed','scope':'Original edge-plane and packed-plane numeric results; screen bounds supplied as adapter inputs. Exact finite numerical equality, signed-zero bits ignored.','resultClaim':'No compiled-source equivalence until ordinary output is compared.'}
try:
 if args.harness:
  result=subprocess.run([str(args.harness.resolve())]+([args.module]if args.module else[])+[str(inputPath),str(outputPath)],capture_output=True,text=True,check=True);report['stdout']=result.stdout;report['stderr']=result.stderr;args.compare=outputPath
 if args.compare:
  actual=args.compare.read_bytes()
  if len(actual)!=8+4*len(expected)or actual[:4]!=b'PVLO'or struct.unpack_from('<I',actual,4)[0]!=len(cases):raise ValueError('Incorrect compiled output header or length')
  values=struct.unpack_from('<'+'f'*len(expected),actual,8);errors=[{'scalar':i,'native':e,'managed':a}for i,(a,e)in enumerate(zip(values,expected))if a!=e];zeroSigns=sum(a==e==0 and struct.pack('<f',a)!=struct.pack('<f',e)for a,e in zip(values,expected))
  report.update(status='passed'if not errors else'failed',mismatches=len(errors),examples=errors[:20],signedZeroBitDifferences=zeroSigns,outputSHA256=hashlib.sha256(actual).hexdigest(),resultClaim='Ordinary compiled numeric plane outputs compared to saved original-PC results.')
except Exception as e:report.update(status='execution-or-comparison-failed',error=str(e))
(R/'geometry-portal-volume-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
if report['status']in['failed','execution-or-comparison-failed']:raise SystemExit(1)
