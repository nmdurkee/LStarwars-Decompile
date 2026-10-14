"""Whole original gameOpen with real container/provider/stream/seek/poll children, only formatter and finalOS/CRT/diagnostic ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase93-20261013-verify.py').read_text().split('\nfor freeRecords,freeParents')[0])
PROVIDER=D+0x9000;FILENAME=D+0xf000;HANDLES=0x80079c;DEFAULT=0x800478;PCOUNT=0x297e064;PROVIDERS=0x29803e0;STREAMS=0x8ceb50;FORMAT=n.STOP+0x300;CREATE=n.STOP+0x400;POINTER=n.STOP+0x500;BUFFERFLAG=0x91ee90
segments +=[(PROVIDER,0x234),(HANDLES,260),(DEFAULT,4),(PCOUNT,4),(PROVIDERS,0x234),(STREAMS,4096),(BUFFERFLAG,4),(0x75ebd8,4)];cases=[];checks=0;errors=[];seekOrdinal=0;pollCalls=0

def cbytes94(p,model):
 out=[]
 while (rb(p)if model else n.read(p,1)[0]):out.append(rb(p)if model else n.read(p,1)[0]);p+=1
 return bytes(out).hex()
def port94(name,args,model):
 events.append(dict(name=name,args=args));write=wd if model else lambda p,v:n.pack('<I',p,v)
 for p,v in config.get('patches',{}).get(name,[]):write(p,v)
 return config.get('crtResult',7)if name=='CrtOpen'else config.get('createResult',0x12345678)if name=='CreateFile'else config.get('openResult',0)
def port92(name,args,model):return port94(name,args,model)
def format94(provider,destination,path,capacity,model):
 port94('Format',[provider,cbytes94(path,model),capacity],model);payload=bytes.fromhex(config.get('formatted','4142313266696c652e646174'))+b'\0'
 if model:
  for i,b in enumerate(payload):wb(destination+i,b)
 else:n.write(destination,payload)
def create94(path,mode):
 access=0;disposition=0
 if mode==0:access=0x80000000;disposition=3
 elif mode==1:access=0x40000000;disposition=2
 elif mode==2:access=0x40000000;disposition=4
 index=0xffffffff
 for i in range(64):
  if rd(0x8007a0+i*4)==0xffffffff:index=i;break
 value=port94('CreateFile',[cbytes94(path,True),access,1,0,disposition,0,0],True);wd((0x8007a0+(index<<2))&0xffffffff,value);return 0xffffffff if value==0xffffffff else index

def seekValue94(args,model):
 global seekOrdinal
 port94('SetPointer',args,model);plan=config.get('seekPlan',[[0x12345678,2],[0,0]]);value=plan[min(seekOrdinal,len(plan)-1)];seekOrdinal+=1;return value

def rawSeek94(index,origin):
 args=[rd(0x8007a0+index*4),0,0,origin];lo,hi=seekValue94(args,True);return lo|(hi<<32)
def readySeek94(index,origin,quiet):
 while True:
  value=rawSeek94(index,origin)
  if signed(value>>32)>=0:return value
  if not quiet:port94('Diagnostic',[],True)
def gameOpen94(path,mode,container,quiet):
 global pollCalls
 provider=provider90(path)
 if not provider:
  if container and mode not in[1,2]:
   handle=open93(container,path,mode)
   if handle:return handle
  provider=rd(DEFAULT)
 format94(provider,FILENAME,path,256,True)
 if rd(provider)==2:
  end=FILENAME+length90(FILENAME);suffix=0x75ebd8
  while True:
   b=rb(suffix);wb(end,b);suffix+=1;end+=1
   if not b:break
 if rd(provider)==1:
  first=(rb(FILENAME+2)if rb(FILENAME+2)<128 else rb(FILENAME+2)-256)-48;second=(rb(FILENAME+3)if rb(FILENAME+3)<128 else rb(FILENAME+3)-256)-48;value=port94('CrtOpen',[first&0xffffffff,second&0xffffffff,cbytes94(FILENAME+rd(provider+72),True),mode,0],True);return(value+0x1000)&0xffffffff if signed(value)>=0 else 0
 index=create94(FILENAME,mode)
 if signed(index)<0:return 0
 stream=STREAMS+index*64
 for i in range(64):wb(stream+i,0)
 wd(stream,index);wd(stream+52,mode);handle=index+1
 if mode==1:return handle
 if index<=16:
  size=readySeek94(index,2,quiet);wd(stream+24,size&0xffffffff);wd(stream+28,size>>32)
  if mode==3:pollCalls+=1
  readySeek94(index,0,quiet)
  if mode==3:pollCalls+=1
 if mode==0:wd(stream+44,rd(BUFFERFLAG))
 return handle
n=nm.NativeX86();n.pack('<I',0x7510b8,ENTER);n.pack('<I',0x7510b4,LEAVE);n.pack('<I',0x7510dc,CREATE);n.pack('<I',0x7510ec,POINTER)
def hook94(mu,address,size,data):
 global pollCalls
 if address==0x4f01f0:pollCalls+=1;return #Count real body execution without intercepting it.
 if address not in[ENTER,LEAVE,FORMAT,CREATE,POINTER,0x6dee30,0x4ef7b0]:return
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];clean=4;value=0
 if address in[ENTER,LEAVE]:value=port94('Enter'if address==ENTER else'Leave',[n.unpack('<I',sp+4)[0]],False);clean=8
 elif address==FORMAT:args=n.unpack('<4I',sp+4);format94(*args,False)
 elif address==CREATE:args=list(n.unpack('<7I',sp+4));args[0]=cbytes94(args[0],False);value=port94('CreateFile',args,False);clean=32
 elif address==POINTER:
  handle,low,high,out,origin=n.unpack('<5I',sp+4);lo,hi=seekValue94([handle,low,high,origin],False);n.pack('<II',out,lo,hi);value=1;clean=24
 elif address==0x6dee30:args=list(n.unpack('<5I',sp+4));args[2]=cbytes94(args[2],False);value=port94('CrtOpen',args,False)
 else:args=[n.unpack('<I',sp+4)[0]]if ret==0x4f9d6d else[];value=port94('Diagnostic',args,False)
 mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+clean);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook94)
def execute94(c):
 global config,shadow,events,checks,seekOrdinal,pollCalls
 config=c
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 payload=b'pc:file.dat'if c.get('explicit')else b'file.dat';n.write(PATH,payload+b'\0'+bytes(32-len(payload)-1));n.pack('<I',FLAG,0);n.pack('<I',LOCK,1);n.pack('<I',BASEOFFSET,0);n.pack('<I',BUFFERFLAG,c.get('buffered',7));n.write(0x75ebd8,b';1\0\0');n.pack('<I',DEFAULT,PROVIDER);n.pack('<I',PCOUNT,1);n.write(PROVIDERS,bytes(0x234));n.write(PROVIDERS+52,b'pc:\0');n.pack('<I',PROVIDERS+68,3)
 for p in[PROVIDER,PROVIDERS]:n.pack('<I',p,c.get('type',0));n.pack('<I',p+72,4);n.pack('<I',p+0x22c,FORMAT)
 n.pack('<I',HANDLES,0xabcdef01)
 for i in range(64):n.pack('<I',0x8007a0+i*4,0xffffffff if i==c.get('free',0)else 0x11111111+i)
 n.pack('<I',CON,0);n.pack('<I',CON+4,1);n.pack('<I',CON+8,ROWS);n.pack('<I',CON+16,0);n.pack('<I',CON+28,HASHES);n.pack('<I',CON+32,0);n.pack('<I',CON+40,0);h=0x811c9dc5
 for b in b'FILE.DAT':h=((h^b)*0x199933)&0xffffffff
 n.pack('<I',HASHES,h if c.get('containerFound',True)else(h+1)&0xffffffff);n.pack('<4I',ROWS,17,17,31,2)
 for i in range(20):n.pack('<I',COMP+36+i*48,0 if i==0 else 7)
 for i in range(8):n.pack('<I',CON+52+i*16,0xffffffff if i==0 else 7);n.pack('<I',CON+48+i*16,0x400)
 n.pack('<5I',TABLE,FILEDATA,FILEDATA+1023,FILEDATA+7,0,1);initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 for i in range(256):shadow[FILENAME+i]=0;shadow[LOCAL+i]=0
 events=[];seekOrdinal=0;pollCalls=0;container=CON if c.get('container')else 0;want=gameOpen94(PATH,c['mode'],container,c.get('quiet',0));model=snap(True);me=events.copy();mp=pollCalls;ms=seekOrdinal;events=[];seekOrdinal=0;pollCalls=0;actual=n.call(0x4fa3f0,[PATH,c['mode'],container,c.get('quiet',0)],count=5000000);final=snap();ne=events.copy();np=pollCalls;ns=seekOrdinal
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me),('callState',[np,ns],[mp,ms])]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[x for x,y in zip(a,b)if x!=y][:1],model=b if group!='images'else[y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(context=c,inputs=dict(path=PATH,mode=c['mode'],container=container,quiet=c.get('quiet',0)),initial=initial,returnValue=actual,final=final,nativeEvents=ne,callState=dict(pollCalls=np,seekOrdinal=ns)))
for type,mode,free,result in itertools.product([0,2],[0,1,2,3,0xffffffff],[0,16,17,63,-1],[0,0x12345678,0xffffffff]):execute94(dict(type=type,mode=mode,free=free,createResult=result,explicit=bool(len(cases)&1)))
for mode,result in itertools.product([0,1,2,3,0xffffffff],[0,7,0x7fffffff,0x80000000,0xffffffff]):execute94(dict(type=1,mode=mode,crtResult=result,explicit=bool(len(cases)&1)))
for mode,found,explicit in itertools.product([0,1,2,3],[False,True],[False,True]):execute94(dict(type=0,mode=mode,container=True,containerFound=found,explicit=explicit))
for quiet in[0,1]:execute94(dict(type=0,mode=0,quiet=quiet,seekPlan=[[0xffffffff,0xffffffff],[17,0],[0,0]]))
execute94(dict(type=0,mode=0,patches={'Format':[[PROVIDER,2],[BUFFERFLAG,0]]}))
execute94(dict(type=1,mode=0,crtResult=7,formatted='4142ff8066696c652e646174'))
pollCases=[];pollInitial=snap()
for handle in[0,1,0x3ff,0x400,0x7ff,0x800,0x7fffffff,0x80000000,0xffffffff]:
 actual=n.call(0x4f01f0,[handle]);final=snap();checks+=2
 if actual!=0 or final!=pollInitial:errors.append(dict(group='standalonePoll',handle=handle,native=actual))
 pollCases.append(dict(handle=handle,returnValue=actual))
report=dict(pollStandaloneCases=len(pollCases),binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=2,ports=['providerFormat','CreateFileIAT7510dc','SetFilePointerExIAT7510ec','CRTopen6dee30','finalCriticalSectionIATs','diagnostic4ef7b0'],closure='Whole original4fa3f0→provider4f98c0/container4f9bd0/stream4ff2f0/public+Win32seek/poll4f01f0/cookie; no own-body or container adapters')
(nm.BASE/'reports/script-phase94-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase94-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases,pollInitial=pollInitial,pollCases=pollCases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
