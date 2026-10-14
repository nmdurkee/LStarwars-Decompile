"""Original513f20 inheritance with actual513010 resolve/513cc0 deepcopy/513100/X87defaults/512fc0 target binding."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase41-20261013-verify.py').read_text().split('\nfor conditions,actions')[0])
n=nm.NativeX86();SYS42=D+0x1000;PARENT42=D+0x1800;CHILD42=D+0x1900;CHILDSTATE42=D+0x1400;CHILDCOND42=D+0x1700;PARENTSTATE2=D+0x1280;NAMES42=D+0x7000;segments=[(D,0x10000),(0x921ee8,8),(0x922248,4)]
def names_equal42(a,b):return bool(a and b and fold(text(a))==fold(text(b)))
def findscript42(name,listp):
 node=rd(listp)
 while node:
  if names_equal42(name,rd(node+8)):return node
  node=rd(node)
 return 0
def resolve42(system,name,scoped,globalFlag):
 if name:
  if scoped and system:
   value=findscript42(name,system+28)
   if value:return value
  if globalFlag:
   value=findscript42(name,0x921ee8)
   if value:return value
 return 0
def findstate42(name,script):
 node=rd(script+16)
 if not name:return 0
 while node:
  if names_equal42(name,rd(node+24)):return node
  node=rd(node)
 return 0
def apply42(script,top,bottom,system):
 if not script or not rd(script+12)or not rd(script+60)&2:return 1
 shifted=rd(script+60)>>2;parent=resolve42(system,rd(script+12),shifted&1,(~shifted)&1)
 if not parent:events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[rd(script+8),rd(script+12)]));wd(script+60,rd(script+60)&0xfffffffd);return 1
 if parent!=script:
  if rb(parent+60)&2:return 0
  state=rd(parent+16)
  while state:
   child=rd(script+16);exists=False
   while child:
    if names_equal42(rd(state+24),rd(child+24)):exists=True;break
    child=rd(child)
   if not exists:
    copy=copystate41(state,top,bottom)
    if copy:append36(script+16,copy)
   state=rd(state)
  for i in range(4):
   source=rd(parent+24+i*8)
   if source and not rd(script+24+i*8):name=copy_string(top,source,bottom);wd(script+24+i*8,name);value=rd(parent+28+i*8);wd(script+28+i*8,value)
  state=rd(script+16)
  while state:
   node=rd(state+8)
   while node:
    target=findstate42(rd(node+32),script);name=rd(node+32);wd(node+36,target)
    if name and not target:events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[name,rd(script+8),rd(state+24)]))
    node=rd(node)
   state=rd(state)
 wd(script+60,rd(script+60)&0xfffffffd);return 1

def hook42(mu,address,size,data):
 if address in[0x512850,0x512860]:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];count=2 if ret in[0x514107,0x514126]else 3 if ret in[0x5140b7,0x5140be]else 0;events.append(dict(name='Diagnostic',callback=address,args=list(n.unpack('<'+'I'*count,sp+4))))
n.mu.hook_add(UC_HOOK_CODE,hook42)
def setup42(c):
 setup41(dict(c,stateName=c.get('parentStateName','BASE'),targetName=c.get('targetName','BASE'),conditions=c.get('conditions',1),actions=c.get('actions',1),references=c.get('references',1),flags=c.get('referenceFlags',3)))
 namePtrs={}
 for i,(key,value)in enumerate([('parent',c.get('parentName','parent')),('child','child'),('request',c.get('requestName','parent')),('own',c.get('childStateName','own')),('second','SECOND')]):p=NAMES42+i*0x80;n.write(p,value.encode('latin1')+b'\0');namePtrs[key]=p
 n.write(PARENT42,bytes(0x58));n.write(CHILD42,bytes(0x58));n.pack('<I',PARENT42+8,namePtrs['parent']);n.pack('<I',CHILD42+8,namePtrs['child']);n.pack('<I',CHILD42+12,0 if c.get('noParentName')else namePtrs['child']if c.get('selfParent')else namePtrs['request']);n.pack('<I',CHILD42+60,c.get('childFlags',2));n.pack('<I',PARENT42+60,c.get('parentFlags',0));n.pack('<II',SOURCE41,0,0)
 parentCount=c.get('parentStates',1);n.pack('<II',PARENT42+16,SOURCE41 if parentCount else 0,PARENTSTATE2 if parentCount>1 else SOURCE41 if parentCount else 0)
 if parentCount>1:n.write(PARENTSTATE2,n.read(SOURCE41,36));n.pack('<I',SOURCE41,PARENTSTATE2);n.pack('<I',PARENTSTATE2+4,SOURCE41);n.pack('<I',PARENTSTATE2+24,namePtrs['second'])
 if c.get('nullParentStateName'):n.pack('<I',SOURCE41+24,0)
 childCount=c.get('childStates',1);n.write(CHILDSTATE42,bytes(0x80));n.pack('<II',CHILD42+16,CHILDSTATE42 if childCount else 0,CHILDSTATE42+0x40 if childCount>1 else CHILDSTATE42 if childCount else 0)
 if childCount:
  n.pack('<I',CHILDSTATE42+24,namePtrs['own']);n.pack('<II',CHILDSTATE42+8,CHILDCOND42,CHILDCOND42);n.write(CHILDCOND42,n.read(CONDITIONS41,44));n.pack('<II',CHILDCOND42,0,0)
 if childCount>1:n.pack('<I',CHILDSTATE42,CHILDSTATE42+0x40);n.pack('<I',CHILDSTATE42+0x40+4,CHILDSTATE42);n.pack('<I',CHILDSTATE42+0x40+24,namePtrs['second'])
 for i in range(4):
  p=NAMES42+0x300+i*0x80;n.write(p,('param'+str(i)).encode('latin1')+b'\0');n.pack('<II',PARENT42+24+i*8,0 if c.get('parentParameterMask',15)&(1<<i)==0 else p,c.get('defaultBits',0x80000000)+i if c.get('varyDefaults')else c.get('defaultBits',0x80000000));n.pack('<II',CHILD42+24+i*8,p if c.get('childParameterMask',0)&(1<<i)else 0,0x12345678+i)
 first=CHILD42 if c.get('selfParent')else PARENT42
 if c.get('selfParent'):n.pack('<I',CHILD42,PARENT42);n.pack('<I',PARENT42+4,CHILD42)
 n.pack('<II',0x921ee8,0 if c.get('globalMissing')else first,PARENT42);n.pack('<I',SYS42+28,0 if c.get('scopedMissing')else first);n.pack('<I',0x922248,c.get('mode',0))
def execute42(c):
 global config,shadow,events,checks
 config=c;setup42(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];script=0 if c.get('nullScript')else CHILD42;system=0 if c.get('nullSystem')else SYS42;top=0 if c.get('nullTop')else TOP;bottom=0 if c.get('nullBottom')else BOTTOM;modelFault=False;want=0
 try:want=apply42(script,top,bottom,system)
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();events=[];nativeFault=False;got=0
 try:got=n.call(0x513f20,[script,top,bottom,system],count=8000000)
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in[('fault',nativeFault,modelFault),('return',0 if nativeFault else got,0 if modelFault else want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(script=script,top=top,bottom=bottom,system=system),initial=initial,fault=nativeFault,returnValue=0 if nativeFault else got,final=nf,nativeEvents=ne))
for parentStates,childStates,childStateName,scope in itertools.product([0,1,2],[0,1,2],['own','BASE','base'],[0,4]):execute42(dict(parentStates=parentStates,childStates=childStates,childStateName=childStateName,childFlags=2|scope))
for parentFlags,childFlags,nullSystem,missing in itertools.product([0,2,4,6],[0,2,6,0xffffffff],[False,True],[False,True]):execute42(dict(parentFlags=parentFlags,childFlags=childFlags,nullSystem=nullSystem,globalMissing=missing,scopedMissing=missing))
for childMask,parentMask in itertools.product([0,1,5,15],[0,1,5,15]):execute42(dict(childParameterMask=childMask,parentParameterMask=parentMask,parentStates=0,childStates=0))
for bits in[0,0x80000000,0x3f800000,0x7f800000,0xff800000,0x7fc01234,0xffc01234,1,0x007fffff]:execute42(dict(defaultBits=bits,parentStates=0,childStates=0))
for size,align in itertools.product([0,36,37,48,64,96,128,192,256,512,1024],[0,1,15]):execute42(dict(bankSize=size,alignment=align,childParameterMask=15))
for mode,target in itertools.product([0,1,2],['BASE','MISSING','']):execute42(dict(mode=mode,targetName=target,parentStates=2))
for c in[dict(nullScript=True),dict(noParentName=True),dict(selfParent=True),dict(selfParent=True,childFlags=6),dict(nullTop=True,childParameterMask=15),dict(nullBottom=True,childParameterMask=15),dict(nullTop=True),dict(nullBottom=True),dict(nullParentStateName=True),dict(requestName='missing',mode=1),dict(requestName='missing',mode=0),dict(parentStates=0,childStates=0,childFlags=0),dict(conditions=0,actions=0,references=0,parentStates=2)]:execute42(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,abi='cdecl(script,top,bottom,system),EAX0deferred/EAX1resolved',ports=['512850/512860 actualRET diagnostic observers'],closure='actual513010 resolver/513cc0 statecopy/513990+513b30+513100/512fc0 binding/X87defaultstores')
(nm.BASE/'reports/script-phase42-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase42-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
