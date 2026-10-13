"""Original full ellipse shadow CPU writer, real helpers and authored records."""
from pathlib import Path
import ast,struct,json,gzip,base64,hashlib,random,math,collections
B=Path(__file__).resolve().parent.parent;R=B/'reports'
path=B/'tools/animation-shadow-consumer-verify.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.For)and isinstance(node.target,ast.Name)and node.target.id=='i'and ast.unparse(node.iter)=='range(512)':break
 nodes.append(node)
for node in nodes:
 if isinstance(node,ast.For)and isinstance(node.iter,ast.List)and[getattr(v,'value',None)for v in node.iter.elts]==[0x5e2920,0x5e3b50,0x5e4280]:node.iter.elts=[]
c={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),'ellipse-common','exec'),c)
n=c['n'];D=n.DATA;f=c['f'];W=c['W'];S=c['S'];bits=f.bits;value=f.value;raw=c['raw'];SHAPE=D+0x100;MATRIX=D+0x200;DIRECTION=D+0x300;STARTS=D+0x1000;COUNTS=D+0x2000;OUTPUT=D+0x3000;SIZE=0x5000;cases=[];ellipses=[];counts=collections.Counter();rng=random.Random(0x5e3b50)
p=dict(W=W,S=S)
polyPath=B/'tools/animation-shadow-polygons-verify.py'
for node in ast.parse(polyPath.read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name=='transform':exec(compile(ast.Module(body=[node],type_ignores=[]),'ellipse-transform','exec'),p)
def sha(b):return hashlib.sha256(b).hexdigest()
def words(v):return[bits(x)for x in v]
def put(b,addr,v):b[addr-D:addr-D+len(v)]=v
def u32(b,addr,v):struct.pack_into('<I',b,addr-D,v&0xffffffff)
def model(before,ellipse,matrix,direction,ring,vertexCount,groupCount,generated,color):
 b=bytearray(before);center=p['transform'](ellipse[:3]+[1.],matrix,False)[:3];axes=[];inverse=[]
 for at in [6,3,9]:
  endpoint=[S(W(ellipse[i])+W(ellipse[at+i]))for i in range(3)]+[1.];q=p['transform'](endpoint,matrix,False);axis=[S(W(q[i])-W(center[i]))for i in range(3)];axes.append(axis);x,y,z=map(W,axis);length=f.f32(math.sqrt(S(y*y+x*x+z*z)));inverse.append(0. if length==0 else f.p.x.store(f.p.x.div(f.p.x.wide(1.),f.p.x.wide(length))))
 if groupCount<250:u32(b,STARTS+groupCount*4,vertexCount);u32(b,COUNTS+groupCount*4,8);groupCount+=1
 def point(r):
  coefficients=[S((W(r[1])*W(a[1])+W(r[0])*W(a[0])+W(r[2])*W(a[2]))*W(inverse[i]))for i,a in enumerate(axes)]
  offset=[S(W(coefficients[1])*W(axes[1][i])+W(coefficients[0])*W(axes[0][i])+W(coefficients[2])*W(axes[2][i]))for i in range(3)]
  return[S(W(center[i])+W(offset[i]))for i in range(3)]
 for i in range(8):
  generated=(generated+2)&0xffffffff;a=point(ring[i]);v=point(ring[(i+1)&7]);ea=[S(W(direction[j])*W(5.)+W(a[j]))for j in range(3)];ev=[S(W(direction[j])*W(5.)+W(v[j]))for j in range(3)]
  for xyz in[a,ea,ev,v]:put(b,OUTPUT+vertexCount*16,raw(xyz)+struct.pack('<I',color));vertexCount+=1
 return b,dict(vertexCount=vertexCount,groupCount=groupCount,generated=generated)
def check(ei,index,mode):
 e=ellipses[ei];matrix=e.get('matrix',f.IDENTITY).copy();direction=[[0.,-4.,0.],[1.,-3.,2.],[0.,0.,0.],[-1.,2.,-3.]][mode%4]
 if mode==1:matrix=[f.f32(rng.uniform(-2,2))for i in range(16)]
 if mode==3:matrix=[-0. if(i+index)%2 else 0. for i in range(16)]
 if mode==2:ring=[[f.f32(rng.uniform(-2,2))for j in range(3)]for i in range(8)]
 else:_,ring=c['prepare'](direction)
 initial=dict(vertexCount=[0,1,33][index%3],groupCount=[0,249,250,251,0xffffffff][index%5],generated=[0,0xfffffff8,0x80000000][index%3]);color=[0,0xffffffff,0x12345678,0x80000000][index%4];b=bytearray(b'\xa5'*SIZE);put(b,SHAPE,raw(e['values']));put(b,MATRIX,raw(matrix));put(b,DIRECTION,raw(direction));want,result=model(b,e['values'],matrix,direction,ring,color=color,**initial);n.write(D,b);n.write(0x9715b0,b''.join(raw(r)for r in ring))
 for addr,v in [(0x973fec,initial['vertexCount']),(0x973ff0,initial['groupCount']),(0x971878,initial['generated']),(0x963f88,STARTS),(0x96e568,COUNTS),(0x963f94,OUTPUT),(0x2854c00,color)]:n.pack('<I',addr,v)
 c['trace'].clear();n.call(0x5e3b50,[SHAPE,MATRIX,DIRECTION,0xffc00001,0x7f800000],count=1000000);got=n.read(D,SIZE);actual=dict(vertexCount=n.unpack('<I',0x973fec)[0],groupCount=n.unpack('<I',0x973ff0)[0],generated=n.unpack('<I',0x971878)[0])
 if got!=want or actual!=result:
  offsets=[i for i,(a,v)in enumerate(zip(got,want))if a!=v];(R/'animation-shadow-ellipse-debug.json').write_text(json.dumps(dict(ellipse=ei,index=index,mode=mode,source=e['source'],offsets=offsets[:40],actual=actual,expected=result,words=[dict(offset=i-i%4,actual=struct.unpack_from('<I',got,i-i%4)[0],expected=struct.unpack_from('<I',want,i-i%4)[0])for i in offsets[:12]]),indent=2));raise AssertionError('ellipse mismatch')
 assert c['trace'].count(0x5c0240)==3 and n.read(0x9715b0,96)==b''.join(raw(r)for r in ring)
 cases.append(dict(ellipse=ei,mode=mode,matrix=words(matrix),direction=words(direction),ring=[words(r)for r in ring],initial=initial,color=color,native=dict(actual,sha256=sha(got))));counts['cases']+=1;counts['vertices']+=32;counts['roots']+=3
bindings=json.loads((R/'animation-shadow-queue-bindings.json').read_text());rigs=json.loads(gzip.decompress((R/'animation-shadow-queue-native-fixtures.json.gz').read_bytes()))['rigs'];byPath={r['source']['path']:r for r in rigs if'path'in r['source']};usedRigs=set();groups=0
for entry in bindings['entries']:
 rows=[r for r in entry['records']if r['serialized'][3]and r['resolvedPointers'][0]]
 if not rows:continue
 rawSource=(B/'extracted'/entry['path']).read_bytes();assert sha(rawSource)==entry['sha256']
 for row in rows:
  groups+=1
  for i in range(row['serialized'][3]):
   at=row['resolvedPointers'][0]+i*48;v=list(struct.unpack_from('<12f',rawSource,at));assert all(math.isfinite(x)for x in v);ei=len(ellipses);ellipses.append(dict(source=dict(path=entry['path'],sha256=entry['sha256'],bindingOffset=row['sourceOffset'],sourceOffset=at,recordSha256=sha(rawSource[at:at+48])),values=v,matrix=[value(x)for x in byPath[entry['path']]['joints'][row['serialized'][6]]]))
   for mode in[0,1,2]:check(ei,len(cases),mode)
 usedRigs.add(entry['path'])
 if len(usedRigs)%50==0:print('rigs',len(usedRigs),'ellipses',len(ellipses),'cases',len(cases),flush=True)
authored=len(ellipses)
for i in range(128):
 v=[f.f32(rng.uniform(-10,10))for j in range(12)]
 if i%4==0:v=[-0. if(i+j)%2 else 0. for j in range(12)]
 if i%4==1:v[3:6]=[0.,0.,0.]
 ei=len(ellipses);ellipses.append(dict(source=dict(synthetic=i),values=v))
 for mode in range(4):check(ei,len(cases),mode)
fixture=R/'animation-shadow-ellipse-native-fixtures.json.gz';payload=[dict(e,values=words(e['values']),matrix=words(e.get('matrix',f.IDENTITY)))for e in ellipses];fixture.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,ellipses=payload,cases=cases),separators=(',',':')).encode(),mtime=0))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
data=n.read(0x5e3b50,0x72d);assembly=dict(binarySha256=n.sha256,windows=[dict(address='0x5e3b50',size=len(data),sha256=sha(data),instructions=[dict(address=hex(v.address),mnemonic=v.mnemonic,operands=v.op_str)for v in Cs(CS_ARCH_X86,CS_MODE_32).disasm(data,0x5e3b50)])]);(R/'animation-shadow-ellipse-assembly.json').write_text(json.dumps(assembly,indent=2)+'\n')
dependencies=['tools/animation-shadow-consumer-verify.py','tools/animation-shadow-polygons-verify.py','reports/animation-shadow-queue-bindings.json','reports/animation-shadow-queue-native-fixtures.json.gz']
report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),authoredRigs=len(usedRigs),authoredGroups=groups,authoredEllipses=authored,mismatches=0,fixture=dict(path=str(fixture.relative_to(B)),bytes=fixture.stat().st_size,sha256=sha(fixture.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Original5e3b50 and actual scalar point/root helpers execute without computational replacements. Entire20,480-byte backing, vertex/group/generated counters and untouched ring match independent64-significand model. Two extra stack parameters carry nonfinite poison to establish they are ignored.',limits=['Finite ellipse/matrix/direction/ring and finite stored results. Degenerate zero axes retain inverse-length0.','Adequate disjoint output backing;250-entry metadata capacity does not stop vertex writes.','No managed executable or graphics-device launch.'])
(R/'animation-shadow-ellipse-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
