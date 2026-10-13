"""Original light extrusion planes and aggregate camera-corner bounds."""
import ast,json,struct,gzip,hashlib,math,random,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
source=B/'tools/geometry-shadow-frustum-native.py';tree=ast.parse(source.read_text());prefix=[]
for node in tree.body:
 if isinstance(node,ast.Assign) and any(isinstance(t,ast.Name)and t.id=='portals'for t in node.targets):break
 prefix.append(node)
ns={'__file__':str(source)};exec(compile(ast.Module(body=prefix,type_ignores=[]),str(source),'exec'),ns)
n=ns['n'];x=ns['x'];W=x.wide;add=x.add;mul=x.mul;div=x.div;store=ns['store'];f32=ns['f32'];plane=ns['plane'];frustum=ns['frustum'];D=n.DATA;SIZE=1024;DIR=D+0x80;CORNERS=D+0x100;OUT=D+0x200;CENTER=D+0x300;POSITION=D+0x320;RADIUS=D+0x340
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX
faces=[tuple(struct.unpack('<4I',n.read(0x806ba0+i*16,16)))for i in range(6)]
edges=[tuple(struct.unpack('<2I',n.read(0x806c00+i*8,8)))for i in range(12)]
adjacent=[tuple(struct.unpack('<2I',n.read(0x806c60+i*8,8)))for i in range(12)]
extrusion=n.unpack('<f',0x80bf7c)[0];assert extrusion==120.
calls=[]
for address in [0x5c82c0,0x5c8540,0x5c7fa0,0x5b3920,0x5b3b30,0x5c0240]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:calls.append(a),begin=address,end=address)
def dot(a,b):return store(add(add(mul(W(a[1]),W(b[1])),mul(W(a[0]),W(b[0]))),mul(W(a[2]),W(b[2]))),(a[1]*b[1]+a[0]*b[0])+a[2]*b[2])
def cross(a,b):
 return [store(add(mul(W(a[i]),W(b[j])),mul(W(-a[j]),W(b[i]))),a[i]*b[j]-a[j]*b[i])for i,j in [(1,2),(2,0),(0,1)]]
def normal(v):
 length=f32(math.sqrt(dot(v,v)));inverse=x.store(div(W(1),W(length)))if length>0 else 0.
 return [store(mul(W(t),W(inverse)),t*inverse)for t in v]
def planes(direction,corners):
 delta=[f32(-extrusion*v)for v in direction];result=[];facing=[]
 for face in faces:
  a,b,c=[corners[j]for j in face[:3]];left=[f32(b[i]-a[i])for i in range(3)];right=[f32(c[i]-a[i])for i in range(3)];v=cross(left,right);positive=dot(v,delta)>=0;facing.append(positive)
  if not positive:
   v=normal([-t for t in v]);result.append(v+[-dot(v,a)])
 for edge,adj in zip(edges,adjacent):
  if len(result)>=9:break
  if facing[adj[0]]!=facing[adj[1]]:
   a,b=[corners[j]for j in edge];c=[f32(a[i]+delta[i])for i in range(3)];result.append(plane(a,b,c)if facing[adj[0]]else plane(c,b,a))
 return result,facing
def aggregate(direction,corners):
 center=corners[0].copy()
 for p in corners[1:]:
  for j in range(3):center[j]=f32(p[j]+center[j])
 for j in range(3):center[j]=f32(center[j]*.125)
 squared=[]
 for p in corners:
  v=[f32(center[j]-p[j])for j in range(3)];squared.append(dot(v,v))
 # The original computes a maximum in memory, then passes the LAST squared
 # distance still on the x87 stack to sqrt. Preserve the actual instruction path.
 radius=f32(math.sqrt(squared[-1]));position=[f32(center[j]-f32(direction[j]*100.))for j in range(3)]
 return center,position,radius,squared
