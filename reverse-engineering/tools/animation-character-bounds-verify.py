"""Original55d2b0 predicted bounds, including actual POI/vector branches."""
from pathlib import Path
import importlib.util,struct,json,gzip,base64,hashlib,random,math,collections
B=Path(__file__).resolve().parent.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('bounds_math',B/'tools/animation-skeletal-fixture.py');f=importlib.util.module_from_spec(s);s.loader.exec_module(f);n=f.p.nx.NativeX86();D=n.DATA;SIZE=0x10d8;DATA=D+0x2000;MODEL=D+0x3000;GAME=D+0x4000;INFO=D+0x6800;OUT=D+0x8000;VECTOR=D+0x8100;OTHER=D+0x8200;MATRIX=D+0x8300;calls=[];cases=[];errors=[];counts=collections.Counter();rng=random.Random(0x55d2b0)
from unicorn import UC_HOOK_CODE
for a in [0x55d2b0,0x5b3200,0x5b37d0]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:calls.append(hex(a)),begin=a,end=a)
def sha(b):return hashlib.sha256(b).hexdigest()
def fl(b,p):return struct.unpack_from('<f',b,p)[0]
def u(b,p):return struct.unpack_from('<I',b,p)[0]
def w(b,p,x):struct.pack_into('<I',b,p,x&0xffffffff)
def sf(b,p,x):struct.pack_into('<f',b,p,x)
def store(x):
 v=f.p.x.store(x.w);assert math.isfinite(v)
 return math.copysign(0.,-1 if x.negative else 1)if v==0 and x.w[0]==0 else v
class W:
 def __init__(self,v):self.w=f.p.x.wide(v);self.negative=math.copysign(1.,v)<0
 @staticmethod
 def make(w,negative):r=W(0);r.w=w;r.negative=w[0]<0 or(w[0]==0 and negative);return r
 def __add__(a,b):return W.make(f.p.x.add(a.w,b.w),a.negative and b.negative)
 def __sub__(a,b):return W.make(f.p.x.add(a.w,(-b.w[0],b.w[1])),a.negative and not b.negative)
 def __mul__(a,b):return W.make(f.p.x.mul(a.w,b.w),a.negative!=b.negative)

def direction(v,m):return[store((W(v[0])*W(m[i])+W(v[1])*W(m[4+i]))+W(v[2])*W(m[8+i]))for i in range(3)]
def add(a,b):return[store(W(x)+W(y))for x,y in zip(a,b)]
def model(before,e):
 b=bytearray(before);F=lambda p:W(fl(b,p));dt=W(f.value(e['dt']));flags=u(b,0x1f8)|0x100;w(b,0x1f8,flags);fallback=True;branch='basic';trace=['0x55d2b0'];enabled=e['enabled']
 if b[0x1079]:
  primary=e['primary'];secondary=e['fallback']
  if primary!=-1 and u(b,0x50)!=0 and enabled[primary]:
   fallback=False
   if b[0xe24]&8:
    branch='primary-point';p=0x834+primary*64;sf(b,0x80,store(F(0x74)*dt+F(p)));sf(b,0x84,store((F(0xff4)+F(0xff0))*F(0xa8)*W(.5)+(F(0x78)*dt+F(p+4))));sf(b,0x88,store(F(0x7c)*dt+F(p+8)))
   else:
    branch='rotated-bottom';trace+=['0x5b3200','0x5b37d0'];center=add(direction([0.,-fl(b,0xff0),0.],list(struct.unpack_from('<16f',b,0xb8))),list(struct.unpack_from('<3f',b,0x5c)))
    for i,x in enumerate(center):sf(b,0x80+i*4,x)
   for i in range(3):sf(b,0x80+i*4,store(F(0x74+i*4)*dt+F(0x80+i*4)))
  elif fl(b,0xd30)==1 and secondary!=-1 and enabled[secondary]and b[0x28c]:
   assert u(b,0x50)!=0;branch='fallback-point';fallback=False;b[0x80:0x8c]=b[0x834+secondary*64:0x840+secondary*64]
 if fallback:
  w(b,0x1f8,flags^0x100);sf(b,0x80,store(F(0x74)*dt+F(0x5c)));sf(b,0x84,store((F(0xff4)+F(0xff0))*F(0xa8)*W(.5)+(F(0x78)*dt+F(0x60))));sf(b,0x88,store(F(0x7c)*dt+F(0x64)))
 for out,v in [(0x178,F(0x80)-F(0x1dc)),(0x184,F(0x1dc)+F(0x80)),(0x180,F(0x88)-F(0x1dc)),(0x18c,F(0x1dc)+F(0x88))]:sf(b,out,store(v))
 lo=store(F(0x84)-F(0x1e0));hi=store(F(0x1e0)+F(0x84));sf(b,0x17c,lo);sf(b,0x188,hi)
 for p in [0x190,0x19c,0x1a8]:sf(b,p,store(F(0x74)*dt+F(0x5c)));sf(b,p+8,store(F(0x7c)*dt+F(0x64)))
 sf(b,0x194,hi);sf(b,0x1a0,lo);sf(b,0x1ac,store(F(0x78)*dt+W(lo)));b[0x414:0x420]=b[0x1a8:0x1b4]
 if e['contextFlags']&0x80000 and u(b,0x7bc)&0x800:sf(b,0x418,store(W(store(W(hi)-W(lo)))+F(0x418)));branch+=':upper'
 elif e['contextFlags']&0x100000:b[0x414:0x420]=b[0x5c:0x68];branch+=':position'
 else:
  y=store(F(0x418)-F(0xd7c));sf(b,0x418,y)
  if y<fl(b,0x21c)and (F(0xb4)+F(0x1ac)-F(0x21c)).w[0]>0:b[0x418:0x41c]=b[0x21c:0x220];branch+=':clamped'
  else:branch+=':unclamped'
 return b,trace,branch

