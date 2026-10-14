"""Full original 2420-byte narrow printf parser and recovered byte/locale children; explicit conversion/runtime services."""
import importlib.util,json,itertools,random,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
D=n.DATA;FILE=n.STACK+0xdfdc;OUT=D+0x1000;FORMAT=D+0x300;ARGS=D+0x800;TEXT=D+0x500;WTEXT=D+0x600;DESC=D+0x700;LOC=D+0x3000;LI=D+0x3200;MB=D+0x3400;CT=D+0x3600;THREAD=D+0x3800;ERR=D+0x3900;HEAP=D+0x4000;FRAME=n.STACK+0xddc8;CTX=FRAME-0x64;COUNTER=FRAME-0x34;PREFIX=FRAME-0x38;BUF=FRAME-0x14;FLOAT=n.STOP+0xa00;POINT=n.STOP+0xa10;TRIM=n.STOP+0xa20
shadow={};segments=[];events=[];config={};cases=[];errors=[];checks=0;flushes=0;PROBE=n.STOP+0xc00;WIN=n.STOP+0xb00;LAST=n.STOP+0xb10;n.pack('<I',0x7511ec,WIN);n.pack('<I',0x751190,LAST)
U=lambda v:v&0xffffffff
I=lambda v:(v&0x7fffffff)-(v&0x80000000)
def rd(p,z=4):return sum(shadow[U(p+i)]<<(i*8)for i in range(z))
def wr(p,v,z=4):
 for i in range(z):shadow[U(p+i)]=(v>>(i*8))&255

def snap(model=False,rows=None):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in(rows or segments)]
def port(address,args,model):
 global flushes
 if address==0x701ea2:return actual_wide(args)
 if address==0x6e7a93:return int(rd(0x297c194)==(rd(0x829570)|1))
 read=rd if model else lambda p,z=4:int.from_bytes(n.read(p,z),'little');write=wr if model else lambda p,v,z=4:n.write(p,int(v&((1<<(8*z))-1)).to_bytes(z,'little'))
 event=dict(callback=address,args=list(args))
 if address==0x6ead5f:event['errno']=read(ERR)
 if address==FLOAT:event['value']=read(args[0],8)
 events.append(event)
 if address==PROBE:
  event['header']=[read(args[0]+i*4)for i in range(8)]
  write(args[0]+4,config.get('probeCount',0x12345678));return config.get('probeReturn',0xfedcba98)
 if address==0x6f040c:return THREAD
 if address==0x6fae25:return LI
 if address==0x6fa67a:return MB
 if address==0x6ead5f:return ERR
 if address==0x6e9fc2:return 0
 if address==0x6eecd9:
  flushes+=1;write(ERR,config.get('errorValue',21));return config.get('flushReturn',0xffffffff)
 if address==LAST:return config.get('lastError',21)
 if address==WIN:
  payload=bytes.fromhex(config.get('widePayload','c3a9'));write(args[7],config.get('usedDefault',0))
  if args[4]and config.get('winCount',2)!=0:
   for i,b in enumerate(payload[:args[5]]):write(args[4]+i,b,1)
  return config.get('winCount',2)
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
ports={0x6f040c:0,0x6fae25:0,0x6fa67a:0,0x6ead5f:0,0x6e9fc2:5,0x6eecd9:2,0x6e7a93:0,0x6f01bc:1,0x6f076f:1,0x6e7633:1,0x701ea2:4,FLOAT:7,POINT:2,TRIM:2,WIN:8,LAST:0,PROBE:4}
def hook(mu,address,size,data):
 if address not in ports or address in[0x6e7a93,0x701ea2]:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*ports[address],sp+4))if ports[address]else[];value=port(address,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,U(value));mu.reg_write(UC_X86_REG_ESP,sp+4+(ports[address]*4 if address in[WIN,LAST]else 0));mu.reg_write(UC_X86_REG_EIP,ret)
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

def wide_cleanup(context):
 if rd(context+12,1):t=rd(context+8);wr(t+0x70,rd(t+0x70)&0xfffffffd)
def wide_invalid(code):wr(port(0x6ead5f,[],True),code);port(0x6e9fc2,[0]*5,True)
def wide_fill(buffer,capacity):
 for i in range(capacity):wr(buffer+i,0,1)
def wide_local(args,context):
 buffer=rd(args+4);capacity=rd(args+8);result=rd(args)
 if not buffer and capacity:
  if result:wr(result,0)
  return 0
 if result:wr(result,0xffffffff)
 if capacity>0x7fffffff:wide_invalid(22);return 22
 ctor(context,rd(args+16));locale=rd(context)
 if not rd(locale+0x14):
  char=rd(args+12,2)
  if char<=255:
   if buffer:
    if not capacity:wide_invalid(34);wide_cleanup(context);return 34
    wr(buffer,char,1)
   result=rd(args)
   if result:wr(result,1)
   wide_cleanup(context);return 0
  if buffer and capacity:wide_fill(buffer,capacity)
 else:
  wr(args+4,0);count=port(WIN,[rd(locale+4),0,args+12,1,buffer,capacity,0,args+4],True)
  if count==0:
   if port(LAST,[],True)==122:
    if buffer and capacity:wide_fill(buffer,capacity)
    wide_invalid(34);wide_cleanup(context);return 34
  elif not rd(args+4):
   result=rd(args)
   if result:wr(result,count)
   wide_cleanup(context);return 0
 wr(port(0x6ead5f,[],True),42);v=rd(port(0x6ead5f,[],True));wide_cleanup(context);return v

