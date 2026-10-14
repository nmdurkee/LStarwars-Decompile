"""Original4fb550 allhandle branches and64bit buffered copy/refill body; actual76allocator/Win32wrappers and71memoryreader. FinalWin32/CRT/compressed ports only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase76-20261013-verify.py').read_text().split('\nfor index,count')[0])
import random
OUT=D+0x8000;MEMDATA=D+0x5000;TABLE=0x2983740;STREAMS=0x8cea00;MASK64=(1<<64)-1;segments=[(STREAM,0x2000),(OUT,0x4000),(MEMDATA,0x1000),(POOL,0x1020),(COUNTER,4),(HANDLES-16,0x80),(0x7510e4,12),(TABLE,400),(STREAMS,0x1400)];backend=0
s71=Path(__file__).with_name('script-phase71-20261013-verify.py').read_text();exec(s71[s71.index('\ndef read71'):s71.index('\ndef setup71')])
def q(p):return rd(p)|(rd(p+4)<<32)
def wq(p,v):wd(p,v&0xffffffff);wd(p+4,v>>32)
def signed64(v):return v-(1<<64)if v&(1<<63)else v

def api76(name,args,model):
 global backend
 events.append(dict(name=name,args=args.copy()));patches76(name,model);base=config.get('basePosition',0);physical=config.get('physicalSize',config.get('size',2048))
 if name=='SetFilePointerEx':
  offset=args[1]|(args[2]<<32);origin=args[3];backend=(offset if origin==0 else backend+offset if origin==1 else base+physical+offset)&MASK64;return 1,[backend&0xffffffff,backend>>32]
 offset=(backend-base)&MASK64;count=min(args[2],config.get('chunk',1024),max(0,physical-offset));payload=bytes(((offset+i)*37+13)&255 for i in range(count))
 if model:
  for i,b in enumerate(payload):wb(args[1]+i,b)
 else:n.write(args[1],payload)
 backend=(backend+count)&MASK64;return 1,count
def reader77(handle,destination,count):
 if signed(handle)>=0x1000:events.append(dict(name='CrtRead',args=[handle-0x1000,destination,count,0]));return config.get('portResult',0x12345678)
 if signed(handle)>=0x400:
  if signed(handle)>=0x800:events.append(dict(name='CompressedRead',args=[handle,destination,count]));return config.get('portResult',0x12345678)
  return read71(handle,destination,count)
 index=(handle-1)&0xffffffff;stream=(0x8ceb50+(index<<6))&0xffffffff
 if not rd(stream+0x2c):return read76(index,destination,count)
 if not rd(stream+0x38):acquire76(stream)
 remaining=count;total=0;iterations=0
 while signed(remaining)>0:
  iterations+=1
  if iterations>8192:raise ValueError('nonprogress')
  current=q(stream+8)
  if signed64(current)>=signed64(q(stream+0x18)):break
  start=q(stream+0x20);end=(start+signed(rd(stream+0x28)))&MASK64
  if signed64(current)<signed64(start)or signed64(current)>=signed64(end):
   if current!=q(stream+0x10):seek76(rd(stream),current&0xffffffff,current>>32,0);wq(stream+0x10,q(stream+8))
   value=read76(rd(stream),(rd(stream+0x38)+8)&0xffffffff,1024);before=q(stream+0x10);wd(stream+0x28,value);wq(stream+0x20,before);wq(stream+0x10,(before+signed(value))&MASK64)
  available=signed((rd(stream+0x28)-rd(stream+8)+rd(stream+0x20))&0xffffffff);copied=min(available,signed(remaining))
  if copied<0:raise KeyError('negative memcpy')
  if copied:
   source=(rd(stream+0x38)-rd(stream+0x20)+rd(stream+8)+8)&0xffffffff
   for i in range(copied):wb((destination+i)&0xffffffff,rb((source+i)&0xffffffff))
  destination=(destination+copied)&0xffffffff;total=(total+copied)&0xffffffff;remaining=(remaining-copied)&0xffffffff;wq(stream+8,(q(stream+8)+copied)&MASK64)
 return total
n=nm.NativeX86();n.mu.hook_add(UC_HOOK_CODE,hook76)
def hook77(mu,address,size,data):
 if address not in[0x6dee50,0x4faf60]:return
 sp=mu.reg_read(UC_X86_REG_ESP);argc=4 if address==0x6dee50 else 3;events.append(dict(name='CrtRead'if argc==4 else'CompressedRead',args=list(n.unpack('<'+'I'*argc,sp+4))));mu.reg_write(UC_X86_REG_EAX,config.get('portResult',0x12345678));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook77)
def setup77(c):
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 n.pack('<I',0x7510e4,READAPI);n.pack('<I',0x7510ec,SEEKAPI);n.pack('<I',COUNTER,5)
 for i in[-1]+list(range(16)):n.pack('<I',HANDLES+i*4,(0xf00d0000+i)&0xffffffff)
 for i in range(4):n.pack('<II',POOL+i*0x408,OLD+i*0x80,i+1);n.pack('<I',OLD+i*0x80+0x38,POOL+i*0x408)
 handle=c['handle'];base=c.get('basePosition',0);position=c.get('position',0);cache=c.get('cache',0);cacheStart=c.get('cacheStart',0);osPosition=c.get('osPosition',cacheStart+cache);size=c.get('size',2048)
 if 0x400<=handle<0x414:n.pack('<5I',TABLE+(handle-0x400)*20,MEMDATA,MEMDATA+size-1,MEMDATA+position,0,1);n.write(MEMDATA,bytes((i*37+13)&255 for i in range(4096)))
 elif signed(handle)<0x400:
  stream=(0x8ceb50+(((handle-1)&0xffffffff)<<6))&0xffffffff;n.write(stream,bytes(64));n.pack('<I',stream,c.get('streamIndex',7));n.pack('<Q',stream+8,(base+position)&MASK64);n.pack('<Q',stream+0x10,(base+osPosition)&MASK64);n.pack('<Q',stream+0x18,(base+size)&MASK64);n.pack('<Q',stream+0x20,(base+cacheStart)&MASK64);n.pack('<II',stream+0x28,cache,c.get('buffered',1));n.pack('<I',stream+0x38,POOL if c.get('hasBuffer',True)else 0)
  if c.get('hasBuffer',True):n.pack('<I',POOL,stream);n.write(POOL+8,bytes(((cacheStart+i)*37+13)&255 for i in range(cache)))
def execute77(c):
 global config,shadow,events,checks,backend
 config=c;setup77(c);initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];backend=(c.get('basePosition',0)+c.get('osPosition',c.get('cacheStart',0)+c.get('cache',0)))&MASK64;want=reader77(c['handle'],OUT,c['wanted']);model=snap(True);me=events.copy();mb=backend;events=[];backend=(c.get('basePosition',0)+c.get('osPosition',c.get('cacheStart',0)+c.get('cache',0)))&MASK64;actual=n.call(0x4fb550,[c['handle'],OUT,c['wanted']],count=12000000);final=snap();ne=events.copy();nb=backend
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me),('hostPosition',nb,mb)]:
  checks+=1
  if a!=b:
   e=dict(group=group,context=c)
   if group=='images':e['differences']=[dict(address=x['address'],native=x['bytes'],model=y['bytes'])for x,y in zip(a,b)if x!=y][:2]
   else:e.update(native=a,model=b)
   errors.append(e)
 cases.append(dict(context=c,inputs=dict(handle=c['handle'],destination=OUT,count=c['wanted']),initial=initial,returnValue=actual,final=final,nativeEvents=ne,hostPosition=[nb&0xffffffff,nb>>32]))
for handle,wanted,result in itertools.product([0x800,0x803,0xfff,0x1000,0x1007,0x7fffffff],[0,1,17,0xffffffff],[0,7,0x80000000,0xffffffff]):execute77(dict(handle=handle,wanted=wanted,portResult=result))
for handle,size,position,wanted in itertools.product([0x400,0x407,0x413],[1,17,1024],[0,1],[0,1,17,1024,2048]):execute77(dict(handle=handle,size=size,position=position,wanted=wanted))
for handle,buffered,hasBuffer,chunk,wanted in itertools.product([0,1,7],[0,1],[False,True],[17,1024],[0,1,17,1024,2048]):execute77(dict(handle=handle,buffered=buffered,hasBuffer=hasBuffer,chunk=chunk,wanted=wanted,size=2048,cache=0))
for base,hasBuffer,cacheStart,cache,position,wanted,chunk in itertools.product([0,0xfffffff0,0x8000000000000000,0xffffffffffffffe0],[False,True],[0,7],[17,1024],[0,1,16,17],[0,1,17,1024,2048],[17,1024]):execute77(dict(handle=1,basePosition=base,hasBuffer=hasBuffer,cacheStart=cacheStart,cache=cache,position=position,wanted=wanted,chunk=chunk,size=2048))
for hasBuffer,cached,wanted in itertools.product([False,True],[0,17],[0x80000000,0xffffffff]):execute77(dict(handle=1,hasBuffer=hasBuffer,cache=cached,wanted=wanted,size=2048))
for hasBuffer in[False,True]:execute77(dict(handle=1,hasBuffer=hasBuffer,cache=0,wanted=1,size=0))
stream=0x8ceb50
for patches in[{'SetFilePointerEx':[[stream+8,4,3]]},{'ReadFile':[[stream+0x10,4,0xffffffff],[stream+0x14,4,0xffffffff]]},{'ReadFile':[[stream+0x38,4,POOL+0x408]]}]:execute77(dict(handle=1,size=2048,position=0,cache=0,osPosition=7,wanted=17,patches=patches))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=['ReadFileIAT7510e4','SetFilePointerExIAT7510ec','CRTread6dee50','compressedRead4faf60'],closure='Actual4fb550 allbranches→real4f0230/4ff3b0/4ff430/4fb4f0/6e6d90; signed64EOF/cache checks,low32available/copy,partialrefill/cursor carry/livecallback rereads')
(nm.BASE/'reports/script-phase77-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase77-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