registry=json.loads((R/'animation-context-registry.json').read_text())['contexts']
def setup(index,mode,point=None):
 b=bytearray((i*37+index*17)&255 for i in range(SIZE));e=dict(dt=f.bits([0.,1/60,.5,-.25][index%4]),primary=index%16,fallback=(index+3)%16,enabled=[1]*16,contextFlags=[0,0x80000,0x100000,0x180000][index%4]);w(b,0x50,MODEL);w(b,0x54,DATA)
 for p in [0x5c,0x60,0x64,0x74,0x78,0x7c,0xa8,0xb4,0x1dc,0x1e0,0x21c,0xd7c,0xff0,0xff4]:sf(b,p,f.f32(rng.uniform(-32,32)))
 for i in range(16):sf(b,0xb8+i*4,f.f32(rng.uniform(-2,2)))
 for slot in range(16):
  for i in range(16):sf(b,0x804+slot*64+i*4,f.f32(rng.uniform(-16,16)))
 w(b,0x7bc,0x800 if index&4 else 0);b[0x1079]=[1,255,128][index%3];b[0x28c]=1;b[0xe24]=8;sf(b,0xd30,1.);b[0x7b5]=index%100
 if mode==0:b[0x1079]=0
 elif mode==2:b[0xe24]=0
 elif mode==3:e['primary']=-1
 elif mode==4:e['primary']=-1;sf(b,0xd30,0.)
 elif mode==5:e['enabled'][e['primary']]=0
 elif mode==6:w(b,0x50,0);e['fallback']=-1
 elif mode==7:e['primary']=-1;e['enabled'][e['fallback']]=0
 elif mode==8:e['primary']=-1;b[0x28c]=0
 elif mode==9:b[0x1079]=0;w(b,0x54,0)
 if point is not None:
  slot=e['primary']if mode==1 else e['fallback'];raw=struct.pack('<16I',*point['native']);b[0x804+slot*64:0x844+slot*64]=raw
 return b,e

def check(b,e,label):
 want,trace,branch=model(b,e);n.write(D,b);n.pack('<I',DATA+0x24,GAME);n.write(GAME+0x10f,bytes([e['primary']&255]));n.write(GAME+0x10d,bytes([e['fallback']&255]));n.pack('<16I',MODEL+0x14,*e['enabled']);n.pack('<I',0x7fb0e4,INFO);context=struct.unpack_from('<b',b,0x7b5)[0];n.pack('<II',INFO+context*16+8,e['contextFlags'],0x12345678);n.pack('<I',0x925018,e['dt']);external=sha(n.read(DATA,0x6000));calls.clear();n.call(0x55d2b0,[D]);got=n.read(D,SIZE)
 if got!=want or calls!=trace or external!=sha(n.read(DATA,0x6000)):
  err=dict(label=label,branch=branch,offsets=[i for i,(a,c)in enumerate(zip(got,want))if a!=c],trace=calls.copy(),expectedTrace=trace);errors.append(err);print(err);raise AssertionError('bounds mismatch')
 cases.append(dict(kind='bounds',label=label,branch=branch,environment=e,before=base64.b64encode(b).decode(),nativeSha256=sha(got)));counts['bounds']+=1;counts[branch]+=1
for i in range(1200):
 b,e=setup(i,i%10);check(b,e,dict(synthetic=i,mode=i%10))
