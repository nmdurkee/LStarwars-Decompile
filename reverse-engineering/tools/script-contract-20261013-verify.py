"""Five SCP predicates; original PC bytes, static rigid lookup and build registry lookup.
Only build record name callbacks are fixture adapters. No original game execution.
"""
import importlib.util,json,struct,itertools,random,re,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;CRE=D+0x4000;PACK=D+0x5000;REF=D+0x6000;OBJ=D+0x7000;ANIM=D+0x8000;TEXT=D+0x9000;RESULT=D+0xa000;SCENE=D+0x10000;SCENEOBJ=D+0x12000;ATTACH=D+0x14000;REGISTRY=D+0x18000;BUCKET=D+0x19000;TYPES=D+0x1a000;RECORDS=D+0x1c000;TYPEGLOBAL=D+0x1e000;NAMES=D+0x20000;LIST=D+0x24000;COND=D+0x24100;DEF=D+0x24200
ADAPTER=n.STOP+0x100;COUNTS=0x876847
ADDR={'PartyUnderCover':0x442cf0,'CannotReachDestination':0x442dc0,'RigidAnimFrame':0x442630,'BuildItComplete':0x441610,'IsSetAlive':0x441fd0}
checks={};errors=[];cases=[];initializers=[];callback_calls=[]
def check(group,got,want,meta=None):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def fl(x):return struct.unpack('<f',struct.pack('<I',x))[0]
def string(p):return n.read(p,512).split(b'\0')[0].decode('ascii') if p else None
def token(t):
 if t is None:return 0
 n.write(TEXT,t.encode()+b'\0');return TEXT
def init():
 n.write(D,bytes(0x25000));n.pack('<I',0x802c54,SYS);n.pack('<I',SYS+0x13c,SCENE);n.pack('<I',SYS+0x2ac8,REGISTRY);n.pack('<I',0x93b268,TYPEGLOBAL);n.pack('<i',0x804e44,1);n.pack('<II',TYPEGLOBAL,3,0);n.pack('<I',TYPEGLOBAL+8,TYPES);n.pack('<I',REGISTRY,BUCKET)
 n.pack('<II',SCENE+0x24,3,SCENEOBJ);n.pack('<I',SCENE+0x110,0)
 for i,name in enumerate(['Alpha','Dupe','DUPE']):
  p=SCENEOBJ+i*0x4c;n.write(NAMES+i*128,name.encode()+b'\0');n.pack('<I',p+0x44,NAMES+i*128);n.pack('<I',p+0x40,ATTACH+i*0x100);n.pack('<I',ATTACH+i*0x100+0x48,ANIM+i*0x100);n.pack('<f',ANIM+i*0x100+0x4c,i+.25)
 for t in range(4):
  n.pack('<I',TYPES+t*0x9c+0x44,ADAPTER);n.pack('<I',BUCKET+t*0x14+4,3);n.pack('<I',BUCKET+t*0x14+12,RECORDS+t*0x100)
  for i,name in enumerate(['Alpha','Dupe','DUPE']):
   record=RECORDS+t*0x100+i*8;obj=OBJ+t*0x100+i*0x80;n.pack('<II',record,obj,NAMES+0x1000+t*0x400+i*128);n.write(NAMES+0x1000+t*0x400+i*128,name.encode()+b'\0');n.pack('<B',obj+0x6d,2 if i==0 else 1)
 callback_calls.clear()
