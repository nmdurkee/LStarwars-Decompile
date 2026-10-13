"""Eight outstanding SCP condition bodies plus original lookup/helper composition.
Only the synthetic Force registry name accessor is adapted; all other bodies
and table/list/numeric helpers run original PC x86 bytes in Unicorn.
"""
import importlib.util,json,struct,itertools,random,re,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;CRE=D+0x6000;REF=D+0x7000;ACTOR=D+0x8000;TARGET=D+0xa000;GROUP=D+0xb000;PLAYER=D+0xc000;DEFINITION=D+0xe000;CLASS=D+0xf000;CATEGORIES=D+0x10000;TEXT=D+0x11000;RESULT=D+0x12000;HINTS=D+0x14000;ACTIVE=D+0x15000;REGISTERED=D+0x16000;REGISTRY=D+0x17000;BUCKET=D+0x18000;TYPES=D+0x19000;TYPEGLOBAL=D+0x1a000;RECORDS=D+0x1b000;NAMES=D+0x1c000;LIST=D+0x20000;COND=D+0x20100;DEF=D+0x20200
ADAPTER=n.STOP+0x100
ADDR={'OpponentIsAThreat':0x440df0,'ForceBeingUsed':0x441300,'ForceFinished':0x4415c0,'PlayerCategoryIs':0x440c70,'InContext':0x442180,'OpponentContext':0x4421b0,'HintAvailable':0x442a40,'HintComplete':0x442a60}
checks={};errors=[];cases=[];initializers=[];calls=[]
def check(group,got,want,meta=None):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def fl(x):return struct.unpack('<f',struct.pack('<I',x))[0]
def string(p):return n.read(p,512).split(b'\0')[0].decode('ascii') if p else None
def token(t):
 if t is None:return 0
 n.write(TEXT,t.encode()+b'\0');return TEXT
def callback(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);record=n.unpack('<I',sp+4)[0];calls.append(record);result=n.unpack('<I',record+4)[0];ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,callback,begin=ADAPTER,end=ADAPTER)
def init(c=None):
 c=c or {};n.write(D,bytes(0x21000));calls.clear();n.pack('<I',0x802c54,SYS);n.pack('<I',SYS+0x2ac8,REGISTRY);n.pack('<I',0x7f8cc4,c.get('forceType',1));n.pack('<I',0x93b268,TYPEGLOBAL);n.pack('<II',TYPEGLOBAL,3,0);n.pack('<I',TYPEGLOBAL+8,TYPES);n.pack('<I',REGISTRY,BUCKET)
 for t in range(4):
  n.pack('<I',TYPES+t*0x9c+0x44,ADAPTER);n.pack('<I',BUCKET+t*0x14+4,3);n.pack('<I',BUCKET+t*0x14+12,RECORDS+t*0x100)
  for i,name in enumerate(['Alpha','Dupe','DUPE']):
   record=RECORDS+t*0x100+i*8;n.pack('<II',record,TARGET+i*0x100,NAMES+t*0x400+i*128);n.write(NAMES+t*0x400+i*128,name.encode()+b'\0')
 n.pack('<I',CRE+0x1e8,c.get('flags',0));n.pack('<II',CRE+0xd0,REF if c.get('reference',True) else 0,0);n.pack('<I',CRE+0xe4,REF if c.get('reference',True) else 0);n.pack('<I',REF,ACTOR if c.get('worldObject',True) else 0);n.pack('<B',ACTOR+0x7b5,c.get('contextByte',23)&255)
 n.pack('<I',TARGET+0xa0,c.get('flags',0));n.pack('<I',TARGET+0x3c,0xdeadbeef if c.get('hasUser',False) else 0);n.pack('<I',TARGET+0x28,GROUP if c.get('group',False) else 0);n.pack('<i',GROUP+0xc,c.get('groupState',2))
 n.pack('<I',0x93d810,PLAYER if c.get('player',True) else 0);n.pack('<I',PLAYER+0x54,DEFINITION);n.pack('<I',DEFINITION+0x24,CLASS);n.pack('<I',DEFINITION+4,c.get('definitionFlags',0));n.pack('<II',CLASS+0x90,c.get('classFlags90',0),c.get('classFlags94',0));n.pack('<I',0x93b280,CATEGORIES if c.get('categoryTable',True) else 0);n.pack('<i',0x93b26c,c.get('categoryCount',3))
 for i,name in enumerate(['Alpha','Dupe','DUPE']):
  n.write(NAMES+0x1100+i*128,name.encode()+b'\0');n.pack('<III',CATEGORIES+i*12,NAMES+0x1100+i*128,c.get('definitionMask',0),c.get('classMask',0))
 entries=c.get('hints',[dict(id=1,complete=0,timerBits=0),dict(id=2,complete=1,timerBits=0),dict(id=-1,complete=0,timerBits=0)])
 n.pack('<I',0x9514b4,HINTS if c.get('hintList',True) else 0)
 for i,row in enumerate(entries):n.pack('<h',HINTS+i*0x1c,row['id']);n.pack('<B',HINTS+i*0x1c+0x14,row['complete']);n.pack('<I',HINTS+i*0x1c+0x18,row['timerBits'])
 active=c.get('activeHint');n.pack('<I',0x9514b8,ACTIVE if active is not None else 0)
 if active is not None:n.pack('<h',ACTIVE,active)
 n.pack('<I',0x926c20,REGISTERED)
 for idx in c.get('registeredHints',[0,1,2,7]):n.pack('<I',REGISTERED+idx*4,0xdeadbeef)
