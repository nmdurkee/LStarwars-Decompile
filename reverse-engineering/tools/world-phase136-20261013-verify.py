import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x751100,0x100,0),(0x297c974,4,0),(0x29a9b28,4,0),(0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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


HEAP=0x10300000;LAST=HEAP+0x100;ALT=HEAP+0x200;n.mu.mem_map(HEAP,0x1000)
for a in [HEAP,LAST,ALT]:n.write(a,b'\xc3')
P=D+0x1000;ERR=D+0xf000;trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['header'] if a==0x6f19a6 else case['heapResult'] if a in [HEAP,ALT] else ERR if a==0x6ead5f else case['lastError'] if a==LAST else case['mappedError'] if a==0x6ead24 else case['endpoint']
def apply(im,c):
 p=c['args'][0]
 if not p:return
 if im.W(0x29a9b28)==3:
  service(im,0x6f188a,[4]);header=service(im,0x6f19a6,[p])
  if header:service(im,0x6f19d1,[header,p])
  service(im,0x6f179a,[4])
  if header:return
 if not service(im,im.W(0x75117c),[im.W(0x297c974),0,p]):
  error=service(im,0x6ead5f,[]);code=service(im,im.W(0x751190),[]);im.W(error,service(im,0x6ead24,[code]))
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x6e7633,0x6e7689,0x6f0954,0x6f0999]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [HEAP,LAST,ALT,0x6f188a,0x6f179a,0x6f19a6,0x6f19d1,0x6ead5f,0x6ead24]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if a in [LAST,0x6ead5f] else 3 if a in [HEAP,ALT] else 2 if a==0x6f19d1 else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+(count*4 if a in [HEAP,LAST,ALT] else 0))
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013136);cases=[]
def seed(p=P,mode=3,header=P+0x100,heapResult=1):return dict(args=[p],header=header,heapResult=heapResult,lastError=0x12345678,mappedError=22,endpoint=0xfedcba98,writes=[word(0x75117c,HEAP),word(0x751190,LAST),word(0x297c974,0xabcdef01),word(0x29a9b28,mode),word(0,0xffffffff)])
for p in [0,P,0xffffffff,0x80000000]:
 for mode in [0,3,0xffffffff]:
  for header in [0,P+0x100,0xffffffff]:
   for result in [0,1,0xffffffff]:cases.append(seed(p,mode,header,result))
for i in range(256):
 c=seed(rng.getrandbits(32),rng.choice([0,3]),rng.choice([0,P+0x100]),rng.getrandbits(32) if i%3 else 0);c.update(lastError=rng.getrandbits(32),mappedError=rng.getrandbits(32),endpoint=rng.getrandbits(32));cases.append(c)
for a in [0x6f188a,0x6f19a6,0x6f19d1,0x6f179a,HEAP,0x6ead5f,LAST,0x6ead24]:
 for header in [0,P+0x100]:
  for at,value in [(0x297c974,0x13579bdf),(0x29a9b28,0),(0x75117c,ALT),(ERR,0xffffffff)]:
   c=seed(header=header,heapResult=0);c['serviceWrites']={hex(a):[word(at,value)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6e7633,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6e7633,86)+n.read(0x6e7692,47)).hexdigest(),domain='normal no-exception void cdecl semantics; cached original pointer/small-header/errno pointer across callback mutations; null no services; SEH chain restored; incidental EAX and raw stack aliases excluded',nativeAdapters=['CRT lock/unlock and small block locate/free','HeapFree/GetLastError endpoints','errno getter/map'],syntheticExcluded=0,reaEvidenceIds=["ev_1548f84ffad6268f13b36d361e98bde6366f60ef2775bbe916956e9cb8ed4ea2","ev_ff8aa5b02e6301d79b5f95dfa339f4a9308c07d88ce044384f5500e8ef62754f"],seconds=round(time.time()-start,3))
(B/'reports/world-phase136-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase136-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