def callback(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);record=n.unpack('<I',sp+4)[0];callback_calls.append(record);result=n.unpack('<I',record+4)[0];ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,callback,begin=ADAPTER,end=ADAPTER)
def floating(a,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(a,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',RESULT)[0]
def evaluate(name,bound=0,cre=CRE):return floating(ADDR[name],[SYS,PACK,cre,0,bound])
def remember(name,bound,got,context):cases.append(dict(command=name,initialized=bound,nativeBits=got,context=context))
init()
for value in [0,1,-1,2,-2147483648,2147483647,0x40000000]:
 n.pack('<i',0x876cc8,value);got=evaluate('PartyUnderCover');check('PartyUnderCover-dword-presence',got,bits(float(value!=0)),value);remember('PartyUnderCover',0,got,dict(partyCover=value))
flags=[0,1,0x400000,0x400001,0xffffffff]+[1<<i for i in range(32)]
rng=random.Random(0x442dc0);flags += [rng.randrange(0x100000000) for _ in range(512)]
for present,flag in itertools.product([False,True],flags):
 n.pack('<I',CRE+0x1e8,flag);got=evaluate('CannotReachDestination',cre=CRE if present else 0);check('CannotReachDestination-reference-and-bit',got,bits(float(present and bool(flag&0x400000))),dict(present=present,flags=flag));remember('CannotReachDestination',0,got,dict(creature=present,flags=flag))
frames=[0,0x80000000,1,0x80000001,0x00800000,0x7f7fffff,0xff7fffff]+[bits(x) for x in [-50.,-.5,.25,1.,20.5,65536.]]
for present,frame in itertools.product([False,True],frames):
 n.pack('<I',ANIM+0x4c,frame);got=evaluate('RigidAnimFrame',ANIM if present else 0);check('RigidAnimFrame-null-default-or-frame',got,frame if present else bits(1.),dict(present=present,frameBits=frame));remember('RigidAnimFrame',int(present),got,dict(frameBits=frame))
for ref,target,status in itertools.product([False,True],[False,True],range(256)):
 n.pack('<I',REF,OBJ if target else 0);n.pack('<B',OBJ+0x6d,status);got=evaluate('BuildItComplete',REF if ref else 0);check('BuildItComplete-null-chain-and-byte-domain',got,bits(float(ref and target and status==2)),dict(reference=ref,target=target,status=status));remember('BuildItComplete',int(ref),got,dict(target=target,status=status))
for selector,count in itertools.product(range(17),range(256)):
 n.pack('<B',COUNTS+selector,count);got=evaluate('IsSetAlive',selector);check('IsSetAlive-all-literal-indices-and-counts',got,bits(float(selector!=0 and count!=0)),dict(selector=selector,count=count));remember('IsSetAlive',selector,got,dict(selector=selector,count=count))
for own in range(256):
 n.pack('<B',PACK+0xb0,own);n.pack('<B',COUNTS+own,own&1);got=evaluate('IsSetAlive',0xffffffff);check('IsSetAlive-myset-byte-domain',got,bits(float(own!=0 and bool(own&1))),own);remember('IsSetAlive',-1,got,dict(setId=own,count=own&1))
operands=[None,'','myset','MYSET','mysetx','+1',' 1','1tail','1.9','4294967297','-4294967295']+[str(x)for x in range(-2,20)]
def parse_int(t):
 if t is None:return 0
 if t.lower()=='myset':return -1
 m=re.match(r'-?\d+',t);v=int(m[0]) if m else 0;v=(v+0x80000000)%0x100000000-0x80000000;return v if 1<=v<=16 else 0
for operand in operands:
 init();got=n.call(0x441f90,[SYS,token(operand)]);check('IsSetAlive-original-initializer',got,parse_int(operand)&0xffffffff,operand);initializers.append(dict(command='IsSetAlive',operand=operand,selector=got))
# Static scene lookup remains entirely native. Duplicates preserve first-match order.
for operand,want in [(None,0),('',0),('alpha',ANIM),('ALPHA',ANIM),('DuPe',ANIM+0x100),('missing',0)]:
 init();got=n.call(0x4425e0,[SYS,token(operand)]);check('RigidAnimFrame-native-static-scene-initializer',got,want,operand);initializers.append(dict(command='RigidAnimFrame',operand=operand,initializedPointer=got,nativeBits=evaluate('RigidAnimFrame',got)))
for scene_present in [False,True]:
 init();n.pack('<I',SYS+0x13c,SCENE if scene_present else 0);n.pack('<I',SCENE+0x24,0);got=n.call(0x4425e0,[SYS,token('Alpha')]);check('RigidAnimFrame-absent-or-empty-scene',got,0)
# Build initializer installs its runtime type global and world registry before tail lookup.
for typ,operand in itertools.product([-1,0,1,2,3,4],[None,'','alpha','DuPe','missing']):
 init();n.pack('<i',0x804e44,typ);got=n.call(0x4415e0,[SYS,token(operand),0]);selected=typ if 0<=typ<=3 else 0;slot=0 if operand and operand.lower()=='alpha' else 1 if operand and operand.lower()=='dupe' else None;want=RECORDS+selected*0x100+slot*8 if slot is not None else 0;check('BuildItComplete-original-registry-initializer',got,want,dict(type=typ,operand=operand));initializers.append(dict(command='BuildItComplete',type=typ,operand=operand,initializedPointer=got,callbackRecords=list(callback_calls),nativeBits=evaluate('BuildItComplete',got)))
for missing in ['global','registry','callback','empty-bucket']:
 init()
 if missing=='global':n.pack('<I',0x93b268,0)
 elif missing=='registry':n.pack('<I',SYS+0x2ac8,0)
 elif missing=='callback':n.pack('<I',TYPES+0x9c+0x44,0)
 else:n.pack('<I',BUCKET+0x14+4,0)
 got=n.call(0x4415e0,[SYS,token('Alpha'),0]);check('BuildItComplete-initializer-gates',got,0,missing)
# Every preserved source occurrence runs native initializer, body and literal comparator.
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'));shipped=[];omissions=[]
ops={'==':(0,lambda a,b:a==b),'<':(1,lambda a,b:a<b),'>':(2,lambda a,b:a>b),'<=':(3,lambda a,b:a<=b),'>=':(4,lambda a,b:a>=b),'!=':(5,lambda a,b:a!=b)}
for row in ledger['rows']:
 name=row['name']
 if row['kind']!='scp-condition' or name not in ADDR:continue
 for use in row['uses']:
  init();quote=re.findall(r'"([^"]*)"',use['text']);operand=quote[0] if quote else None;bound=0;want=0
  if name=='PartyUnderCover':n.pack('<i',0x876cc8,use['line']%2);want=bits(float(use['line']%2))
  elif name=='CannotReachDestination':n.pack('<I',CRE+0x1e8,0x400000 if use['line']%2 else 0);want=bits(float(use['line']%2))
  elif name=='RigidAnimFrame':
   n.write(NAMES,(operand or '').encode()+b'\0');bound=n.call(0x4425e0,[SYS,token(operand)]);n.pack('<f',ANIM+0x4c,use['line']*.25);want=bits(use['line']*.25) if bound else bits(1.)
  elif name=='BuildItComplete':
   n.write(NAMES+0x1400,(operand or '').encode()+b'\0');bound=n.call(0x4415e0,[SYS,token(operand),0]);n.pack('<B',OBJ+0x100+0x6d,2 if use['line']%2 else 1);want=bits(float(bool(bound) and bool(use['line']%2)))
  elif name=='IsSetAlive':
   bound=n.call(0x441f90,[SYS,token(operand)]);idx=7 if bound==0xffffffff else bound;n.pack('<B',PACK+0xb0,7);n.pack('<B',COUNTS+idx,use['line']%2);want=bits(float(idx!=0 and bool(use['line']%2)))
  got=evaluate(name,bound);check('shipped-'+name+'-body',got,want,use);comparison=None
  m=re.search(r'(==|!=|<=|>=|<|>)\s*(-?(?:\d+(?:\.\d*)?|\.\d+))\s+(?:goto|and|or)\b',use['text'],re.I)
  if m:
   op=m[1];threshold=float(m[2]);n.pack('<I',LIST,COND);n.pack('<f',COND+8,threshold);n.pack('<B',COND+12,ops[op][0]);n.pack('<I',COND+0x18,bound);n.pack('<I',COND+0x1c,DEF);n.pack('<II',DEF,0,ADDR[name]);matched=n.call(0x52c880,[SYS,LIST,CRE,PACK],regs={UC_X86_REG_EAX:0})!=0;check('shipped-'+name+'-original-comparison',matched,ops[op][1](fl(got),threshold),use);comparison=dict(operator=op,thresholdBits=bits(threshold),matched=matched)
  else:omissions.append(dict(source=use['source'],line=use['line'],text=use['text']))
  shipped.append(dict(command=name,source=use['source'],line=use['line'],text=use['text'],operand=operand,initializedPointer=bound,nativeBits=got,comparison=comparison))
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,size in [(0x442cf0,15),(0x442dc0,26),(0x442630,15),(0x4425e0,72),(0x441610,26),(0x4415e0,39),(0x441fd0,39),(0x441f90,53),(0x5d0420,43),(0x5cfac0,35)]:
 code=n.read(a,size);assembly.append(dict(entry=hex(a),size=size,bytes=code.hex(),sha256=hashlib.sha256(code).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in md.disasm(code,a)]))
report=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,errors=errors[:20],shippedOccurrences=len(shipped),shippedByName={name:sum(x['command']==name for x in shipped)for name in ADDR},originalShippedComparisons=sum(x['comparison'] is not None for x in shipped),comparisonOmissions=omissions,method='Original five predicate bodies, three initializer entrypoints, static scene name lookup 0x5cf5b0, scene reference validation 0x5cfac0, animation projection 0x5d0420, generic build registry lookup 0x55a020 and SCP comparator 0x52c880. Synthetic world/scene/registry/packet fields. Build name accessor callback only is adapted.',adapters=[dict(address=hex(ADAPTER),via='registry type record +0x44',scope='Synthetic build record name accessor returns fixture name pointer at record +4. Real name-accessor layout, loader and reference lifetime are external.')],limits=['No whole-game execution; callbacks and globals are fixture preparation.','Rigid initializer checks cover static scene linear lookup (scene +0x110 == 0); accelerated/dynamic resolver 0x5cf510 is outside this contract.','Finite float32 frame values only; signaling NaN and x87 exception/payload semantics excluded.','Build callback and synthetic registry projections validate lookup orchestration, not build object creation or completion updates.','IsSetAlive myset covers 256 byte indices in a synthetic backing region, not proof of the actual global table allocation.','Compiled C# behavioral comparisons are pending.'])
(BASE/'reports/script-contract-20261013-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/script-contract-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases,initializers=initializers,shipped=shipped),separators=(',',':')),encoding='utf8');(BASE/'reports/script-contract-20261013-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8');print(json.dumps(report));assert not errors
