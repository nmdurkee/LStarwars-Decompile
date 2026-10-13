"""Prepared integrated sorted/emission fixture; never launches managed code."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args()
native=json.loads((R/'geometry-sorted-shader-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'SINT'+struct.pack('<I',len(cases)))
for c in cases:
 mem=bytes.fromhex(c['before']);buf.extend(struct.pack('<I',len(mem)));buf.extend(mem);buf.extend(struct.pack('<6I',c['head'],c['global'],c['control'],c['descriptor'],c['tokenBase'],len(c['registered'])))
 for p in c['registered']:buf.extend(struct.pack('<I',p))
path=B/'reconstructed/geometry/fixtures/sorted-shader.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data)
report={'schema':'geometry-sorted-shader-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-sorted-shader-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'SortedShaderHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'No compiled-source equivalence until saved managed output is compared.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'SIOU',len(cases)):raise ValueError('Invalid header')
 for i,c in enumerate(cases):
  actual=take('<32s')[0].hex();count=take('<I')[0]
  if count>1000000:raise ValueError('Unbounded trace')
  calls=[]
  for _ in range(count):
   size=take('<I')[0]
   if not 1<=size<=3:raise ValueError('Invalid call entry')
   calls.append(list(take('<'+'I'*size)))
  for field,a,e in [('memorySHA256',actual,c['nativeSHA256']),('calls',calls,c['nativeCalls'])]:
   if a!=e and len(errors)<30:errors.append({'case':i,'field':field,'managed':a,'native':e})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled output compared to original full sorted/emission CPU integration; no GPU execution.')
(R/'geometry-sorted-shader-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))

