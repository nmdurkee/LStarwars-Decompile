import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x11000000,0x100000,167),(0x751000,0x200,0),(0x29a9b10,0x14,0),(0x297c974,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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



RESERVE=0x11000000;n.mu.mem_map(RESERVE,0x100000);REALLOC=0x10300000;ALLOC=REALLOC+0x100;VIRTUAL=REALLOC+0x200;FREE=REALLOC+0x300;ALT=REALLOC+0x400;n.mu.mem_map(REALLOC,0x1000)
for a in [REALLOC,ALLOC,VIRTUAL,FREE,ALT]:n.write(a,b'\xc3')
P=D+0x1000;TABLE2=D+0x2000;META=D+0x4000;trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 if a==REALLOC:return case['realloc']
 if a==ALLOC:
  p=case['allocation']
  if p:im.write(p,bytes(args[2]))
  return p
 if a in [VIRTUAL,ALT]:return case['reserve'] if args[2]==0x2000 else case['commit']
 return case['endpoint']
def create(im):
 capacity=im.W(0x29a9b20);count=im.W(0x29a9b10)
 if count==capacity:
  table=service(im,im.W(0x751194),[im.W(0x297c974),0,im.W(0x29a9b14),U((capacity+16)*20)])
  if not table:return 0
  im.W(0x29a9b20,U(im.W(0x29a9b20)+16));count=im.W(0x29a9b10);im.W(0x29a9b14,table)
 row=U(im.W(0x29a9b14)+count*20);metadata=service(im,im.W(0x751184),[im.W(0x297c974),8,0x41c4]);im.W(row+16,metadata)
 if not metadata:return 0
 reserve=service(im,im.W(0x7510a4),[0,0x100000,0x2000,4]);im.W(row+12,reserve)
 if not reserve:service(im,im.W(0x75117c),[im.W(0x297c974),0,im.W(row+16)]);return 0
 im.W(row+8,0xffffffff);im.W(row,0);im.W(row+4,0);im.W(0x29a9b10,U(im.W(0x29a9b10)+1));im.W(im.W(row+16),0xffffffff);return row
def commit(im,header):
 mask=im.W(header+8);metadata=im.W(header+16);index=0
 while S(mask)>=0:mask=U(mask*2);index+=1
 group=U(metadata+0x144+index*0x204)
 for i in range(63):
  head=U(group+i*8);im.W(head+8,head);im.W(head+4,head)
 block=U(im.W(header+12)+(index<<15))
 if not service(im,im.W(0x7510a4),[block,0x8000,0x1000,4]):return 0xffffffff
 last=U(block+0x7000)
 if block<=last:
  for page in range(block,last+1,0x1000):
   p=U(page+16);im.W(p-8,0xffffffff);im.W(p+0xfec,0xffffffff);im.W(p,U(p+0xffc));im.W(p-4,0xff0);im.W(p+4,U(p-0x1004));im.W(p+0xfe8,0xff0)
 sentinel=U(group+0x1f8);first=U(block+12);end=U(last+12);im.W(sentinel+4,first);im.W(first+8,sentinel);im.W(sentinel+8,end);im.W(end+4,sentinel);im.W(metadata+index*4+0x44,0);im.W(metadata+index*4+0xc4,1);old=im.B(metadata+0x43);im.B(metadata+0x43,(old+1)&255)
 if not old:im.W(header+4,im.W(header+4)|1)
 im.W(header+8,im.W(header+8)&~(0x80000000>>index));return index
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x6f1ce5,0x6f1d95]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [REALLOC,ALLOC,VIRTUAL,FREE,ALT]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=4 if a in [REALLOC,VIRTUAL,ALT] else 3;args=list(n.unpack('<'+'I'*count,sp+4));rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+count*4)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013145);cases=[]
def seed(entry='create',count=0,capacity=0,index=0):return dict(entry=entry,args=[] if entry=='create' else [P],realloc=TABLE2,allocation=META,reserve=RESERVE,commit=1,endpoint=0xfedcba98,writes=[word(0x751194,REALLOC),word(0x751184,ALLOC),word(0x7510a4,VIRTUAL),word(0x75117c,FREE),word(0x297c974,0xabcdef01),word(0x29a9b10,count),word(0x29a9b14,P),word(0x29a9b20,capacity),word(P+8,0x80000000>>index),word(P+12,RESERVE),word(P+16,META),patch(META,bytes(0x41c4))])
for count,capacity in [(0,0),(1,1),(0,16),(3,4),(16,16)]:
 for realloc in [0,TABLE2]:
  for allocation in [0,META]:
   for reserve in [0,RESERVE]:
    c=seed(count=count,capacity=capacity);c.update(realloc=realloc,allocation=allocation,reserve=reserve);cases.append(c)
for index in range(32):
 for result in [0,1]:
  for old in [0,1,255]:
   c=seed('commit',index=index);c['commit']=result;c['writes'].append(byte(META+0x43,old));cases.append(c)
for i in range(128):
 c=seed(rng.choice(['create','commit']),rng.randrange(32),rng.randrange(32),rng.randrange(32));c.update(allocation=rng.choice([0,META]),reserve=rng.choice([0,RESERVE]),commit=rng.getrandbits(32) if i%3 else 0);cases.append(c)
for entry in ['create','commit']:
 for a in [REALLOC,ALLOC,VIRTUAL,FREE]:
  for at,value in [(0x29a9b10,2),(0x29a9b20,5),(0x29a9b14,TABLE2),(0x297c974,0x13579bdf),(0x7510a4,ALT),(P+8,0xffffffff),(META+0x43,255)]:
   c=seed(entry);c['serviceWrites']={hex(a):[word(at,value)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=create(im) if c['entry']=='create' else commit(im,c['args'][0]);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f1ce5 if c['entry']=='create' else 0x6f1d95,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=dict(create=hashlib.sha256(n.read(0x6f1ce5,176)).hexdigest(),commit=hashlib.sha256(n.read(0x6f1d95,262)).hexdigest()),sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase145-20261013-ptl-small-pool-pages.cs').read_bytes()).hexdigest(),domain='prepared physical table/metadata/1MiB reservation; commit mask nonzero; original 63 bin heads and8 page linked extents; cached pointers with fresh global/field reloads after mutable Win32 endpoint callbacks',nativeAdapters=['HeapReAlloc/HeapAlloc/HeapFree','VirtualAlloc reserve/commit'],syntheticExcluded=0,managedReplayExecuted=False,reaEvidenceIds=["ev_cb5636231d24e54ba02b2e7d4ee64025d90abe2d709e3ae0e7448b62c09b3ff7","ev_3aa3133f31232e18daa4a21d1572b1049167c8a73496dfbdfa6062cbc61c0fab"],seconds=round(time.time()-start,3))
(B/'reports/world-phase145-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase145-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
