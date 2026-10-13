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
port_sites={0x54a850:('Feedback',3),0x10200400:('Notify',1),0x415000:('Rebind',1),0x52c790:('ChangeState',2),0x52cc90:('RunScript',5),0x4c99b0:('DistanceFactor',2),0x561e20:('DirectedJump',6),0x54a3e0:('Camera',4),0x681e90:('PlayerSound',2),0x681eb0:('WorldSound',3)}
actual_entries={0x4a1f50:'FinishAction',0x5a0320:'VehicleResponse',0x62e040:'Duration',0x5ca470:'EndFrame',0x4a25b0:'ClearAction',0x58ff10:'ResetActor',0x59cb00:'StopActor',0x55e4e0:'ResetControls',0x58d8e0:'PrepareActor',0x4882d0:'Release',0x4876a0:'Transfer',0x487270:'Selector',0x4871a0:'Seat',0x55d2b0:'Bounds',0x5a01f0:'Eject',0x561ba0:'Context',0x547f30:'SoundRouter',0x62e650:'ResetPacket',0x54fa60:'QRAND',0x5c0240:'SquareRoot'}
occurrences={};native_trace=[]
def peek(model):
 get=rd if model else lambda p:n.unpack('<I',p)[0];byte=rb if model else lambda p:n.unpack('<B',p)[0];word=rw if model else lambda p:n.unpack('<H',p)[0]
 return dict(rng=get(0x80253c),actors=[dict(link=get(a+0xcd0),context=byte(a+0x7b5),animation=word(a+0x7aa),flags1fc=get(a+0x1fc),flags1f8=get(a+0x1f8),packetWord=get(a+0x2c8),set=byte(a+0x378),xBits=get(a+0x5c),yBits=get(a+0x60),zBits=get(a+0x64),velocityXBits=get(a+0x68),velocityYBits=get(a+0x6c),velocityZBits=get(a+0x70),bottomBits=get(a+0x1a0),input=get(a+0xca4))for a in [A,B]])
def patches(name,ordinal):return config.get('patches',{}).get(name,[])+config.get('patches',{}).get(name+'#'+str(ordinal),[])
def port_hook(mu,address,size,data):
 if address in actual_entries:native_trace.append(actual_entries[address])
 if address not in port_sites:return
 name,count=port_sites[address];sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*count,sp+4))
 if name=='Notify':args=[address]+args
 if name=='ChangeState':name='ChangeReleasedState'if args[1]==0x759978 else'ChangeTakenOverState'
 occurrences[name]=occurrences.get(name,0)+1;events.append(dict(name=name,args=args,observed=peek(False)))
 for p,value in patches(name,occurrences[name]):n.pack('<I',p,value)
 if name=='DistanceFactor':
  n.pack('<I',ALT+0x800,config.get('factorBits',bits(.375)));n.write(n.STOP+0x100,b'\xd9\x05'+struct.pack('<I',ALT+0x800)+b'\xc3');mu.reg_write(UC_X86_REG_EIP,n.STOP+0x100);return
 result=config.get('stateResults',{}).get(str(args[0]),0)if name in ['ChangeTakenOverState','ChangeReleasedState']else 0;mu.reg_write(UC_X86_REG_EAX,result&0xffffffff);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,port_hook)
def service(name,args):
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
 return config.get('stateResults',{}).get(str(args[0]),0)if name in ['ChangeTakenOverState','ChangeReleasedState']else 0
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
 ranges=[(A,0x1100),(B,0x1100),(INPUT,0x100),(ALTINPUT,0x100),(ALT,0x100),(CL,0x400),(AUX_A,0x1630),(0x93d5f0,0x400),(0x87a7c8,16),(0x80253c,4),(D+0x30000,0x1300),(0x29a99a4,4)]
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
for context,action,other in itertools.product([-1,0,88,255,344,0x80000000],[-32768,-2,-1,0,3,255,32767],[False,True]):execute_unit(dict(responseContext=context,responseAction=action,noOther=other),'Respond')
for type,slot in itertools.product([-32768,-1,0,111,255,32767],[-32768,-2,-1,0,1,32767]):execute_unit(dict(type=type,modelSlot=slot),'Respond')
for frames,fps,blend in itertools.product([0.,.5,1.,1.0000001192092896,29.,65535.,131070.],[.125,29.97,30.,60.,120.],[0.,-.0,.25,-.25,1.]):execute_unit(dict(frames=frames,fps=fps,blend=blend),'Respond')
for magic,start,end in itertools.product([0x414e4934,0x414e4935],[0,1,65535],[0,1,29,65535]):execute_unit(dict(headerMagic=magic,headerStart=start,headerEnd=end),'Respond')
for key in ['nullActor','nullInput','nullModel','nullTimingRegistry','nullSlots','nullTimingClips','nullTimingArray','nullTiming','nullHeader','missingResponseClip']:
 execute_unit({key:True},'Respond')
