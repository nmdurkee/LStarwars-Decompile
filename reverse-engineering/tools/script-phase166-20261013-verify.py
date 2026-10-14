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
ports={0x6f040c:0,0x6fae25:0,0x6fa67a:0,0x6ead5f:0,0x6e9fc2:5,WIN:8,LAST:0}
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

def capacity():
 t=port(0x6f040c,[],True);l=rd(t+0x6c)
 if l!=rd(0x82a678)and not rd(t+0x70)&rd(0x82a594):l=port(0x6fae25,[],True)
 return rd(l+0xac)
def wrapper(method):
 frame=n.STACK+0xdffc;result=frame-4
 if method=='Capacity':return capacity()
 wr(result,0xffffffff)
 if method=='Local':
  context=frame-0x14;child=frame-0x28;ctor(context,rd(ARGS+8));wr(child+16,context);wr(child+12,rd(ARGS+4));wr(child+8,rd(rd(context)+0xac));wr(child+4,rd(ARGS));wr(child,result);status=local(child,frame-0x40);value=rd(result)if not status else 0xffffffff;cleanup(context);return value
 child=frame-0x18;wr(child+16,0);wr(child+12,rd(ARGS+4));size=capacity();wr(child+8,size);wr(child+4,rd(ARGS));wr(child,result);status=local(child,frame-0x30);return rd(result)if not status else 0xffffffff

def execute(c):
 global config,shadow,segments,events,calls,checks
 config=c;n.write(D,bytes([0xcd])*0x1400);n.write(n.STACK+0xd800,bytes([0xcd])*0x830);n.pack('<2I',LOC,LI,MB);n.pack('<I',LI+0x14,c.get('mode',0));n.pack('<I',LI+4,65001);n.pack('<I',LI+0xac,c.get('capacity',4));n.pack('<3I',THREAD+0x68,MB,LI,c.get('threadFlags',0));n.pack('<I',ERR,21);n.pack('<I',ERR2,123);n.pack('<I',0x82a678,0 if c.get('refresh')else LI);n.pack('<I',0x82a498,MB);n.pack('<I',0x82a594,c.get('mask',1));n.pack('<I',0x29a9c48,c.get('vectorZero',0));buffer=c.get('buffer',BUFFER);char=U(c.get('character',233));locale=c.get('locale',LOC);args=[buffer,char,locale];n.pack('<3I',ARGS,*args);method=c.get('method','Local')
 segments=[(D,0x1400),(ARGS,12),(0x82a678,4),(0x82a498,4),(0x82a594,4),(0x29a9c48,4)];initial=snap()+[dict(address=n.STACK+0xd800,bytes=n.read(n.STACK+0xd800,0x804).hex())];shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];calls={};mf=False;want=0
 try:want=wrapper(method)
 except KeyError:mf=True
 model=snap(True);me=events.copy();events=[];calls={};nf=False;got=0
 try:got=n.call({'Local':0x701ebd,'Standard':0x701f0c,'Capacity':0x70afe5}[method],args if method=='Local'else args[:2]if method=='Standard'else[],count=500000)
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
   errors.append(dict(group=group,context=c,native=a if group!='images'else diffs[:20],model=b if group!='images'else'byte model'))
 cases.append(dict(context=c,inputs=dict(method=method,caller=ARGS,frame=n.STACK+0xdffc),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for method,mode,buffer,size,char,locale in itertools.product(['Local','Standard'],[0,1],[0,BUFFER],[0,1,4,256,0x80000000],[0,233,255,256,65535,0xdead00e9],[0,LOC]):execute(dict(method=method,mode=mode,buffer=buffer,capacity=size,character=char,locale=locale))
for method,flags,refresh,size in itertools.product(['Capacity','Local','Standard'],[0,1,2,0x80000000],[False,True],[0,1,4,0xffffffff]):execute(dict(method=method,threadFlags=flags,refresh=refresh,capacity=size,locale=0))
for method,count,used,error in itertools.product(['Local','Standard'],[0,1,2],[0,1],[21,122]):execute(dict(method=method,mode=1,winCount=count,usedDefault=used,lastError=error,locale=0))
for c in[dict(method='Standard',patches={'0x6f040c':[[ARGS+4,4,256],[ARGS,4,BUFFER+1]]}),dict(method='Local',locale=0,patches={'0x6f040c':[[ARGS+4,4,65]]}),dict(method='Local',locale=0xdead0000),dict(method='Standard',buffer=0xdead0000),dict(method='Local',character=256,capacity=512,vectorZero=1)]:execute(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=3,imports=dict(wide=WIN,lastError=LAST),closure='actual701EBD/701F0C/70AFE5→actual701D43/6EB53D/memset/SSE; Windows imports and locale runtime services explicit')
(nm.BASE/'reports/script-phase166-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase166-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
