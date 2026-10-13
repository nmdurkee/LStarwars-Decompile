import importlib.util,json,struct,hashlib,base64,random,time
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
B=x.BASE;D=n.DATA;CR=D+0x6000;ER=CR+4;ARENA=D+0x10000;PATH=D+0x5000
HANDLE=0x80f884;POS=0x2900a5c;BUF=0x29110b8;MODE=0x2912f3c;ARCHIVE=0x2912f40;WRITING=0x2912f44;SWAP=0x2912f48;BASE=0x95e41c;COUNT=BASE+4
REGIONS=[(D,0x40000),(HANDLE,4),(0x91ee88,4),(BASE,8),(POS,4),(0x2910c9c,8),(BUF,4096),(MODE,16)]
U=lambda v:v&0xffffffff
S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
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
 def half(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def byte(self,a):return self.read(a,1)[0]
 def text(self,a):
  out=b''
  while self.byte(a):out+=bytes([self.byte(a)]);a+=1
  return out.decode('ascii')
 def digest(self):return hashlib.sha256(b''.join(self.read(a,z) for a,z in REGIONS)).hexdigest()
class Native(Image):
 def __init__(self):pass
 def read(self,a,z):return n.read(a,z)
 def write(self,a,b):n.write(a,b)
vm=Native();current=None;trace=[];filepos=0;opens=reads=closes=0;calls={}
def transport(m,kind,args):
 global filepos,opens,reads,closes
 payload=base64.b64decode(current['payload'])
 if kind=='open':
  opens+=1;trace.append(['open',m.text(args[0]),args[1],args[2],args[3]]);filepos=0;return U(current.get('openResult',1))
 if kind=='read':
  reads+=1;take=min(args[2],len(payload)-filepos,current.get('readLimit',4096));take=max(0,take);m.write(args[1],payload[filepos:filepos+take]);trace.append(['read',args[0],args[1],args[2],filepos,take]);filepos+=take;return take
 closes+=1;trace.append(['close',args[0]]);return 0
def hook(uc,a,z,data):
 sp=uc.reg_read(UC_X86_REG_ESP);args=lambda amount:[n.unpack('<I',sp+4+i*4)[0] for i in range(amount)]
 if a==0x4fa3f0:ret=transport(vm,'open',args(4))
 elif a==0x4fb550:ret=transport(vm,'read',args(3))
 elif a==0x4f99e0:ret=transport(vm,'close',args(1))
 else:calls[hex(a)]=calls.get(hex(a),0)+1;return
 uc.reg_write(UC_X86_REG_EAX,U(ret));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
for a in [0x4fa3f0,0x4fb550,0x4f99e0,0x5b1ee0,0x621270,0x6213e0,0x6216f0,0x6217e0,0x6217a0,0x6218c0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def open_read(m):
 if m.word(HANDLE)!=0xffffffff:return 0
 m.write(BUF,bytes(4096));m.word(POS,0);m.word(0x2910ca0,0);m.word(0x2910c9c,0);m.word(HANDLE,0xffffffff);m.word(WRITING,0)
 if m.word(MODE)!=1:return 0
 h=transport(m,'open',[PATH,0,m.word(0x91ee88),0]);m.word(HANDLE,h)
 if S(h)<1:m.word(HANDLE,0xffffffff);return 0
 m.write(BUF,bytes(4096));transport(m,'read',[h,BUF,4096]);m.word(POS,0);return 1
def close_read(m):
 m.word(ARCHIVE,0)
 if m.word(HANDLE)!=0xffffffff and m.word(MODE)==1:transport(m,'close',[m.word(HANDLE)]);m.word(HANDLE,0xffffffff);m.word(MODE,0);return 1
 return 0
def raw(m,amount):
 out=b''
 while amount>0:
  pos=m.word(POS);take=min(amount,4096-pos);out+=m.read(BUF+pos,take);h=m.word(HANDLE);pos=m.word(POS)+take;m.word(POS,pos);amount-=take
  if pos==4096 and h!=0xffffffff:
   m.write(BUF,bytes(4096))
   if m.word(MODE)==1:transport(m,'read',[h,BUF,4096]);m.word(POS,0)
 return out
def word(m):return int.from_bytes(raw(m,4),'big' if m.word(SWAP) else 'little')
def byte(m):return raw(m,1)[0]
def floatbits(m):
 v=word(m)
 return v
def load(m):
 rawcur=m.word(CR);m.word(BASE,rawcur);names=U(rawcur+3)&0xfffffffc;m.word(CR,names);m.word(MODE,1)
 if not open_read(m):m.word(BASE,0);return 0
 for ch in b'EDSPLINE v. ':
  if byte(m)!=ch:close_read(m);m.word(BASE,0);return 0
 word(m);count=word(m);points=word(m);namebytes=word(m);names=U(names+count*12);namesend=U(names+namebytes);pointcur=U(namesend+3)&0xfffffffc;end=U(pointcur+points*12)
 if m.word(ER)<end:close_read(m);m.word(BASE,0);return 0
 failed=False
 for record in range(max(0,S(count))):
  byte(m);length=S(word(m));at=U(m.word(BASE)+record*12);m.half(at+2,12);m.word(at+4,names);m.half(at,word(m));m.word(at+8,pointcur)
  for i in range(max(0,length)):m.write(m.word(at+4)+i,bytes([byte(m)]))
  names=U(names+length)
  if namesend<names:close_read(m);m.word(BASE,0);failed=True;break
  signedpoints=struct.unpack('<h',struct.pack('<H',m.half(at)))[0]
  for i in range(max(0,signedpoints)):
   p=m.word(at+8)+i*12
   for axis in range(3):m.word(p+axis*4,floatbits(m))
  pointcur=U(pointcur+signedpoints*12)
  if end<pointcur:close_read(m);m.word(BASE,0);failed=True;break
 close_read(m);m.word(CR,end);m.word(COUNT,count);return 0 if failed else count
def patch(a,b):return dict(address=a,data=base64.b64encode(b).decode())
def wp(a,v):return patch(a,struct.pack('<I',U(v)))
def make(payload,mis=0,space=0x18000,swap=0,handle=0xffffffff,openresult=1):
 return dict(kind='load',payload=base64.b64encode(payload).decode(),openResult=U(openresult),writes=[wp(CR,ARENA+mis),wp(ER,ARENA+space),wp(HANDLE,handle),wp(0x91ee88,0),wp(MODE,0x9876),wp(ARCHIVE,0),wp(WRITING,0),wp(SWAP,swap),wp(COUNT,0xdeadbeef),patch(PATH,b'levels\\prepared.spl\0')])
def spl(records,count=None,points=None,namebytes=None,swap=False,version=1):
 endian='>' if swap else '<';pack=lambda v:struct.pack(endian+'I',U(v));out=b'EDSPLINE v. '+pack(version)+pack(len(records) if count is None else count)+pack(sum(max(0,r[1]) for r in records) if points is None else points)+pack(sum(len(r[0]) for r in records) if namebytes is None else namebytes)
 for name,num,values in records:
  out+=b'\x07'+pack(len(name))+pack(num)+name+b''.join(pack(v) for v in values)
 return out
cases=[];provenance=[]
for f in sorted((B/'extracted').rglob('*.SPL')):
 payload=f.read_bytes();provenance.append(dict(path=str(f.relative_to(B)).replace('\\','/'),bytes=len(payload),sha256=hashlib.sha256(payload).hexdigest()))
 for mis in range(4):
  for space in [0,20,500]:
   c=make(payload,mis,space);c['authored']=str(f.relative_to(B)).replace('\\','/');cases.append(c)
rng=random.Random(0x5b1ee0)
for i in range(180):
 records=[]
 for j in range(rng.randrange(0,7)):
  num=rng.randrange(0,12);name=('record'+str(j)).encode()+b'\0';values=[rng.choice([0,0x80000000,0x3f800000,0x7f800000,0xff800000,0x7fc01234,rng.randrange(0x7f800000)]) for k in range(num*3)];records.append((name,num,values))
 swap=bool(i%2);payload=spl(records,swap=swap,version=rng.randrange(0x100000000));cases.append(make(payload,i%4,rng.choice([0,40,120,0x18000]),int(swap)))
for size in [1023,1024,4095,4096,4097,8193]:
 payload=spl([(bytes((i%251 for i in range(size))),0,[])])
 for mis in range(4):cases.append(make(payload,mis))
for points in [340,341,342,400]:
 payload=spl([(b'long\0',points,[U(j*12345) for j in range(points*3)])]);cases.append(make(payload))
for count in [0,0xffffffff,0x80000000]:
 for pt in [0,0xffffffff]:cases.append(make(spl([],count=count,points=pt,namebytes=0)))
for signed in [0xffff,0x8000,0x10000,0x10001]:cases.append(make(spl([(b'n\0',signed,[0,0,0] if signed==0x10001 else [])],points=1)))
for over in [1,2,4,16]:
 cases.append(make(spl([(b'abcdefgh\0',0,[])],namebytes=9-over)))
 cases.append(make(spl([(b'n\0',4,[0x3f800000]*12)],points=4-over)))
for payload in [b'',b'bad signature',b'EDSPLINE x. '+bytes(40),b'EDSPLINE v. ']:
 for handle in [0xffffffff,0,0xfffffffe]:cases.append(make(payload,handle=handle))
for ret in [0,0xffffffff,0x80000000]:cases.append(make(spl([]),openresult=ret))
for limit in [0,1,11,12,28]:
 c=make(spl([(b'name\0',0,[])]));c['readLimit']=limit;cases.append(c)
for pos in [0,1,4093,4095,4096]:
 for amount in [0,1,4,16,4096,8197,0xffffffff]:
  payload=bytes((i%251 for i in range(16000)));c=make(payload);c['kind']='read';c['args']=[D+0x8000,amount];c['initialFilePosition']=4096;c['writes'].extend([wp(HANDLE,1),wp(MODE,1),wp(POS,pos),patch(BUF,payload[:4096])]);cases.append(c)
start=time.time();results=[];fails=[]
for i,c in enumerate(cases):
 current=c;m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 trace=[];filepos=c.get('initialFilePosition',0);opens=reads=closes=0;ret=n.call(0x6216f0 if c['kind']=='read' else 0x5b1ee0,c.get('args',[PATH,CR,ER]),count=6000000);observed=dict(result=None if c['kind']=='read' else ret,sha256=vm.digest(),trace=trace.copy(),state=dict(filePosition=filepos,opens=opens,reads=reads,closes=closes))
 trace=[];filepos=c.get('initialFilePosition',0);opens=reads=closes=0
 if c['kind']=='read':m.write(c['args'][0],raw(m,max(0,S(c['args'][1]))));expected=None
 else:expected=load(m)
 predicted=dict(result=expected,sha256=m.digest(),trace=trace.copy(),state=dict(filePosition=filepos,opens=opens,reads=reads,closes=closes))
 if observed!=predicted:fails.append(dict(case=i,observed=observed,predicted=predicted,diffs=[dict(address=hex(a+j),native=vm.read(a+j,4).hex(),model=m.read(a+j,4).hex()) for a,z in REGIONS for j in range(0,z,4) if vm.read(a+j,min(4,z-j))!=m.read(a+j,min(4,z-j))][:30]));print(json.dumps(fails[-1]));break
 c['expected']=observed;results.append(c)
out=dict(binarySha256=n.sha256,cases=len(results),mismatches=len(fails),nativeEntryCalls=calls,authoredFiles=provenance,seconds=round(time.time()-start,3),failures=fails)
(B/'reports/world-phase7-20261013-native-tests.json').write_text(json.dumps(out,indent=2)+'\n')
if not fails:(B/'reports/world-phase7-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z) for a,z in REGIONS],authoredFiles=provenance,cases=results),separators=(',',':'))+'\n')
print(json.dumps(out));assert not fails