for c in [dict(nullActor=True,responseContext=-1),dict(nullActor=True,responseAction=-1),dict(type=-1,nullTimingRegistry=True),dict(responseAction=-2,nullTimingRegistry=True),dict(typeCount=111),dict(actionCount=3),dict(notify=False),dict(aliasInput=True),dict(feedbackModelAlias=True),dict(patches={'Feedback':[[0x8028a8,315],[0x804d08,0xffff],[A+0x1064,32767]]}),dict(patches={'Feedback':[[0x804d08,5],[0x95660c,0]]}),dict(patches={'Notify':[[A+0x7b5,27],[A+0x77c,0x3f800000]]}),dict(patches={'Feedback':[[0x29130e4,0]]})]:execute_unit(c,'Respond')

r15=random.Random(0x5a0320)
for i in range(512):
 frames=frombits(r15.randrange(0x00800000,0x43000000));fps=frombits(r15.randrange(0x37000000,0x70000000));blend=frombits(r15.randrange(0x00800000,0x42000000))*(-1 if i&1 else 1)
 execute_unit(dict(frames=frames,fps=fps,blend=blend,noOther=bool(i&2),notify=bool(i&4)),'Respond')
for c in [dict(patches={'Feedback':[[RCLIPA+12,0]]}),dict(patches={'Feedback':[[REG+0x18,0]]}),dict(patches={'Feedback':[[SLOTS+111*2,0xffffffff]]}),dict(patches={'Feedback':[[RTABLE+12,0]]}),dict(patches={'Feedback':[[RROW+0xc,0]]}),dict(frames=0.9999999403953552,fps=3.4028234663852886e38,blend=0),dict(frames=1.,fps=30,blend=-0.)]:execute_unit(c,'Respond')

for flags,mode in itertools.product([0,1,0x40000,0x40001,0xffffffff],[0,1,0xffffffff]):execute_unit(dict(finishFlags=flags,mode=mode),'Finish')
for c in [dict(nullActor=True),dict(patches={'Camera':[[A+0x7b5,29]]})]:execute_unit(c,'Finish')
for context,inputB in itertools.product([8,27,29,59],[False,True]):execute(dict(contextA=context,inputB=inputB,classFloat=0,classFlags=0x20000,contextFlags=0x2000,linkedAction=True,gizmoAction=True,stateResults={str(A+0x2c8):1,str(B+0x2c8):1}))
for c in [dict(skipTransfer=True),dict(selfLink=True),dict(nullInput=True),dict(aliasInput=True),dict(patches={'Feedback':[[0x8028a8,315],[0x804d08,5]]}),dict(patches={'Notify':[[A+0x7b5,27]]}),dict(contextA=29,gizmoAction=True,calls=2)]:execute(c)
assembly=[]
for a,size in [(0x5a0320,168),(0x4a1f50,86),(0x62e040,324),(0x5ca470,58)]:assembly.append(dict(address=hex(a),size=size,bytes=n.read(a,size).hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,size),a)]))
report=dict(binarySha256=n.sha256,nativeChecks=sum(checks.values()),checks=checks,mismatches=len(errors),errors=errors,unitCases=len(unit_cases),pipelineCases=len(cases),remainingAdapters={hex(p):dict(name=row[0],argc=row[1])for p,row in port_sites.items()},limits=['Actual vehicle response/action finish/timing/header and prior recovered pipeline execute unmodified; feedback, dynamic notification and remaining engine ports explicit.','Fixed62e040 response call has finite frame/span/duration/blend, positive finite FPS domain; registry pointer/index failures retained. Existing timing/header addresses add zero credit.'])
for suffix,obj in [('tests',report),('native-fixtures',dict(binarySha256=n.sha256,unitCases=unit_cases,cases=cases)),('assembly',dict(binarySha256=n.sha256,functions=assembly))]:(native.BASE/'reports'/('script-phase15-20261013-'+suffix+'.json')).write_text(json.dumps(obj,indent=2))
print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
