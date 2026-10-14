"""Actual condition macro/reference block bodies with complete condition parser and rawfile/program/state parents."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase34-20261013-verify.py').read_text().split('\nfiles=')[0])
n=nm.NativeX86();priorCommand35=command31
segments+=[(p,len(native_text(p))+1)for p in[0x75fff0,0x76042c,0x75ffe8,0x75ffe0,0x755d8c]]
def append35(listp,node):
 tail=rd(listp+4);wd(node,0);wd(node+4,tail)
 if tail:wd(tail,node)
 else:wd(listp,node)
 wd(listp+4,node)
def zero35(p,size):
 for i in range(size):wb(p+i,0)
def macro35():
 if not next_count():return
 top=rd(0x922214)
 if not top:events.append(dict(name='Diagnostic',callback=0x512850,args=[]));return
 bottom=rd(0x922218)
 if not bottom or((rd(top)+20)&0xffffffff)>=rd(bottom):events.append(dict(name='Diagnostic',callback=0x512850,args=[]));return
 macro=(rd(top)+15)&0xfffffff0;wd(top,(macro+20)&0xffffffff);zero35(macro,20)
 if not macro:return
 zero35(macro,20);name=copy_string(top,rd(PARSER+0x510),bottom);wd(macro+8,name);append35(rd(0x92221c)+72,macro);wd(0x922230,macro+12);wd(0x922238,1);materialize();wd(0x922230,0);wd(0x922238,0)
def operand35(source,top,bottom):
 length=len(text(source))
 if not length:return 0
 size=length+1;dst=0
 if top and bottom and((rd(top)+size)&0xffffffff)<rd(bottom):dst=(rd(top)+15)&0xfffffff0;wd(top,(dst+size)&0xffffffff);zero35(dst,size)
 else:events.append(dict(name='Diagnostic',callback=0x512850,args=[]))
 for i in range(4096):
  c=rb(source+i)
  if dst+i not in shadow:raise ValueError('invaliddest')
  wb(dst+i,c)
  if not c:return dst
 raise ValueError('nonterminatingoperand')
def reference35():
 if not rd(0x92222c):return
 top=rd(0x922214);bottom=rd(0x922218);original=rd(top)
 if not bottom or((original+36)&0xffffffff)>=rd(bottom):events.append(dict(name='Diagnostic',callback=0x512850,args=[]));return
 node=(original+15)&0xfffffff0;wd(top,(node+36)&0xffffffff);zero35(node,36)
 if not node:return
 zero35(node,36);stop=False
 while not stop and nextline(True):
  while next_count():
   ptr=rd(PARSER+0x510);name=text(ptr)
   if fold(name)=='}':stop=True;break
   found=fold(name).find('SCRIPT')
   if found>=0:bottom=rd(0x922218);top=rd(0x922214);value=operand35((ptr+found+7)&0xffffffff,top,bottom);wd(node+8,value);continue
   found=fold(name).find('RETURNSTATE')
   if found>=0:bottom=rd(0x922218);top=rd(0x922214);value=operand35((ptr+found+12)&0xffffffff,top,bottom);wd(node+16,value);continue
   if fold(name)=='CONDITIONS':wd(0x922230,node+28);wd(0x922238,1);materialize();wd(0x922230,0);wd(0x922238,0);continue
   if 'SOURCE'in fold(name):
    if 'GLOBAL'in fold(name):wd(node+24,rd(node+24)|1)
    elif 'LEVEL'in fold(name):wd(node+24,rd(node+24)|2)
 if rd(node+8):
  flags=rd(node+24)
  if not flags&3:wd(node+24,flags|3)
  append35(rd(0x92222c),node);return
 events.append(dict(name='Diagnostic',callback=0x512860,args=[]));wd(rd(0x922214),original)
def command31(callback,model):
 if callback==0x52bdf0:macro35()
 elif callback==0x52c000:reference35()
 else:priorCommand35(callback,model)
def hook35(mu,address,size,data):
 if address==0x4fb550:hook26(mu,address,size,data)
 elif address in[f for p,f,name in commands+stateCommands if f not in[0x513540,0x5133f0,0x5136c0,0x513730,0x52b3f0,0x52bdf0,0x52c000]]+[FALLBACK,SECONDARY]:
  sp=mu.reg_read(UC_X86_REG_ESP);leaf33(address,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0x12345678);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address in[CB,0x512850,0x512860,0x512870,0x4ef790]:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
  if address in[0x512850,0x512860] and(ret in[0x5135ba,0x513755,0x52c165,0x52c170,0x52c211,0x52c21c,0x52c309,0x4fa13e,n.STOP]or 0x52bdf0<=ret<0x52bec0):count=1 if ret==0x513755 else 0;events.append(dict(name='Diagnostic',callback=address,args=list(n.unpack('<'+'I'*count,sp+4))))
  else:hook25(mu,address,size,data)
n.mu.hook_add(UC_HOOK_CODE,hook35)
def execute35(c,method='Pipeline'):
 global config,shadow,events,checks,stream,parameters,commandOrdinal
 config=c;setup26(c);n.pack('<I',0x91eec4,FALLBACK if c.get('fallback',True)else 0);n.pack('<I',0x922244,0);n.pack('<I',TOP,BANK+c.get('alignment',0));n.pack('<I',BOTTOM,BANK+c.get('bankSize',0x4000));n.pack('<II',SCRIPT+16,0,0);n.pack('<II',SCRIPT+64,0,0);n.pack('<II',SCRIPT+72,0,0);n.pack('<I',0x92222c,0 if c.get('nullDestination')else SCRIPT+64);n.pack('<I',PARSER+0x570,c.get('depth',-1)&0xffffffff)
 if c.get('nullTop'):n.pack('<I',0x922214,0)
 if c.get('nullBottom'):n.pack('<I',0x922218,0)
 if method=='Macro':n.write(RAWLINE,c.get('line','guard').encode('latin1')+b'\0');n.write(TOKEN,b'CONDITIONMACRO\0');n.pack('<I',PARSER+0x520,0)
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];stream=fresh_stream();parameters=dict(text=c['file'],chunk=c.get('chunk',4096),failAfter=c.get('failAfter',0x7fffffff),capacity=4096,binary=0);commandOrdinal=0;modelFault=False
 try:
  if method=='Pipeline':populate31(SCRIPT)
  elif method=='Macro':macro35()
  else:reference35()
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();ms=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0);events=[];stream=fresh_stream();commandOrdinal=0;nativeFault=False
 try:
  if method=='Pipeline':n.call(0x5137a0,[SCRIPT],regs={UC_X86_REG_EAX:TOP,UC_X86_REG_ECX:BOTTOM,UC_X86_REG_ESI:PARSER},count=8000000)
  else:n.call(0x52bdf0 if method=='Macro'else 0x52c000,[PARSER],count=8000000)
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy();ns=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0)
 for group,a,b in[('fault',nativeFault,modelFault),('images',nf,mf),('events',ne,me),('stream',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(parser=PARSER,script=SCRIPT,top=TOP,bottom=BOTTOM),initial=initial,fault=nativeFault,final=nf,nativeEvents=ne,nativeStream=ns))
for name,align,file in itertools.product(['guard','Guard','\xe0Macro','"a b"','""',''],[0,1,15],['}\n','IF Timer > 1 goto BASE\n}\n','IF Random == missing\nIF AlwaysTrue == 1\n}\n']):execute35(dict(file=file,line=name,alignment=align,callback=True),'Macro')
for file,chunk in itertools.product(['Script=other ReturnState=BASE Source=Global\n}\n','Script=other\nSource=Level\n}\n','ReturnState=BASE Script=other Source=GlobalLevel\n}\n','Script=one Script=two\nSource=Global Source=Level\n}\n','xxScript=other abcReturnState=BASE Source=weird\n}\n','Script= ReturnState=\n}\n','ReturnState=BASE\n}\n','Script=other\nCONDITIONS\nIF Timer > 1\n}\n}\n','CONDITIONS\nIF Timer > 1\n}\n}\n'],[1,17,4096]):execute35(dict(file=file,chunk=chunk),'Reference')
for method,size,align in itertools.product(['Macro','Reference'],[0,20,21,36,37,48,49,64,96],[0,1,15]):execute35(dict(file='Script=other\n}\n'if method=='Reference'else 'IF Timer == 1\n}\n',bankSize=size,alignment=align),method)
files=['CONDITIONMACRO guard\nIF Timer > 1 goto BASE\n}\nSTATE first\nCONDITIONS\nOnMacro guard\n}\n}\nSTATE BASE\n}\n','REFERENCESCRIPT\nScript=other Source=Level ReturnState=BASE\nCONDITIONS\nIF Timer > 2\n}\n}\nSTATE BASE\nREFERENCESCRIPT\nScript=other Source=Global\n}\n}\n','CONDITIONMACRO guard\nIF Random > missing\n}\nREFERENCESCRIPT\nScript=other\nCONDITIONS\nOnMacro guard\n}\n}\nSTATE BASE\nCONDITIONS\nOnMacro guard goto BASE\n}\n}\n']
for file,chunk,handled in itertools.product(files,[1,17,4096],[False,True]):execute35(dict(file=file,chunk=chunk,callback=True,handled=handled))
for c,method in[(dict(file='',nullTop=True),'Macro'),(dict(file='',nullBottom=True),'Macro'),(dict(file='Script=other\n}\n',nullTop=True),'Reference'),(dict(file='Script=other\n}\n',nullBottom=True),'Reference'),(dict(file='Script=other\n}\n',nullDestination=True),'Reference')]:execute35(c,method)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,methods={method:sum(r['method']==method for r in cases)for method in['Pipeline','Macro','Reference']},newEntries=2,ports=['4fb550finalfilebytes','9238c0symbolcallback','remainingACTION/ACTIONMACRO/DERIVE/INCLUDE callbacks'])
(nm.BASE/'reports/script-phase35-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase35-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
