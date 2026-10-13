"""Complete original cylinder writer against independently evaluated finite math."""
from pathlib import Path
import ast,struct,json,gzip,hashlib,random,math,collections
B=Path(__file__).resolve().parent.parent;R=B/'reports'
path=B/'tools/animation-shadow-ellipse-verify.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.Assign)and any(isinstance(t,ast.Name)and t.id=='bindings'for t in node.targets):break
 if isinstance(node,ast.FunctionDef)and node.name in ['model','check']:continue
 nodes.append(node)
c={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),'cylinder-common','exec'),c)
n=c['n'];D=n.DATA;f=c['f'];W=c['W'];S=c['S'];bits=f.bits;value=f.value;raw=c['raw'];p=c['p'];SHAPE=c['SHAPE'];MATRIX=c['MATRIX'];DIRECTION=c['DIRECTION'];STARTS=c['STARTS'];COUNTS=c['COUNTS'];OUTPUT=c['OUTPUT'];SIZE=c['SIZE'];cases=[];cylinders=[];counts=collections.Counter();rng=random.Random(0x5e2920)
def sha(b):return hashlib.sha256(b).hexdigest()
def words(v):return[bits(x)for x in v]
def put(b,addr,v):b[addr-D:addr-D+len(v)]=v
def u32(b,addr,v):struct.pack_into('<I',b,addr-D,v&0xffffffff)
def double(v):return W(math.copysign(0.,-1 if v.negative else 1)if v.w[0]==0 else math.ldexp(float(v.w[0]),v.w[1]))
def neg(v):return W.make((-v.w[0],v.w[1]),not v.negative)
def reciprocal(v):return 0. if v==0 else f.p.x.store(f.p.x.div(f.p.x.wide(1.),f.p.x.wide(v)))
def edge_pair(edge,axis,side,radius,inverse,rounded):
 result=[[],[]];k=W(f.f32(.707));r=W(radius);inv=W(inverse)
 for j in range(3):
  a=W(axis[j]);s=W(side[j]);sr=s*r
  if not rounded:
   v=[s+a,s-a,neg(a)-s,a-s,s+a];x,y=v[edge:edge+2]
  elif edge==0:x,y=sr+a,double(sr)-a
  elif edge==1:x,y=sr-a,(double(sr)*k-a)-(a*inv if j==2 else inv*a)*r*k
  elif edge==2:x,y=(sr*k-a)-(a*inv if j==2 else inv*a)*r*k,neg(a)-(inv*r*a if j==2 else r*a*inv)
  elif edge==3:x,y=neg(a)-(inv*r*a if j==2 else r*a*inv),(neg(a)-sr*k)-inv*a*r*k
  elif edge==4:x,y=(neg(a)-sr*k)-(r*inv*a if j==2 else inv*a*r)*k,neg(a)-double(sr)
  elif edge==5:x,y=neg(a)-sr,a-double(sr)
  elif edge==6:x,y=a-sr,(a-double(sr)*k)+r*a*inv*k
  elif edge==7:
   cap=double(r*a*inv);x,y=(a-sr*k)+cap*k,a+cap
  elif edge==8:
   cap=r*a*inv;x,y=cap+a,(sr*k+a)+double(cap)*k
  else:x,y=(sr*k+a)+r*a*inv*k,a+double(sr)
  result[0].append(S(x));result[1].append(S(y))
 return result
