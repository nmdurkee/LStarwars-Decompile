import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(0x8298e0,360,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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



TABLEDATA=n.read(0x8298e0,360);rng=random.Random(20261013137);cases=[]
def apply(im,c):
 code=c['args'][0]
 for i in range(45):
  if im.W(0x8298e0+i*8)==code:return im.W(0x8298e4+i*8)
 if U(code-19)<=17:return 13
 return 22 if U(code-188)>14 else 8
def seed(code):return dict(args=[code],writes=[patch(0x8298e0,TABLEDATA)])
for code in list(range(300))+[0x7fffffff,0x80000000,0xffffffff]:cases.append(seed(code))
for i in range(512):cases.append(seed(rng.getrandbits(32)))
for i in range(45):
 for code in [0,19,188,0xffffffff]:
  c=seed(code);c['writes']+=[word(0x8298e0+i*8,code),word(0x8298e4+i*8,0xa0000000+i)];cases.append(c)
for i in range(128):
 c=seed(rng.randrange(256))
 for j in range(45):c['writes']+=[word(0x8298e0+8*j,rng.randrange(256)),word(0x8298e4+8*j,rng.getrandbits(32))]
 cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);expected=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6ead24,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash():errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected));break
 c['expected']=dict(sha256=actual,result=rv);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6ead24,59)).hexdigest(),originalTableSha256=hashlib.sha256(TABLEDATA).hexdigest(),domain='full uint codes; original45-row runtime table and prepared mutations including duplicate keys/first hit; exact wrapped secondary intervals',nativeAdapters=[],syntheticExcluded=0,reaEvidenceIds=["ev_33e3bcd309202109b7ebb628f82b04eefa94b16df4d6e9423ca3aab6717d8b75"],seconds=round(time.time()-start,3))
(B/'reports/world-phase137-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase137-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
