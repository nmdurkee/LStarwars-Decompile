import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x1000,167),(0x829a48,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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



trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('writesByThread',[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['thread']
def apply(im,c):
 p=service(im,0x6f0395,[]);return U(p+8) if p else 0x829a48
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a==0x6ead5f:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=0x6f0395:return
 sp=uc.reg_read(UC_X86_REG_ESP);rv=service(ni,a,[]);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013142);cases=[dict(thread=t,writes=[]) for t in [0,1,D,0x829a40,0xfffffff7,0xfffffff8,0xffffffff,0x80000000]]
for i in range(512):cases.append(dict(thread=rng.getrandbits(32),writes=[]))
for thread in [0,D,0xfffffff8]:
 for at,value in [(D,0),(D+8,0xffffffff),(0x829a48,0x12345678)]:cases.append(dict(thread=thread,writes=[],writesByThread=[word(at,value)]))
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6ead5f,[],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6ead5f,19)).hexdigest(),sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase142-20261013-ptl-errno-pointer.cs').read_bytes()).hexdigest(),domain='all uint thread acquisition returns; no dereference of returned thread; cached return, shared fallback and uint wrapping verified',nativeAdapters=['6f0395 no-exit thread acquisition'],syntheticExcluded=0,managedReplayExecuted=False,reaEvidenceIds=["ev_6acd32f09a94b3a2f80016a2dce6dcb284ede1cf78d753db12c26b7f04b1cc6a"],seconds=round(time.time()-start,3))
(B/'reports/world-phase142-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase142-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
