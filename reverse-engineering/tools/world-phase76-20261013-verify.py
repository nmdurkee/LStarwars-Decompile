import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x973660,0x180,167),(0x80b680,0x180,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

P=D+0x1000
quiet=lambda w:w|0x400000 if w&0x7fffffff>0x7f800000 else w
def apply(im,c):
 dest=c['destination']
 if c['entry']==0x5d60c0:
  for i in range(30):im.W(dest+i*4,im.W(0x9736e8+i*4))
 else:
  for row in range(3):
   for col,neg in [(0,True),(1,False),(2,True)]:im.W(dest+col*16+row*4,quiet(im.W(0x80b708+row*16+col*4))^(0x80000000 if neg else 0))
  for off in [0x2c,0x1c,0x0c]:im.W(dest+off,0)
  im.W(dest+0x3c,0x3f800000)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x5d60c0,0x5edd70]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(e,d=P):return dict(entry=e,destination=d,writes=[])
words=[(sign<<31)|(exponent<<23)|f for sign in [0,1] for exponent in range(256) for f in [0,1,0x3fffff,0x400000,0x7fffff]]
cases=[];rng=random.Random(2026101376)
for i in range(0,len(words),30):
 c=seed(0x5d60c0);chunk=words[i:i+30];chunk += [0]*(30-len(chunk));c['writes'] += [patch(0x9736e8,struct.pack('<30I',*chunk))];cases.append(c)
for shift in range(-120,121):
 c=seed(0x5d60c0,0x9736e8+shift);c['writes'] += [patch(0x9736e8,bytes(rng.randrange(256) for i in range(120)))];cases.append(c)
consumed=[w for w in words if w&0x7fffffff<=0x7f800000 or w&0x400000]
for i in range(0,len(consumed),9):
 c=seed(0x5edd70);chunk=consumed[i:i+9];chunk += [0]*(9-len(chunk))
 for row in range(3):c['writes'] += [patch(0x80b708+row*16,struct.pack('<3I',*chunk[row*3:row*3+3]))]
 cases.append(c)
for shift in range(-64,65,4):
 c=seed(0x5edd70,0x80b708+shift)
 for row in range(3):c['writes'] += [patch(0x80b708+row*16,struct.pack('<3f',*[rng.uniform(-100,100) for i in range(3)]))]
 cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(c['entry'],[c['destination']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():errors.append(dict(case=i,entry=hex(c['entry']),native=actual,model=im.hash()));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors,entryCounts=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=0,consumedSignalingNaNDomain='excluded from BasisModifier domain; allbits raw CopyCamera retained')
(B/'reports/world-phase76-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase76-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
