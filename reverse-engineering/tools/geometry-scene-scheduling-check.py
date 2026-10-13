"""Build compact scheduling replay and compare saved output; no managed launch."""
import argparse,json,gzip,struct,hashlib,math
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';D=B/'reconstructed/geometry/fixtures'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args()
native=json.loads((R/'geometry-scene-scheduling-native-validation.json').read_text());boundaries=json.loads((R/'geometry-scheduling-boundaries-native-validation.json').read_text());assert native['passed']and boundaries['passed']
with gzip.open(R/native['fixtureFile'],'rt',encoding='utf8')as f:cases=json.load(f)['cases']
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};buf=bytearray(b'PSCI'+struct.pack('<I',len(native['sources'])));ids={};dimensions={}
for si,source in enumerate(native['sources']):
 ids[source['source']]=si;row=index[source['source']]
 if row['sha256']!=source['sha256']:raise ValueError('Source changed')
 data=json.loads((B/row['report']).read_text());pd=data['portalData'];render=json.loads((B/'exports/geometry/scene-runtime'/(row['source']+'.json')).read_text())['renderState'];raw=(B/'extracted'/row['source']).read_bytes();dims=[len(data['bounds']),len(pd['rooms']),len(pd['portals']),len(data['models']),len(data['materials']),len(data['specialObjects'])];dimensions[row['source']]=dims;buf.extend(struct.pack('<6I',*dims))
 for b in data['bounds']:buf.extend(struct.pack('<6f',*b['center'],*b['extent']))
 buf.extend(bytes(v['flags']for v in render['instances']));overrides=bytearray(625)
 for v in render['instances']:
  if v['portalVisibilityOverride']:overrides[v['index']>>3]|=1<<(v['index']&7)
 buf.extend(overrides)
 for r in pd['rooms']:
  buf.extend(struct.pack('<IBIII',r['flags'],r['priority'],len(r['instanceIndices']),len(r['portalIndices']),len(r['planeEquations'])))
  for i in r['instanceIndices']+r['portalIndices']:buf.extend(struct.pack('<h',i))
  for p in r['planeEquations']:buf.extend(struct.pack('<4f',*p))
 for p in pd['portals']:
  buf.extend(struct.pack('<4fhhII',*p['plane'],p['frontRoom'],p['backRoom'],p['activeFlags'],len(p['vertices'])))
  for v in p['vertices']:buf.extend(struct.pack('<3f',*v))
 for i,m in enumerate(data['models']):
  buf.extend(struct.pack('<ffI',render['lodRangesSquared'][i],render['farClipRanges'][i],len(m['parts'])))
  for p in m['parts']:buf.extend(struct.pack('<I',p['material']))
 for r in render['instances']:buf.extend(struct.pack('<2f',*r['fade']))
 for s in data['specialObjects']:
  a=s['address'];flags=struct.unpack_from('<I',raw,a+184)[0];relative=struct.unpack_from('<i',raw,a+196)[0];buf.extend(struct.pack('<Ii',flags,s['boundsIndex']));buf.extend(raw[a+64:a+128]);buf.extend(struct.pack('<?',relative not in[0,-1]))
  if relative not in[0,-1]:buf.extend(raw[a+196+relative:a+260+relative])
buf.extend(struct.pack('<I',len(cases)))
for c in cases:
 e=c['entryFixture'];buf.extend(struct.pack('<IBB??38fi',ids[c['source']],c['mode'],c['parity'],c['portalsEnabled'],c['dynamicPortalFiltering'],*e['world'],*e['projection'],e['fov'],e['aspect'],e['near'],*e['point'],e['depthLimit']));buf.extend(bytes.fromhex(c['frustumBlockHex']))