def actual_wide(args):
 caller=FRAME-0x9c;child=FRAME-0xb4
 for i,value in enumerate(args):wr(caller+i*4,value)
 wr(child+16,0)
 for i in[3,2,1,0]:wr(child+i*4,rd(caller+i*4))
 return wide_local(child,FRAME-0xcc)

def execute(c):
 global shadow,segments,events,config,checks,flushes
 config=c;n.pack('<I',0x829570,c.get('cookie',0x12345678));n.pack('<I',0x297c194,(c.get('cookie',0x12345678)|1)if c.get('nEnabled',1)else(c.get('cookie',0x12345678)|1)^2);n.write(D,bytes([0xcd])*0x4800);n.write(n.STACK+0xd800,bytes([0xcd])*0x800);n.pack('<4I',FILE,OUT,c.get('capacity',1024),0 if c.get('countOnly')else OUT,c.get('flags',0x42));n.pack('<I',FILE+16,U(c.get('descriptor',0)));n.write(FORMAT,c['format'].encode('latin1')+b'\0');n.write(TEXT,b'alpha\0omega');n.write(WTEXT,'a\u00e9\u03a9'.encode('utf-16le')+b'\0\0');n.pack('<HHI',DESC,c.get('zLength',5),0,WTEXT if c.get('zWide')else TEXT);n.pack('<2I',LOC,LI,MB);n.pack('<I',LI+0xc8,CT);n.pack('<I',LI+0x14,c.get('wideMode',0));n.pack('<I',LI+4,65001);n.write(CT,bytes(512));n.pack('<H',CT+0x81*2,0x8000);n.pack('<3I',THREAD+0x68,MB,LI,c.get('threadFlags',0));n.pack('<I',ERR,c.get('errorValue',21));n.pack('<I',0x82a678,LI);n.pack('<I',0x82a498,MB);n.pack('<I',0x82a594,1);n.pack('<3I',0x829a98,FLOAT,0,TRIM);n.pack('<I',0x829aa4,POINT);n.pack('<2I',0x829aa8,TEXT,WTEXT);n.write(0x829c00,bytes(56));n.write(D+0x4700,bytes(56));n.pack('<I',0x29a9b40,D+0x4700);n.write(D+0x4724,bytes([c.get('descriptorFlags',0)]));n.write(0x829c24,bytes([c.get('descriptorFlags',0)]));values=c.get('arguments',[0]*12);n.pack('<'+'I'*len(values),ARGS,*[U(v)for v in values]);file=0 if c.get('nullFile')else FILE;fmt=0 if c.get('nullFormat')else FORMAT;locale=0 if c.get('nullLocale')else LOC
 segments=[(FILE,32),(0x29a9c48,4),(0x829570,4),(0x297c194,4),(D,0x4800),(0x777e80,0x100),(0x829a98,24),(0x82a678,4),(0x82a498,4),(0x82a594,4),(0x829c00,56),(0x29a9b40,4)];initial=snap()+[dict(address=n.STACK+0xd800,bytes=n.read(n.STACK+0xd800,0x800).hex())];shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];flushes=0;mf=False;want=0
 try:
  if not fmt:wr(port(0x6ead5f,[],True),22);port(0x6e9fc2,[0]*5,True);want=0xffffffff
  else:
   wr(FILE+4,0x7fffffff);wr(FILE+12,0x42);wr(FILE+8,0);wr(FILE,0);want=port(PROBE,[FILE,fmt,locale,ARGS],True)if c.get('probe')else execute_model(FILE,fmt,locale,ARGS)
 except(KeyError,ValueError)as e:mf=True
 model=snap(True);me=events.copy();events=[];flushes=0;nf=False;got=0
 try:got=n.call(0x6e7b3c,[PROBE if c.get('probe')else 0x6eef05,fmt,locale,ARGS],count=1000000)
 except RuntimeError:nf=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:
   diffs=[]
   if group=='images':
    for x,y in zip(a,b):
     for i,(aa,bb)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes']))):
      if aa!=bb:diffs.append([hex(x['address']+i),aa,bb])
   errors.append(dict(group=group,context=c,native=a if group!='images'else diffs[:12],model=b if group!='images'else'byte model'))
 cases.append(dict(context=c,inputs=dict(function=PROBE if c.get('probe')else 0x6eef05,file=FILE,format=fmt,locale=locale,arguments=ARGS,frame=FRAME),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for fmt,value in itertools.product(['%d','%i','%u','%o','%x','%X','%p','%+08d','% 12d','%-12d','%#08x','%#.0o','%.0d','%.8x','%hd','%hu','%ld','%I32u','%Iu'],[0,1,-1,0x80000000,0x7fffffff,65535]):execute(dict(format='['+fmt+']',arguments=[value,1]))
for fmt,lo,hi in itertools.product(['%I64d','%llu','%#I64x','%020I64i','%.32llo'],[0,1,0xffffffff],[0,1,0x80000000,0xffffffff]):execute(dict(format=fmt,arguments=[lo,hi]))
for fmt,arg in itertools.product(['%s','%.0s','%.3s','%10s','%-10s','%S','%ls','%hs','%wZ','%Z'],[0,TEXT,WTEXT,DESC]):
 if fmt in['%Z','%wZ']and arg not in[0,DESC]:continue
 if fmt in['%S','%ls']and arg not in[0,WTEXT]:continue
 if fmt in['%s','%.0s','%.3s','%10s','%-10s','%hs']and arg not in[0,TEXT]:continue
 execute(dict(format=fmt,arguments=[arg],zWide=fmt=='%wZ',zLength=6 if fmt=='%wZ'else 5))
for fmt,char in itertools.product(['%c','%C','%hc','%lc','%wC'],[0,65,128,233,0x3a9,0xffff]):execute(dict(format=fmt,arguments=[char]))
for fmt in['%f','%e','%g','%G','%a','%A','%#.0f','%.0g','%020f','%.164f','%.600f']:
 for fail in[False,True]:execute(dict(format=fmt,arguments=[0,0x3ff00000],allocationFail=fail))
for fmt in['abc','%%','a%nb','a%hnb','a%n%u','%*.*d','%Ifoo','%q','%','%.','%00d','%999999999999d','\x81A','\x81']:
 execute(dict(format=fmt,arguments=[D+0x900 if 'n'in fmt else 8,3,123],nullLocale=True))
for c in[dict(format='abc',nullFile=True),dict(format='abc',nullFormat=True),dict(format='abc',nullLocale=True,threadFlags=2),dict(format='abc',flags=2,descriptorFlags=0),dict(format='abc',flags=2,descriptorFlags=1),dict(format='abc',flags=2,descriptor=-1),dict(format='abc',flags=2,descriptor=-2),dict(format='a%n',arguments=[D+0x900],nEnabled=0),dict(format='%-12d',arguments=[123],capacity=0),dict(format='%20s',arguments=[TEXT],capacity=2,flushReturn=0xffffffff),dict(format='%s',arguments=[TEXT],countOnly=True),dict(format='%wZ',arguments=[DESC],zLength=65535,zWide=True,countOnly=True),dict(format='%.512u',arguments=[1],countOnly=True),dict(format='%*.0d',arguments=[0x80000000,0],countOnly=True)]:execute(c)
rng=random.Random(159)
for i in range(180):
 width=rng.randrange(-32,33);precision=rng.choice([-1,0,1,2,8,16]);value=rng.getrandbits(32)
 execute(dict(format='%*.*s/%#x/%+d/%%',arguments=[width,precision,TEXT,value,rng.getrandbits(32)],nullLocale=bool(i&1),countOnly=i%5==0))
for flags,precision in itertools.product(['','+','#','0','-','+#0',' #','-0'],[0,1,163,164,512,600]):execute(dict(format='%'+flags+'.'+str(precision)+'g',arguments=[0,0xbff00000],allocationFail=bool(precision&1),floating='0' if precision&1 else '-0.50'))
for i in range(12):execute(dict(format='%s:%S:%c:%I64d:%f:%n:end',arguments=[TEXT,WTEXT,233,0xffffffff,0x80000000,0,0x3ff00000,D+0x900],nullLocale=bool(i&1),threadFlags=2 if i%3==0 else 0,countOnly=i%4==0))
for capacity,ret,error in itertools.product([0,1,3],[0xffffffff,65],[21,42]):execute(dict(format='%10s/%C/%-8d',arguments=[TEXT,233,123],capacity=capacity,flushReturn=ret,errorValue=error))

for mode,count,used,error in itertools.product([0,1],[0,1,2],[0,1],[21,122]):execute(dict(format='%C/%S/%ls/%wc/%n',arguments=[233,WTEXT,WTEXT,0,D+0x900],wideMode=mode,winCount=count,usedDefault=used,lastError=error,nullLocale=True))

for value,count,fmt in itertools.product([0,1,0x80000000,0xffffffff],[0,1,0x80000000,0xffffffff],[False,True]):execute(dict(format='probe',probe=True,probeCount=count,probeReturn=value,nullFormat=fmt))

report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:5],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,imports=dict(wide=WIN,lastError=LAST),closure='actual6E7B3C count helper pluswide701EA2/701D43 plus6E7A93 predicate plus6EEF05 full ownbody plus actual6EEE39/6EEE6C/6EEE90,6EB53D,6FC0EE,6F3C74,6EDD80,701F40 children; conversion, allocator, locale runtime and flush explicit')
(nm.BASE/'reports/script-phase167-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase167-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
