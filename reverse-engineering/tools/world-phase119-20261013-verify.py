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

trace=[];case={}
def service(im,address,args):
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['pointer'] if address==0x6f0395 else case['fatalResult']
def apply(im,c):
 pointer=service(im,0x6f0395,[])
 if not pointer:service(im,0x6ebd99,[16])
 return pointer
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI();entries={}
def observe(uc,a,z,user):
 if a==0x6f040c:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x6f0395,0x6ebd99]:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<I',sp+4)) if a==0x6ebd99 else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe)
cases=[];rng=random.Random(20261013119)
for i in range(512):cases.append(dict(pointer=rng.getrandbits(32),fatalResult=rng.getrandbits(32),writes=[]))
for pointer in [0,1,0xffffffff,0x80000000,0x7fffffff,D+0x1000]:
 for fatalResult in [0,1,0xffffffff,0x80000000,0x7fffffff]:cases.append(dict(pointer=pointer,fatalResult=fatalResult,writes=[]))
for address in [0x6f0395,0x6ebd99]:
 for pointer in [0,D+0x1000]:
  c=dict(pointer=pointer,fatalResult=0xdeadbeef,writes=[],serviceWrites={hex(address):[word(D+0x1000,0x12345678)]});cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f040c);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,originalBytesSha256=hashlib.sha256(n.read(0x6f040c,24)).hexdigest(),binarySha256=n.sha256,domain='get-pointer child returned value with explicit side effects; null invokes code16 fatal child; own body caches pointer regardless of conditional child result; fatal child return is an explicit suspension projection rather than process-exit recovery',reaEvidenceIds=["ev_a8a01d8436a1680428e488ab7a20680f466feddc44c58ebf651a68568f552ce6"],nativeAdapters=['6f0395 noexit thread acquisition child initially explicit','6ebd99 code16 fatal reporting/exit boundary'],syntheticExcluded=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase119-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase119-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
