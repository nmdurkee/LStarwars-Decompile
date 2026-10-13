"""Original PC player-reference, liveness and aggregate condition contracts."""
import importlib.util,json,struct,itertools,random,re,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;PACK=D+0x2000;CRE=D+0x3000;REFS=D+0x5000;BOUND=D+0x9000;SELF=D+0xb000;DEFINITION=D+0xd000;GROUP=D+0xe000;MEMBERS=D+0x10000;TEXT=D+0x15000;RESULT=D+0x16000;LIST=D+0x17000;COND=D+0x17100;DEF=D+0x17200;ACTORS=D+0x20000;ADAPTER=n.STOP+0x100
ADDR={'EitherPlayerIs':0x440f30,'Player1Is':0x440f60,'Player2Is':0x440f80,'FinishedSpline':0x4429d0,'NumBaddies':0x442270,'IsAlive':0x4416b0,'MySet':0x440b30,'NumBaddiesThatCanSeePlayers':0x442d00}
checks={};errors=[];cases=[];initializers=[];shipped=[];calls=[];bindings={}
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def check(group,got,want,meta=None):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def reference(i):return REFS+i*0x1100 if i>=0 else 0
def actor(i):return ACTORS+i*0x10d8
def member(i):return MEMBERS+i*0x1100
def string(p):return n.read(p,512).split(b'\0')[0].decode('ascii')if p else None
def token(t):
 if t is None:return 0
 n.write(TEXT,t.encode()+b'\0');return TEXT
def callback(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);system=n.unpack('<I',sp+4)[0];name=string(n.unpack('<I',sp+8)[0]);calls.append(dict(system=system!=0,name=name));result=bindings.get((name or '').lower(),0);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,callback,begin=ADAPTER,end=ADAPTER)
def init(c=None):
 c=c or {};n.write(D,bytes(0x65000));calls.clear();bindings.clear();bindings.update({'first':reference(0),'second':reference(1),'alias':reference(2),'alive':BOUND})
 n.pack('<I',0x923904,ADAPTER if c.get('callback',True)else 0);n.pack('<II',SYS+0x138c,reference(c.get('player1',0)),reference(c.get('player2',1)))
 # First and alias point to same physical object but retain distinct references.
 n.pack('<I',reference(0),SELF);n.pack('<I',reference(1),SELF+0x1100);n.pack('<I',reference(2),SELF)
 n.pack('<I',CRE+0xd0,reference(0)if c.get('reference',True)else 0);n.pack('<I',reference(0),SELF if c.get('worldObject',True)else 0);n.pack('<I',SELF+0xe64,0xdeadbeef if c.get('spline',True)else 0);n.pack('<B',SELF+0xe6b,c.get('splineFinished',0))
 n.pack('<I',BOUND+4,DEFINITION if c.get('definition',True)else 0);n.pack('<I',DEFINITION+0x144,GROUP if c.get('group',False)else 0);n.pack('<I',BOUND+0x1fc,c.get('flags',0x1000));n.pack('<B',BOUND+0x28b,c.get('dead',0))
 members=c.get('members',[dict(flags=0x1001,dead=0)]);count=c.get('groupCount',len(members));n.pack('<B',GROUP+7,count)
 for i,row in enumerate(members):
  pointer=member(i)if row is not None else 0;n.pack('<I',GROUP+0xc+i*4,pointer)
  if row is not None:n.pack('<I',pointer+0x1fc,row['flags']);n.pack('<B',pointer+0x28b,row['dead'])
 n.pack('<B',PACK+0xb0,c.get('setId',7));n.pack('<i',0x876840,c.get('baddiesSeeing',17));rows=c.get('actors',[]);n.pack('<i',0x93d500,c.get('actorCount',len(rows)));n.pack('<I',0x93d504,ACTORS)
 for i,row in enumerate(rows):n.pack('<II',actor(i)+0x1f8,row['flags1f8'],row['flags1fc'])
