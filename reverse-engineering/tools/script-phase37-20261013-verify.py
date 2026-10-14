"""Actual ACTIONS/ACTIONMACRO plus lookup/array/copy and complete raw program/state/condition/reference parents."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase35-20261013-verify.py').read_text().split('\nfor name,align')[0])
primitiveText=Path(__file__).with_name('script-phase36-20261013-verify.py').read_text();exec(primitiveText[primitiveText.index('\ndef zero36'):primitiveText.index('\ndef hook36')])
n=nm.NativeX86();prior37=command31;actions=[];at=0x8019c0
while n.unpack('<I',at)[0]:ptr=n.unpack('<I',at)[0];actions.append(dict(address=at,name=native_text(ptr),namePointer=ptr));at+=12
segments+=[(0x8019c0,at+12-0x8019c0),(0x760424,len(native_text(0x760424))+1),(0x75a204,len(native_text(0x75a204))+1)]+[(r['namePointer'],len(r['name'])+1)for r in actions];CUSTOM37=D+0x1000;MACRO37=D+0x5500;MACROACTION37=D+0x6000;MACROARRAY37=D+0x6100

def missing37():
 mode=rd(0x922248);state=rd(0x922220);stateName=rd(state+24)if state else 0x755ba8;events.append(dict(name='Diagnostic',callback=0x512860 if mode==1 else 0x512850,args=[rd(PARSER+0x510),rd(rd(0x92221c)+8),stateName]))
def save37(value,top,bottom):
 if not value:return 0
 size=len(value)+1;target=0
 if top and bottom and((rd(top)+size)&0xffffffff)<rd(bottom):target=(rd(top)+15)&0xfffffff0;wd(top,(target+size)&0xffffffff);zero36(target,size)
 for i,b in enumerate(value.encode('latin1')+b'\0'):
  if target+i not in shadow:raise KeyError(target+i)
  wb(target+i,b)
 return target

def load37():
 line=nextline(True)
 while line:
  next_count();name=text(rd(PARSER+0x510))
  if fold(name)=='}':return
  if fold(name)=='DOMACRO':
   next_count();macro=rd(rd(0x92221c)+80);found=False
   while macro:
    p=rd(macro+8)
    if p and fold(text(p))==fold(text(rd(PARSER+0x510))):copy36(macro+12,rd(0x922234),rd(0x922214),rd(0x922218));found=True;break
    macro=rd(macro)
   if not found:missing37()
  else:
   descriptor=find36(rd(PARSER+0x510))
   if not descriptor:
    if '{'not in text(rd(PARSER+0x510)):missing37()
   else:
    top=rd(0x922214);bottom=rd(0x922218)
    if not top or not bottom or((rd(top)+20)&0xffffffff)>=rd(bottom):diag36()
    else:
     action=(rd(top)+15)&0xfffffff0;wd(top,(action+20)&0xffffffff);zero36(action,20)
     if action:
      zero36(action,20);append36(rd(0x922234),action);wd(action+16,descriptor);args=[]
      while next_count():
       value=text(rd(PARSER+0x510))
       if value==text(0x75a204):nextline(True)
       else:
        if len(args)>=24 or len(value)>=128:raise ValueError('nativeargslocals')
        args.append(value)
      if args:
       array=allocate36(rd(0x922214),rd(0x922218),len(args)*4);wd(action+8,array)
       if array:
        wd(action+12,len(args))
        for i,value in enumerate(args):copy=save37(value,rd(0x922214),rd(0x922218));wd(rd(action+8)+i*4,copy)
  line=nextline(True)
def macro37():
 if not next_count():return
 top=rd(0x922214)
 if not top:diag36();return
 bottom=rd(0x922218)
 if not bottom or((rd(top)+20)&0xffffffff)>=rd(bottom):diag36();return
 macro=(rd(top)+15)&0xfffffff0;wd(top,(macro+20)&0xffffffff);zero36(macro,20)
 if not macro:return
 zero36(macro,20);name=copy_string(top,rd(PARSER+0x510),bottom);wd(macro+8,name);append36(rd(0x92221c)+80,macro);wd(0x922234,macro+12);load37();wd(0x922234,0)
def command31(callback,model):
 if callback==0x52b9c0:load37()
 elif callback==0x52bec0:macro37()
 else:prior37(callback,model)
def hook37(mu,address,size,data):
 if address==0x4fb550:hook26(mu,address,size,data)
 elif address in[f for p,f,name in commands+stateCommands if f not in[0x513540,0x5133f0,0x5136c0,0x513730,0x52b3f0,0x52bdf0,0x52c000,0x52b9c0,0x52bec0]]+[FALLBACK,SECONDARY]:
  sp=mu.reg_read(UC_X86_REG_ESP);leaf33(address,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0x12345678);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address in[CB,0x512850,0x512860,0x512870,0x4ef790]:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
  if address in[0x512850,0x512860]and(ret in[0x52bb98,0x52bad2,0x52bca8]or 0x513b30<=ret<0x513cc0 or 0x52bec0<=ret<0x52bf80):count=3 if ret in[0x52bad2,0x52bca8]else 0;events.append(dict(name='Diagnostic',callback=address,args=list(n.unpack('<'+'I'*count,sp+4))))
  else:hook35(mu,address,size,data)
n.mu.hook_add(UC_HOOK_CODE,hook37)
def execute37(c,method='Load'):
 global config,shadow,events,checks,stream,parameters,commandOrdinal
 config=c;setup26(c);n.pack('<I',0x91eec4,FALLBACK if c.get('fallback',True)else 0);n.pack('<I',0x922244,0);n.pack('<I',TOP,BANK+c.get('alignment',0));n.pack('<I',BOTTOM,BANK+c.get('bankSize',0x4000));n.pack('<II',SCRIPT+16,0,0);n.pack('<II',SCRIPT+64,0,0);n.pack('<II',SCRIPT+72,0,0);n.pack('<II',SCRIPT+80,0,0);n.pack('<I',0x922234,LIST);n.pack('<II',LIST,0,0);n.pack('<I',PARSER+0x570,c.get('depth',-1)&0xffffffff);n.pack('<I',0x922228,CUSTOM37 if c.get('custom')else 0)
 for i,name in enumerate(['myAction',actions[0]['name']]):p=NAMES+0x1800+i*0x80;n.write(p,name.encode('latin1')+b'\0');n.pack('<3I',CUSTOM37+i*12,p,0x12345678+i,0xaabbccdd+i)
 n.pack('<3I',CUSTOM37+24,0,0,0)
 if c.get('existingMacro'):
  n.pack('<II',SCRIPT+80,MACRO37,MACRO37);n.pack('<I',MACRO37+8,NAMES+0x1a00);n.write(NAMES+0x1a00,b'guard\0');n.pack('<II',MACRO37+12,MACROACTION37,MACROACTION37);n.pack('<5I',MACROACTION37,0,0,MACROARRAY37,2,actions[0]['address']);n.pack('<II',MACROARRAY37,NAMES+0x1b00,NAMES+0x1b80);n.write(NAMES+0x1b00,b'one\0');n.write(NAMES+0x1b80,b'two\0')
 if c.get('nullState'):n.pack('<I',0x922220,0)
 if c.get('nullTop'):n.pack('<I',0x922214,0)
 if c.get('nullBottom'):n.pack('<I',0x922218,0)
 if method=='Macro':n.write(RAWLINE,c.get('line','guard').encode('latin1')+b'\0');n.write(TOKEN,b'ACTIONMACRO\0');n.pack('<I',PARSER+0x520,0)
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];stream=fresh_stream();parameters=dict(text=c['file'],chunk=c.get('chunk',4096),failAfter=c.get('failAfter',0x7fffffff),capacity=4096,binary=0);commandOrdinal=0;modelFault=False
 try:
  if method=='Pipeline':populate31(SCRIPT)
  elif method=='Macro':macro37()
  else:load37()
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();ms=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0);events=[];stream=fresh_stream();commandOrdinal=0;nativeFault=False
 try:
  if method=='Pipeline':n.call(0x5137a0,[SCRIPT],regs={UC_X86_REG_EAX:TOP,UC_X86_REG_ECX:BOTTOM,UC_X86_REG_ESI:PARSER},count=8000000)
  else:n.call(0x52bec0 if method=='Macro'else 0x52b9c0,[PARSER],count=8000000)
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy();ns=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0)
 for group,a,b in[('fault',nativeFault,modelFault),('images',nf,mf),('events',ne,me),('stream',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(parser=PARSER,script=SCRIPT,top=TOP,bottom=BOTTOM),initial=initial,fault=nativeFault,final=nf,nativeEvents=ne,nativeStream=ns))
for row in actions:
 for arg in['',' token']:execute37(dict(file=row['name']+arg+'\n}\n'))
first=actions[0]['name'];continuation=native_text(0x75a204)
for file,chunk in itertools.product([first+' one two\n}\n',first+' "a b" "" three\n}\n',first+' one '+continuation+'\n two three\n}\n',first+' one '+continuation+'\n}\n',first+' '+continuation+'\n',first+' '+(' '.join('arg'+str(i)for i in range(24)))+'\n}\n',first+' '+('x'*127)+'\n}\n',first+' '+('x'*512)+'\n}\n','myAction value\n}\n','{\nunknown x\n}\n','DoMacro guard\n}\n','DoMacro missing\n}\n','}\n','   '],[1,17,4096]):execute37(dict(file=file,chunk=chunk,custom=True,existingMacro=True))
for name,align in itertools.product(['guard','"a b"','\xe0Macro','""',''],[0,1,15]):execute37(dict(file=first+' one two\n}\n',line=name,alignment=align),'Macro')
for method,size,align in itertools.product(['Load','Macro'],[0,20,21,24,32,36,48,64,96,128],[0,1,15]):execute37(dict(file=first+' one two\n}\n',bankSize=size,alignment=align),method)
for mode,nullState in itertools.product([0,1,2],[False,True]):execute37(dict(file='unknown\nDoMacro missing\n}\n',mode=mode,nullState=nullState))
files=['ACTIONMACRO guard\n'+first+' one two\n}\nSTATE BASE\nACTIONS\nDoMacro guard\n'+first+' three\n}\n}\n','CONDITIONMACRO check\nIF Timer > missing\n}\nACTIONMACRO guard\n'+first+' one\n}\nREFERENCESCRIPT\nScript=other Source=Level\nCONDITIONS\nOnMacro check\n}\n}\nSTATE first\nCONDITIONS\nOnMacro check goto BASE\n}\nACTIONS\nDoMacro guard\n}\n}\nSTATE BASE\nACTIONS\n'+first+' two\n}\n}\n']
for file,chunk in itertools.product(files,[1,17,4096]):execute37(dict(file=file,chunk=chunk,callback=True),'Pipeline')
for method in['Load','Macro']:
 for c in[dict(nullTop=True),dict(nullBottom=True)]:execute37(dict(file=first+' one\n}\n',**c),method)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,methods={method:sum(r['method']==method for r in cases)for method in['Pipeline','Load','Macro']},builtinActions=len(actions),continuation=continuation,newEntries=2,ports=['4fb550finalfilebytes','9238c0expressiongamecallback','remainingDERIVE/INCLUDE callbacks'])
(nm.BASE/'reports/script-phase37-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase37-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
