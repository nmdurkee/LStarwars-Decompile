"""Original wctomb_s wrapper and locale core, actual memset and locale constructor, explicit Windows imports."""
import importlib.util,json,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
D=n.DATA;RESULT=D+0x100;BUFFER=D+0x200;LOC=D+0x800;LI=D+0xa00;MB=D+0xc00;THREAD=D+0xe00;ERR=D+0xf00;ERR2=D+0xf10;ARGS=n.STACK+0xe004;WIN=n.STOP+0x900;LAST=n.STOP+0x910;n.pack('<I',0x7511ec,WIN);n.pack('<I',0x751190,LAST);shadow={};segments=[];events=[];config={};calls={};cases=[];errors=[];checks=0
U=lambda x:x&0xffffffff
def rd(p,z=4):return sum(shadow[p+i]<<(8*i)for i in range(z))
def wr(p,v,z=4):
 for i in range(z):
  if p+i not in shadow:raise KeyError(p+i)
  shadow[p+i]=(v>>(8*i))&255

def snap(model=False,rows=None):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in(rows or segments)]
def port(address,args,model):
 read=rd if model else lambda p,z=4:int.from_bytes(n.read(p,z),'little');write=wr if model else lambda p,v,z=4:n.write(p,int(v&((1<<(z*8))-1)).to_bytes(z,'little'));events.append(dict(callback=address,args=list(args)));calls[address]=calls.get(address,0)+1
 for p,z,v in config.get('patches',{}).get(hex(address),[]):write(p,v,z)
 if address==0x6fc355:return config.get('typeReturn',args[1])
 if address==0x6fc0ab:
  events[-1]['source']=[read(args[3]+i,1)for i in range(args[4])]
  payload=bytes.fromhex(config.get('mappedOutput','617a'))
  for i,b in enumerate(payload[:args[6]]):write(args[5]+i,b,1)
  return config.get('mapReturn',2)
 if address==0x6f040c:return THREAD
 if address==0x6fae25:return LI
 if address==0x6fa67a:return MB
 if address==0x6ead5f:return ERR2 if config.get('alternateErrno')and calls[address]>1 else ERR
 if address==0x6e9fc2:return 0
 if address==LAST:return config.get('lastError',21)
 if address==WIN:
  payload=bytes.fromhex(config.get('payload','c3a9'));write(args[7],config.get('usedDefault',0))
  if args[4]and config.get('winCount',2)!=0:
   for i,b in enumerate(payload[:args[5]]):write(args[4]+i,b,1)
  return config.get('winCount',2)
 raise ValueError(hex(address))
ports={0x6fc355:3,0x6fc0ab:9,0x6f040c:0,0x6fae25:0,0x6fa67a:0,0x6ead5f:0,0x6e9fc2:5,WIN:8,LAST:0}
def hook(mu,address,size,data):
 if address not in ports:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*ports[address],sp+4))if ports[address]else[];ret=n.unpack('<I',sp)[0];v=port(address,args,False);mu.reg_write(UC_X86_REG_EAX,U(v));mu.reg_write(UC_X86_REG_ESP,sp+4+(ports[address]*4 if address in[WIN,LAST]else 0));mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
def ctor(obj,locale):
 wr(obj+12,0,1)
 if locale:wr(obj,rd(locale));wr(obj+4,rd(locale+4));return
 t=port(0x6f040c,[],True);wr(obj+8,t);wr(obj,rd(t+0x6c));wr(obj+4,rd(t+0x68))
 if rd(obj)!=rd(0x82a678)and not rd(t+0x70)&rd(0x82a594):wr(obj,port(0x6fae25,[],True))
 if rd(obj+4)!=rd(0x82a498)and not rd(rd(obj+8)+0x70)&rd(0x82a594):wr(obj+4,port(0x6fa67a,[],True))
 t=rd(obj+8)
 if not rd(t+0x70)&2:wr(t+0x70,rd(t+0x70)|2);wr(obj+12,1,1)