def floating(address,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(address,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',RESULT)[0]
def evaluate(name,c):
 bound=reference(c.get('bound',0))if name in ['EitherPlayerIs','Player1Is','Player2Is']else BOUND if name=='IsAlive'and c.get('bound',True)else 0
 return floating(ADDR[name],[SYS if c.get('system',True)else 0,PACK if c.get('packet',True)else 0,CRE if c.get('creature',True)else 0,0,bound])
def record(name,c,want,group):
 init(c)
 if c.get('expectedFault'):
  try:evaluate(name,c)
  except RuntimeError as e:check(group+'-fault',True,True);cases.append(dict(command=name,context=c,nativeFault=str(e)));return
  check(group+'-fault',False,True);return
 got=evaluate(name,c);check(group,got,want,c);cases.append(dict(command=name,context=c,nativeBits=got))
for name,system,bound,p1,p2 in itertools.product(['EitherPlayerIs','Player1Is','Player2Is'],[False,True],[-1,0,1,2],[-1,0,1,2],[-1,0,1,2]):
 yes=system and bound!=-1 and((bound==p1 or bound==p2)if name=='EitherPlayerIs'else bound==(p1 if name=='Player1Is'else p2));record(name,dict(system=system,bound=bound,player1=p1,player2=p2),bits(float(yes)),'player-reference-identity-not-object-alias')
for creature,ref,obj,spline,status in itertools.product([False,True],[False,True],[False,True],[False,True],range(256)):
 value=-1 if not(creature and ref and obj)else 0 if spline and status==0 else 1;record('FinishedSpline',dict(creature=creature,reference=ref,worldObject=obj,spline=spline,splineFinished=status),bits(float(value)),'finished-spline-complete-byte-and-null-domain')
for bound,flags,dead in itertools.product([False,True],[0,1,0x1000,0x1001,0xffffffff],[0,1,255]):record('IsAlive',dict(bound=bound,flags=flags,dead=dead),bits(float(bound and flags&0x1000!=0 and dead==0)),'alive-solo-omits-active-bit')
record('IsAlive',dict(definition=False,expectedFault=True),0,'alive-missing-definition')
memberpatterns=[[],[None],[dict(flags=0x1000,dead=0)],[dict(flags=1,dead=0)],[dict(flags=0x1001,dead=0)],[dict(flags=0x1001,dead=1)],[None,dict(flags=0x1001,dead=0)],[dict(flags=0x1001,dead=255),None,dict(flags=0xffffffff,dead=0)],[dict(flags=0xffffffff,dead=0),dict(flags=0x1001,dead=1)]]
for members,bound,solo,dead in itertools.product(memberpatterns,[False,True],[0,0x1000],[0,255]):
 yes=bound and any(row is not None and row['flags']&0x1001==0x1001 and row['dead']==0 for row in members);record('IsAlive',dict(bound=bound,group=True,members=members,flags=solo,dead=dead),bits(float(yes)),'alive-ordered-group-precedes-solo')
for raw in range(256):record('IsAlive',dict(group=True,members=[dict(flags=0x1001,dead=raw)]),bits(float(raw==0)),'alive-group-complete-dead-byte')
# Explicitly prepared255member pointer slots; aliases may repeat and list count
# is a byte. Place eligible target at end then none to exercise complete scan.
for live_at_end in [False,True]:
 init(dict(group=True,groupCount=255,members=[]));n.pack('<I',member(0)+0x1fc,0x1001);n.pack('<B',member(0)+0x28b,0)
 for i in range(255):n.pack('<I',GROUP+0xc+i*4,member(0)if live_at_end and i==254 else 0)
 got=evaluate('IsAlive',dict(group=True));check('alive-255-slot-member-count-boundary',got,bits(float(live_at_end)));cases.append(dict(command='IsAlive',context=dict(group=True,groupCount=255,members=[None]*254+[dict(flags=0x1001,dead=0)if live_at_end else None]),nativeBits=got))
rng=random.Random(0x442270)
rows=[dict(flags1f8=a,flags1fc=b)for a,b in itertools.product([0,1,2,0xffffffff],[0,1,0x1000,0x1001,0xffffffff,0x1002])]
for count in [-2,-1,0]+list(range(1,len(rows)+1)):
 yes=sum(row['flags1fc']&0x1001==0x1001 and row['flags1f8']&1!=0 for row in rows[:max(0,count)]);record('NumBaddies',dict(actorCount=count,actors=rows),bits(float(yes)),'num-baddies-array-stride-and-three-bit-gates')
for count in [1,2,8,32,64]:
 for seed in range(32):
  actors=[dict(flags1f8=rng.randrange(0x100000000),flags1fc=rng.randrange(0x100000000))for _ in range(count)];yes=sum(row['flags1fc']&0x1001==0x1001 and row['flags1f8']&1!=0 for row in actors);record('NumBaddies',dict(actorCount=count,actors=actors),bits(float(yes)),'num-baddies-random-prepared-array')
init();zero=n.call(0x442260,[SYS,token('ignored')]);check('num-baddies-original-zero-initializer',zero,0);initializers.append(dict(command='NumBaddies',operand='ignored',nativePointer=zero,callbackCalls=[]))
for packet,own in itertools.product([False,True],range(256)):record('MySet',dict(packet=packet,setId=own,expectedFault=not packet),bits(float(own)),'my-set-complete-byte-domain-and-packet-fault')
values=[-2147483648,-16777217,-1,0,1,2,16777215,16777216,16777217,2147483647]+[rng.randrange(-2147483648,2147483648)for _ in range(256)]
for value in values:record('NumBaddiesThatCanSeePlayers',dict(baddiesSeeing=value),bits(float(value)),'baddies-seeing-signed-dword-to-float32')
for command,address in [('PlayerReference',0x440f10),('IsAlive',0x441690)]:
 for operand,system,callback_present in itertools.product([None,'','first','alias','alive','missing'],[False,True],[False,True]):
  init(dict(callback=callback_present));got=n.call(address,[SYS if system else 0,token(operand)]);want=bindings.get((operand or '').lower(),0)if operand is not None and callback_present else 0;check('reference-original-initializers-null-system-allowed',got,want);check('reference-original-initializer-callback-gates',len(calls),int(operand is not None and callback_present));initializers.append(dict(command=command,operand=operand,system=system,callback=callback_present,nativePointer=got,callbackCalls=list(calls)))
# Every97cataloged authored condition occurrence runs original body and literal
# comparator. BindReference cases adapt source names to existing records only.
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'));ops={'==':(0,lambda a,b:a==b),'!=':(5,lambda a,b:a!=b),'<':(1,lambda a,b:a<b),'>':(2,lambda a,b:a>b),'<=':(3,lambda a,b:a<=b),'>=':(4,lambda a,b:a>=b)}
for row in ledger['rows']:
 name=row['name']
 if row['kind']!='scp-condition'or name not in ADDR:continue
 for use in row['uses']:
  q=re.findall(r'"([^"]*)"',use['text']);operand=q[0]if q else None;line=use['line'];c=dict(splineFinished=line%2,flags=0x1000 if line%2 else 0,dead=0,setId=line%17,baddiesSeeing=line%8,actors=[dict(flags1f8=1,flags1fc=0x1001),dict(flags1f8=1,flags1fc=0x1001 if line%2 else 0)],bound=True);init(c);bound=0
  if name in ['EitherPlayerIs','Player1Is','Player2Is']:
   if operand is not None:bindings[operand.lower()]=reference(0)
   bound=n.call(0x440f10,[SYS,token(operand)]);want=bits(float(bound!=0 and name!='Player2Is'))
  elif name=='IsAlive':
   if operand is not None:bindings[operand.lower()]=BOUND
   bound=n.call(0x441690,[SYS,token(operand)]);want=bits(float(bound!=0 and bool(line%2)))
  elif name=='NumBaddies':bound=n.call(0x442260,[SYS,token(operand)]);want=bits(float(1+line%2))
  elif name=='FinishedSpline':want=bits(float(line%2))
  elif name=='MySet':want=bits(float(c['setId']))
  else:want=bits(float(c['baddiesSeeing']))
  got=floating(ADDR[name],[SYS,PACK,CRE,0,bound]);check('shipped-'+name+'-body',got,want,use)
  m=re.search(r'(==|!=|<=|>=|<|>)\s*(-?(?:\d+(?:\.\d*)?|\.\d+))(?:f)?(?:\s+(?:goto|and|or)\b|\s*$)',use['text'],re.I);assert m,use;op=m[1];rhs=float(m[2]);n.pack('<I',LIST,COND);n.pack('<f',COND+8,rhs);n.pack('<B',COND+12,ops[op][0]);n.pack('<I',COND+0x18,bound);n.pack('<I',COND+0x1c,DEF);n.pack('<II',DEF,0,ADDR[name]);matched=n.call(0x52c880,[SYS,LIST,CRE,PACK],regs={UC_X86_REG_EAX:0})!=0;check('shipped-'+name+'-original-comparison',matched,ops[op][1](fl(got),rhs),use);shipped.append(dict(command=name,source=use['source'],line=line,text=use['text'],operand=operand,context=c,nativePointer=bound,nativeBits=got,callbackCalls=list(calls),comparison=dict(operator=op,thresholdBits=bits(rhs),matched=matched)))
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,z in [(0x440f10,29),(0x440f30,43),(0x440f60,30),(0x440f80,30),(0x4429d0,65),(0x442260,3),(0x442270,87),(0x441690,29),(0x4416b0,115),(0x440b30,23),(0x442d00,7)]:
 code=n.read(a,z);assembly.append(dict(entry=hex(a),size=z,bytes=code.hex(),sha256=hashlib.sha256(code).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in md.disasm(code,a)]))
report=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,errors=errors[:20],savedCases=len(cases),savedInitializers=len(initializers),shippedOccurrences=len(shipped),shippedByName={name:sum(x['command']==name for x in shipped)for name in ADDR},shippedConditionComparisons=len(shipped),method='Original eight condition bodies, three named/zero initializer entries and original SCP comparator. Synthetic valid records/definitions/group members/actor arrays/packet fields and signed global dword values. Named-character callback0x923904 alone is adapted.',adapters=[dict(globalAddress='0x923904',fixtureAddress=hex(ADAPTER),scope='ASCII names map to reference records or null; callback retains null-system calls. References that share physical-object first pointer remain distinct.')],limits=['No game execution,reference lifetime,group construction,spline updates or population of aggregate globals.','IsAlive reads initialized record+4 definition without guard; missing definition faults native and portable source throws explicitly.','Solo IsAlive tests live bit1000 without active bit1; grouped members need both. An existing zero-count group overrides solo liveness.','MySet has no packet-null guard; actual faults saved,portable source throws explicitly.','Prepared group member arrays honor uint8 count through255; generic malformed/out-of-backing memory is outside scope.','Actor array uses original stride0x10d8; counted records and liveness fields must be prepared.','Global NumBaddiesThatCanSeePlayers is signed dword read; tests compare float32 storage boundary used by SCP evaluator.','ASCII names only in portable source; alias policy and callback side effects beyond fixture resolution external.','Managed execution pending under existing EPERM restriction; no launch retry.'])
(BASE/'reports/script-phase5-20261013-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/script-phase5-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases,initializers=initializers,shipped=shipped),separators=(',',':')),encoding='utf8');(BASE/'reports/script-phase5-20261013-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8');print(json.dumps(report));assert not errors
