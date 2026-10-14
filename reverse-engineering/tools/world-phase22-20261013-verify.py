import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
from fractions import Fraction
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;PTR=D+0x1000;R=D+0x3000;R2=D+0x4000
REGIONS=[(D,0x20000,167),(0x296205c,8,0),(0x296209c,4,0),(0x810700,0x800,167),(0x29a9c48,4,0)];rot['REGIONS']=REGIONS;rot['common']=[]
U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];quant=rot['quant']
class Image(rot['Image']):
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
def cvt(im,v):
 x=float(v.v) if im.W(0x29a9c48) else v.v;value=int(x);assert -2147483648<=value<=2147483647;return value
def random_value(im,ptr):
 seed=U(im.W(ptr)*0x19660d+0x3c6ef35f);im.W(ptr,seed);return N.word(bits((seed&0x7fffff)/8388608.0))
def timing(im,em,time):
 t=N.word(time);ticks=cvt(im,t*N(60))
 if not em:return
 physical=rot['signed16'](im.H(em+0x182));r=im.W(U(im.W(0x296209c)+physical*4));clock=N.word(im.W(0x2962060 if im.B(r+0x2f1)==4 else 0x296205c));base=N.word(im.W(r+0x1c));spread=N.word(im.W(r+0x20));pause=N.word(im.W(r+0x24));spread2=N.word(im.W(r+0x28))
 if spread.v!=0 or spread2.v!=0:start=clock
 else:
  period=N.word((base+pause).store());assert period.v>0;cycles=cvt(im,N(quant(clock.v/period.v,64)));boundary=N.word((N(cycles)*period).store())
  if im.B(r+0x2c)==7 and pause.v==0:
   tick=N.word(N(ticks).store());im.H(em+0x1d0,cvt(im,tick*N.word(im.W(r+0x50))));im.H(em+0x1d2,cvt(im,tick*N.word(im.W(r+0x54))));start=boundary+period
  else:start=(t+boundary)+period
  stored=start.store();iterations=0
  while F(stored)>F(clock.store()):
   next=(N.word(stored)-period).store();assert next!=stored;stored=next;iterations+=1;assert iterations<10000
  start=N.word(stored)
 im.W(em+0x1e0,start.store());rv=random_value(im,0x810900);duration=(N.word(im.W(r+0x1c))+N.word(im.W(em+0x1e0)))+(rv*N.word(im.W(r+0x20)));im.W(em+0x1e4,duration.store());im.W(em+0x1dc,bits(-10))
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x655c30,0x5b9d90,0x6e6b90]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed():return dict(kind='timing',emitter=EM,time=bits(0.125),writes=[word(0x296209c,PTR),word(PTR+4,R),word(PTR-8,R2),patch(EM+0x182,struct.pack('<H',1)),word(0x296205c,bits(10)),word(0x2962060,bits(20)),patch(R+0x2f1,b'\0'),patch(R+0x2c,b'\0'),word(R+0x1c,bits(0.5)),word(R+0x20,0),word(R+0x24,bits(0.25)),word(R+0x28,0),word(R+0x50,bits(1.25)),word(R+0x54,bits(-2.5)),word(0x810900,0x12345678),word(0x29a9c48,0)])
cases=[]
for mode in [0,1]:
 for t in [-100,-2,-0.0,0,0.125,0.5,1,2,100,1234.5]:
  for spread in [0,-0.0,0.125,-3]:
   for spread2 in [0,-0.0,0.25]:
    for typ in [0,7]:
     c=seed();c['time']=bits(t);c['writes'] += [word(0x29a9c48,mode),word(R+0x20,bits(spread)),word(R+0x28,bits(spread2)),patch(R+0x2c,bytes([typ]))];cases.append(c)
for mode in [0,1]:
 for clock in [-100,-0.0,0,0.125,0.5,1,3.75,10,1024]:
  for typ in [0,7,255]:
   for pause in [0,-0.0,0.25]:
    c=seed();c['writes'] += [word(0x29a9c48,mode),word(0x296205c,bits(clock)),word(R+0x24,bits(pause)),patch(R+0x2c,bytes([typ]))];cases.append(c)
