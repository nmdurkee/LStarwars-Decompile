import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x80e85c,4,0),(0x80e870,0x90,0),(0x973730,8,0),(0x97374c,4,0),(0x966378,4,0),(0x97313c,4,0),(0x80b708,64,0),(0x280c480,64,167),(0x297c0d0,4,0),(0x2854f50,0x100,167),(0x97c1b0,32,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
class Image(rot['Image']):
 def read(self,a,z):return super().read(U(a),z)
 def write(self,a,v):return super().write(U(a),v)
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))

def model(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);t=ast.parse(p.read_text());selected=ast.Module(body=[x for x in t.body if isinstance(x,ast.FunctionDef) and x.name not in ['seed','observe','model']],type_ignores=[]);ctx=dict(globals(),__file__=str(p));exec(compile(selected,str(p),'exec'),ctx);return ctx
affine=model(102);simd=model(104);dot=affine['dot'];quiet=lambda w:w|0x400000 if w&0x7fffffff>0x7f800000 else w
DESTINATIONS=[0x2854f50,0x2854f60,0x2854f70,0x2854f54,0x2854f64,0x2854f74,0x2854f58,0x2854f68,0x2854f78,0x2854f5c,0x2854f6c,0x2854f7c,0x2854f80,0x2854f90,0x2854fa0,0x2854f84,0x2854f94,0x2854fa4,0x2854f88,0x2854f98,0x2854fa8,0x2854f8c,0x2854f9c,0x2854fac];SELECTORS=[0,1,2,3,4,5,0,1,5,3,4,2,0,4,2,0,4,5,3,1,2,3,1,5]
def apply(im,c):
 minimum,maximum,transform,far,fatal=c['args']
 if im.W(0x80e85c)==0:return 1
 if fatal:raise ValueError('nonzerofifthargumentfatalserviceandpermanentloop excludedfrom returning domain')
 if F(far)==0:far=im.W(0x973734) if F(im.W(0x97374c))==0 else im.W(0x97374c)
 if transform in [0,0x806680]:
  for i in range(16):im.W(0x280c480+i*4,im.W(0x80b708+i*4))
 else:affine['apply'](im,dict(args=[0x280c480,transform,0x80b708]))
 far=quiet(far)
 for address in [0x80e8fc,0x80e8f8,0x80e8f4,0x80e8f0]:im.W(address,far)
 if im.W(0x297c0d0):
  for address,sel in zip(DESTINATIONS,SELECTORS):im.W(address,quiet(im.W((minimum if sel<3 else maximum)+(sel%3)*4)))
  simd['apply'](im,dict(args=[0x2854fd0,0x2854f50,0x280c480,8,0x97c1b0]));allCode=0xffffffff;anyCode=0
  for i in range(8):code=im.W(0x97c1b0+i*4);allCode&=code;anyCode|=code
  return 0 if allCode else 2 if anyCode else 1
 corners=[]
 for mask in [0,7,4,3,2,6,1,5]:corners.extend(quiet(im.W((maximum if mask&(1<<c) else minimum)+c*4)) for c in range(3))
 transformed=[]
 for i in range(8):
  for col in range(3):
   w=dot(*corners[i*3:i*3+3],im.W(0x280c480+col*4),im.W(0x280c480+col*4+16),im.W(0x280c480+col*4+32),True,im.W(0x280c480+col*4+48))
   if not __import__('math').isfinite(F(w)):raise ValueError('nonfinite scalar transformed result excluded')
   transformed.append(F(w))
 near=F(im.W(0x973730));sx=F(im.W(0x966378));sy=F(im.W(0x97313c));allCode=63;anyCode=0
 for i in range(8):
  x,y,z=transformed[i*3:i*3+3];code=0
  if z<near:code|=32
  if F(far)<z:code|=16
  if x<-z*sx:code|=1
  if z*sx<x:code|=2
  if y<-z*sy:code|=8
  if z*sy<y:code|=4
  allCode&=code;anyCode|=code
 return 0 if allCode else 2 if anyCode else 1
