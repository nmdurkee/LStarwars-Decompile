"""Original jump-context561ba0/sound547f30/reset62e650. Only terminal audio adapters."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
spec=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();D=n.DATA;ACTOR=D+0x1000;DEF=D+0x8000;CL=D+0x9000;WORLD=D+0xa000;checks={};errors=[];cases=[];events=[];config={};shadow={};model_events=[]
cs=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,size in [(0x561ba0,244),(0x547f30,210),(0x62e650,59)]:assembly.append(dict(address=hex(a),size=size,bytes=n.read(a,size).hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,size),a)]))
switchData=dict(address='0x548004',kind='data',bytes=n.read(0x548004,20).hex(),targets=[hex(x)for x in n.unpack('<5I',0x548004)])
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def rb(p):
 if p not in shadow:raise RuntimeError('unmapped '+hex(p))
 return shadow[p]
def rd(p):return sum(rb(p+i)<<(i*8)for i in range(4))
def rw(p):return rb(p)|(rb(p+1)<<8)
def wb(p,v):
 if p not in shadow:raise RuntimeError('unmapped write '+hex(p))
 shadow[p]=v&255
def wd(p,v):
 for i in range(4):wb(p+i,v>>(i*8))
def ww(p,v):wb(p,v);wb(p+1,v>>8)
def check(k,a,b,c):
 checks[k]=checks.get(k,0)+1
 if a!=b:errors.append(dict(group=k,got=a,want=b,input=c))
def hook(mu,a,size,data):
 if a not in [0x681e90,0x681eb0]:return
 name='PlayerSound'if a==0x681e90 else'WorldSound';count=2 if a==0x681e90 else 3;sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*count,sp+4));events.append(dict(name=name,args=args))
 for p,value in config.get('patches',{}).get(name,[]):n.pack('<I',p,value)
 mu.reg_write(UC_X86_REG_EAX,0xaabbccdd);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,hook)
def sound(actor,mode):
 flags=rd(rd(actor+0x54)+4)
 if flags&0x40:slot=0x15a
 elif not flags&8:slot=0x158
 else:
  if mode>4:return
  slot=[0x15c,0x15e,0x164,0x160,0x162][mode]
 id=rw(rd(0x8020bc)+slot);id=id-65536 if id>=32768 else id
 if id==-1:return
 name='PlayerSound'if(rb(actor+0x1fc)&0x80)or(rd(actor+0xeec)&0x8000000)else'WorldSound';args=[id&0xffffffff,actor+0x19c]+([]if name=='PlayerSound'else[bits(.5)]);model_events.append(dict(name=name,args=args))
 for p,value in config.get('patches',{}).get(name,[]):wd(p,value)
def enter(actor,mode):
 context=rd(0x802838)
 if context!=0xffffffff:
  wb(actor+0x7b5,context);wb(actor+0x7b8,mode);animation=rw(0x804bec);wd(actor+0x77c,0);ww(actor+0x7aa,animation);flags=rd(actor+0x7bc);height=rd(actor+0x17c);wd(actor+0x78c,height);wd(actor+0x788,0);wb(actor+0x7b9,1);wd(actor+0x7bc,(flags&0xfffe6fff)|(0x10000 if mode in[3,4]else 0))
  if mode&255 not in[6,7]:sound(actor,0)
 definition=rd(actor+0x54);wb(actor+0x281,0);ww(actor+0x1050,0);typ=rd(definition+0x24);impulse=rd(typ+0x2c);wd(actor+0xe20,rd(actor+0xe20)|0x100000);wd(actor+0x6c,impulse);wd(actor+0xd48,0);wd(actor+0xd2c,0);wd(actor+0xd1c,0)
 p=actor+8;wd(p+4,bits(1));ww(p+0x3a,65535);wd(p+0x14,bits(1));ww(p+0x38,65535);wd(p,bits(1));ww(p+0x36,65535);wb(p+0x31,0);wb(p+0x30,4);ww(p+0x42,65535);wb(p+0x3e,0);wb(p+0x3c,0);wb(p+0x3d,0);ww(actor+0x278,0);ww(actor+0x27c,0);wb(actor+0x107a,2)
def prepare(c):
 n.write(D,bytes(0x10000));rng=random.Random(c.get('seed',7));n.write(ACTOR,bytes(rng.randrange(256)for _ in range(0x1100)));n.pack('<I',ACTOR+0x54,0 if c.get('nullDef')else DEF);n.pack('<I',DEF+0x24,0 if c.get('nullClass')else CL);n.pack('<I',DEF+4,c.get('definitionFlags',0));n.pack('<I',ACTOR+0x1fc,c.get('flags1fc',0));n.pack('<I',ACTOR+0xeec,c.get('flagsEec',0));n.pack('<I',ACTOR+0x17c,c.get('heightBits',bits(17.25)));n.pack('<I',CL+0x2c,c.get('impulseBits',bits(-3.5)));n.pack('<I',0x802838,c.get('context',59)&0xffffffff);n.pack('<H',0x804bec,c.get('animation',65535));n.pack('<I',0x8020bc,0 if c.get('nullWorld')else WORLD)
 for slot,id in zip([0x158,0x15a,0x15c,0x15e,0x160,0x162,0x164],c.get('soundIds',[11,22,33,44,55,66,77])):n.pack('<h',WORLD+slot,id)
 return [dict(address=p,bytes=n.read(p,z).hex())for p,z in [(ACTOR,0x1100),(DEF,0x100),(CL,0x200),(WORLD,0x200),(0x802838,4),(0x804bec,2),(0x8020bc,4)]]
def execute(c,method='Enter'):
 global config,events,shadow,model_events
 config=c;events=[];initial=prepare(c);shadow={}
 for seg in initial:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 actor=0 if c.get('nullActor')else ACTOR;mode=c.get('mode',0)&0xffffffff;model_events=[];fault=None;wantfault=None
 try:(enter if method=='Enter'else sound)(actor,mode)
 except RuntimeError as e:wantfault=str(e)
 try:n.call(0x561ba0 if method=='Enter'else 0x547f30,[actor,mode])
 except RuntimeError as e:fault=str(e)
 got=n.read(ACTOR,0x1100).hex();want=bytes(rb(ACTOR+i)for i in range(0x1100)).hex();check('native-fault-parity-'+method,fault is not None,wantfault is not None,c);check('complete-actor-state-'+method,got,want,c);check('terminal-audio-ABI-'+method,events,model_events,c);cases.append(dict(method=method,context=c,actor=actor,mode=mode,initial=initial,nativeActor=got,nativeEvents=events,nativeFault=fault))
for mode,flags,player,soundIds in itertools.product([0,1,2,3,4,5,0xffffffff,0x10000003],[0,8,0x40,0x48],[(0,0),(0x80,0),(0,0x8000000)],[[-1]*7,list(range(11,18)),[-32768]*7,[32767]*7]):execute(dict(mode=mode,definitionFlags=flags,flags1fc=player[0],flagsEec=player[1],soundIds=soundIds),'Sound')
for context,mode,flags,player in itertools.product([-1,0,255,511,-2],[0,3,4,6,7,0x103,0x104,0x106,0x107,0xffffffff],[0,8,0x40],[False,True]):
 patches=[[ACTOR+0x7bc,0x12345678],[ACTOR+0xe20,0xffffffff],[CL+0x2c,bits(9.25)],[ACTOR+0x7aa,0x56781234]];execute(dict(context=context,mode=mode,definitionFlags=flags,flags1fc=0x80 if player else 0,patches={'PlayerSound':patches,'WorldSound':patches}))
for method,flag,ctx,mode in itertools.product(['Enter','Sound'],['nullActor','nullDef','nullClass','nullWorld'],[-1,59],[0,6,0x106,0xffffffff]):execute({flag:True,'context':ctx,'mode':mode},method)
for ctx,mode in itertools.product([0x80000000,0xfffffffe],[0x10000003,0x10000004,0xfffffff9]):execute(dict(context=ctx,mode=mode))
for height,impulse in itertools.product([0,0x80000000,1,0x80000001,bits(1.),bits(-1.)],[0,0x80000000,1,0x80000001,bits(1.),bits(-1.)]):execute(dict(heightBits=height,impulseBits=impulse,soundIds=[-1]*7))
for name in ['PlayerSound','WorldSound']:execute(dict(flags1fc=0x80 if name=='PlayerSound'else 0,patches={name:[[ACTOR+0x54,0]]}))
report=dict(binarySha256=n.sha256,nativeChecks=sum(checks.values()),checks=checks,mismatches=len(errors),errors=errors,cases=len(cases),adapters=['terminal audio681e90/681eb0 only; full router/context/reset unmodified'],limits=['Finite F32 height17c/class impulse2c; prepared runtime sound IDs and unchecked chains.'])
for suffix,obj in [('tests',report),('native-fixtures',dict(binarySha256=n.sha256,cases=cases)),('assembly',dict(binarySha256=n.sha256,functions=assembly,switchData=switchData))]:(native.BASE/'reports'/('script-phase10-20261013-'+suffix+'.json')).write_text(json.dumps(obj,indent=2))
print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
