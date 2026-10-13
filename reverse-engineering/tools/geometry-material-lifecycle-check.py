"""Prepare composed material replay or compare saved output; never launches."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-material-lifecycle-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'MLCI'+struct.pack('<I',len(cases)))
for c in cases:
 b=bytes.fromhex(c['before']);o=c['options'];buf.extend(struct.pack('<I',len(b)));buf.extend(b);buf.extend(struct.pack('<2i2I',o['capacity'],o['pending'],o['variant'],o['typeWord']))
path=B/'reconstructed/geometry/fixtures/material-lifecycle.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data);report={'schema':'geometry-material-lifecycle-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-material-lifecycle-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'MaterialLifecycleHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'Managed equality pending; complete bounded clone/pool/refresh composition with shader-factory boundary and cached declaration resolver.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'MLCO',len(cases)):raise ValueError('Invalid header')
 for i,c in enumerate(cases):
  digest,ret,pending,count=take('<32s3I')
  if count>1000000:raise ValueError('Unbounded factory count')
  calls=[list(take('<6I'))for _ in range(count)];dc=take('<I')[0]
  if dc>1000000:raise ValueError('Unbounded declaration count')
  decl=list(take('<'+'I'*dc));actual=[digest.hex(),ret,pending,calls,decl];expected=[c['nativeSHA256'],c['nativeReturn'],c['nativePending'],c['nativeFactory'],c['nativeDeclarations']]
  if actual!=expected and len(errors)<20:errors.append({'case':i,'native':expected,'managed':actual})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved managed clone/pool/refresh composition compared to original fixtures; GPU shader-factory/declaration creation remain explicit.')
(R/'geometry-material-lifecycle-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
