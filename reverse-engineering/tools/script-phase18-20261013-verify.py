"""Original vehicle response/action finish/timing joined to recovered takeover pipeline."""
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
def sound(actor,mode):
 flags=rd(rd(actor+0x54)+4)
 if flags&0x40:slot=0x15a
 elif not flags&8:slot=0x158
 else:
  if mode>4:return
  slot=[0x15c,0x15e,0x164,0x160,0x162][mode]
 id=rw(rd(0x8020bc)+slot);id=id-65536 if id>=32768 else id
 if id==-1:return
 name='PlayerSound'if(rb(actor+0x1fc)&0x80)or(rd(actor+0xeec)&0x8000000)else'WorldSound';args=[id&0xffffffff,actor+0x19c]+([]if name=='PlayerSound'else[bits(.5)]);service(name,args)
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
def unused_audio_observe(a,model):
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

fl=frombits
def f32(value):return frombits(bits(value))
A=ACTOR;B=VEHICLE;SYS=D+0x50000
def seat(actor,out):
 cl=rd(rd(actor+0x54)+0x24);s=rb(cl+0x113);s=s-256 if s>=128 else s
 if s!=-1 and rd(rd(actor+0x50)+0x14+s*4):p=actor+0x834+s*0x40;wd(out,rd(p));wd(out+4,rd(p+4));wd(out+8,rd(p+8))
 else:wd(out,rd(actor+0x5c));wd(out+4,rd(actor+0x194));wd(out+8,rd(actor+0x64))

def transfer_model(source,target,camera):
 if rd(0x951c5c):return 0
 da8=rd(source+0xda8);isrc=rd(source+0xca4);itgt=rd(target+0xca4);rb(target+0x107f);ft=rd(target+0x1fc);rb(source+0x107f);fs=rd(source+0x1fc);ss=bytes(rb(source+0x2c8+i)for i in range(0xcc));st=bytes(rb(target+0x2c8+i)for i in range(0xcc))
 for a in [source,target]:
  for off in [0xd80,0xd84,0xd14,0xd90,0xd18]:wd(a+off,0)
  wd(a+0xd88,0x3e4ccccd)
 wd(target+0xca4,isrc);wd(source+0xca4,itgt);wd(source+0x1fc,(rd(source+0x1fc)&~0x80)|(ft&0x80));wd(target+0x1fc,(rd(target+0x1fc)&~0x80)|(fs&0x80));wd(source+0xda8,rd(target+0xda8));wd(target+0xda8,da8)
 for off in [0x7fc,0x280,0xdec,0x800]:
  size=1 if off==0x280 else 4;v=bytes(rb(source+off+i)for i in range(size));w=bytes(rb(target+off+i)for i in range(size))
  for i,x in enumerate(w):wb(source+off+i,x)
  for i,x in enumerate(v):wb(target+off+i,x)
 for a in [source,target]:
  aux=rd(a+0x800)
  if aux:
   for i in range(0x630):wb(aux+i,0)
 old=rd(source+0x1f8);mask=0x146fd;unmasked=old&~mask;wd(source+0x1f8,unmasked);wd(source+0x1f8,unmasked|(rd(target+0x1f8)&mask));wd(target+0x1f8,(rd(target+0x1f8)&~mask)|(old&mask))
 for off in [0xea8,0x1000]:v=rd(source+off);wd(source+off,rd(target+off));wd(target+off,v)
 service('Rebind',[source])
 for a in [source,target]:
  index=rb(a+0x280);index=index-256 if index>=128 else index
  if index!=-1:wd(0x93d7f0+index*4,a)
 wd(target+0xef0,rd(target+0xef0)&0xffe7ffff);wd(target+0xee4,0);wd(target+0xee8,0);wd(target+0x7c0,bits(1.))
 if source==rd(0x87a7c8)and target!=rd(0x87a7cc):
  for p in [0x87a7d0,0x87a7c8,0x87a7cc,0x87a7d4]:wd(p,0)
 packet=target+0x2c8
 if service('ChangeTakenOverState',[packet,0x759958]):service('RunScript',[rd(rd(0x802c54)+0x2ae8),target,packet,packet,rd(0x925018)])
 for i,x in enumerate(st):wb(source+0x2c8+i,x)
 for i,x in enumerate(ss):wb(target+0x2c8+i,x)
 wb(source+0x378,ss[0xb0]);wb(target+0x378,st[0xb0]);service('Rebind',[source]);wd(source+0x1fc,(rd(source+0x1fc)&~0x100)|(ft&0x100));wd(target+0x1fc,(rd(target+0x1fc)&~0x100)|(fs&0x100));service('ClearAction',[source,0]);service('ResetActor',[source,0]);service('StopActor',[source]);service('ResetAnimation',[source+0x6c4])
 if not rb(source+0xeec)&0x10:service('PrepareActor',[source])
 wd(source+0xcd0,target);wd(target+0xcd0,source);wd(source+0xea4,0);wd(target+0xea4,0);wd(source+0xcd4,target);wb(source+0x7b5,59);service('SelectTakeoverAnimation',[rd(source+0xcd0),source]);wd(source+0xdd0,bits(1.))
 for off in [0,4,8]:wd(source+0x748+off,rd(source+0x5c+off))
 if camera:service('Camera',[rd(0x8021b4),bits(.5),0,1])
 cl=rd(rd(target+0x54)+0x24)
 if fl(rd(cl+0x28))>0:wd(target+0x6c,bits(f32(fl(rd(target+0x6c))-fl(rd(rd(rd(source+0x54)+0x24)+0x2c))*.5)))
 return 1

def release_model(inp):
 link=rd(inp+0xcd0)
 if not link:return
 a,b=(inp,link)if rb(inp+0x7b5)==59 else(link,inp)
 sa=bytes(rb(a+0x2c8+i)for i in range(0xcc));sb=bytes(rb(b+0x2c8+i)for i in range(0xcc));fa=rd(a+0x1fc);fb=rd(b+0x1fc)
 if not rb(a+0xef4)&2 and service('Transfer',[a,b,1,0,0])==0:return
 rd(rd(b+0x54)+0xc);rd(rd(a+0x54)+0xc)
 for i,x in enumerate(sb):wb(a+0x2c8+i,x)
 for i,x in enumerate(sa):wb(b+0x2c8+i,x)
 wb(a+0x378,sa[0xb0]);wb(b+0x378,sb[0xb0]);service('Rebind',[b]);wd(a+0x1fc,(rd(a+0x1fc)&~0x100)|(fb&0x100));wd(b+0x1fc,(rd(b+0x1fc)&~0x100)|(fa&0x100))
 link=rd(a+0xcd0)
 if link:
  seat(link,a+0x5c);link=rd(a+0xcd0);ww(a+0x278,0);ww(a+0x27c,0);ww(a+0x27a,rw(link+0x58));ww(a+0x58,rw(link+0x58));ww(a+0x5a,rw(link+0x58))
 service('RefreshPose',[a]);wd(a+0xcd0,0);wb(a+0x7b5,255)
 if rw(b+0x1064)==rw(0x7f1914) and rd(rd(0x802c54)+0x128)==rd(0x87b234):
  service('DistanceFactor',[a+0x5c,0x7fa574]);factor=fl(config.get('factorBits',bits(.375)));duration=bits(f32(factor*fl(rd(0x7fa570))));speed=bits(f32(factor*fl(rd(0x7fa56c))));service('DirectedJump',[a,0x7fa574,0,speed,duration,0]);service('Camera',[rd(0x8021b4),bits(2),0,1])
 else:service('Eject',[a,b])
 cl=rd(rd(b+0x54)+0x24)
 if fl(rd(cl+0x28))>0:wd(b+0x6c,bits(f32(fl(rd(b+0x6c))-fl(rd(a+0x6c))*.5)))
 elif rd(cl+0x94)&0x20000:service('VehicleResponse',[b,a])
 wd(b+0xcd0,0);wd(a+0xe20,rd(a+0xe20)&0x7fffffff);wd(b+0xe20,rd(b+0xe20)&0x7fffffff);ww(a+0x42e,rw(a+0x42e)&0xfffe)
 for off in [0,4,8]:wd(b+0x10bc+off,rd(b+0x5c+off))
 if rb(a+0x280)!=255 or rb(b+0x280)!=255:service('Camera',[rd(0x8021b4),bits(.3),0,1])
 for actor in [a,b]:
  p=actor+0x2c8
  if service('ChangeReleasedState',[p,0x759978]):service('RunScript',[rd(rd(0x802c54)+0x2ae8),actor,p,p,rd(0x925018)])

