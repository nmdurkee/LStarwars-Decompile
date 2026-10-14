"""Full original 2420-byte narrow printf parser and recovered byte/locale children; explicit conversion/runtime services."""
import importlib.util,json,itertools,random,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
D=n.DATA;FILE=D+0x100;OUT=D+0x1000;FORMAT=D+0x300;ARGS=D+0x800;TEXT=D+0x500;WTEXT=D+0x600;DESC=D+0x700;LOC=D+0x3000;LI=D+0x3200;MB=D+0x3400;CT=D+0x3600;THREAD=D+0x3800;ERR=D+0x3900;HEAP=D+0x4000;FRAME=n.STACK+0xde04;CTX=FRAME-0x64;COUNTER=FRAME-0x34;PREFIX=FRAME-0x38;BUF=FRAME-0x14;FLOAT=n.STOP+0xa00;POINT=n.STOP+0xa10;TRIM=n.STOP+0xa20
shadow={};segments=[];events=[];config={};cases=[];errors=[];checks=0;flushes=0
U=lambda v:v&0xffffffff
I=lambda v:(v&0x7fffffff)-(v&0x80000000)
def rd(p,z=4):return sum(shadow[U(p+i)]<<(i*8)for i in range(z))
def wr(p,v,z=4):
 for i in range(z):shadow[U(p+i)]=(v>>(i*8))&255

def snap(model=False,rows=None):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in(rows or segments)]
def port(address,args,model):
 global flushes
 read=rd if model else lambda p,z=4:int.from_bytes(n.read(p,z),'little');write=wr if model else lambda p,v,z=4:n.write(p,int(v&((1<<(8*z))-1)).to_bytes(z,'little'))
 event=dict(callback=address,args=list(args))
 if address==0x6ead5f:event['errno']=read(ERR)
 if address==FLOAT:event['value']=read(args[0],8)
 events.append(event)
 if address==0x6f040c:return THREAD
 if address==0x6fae25:return LI
 if address==0x6fa67a:return MB
 if address==0x6ead5f:return ERR
 if address==0x6e9fc2:return 0
 if address==0x6eecd9:
  flushes+=1;write(ERR,config.get('errorValue',21));return config.get('flushReturn',0xffffffff)
 if address==0x6e7a93:return config.get('nEnabled',1)
 if address==0x6f01bc:return args[0]
 if address==0x6f076f:return 0 if config.get('allocationFail')else HEAP
 if address==0x6e7633:return 0
 if address==0x701ea2:
  result,buffer,capacity,character=args
  if character==0xffff:write(result,0);return 42
  payload=bytes([character])if character<128 else bytes([0xc0|(character>>6)&31,0x80|character&63])
  if character==0:payload=b''
  write(result,len(payload))
  for i,b in enumerate(payload):write(buffer+i,b,1)
  return 0
 if address==FLOAT:
  payload=config.get('floating','-12.500').encode()+b'\0'
  for i,b in enumerate(payload):write(args[1]+i,b,1)
  return 0
 if address in[POINT,TRIM]:return 0
 raise ValueError(hex(address))
ports={0x6f040c:0,0x6fae25:0,0x6fa67a:0,0x6ead5f:0,0x6e9fc2:5,0x6eecd9:2,0x6e7a93:0,0x6f01bc:1,0x6f076f:1,0x6e7633:1,0x701ea2:4,FLOAT:7,POINT:2,TRIM:2}
def hook(mu,address,size,data):
 if address not in ports:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*ports[address],sp+4))if ports[address]else[];value=port(address,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,U(value));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
def ctor(instance,locale):
 wr(instance+12,0,1)
 if locale:wr(instance,rd(locale));wr(instance+4,rd(locale+4));return
 thread=port(0x6f040c,[],True);wr(instance+8,thread);wr(instance,rd(thread+0x6c));wr(instance+4,rd(thread+0x68))
 if rd(instance)!=rd(0x82a678)and not rd(thread+0x70)&rd(0x82a594):wr(instance,port(0x6fae25,[],True))
 if rd(instance+4)!=rd(0x82a498)and not rd(rd(instance+8)+0x70)&rd(0x82a594):wr(instance+4,port(0x6fa67a,[],True))
 thread=rd(instance+8)
 if not rd(thread+0x70)&2:wr(thread+0x70,rd(thread+0x70)|2);wr(instance+12,1,1)
