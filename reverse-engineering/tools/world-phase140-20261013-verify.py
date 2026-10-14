import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x29a9b18,4,0),(0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

if not any(begin<=0<=end for begin,end,_ in n.mu.mem_regions()):n.mu.mem_map(0,0x1000)


P=D+0x1000;trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['allocation'] if a==0x6f25d1 else case['endpoint']
def apply(im,c):
 size=c['args'][0]
 if size>im.W(0x29a9b18):return 0
 service(im,0x6f188a,[4]);result=service(im,0x6f25d1,[size]);service(im,0x6f179a,[4]);return result
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x6e74ac,0x6e74f2,0x6f0954,0x6f0999]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x6f188a,0x6f179a,0x6f25d1]:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=[n.unpack('<I',sp+4)[0]];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013140);cases=[]
def seed(size=24,threshold=100,allocation=P):return dict(args=[size],allocation=allocation,endpoint=0xfedcba98,writes=[word(0x29a9b18,threshold),word(0,0xffffffff)])
for size in [0,1,24,100,101,0x7fffffff,0x80000000,0xffffffff]:
 for threshold in [0,24,100,0x7fffffff,0x80000000,0xffffffff]:
  for allocation in [0,P,0xffffffff]:cases.append(seed(size,threshold,allocation))
for i in range(256):
 c=seed(rng.getrandbits(32),rng.getrandbits(32),rng.getrandbits(32));c['endpoint']=rng.getrandbits(32);cases.append(c)
for a in [0x6f188a,0x6f25d1,0x6f179a]:
 for at,value in [(0x29a9b18,0),(0x29a9b18,0xffffffff),(P,0),(P,0xffffffff)]:
  c=seed();c['serviceWrites']={hex(a):[word(at,value)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6e74ac,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6e74ac,70)).hexdigest(),sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase140-20261013-ptl-small-malloc.cs').read_bytes()).hexdigest(),domain='normal no-exception prepared threshold cell and explicit small-block service; unsigned gate/cached result survives callback mutations; actual SEH/frame/finally children',nativeAdapters=['CRT lock/unlock','6f25d1 small-block allocator'],syntheticExcluded=0,managedReplayExecuted=False,reaEvidenceIds=["ev_913a64841cb34d82dfc561099750e466fbd91953d5b003ff7b67af037546d864"],seconds=round(time.time()-start,3))
(B/'reports/world-phase140-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase140-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