MODEL_A=D+0xd000;MODEL_B=D+0xd100;CLIPS_A=D+0x18000;CLIPS_B=D+0x19000;AUX_A=D+0x20000;AUX_B=D+0x21000;INFO=D+0x60000;ALT=D+0xf000
old=BASIS_PATH=Path(__file__).with_name('animation-character-bounds-verify.py');bounds={'__file__':str(old)};exec(old.read_text().split('for i in range(1200):')[0],bounds);bound_model=bounds['model']
port_sites={0x52c880:('Conditions',4),0x52caf0:('References',2),0x53db30:('Animation',2),0x10200500:('Scratch',3),0x10200600:('Command',7),0x698900:('ControllerRequest',5),0x10200400:('Notify',1),0x4c99b0:('DistanceFactor',2),0x561e20:('DirectedJump',6),0x681e90:('PlayerSound',2),0x681eb0:('WorldSound',3)}
actual_entries={0x415000:'Rebind',0x52cc90:'Dispatcher',0x5a03d0:'VehicleTimer',0x52c790:'ChangeBaseState',0x512fc0:'FindState',0x5145a0:'EnterState',0x514640:'BindState',0x514550:'AdvanceAction',0x4f1440:'ListHead',0x4f1460:'ListNext',0x4f8b10:'CompareName',0x54a3e0:'Camera',0x54a850:'Feedback',0x54a8a0:'ForwardFeedback',0x6e6b90:'Convert',0x6e6b99:'SSEConversion',0x6e6bc6:'LegacyConversion',0x4a1f50:'FinishAction',0x5a0320:'VehicleResponse',0x62e040:'Duration',0x5ca470:'EndFrame',0x4a25b0:'ClearAction',0x58ff10:'ResetActor',0x59cb00:'StopActor',0x55e4e0:'ResetControls',0x58d8e0:'PrepareActor',0x4882d0:'Release',0x4876a0:'Transfer',0x487270:'Selector',0x4871a0:'Seat',0x55d2b0:'Bounds',0x5a01f0:'Eject',0x561ba0:'Context',0x547f30:'SoundRouter',0x62e650:'ResetPacket',0x54fa60:'QRAND',0x5c0240:'SquareRoot'}
occurrences={};native_trace=[]
def peek(model):
 get=rd if model else lambda p:n.unpack('<I',p)[0];byte=rb if model else lambda p:n.unpack('<B',p)[0];word=rw if model else lambda p:n.unpack('<H',p)[0]
 return dict(rng=get(0x80253c),actors=[dict(link=get(a+0xcd0),context=byte(a+0x7b5),animation=word(a+0x7aa),flags1fc=get(a+0x1fc),flags1f8=get(a+0x1f8),packetWord=get(a+0x2c8),set=byte(a+0x378),xBits=get(a+0x5c),yBits=get(a+0x60),zBits=get(a+0x64),velocityXBits=get(a+0x68),velocityYBits=get(a+0x6c),velocityZBits=get(a+0x70),bottomBits=get(a+0x1a0),input=get(a+0xca4))for a in [A,B]])
def patches(name,ordinal):return config.get('patches',{}).get(name,[])+config.get('patches',{}).get(name+'#'+str(ordinal),[])
def port_hook(mu,address,size,data):
 if address in actual_entries:native_trace.append(actual_entries[address])
 if address not in port_sites:return
 name,count=port_sites[address];sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*count,sp+4))
 if name in ['Notify','Scratch','Command']:args=[address]+args
 if name=='Conditions':args=[mu.reg_read(UC_X86_REG_EAX)]+args
 if name=='ChangeState':name='ChangeReleasedState'if args[1]==0x759978 else'ChangeTakenOverState'
 occurrences[name]=occurrences.get(name,0)+1;events.append(dict(name=name,args=args,observed=peek(False)))
 for p,value in patches(name,occurrences[name]):n.pack('<I',p,value)
 if name=='DistanceFactor':
  n.pack('<I',ALT+0x800,config.get('factorBits',bits(.375)));n.write(n.STOP+0x100,b'\xd9\x05'+struct.pack('<I',ALT+0x800)+b'\xc3');mu.reg_write(UC_X86_REG_EIP,n.STOP+0x100);return
 result=port_result(name,args,occurrences[name]);mu.reg_write(UC_X86_REG_EAX,result&0xffffffff);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,port_hook)
def service(name,args):
 if name=='Rebind':rebind(args[0]);return 0
 if name=='Command'and args[0]!=n.STOP+0x600:raise RuntimeError('unmapped prepared command callback')
 if name=='Scratch'and args[0]!=n.STOP+0x500:raise RuntimeError('unmapped prepared scratch callback')
 if name=='RunScript':dispatch(args[0],args[2],args[3],args[4]);return 0
 if name in ['ChangeTakenOverState','ChangeReleasedState']:return change_base(args[0],args[1])
 if name=='Camera':camera(args[0],args[1],args[2],args[3]);return 0
 if name=='Feedback':feedback(args[0],args[1]);return 0
 if name=='FinishAction':finish_action(args[0]);return 0
 if name=='VehicleResponse':vehicle_response(args[0],args[1]);return 0
 if name=='ClearAction':clear_action(args[0],args[1]);return 0
 if name=='ResetActor':reset_actor(args[0],args[1]);return 0
 if name=='StopActor':stop_actor(args[0]);return 0
 if name=='ResetAnimation':reset_controls(args[0]);return 0
 if name=='PrepareActor':prepare_actor(args[0]);return 0
 if name=='Transfer':return transfer_model(args[0],args[1],bool(args[3]))
 if name=='SelectTakeoverAnimation':selector(args[0],args[1]);return 0
 if name=='RefreshPose':refresh(args[0]);return 0
 if name=='Eject':eject(args[0],args[1]);return 0
 model_occurrences[name]=model_occurrences.get(name,0)+1;model_events.append(dict(name=name,args=args,observed=peek(True)))
 for p,value in patches(name,model_occurrences[name]):wd(p,value)
 return port_result(name,args,model_occurrences[name])
def selector(vehicle,rider):
 ids=[0x7f1814,0x7f1850,0x7f1934,0x7f1938,0x7f193c,0x7f1940,0x7f1aa4,0x7f1944,0x7f1948,0x7f194c,0x7f1950,0x7f1954,0x7f19bc,0x7f1920];values=[rw(p)for p in ids];t=rw(vehicle+0x1064)
 if t==values[0]:action=0x70
 elif t==values[1]:action=0x83
 elif not rd(0x7f39e4):ww(rider+0x7aa,0x6c);return
 elif rb(rd(rd(vehicle+0x54)+0x24)+0x116)==12:action=0xc4 if rw(vehicle+8+(0x34 if rb(vehicle+8+0x31)else 0x36))in[3,23]else 0xc3
 elif t in values[2:4]:action=0x70
 elif t==values[4]:action=0x83
 elif t in values[5:7]:action=0x84
 elif t==values[7]:action=0x86
 elif t==values[8]:action=0xc0
 elif t in values[9:11]:action=0xc1
 elif t==values[11]:action=0xc2 if rd(rd(rd(rider+0x50)+0xc)+0x308)else 0xc1
 elif t==values[12]:action=0xc1
 elif t==values[13]:action=0xc0
 else:ww(rider+0x7aa,0x6c);return
 clips=rd(rd(rider+0x50)+0xc);ww(rider+0x7aa,action if rd(clips+action*4)else 0x6c)
def refresh(actor):
 wd(actor+0x1f8,rd(actor+0x1f8)|0x100);e=dict(dt=rd(0x925018),primary=-1,fallback=-1,enabled=[0]*16,contextFlags=0)
 if rb(actor+0x1079):
  typ=rd(rd(actor+0x54)+0x24);index=rb(typ+0x10f);e['primary']=index-256 if index>=128 else index;modelPtr=rd(actor+0x50);primary=False
  if e['primary']!=-1 and modelPtr:e['enabled'][e['primary']]=rd(modelPtr+0x14+e['primary']*4);primary=bool(e['enabled'][e['primary']])
  if not primary and frombits(rd(actor+0xd30))==1:
   index=rb(typ+0x10d);e['fallback']=index-256 if index>=128 else index
   if e['fallback']!=-1:e['enabled'][e['fallback']]=rd(modelPtr+0x14+e['fallback']*4)
 before=bytes(rb(actor+i)for i in range(0x10d8));dummy=bytearray(before)
 for p in [0xd7c,0x21c,0xb4]:struct.pack_into('<I',dummy,p,0)
 pre,_,_=bound_model(dummy,e)
 for p in [0xd7c,0x21c,0xb4]:pre[p:p+4]=before[p:p+4]
 pre[0x414:0x420]=pre[0x1a8:0x1b4]
 for i,x in enumerate(pre):wb(actor+i,x)
 context=rb(actor+0x7b5);context=context-256 if context>=128 else context;e['contextFlags']=rd((rd(0x7fb0e4)+context*16+8)&0xffffffff);final,_,_=bound_model(before,e)
 for i,x in enumerate(final):wb(actor+i,x)
