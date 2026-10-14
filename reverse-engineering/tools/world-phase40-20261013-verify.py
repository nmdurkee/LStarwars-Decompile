import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;R=D+0x3000;DESC=D+0x8000;FREE=D+0x1000;SINE=0x29899a0;REGIONS=[(D,0x20000,167),(0x2962000,0x400,0),(0x2924b44,4,0),(0x8108fc,4,0),(0x29a9c48,4,0),(SINE,0x20000,0)];rot['REGIONS']=REGIONS;rot['common']=[rot['patch'](SINE,n.read(SINE,0x20000))];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
class Image(rot['Image']):
 def read(self,a,z):return super().read(U(a),z)
 def write(self,a,v):return super().write(U(a),v)
 def B(self,a):return self.read(a,1)[0]
def finite(w):
 if not math.isfinite(F(w)):raise ValueError('nonfinite consumed '+hex(w))
 return N.word(w)
def sub(a,b):return a+N(-b.v,not b.neg)
def div(a,b):return N(rot['quant'](a.v/b.v,64),a.neg!=b.neg)
def i64word(w):
 f=F(w)
 if not math.isfinite(f) or f< -9223372036854775808 or f>=9223372036854775808:return 0
 return U(math.trunc(f))
def ftol(im,x):
 v=x.v
 if im.W(0x29a9c48):v=rot['quant'](v,53)
 q=abs(v.numerator)//v.denominator*(-1 if v<0 else 1);return q if -2147483648<=q<=2147483647 else -2147483648
def sine(im,x):return finite(im.W(SINE+((ftol(im,x)>>1)&32767)*4))
def curve(im,r,field,t):
 for i in range(7):
  at=r+field+i*8;a=im.W(at);b=im.W(at+8)
  if F(a)<=F(t)<=F(b):
   delta=sub(finite(t),finite(a)).store()
   if not delta&0x7fffffff:return im.W(at+4)
   length=sub(finite(b),finite(a)).store();fraction=div(finite(delta),finite(length));difference=sub(finite(im.W(at+12)),finite(im.W(at+4)));return (difference*fraction+finite(im.W(at+4))).store()
 return 0
case={};trace=[]
def produce(im,r):
 if not im.W(r+0x2a8):
  count=im.W(0x2924b44)
  if S(count)>=S(im.W(0x8108fc)):trace.append([0x5f74a0,[]]);return
  im.W(r+0x2a8,im.W(im.W(0x2962090)+count*4));im.W(0x2924b44,im.W(0x2924b44)+1)
 dest=im.W(r+0x2a8);im.W(dest+0x10,im.W(r+0xa0))
 for j in range(4):im.W(dest+0x28+j*4,(N(i64word(im.W(r+0x298+j*4))&511)*N(0.003921568859368563)).store())
 for index in range(64):
  t=(N(index)*N(0.015625)).store();width=curve(im,r,0x150,t);height=curve(im,r,0x190,t);angle=curve(im,r,0x1d8,t)
  oscillationX=(sine(im,finite(t)*finite(im.W(r+0xb0))*N(65536))*finite(im.W(r+0xb4))).store();oscillationY=(sine(im,finite(t)*finite(im.W(r+0xb8))*N(65536))*finite(im.W(r+0xbc))).store();dest=im.W(r+0x2a8)+0x4c+index*0x28
  rotated=sub(finite(angle),N(16384)).store();sc=sine(im,N(16384)+finite(rotated));sd=sine(im,finite(rotated));halfWidth=finite(width)*N(0.25);halfHeight=finite(height)*N(0.25);scWidth=sc*halfWidth;sdHeight=sd*halfHeight;sdHeightDouble=N(rot['quant'](sdHeight.v,53),sdHeight.neg)
  firstY=sub(finite(oscillationY),sdHeight+scWidth).store();scHeight=halfHeight*sc;sdWidth=sd*halfWidth;firstX=sub(finite(oscillationX),sdWidth+scHeight).store();otherY=(sub(sdHeightDouble,scWidth)+finite(oscillationY)).store();newHalf=finite(width)*N(0.5);newD=(sd*newHalf).store();newC=(newHalf*sc).store();otherX=(sub(scHeight,sdWidth)+finite(oscillationX)).store();factor=N(0.00048828125)
  for at,value in [(0,otherX),(4,firstY),(12,firstX),(16,otherY)]:im.W(dest+at,(finite(value)*factor).store())
  for at in [8,20,32]:im.W(dest+at,0)
  im.W(dest+24,((finite(firstX)+finite(newD))*factor).store());im.W(dest+28,((finite(otherY)+finite(newC))*factor).store())
  color=[0,0,0]
  for i in range(7):
   at=r+0xc0+i*8;a=im.W(at);b=im.W(at+8)
   if F(a)<=F(t)<=F(b):
    length=sub(finite(b),finite(a)).store();delta=sub(finite(t),finite(a)).store()
    if not delta&0x7fffffff:color=[bits(float(im.B(at+4+j))) for j in range(3)]
    else:
     fraction=div(finite(delta),finite(length));color=[(N(im.B(at+12+j)-im.B(at+4+j))*fraction+N(im.B(at+4+j))).store() for j in range(3)]
    break
  alpha=curve(im,r,0x100,t);alpha=(finite(alpha)+finite(alpha)).store()
  if F(alpha)>=255:alpha=bits(255)
  packed=U(i64word(alpha)<<8);packed=U((packed|i64word(color[0]))<<8);packed=U((packed|i64word(color[1]))<<8);packed|=i64word(color[2]);im.W(dest+36,packed)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={}
