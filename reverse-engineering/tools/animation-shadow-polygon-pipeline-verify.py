"""Original queue consumer through actual polygon extrusion; other shapes explicit."""
from pathlib import Path
import ast,struct,json,gzip,base64,hashlib,collections,os
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def sha(b):return hashlib.sha256(b).hexdigest()
consumerPath=B/'tools/animation-shadow-consumer-verify.py';text=consumerPath.read_text();nodes=[]
for node in ast.parse(text).body:
 if isinstance(node,ast.For)and isinstance(node.target,ast.Name)and node.target.id=='i'and isinstance(node.iter,ast.Call)and ast.unparse(node.iter)=='range(512)':break
 nodes.append(node)
removed=False
for node in nodes:
 if isinstance(node,ast.For)and isinstance(node.iter,ast.List)and [getattr(v,'value',None)for v in node.iter.elts]==[0x5e2920,0x5e3b50,0x5e4280]:node.iter.elts=node.iter.elts[:2];removed=True
assert removed
prefix=ast.unparse(ast.Module(body=nodes,type_ignores=[]))
c={'__file__':str(consumerPath)};exec(compile(prefix,'consumer-with-real-polygons','exec'),c)
n=c['n'];D=n.DATA;f=c['f'];QUEUE=c['QUEUE'];CIRCLE=c['CIRCLE'];QUEUE_SIZE=c['SIZE'];SOURCE=0x30000000;n.mu.mem_map(SOURCE,0x4000000);SIZE=0x100000;STARTS=D+0x20000;COUNTS=D+0x21000;OUTPUT=D+0x30000;raw=c['raw'];bits=f.bits;value=f.value
p=dict(D=D,STARTS=STARTS,COUNTS=COUNTS,OUTPUT=OUTPUT,W=c['W'],S=c['S'],struct=struct);polygonPath=B/'tools/animation-shadow-polygons-verify.py'
for node in ast.parse(polygonPath.read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['put','u32','transform','model']:exec(compile(ast.Module(body=[node],type_ignores=[]),'polygon-composition-'+node.name,'exec'),p)
p['raw']=raw;p['math']=__import__('math')
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
def observePolygon(mu,a,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);record,first,second,direction=n.unpack('<4I',sp+4);c['events'].append(dict(entry=a,record=(record-QUEUE)//104,first=first,second=second,direction=list(n.unpack('<3I',direction))))
n.mu.hook_add(UC_HOOK_CODE,observePolygon,begin=0x5e4280,end=0x5e4280)
polyFixture=R/'animation-shadow-polygons-native-fixtures.json.gz';doc=json.loads(gzip.decompress(polyFixture.read_bytes()));shapes={}
for i,s in enumerate(doc['shapes']):
 if 'path'not in s['source']:continue
 converted=dict(s,normals=[[value(x)for x in r]for r in s['normals']],vertices=[[value(x)for x in r]for r in s['vertices']]);shapes[(s['source']['path'],s['source']['bindingOffset'])]=(i,converted)
queueFixture=R/'animation-shadow-queue-native-fixtures.json.gz';rigDoc=json.loads(gzip.decompress(queueFixture.read_bytes()));rigs={r['source']['path']:r for r in rigDoc['rigs']if'path'in r['source']}
bindings=json.loads((R/'animation-shadow-queue-bindings.json').read_text());cases=[];counts=collections.Counter();usedRigs=set();usedShapes=set();sourceRecords=[]
for entry in bindings['entries']:
 if not any((entry['path'],r['sourceOffset'])in shapes for r in entry['records']):continue
 original=(B/'extracted'/entry['path']).read_bytes();assert sha(original)==entry['sha256']and len(original)<0x4000000;sourceImage=bytearray(original);pairs={};resolved={};shapeBindings={}
 for row in entry['records']:
  key=(entry['path'],row['sourceOffset'])
  if key not in shapes:continue
  si,s=shapes[key];pair=s['source']['pairOffset'];first=SOURCE+s['source']['normalOffset'];second=SOURCE+s['source']['vertexOffset'];struct.pack_into('<2I',sourceImage,pair,first,second);pairs[str(SOURCE+pair)]=[first,second];resolved[(first,second)]=s;shapeBindings[str(first)+':'+str(second)]=si;usedShapes.add(si)
 n.write(SOURCE,sourceImage);beforeSource=sha(sourceImage);sourceIndex=len(sourceRecords);sourceRecords.append(dict(path=entry['path'],sha256=entry['sha256'],relocatedSha256=beforeSource,shapeBindings=shapeBindings))
 for mode in range(4):
  queue=bytearray(b'\xa5'*QUEUE_SIZE)
  for i,row in enumerate(entry['records']):
   off=i*104;binding=row['serialized'];joint=rigs[entry['path']]['joints'][binding[6]];queue[off:off+64]=struct.pack('<16I',*joint);ptrs=[SOURCE+v if v else 0 for v in row['resolvedPointers']];struct.pack_into('<3I',queue,off+64,*ptrs);queue[off+100:off+103]=bytes(binding[3:6]);queue[off+103]=(i//2 if mode==1 else 7 if mode==2 else i)&255
   direction=[65536.,12.,-8.]if mode==1 else[1.,-3.,2.]
   for j,v in enumerate(direction):struct.pack_into('<f',queue,off+76+j*4,v)
   struct.pack_into('<2f',queue,off+92,0.,0. if mode==2 or mode==3 and i%2 else 1e6)
  camera=[1.,2.,3.];circle=[[float(i*3+j-12)for j in range(3)]for i in range(8)];initial=dict(vertexCount=5 if mode&1 else 0,groupCount=[0,249,250,0xffffffff][mode],generated=0xa5a5a5a5);before=bytearray(b'\xa5'*SIZE);want=bytearray(before);consumer=c['model'](queue,len(entry['records']),camera,pairs,circle);vc=initial['vertexCount'];gc=initial['groupCount'];generated=0
  for event in consumer['events']:
   if event['entry']!=0x5e4280:generated=(generated+(event['entry']&255)+1)&0xffffffff;continue
   shape=resolved[(event['first'],event['second'])];matrix=list(struct.unpack_from('<16f',queue,event['record']*104));direction=[value(v)for v in event['direction']];want,result=p['model'](want,shape,matrix,direction,vc,gc,generated);vc=result['vertexCount'];gc=result['groupCount'];generated=result['generated']
  n.write(D,before);n.write(QUEUE,queue);n.pack('<i',0x973fe8,len(entry['records']));n.pack('<3f',0x973718,*camera);n.write(CIRCLE,b''.join(raw(r)for r in circle))
  for a,v in [(0x973fec,initial['vertexCount']),(0x973ff0,initial['groupCount']),(0x971878,initial['generated']),(0x963f88,STARTS),(0x96e568,COUNTS),(0x963f94,OUTPUT)]:n.pack('<I',a,v)
  c['events'].clear();c['trace'].clear();n.call(0x5e4840,count=100000000);got=n.read(D,SIZE);actual=dict(vertexCount=n.unpack('<I',0x973fec)[0],groupCount=n.unpack('<I',0x973ff0)[0],generated=n.unpack('<I',0x971878)[0],circle=[list(n.unpack('<3I',CIRCLE+i*12))for i in range(8)],events=c['events'].copy())
  expected=dict(vertexCount=vc,groupCount=gc,generated=generated,circle=consumer['circle'],events=consumer['events'])
  assert got==want and actual==expected,(entry['path'],mode,[i for i,(a,b)in enumerate(zip(got,want))if a!=b][:30],[(k,actual[k],expected[k])for k in actual if actual[k]!=expected[k]][:1])
  assert n.read(QUEUE,QUEUE_SIZE)==queue and n.unpack('<i',0x973fe8)[0]==len(entry['records'])and n.read(0x973718,12)==raw(camera)and sha(n.read(SOURCE,len(sourceImage)))==beforeSource
  actual['sha256']=sha(got);cases.append(dict(source=sourceIndex,mode=mode,queueZ=base64.b64encode(gzip.compress(queue,mtime=0)).decode(),count=len(entry['records']),camera=[bits(v)for v in camera],pairs=pairs,initial=initial,native=actual));counts['cases']+=1;counts['polygonCalls']+=sum(v['entry']==0x5e4280 for v in actual['events']);counts['otherShapeCalls']+=sum(v['entry']!=0x5e4280 for v in actual['events']);counts['vertices']+=vc-initial['vertexCount'];counts['preparations']+=c['trace'].count(0x5e4740)
 usedRigs.add(entry['path'])
 if len(usedRigs)%25==0:print('rigs',len(usedRigs),'checks',len(cases),flush=True)
fixture=R/'animation-shadow-polygon-pipeline-native-fixtures.json.gz';fixture.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,polygonFixture=dict(path=str(polyFixture.relative_to(B)),sha256=sha(polyFixture.read_bytes())),sine=dict(path=str(c['sinePath'].relative_to(B)),sha256=sha(c['sineRaw'])),angleTable=c['table'],sources=sourceRecords,cases=cases),separators=(',',':')).encode(),mtime=0))
dependencies=['tools/animation-shadow-consumer-verify.py','tools/animation-shadow-polygons-verify.py',str(polyFixture.relative_to(B)),str(queueFixture.relative_to(B)),'reports/animation-shadow-queue-bindings.json']
report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),authoredRigs=len(usedRigs),authoredPolygonGroups=len(usedShapes),mismatches=0,fixture=dict(path=str(fixture.relative_to(B)),bytes=fixture.stat().st_size,sha256=sha(fixture.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Original5e4840 through actual5e4280 and all direction/angle/root/transform code. Only ellipse5e3b50 and cylinder5e2920 remain recording callbacks with explicit counter effects. Complete1MiB output, shape events, counters/ring and unchanged queue/camera/relocated source blob match independently composed recovered models.',limits=['All496 authored polygon groups across198 source rigs, full binding-list order; control lighting/camera parameters, four queue scenarios. Source pair fields relocated to bounded copied source blobs.','The ellipse/cylinder services remain explicit; no complete all-shape geometry or GPU claim.','Vertices/matrix/direction finite, quietNaN face-normal policy inherited from verified writer. Valid disjoint backing and adequate output capacity.','Managed compilation only; no generated managed executable launched.'])
(R/'animation-shadow-polygon-pipeline-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
