import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x20000,167),(0x11000000,0x100000,167),(0x751000,0x300,0),(0x297c53c,8,0),(0x82a070,4,0),(0x82a678,4,0),(0x829c40,0x100,0),(0x297cb3c,4,0),(0x297c1b4,16,0),(0x829ab4,8,0),(0x777fc0,8,0),(0x11300000,0x100000,167),(0x829a48,4,0),(0x8298e0,360,0),(0x29a9b28,4,0),(0x297cacc,8,0),(0x297c548,4,0),(0x29a9c48,4,0),(0,4,0),(0x11200000,0x100000,167),(0x29a9b10,0x18,0),(0x297c974,4,0),(0x297cac8,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
USER=0x11300000;n.mu.mem_map(USER,0x100000);TABLEDATA=n.read(0x8298e0,360)
RESERVE=0x11000000;RESERVE2=0x11200000;n.mu.mem_map(RESERVE2,0x100000);n.mu.mem_map(RESERVE,0x100000);REALLOC=0x10300000;ALLOC=REALLOC+0x100;VIRTUAL=REALLOC+0x200;FREE=REALLOC+0x300;ALT=REALLOC+0x400;VFREE=REALLOC+0x500;VFREE2=REALLOC+0x600;SLEEP=REALLOC+0x700;LASTERROR=REALLOC+0x800;HANDLER=REALLOC+0x900;ENTER=REALLOC+0xa00;LEAVE=REALLOC+0xb00;BASIC=REALLOC+0xc00;SPIN=REALLOC+0xd00;MODULE=REALLOC+0xe00;PROC=REALLOC+0xf00;DECODE=REALLOC+0x1000;ENCODE=REALLOC+0x1100;TLS=REALLOC+0x1200;GETTER=REALLOC+0x1300;CACHESET=REALLOC+0x1400;SETTER=REALLOC+0x1500;THREADID=REALLOC+0x1600;ATOMIC=REALLOC+0x1700;RESTORE=REALLOC+0x1800;n.mu.mem_map(REALLOC+0x2000,0x1000);L=D+0x16000;n.mu.mem_map(REALLOC+0x1000,0x1000);COOKIE=0x55aa55aa;CTX=D+0x1a000;SELF=D+0x1d000;n.mu.mem_map(REALLOC,0x1000)
for a in [REALLOC,ALLOC,VIRTUAL,FREE,ALT,VFREE,VFREE2,SLEEP,LASTERROR,HANDLER,ENTER,LEAVE,BASIC,SPIN,MODULE,PROC,DECODE,ENCODE,TLS,GETTER,CACHESET,SETTER,THREADID,ATOMIC,RESTORE]:n.write(a,b'\xc3')
P=D+0x1000;TABLE2=D+0x2000;META=D+0x4000;trace=[];case={};entries={};counts={};phase='allocate'
def service(im,a,args):
 if a in [0x751190,0x7510d8,0x7511d0]:return service(im,im.W(a),args)
 if a==0x6f0395:return consumer['noexit']['apply'](im,{})
 if a==0x6f024e:return consumer['getter']['getter'](im)
 if a==0x6f02d6:return consumer['initializer']['apply'](im,dict(entry='initialize',args=args))
 if a==0x6facb1:return consumer['locale']['apply'](im,dict(args=args))
 if a==0x6f040c:
  p=service(im,0x6f0395,[])
  if not p:service(im,0x6ebd99,[16])
  return p
 if a==0x6f01bc:return consumer['decode']['decode'](im,args[0])
 if a==0x6f0145:return consumer['encode']['decode'](im,args[0])
 if a==0x6f00d9:return consumer['capability']['apply'](im,dict(entry='supported',args=[]))
 if a==0x6f188a:return consumer['lock']['apply'](im,dict(entry='enter',args=args))
 if a==0x6f179a:return consumer['lock']['apply'](im,dict(entry='leave',args=args))
 if a==0x6f17c7:return consumer['lazy']['apply'](im,dict(args=args))
 if a==0x6fd033:return consumer['critical']['apply'](im,dict(entry='initialize',args=args))

 if a==0x6f076f:return consumer['mallocRetry']['apply'](im,dict(args=args))
 if a==0x6f07af:return consumer['callocRetry']['apply'](im,dict(args=args))
 if a==0x6e7570:return consumer['malloc']['apply'](im,dict(args=args))
 if a==0x6eae5c:return consumer['calloc']['apply'](im,dict(args=args))
 if a==0x6e74ac:return consumer['smallMalloc']['apply'](im,dict(args=args))
 if a==0x6f25d1:return apply(im,dict(args=args))
 if a==0x6e7633:consumer['free']['apply'](im,dict(args=args));return 0
 if a==0x6f19a6:return locate(im,args[0])
 if a==0x6f19d1:release(im,*args);return 0
 if a==0x6ead5f:return consumer['errno']['apply'](im,{})
 if a==0x6ead24:return consumer['map']['apply'](im,dict(args=args))
 if a==0x6f2905:return consumer['new']['apply'](im,dict(args=args))
 if a==0x6e6950:im.write(args[0],bytes([args[1]&255])*args[2]);return args[0]

 if a==0x6eb0f0:return copyMove(im,dict(entry='move',args=args))
 if a==0x6f1ce5:return create(im)
 if a==0x6f1d95:return commit(im,args[0])
 key=hex(a);index=counts.get(key,0);counts[key]=index+1
 trace.append([a,args])
 if a not in [LASTERROR,RESTORE]:counts['lastErrorValue']=case['calleeError']
 for p in (case.get('freeWrites',{}) if phase=='free' else case.get('serviceWrites',{})).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 if a==0x6eb0f0:return copyMove(im,dict(entry='move',args=args))
 if a==REALLOC:return case['reallocResults'][min(index,len(case['reallocResults'])-1)]
 if a==ALLOC and args[2]!=0x41c4:
  at=counts.get('user',0);counts['user']=at+1;values=case['userResults'];ok=values[min(at,len(values)-1)];p=USER+at*0x1000 if ok else 0
  if p and (args[1]&8):im.write(p,bytes(args[2]))
  return p
 if a==FREE:return case['heapFreeResult']
 if a==LASTERROR:return counts.get('lastErrorValue',case['lastError'])
 if a==0x6f0395:return case['thread']
 if a==0x6f01bc:
  if args[0]==0x12345678:return HANDLER if case['handlerPresent'] else 0
  if args[0]==0xdec0ded0:return counts.get('encodedCritical',0x6fd023)
  return case['criticalCached']
 if a==0x6f0145:counts['encodedCritical']=args[0];return 0xdec0ded0
 if a==SPIN:return case['criticalResult']
 if a==MODULE:return SELF if args[0]==0 else case['module']
 if a==PROC:
  if args[1]==0x777fe8:return DECODE if case['codecAvailable'] else 0
  if args[1]==0x777fc8:return ENCODE if case['codecAvailable'] else 0
  return case['procedure']
 if a==TLS:return counts.get('tlsGetterValue',GETTER if case['cacheHit'] else 0)
 if a==GETTER:return counts.get('ptdValue',case['initialPtd'])
 if a==CACHESET:
  if case['cacheSetResult']:counts['tlsGetterValue']=args[1]
  return case['cacheSetResult']
 if a==SETTER:
  if case['setterResult']:counts['ptdValue']=args[1]
  return case['setterResult']
 if a==THREADID:return case['threadId']
 if a==ATOMIC:
  p=args[0];value=U(struct.unpack('<I',im.read(p,4))[0]+1);im.write(p,struct.pack('<I',value));return value
 if a==RESTORE:counts['lastErrorValue']=args[0];return case['endpoint']
 if a in [DECODE,ENCODE]:return args[0]^COOKIE
 if a==ENTER and args[0]==D+0x1c100 and case.get('race',False):im.write(0x829ca0,struct.pack('<I',D+0x1c200))
 if a==HANDLER:
  values=case['handlerResults'];return values[min(index,len(values)-1)]
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
 if a in [0x6ebe79,0x6ebeb5,0x6f25d1,0x6f1ce5,0x6f1d95,0x6f19a6,0x6f19d1,0x6eb0f0,0x6f076f,0x6f07af,0x6e7570,0x6eae5c,0x6e74ac,0x6e7633,0x6ead5f,0x6ead24,0x6e6950,0x6f2905,0x6f188a,0x6f179a,0x6f17c7,0x6fd033,0x6ebe42,0x6fd023,0x6f01bc,0x6f0145,0x6f00d9,0x6ebef1,0x6f4bc0,0x6f0395,0x6f024e,0x6f02d6,0x6facb1,0x6f040c]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [REALLOC,ALLOC,VIRTUAL,FREE,ALT,VFREE,VFREE2,SLEEP,LASTERROR,HANDLER,ENTER,LEAVE,BASIC,SPIN,MODULE,PROC,DECODE,ENCODE,TLS,GETTER,CACHESET,SETTER,THREADID,ATOMIC,RESTORE,0x6e9fc2,0x6e9e8e,0x6ebd99]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if a in [LASTERROR,THREADID] else 5 if a in [0x6e9fc2,0x6e9e8e] else 2 if a in [SPIN,PROC,CACHESET,SETTER] else 1 if a in [SLEEP,HANDLER,ENTER,LEAVE,BASIC,MODULE,DECODE,ENCODE,TLS,GETTER,ATOMIC,RESTORE,0x6ebd99] else 4 if a in [REALLOC,VIRTUAL,ALT] else 3;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+(count*4 if a in [REALLOC,ALLOC,VIRTUAL,FREE,ALT,VFREE,VFREE2,SLEEP,LASTERROR,ENTER,LEAVE,BASIC,SPIN,MODULE,PROC,DECODE,ENCODE,TLS,GETTER,CACHESET,SETTER,THREADID,ATOMIC,RESTORE] else 0))
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


