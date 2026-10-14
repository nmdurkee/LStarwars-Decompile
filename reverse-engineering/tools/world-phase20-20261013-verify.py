import importlib.util,json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
from fractions import Fraction
p=Path(__file__).with_name('world-phase17-20261013-verify.py');exact={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('n.mu.hook_add')],str(p),'exec'),exact)
Native=exact['m'].NativeX86;n=Native();B=exact['B'];D=n.DATA;MAT=D+0x1000;SRC=D+0x2000;EM=D+0x8000;TEMPLATE=0x8065c0;SINE=0x29899a0;GLOBAL=0x29620a4
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX
REGIONS=[(D,0x20000,167),(TEMPLATE,64,0),(SINE,0x20000,0),(0x2961800,0x1800,167)]
U=lambda v:v&0xffffffff
F=lambda v:struct.unpack('<f',struct.pack('<I',U(v)))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
patch=lambda a,b:dict(address=a,data=base64.b64encode(bytes(b)).decode())
word=lambda a,v:patch(a,struct.pack('<I',U(v)))
quiet=lambda v:v|0x400000 if v&0x7fffffff>0x7f800000 else v
sine=(B/'references/native-animation-sine-table.f32').read_bytes();template=n.read(TEMPLATE,64);common=[patch(SINE,sine),patch(TEMPLATE,template)]
quant=exact['quant']
def fstore(v,negative=False):
 if not v:return 0x80000000 if negative else 0
 neg=v<0;x=abs(v);e=x.numerator.bit_length()-x.denominator.bit_length()
 if x<Fraction(2)**e:e-=1
 step=Fraction(2)**max(e-23,-149);q,r=divmod(x/step,1);q=int(q)
 if r>Fraction(1,2) or r==Fraction(1,2) and q&1:q+=1
 if q==0:return 0x80000000 if neg else 0
 try:return bits(float((-1 if neg else 1)*q*step))
 except OverflowError:return 0xff800000 if neg else 0x7f800000
class N:
 def __init__(self,v,neg=False):self.v=Fraction(v);self.neg=self.v<0 or self.v==0 and neg
 @classmethod
 def word(cls,w):return cls(F(w),bool(w&0x80000000))
 def __add__(a,b):return N(quant(a.v+b.v,64),not a.v and not b.v and a.neg and b.neg)
 def __neg__(a):return N(-a.v,not a.neg)
 def __sub__(a,b):return a+ -b
 def __mul__(a,b):return N(quant(a.v*b.v,64),a.neg!=b.neg)
 def store(a):return fstore(a.v,a.neg)
class Image:
 def __init__(self,c):
  self.regions={a:bytearray([fill])*z for a,z,fill in REGIONS}
  for p in common+c['writes']:self.write(p['address'],base64.b64decode(p['data']))
 def block(self,a):
  for base,b in self.regions.items():
   if base<=a<base+len(b):return b,a-base
  raise ValueError(hex(a))
 def read(self,a,z):b,o=self.block(a);return bytes(b[o:o+z])
 def write(self,a,v):b,o=self.block(a);assert o+len(v)<=len(b);b[o:o+len(v)]=v
 def W(self,a,v=None):
  if v is None:return struct.unpack('<I',self.read(a,4))[0]
  self.write(a,struct.pack('<I',U(v)))
 def B(self,a,v):self.write(a,bytes([v&255]))
 def hash(self):return hashlib.sha256(b''.join(self.read(a,z) for a,z,_ in REGIONS)).hexdigest()
def copy(im,dest,src):
 for i in range(0,64,4):im.W(dest+i,im.W(src+i))
def rotate(im,ptr,angle,axis):
 c=N.word(im.W(SINE+((U(angle+0x4000)>>1)&0x7fff)*4));s=N.word(im.W(SINE+((U(angle)>>1)&0x7fff)*4));a=4 if axis==0 else 0;b=4 if axis==2 else 8;first=[N.word(im.W(ptr+r*16+a)) for r in range(4)]
 for r in range(4):
  pa=ptr+r*16+a;pb=ptr+r*16+b;v=N.word(im.W(pb));im.W(pa,(first[r]*c+s*v if axis==1 else first[r]*c-s*v).store());v=N.word(im.W(pb));im.W(pb,(c*v-s*first[r] if axis==1 else c*v+s*first[r]).store())
def signed16(x):return (x&65535)-65536 if x&32768 else x&65535
def orientation(im,c):
 id=c['id']
 if id==0xffffffff:return
 off=U(id*0x330);kind=c['kind'];field=dict(primary=0x40,secondary=0x80,mode=0xc0)[kind]
 at=lambda f:U(im.W(GLOBAL)+off+f)
 if kind=='mode':im.B(at(0x2fa),c['mode'])
 copy(im,at(field),TEMPLATE)
 if kind=='mode':rotate(im,at(field),signed16(c['angles'][0]),0);rotate(im,at(field),signed16(c['angles'][1]),1)
 else:
  rotate(im,at(field),signed16(c['angles'][0]),2);rotate(im,at(field),signed16(c['angles'][1]),1)
  if kind=='secondary':rotate(im,at(field),signed16(c['angles'][2]),0)
  im.W(at(0x300),0)
