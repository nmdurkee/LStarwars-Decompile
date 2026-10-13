import importlib.util,json,struct,hashlib,base64,random,time
from fractions import Fraction
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_ESI,UC_X86_REG_EIP,UC_X86_REG_EAX
B=m.BASE;D=n.DATA;R=D+0x1000;R2=D+0x2000;TABLE=D+0x4000;EMITTER=D+0x10000;ROWS=0x2924b50;ORIGIN=0x2920abc;SELECTED=0x29231a8
REGIONS=[(D,0x30000,167),(ROWS,0xb010,167),(ORIGIN,12,0),(SELECTED,4,0),(0x296209c,12,0)]
F=lambda v:struct.unpack('<f',struct.pack('<I',v))[0]
U=lambda v:v&0xffffffff
S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
S16=lambda v:(v&65535)-65536 if v&32768 else v&65535
S8=lambda v:(v&255)-256 if v&128 else v&255
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
f32=lambda v:F(bits(float(v)))
def quant(v,p):
 if not v:return Fraction(0)
 neg=v<0;x=abs(v);e=x.numerator.bit_length()-x.denominator.bit_length()
 if x<Fraction(2)**e:e-=1
 scale=Fraction(2)**(e-p+1);q,r=divmod(x/scale,1);q=int(q)
 if r>Fraction(1,2) or r==Fraction(1,2) and q&1:q+=1
 return (-1 if neg else 1)*q*scale
X=lambda v:Fraction(float(v))
add=lambda a,b:quant(a+b,64)
sub=lambda a,b:quant(a-b,64)
mul=lambda a,b:quant(a*b,64)
def patch(a,b):return dict(address=a,data=base64.b64encode(bytes(b)).decode())
def word(a,v):return patch(a,struct.pack('<I',U(v)))
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))
def flt(a,v):return word(a,bits(v))
def vector(a,v):return patch(a,struct.pack('<3f',*v))
class Image:
 def __init__(self,c):
  self.regions={a:bytearray([fill])*size for a,size,fill in REGIONS}
  for p in c['writes']:self.write(p['address'],base64.b64decode(p['data']))
 def block(self,a):
  for p,b in self.regions.items():
   if p<=a<p+len(b):return b,a-p
  raise ValueError(hex(a))
 def read(self,a,size):b,o=self.block(a);return bytes(b[o:o+size])
 def write(self,a,data):
  b,o=self.block(a);assert o+len(data)<=len(b);b[o:o+len(data)]=data
 def W(self,a,v=None):
  if v is None:return struct.unpack('<I',self.read(a,4))[0]
  self.write(a,struct.pack('<I',U(v)))
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a):return self.read(a,1)[0]
 def F(self,a):return F(self.W(a))
 def hash(self):return hashlib.sha256(b''.join(self.read(a,z) for a,z,_ in REGIONS)).hexdigest()
trace=[];case={};entries={}
def allocate(im,at):
 trace.append([at,im.H(at+0x18c),im.H(at+0x18e),im.H(at+0x180)])
 if case.get('mutate') and len(trace)==1:
  im.W(0x29620a4,EMITTER+0x4000);im.H(R+0x14,0xfff1);im.W(ROWS+511*0x58+16,2)
def setcount(im,at,count):
 r=im.W(im.W(0x296209c)+S16(im.H(at+0x182))*4);im.H(at+0x18e,count)
 q=S(count+11) if im.B(r+0x2e)==7 else S(count+31);q=int(q/ (12 if im.B(r+0x2e)==7 else 32));im.H(at+0x18c,q)
 if S16(im.H(at+0x18c))>32:im.H(at+0x18c,32);im.H(at+0x18e,384 if im.B(r+0x2e)==7 else 1024)
 if im.H(at+0x18c)==im.H(at+0x180):im.H(at+0x186,im.H(at+0x18e))
 elif im.H(at+0x18c)!=0 and im.H(at+0x180)==0:allocate(im,at)
