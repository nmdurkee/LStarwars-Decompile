"""Compact full-entry fixture; prepare/compare only, never launches managed code."""
import argparse,gzip,json,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';D=B/'reconstructed/geometry/fixtures'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args()
native=json.loads((R/'geometry-portal-entry-native-validation.json').read_text());assert native['passed']
with gzip.open(R/native['fixtureFile'],'rt',encoding='utf8')as f:cases=json.load(f)['cases']
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};buffer=bytearray(b'PENT'+struct.pack('<I',len(native['sources'])));ids={}
for si,source in enumerate(native['sources']):
 row=index[source['source']];ids[source['source']]=si
 if row['sha256']!=source['sha256']:raise ValueError('Source metadata changed')
 data=json.loads((B/row['report']).read_text());pd=data['portalData'];render=json.loads((B/'exports/geometry/scene-runtime'/(row['source']+'.json')).read_text())['renderState'];buffer.extend(struct.pack('<III',len(data['bounds']),len(pd['rooms']),len(pd['portals'])))
 for b in data['bounds']:buffer.extend(struct.pack('<6f',*b['center'],*b['extent']))
 buffer.extend(bytes(v['flags']for v in render['instances']));overrides=bytearray(625)
 for v in render['instances']:
  if v['portalVisibilityOverride']:overrides[v['index']>>3]|=1<<(v['index']&7)
 buffer.extend(overrides)
 for r in pd['rooms']:
  buffer.extend(struct.pack('<IBIII',r['flags'],r['priority'],len(r['instanceIndices']),len(r['portalIndices']),len(r['planeEquations'])))
  for i in r['instanceIndices']+r['portalIndices']:buffer.extend(struct.pack('<h',i))
  for p in r['planeEquations']:buffer.extend(struct.pack('<4f',*p))
 for p in pd['portals']:
  buffer.extend(struct.pack('<4fhhII',*p['plane'],p['frontRoom'],p['backRoom'],p['activeFlags'],len(p['vertices'])))
  for v in p['vertices']:buffer.extend(struct.pack('<3f',*v))
frames=[];frameIds={};records=[]
for c in cases:
 record=struct.pack('<35f',*c['world'],*c['projection'],c['fov'],c['aspect'],c['near'])
 if record not in frameIds:frameIds[record]=len(frames);frames.append(record)
 records.append(struct.pack('<IB?B3fIi',ids[c['source']],c['mode'],c['override'],c['gate'],*c['point'],frameIds[record],c['depthLimit']))
buffer.extend(struct.pack('<I',len(frames)))
for record in frames:buffer.extend(record)
buffer.extend(struct.pack('<I',len(records)))
for record in records:buffer.extend(record)
inputPath=D/'portal-entry.bin';inputPath.write_bytes(buffer)
report={'schema':'portal-entry-managed-check-v1','nativeEvidence':'geometry-portal-entry-native-validation.json','fixtureCount':len(cases),'sourceCount':len(ids),'frameCount':len(frames),'fixtureBytes':len(buffer),'fixtureSHA256':hashlib.sha256(buffer).hexdigest(),'status':'prepared-not-executed','mainType':'PortalEntryHarness','arguments':['inputFixture','originalSineTable','outputFile'],'comparison':'All entry return/root/cache/bit/room/path/clip states,plane aliasing and numeric planes; then exact room-query/mask/canary bytes. Signed-zero differences counted separately.','resultClaim':'No compiled-source equivalence until ordinary compiled output is compared.'}
if args.compare:
 output=args.compare.read_bytes();offset=0;errors=[];zeroSigns=0;scalarCount=0
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(output):raise ValueError('Truncated compiled output')
  v=struct.unpack_from(fmt,output,offset);offset+=size;return v
 def compare(a,e,where):
  if a!=e and len(errors)<30:errors.append({'context':where,'managed':a,'native':e})
 def floats(expected,where):
  global scalarCount,zeroSigns
  actual=take('<'+'f'*len(expected))
  for i,(a,e)in enumerate(zip(actual,expected)):
   scalarCount+=1
   if a==e==0 and struct.pack('<f',a)!=struct.pack('<f',e):zeroSigns+=1
   compare(a,e,[where,i])
 if take('<4sI')!=(b'PENO',len(cases)):raise ValueError('Invalid compiled header')
 for ci,c in enumerate(cases):
  e=c['native'];compare(list(take('<???hi')),[bool(e['returned']),e['attached'],e['cameraBound'],e['selectedGlobal'],e['selectedHeader']],[ci,'entryHeader']);floats(e['cameraCopy']+e['cachedPosition']+e['eyePlane']+e['nearPlane'],[ci,'camera']);compare(take('<32s')[0].hex(),e['bitsSHA256'],[ci,'visibility']);compare(list(take('<'+'I'*len(e['roomFlags']))),e['roomFlags'],[ci,'roomFlags']);count=take('<I')[0]
  if count>100000:raise ValueError('Unbounded compiled entry count')
  compare([list(take('<hhi'))for _ in range(count)],e['entries'],[ci,'entries']);compare(list(take('<16h')),e['path'],[ci,'path']);count=take('<I')[0]
  if count!=len(c['nativeVolumes']):raise ValueError('Incorrect compiled volume count atcase'+str(ci))
  for vi,v in enumerate(c['nativeVolumes']):
   room,alias,planes=take('<hiI');compare([room,alias,planes],[v['room'],c['nativeAliases'][vi],len(v['planes'])],[ci,vi,'header'])
   if planes!=len(v['planes']):raise ValueError('Incorrect compiled plane count')
   floats([x for p in v['planes']for x in p]+v['packed']+v['min']+v['max'],[ci,vi,'volume'])
  if e['returned']:
   queries=take('<'+str(len(e['roomQueries']))+'s')[0];compare(list(queries),e['roomQueries'],[ci,'roomQueries']);mask=take('<'+str(len(e['roomFlags'])+16)+'s')[0];compare(mask.hex(),(bytes.fromhex(e['roomMask'])+bytes([0xa5])*16).hex(),[ci,'roomMaskAndTail'])
 if offset!=len(output):raise ValueError('Trailing compiled output')
 report.update(status='passed'if not errors else'failed',errors=errors,scalarComparisons=scalarCount,signedZeroBitDifferences=zeroSigns,outputSHA256=hashlib.sha256(output).hexdigest(),resultClaim='Saved compiled output compared against original-PC entry results.')
(R/'geometry-portal-entry-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
if report['status']=='failed':raise SystemExit(1)