def cleanup():
 if rd(CTX+12,1):thread=rd(CTX+8);wr(thread+0x70,rd(thread+0x70)&0xfffffffd)
def bad():wr(port(0x6ead5f,[],True),22);port(0x6e9fc2,[0]*5,True);cleanup();return 0xffffffff
def emit(file,eax):
 if rd(file+12,1)&0x40 and not rd(file+8):wr(COUNTER,rd(COUNTER)+1);return eax
 count=U(rd(file+4)-1);wr(file+4,count)
 if I(count)>=0:wr(rd(file),eax,1);wr(file,rd(file)+1);eax&=255
 else:char=eax&255;eax=port(0x6eecd9,[U(char if char<128 else char-256),file],True)
 wr(COUNTER,rd(COUNTER)|eax if eax==0xffffffff else rd(COUNTER)+1);return eax
def repeat(file,char,count):
 while count>0:
  count-=1;emit(file,char)
  if rd(COUNTER)==0xffffffff:break

def span(file,p,count):
 if rd(file+12,1)&0x40 and not rd(file+8):wr(COUNTER,rd(COUNTER)+count);return
 while I(count)>0:
  count=U(count-1);emit(file,rd(p,1));p=U(p+1)
  if rd(COUNTER)==0xffffffff:
   error=port(0x6ead5f,[],True)
   if rd(error)!=42:break
   emit(file,0x3f)
def strlen(p):
 q=p
 while rd(q,1):q=U(q+1)
 return U(q-p)
def descriptor(file):
 if I(rd(file+16))in[-1,-2]:return 0x829c00
 return U(rd(U(0x29a9b40+(I(rd(file+16))>>5)*4))+(rd(file+16)&31)*56)
