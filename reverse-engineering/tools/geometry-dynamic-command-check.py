"""Prepare dynamic support replay or compare saved managed output; no launch."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args()
native=json.loads((R/'geometry-dynamic-command-native-validation.json').read_text());assert native['passed'];fixtures=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()));cases=fixtures['cases'];branches=fixtures['dispatch'];buf=bytearray(b'DSPI'+struct.pack('<I',len(cases)));kinds=['reserve','alpha','metadata','override']
for c in cases:
 mem=bytes.fromhex(c['before']);buf.extend(struct.pack('<3I',kinds.index(c['kind']),len(mem),len(c['args'])));buf.extend(mem)
 for value in c['args']:buf.extend(struct.pack('<I',value&0xffffffff))
buf.extend(struct.pack('<I',len(branches)))
for c in branches:
 for value in c['input']:buf.extend(struct.pack('<I',value&0xffffffff))
path=B/'reconstructed/geometry/fixtures/dynamic-command-support.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data)
report={'schema':'geometry-dynamic-command-managed-check-v1','caseCount':len(cases),'dispatchCases':len(branches),'excludedSignalingNanCases':native['excludedSignalingNanCount'],'nativeEvidence':'geometry-dynamic-command-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'DynamicCommandSupportHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'Compiled C# equality pending; no executable launch.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  value=struct.unpack_from(fmt,out,offset);offset+=size;return value
 if take('<4sI')!=(b'DSPO',len(cases)):raise ValueError('Invalid header')
 for i,c in enumerate(cases):
  digest,ret=take('<32sI')
  if digest.hex()!=c['nativeSHA256']and len(errors)<30:errors.append({'case':i,'field':'memorySHA256','managed':digest.hex(),'native':c['nativeSHA256']})
  if c['nativeReturn']is not None and ret!=c['nativeReturn']:errors.append({'case':i,'field':'return','managed':ret,'native':c['nativeReturn']})
 if take('<I')[0]!=len(branches):raise ValueError('Invalid branch count')
 for i,c in enumerate(branches):
  actual=take('<I')[0]
  if actual!=c['native']['target']and len(errors)<30:errors.append({'branch':i,'managed':actual,'native':c['native']['target']})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled output compared to original CPU helpers and dispatcher predicate; GPU unclaimed.')
(R/'geometry-dynamic-command-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