def cleanup(context):
 if rd(context+12,1):t=rd(context+8);wr(t+0x70,rd(t+0x70)&0xfffffffd)
def invalid(code):wr(port(0x6ead5f,[],True),code);port(0x6e9fc2,[0]*5,True)
def fill(buffer,capacity):
 for i in range(capacity):wr(buffer+i,0,1)
def local(args,context):
 buffer=rd(args+4);capacity=rd(args+8);result=rd(args)
 if not buffer and capacity:
  if result:wr(result,0)
  return 0
 if result:wr(result,0xffffffff)
 if capacity>0x7fffffff:invalid(22);return 22
 ctor(context,rd(args+16));locale=rd(context)
 if not rd(locale+0x14):
  char=rd(args+12,2)
  if char<=255:
   if buffer:
    if not capacity:invalid(34);cleanup(context);return 34
    wr(buffer,char,1)
   result=rd(args)
   if result:wr(result,1)
   cleanup(context);return 0
  if buffer and capacity:fill(buffer,capacity)
 else:
  wr(args+4,0);count=port(WIN,[rd(locale+4),0,args+12,1,buffer,capacity,0,args+4],True)
  if count==0:
   if port(LAST,[],True)==122:
    if buffer and capacity:fill(buffer,capacity)
    invalid(34);cleanup(context);return 34
  elif not rd(args+4):
   result=rd(args)
   if result:wr(result,count)
   cleanup(context);return 0
 wr(port(0x6ead5f,[],True),42);v=rd(port(0x6ead5f,[],True));cleanup(context);return v

CTABLE=D+0x1000;LOWER=D+0x1400;LI2=D+0x1600;CTABLE2=D+0x1800;LOWER2=D+0x1a00;FRAME=n.STACK+0xdffc

def lead172(character,context):return rd(rd(rd(context)+0xc8)+(character&255)*2,2)&0x8000

def model172(method):
 context=FRAME-(0x18 if method=='Lower'else 0x10);ctor(context,rd(ARGS+4));locale=rd(context);character=rd(ARGS);value=character
 if method=='Digit':
  if ((rd(locale+0xac)&0x7fffffff)-(rd(locale+0xac)&0x80000000))<=1:value=rd(U(rd(locale+0xc8)+character*2),1)&4
  else:value=port(0x6fc355,[character,4,context],True)
  cleanup(context);return value
 if character<256:
  if ((rd(locale+0xac)&0x7fffffff)-(rd(locale+0xac)&0x80000000))<=1:classification=rd(rd(locale+0xc8)+character*2,1)&1
  else:classification=port(0x6fc355,[character,1,context],True);locale=rd(context)
  if classification:value=rd(rd(locale+0xcc)+character,1)
 else:
  input=FRAME-4;output=FRAME-8;count=1;lead=False
  if ((rd(locale+0xac)&0x7fffffff)-(rd(locale+0xac)&0x80000000))>1:
   signed=character if character<0x80000000 else character-0x100000000;wr(ARGS,U(signed>>8));lead=bool(lead172(rd(ARGS)&255,context))
  if lead:wr(input,rd(ARGS,1),1);wr(input+1,character,1);wr(input+2,0,1);count=2
  else:wr(port(0x6ead5f,[],True),42);wr(input,character,1);wr(input+1,0,1)
  locale=rd(context);mapped=port(0x6fc0ab,[context,rd(locale+0x14),0x100,input,count,output,3,rd(locale+4),1],True)
  if mapped==1:value=rd(output,1)
  elif mapped:value=rd(output,1)<<8|rd(output+1,1)
 cleanup(context);return value

