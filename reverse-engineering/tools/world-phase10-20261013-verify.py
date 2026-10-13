import importlib.util,json,struct,hashlib,base64,random,time
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_EBX,UC_X86_REG_ESI
B=x.BASE;D=n.DATA;WORLD=D;CR=D+0x6000;ER=CR+4;REG=D+0x8000;ALT=REG+0x20;DESC=D+0x9000;DESC2=D+0xb000;ARENA=D+0x10000;A=n.STOP+0x100;C=n.STOP+0x120
REGIONS=[(D,0x30000),(0x2913a58,128*376),(0x8101b8,4),(0x950ff8,8)];U=lambda v:v&0xffffffff;S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
class Image:
 def __init__(self,c):
  self.regions={a:bytearray([0 if a==0x2913a58 else 167])*z for a,z in REGIONS}
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
vm=Native();current=None;trace=[];calls={};RECORDS=0x2913a58;TABLE=D+0x7000;STRINGS=D+0x8000;Q=D+0x5000;LEVEL=D+0x4000
class NativeText(Native):
 def text(self,a):
  out=b''
  while self.read(a,1)!=b'\0':out+=self.read(a,1);a+=1
  return out.decode('ascii')
vm=NativeText()
def service(m,kind,args):
 if kind=='exists':trace.append(['exists',args[0],m.word(WORLD+0x2a9c),m.word(0x8101b8)]);ret=current.get('exists',0);writes=current.get('existsWrites',[])
 else:trace.append(['load',args[0],args[1],args[2]]);ret=current.get('handle',0xffffffff);writes=current.get('loadWrites',[])
 for p in writes:m.write(p['address'],base64.b64decode(p['data']))
 return U(ret)
def text(m,a):
 out=b''
 while m.read(a,1)!=b'\0':out+=m.read(a,1);a+=1
 return out.decode('ascii')
def hook(uc,a,z,data):
 sp=uc.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4+i*4)[0]
 if a==0x6e69ef:
  assert vm.text(arg(1))=='%s.par';out=vm.text(arg(2))+'.par';n.write(arg(0),out.encode()+b'\0');ret=len(out)
 elif a==0x4ff120:ret=service(vm,'exists',[vm.text(arg(0))])
 elif a==0x64c6c0:ret=service(vm,'load',[vm.text(arg(0)),arg(1),arg(2)])
 else:calls[hex(a)]=calls.get(hex(a),0)+1;return
 uc.reg_write(UC_X86_REG_EAX,ret);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
for a in [0x6e69ef,0x4ff120,0x64c6c0,0x64b020,0x571890,0x571a50,0x6489c0,0x4f8b80,0x4f2130]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def eq16(m,q,r,fold):
 for i in range(16):
  a=m.read(q+i,1)[0];b=m.read(r+i,1)[0]
  if fold:a=a-32 if 97<=a<=122 else a;b=b-32 if 97<=b<=122 else b
  if a!=b:return False
  if not a or not b:return True
 return True
def resolve(m,q,p):
 if not q or not m.read(q,1)[0]:return 0xffffffff
 if U(p-1)<7:
  for i in range(128):
   r=RECORDS+i*376;bank=m.read(r+178,1)[0];bank=bank if bank<128 else bank-256
   if bank==S(p) and eq16(m,q,r,True):return i
 for i in range(128):
  r=RECORDS+i*376
  if m.read(r+178,1)[0]==0 and eq16(m,q,r,False):return i
 return 0xffffffff
def cache(m,c,e,cap,num,names,pref):
 h=U(m.word(c)+15)&0xfffffff0;m.word(c,h+12)
 if not h:return 0
 m.word(h+8,0);m.word(h,num);m.word(h+4,cap);rows=U(m.word(c)+15)&0xfffffff0;m.word(h+8,rows);m.word(c,U(rows+cap*20))
 if not rows:return 0
 if cap:m.write(rows,b'\xff'*(cap*20))
 written=0
 if names:
  while written<S(m.word(h)):
   at=m.word(h+8)+written*20;m.write(at+4,text(m,m.word(names+written*4)).encode()+b'\0');m.word(at,0xffffffff);m.word(m.word(h+8)+written*20,resolve(m,m.word(h+8)+written*20+4,pref));written+=1
 for i in range(128):
  if written>=S(m.word(h+4)):break
  r=RECORDS+i*376;at=m.word(h+8)+written*20;m.word(at,0xffffffff);status=m.read(r+176,1)[0]
  if 0<status<128:m.write(at+4,text(m,r).encode()+b'\0');m.word(m.word(h+8)+written*20,resolve(m,m.word(h+8)+written*20+4,pref));written+=1
 while written<S(m.word(h+4)):m.word(m.word(h+8)+written*20,0xffffffff);written+=1
 return h
