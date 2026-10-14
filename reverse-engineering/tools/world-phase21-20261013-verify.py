import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;ALT=D+0x14000;PTR=D+0x1000;FIFO=D+0x2000;R=D+0x3000;R2=D+0x4000;OUT=D+0x800;GLOBAL=0x29620a4;HEAD=0x29620a8;NEXT=0x29211e8
REGIONS=[(D,0x40000,167),(rot['TEMPLATE'],64,0),(rot['SINE'],0x20000,0),(0x2961800,0x1800,167),(0x2921100,0x1000,167),(0x810710,0x434,167)]
common=rot['common']+[rot['patch'](0x810710,n.read(0x810710,0x434))];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];rot['REGIONS']=REGIONS;rot['common']=common
class Image(rot['Image']):
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0]
S16=rot['signed16'];S8=lambda x:x-256 if x&128 else x
case={};trace=[]
def at(im,off,f):return U(im.W(GLOBAL)+off+f)
def allocate(im):
 cursor=S(im.W(NEXT))
 if cursor>=S(im.W(0x2962094)):return 0xffffffff
 id=S16(im.H(U(im.W(0x2962084)+cursor*2)));im.W(NEXT,cursor+1);off=U(id*0x330)
 for i in range(32):im.W(at(im,off,0x100+i*4),0)
 for field in [0x180,0x18a,0x186,0x18c,0x18e,0x188]:im.H(at(im,off,field),0)
 im.H(at(im,off,0x2f2),65535);im.W(at(im,off,0x2fc),0)
 for field in [0x2f4,0x2f6,0x2f7]:im.B(at(im,off,field),1)
 im.W(at(im,off,0x32c),0);im.H(at(im,off,0x32a),id);im.B(at(im,off,0x2fa),0);return U(id)
def position(im,id,xyz):
 if id==0xffffffff:return
 off=U(id*0x330)
 for j,field in enumerate([0x190,0x194,0x198]):im.W(at(im,off,field),xyz[j])
 im.W(at(im,off,0x300),0)
def fields(im,id,args):
 if id==0xffffffff:return
 off=U(id*0x330);im.H(at(im,off,0x2dc),args[0]);im.H(at(im,off,0x2de),args[1]);im.W(at(im,off,0x2e0),args[2]);im.W(at(im,off,0x2e4),args[3])
def timer(im,ptr,time):
 trace.append([ptr,time,im.W(GLOBAL),im.W(OUT)])
 target=ptr
 if case.get('retarget'):im.W(GLOBAL,ALT);target=U(ALT+(ptr-EM))
 im.W(target+0x1e4,case.get('duration',bits(5)))
 if case.get('swapRecord'):im.W(PTR+4,R2)
 if case.get('mutateRecord'):
  im.B(R+0x2c,128);im.B(R+0x2d,255);im.B(R+0x2e,7);im.B(R+0x2f1,4);im.W(R+0x3e0,0);im.W(R+0x3e4,4)
 if case.get('mutateClock'):im.W(0x296205c,bits(80));im.W(0x2962060,bits(90))
 if case.get('invalidate'):im.W(OUT,0xffffffff)
 if case.get('swapId'):im.W(OUT,7)
 return 0xdeadbeef
