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
 output,left,right=c['args'];temporary=output==left or output==right;values=[]
 for row in range(4):
  for col in range(3):
   word=dot(im.W(left+row*16),im.W(left+row*16+4),im.W(left+row*16+8),im.W(right+col*4),im.W(right+col*4+16),im.W(right+col*4+32),row==3,im.W(right+col*4+48) if row==3 else 0)
   if not __import__('math').isfinite(F(word)):raise ValueError('outsidefiniteintermediateresultdomain')
   if temporary:values.append(word)
   else:im.W(output+row*16+col*4,word)
  end=bits(1) if row==3 else 0
  if temporary:values.append(end)
  else:im.W(output+row*16+12,end)
 if temporary:
  for i,word in enumerate(values):im.W(output+i*4,word)
 return 0
LEFT=D+0x1000;RIGHT=D+0x1100;OUTPUT=D+0x1200;rng=random.Random(20261013102);cases=[]
def seed(output=OUTPUT,left=LEFT,right=RIGHT):
 l=[bits(rng.uniform(-16,16)) for i in range(16)];r=[bits(rng.uniform(-16,16)) for i in range(16)]
 return dict(args=[output,left,right],writes=[patch(LEFT,struct.pack('<16I',*l)),patch(RIGHT,struct.pack('<16I',*r))])
for i in range(768):cases.append(seed([OUTPUT,LEFT,RIGHT][i%3]))
for base in [LEFT,RIGHT]:
 for shift in range(-64,65,4):
  c=seed(base+shift);cases.append(c)
for mask in range(128):
 c=seed();l=[0x80000000 if mask&(1<<(i%3)) else 0 for i in range(16)];r=[bits(-1 if mask&(1<<(i%3+3)) else 1) for i in range(16)];r[12:15]=[0x80000000 if mask&64 else 0]*3;c['writes'] += [patch(LEFT,struct.pack('<16I',*l)),patch(RIGHT,struct.pack('<16I',*r))];cases.append(c)
for alias in [OUTPUT,LEFT,RIGHT]:
 c=seed(alias,LEFT,LEFT);cases.append(c)
for ignored in [0x7fc00001,0x7f800001,0x7f800000,0xff800000,0xdeadbeef]:
 c=seed()
 for a in [LEFT,RIGHT]:
  for j in [3,7,11,15]:c['writes'].append(word(a+j*4,ignored))
 cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:apply(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x5b5430,c['args']);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,native=actual,model=im.hash(),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for a,z,_ in REGIONS for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors,entry='0x5b5430',originalBytesSha256=hashlib.sha256(n.read(0x5b5430,706)).hexdigest(),binarySha256=n.sha256,domain='finite prepared memory; exact output/input aliases use private buffer, other overlaps store sequentially; ignored perspective words all bits',duplicateAddressCredit=0,reaEvidenceIds=["ev_f38354640510002d99d11e38b917f3bb393f274bf46e6c66bd17f7f80454f587"],nativeAdapters=[],syntheticExcluded=len(excluded),excluded=excluded,seconds=round(time.time()-start,3))
(B/'reports/world-phase102-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase102-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
