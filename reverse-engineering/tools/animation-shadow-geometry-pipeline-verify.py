"""Full original legacy queue consumer and all three real CPU shape writers."""
from pathlib import Path
import ast,struct,json,gzip,base64,hashlib,collections,math
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def sha(b):return hashlib.sha256(b).hexdigest()
consumerPath=B/'tools/animation-shadow-consumer-verify.py';nodes=[]
for node in ast.parse(consumerPath.read_text()).body:
 if isinstance(node,ast.For)and isinstance(node.target,ast.Name)and node.target.id=='i'and ast.unparse(node.iter)=='range(512)':break
 nodes.append(node)
for node in nodes:
 if isinstance(node,ast.For)and isinstance(node.iter,ast.List)and[getattr(v,'value',None)for v in node.iter.elts]==[0x5e2920,0x5e3b50,0x5e4280]:node.iter.elts=[]
# Observe the independently predicted ring at each shape call, not only at end.
class Rings(ast.NodeTransformer):
 def visit_Call(self,node):
  self.generic_visit(node)
  if isinstance(node.func,ast.Attribute)and isinstance(node.func.value,ast.Name)and node.func.value.id=='out'and node.func.attr=='append':node.args[0]=ast.Call(func=ast.Name(id='dict',ctx=ast.Load()),args=[node.args[0]],keywords=[ast.keyword(arg='ring',value=ast.parse('[words(r) for r in circle]',mode='eval').body)])
  return node
for node in nodes:
 if isinstance(node,ast.FunctionDef)and node.name=='model':Rings().visit(node)
c={'__file__':str(consumerPath)};exec(compile(ast.fix_missing_locations(ast.Module(body=nodes,type_ignores=[])),'full-legacy-consumer','exec'),c)
n=c['n'];D=n.DATA;f=c['f'];QUEUE=c['QUEUE'];CIRCLE=c['CIRCLE'];QUEUE_SIZE=c['SIZE'];SOURCE=0x30000000;n.mu.mem_map(SOURCE,0x4000000);SIZE=0x100000;STARTS=D+0x20000;COUNTS=D+0x21000;OUTPUT=D+0x30000;raw=c['raw'];bits=f.bits;value=f.value
p=dict(D=D,STARTS=STARTS,COUNTS=COUNTS,OUTPUT=OUTPUT,W=c['W'],S=c['S'],struct=struct,raw=raw,math=math)
def functions(path,names,scope):
 for node in ast.parse((B/path).read_text()).body:
  if isinstance(node,ast.FunctionDef)and node.name in names:exec(compile(ast.Module(body=[node],type_ignores=[]),path+'-'+node.name,'exec'),scope)
