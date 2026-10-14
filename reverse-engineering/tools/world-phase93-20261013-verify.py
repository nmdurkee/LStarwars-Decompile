import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x297d690,0x420,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
TABLE=0x297d698
def initialize(im,receiver):
 for i in range(256):
  crc=i<<8
  for b in range(8):crc=((crc<<1)^(0x1021 if crc&0x8000 else 0))&65535
  im.W(TABLE+i*4,crc)
 return receiver
def checksum(im,c):
 crc=65535;p=c['point'];length=S(c['length'])
 if c['entry']==0x7462f0:p=U(p+length)
 for i in range(max(0,length)):
  if c['entry']==0x7462f0:p=U(p-1)
  value=im.B(p);index=((crc>>8)^value)&255;crc=((crc<<8)^im.W(TABLE+index*4))&65535
  if c['entry']==0x7462b0:p=U(p+1)
 return crc
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
entries={}
def observe(uc,a,z,user):
 if a in [0x7461b0,0x7462b0,0x7462f0]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(e):return dict(entry=e,point=P,length=104,initialize=True,receiver=0xdeadbeef,writes=[patch(P,bytes(range(256))*16)])
cases=[];rng=random.Random(2026101393)
for receiver in [0,1,0xffffffff,0x80000000]+[rng.getrandbits(32) for i in range(16)]:c=seed(0x7461b0);c['receiver']=receiver;cases.append(c)
for e in [0x7462b0,0x7462f0]:
 for length in [-2147483648,-1,0,1,2,3,7,8,15,16,31,32,63,64,103,104,105,255,256,511,512,4096]:
  c=seed(e);c['length']=U(length)
  if length<=0:c['point']=rng.choice([0,0xffffffff,P])
  cases.append(c)
 for shift in range(-4,17):c=seed(e);c['point']=TABLE+shift;cases.append(c)
 for i in range(128):
  c=seed(e);c['length']=rng.randrange(4097);c['writes'] += [patch(P,bytes(rng.randrange(256) for j in range(c['length'])))];cases.append(c)
 for i in range(64):
  c=seed(e);c['initialize']=False;c['length']=rng.randrange(257);c['writes'] += [patch(TABLE,struct.pack('<256I',*[rng.getrandbits(32) for j in range(256)]))];cases.append(c)
rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 im=Image(c);init=c['entry']==0x7461b0 or c['initialize']
 if init:initialize(im,c['receiver'])
 pred=c['receiver'] if c['entry']==0x7461b0 else checksum(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 if init:
  got=n.call(0x7461b0,regs={UC_X86_REG_ECX:c['receiver']})
  if got!=c['receiver']:errors.append(dict(case=i,initializerEAX=got,receiver=c['receiver']));break
 rv=got if c['entry']==0x7461b0 else n.call(c['entry'],[c['point'],c['length']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest();checks+=2+(init and c['entry']!=0x7461b0)
 if rv!=pred or actual!=im.hash():errors.append(dict(case=i,entry=hex(c['entry']),native=actual,model=im.hash(),nativeResult=rv,modelResult=pred));break
 c['expected']=dict(sha256=actual,result=rv);rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase93-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase93-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
