import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x96d9c0,0x20,167),(0x96e53c,4,0),(0x971580,0x40,167),(0x9736e8,64,167),(0x97acd0,64,167),(0x80bfa8,96,0)];rot['REGIONS']=REGIONS;rot['common']=[rot['patch'](0x80bfa8,n.read(0x80bfa8,96))];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
P=D+0x2000
from fractions import Fraction
def prepare(im,c):
 if not im.W(0x96e53c):
  for i in range(16):im.W(0x97acd0+i*4,im.W(0x9736e8+i*4))
 inputs=[im.W(c['size']+i*4) for i in range(3)];product=[[N.word(im.W(0x97acd0+row*16+axis*4))*N.word(inputs[row]) for row in range(3)] for axis in range(3)];minimum=[];maximum=[]
 for corner in range(8):
  x,y,z=[N.word(im.W(0x80bfa8+corner*12+i*4)) for i in range(3)]
  for axis in range(3):
   value=(x*product[axis][0]+N.word(im.W(0x97ad00+axis*4))+y*product[axis][1]+z*product[axis][2]).store()
   if corner==0:minimum.append(value);maximum.append(value)
   else:
    if F(value)<F(minimum[axis]):minimum[axis]=value
    if F(value)>F(maximum[axis]):maximum[axis]=value
 im.W(0x9715ac,inputs[2]);im.W(0x9715a8,inputs[1]);im.W(0x9715a4,inputs[0])
 for axis in range(3):mid=(N.word(maximum[axis])+N.word(minimum[axis]))*N(Fraction(1,2));offset=N.word(inputs[axis])*N(Fraction(1,2));im.W(0x96d9c4+axis*4,(mid+N(-offset.v,not offset.neg)).store())
 for axis,w in enumerate(inputs):im.W(0x971584+axis*4,(w&0x80000000)|0x7f800000 if not w&0x7fffffff else N(rot['quant'](1/N.word(w).v,64),bool(w&0x80000000)).store())
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a==0x5d4380:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
identity=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]
def seed(mode=0,size=[1,2,3],matrix=identity,p=P):return dict(size=p,writes=[word(0x96e53c,mode),patch(p,struct.pack('<3f',*size)),patch(0x9736e8,struct.pack('<16f',*matrix)),patch(0x97acd0,struct.pack('<16f',*matrix))])
cases=[seed(mode,[x,y,z]) for mode in [0,1] for x in [-1,0,1,2] for y in [-1,0,1,2] for z in [-1,0,1,2]]
for pointer in [P,0x97acd0,0x97acd4,0x9715a4,0x9715a8,0x96d9c4,0x9736e8]:
 for mode in [0,1]:cases.append(seed(mode,p=pointer))
for value in [0,0x80000000,1,0x80000001,0x007fffff,0x00800000,bits(10000),bits(-10000)]:
 c=seed();c['writes'].append(patch(P,struct.pack('<3I',value,value,value)));cases.append(c)
rng=random.Random(2026101369)
for i in range(256):cases.append(seed(rng.randrange(2),[rng.uniform(-16,16) for j in range(3)],[rng.uniform(-16,16) for j in range(16)]))
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:prepare(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x5d4380,[c['size']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,native=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:12]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase69-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase69-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
