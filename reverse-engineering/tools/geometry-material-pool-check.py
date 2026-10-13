"""Prepare material-pool replay or compare saved output; never launches."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-material-pool-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'MPLI'+struct.pack('<I',len(cases)));kinds=['reset','initialize','allocate','cloneIntegration']
for c in cases:
 b=bytes.fromhex(c['before']);o=c['options'];a=c['args'];buf.extend(struct.pack('<2I',kinds.index(c['kind']),len(b)));buf.extend(b);buf.extend(struct.pack('<I',len(a)));buf.extend(struct.pack('<'+'I'*len(a),*[v&0xffffffff for v in a]));buf.extend(struct.pack('<2i2I',o['capacity'],o['pending'],o['refreshXor'],o['typeWord']))
path=B/'reconstructed/geometry/fixtures/material-pool.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data);report={'schema':'geometry-material-pool-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-material-pool-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'MaterialPoolHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'Managed equality pending; successful positive pool capacity/zero locks, plus clone composition with shader refresh explicit.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'MPLO',len(cases)):raise ValueError('Invalid header')
 for i,c in enumerate(cases):
  digest,ret,pending=take('<32s2I');actual=[digest.hex(),ret if c['nativeReturn']is not None else None,pending];expected=[c['nativeSHA256'],c['nativeReturn'],c['nativePending']]
  if actual!=expected and len(errors)<20:errors.append({'case':i,'native':expected,'managed':actual})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved managed pool/initializer/clone-composition outputs compared to original fixtures; shader refresh/device creation remain excluded.')
(R/'geometry-material-pool-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