def execute_model(file,fmt,locale,arguments):
 ctor(CTX,locale)
 if not file:return bad()
 if not rd(file+12,1)&0x40:
  if rd(descriptor(file)+0x24,1)&0x7f:return bad()
  if rd(descriptor(file)+0x24,1)&0x80:return bad()
 if not fmt:return bad()
 wr(COUNTER,0);state=precision=width=prefixlen=digitoff=flags=allocated=body=length=capitals=0;wide=skip=False;ch=rd(fmt,1)
 while ch and I(rd(COUNTER))>=0:
  nxt=U(fmt+1);category=rd(0x777e80+ch,1)&15 if(ch-32)&255<89 else 0;sb=rd(0x777ea0+category*8+state,1);state=(sb if sb<128 else sb-256)>>4;literal=False
  if state==1:precision=-1;capitals=0;skip=False;width=prefixlen=flags=0;wide=False
  elif state==2:flags|={32:2,35:128,43:1,45:4,48:8}.get(ch,0)
  elif state==3:
   if ch==42:
    width=I(rd(arguments));arguments+=4
    if width<0:flags|=4;width=I(-width)
   else:width=I(width*10-48+ch)
  elif state==4:precision=0
  elif state==5:
   if ch==42:precision=I(rd(arguments));arguments+=4;precision=max(-1,precision)
   else:precision=I(precision*10-48+ch)
  elif state==6:
   if ch==73:
    a=rd(nxt,1)
    if a==54 and rd(nxt+1,1)==52:flags|=0x8000;nxt+=2
    elif a==51 and rd(nxt+1,1)==50:flags&=0xffff7fff;nxt+=2
    elif a not in b'diouxX':state=0;literal=True
   elif ch==104:flags|=32
   elif ch==108:
    if rd(nxt,1)==108:flags|=0x1000;nxt+=1
    else:flags|=16
   elif ch==119:flags|=0x800
  elif state==0:literal=True
  elif state==7:
   integer=ch in b'diouxXp';radix=10
   if ch in b'di':flags|=64
   elif ch==111:
    radix=8
    if flags&128:flags|=512
   elif ch in b'xXp':
    radix=16;digitoff=39 if ch==120 else 7
    if ch==112:precision=8
    if flags&128:wr(PREFIX,48,1);wr(PREFIX+1,digitoff+81,1);prefixlen=2
   if integer:
    if flags&0x9000:number=rd(arguments,8);arguments+=8
    else:
     word=rd(arguments);arguments+=4
     if flags&32:word=U((word&32767)-(word&32768))if flags&64 else word&65535
     number=(I(word)if flags&64 else word)&0xffffffffffffffff
    if flags&64 and number>>63:number=(-number)&0xffffffffffffffff;flags|=256
    if not flags&0x9000:number&=0xffffffff
    if precision<0:precision=1
    else:flags&=0xfffffff7;precision=min(512,precision)
    if not number:prefixlen=0
    p=FRAME+0x1eb
    while True:
     old=precision;precision=I(precision-1)
     if old<=0 and not number:break
     number,digit=divmod(number,radix);digit+=48
     if digit>57:digit+=digitoff
     wr(p,digit,1);p-=1
    length=FRAME+0x1eb-p;body=p+1
    if flags&512 and(not length or rd(body,1)!=48):body-=1;wr(body,48,1);length+=1
   elif ch in b'sS':
    if ch==83 and not flags&0x830:flags|=0x800
    limit=0x7fffffff if precision==-1 else precision;body=rd(arguments);arguments+=4;wide=bool(flags&0x810)
    if not body:body=rd(0x829aac if wide else 0x829aa8)
    p=body
    while limit:
     limit=I(limit-1)
     if not rd(p,2 if wide else 1):break
     p+=2 if wide else 1
    length=(p-body)//(2 if wide else 1)
   elif ch in b'cC':
    if ch==67 and not flags&0x830:flags|=0x800
    char=rd(arguments,2);arguments+=4;body=BUF
    if flags&0x810:skip=bool(port(0x701ea2,[FRAME-0x28,BUF,512,char],True));length=rd(FRAME-0x28)
    else:wr(BUF,char,1);length=1
   elif ch==90:
    z=rd(arguments);arguments+=4;body=rd(0x829aa8)
    if not z or not rd(z+4):length=strlen(body)
    else:
     body=rd(z+4);zlen=(rd(z,2)&32767)-(rd(z,2)&32768);wide=bool(flags&0x800);length=U(int(zlen/2)if wide else zlen)
   elif ch==110:
    target=rd(arguments);arguments+=4
    if not port(0x6e7a93,[],True):return bad()
    wr(target,rd(COUNTER),2 if flags&32 else 4);skip=True
   elif ch in b'aAeEfgG':
    if ch in b'AEG':ch+=32;capitals=1
    flags|=64;capacity=512;body=BUF
    if precision<0:precision=6
    elif precision==0:
     if ch==103:precision=1
    else:
     precision=min(512,precision)
     if precision>163:
      allocated=port(0x6f076f,[precision+349],True)
      if allocated:body=allocated;capacity=precision+349
      else:precision=163
    wr(FRAME-0x80,rd(arguments));wr(FRAME-0x7c,rd(arguments+4));arguments+=8;fn=port(0x6f01bc,[rd(0x829a98)],True);port(fn,[FRAME-0x80,body,capacity,ch,precision,capitals,CTX],True);alternate=bool(flags&128)
    if alternate and precision==0:fn=port(0x6f01bc,[rd(0x829aa4)],True);port(fn,[body,CTX],True)
    if ch==103 and not alternate:fn=port(0x6f01bc,[rd(0x829aa0)],True);port(fn,[body,CTX],True)
    if rd(body,1)==45:flags|=256;body+=1
    length=strlen(body)
   if not skip:
    if flags&64:
     sign=45 if flags&256 else 43 if flags&1 else 32 if flags&2 else None
     if sign!=None:wr(PREFIX,sign,1);prefixlen=1
    padding=I(width-I(length)-prefixlen)
    if not flags&12:repeat(file,32,padding)
    span(file,PREFIX,prefixlen)
    if flags&8 and not flags&4:repeat(file,48,padding)
    if not wide or I(length)<1:span(file,body,length)
    else:
     left=length;p=body
     while True:
      char=rd(p,2);p+=2;left-=1;status=port(0x701ea2,[FRAME-0x70,FRAME+0x1ec,6,char],True);count=rd(FRAME-0x70)
      if status or not count:wr(COUNTER,0xffffffff);break
      span(file,FRAME+0x1ec,count)
      if not left:break
    if I(rd(COUNTER))>=0 and flags&4:repeat(file,32,padding)
   if allocated:port(0x6e7633,[allocated],True);allocated=0
  if literal:
   wide=False;lead=bool(rd(rd(rd(CTX)+0xc8)+ch*2,2)&0x8000)
   if lead:
    emit(file,ch);ch=rd(nxt,1);nxt+=1
    if not ch:return bad()
   emit(file,ch)
  fmt=nxt;ch=rd(fmt,1)
 cleanup();return rd(COUNTER)

