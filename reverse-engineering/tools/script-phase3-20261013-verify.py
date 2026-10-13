"""Original PC actor flag/input script commands; named callback alone adapted."""
import importlib.util,json,struct,itertools,random,re,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;PACK=D+0x1000;CRE=D+0x2000;REF=D+0x3000;ACTORS=D+0x5000;INPUT=D+0x9000;ARGS=D+0xa000;TEXT=D+0xb000;RESULT=D+0x10000;LIST=D+0x11000;COND=D+0x11100;DEF=D+0x11200;ADAPTER=n.STOP+0x100
ADDR={'PressJumpButton':0x449970,'PrefersPlayers':0x44f1b0,'CanShootOffScreen':0x44ee70,'CanOpenDoors':0x44ede0,'CanDefend':0x4445c0,'Respawnable':0x4447a0,'SetBoss':0x4448c0,'SetDontMove':0x445b70,'UnderPlayerControl':0x443280}
checks={};errors=[];cases=[];initializers=[];calls=[];bindings={}
def check(group,got,want,meta=None):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def string(p):return n.read(p,512).split(b'\0')[0].decode('ascii') if p else None
def actor(i):return ACTORS+i*0x1100
def reference(i):return REF+i*0x100
def callback(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);system=n.unpack('<I',sp+4)[0];operand=string(n.unpack('<I',sp+8)[0]);calls.append(dict(system=system!=0,name=operand));result=bindings.get((operand or '').lower(),0);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,callback,begin=ADAPTER,end=ADAPTER)
def init(tokens,c=None):
 c=c or {};n.write(D,bytes(0x12000));calls.clear();bindings.clear();bindings.update({'self':reference(0),'other':reference(1),'third':reference(2),'empty':reference(3)})
 n.pack('<I',0x923904,ADAPTER if c.get('callback',True) else 0);n.pack('<I',0x802278,c.get('jumpMask',0x40));n.pack('<I',CRE+0xd0,reference(0) if c.get('reference',True) else 0)
 for i in range(3):
  n.write(actor(i),bytes([0x55+i*17])*0x1100);n.pack('<I',reference(i),actor(i) if i!=0 or c.get('worldObject',True) else 0);n.pack('<I',actor(i)+0xca4,INPUT+i*0x100 if c.get('input',True) else 0)
  f=c.get('initialFlags',0x81234567)^((i*0x11111111)&0xffffffff)
  for off in [0x1fc,0xeec,0xef0,0x1044]:n.pack('<I',actor(i)+off,f)
  n.pack('<I',INPUT+i*0x100+8,f)
 for i,t in enumerate(tokens):
  if t is None:n.pack('<I',ARGS+i*4,0)
  else:n.write(TEXT+i*512,t.encode()+b'\0');n.pack('<I',ARGS+i*4,TEXT+i*512)
def token(t):
 if t is None:return 0
 n.write(TEXT+0x4000,t.encode()+b'\0');return TEXT+0x4000
def snap():return [dict(flags1fc=n.unpack('<I',actor(i)+0x1fc)[0],flagsEec=n.unpack('<I',actor(i)+0xeec)[0],flagsEf0=n.unpack('<I',actor(i)+0xef0)[0],flags1044=n.unpack('<I',actor(i)+0x1044)[0],inputFlags=n.unpack('<I',INPUT+i*0x100+8)[0])for i in range(3)]
def equal(a,b):return a is not None and b is not None and a.lower()==b.lower()
def expected(name,tokens,c,before):
 out=[dict(x)for x in before];present=c.get('creature',True) and c.get('reference',True) and c.get('worldObject',True);first=c.get('first',True);selection=0 if present else None
 if name=='SetDontMove':
  if not first:return out,[]
  enabled=True;ev=[]
  for t in tokens:
   at=(t or '').lower().find('character')
   if at>=0:
    if not c.get('callback',True):selection=None
    else:
     namepart=t[at+10:];ev.append(dict(system=c.get('system',True),name=namepart));selection={'self':0,'other':1,'third':2}.get(namepart.lower())
   elif equal(tokens[0],'FALSE'):enabled=False
  if selection is not None:out[selection]['flagsEf0']=(out[selection]['flagsEf0']&0xffffffef)|(0x10 if enabled else 0)
  return out,ev
 if not present:return out,[]
 row=out[0]
 if name=='PressJumpButton':row['inputFlags']|=c.get('jumpMask',0x40)
 elif name=='PrefersPlayers':row['flagsEec']=(row['flagsEec']|0x40000000)&(0xbfffffff if any(equal(t,'FALSE')for t in tokens)else 0xffffffff)
 elif first:
  if name in ['CanShootOffScreen','CanOpenDoors']:
   bit=4 if name=='CanShootOffScreen' else 1;row['flags1044']|=bit
   for t in tokens:
    if equal(t,'TRUE'):row['flags1044']|=bit
    elif equal(t,'FALSE'):row['flags1044']&=~bit
  elif name in ['CanDefend','SetBoss']:
   bit=2 if name=='CanDefend' else 0x8000000;row['flagsEec']|=bit
   if any(equal(t,'FALSE')for t in tokens):row['flagsEec']&=~bit
  elif name=='Respawnable':
   row['flagsEec']=(row['flagsEec']&0xffdfffff)|0x100000
   for t in tokens:
    if equal(t,'origin'):row['flagsEec']|=0x200000
    elif equal(t,'FALSE'):row['flagsEec']&=0xffefffff
 return out,[]