def normalize(im):
 L=im.F(R+0xa4);active=0.0;total=0.0;count=1;loops=0
 if L>0:
  cycle=add(X(im.F(R+0x20)),X(im.F(R+0x1c)))
  while True:
   remaining=f32(sub(X(L),X(total)))
   if X(remaining)<cycle:active=f32(add(X(remaining),X(active)));end=add(X(remaining),X(total))
   else:active=f32(add(X(active),cycle));end=add(X(total),cycle)
   end=f32(end);rest=f32(sub(X(L),X(end)));gap=im.F(R+0x24);total=f32(add(X(end),X(min(gap,rest))));loops+=1
   if total>=L:break
   if loops>10000:raise ValueError('outside terminating projection')
  fraction=f32(quant(X(active)/X(total),64));amount=mul(mul(X(fraction),X(S16(im.H(R+0x16)))),X(L));count=max(1,S16(int(amount)))
 im.H(R+0x14,(S8(im.B(R+0x410))+1)*count)
 for at in range(ROWS+16,ROWS+0xb010,0x58):
  id=S(im.W(at))
  if id in [-1,99999]:continue
  e=U(im.W(0x29620a4)+id*0x330);particle=S16(im.H(e+0x182))
  if im.W(im.W(0x296209c)+particle*4)==R:setcount(im,e,S16(im.H(R+0x14)))
def distance(im,at):
 x,y,z=[X(f32(sub(X(im.F(ORIGIN+j*4)),X(im.F(at+j*4))))) for j in range(3)]
 return f32(add(add(mul(y,y),mul(x,x)),mul(z,z)))
def select(im,threshold):
 chosen=S(im.W(SELECTED))
 if chosen!=-1:
  at=U(ROWS+chosen*0x58)
  if im.W(at+16) not in [0xffffffff,99999] and distance(im,at)==0:return
 im.W(SELECTED,0xffffffff)
 for i in range(512):
  at=ROWS+i*0x58
  if im.W(at+16) in [0xffffffff,99999]:continue
  d=distance(im,at)
  if threshold<0 or d<threshold:im.W(SELECTED,i);threshold=d
class NativeImage:
 def H(self,a,v=None):
  if v is None:return n.unpack('<H',a)[0]
  n.pack('<H',a,v&65535)
 def W(self,a,v):n.pack('<I',a,U(v))
 def write(self,a,b):n.write(a,b)
def hook(mu,a,size,user):
 if a in [0x68cfd0,0x683e90,0x661f60,0x5b3800,0x6e6b90]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a==0x683560:
  sp=mu.reg_read(UC_X86_REG_ESP);at=n.unpack('<I',sp+4)[0];allocate(NativeImage(),at);mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook)
def seed(kind='normalize'):
 writes=[word(0x296209c,TABLE),word(0x29620a4,EMITTER),word(TABLE,R),word(TABLE+4,R2),word(TABLE-4,R),word(SELECTED,-1),flt(R+0xa4,3),flt(R+0x1c,0.125),flt(R+0x20,0.375),flt(R+0x24,0.25),half(R+0x16,60),byte(R+0x410,0),byte(R+0x2e,0),byte(R2+0x2e,7),vector(ORIGIN,[0,0,0])]
 for i in range(512):writes.append(word(ROWS+i*0x58+16,0xffffffff if i%2 else 99999))
 for i in range(16):
  for base in [EMITTER,EMITTER+0x4000]:writes += [half(base+i*0x330+0x182,0 if i%3 else 1),half(base+i*0x330+0x180,0)]
 return dict(kind=kind,writes=writes,count=35,threshold=bits(-1.0),emitter=EMITTER+0x330)
cases=[]
for typ in [0,7]:
 for count in [-2147483648,-2147483637,-65537,-32768,-1025,-385,-33,-32,-31,-12,-11,-1,0,1,11,12,13,31,32,33,383,384,385,1023,1024,1025,32767,32768,65535,65536,2147483636,2147483647]:
  for current in [0,1,32,65535]:
   c=seed('count');c['count']=U(count);c['writes'] += [byte(R+0x2e,typ),half(c['emitter']+0x180,current)];cases.append(c)
for extra in range(256):
 c=seed();c['writes'] += [byte(R+0x410,extra),word(ROWS+16,1),word(ROWS+3*0x58+16,2),word(ROWS+511*0x58+16,4)];cases.append(c)