def prepare(c):
 n.write(D,bytes(0x70000));rng=random.Random(c.get('seed',113))
 for a,df,cl,mo,clips,aux,inputp in [(A,DEF,CL,MODEL_A,CLIPS_A,AUX_A,INPUT),(B,VDEF,VCL,MODEL_B,CLIPS_B,AUX_B,ALTINPUT)]:
  n.write(a,bytes(rng.randrange(256)for _ in range(0x1100)));n.pack('<I',a+0x54,df);n.pack('<I',df+0xc,D+0x17000);n.pack('<I',df+0x24,cl);n.pack('<I',df+4,c.get('definitionFlags',0));n.pack('<I',a+0x50,mo);n.pack('<I',mo+0xc,clips);n.pack('<16I',mo+0x14,*([1]*16));
  if c.get('primaryDisabled')and c.get('primary',0)!=-1:n.pack('<I',mo+0x14+c.get('primary',0)*4,0)
  n.pack('<I',a+0x800,aux if not c.get('nullAux')else 0);n.pack('<I',a+0xca4,inputp);n.write(inputp,b'\xab'*0x100);n.write(aux,b'\xcd'*0x630)
  for field,value in {0xda8:3.125,0xdec:-.5,0x1000:1.0,0x17c:3.,0x194:4.,0x1a0:1.,0x74:.125,0x78:.25,0x7c:-.125,0xa8:1.25,0xff0:.5,0xff4:1.5,0x1dc:.375,0x1e0:.5,0xd7c:.25,0x21c:1.,0xb4:.5,0xd30:1.,0x6c:2.5}.items():n.pack('<f',a+field,value)
  n.pack('<3f',a+0x5c,1.5 if a==A else-3.,2.25 if a==A else 4.,-2.5);n.pack('<16f',a+0xb8,*[float(i%5==0)for i in range(16)])
  for slot in range(16):n.pack('<16f',a+0x804+slot*64,*[float(i%5==0)for i in range(12)],1.+slot*.25,2.+slot*.5,-3.-slot*.125,1.)
  n.pack('<B',cl+0x10f,c.get('primary',0)&255);n.pack('<B',cl+0x10d,c.get('fallback',1)&255);n.pack('<B',cl+0x113,c.get('seat',-1)&255);n.pack('<B',cl+0x116,c.get('subtype',0));n.pack('<f',cl+0x24,c.get('gravity',-9.75));n.pack('<f',cl+0x2c,c.get('impulse',2.5));n.pack('<f',cl+0x34,c.get('threshold',-1.));n.pack('<f',cl+0x28,c.get('classFloat',1.));n.pack('<I',cl+0x94,c.get('classFlags',0));n.pack('<I',a+0xeec,c.get('flagsEec',0));n.pack('<I',a+0x1fc,c.get('flagsA'if a==A else'flagsB',0x101 if a==A else 0x80000080));n.pack('<I',a+0x1f8,0xaabbccdd if a==A else 0x11223344);n.pack('<B',a+0x1079,int(c.get('pose',True)));n.pack('<B',a+0x28c,c.get('fallbackGate',1));n.pack('<B',a+0xe24,c.get('poseBit8',8));n.pack('<B',a+0xef4,2 if c.get('skipTransfer')else 0);n.pack('<B',a+0x280,c.get('personalA'if a==A else'personalB',0 if a==A else 1)&255);n.pack('<H',a+0x1064,c.get('type',111)&65535);n.pack('<H',a+0x58,0x2345 if a==A else 0xabcd);n.pack('<B',a+8+0x31,1);n.pack('<hh',a+8+0x34,c.get('action',3),-1)
  for action in [0x70,0x83,0x84,0x86,0xc0,0xc1,0xc2,0xc3,0xc4]:n.pack('<I',clips+action*4,0 if c.get('missingClips')else 1)
 n.pack('<I',A+0xcd0,B);n.pack('<I',B+0xcd0,A);n.pack('<B',A+0x7b5,c.get('contextA',59)&255);n.pack('<B',B+0x7b5,c.get('contextB',0)&255);n.pack('<I',0x802c54,SYS);n.pack('<I',SYS+0x128,123);n.pack('<I',SYS+0x2ae8,D+0x55000);n.pack('<I',0x87b234,123);n.pack('<I',0x8021b4,D+0x57000);n.pack('<I',0x951c5c,int(c.get('blocked',False)));n.pack('<H',0x7f1914,c.get('type',111)if c.get('special')else 65535);n.pack('<2f',0x7fa56c,11.25,2.75);n.pack('<I',0x7fb0e4,0 if c.get('nullRegistry')else INFO);n.pack('<I',0x925018,bits(c.get('dt',.016)));n.pack('<I',0x802838,c.get('ejectionContext',77)&0xffffffff);n.pack('<H',0x804bec,0x1234);n.pack('<I',0x8020bc,WORLD);n.pack('<f',0x805714,2.5);n.pack('<I',0x80253c,c.get('rng',1)&0xffffffff);n.pack('<I',0x7f39e4,1);n.write(0x93d5f0,b'\xee'*0x400);n.pack('<4I',0x87a7c8,A,A,0x12345678,0x87654321)
 ids=[0x7f1814,0x7f1850,0x7f1934,0x7f1938,0x7f193c,0x7f1940,0x7f1aa4,0x7f1944,0x7f1948,0x7f194c,0x7f1950,0x7f1954,0x7f19bc,0x7f1920]
 for p,value in zip(ids,range(100,114)):n.pack('<H',p,value)
 for row in range(-128,128):n.pack('<I',INFO+row*16+8,c.get('contextFlags',0))
 for slot,value in zip([0x158,0x15a,0x15c,0x15e,0x160,0x162,0x164],c.get('soundIds',[11,22,33,44,55,66,77])):n.pack('<h',WORLD+slot,value)
 inputActor=B if c.get('inputB')else A
 if c.get('selfLink'):n.pack('<I',inputActor+0xcd0,inputActor)
 if c.get('noLink'):n.pack('<I',inputActor+0xcd0,0)
 if c.get('nullInput'):n.pack('<I',A+0xca4,0);n.pack('<I',B+0xca4,0)
 if c.get('aliasInput'):n.pack('<I',A+0xca4,A+0xca0);n.pack('<I',B+0xca4,B+0xca0)
 if c.get('nullDef'):n.pack('<I',B+0x54,0)
 if c.get('nullModel'):n.pack('<I',A+0x50,0);n.pack('<I',B+0x50,0)
 if c.get('contextAliasField')is not None:n.pack('<I',0x7fb0e4,(A+c['contextAliasField']-59*16-8)&0xffffffff)
 states={c.get('rng',1)&0xffffffff}
 for rows in c.get('patches',{}).values():
  for p,value in rows:
   if p==0x80253c:states.add(value&0xffffffff)
 sine={}
 for state in states:
  for call in range(c.get('calls',1)*3+8):
   state=((state*0x24cd)+1)&65535;angle=state
   for index in [angle>>1,((angle+0x4000)>>1)&0x7fff]:sine[0x29899a0+index*4]=[0,0x80000000,bits(.75),bits(-.5)][index%4]
 for p,value in sine.items():n.pack('<I',p,value)
 n.pack('<4I',0x802854,c.get('cameraStopContext',0xffffffff)&0xffffffff,0,0,c.get('cameraResetContext',0xffffffff)&0xffffffff);n.pack('<2I',0x802864,c.get('prepareContextA',0xffffffff)&0xffffffff,c.get('prepareContextB',0xffffffff)&0xffffffff);n.pack('<f',0x7fb084,c.get('gizmoTimer',1.5));n.pack('<I',A+0x790,B if c.get('linkedAction')else 0);n.pack('<I',B+0x790,A if c.get('linkedAction')else 0);n.pack('<I',A+0xcb8,D+0x30000 if c.get('gizmoAction')else 0);n.pack('<I',B+0xcb8,D+0x31000 if c.get('gizmoAction')else 0);n.pack('<B',D+0x30206,c.get('gizmoMask',255));n.pack('<B',D+0x31206,c.get('gizmoMask',255));n.pack('<H',INPUT+0x5a,65535);n.pack('<H',ALTINPUT+0x5a,65535)
 if c.get('gizmoPointerAlias'):n.pack('<I',A+0xcb8,A+0xcb8+1-0x206)
 if c.get('selfActionLink'):n.pack('<I',A+0x790,A)
 if c.get('badActionLink'):n.pack('<I',A+0x790,0x10300000)
 if c.get('padPointerAlias'):n.pack('<I',A+0xca4,A+0xca4+1-0x5a);n.pack('<I',B+0xca4,B+0xca4+1-0x5a)
 segs=[(0x802854,24),(0x7fb084,4),(D+0x30000,0x1300),(A,0x1100),(B,0x1100),(DEF,0x200),(CL,0x400),(WORLD,0x200),(INPUT,0x100),(ALTINPUT,0x100),(ALT,0x100),(MODEL_A,0x200),(CLIPS_A,0x1400),(AUX_A,0x1630),(SYS,0x2af0),(INFO-0x800,0x1000),(0x802c54,4),(0x87b234,4),(0x8021b4,4),(0x951c5c,4),(0x7f1914,2),(0x7fa56c,8),(0x7fb0e4,4),(0x925018,4),(0x802838,4),(0x804bec,2),(0x8020bc,4),(0x805714,4),(0x80253c,4),(0x7f39e4,4),(0x93d5f0,0x400),(0x87a7c8,16),(0x7f1800,0x300)]+[(p,8)for p in CONSTANTS]+[(p,4)for p in sine]
 return [dict(address=p,bytes=n.read(p,z).hex())for p,z in segs]
def execute(c):
 global config,events,shadow,model_events,model_occurrences,occurrences,native_trace
 config=c;events=[];occurrences={};native_trace=[];initial=prepare(c);shadow={}
 for seg in initial:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 inputActor=0 if c.get('nullActor')else B if c.get('inputB')else A;model_events=[];model_occurrences={};fault=None;wantfault=None
 for call in range(c.get('calls',1)):
  try:release_model(inputActor)
  except RuntimeError as exc:wantfault=str(exc);break
 for call in range(c.get('calls',1)):
  try:n.call(0x4882d0,[inputActor])
  except RuntimeError as exc:fault=str(exc);break
 ranges=[(A,0x1100),(B,0x1100),(INPUT,0x100),(ALTINPUT,0x100),(ALT,0x100),(CL,0x400),(AUX_A,0x1630),(0x93d5f0,0x400),(0x87a7c8,16),(0x80253c,4),(D+0x30000,0x1300),(0x29a99a4,4),(CAM,0x240),(PART,0x1000)]
 got=[n.read(p,z).hex()for p,z in ranges];want=[bytes(rb(p+i)for i in range(z)).hex()for p,z in ranges];check('pipeline-native-fault-state',fault is not None,wantfault is not None,c);check('pipeline-complete-prepared-state',got,want,c);check('pipeline-callback-alias-order',events,model_events,c);cases.append(dict(context=c,input=inputActor,calls=c.get('calls',1),initial=initial,nativeState=got,nativeEvents=events,nativeFault=fault,nativeTrace=native_trace.copy()))