def execute(name,tokens,c,group,source=None):
 init(tokens,c);before=snap();oldactors=[n.read(actor(i),0x1100)for i in range(3)];oldinputs=[n.read(INPUT+i*0x100,0x100)for i in range(3)];cre=CRE if c.get('creature',True)else 0
 if c.get('expectedFault'):
  try:n.call(ADDR[name],[SYS,PACK,cre,ARGS,len(tokens),int(c.get('first',True))])
  except RuntimeError as e:check(group+'-native-fault',True,True);cases.append(dict(command=name,tokens=tokens,context=c,nativeFault=str(e)));return
  check(group+'-native-fault',False,True);return
 ret=n.call(ADDR[name],[SYS if c.get('system',True)else 0,PACK,cre,ARGS,len(tokens),int(c.get('first',True))]);want,ev=expected(name,tokens,c,before);got=snap();check(group+'-return',ret,1);check(group+'-state',got,want,dict(name=name,tokens=tokens,context=c));check(group+'-callbacks',calls,ev)
 expectedactors=[];expectedinputs=[]
 for i in range(3):
  a=bytearray(oldactors[i]);inp=bytearray(oldinputs[i]);row=want[i]
  for off,key in [(0x1fc,'flags1fc'),(0xeec,'flagsEec'),(0xef0,'flagsEf0'),(0x1044,'flags1044')]:struct.pack_into('<I',a,off,row[key])
  struct.pack_into('<I',inp,8,row['inputFlags']);expectedactors.append(bytes(a));expectedinputs.append(bytes(inp))
 confined=all(n.read(actor(i),0x1100)==expectedactors[i]and n.read(INPUT+i*0x100,0x100)==expectedinputs[i]for i in range(3));check(group+'-write-confinement',confined,True)
 row=dict(command=name,tokens=tokens,context=c,nativeReturn=ret,nativeState=got,callbackCalls=list(calls),writesConfined=confined)
 if source:row['source']=source
 cases.append(row)
actions=[name for name in ADDR if name!='UnderPlayerControl']
tokensets=[[],['TRUE'],['FALSE'],['true','FALSE'],['FALSE','true'],['unknown','false'],['falsex'],['FALSE','unknown','TRUE'],['origin'],['FALSE','origin'],['origin','FALSE'],['origin','TRUE','FALSE']]
for name,first,creature,ref,obj,ts,flags in itertools.product(actions,[False,True],[False,True],[False,True],[False,True],tokensets,[0,0xffffffff,0x81234567,0x0c300007]):
 execute(name,ts,dict(first=first,creature=creature,reference=ref,worldObject=obj,initialFlags=flags),'actor-actions-gates-token-order-unrelated-bits')
