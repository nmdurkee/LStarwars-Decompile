import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x20000,167),(0x11000000,0x100000,167),(0x751000,0x300,0),(0x11200000,0x100000,167),(0x29a9b10,0x18,0),(0x297c974,4,0),(0x297cac8,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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



RESERVE=0x11000000;RESERVE2=0x11200000;n.mu.mem_map(RESERVE2,0x100000);n.mu.mem_map(RESERVE,0x100000);REALLOC=0x10300000;ALLOC=REALLOC+0x100;VIRTUAL=REALLOC+0x200;FREE=REALLOC+0x300;ALT=REALLOC+0x400;VFREE=REALLOC+0x500;VFREE2=REALLOC+0x600;n.mu.mem_map(REALLOC,0x1000)
for a in [REALLOC,ALLOC,VIRTUAL,FREE,ALT,VFREE,VFREE2]:n.write(a,b'\xc3')
P=D+0x1000;TABLE2=D+0x2000;META=D+0x4000;trace=[];case={};entries={};counts={};phase='allocate'
def service(im,a,args):
 if a==0x6f1ce5:return create(im)
 if a==0x6f1d95:return commit(im,args[0])
 key=hex(a);index=counts.get(key,0);counts[key]=index+1
 trace.append([a,args])
 for p in (case.get('freeWrites',{}) if phase=='free' else case.get('serviceWrites',{})).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 if a==0x6eb0f0:im.write(args[0],im.read(args[1],args[2]));return args[0]
 if a==REALLOC:return case['reallocResults'][min(index,len(case['reallocResults'])-1)]
 if a==ALLOC:
  p=case['allocationResults'][min(index,len(case['allocationResults'])-1)]
  if p:im.write(p,bytes(args[2]))
  return p
 if a in [VIRTUAL,ALT]:
  kind='reserve' if args[2]==0x2000 else 'commit';subkey=kind;subindex=counts.get(subkey,0);counts[subkey]=subindex+1;values=case[kind+'Results'];return values[min(subindex,len(values)-1)]
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
 def read(self,a,z):return n.read(a,z)
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x6f25d1,0x6f1ce5,0x6f1d95,0x6f19a6,0x6f19d1]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [REALLOC,ALLOC,VIRTUAL,FREE,ALT,VFREE,VFREE2,0x6eb0f0]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=4 if a in [REALLOC,VIRTUAL,ALT] else 3;args=list(n.unpack('<'+'I'*count,sp+4));rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+(0 if a==0x6eb0f0 else count*4))
def eligible(im,row,lo,hi):return bool((im.W(row)&lo)|(im.W(row+4)&hi))
def groupok(im,meta,index,lo,hi):return bool((im.W(meta+index*4+0x44)&lo)|(im.W(meta+index*4+0xc4)&hi))
def apply(im,c):
 end=U(im.W(0x29a9b10)*20+im.W(0x29a9b14));rounded=U(c['args'][0]+23)&0xfffffff0;minimum=(S(rounded)>>4)-1
 if minimum<32:lo=0xffffffff>>(minimum&31);hi=0xffffffff
 else:lo=0;hi=0xffffffff>>((minimum-32)&31)
 start=im.W(0x29a9b1c);row=start
 while row<end and not eligible(im,row,lo,hi):row=U(row+20)
 if row==end:
  row=im.W(0x29a9b14)
  while row<start and not eligible(im,row,lo,hi):row=U(row+20)
  if row==start:
   while row<end and not im.W(row+8):row=U(row+20)
   if row==end:
    row=im.W(0x29a9b14)
    while row<start and not im.W(row+8):row=U(row+20)
    if row==start:
     row=service(im,0x6f1ce5,[])
     if not row:return 0
   index=service(im,0x6f1d95,[row]);im.W(im.W(row+16),index)
   if im.W(im.W(row+16))==0xffffffff:return 0
 im.W(0x29a9b1c,row);meta=im.W(row+16);gi=im.W(meta)
 if gi==0xffffffff or not groupok(im,meta,gi,lo,hi):
  gi=0
  while not groupok(im,meta,gi,lo,hi):gi+=1
 group=U(meta+0x144+gi*0x204);flags=im.W(meta+gi*4+0x44)&lo;bin=0
 if not flags:flags=im.W(meta+gi*4+0xc4)&hi;bin=32
 while S(flags)>=0:flags=U(flags*2);bin+=1
 node=im.W(group+bin*8+4);remainder=U(im.W(node)-rounded);nb=(S(remainder)>>4)-1
 if nb>63:nb=63
 if nb!=bin:
  if im.W(node+4)==im.W(node+8):
   mask=U(~(0x80000000>>(bin&31)));at=meta+gi*4+(0x44 if bin<32 else 0xc4);im.W(at,im.W(at)&mask);counter=meta+bin+4;left=(im.B(counter)-1)&255;im.B(counter,left)
   if not left:at=row+(0 if bin<32 else 4);im.W(at,im.W(at)&mask)
  previous=im.W(node+8);next=im.W(node+4);im.W(previous+4,next);next=im.W(node+4);previous=im.W(node+8);im.W(next+8,previous)
  if remainder:
   head=U(group+nb*8);next=im.W(head+4);im.W(node+8,head);im.W(node+4,next);im.W(head+4,node);im.W(im.W(node+4)+8,node)
   if im.W(node+4)==im.W(node+8):
    counter=meta+nb+4;before=im.B(counter);im.B(counter,(before+1)&255);bit=0x80000000>>(nb&31);at=row+(0 if nb<32 else 4)
    if not before:im.W(at,im.W(at)|bit)
    at=meta+gi*4+(0x44 if nb<32 else 0xc4);im.W(at,im.W(at)|bit)
 if remainder:im.W(node,remainder);im.W(U(node+remainder-4),remainder)
 node=U(node+remainder);im.W(node,U(rounded+1));im.W(U(node+rounded-4),U(rounded+1));old=im.W(group);im.W(group,U(old+1))
 if not old and row==im.W(0x297cac8) and gi==im.W(0x29a9b24):im.W(0x297cac8,0)
 im.W(meta,gi);return U(node+4)