def signed32(v):return v-0x100000000 if v>=0x80000000 else v
def signed_context(actor):v=rb(actor+0x7b5);return v-256 if v>=128 else v
def clear_action(actor,mode):
 context=signed_context(actor)
 if context==8:
  if rb(actor+0x1fc)&0x80:service('Camera',[rd(0x8021b4),bits(1),0,1])
  service('FinishAction',[actor,mode])
 elif context==27:
  linked=rd(actor+0x790)
  if linked:
   if rb(linked+0x7b5)==28:wb(linked+0x7b5,255);wd(linked+0x790,0)
   wd(actor+0x790,0)
  service('FinishAction',[actor,mode])
 elif context==29:
  gizmo=rd(actor+0xcb8)
  if gizmo:
   shift=rb(actor+0x280)&31;wb(gizmo+0x206,rb(gizmo+0x206)&~((1<<shift)&255));gizmo=rd(actor+0xcb8)
   if rb(gizmo+0x206)==0:wb(gizmo+0x206,255)
   gizmo=rd(actor+0xcb8);wd(gizmo+0xe8,rd(0x7fb084));wd(actor+0xcb8,0)
  wb(actor+0x7b5,255);service('FinishAction',[actor,mode])
def reset_actor(actor,mode):
 configured=signed32(rd(0x802860))
 if configured==-1:return
 if signed_context(actor)!=configured:return
 wb(actor+0x7b5,255);service('Camera',[rd(0x8021b4),bits(.5),0x3f19999a if mode else 0,1])
def stop_actor(actor):
 registry=rd(0x7fb0e4);context=signed_context(actor)
 if not rd((registry+context*16+8)&0xffffffff)&0x2000:return
 configured=signed32(rd(0x802854))
 if configured!=-1 and context==configured:service('Camera',[0,bits(.5),0,1])
 wb(actor+0x7b5,255);wd(actor+0xdc4,0)
def prepare_actor(actor):
 context=signed_context(actor)
 if context!=-1 and(context==signed32(rd(0x802864))or context==signed32(rd(0x802868))):wb(actor+0x7b5,255)
 wd(actor+0xe20,rd(actor+0xe20)&0xfffeffff);wd(actor+0xd3c,0);wb(actor+0xe33,0)
def reset_controls(p):
 held=rb(p+0x75e)&1;wd(p+0xfc,0);wb(p+0x100,255);wd(p+0x678,bits(1)if held else 0);pad=rd(p+0x5e0);wd(p+0x67c,bits(5));wb(p+0x76f,0);wd(p+0x66c,0);wb(p+0xf1,255);wd(p+0x674,0);wb(p+0xf5,0);wd(p+0x664,0);wb(p+0xf4,0);ww(pad+0x5a,rw(pad+0x5a)&0xfffb);pad=rd(p+0x5e0);ww(pad+0x5a,rw(pad+0x5a)&0xffef);wd(p+0x75c,rd(p+0x75c)&0xfffffbff);wd(p+0x65c,0);wd(p+0x648,0);value=draw()
 for off in [0x694,0x698,0x670,0x6d0,0x6e8]:wd(p+off,0)
 wb(p+0x77d,value>>15);wd(p+0x700,0);wd(p+0x714,0);ww(p+0xe8,0);wd(p+0x720,0);wb(p+0xee,0);wb(p+0x76e,0);wd(p+0x724,0);wd(p+0x60c,0)
 for off in [0x74c,0x750,0x752]:ww(p+off,65535)


CONSTANTS.extend([0x7531c8,0x76b1b8])
REG=D+0x70000;SLOTS=D+0x71000;RROW=D+0x72000;RHEAD=D+0x76000;RTIME=D+0x77000;RTABLE=D+0x80000;RCLIPA=D+0x90000;RCLIPB=D+0xb0000
prepare_old=prepare
def prepare(c):
 segs=prepare_old(c);n.write(REG,bytes(0x9000));n.pack('<I',0x29130e4,0 if c.get('nullTimingRegistry')else REG);n.pack('<I',REG,c.get('typeCount',32768));n.pack('<I',REG+8,c.get('actionCount',32768));n.pack('<I',REG+0x1c,0 if c.get('nullSlots')else SLOTS)
 slot=c.get('modelSlot',0);n.pack('<I',REG+0x18,(RROW-slot*0x54)&0xffffffff);n.pack('<I',RROW+0xc,0 if c.get('nullTimingClips')else RCLIPA);n.pack('<I',RROW+8,0 if c.get('nullTimingArray')else RTABLE)
 n.pack('<I',0x8028a8,c.get('responseContext',88)&0xffffffff);n.pack('<H',0x804d08,c.get('responseAction',3)&65535);n.pack('<I',0x95660c,n.STOP+0x400 if c.get('notify',True)else 0);n.pack('<I',0x29a99a4,0x12345678)
 n.pack('<I',INPUT,c.get('controller',0x12345678));n.pack('<I',ALTINPUT,c.get('controller',0x87654321));n.pack('<I',MODEL_A+0xc,RCLIPA);n.pack('<I',MODEL_B+0xc,RCLIPB)
 n.write(RCLIPA,n.read(CLIPS_A,0x1400));n.write(RCLIPB,n.read(CLIPS_B,0x1400));n.pack('<I',A+0x1f8,c.get('finishFlags',0));n.pack('<I',B+0x1f8,c.get('finishFlagsB',0));n.pack('<I',VCL+0x94,c.get('classFlags',0x20000));n.pack('<f',VCL+0x28,c.get('classFloat',0))
 types={c.get('type',111)&65535};actions={c.get('responseAction',3)&65535}
 for rows in c.get('patches',{}).values():
  for p,v in rows:
   if p==0x804d08:actions.add(v&65535)
   if p in [A+0x1064,B+0x1064]:types.add(v&65535)
 extra=[]
 for t in types:
  signed=t-65536 if t>=32768 else t
  if signed>=0:n.pack('<h',SLOTS+signed*2,slot);extra.append((SLOTS+signed*2,4))
 for a in actions:
  signed=a-65536 if a>=32768 else a
  for p in [RCLIPA,RCLIPB]:n.pack('<I',p+signed*4,0 if c.get('missingResponseClip')else RHEAD);extra.append((p+signed*4,4))
  if signed>=0:n.pack('<I',RTABLE+signed*4,0 if c.get('nullTiming')else RTIME);extra.append((RTABLE+signed*4,4))
 if c.get('headerMagic'):
  n.pack('<I',RHEAD,c['headerMagic']);n.pack('<H',RHEAD+0xa,c.get('headerStart',1));n.pack('<H',RHEAD+0xe,c.get('headerEnd',29))
 else:n.pack('<f',RHEAD,c.get('frames',30))
 n.pack('<f',RTIME+0x18,c.get('fps',30));n.pack('<f',RTIME+0x14,c.get('blend',.25))
 if c.get('nullHeader'):n.pack('<I',RCLIPA+(c.get('responseAction',3)&65535)*4,0)
 if c.get('danglingCallback'):n.pack('<I',0x95660c,0x10300000)
 if c.get('feedbackModelAlias'):n.pack('<I',A+0xca4,A+0x7b1)
 ranges=[(s['address'],len(bytes.fromhex(s['bytes'])))for s in segs]+[(REG,0x20),(RROW,0x54),(RHEAD,16),(RTIME,32),(RCLIPA,0x1400),(RCLIPB,0x1400),(0x29130e4,4),(0x8028a8,4),(0x804d08,4),(0x95660c,4),(0x29a99a4,4)]+extra
 return [dict(address=p,bytes=n.read(p,z).hex())for p,z in ranges]
def duration(type,action):
 if type<0:return 0
 registry=rd(0x29130e4)
 if type>=signed32(rd(registry)):return 0
 if action<0 or action>=signed32(rd(registry+8)):return 0
 slot=rw(rd(registry+0x1c)+type*2);slot=slot-65536 if slot>=32768 else slot
 if slot==-1:return 0
 model=(rd(registry+0x18)+slot*0x54)&0xffffffff;header=rd(rd(model+0xc)+action*4)
 if not header:return 0
 magic=rd(header);frames=rw(header+0xe)+rw(header+0xa)if magic in [0x414e4934,0x414e4935]else frombits(magic)
 span=store(wide(frac(frames)-1));timing=rd(rd(model+8)+action*4);fps=frombits(rd(timing+0x18));rate=wide(frac(fps)/frac(double(0x7531c8)));seconds=wide(Fraction(1)/rate);seconds=wide(seconds*frac(double(0x76b1b8)));stored=store(wide(seconds*ffrac(span)));blend=rd(timing+0x14);wd(0x29a99a4,blend);return store(wide(ffrac(stored)-ffrac(blend)),stored&(blend^0x80000000)&0x80000000)
