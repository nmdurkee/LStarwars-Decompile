"""Original graphinitializer/referencebinder with actuallookup/default initializer, onlydynamicotherinitializers supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase20-20261013-verify.py').read_text().split('\ntexts=')[0])
n=nm.NativeX86();SYS=D+0x1000;SCOPED=D+0x3000;GLOBAL=D+0x4000;STATES=D+0x5000;CONDS=D+0x7000;REFS=D+0x9000;DESCS=D+0xb000;STRINGS=D+0xc000;OUT=D+0xf000;INIT=n.STOP+0xa00
segments=[(D,0x10000),(0x921ee8,8),(0x922248,4),(0x753270,5),(0x757734,8)];names={};initOrdinal=0

def string_native(p):
 out=[]
 while n.unpack('<B',p)[0]:out.append(n.unpack('<B',p)[0]);p+=1
 return bytes(out).decode('latin1')
def findstate(name,script):
 node=rd(script+0x10)
 if not name:return 0
 while node:
  if fold(text(name,True))==fold(text(rd(node+0x18),True)):return node
  node=rd(node)
 return 0

def findscript(name,listp):
 node=rd(listp)
 while node:
  if fold(text(name,True))==fold(text(rd(node+8),True)):return node
  node=rd(node)
 return 0

def resolvescript(system,name,fallback,scoped,globalFlag):
 if name:
  if scoped and system:
   found=findscript(name,system+0x1c)
   if found:return found
  if globalFlag:
   found=findscript(name,0x921ee8)
   if found:return found
 return findscript(0x757734,0x921ee8)if fallback else 0

def defaultinit(argument):return 0x3f800000 if not argument or not text(argument,True)else bits(number(text(argument,True)))
def init_port(callback,system,argument,script,model):
 global initOrdinal
 initOrdinal+=1;read=rd if model else lambda p:n.unpack('<I',p)[0];events.append(dict(name='Initialize',callback=callback,args=[system,argument,script],flags=0 if not system else n.unpack('<B',system+0x1386)[0]if not model else rb(system+0x1386),values=[read(CONDS+0x18),read(CONDS+0x40+0x18)]))
 for p,size,v in config.get('patches',{}).get('Initialize#'+str(initOrdinal),[]):
  if model:
   for i in range(size):wb(p+i,v>>(i*8))
  else:n.write(p,int(v).to_bytes(size,'little'))
 return config.get('initResults',[0x12345678])[min(initOrdinal-1,len(config.get('initResults',[0x12345678]))-1)]
def initialize(callback,system,argument,script):return defaultinit(argument)if callback==0x5149b0 else init_port(callback,system,argument,script,True)
def diag(callback,args,model):events.append(dict(name='Diagnostic',callback=callback,args=args))
def hook28(mu,address,size,data):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==INIT:
  args=list(n.unpack('<3I',sp+4));value=init_port(address,*args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address in [0x512850,0x512860]:
  ret=n.unpack('<I',sp)[0];count=2 if ret in[0x5141f3,0x5141ff]else 3;diag(address,list(n.unpack('<'+'I'*count,sp+4)),False)
n.mu.hook_add(UC_HOOK_CODE,hook28)
def unlink(listp,node):
 if not rd(node):wd(listp+4,rd(node+4))
 else:wd(rd(node)+4,rd(node+4))
 if rd(node+4):wd(rd(node+4),rd(node))
 else:wd(listp,rd(node))
def initlist(system,script,listp,cached,alternate):
 node=rd(listp)
 while node:
  callback=rd(rd(node+28)+8)
  if callback and(not cached or not system or not rb(system+0x1386)&4 or not rd(node+24)):argument=rd(node+20);value=initialize(callback,system,argument,script);wd(node+24,value)
  if alternate:
   other=rd(node+40);desc=rd(other+28)if other else 0
   if desc:
    callback=rd(desc+8)
    if callback:argument=rd(other+20);value=initialize(callback,system,argument,script);wd(rd(node+40)+24,value)
  node=rd(node)

def resolve_reference(system,ref):
 if not rb(system+0x1386)&4 or not rd(ref+12):flags=rd(ref+24);name=rd(ref+8);result=resolvescript(system,name,1,(flags>>1)&1,flags&1);wd(ref+12,result)
def target(script,ref,state):
 result=findstate(rd(ref+16),script);wd(ref+20,result)
 if not result and rd(ref+16):args=[rd(ref+16),rd(script+8)]+([rd(state+24)]if state else[]);diag(0x512860 if rd(0x922248)==1 else 0x512850,args,True)
def bindrefs(system,script):
 if not system or not script:return
 ref=rd(script+64)
 while ref:
  nxt=rd(ref);resolve_reference(system,ref);other=rd(ref+12)
  if not other or other==script:unlink(script+64,ref)
  else:target(script,ref,0);initlist(system,script,ref+28,False,False)
  ref=nxt
 state=rd(script+16)
 while state:
  ref=rd(state+28)
  while ref:
   nxt=rd(ref);resolve_reference(system,ref);other=rd(ref+12)
   if not other or other==script:unlink(script+64,ref)
   target(script,ref,state);initlist(system,script,ref+28,False,False);ref=nxt
  state=rd(state)
def bindsystem(system):
 rd(0x921ee8)
 if system:
  script=rd(system+28)
  while script:
   state=rd(script+16)
   while state:initlist(system,script,state+8,False,True);state=rd(state)
   wd(script+56,findstate(0x753270,script));bindrefs(system,script);script=rd(script)
 script=rd(0x921ee8)
 while script:
  state=rd(script+16)
  while state:initlist(system,script,state+8,True,False);state=rd(state)
  wd(script+56,findstate(0x753270,script));bindrefs(system,script);script=rd(script)

def setup28(c):
 global names
 n.write(D,bytes(0x10000));n.pack('<II',0x921ee8,GLOBAL if c.get('globals',True)else 0,GLOBAL+0x100);n.pack('<I',0x922248,c.get('mode',0));n.write(SYS+0x1386,bytes([c.get('flags',0)]));n.pack('<I',SYS+28,SCOPED if c.get('scoped',True)else 0);names={}
 def name(key,value):p=STRINGS+len(names)*0x100;n.write(p,value.encode('latin1')+b'\0');names[key]=p;return p
 for key,value in [('scope','scoped'),('global','global'),('default','default'),('base','BASE'),('other','otherState'),('argument',c.get('argument','')),('ref',c.get('refName','global')),('target',c.get('targetName','BASE')),('missing','missing'),('extended','\xe0name')]:name(key,value)
 for script,nam,key in [(SCOPED,names['scope'],0),(GLOBAL,names['global'],1),(GLOBAL+0x100,names['default'],2)]:
  n.pack('<I',script+8,nam);n.pack('<I',script+16,STATES+key*0x200);n.pack('<I',script+20,STATES+key*0x200+0x80);n.pack('<I',script+56,0xdeadbeef)
  for i in range(2):state=STATES+key*0x200+i*0x80;n.pack('<I',state+24,names['base']if i==0 else names['other']);n.pack('<I',state,STATES+key*0x200+0x80 if i==0 else 0);n.pack('<I',state+4,STATES+key*0x200 if i else 0)
 n.pack('<I',GLOBAL,GLOBAL+0x100);n.pack('<I',GLOBAL+0x100+4,GLOBAL)
 for i in range(8):node=CONDS+i*0x40;n.pack('<I',node+28,DESCS+(i%2)*0x20);n.pack('<I',node+20,names['argument']if c.get('argumentPointer',True)else 0);n.pack('<I',node+24,c.get('cached',0));n.pack('<I',DESCS+(i%2)*0x20+8,0x5149b0 if not i%2 and c.get('defaultInitializer',True)else INIT)
 n.pack('<II',STATES+8,CONDS,CONDS+0x40);n.pack('<I',CONDS,CONDS+0x40);n.pack('<I',CONDS+0x40+4,CONDS);n.pack('<I',CONDS+40,CONDS+0x80 if c.get('alternate',True)else 0);n.pack('<II',STATES+0x200+8,CONDS+0xc0,CONDS+0xc0);n.pack('<I',CONDS+0xc0+40,CONDS+0x100);n.pack('<II',STATES+0x400+8,CONDS+0x140,CONDS+0x140)
 for i in range(2):ref=REFS+i*0x80;n.pack('<I',ref+8,names['ref']);n.pack('<I',ref+12,c.get('cachedScript',0));n.pack('<I',ref+16,names['target']if c.get('targetPresent',True)else 0);n.pack('<I',ref+24,c.get('refFlags',3));n.pack('<II',ref+28,CONDS+0x180+i*0x40,CONDS+0x180+i*0x40)
 n.pack('<II',SCOPED+64,REFS,REFS);n.pack('<II',STATES+28,REFS+0x80,REFS+0x80)
 if c.get('invalidDescriptor'):n.pack('<I',CONDS+28,0)
 if c.get('noCallback'):n.pack('<I',DESCS+8,0)
 n.pack('<I',OUT,0xabcdef01)
 for p,size,value in c.get('initialPatches',[]):n.write(p,int(value).to_bytes(size,'little'))
def execute28(c,method='BindSystem'):
 global config,shadow,events,initOrdinal,checks
 config=c;setup28(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];initOrdinal=0;system=0 if c.get('nullSystem')else SYS;script=0 if c.get('nullScript')else SCOPED;argument=0 if c.get('nullName')else names[c.get('nameKey','base')];want=0;modelFault=False
 try:
  if method=='BindSystem':bindsystem(system)
  elif method=='BindReferences':bindrefs(system,script)
  elif method=='FindState':want=findstate(argument,script)
  elif method=='ResolveScript':want=resolvescript(system,argument,c.get('fallback',1),c.get('searchScoped',1),c.get('searchGlobal',1))
  else:want=defaultinit(0 if c.get('nullArgument')else names['argument'])
 except(KeyError,ValueError):modelFault=True
 modelFinal=snapshot(True);modelEvents=events.copy();events=[];initOrdinal=0;nativeFault=False;got=0
 try:
  if method=='BindSystem':n.call(0x5143a0,[system])
  elif method=='BindReferences':n.call(0x514140,[system,script])
  elif method=='FindState':got=n.call(0x512fc0,[argument,script])
  elif method=='ResolveScript':got=n.call(0x513010,[system,argument,c.get('fallback',1),c.get('searchScoped',1),c.get('searchGlobal',1)])
  else:got=n.call(0x5149b0,[system,0 if c.get('nullArgument')else names['argument'],script])
 except RuntimeError:nativeFault=True
 nativeFinal=snapshot();nativeEvents=events.copy()
 for group,a,b in [('fault',nativeFault,modelFault),('return',got if not nativeFault else 0,want if not modelFault else 0),('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(system=system,script=script,argument=argument,defaultArgument=0 if c.get('nullArgument')else names['argument']),initial=initial,fault=nativeFault,returnValue=got if not nativeFault else 0,final=nativeFinal,nativeEvents=nativeEvents))
for flags,cached,alternate,defaultInitializer in itertools.product([0,4,255],[0,1,0x80000000,0xffffffff],[False,True],[False,True]):execute28(dict(flags=flags,cached=cached,alternate=alternate,defaultInitializer=defaultInitializer))
for refName,refFlags,cachedScript,targetName,mode in itertools.product(['global','scoped','missing'],[0,1,2,3],[0,GLOBAL,SCOPED],['BASE','missing'],[0,1]):execute28(dict(refName=refName,refFlags=refFlags,cachedScript=cachedScript,targetName=targetName,mode=mode),'BindReferences')
for c in [dict(nullSystem=True),dict(nullScript=True),dict(globals=False),dict(scoped=False),dict(noCallback=True),dict(invalidDescriptor=True),dict(targetPresent=False),dict(initResults=[0]),dict(initResults=[0xffffffff]),dict(patches={'Initialize#1':[[CONDS+40,4,CONDS+0x100]]}),dict(patches={'Initialize#2':[[SYS+0x1386,1,4],[CONDS+0xc0+24,4,0x80000000]]}),dict(patches={'Initialize#1':[[REFS,4,0]]}),dict(patches={'Initialize#1':[[STATES,4,0]]}),dict(patches={'Initialize#2':[[CONDS+40,4,0]]})]:execute28(c)
for nameKey,nullName,nullScript in itertools.product(['base','other','missing'],[False,True],[False,True]):execute28(dict(nameKey=nameKey,nullName=nullName,nullScript=nullScript),'FindState')
for nameKey,fallback,scoped,globalFlag,nullName in itertools.product(['scope','global','default','missing'],[0,1],[0,1],[0,1],[False,True]):execute28(dict(nameKey=nameKey,fallback=fallback,searchScoped=scoped,searchGlobal=globalFlag,nullName=nullName),'ResolveScript')
for arg in ['', '1','-0','-1.75','.5','+5','1+2','Rand','16777219','123456.789012345','\xe0name']:execute28(dict(argument=arg),'AlwaysTrueInitializer')
execute28(dict(nullArgument=True),'AlwaysTrueInitializer')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),actualBodies=['0x514140','0x5143a0','0x512fc0','0x513010','0x5149b0','0x4f1410'],remainingPorts=['Nondefault descriptor initializer EAX rawword'],managedExecution=False)
(nm.BASE/'reports/script-phase28-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase28-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
