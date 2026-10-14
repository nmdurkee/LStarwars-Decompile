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

TARGET=0x715718;trace=[];case={}
def apply(im,c):
 trace.append([TARGET,c['args']])
 for p in c.get('mutations',[]):im.write(p['address'],base64.b64decode(p['data']))
 return c['result']
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI();entries={}
def observe(uc,a,z,user):
 if a==0x5c0500:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=TARGET:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<3I',sp+4));assert args==case['args'];rv=apply(ni,case);uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+16)
n.mu.hook_add(UC_HOOK_CODE,observe)
cases=[];rng=random.Random(20261013116);values=[0,1,0xffffffff,0x80000000,0x7fffffff,0xdeadbeef]
for field in range(3):
 for value in values:cases.append(dict(args=[value if i==field else D+0x1000+i*0x100 for i in range(3)],result=value,writes=[]))
for i in range(512):cases.append(dict(args=[rng.getrandbits(32) for j in range(3)],result=rng.getrandbits(32),writes=[]))
for result in values:
 for alias in [D+0x1000,D+0x1100,D+0x1200]:cases.append(dict(args=[alias,D+0x1000,D+0x1100],result=result,writes=[],mutations=[patch(alias,bytes(range(64)))]))
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];case=c;initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x5c0500,c['args']);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,originalBytesSha256=hashlib.sha256(n.read(0x5c0500,21)).hexdigest(),binarySha256=n.sha256,domain='raw wrapperABI forwardsall uint32 words without reading operands; imported endpoint supplies result and controlled memory writes',duplicateAddressCredit=0,reaEvidenceIds=["ev_654195f858af5e866348eb944014723bdc16ad55bc5dd6dcaa11be1cf6faba51"],nativeAdapters=['715718 D3DXMatrixMultiply imported stdcall endpoint'],syntheticExcluded=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase116-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase116-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