def floating(a,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(a,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',RESULT)[0]
def evaluate(name,c,selector=0):
 cre=CRE if c.get('creature',True) else 0;bound=selector
 if name in ['ForceBeingUsed','ForceFinished','ForceFinishedHelper']:bound=TARGET if c.get('bound',True) else 0
 if name=='ForceFinishedHelper':return bits(float(n.call(0x467860,[bound])))
 if name=='HintAvailableHelper':return bits(float(n.call(0x5764b0,[selector])))
 if name=='HintCompleteHelper':return bits(float(n.call(0x576500,[selector])))
 return floating(ADDR[name],[SYS,0,cre,0,bound&0xffffffff])
def record(name,c,selector,want,group):
 init(c)
 try:got=evaluate(name,c,selector)
 except RuntimeError as e:
  if not c.get('expectedFault'):raise
  check(group+'-fault',True,True);cases.append(dict(command=name,context=c,selector=selector,nativeFault=str(e)));return
 if c.get('expectedFault'):check(group+'-fault',False,True)
 else:check(group,got,want,c);cases.append(dict(command=name,context=c,selector=selector,nativeBits=got))
rng=random.Random(0x440df0)
flags=[0,0xffffffff,0x800,0x801]+[1<<i for i in range(32)]+[rng.randrange(0x100000000) for i in range(256)]
for present,flag in itertools.product([False,True],flags):record('OpponentIsAThreat',dict(creature=present,flags=flag),0,bits(float(present and bool(flag&0x800))),'threat-creature-and-flags')
for bound,user,flag in itertools.product([False,True],[False,True],[0,1,0x200000,0x200001,0xffffffff,0x800]+[1<<i for i in range(32)]):record('ForceBeingUsed',dict(bound=bound,hasUser=user,flags=flag),0,bits(float(bound and (user or bool(flag&0x200000)))),'force-used-pointer-or-bit')
for bound,group,flag,state in itertools.product([False,True],[False,True],[0,0x40,0x40000040,0xffffffff],[-1,0,1,2,3,2147483647]):record('ForceFinished',dict(bound=bound,group=group,flags=flag,groupState=state),0,bits(float(bound and (not group or state==(0 if flag&0x40 else 2)))),'force-finished-playback-gate')
for bound,group,flag,state in itertools.product([False,True],[False,True],[0,0x40,0x40000040,0xffffffff],[-1,0,1,2,3,2147483647]):record('ForceFinishedHelper',dict(bound=bound,group=group,flags=flag,groupState=state),0,bits(float(not bound or not group or state==(0 if flag&0x40 else 2))),'force-finished-original-helper')
# Each byte's exact signed value and neighboring full-int selectors; unlike
# int-to-byte casting, selector255 never matches the native signed byte-1.
for name in ['InContext','OpponentContext']:
 for raw in range(256):
  signed=raw if raw<128 else raw-256
  for selector in [signed,raw,signed+256,signed-256,100]:record(name,dict(contextByte=raw),selector,bits(float(signed==selector)),'context-signed-byte-full-int')
 for creature,reference,world in itertools.product([False,True],repeat=3):
  c=dict(creature=creature,reference=reference,worldObject=world,contextByte=23)
  if name=='OpponentContext' and creature and reference and not world:c['expectedFault']=True
  record(name,c,23,bits(float(creature and reference and world)),'context-pointer-gates')
for player,selector,mask,cmask,df,cf,exclude in itertools.product([False,True],[-2,-1,0,1,2,3],[0,8,5],[0,2],[0,8,5,0xffffffff],[0,2,0xffffffff],[0,0x8000]):
 c=dict(player=player,definitionMask=mask,classMask=cmask,definitionFlags=df,classFlags90=cf,classFlags94=exclude)
 yes=player and 0<=selector<3 and (mask==0 or (not(mask&8 and exclude&0x8000) and df&mask==mask)) and cf&cmask==cmask
 record('PlayerCategoryIs',c,selector,bits(float(yes)),'player-category-original-mask-helper')
# Hint list is signed-short, ordered and terminated. Duplicate ID takes first.
def hint_expected(c,selector,complete=False,helper=False):
 entries=c.get('hints',[]);entry=None
 if c.get('hintList',True):
  for row in entries:
   if row['id']==-1:break
   if row['id']==selector:entry=row;break
 if not helper and selector==0:return 0
 if complete:return entry['complete'] if helper and entry else int(entry is not None and entry['complete']!=0)
 timer=fl(entry['timerBits']) if entry else 1
 return int(c.get('activeHint')!=selector and selector>=0 and selector in c.get('registeredHints',[0,1,2,7]) and entry is not None and entry['complete']==0 and (timer<=0 or timer!=timer))
for value in range(256):
 c=dict(hints=[dict(id=1,complete=value,timerBits=0),dict(id=1,complete=0,timerBits=0),dict(id=-1,complete=0,timerBits=0)])
 for name in ['HintAvailable','HintComplete','HintCompleteHelper']:record(name,c,1,bits(float(hint_expected(c,1,complete=name!='HintAvailable',helper=name.endswith('Helper')))),'hint-completion-byte-domain-first-match')
timers=[bits(v)for v in [-100.,-0.,0.,.0001,1.,100.]]+[1,0x80000001,0x7f800000,0xff800000,0x7fc00000,0xffc00000]
for name,selector,listing,active,registered,timer in itertools.product(['HintAvailable','HintComplete','HintAvailableHelper'],[-2,-1,0,1,2,7,32767,65535],[False,True],[None,1],[False,True],timers):
 # Keep unchecked registration reads within the prepared synthetic backing.
 if selector>7 and name in ['HintAvailable','HintAvailableHelper'] and registered:continue
 entries=[dict(id=0,complete=0,timerBits=timer),dict(id=1,complete=0,timerBits=timer),dict(id=2,complete=1,timerBits=timer),dict(id=-2,complete=255,timerBits=timer),dict(id=32767,complete=2,timerBits=timer),dict(id=-1,complete=0,timerBits=0)]
 c=dict(hints=entries,hintList=listing,activeHint=active,registeredHints=[0,1,2,7] if registered else [])
 record(name,c,selector,bits(float(hint_expected(c,selector,complete=name=='HintComplete',helper=name.endswith('Helper')))),'hint-id-list-active-registration-timer-gates')
# Force initializers use original generic lookup and return the target first word.
for address,name in [(0x440ff0,'ForceBeingUsed'),(0x441570,'ForceFinished')]:
 for operand,nulltarget,gate in itertools.product([None,'','alpha','DuPe','missing'],[False,True],['none','registry','table','callback']):
  init();n.pack('<I',RECORDS+0x100,TARGET if not nulltarget else 0)
  if gate=='registry':n.pack('<I',SYS+0x2ac8,0)
  elif gate=='table':n.pack('<I',0x93b268,0)
  elif gate=='callback':n.pack('<I',TYPES+0x9c+0x44,0)
  got=n.call(address,[SYS,token(operand)]);idx=0 if operand and operand.lower()=='alpha' else 1 if operand and operand.lower()=='dupe' else None;want=TARGET+idx*0x100 if idx is not None and gate=='none' and not(idx==0 and nulltarget) else 0;check('force-name-original-initializers',got,want,dict(name=name,operand=operand,gate=gate,nullTarget=nulltarget));initializers.append(dict(command=name,operand=operand,nullTarget=nulltarget,gate=gate,nativePointer=got,callbackRecords=list(calls)))
context_names={'DEACTIVATED':23,'FORCEDBACK':34,'GRAB':56,'EAT':63,'FORCEPUSHED':28,'FORCEPUSH':27,'GETIN':60,'BALLOONING':93,'STUNNED':90,'FLOAT':75,'GRAPPLE':70}
for operand in [None,'','unknown','STUNNEDx']+list(context_names)+[x.lower()for x in context_names]:
 init();got=n.call(0x442060,[SYS,token(operand)]);want=context_names.get((operand or '').upper(),100);check('context-name-original-initializer',got,want,operand);initializers.append(dict(command='Context',operand=operand,nativeSelector=got))
def parse_int(t):
 if t is None:return 0
 m=re.match(r'-?\d+',t);v=int(m[0]) if m else 0;return(v+0x80000000)%0x100000000-0x80000000
for operand in [None,'','0','1','-1','+1',' 1','1tail','1.9','4294967297','-4294967295','32768','65535']:
 init();got=n.call(0x442a20,[SYS,token(operand)]);check('hint-original-initializer',got,parse_int(operand)&0xffffffff,operand);initializers.append(dict(command='Hint',operand=operand,nativeSelector=got))
for system,table,operand in itertools.product([False,True],[False,True],[None,'','alpha','DuPe','missing']):
 init(dict(categoryTable=table));got=n.call(0x440c00,[SYS if system else 0,token(operand)]);want=(0 if operand and operand.lower()=='alpha' else 1 if operand and operand.lower()=='dupe' else -1) if system and table else -1;check('player-category-original-initializer',got,want&0xffffffff,dict(system=system,table=table,operand=operand));initializers.append(dict(command='PlayerCategoryIs',system=system,table=table,operand=operand,nativeSelector=got))
# All retained source occurrences: original initializer, body, literal comparison.
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'));shipped=[];omissions=[]
ops={'==':(0,lambda a,b:a==b),'<':(1,lambda a,b:a<b),'>':(2,lambda a,b:a>b),'<=':(3,lambda a,b:a<=b),'>=':(4,lambda a,b:a>=b),'!=':(5,lambda a,b:a!=b)}
for row in ledger['rows']:
 name=row['name']
 if row['kind']!='scp-condition' or name not in ADDR:continue
 for use in row['uses']:
  quoted=re.findall(r'"([^"]*)"',use['text']);operand=quoted[0] if quoted else None;line=use['line'];c={};bound=0
  if name=='OpponentIsAThreat':c=dict(flags=0x800 if line%2 else 0)
  elif name in ['ForceBeingUsed','ForceFinished']:c=dict(flags=0x200000 if line%2 else 0,hasUser=False,group=True,groupState=2 if line%2 else 1)
  elif name in ['InContext','OpponentContext']:c=dict(contextByte=context_names.get((operand or '').upper(),100) if line%2 else 0)
  elif name=='PlayerCategoryIs':c=dict(definitionMask=8,classMask=2,definitionFlags=8 if line%2 else 0,classFlags90=2,classFlags94=0)
  else:
   id=parse_int(operand);assert id>=0 and id<=32767;c=dict(hints=[dict(id=id,complete=0 if name=='HintAvailable' else line%2,timerBits=bits(0. if line%2 else 1.)),dict(id=-1,complete=0,timerBits=0)],registeredHints=[id])
  init(c)
  if name in ['ForceBeingUsed','ForceFinished']:
   n.write(NAMES+0x400,(operand or '').encode()+b'\0');bound=n.call(0x440ff0 if name=='ForceBeingUsed' else 0x441570,[SYS,token(operand)])
  elif name in ['InContext','OpponentContext']:bound=n.call(0x442060,[SYS,token(operand)])
  elif name=='PlayerCategoryIs':n.write(NAMES+0x1100,(operand or '').encode()+b'\0');bound=n.call(0x440c00,[SYS,token(operand)])
  elif name in ['HintAvailable','HintComplete']:bound=n.call(0x442a20,[SYS,token(operand)])
  if name=='OpponentIsAThreat':want=bits(float(bool(c['flags']&0x800)))
  elif name=='ForceBeingUsed':want=bits(float(bool(bound) and bool(c['flags']&0x200000)))
  elif name=='ForceFinished':want=bits(float(bool(bound) and c['groupState']==2))
  elif name in ['InContext','OpponentContext']:want=bits(float(c['contextByte']==bound))
  elif name=='PlayerCategoryIs':want=bits(float(bound!=0xffffffff and c['definitionFlags']==8))
  else:want=bits(float(hint_expected(c,parse_int(operand),complete=name=='HintComplete')))
  got=floating(ADDR[name],[SYS,0,CRE,0,bound]);check('shipped-'+name+'-body',got,want,use);comparison=None
  m=re.search(r'(==|!=|<=|>=|<|>)\s*(-?(?:\d+(?:\.\d*)?|\.\d+))(?:\s+(?:goto|and|or)\b|\s*$)',use['text'],re.I)
  if m:
   op=m[1];rhs=float(m[2]);n.pack('<I',LIST,COND);n.pack('<f',COND+8,rhs);n.pack('<B',COND+12,ops[op][0]);n.pack('<I',COND+0x18,bound);n.pack('<I',COND+0x1c,DEF);n.pack('<II',DEF,0,ADDR[name]);matched=n.call(0x52c880,[SYS,LIST,CRE,D+0x4000],regs={UC_X86_REG_EAX:0})!=0;check('shipped-'+name+'-original-comparison',matched,ops[op][1](fl(got),rhs),use);comparison=dict(operator=op,thresholdBits=bits(rhs),matched=matched)
  else:omissions.append(dict(source=use['source'],line=line,text=use['text']))
  shipped.append(dict(command=name,source=use['source'],line=line,text=use['text'],operand=operand,context=c,initialized=bound,nativeBits=got,comparison=comparison))
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,z in [(0x440df0,42),(0x441300,32),(0x4415c0,27),(0x467860,57),(0x442060,281),(0x442180,44),(0x4421b0,39),(0x442a20,21),(0x442a40,27),(0x442a60,27),(0x576480,45),(0x5764b0,77),(0x576500,51),(0x440c70,38),(0x440ff0,48),(0x441570,48)]:
 code=n.read(a,z);assembly.append(dict(entry=hex(a),size=z,bytes=code.hex(),sha256=hashlib.sha256(code).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in md.disasm(code,a)]))
report=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,errors=errors[:20],nativeFixtureCases=len(cases),initializerCases=len(initializers),shippedOccurrences=len(shipped),shippedByName={name:sum(x['command']==name for x in shipped)for name in ADDR},originalShippedComparisons=sum(x['comparison'] is not None for x in shipped),comparisonOmissions=omissions,adapters=[dict(address=hex(ADAPTER),scope='Force registry name callback returns prepared fixture record +4 name pointer; generic registry lookup and target-first-pointer extraction remain original.')],method='Original eight predicate bodies plus Force registry initializers, context initializer, category initializer and mask helper, hint initializer and ordered sentinel-list helpers, and SCP comparator. Synthetic prepared fields/tables. No native predicate/comparator/helper replacement.',limits=['No game or whole-level execution, source reachability, state producers or lifetime recovery.','ASCII operands in portable source.','Hint registration is unchecked native indexed access; fixtures prepare sufficient synthetic backing without inferring real allocation size.','Hint timer tests include finite float32, infinities and quiet NaN; signaling NaN/x87 exception or payload behavior excluded.','Prepared hint lists require a -1 sentinel; malformed unterminated memory is outside scope.','OpponentContext nonnull reference/null target faults native; portable source throws explicitly rather than manufacturing false.','Compiled C# behavioral run pending under known executable-launch restriction.'])
(BASE/'reports/script-next-20261013-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/script-next-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases,initializers=initializers,shipped=shipped),separators=(',',':')),encoding='utf8');(BASE/'reports/script-next-20261013-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8');print(json.dumps(report));assert not errors
