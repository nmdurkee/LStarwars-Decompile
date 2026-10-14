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
 if address==0x7014a5:
  x=args[0];signed=x if x<0x80000000 else x-0x100000000;return config.get('lower',{}).get(str(x),U(signed+32)if 65<=signed<=90 else x)
 if address==0x700f70:return config.get('digit',{}).get(str(args[0]),4 if 48<=args[0]<=57 else 0)
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
ports={0x7014a5:1,0x700f70:1,0x6f040c:0,0x6fae25:0,0x6fa67a:0,0x6ead5f:0,0x6e9fc2:5,WIN:8,LAST:0}
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
CONTEXT=n.STACK+0xdfec;DP=D+0x1100;DECIMAL=D+0x1120;SECOND=D+0x600
def decimal(locale):return rd(rd(rd(locale+0xbc)),1)
def cleanup(context,eax):
 if rd(context+12,1):eax=rd(context+8);wr(eax+0x70,rd(eax+0x70)&0xfffffffd)
 return eax

def model(method):
 ctor(CONTEXT,rd(ARGS+4));p=rd(ARGS)
 if method=='Force':
  char=rd(p,1);eax=port(0x7014a5,[U(char if char<128 else char-256)],True);again=eax!=101
  while again:p+=1;eax=port(0x700f70,[rd(p,1)],True);again=eax!=0
  char=rd(p,1);eax=port(0x7014a5,[U(char if char<128 else char-256)],True)
  if eax==120:p+=2
  carry=rd(p,1);point=decimal(rd(CONTEXT));wr(p,point,1)
  while True:
   p+=1;next=rd(p,1);wr(p,carry,1);carry=next;eax=eax&0xffffff00|carry
   if not rd(p,1):break
  return cleanup(CONTEXT,eax)
 locale=rd(CONTEXT);c=rd(p,1)
 if c:
  point=decimal(locale)
  while c!=point:
   p+=1;c=rd(p,1)
   if not c:break
 c=rd(p,1);p+=1
 if c:
  while rd(p,1)not in[0,101,69]:p+=1
  tail=p
  while True:
   p-=1
   if rd(p,1)!=48:break
  if rd(p,1)==decimal(locale):p-=1
  while True:
   c=rd(tail,1);p+=1;tail+=1;wr(p,c,1)
   if not c:break
 return cleanup(CONTEXT,p)

def execute(c):
 global config,shadow,segments,events,calls,checks
 config=c;n.write(D,bytes([0xcd])*0x1400);n.write(BUFFER,bytes(512));n.write(SECOND,bytes(256));n.write(SECOND,b'42.000e+02\0');payload=c.get('text','12.500').encode('latin1');n.write(BUFFER,payload+b'\0');n.write(BUFFER+len(payload)+1,bytes([c.get('padding',0)]));n.write(n.STACK+0xd800,bytes([0xcd])*0x830);n.pack('<2I',LOC,LI,MB);n.pack('<I',LI+0xbc,DP);n.pack('<I',DP,DECIMAL);n.write(DECIMAL,bytes([c.get('decimal',46)]));n.pack('<3I',THREAD+0x68,MB,LI,c.get('threadFlags',0));n.pack('<I',0x82a678,0 if c.get('refresh')else LI);n.pack('<I',0x82a498,MB);n.pack('<I',0x82a594,1);args=[c.get('buffer',BUFFER),c.get('locale',LOC)];n.pack('<2I',ARGS,*args);method=c.get('method','Force');segments=[(D,0x1400),(ARGS,8),(0x82a678,4),(0x82a498,4),(0x82a594,4)];initial=snap()+[dict(address=n.STACK+0xd800,bytes=n.read(n.STACK+0xd800,0x804).hex())];shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];calls={};mf=False;want=0
 try:want=model(method)
 except KeyError:mf=True
 modelImage=snap(True);me=events.copy();events=[];calls={};nf=False;got=0
 try:got=n.call(0x6edf15 if method=='Force'else 0x6edf86,args,count=500000)
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
 cases.append(dict(context=c,inputs=dict(method=method,bufferSlot=ARGS,localeSlot=ARGS+4,context=CONTEXT),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
texts=['','0','1','123','-123','123e+04','123E-04','e+4','E-4','0x1p+0','0Xap-5','nan','INF','12.500','12.000e+04','12.000E-04','12.3400','12.','0.000','.000','.','1.000.00','00,000','1.000e00','0e0','0000']
for method,text,locale,point in itertools.product(['Force','Crop'],texts,[0,LOC],[46,44,0,48]):execute(dict(method=method,text=text,locale=locale,decimal=point))
for method,text,padding,flags in itertools.product(['Force','Crop'],['1e+0','0xap+0','-10.000',''],[0,0xcd,0xab],[0,2,0x80000000]):execute(dict(method=method,text=text,padding=padding,locale=0,threadFlags=flags))
for c in[dict(text='1e+0',padding=0xcd,lower={'101':0xaabbcc65}),dict(text='-123',digit={'49':0}),dict(text='123',patches={'0x7014a5':[[DECIMAL,1,44]]}),dict(text='123',patches={'0x700f70':[[BUFFER+1,1,56]]}),dict(locale=0,patches={'0x6f040c':[[ARGS,4,SECOND]]}),dict(method='Crop',locale=0,refresh=True),dict(buffer=0),dict(buffer=0xdead0000),dict(locale=0xdead0000)]:execute(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=['7014A5 tolower','700F70 isdigit','6F040C thread','6FAE25 locale refresh','6FA67A multibyte refresh'],closure='actual6EDF15/6EDF86→actual6EB53D with original returnEAX/overlap byte moves; ctype/locale runtime services explicit')
(nm.BASE/'reports/script-phase169-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase169-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