rng=random.Random(2026101322)
for i in range(300):
 c=seed();period=rng.choice([0.125,0.25,0.5,1,2,3.75]);clock=rng.randrange(-200,200)/8;t=rng.randrange(-200,200)/16;c['time']=bits(t);c['writes'] += [word(R+0x1c,bits(period)),word(R+0x24,0),word(0x296205c,bits(clock)),word(0x2962060,bits(-clock)),patch(R+0x2f1,bytes([rng.choice([0,4,255])])),patch(R+0x2c,bytes([rng.randrange(256)])),word(0x810900,rng.randrange(1<<32)),word(0x29a9c48,i&1)];cases.append(c)
for mode in [0,1]:
 for t in [0,-0.0,0.125,-2,1e-30]:
  c=seed();c.update(emitter=0,time=bits(t));c['writes'].append(word(0x29a9c48,mode));cases.append(c)
for id in [-2,1]:
 c=seed();c['writes'] += [patch(EM+0x182,struct.pack('<H',id&65535)),patch(R2+0x2f1,b'\x04'),patch(R2+0x2c,b'\x07'),word(R2+0x1c,bits(0.5)),word(R2+0x20,0),word(R2+0x24,0),word(R2+0x28,0),word(R2+0x50,bits(2)),word(R2+0x54,bits(3))];cases.append(c)
# Store aliases: timer start / counter fields can update later-read physical fields or RNG state.
for field in [0x1c,0x20,0x24,0x50,0x54]:
 c=seed();alias=EM+0x1e0-field;c['writes'] += [word(PTR+4,alias),patch(alias+0x2f1,b'\0'),patch(alias+0x2c,b'\x07'),word(alias+0x1c,bits(0.5)),word(alias+0x20,bits(0.125)),word(alias+0x24,0),word(alias+0x28,0),word(alias+0x50,bits(2)),word(alias+0x54,bits(3))];cases.append(c)
c=seed();c['emitter']=0x810720;c['writes'] += [patch(0x810720+0x182,struct.pack('<H',1)),word(R+0x20,bits(0.125))];cases.append(c)
for offset in [0x1d0,0x1d2]:
 c=seed();alias=EM+offset-0x54;c['writes'] += [word(PTR+4,alias),patch(alias+0x2f1,b'\0'),patch(alias+0x2c,b'\x07'),word(alias+0x1c,bits(0.5)),word(alias+0x20,0),word(alias+0x24,0),word(alias+0x28,0),word(alias+0x50,bits(2)),word(alias+0x54,bits(3))];cases.append(c)
for sign in [0,1]:
 for exponent in range(255):
  c=seed();c['writes'] += [word(R+0x20,(sign<<31)|(exponent<<23)|0x7fffff),word(R+0x28,bits(1)),word(0x810900,rng.randrange(1<<32))];cases.append(c)
for mode in [0,1]:
 for timebits in [1,0x80000001,0x007fffff,0x807fffff,bits(35791392),bits(-35791392)]:
  c=seed();c['time']=timebits;c['writes'] += [word(R+0x20,bits(0.125)),word(0x29a9c48,mode)];cases.append(c)
for byte in range(256):
 c=seed();c['writes'] += [patch(R+0x2f1,bytes([byte])),word(R+0x20,bits(0.125))];cases.append(c)
for id in [-32768,-32767,-2,0,32767]:
 c=seed();c['writes'] += [patch(EM+0x182,struct.pack('<H',id&65535)),word(0x296209c,U(PTR-id*4)),word(PTR,R),word(R+0x20,bits(0.125))];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);timing(im,c['emitter'],c['time']);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x655c30,[c['emitter'],c['time']],count=1000000)
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest();predicted=im.hash()
 if predicted!=actual:
  errors.append(dict(case=i,actual=actual,model=predicted))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase22-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase22-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