def schedule(im,id,t):return timer(im,at(im,U(id*0x330),0),t)
def create(im,out,physical,xyz):
 if physical in [0,0xffffffff] or S(physical)>=S(im.W(0x2962098)):return
 r=im.W(U(im.W(0x296209c)+physical*4))
 if not r or im.B(r+0x13):return
 fresh=im.W(out)==0xffffffff
 if fresh:im.W(out,allocate(im))
 id=im.W(out)
 if id==0xffffffff:return
 off=U(id*0x330);clock=im.W(0x2962060 if im.B(r+0x2f1)==4 else 0x296205c);im.H(at(im,off,0x182),physical);im.B(at(im,off,0x184),0);schedule(im,id,im.W(r+0x18));im.W(at(im,off,0x1c0),im.W(0x810910+S8(im.B(r+0x2c))*4));im.W(at(im,off,0x1c4),im.W(0x810944+S8(im.B(r+0x2d))*4));im.W(at(im,off,0x1d4),0)
 for f in [0x1d0,0x1d2,0x2c8]:im.H(at(im,off,f),0)
 im.W(at(im,off,0x2cc),0);i=0
 while i<S8(im.B(im.W(U(im.W(0x296209c)+physical*4))+0x2f0)):im.W(at(im,off,0x200+i*0x1c),bits(-1));i+=1
 for f in [0x19c,0x1a0,0x1a4,0x1a8,0x1ac,0x1b0,0x1b4,0x1b8,0x1bc]:im.W(at(im,off,f),0)
 im.H(at(im,off,0x2f2),65535);im.B(at(im,off,0x1da),7);im.W(at(im,off,0x2fc),0);im.W(at(im,off,0x300),0);im.W(at(im,off,0x31c),0x497423f0);im.B(at(im,off,0x2f5),0);im.W(at(im,off,0x320),clock);im.B(at(im,off,0x2f9),1);im.W(at(im,off,0x32c),0);im.B(at(im,off,0x2fa),0);live=im.W(GLOBAL);duration=im.W(U(live+off+0x1e4));im.W(U(live+off+0x324),duration if F(duration)<F(clock) else clock);im.H(at(im,off,0x1d8),0);type=S8(im.B(r+0x2e));im.H(at(im,off,0x328),{2:50000,3:40000,7:20000}.get(type,30000))
 for i in range(4):
  a=r+0x3e0+i*12;im.H(at(im,off,0x2e8+i*2),9999)
  if im.W(a)!=0xffffffff:
   if im.W(a+4) in [3,4]:im.H(at(im,off,0x2e8+i*2),1)
   im.B(at(im,off,0x2f5),1)
 position(im,id,xyz);rot['orientation'](im,dict(kind='secondary',id=id,angles=[0,0,0],mode=0));rot['orientation'](im,dict(kind='primary',id=id,angles=[0,0],mode=0));fields(im,id,[0,0,0,bits(0.9)]);im.W(at(im,off,0x2d0),0);im.W(at(im,off,0x2d4),0xffffffff);im.W(at(im,off,0x2d8),0)
 if fresh:
  e=U(im.W(GLOBAL)+off);h=im.W(HEAD)
  if h:im.W(h+0x1cc,e);h=im.W(HEAD)
  im.W(e+0x1c8,h);im.W(HEAD,e)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
class NativeImage:
 def read(self,a,z):return n.read(a,z)
 def write(self,a,b):n.write(a,b)
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',a)[0]
  n.pack('<I',a,U(v))
 def H(self,a,v=None):
  if v is None:return n.unpack('<H',a)[0]
  n.pack('<H',a,v&65535)
 def B(self,a,v=None):
  if v is None:return n.read(a,1)[0]
  n.write(a,bytes([v&255]))
entries={}
def hook(uc,a,z,user):
 if a in [0x684ee0,0x6550b0,0x655940,0x655ba0,0x655da0,0x684640,0x6846a0,0x64ff80,0x64ffe0,0x6500c0,0x6501a0]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a==0x655c30:
  sp=uc.reg_read(UC_X86_REG_ESP);args=n.unpack('<2I',sp+4);result=timer(NativeImage(),*args);uc.reg_write(UC_X86_REG_EAX,result);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,hook)
def seed(kind='create'):
 c=dict(kind=kind,writes=[word(GLOBAL,EM),word(HEAD,0),word(NEXT,0),word(0x2962084,FIFO),word(0x2962094,32),word(0x2962098,512),word(0x296209c,PTR),patch(PTR,bytes(512*4)),word(PTR,R),word(PTR+4,R),word(PTR+8,R2),word(PTR-8,R),word(OUT,-1),word(0x296205c,bits(10)),word(0x2962060,bits(20))],id=1,physical=1,xyz=[bits(1.25),bits(-2.5),bits(-0.0)],args=[0xffffffff,0x12348000,bits(-0.0),bits(0.125)],time=bits(0.25))
 for i in range(-2,34):c['writes'].append(patch(FIFO+i*2,struct.pack('<H',(i+1)&65535)))
 for r in [R,R2]:
  c['writes'] += [patch(r+0x13,b'\0'),word(r+0x18,bits(0.125)),patch(r+0x2c,b'\0\0\0'),patch(r+0x2f0,b'\x02\0')]
  for i in range(4):c['writes'] += [word(r+0x3e0+i*12,0xffffffff),word(r+0x3e4+i*12,0)]
 return c