# Deliberate signed-zero/subnormal and strict wide comparison boundaries.
for i in range(32):
 for mode in [0,1,2,3]:
  b,e=setup(i,mode);e['contextFlags']=0;e['dt']=[0,0x80000000,0x3f800000,0xbf800000][i%4]
  for j,p in enumerate([0x5c,0x60,0x64,0x74,0x78,0x7c,0xa8,0xb4,0x1dc,0x1e0,0x21c,0xd7c,0xff0,0xff4]):w(b,p,[0,0x80000000,1,0x80000001][(i+j)%4])
  for slot in [e['primary'],e['fallback']]:
   for j in range(3):w(b,0x834+slot*64+j*4,[0,0x80000000,1,0x80000001][(i+j)%4])
  check(b,e,dict(boundary='signed-zero-subnormal',index=i,mode=mode))
for exponent in [-65,-64,-63,-62,-60,-54,-53,-52,-25,-24,-23]:
 for directionSign in [-1,1]:
  b,e=setup(exponent,0);e['contextFlags']=0;e['dt']=0
  for p,x in [(0x60,1),(0xff4,0),(0xff0,0),(0x1e0,0),(0xd7c,.5),(0x21c,1),(0xb4,directionSign*2.**exponent)]:sf(b,p,x)
  check(b,e,dict(boundary='wide-clamp-threshold',exponent=exponent,sign=directionSign))
# Every native context's actual low flags, with both POI paths and both branches
# of object context bit800, using complete original function execution.
for ri,row in enumerate(registry):
 for mode in [0,1,2,3]:
  for bit in [0,0x800]:
   b,e=setup(ri*8+mode,mode);b[0x7b5]=row['id']&255;e['contextFlags']=row['flags']&0xffffffff;w(b,0x7bc,bit);check(b,e,dict(context=row['id'],name=row['name'],mode=mode,bit=bit))
# Feed already-native-evaluated authored POI matrices into the exact consumer.
pointPath='reports/animation-points-native-fixtures.json.gz';points=json.loads(gzip.decompress((B/pointPath).read_bytes()));seen=set()
for row in points['cases']:
 if row['kind']!='point':continue
 mi=row['input']['model'];origin=points['models'][mi]['source']
 if 'path'not in origin or mi in seen:continue
 seen.add(mi)
 for mode in [1,3]:b,e=setup(mi,mode,row);check(b,e,dict(source=origin,point=row['input']['point'],mode=mode))
# Direct scalar vector helpers, including in-place native destinations.
for i in range(256):
 v=[f.f32(rng.uniform(-1e4,1e4))for _ in range(3)];m=[f.f32(rng.uniform(-3,3))for _ in range(16)];other=[f.f32(rng.uniform(-1e4,1e4))for _ in range(3)]
 if i<32:v=[f.value([0,0x80000000,1,0x80000001][(i+j)%4])for j in range(3)];m=[float(j%5==0)for j in range(16)]
 for kind in ['direction','add']:
  for alias in [False,True]:
   n.pack('<3f',VECTOR,*v);n.pack('<3f',OTHER,*other);n.pack('<16f',MATRIX,*m);out=VECTOR if alias else OUT;n.call(0x5b3200 if kind=='direction'else 0x5b37d0,[out,VECTOR,MATRIX if kind=='direction'else OTHER]);got=list(n.unpack('<3I',out));want=[f.bits(x)for x in(direction(v,m)if kind=='direction'else add(v,other))];assert got==want,dict(kind=kind,index=i,expected=want,native=got);cases.append(dict(kind=kind,vector=[f.bits(x)for x in v],matrix=[f.bits(x)for x in m],other=[f.bits(x)for x in other],alias=alias,native=got));counts[kind]+=1
fp=R/'animation-character-bounds-native-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')).encode(),mtime=0))
report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),authoredPointModels=len(seen),contextRows=len(registry),mismatches=len(errors),examples=errors,fixture=dict(path=fp.relative_to(B).as_posix(),bytes=fp.stat().st_size,sha256=sha(fp.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in [pointPath,'reports/animation-context-registry.json','tools/animation-skeletal-fixture.py']],method='Unmodified55d2b0 and both actual vector helpers execute without callbacks. Full0x10d8 object bytes, unchanged referenced input memory and nested helper order compared. Separate vector probes include exact in-place destinations. Authored matrix inputs reuse hash-bound earlier native point outputs.',limits=['Finite active math/stores; valid point indices-1 or0..15 and enabled16-slot model data.','Native fallback may dereference a null model for invalid state; portable adapter requires validity when that branch reads the slot.','Point generation and character-data loader are external; resolved model words/context flags supplied explicitly.','No terrain collision query, game/GPU or managed executable launch.'])
(R/'animation-character-bounds-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not errors
