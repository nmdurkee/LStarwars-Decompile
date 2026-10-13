import importlib.util,json,struct,hashlib,base64,random,time
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
B=x.BASE;D=n.DATA; W=D; CR=D+0x6000;ER=CR+4; TABLE=D+0x7000; RECORDS=D+0x8000; NAMES=D+0xa000; STRINGS=D+0xb000; Q=D+0x5000; ARENA=D+0x10000
READONLY=[(0x755424,n.read(0x755424,0x6b4)),(0x7f5dd0,n.read(0x7f5dd0,147*4))]
REGIONS=[(D,0x30000),(0x956618,4),(0x2924910,0x400),(0x2962098,8)]
U=lambda v:v&0xffffffff
S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
class Image:
 def __init__(self,c):
  self.regions={a:bytearray([167])*z for a,z in REGIONS};self.regions.update({a:bytearray(b) for a,b in READONLY})
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
 def byte(self,a):return self.read(a,1)[0]
 def text(self,a):
  out=b''
  while self.byte(a):out+=bytes([self.byte(a)]);a+=1
  return out.decode('ascii')
 def digest(self):return hashlib.sha256(b''.join(self.read(a,z) for a,z in REGIONS)).hexdigest()
class Native:
 def read(self,a,z):return n.read(a,z)
 def write(self,a,v):n.write(a,v)
 def word(self,a,v=None):
  if v is None:return n.unpack('<I',a)[0]
  n.pack('<I',a,U(v))
 def byte(self,a):return n.read(a,1)[0]
 def text(self,a):
  out=b''
  while self.byte(a):out+=n.read(a,1);a+=1
  return out.decode('ascii')
 def digest(self):return hashlib.sha256(b''.join(n.read(a,z) for a,z in REGIONS)).hexdigest()
vm=Native(); current=None; trace=[]; native_calls={}
def service(m,c,kind,args):
 if kind=='exists':
  trace.append(['exists',args[0],m.word(W+0x2a98)]);ops=c.get('existsWrites',[]);ret=c.get('exists',0)
 else:
  trace.append(['load',args[0],args[1],args[2]]);ops=c.get('loadWrites',[]);ret=c.get('handle',0xffffffff)
 for p in ops:m.write(p['address'],base64.b64decode(p['data']))
 return U(ret)
def hook(uc,a,size,data):
 global trace
 sp=uc.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4+4*i)[0]
 if a==0x48d094:uc.reg_write(UC_X86_REG_EIP,n.STOP);return
 if a==0x6e69ef:
  fmt=vm.text(arg(1));assert fmt=='%s.ptl',fmt
  out=vm.text(arg(2))+'.ptl';n.write(arg(0),out.encode()+b'\0');ret=len(out)
 elif a==0x4ff120:ret=service(vm,current,'exists',[vm.text(arg(0))])
 elif a==0x68df20:ret=service(vm,current,'load',[vm.text(arg(0)),arg(1),arg(2)])
 else:native_calls[hex(a)]=native_calls.get(hex(a),0)+1;return
 uc.reg_write(UC_X86_REG_EAX,U(ret));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
for a in [0x48d094,0x6e69ef,0x4ff120,0x68df20,0x552670,0x5a05b0,0x62c400,0x658330,0x658470,0x658490,0x5a8090]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def allocate(m,c,e,z):
 if not c or not e:return 0
 raw=m.word(c)
 if U(raw+z)>=m.word(e):return 0
 dst=U(raw+3)&0xfffffffc;m.word(c,U(dst+z))
 if dst:m.write(dst,b'\0'*z)
 return dst
def aux(m,c,e):
 r=allocate(m,c,e,16)
 if r and m.word(0x956618):m.word(r+12,allocate(m,c,e,U(m.word(0x956618)*4)))
 return r
def resolve(m,q,p,exclude,allgroups):
 if not q:return 0xffffffff
 p&=255
 active=lambda g:m.word(U(0x2924b10+g*4))!=0
 for part in range(3 if allgroups else 2):
  if part==0 and (p>=8 or not active(p)):continue
  for i in range(1,S(m.word(0x2962098))):
   if i==exclude:continue
   r=m.word(m.word(0x296209c)+i*4)
   if not r:continue
   g=m.byte(r+17);sg=g if g<128 else g-256
   ok=(g==p) if part==0 else (g in [0,1] and active(g)) if part==1 else active(sg)
   if ok and m.text(r).lower()==m.text(q).lower():return i
 return 0xffffffff
