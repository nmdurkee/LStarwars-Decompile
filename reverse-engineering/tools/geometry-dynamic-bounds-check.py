"""Prepare scalar dynamic clipping replay or compare saved results; no launch."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-dynamic-bounds-native-validation.json').read_text());assert native['passed'];cases=json.loads(gzip.decompress((R/native['fixtureFile']).read_bytes()))['cases'];buf=bytearray(b'DBPI'+struct.pack('<I',len(cases)))
def put(fmt,*values):buf.extend(struct.pack(fmt,*values))
def floats(values):put('<'+'f'*len(values),*values)
for c in cases:
 if c['kind']=='box':
  put('<I',0);floats(c['minimum']+c['maximum']);put('<I',int(c['matrix']is not None))
  if c['matrix']is not None:floats(c['matrix'])
  floats(c['view']);floats(c['params'][:6]);put('<I',c['params'][6]);floats(c['beforeMatrix']+c['beforeFar'])
 elif c['kind']=='affine':put('<I',1);floats(c['left']+c['right'])
 else:put('<2I',2,len(c['packed']));floats(c['matrix']+c['packed'])
path=B/'reconstructed/geometry/fixtures/dynamic-bounds.bin.gz';data=gzip.compress(buf,mtime=0);path.write_bytes(data);report={'schema':'geometry-dynamic-bounds-managed-check-v1','caseCount':len(cases),'nativeEvidence':'geometry-dynamic-bounds-native-validation.json','fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(data),'fixtureSHA256':hashlib.sha256(data).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'DynamicBoundsHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'Compiled C# equality pending; all classification and float words required exact, including signed zero.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[];zeros=0
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  value=struct.unpack_from(fmt,out,offset);offset+=size;return value
 def check(values,case,field):
  global zeros
  actual=take('<'+'I'*len(values));expected=struct.unpack('<'+'I'*len(values),struct.pack('<'+'f'*len(values),*values))
  for j,(a,e)in enumerate(zip(actual,expected)):
   if a==e:continue
   if(a&0x7fffffff)==0 and(e&0x7fffffff)==0:zeros+=1
   if len(errors)<30:errors.append({'case':case,'field':field,'slot':j,'managedWord':a,'nativeWord':e})
 if take('<4sI')!=(b'DBPO',len(cases)):raise ValueError('Invalid output header')
 for i,c in enumerate(cases):
  if c['kind']=='box':
   code=take('<i')[0]
   if code!=c['nativeClass']:errors.append({'case':i,'managedClass':code,'nativeClass':c['nativeClass']})
   check(c['nativeMatrix'],i,'matrix');check(c['nativeFar'],i,'far');count=take('<I')[0];expected=c['nativePoints']or[]
   if count!=len(expected):raise ValueError('Invalid point output size')
   check(expected,i,'points')
  else:
   count=take('<I')[0]
   if count!=len(c['native']):raise ValueError('Invalid vector output size')
   check(c['native'],i,'result')
 if offset!=len(out):raise ValueError('Trailing output')
 report.update(status='passed'if not errors else'failed',errors=errors,signedZeroDifferences=zeros,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled classification and every float word compared to original, including signed zero; GPU unclaimed.')
(R/'geometry-dynamic-bounds-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
