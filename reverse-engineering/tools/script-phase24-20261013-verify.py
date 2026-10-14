"""Original condition loader primitives, exact custom registers; token/diagnostic ports supplied."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ESI,UC_X86_REG_EDI
D=n.DATA;TABLE=D+0x1000;NAMES=D+0x2000;TEXT=D+0x3000;PARSER=D+0x4000;COND=D+0x4700;TOP=D+0x5000;BOTTOM=TOP+4;SCRIPT=D+0x5100;STATE=D+0x5200;LINE=D+0x5300;BANK=D+0x8000
shadow={};events=[];ordinal=0;config={};errors=[];cases=[];checks=0

def native_text(p):
 s=[]
 while n.unpack('<B',p)[0]:s.append(chr(n.unpack('<B',p)[0]));p+=1
 return ''.join(s)
staticSegments=[(p,len(native_text(p))+1)for p in [0x75ffc8,0x75ffb4,0x75ffb0,0x755ba8]];builtin=[];p=0x801768
while n.unpack('<I',p)[0]:ptr=n.unpack('<I',p)[0];builtin.append(dict(address=p,name=native_text(ptr),words=list(n.unpack('<3I',p))));staticSegments.append((ptr,len(native_text(ptr))+1));p+=12
staticSegments.append((0x801768,p+12-0x801768));staticSegments=list(dict.fromkeys(staticSegments))
segments=[(D,0x10000),(0x922214,0x38)]+staticSegments

def rb(p):return shadow[p]
def wb(p,v):shadow[p]=v&255
def rd(p):return sum(rb(p+i)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):wb(p+i,v>>(i*8))
def rw(p):return rb(p)|(rb(p+1)<<8)
def ww(p,v):wb(p,v);wb(p+1,v>>8)
def text(p):
 out=[]
 while rb(p):out.append(chr(rb(p)));p+=1
 return ''.join(out)
def fold(s):return ''.join(chr((ord(c)-32)&255)if 97<=ord(c)<=122 or ord(c)>=224 else c for c in s)
def find(name):
 table=rd(0x922224)
 if table:
  row=table
  while rd(row):
   if fold(name)==fold(text(rd(row))):return row
   row+=12
 row=0x801768
 while rd(row):
  if fold(name)==fold(text(rd(row))):return row
  row+=12
 return 0

def copy_string(top,source,bottom):
 dst=0
 if not source:return 0
 length=len(text(source))
 if not length:return 0
 size=length+1
 if top and bottom and ((rd(top)+size)&0xffffffff)<rd(bottom):
  dst=(rd(top)+15)&0xfffffff0;wd(top,dst+size)
  for i in range(size):wb(dst+i,0)
 for i in range(4096):
  value=rb(source+i)
  if dst+i not in shadow:raise ValueError('invaliddest')
  wb(dst+i,value)
  if not value:return dst
 raise ValueError('nonprogresscopy')
def token(model):
 global ordinal
 ordinal+=1;read=rd if model else lambda p:n.unpack('<I',p)[0];events.append(dict(name='NextToken',parser=PARSER,observed=[read(COND+0xe)&65535,read(COND+0x20),read(TOP)]));p=TEXT+(ordinal-1)*0x100
 if model:wd(PARSER+0x510,p)
 else:n.pack('<I',PARSER+0x510,p)
 for address,size,value in config.get('patches',{}).get('NextToken#'+str(ordinal),[]):
  if model:
   for i in range(size):wb(address+i,value>>(i*8))
  else:n.write(address,int(value).to_bytes(size,'little'))
def diagnostic(callback,args,model):events.append(dict(name='Diagnostic',callback=callback,args=args))
def hook(mu,address,size,data):
 if address not in [0x4f7fb0,0x512850,0x512860]:return
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x4f7fb0:token(False)
 else:diagnostic(address,list(n.unpack('<3I',sp+4)),False)
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
def finish():
 token(True);value=text(rd(PARSER+0x510))
 if fold(value)=='GOTO':
  ww(COND+0xe,rw(COND+0xe)&0xfffd);token(True);bottom=rd(0x922218);source=rd(PARSER+0x510);top=rd(0x922214);result=copy_string(top,source,bottom);wd(COND+0x20,result);token(True)
  if fold(text(rd(PARSER+0x510)))=='KEEPBLOCKEDMESSAGES':ww(COND+0xe,rw(COND+0xe)|2)
 elif fold(value)=='AND':ww(COND+0xe,rw(COND+0xe)|1)
 elif not rd(0x922238):
  state=rd(0x922220);stateName=rd(state+0x18)if state else 0x755ba8;line=rd(PARSER+0x50c);script=rd(0x92221c);scriptName=rd(script+8);diagnostic(0x512860 if rd(0x922248)==1 else 0x512850,[scriptName,stateName,line],True)
def setup(c,method):
 n.write(D,bytes(0x10000));n.write(BANK,b'\xa5'*0x5000);n.write(0x922214,bytes(0x38));n.pack('<I',0x922214,TOP);n.pack('<I',0x922218,BOTTOM);n.pack('<I',0x92221c,SCRIPT);n.pack('<I',0x922220,STATE if c.get('state',True)else 0);n.pack('<I',0x922224,TABLE if c.get('custom',True)else 0);n.pack('<I',0x922238,c.get('allowInvalid',0));n.pack('<I',0x922248,c.get('mode',0));n.pack('<I',SCRIPT+8,NAMES+0x800);n.write(NAMES+0x800,b'script_name\0');n.pack('<I',STATE+0x18,NAMES+0x900);n.write(NAMES+0x900,b'state_name\0');n.write(LINE,b'original line\0');n.pack('<II',PARSER+0x50c,LINE,TEXT);n.pack('<I',TOP,BANK+c.get('alignment',0));n.pack('<I',BOTTOM,c.get('bottom',BANK+0x4000));n.pack('<H',COND+0xe,c.get('flags',0xa55a));n.pack('<I',COND+0x20,0xabcdef01)
 names=c.get('names',['alpha','beta','alpha','\xe0name'])
 for i,name in enumerate(names):p=NAMES+i*0x100;n.write(p,name.encode('latin1')+b'\0');n.pack('<3I',TABLE+i*12,p,0x12340000+i,0x56780000+i)
 if method=='Finish':
  tokens=c.get('tokens',['goto','new_target','KeepBlockedMessages'])
  for i,t in enumerate(tokens):n.write(TEXT+i*0x100,t.encode('latin1')+b'\0')
 else:n.write(TEXT,c.get('text','alpha').encode('latin1')+b'\0')
 if c.get('overlap'):n.write(BANK+c.get('alignment',0),c.get('text','alpha').encode('latin1')+b'\0')
 for p,size,v in c.get('initialPatches',[]):n.write(p,int(v).to_bytes(size,'little'))
def snapshot(model=False):return [dict(address=p,bytes=bytes(rb(p+i)for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def execute(c,method='FindPredicate'):
 global config,shadow,events,ordinal,checks
 config=c;setup(c,method);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0;want=0;modelFault=False;source=c.get('textPointer',BANK+c.get('alignment',0)if c.get('overlap')else TEXT);top=0 if c.get('nullTop')else TOP;bottom=0 if c.get('nullBottom')else BOTTOM
 try:
  if method=='FindPredicate':want=find(text(source))
  elif method=='CopyString':want=copy_string(top,source,bottom)
  else:finish()
 except(ValueError,KeyError):modelFault=True
 modelFinal=snapshot(True);modelEvents=events.copy();events=[];ordinal=0;got=0;nativeFault=False
 try:
  if method=='FindPredicate':got=n.call(0x512ea0,regs={UC_X86_REG_EDI:source})
  elif method=='CopyString':got=n.call(0x513100,[source,bottom],regs={UC_X86_REG_EDI:top})
  else:n.call(0x5132f0,[COND],regs={UC_X86_REG_ESI:PARSER})
 except RuntimeError:nativeFault=True
 nativeFinal=snapshot();nativeEvents=events.copy()
 for group,a,b in [('fault',nativeFault,modelFault),('return',0 if nativeFault else got,0 if modelFault else want),('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(text=source,top=top,bottom=bottom,parser=PARSER,condition=COND),initial=initial,returnValue=got if not nativeFault else 0,fault=nativeFault,final=nativeFinal,nativeEvents=nativeEvents))
for custom,name in itertools.product([False,True],['alpha','ALPHA','beta','missing','PreviousResult','AlwaysTrue','Timer','\xe0name','\xc0NAME']):execute(dict(custom=custom,text=name))
for row in builtin:execute(dict(custom=False,text=row['name']));execute(dict(custom=False,text=row['name'].swapcase()))
for names in [[],['Timer','alpha'],['alpha','alpha'],['PreviousResult','PreviousResult']]:execute(dict(names=names,text='Timer'))
for alignment,length in itertools.product(range(16),[0,1,7,15,16,31,255,256,1000]):execute(dict(alignment=alignment,text='x'*length),'CopyString')
for alignment,extra in itertools.product(range(16),[-1,0,1,7,16]):execute(dict(alignment=alignment,text='abc',bottom=BANK+alignment+4+extra),'CopyString')
for c in [dict(textPointer=0),dict(text=''),dict(nullTop=True),dict(nullBottom=True),dict(overlap=True,text='alpha'),dict(overlap=True,text='alpha',alignment=3),dict(text='\xe0\xffraw')]:execute(c,'CopyString')
for flags,tokens,allowInvalid,mode,state in itertools.product([0,1,2,3,0xa55a], [['goto','target','KeepBlockedMessages'],['goto','target','and'],['goto','','KeepBlockedMessages'],['and'],['bad']], [0,1], [0,1,2], [False,True]):execute(dict(flags=flags,tokens=tokens,allowInvalid=allowInvalid,mode=mode,state=state),'Finish')
for c in [dict(tokens=['goto','target','KeepBlockedMessages'],patches={'NextToken#2':[[TOP,4,BANK+3]]}),dict(tokens=['goto','target','KeepBlockedMessages'],patches={'NextToken#3':[[COND+0xe,2,0x1234]]}),dict(tokens=['bad'],patches={'NextToken#1':[[0x922238,4,1]]}),dict(tokens=['bad'],patches={'NextToken#1':[[0x922220,4,0],[0x922248,4,1]]}),dict(tokens=['and'],patches={'NextToken#1':[[COND+0xe,2,0x9876]]}),dict(tokens=['goto','target','KeepBlockedMessages'],bottom=BANK+1)]:execute(c,'Finish')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],faultCases=sum(c['fault']for c in cases),builtinPredicateRows=len(builtin),remainingPorts=['4f7fb0 NextToken for5132f0','512850/512860 diagnostics'],actualBodies=['0x512ea0','0x513100','0x5132f0','0x4f8b10','0x4f1ff0','0x4f1f10','0x6e6950'],managedExecution=False)
(nm.BASE/'reports/script-phase24-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase24-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,builtinPredicates=builtin,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
