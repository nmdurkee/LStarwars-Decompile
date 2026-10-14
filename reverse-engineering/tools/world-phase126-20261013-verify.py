import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,0),(0x7510b0,16,0),(0x829c00,0x400,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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



ENTER=0x10300000;LEAVE=ENTER+0x100;ALT=ENTER+0x200;n.mu.mem_map(ENTER,0x1000)
for a in [ENTER,LEAVE,ALT]:n.write(a,b'\xc3')
trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['initialize'] if a==0x6f17c7 else case['fatal'] if a==0x6ebd99 else case['endpoint']
def apply(im,c):
 id=c['args'][0];slot=U(0x829c40+id*8)
 if c['entry']=='enter':
  if not im.W(slot) and not service(im,0x6f17c7,[id]):service(im,0x6ebd99,[17])
  p=im.W(slot);return service(im,im.W(0x7510b8),[p])
 p=im.W(slot);return service(im,im.W(0x7510b4),[p])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x6f188a,0x6f179a]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [ENTER,LEAVE,ALT,0x6f17c7,0x6ebd99]:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=[n.unpack('<I',sp+4)[0]];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+(4 if a in [ENTER,LEAVE,ALT] else 0))
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013126);cases=[]
def seed(entry='enter',id=12,p=0,initialize=1):return dict(entry=entry,args=[id],initialize=initialize,fatal=0,endpoint=0xfedcba98,writes=[word(0x7510b8,ENTER),word(0x7510b4,LEAVE),word(U(0x829c40+id*8),p)])
for entry in ['enter','leave']:
 for id in [0,1,12,31,0xffffffff,0x20000000,0x1fffffff]:
  for p in [0,D+0x1000,0xffffffff]:
   for initialize in [0,1,0xffffffff]:cases.append(seed(entry,id,p,initialize))
for i in range(256):
 c=seed(rng.choice(['enter','leave']),rng.randrange(32),rng.getrandbits(32) if i%3 else 0,rng.getrandbits(32) if i%5 else 0);c['endpoint']=rng.getrandbits(32);cases.append(c)
for address in [0x6f17c7,0x6ebd99]:
 for initialize in [0,1]:
  for at,value in [(0x829ca0,D+0x2000),(0x7510b8,ALT),(0x7510b4,ALT)]:
   c=seed(initialize=initialize);c['serviceWrites']={hex(address):[word(at,value)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f188a if c['entry']=='enter' else 0x6f179a,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=dict(enter=hashlib.sha256(n.read(0x6f188a,49)).hexdigest(),leave=hashlib.sha256(n.read(0x6f179a,21)).hexdigest()),domain='prepared lock table slots including wrapped IDs; cached slot address and fresh pointer/import target after lazy initializer or returning fatal suspension',nativeAdapters=['6f17c7 lazy initialization','6ebd99 fatal suspension','Win32 Enter/LeaveCriticalSection'],syntheticExcluded=0,reaEvidenceIds=["ev_362007116303aa0faca000058a1156ed136e83f2719b050b58e6237f8b65af79","ev_5f016e4902632380646d544186fbb423af9037a90a4a368ef3e996f1ce155313"],seconds=round(time.time()-start,3))
(B/'reports/world-phase126-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase126-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