cases=[];counts=collections.Counter();hist=collections.Counter();facehist=collections.Counter();radiusDiffs=0
def execute(kind,index,direction,corners,poison=0,origin=None):
 global radiusDiffs
 before=bytearray((i*37+index*13)&255 for i in range(SIZE));pack=lambda b,p,v:struct.pack_into('<'+'f'*len(v),b,p-D,*v)
 pack(before,DIR,direction)
 for i,p in enumerate(corners):pack(before,CORNERS+i*16,p)
 expected=bytearray(before);wanted=None
 if kind=='planes':
  values,facing=planes(direction,corners);wanted=len(values)
  for i,v in enumerate(values):pack(expected,OUT+i*16,v)
  args=[DIR,CORNERS,OUT];address=0x5c82c0;hist[wanted]+=1;facehist[''.join(str(int(v))for v in facing)]+=1;counts['floatWords']+=4*wanted
 else:
  center,position,radius,squared=aggregate(direction,corners);pack(expected,CENTER,center);pack(expected,POSITION,position);pack(expected,RADIUS,[radius]);args=[DIR,CORNERS,CENTER,POSITION,RADIUS];address=0x5c8540;counts['floatWords']+=8;radiusDiffs+=radius!=f32(math.sqrt(max(squared)))
 n.write(D,before);n.write(n.STACK,struct.pack('<I',poison)*16384);calls.clear();n.call(address,args,count=100000);actual=bytearray(n.read(D,SIZE));raw=bytes(actual);returned=n.mu.reg_read(UC_X86_REG_EAX)
 if kind=='bounds':actual[POSITION-D+12:POSITION-D+16]=expected[POSITION-D+12:POSITION-D+16]
 if actual!=expected or wanted is not None and returned!=wanted:raise AssertionError(dict(kind=kind,index=index,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:30],actual=raw.hex(),expected=expected.hex(),returned=returned,wanted=wanted))
 counts['cases']+=1;counts[kind]+=1;cases.append(dict(kind=kind,index=index,before=bytes(before).hex(),nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeReturn=wanted,nativeOutputBytes=raw[OUT-D:OUT-D+144].hex()if kind=='planes'else raw[CENTER-D:RADIUS-D+4].hex(),nativeCalls=calls.copy(),stackPoison=poison,source=origin));return raw
cp='exports/cutscenes/LEVELS/EPISODE_V/ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.CU2.json';camera=json.loads((B/cp).read_text());identity=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.];matrices=[identity]+[r['matrix']for r in camera['cameras']['cameras']];directions=[[1.,0.,0.],[-1.,0.,0.],[0.,1.,0.],[0.,-1.,0.],[0.,0.,1.],[0.,0.,-1.],[0.,0.,0.],[-0.,-0.,-0.],[1.,1.,1.],[-1.,1.,-1.]];rng=random.Random(0x5c82c0)
for i in range(1024):
 params=[f32([0.,.1,1.,2.,3.,-1.][i%6]),f32([1.,.75,1.3333333,-1.][i%4]),f32([.1,1.,10.,-1.][i//4%4]),f32([0.,1.,100.,1000.][i//16%4])];points,_,_=frustum(matrices[i%7],*params);corners=[p+[1.]for p in points];direction=directions[i%len(directions)]if i%2==0 else[f32(rng.uniform(-1,1))for j in range(3)]
 for kind in ['planes','bounds']:execute(kind,i,direction,corners,poison=[0,0x3f800000,0xdeadbeef][i%3],origin=dict(cameraFile=cp,cameraIndex=i%7-1,projection=params))
# Arbitrary finite corner inputs exercise non-frustum data, degenerate faces,
# count9 truncation, and an asymmetric radius that distinguishes last from max.
for i in range(512):
 corners=[[f32(rng.uniform(-1000,1000))for _ in range(3)]+[float(i%5)]for k in range(8)]
 if i%7==0:corners=[[0.,-0.,0.,1.]for k in range(8)]
 if i%11==0:corners[7]=[0.,0.,0.,1.]
 direction=directions[i%len(directions)]
 for kind in ['planes','bounds']:execute(kind,2000+i,direction,corners,poison=0x12345678)
audit=[];corners=[[float(i),float(i*i),float(i%3),1.]for i in range(8)]
for poison in [0,0x12345678,0xdeadbeef]:
 raw=execute('bounds',3000+len(audit),[1.,0.,0.],corners,poison);audit.append(dict(stackPoison=poison,positionW=struct.unpack_from('<I',raw,POSITION-D+12)[0]))
assert all(a['positionW']==a['stackPoison']for a in audit)
fp=R/'geometry-shadow-volume-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,direction=DIR,corners=CORNERS,output=OUT,center=CENTER,position=POSITION,radius=RADIUS,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-volume-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],planeCountHistogram=dict(hist),faceMaskHistogram=dict(facehist),radiusNotMaximumCases=radiusDiffs,fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),paddingAudit=audit,tables=dict(faces=faces,edges=edges,adjacent=adjacent,extrusion=extrusion),limits=['Actual original5c82c0/5c8540 and real nested plane/cross/normalization/sqrt helpers execute; no computational replacements.','Finite disjoint input/output domain. Six authored CU2 matrices plus identity generate controlled frustums; synthetic corners include degenerate geometry. Camera projection/light directions are controlled, not recovered producer inputs.','The aggregate helper returns sqrt(distanceSquaredToCorner7), despite computing a maximum in memory first. This is original instruction behavior, not a corrected bounding sphere.','Position W is uninitialized native stack padding, normalized only for comparison; raw native bytes and poison audit retained. Portable helper preserves caller W.','Managed replay compilation and equality remain separate. Outer5e8950 integration, perspective/rigid inverse andGPU outputs remain separate.']);(R/'geometry-shadow-volume-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
