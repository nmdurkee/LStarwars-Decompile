"""Prepare compact reset fixture or compare saved managed output; never launches."""
import argparse,json,struct,hashlib,gzip
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args()
native=json.loads((R/'geometry-frame-reset-native-validation.json').read_text());assert native['passed']
fixture=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))
buf=bytearray(b'FRST'+struct.pack('<III',len(fixture['specs']),len(native['sources']),len(fixture['cases'])))
def blob(b):buf.extend(struct.pack('<I',len(b)));buf.extend(b)
for spec in fixture['specs']:
 buf.extend(struct.pack('<IIIII',spec['clipCount'],len(spec['table']),len(spec['records']),len(spec['contexts']),len(spec['recordContexts'])))
 for v in spec['table']:buf.extend(struct.pack('<I',v))
 for r in spec['records']:blob(bytes.fromhex(r))
 for c in spec['contexts']:blob(bytes.fromhex(c))
 for v in spec['recordContexts']:buf.extend(struct.pack('<I',v))
kinds={'reset':0,'contextReset':1,'shaderReset':2,'globalReset':3,'advance':4}
for c in fixture['cases']:
 buf.extend(struct.pack('<B',kinds[c['kind']]))
 if c['kind']=='reset':buf.extend(struct.pack('<IIII',c['spec'],c['flags'],c['force'],c['seed']))
 elif c['kind']=='advance':buf.extend(struct.pack('<II',c['count'],c['pattern']))
 else:buf.extend(struct.pack('<I?',c['seed'],c['alias']))
path=B/'reconstructed/geometry/fixtures/frame-reset.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data)
report={'schema':'geometry-frame-reset-managed-check-v1','nativeEvidence':'geometry-frame-reset-native-validation.json','sourceCount':len(native['sources']),'caseCount':len(fixture['cases']),'fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'FrameResetHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'No compiled-source equivalence until saved managed output is compared.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'FROU',len(fixture['cases'])):raise ValueError('Invalid output header')
 for i,c in enumerate(fixture['cases']):
  actual=take('<32s')[0].hex();count=take('<I')[0]
  if count>1000000:raise ValueError('Invalid call count')
  calls=list(take('<'+'I'*count))
  if actual!=c['nativeSHA256']and len(errors)<30:errors.append({'case':i,'field':'stateSHA256','native':c['nativeSHA256'],'managed':actual})
  expected=c.get('nativeCalls',[])
  if calls!=expected and len(errors)<30:errors.append({'case':i,'field':'calls','native':expected,'managed':calls})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled output compared against exact original frame-reset state and call sequence fixtures.')
(R/'geometry-frame-reset-managed-check.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report))

