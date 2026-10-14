"""Actual52b3f0 and513990 condition production; line/token filetransport and gamecallback supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
# Independent sealed expression arithmetic/lexer model; only model methods reused.
e={'__file__':str(Path(__file__).with_name('script-phase20-20261013-verify.py'))};exec(Path(__file__).with_name('script-phase20-20261013-verify.py').read_text().split('\ntexts=')[0],e)
n=nm.NativeX86();CB=n.STOP+0x900;LIST=D+0x5400;MACRO=D+0x5500;MACRONODES=D+0x6000;lineIndex=-1;tokenIndex=0;symbolOrdinal=0
operatorAddresses=[0x758460,0x76041c,0x7533c8,0x7533c4,0x760418,0x760414,0x760410];newstatic=[0x75ff74,0x760420,0x760408]+operatorAddresses
segments=[(D,0x10000),(0x9220f0,0x174),(0x9238c0,4)]+staticSegments+[(p,len(native_text(p))+1)for p in newstatic]
def nextline(model):
 global lineIndex,tokenIndex
 lineIndex+=1;tokenIndex=0;read=rd if model else lambda p:n.unpack('<I',p)[0];events.append(dict(name='NextLine',parser=PARSER,top=read(TOP)));return 1 if lineIndex<len(config['lines'])else 0

def token(model):
 global tokenIndex
 read=rd if model else lambda p:n.unpack('<I',p)[0];events.append(dict(name='NextToken',line=lineIndex,index=tokenIndex,top=read(TOP)));p=TEXT+tokenIndex*0x100;value=config['lines'][lineIndex][tokenIndex]if tokenIndex<len(config['lines'][lineIndex])else '';tokenIndex+=1;b=value.encode('latin1')+b'\0'
 if model:
  for i,v in enumerate(b):wb(p+i,v)
  wd(PARSER+0x510,p)
 else:n.write(p,b);n.pack('<I',PARSER+0x510,p)
 for address,size,value in config.get('patches',{}).get('Token#'+str(lineIndex)+'.'+str(tokenIndex),[]):
  if model:
   for i in range(size):wb(address+i,value>>(i*8))
  else:n.write(address,int(value).to_bytes(size,'little'))
def game_port(name,model):
 global symbolOrdinal
 symbolOrdinal+=1;read=rd if model else lambda p:n.unpack('<I',p)[0];events.append(dict(name='Symbol',symbol=name,flags=[read(p)for p in [0x92224c,0x922250,0x922254]],top=read(TOP)));value=config.get('symbolBits',0x40400000);return config.get('handledNames',{}).get(name,config.get('handled',0)),value

def hook25(mu,address,size,data):
 global events
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address in [0x4fc5b0,0x4f7fb0,CB]:
  if address==0x4fc5b0:value=nextline(False)
  elif address==0x4f7fb0:token(False);value=0
  else:creature,packet,name,out=n.unpack('<4I',sp+4);value,result=game_port(native_text(name),False);n.pack('<I',out,result)
  ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address in [0x512850,0x512860,0x512870]:
  ret=n.unpack('<I',sp)[0];argc=0 if ret==0x52b53f or 0x513990<=ret<0x514000 else 2 if ret in [0x52b97a,0x52b99a]else 3;diagnostic(address,list(n.unpack('<'+'I'*argc,sp+4))if argc else [],False)
 elif address==0x4ef790:events.append(dict(error=True))
n.mu.hook_add(UC_HOOK_CODE,hook25)
def resolve_load(name):
 wd(0x92224c,1);wd(0x922250,1);value=0
 if rd(0x9238c0):
  handled,value=game_port(name,True)
  if handled:wd(0x922250,0)
 return value

def expression(p):
 wd(0x92224c,0);wd(0x922250,0);wd(0x922254,0);e.update(rb=rb,wb=wb,resolve=resolve_load,events=events);v=e['Parser'](p).run()
 if rd(0x922250):wd(0x922254,1)
 return v

def append(lst,node):
 wd(node,0);wd(node+4,rd(lst+4))
 if rd(lst+4):wd(rd(lst+4),node)
 wd(lst+4,node)
 if not rd(lst):wd(lst,node)
def admit(top,bottom,size):return top and bottom and ((rd(top)+size)&0xffffffff)<rd(bottom)
def alloc(top,size):
 p=(rd(top)+15)&0xfffffff0;wd(top,p+size)
 for i in range(size):wb(p+i,0)
 return p

def copy_macro(source,target,top,bottom):
 node=rd(source)
 while node:
  if not admit(top,bottom,44):diagnostic(0x512850,[],True)
  else:
   copy=alloc(top,44)
   if copy:
    for i in range(44):wb(copy+i,0)
    for i in range(44):wb(copy+i,rb(node+i))
    wd(copy,0);wd(copy+4,0);argument=copy_string(top,rd(node+20),bottom);wd(copy+20,argument);targetName=copy_string(top,rd(node+32),bottom);wd(copy+32,targetName);append(target,copy)
  node=rd(node)
def error_context(tokenp,include):
 state=rd(0x922220);name=rd(state+24)if state else 0x755ba8;scriptName=rd(rd(0x92221c)+8);return [tokenp,scriptName,name]if include else[scriptName,name]
def current():return rd(PARSER+0x510)
def operator(node):
 word=fold(text(current()));ops=['=','==','<','>','<=','>=','!=']
 if word in ops:wb(node+12,0 if ops.index(word)<2 else ops.index(word)-1);return True
 return False

def materialize():
 slot=0
 while nextline(True):
  token(True);word=fold(text(current()))
  if word=='}':return
  if word=='IF':
   token(True);desc=find(text(current()))
   if not desc:diagnostic(0x512870 if rd(0x922248)==1 else 0x512850,error_context(current(),True),True);continue
   top=rd(0x922214);bottom=rd(0x922218)
   if not admit(top,bottom,44):diagnostic(0x512850,[],True);continue
   node=alloc(top,44)
   if not node:continue
   for i in range(44):wb(node+i,0)
   append(rd(0x922230),node);wd(node+28,desc);token(True)
   if not operator(node):argument=copy_string(rd(0x922214),current(),rd(0x922218));wd(node+20,argument);token(True);operator(node)
   token(True)
   if not rd(node+40):
    name=text(current())
    if 'PARAM'in fold(name):wb(node+13,0);ww(node+14,rw(node+14)|4)
    else:
     for i in range(4):
      p=rd(rd(0x92221c)+24+i*8)
      if p and fold(text(p))==fold(text(current())):wb(node+13,i);ww(node+14,rw(node+14)|4);break
    if not rb(node+14)&4:
     i=0;count=rd(0x922244);signedcount=count-0x100000000 if count>=0x80000000 else count
     if signedcount>0:
      while i<signedcount:
       if fold(text(0x9220f0+i*36))==fold(text(current())):wd(node+8,rd(0x922110+i*36));break
       i+=1
     if i==signedcount:
      v=expression(current());wd(node+8,v)
      if rd(0x922254):ww(node+14,rw(node+14)|8);wb(node+13,slot);slot+=1;value=copy_string(rd(0x922214),current(),rd(0x922218));wd(node+16,value)
   finish();continue
  if word=='ONMACRO':
   token(True);node=rd(rd(0x92221c)+72)
   while node and fold(text(rd(node+8)))!=fold(text(current())):node=rd(node)
   if node:copy_macro(node+12,rd(0x922230),rd(0x922214),rd(0x922218));finish()
   else:diagnostic(0x512860 if rd(0x922248)==1 else 0x512850,error_context(current(),True),True)
   continue
  if '{'not in text(current()):diagnostic(0x512870 if rd(0x922248)==1 else 0x512850,error_context(0,False),True)
# Targettail model calls fixedCOND; bind its condition to the actual newly appended tail eachcall.
oldfinish=finish
def finish():
 global COND
 previous=COND;COND=rd(rd(0x922230)+4)
 try:oldfinish()
 finally:COND=previous

def setup25(c):
 setup(c,'FindPredicate');n.pack('<I',0x922230,LIST);n.pack('<I',0x922244,c.get('constantCount',0));n.pack('<I',0x9238c0,CB if c.get('callback',False)else 0)
 for i,name in enumerate(c.get('parameterNames',['alpha','beta','gamma','delta'])):p=NAMES+0xa00+i*0x80;n.write(p,name.encode('latin1')+b'\0');n.pack('<I',SCRIPT+24+i*8,p)
 for i,(name,value)in enumerate(c.get('constants',[])):n.write(0x9220f0+i*36,name.encode('latin1')+b'\0');n.pack('<I',0x922110+i*36,value)
 if c.get('macro'):
  n.pack('<I',SCRIPT+72,MACRO);n.pack('<I',MACRO+8,NAMES+0xc00);n.write(NAMES+0xc00,b'testMacro\0');n.pack('<I',MACRO+12,MACRONODES);n.pack('<I',MACRO+16,MACRONODES+0x40);n.pack('<I',MACRONODES,MACRONODES+0x40);n.pack('<I',MACRONODES+0x40+4,MACRONODES);n.pack('<H',MACRONODES+14,1);n.pack('<H',MACRONODES+0x40+14,0);n.pack('<I',MACRONODES+20,NAMES+0xd00);n.write(NAMES+0xd00,b'argument\0');n.pack('<I',MACRONODES+32,NAMES+0xe00);n.write(NAMES+0xe00,b'targetState\0');n.pack('<I',MACRONODES+16,NAMES+0xf00);n.write(NAMES+0xf00,b'sharedExpression\0');n.pack('<I',MACRONODES+28,0x801774);n.pack('<I',MACRONODES+0x40+28,0x801774)
def execute25(c,method='Load'):
 global config,shadow,events,ordinal,symbolOrdinal,lineIndex,tokenIndex,checks
 config=c;setup25(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0;symbolOrdinal=0;lineIndex=-1;tokenIndex=0;modelFault=False
 try:
  if method=='Load':materialize()
  else:copy_macro(MACRO+12,LIST,TOP,BOTTOM)
 except(ValueError,KeyError):modelFault=True
 modelFinal=snapshot(True);modelEvents=events.copy();events=[];ordinal=0;symbolOrdinal=0;lineIndex=-1;tokenIndex=0;nativeFault=False
 try:
  if method=='Load':n.call(0x52b3f0,[PARSER],count=2000000)
  else:n.call(0x513990,[MACRO+12,LIST,TOP,BOTTOM])
 except RuntimeError:nativeFault=True
 nativeFinal=snapshot();nativeEvents=events.copy()
 for group,a,b in [('fault',nativeFault,modelFault),('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,initial=initial,fault=nativeFault,final=nativeFinal,nativeEvents=nativeEvents))
for op,rhs,tail,callback,handled in itertools.product(['=','==','<','>','<=','>=','!='],['alpha','param99','42','symbol','true'],[['and'],['goto','Base','KeepBlockedMessages']],[False,True],[0,1]):execute25(dict(lines=[['IF','AlwaysTrue',op,rhs]+tail],callback=callback,handled=handled))
for op in ['=','<','<=','!=','invalid']:execute25(dict(lines=[['IF','LocatorRange','extraArgument',op,'symbol','and']]))
for c in [dict(lines=[]),dict(lines=[['}'],['IF','AlwaysTrue','=','1','and']]),dict(lines=[['{']]),dict(lines=[['bad']]),dict(lines=[['bad']],mode=1),dict(lines=[['IF','unknown','=','1','and']]),dict(lines=[['IF','unknown','=','1','and']],mode=1),dict(lines=[['OnMacro','missing','and']],mode=1),dict(lines=[['IF','AlwaysTrue','=','constant','and']],constantCount=1,constants=[['constant',0x40480000]]),dict(lines=[['IF','AlwaysTrue','=','symbol','and']],constantCount=0xffffffff),dict(lines=[['IF','AlwaysTrue','=','symbol','and']]*257),dict(lines=[['IF','AlwaysTrue','=','1','and']],bottom=BANK+44),dict(lines=[['OnMacro','testMacro','goto','Base','KeepBlockedMessages']],macro=True),dict(lines=[['OnMacro','testMacro','and']],macro=True)]:execute25(c)
for alignment in range(16):execute25(dict(lines=[['OnMacro','testMacro','and']],macro=True,alignment=alignment),'CopyMacro')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),actualBodies=['0x52b3f0','0x513990','0x512ea0','0x513100','0x5132f0','0x5132a0','0x513230','0x4f8420','0x4f1310'],remainingPorts=['NextLine4fc5b0/NextToken4f7fb0 filetransport','GameSymbol9238c0'],managedExecution=False)
(nm.BASE/'reports/script-phase25-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase25-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
