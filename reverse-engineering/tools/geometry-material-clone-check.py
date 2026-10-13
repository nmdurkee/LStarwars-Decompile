"""Prepare clone replay or compare a saved result; never launches."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-material-clone-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'MCCI'+struct.pack('<I',len(cases)));kinds=['next','node','find','ensure','merge']
for c in cases:
 b=bytes.fromhex(c['before']);o=c['options'];a=c['args'];buf.extend(struct.pack('<2I',kinds.index(c['kind']),len(b)));buf.extend(b);buf.extend(struct.pack('<I',len(a)));buf.extend(struct.pack('<'+'I'*len(a),*a));buf.extend(struct.pack('<4I',o['thread'],o['typeWord'],o['refreshXor'],o['counter']))
path=B/'reconstructed/geometry/fixtures/material-clone-cache.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data);report={'schema':'geometry-material-clone-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-material-clone-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'MaterialCloneCacheHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'Managed equality pending; material constructor/shader refresh are explicit services, declaration resolution uses a controlled cached lookup result.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'MCCO',len(cases)):raise ValueError('Invalid header')
 for i,c in enumerate(cases):
  digest,ret,count=take('<32s2I')
  if count>1000000:raise ValueError('Unbounded output')
  calls=[]
  for j in range(count):
   size=take('<I')[0]
   if size<1 or size>4:raise ValueError('Invalid service row')
   calls.append(list(take('<'+'I'*size)))
  actual=[digest.hex(),ret if c['nativeReturn']is not None else None,calls];expected=[c['nativeSHA256'],c['nativeReturn'],c['nativeServices']]
  if actual!=expected and len(errors)<20:errors.append({'case':i,'native':expected,'managed':actual})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved managed clone/cache outputs compared to original fixtures with explicit constructor/refresh services; GPU creation remains unclaimed.')
(R/'geometry-material-clone-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