def blocks(im,out,src,length,eax):
 for at in range(0,(length>>7)*128,128):
  for half in [0,64]:im.write(U(out+at+half),im.read(U(src+at+half),64))
 return eax
def vector(im,out,src,length):
 sr=S(src)%16 if S(src)>=0 else -((-S(src))%16);dr=S(out)%16 if S(out)>=0 else -((-S(out))%16)
 if not(sr|dr):
  tail=length&127
  if length!=tail:blocks(im,out,src,length-tail,out)
  for i in range(tail):im.B(U(out+length-tail+i),im.B(U(src+length-tail+i)))
  return out
 if sr==dr:
  head=16-sr
  for i in range(head):im.B(U(out+i),im.B(U(src+i)))
  vector(im,U(out+head),U(src+head),U(length-head));return out
 words=length>>2
 for i in range(words):im.W(U(out+i*4),im.W(U(src+i*4)))
 for i in range(length&3):im.B(U(out+words*4+i),im.B(U(src+words*4+i)))
 return out
def copyMove(im,c):
 out,src,length=c['args']
 if c['entry']=='blocks':return blocks(im,out,src,length,c['eax'])
 if c['entry']=='vector':return vector(im,out,src,length)
 if out>src and out<U(src+length):
  for i in range(length-1,-1,-1):im.B(U(out+i),im.B(U(src+i)))
  return out
 if length>=256 and im.W(0x29a9c48) and (out&15)==(src&15):return vector(im,out,src,length)
 for i in range(length):im.B(U(out+i),im.B(U(src+i)))
 return out
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

