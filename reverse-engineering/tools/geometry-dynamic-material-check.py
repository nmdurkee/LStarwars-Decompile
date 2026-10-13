"""Prepare dynamic material integration replay or compare saved output."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-dynamic-material-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'DMCI'+struct.pack('<I',len(cases)))
for c in cases:
 b=bytes.fromhex(c['before']);o=c['options'];lc=c['lifecycleOptions'];buf.extend(struct.pack('<I',len(b)));buf.extend(b);buf.extend(struct.pack('<2I3iIi4I',o['handle'],o['matrix'],o['forcedVisibility'],o['forcedLod'],o['filterMode'],o['shadowMask'],o['shadowMetadataDisabled'],o['globalOverride'],o['overrideTable'],o['overrideFirst'],o['overrideScalarWord']));buf.extend(struct.pack('<4I',*o['uv']));buf.extend(struct.pack('<24fi',*o['camera'],*o['view'],o['near'],o['far'],o['farOverride'],o['sx'],o['sy'],o['enabled']));buf.extend(struct.pack('<2I',lc['typeWord'],lc['factoryVariant']))
path=B/'reconstructed/geometry/fixtures/dynamic-material.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data);report={'schema':'geometry-dynamic-material-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-dynamic-material-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'DynamicMaterialHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'Managed equality pending; normal different-layout submission composed through clone/pool/refresh with shader factory explicit.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 def rows(width):
  count=take('<I')[0]
  if count>1000000:raise ValueError('Unbounded output count')
  return[list(take('<'+'I'*width))for _ in range(count)]
 if take('<4sI')!=(b'DMCO',len(cases)):raise ValueError('Invalid header')
 for i,c in enumerate(cases):
  digest,ret,shadow=take('<32s2I');draws=rows(3);factory=rows(6);decl=[v[0]for v in rows(1)];actual=[digest.hex(),ret,shadow,draws,factory,decl];expected=[c['nativeSHA256'],c['nativeReturn'],c['nativeShadowMask'],c['nativeDraws'],c['nativeFactory'],c['nativeDeclarations']]
  if actual!=expected and len(errors)<20:errors.append({'case':i,'native':expected,'managed':actual})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved managed normal draw/lifecycle outputs compared to original; shader factory and device creation remain explicit.')
(R/'geometry-dynamic-material-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
