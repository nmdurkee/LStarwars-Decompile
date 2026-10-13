"""Original legacy shadow scheduler/direction helpers, explicit shape boundary."""
from pathlib import Path
import importlib.util,ast,struct,json,gzip,base64,hashlib,random,math,collections
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def load(name,p):
 spec=importlib.util.spec_from_file_location(name,B/'tools'/p);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
f=load('legacy_shadow_math','animation-skeletal-fixture.py');angle=load('legacy_shadow_angles','gameplay-path-angle-verify.py');n=f.p.nx.NativeX86();D=n.DATA;QUEUE=0x9666b0;CIRCLE=0x9715b0;SIZE=29120;cases=[];counts=collections.Counter();rng=random.Random(0x5e4840)
wide={'f':f,'math':math}
path=B/'tools/animation-character-bounds-verify.py'
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.ClassDef)and node.name=='W'or isinstance(node,ast.FunctionDef)and node.name=='store':exec(compile(ast.Module(body=[node],type_ignores=[]),'legacy-shadow-wide','exec'),wide)
W=wide['W'];S=wide['store'];bits=f.bits;value=f.value
def sha(b):return hashlib.sha256(b).hexdigest()
def words(v):return [bits(x)for x in v]
def raw(v):return struct.pack('<'+'f'*len(v),*v)
def fl(b,p):return struct.unpack_from('<f',b,p)[0]
def u(b,p):return struct.unpack_from('<I',b,p)[0]
def p32(b,p,v):struct.pack_into('<I',b,p,v&0xffffffff)
def sf(b,p,v):struct.pack_into('<f',b,p,v)
sinePath=B/'references/native-animation-sine-table.f32';sineRaw=sinePath.read_bytes();sine=struct.unpack('<32768f',sineRaw);n.write(0x29899a0,sineRaw);table=list(struct.unpack('<513H',n.read(0x8066c8,1026)));assert table==list(angle.TABLE)
def angles(v):return [float(angle.direction(-v[1],f.f32(math.sqrt(S(W(v[0])*W(v[0])+W(v[2])*W(v[2])))))),float(angle.direction(v[0],v[2]))]
def rotate(v,pitch,yaw):
 sp=W(sine[(int(pitch)>>1)&32767]);cp=W(sine[(int(pitch+16384)>>1)&32767]);sy=W(sine[(int(yaw)>>1)&32767]);cy=W(sine[(int(yaw+16384)>>1)&32767]);x,y,z=map(W,v);projected=W(S(cp*z+sp*y))
 return [S(projected*sy+cy*x),S(y*cp-sp*z),S(cy*projected-sy*x)]
def prepare(v):
 pitch,yaw=angles(v);pitch=max(8192.,pitch);x,y,z=map(W,v);length=f.f32(math.sqrt(S(y*y+x*x+z*z)));out=rotate([0.,0.,length],pitch,yaw);circle=[rotate([sine[((i*8192+16384)>>1)&32767],-sine[i*4096],0.],pitch,yaw)for i in range(8)];return out,circle