def cache(m,c,e,cap,num,names,pref):
 h=U(m.word(c)+15)&0xfffffff0;m.word(c,h+12)
 if not h:return 0
 m.word(h+8,0);m.word(h,num);m.word(h+4,cap)
 entries=U(m.word(c)+15)&0xfffffff0;m.word(h+8,entries);m.word(c,U(entries+cap*20))
 if not entries:return 0
 m.write(entries,b'\xff'*(cap*20));written=0
 while written<S(m.word(h)):
  at=m.word(h+8)+written*20;m.write(at+4,m.text(m.word(names+written*4)).encode()+b'\0');m.word(at,0xffffffff)
  m.word(m.word(h+8)+written*20,resolve(m,m.word(h+8)+written*20+4,pref,0,True));written+=1
 scan=1
 while written<S(m.word(h+4)):
  if scan>=S(m.word(0x2962098)):break
  at=m.word(h+8)+written*20;m.word(at,0xffffffff);r=m.word(m.word(0x296209c)+scan*4)
  if r:
   m.write(at+4,m.text(r).encode()+b'\0');m.word(m.word(h+8)+written*20,resolve(m,m.word(h+8)+written*20+4,pref,0,False));written+=1
  scan+=1
 while written<S(m.word(h+4)):m.word(m.word(h+8)+written*20,0xffffffff);written+=1
 return h
def model(m,c):
 a=c['args'];k=c['kind']
 if k=='allocate':return allocate(m,*a)
 if k=='aux':return aux(m,*a)
 if k=='resolve':return resolve(m,a[0],a[1],S(a[2]),True)
 if k=='fast':return resolve(m,a[0],a[1],0,False)
 if k=='cache':return cache(m,a[0],a[1],S(a[2]),S(a[3]),a[4],a[5])
 if k=='composed':
  m.word(W+0x2960,aux(m,W+0x104,W+0x108));a=[W,0x7f5dd0,400,147]
 m.word(W+0x2a98,0xffffffff);path=m.text(W+0x80)+'.ptl'
 if service(m,c,'exists',[path]):m.word(W+0x2a98,service(m,c,'load',[path,1,m.word(W+0x13c)]))
 m.word(W+0x134,cache(m,W+0x104,W+0x108,S(a[2]),S(a[3]),a[1],m.word(W+0x2a98)));return None
VAs={'allocate':0x552670,'aux':0x5a05b0,'resolve':0x658330,'fast':0x658490,'cache':0x62c400,'stage':0x5a8090,'composed':0x48d063}
def patch(a,b):return dict(address=a,data=base64.b64encode(b).decode())
def wordpatch(a,v):return patch(a,struct.pack('<I',U(v)))
def seed(kind,args,cur=ARENA+1,end=ARENA+0x9000,count=0,records=None,active=None,names=None,query='spark'):
 c=dict(kind=kind,args=[U(v) for v in args],writes=[]);ws=c['writes'];ws.extend([wordpatch(CR,cur),wordpatch(ER,end),wordpatch(W+0x104,cur),wordpatch(W+0x108,end),wordpatch(W+0x13c,D+0x4000),wordpatch(0x956618,count),wordpatch(0x296209c,TABLE),patch(0x2924910,bytes(0x400)),patch(W+0x80,b'levels\\prepared\\stage\0'),patch(Q,query.encode()+b'\0')])
 records=records or [];ws.append(wordpatch(0x2962098,len(records)+1));ws.append(wordpatch(TABLE,0))
 for i,r in enumerate(records,1):
  ws.append(wordpatch(TABLE+i*4,0 if r is None else RECORDS+i*32))
  if r is not None:ws.extend([patch(RECORDS+i*32,r[0].encode()+b'\0'),patch(RECORDS+i*32+17,bytes([r[1]&255]))])
 for group,value in (active or {}).items():ws.append(wordpatch(U(0x2924b10+group*4),value))
 for i,name in enumerate(names or []):ws.extend([wordpatch(NAMES+i*4,STRINGS+i*32),patch(STRINGS+i*32,name.encode()+b'\0')])
 return c
cases=[]
for mis in range(4):
 for z in [0,1,2,3,4,7,16,31]:
  for extra in [-1,0,1,2,3,4]:cases.append(seed('allocate',[CR,ER,z],ARENA+mis,ARENA+mis+z+extra))
for null in [(0,ER),(CR,0),(0,0)]:cases.append(seed('allocate',[*null,16]))
for raw in [0xfffffffd,0xfffffffe,0xffffffff]:cases.append(seed('allocate',[CR,ER,4],raw,16))
for mis in range(4):
 for count in [0,1,2,7,16,0x40000000,0x40000001]:
  for space in [15,16,17,19,20,24,32,128]:cases.append(seed('aux',[CR,ER],ARENA+mis,ARENA+mis+space,count))