def vehicle_response(actor,other):
 if rd(0x8028a8)==0xffffffff:return
 action=rw(0x804d08);action=action-65536 if action>=32768 else action
 if action==-1:return
 if not rd((rd(rd(actor+0x50)+0xc)+action*4)&0xffffffff):return
 if other:service('Feedback',[rd(rd(other+0xca4)),0x3f19999a,0])
 wb(actor+0x7b5,rb(0x8028a8));action=rw(0x804d08);type=rw(actor+0x1064);type=type-65536 if type>=32768 else type;ww(actor+0x7aa,action);action=action-65536 if action>=32768 else action;wd(actor+0x77c,duration(type,action));callback=rd(0x95660c)
 if callback:service('Notify',[callback,actor])
def finish_action(actor):
 if actor and not rd(actor+0x1f8)&0x40000:wd(actor+0xe20,rd(actor+0xe20)&0xfffdffff);wd(actor+0xd14,0);wd(actor+0xd18,0);wb(actor+0x7b5,255)
 service('Camera',[rd(0x8021b4),bits(.5),0,1])
unit_cases=[]
def execute_unit(c,method):
 global config,events,shadow,model_events,model_occurrences,occurrences,native_trace
 config=c;events=[];occurrences={};native_trace=[];initial=prepare(c);shadow={}
 for seg in initial:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 actor=0 if c.get('nullActor')else A;other=0 if c.get('noOther')else B;mode=c.get('mode',0)&0xffffffff;model_events=[];model_occurrences={};fault=None;wantfault=None
 try:vehicle_response(actor,other)if method=='Respond'else finish_action(actor)
 except RuntimeError as exc:wantfault=str(exc)
 try:n.call(0x5a0320 if method=='Respond'else 0x4a1f50,[actor,other if method=='Respond'else mode])
 except RuntimeError as exc:fault=str(exc)
 ranges=[(A,0x1100),(B,0x1100),(INPUT,0x100),(ALTINPUT,0x100),(ALT,0x100),(CL,0x400),(AUX_A,0x1630),(0x93d5f0,0x400),(0x87a7c8,16),(0x80253c,4),(D+0x30000,0x1300),(0x29a99a4,4)];got=[n.read(p,z).hex()for p,z in ranges];want=[bytes(rb(p+i)for i in range(z)).hex()for p,z in ranges];check('response-fault-'+method,fault is not None,wantfault is not None,c);check('response-whole-state-'+method,got,want,c);check('response-callback-order-'+method,events,model_events,c);

 # Retain every byte used or compared by the standalone contract, avoiding unrelated pipeline-only backing.
 kept={p for p,z in ranges}|{MODEL_A,0x8021b4,0x8028a8,0x804d08,0x95660c,0x29130e4,0x7531c8,0x76b1b8}
 initial=[s for s in initial if s['address'] in kept or REG<=s['address']<=D+0xfffff]
 unit_cases.append(dict(method=method,context=c,argument=actor,other=other,mode=mode,initial=initial,nativeState=got,nativeEvents=events,nativeFault=fault,nativeTrace=native_trace.copy()))

CAM=D+0x57000;PART=0x10301000
n.mu.mem_map(PART,0x1000)
prepare15=prepare
peek15=peek
def peek(model):
 if config.get('unitEffects'):
  get=rd if model else lambda p:n.unpack('<I',p)[0];byte=rb if model else lambda p:n.unpack('<B',p)[0]
  return dict(conversionFlag=get(0x29a9c48),cameraDurationBits=get(CAM+0x1c0),cameraActive=byte(CAM+0x22a))
 return peek15(model)
def prepare(c):
 segs=prepare15(c);random16=random.Random(0x54a3e0);n.write(CAM,bytes(random16.randrange(256)for _ in range(0x240)));n.write(PART,b'\xa5'*0x1000);n.pack('<I',0x29a9c48,c.get('sse',0));n.pack('<B',CAM+0x22c,c.get('cameraIndex',0));n.pack('<I',0x8021b4,c.get('defaultCamera',A if c.get('cameraActor')else CAM))
 if c.get('cameraActor'):n.pack('<B',A+0x22c,c.get('cameraIndex',0))
 if c.get('partialOffset')is not None:n.pack('<B',PART+c['partialOffset']+0x22c,c.get('cameraIndex',0))
 segs=[dict(address=s['address'],bytes=n.read(s['address'],len(bytes.fromhex(s['bytes']))).hex())for s in segs]
 return segs+[dict(address=p,bytes=n.read(p,z).hex())for p,z in [(CAM,0x240),(PART,0x1000),(0x29a9c48,4)]]
def quiet(v):return v|0x400000 if v&0x7f800000==0x7f800000 and v&0x7fffff else v
def camera(p,duration,blend,mode):
 if p==0:p=rd(0x8021b4)
 if not frombits(duration)>0:return
 if rb(p+0x22c)==255:return
 one=rw(p+0x21e);two=rw(p+0x222);wd(p+0x1c4,quiet(blend));ww(p+0x21c,one);wd(p+0x1bc,0);three=rw(p+0x226);wd(p+0x1c0,duration);ww(p+0x220,two);ww(p+0x224,three);state=rb(p+0x22d);wb(p+0x22b,2 if mode else 1);x=rd(p+0x140);wb(p+0x22e,state);y=rd(p+0x144);wd(p+0x134,x);z=rd(p+0x148);wd(p+0x138,y);px=rd(p+0x128);wd(p+0x164,px);pz=rd(p+0x130);wd(p+0x13c,z);py=rd(p+0x12c);wd(p+0x168,py);x=rd(p+0x140);wd(p+0x16c,pz);y=rd(p+0x144);wd(p+0x14c,x);z=rd(p+0x148);wd(p+0x150,y);px=rd(p+0x128);wd(p+0x17c,px);pz=rd(p+0x130);wd(p+0x154,z);py=rd(p+0x12c);wd(p+0x180,py);wb(p+0x22a,1);wd(p+0x184,pz)
def feedback(controller,value):
 if controller:
  amount=int(frac(frombits(value))*255);rd(0x29a9c48);amount=min(255,amount);service('ControllerRequest',[controller,0,amount&0xffffffff,0,value])
def forward(controller,value):
 if controller:service('ControllerRequest',[controller,quiet(value),0,0,0])
unit_cases=[];unsupported_observations=[]
def execute_unit16(c,method):
 global config,events,shadow,model_events,model_occurrences,occurrences,native_trace
 c=dict(c,unitEffects=True);config=c;events=[];occurrences={};native_trace=[];initial=prepare(c);shadow={}
 for seg in initial:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 pointer=PART+c['partialOffset'] if c.get('partialOffset')is not None else 0x10300000 if c.get('badCamera')else A if c.get('cameraActor')else 0 if c.get('defaultArgument')else CAM;value=c.get('valueBits',bits(.5));blend=c.get('blendBits',bits(.25));mode=c.get('mode',1)&0xffffffff;controller=c.get('controller',0x12345678);model_events=[];model_occurrences={};fault=None;wantfault=None
 try:
  if method=='Transition':camera(pointer,value,blend,mode)
  elif method=='Feedback':feedback(controller,value)
  else:forward(controller,value)
 except RuntimeError as exc:wantfault=str(exc)
 address={'Transition':0x54a3e0,'Feedback':0x54a850,'Forward':0x54a8a0}[method];args=[pointer,value,blend,mode]if method=='Transition'else[controller,value,mode]
 try:n.call(address,args)
 except RuntimeError as exc:fault=str(exc)
 ranges=[(CAM,0x240),(PART,0x1000),(A,0x1100)];got=[n.read(p,z).hex()for p,z in ranges];want=[bytes(rb(p+i)for i in range(z)).hex()for p,z in ranges];snan=lambda v:v&0x7f800000==0x7f800000 and v&0x7fffff and not v&0x400000
 unsupported=(method=='Transition'and frombits(value)>0 and snan(blend))or(method=='Forward'and controller and snan(value))
 if not unsupported:check('effects-fault-'+method,fault is not None,wantfault is not None,c);check('effects-state-'+method,got,want,c);check('effects-driver-arguments-'+method,events,model_events,c)
 keep={CAM,PART,A,0x8021b4,0x29a9c48};initial=[s for s in initial if s['address'] in keep];saved=dict(method=method,context=c,pointer=pointer,valueBits=value,blendBits=blend,mode=mode,controller=controller,initial=initial,nativeState=got,nativeEvents=events,nativeFault=fault,nativeTrace=native_trace.copy())
 if unsupported:saved.update(reason='Unicorn FLD/FSTP preserved signaling-NaN payload while the candidate quiet-store model differed. Payload semantics require another execution backend; outside paired contract.',referenceState=want,referenceEvents=model_events);unsupported_observations.append(saved)
 else:unit_cases.append(saved)