buf.extend(struct.pack('<I',len(boundaries['cases'])))
for c in boundaries['cases']:buf.extend(struct.pack('<???????',*c['input']))
buf.extend(struct.pack('<I',len(boundaries['prepareCases'])))
for c in boundaries['prepareCases']:buf.extend(struct.pack('<???i',c['workspace'],c['enabled'],c['alternateCount']is not None,c['alternateCount']or 0))
path=D/'scene-scheduling.bin';path.write_bytes(buf)
report={'schema':'scene-scheduling-managed-check-v1','nativeEvidence':'geometry-scene-scheduling-native-validation.json','boundaryEvidence':'geometry-scheduling-boundaries-native-validation.json','sourceCount':len(ids),'fixtureCount':len(cases),'boundaryCounts':boundaries['counts'],'fixtureBytes':len(buf),'fixtureSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'SceneSchedulingHarness','arguments':['inputFixture','originalSineTable','outputFile'],'resultClaim':'No compiled-source equivalence until ordinary compiled output is compared.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[];alphaComparisons=0;alphaMaximumError=0.
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated compiled output')
  values=struct.unpack_from(fmt,out,offset);offset+=size;return values
 def compare(a,e,context):
  if a!=e and len(errors)<30:errors.append({'context':context,'managed':a,'native':e})
 def calls():
  count=take('<I')[0]
  if count>100000:raise ValueError('Unbounded call count')
  return[hex(v)for v in take('<'+'I'*count)]
 if take('<4sI')!=(b'PSCO',len(cases)):raise ValueError('Bad output header')
 for ci,c in enumerate(cases):
  e=c['native'];dims=dimensions[c['source']];compare(calls(),e['phaseCalls'],[ci,'calls']);compare(list(take('<Ii2IIii')),[e['displayFlags'],e['contextCount'],*e['contextScratch'],e['contextFlags'],e['cameraMode'],e['visibilityActive']],[ci,'state']);compare(list(take('<105I')),e['shaderContext'],[ci,'shader']);compare(take('<'+str((dims[4]+7)//8)+'s')[0].hex(),e['materialBits'],[ci,'materialBits']);compare(take('<'+str(((dims[3]+15)//16)*4)+'s')[0].hex(),e['clipBits'],[ci,'clipBits']);count=take('<I')[0]
  if count!=len(e['dynamicHandoffs']):raise ValueError('Incorrect dynamic handoff count')
  for i,nativeEvent in enumerate(e['dynamicHandoffs']):
   index,override=take('<i?');matrix=take('<64s')[0].hex();compare([index,override,matrix],[nativeEvent['special'],nativeEvent['usesOverride'],nativeEvent['matrixHex']],[ci,'handoff',i])
  count=take('<I')[0]
  if count!=len(c['nativeAlpha']):raise ValueError('Incorrect alpha count')
  for i,(nativeIndex,nativeAlpha)in enumerate(c['nativeAlpha']):
   actualIndex,a=take('<if');compare(actualIndex,nativeIndex,[ci,'alphaIndex',i]);error=abs(a-nativeAlpha);alphaMaximumError=max(alphaMaximumError,error);alphaComparisons+=1;compare((math.isnan(a)and math.isnan(nativeAlpha))or error<=1e-7,True,[ci,'alpha',i,a,nativeAlpha])
  compare(take('<32s')[0].hex(),hashlib.sha256(bytes.fromhex(c['portalBitsHex'])).hexdigest(),[ci,'portalBits'])
  compare(calls(),['0x5f5830','0x5c12f0'],[ci,'dirtyReturn']);compare(calls(),['0x5f5830'],[ci,'globalSkip'])
 if take('<I')[0]!=len(boundaries['cases']):raise ValueError('Bad scheduler boundary count')
 for ci,c in enumerate(boundaries['cases']):
  e=c['native'];compare(calls(),e['calls'],['boundary',ci,'calls']);compare(take('<I')[0],e['displayFlags'],['boundary',ci,'flags']);compare(take('<32s')[0].hex(),e['shaderSHA256'],['boundary',ci,'shader']);count=take('<I')[0]
  if count!=len(e['events']):raise ValueError('Bad boundary handoff count')
  compare([[i,v,True,0,0,0]for i,v in[take('<i?')for _ in range(count)]],e['events'],['boundary',ci,'events'])
 if take('<I')[0]!=len(boundaries['prepareCases']):raise ValueError('Bad preparation boundary count')
 for ci,c in enumerate(boundaries['prepareCases']):
  e=c['native'];compare(list(take('<?II?II')),[bool(e[0]),e[1],e[2],bool(e[3]),e[4],e[5]],['prepare',ci])
 if offset!=len(out):raise ValueError('Trailing compiled output')
 report.update(status='passed'if not errors else'failed',errors=errors,alphaComparisons=alphaComparisons,alphaMaximumError=alphaMaximumError,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled output compared against original CPU scheduling results; dynamic packet generation remains outside scope.')
(R/'geometry-scene-scheduling-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
if report['status']=='failed':raise SystemExit(1)
