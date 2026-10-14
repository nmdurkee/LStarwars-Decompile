import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x20000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
EM=D+0x4000;R=D+0x8000
def bounds(im,c):
 r=c['record'];e=c['emitter'];matrix=[im.W(e+0x40+i*4) for i in range(16)]
 for i in range(3):matrix[12+i]=(N.word(matrix[12+i])+N.word(im.W(e+0x190+i*4))).store()
 drift=N.word(im.W(r+0x20))+N.word(im.W(r+0x1c));extents=[]
 extents.append((N.word(im.W(r+0x4c))*N.word(im.W(r+0xa4))+N.word(im.W(r+0x64)&0x7fffffff)*drift+N.word(im.W(r+0x58))).store());extents.append(((N.word(im.W(r+0x50))+N.word(im.W(r+0x48)&0x7fffffff))*N.word(im.W(r+0xa4))+N.word(im.W(r+0x68)&0x7fffffff)*drift+N.word(im.W(r+0x5c))).store());extents.append((N.word(im.W(r+0x54))*N.word(im.W(r+0xa4))+N.word(im.W(r+0x6c)&0x7fffffff)*drift+N.word(im.W(r+0x60))).store())
 output=[]
 for i in range(3):output.append((N.word(extents[0])*N.word(im.W(e+0x80+i*4))+N.word(extents[1])*N.word(im.W(e+0x90+i*4))+N.word(extents[2])*N.word(im.W(e+0xa0+i*4))).store())
 padding=(N.word(im.W(r+0x14c))*N.word(0x38d1b717)).store()
 for i in range(3):absolute=output[i]^0x80000000 if F(output[i])<0 else output[i];expanded=(N.word(absolute)+N.word(padding)).store();output[i]=(N.word(expanded)+N.word(0x3e4ccccd)).store()
 minimum=[v^0x80000000 for v in output];acceleration=im.W(r+0xa0)
 if F(acceleration)>0:output[1]=(N.word(im.W(r+0xa4))*N.word(acceleration)*N.word(im.W(r+0xa4))+N.word(output[1])).store()
 elif F(acceleration)<0:minimum[1]=(N.word(im.W(r+0xa4))*N.word(acceleration)*N.word(im.W(r+0xa4))+N.word(minimum[1])).store()
 xz=output[0] if F(output[2])<F(output[0]) else output[2];negativeY=minimum[1]^0x80000000;y=output[1] if F(negativeY)<F(output[1]) else negativeY
 radius=(negativeY if F(output[1])<=F(negativeY) else output[1]) if F(xz)<=F(y) else (output[0] if F(output[2])<F(output[0]) else output[2])
 for field,value in [(0x300,radius),(0x304,minimum[0]),(0x308,minimum[1]),(0x310,output[0]),(0x30c,minimum[2]),(0x314,output[1]),(0x318,output[2])]:im.W(e+field,value)
 for i in range(16):im.W(e+i*4,matrix[i])
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x656e50,0x64ff80,0x5b4900,0x5b3200]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
identity=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]
def seed(acceleration=0,lifetime=1,padding=0,matrix=identity,record=R):
 c=dict(record=record,emitter=EM,writes=[patch(EM+0x40,struct.pack('<16f',*identity)),patch(EM+0x80,struct.pack('<16f',*matrix)),patch(EM+0x190,struct.pack('<3f',1.25,-2.5,-0.0)),word(record+0x1c,bits(1)),word(record+0x20,bits(2)),word(record+0x14c,bits(padding)),word(record+0xa0,bits(acceleration)),word(record+0xa4,bits(lifetime)),patch(record+0x48,struct.pack('<10f',.5,1,-2,3,4,-5,6,-.25,.5,-.75))]);return c
cases=[seed(a,t,p) for a in [-4,-1,0,1,4] for t in [-2,0,1,4] for p in [-10000,0,1,1000]]
for matrix in [identity,[-v for v in identity],[0]*16,[.5,-.25,1,0,1,-2,.25,0,-.5,1,2,0,0,0,0,1]]:
 for acceleration in [-1,0,1]:
  for padding in [-10000,0,1000]:cases.append(seed(acceleration=acceleration,padding=padding,matrix=matrix))
for record in [EM,EM+0x200,EM+0x2b0,EM+0x300-0xa0]:cases.append(seed(record=record))
rng=random.Random(2026101365)
for i in range(256):
 c=seed(rng.uniform(-16,16),rng.uniform(-4,4),rng.uniform(-10000,10000),[rng.uniform(-4,4) for j in range(16)])
 for field in [0x1c,0x20,0x48,0x4c,0x50,0x54,0x58,0x5c,0x60,0x64,0x68,0x6c]:c['writes'].append(word(R+field,bits(rng.uniform(-16,16))))
 cases.append(c)
for value in [0,0x80000000,1,0x80000001,bits(1),bits(-1)]:
 for padding in [-2000,-2000.0001220703125,0,2000]:
  c=seed(padding=padding,matrix=identity)
  for field in [0x1c,0x20,0x48,0x4c,0x50,0x54,0x58,0x5c,0x60,0x64,0x68,0x6c]:c['writes'].append(word(R+field,value))
  cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:bounds(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x656e50,[c['record'],c['emitter']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,native=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:12]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase65-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase65-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
