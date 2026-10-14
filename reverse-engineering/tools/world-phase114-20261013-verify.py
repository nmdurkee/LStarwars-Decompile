import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x97157c,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

def apply(im,c):
 index=S(c['index'])
 return 0 if index<=0 else im.W(U(im.W(0x97157c)+index*4-4))
TABLE=D+0x1000;rng=random.Random(20261013114);cases=[]
def seed(index=1,value=0):return dict(index=U(index),writes=[word(0x97157c,TABLE),word(U(TABLE+U(index)*4-4),value)] if index>0 else [word(0x97157c,0xffffffff)])
for index in [0,-1,-2147483648,-2147483647,1,2,3,255,400,1024,0x40000000,0x40000001,0x7fffffff]:
 for value in [0,1,0xffffffff,0x80000000,0x7fffffff,0xdeadbeef]:cases.append(seed(index,value))
for i in range(512):cases.append(seed(rng.randrange(1,1025),rng.getrandbits(32)))
for index in [1,2,0x40000000,0x40000001,0x7fffffff]:
 c=seed(index,TABLE);c['writes'].append(word(0x97157c,U(0x97157c-index*4+4)));cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);expected=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x5e5310,[c['index']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash():errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected));break
 c['expected']=dict(result=rv,sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entry='0x5e5310',originalBytesSha256=hashlib.sha256(n.read(0x5e5310,22)).hexdigest(),binarySha256=n.sha256,domain='readable positive index-selected cell with wrapped addresses; nonpositive signed indices read neither table nor selected cell',reaEvidenceIds=["ev_718a7ee47cba9c24cd0e41201dfe02e64f77cabf97a09efe964e67b3211942fc"],nativeAdapters=[],syntheticExcluded=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase114-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase114-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
