import importlib.util,json,hashlib,struct,base64,gzip,time,random
from pathlib import Path
p=Path(__file__).with_name('world-phase15-20261013-verify.py');asset={'__file__':str(p)};src=p.read_text();exec(compile(src[:src.index('rng=random.Random')],str(p),'exec'),asset)
p=Path(__file__).with_name('world-phase17-20261013-verify.py');rt={'__file__':str(p)};src=p.read_text();exec(compile(src[:src.index('n.mu.hook_add')],str(p),'exec'),rt)
Native=asset['nx'].NativeX86;n=Native();B=asset['B'];D=n.DATA;ROWS=0x2924b50;EMITTER=D+0x8000;ALT=D+0xc000;PTR=D+0x1000;PHYS=D+0x3000;FLAGS=0x2924b10;SCENES=0x2947bdc;ACTIVE=0x2948eb0
REGIONS=[(D,0x20000,167),(ROWS,0xb010,167),(SCENES-512,1024,167),(ACTIVE-512,1024,167),(FLAGS,32,0),(0x2962098,12,0),(0x29620a4,4,0),(0x2920abc,12,0),(0x29231a8,4,0),(0x810ad8,4,0)]
U=lambda v:v&0xffffffff
S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
S8=lambda v:v if v<128 else v-256
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
patch=lambda a,b:dict(address=a,data=base64.b64encode(bytes(b)).decode())
word=lambda a,v:patch(a,struct.pack('<I',U(v)))
half=lambda a,v:patch(a,struct.pack('<H',v&65535))
byte=lambda a,v:patch(a,bytes([v&255]))
vector=lambda a,v:patch(a,struct.pack('<3f',*v))
class Image:
 def __init__(self,c):
  self.regions={a:bytearray([f])*z for a,z,f in REGIONS}
  for p in c['writes']:self.write(p['address'],base64.b64decode(p['data']))
 def at(self,a):
  for base,b in self.regions.items():
   if base<=a<base+len(b):return b,a-base
  raise ValueError(hex(a))
 def read(self,a,z):b,o=self.at(a);return bytes(b[o:o+z])
 def write(self,a,v):b,o=self.at(a);assert o+len(v)<=len(b);b[o:o+len(v)]=v
 def word(self,a,v=None):
  if v is None:return struct.unpack('<I',self.read(a,4))[0]
  self.write(a,struct.pack('<I',U(v)))
 def half(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def byte(self,a):return self.read(a,1)[0]
 def digest(self):return hashlib.sha256(b''.join(self.read(a,z) for a,z,_ in REGIONS)).hexdigest()
class RuntimeAdapter:
 def __init__(self,m):self.m=m
 def W(self,a,v=None):return self.m.word(a,v)
 def H(self,a,v=None):return self.m.half(a,v)
 def B(self,a):return self.m.byte(a)
 def F(self,a):return struct.unpack('<f',self.m.read(a,4))[0]
class NativeImage:
 def read(self,a,z):return n.read(a,z)
 def write(self,a,v):n.write(a,v)
 def word(self,a,v=None):
  if v is None:return n.unpack('<I',a)[0]
  n.pack('<I',a,U(v))
 def half(self,a,v=None):
  if v is None:return n.unpack('<H',a)[0]
  n.pack('<H',a,v&65535)
 def byte(self,a):return n.read(a,1)[0]
case={};trace=[];lookups=[];marker=None
PORTS={0x684ee0:5,0x684640:3,0x6846a0:4,0x655c30:2,0x684720:4,0x5d92b0:2}
def service(im,address,args):
 global marker
 if address==0x684ee0:marker=args[0]
 trace.append([address,args.copy(),im.word(0x29620a4),im.word(marker) if marker is not None else None])
 result=0xdeadbeef
 if address==0x684ee0:im.word(marker,0xffffffff if case.get('fail') or args[1]==0xffffffff else case.get('spawnId',1))
 if address==0x5d92b0:
  im.write(args[1],struct.pack('<3f',17,18,19));result=case.get('queryResult',0x12340000)
 if address==case.get('stage'):
  if case.get('retarget'):im.word(0x29620a4,ALT)
  if marker is not None:
   if case.get('invalidate'):im.word(marker,0xffffffff)
   elif case.get('swapId'):im.word(marker,2)
   at=marker-16
   if case.get('mutateFields'):
    im.word(at+0x34,bits(7));im.word(at+0x38,bits(8));im.word(at+0x3c,bits(9));im.word(at+0x44,bits(10));im.word(at+0x48,bits(11));im.half(at+0x40,0xfedc);im.half(at+0x42,0x8abc)
   if 'mutateBank' in case:im.write(at+0x51,bytes([case['mutateBank']]))
 if case.get('alias') and address==0x684720:im.word(marker,1)
 return result
def at(im,id,field):return U(im.word(0x29620a4)+id*0x330+field)
def attach(im,id,scene):
 offset=U(id*0x330)
 if scene:
  result=service(im,0x5d92b0,[scene,U(im.word(0x29620a4)+offset+0x190)]);im.half(U(im.word(0x29620a4)+offset+0x2f2),result);live=im.word(0x29620a4);im.word(U(live+offset+0x2fc),scene if im.half(U(live+offset+0x2f2))!=65535 else 0)
 else:im.half(U(im.word(0x29620a4)+offset+0x2f2),65535);im.word(U(im.word(0x29620a4)+offset+0x2fc),0)
def activate(im):
 for row in range(512):
  pos=ROWS+row*0x58;mark=pos+16
  if im.word(mark)==0xffffffff:continue
  im.word(mark,0xffffffff);q=im.read(pos+0x24,16);lookups.append([base64.b64encode(q).decode(),0,0]);physical=asset['particle'](im,q,0,False,0);z=im.word(pos+8);im.word(pos+12,physical);y=im.word(pos+4);x=im.word(pos)
  service(im,0x684ee0,[mark,physical,x,y,z]);id=im.word(mark)
  if id==0xffffffff:im.word(mark,99999)
  else:
   im.write(at(im,id,0x2f9),b'\0');second=im.half(pos+0x16);first=im.half(pos+0x14);service(im,0x684640,[im.word(mark),first,second]);third=im.half(pos+0x1c);second=im.half(pos+0x1a);first=im.half(pos+0x18);service(im,0x6846a0,[im.word(mark),first,second,third]);id=im.word(mark);delay=im.word(pos+0x20);service(im,0x655c30,[at(im,id,0),delay]);id=im.word(mark);ff=im.word(pos+0x3c);ww=im.word(pos+0x38)
   if id!=0xffffffff:im.word(at(im,id,0x2d0),im.word(pos+0x34));im.word(at(im,id,0x2d4),ww);im.word(at(im,id,0x2d8),ff)
   first=im.word(pos+0x44);id=im.word(mark);second=im.word(pos+0x48);hh=im.half(pos+0x42)
   if id!=0xffffffff:im.half(at(im,id,0x2dc),im.half(pos+0x40));im.half(at(im,id,0x2de),hh);im.word(at(im,id,0x2e0),first);im.word(at(im,id,0x2e4),second)
   third=im.half(pos+0x56);second=im.half(pos+0x54);first=im.byte(pos+0x53);service(im,0x684720,[im.word(mark),first,second,third]);id=im.word(mark)
   if id!=0xffffffff:im.half(at(im,id,0x2f0),im.half(pos+0x4c))
   bank=S8(im.byte(pos+0x51));scene=im.word(SCENES+bank*4);attach(im,im.word(mark),scene)
  bank=S8(im.byte(pos+0x51));im.word(ACTIVE+bank*4,1)
 im.word(0x810ad8,0xffffffff);rt['select'](RuntimeAdapter(im),1.0)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
entries={}
def hook(uc,a,z,user):
 if a in [0x68e4f0,0x655f30,0x658330,0x661f60,0x5b3800]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a==0x658330:
  sp=uc.reg_read(UC_X86_REG_ESP);p,g,e=n.unpack('<3I',sp+4);lookups.append([base64.b64encode(n.read(p,16)).decode(),g,e])
 if a in PORTS:
  sp=uc.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*PORTS[a],sp+4));result=service(NativeImage(),a,args);uc.reg_write(UC_X86_REG_EAX,result);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,hook)