for lifetime in [0,-0.0,-1,0.015625,0.125,0.4999999701976776,0.5,0.5000000596046448,1,3,7.625,100]:
 for rate in [-32768,-1,0,1,60,32767]:
  for gap in [0,0.125,1]:
   c=seed();c['writes'] += [flt(R+0xa4,lifetime),half(R+0x16,rate),flt(R+0x24,gap),word(ROWS+16,1)];cases.append(c)
for typeid in [0,7]:
 for rate in [1,32,300,1000]:
  c=seed();c['mutate']=True;c['writes'] += [byte(R+0x2e,typeid),half(R+0x16,rate),word(ROWS+16,1),word(ROWS+511*0x58+16,4)];cases.append(c)
rng=random.Random(171013)
for i in range(180):
 c=seed();on=rng.choice([0.015625,0.03125,0.1,0.3,0.7,1.25]);extra=rng.choice([0,0.03125,0.2,0.3]);gap=rng.choice([0,0.125,0.33333334,1]);lifetime=rng.choice([0.01,0.5,1,3.3,7.625,10.2]);c['writes'] += [flt(R+0x1c,on),flt(R+0x20,extra),flt(R+0x24,gap),flt(R+0xa4,lifetime),half(R+0x16,rng.randint(-32768,32767)),byte(R+0x410,rng.randrange(256)),word(ROWS+16,1)];cases.append(c)
for threshold in [-100,-0.0,0,0.25,1,2,3,4,100,float('inf'),float('-inf'),float('nan')]:
 for chosen in [-1,0,511]:
  for dist in [0,1,2]:
   c=seed('select');c['threshold']=bits(threshold);c['writes'] += [word(SELECTED,chosen),word(ROWS+16,1),vector(ROWS,[dist,0,0]),word(ROWS+4*0x58+16,1),vector(ROWS+4*0x58,[1,1,0]),word(ROWS+511*0x58+16,1),vector(ROWS+511*0x58,[0,0,dist])];cases.append(c)
for i in range(128):
 c=seed('select');origin=[rng.choice([0,-0.0,1,0.125,-8,1024]) for _ in range(3)];c['writes'] += [vector(ORIGIN,origin)];c['threshold']=bits(rng.choice([-1,0,1,16,1024]));slots=sorted(rng.sample(range(512),12))
 for slot in slots:
  v=[rng.choice([0,-0.0,1,0.125,-8,1024]) for _ in range(3)];c['writes'] += [word(ROWS+slot*0x58+16,rng.choice([0,1,-2,99998])),vector(ROWS+slot*0x58,v)]
 cases.append(c)
for c in cases:
 im=Image(c);case=c;trace=[]
 if c['kind']=='normalize':normalize(im)
 elif c['kind']=='count':setcount(im,c['emitter'],S(c['count']))
 else:select(im,F(c['threshold']))
 c['model']=dict(sha256=im.hash(),trace=trace.copy(),count=im.H(R+0x14),selected=im.W(SELECTED))
 trace=[];ini=Image(c)
 for a,z,_ in REGIONS:n.write(a,ini.read(a,z))
 if c['kind']=='normalize':n.call(0x68cfd0,regs={UC_X86_REG_ESI:R},count=300000)
 elif c['kind']=='count':n.call(0x683e90,[c['emitter'],c['count']])
 else:n.call(0x661f60,[c['threshold']],count=300000)
 c['expected']=dict(sha256=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest(),trace=trace.copy(),count=n.unpack('<H',R+0x14)[0],selected=n.unpack('<I',SELECTED)[0])
errors=[];checks=0
for i,c in enumerate(cases):
 for key in ['sha256','trace','count','selected']:
  checks+=1
  if c['model'][key]!=c['expected'][key]:errors.append(dict(case=i,kind=c['kind'],key=key,model=c['model'][key],native=c['expected'][key]))
 for key in ['model']:del c[key]
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(cases),checks=checks,mismatches=len(errors),errors=errors[:20],entryCounts=entries,binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS])
(B/'reports/world-phase17-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=report['regions'],cases=cases),separators=(',',':'))+'\n')
(B/'reports/world-phase17-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report))
