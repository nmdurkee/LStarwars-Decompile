"""Original513cc0 state copier with actualcondition/action copiers, strings/arrays/lists; onlyRETdiagnostics observed."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase25-20261013-verify.py').read_text().split('\nfor op,rhs')[0])
primitiveText=Path(__file__).with_name('script-phase36-20261013-verify.py').read_text();exec(primitiveText[primitiveText.index('\ndef zero36'):primitiveText.index('\ndef hook36')])
n=nm.NativeX86();SOURCE41=D+0x1200;CONDITIONS41=D+0x3000;ACTIONS41=D+0x4000;ARRAYS41=D+0x4400;REFERENCES41=D+0x4800;GUARDS41=D+0x5800;TEXTS41=D+0x6200;segments=[(D,0x10000)]
def copy_macro(source,target,top,bottom):
 node=rd(source)
 while node:
  if not admit(top,bottom,44):diagnostic(0x512850,[],True)
  else:
   copy=alloc(top,44)
   if copy:
    for i in range(44):wb(copy+i,rb(node+i))
    wd(copy,0);wd(copy+4,0);argument=rd(node+20)
    if argument and text(argument)and not admit(top,bottom,len(text(argument))+1):diagnostic(0x512850,[],True)
    value=copy_string(top,argument,bottom);wd(copy+20,value);targetName=rd(node+32)
    if targetName and text(targetName)and not admit(top,bottom,len(text(targetName))+1):diagnostic(0x512850,[],True)
    value=copy_string(top,targetName,bottom);wd(copy+32,value);append(target,copy)
  node=rd(node)

def textcopy41(source,top,bottom):
 if not source:return 0
 size=len(text(source))
 if not size:return 0
 size+=1;result=0
 if((rd(top)+size)&0xffffffff)<rd(bottom):result=(rd(top)+15)&0xfffffff0;wd(top,(result+size)&0xffffffff);zero36(result,size)
 else:diag36()
 for i in range(4096):
  c=rb(source+i)
  if result+i not in shadow:raise KeyError(result+i)
  wb(result+i,c)
  if not c:return result
 raise ValueError('unterminatedcopy')
def copystate41(source,top,bottom):
 if not top or not bottom or((rd(top)+36)&0xffffffff)>=rd(bottom):diag36();return 0
 state=(rd(top)+15)&0xfffffff0;wd(top,(state+36)&0xffffffff);zero36(state,36)
 if not state:return state
 value=copy_string(top,rd(source+24),bottom);wd(state+24,value);copy_macro(source+8,state+8,top,bottom);copy36(source+16,state+16,top,bottom);ref=rd(source+28)
 while ref:
  if((rd(top)+36)&0xffffffff)>=rd(bottom):diag36()
  else:
   copy=(rd(top)+15)&0xfffffff0;wd(top,(copy+36)&0xffffffff);zero36(copy,36)
   if copy:
    value=textcopy41(rd(ref+8),top,bottom);wd(copy+8,value);target=textcopy41(rd(ref+16),top,bottom);wd(copy+16,target);flags=rd(copy+24);wd(copy+24,flags^((flags^rd(ref+24))&1));flags=rd(copy+24);wd(copy+24,flags^((flags^rd(ref+24))&2));copy_macro(ref+28,copy+28,top,bottom);append36(state+28,copy)
  ref=rd(ref)
 return state

def hook41(mu,address,size,data):
 if address==0x512850:diag36()
n.mu.hook_add(UC_HOOK_CODE,hook41)
def setup41(c):
 n.write(D,bytes(0x10000));n.pack('<II',TOP,BANK+c.get('alignment',0),BANK+c.get('bankSize',0x4000));p=TEXTS41;names={}
 for key,value in [('state',c.get('stateName','sourceState')),('arg',c.get('argument','arg')),('target',c.get('targetName','BASE')),('expression','cached+expr'),('script',c.get('scriptName','otherScript')),('token','actionArg')]:n.write(p,value.encode('latin1')+b'\0');names[key]=p;p+=0x80
 def conditions(listp,first,count):
  n.pack('<II',listp,first if count else 0,first+(count-1)*0x40 if count else 0)
  for i in range(count):node=first+i*0x40;n.write(node,bytes([0xa5])*44);n.pack('<II',node,node+0x40 if i+1<count else 0,node-0x40 if i else 0);n.pack('<I',node+8,c.get('constantBits',0x7f800001));n.pack('<I',node+16,names['expression']);n.pack('<I',node+20,0 if c.get('nullArgument')else names['arg']);n.pack('<I',node+28,0xd00dc0de+i);n.pack('<I',node+32,0 if c.get('nullTarget')else names['target']);n.pack('<II',node+36,0x87654321,0xabcdef01)
 n.pack('<I',SOURCE41+24,0 if c.get('nullName')else names['state']);n.pack('<II',SOURCE41,0xdeadbeef,0x12345678);conditions(SOURCE41+8,CONDITIONS41,c.get('conditions',1));count=c.get('actions',1);n.pack('<II',SOURCE41+16,ACTIONS41 if count else 0,ACTIONS41+(count-1)*0x40 if count else 0)
 for i in range(count):node=ACTIONS41+i*0x40;array=ARRAYS41+i*0x20;n.pack('<5I',node,node+0x40 if i+1<count else 0,node-0x40 if i else 0,array,c.get('tokenCount',2),0xabcdef01+i);n.pack('<3I',array,0 if c.get('nullToken')else names['token'],names['arg'],names['target'])
 count=c.get('references',1);n.pack('<II',SOURCE41+28,REFERENCES41 if count else 0,REFERENCES41+(count-1)*0x80 if count else 0)
 for i in range(count):node=REFERENCES41+i*0x80;n.pack('<7I',node,node+0x80 if i+1<count else 0,node-0x80 if i else 0,0 if c.get('nullScriptName')else names['script'],0xdeadbeef,0 if c.get('nullRefTarget')else names['target'],0x12345678,c.get('flags',0xffffffff));conditions(node+28,GUARDS41+i*0x200,c.get('guards',1))
 return names

def execute41(c):
 global config,shadow,events,checks
 config=c;setup41(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];top=0 if c.get('nullTop')else TOP;bottom=0 if c.get('nullBottom')else BOTTOM;source=0 if c.get('nullSource')else SOURCE41;modelFault=False;want=0
 try:want=copystate41(source,top,bottom)
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();events=[];nativeFault=False;got=0
 try:got=n.call(0x513cc0,[source,bottom],regs={UC_X86_REG_EAX:top},count=4000000)
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in[('fault',nativeFault,modelFault),('return',0 if nativeFault else got,0 if modelFault else want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(source=source,top=top,bottom=bottom),initial=initial,fault=nativeFault,returnValue=0 if nativeFault else got,final=nf,nativeEvents=ne))
for conditions,actions,references,flags in itertools.product([0,1,2],[0,1,2],[0,1,2],[0,1,2,3,0xffffffff]):execute41(dict(conditions=conditions,actions=actions,references=references,flags=flags))
for size,align in itertools.product([0,36,37,48,64,80,96,128,192,256,384,512,1024],[0,1,7,15]):execute41(dict(bankSize=size,alignment=align))
for c in[dict(nullTop=True),dict(nullBottom=True),dict(nullSource=True),dict(nullName=True),dict(stateName=''),dict(argument=''),dict(targetName=''),dict(scriptName=''),dict(nullArgument=True),dict(nullTarget=True),dict(nullScriptName=True),dict(nullRefTarget=True),dict(nullToken=True),dict(tokenCount=0),dict(tokenCount=1),dict(guards=0),dict(guards=2),dict(constantBits=0x80000000),dict(constantBits=0x7fc01234)]:execute41(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=['512850 actualRET diagnostic observer'],abi='EAXtop,cdecl(sourceState,bottom);EAXnewState',closure='513cc0 actual513990/513b30/513100/strlen/strcpy/memset/listchildren')
(nm.BASE/'reports/script-phase41-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase41-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