def seed(kind='activate',slot=0):
 c=dict(kind=kind,writes=[word(0x2962098,512),word(0x296209c,PTR),word(0x29620a4,EMITTER),word(FLAGS+8,1),patch(PTR,bytes(512*4)),word(PTR+4,PHYS),patch(PHYS,b'Present\0'.ljust(16,b'\0')),byte(PHYS+17,2),word(0x29231a8,-1),patch(0x2920abc,bytes(12)),word(0x810ad8,0x12345678)],id=1,scene=D+0x19000,queryResult=0x12340000)
 for i in range(512):c['writes'].append(word(ROWS+i*0x58+16,-1))
 for i in range(-128,128):c['writes'].append(word(SCENES+i*4,D+0x19000))
 pos=ROWS+slot*0x58;c['writes'] += [word(pos+16,99999),vector(pos,[0.5,-0.0,0]),patch(pos+0x24,b'Present\0'.ljust(16,b'\0')),byte(pos+0x51,2),word(pos+0x20,bits(0.125)),word(pos+0x34,0x80000001),word(pos+0x38,0xffffffff),word(pos+0x3c,bits(-0.0)),word(pos+0x44,bits(1.125)),word(pos+0x48,bits(0.5))]
 return c
cases=[]
for bank in range(256):
 for fail in [False,True]:c=seed();c['fail']=fail;c['writes'].append(byte(ROWS+0x51,bank));cases.append(c)
