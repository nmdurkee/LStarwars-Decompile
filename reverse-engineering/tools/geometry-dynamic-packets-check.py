"""Prepare dynamic material dependency fixture or compare saved C# output."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args()
native=json.loads((R/'geometry-dynamic-packets-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'DMAT'+struct.pack('<I',len(cases)))
for c in cases:
 data=bytes.fromhex(c['before']);buf.extend(struct.pack('<III',c['entry'],c['commandCount'],len(c['args'])))
 for a in c['args']:buf.extend(struct.pack('<I',a))
 buf.extend(struct.pack('<I',len(data)));buf.extend(data)
path=B/'reconstructed/geometry/fixtures/dynamic-material-packets.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data)
report={'schema':'geometry-dynamic-packets-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-dynamic-packets-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'DynamicMaterialPacketsHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'No compiled-source equivalence until saved managed output is compared.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'DMOU',len(cases)):raise ValueError('Invalid output header')
 for i,c in enumerate(cases):
  actual=take('<32s')[0].hex();ret=take('<I')[0];count=take('<I')[0]
  if count>7:raise ValueError('Invalid call count')
  calls=list(take('<'+'I'*count))
  for field,a,e in [('memory',actual,c['nativeSHA256']),('calls',calls,c['nativeCalls']),('return',ret,c['nativeReturn']or 0)]:
   if a!=e and len(errors)<30:errors.append({'case':i,'field':field,'managed':a,'native':e})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved managed output compared against original packet/range helper fixture; full dynamic queue remains separate.')
(R/'geometry-dynamic-packets-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))