# Everyjump mask bit is a runtime global input; PressJump ignores firstCall.
for bit,seed,first in itertools.product(range(32),[0,0xffffffff,0xaaaaaaaa],[False,True]):execute('PressJumpButton',[],dict(jumpMask=1<<bit,initialFlags=seed,first=first),'jump-runtime-global-mask')
execute('PressJumpButton',[],dict(input=False,expectedFault=True),'jump-missing-input')
# Target alias and missing-target semantics; setter can recover a target from
# callback even when its script creature/self chain is absent.
retarget=[['character=other'],['prefixCHARACTER=third'],['FALSE','character=other'],['character=other','FALSE'],['unknown','FALSE','character=other'],['character=other','character=self'],['character=self','character=other'],['character=other','character=missing'],['character=missing','character=third'],['character=empty'],['character=other','TRUE']]
for ts,callback,system,first,present in itertools.product(retarget,[False,True],[False,True],[False,True],[False,True]):execute('SetDontMove',ts,dict(callback=callback,system=system,first=first,creature=present),'dont-move-named-selection-first-token-false')
# Complete byte flag domain plus unrelated high flags. No self fallback.
for bound,low,high in itertools.product([False,True],range(256),[0,0x12345600]):
 init([]);n.pack('<I',actor(0)+0x1fc,high|low);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(0x443280,[SYS,PACK,CRE,0,actor(0)if bound else 0]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',RESULT)[0];check('under-player-control-bound-flags',got,bits(float(bound and bool(low&0x80))));cases.append(dict(command='UnderPlayerControl',context=dict(bound=bound,flags1fc=high|low),nativeBits=got))
for operand,system,callback in itertools.product([None,'','self','other','empty','missing'],[False,True],[False,True]):
 init([],dict(callback=callback));got=n.call(0x443250,[SYS if system else 0,token(operand)]);want={'self':actor(0),'other':actor(1)}.get(operand,0)if system and callback and operand is not None else 0;check('under-player-control-original-initializer',got,want);check('under-player-control-initializer-callback-gates',len(calls),int(system and callback and operand is not None));initializers.append(dict(operand=operand,system=system,callback=callback,nativePointer=got,callbackCalls=list(calls)))
# All169source uses: each action in both first/nonfirst modes, each condition
# original initializer/body/literal comparator. This is authored-form coverage,
# not a count of reachable world-state scenarios.
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'));shipped=[];ops={'==':(0,lambda a,b:a==b),'!=':(5,lambda a,b:a!=b)}
for row in ledger['rows']:
 name=row['name']
 if name not in ADDR:continue
 for use in row['uses']:
  if name!='UnderPlayerControl':
   for first in [False,True]:execute(name,use['args'],dict(first=first,initialFlags=0x81234567),'shipped-'+name,use)
   shipped.append(dict(command=name,source=use['source'],line=use['line'],text=use['text']))
  else:
   quoted=re.findall(r'"([^"]*)"',use['text']);operand=quoted[0]if quoted else None;init([])
   if operand is not None:bindings[operand.lower()]=reference(1)
   n.pack('<I',actor(0)+0x1fc,0x80);n.pack('<I',actor(1)+0x1fc,0x80 if use['line']%2 else 0);bound=n.call(0x443250,[SYS,token(operand)]);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(0x443280,[SYS,PACK,CRE,0,bound]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',RESULT)[0];want=bits(float(operand is not None and bool(use['line']%2)));check('shipped-UnderPlayerControl-body',got,want)
   m=re.search(r'(==|!=)\s*(\d+)(?:\s+(?:goto|and|or)\b|\s*$)',use['text'],re.I);assert m;op=m[1];rhs=float(m[2]);n.pack('<I',LIST,COND);n.pack('<f',COND+8,rhs);n.pack('<B',COND+12,ops[op][0]);n.pack('<I',COND+0x18,bound);n.pack('<I',COND+0x1c,DEF);n.pack('<II',DEF,0,0x443280);matched=n.call(0x52c880,[SYS,LIST,CRE,PACK],regs={UC_X86_REG_EAX:0})!=0;check('shipped-UnderPlayerControl-original-comparison',matched,ops[op][1](struct.unpack('<f',struct.pack('<I',got))[0],rhs));shipped.append(dict(command=name,source=use['source'],line=use['line'],text=use['text'],operand=operand,nativePointer=bound,nativeBits=got,callbackCalls=list(calls),comparison=dict(operator=op,thresholdBits=bits(rhs),matched=matched)))
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,z in [(0x449970,50),(0x44f1b0,112),(0x44ee70,144),(0x44ede0,144),(0x4445c0,144),(0x4447a0,160),(0x4448c0,144),(0x445b70,180),(0x443250,44),(0x443280,23)]:
 code=n.read(a,z);assembly.append(dict(entry=hex(a),size=z,bytes=code.hex(),sha256=hashlib.sha256(code).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in md.disasm(code,a)]))
report=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,errors=errors[:20],savedCases=len(cases),savedInitializers=len(initializers),shippedOccurrences=len(shipped),shippedByName={name:sum(x['command']==name for x in shipped)for name in ADDR},shippedActionCalls=sum('source'in x for x in cases),shippedConditionComparisons=sum(x['command']=='UnderPlayerControl'for x in shipped),method='Original eight action entrypoints, UnderPlayerControl initializer/body and SCP comparator. Original token equality/substring helpers. Prepared actor/reference/input fields. Named callback0x923904 is the only adapter. Each successful action additionally checks entire prepared actor and input bytes against only permitted field writes.',adapters=[dict(globalAddress='0x923904',fixtureAddress=hex(ADAPTER),scope='Maps ASCII fixture names to actor references or null; callback records system-presence and operand order. Native code performs reference first-pointer extraction.')],limits=['No world loading, actor lifetime, input consumption, movement or AI consumer recovery.','Actions use prepared token arrays and counts matching array lengths; invalid external argc/argv memory is outside scope.','ASCII tokens only in portable source. Character-substring operands require at least one following delimiter byte before name+10.','Jump input pointer is unchecked by native after actor gates; actual memory fault saved, portable source raises explicit exception.','UnderPlayerControl uses only initialized named actor and has no self fallback on missing operand.','Standalone C# compilation does not establish managed behavioral execution; no launch retry under known EPERM restriction.'])
(BASE/'reports/script-phase3-20261013-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/script-phase3-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases,initializers=initializers,shipped=shipped),separators=(',',':')),encoding='utf8');(BASE/'reports/script-phase3-20261013-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8');print(json.dumps(report));assert not errors
