import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,0),(0x297cacc,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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




H=0x10300000;ALT=H+0x100;n.mu.mem_map(H,0x1000);n.write(H,b'\xc3');n.write(ALT,b'\xc3');trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['handler'] if a==0x6f01bc else case['result']
def apply(im,c):
 handler=service(im,0x6f01bc,[im.W(0x297cacc)]);return 1 if handler and service(im,handler,c['args']) else 0
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a==0x6f2905:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [H,ALT,0x6f01bc]:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=[n.unpack('<I',sp+4)[0]];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013134);cases=[]
def seed(size=24,handler=H,result=1,encoded=0x12345678):return dict(args=[size],handler=handler,result=result,writes=[word(0x297cacc,encoded)])
for size in [0,1,24,0x214,0x80000000,0xffffffff]:
 for handler in [0,H,ALT]:
  for result in [0,1,0xffffffff,0x80000000]:cases.append(seed(size,handler,result))
for i in range(256):cases.append(seed(rng.getrandbits(32),rng.choice([0,H,ALT]),rng.getrandbits(32),rng.getrandbits(32)))
for a in [0x6f01bc,H,ALT]:
 for value in [0,1,0xffffffff]:
  c=seed(handler=ALT if a==ALT else H);c['serviceWrites']={hex(a):[word(0x297cacc,value)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f2905,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6f2905,34)).hexdigest(),domain='prepared encoded handler cell and cdecl handler endpoint; full0/nonzero normalization and no handler invocation on null decoded pointer; raw caller stack aliases excluded',nativeAdapters=['6f01bc decoder','cdecl new-handler endpoint'],syntheticExcluded=0,reaEvidenceIds=["ev_925150a769fa69bb08781e52b4b77cd49a5d7578242ceac8ecb73a53d0aeb91c"],seconds=round(time.time()-start,3))
(B/'reports/world-phase134-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase134-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