cases=[]
for cursor in [-2,-1,0,1,4,31]:
 for cap in [-2,-1,0,1,4,32]:c=seed('allocate');c['writes'] += [word(NEXT,cursor),word(0x2962094,cap)];cases.append(c)
for id in [-32768,-32767,-2,-1,0,1,31,32767]:
 c=seed('allocate');c['writes'] += [patch(FIFO,struct.pack('<H',id&65535)),word(GLOBAL,U(EM-id*0x330))];cases.append(c)
for kind in ['position','fields','schedule']:
 for id in [-2,-1,0,1,31]:
  for values in [[bits(0),bits(-0.0),1],[bits(-3.5),bits(1.25),0x80000001]]:
   c=seed(kind);c.update(id=U(id),xyz=values,time=values[0]);cases.append(c)
for physical in [0,0xffffffff,0xfffffffe,0x80000000,1,2,511,512,0x7fffffff]:
 for existing in [0xffffffff,0,1,7]:
  for disabled in [0,1]:
   c=seed();c['physical']=U(physical);c['writes'] += [word(OUT,existing),patch(R+0x13,bytes([disabled]))];cases.append(c)
for type in range(256):
 c=seed();c['writes'].append(patch(R+0x2e,bytes([type])));cases.append(c)
for type in [0,4,255]:
 for count in [0,1,4,127,128,255]:
  for fresh in [False,True]:
   c=seed();c['writes'] += [patch(R+0x2f1,bytes([type])),patch(R+0x2f0,bytes([count])),word(OUT,-1 if fresh else 1),word(HEAD,EM+5*0x330)];cases.append(c)
for duration in [bits(-100),bits(-0.0),bits(0),bits(5),bits(10),bits(20),0x7f800000,0xff800000,0x7fc12345,0xffc12345]:
 for retarget in [False,True]:
  for swap in [False,True]:
   c=seed();c.update(duration=duration,retarget=retarget,swapRecord=swap,mutateRecord=True,mutateClock=True);c['writes'].append(patch(R2+0x2f0,b'\x04'));cases.append(c)
for invalidate in [False,True]:
 for swapId in [False,True]:c=seed();c.update(invalidate=invalidate,swapId=swapId);cases.append(c)
for selector in [0,1,127,128,255]:
 for mode in [0,1,3,4,0xffffffff]:
  c=seed();c['writes'] += [patch(R+0x2c,bytes([selector])),patch(R+0x2d,bytes([selector])),word(R+0x3e0,0),word(R+0x3e4,mode),word(R+0x3ec,5),word(R+0x3f0,mode)];cases.append(c)
c=seed();c['writes'].append(word(HEAD,HEAD-0x1cc));cases.append(c)
c=seed();alias=EM+0x330-0xf0;c['writes'] += [word(PTR+4,alias),patch(alias+0x13,b'\0'),word(alias+0x18,bits(0.125)),patch(alias+0x2f0,b'\x02\0')];cases.append(c)
rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);result=None
 if c['kind']=='allocate':result=allocate(im)
 elif c['kind']=='position':position(im,c['id'],c['xyz'])
 elif c['kind']=='fields':fields(im,c['id'],c['args'])
 elif c['kind']=='schedule':schedule(im,c['id'],c['time'])
 else:create(im,OUT,c['physical'],c['xyz'])
 predicted=dict(sha256=im.hash(),trace=trace.copy(),output=im.W(OUT),result=result)
 trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 if c['kind']=='allocate':result=n.call(0x6550b0)
 elif c['kind']=='position':n.call(0x655940,[c['id']]+c['xyz'])
 elif c['kind']=='fields':n.call(0x655ba0,[c['id']]+c['args'])
 elif c['kind']=='schedule':n.call(0x655da0,[c['id'],c['time']])
 else:n.call(0x684ee0,[OUT,c['physical']]+c['xyz'])
 actual=dict(sha256=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest(),trace=trace.copy(),output=n.unpack('<I',OUT)[0],result=result if c['kind']=='allocate' else None)
 for k in actual:
  checks+=1
  if actual[k]!=predicted[k]:errors.append(dict(case=i,kind=c['kind'],key=k,actual=actual[k],model=predicted[k]))
 if errors:
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=actual;rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors[:10],entryCounts=entries,binarySha256=n.sha256,seconds=round(time.time()-start,3),explicitAdapters=['0x655c30 timing only'])
(B/'reports/world-phase21-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase21-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],commonWrites=common,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