SB_A=D+0x38000;SB_B=D+0x39000;OTHER_SCRIPT=D+0x3a000;NODES=D+0x3b000;NAMES=D+0x3c000;ACTIONS=D+0x3d000;REQ=D+0x3e000;PACKET=A+0x2c8
prepare16=prepare
def prepare(c):
 segs=prepare16(c);n.write(SB_A,bytes(0x7000));names=c.get('stateNames',['JustBeenTakenOver','ReleasedTakeOver','Base']);n.write(REQ,c.get('requestedName','ReleasedTakeOver').encode('ascii')+b'\0')
 for script,offset in [(SB_A,0),(SB_B,0x200)]:
  n.pack('<I',script+0x10,0 if c.get('emptyStates')else NODES+offset)
  for i,name in enumerate(names):
   node=NODES+offset+i*0x40;nameptr=NAMES+offset+i*0x40;n.write(nameptr,name.encode('ascii')+b'\0');n.pack('<I',node,0 if i==len(names)-1 else node+0x40);n.pack('<I',node+0x18,0 if c.get('nullStateName')else nameptr);n.pack('<I',node+0x10,0 if c.get('noActions')else ACTIONS+offset+i*0x40)
  for i,value in enumerate(c.get('defaults',[.125,-.25,1.5,-0.])):n.pack('<f',script+0x1c+i*8,value)
 for a,script in [(A,SB_A),(B,SB_B)]:
  p=a+0x2c8;n.pack('<I',p,script);n.pack('<I',p+4,OTHER_SCRIPT if c.get('differentScript')else script);n.pack('<I',p+0x50,c.get('packetFlags',0xffffffff));n.pack('<I',p+0x64,3);n.pack('<H',p+0xb2,0x1234)
 if c.get('nullBase'):n.pack('<I',PACKET,0)
 if c.get('nullCurrent'):n.pack('<I',PACKET+4,0)
 if c.get('badStateName'):n.pack('<I',NODES+0x18,0x10300000)
 if c.get('lateNodeFault'):n.pack('<I',NODES,0x10300000)
 if c.get('lateActionFault'):n.pack('<I',SB_A+0x10,PART-0x18);n.pack('<I',PART,REQ)
 if c.get('statePacketAlias'):n.pack('<I',SB_A+0x10,PACKET+0x40);n.pack('<I',PACKET+0x40+0x18,REQ);n.pack('<I',PACKET+0x40,0)
 if c.get('aliasBase'):
  script=PACKET-0x10;n.pack('<I',script,0);n.pack('<I',PACKET,script);n.pack('<I',PACKET+4,OTHER_SCRIPT);n.pack('<I',PACKET+8,REQ);n.pack('<I',PACKET+0xc,bits(1.25));n.pack('<I',PACKET+0x1c,bits(-.25));n.pack('<I',PACKET+0x24,bits(.5))
 if c.get('nullDefaultBase'):
  # Default source +0x24 is unmapped: first copy commits before the second fault.
  script=PART+0xfe0;n.pack('<I',PACKET,script);n.pack('<I',PACKET+4,OTHER_SCRIPT);n.pack('<I',script+0x10,NODES);n.pack('<f',script+0x1c,1.25)
 if c.get('timerContext')is not None:n.pack('<B',A+0x7b5,c['timerContext']&255)
 if c.get('timerBits')is not None:n.pack('<I',A+0x77c,c['timerBits'])
 if c.get('dtBits')is not None:n.pack('<I',0x925018,c['dtBits'])
 if c.get('noTimerLink'):n.pack('<I',A+0xcd0,0)
 if c.get('badTimerLink'):n.pack('<I',A+0xcd0,0x10300000)
 out=[dict(address=s['address'],bytes=n.read(s['address'],len(bytes.fromhex(s['bytes']))).hex())for s in segs]
 return out+[dict(address=p,bytes=n.read(p,z).hex())for p,z in [(SB_A,0x7000),(0x759958,32),(0x759978,32)]]
def ascii_match(a,b):
 if not b:return False
 while True:
  one=rb(a);one=one-32 if 97<=one<=122 or one>223 else one;two=rb(b);two=two-32 if 97<=two<=122 or two>223 else two
  if one!=two:return False
  if not one:return True
  a+=1;b+=1
def change_base(p,name):
 if not name or not p:return 0
 if not rd(p+4):return 0
 script=rd(p);node=rd(script+0x10)
 while node:
  if ascii_match(name,rd(node+0x18)):break
  node=rd(node)
 if not node:return 0
 script=rd(p);same=rd(p+4)==script
 if not same:
  wd(p+0x50,rd(p+0x50)&0xfffffffb);ww(p+0xb2,0);empty=rd(p)==0;wd(p+4,script);wd(p+0x10,0)
  if empty:wd(p,script)
  for i in range(4):wd(p+0x14+i*4,rd(script+0x1c+i*8))
 flags=rd(p+0x50)
 if not flags&4:ww(p+0xb2,0)
 wd(p+0x50,flags&0xfffffffb);wd(p+8,node);wd(p+0xc,0);wd(p+0x10,0);wb(p+0x38,1);action=rd(rd(p+8)+0x10)
 if action:wd(p+0x50,rd(p+0x50)|1)
 wd(p+0xc,action)
 if not same:
  wb(p+0xb4,0);wd(p+0xb8,0);wb(p+0xb5,0);wd(p+0xbc,0);wd(p+0xc0,0);wd(p+0x64,0)
 return 1
def timer(a,retry):
 configured=signed32(rd(0x8028a8))
 if configured!=-1 and signed_context(a)==configured:
  old=rd(a+0x77c);delta=rd(0x925018);value=store(wide(ffrac(old)-ffrac(delta)),old&(delta^0x80000000)&0x80000000);wd(a+0x77c,value)
  if frombits(value)<=0:wb(a+0x7b5,255)
  return
 if rb(a+0x7b5)==255 and retry:vehicle_response(a,rd(a+0xcd0))
unit_cases=[]
def execute_unit17(c,method):
 global config,events,shadow,model_events,model_occurrences,occurrences,native_trace
 config=c;events=[];occurrences={};native_trace=[];initial=prepare(c);shadow={}
 for seg in initial:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 actor=0 if c.get('nullActor')else A;packet=0 if c.get('nullPacket')else PACKET;name=0 if c.get('nullName')else 0x10300000 if c.get('badRequested')else REQ;retry=c.get('retry',1)&0xffffffff;model_events=[];model_occurrences={};fault=None;wantfault=None;wantresult=gotresult=0
 try:
  if method=='Change':wantresult=change_base(packet,name)
  else:
   for call in range(c.get('calls',1)):timer(actor,retry)
 except RuntimeError as exc:wantfault=str(exc)
 try:
  if method=='Change':gotresult=n.call(0x52c790,[packet,name])
  else:
   for call in range(c.get('calls',1)):n.call(0x5a03d0,[actor,retry])
 except RuntimeError as exc:fault=str(exc)
 ranges=[(A,0x1100),(B,0x1100),(INPUT,0x100),(ALTINPUT,0x100),(ALT,0x100),(CL,0x400),(AUX_A,0x1630),(0x93d5f0,0x400),(0x87a7c8,16),(0x80253c,4),(D+0x30000,0x1300),(0x29a99a4,4),(CAM,0x240),(PART,0x1000)];got=[n.read(p,z).hex()for p,z in ranges];want=[bytes(rb(p+i)for i in range(z)).hex()for p,z in ranges];check('bridge-fault-'+method,fault is not None,wantfault is not None,c);check('bridge-state-'+method,got,want,c);check('bridge-ports-'+method,events,model_events,c)
 if method=='Change'and not fault:check('bridge-result-'+method,gotresult,wantresult,c)
 

 keep={p for p,z in ranges}|{MODEL_A,0x7531c8,0x76b1b8,0x8028a8,0x804d08,0x95660c,0x29130e4,0x8021b4,0x29a9c48,0x925018}
 initial=[s for s in initial if s['address'] in keep or (method=='Timer'and REG<=s['address']<=D+0xfffff)or(method=='Change'and s['address']==SB_A)]
 unit_cases.append(dict(method=method,context=c,actor=actor,packet=packet,name=name,retry=retry,calls=c.get('calls',1),initial=initial,nativeState=got,nativeEvents=events,nativeFault=fault,nativeResult=gotresult if method=='Change'and not fault else None,nativeTrace=native_trace.copy()))

