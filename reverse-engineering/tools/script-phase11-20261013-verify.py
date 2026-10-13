"""Original jump-context561ba0/sound547f30/reset62e650. Only terminal audio adapters."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
spec=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();D=n.DATA;ACTOR=D+0x1000;VEHICLE=D+0x4000;DEF=D+0x8000;VDEF=D+0x8100;CL=D+0x9000;VCL=D+0x9200;WORLD=D+0xa000;INPUT=D+0xb000;ALTINPUT=D+0xc000;checks={};errors=[];cases=[];events=[];config={};shadow={};model_events=[]
cs=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,size in [(0x5a01f0,294),(0x561ba0,244),(0x547f30,210),(0x62e650,59),(0x54fa60,25),(0x5c0240,34)]:assembly.append(dict(address=hex(a),size=size,bytes=n.read(a,size).hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,size),a)]))
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
 name='PlayerSound'if a==0x681e90 else'WorldSound';count=2 if a==0x681e90 else 3;sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*count,sp+4));events.append(dict(name=name,args=args,observed=observe(args[1]-0x19c,False)))
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
 name='PlayerSound'if(rb(actor+0x1fc)&0x80)or(rd(actor+0xeec)&0x8000000)else'WorldSound';args=[id&0xffffffff,actor+0x19c]+([]if name=='PlayerSound'else[bits(.5)]);model_events.append(dict(name=name,args=args,observed=observe(actor,True)))
 for p,value in config.get('patches',{}).get(name,[]):wd(p,value)
def enter(actor,mode):
 context=rd(0x802838)
 if context!=0xffffffff:
  wb(actor+0x7b5,context);wb(actor+0x7b8,mode);animation=rw(0x804bec);wd(actor+0x77c,0);ww(actor+0x7aa,animation);flags=rd(actor+0x7bc);height=rd(actor+0x17c);wd(actor+0x78c,height);wd(actor+0x788,0);wb(actor+0x7b9,1);wd(actor+0x7bc,(flags&0xfffe6fff)|(0x10000 if mode in[3,4]else 0))
  if mode&255 not in[6,7]:sound(actor,0)
 definition=rd(actor+0x54);wb(actor+0x281,0);ww(actor+0x1050,0);typ=rd(definition+0x24);impulse=rd(typ+0x2c);wd(actor+0xe20,rd(actor+0xe20)|0x100000);wd(actor+0x6c,impulse);wd(actor+0xd48,0);wd(actor+0xd2c,0);wd(actor+0xd1c,0)
 p=actor+8;wd(p+4,bits(1));ww(p+0x3a,65535);wd(p+0x14,bits(1));ww(p+0x38,65535);wd(p,bits(1));ww(p+0x36,65535);wb(p+0x31,0);wb(p+0x30,4);ww(p+0x42,65535);wb(p+0x3e,0);wb(p+0x3c,0);wb(p+0x3d,0);ww(actor+0x278,0);ww(actor+0x27c,0);wb(actor+0x107a,2)

from fractions import Fraction
import math
CONSTANTS=[0x751700,0x7586e8,0x7531a8,0x751788,0x7598e8]
def frombits(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def frac(v):return Fraction(v)
def floorlog(f):
 n,d=f.numerator,f.denominator;e=n.bit_length()-d.bit_length()
 if (n<<(-e)if e<0 else n)<(d if e<0 else d<<e):e-=1
 return e
def power(e):return Fraction(1<<e)if e>=0 else Fraction(1,1<<-e)
def roundint(f):
 q,r=divmod(f.numerator,f.denominator);return q+int(r*2>f.denominator or(r*2==f.denominator and q&1))
def wide(f):
 if not f:return Fraction(0)
 neg=f<0;a=abs(f);e=floorlog(a)-63;q=roundint(a/power(e));return (-1 if neg else 1)*q*power(e)
def store(f,zeroSign=0):
 if not f:return zeroSign
 sign=0x80000000 if f<0 else 0;a=abs(f);e=floorlog(a)
 if e < -126:q=roundint(a/power(-149));return sign|q
 shift=e-23;q=roundint(a/power(shift))
 if q==1<<24:q>>=1;e+=1
 if e>127:return sign|0x7f800000
 return sign|((e+127)<<23)|(q&0x7fffff)
def ffrac(bits):return Fraction(frombits(bits))
def addbits(a,b):return store(wide(ffrac(a)+ffrac(b)),(a&b)&0x80000000)
def mulbits(a,b):return store(wide(ffrac(a)*ffrac(b)),(a^b)&0x80000000)
def observe(a,model):
 get=rd if model else lambda p:n.unpack('<I',p)[0];byte=rb if model else lambda p:n.unpack('<B',p)[0];word=rw if model else lambda p:n.unpack('<H',p)[0]
 return dict(velocityXBits=get(a+0x68),velocityZBits=get(a+0x70),rng=get(0x80253c),context=byte(a+0x7b5),animation=word(a+0x7aa),flags7bc=get(a+0x7bc),input=get(a+0xca4))
def draw():v=((rd(0x80253c)*0x24cd)+1)&65535;wd(0x80253c,v);return v
def double(p):return struct.unpack('<d',bytes(rb(p+i)for i in range(8)))[0]
def eject(actor,vehicle):
 angle=draw();draw2=draw();speed=wide(wide(frac(draw2)*frac(double(0x751700)))*frac(double(0x7586e8)));speedBits=store(wide(speed+frac(double(0x7531a8))));x=(angle>>1);z=((angle+0x4000)>>1)&0x7fff
 wd(actor+0x68,mulbits(rd(0x29899a0+x*4),speedBits));wd(actor+0x70,mulbits(speedBits,rd(0x29899a0+z*4)));enter(actor,0);wb(actor+0x7c5,rb(actor+0x7c5)|1);wd(actor+0x68,0);inp=rd(actor+0xca4);wd(actor+0x70,0);wd(actor+0xd1c,vehicle);wd(inp+4,0);wd(rd(actor+0xca4)+8,0)
 top=rd(vehicle+0x194);vdef=rd(vehicle+0x54);vtype=rd(vdef+0x24)
 if rd(vtype+0x94)&0x20000:top=addbits(rd(0x805714),top)
 definition=rd(actor+0x54);delta=addbits(top,rd(actor+0x1a0)^0x80000000);typ=rd(definition+0x24);delta=store(wide(ffrac(delta)+frac(double(0x751788))))
 if frombits(rd(typ+0x34))<frombits(delta):
  gravity=rd(typ+0x24);argument=store(wide(wide(ffrac(gravity)*frac(double(0x7598e8)))*ffrac(delta)),(gravity^delta^0x80000000)&0x80000000);f=frombits(argument);rootBits=bits(0. if f<0 else math.sqrt(f));wd(actor+0x6c,rootBits)
def prepare(c):
 n.write(D,bytes(0x10000));rng=random.Random(c.get('seed',17))
 for a in [ACTOR,VEHICLE]:n.write(a,bytes(rng.randrange(256)for _ in range(0x1100)))
 n.pack('<I',ACTOR+0x54,0 if c.get('nullRiderDef')else DEF);n.pack('<I',VEHICLE+0x54,0 if c.get('nullVehicleDef')else VDEF);n.pack('<I',DEF+0x24,CL);n.pack('<I',VDEF+0x24,VCL);n.pack('<I',DEF+4,c.get('definitionFlags',0));n.pack('<I',ACTOR+0x1fc,c.get('flags1fc',0));n.pack('<I',ACTOR+0xeec,c.get('flagsEec',0));n.pack('<I',ACTOR+0x17c,c.get('heightBits',bits(17.25)));n.pack('<I',CL+0x2c,c.get('impulseBits',bits(-3.5)));n.pack('<I',0x802838,c.get('context',59)&0xffffffff);n.pack('<H',0x804bec,c.get('animation',65535));n.pack('<I',0x8020bc,0 if c.get('nullWorld')else WORLD)
 for slot,id in zip([0x158,0x15a,0x15c,0x15e,0x160,0x162,0x164],c.get('soundIds',[11,22,33,44,55,66,77])):n.pack('<h',WORLD+slot,id)
 n.pack('<I',ACTOR+0xca4,0 if c.get('nullInput')else ACTOR+0xca0 if c.get('aliasInput')else INPUT);n.write(INPUT,b'\xab'*0x100);n.write(ALTINPUT,b'\xcd'*0x100);n.pack('<I',ACTOR+0x1a0,c.get('bottomBits',bits(1.25)));n.pack('<I',VEHICLE+0x194,c.get('topBits',bits(3.)));n.pack('<I',VCL+0x94,c.get('vehicleFlags',0));n.pack('<I',0x805714,c.get('offsetBits',bits(2.5)));n.pack('<I',CL+0x24,c.get('gravityBits',bits(-9.75)));n.pack('<I',CL+0x34,c.get('thresholdBits',bits(-1.)));n.pack('<I',0x80253c,c.get('rng',1)&0xffffffff)
 state=c.get('rng',1)&0xffffffff;sines={}
 for i in range(c.get('calls',1)):
  angle=((state*0x24cd)+1)&65535;state=((angle*0x24cd)+1)&65535
  for index,value in [((angle>>1),c.get('sineXBits',bits(.7071067690849304))),((((angle+0x4000)>>1)&0x7fff),c.get('sineZBits',bits(-.7071067690849304)))]:sines[0x29899a0+index*4]=value
 for p,value in sines.items():n.pack('<I',p,value)
 segs=[(ACTOR,0x1100),(VEHICLE,0x1100),(DEF,0x200),(CL,0x400),(WORLD,0x200),(INPUT,0x100),(ALTINPUT,0x100),(0x802838,4),(0x804bec,2),(0x8020bc,4),(0x80253c,4),(0x805714,4)]+[(p,8)for p in CONSTANTS]+[(p,4)for p in sines]
 return [dict(address=p,bytes=n.read(p,z).hex())for p,z in segs]
def execute(c):
 global config,events,shadow,model_events
 config=c;events=[];initial=prepare(c);shadow={}
 for seg in initial:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 actor=0 if c.get('nullActor')else ACTOR;vehicle=0 if c.get('nullVehicle')else VEHICLE;model_events=[];fault=None;wantfault=None
 for i in range(c.get('calls',1)):
  try:eject(actor,vehicle)
  except RuntimeError as e:wantfault=str(e);break
 for i in range(c.get('calls',1)):
  try:n.call(0x5a01f0,[actor,vehicle])
  except RuntimeError as e:fault=str(e);break
 ranges=[(ACTOR,0x1100),(VEHICLE,0x1100),(INPUT,0x100),(ALTINPUT,0x100),(CL,0x400),(0x80253c,4)]
 got=[n.read(p,z).hex()for p,z in ranges];want=[bytes(rb(p+i)for i in range(z)).hex()for p,z in ranges];check('ejection-native-fault-parity',fault is not None,wantfault is not None,c);check('ejection-complete-state',got,want,c);check('audio-ABI-temporary-velocity-rng',events,model_events,c);cases.append(dict(context=c,rider=actor,vehicle=vehicle,calls=c.get('calls',1),initial=initial,nativeState=got,nativeEvents=events,nativeFault=fault))
# RNG extremes and exact intermediate observation before temporary velocities vanish.
for state,sx,sz,context,player in itertools.product([0,1,2,65535,0xffffffff],[0,0x80000000,1,bits(.75),bits(-.5)],[bits(1.),bits(-1.),0x80000000],[-1,59],[False,True]):execute(dict(rng=state,sineXBits=sx,sineZBits=sz,context=context,flags1fc=0x80 if player else 0))
# Stored-F32 height boundaries, offset class branch, sqrt clamp and threshold ordering.
for top,bottom,offset,gravity,threshold in itertools.product([bits(3.),bits(-3.),0,0x80000000],[bits(1.25),bits(-.1),0,0x80000000],[False,True],[bits(-9.75),bits(9.75),0,0x80000000],[bits(-1.),bits(10.),0x7fc12345]):execute(dict(topBits=top,bottomBits=bottom,vehicleFlags=0x20000 if offset else 0,gravityBits=gravity,thresholdBits=threshold,soundIds=[-1]*7))
for flags in ['nullActor','nullVehicle','nullInput','aliasInput','nullRiderDef','nullVehicleDef','nullWorld']:execute({flags:True})
for callbacks in ['PlayerSound','WorldSound']:
 patches=[[ACTOR+0xca4,ALTINPUT],[ACTOR+0x1a0,bits(-7.)],[VEHICLE+0x194,bits(13.)],[CL+0x24,bits(-2.)],[CL+0x34,bits(3.)],[0x80253c,0x12345678]];execute(dict(flags1fc=0x80 if callbacks=='PlayerSound'else 0,patches={callbacks:patches}))
for state in [0,1,0x80000000,0xffffffff]:execute(dict(rng=state,calls=3))

# Exhaustive original instruction prefix: two QRAND calls and speed FSTP at5a0233.
# Stops before any actor/sine reads. Compact meaningful fixtures retain each result.
prefixNative=native.NativeX86()
speed_cases=[]
for initialState in range(65536):
 prefixNative.mu.context_restore(prefixNative.context);sp=prefixNative.STACK+0xe000;prefixNative.pack('<III',sp,n.STOP,ACTOR,VEHICLE);prefixNative.mu.reg_write(UC_X86_REG_ESP,sp);prefixNative.pack('<I',0x80253c,initialState);prefixNative.mu.emu_start(0x5a01f0,0x5a0237,count=100)
 check('exhaustive-original-prefix-stop',prefixNative.mu.reg_read(UC_X86_REG_EIP),0x5a0237,initialState);activeSp=prefixNative.mu.reg_read(UC_X86_REG_ESP);speedBits=prefixNative.unpack('<I',activeSp+0xc)[0];draw1=((initialState*0x24cd)+1)&65535;draw2=((draw1*0x24cd)+1)&65535;value=wide(wide(frac(draw2)*frac(prefixNative.unpack('<d',0x751700)[0]))*frac(prefixNative.unpack('<d',0x7586e8)[0]));want=store(wide(value+frac(prefixNative.unpack('<d',0x7531a8)[0])))
 check('exhaustive-original-prefix-speed',speedBits,want,initialState);check('exhaustive-original-prefix-state',prefixNative.unpack('<I',0x80253c)[0],draw2,initialState);speed_cases.append(dict(inputState=initialState,firstDraw=draw1,speedDraw=draw2,nativeSpeedBits=speedBits))
speed_initial=[dict(address=p,bytes=prefixNative.read(p,8).hex())for p in CONSTANTS[:3]]

report=dict(binarySha256=n.sha256,nativeChecks=sum(checks.values()),checks=checks,mismatches=len(errors),errors=errors,cases=len(cases),exhaustiveSpeedCases=len(speed_cases),adapters=['terminal audio681e90/681eb0 only'],limits=['Prepared finite F32 arithmetic operands/intermediates and sine entries; class threshold quietNaN/ordered values tested.','Original5a01f0,QRAND,context/sound/reset andsqrt execute. No game/platform APIs.'])
for suffix,obj in [('tests',report),('native-fixtures',dict(binarySha256=n.sha256,cases=cases,speedCases=speed_cases,speedInitial=speed_initial)),('assembly',dict(binarySha256=n.sha256,functions=assembly,switchData=switchData,constants=[dict(address=hex(p),bytes=n.read(p,8).hex(),double=n.unpack('<d',p)[0])for p in CONSTANTS]))]:(native.BASE/'reports'/('script-phase11-20261013-'+suffix+'.json')).write_text(json.dumps(obj,indent=2))
print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