# Actual nested frame positions calculated from original prologues and confirmed in callback traces.
FILE=n.STACK+0xdbb4;OUT=n.STACK+0xdbfc;ARGS=n.STACK+0xe00c;FRAME=n.STACK+0xd99c;CTX=FRAME-0x64;COUNTER=FRAME-0x34;PREFIX=FRAME-0x38;BUF=FRAME-0x14
TABLE=0x2983740;HANDLES=0x8007a0;DATA=D+0x5000;WRITE=n.STOP+0x200;n.pack('<I',0x7510e8,WRITE);ms={};ns={}
def writeport139(model,raw,data,count):
 state=ms if model else ns;events.append(dict(name='WriteFile',args=[raw,data.hex(),count,0]));amount=min(count,config.get('writeCap',1024));p=state['position'];end=p+amount
 if end>len(state['bytes']):state['bytes'].extend(b'\0'*(end-len(state['bytes'])))
 state['bytes'][p:end]=data[:amount];state['position']=end;state['writes']+=1
 return config.get('writeBoolean',1),amount if config.get('reportWritten',True)else None
def hook139(mu,address,size,data):
 if address!=WRITE:return
 sp=mu.reg_read(UC_X86_REG_ESP);raw,p,count,out,overlapped=n.unpack('<5I',sp+4);success,got=writeport139(False,raw,n.read(p,count),count)
 if got is not None:n.pack('<I',out,got)
 mu.reg_write(UC_X86_REG_EAX,success);mu.reg_write(UC_X86_REG_ESP,sp+24);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook139)
def modelwrite139(h,p,count):
 if h>=0x1000:return 0
 if h>=0x400:
  r=TABLE+(h-0x400)*20;cur=rd(r+8);size=min(count,I(U(rd(r+4)-cur+1)))
  if size<0:raise ValueError('nonnegative memory capacity')
  data=bytes(rd(p+i,1)for i in range(size))
  for i,b in enumerate(data):wr(cur+i,b,1)
  wr(r+8,U(rd(r+8)+size));return size
 success,got=writeport139(True,rd(HANDLES+(h-1)*4),bytes(rd(p+i,1)for i in range(count)),count);return(got or 0)if success else 0