DESCS=D+0x40000;REFS=D+0x42000;MATCH=D+0x44000;PROFILES=D+0x45000;SCRIPT_SYSTEM=D+0x55000
prepare17=prepare
def prepare(c):
 segs=prepare17(c);n.write(DESCS,bytes(0x7000));n.write(SCRIPT_SYSTEM,bytes(0x100));n.pack('<I',SCRIPT_SYSTEM+0x18,PROFILES);n.pack('<I',0x9238ac,n.STOP+0x500 if c.get('scratch')else 0)
 for offset,script,a in [(0,SB_A,A),(0x200,SB_B,B)]:
  for i in range(8):
   act=ACTIONS+offset+i*0x40;desc=DESCS+offset+i*0x40;n.pack('<I',act,act+0x40 if i+1<c.get('actionCount',1)else 0);n.pack('<I',act+8,0x11110000+i);n.pack('<I',act+0xc,0x22220000+i);n.pack('<I',act+0x10,0 if c.get('nullDescriptor')else desc);n.pack('<I',desc+4,n.STOP+0x600 if c.get('commands')else 0);n.pack('<B',desc+8,int(c.get('animation',False)))
  for i in range(3):n.pack('<I',NODES+offset+i*0x40+0x10,0 if c.get('noActions')else ACTIONS+offset)
  n.pack('<I',script+0x38,0 if c.get('noIdle')else NODES+offset+0x80)
  p=a+0x2c8;n.pack('<f',p+0x24,c.get('timer',.125));n.pack('<I',p+0x64,c.get('depth',0)&0xffffffff);n.pack('<I',p+8,0 if c.get('noState')else NODES+offset+(0x80 if c.get('atIdle')else 0));n.pack('<I',p+0xc,0 if c.get('noCurrentAction')else ACTIONS+offset);n.pack('<I',p+0x10,NODES+offset+0x40 if c.get('pending')else 0);n.pack('<I',p+0x50,c.get('packetFlags',1));n.pack('<f',p+0xb8,c.get('deadline',0));n.pack('<I',p+0xbc,NODES+offset+0x40 if c.get('deadlineState')else 0);n.pack('<B',a+0x138,c.get('profileIndex',255));n.pack('<B',p+0x138,c.get('profileIndex',255))
  for i in range(4):
   ref=REFS+offset+i*0x40;n.pack('<I',p+0x54+i*4,ref);n.pack('<I',ref+0xc,script);n.pack('<I',ref+0x14,NODES+offset+0x40);n.pack('<I',ref+0x1c,0x12345678 if c.get('guards')else 0)
 for i in range(8):
  prof=PROFILES+i*0xa4;n.pack('<I',prof+0x48,c.get('overrideMask',0));n.pack('<4f',prof+0x64,*c.get('overrides',[10.,20.,30.,40.]))
 n.pack('<H',MATCH+0xe,c.get('conditionFlags',0));n.pack('<I',MATCH+0x24,NODES+0x40);n.pack('<f',0x925018,c.get('dt',.016))
 if c.get('nullSystem'):n.pack('<I',0x802c54,0)
 if c.get('badIdleScript'):n.pack('<I',PACKET,0x10300000)
 if c.get('emptyBaseList'):n.pack('<I',SB_A+0x10,0)
 if c.get('aliasDefaults'):
  script=PACKET-0x10;n.pack('<I',script,0);n.pack('<I',PACKET,script);n.pack('<I',PACKET+0x38-0x10,NODES);n.pack('<I',PACKET+0xc,bits(1.25));n.pack('<I',PACKET+0x1c,bits(-.25));n.pack('<I',PACKET+0x24,bits(.5))
 if c.get('lateBindDefaults'):
  script=PART+0xfe0;n.pack('<I',PACKET,script);n.pack('<I',script+0x38,NODES);n.pack('<f',script+0x1c,1.25)
 if c.get('sparseDefaults'):
  n.pack('<I',PACKET,PART-0x20);n.pack('<I',PART+0x18,NODES)
 if c.get('idleActionFault'):n.pack('<I',SB_A+0x38,0x10300000)
 if c.get('profileAlias'):
  n.pack('<I',SCRIPT_SYSTEM+0x18,PACKET-0x30);n.pack('<4I',PACKET+0x34,bits(1),2,bits(3),bits(4));n.pack('<B',A+0x138,0)
 if c.get('badDescriptor'):n.pack('<I',ACTIONS+0x10,0x10300000)
 if c.get('badDeadlineState'):n.pack('<I',PACKET+0xbc,0x10300000)
 if c.get('stateHeadAlias'):n.pack('<I',SB_A+0x38,PACKET+0x40)
 out=[dict(address=s['address'],bytes=n.read(s['address'],len(bytes.fromhex(s['bytes']))).hex())for s in segs]
 return out+[dict(address=p,bytes=n.read(p,z).hex())for p,z in [(DESCS,0x7000),(SCRIPT_SYSTEM,0x100),(0x9238ac,4),(0x753270,5)]]
def port_result(name,args,ordinal):
 result=config.get('results',{}).get(name)
 if result is not None:return (result[min(ordinal-1,len(result)-1)]if isinstance(result,list)else result)&0xffffffff
 if name=='Command':return 1
 if name=='Conditions':return (1 if args[0]else MATCH if config.get('conditionMatch')else 0)
 return 0
def advance(p):
 if not p:return
 old=rd(p+0xc);next=rd(old)if old else rd(rd(p+8)+0x10)
 if next:wd(p+0x50,rd(p+0x50)|1)
 wd(p+0xc,next)
def enter_script(p,state):
 if not p or not state:return
 flags=rd(p+0x50)
 if not flags&4:ww(p+0xb2,0)
 wd(p+0x50,flags&0xfffffffb);wd(p+8,state);wd(p+0xc,0);wd(p+0x10,0);wb(p+0x38,1);advance(p)
def find_base(script):
 node=rd(script+0x10)
 while node:
  if ascii_match(0x753270,rd(node+0x18)):return node
  node=rd(node)
 return 0
def bind(p,script,state,profile=0):
 if not p:return
 wd(p+0x50,rd(p+0x50)&0xfffffffb);ww(p+0xb2,0)
 if not script:raise RuntimeError('nonnull supplied script domain')
 empty=rd(p)==0;wd(p+4,script);wd(p+0x10,0)
 if empty:wd(p,script)
 if not profile:
  for i in range(4):wd(p+0x14+i*4,rd(script+0x1c+i*8))
 else:
  for i in range(4):wd(p+0x14+i*4,rd(profile+0x64+i*4))
  for i in range(4):
   if not rd(profile+0x48)&(2<<i):wd(p+0x14+i*4,rd(script+0x1c+i*8))
 if not state:state=find_base(rd(p+4))
 enter_script(p,state);wb(p+0xb4,0);wd(p+0xb8,0);wb(p+0xb5,0);wd(p+0xbc,0);wd(p+0xc0,0)
def rebind(a):
 p=a+0x2c8;script=rd(p)
 if script:state=rd(script+0x38);rd(rd(0x802c54)+0x2ae8);bind(p,script,state);wd(a+0x32c,0)
def profile(system,actor):
 index=rb(actor+0x138);return 0 if index==255 else rd(system+0x18)+index*0xa4
def return_reference(system,actor,p,ref,index):
 if index==0:prof=profile(system,actor);state=rd(ref+0x14);script=rd(p)
 else:prof=0;state=rd(ref+0x14);script=rd(rd(p+index*4+0x50)+0xc)
 bind(p,script,state,prof)
def dispatch(system,actor,p,dt):
 if not p or not rd(p+4):return
 old=rd(p+0x24);initial=signed32(rd(p+0x64));wd(p+0x24,store(wide(ffrac(old)+ffrac(dt)),old&dt&0x80000000))
 if initial>0:
  i=0
  while True:
   ref=rd(p+0x54+i*4);lst=ref+0x1c
   if rd(lst)and not service('Conditions',[1,system,lst,actor,p]):wd(p+0x64,i);return_reference(system,actor,p,ref,i);break
   i+=1
   if i>=signed32(rd(p+0x64)):break
 depth=signed32(rd(p+0x64))
 if depth and not rd(p+0x10)and rd(rd(p+4)+0x38)==rd(p+8):ref=rd((p+depth*4+0x50)&0xffffffff);depth-=1;wd(p+0x64,depth);return_reference(system,actor,p,ref,depth)
 pending=rd(p+0x10)
 if pending:enter_script(p,pending);wd(p+0x10,0)
 elif not rd(p+8):
  first=rd(rd(p+4)+0x10)
  if first:enter_script(p,first)
 if rd(p+8):
  while rd(p+0xc):
   act=rd(p+0xc);desc=rd(act+0x10);first=0
   if not desc or not rd(desc+4):wd(p+0x50,rd(p+0x50)&0xfffffffe)
   else:
    if rb(p+0x50)&1:
     wd(p+0x70,0);wb(p+0x68,0);wd(p+0x74,0);wb(p+0x69,0);wd(p+0x9c,0);wd(p+0x6c,0);ww(p+0x6a,0);ww(p+0xb6,0);wd(p+0x80,0);wd(p+0x7c,0);wd(p+0x78,0)
     for off in [0x84,0x88,0x8c,0x90,0x94,0x98]:wd(p+off,0)
     if actor:
      wd(actor+0x180,0);wb(actor+0x13f,0);wd(actor+0x17c,0);wd(actor+0x1e4,0);callback=rd(0x9238ac)
      if callback:service('Scratch',[callback,system,actor,p])
     wd(p+0x50,rd(p+0x50)&0xfffffffe);desc=rd(act+0x10);first=1
     if rb(desc+8):service('Animation',[act,actor])
    desc=rd(act+0x10);argC=rd(act+0xc);arg8=rd(act+8);handler=rd(desc+4)
    if not service('Command',[handler,system,p,actor,arg8,argC,first,dt]):break
   if not rb(p+0x50)&1:advance(p)
 if service('References',[system,actor]):return
 before=rd(p+0xb8)
 if frombits(before)>0:wd(p+0xb8,store(wide(ffrac(rd(p+0xb8))-ffrac(dt))))
 if frombits(before)>0 and frombits(rd(p+0xb8))<=0 and rd(p+0xbc):enter_script(p,rd(p+0xbc));wd(p+0xbc,0);wb(p+0xb4,0);return
 current=rd(p+8)
 if current:
  match=service('Conditions',[0,system,current+8,actor,p])
  if match:message=rw(match+0xe);flags=rd(p+0x50);wd(p+0x50,flags^(((message*2)^flags)&4));enter_script(p,rd(match+0x24))
