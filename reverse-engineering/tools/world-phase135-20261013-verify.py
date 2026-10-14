import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x751184,4,0),(0x297c974,4,0),(0x297cacc,8,0),(0x29a9c48,4,0),(0x29a9b18,0x14,0),(0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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


HEAP=0x10300000;ALT=HEAP+0x100;HANDLER=HEAP+0x200;n.mu.mem_map(HEAP,0x1000);n.write(HEAP,b'\xc3');n.write(ALT,b'\xc3');n.write(HANDLER,b'\xc3');P=D+0x1000;ERR=D+0xf000;trace=[];case={};counts={};entries={}
def service(im,a,args):
 if a==0x6e6950:
  out,value,length=args
  if not value and length>=256 and im.W(0x29a9c48):return zero(im,out,length)
  im.write(out,bytes([value&255])*length);return out
 if a==0x6f2905:
  handler=service(im,0x6f01bc,[im.W(0x297cacc)]);return 1 if handler and service(im,handler,args) else 0
 key=hex(a);index=counts.get(key,0);counts[key]=index+1;trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 seq=case.get('sequenceWrites',{}).get(key,[])
 if index<len(seq):
  for p in seq[index]:im.write(p['address'],base64.b64decode(p['data']))
 if a==0x6ead5f:return ERR
 if a==0x6f01bc:return case.get('handler',HANDLER)
 if a==0x6e6950:im.write(args[0],bytes([args[1]&255])*args[2]);return args[0]
 values=case['smallResults'] if a==0x6f25d1 else case['heapResults'] if a in [HEAP,ALT] else case['newResults'] if a==HANDLER else [0xfedcba98];return values[min(index,len(values)-1)]
def blocks(im,out,length,eax):im.write(out,bytes((length>>7)*128));return eax
def zero(im,out,length):
 rem=S(out)%16 if S(out)>=0 else -((-S(out))%16)
 if rem:
  head=16-rem;im.write(out,bytes(head));zero(im,U(out+head),U(length-head));return out
 tail=length&127
 if length!=tail:blocks(im,out,length-tail,out)
 if tail:im.write(U(out+length-tail),bytes(tail))
 return out
def apply(im,c):
 count,size,error=c['args']
 if count and size>0xffffffe0//count:
  p=service(im,0x6ead5f,[]);im.W(p,12);service(im,0x6e9fc2,[0]*5);return 0
 requested=U(count*size);allocation=requested or 1
 while True:
  result=0
  if allocation<=0xffffffe0:
   if im.W(0x29a9b28)==3:
    allocation=U(allocation+15)&0xfffffff0
    if requested<=im.W(0x29a9b18):
     service(im,0x6f188a,[4]);result=service(im,0x6f25d1,[requested]);service(im,0x6f179a,[4])
     if result:service(im,0x6e6950,[result,0,requested])
   if not result:result=service(im,im.W(0x751184),[im.W(0x297c974),8,allocation])
  if result:return result
  if im.W(0x297cad0) and service(im,0x6f2905,[allocation]):continue
  if error:im.W(error,12)
  return 0
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x6eae5c,0x6eaf58,0x6f0954,0x6f0999,0x6e6950,0x6eec22,0x6eebcb,0x6f2905]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [HEAP,ALT,0x6f188a,0x6f179a,0x6f25d1,HANDLER,0x6f01bc,0x6ead5f,0x6e9fc2]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if a==0x6ead5f else 5 if a==0x6e9fc2 else 3 if a in [HEAP,ALT,0x6e6950] else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+(12 if a in [HEAP,ALT] else 0))
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013132);cases=[]
def seed(count=1,size=24,mode=3,threshold=100,small=[P],heap=[P],new=[0],newmode=0,error=ERR):return dict(args=[count,size,error],smallResults=small,heapResults=heap,newResults=new,writes=[word(0x751184,HEAP),word(0x297c974,0xabcdef01),word(0x297cad0,newmode),word(0x297cacc,0x12345678),word(0x29a9c48,1),word(0x29a9b28,mode),word(0x29a9b18,threshold),word(0,0xffffffff)])
for count,size in [(0,0),(0,0xffffffff),(1,0),(1,1),(1,15),(1,16),(2,17),(0xffffffff,0),(0xffffffff,1),(1,0xffffffe0),(1,0xffffffe1),(0x7ffffff0,2),(0x7ffffff1,2),(0x80000000,2),(2,0xffffffff)]:
 for mode in [0,3,0xffffffff]:
  for threshold in [0,24,100]:
   for success in [False,True]:
    requested=U(count*size);small=[P] if success and requested<=100 else [0];heap=[P] if success else [0];cases.append(seed(count,size,mode,threshold,small,heap))
for i in range(256):
 size=rng.randrange(100);c=seed(1,size,rng.choice([0,3]),rng.randrange(100),rng.choice([[0],[P],[0,P]]),rng.choice([[0],[P],[0,P]]),[1,0],1,rng.choice([0,ERR,0x297cad0]));cases.append(c)
for address in [0x6f188a,0x6f25d1,0x6f179a,0x6e6950,HEAP,0x6f2905,0x6ead5f,0x6e9fc2]:
 for at,value in [(0x297c974,0x12345678),(0x297cad0,0),(0x29a9b28,0),(0x29a9b18,0),(0x751184,ALT),(ERR,0xffffffff)]:
  c=seed(small=[0,P],heap=[0,P],new=[1,0],newmode=1);c['serviceWrites']={hex(address):[word(at,value)]};cases.append(c)

# Fake mutations previously attached to now-recovered children have no equivalence credit.
old=len(cases);cases=[c for c in cases if not any(k in c.get('serviceWrites',{}) for k in ['0x6e6950','0x6f2905'])];superseded=old-len(cases)
for size in [256,257,511,512,1024]:
 for offset in range(16):
  c=seed(size=size,threshold=1024,small=[P+offset],heap=[0]);cases.append(c)
for handler in [0,HANDLER]:
 c=seed(small=[0],heap=[0,P],new=[0xffffffff,0],newmode=1);c['handler']=handler;cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6eae5c,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6eae5c,247)+n.read(0x6eaf61,25)).hexdigest(),domain='normal no-exception bounded returning allocation/new-handler sequences; raw multiplication overflow guard and requested/rounded sizes; actual memset/vector zero/new-handler dispatcher; explicit small-pool and Win32 heap endpoints; no raw stack alias',nativeAdapters=['6f188a/6f179a mutex children','6f25d1 small-block allocator','6f01bc decoder/cdecl new-handler endpoint','HeapAlloc endpoint','errno and invalid parameter children'],additionalAddressCredit=0,supersededFakeMutations=superseded,syntheticExcluded=0,reaEvidenceIds=["ev_9c14a6bb73f396034b5de15190942251286cbddf84644d15f5fe60e203ed594b","ev_249dd26b031171ee43ef8aef7bd97d813517e8aedad63e602371ddc28c3a48c5","ev_ae526d4c8ec35d767abe41585a45a35486c0babaa5f25da85904dedb783f6054","ev_0683a8a347c3cf1bb1c2edf8e5b7e70875f9dc3ad5332013222301785fa115ee","ev_925150a769fa69bb08781e52b4b77cd49a5d7578242ceac8ecb73a53d0aeb91c"],seconds=round(time.time()-start,3))
(B/'reports/world-phase135-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase135-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