def model(before,cylinder,matrix,direction,vertexCount,groupCount,generated):
 b=bytearray(before);rounded=bool(bits(cylinder[0])&1);edges=10 if rounded else 4;roots=1
 if groupCount<250:u32(b,STARTS+groupCount*4,vertexCount);u32(b,COUNTS+groupCount*4,edges);groupCount+=1
 center=p['transform'](cylinder[:3]+[1.],matrix,False)[:3];axes=[]
 for at in [3,6,10]:
  endpoint=[S(W(cylinder[i])+W(cylinder[at+i]))for i in range(3)]+[1.];q=p['transform'](endpoint,matrix,False);axes.append([S(W(q[i])-W(center[i]))for i in range(3)])
 a,ab,ac=axes;x,y,z=map(W,a);dx,dy,dz=map(W,direction);side=[S(y*dz-z*dy),S(dx*z-dz*x),S(x*dy-y*dx)];sx,sy,sz=map(W,side);squared=S(sx*sx+sy*sy+sz*sz)
 if squared>0:roots+=1;squared=reciprocal(f.f32(math.sqrt(squared)))
 side=[S(W(v)*W(squared))for v in side];squared=S(x*x+y*y+z*z);inverse=0.
 if squared>0:roots+=1;inverse=reciprocal(f.f32(math.sqrt(squared)))
 dots=[S(W(side[1])*W(t[1])+W(side[0])*W(t[0])+W(side[2])*W(t[2]))for t in [ab,ac]];radius=f.f32(math.sqrt(S(W(dots[0])*W(dots[0])+W(dots[1])*W(dots[1]))))
 if not rounded:side=[S(W(v)*W(radius))for v in side]
 for edge in range(edges):
  if rounded:generated=(generated+2)&0xffffffff
  a,v=edge_pair(edge,axes[0],side,radius,inverse,rounded);a=[S(W(center[j])+W(a[j]))for j in range(3)];v=[S(W(v[j])+W(center[j]))for j in range(3)];ea=[S(W(direction[j])*W(5.)+W(a[j]))for j in range(3)];ev=[S(W(direction[j])*W(5.)+W(v[j]))for j in range(3)]
  for xyz in[a,ea,ev,v]:put(b,OUTPUT+vertexCount*16,raw(xyz)+struct.pack('<I',0xffffffff));vertexCount+=1
 return b,dict(vertexCount=vertexCount,groupCount=groupCount,generated=generated),roots
def check(ci,index,mode):
 e=cylinders[ci];matrix=e.get('matrix',f.IDENTITY).copy();direction=[[0.,-4.,0.],[1.,-3.,2.],[0.,0.,0.],[-1.,2.,-3.]][mode%4]
 if mode==1:matrix=[f.f32(rng.uniform(-2,2))for i in range(16)]
 if mode==3:matrix=[-0. if(i+index)%2 else 0. for i in range(16)]
 initial=dict(vertexCount=[0,1,33][index%3],groupCount=[0,249,250,251,0xffffffff][index%5],generated=[0,0xfffffff8,0x80000000][index%3]);b=bytearray(b'\xa5'*SIZE);put(b,SHAPE,struct.pack('<16I',*e.get('recordWords',words(e['values']))));put(b,MATRIX,raw(matrix));put(b,DIRECTION,raw(direction));want,result,roots=model(b,e['values'],matrix,direction,**initial);n.write(D,b)
 for addr,v in [(0x973fec,initial['vertexCount']),(0x973ff0,initial['groupCount']),(0x971878,initial['generated']),(0x963f88,STARTS),(0x96e568,COUNTS),(0x963f94,OUTPUT)]:n.pack('<I',addr,v)
 c['c']['trace'].clear();n.call(0x5e2920,[SHAPE,MATRIX,DIRECTION],count=1000000);got=n.read(D,SIZE);actual=dict(vertexCount=n.unpack('<I',0x973fec)[0],groupCount=n.unpack('<I',0x973ff0)[0],generated=n.unpack('<I',0x971878)[0]);actualRoots=c['c']['trace'].count(0x5c0240)
 if got!=want or actual!=result or roots!=actualRoots:
  offsets=[i for i,(a,v)in enumerate(zip(got,want))if a!=v];(R/'animation-shadow-cylinder-debug.json').write_text(json.dumps(dict(cylinder=ci,index=index,mode=mode,source=e['source'],offsets=offsets[:40],actual=actual,expected=result,roots=[actualRoots,roots],words=[dict(offset=i-i%4,actual=struct.unpack_from('<I',got,i-i%4)[0],expected=struct.unpack_from('<I',want,i-i%4)[0])for i in offsets[:12]]),indent=2));raise AssertionError('cylinder mismatch')
 cases.append(dict(cylinder=ci,mode=mode,matrix=words(matrix),direction=words(direction),initial=initial,native=dict(actual,sha256=sha(got))));counts['cases']+=1;counts['vertices']+=result['vertexCount']-initial['vertexCount'];counts['roots']+=roots;counts['rounded'if bits(e['values'][0])&1 else'four-sided']+=1
