"""Prepare valid dynamic queue replays; original unsafe fixture stays separate."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-dynamic-queue-native-validation.json').read_text());assert native['passed'];fixtures=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()));cases=fixtures['cases'];buf=bytearray(b'DQUE'+struct.pack('<I',len(cases)))
for c in cases:
 mem=bytes.fromhex(c['before']);buf.extend(struct.pack('<I',len(mem)));buf.extend(mem)
path=B/'reconstructed/geometry/fixtures/dynamic-material-queue.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data)
report={'schema':'geometry-dynamic-queue-managed-check-v1','caseCount':len(cases),'excludedOriginalUnsafe':len(fixtures.get('excludedUnsafe',[])),'nativeEvidence':'geometry-dynamic-queue-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'DynamicMaterialQueueHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'No compiled-source equivalence until saved managed output is compared.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 if take('<4sI')!=(b'DQOU',len(cases)):raise ValueError('Invalid output header')
 for i,c in enumerate(cases):
  digest=take('<32s')[0].hex();count=take('<I')[0]
  if count>1000000:raise ValueError('Unbounded trace')
  calls=list(take('<'+'I'*count))
  for field,a,e in [('memory',digest,c['nativeSHA256']),('calls',calls,c['nativeCalls'])]:
   if a!=e and len(errors)<30:errors.append({'case':i,'field':field,'managed':a,'native':e})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled output compared to finite original queue states. Original-fault stale-list fixture remains excluded.')
(R/'geometry-dynamic-queue-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))