unit_cases=[]
def execute_unit18(c,method):
 global config,events,shadow,model_events,model_occurrences,occurrences,native_trace
 config=c;events=[];occurrences={};native_trace=[];initial=prepare(c);shadow={}
 for seg in initial:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 actor=0 if c.get('nullActor')else A;packet=0 if c.get('nullPacket')else PACKET;entity=0 if c.get('nullEntity')else packet if c.get('actorPacket')else A;system=0 if c.get('nullScriptSystem')else SCRIPT_SYSTEM;dt=bits(c.get('dt',.016));model_events=[];model_occurrences={};fault=None;wantfault=None
 try:
  if method=='Rebind':rebind(actor)
  else:
   for call in range(c.get('calls',1)):dispatch(system,entity,packet,dt)
 except RuntimeError as exc:wantfault=str(exc)
 try:
  if method=='Rebind':n.call(0x415000,[actor])
  else:
   for call in range(c.get('calls',1)):n.call(0x52cc90,[system,A,entity,packet,dt])
 except RuntimeError as exc:fault=str(exc)
 ranges=[(A,0x1100),(B,0x1100),(INPUT,0x100),(ALTINPUT,0x100),(ALT,0x100),(CL,0x400),(AUX_A,0x1630),(0x93d5f0,0x400),(0x87a7c8,16),(0x80253c,4),(D+0x30000,0x1300),(0x29a99a4,4),(CAM,0x240),(PART,0x1000)];got=[n.read(p,z).hex()for p,z in ranges];want=[bytes(rb(p+i)for i in range(z)).hex()for p,z in ranges];check('runtime-fault-'+method,fault is not None,wantfault is not None,c);check('runtime-whole-state-'+method,got,want,c);check('runtime-child-order-'+method,events,model_events,c);

 # Every consumed/compared byte remains; discard unrelated rendering/vehicle-only backing in standalone runtime cases.
 keep={p for p,z in ranges}|{SB_A,DESCS,SCRIPT_SYSTEM,0x9238ac,0x753270,0x802c54}
 system_cell=dict(address=SYS+0x2ae8,bytes=n.read(SYS+0x2ae8,4).hex());initial=[s for s in initial if s['address'] in keep]+[system_cell]
 unit_cases.append(dict(method=method,context=c,actor=actor,entity=entity,packet=packet,system=system,deltaBits=dt,calls=c.get('calls',1),initial=initial,nativeState=got,nativeEvents=events,nativeFault=fault,nativeTrace=native_trace.copy()))
for c in [dict(),dict(noIdle=True),dict(noIdle=True,emptyBaseList=True),dict(noActions=True),dict(nullBase=True),dict(nullActor=True),dict(nullBase=True,nullSystem=True),dict(nullSystem=True),dict(badIdleScript=True),dict(idleActionFault=True),dict(aliasDefaults=True),dict(stateHeadAlias=True)]:execute_unit18(c,'Rebind')
for flags,idle,actions in itertools.product([0,1,4,5,0xffffffff],[False,True],[False,True]):execute_unit18(dict(packetFlags=flags,noIdle=not idle,noActions=not actions),'Rebind')
for flags,commands,animation,scratch,entity in itertools.product([0,1,4,5],[False,True],[False,True],[False,True],[False,True]):execute_unit18(dict(packetFlags=flags,commands=commands,animation=animation,scratch=scratch,nullEntity=not entity),'Tick')
for c in [dict(nullPacket=True),dict(nullCurrent=True),dict(noState=True,noCurrentAction=True),dict(pending=True),dict(nullDescriptor=True),dict(badDescriptor=True),dict(actorPacket=True,commands=True,scratch=True),dict(commands=True,actionCount=4),dict(commands=True,results={'Command':0}),dict(commands=True,deadline=.01,deadlineState=True),dict(commands=True,deadline=.01,badDeadlineState=True),dict(commands=True,deadline=.01,deadlineState=True,results={'References':1}),dict(conditionMatch=True,conditionFlags=2),dict(conditionMatch=True,conditionFlags=0),dict(commands=True,calls=3),dict(commands=True,scratch=True,patches={'Scratch':[[PACKET+0xc,ACTIONS+0x40],[ACTIONS+8,0x76543210]]}),dict(commands=True,scratch=True,patches={'Scratch':[[ACTIONS+0x10,0]]}),dict(commands=True,animation=True,patches={'Animation#1':[[PACKET+0xc,0]]}),dict(commands=True,results={'Command':[1,0]},patches={'Command#1':[[PACKET+0x50,1]]})]:execute_unit18(c,'Tick')
for depth,guard,index,mask in itertools.product([1,2,3,4],[False,True],[255,0,1],[0,2,0x1e]):execute_unit18(dict(depth=depth,guards=guard,profileIndex=index,overrideMask=mask,results={'Conditions':[0]}if guard else{},atIdle=not guard),'Tick')
for c in [dict(depth=1,guards=True,profileIndex=255,nullEntity=True,results={'Conditions':0}),dict(depth=-1,atIdle=True),dict(depth=2,guards=True,results={'Conditions':[1,0]}),dict(depth=2,guards=True,pending=True,results={'Conditions':1}),dict(depth=1,guards=True,patches={'Conditions':[[PACKET+0x64,0]]})]:execute_unit18(c,'Tick')

for mask in list(range(32))+[0x80000000,0xffffffff]:execute_unit18(dict(depth=1,guards=True,profileIndex=0,overrideMask=mask,results={'Conditions':[0]}),'Tick')
for c in [dict(depth=1,guards=True,profileAlias=True,results={'Conditions':[0]}),dict(commands=True,scratch=True,patches={'Scratch#1':[[ACTIONS+0x10,DESCS+0x40],[ACTIONS+8,0x12345678],[PACKET+0xc,ACTIONS+0x40]]}),dict(commands=True,animation=True,patches={'Animation#1':[[DESCS+4,n.STOP+0x600],[ACTIONS+0xc,0xaabbccdd]]}),dict(commands=True,patches={'Command#1':[[PACKET+8,0],[PACKET+0xc,0]]}),dict(conditionMatch=True,patches={'Conditions#1':[[MATCH+0x24,0]]}),dict(commands=True,results={'References':1},deadline=.001,deadlineState=True)]:execute_unit18(c,'Tick')
r18=random.Random(0x52cc90)
for i in range(256):
 timer_value=frombits(r18.randrange(0,0x47000000))*(-1 if i&1 else 1);dt_value=frombits(r18.randrange(0,0x42000000))*(-1 if i&2 else 1);deadline_value=frombits(r18.randrange(0x00800000,0x43000000))
 execute_unit18(dict(timer=timer_value,dt=dt_value,deadline=deadline_value,deadlineState=True,noActions=True),'Tick')


for c in [dict(sparseDefaults=True),dict(noIdle=True,stateNames=['taken','release','bAsE']),dict(noIdle=True,stateNames=['Missing']),dict(nullBase=True,nullSystem=True)]:execute_unit18(c,'Rebind')
for c in [dict(commands=True,scratch=True,patches={'Scratch#1':[[DESCS+4,0]]}),dict(commands=True,patches={'References#1':[[PACKET+8,0]]}),dict(commands=True,patches={'Command#1':[[PACKET+0x10,NODES+0x40]]}),dict(conditionMatch=True,conditionFlags=2,packetFlags=4),dict(commands=True,scratch=True,patches={'Scratch#1':[[0x9238ac,0]]})]:execute_unit18(c,'Tick')

for context,inputB in itertools.product([8,27,29,59],[False,True]):execute(dict(contextA=context,inputB=inputB,classFloat=0,classFlags=0x20000,contextFlags=0x2000,linkedAction=True,gizmoAction=True))
for c in [dict(commands=True,scratch=True,animation=True),dict(commands=True,results={'Command':0}),dict(noIdle=True),dict(emptyBaseList=True,noIdle=True),dict(nullSystem=True),dict(nullBase=True),dict(skipTransfer=True),dict(special=True),dict(cameraActor=True),dict(calls=2)]:execute(c)

# Out-of-domain nonprogress callback: retain original execution under a bounded host instruction budget only.
config=dict(commands=True,animation=True,patches={'Animation':[[PACKET+0xc,0]]});events=[];occurrences={};native_trace=[];initial_observation=prepare(config);observation_stop=None
try:n.call(0x52cc90,[SCRIPT_SYSTEM,A,A,PACKET,bits(.016)],count=10000)
except RuntimeError as exc:observation_stop=str(exc)
unsupported_observations=[dict(reason='Callback re-inserts first action on every animation invocation; nonprogress loop outside paired contract.',hostInstructionBudget=10000,stop=observation_stop,initial=initial_observation,nativeEvents=events.copy(),nativeTrace=native_trace.copy(),nativeActorState=[n.read(a,0x1100).hex()for a in [A,B]])]

assembly=[]
for a,size in [(0x415000,68),(0x52cc90,989),(0x514640,384),(0x5145a0,59),(0x514550,77),(0x512fc0,78)]:assembly.append(dict(address=hex(a),size=size,bytes=n.read(a,size).hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,size),a)]))
report=dict(binarySha256=n.sha256,nativeChecks=sum(checks.values()),checks=checks,mismatches=len(errors),errors=errors,unitCases=len(unit_cases),pipelineCases=len(cases),unsupportedObservations=len(unsupported_observations),remainingAdapters={hex(p):dict(name=row[0],argc=row[1])for p,row in port_sites.items()},limits=['Actual Rebind/binding and52cc90 body execute; condition/reference evaluator, scratch/animation/command child callbacks, driver/notification/special-jump/audio remain explicit.','Nonnull supplied script binding, finite copied defaults/overrides, finite timer/delta/deadline arithmetic, ASCII Base lookup and bounded-progress actions. No additional existing-address or authored command credit.'])
for suffix,obj in [('tests',report),('native-fixtures',dict(binarySha256=n.sha256,unitCases=unit_cases,cases=cases,unsupportedObservations=unsupported_observations)),('assembly',dict(binarySha256=n.sha256,functions=assembly))]:(native.BASE/'reports'/('script-phase18-20261013-'+suffix+'.json')).write_text(json.dumps(obj,indent=2))
print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