bindings=json.loads((R/'animation-shadow-queue-bindings.json').read_text());rigs=json.loads(gzip.decompress((R/'animation-shadow-queue-native-fixtures.json.gz').read_bytes()))['rigs'];byPath={r['source']['path']:r for r in rigs if'path'in r['source']};usedRigs=set();groups=0;flags=collections.Counter()
for entry in bindings['entries']:
 rows=[r for r in entry['records']if r['serialized'][4]and r['resolvedPointers'][1]]
 if not rows:continue
 rawSource=(B/'extracted'/entry['path']).read_bytes();assert sha(rawSource)==entry['sha256']
 for row in rows:
  groups+=1
  for i in range(row['serialized'][4]):
   at=row['resolvedPointers'][1]+i*64;v=list(struct.unpack_from('<16f',rawSource,at));assert all(math.isfinite(v[j])for j in list(range(9))+[10,11,12]);ci=len(cylinders);cylinders.append(dict(source=dict(path=entry['path'],sha256=entry['sha256'],bindingOffset=row['sourceOffset'],sourceOffset=at,recordSha256=sha(rawSource[at:at+64])),values=v,recordWords=list(struct.unpack_from('<16I',rawSource,at)),matrix=[value(x)for x in byPath[entry['path']]['joints'][row['serialized'][6]]]))
   flags[str(bits(v[0])&1)]+=1
   for mode in[0,1,2]:check(ci,len(cases),mode)
 usedRigs.add(entry['path'])
 if len(usedRigs)%25==0:print('rigs',len(usedRigs),'cylinders',len(cylinders),'cases',len(cases),flush=True)
authored=len(cylinders)
for i in range(256):
 v=[f.f32(rng.uniform(-10,10))for j in range(16)]
 if i%4==0:v=[-0. if(i+j)%2 else 0. for j in range(16)]
 if i%4==1:v[3:6]=[0.,0.,0.]
 v[0]=value((bits(v[0])&0xfffffffe)|(i//4&1));ci=len(cylinders);cylinders.append(dict(source=dict(synthetic=i),values=v))
 for mode in range(4):check(ci,len(cases),mode)
fixture=R/'animation-shadow-cylinder-native-fixtures.json.gz';fixture.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,cylinders=[dict(e,values=e.get('recordWords',words(e['values'])),matrix=words(e.get('matrix',f.IDENTITY)))for e in cylinders],cases=cases),separators=(',',':')).encode(),mtime=0))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
data=n.read(0x5e2920,0x11f2);assembly=dict(binarySha256=n.sha256,windows=[dict(address='0x5e2920',size=len(data),sha256=sha(data),instructions=[dict(address=hex(v.address),mnemonic=v.mnemonic,operands=v.op_str)for v in Cs(CS_ARCH_X86,CS_MODE_32).disasm(data,0x5e2920)])],jumpTables=[dict(address=hex(a),targets=[hex(v)for v in n.unpack('<'+'I'*count,a)])for a,count in[(0x5e3b14,10),(0x5e3b3c,4)]],roundingConstant=dict(address='0x7653d0',bytes=n.read(0x7653d0,8).hex(),value=n.unpack('<d',0x7653d0)[0]));(R/'animation-shadow-cylinder-assembly.json').write_text(json.dumps(assembly,indent=2)+'\n')
dependencies=['tools/animation-shadow-ellipse-verify.py','tools/animation-shadow-consumer-verify.py','tools/animation-shadow-polygons-verify.py','reports/animation-shadow-queue-bindings.json','reports/animation-shadow-queue-native-fixtures.json.gz'];report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),authoredRigs=len(usedRigs),authoredGroups=groups,authoredCylinders=authored,authoredFlags=dict(flags),mismatches=0,fixture=dict(path=str(fixture.relative_to(B)),bytes=fixture.stat().st_size,sha256=sha(fixture.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Original5e2920 and actual scalar point/cross/root helpers execute without computational replacements. Full20,480-byte image and vertex/group/generated counters match independent64-significand model.',limits=['Finite active resource/matrix/direction and stored results; sufficient disjoint output backing.','Both flag branches, zero axes/direction and signed-zero matrices;250-entry metadata saturation does not stop vertices.','No managed executable or graphics-device launch.']);(R/'animation-shadow-cylinder-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