trace=[];events=[]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
def boundary(mu,a,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==0x5e2920:resource,record,direction=n.unpack('<3I',sp+4);event=dict(entry=a,record=(record-QUEUE)//104,resource=resource,direction=list(n.unpack('<3I',direction)))
 elif a==0x5e3b50:
  resource,record,direction,upper,lower=n.unpack('<5I',sp+4);event=dict(entry=a,record=(record-QUEUE)//104,resource=resource,direction=list(n.unpack('<3I',direction)),upper=upper,lower=lower)
 else:
  record,first,second,direction=n.unpack('<4I',sp+4);event=dict(entry=a,record=(record-QUEUE)//104,first=first,second=second,direction=list(n.unpack('<3I',direction)))
 events.append(event);n.pack('<I',0x971878,(n.unpack('<I',0x971878)[0]+(a&255)+1)&0xffffffff);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret);mu.reg_write(UC_X86_REG_EAX,0)
for a in [0x5e2920,0x5e3b50,0x5e4280]:n.mu.hook_add(UC_HOOK_CODE,boundary,begin=a,end=a)
for a in [0x5e4600,0x5e4670,0x5e4740,0x5c0240]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,s,u:trace.append(a),begin=a,end=a)
def model(queue,count,camera,pairs,circle):
 last=-1;accepted=False;direction=None;upper=1e7;lower=-1e7;out=[];preparations=0;discardedRoots=0
 for i in range(max(0,count)):
  p=i*104;sequence=queue[p+103]
  if sequence!=last:
   last=sequence;upper=1e7;lower=-1e7;x,y,z=[W(fl(queue,p+48+j*4))-W(camera[j])for j in range(3)];distance=S(y*y+x*x+z*z);maximum=fl(queue,p+96);fade=fl(queue,p+92);accepted=distance<maximum*maximum
   if not accepted:continue
   if fl(queue,p+76)>=65536:
    direction,circle=prepare([0.,-1.,0.]);direction[1]=-4.;upper=fl(queue,p+80);lower=fl(queue,p+84)
   else:direction,circle=prepare([fl(queue,p+76+j*4)for j in range(3)]);direction=[S(W(x)*W(4))for x in direction]
   preparations+=1;discardedRoots+=fade*fade<distance
  if not accepted:continue
  for resourceOffset,countOffset,stride,entry in [(68,101,64,0x5e2920),(64,100,48,0x5e3b50)]:
   resource=u(queue,p+resourceOffset)
   if resource:
    for j in range(queue[p+countOffset]):
     event=dict(entry=entry,record=i,resource=(resource+j*stride)&0xffffffff,direction=words(direction))
     if entry==0x5e3b50:event.update(upper=bits(upper),lower=bits(lower))
     out.append(event)
  resource=u(queue,p+72)
  if resource:
   for j in range(queue[p+102]):out.append(dict(entry=0x5e4280,record=i,first=pairs[str(resource)][0],second=pairs[str(resource)][1],direction=words(direction)))
 return dict(events=out,circle=[words(r)for r in circle],generated=sum((v['entry']&255)+1 for v in out)&0xffffffff,prepareCalls=preparations,rootCalls=preparations*2+discardedRoots)
def checkDirect(kind,v,pitch=0.,yaw=0.,origin=None):
 before=bytes((i*37+11)&255 for i in range(256));n.write(D,before);n.write(D+32,raw(v));initialCircle=raw([float(i-12)for i in range(24)]);n.write(CIRCLE,initialCircle);trace.clear()
 if kind=='angles':n.call(0x5e4600,[D+32,D+64,D+68]);want=angles(v);got=list(n.unpack('<2I',D+64));expected=words(want);after=bytearray(before);after[32:44]=raw(v);after[64:72]=raw(want)
 elif kind=='rotate':n.call(0x5e4670,[D+32,bits(pitch),bits(yaw)]);want=rotate(v,pitch,yaw);got=list(n.unpack('<3I',D+32));expected=words(want);after=bytearray(before);after[32:44]=raw(want)
 else:
  n.call(0x5e4740,[D+32]);want,circle=prepare(v);got=list(n.unpack('<3I',D+32));expected=words(want);after=bytearray(before);after[32:44]=raw(want)
  assert n.read(CIRCLE,96)==b''.join(raw(r)for r in circle),(kind,v,'circle',list(n.unpack('<24I',CIRCLE)),[bits(x)for r in circle for x in r])
 if got!=expected or n.read(D,256)!=after:raise AssertionError(dict(kind=kind,input=v,pitch=pitch,yaw=yaw,native=got,expected=expected))
 if kind!='prepare':assert n.read(CIRCLE,96)==initialCircle
 record=dict(kind=kind,vector=words(v),pitch=bits(pitch),yaw=bits(yaw),native=got)
 if kind=='prepare':record['circle']=[words(r)for r in circle]
 if origin is not None:record['source']=origin
 cases.append(record);counts[kind]+=1
def checkQueue(queue,count,camera,pairs,origin):
 circle=[[float(i*3+j-12)for j in range(3)]for i in range(8)];want=model(queue,count,camera,pairs,circle);n.write(QUEUE,queue);n.pack('<i',0x973fe8,count);n.pack('<3f',0x973718,*camera);n.pack('<I',0x971878,0xa5a5a5a5);n.write(CIRCLE,b''.join(raw(r)for r in circle))
 for p,v in pairs.items():n.pack('<2I',int(p),*v)
 trace.clear();events.clear();n.call(0x5e4840,count=10000000)
 actual=dict(events=events.copy(),circle=[list(n.unpack('<3I',CIRCLE+i*12))for i in range(8)],generated=n.unpack('<I',0x971878)[0],prepareCalls=trace.count(0x5e4740),rootCalls=trace.count(0x5c0240))
 assert n.read(QUEUE,SIZE)==queue and n.unpack('<i',0x973fe8)[0]==count and n.read(0x973718,12)==raw(camera)
 if actual!=want:
  (R/'animation-shadow-consumer-debug.json').write_text(json.dumps(dict(source=origin,native=actual,expected=want),indent=2));raise AssertionError('legacy shadow consumer mismatch '+str(origin))
 cases.append(dict(kind='queue',source=origin,queueZ=base64.b64encode(gzip.compress(queue,mtime=0)).decode(),count=count,camera=words(camera),pairs=pairs,native=actual));counts['queue']+=1;counts['shapeCalls']+=len(events);counts['preparations']+=actual['prepareCalls'];counts['discardedRoots']+=actual['rootCalls']-actual['prepareCalls']*2
for i in range(512):
 v=[f.f32(rng.uniform(-100,100))for j in range(3)];pitch=f.f32(rng.uniform(-100000,100000));yaw=f.f32(rng.uniform(-100000,100000))
 for kind in ['angles','rotate','prepare']:checkDirect(kind,v,pitch,yaw)
for i in range(64):
 v=[value([0,0x80000000,1,0x80000001][(i>>j*2)&3])for j in range(3)]
 for kind in ['angles','rotate','prepare']:checkDirect(kind,v,[-0.,0.,8192.,16384.,32768.,49152.,65536.,-16384.][i%8],float(i*1024))
for a in [-2147483648.,-65536.,-16384.,-8192.,-1.,0.,1.,8192.,16384.,65536.,2147467136.]:
 for step in [-1,0,1]:
  vbits=bits(a);v=value(vbits+step)if vbits+step>=0 else 0.
  if math.isfinite(v)and -2147483648<=v and v+16384<2147483648:checkDirect('rotate',[1.,-2.,3.],v,v)
catalog=json.loads(gzip.decompress((R/'animation-shadow-queue-native-fixtures.json.gz').read_bytes()));bound=[r for r in catalog['rigs']if 'path'in r['source']and r['bindings']is not None]
for ri,r in enumerate(bound):
 records=r['bindings'][:-1];pairs={};sourceRaw=(B/'extracted'/r['source']['path']).read_bytes();assert sha(sourceRaw)==r['source']['sha256'];queue=bytearray(b'\xa5'*SIZE)
 for i,binding in enumerate(records):
  p=i*104;joints=r['joints'][binding[6]];queue[p:p+64]=struct.pack('<16I',*joints);pointers=binding[:3]
  if pointers[2]:pair=D+0x1000+i*16;pairs[str(pair)]=list(struct.unpack_from('<2I',sourceRaw,pointers[2]));pointers=[pointers[0],pointers[1],pair]
  struct.pack_into('<3I',queue,p+64,*pointers);queue[p+100:p+103]=bytes(binding[3:6]);queue[p+103]=i&255
  for j,v in enumerate([1.,-3.,2.]):sf(queue,p+76+j*4,v)
  sf(queue,p+92,0.);sf(queue,p+96,1e6);checkDirect('prepare',[value(joints[12]),value(joints[13]),value(joints[14])],origin=dict(r['source'],joint=binding[6]))
 for mode in range(3):
  b=bytearray(queue)
  for i in range(len(records)):
   p=i*104
   if mode==1:sf(b,p+76,65536.);sf(b,p+80,12.);sf(b,p+84,-8.);b[p+103]=(i//2)&255
   if mode==2:sf(b,p+96,0.);b[p+103]=7
  checkQueue(b,len(records),[1.,2.,3.],pairs,dict(r['source'],mode=mode,authoredGroups=len(records)))
 if ri%50==0:print('authored queue rigs',ri,'cases',len(cases),flush=True)
for i in range(192):
 count=[0,-1,1,2,3,8,33,280][i%8];queue=bytearray(b'\xa5'*SIZE);pairs={}
 for j in range(max(0,count)):
  p=j*104;queue[p:p+64]=raw(f.IDENTITY);pos=[0.,0.,0.]if i%4==0 else[float(j%7),-2.,3.];queue[p+48:p+60]=raw(pos);first=0 if i%7==0 else D+0x20000+j*192;second=0 if i%11==0 else D+0x40000+j*256;pair=D+0x1000+j*16;pairs[str(pair)]=[0xabcdef01+j,0x80000000-j];struct.pack_into('<3I',queue,p+64,first,second,0 if i%13==0 else pair)
  direction=[65536.,12.,-7.]if i%3==0 else [0.,-1.,0.]if i%3==1 else[f.f32(rng.uniform(-12,12))for k in range(3)];queue[p+76:p+88]=raw(direction);sf(queue,p+92,[-1.,0.,3.,10.][i%4]);sf(queue,p+96,[0.,1.,3.,math.sqrt(13),5.,-5.,100000.][(i+j)%7]);queue[p+100:p+103]=bytes([j%4,(j+1)%3,(j+2)%4]);queue[p+103]=([j,j//2,255,0][i%4])&255
 checkQueue(queue,count,[0.,0.,0.],pairs,dict(synthetic=i,groupMode=i%4))
for radiusWord in [bits(5.)-1,bits(5.),bits(5.)+1,bits(-5.)-1,bits(-5.),bits(-5.)+1]:
 for marker in [bits(65536.)-1,bits(65536.),bits(65536.)+1]:
  for grouped in [False,True]:
   b=bytearray(b'\xa5'*SIZE);pairs={}
   for j in range(3):
    p=j*104;b[p:p+64]=raw(f.IDENTITY);b[p+48:p+60]=raw([[3.,4.,0.],[0.,0.,0.],[20.,0.,0.]][j]);struct.pack_into('<3I',b,p+64,D+0x20000,D+0x40000,0);p32(b,p+76,marker);sf(b,p+80,-0.);sf(b,p+84,0.);sf(b,p+92,5.);p32(b,p+96,radiusWord);b[p+100:p+103]=bytes([1,1,0]);b[p+103]=255 if grouped else(j+254)&255
   checkQueue(b,3,[0.,0.,0.],pairs,dict(boundary='radius-marker-sequence',radiusWord=radiusWord,marker=marker,grouped=grouped))
fixture=R/'animation-shadow-consumer-native-fixtures.json.gz';fixture.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,sine=dict(path=str(sinePath.relative_to(B)),sha256=sha(sineRaw)),angleTable=table,cases=cases),separators=(',',':')).encode(),mtime=0))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
assembly=[]
for address,size in [(0x5e4600,0x6b),(0x5e4670,0xcf),(0x5e4740,0xfc),(0x5e4840,0x28b)]:
 data=n.read(address,size);assembly.append(dict(address=hex(address),size=size,sha256=sha(data),instructions=[dict(address=hex(v.address),mnemonic=v.mnemonic,operands=v.op_str)for v in Cs(CS_ARCH_X86,CS_MODE_32).disasm(data,address)]))
(R/'animation-shadow-consumer-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,windows=assembly),indent=2)+'\n')
dependencies=['tools/animation-skeletal-fixture.py','tools/animation-x87.py','tools/animation-character-bounds-verify.py','tools/gameplay-path-angle-verify.py','reports/animation-shadow-queue-native-fixtures.json.gz',str(sinePath.relative_to(B))]
report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),authoredBindingRigs=len(bound),authoredGroups=sum(len(r['bindings'])-1 for r in bound),mismatches=0,fixture=dict(path=str(fixture.relative_to(B)),bytes=fixture.stat().st_size,sha256=sha(fixture.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Original scheduler and all direction, angle-table and square-root helpers execute. Only three shape-generation services are supplied at exact native call boundaries; they record arguments and apply a deterministic GeneratedValue increment. Compare exact output words, ring, callback order/arguments, total, direction/root-call counts and untouched queue/camera backing. Direct helper checks replace no computational callbacks.',limits=['Finite vector/metadata values and finite stored squares; rotation angle plus16384 integral part must fit signedInt32. No NaN/Infinity or arbitrary out-of-range conversion claim.','Queue count is backed and at most280; nonpositive counts return after resetting GeneratedValue. Adjacent equal sequence bytes intentionally reuse acceptance, direction and upper/lower values.','Shape service implementations5e2920/5e3b50/5e4280 are not recovered here. Authored bindings retain original count/topology; ellipse/cylinder pointers and pair words are opaque service identities, not runtime object hydration.','Managed compilation/replay preparation only; no managed executable or live graphics device launch.'])
(R/'animation-shadow-consumer-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