def observe(uc,a,z,user):
 if a in [0x600260,0x6e6b90]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=0x5f74a0:return
 trace.append([a,[]]);sp=uc.reg_read(UC_X86_REG_ESP);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed():
 c=dict(record=R,writes=[patch(R,bytes(0x440)),word(R+0x2a8,0),word(0x2962090,FREE),word(0x2924b44,0),word(0x8108fc,4),word(FREE-4,DESC+0x1000),word(FREE,DESC),word(FREE+4,DESC+0x1000),word(FREE+8,DESC+0x2000),word(FREE+12,DESC+0x3000),word(R+0xa0,bits(2)),patch(R+0x298,struct.pack('<4f',0,127.5,255.75,511.99)),patch(R+0xb0,struct.pack('<4f',1,0.25,2,-0.5))])
 for field,value in [(0x150,256),(0x190,128),(0x1d8,0),(0x100,100)]:
  for i in range(8):c['writes'] += [word(R+field+i*8,bits(i/7)),word(R+field+i*8+4,bits(value+i*value/8))]
 for i in range(8):c['writes'] += [word(R+0xc0+i*8,bits(i/7)),patch(R+0xc4+i*8,bytes([i*31,255-i*31,(i*53)&255,0]))]
 return c
cases=[]
for reuse in [False,True]:
 for count in [-1,0,1,3,4]:
  for cap in [-1,0,1,4]:
   c=seed();c['writes'] += [word(0x2924b44,count),word(0x8108fc,cap)]
   if reuse:c['writes'] += [word(R+0x2a8,DESC)]
   cases.append(c)
rng=random.Random(2026101340)
for k in range(64):
 c=seed();c['writes'] += [patch(R+0xb0,struct.pack('<4f',rng.uniform(-100,100),rng.uniform(-10,10),rng.uniform(-100,100),rng.uniform(-10,10)))]
 for field in [0x150,0x190,0x1d8,0x100]:
  for i in range(8):c['writes'] += [word(R+field+i*8+4,bits(rng.uniform(-1000,1000) if field!=0x1d8 else rng.uniform(-100000,100000)))]
 cases.append(c)
for field in [0x150,0x190,0x1d8,0x100,0xc0]:
 for form in ['none','zero','descending','firstdegenerate','offset']:
  c=seed()
  for i in range(8):c['writes'] += [word(R+field+i*8,bits(2+i if form=='none' else 0 if form=='zero' else 1-i/7 if form=='descending' else (0 if i<2 else i/7) if form=='firstdegenerate' else i/7-0.25))]
  cases.append(c)
for values in [(0,-0.0,1,-1),(0.125,-0.125,511.9,512),(1e30,-1e30,2147483648,-2147483648),(-9223372036854775808,9223372036854775808,255.99,511.99)]:c=seed();c['writes'] += [patch(R+0x298,struct.pack('<4f',*values))];cases.append(c)
for selector in [0,1]:
 for angle in [0,16384,32768,65536,-16384,1e8,-1e8]:
  c=seed();c['writes'] += [word(0x29a9c48,selector)]
  for i in range(8):c['writes'] += [word(R+0x1dc+i*8,bits(angle))]
  cases.append(c)
# First retained header store can replace the live descriptor pointer; remaining header writes use the cached destination.
c=seed();c['writes'] += [word(R+0x2a8,R+0x2a8-16),word(R+0xa0,D+0xa000)];cases.append(c)
# Earlier sampled geometry overwrites future curves while keeping the physical descriptor pointer outside its written span.
for shift in [0x900,0x880,0x800]:c=seed();c['writes'] += [word(R+0x2a8,R-shift)];cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c)
 try:produce(im,c['record'])
 except (ValueError,ZeroDivisionError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 modelTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x600260,[c['record']],count=3000000)
 except Exception as ex:errors.append(dict(case=i,stage='native',error=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=modelTrace:
  errors.append(dict(case=i,actual=actual,model=im.hash(),nativeTrace=trace,modelTrace=modelTrace))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=['0x5f74a0 capacity failure terminal service'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase40-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase40-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
