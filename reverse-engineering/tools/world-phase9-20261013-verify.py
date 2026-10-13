import importlib.util,json,struct,hashlib,base64,random,time
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_EBX,UC_X86_REG_ESI
B=x.BASE;D=n.DATA;WORLD=D;CR=D+0x6000;ER=CR+4;REG=D+0x8000;ALT=REG+0x20;DESC=D+0x9000;DESC2=D+0xb000;ARENA=D+0x10000;A=n.STOP+0x100;C=n.STOP+0x120
REGIONS=[(D,0x30000),(0x93b268,4),(0x802724,4)];U=lambda v:v&0xffffffff;S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
class Image:
 def __init__(self,c):
  self.regions={a:bytearray([167])*z for a,z in REGIONS}
  for p in c['writes']:self.write(p['address'],base64.b64decode(p['data']))
 def read(self,a,z):
  for p,b in self.regions.items():
   if p<=a and a+z<=p+len(b):return bytes(b[a-p:a-p+z])
  raise ValueError(hex(a))
 def write(self,a,v):
  for p,b in self.regions.items():
   if p<=a and a+len(v)<=p+len(b):b[a-p:a-p+len(v)]=v;return
  raise ValueError(hex(a))
 def word(self,a,v=None):
  if v is None:return struct.unpack('<I',self.read(a,4))[0]
  self.write(a,struct.pack('<I',U(v)))
 def digest(self):return hashlib.sha256(b''.join(self.read(a,z) for a,z in REGIONS)).hexdigest()
class Native(Image):
 def __init__(self):pass
 def read(self,a,z):return n.read(a,z)
 def write(self,a,b):n.write(a,b)
vm=Native();current=None;trace=[];calls={}
def callback(m,code,world,descriptor,entry):
 index=(descriptor-DESC)//156;which='count' if code==A else 'state';key=str(index)+':'+which;opts=current.get('callbacks',{}).get(key,{})
 ret=U(opts.get('result',current.get('counts',[0]*10)[index] if code==A else 0xb000+index));registry=m.word(0x93b268)
 trace.append([code,world,descriptor,entry,m.word(CR),m.word(ER),registry,m.word(registry),ret])
 for p in opts.get('writes',[]):m.write(p['address'],base64.b64decode(p['data']))
 return ret
def hook(uc,a,z,data):
 if a not in [A,C]:calls[hex(a)]=calls.get(hex(a),0)+1;return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=callback(vm,a,n.unpack('<I',sp+4)[0],uc.reg_read(UC_X86_REG_EBX),uc.reg_read(UC_X86_REG_ESI));uc.reg_write(UC_X86_REG_EAX,ret);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