entries={}
def observe(uc,a,z,user):
 if a in [0x64ff80,0x64ffe0,0x6500c0,0x6501a0,0x684640,0x6846a0,0x684720]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
cases=[];rng=random.Random(2026101320)
def seed(kind):return dict(kind=kind,writes=[word(GLOBAL,EM)],id=1,angles=[0,0,0],mode=0,ptr=MAT,src=SRC,dest=MAT)
# Every exponent/sign classification with payload boundary values, grouped into16word calls.
words=[(sign<<31)|(exponent<<23)|frac for sign in [0,1] for exponent in range(256) for frac in [0,1,0x3fffff,0x400000,0x7fffff] if exponent!=255 or frac==0 or frac&0x400000]
for i in range(0,len(words),16):
 c=seed('copy');chunk=words[i:i+16];chunk += [0]*(16-len(chunk));c['writes'].append(patch(SRC,struct.pack('<16I',*chunk)));cases.append(c)
for shift in [-20,-12,-8,-4,-3,-2,-1,0,1,2,3,4,8,12,20]:
 c=seed('copy');c['dest']=SRC+shift;c['writes'].append(patch(SRC-24,bytes(rng.randrange(256) for _ in range(128))));cases.append(c)
angles=[0,1,2,3,0x3fff,0x4000,0x4001,0x7fff,0x8000,0xbfff,0xc000,0xffff,0x10000,0x10001,0x7fffffff,0x80000000,0xffff4000,0xffffffff]+[rng.randrange(1<<32) for _ in range(192)]
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0xff7fffff,bits(1),bits(-1),bits(0.125),bits(-3.75),bits(1024)]
for axis in range(3):
 for angle in angles:
  c=seed('rotate');c.update(axis=axis,angle=angle);c['ptr']=MAT+rng.choice([0,1,2,3]);c['writes'].append(patch(c['ptr'],struct.pack('<16I',*[rng.choice(choices) for _ in range(16)])));cases.append(c)
for kind in ['primary','secondary','mode']:
 for id in [-2,-1,0,1,31]:
  for angles in [[0,0,0],[1,2,3],[32767,65535,32768],[0xffffffff,0xffff0001,0x80001234]]:
   c=seed(kind);c.update(id=U(id),angles=angles,mode=0xffffffff);cases.append(c)
 for i in range(128):c=seed(kind);c.update(angles=[rng.randrange(1<<32) for _ in range(3)],mode=rng.randrange(1<<32));cases.append(c)
for mode in range(256):c=seed('mode');c['mode']=mode;c['angles']=[0x7fff,0x8000,0];cases.append(c)
for kind in ['primary','secondary']:
 c=seed(kind);c['id']=0;c['writes'] += [word(GLOBAL,GLOBAL-dict(primary=0x40,secondary=0x80)[kind]),word(TEMPLATE,D+0x7000)];cases.append(c)
for mode in [0,1,127,128,255]:
 c=seed('mode');c['id']=0;c['mode']=mode;c['writes'].append(word(GLOBAL,GLOBAL-0x2fa));cases.append(c)
rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 if c['kind']=='copy':copy(im,c['dest'],c['src'])
 elif c['kind']=='rotate':rotate(im,c['ptr'],c['angle'],c['axis'])
 else:orientation(im,c)
 predicted=im.hash();initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 if c['kind']=='copy':n.call(0x64ff80,regs={UC_X86_REG_EAX:c['src'],UC_X86_REG_ECX:c['dest']})
 elif c['kind']=='rotate':n.call([0x64ffe0,0x6500c0,0x6501a0][c['axis']],regs={UC_X86_REG_EAX:c['ptr'],UC_X86_REG_ECX:c['angle']})
 else:n.call(dict(primary=0x684640,secondary=0x6846a0,mode=0x684720)[c['kind']],[c['id']]+([c['mode']] if c['kind']=='mode' else [])+c['angles'][:2 if c['kind']!='secondary' else 3])
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest();checks+=1
 if predicted!=actual:
  errors.append(dict(case=i,kind=c['kind'],actual=actual,model=predicted));
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors[:10],entryCounts=entries,binarySha256=n.sha256,seconds=round(time.time()-start,3),sineSha256=hashlib.sha256(sine).hexdigest(),templateSha256=hashlib.sha256(template).hexdigest(),nativeAdapters=0)
(B/'reports/world-phase20-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase20-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],commonWrites=common,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
