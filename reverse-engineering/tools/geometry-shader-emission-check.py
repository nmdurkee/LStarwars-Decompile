"""Prepare CPU shader emission fixture or compare saved managed output."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args()
native=json.loads((R/'geometry-shader-emission-native-validation.json').read_text());assert native['passed']
cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'SEMI'+struct.pack('<I',len(cases)))
for c in cases:
 mem=bytes.fromhex(c['before']);buf.extend(struct.pack('<II',c['entry'],len(mem)));buf.extend(mem);buf.extend(struct.pack('<6I',c['control'],c['shader'],c['record'],c['descriptor'],c['globalToken'],int(c['nativeReturn']is not None)))
path=B/'reconstructed/geometry/fixtures/shader-emission.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data)
report={'schema':'geometry-shader-emission-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-shader-emission-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'ShaderContextEmissionHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'No compiled-source equivalence until saved compiled output is compared.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'SEOU',len(cases)):raise ValueError('Invalid output header')
 for i,c in enumerate(cases):
  actual=take('<32s')[0].hex();ret=take('<I')[0];count=take('<I')[0]
  if count>100:raise ValueError('Invalid trace count')
  calls=list(take('<'+'I'*count))
  for field,a,e in [('memorySHA256',actual,c['nativeSHA256']),('calls',calls,c['nativeCalls']),('return',ret,c['nativeReturn']or 0)]:
   if a!=e and len(errors)<30:errors.append({'case':i,'field':field,'managed':a,'native':e})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled output compared to original shader payload and CPU emission fixtures; GPU command consumption untested.')
(R/'geometry-shader-emission-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))