functions('tools/animation-shadow-polygons-verify.py',['put','u32','transform','model'],p)
ellipse=dict(p,p=p,f=f);functions('tools/animation-shadow-ellipse-verify.py',['model'],ellipse)
cylinder=dict(p,p=p,f=f,bits=bits);functions('tools/animation-shadow-cylinder-verify.py',['double','neg','reciprocal','edge_pair','model'],cylinder)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
def observe(mu,a,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==0x5e4280:
  record,first,second,direction=n.unpack('<4I',sp+4);event=dict(entry=a,record=(record-QUEUE)//104,first=first,second=second,direction=list(n.unpack('<3I',direction)))
 else:
  resource,record,direction=n.unpack('<3I',sp+4);event=dict(entry=a,record=(record-QUEUE)//104,resource=resource,direction=list(n.unpack('<3I',direction)))
  if a==0x5e3b50:event.update(zip(['upper','lower'],n.unpack('<2I',sp+16)))
 event['ring']=[list(n.unpack('<3I',CIRCLE+i*12))for i in range(8)];c['events'].append(event)
for address in[0x5e4280,0x5e2920,0x5e3b50]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
polyFixture=R/'animation-shadow-polygons-native-fixtures.json.gz';polyDoc=json.loads(gzip.decompress(polyFixture.read_bytes()));shapes={}
for i,s in enumerate(polyDoc['shapes']):
 if'path'in s['source']:shapes[(s['source']['path'],s['source']['bindingOffset'])]=(i,dict(s,normals=[[value(x)for x in r]for r in s['normals']],vertices=[[value(x)for x in r]for r in s['vertices']]))
ellipseFixture=R/'animation-shadow-ellipse-native-fixtures.json.gz';cylinderFixture=R/'animation-shadow-cylinder-native-fixtures.json.gz';eDoc=json.loads(gzip.decompress(ellipseFixture.read_bytes()));cyDoc=json.loads(gzip.decompress(cylinderFixture.read_bytes()));resources={}
for kind,doc,key in [('ellipse',eDoc,'ellipses'),('cylinder',cyDoc,'cylinders')]:
 resources[kind]={(s['source']['path'],s['source']['sourceOffset']):(i,[value(v)for v in s['values']])for i,s in enumerate(doc[key])if'path'in s['source']}
queueFixture=R/'animation-shadow-queue-native-fixtures.json.gz';rigDoc=json.loads(gzip.decompress(queueFixture.read_bytes()));rigs={r['source']['path']:r for r in rigDoc['rigs']if'path'in r['source']};bindings=json.loads((R/'animation-shadow-queue-bindings.json').read_text());cases=[];counts=collections.Counter();usedShapes=set();usedEllipses=set();usedCylinders=set();sourceRecords=[]
for entry in bindings['entries']:
 if not entry['records']:continue
 original=(B/'extracted'/entry['path']).read_bytes();assert sha(original)==entry['sha256']and len(original)<0x4000000;sourceImage=bytearray(original);pairs={};resolved={};shapeBindings={};resourceValues={};resourceBindings={'ellipse':{},'cylinder':{}}
 for row in entry['records']:
  key=(entry['path'],row['sourceOffset'])
  if key in shapes:
   si,s=shapes[key];pair=s['source']['pairOffset'];first=SOURCE+s['source']['normalOffset'];second=SOURCE+s['source']['vertexOffset'];struct.pack_into('<2I',sourceImage,pair,first,second);pairs[str(SOURCE+pair)]=[first,second];resolved[(first,second)]=s;shapeBindings[str(first)+':'+str(second)]=si;usedShapes.add(si)
  for kind,ptrIndex,countIndex,stride in [('ellipse',0,3,48),('cylinder',1,4,64)]:
   for j in range(row['serialized'][countIndex]):
    at=row['resolvedPointers'][ptrIndex]+j*stride;si,v=resources[kind][(entry['path'],at)];resourceValues[(kind,SOURCE+at)]=v;resourceBindings[kind][str(SOURCE+at)]=si;(usedEllipses if kind=='ellipse'else usedCylinders).add(si)
 n.write(SOURCE,sourceImage);beforeSource=sha(sourceImage);sourceIndex=len(sourceRecords);sourceRecords.append(dict(path=entry['path'],sha256=entry['sha256'],relocatedSha256=beforeSource,shapeBindings=shapeBindings,resources=resourceBindings))
 for mode in range(6):
  queue=bytearray(b'\xa5'*QUEUE_SIZE)
  for i,row in enumerate(entry['records']):
   off=i*104;binding=row['serialized'];joint=rigs[entry['path']]['joints'][binding[6]];queue[off:off+64]=struct.pack('<16I',*joint);ptrs=[SOURCE+v if v else 0 for v in row['resolvedPointers']];struct.pack_into('<3I',queue,off+64,*ptrs);queue[off+100:off+103]=bytes(binding[3:6]);queue[off+103]=(i//2 if mode==1 else 7 if mode==2 else i)&255
   direction=[65536.,12.,-8.]if mode==1 else[1.,-3.,2.]
   if mode==4:direction=[[1.,-3.,2.],[-2.,-1.,.5],[0.,0.,0.],[65536.,-0.,4.]][i%4]
   for j,v in enumerate(direction):struct.pack_into('<f',queue,off+76+j*4,v)
   struct.pack_into('<2f',queue,off+92,0.,0. if mode==2 or mode==3 and i%2 else 1e6)
  camera=[1.,2.,3.];circle=[[float(i*3+j-12)for j in range(3)]for i in range(8)];initial=dict(vertexCount=5 if mode&1 else 0,groupCount=[0,249,250,0xffffffff,240,3][mode],generated=0xa5a5a5a5);color=[0xffffffff,0x12345678,0,0x80000000,0xabcdef01,0x01020304][mode];count=len(entry['records'])if mode!=5 else 0;before=bytearray(b'\xa5'*SIZE);want=bytearray(before);consumer=c['model'](queue,count,camera,pairs,circle);vc=initial['vertexCount'];gc=initial['groupCount'];generated=0
  for event in consumer['events']:
   matrix=list(struct.unpack_from('<16f',queue,event['record']*104));direction=[value(v)for v in event['direction']]
   if event['entry']==0x5e4280:want,result=p['model'](want,resolved[(event['first'],event['second'])],matrix,direction,vc,gc,generated)
   elif event['entry']==0x5e3b50:want,result=ellipse['model'](want,resourceValues[('ellipse',event['resource'])],matrix,direction,[[value(v)for v in r]for r in event['ring']],vc,gc,generated,color)
   else:want,result,_=cylinder['model'](want,resourceValues[('cylinder',event['resource'])],matrix,direction,vc,gc,generated)
   vc=result['vertexCount'];gc=result['groupCount'];generated=result['generated']
  n.write(D,before);n.write(QUEUE,queue);n.pack('<i',0x973fe8,count);n.pack('<3f',0x973718,*camera);n.write(CIRCLE,b''.join(raw(r)for r in circle))
  for a,v in [(0x973fec,initial['vertexCount']),(0x973ff0,initial['groupCount']),(0x971878,initial['generated']),(0x963f88,STARTS),(0x96e568,COUNTS),(0x963f94,OUTPUT),(0x2854c00,color)]:n.pack('<I',a,v)
  c['events'].clear();c['trace'].clear();n.call(0x5e4840,count=100000000);got=n.read(D,SIZE);actual=dict(vertexCount=n.unpack('<I',0x973fec)[0],groupCount=n.unpack('<I',0x973ff0)[0],generated=n.unpack('<I',0x971878)[0],circle=[list(n.unpack('<3I',CIRCLE+i*12))for i in range(8)],events=c['events'].copy());expected=dict(vertexCount=vc,groupCount=gc,generated=generated,circle=consumer['circle'],events=consumer['events'])
  assert got==want and actual==expected,(entry['path'],mode,[i for i,(a,b)in enumerate(zip(got,want))if a!=b][:30],[(k,actual[k],expected[k])for k in actual if actual[k]!=expected[k]][:1])
  assert n.read(QUEUE,QUEUE_SIZE)==queue and n.unpack('<i',0x973fe8)[0]==count and n.read(0x973718,12)==raw(camera)and sha(n.read(SOURCE,len(sourceImage)))==beforeSource
  actual['sha256']=sha(got);cases.append(dict(source=sourceIndex,mode=mode,queueZ=base64.b64encode(gzip.compress(queue,mtime=0)).decode(),count=count,camera=[bits(v)for v in camera],pairs=pairs,initial=initial,color=color,native=actual));counts['cases']+=1;counts['vertices']+=vc-initial['vertexCount'];counts['preparations']+=c['trace'].count(0x5e4740)
  for address,name in[(0x5e4280,'polygonCalls'),(0x5e2920,'cylinderCalls'),(0x5e3b50,'ellipseCalls')]:counts[name]+=sum(e['entry']==address for e in actual['events'])
 if len(sourceRecords)%25==0:print('rigs',len(sourceRecords),'checks',len(cases),flush=True)
def ref(p):return dict(path=p.relative_to(B).as_posix(),sha256=sha(p.read_bytes()))
fixture=R/'animation-shadow-geometry-pipeline-native-fixtures.json.gz';fixture.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,polygonFixture=ref(polyFixture),ellipseFixture=ref(ellipseFixture),cylinderFixture=ref(cylinderFixture),sine=ref(c['sinePath']),angleTable=c['table'],sources=sourceRecords,cases=cases),separators=(',',':')).encode(),mtime=0))
dependencies=['tools/animation-shadow-consumer-verify.py','tools/animation-shadow-polygons-verify.py','tools/animation-shadow-ellipse-verify.py','tools/animation-shadow-cylinder-verify.py',str(polyFixture.relative_to(B)),str(ellipseFixture.relative_to(B)),str(cylinderFixture.relative_to(B)),str(queueFixture.relative_to(B)),'reports/animation-shadow-queue-bindings.json'];report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),authoredRigs=len(sourceRecords),authoredPolygonGroups=len(usedShapes),authoredEllipses=len(usedEllipses),authoredCylinders=len(usedCylinders),mismatches=0,fixture=dict(ref(fixture),bytes=fixture.stat().st_size),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Original5e4840 and all three real shape writers execute unchanged, with their actual numerical helpers. No computational or shape callbacks. Complete1MiB output, ordered shape arguments/ring snapshots, counters and untouched queue/camera/relocated source blobs match independently composed models.',limits=['All244 nonempty authored binding rigs; finite active geometry, authored quietNaN polygon normals retain original policy.','Six scenarios: vector, paired vertical, full rejection, alternating rejection, varying per-record directions, zero queue count; controlled camera/light values.','Adequate disjoint output backing. Native pair fields relocated in copied source blobs; not a complete runtime GHG loader or GPU frame.','Managed replay compiled only; no generated managed executable launched.']);(R/'animation-shadow-geometry-pipeline-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