rng=random.Random(0x658330)
for j in range(320):
 records=[None if rng.randrange(6)==0 else (rng.choice(['spark','SPARK','smoke','flare','other','']),rng.choice([0,1,2,3,7,8,127,128,255])) for i in range(rng.randrange(0,12))]
 active={g:rng.choice([0,0,1,0xffffffff]) for g in [0,1,2,3,7,8,127,-128,-1]}
 q=rng.choice(['spark','SpArK','smoke','missing','']);pref=rng.choice([0,1,2,3,7,8,255,0x102]);exc=rng.choice([-1,0,1,2,5,11]);query=0 if j%19==0 else Q
 for kind,args in [('resolve',[query,pref,exc]),('fast',[query,pref])]:cases.append(seed(kind,args,records=records,active=active,query=q))
for j in range(180):
 cap=rng.randrange(0,14);num=rng.choice([-3,0,1,2,cap,cap+2]);names=[rng.choice(['spark','SPARK','missing','smoke','123456789012345']) for i in range(max(0,num))]
 records=[None if rng.randrange(5)==0 else (rng.choice(['spark','SPARK','smoke','flare']),rng.randrange(8)) for i in range(rng.randrange(12))]
 active={g:rng.randrange(2) for g in range(8)};pref=rng.choice([0,1,2,5,7,255]);cases.append(seed('cache',[CR,0 if j%3==0 else ER,cap,num,NAMES,pref],ARENA+j%16,ARENA-100,records=records,active=active,names=names))
# Original 147 authored name literals, relocated as input strings without decoding or editing them.
original_names=[vm.text(n.unpack('<I',0x7f5dd0+i*4)[0]) for i in range(147)]
assert max(map(len,original_names))<=15
for pref in [0,2,255]:cases.append(seed('cache',[CR,ER,400,147,NAMES,pref],records=[(original_names[i],i%8) for i in range(12)],active={g:1 for g in range(8)},names=original_names))
for raw in [0xfffffff1,0xffffffff]:cases.append(seed('cache',[CR,ER,0,0,NAMES,255],raw,0))
for j in range(120):
 cap=rng.randrange(1,14);num=rng.randrange(cap+1);records=[('spark',2),('SPARK',0),None,('smoke',1),('flare',7)];names=[rng.choice(['spark','missing','smoke']) for i in range(num)]
 c=seed('stage',[W,NAMES,cap,num],ARENA+j%16,ARENA-4,records=records,active={0:1,1:1,2:0,7:1},names=names);c['exists']=[0,1,0xffffffff][j%3];c['handle']=[2,0xffffffff,0x102][j%3]
 if j%4==0:c['existsWrites']=[wordpatch(W+0x13c,D+0x4020)]
 if j%5==0:c['loadWrites']=[wordpatch(0x2924b18,1),wordpatch(W+0x104,ARENA+0x20),wordpatch(W+0x13c,D+0x4040)]
 cases.append(c)
for j in range(24):
 c=seed('composed',[],ARENA+j%16,ARENA+[15,16,17,64,10000][j%5],count=[0,1,7,0x40000000][j%4],records=[(original_names[i],i%8) for i in range(12)],active={g:1 for g in range(8)});c['exists']=j%2;c['handle']=[2,255,0x102][j%3];cases.append(c)
start=time.time();fail=[];counts={};results=[]
for i,c in enumerate(cases):
 current=c;m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 trace=[];ret=n.call(VAs[c['kind']],c['args'],regs={x.UC_X86_REG_ESI:W} if c['kind']=='composed' else None,count=4000000);observed=dict(result=None if c['kind'] in ['stage','composed'] else ret,sha256=vm.digest(),trace=trace.copy())
 trace=[];expected=model(m,c);prediction=dict(result=expected,sha256=m.digest(),trace=trace.copy())
 if observed!=prediction:
  fail.append(dict(case=i,kind=c['kind'],observed=observed,prediction=prediction));print(json.dumps(fail[-1]));break
 c['expected']=observed;results.append(c);counts[c['kind']]=counts.get(c['kind'],0)+1
out=dict(binarySha256=n.sha256,cases=len(results),mismatches=len(fail),byKind=counts,nativeEntryCalls=native_calls,seconds=round(time.time()-start,3),failures=fail)
(B/'reports/world-phase6-20261013-native-tests.json').write_text(json.dumps(out,indent=2)+'\n')
if not fail:
 (B/'reports/world-phase6-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z) for a,z in REGIONS],readOnlyRegions=[patch(a,b) for a,b in READONLY],originalNameTableAddress=0x7f5dd0,originalNames=original_names,cases=results),separators=(',',':'))+'\n')
print(json.dumps(out));assert not fail