LO=D+0x1000;HI=D+0x1100;M=D+0x1200;IDENTITY=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1];rng=random.Random(20261013105);cases=[]
rot['common']=[patch(0x80e870,n.read(0x80e870,0x70)),patch(0x80b708,struct.pack('<16f',*IDENTITY)),word(0x973730,bits(.1)),word(0x973734,bits(10)),word(0x97374c,0),word(0x966378,bits(1)),word(0x97313c,bits(.75))]
def seed(mode=0,transform=0,far=0,lo=(-1,-1,4),hi=(1,1,6)):return dict(args=[LO,HI,transform,far,0],writes=[word(0x80e85c,1),word(0x297c0d0,mode),patch(LO,struct.pack('<3f',*lo)),patch(HI,struct.pack('<3f',*hi)),patch(M,struct.pack('<16f',*IDENTITY))])
for mode in [0,1,0xffffffff]:
 for transform in [0,0x806680,M,0x280c480,0x80b708]:
  for center in [(0,0,5),(5,0,5),(5+2**-20,0,5),(0,3.75,5),(0,0,.1),(0,0,10),(0,0,-1)]:
   for extent in [0,.1,1]:
    c=seed(mode,transform,0,[x-extent for x in center],[x+extent for x in center]);c['writes'] += [patch(0x280c480,struct.pack('<16f',*IDENTITY))];cases.append(c)
for i in range(512):
 mode=i%2;center=[rng.uniform(-20,20) for j in range(3)];extent=[rng.uniform(0,5) for j in range(3)];c=seed(mode,M,0,[center[j]-extent[j] for j in range(3)],[center[j]+extent[j] for j in range(3)]);c['writes'] += [patch(M,struct.pack('<16f',*[rng.uniform(-2,2) for j in range(16)])),patch(0x80b708,struct.pack('<16f',*[rng.uniform(-2,2) for j in range(16)]))];cases.append(c)
for mode in [0,1]:
 for far in [0,0x80000000,bits(-1),bits(1),bits(100),0x7fc00001,0x7f800000,0xff800000]:
  for override in [0,0x80000000,bits(2),bits(-2),0x7fc00001]:
   c=seed(mode,0,far);c['writes'] += [word(0x97374c,override)];cases.append(c)
for mode in [0,1]:
 for pointer in [0x80e8f0,0x280c480,0x80b708,0x2854f50,0x2854f54,0x2854f60,0x2854f70,0x97c1b0]:
  for side in [0,1]:
   c=seed(mode);c['args'][side]=pointer;c['writes'] += [patch(pointer,struct.pack('<3f',-1,.25,5))];cases.append(c)
for mode in [0,1]:
 for requested in [0,0x7fc00001,0xffffffff]:
  c=seed(mode);c['args']=[0,1,0xffffffff,requested,0xffffffff];c['writes'] += [word(0x80e85c,0)];cases.append(c)
# Prepared failure domain records no returning equivalence credit.
c=seed();c['args'][4]=1;cases.append(c)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_MXCSR
entries={}
def observe(uc,a,z,user):
 if a in [0x6042e0,0x5b5430,0x603f10,0x604110]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:expected=apply(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.mu.reg_write(UC_X86_REG_MXCSR,0x1f80);result=n.call(0x6042e0,c['args'],regs={UC_X86_REG_MXCSR:0x1f80},count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or result!=expected:
  errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=result,modelResult=expected,diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for a,z,_ in REGIONS for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]));break
 c['expected']=dict(sha256=actual,result=result);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,mxcsr=0x1f80,originalBytesSha256=hashlib.sha256(n.read(0x6042e0,1608)).hexdigest(),binarySha256=n.sha256,domain='prepared finite transformed arithmetic, both scalar and SIMD; explicit far comparison infinities/quietNaNs; nonzero fifth argument only with disabled gate; aliases follow original global/corner stores',duplicateAddressCredit=0,reaEvidenceIds=["ev_6dc44fb59eaa6d6406bf2bea08b3559caf439d36182655c21186be29b7d33f28","ev_4c9814824d93a5bfbdac0e0b0eb265c8df2c60ab2f760b6e7774ba03f76cc451","ev_f38354640510002d99d11e38b917f3bb393f274bf46e6c66bd17f7f80454f587","ev_9b967b45b8671c06bc41d9a6ce7f1e575c2b3ec525c056a3dc288228f0ddb57f","ev_4b58b4b52ca97ca19a1dc3440e1ae22f8e6862c85bef633deaf722baab203ad4"],nativeAdapters=[],syntheticExcluded=len(excluded),excluded=excluded,seconds=round(time.time()-start,3))
(B/'reports/world-phase105-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase105-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
