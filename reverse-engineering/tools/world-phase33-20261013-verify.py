import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;PHYS=D+0x3000;CUE=D+0x1000;REGIONS=[(D,0x20000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];S16=rot['signed16'];S8=lambda v:v-256 if v&128 else v
class Image(rot['Image']):
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
row=lambda im,e,f:U(e+S16(im.H(e+0x2c8))*28+f)
def produce(im,c):
 e=c['emitter'];cue=c['cue'];r=c['physical'];t=c['time']
 if not F(im.W(e+0x2cc))<=F(t):return
 count=S16(im.H(e+0x2ca))
 if count>0:im.H(e+0x2ca,count-1);return
 T=N.word(t);im.W(row(im,e,0x200),t)
 for axis in range(3):dest=row(im,e,0x1e8+axis*4);im.W(dest,(N.word(im.W(e+0x190+axis*4))+N.word(im.W(cue+axis*4))).store())
 dest=row(im,e,0x1f4)
 for i in range(3):im.W(dest+i*4,im.W(cue+0x10+i*4))
 im.H(e+0x2c8,im.H(e+0x2c8)+1);rate=S8(im.B(r+0x2f0))
 if S16(im.H(e+0x2c8))>=rate:im.H(e+0x2c8,0)
 if c['latch']:im.H(e+0x2ca,im.H(e+0x2c8))
 rate=S8(im.B(r+0x2f0));life=im.W(r+0xa4)
 if rate==0:im.W(e+0x2cc,0xffc00000 if not(life&0x7fffffff) else (life&0x80000000)|0x7f800000)
 else:
  L=N.word(life);delay=N(rot['quant'](L.v/rate,64),L.neg!=(rate<0));im.W(e+0x2cc,(T+delay).store())
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a==0x656080:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))
def seed():return dict(emitter=EM,cue=CUE,physical=PHYS,time=bits(1),latch=0,writes=[half(EM+0x2c8,0),half(EM+0x2ca,0),word(EM+0x2cc,bits(0)),patch(EM+0x190,struct.pack('<3f',1.25,-2.5,-0.0)),patch(CUE,struct.pack('<3f',0.5,0.25,-0.0)),patch(CUE+0x10,struct.pack('<3I',0xffffffff,0x7f800001,0x12345678)),byte(PHYS+0x2f0,4),word(PHYS+0xa4,bits(0.5))])
cases=[]
for last in [bits(-1),0,0x80000000,bits(1),bits(2),0x7f800000,0xff800000,0x7fc12345,0xffc12345]:
 for countdown in [-32768,-1,0,1,2,32767]:
  for latch in [0,1,0xffffffff]:c=seed();c.update(latch=latch);c['writes'] += [word(EM+0x2cc,last),half(EM+0x2ca,countdown)];cases.append(c)
for rate in range(1,256):
 for index in [-2,-1,0,1,3,7,8,31]:
  c=seed();c['writes'] += [byte(PHYS+0x2f0,rate),half(EM+0x2c8,index)]
  if index==8:c['writes'].append(word(EM+0x190,bits(0.5)))
  cases.append(c)
for timebits in [0,0x80000000,1,0x80000001,bits(-3.75),bits(1),bits(100),0x7f7fffff,0xff7fffff]:
 for life in [0,0x80000000,1,0x80000001,bits(0.5),bits(-2.5),0x7f7fffff,0xff7fffff]:
  c=seed();c['time']=timebits;c['writes'] += [word(EM+0x2cc,0xff800000),word(PHYS+0xa4,life),byte(PHYS+0x2f0,127)];cases.append(c)
for timebits in [0x7f800000,0xff800000,0x7fc00001]:
 c=seed();c['time']=timebits;c['writes'] += [word(EM+0x2cc,0xff800000),half(EM+0x2ca,1)];cases.append(c)
# A zero rate is allowed on gated/countdown-only paths and receives no creation credit.
for last,countdown in [(bits(2),0),(bits(0),1)]:c=seed();c['writes'] += [byte(PHYS+0x2f0,0),word(EM+0x2cc,last),half(EM+0x2ca,countdown)];cases.append(c)
rng=random.Random(2026101333)
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0xff7fffff,bits(1),bits(-1),bits(0.125)]
for i in range(256):
 c=seed();c['time']=bits(rng.randrange(-10,10)/8);c['writes'] += [word(EM+0x2cc,0xff800000),patch(EM+0x190,struct.pack('<3I',*[rng.choice(choices) for _ in range(3)])),patch(CUE,struct.pack('<3I',*[rng.choice(choices) for _ in range(3)])),byte(PHYS+0x2f0,rng.randrange(1,256))];cases.append(c)
# Live index rewrite by X store: index8 row X aliases index/countdown word.
for latch in [0,1]:c=seed();c['latch']=latch;c['writes'] += [half(EM+0x2c8,8),word(EM+0x190,bits(0.5))];cases.append(c)
# Raw attributes replace signed rate before wrap and deadline division.
c=seed();c['physical']=EM;c['writes'] += [half(EM+0x2c8,9),byte(EM+0x2f0,4),word(EM+0xa4,bits(0.5)),word(CUE+0x10,2)];cases.append(c)
for life in [0,0x80000000,1,0x80000001,bits(0.5),bits(-0.5),0x7f7fffff,0xff7fffff]:
 for latch in [0,1]:
  c=seed();c['latch']=latch;c['writes'] += [byte(PHYS+0x2f0,0),word(PHYS+0xa4,life)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);produce(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x656080,[c['cue'],c['time'],c['physical'],c['emitter'],c['latch']])
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase33-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase33-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
