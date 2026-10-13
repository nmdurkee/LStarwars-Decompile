"""Prepare normal submission fixture or compare saved output. Never launches."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-dynamic-submission-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'DYNI'+struct.pack('<I',len(cases)))
for c in cases:
 b=bytes.fromhex(c['before']);o=c['options'];buf.extend(struct.pack('<I',len(b)));buf.extend(b);buf.extend(struct.pack('<2I3iIi4I',o['handle'],o['matrix'],o['forcedVisibility'],o['forcedLod'],o['filterMode'],o['shadowMask'],o['shadowMetadataDisabled'],o['globalOverride'],o['overrideTable'],o['overrideFirst'],o['overrideScalarWord']));buf.extend(struct.pack('<4I',*o['uv']));buf.extend(struct.pack('<24fi',*o['camera'],*o['view'],o['near'],o['far'],o['farOverride'],o['sx'],o['sy'],o['enabled']))
path=B/'reconstructed/geometry/fixtures/dynamic-submission.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data);report={'schema':'geometry-dynamic-submission-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-dynamic-submission-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'DynamicSubmissionHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'Managed equality pending. Normal finite ordinary/prefix branch only; GPU output unclaimed.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'DYNO',len(cases)):raise ValueError('Invalid header')
 for i,c in enumerate(cases):
  digest,ret,shadow,count=take('<32s3I')
  if count>1000000:raise ValueError('Unbounded output draw count')
  draws=[list(take('<3I'))for _ in range(count)];actual=[digest.hex(),ret,shadow,draws];expected=[c['nativeSHA256'],c['nativeReturn'],c['nativeShadowMask'],c['nativeDraws']]
  if actual!=expected and len(errors)<20:errors.append({'case':i,'native':expected,'managed':actual})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved managed normal CPU outputs compared to original-x86 fixtures; excluded paths and GPU behavior remain unclaimed.')
(R/'geometry-dynamic-submission-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
