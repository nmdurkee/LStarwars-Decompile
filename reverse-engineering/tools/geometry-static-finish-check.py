"""Compact CPU finishing fixture; prepares/compares without managed execution."""
import argparse,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';D=B/'reconstructed/geometry/fixtures'
ap=argparse.ArgumentParser();ap.add_argument('--compare',type=Path);args=ap.parse_args();native=json.loads((R/'geometry-static-finish-native-validation.json').read_text());assert native['passed']
with gzip.open(R/native['fixtureFile'],'rt',encoding='utf8')as f:fixture=json.load(f)
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};buf=bytearray(b'FFIN'+struct.pack('<I',len(native['sources'])));ids={};sourceInfo={}
for si,source in enumerate(native['sources']):
 ids[source['source']]=si;row=index[source['source']];data=json.loads((B/row['report']).read_text());raw=(B/'extracted'/row['source']).read_bytes();rs=json.loads((B/'exports/geometry/scene-runtime'/(row['source']+'.json')).read_text())['renderState'];a=rs['address'];u=lambda q:struct.unpack_from('<I',raw,q)[0]
 def ptr(q):
  v=struct.unpack_from('<i',raw,q)[0];return q+v if v else 0
 count=u(a+4);start=ptr(a+8);items=raw[start:start+count*16];buf.extend(struct.pack('<I',count));buf.extend(items);clips=[];targets={};bindings={}
 for i,m in enumerate(data['models']):
  cp=ptr(m['address']+8);indices=[u(cp+j*4)for j in range(rs['clipItemCounts'][i])];clips.append(indices)
  for ix in indices:
   if items[ix*16]==0x82:
    resource=ptr(start+(ix-1)*16+4)
    if resource not in targets:targets[resource]=len(targets)
    bindings[ix]=targets[resource]
 buf.extend(struct.pack('<I',len(clips)))
 for indices in clips:
  buf.extend(struct.pack('<I',len(indices)))
  for i in indices:buf.extend(struct.pack('<I',i))
 buf.extend(struct.pack('<I',len(targets)))
 for resource in targets:buf.extend(raw[resource:resource+64])
 buf.extend(struct.pack('<I',len(bindings)))
 for item,target in bindings.items():buf.extend(struct.pack('<II',item,target))
 materialCount=u(a+0x4c);mt=ptr(a+0x50);rt=ptr(a+0x54);buf.extend(struct.pack('<I',materialCount))
 for i in range(materialCount):
  m=ptr(mt+i*4);buf.extend(struct.pack('<?',bool(m)))
  if m:buf.extend(raw[m+248:m+251])
  r=ptr(rt+i*4);buf.extend(struct.pack('<II',u(r+4),(ptr(r+12)-start)//16))
 sourceInfo[source['source']]={'items':items,'targetResources':list(targets)}
buf.extend(struct.pack('<I',len(fixture['authored'])))
for c in fixture['authored']:
 buf.extend(struct.pack('<IB',ids[c['source']],0 if c['kind']=='alpha'else 1))
 if c['kind']=='alpha':buf.extend(struct.pack('<?B',c['alphaPresent'],c['pattern']))
 else:buf.extend(struct.pack('<BB?',c['parity'],c['mode'],c['equal']))
buf.extend(struct.pack('<I',len(fixture['materialBoundaries'])))
for c in fixture['materialBoundaries']:
 buf.extend(struct.pack('<I??BB',c['count'],c['present'],c['firstPresent'],c['mode'],c['parity']));buf.extend(bytes.fromhex(c['current']));buf.extend(bytes.fromhex(c['previous']))
buf.extend(struct.pack('<I',len(fixture['finish'])))
for c in fixture['finish']:buf.extend(struct.pack('<IB',c['registeredCount'],c['pattern']))
path=D/'static-finish.bin.gz';compressed=gzip.compress(buf,mtime=0);path.write_bytes(compressed);report={'schema':'static-finish-managed-check-v1','nativeEvidence':'geometry-static-finish-native-validation.json','sourceCount':len(ids),'fixtureCounts':{'authored':len(fixture['authored']),'materialBoundaries':len(fixture['materialBoundaries']),'finish':len(fixture['finish'])},'fixtureFile':str(path.relative_to(B)),'fixtureBytes':len(compressed),'fixtureSHA256':hashlib.sha256(compressed).hexdigest(),'uncompressedBytes':len(buf),'uncompressedSHA256':hashlib.sha256(buf).hexdigest(),'status':'prepared-not-executed','mainType':'StaticFinalizationHarness','arguments':['compressedInputFixture','outputFile'],'resultClaim':'No compiled-source equivalence until ordinary compiled output is compared.'}
if args.compare:
 out=args.compare.read_bytes();offset=0;errors=[]
 def take(fmt):
  global offset
  size=struct.calcsize(fmt)
  if offset+size>len(out):raise ValueError('Truncated output')
  v=struct.unpack_from(fmt,out,offset);offset+=size;return v
 def compare(a,e,where):
  if a!=e and len(errors)<30:errors.append({'context':where,'managed':a,'native':e})
 if take('<4sI')!=(b'FFOU',len(fixture['authored'])):raise ValueError('Invalid output header')
 for ci,c in enumerate(fixture['authored']):
  if c['kind']=='alpha':
   resources=sourceInfo[c['source']]['targetResources'];count=take('<I')[0]
   if count!=len(resources):raise ValueError('Invalid matrix target count')
   expected=dict(c['nativeMatrixAlphaWords']);compare(list(take('<'+'I'*count)),[expected[p]for p in resources],[ci,'alphaBits'])
   items=bytearray(sourceInfo[c['source']]['items'])
   for ix in range(len(items)//16):items[ix*16+1]=[0,1,3,255][(ix+c['pattern'])%4]
   compare(take('<32s')[0].hex(),hashlib.sha256(items).hexdigest(),[ci,'portableItemPreservation'])
  else:compare(take('<32s')[0].hex(),c['nativeItemSHA256'],[ci,'materialItems'])
 if take('<I')[0]!=len(fixture['materialBoundaries']):raise ValueError('Incorrect material-boundary count')
 for ci,c in enumerate(fixture['materialBoundaries']):
  size=take('<I')[0]
  if size!=len(bytes.fromhex(c['nativeItems'])):raise ValueError('Incorrect command size')
  compare(take('<'+str(size)+'s')[0].hex(),c['nativeItems'],['materialBoundary',ci])
 if take('<I')[0]!=len(fixture['finish']):raise ValueError('Incorrect finish count')
 for ci,c in enumerate(fixture['finish']):
  count=take('<I')[0]
  if count>10000:raise ValueError('Unbounded finish call count')
  compare([hex(v)for v in take('<'+'I'*count)],c['nativeCalls'],['finish',ci,'calls']);compare(list(take('<24I')),c['nativeStats'],['finish',ci,'statistics'])
 if offset!=len(out):raise ValueError('Trailing output bytes')
 report.update(status='passed'if not errors else'failed',errors=errors,outputSHA256=hashlib.sha256(out).hexdigest(),resultClaim='Saved compiled output compared against original alpha/material/finish contracts; dynamic-list and sorted-packet callbacks remain boundaries.')
(R/'geometry-static-finish-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
if report['status']=='failed':raise SystemExit(1)
