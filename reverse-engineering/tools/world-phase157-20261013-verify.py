import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x829ac0,184,0),(0xf0000000,0x10000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

n.mu.mem_map(0xf0000000,0x10000);TABLEDATA=n.read(0x829ac0,184);entries={}
def length(im,p):
 cursor=p
 while cursor&3:
  value=im.B(cursor);cursor=U(cursor+1)
  if not value:return U(cursor-1-p)
 while True:
  value=im.W(cursor);flags=U((~value)^U(value+0x7efefeff));cursor=U(cursor+4)
  if not flags&0x81010100:continue
  value=im.W(cursor-4)
  for j in range(4):
   if not (value>>(j*8))&255:return U(cursor-4+j-p)
def apply(im,c):
 if c['entry']==0x6edd80:return length(im,c['args'][0])
 for i in range(23):
  if im.W(0x829ac0+i*8)==c['args'][0]:return im.W(0x829ac4+i*8)
 return 0
from unicorn import UC_HOOK_CODE
def observe(uc,a,z,u):
 if a in [0x6edd80,0x6f0b98]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013157);cases=[]
for base in [D,0xf0000000]:
 for offset in range(16):
  for size in list(range(32))+[63,64,127,128,255,256,511,512,1000]:
   p=base+0x100+offset;content=bytes(rng.randrange(1,256) for _ in range(size))+bytes([0])+bytes(rng.getrandbits(8) for _ in range(8));cases.append(dict(entry=0x6edd80,args=[p],writes=[patch(p,content)]))
for i in range(256):
 code=struct.unpack_from('<I',TABLEDATA,(i%23)*8)[0] if i<128 else rng.getrandbits(32);c=dict(entry=0x6f0b98,args=[code],writes=[patch(0x829ac0,TABLEDATA)])
 if i%3==0:c['writes'] += [word(0x829ac0+(i%23)*8,code),word(0x829ac4+(i%23)*8,rng.getrandbits(32))]
 if i%5==0:c['writes'] += [word(0x829ac0,code),word(0x829ac4,rng.getrandbits(32))]
 cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);expected=apply(im,c);initial=Image(c)
 for address,size,fill in REGIONS:n.write(address,initial.read(address,size))
 result=n.call(c['entry'],c['args'],count=100000);actual=hashlib.sha256(b''.join(n.read(address,size) for address,size,fill in REGIONS)).hexdigest()
 if result!=expected or actual!=im.hash():errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=result,modelResult=expected));break
 c['expected']=dict(result=result,sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase157-20261013-ptl-runtime-string-length.cs').read_bytes()).hexdigest(),originalBodies=[dict(address=hex(a),length=z,sha256=hashlib.sha256(n.read(a,z)).hexdigest()) for a,z in [(0x6edd80,139),(0x6f0b98,32)]],domain='NUL strings with readable aligned DWORD tail, low/high unsigned addresses and every alignment; fixed 23-row first-match diagnostic lookup with duplicates/missing keys; no ports or image writes',nativeAdapters=[],reaEvidenceIds=['ev_320838c3d0c8e4a9104d89d09cfff86b1cde26a00e0ae3899dc1cf5e0a5360d9'],rawLookupEvidence='Ghidra function manager does not expose raw 6F0B98 entry; exact 32 original bytes and native execution retained',managedReplayExecuted=False,seconds=round(time.time()-start,3))
(B/'reports/world-phase157-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase157-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