for stage in PORTS:
 for retarget in [False,True]:
  for invalidate in [False,True]:
   for swapId in [False,True]:
    c=seed(slot=511);c.update(stage=stage,retarget=retarget,invalidate=invalidate,swapId=swapId,mutateFields=True,mutateBank=128);cases.append(c)
for id in [-2,-1,0,1,31]:
 for scene in [0,0xffffffff,D+0x19000]:
  for query in [0xffffffff,0,1,0x12348000,0xabcdffff]:
   for retarget in [False,True]:c=seed('attach');c.update(id=U(id),scene=scene,queryResult=query,stage=0x5d92b0,retarget=retarget);cases.append(c)
for shift in [0,0x38]:
 c=seed(slot=64);pos=ROWS+64*0x58;c.update(alias=True);c['writes'] += [word(0x29620a4,pos+shift-0x330-0x2d0),word(pos+0x34,bits(7)),word(pos+0x38,bits(8)),word(pos+0x3c,bits(9))];cases.append(c)
rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 case=c;marker=None;trace=[];lookups=[];im=Image(c)
 if c['kind']=='activate':activate(im)
 else:attach(im,c['id'],c['scene'])
 predicted=dict(sha256=im.digest(),trace=trace.copy(),lookups=lookups.copy(),selected=im.word(0x29231a8))
 marker=None;trace=[];lookups=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 if c['kind']=='activate':n.call(0x68e4f0,count=2000000)
 else:n.call(0x655f30,[c['id'],c['scene']])
 actual=dict(sha256=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest(),trace=trace.copy(),lookups=lookups.copy(),selected=n.unpack('<I',0x29231a8)[0])
 for k in actual:
  checks+=1
  if actual[k]!=predicted[k]:errors.append(dict(case=i,key=k,actual=actual[k],model=predicted[k]))
 if errors:
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=actual;rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors[:10],entryCounts=entries,binarySha256=n.sha256,seconds=round(time.time()-start,3))
(B/'reports/world-phase19-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase19-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