def binof(size):return min(U((S(size)>>4)-1),63)
def remove(im,header,meta,index,node,bin):
 if im.W(node+4)==im.W(node+8):
  mask=U(~(0x80000000>>(bin&31)));at=meta+index*4+(0x44 if bin<32 else 0xc4);im.W(at,im.W(at)&mask);counter=meta+bin+4;left=(im.B(counter)-1)&255;im.B(counter,left)
  if not left:at=header+(0 if bin<32 else 4);im.W(at,im.W(at)&mask)
 previous=im.W(node+8);next=im.W(node+4);im.W(previous+4,next);next=im.W(node+4);previous=im.W(node+8);im.W(next+8,previous)
def insert(im,header,meta,index,group,node,bin):
 head=U(group+bin*8);next=im.W(head+4);im.W(node+8,head);im.W(node+4,next);im.W(head+4,node);im.W(im.W(node+4)+8,node)
 if im.W(node+4)==im.W(node+8):
  counter=meta+bin+4;before=im.B(counter);im.B(counter,(before+1)&255);bit=0x80000000>>(bin&31);at=header+(0 if bin<32 else 4)
  if not before:im.W(at,im.W(at)|bit)
  at=meta+index*4+(0x44 if bin<32 else 0xc4);im.W(at,im.W(at)|bit)
def locate(im,p):
 cursor=im.W(0x29a9b14);end=U(cursor+im.W(0x29a9b10)*20)
 while cursor<end:
  if U(p-im.W(cursor+12))<0x100000:return cursor
  cursor=U(cursor+20)
 return 0
def release(im,header,pointer):
 meta=im.W(header+16);index=U(pointer-im.W(header+12))>>15;group=U(meta+0x144+index*0x204);node=U(pointer-4);size=U(im.W(node)-1)
 if size&1:return
 next=U(node+size);nextSize=im.W(next);previousSize=im.W(U(node-4))
 if not(nextSize&1):remove(im,header,meta,index,next,binof(nextSize));size=U(size+nextSize)
 bin=binof(size);previousBin=0;previousAllocated=bool(previousSize&1)
 if not previousAllocated:
  node=U(node-previousSize);previousBin=binof(previousSize);size=U(size+previousSize);bin=binof(size)
  if previousBin!=bin:remove(im,header,meta,index,node,previousBin)
 if previousAllocated or previousBin!=bin:insert(im,header,meta,index,group,node,bin)
 im.W(node,size);im.W(U(node+size-4),size);count=U(im.W(group)-1);im.W(group,count)
 if count:return
 old=im.W(0x297cac8)
 if old:
  target=im.W(0x751204);oldIndex=im.W(0x29a9b24);block=U(im.W(old+12)+(oldIndex<<15));service(im,target,[block,0x8000,0x4000]);oldIndex=im.W(0x29a9b24);old=im.W(0x297cac8);im.W(old+8,im.W(old+8)|(0x80000000>>(oldIndex&31)));old=im.W(0x297cac8);oldMeta=im.W(old+16);oldIndex=im.W(0x29a9b24);im.W(oldMeta+oldIndex*4+0xc4,0);old=im.W(0x297cac8);oldMeta=im.W(old+16);im.B(oldMeta+0x43,(im.B(oldMeta+0x43)-1)&255);old=im.W(0x297cac8);oldMeta=im.W(old+16)
  if not im.B(oldMeta+0x43):im.W(old+4,im.W(old+4)&0xfffffffe);old=im.W(0x297cac8)
  if im.W(old+8)==0xffffffff:
   service(im,target,[im.W(old+12),0,0x8000]);old=im.W(0x297cac8);memory=im.W(old+16);service(im,im.W(0x75117c),[im.W(0x297c974),0,memory]);total=U(im.W(0x29a9b10)*20);old=im.W(0x297cac8);table=im.W(0x29a9b14);service(im,0x6eb0f0,[old,U(old+20),U(total-old+table-20)]);im.W(0x29a9b10,U(im.W(0x29a9b10)-1))
   if header>im.W(0x297cac8):header=U(header-20)
   im.W(0x29a9b1c,im.W(0x29a9b14))
 im.W(0x297cac8,header);im.W(0x29a9b24,index)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013148);cases=[]