def model(m,c):
 a=c['args']
 if c['kind']=='resolve':return resolve(m,*a)
 if c['kind']=='cache':return cache(m,a[0],a[1],S(a[2]),S(a[3]),a[4],a[5])
 m.word(WORLD+0x2a9c,0xffffffff);m.word(0x8101b8,m.word(WORLD+0x2a98))
 if m.read(m.word(WORLD+0x128)+100,1)[0]&224:return None
 path=text(m,WORLD+128)+'.par'
 if S(service(m,'exists',[path]))>0:m.word(WORLD+0x2a9c,service(m,'load',[path,1,m.word(WORLD+0x13c)]))
 m.word(WORLD+0x138,cache(m,WORLD+0x104,WORLD+0x108,64,S(m.word(0x950ff8)),m.word(0x950ffc),m.word(WORLD+0x2a9c)));return None
def patch(a,b):return dict(address=a,data=base64.b64encode(b).decode())
def wp(a,v):return patch(a,struct.pack('<I',U(v)))
def seed(kind,args,records,names=None,mis=0,query='spark',flags=0,num=None):
 c=dict(kind=kind,args=[U(v) for v in args],writes=[wp(CR,ARENA+mis),wp(ER,ARENA-4),wp(WORLD+0x104,ARENA+mis),wp(WORLD+0x108,ARENA-4),wp(WORLD+0x128,LEVEL),wp(WORLD+0x13c,D+0x4200),wp(WORLD+0x2a98,0x103),patch(WORLD+128,b'levels\\prepared\\world\0'),patch(LEVEL+100,bytes([flags])),wp(0x950ff8,len(names or []) if num is None else num),wp(0x950ffc,TABLE if names is not None else 0),patch(Q,query.encode()+b'\0')])
 for i,record in enumerate(records):
  if record is not None:c['writes'].extend([patch(RECORDS+i*376,record[0].encode()+b'\0'),patch(RECORDS+i*376+176,bytes([record[1]&255])),patch(RECORDS+i*376+178,bytes([record[2]&255]))])
 for i,name in enumerate(names or []):c['writes'].extend([wp(TABLE+i*4,STRINGS+i*32),patch(STRINGS+i*32,name.encode()+b'\0')])
 return c
rng=random.Random(0x64b020);cases=[]
for i in range(380):
 records=[(rng.choice(['spark','SPARK','smoke','','abcdefghijklmnopX']),rng.choice([0,1,2,127,128,255]),rng.choice([0,1,2,7,8,128,255])) for j in range(rng.randrange(0,12))];pref=rng.choice([0,1,2,7,8,255,0x101,0xffffffff]);q=rng.choice(['spark','SPARK','SpArK','smoke','abcdefghijklmnopY','','missing']);cases.append(seed('resolve',[0 if i%29==0 else Q,pref],records,query=q))
for i in range(180):
 cap=rng.randrange(0,15);num=rng.choice([-2,0,1,cap,cap+2]);names=None if i%4==0 else [rng.choice(['spark','SPARK','smoke','missing']) for j in range(max(0,num))];records=[(rng.choice(['spark','SPARK','smoke','','other']),rng.choice([0,1,127,128,255]),rng.choice([0,1,2,7,255])) for j in range(rng.randrange(12))];cases.append(seed('cache',[CR,0 if i%3==0 else ER,cap,num,0 if names is None else TABLE,rng.choice([0,1,2,7,8,255])],records,names,mis=i%16,num=num))
for i in range(180):
 names=None if i%3==0 else ['spark','SPARK','missing'];records=[('spark',1,2),('SPARK',1,0),('spark',128,0),('smoke',127,1),('other',255,2)];c=seed('stage',[WORLD],records,names,mis=i%16,flags=[0,1,32,64,128,224,255][i%7],num=5 if names is None else None);c['exists']=[0,1,-1,0x80000000][i%4];c['handle']=[2,0xffffffff,0x102][i%3]
 if i%5==0:c['existsWrites']=[wp(WORLD+0x13c,D+0x4300)]
 if i%6==0:c['loadWrites']=[wp(WORLD+0x104,ARENA+0x100),wp(0x950ffc,0),wp(0x950ff8,9),patch(RECORDS+178,b'\x02')]
 cases.append(c)
for raw in [0xfffffff1,0xffffffff]:
 c=seed('cache',[CR,ER,0,0,0,255],[]);c['writes'].append(wp(CR,raw));cases.append(c)
VAs={'resolve':0x64b020,'cache':0x571890,'stage':0x571a50};rows=[];fail=[];bykind={};start=time.time()
for i,c in enumerate(cases):
 current=c;m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 trace=[];ret=n.call(VAs[c['kind']],c['args'],count=3000000);observed=dict(result=None if c['kind']=='stage' else ret,sha256=vm.digest(),trace=trace.copy())
 trace=[];ret=model(m,c);predicted=dict(result=ret,sha256=m.digest(),trace=trace.copy())
 if observed!=predicted:fail.append(dict(case=i,kind=c['kind'],observed=observed,prediction=predicted));print(json.dumps(fail[-1]));break
 c['expected']=observed;rows.append(c);bykind[c['kind']]=bykind.get(c['kind'],0)+1
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(fail),byKind=bykind,nativeEntryCalls=calls,seconds=round(time.time()-start,3),failures=fail)
(B/'reports/world-phase10-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fail:(B/'reports/world-phase10-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=0 if a==0x2913a58 else 167) for a,z in REGIONS],cases=rows),separators=(',',':'))+'\n')
print(json.dumps(report));assert not fail