def execute(c):
 global config,shadow,segments,events,calls,checks
 config=c;n.write(D,bytes([0xcd])*0x2400);n.write(n.STACK+0xd800,bytes([0xcd])*0x830);n.pack('<2I',LOC,LI,MB);n.pack('<I',LI+0xac,U(c.get('width',1)));n.pack('<I',LI+4,65001);n.pack('<I',LI+0x14,1033);n.pack('<2I',LI+0xc8,CTABLE,LOWER);n.pack('<I',LI2+0xac,1);n.pack('<2I',LI2+0xc8,CTABLE2,LOWER2)
 for i in range(256):
  n.pack('<H',CTABLE+i*2,(1 if 65<=i<=90 else 4 if 48<=i<=57 else 0)|(0x8000 if c.get('lead')else 0));n.write(LOWER+i,bytes([i+32 if 65<=i<=90 else i]));n.pack('<H',CTABLE2+i*2,5);n.write(LOWER2+i,b'~')
 n.pack('<3I',THREAD+0x68,MB,LI,c.get('threadFlags',0));n.pack('<I',ERR,21);n.pack('<I',0x82a678,LI);n.pack('<I',0x82a498,MB);n.pack('<I',0x82a594,1);n.pack('<I',0x29a9c48,0);character=U(c.get('character',65));locale=c.get('locale',LOC);n.pack('<2I',ARGS,character,locale);method=c.get('method','Lower');segments=[(D,0x2400),(ARGS,8),(0x82a678,4),(0x82a498,4),(0x82a594,4)]
 if method=='Digit'and c.get('width',1)<=1:
  target=U(CTABLE+character*2)
  if not D<=target<D+0x2400:
   try:n.read(target,1);segments.append((target,1))
   except Exception:pass
 initial=snap()+[dict(address=n.STACK+0xd800,bytes=n.read(n.STACK+0xd800,0x804).hex())];shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];calls={};mf=False;want=0
 try:want=model172(method)
 except KeyError:mf=True
 modelImage=snap(True);me=events.copy();events=[];calls={};nf=False;got=0
 try:got=n.call(0x70138e if method=='Lower'else 0x700f21,[character,locale],count=500000)
 except RuntimeError:nf=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,modelImage),('events',ne,me)]:
  checks+=1
  if a!=b:
   diffs=[]
   if group=='images':
    for x,y in zip(a,b):
     for i,(aa,bb)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes']))):
      if aa!=bb:diffs.append([hex(x['address']+i),aa,bb])
   errors.append(dict(group=group,context=c,native=a if group!='images'else diffs[:16],model=b if group!='images'else'byte model'))
 cases.append(dict(context=c,inputs=dict(method=method,characterSlot=ARGS,localeSlot=ARGS+4,frame=FRAME),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for method,width,character,locale,lead in itertools.product(['Lower','Digit'],[-1,0,1,2,3],[0,49,65,90,97,255,256,257,0x8141,65535,0xffffffff,0x80000000],[0,LOC],[False,True]):execute(dict(method=method,width=width,character=character,locale=locale,lead=lead))
for method,result,flags in itertools.product(['Lower','Digit'],[0,1,4,0x80000000,0xffffffff],[0,2,0x80000000]):execute(dict(method=method,width=2,typeReturn=result,threadFlags=flags,locale=0))
for character,result,lead in itertools.product([256,0x8141,0xffffffff],[0,1,2,3,0xffffffff],[False,True]):execute(dict(character=character,width=2,mapReturn=result,lead=lead,locale=0))
for c in[dict(width=2,character=65,patches={'0x6fc355':[[FRAME-0x18,4,LI2]]}),dict(locale=0,patches={'0x6f040c':[[ARGS,4,97]]}),dict(character=0x8141,width=2,patches={'0x6fc0ab':[[ARGS,4,1234]]}),dict(method='Digit',character=0x10000000),dict(locale=0xdead0000),dict(locale=0xdead0000,method='Digit')]:execute(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=['6FC355 locale classification','6FC0AB CRT locale mapping','6F040C/6FAE25/6FA67A locale runtime','6EAD5F errno'],closure='actual70138E/700F21→actual6EB53D/6FC0EE, live original argument SAR8 and packed byte mapping')
(nm.BASE/'reports/script-phase172-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase172-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
