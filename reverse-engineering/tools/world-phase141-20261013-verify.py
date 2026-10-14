import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x751184,4,0),(0x297c974,4,0),(0x297cacc,8,0),(0x29a9b18,0x14,0),(0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
 if a==0x6e74ac:
  size=args[0]
  if size>im.W(0x29a9b18):return 0
  service(im,0x6f188a,[4]);result=service(im,0x6f25d1,[size]);service(im,0x6f179a,[4]);return result
 if a==0x6f2905:
  handler=service(im,0x6f01bc,[im.W(0x297cacc)]);return 1 if handler and service(im,handler,args) else 0
 key=hex(a);index=counts.get(key,0);counts[key]=index+1;trace.append([a,args])
 seq=case.get('sequenceWrites',{}).get(key,[])
 if index<len(seq):
  for p in seq[index]:im.write(p['address'],base64.b64decode(p['data']))
 if a==0x6f01bc:return case.get('handler',HANDLER)
 values=case['smallResults'] if a==0x6f25d1 else case['heapResults'] if a in [HEAP,ALT] else case['newResults'] if a==HANDLER else case['errnoCells'] if a==0x6ead5f else [0xfedcba98];return values[min(index,len(values)-1)]
def error(im):im.W(service(im,0x6ead5f,[]),12)
def apply(im,c):
 size=c['args'][0]
 if size>0xffffffe0:service(im,0x6f2905,[size]);error(im);return 0
 heapTarget=im.W(0x751184)
 while True:
  if not im.W(0x297c974):service(im,0x6f0bb8,[]);service(im,0x6f09f8,[30]);service(im,0x6ebde3,[255])
  result=0;mode=im.W(0x29a9b28)
  if mode==1:result=service(im,heapTarget,[im.W(0x297c974),0,size or 1])
  else:
   if mode==3:result=service(im,0x6e74ac,[size])
   if not result:result=service(im,heapTarget,[im.W(0x297c974),0,U((size or 1)+15)&0xfffffff0])
  if result:return result
  if im.W(0x297cad0):
   if service(im,0x6f2905,[size]):continue
  else:error(im)
  error(im);return 0
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x6e7570,0x6e74ac,0x6e74f2,0x6f2905,0x6f0954,0x6f0999]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [HEAP,ALT,HANDLER,0x6f01bc,0x6f188a,0x6f179a,0x6f25d1,0x6ead5f,0x6f0bb8,0x6f09f8,0x6ebde3]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if a in [0x6ead5f,0x6f0bb8] else 3 if a in [HEAP,ALT] else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+(12 if a in [HEAP,ALT] else 0))
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013139);cases=[]
def seed(size=24,mode=3,small=[P],heap=[P],new=[0],newmode=0,heapPointer=1):return dict(args=[size],smallResults=small,heapResults=heap,newResults=new,errnoCells=[ERR,ERR+4],writes=[word(0x751184,HEAP),word(0x297c974,heapPointer),word(0x297cad0,newmode),word(0x29a9b28,mode),word(0x29a9b18,100),word(0x297cacc,0x12345678),word(0,0xffffffff)])
for size in [0,1,15,16,17,24,0x214,0xffffffe0,0xffffffe1,0xffffffff]:
 for mode in [0,1,3,0xffffffff]:
  for success in [False,True]:
   for newmode in [0,1]:cases.append(seed(size,mode,[P] if success else [0],[P] if success else [0],[0],newmode))
for i in range(256):
 c=seed(rng.getrandbits(32),rng.choice([0,1,3]),rng.choice([[0],[P],[0,P]]),rng.choice([[0],[P],[0,P]]),[1,0],1,rng.choice([0,1]));cases.append(c)
for address in [HEAP,0x6e74ac,0x6f2905,0x6f0bb8,0x6f09f8,0x6ebde3,0x6ead5f]:
 for at,value in [(0x751184,ALT),(0x297c974,0x12345678),(0x297cad0,0),(0x29a9b28,1),(ERR,0xffffffff)]:
  c=seed(small=[0,P],heap=[0,P],new=[1,0],newmode=1,heapPointer=0);c['sequenceWrites']={hex(address):[[word(at,value)]]};cases.append(c)
for cells in [[ERR,ERR+4],[ERR,0x751184],[0x297cad0,ERR],[ERR+4,ERR]]:
 c=seed(small=[0],heap=[0]);c['errnoCells']=cells;cases.append(c)
old=len(cases);cases=[c for c in cases if not any(k in c.get('sequenceWrites',{}) for k in ['0x6e74ac','0x6f2905'])];superseded=old-len(cases)
for size in [0,24,128,512]:
 for threshold in [0,24,128,512]:
  for success in [0,P]:
   c=seed(size=size,small=[success],heap=[0,P],new=[1,0],newmode=1);c['writes'].append(word(0x29a9b18,threshold));cases.append(c)
for a in [0x6f188a,0x6f25d1,0x6f179a,0x6f01bc,HANDLER]:
 for at,value in [(0x751184,ALT),(0x297c974,0x12345678),(0x29a9b18,0),(0x29a9b28,1)]:
  c=seed(small=[0,P],heap=[0,P],new=[1,0],newmode=1);c['sequenceWrites']={hex(a):[[word(at,value)]]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6e7570,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6e7570,195)).hexdigest(),domain='bounded returning allocation/new-handler sequences; captured HeapAlloc target with fresh heap/mode per retry; overflow invokes handler even disabled; distinct errno pointers; zero heap termination child suspension',nativeAdapters=['6f25d1 small-block allocator','CRT lock/unlock','HeapAlloc endpoint','decoder/cdecl handler/errno and termination children'],additionalAddressCredit=0,supersededFakeChildMutations=superseded,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase141-20261013-ptl-malloc-children-cpu.cs').read_bytes()).hexdigest(),managedReplayExecuted=False,syntheticExcluded=0,reaEvidenceIds=["ev_70fd95bf6d2ee469517f33f2c0ca9b13326080da079d0bd41d4a915f0bc95914","ev_913a64841cb34d82dfc561099750e466fbd91953d5b003ff7b67af037546d864","ev_925150a769fa69bb08781e52b4b77cd49a5d7578242ceac8ecb73a53d0aeb91c"],seconds=round(time.time()-start,3))
(B/'reports/world-phase141-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase141-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
