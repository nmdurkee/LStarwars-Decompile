import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x80e870,0x90,0),(0x973730,4,0),(0x966378,4,0),(0x97313c,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

def mul32(a,b):
 w=(N.word(a)*N.word(b)).store()
 if not __import__('math').isfinite(F(w)):raise ValueError('nonfiniteSSEarithmeticoutsideprepared domain')
 return w
def add32(a,b):
 w=(N.word(a)+N.word(b)).store()
 if not __import__('math').isfinite(F(w)):raise ValueError('nonfiniteSSEarithmeticoutsideprepared domain')
 return w
def read4(im,p):return [im.W(p+i*4) for i in range(4)]
def store4(im,p,v):
 for i,w in enumerate(v):im.W(p+i*4,w)
def apply(im,c):
 output,packed,matrix,count,codes=c['args'];groups=S(U(count+3))>>2
 if groups<=0:return
 a=[im.W(matrix+i*4) for i in range(16)]
 for group in range(groups):
  source=packed+group*48;destination=output+group*48
  for col in range(3):
   x=read4(im,source);y=read4(im,source+16);zz=read4(im,source+32);v=[]
   for lane in range(4):
    t0=mul32(a[col],x[lane]);t1=mul32(a[col+4],y[lane]);t2=mul32(a[col+8],zz[lane]);v.append(add32(add32(add32(a[col+12],t0),t1),t2))
   store4(im,destination+col*16,v)
   if col==2:z=v
  near=F(im.W(0x973730));far=read4(im,0x80e8f0);flags=[0]*4
  for lane in range(4):
   if F(z[lane])<near:flags[lane]|=im.W(0x80e870+lane*4)
   if not F(z[lane])<=F(far[lane]):flags[lane]|=im.W(0x80e880+lane*4)
  h=im.W(0x966378);negative=read4(im,0x80e8d0);slope=[mul32(mul32(h,z[i]),negative[i]) for i in range(4)];left=read4(im,destination)
  for lane in range(4):
   if F(left[lane])<F(slope[lane]):flags[lane]|=im.W(0x80e890+lane*4)
  negative=read4(im,0x80e8d0);slope=[mul32(slope[i],negative[i]) for i in range(4)];left=read4(im,destination)
  for lane in range(4):
   if not F(left[lane])<=F(slope[lane]):flags[lane]|=im.W(0x80e8a0+lane*4)
  h=im.W(0x97313c);negative=read4(im,0x80e8d0);slope=[mul32(mul32(h,z[i]),negative[i]) for i in range(4)];top=read4(im,destination+16)
  for lane in range(4):
   if F(top[lane])<F(slope[lane]):flags[lane]|=im.W(0x80e8b0+lane*4)
  negative=read4(im,0x80e8d0);slope=[mul32(slope[i],negative[i]) for i in range(4)];top=read4(im,destination+16)
  for lane in range(4):
   if not F(top[lane])<=F(slope[lane]):flags[lane]|=im.W(0x80e8c0+lane*4)
  store4(im,codes+group*16,flags)
P=D+0x1000;M=D+0x2000;O=D+0x3000;C=D+0x4000;rng=random.Random(20261013104);cases=[]
rot['common']=[patch(0x80e870,n.read(0x80e870,0x70)),patch(0x80e8f0,struct.pack('<4f',10,10,10,10)),word(0x973730,bits(.1)),word(0x966378,bits(1)),word(0x97313c,bits(.75))]
def seed(count=8,output=O,packed=P,matrix=M,codes=C):return dict(args=[output,packed,matrix,U(count),codes],writes=[patch(P,struct.pack('<96f',*[rng.uniform(-10,10) for j in range(96)])),patch(M,struct.pack('<16f',*[rng.uniform(-10,10) for j in range(16)]))])
for count in [-2147483648,-4,-3,-1,0,1,2,3,4,5,7,8,9,15,16,17,31,2147483645,2147483646,2147483647]:
 for i in range(16):cases.append(seed(count,[O,P,M][i%3]))
for count in [4,5,8,9,17]:
 for base in [P,M,C]:
  for shift in range(-64,65,16):cases.append(seed(count,base+shift))
for count in [4,8,17]:
 for code in [O,O+16,O+32,P,M,C]:cases.append(seed(count,codes=code))
for count in [-2147483648,-4,-3,-1,0,2147483645,2147483646,2147483647]:cases.append(dict(args=[0,1,0xffffffff,U(count),2],writes=[]))
for mask in range(128):
 c=seed(5);p=[0x80000000 if mask&(1<<(j%3)) else 0 for j in range(24)];m=[bits(-1 if mask&(1<<(j%3+3)) else 1) for j in range(16)];m[12:15]=[0x80000000 if mask&64 else 0]*3;c['writes'] += [patch(P,struct.pack('<24I',*p)),patch(M,struct.pack('<16I',*m))];cases.append(c)
for far in [0x7fc00001,0x7f800000,0xff800000,0x80000000,bits(1)]:
 c=seed();c['writes'] += [patch(0x80e8f0,struct.pack('<4I',far,far,far,far))];cases.append(c)
for i in range(256):
 c=seed();c['writes'] += [patch(0x80e870,struct.pack('<24I',*[rng.getrandbits(32) for j in range(24)])),patch(0x80e8d0,struct.pack('<4f',*[rng.choice([-2.,-1.,0.,1.,2.]) for j in range(4)]))];cases.append(c)
for value in [1,0x80000001,0x007fffff,0x00800000,0x3f800001,0xbf800001]:
 c=seed();c['writes'] += [patch(P,struct.pack('<24I',*[value]*24)),patch(M,struct.pack('<16I',*[value]*16))];cases.append(c)
from unicorn.x86_const import UC_X86_REG_MXCSR
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:apply(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.mu.reg_write(UC_X86_REG_MXCSR,0x1f80);n.call(0x604110,c['args'],regs={UC_X86_REG_MXCSR:0x1f80},count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,native=actual,model=im.hash(),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for a,z,_ in REGIONS for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors,entry='0x604110',mxcsr=0x1f80,originalBytesSha256=hashlib.sha256(n.read(0x604110,456)).hexdigest(),binarySha256=n.sha256,domain='16-byte aligned prepared readable images; finite SIMD arithmetic and stored results; default MXCSR, count rounding/overflow gates, full four-lane padding, arbitrary classification mask words and live aliases',reaEvidenceIds=["ev_4b58b4b52ca97ca19a1dc3440e1ae22f8e6862c85bef633deaf722baab203ad4"],nativeAdapters=[],syntheticExcluded=len(excluded),excluded=excluded,seconds=round(time.time()-start,3))
(B/'reports/world-phase104-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase104-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
