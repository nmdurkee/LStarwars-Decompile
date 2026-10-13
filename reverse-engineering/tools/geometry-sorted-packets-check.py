"""Prepare sorted packet fixture or compare saved managed output; no launch."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args()
native=json.loads((R/'geometry-sorted-packets-native-validation.json').read_text());assert native['passed']
cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'SPKT'+struct.pack('<I',len(cases)))
for c in cases:
 mem=bytes.fromhex(c['before']);buf.extend(struct.pack('<BI',0 if c['kind']=='complete'else 1,len(mem)));buf.extend(mem)
 if c['kind']=='complete':
  buf.extend(struct.pack('<III',c['head'],c['global'],len(c['registered'])))
  for p in c['registered']:buf.extend(struct.pack('<I',p))
 else:buf.extend(struct.pack('<IIII',c['control'],c['record'],c['type'],c['payload']))
path=B/'reconstructed/geometry/fixtures/sorted-packets.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data)
report={'schema':'geometry-sorted-packets-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-sorted-packets-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'SortedPacketsHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'No compiled-source equivalence until saved compiled output is compared.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  n=struct.calcsize(fmt)
  if offset+n>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=n;return v
 if take('<4sI')!=(b'SPOU',len(cases)):raise ValueError('Invalid output header')
 for i,c in enumerate(cases):
  actual=take('<32s')[0].hex();ret=take('<I')[0];count=take('<I')[0]
  if count>1000000:raise ValueError('Unbounded trace')
  calls=[]
  for _ in range(count):
   nc=take('<I')[0]
   if not 1<=nc<=3:raise ValueError('Invalid call record')
   calls.append(list(take('<'+'I'*nc)))
  for field,a,e in [('memorySHA256',actual,c['nativeSHA256']),('calls',calls,c['nativeCalls']),('appendReturn',ret,c.get('nativeReturn',0))]:
   if a!=e and len(errors)<30:errors.append({'case':i,'field':field,'managed':a,'native':e})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled output compared to original bounded packet completion/append state. Changed shader emission remains excluded.')
(R/'geometry-sorted-packets-managed-check.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report))

