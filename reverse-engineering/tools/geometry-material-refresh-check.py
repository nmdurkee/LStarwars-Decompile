"""Prepare CPU refresh replay or compare saved result; never launches."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-material-refresh-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'MRFI'+struct.pack('<I',len(cases)));kinds=['refresh','lookup','release','firstMode','secondMode','defaultRequest','modeRequest']
for c in cases:
 b=bytes.fromhex(c['before']);a=c['args'];buf.extend(struct.pack('<2I',kinds.index(c['kind']),len(b)));buf.extend(b);buf.extend(struct.pack('<I',len(a)));buf.extend(struct.pack('<'+'I'*len(a),*a));buf.extend(struct.pack('<I',c['options']['variant']))
path=B/'reconstructed/geometry/fixtures/material-refresh.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data);report={'schema':'geometry-material-refresh-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-material-refresh-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'MaterialRefreshHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'Managed equality pending; shader factory mutable boundary, cached declaration resolution, zero locks.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'MRFO',len(cases)):raise ValueError('Invalid header')
 for i,c in enumerate(cases):
  digest,ret,count=take('<32s2I')
  if count>1000000:raise ValueError('Unbounded factory count')
  calls=[list(take('<6I'))for _ in range(count)];actual=[digest.hex(),ret if c['nativeReturn']is not None else None,calls];expected=[c['nativeSHA256'],c['nativeReturn'],c['nativeFactory']]
  if actual!=expected and len(errors)<20:errors.append({'case':i,'native':expected,'managed':actual})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved managed CPU material-refresh outputs compared to native fixtures; shader factory/device creation remain explicit.')
(R/'geometry-material-refresh-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
