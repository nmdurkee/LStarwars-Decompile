"""Prepare selection replay fixture or compare saved output; never launch."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-dynamic-selection-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'DSSI'+struct.pack('<I',len(cases)))
for c in cases:
 if c['kind']=='lod':buf.extend(struct.pack('<2I',0,len(c['thresholds'])));buf.extend(struct.pack('<'+'f'*len(c['thresholds']),*c['thresholds']));buf.extend(struct.pack('<Ii',c['distanceWord'],c['forced']))
 else:buf.extend(struct.pack('<7i',1,c['tag'],c['tablePresent'],c['tableEntry'],c['globalEntry'],c['sameLayout'],c['mode']))
path=B/'reconstructed/geometry/fixtures/dynamic-selection.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data);report={'schema':'geometry-dynamic-selection-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-dynamic-selection-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'DynamicSelectionHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'Compiled branch equivalence pending; no whole5f0f00 or GPU claim.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  value=struct.unpack_from(fmt,out,offset);offset+=size;return value
 if take('<4sI')!=(b'DSSO',len(cases)):raise ValueError('Invalid header')
 for i,c in enumerate(cases):
  if c['kind']=='lod':actual=take('<i')[0];expected=c['nativeIndex']
  else:
   merged,count=take('<2I')
   if count>1000000:raise ValueError('Unbounded chain output')
   actual=[bool(merged),list(take('<'+'I'*count))];expected=[c['nativeMerged'],c['nativeSelected']]
  if actual!=expected and len(errors)<30:errors.append({'case':i,'managed':actual,'native':expected})
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled LOD/material branch outputs compared to original; downstream clone/shader/packet boundaries remain explicit.')
(R/'geometry-dynamic-selection-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