# Function-local source models are used in isolated dictionaries with the same route.
consumer={}
for name,number,names in [('mallocRetry',131,['apply']),('callocRetry',128,['apply']),('malloc',139,['error','apply']),('calloc',132,['apply']),('smallMalloc',140,['apply']),('free',136,['apply']),('errno',142,['apply']),('map',137,['apply']),('new',134,['apply']),('lock',126,['apply']),('lazy',127,['error','apply']),('critical',130,['invalid','platform','fallback','apply']),('decode',121,['decode']),('encode',129,['decode']),('capability',123,['invalid','compare','apply']),('noexit',120,['apply']),('getter',121,['decode','getter']),('initializer',122,['unlock','apply']),('locale',124,['apply'])]:
 p=Path(__file__).with_name('world-phase'+str(number)+'-20261013-verify.py');tree=ast.parse(p.read_text());scope=dict(globals(),service=service);body=[x for x in tree.body if isinstance(x,ast.FunctionDef) and x.name in names];exec(compile(ast.Module(body=body,type_ignores=[]),str(p),'exec'),scope);consumer[name]=scope




def getter(im,c):
 output=c['args'][0]
 if not output or not im.W(0x297c1b4):
  im.W(service(im,0x6ead5f,[]),22);service(im,0x6e9fc2,[0]*5);return 22
 field={0x6ebe42:0x297c1b4,0x6ebef1:0x297c1c0,0x6ebe79:0x297c1b8,0x6ebeb5:0x297c1bc}[c['entry']];im.W(output,im.W(field));return 0
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013169);cases=[]
def seed(cache=False,existing=False,cacheSet=1,setter=1,active=True,lockReady=False):
 encoded=lambda p:p^COOKIE if active else p
 return dict(repetitions=2,required=False,reallocResults=[P],allocationResults=[META,D+0xa000],reserveResults=[RESERVE,RESERVE2],commitResults=[1],userResults=[1],heapFreeResult=1,handlerPresent=1,handlerResults=[0],lastError=0x13579bdf,calleeError=0x2468ace0,endpoint=0xfedcba98,module=1,procedure=SPIN,criticalResult=1,codecAvailable=active,cacheHit=cache,initialPtd=CTX if existing else 0,cacheSetResult=cacheSet,setterResult=setter,threadId=0xabcdef01,writes=[word(0x751194,REALLOC),word(0x751184,ALLOC),word(0x7510a4,VIRTUAL),word(0x75117c,FREE),word(0x751204,VFREE),word(0x7510ac,SLEEP),word(0x751190,LASTERROR),word(0x7511d0,RESTORE),word(0x7510d8,THREADID),word(0x7511cc,ATOMIC),word(0x7510b8,ENTER),word(0x7510b4,LEAVE),word(0x7510d0,BASIC),word(0x751154,MODULE),word(0x7511b0,PROC),word(0x7511bc,TLS),word(0x7511c4,CACHESET),word(0x829ab4,7),word(0x829ab8,3),word(0x829c60,D+0x1c000),word(0x829c90,D+0x1c100),word(0x829ca0,D+0x1c200 if lockReady else 0),word(0x297cb3c,encoded(0)),word(0x297c53c,encoded(GETTER)),word(0x297c540,encoded(SETTER)),word(0x297c1b4,2),word(0x297c1c0,6),word(0x297c974,0xabcdef01),word(0x29a9b10,0),word(0x29a9b14,P),word(0x29a9b1c,P),word(0x29a9b20,16),word(0x29a9b24,0),word(0x29a9b28,3),word(0x297cac8,0),word(0x297cacc,encoded(HANDLER)),word(0x297cad0,0),word(0x297c548,0),word(0x29a9b18,1000),word(0x29a9c48,1),word(0x82a070,0),word(0x82a678,L),patch(L,bytes(0x100)),word(L+0xd4,D+0x19000),word(D+0x190b4,0),patch(CTX,bytes(0x214)),word(CTX+0x1fc,DECODE if active else 0),word(CTX+0x1f8,ENCODE if active else 0),word(0,0xffffffff),patch(0x8298e0,TABLEDATA),patch(0x777fc0,b'.text\0\0\0'),word(SELF+0x3c,0x100),half(SELF+0x106,1),half(SELF+0x114,0x80),patch(SELF+0x198,b'.data\0\0\0')])
