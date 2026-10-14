import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x20000,167),(0x29a9b10,0x18,0),(0x297cac8,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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



BASE=D+0x1000;META=D+0x4000;META2=D+0xa000;NODE=D+0x12000;NODE2=D+0x16000;trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['create'] if a==0x6f1ce5 else case['commit']
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
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a==0x6f25d1:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x6f1ce5,0x6f1d95]:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=[] if a==0x6f1ce5 else [n.unpack('<I',sp+4)[0]];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013146);cases=[]
def seed(requested=24,bin=3,rowIndex=0,startIndex=0,activeGroup=0,currentGroup=0,blocksize=None,newmember=False,counter=1,count=2):
 rounded=U(requested+23)&0xfffffff0;size=blocksize or ((bin+1)*16 if bin<63 else 4080);row=BASE+20*rowIndex;meta=META if rowIndex==0 else META2;node=NODE if rowIndex==0 else NODE2;group=meta+0x144+activeGroup*0x204;head=group+bin*8;mask=0x80000000>>(bin&31);remainder=size-rounded;nb=min((remainder>>4)-1,63)
 writes=[word(0x29a9b10,count),word(0x29a9b14,BASE),word(0x29a9b1c,BASE+20*startIndex),word(0x29a9b24,activeGroup),word(0x297cac8,row),patch(META,bytes(0x41c4)),patch(META2,bytes(0x41c4)),word(BASE,0),word(BASE+4,0),word(BASE+8,0),word(BASE+16,META),word(BASE+20,0),word(BASE+24,0),word(BASE+28,0),word(BASE+36,META2),word(row+(0 if bin<32 else 4),mask),word(meta,currentGroup),word(meta+activeGroup*4+(0x44 if bin<32 else 0xc4),mask),byte(meta+bin+4,counter)]
 for j in range(64):
  h=group+j*8;writes+=[word(h+4,h),word(h+8,h)]
 writes+=[word(group,0),word(head+4,node),word(head+8,node),word(node,size),word(node+4,head),word(node+8,head),word(node+size-4,size)]
 if newmember and nb>=0 and nb!=bin:
  h=group+nb*8;other=node+0x1100;bit=0x80000000>>(nb&31);writes +=[word(h+4,other),word(h+8,other),word(other,(nb+1)*16),word(other+4,h),word(other+8,h),word(meta+activeGroup*4+(0x44 if nb<32 else 0xc4),(mask if (bin<32)==(nb<32) else 0)|bit),word(row+(0 if nb<32 else 4),(mask if (bin<32)==(nb<32) else 0)|bit),byte(meta+nb+4,1)]
 return dict(args=[requested],create=0,commit=0,writes=writes)
for requested in [0,1,8,9,24,56,120,248,504,1000]:
 rounded=(requested+23)&0xfffffff0;minimum=(rounded>>4)-1
 for bin in sorted(set([minimum,min(minimum+1,63),63])):
  for row in [0,1]:
   for start in [0,1]:
    for gi in [0,1]:cases.append(seed(requested,bin,row,start,gi,rng.choice([gi,0xffffffff,2])))
for i in range(256):
 requested=rng.randrange(1001);rounded=(requested+23)&0xfffffff0;minimum=(rounded>>4)-1;bin=rng.randrange(minimum,64);c=seed(requested,bin,rng.randrange(2),rng.randrange(2),rng.randrange(2),rng.choice([0,1,0xffffffff,2]),newmember=bool(i%3),counter=rng.choice([1,2,255]));cases.append(c)
for result in [0,1,0xffffffff]:
 for create in [0,BASE]:
  c=seed();c['writes']+=[word(0x29a9b10,0),word(0x29a9b1c,BASE),word(BASE,0),word(BASE+4,0),word(BASE+8,0)];c.update(create=create,commit=result);cases.append(c)
for active in [0,1]:
 c=seed(activeGroup=active,currentGroup=0xffffffff);c['writes']+=[word(BASE,0),word(BASE+4,0),word(BASE+8,0x80000000>>active)];c['commit']=active;cases.append(c)
for count in [1,0xffffffff]:
 c=seed(count=count);cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f25d1,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6f25d1,739)).hexdigest(),sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase146-20261013-ptl-small-pool-allocate.cs').read_bytes()).hexdigest(),domain='prepared returning coherent masks/groups/circular bin links with size0..1000; header cursor wrap, cached/fallback group scan, low/high bins, split/same-bin/full consumption, counter0/1/255 transitions and allocation/commit failure',nativeAdapters=['6f1ce5 row creation','6f1d95 page commitment'],syntheticExcluded=0,managedReplayExecuted=False,reaEvidenceIds=["ev_a4a1dccf78e730580867b8d40bba3539be1c479984fe41b3047df3e859616cc9"],seconds=round(time.time()-start,3))
(B/'reports/world-phase146-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase146-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
