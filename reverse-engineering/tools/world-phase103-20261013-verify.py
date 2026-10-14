import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
def dot(x,y,z,a,b,c,translate,t):
 v=N.word(x)*N.word(a)+N.word(y)*N.word(b)+N.word(z)*N.word(c)
 if translate:v=v+N.word(t)
 return v.store()

def apply(im,c):
 output,packed,matrix,count=c['args'];count=S(count)
 for i in range(count):
  for col in range(3):
   word=dot(im.W(packed+i*12),im.W(packed+i*12+4),im.W(packed+i*12+8),im.W(matrix+col*4),im.W(matrix+col*4+16),im.W(matrix+col*4+32),True,im.W(matrix+col*4+48))
   if not __import__('math').isfinite(F(word)):raise ValueError('outsidefiniteintermediatedomain')
   im.W(output+i*12+col*4,word)
 return 0
P=D+0x1000;M=D+0x2000;O=D+0x3000;rng=random.Random(20261013103);cases=[]
def seed(count=8,output=O,packed=P,matrix=M):return dict(args=[output,packed,matrix,U(count)],writes=[patch(P,struct.pack('<96f',*[rng.uniform(-10,10) for j in range(96)])),patch(M,struct.pack('<16f',*[rng.uniform(-10,10) for j in range(16)]))])
for count in [-2147483648,-4,-1,0,1,2,3,4,5,7,8,9,15,16,17,31]:
 for i in range(32):cases.append(seed(count,[O,P,M][i%3]))
for count in [1,3,4,5,8,9,17]:
 for base in [P,M]:
  for shift in range(-64,65,4):cases.append(seed(count,base+shift))
for count in [-2147483648,-1,0]:cases.append(dict(args=[0,0xffffffff,1,U(count)],writes=[]))
for mask in range(128):
 c=seed(5);p=[0x80000000 if mask&(1<<(j%3)) else 0 for j in range(15)];m=[bits(-1 if mask&(1<<(j%3+3)) else 1) for j in range(16)];m[12:15]=[0x80000000 if mask&64 else 0]*3;c['writes'] += [patch(P,struct.pack('<15I',*p)),patch(M,struct.pack('<16I',*m))];cases.append(c)
for ignored in [0x7f800000,0xff800000,0x7fc00001,0x7f800001,0xdeadbeef]:
 c=seed()
 for j in [3,7,11,15]:c['writes'].append(word(M+j*4,ignored))
 cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:apply(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x603f10,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,native=actual,model=im.hash(),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for a,z,_ in REGIONS for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors,entry='0x603f10',originalBytesSha256=hashlib.sha256(n.read(0x603f10,497)).hexdigest(),binarySha256=n.sha256,domain='finite prepared image with signed count<=31; all four-point loop/remainder paths, live sequential stores/input and matrix overlaps; nonpositive counts have no input reads',duplicateAddressCredit=0,reaEvidenceIds=["ev_9b967b45b8671c06bc41d9a6ce7f1e575c2b3ec525c056a3dc288228f0ddb57f"],nativeAdapters=[],syntheticExcluded=len(excluded),excluded=excluded,seconds=round(time.time()-start,3))
(B/'reports/world-phase103-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase103-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