for a in [A,C,0x559610,0x5598e0,0x559570,0x59a620,0x59a6b0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def allocate(m,c,e,size):
 if not c or not e:return 0
 raw=m.word(c)
 if U(raw+size)>=m.word(e):return 0
 at=U(raw+15)&0xfffffff0;m.word(c,at+size);zero(m,at,size);return at
# Zero-size clears cannot touch destination0; Image intentionally has no mapping there.
def zero(m,a,size):
 if size:m.write(a,bytes(size))
def pool(m,world,c,e,capacity):
 header=U(m.word(c)+15)&0xfffffff0;m.word(c,header);slots=U(capacity*64);size=U(slots+24)
 if capacity==0 or U(header+size)>m.word(e):return 0
 zero(m,header,size);items=m.word(c)+24;m.word(c,items);m.word(header,items);m.word(header+16,capacity);m.word(header+12,world);m.word(header+8,items);previous=items
 for i in range(1,max(1,S(U(capacity-1)))):
  nxt=m.word(header)+i*64;m.word(previous+56,nxt);previous=nxt
 m.word(c,m.word(c)+slots);return header
def release(m,header,node):
 if not header or not node:return
 at=m.word(header+4)
 if not at:return
 if at==node:m.word(header+4,m.word(node+56));m.word(node+56,m.word(header+8));m.word(header+20,m.word(header+20)-1);m.word(header+8,node);return
 while m.word(at+56):
  nxt=m.word(at+56)
  if nxt==node:m.word(at+56,m.word(node+56));m.word(node+56,m.word(header+8));m.word(header+8,node);break
  at=nxt
 m.word(header+20,m.word(header+20)-1)
def dispatch(m,world,c,e):
 if not m.word(0x93b268) or not c or not e:return 0
 if U(m.word(c)+12)>=m.word(e):return 0
 header=U(m.word(c)+15)&0xfffffff0;m.word(c,header+12)
 for off in [0,4,8]:m.word(header+off,0)
 rows=allocate(m,c,e,U(m.word(m.word(0x93b268))*20));m.word(header,rows)
 if rows:
  descriptor=m.word(m.word(0x93b268)+8);entry=rows;index=0
  while index<S(m.word(m.word(0x93b268))):
   m.word(entry,descriptor);cb=m.word(descriptor+44)
   if cb:m.word(entry+8,callback(m,cb,world,descriptor,entry))
   count=m.word(entry+8)
   if count:m.word(entry+12,allocate(m,c,e,U(count*8)))
   cb=m.word(descriptor+136)
   if cb:m.word(entry+16,callback(m,cb,world,descriptor,entry))
   index+=1;entry+=20;descriptor+=156
 extra=m.word(0x802724)
 if extra:m.word(header+4,allocate(m,c,e,extra))
 return header
def model(m,c):
 a=c['args']
 if c['kind']=='allocate':return allocate(m,*a)
 if c['kind']=='pool':return pool(m,a[0],a[1],a[2],S(a[3]))
 if c['kind']=='dispatch':return dispatch(m,*a)
 for i in range(c.get('repeat',1)):release(m,*a)
 return None
def patch(a,b):return dict(address=a,data=base64.b64encode(b).decode())
def wp(a,v):return patch(a,struct.pack('<I',U(v)))
def seed(kind,args,mis=0,space=0x8000,count=3,extra=0,counts=None):
 c=dict(kind=kind,args=[U(v) for v in args],counts=counts or [0]*10,writes=[wp(CR,ARENA+mis),wp(ER,ARENA+mis+space),wp(0x93b268,REG),wp(0x802724,extra),wp(REG,count),wp(REG+8,DESC),wp(ALT,2),wp(ALT+8,DESC2)])
 for i in range(10):c['writes'].extend([wp(DESC+i*156+44,A),wp(DESC+i*156+136,C),wp(DESC2+i*156+44,A),wp(DESC2+i*156+136,C)])
 return c
cases=[]
for mis in range(16):
 for size in [0,1,4,16,31]:
  for delta in [-1,0,1,7,15,16]:cases.append(seed('allocate',[CR,ER,size],mis,size+delta))
for pair in [(0,ER),(CR,0),(0,0)]:cases.append(seed('allocate',[*pair,16]))
for raw in [0xfffffff1,0xfffffffd]:
 c=seed('allocate',[CR,ER,0]);c['writes'].extend([wp(CR,raw),wp(ER,0xffffffff)]);cases.append(c)
for mis in range(16):
 for capacity in [0,1,2,3,4,8,64]:
  size=capacity*64+24;aligned=(ARENA+mis+15)&0xfffffff0
  for delta in [-1,0,1]:
   c=seed('pool',[WORLD,CR,ER,capacity],mis);c['writes'].append(wp(ER,aligned+size+delta));cases.append(c)
for capacity in [0xc0000000,0xc0000001]:cases.append(seed('pool',[WORLD,CR,ER,capacity]))
for raw in [0xfffffff1,0xffffffff]:
 c=seed('pool',[WORLD,CR,0,0]);c['writes'].append(wp(CR,raw));cases.append(c)
for length in range(6):
 for requested in [0,1,2,4,7,-1]:
  for repeat in [1,2]:
   c=seed('release',[ARENA,0 if requested==-1 else ARENA+24+requested*64]);c['repeat']=repeat;c['writes'].extend([wp(ARENA+4,ARENA+24 if length else 0),wp(ARENA+8,ARENA+24+6*64),wp(ARENA+20,length if repeat==1 else 0)])
   for i in range(8):c['writes'].append(wp(ARENA+24+i*64+56,ARENA+24+(i+1)*64 if i+1<length else 0))
   cases.append(c)
c=seed('release',[0,ARENA+24]);cases.append(c)
rng=random.Random(0x5598e0)
for i in range(280):
 count=rng.randrange(0,7);counts=[rng.choice([0,1,3,5,0x20000000,0x20000001]) for j in range(10)];c=seed('dispatch',[WORLD,CR,ER],i%16,rng.choice([0,12,13,28,44,128,300,0x8000]),count,rng.choice([0,1,16,64]),counts)
 for j in range(count):
  if rng.randrange(3)==0:c['writes'].append(wp(DESC+j*156+44,0))
  if rng.randrange(3)==0:c['writes'].append(wp(DESC+j*156+136,0))
 cases.append(c)
for missing in [(0,ER),(CR,0),(0,0)]:cases.append(seed('dispatch',[WORLD,*missing]))
c=seed('dispatch',[WORLD,0,0]);c['writes'].append(wp(0x93b268,0));cases.append(c)
for count in [0x80000000,0]:cases.append(seed('dispatch',[WORLD,CR,ER],count=count,extra=16))
for mutation in range(8):
 for mis in [0,1,7,15]:
  c=seed('dispatch',[WORLD,CR,ER],mis,count=1 if mutation==1 else 3,extra=16,counts=[0]*10);writes=[]
  if mutation==0:writes=[wp(REG,0)]
  elif mutation==1:writes=[wp(REG,3)]
  elif mutation==2:writes=[wp(0x93b268,ALT)]
  elif mutation==3:writes=[wp(REG+8,DESC2)]
  elif mutation==4:writes=[wp(DESC+136,0)]
  elif mutation==5:writes=[wp(ER,ARENA+100)]
  elif mutation==6:writes=[wp(CR,ARENA+0x400)]
  else:writes=[wp(0x802724,31)]
  c['callbacks']={'0:count':dict(result=2 if mutation in [4,5,6] else 0,writes=writes)};cases.append(c)
VAs={'allocate':0x559610,'pool':0x59a620,'release':0x59a6b0,'dispatch':0x5598e0};start=time.time();rows=[];fails=[];bykind={}
for i,c in enumerate(cases):
 current=c;m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 trace=[];ret=0
 for j in range(c.get('repeat',1)):ret=n.call(VAs[c['kind']],c['args'],count=3000000)
 observed=dict(result=None if c['kind']=='release' else ret,sha256=vm.digest(),trace=trace.copy())
 trace=[];expected=model(m,c);predicted=dict(result=expected,sha256=m.digest(),trace=trace.copy())
 if observed!=predicted:fails.append(dict(case=i,kind=c['kind'],observed=observed,prediction=predicted));print(json.dumps(fails[-1]));break
 c['expected']=observed;rows.append(c);bykind[c['kind']]=bykind.get(c['kind'],0)+1
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(fails),byKind=bykind,nativeEntryCalls=calls,seconds=round(time.time()-start,3),failures=fails)
(B/'reports/world-phase9-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fails:(B/'reports/world-phase9-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z) for a,z in REGIONS],cases=rows),separators=(',',':'))+'\n')
print(json.dumps(report));assert not fails