def filestate139(s):return dict(position=s['position'],bytes=s['bytes'].hex(),seekCalls=0,writeCalls=s['writes'])
def execute139(c):
 global shadow,segments,events,config,checks,flushes,ms,ns
 config=c;n.write(D,bytes([0xcd])*0x6000);n.write(n.STACK+0xd800,bytes([0xcd])*0x800);n.pack('<4I',FILE,OUT,c.get('capacity',1024),0 if c.get('countOnly')else OUT,c.get('flags',0x42));n.pack('<I',FILE+16,U(c.get('descriptor',0)));n.write(FORMAT,c['format'].encode('latin1')+b'\0');n.write(TEXT,b'alpha\0omega');n.write(WTEXT,'a\u00e9\u03a9'.encode('utf-16le')+b'\0\0');n.pack('<HHI',DESC,c.get('zLength',5),0,WTEXT if c.get('zWide')else TEXT);n.pack('<2I',LOC,LI,MB);n.pack('<I',LI+0xc8,CT);n.write(CT,bytes(512));n.pack('<H',CT+0x81*2,0x8000);n.pack('<3I',THREAD+0x68,MB,LI,c.get('threadFlags',0));n.pack('<I',ERR,c.get('errorValue',21));n.pack('<I',0x82a678,LI);n.pack('<I',0x82a498,MB);n.pack('<I',0x82a594,1);n.pack('<3I',0x829a98,FLOAT,0,TRIM);n.pack('<I',0x829aa4,POINT);n.pack('<2I',0x829aa8,TEXT,WTEXT);n.write(0x829c00,bytes(56));n.write(D+0x4700,bytes(56));n.pack('<I',0x29a9b40,D+0x4700);n.write(D+0x4724,bytes([c.get('descriptorFlags',0)]));n.write(0x829c24,bytes([c.get('descriptorFlags',0)]));values=c.get('arguments',[0]*12);n.pack('<'+'I'*len(values),ARGS,*[U(v)for v in values]);file=0 if c.get('nullFile')else FILE;fmt=0 if c.get('nullFormat')else FORMAT;locale=0
 h=c['handle'];n.write(DATA,bytes((i*37+11)&255 for i in range(512)));n.write(TABLE,bytes(400));n.write(HANDLES,bytes(256))
 if 0x400<=h<0x1000:
  for i in range(20):n.pack('<I',TABLE+i*20+16,1 if i<h-0x400 else 0)
  assert n.call(0x4f02d0,[DATA,c.get('fileLength',257),1])==h;n.call(0x4f6de0,[h,c['current'],0,0])
 elif h<0x400:n.pack('<I',HANDLES+(h-1)*4,0x12345678+h)
 n.pack('<'+'I'*len(values),ARGS,*[U(v)for v in values])
 segments=[(D,0x6000),(TABLE,400),(HANDLES,256),(ARGS,len(values)*4),(0x777e80,0x100),(0x829a98,24),(0x82a678,4),(0x82a498,4),(0x82a594,4),(0x829c00,56),(0x29a9b40,4)];initial=snap()+[dict(address=n.STACK+0xd800,bytes=n.read(n.STACK+0xd800,0x800).hex())];shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};initialFile=dict(position=c['current'],bytes=bytes((i*37+11)&255 for i in range(64)).hex());ms=dict(position=c['current'],bytes=bytearray.fromhex(initialFile['bytes']),writes=0);ns=dict(position=c['current'],bytes=bytearray.fromhex(initialFile['bytes']),writes=0);events=[];flushes=0
 wr(FILE+8,OUT);wr(FILE,OUT);wr(FILE+4,0x7fffffff);wr(FILE+12,0x42);result=execute_model(FILE,FORMAT,0,ARGS);count=U(rd(FILE+4)-1);wr(FILE+4,count)
 if I(count)<0:port(0x6eecd9,[0,FILE],True)
 else:wr(rd(FILE),0,1)
 length=strlen(OUT);assert length<1024;wanted=modelwrite139(h,OUT,length);model=snap(True);me=events.copy();mf=filestate139(ms);events=[];actual=n.call(0x4f07b0,[h,FORMAT,*[U(v)for v in values]],count=4000000);final=snap();ne=events.copy();nf=filestate139(ns)
 for group,a,b in [('return',actual,wanted),('images',final,model),('events',ne,me),('file',nf,mf)]:
  checks+=1
  if a!=b:
   if group=='images':a=[[hex(x['address']+i),u,v]for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:10];b='diff'
   errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(handle=h,format=FORMAT,arguments=ARGS,file=FILE,buffer=OUT,frame=FRAME),initial=initial,initialFile=initialFile,final=final,returnValue=actual,nativeEvents=ne,finalFile=nf))
formats=[('plain',[]),('',[]),('%s:%+08d:%#x',[TEXT,123,0xdeadbeef]),('%I64d:%llu',[0xffffffff,0xffffffff,1,1]),('%cTAIL',[0]),('%10.3s:%-8u',[TEXT,77]),('%S',[WTEXT]),('a%nTAIL',[D+0x900]),('%f:%g',[0,0x3ff00000,0,0x40000000]),('%*.*d',[12,5,42]),('%%:%q:%Ifoo',[]),('X'*511,[])]
for h,(fmt,args),current in itertools.product([1,64,0x400,0x413,0x1000],formats,[0,256]):
 c=dict(handle=h,format=fmt,arguments=args or[0],current=current,writeCap=[0,2,1024][len(cases)%3],writeBoolean=len(cases)&1,reportWritten=bool(len(cases)&2));execute139(c)
for flag in[0,1]:execute139(dict(handle=0x400,format='abc%nTAIL',arguments=[D+0x900],current=0,nEnabled=flag))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,closure='Actual raw208-byte4f07b0→6e7b25→6e7aa9→full6eef05/helpers/locale→realmemory/Win32/CRTwrites and originalsecurity-cookie success; output<1024; locale/conversion services remain explicit')
(nm.BASE/'reports/script-phase139-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase139-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
