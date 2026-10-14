import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x751100,0x100,0),(0x297c974,4,0),(0x29a9b10,0x1c,0),(0x829a48,4,0),(0,4,0),(0x8298e0,360,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
TABLEDATA=n.read(0x8298e0,360);
P=D+0x1000;REC=D+0x4000;ERR=D+0xf000;trace=[];case={};entries={}
def service(im,a,args):
 if a==0x6f19a6:
  cursor=im.W(0x29a9b14);end=U(cursor+im.W(0x29a9b10)*20)
  while cursor<end:
   if U(args[0]-im.W(cursor+12))<0x100000:return cursor
   cursor=U(cursor+20)
  return 0
 if a==0x6ead5f:
  p=service(im,0x6f0395,[]);return U(p+8) if p else 0x829a48
 if a==0x6ead24:
  code=args[0]
  for i in range(45):
   if im.W(0x8298e0+i*8)==code:return im.W(0x8298e4+i*8)
  if U(code-19)<=17:return 13
  return 22 if U(code-188)>14 else 8
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['thread'] if a==0x6f0395 else case['heapResult'] if a in [HEAP,ALT] else case['lastError'] if a==LAST else case['endpoint']
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
 if a in [0x6e7633,0x6e7689,0x6f0954,0x6f0999,0x6f19a6,0x6ead5f,0x6ead24]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [HEAP,LAST,ALT,0x6f188a,0x6f179a,0x6f19d1,0x6f0395]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if a in [LAST,0x6f0395] else 3 if a in [HEAP,ALT] else 2 if a==0x6f19d1 else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+(count*4 if a in [HEAP,LAST,ALT] else 0))

n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013144);cases=[]
def seed(pointer=P,mode=3,count=3,result=0,thread=ERR-8,code=5):return dict(args=[pointer],heapResult=result,thread=thread,lastError=code,endpoint=0xfedcba98,writes=[word(0x75117c,HEAP),word(0x751190,LAST),word(0x297c974,0xabcdef01),word(0x29a9b28,mode),word(0x29a9b10,count),word(0x29a9b14,REC),word(REC+12,0x10000000),word(REC+32,P),word(REC+52,0xfff80000),word(0,0xffffffff),patch(0x8298e0,TABLEDATA)])
for pointer in [0,P,P+0xfffff,P+0x100000,0xffffffff,0x80000000]:
 for mode in [0,3]:
  for count in [0,1,2,3,0xffffffff]:
   for result in [0,1]:
    for thread in [0,ERR-8]:cases.append(seed(pointer,mode,count,result,thread))
for code in [0,2,5,19,36,188,202,203,0xffffffff]:
 for thread in [0,ERR-8]:cases.append(seed(count=0,thread=thread,code=code))
for i in range(256):cases.append(seed(rng.getrandbits(32),rng.choice([0,3]),rng.randrange(4),rng.getrandbits(32) if i%3 else 0,rng.choice([0,ERR-8]),rng.getrandbits(32)))
for a in [0x6f188a,0x6f19d1,0x6f179a,HEAP,0x6f0395,LAST]:
 for at,value in [(0x29a9b10,0),(REC+12,0),(0x297c974,0x12345678),(0x75117c,ALT),(0x8298e0,5),(0x8298e4,0xffffffff)]:
  c=seed(count=0 if a in [HEAP,0x6f0395,LAST] else 3);c['serviceWrites']={hex(a):[word(at,value)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x6e7633,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase144-20261013-ptl-runtime-free-resolved-cpu.cs').read_bytes()).hexdigest(),domain='actual free/lookup/errno pointer/error mapper; prepared physical header table and shared/thread errno cells; null, wrapped counts, callback mutations and normal no-exception void ABI',additionalAddressCredit=0,nativeAdapters=['CRT lock/unlock and small-block free','HeapFree/GetLastError endpoints','6f0395 no-exit thread acquisition'],syntheticExcluded=0,managedReplayExecuted=False,reaEvidenceIds=["ev_1548f84ffad6268f13b36d361e98bde6366f60ef2775bbe916956e9cb8ed4ea2","ev_f126f0a7e59cf368ee0c772bebf13e25399c578f393fdcafc5f2bbce74d4b04c","ev_6acd32f09a94b3a2f80016a2dce6dcb284ede1cf78d753db12c26b7f04b1cc6a","ev_33e3bcd309202109b7ebb628f82b04eefa94b16df4d6e9423ca3aab6717d8b75"],seconds=round(time.time()-start,3))
(B/'reports/world-phase144-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase144-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