for i in range(384):
 c=seed(bool(i&1),bool(i&2),i//4%2,i//8%2,bool(i&16),bool(i&32));c.update(entry=rng.choice([0x6ebe42,0x6ebef1,0x6ebe79,0x6ebeb5]),args=[rng.choice([0,D+0x200,0x297c1b4,0x297c1b8,0x297c1bc,0x297c1c0])],lastError=rng.getrandbits(32),calleeError=rng.getrandbits(32));c['writes'] += [word(0x297c1b4,rng.choice([0,1,2,3]) if (i&3)==3 else rng.choice([1,2,3])),word(0x297c1b8,rng.getrandbits(32)),word(0x297c1bc,rng.getrandbits(32)),word(0x297c1c0,rng.choice([3,6,0xffffffff]))];
 if i%13==0 and (i&1) and not (i&2) and c['setterResult']:
  c['args']=[0];c['writes'] += [word(0x297c1b4,2)];c['serviceWrites']={hex(SETTER):[word(0x297c1b4,0)]}
 cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;phase='allocate';trace=[];counts={};im=Image(c);expected=getter(im,c);expectedTrace=trace[:];expectedError=counts.get('lastErrorValue',c['lastError']);trace=[];counts={};initial=Image(c)
 for address,size,fill in REGIONS:n.write(address,initial.read(address,size))
 result=n.call(c['entry'],c['args'],count=3000000);actualError=counts.get('lastErrorValue',c['lastError']);actual=hashlib.sha256(b''.join(n.read(address,size) for address,size,fill in REGIONS)).hexdigest()
 if result!=expected or actual!=im.hash() or trace!=expectedTrace or actualError!=expectedError:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=result,modelResult=expected,nativeError=actualError,modelError=expectedError,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(result=result,trace=trace,sha256=actual,lastError=actualError);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*4,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase169-20261013-ptl-runtime-version-cpu.cs').read_bytes()).hexdigest(),domain='all four version getters with actual errno/no-exit/getter/calloc/initializer/locale/mutex/pool/codec children; existing/fresh thread, cache/setter failure and validation made invalid by successful setter publication, reentrant capability against published thread; initially invalid version requires cached live context; prepared startup4/10/default locale, readable output aliases and version fields; normal no-exception state',nativeAdapters=['Win32 heap/virtual/error/module/procedure/critical/TLS/FLS/atomic/thread endpoints','imported codec/cdecl handler','invalid/Watson returning projection'],additionalAddressCredit=0,coldInvalidVersionDomainExcluded=True,coldInvalidVersionReason='uncached cold invalid-version state recursively requests errno before context publication; outside this returning-value domain, no equivalence credit',managedReplayExecuted=False,reaEvidenceIds=['ev_e97da604485491a123b55a80bcc26f6f4cb397f15885748f86e1e939bd187972','ev_e9f058f21c20dcafd36307d441261cd849d9208cb374202d959fba027a14cce7','ev_6acd32f09a94b3a2f80016a2dce6dcb284ede1cf78d753db12c26b7f04b1cc6a'],rawGetterPrerequisite='world168 exact PE and native proof; no Ghidra manager entry for minor/build',seconds=round(time.time()-start,3))
(B/'reports/world-phase169-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase169-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