def seed(requests=[24,24,24],order=None):return dict(requests=requests,freeIndices=list(range(len(requests))) if order is None else order,reallocResults=[P],allocationResults=[META,D+0xa000],reserveResults=[RESERVE,RESERVE2],commitResults=[1],endpoint=0xfedcba98,writes=[word(0x751194,REALLOC),word(0x751184,ALLOC),word(0x7510a4,VIRTUAL),word(0x75117c,FREE),word(0x751204,VFREE),word(0x297c974,0xabcdef01),word(0x29a9b10,0),word(0x29a9b14,P),word(0x29a9b1c,P),word(0x29a9b20,16),word(0x29a9b24,0),word(0x297cac8,0)])
for size in [0,24,504,1000,4072]:
 for length in [1,2,8,9,17]:
  for reverse in [False,True]:cases.append(seed([size]*length,list(reversed(range(length))) if reverse else list(range(length))))
for length in [257,258]:
 for reverse in [False,True]:cases.append(seed([4072]*length,list(reversed(range(length))) if reverse else None))
for i in range(128):
 length=rng.randrange(1,25);requests=[rng.randrange(1001) for _ in range(length)];order=list(range(length));rng.shuffle(order);cases.append(seed(requests,order))
for order in [[0,0,1],[1,1,0]]:cases.append(seed([24,24],order))
for a in [VFREE,FREE,0x6eb0f0]:
 for at,value in [(0x751204,VFREE2),(0x297c974,0x12345678),(0x29a9b1c,P+20)]:
  c=seed([4072]*257);c['freeWrites']={hex(a):[word(at,value)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;phase='allocate';trace=[];counts={};im=Image(c);expectedResults=[apply(im,dict(args=[size])) for size in c['requests']];phase='free'
 for j in c['freeIndices']:release(im,locate(im,expectedResults[j]),expectedResults[j])
 expectedTrace=trace[:];trace=[];counts={};phase='allocate';initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 actualResults=[n.call(0x6f25d1,[size],count=1000000) for size in c['requests']];phase='free'
 for j in c['freeIndices']:
  pointer=actualResults[j];header=n.call(0x6f19a6,[pointer],count=1000000);n.call(0x6f19d1,[header,pointer],count=1000000)
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actualResults!=expectedResults or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResults=actualResults,modelResults=expectedResults,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,results=actualResults,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6f19d1,788)).hexdigest(),sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase148-20261013-ptl-small-pool-free.cs').read_bytes()).hexdigest(),domain='coherent raw allocator-produced boundary tags and bins; bidirectional coalescing, reused double-free early return, full257/258 page exhaustion across two pools, deferred decommit/release and row move; void ABI and readable mutable Win32 endpoints',nativeAdapters=['HeapReAlloc/HeapAlloc/HeapFree','VirtualAlloc/VirtualFree','6eb0f0 row memmove'],prerequisiteAddressCredit=0,syntheticExcluded=0,managedReplayExecuted=False,reaEvidenceIds=["ev_d89361a42faa7fc65f9d0037cdc3644a063d84929880007431752a010d034082","ev_a4a1dccf78e730580867b8d40bba3539be1c479984fe41b3047df3e859616cc9","ev_f126f0a7e59cf368ee0c772bebf13e25399c578f393fdcafc5f2bbce74d4b04c","ev_cb5636231d24e54ba02b2e7d4ee64025d90abe2d709e3ae0e7448b62c09b3ff7","ev_3aa3133f31232e18daa4a21d1572b1049167c8a73496dfbdfa6062cbc61c0fab"],seconds=round(time.time()-start,3))
(B/'reports/world-phase148-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase148-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
