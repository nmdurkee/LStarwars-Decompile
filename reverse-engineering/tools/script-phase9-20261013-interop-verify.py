"""Inline native 4882d0 + unmodified 4871a0; explicit downstream ABI adapters.
Adapters are recorded, never counted as recovered callee implementations.
"""
import importlib.util,json,struct,itertools,random,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDI
n=native.NativeX86();D=n.DATA;A=D+0x1000;B=D+0x4000;DEF_A=D+0x8000;DEF_B=D+0x8100;CLASS_A=D+0x9000;CLASS_B=D+0x9200;MODEL_A=D+0xa000;MODEL_B=D+0xa200;SYS=D+0xb000;OUT=D+0xc000
cs=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for address,size in [(0x4876a0,0x5fa),(0x4a4ca0,51),(0x466820,31)]:assembly.append(dict(address=hex(address),size=size,bytes=n.read(address,size).hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(address,size),address)]))
callees={0x4a25b0:('ClearAction',2),0x58ff10:('ResetActor',2),0x59cb00:('StopActor',1),0x55e4e0:('ResetAnimation',1),0x58d8e0:('PrepareActor',1),0x487270:('SelectTakeoverAnimation',0),0x415000:('Rebind',1),0x55d2b0:('RefreshPose',1),0x5a01f0:('Eject',2),0x5a0320:('VehicleResponse',2),0x4c99b0:('DistanceFactor',2),0x561e20:('DirectedJump',6),0x54a3e0:('Camera',4),0x52c790:('ChangeState',2),0x52cc90:('RunScript',5)}
checks={};errors=[];cases=[];seats=[];events=[];config={};shadow={}
def check(k,a,b,meta=None):
 checks[k]=checks.get(k,0)+1
 if a!=b:errors.append(dict(group=k,got=a,want=b,input=meta))
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def fl(i):return struct.unpack('<f',struct.pack('<I',i))[0]
def f32(f):return fl(bits(f))
def rb(p):
 if p not in shadow:raise RuntimeError('unmapped shadow '+hex(p))
 return shadow[p]
def rd(p):return sum(rb(p+i)<<(i*8)for i in range(4))
def rw(p):return rb(p)|(rb(p+1)<<8)
def wb(p,x):shadow[p]=x&255
def wd(p,x):
 for i in range(4):wb(p+i,x>>(i*8))
def ww(p,x):wb(p,x);wb(p+1,x>>8)
def hook(mu,a,size,data):
 if a not in callees:return
 name,count=callees[a];sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*count,sp+4)) if count else [mu.reg_read(UC_X86_REG_ECX),mu.reg_read(UC_X86_REG_EDI)];name=('ChangeReleasedState'if args[1]==0x759978 else'ChangeTakenOverState')if name=='ChangeState'else name;events.append(dict(name=name,args=args))
 if a==0x487270:return
 for p,value in config.get('patches',{}).get(name,[]):n.pack('<I',p,value)
 if name=='DistanceFactor':
  n.pack('<I',OUT+0x100,config.get('factorBits',bits(.375)));n.write(n.STOP+0x100,b'\xd9\x05'+struct.pack('<I',OUT+0x100)+b'\xc3');mu.reg_write(UC_X86_REG_EIP,n.STOP+0x100);return
 ret=config.get('transferResult',1)if name=='Transfer'else config.get('stateResults',{}).get(str(args[0]),0)if name in ['ChangeReleasedState','ChangeTakenOverState']else 0
 mu.reg_write(UC_X86_REG_EAX,ret);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,hook)
def service(name,args):
 if name=='Transfer':return transfer_model(args[0],args[1],bool(args[3]))
 model_events.append(dict(name=name,args=args))
 if name=='SelectTakeoverAnimation':selector_model(args[0],args[1]);return 0
 for p,value in config.get('patches',{}).get(name,[]):wd(p,value)
 return config.get('transferResult',1)if name=='Transfer'else config.get('stateResults',{}).get(str(args[0]),0)if name in ['ChangeReleasedState','ChangeTakenOverState']else 0
def seat(actor,out):
 cl=rd(rd(actor+0x54)+0x24);s=rb(cl+0x113);s=s-256 if s>=128 else s
 if s!=-1 and rd(rd(actor+0x50)+0x14+s*4):p=actor+0x834+s*0x40;wd(out,rd(p));wd(out+4,rd(p+4));wd(out+8,rd(p+8))
 else:wd(out,rd(actor+0x5c));wd(out+4,rd(actor+0x194));wd(out+8,rd(actor+0x64))
def model(inp):
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
def prepare(c):
 n.write(D,bytes(0x20000));rng=random.Random(c.get('seed',1))
 for actor,df,cl,mo in [(A,DEF_A,CLASS_A,MODEL_A),(B,DEF_B,CLASS_B,MODEL_B)]:
  n.write(actor,bytes(rng.randrange(256)for _ in range(0x1100)));n.pack('<I',actor+0x54,df);n.pack('<I',actor+0x50,mo);n.pack('<II',df+0xc,0x12345678,0);n.pack('<I',df+0x24,cl);n.pack('<I',actor+0x1fc,c.get('flagA'if actor==A else'flagB',0x81234567));n.pack('<B',actor+0x280,c.get('personalA'if actor==A else'personalB',255));n.pack('<I',actor+0xe20,0xffffffff);n.pack('<I',actor+0x800,0 if c.get('nullAux')else D+0x10000+(0 if actor==A else 0x1000));n.pack('<III',actor+0xda8,bits(3.125),0,0);n.pack('<I',actor+0xdec,bits(-.5));n.pack('<I',actor+0x1000,bits(-0.));n.pack('<f',cl+0x2c,c.get('impulse',2.5));n.pack('<3f',actor+0x5c,1.25 if actor==A else-8.,2.5,3.75);n.pack('<f',actor+0x194,17.25);n.pack('<f',actor+0x6c,c.get('velocityA'if actor==A else'velocityB',3.5 if actor==A else-7.25));n.pack('<B',cl+0x113,c.get('seat',-1)&255);n.pack('<I',cl+0x28,c.get('classBits',bits(1.)));n.pack('<I',cl+0x94,c.get('classFlags',0));n.pack('<B',actor+0xef4,c.get('skipTransfer',False)*2);n.pack('<H',actor+0x1064,77);n.pack('<H',actor+0x58,0xabcd if actor==A else 0x1357)
  index=c.get('seat',-1)
  if index!=-1:n.pack('<I',mo+0x14+index*4,1 if c.get('matrix',True)else 0);n.pack('<III',actor+0x834+index*64,0x3f800001,0x80000000,0x7fc54321)
 n.pack('<II',A+0xcd0,B,0);n.pack('<I',B+0xcd0,A);n.pack('<B',A+0x7b5,c.get('contextA',59));n.pack('<B',B+0x7b5,c.get('contextB',0));n.pack('<I',0x951c5c,1 if c.get('originalBlockedTransfer')else 0);n.pack('<I',0x802c54,SYS);n.pack('<I',0x8021b4,D+0xd000);n.pack('<H',0x7f1914,77 if c.get('special',False)else 88);n.pack('<I',SYS+0x128,c.get('level',123));n.pack('<I',0x87b234,c.get('levelGate',123));n.pack('<I',SYS+0x2ae8,D+0xe000);n.pack('<I',0x925018,bits(.016));n.pack('<I',0x7f39e4,1);n.pack('<I',MODEL_A+0xc,D+0x18000);n.pack('<I',MODEL_B+0xc,D+0x19000)
 for a,x in zip([0x7f1814,0x7f1850,0x7f1934,0x7f1938,0x7f193c,0x7f1940,0x7f1aa4,0x7f1944,0x7f1948,0x7f194c,0x7f1950,0x7f1954,0x7f19bc,0x7f1920],range(100,114)):n.pack('<h',a,x)
 n.pack('<h',B+0x1064,c.get('vehicleType',111));n.pack('<B',CLASS_B+0x116,c.get('subtype',0));n.pack('<B',B+8+0x31,1);n.pack('<hh',B+8+0x34,c.get('action',3),-1)
 for a in [D+0x18000,D+0x19000]:
  for index in [0x70,0x83,0x84,0x86,0xc0,0xc1,0xc2,0xc3,0xc4]:n.pack('<I',a+index*4,0 if c.get('missingClips')else 1)
 n.pack('<II',0x7fa56c,bits(11.25),bits(2.75));n.pack('<I',0x951c5c,int(c.get('blocked',False)));n.write(0x93d5f0,b'\xab'*0x400);n.pack('<4I',0x87a7c8,A if c.get('pairSource',True)else B,B if c.get('pairTarget',False)else A,0x12345678,0x87654321);n.write(D+0x10000,b'\xcd'*0x1630)
 if c.get('skipPrepare'):n.pack('<I',A+0xeec,16)
 if c.get('noLink'):n.pack('<I',(B if c.get('inputB')else A)+0xcd0,0)
 if c.get('selfLink'):n.pack('<I',(B if c.get('inputB')else A)+0xcd0,B if c.get('inputB')else A)
 if c.get('nullDef'):n.pack('<I',B+0x54,0)
 segs=[dict(address=p,bytes=n.read(p,z).hex())for p,z in [(A,0x1100),(B,0x1100),(DEF_A,0x100),(DEF_B,0x100),(CLASS_A,0x200),(CLASS_B,0x200),(D+0x10000,0x1630),(0x93d5f0,0x400),(0x87a7c8,16),(0x951c5c,4),(0x7f39e4,4),(D+0x18000,0x1400),(0x7f1800,0x300),(MODEL_A-0x200,0x500),(SYS+0x128,4),(SYS+0x2ae8,4),(OUT,12),(0x802c54,4),(0x8021b4,4),(0x7f1914,2),(0x87b234,4),(0x925018,4),(0x7fa56c,8)]]
 return segs

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
transfer_cases=[];interop=[]
def execute_transfer(c,release=False):
 global config,events,shadow,model_events
 config=c;events=[];segs=prepare(c);shadow={}
 for seg in segs:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 source=0 if c.get('nullSource')else A;target=0 if c.get('nullTarget')else A if c.get('sameActor')else B;model_events=[];fault=None;model_fault=None;wantret=None;ret=None
 try:wantret=transfer_model(source,target,c.get('camera',False))
 except RuntimeError as e:model_fault=str(e)
 try:ret=n.call(0x4876a0,[source,target,c.get('mode',1),int(c.get('camera',False)),0])
 except RuntimeError as e:fault=str(e)
 check('mode1-fault-parity',fault is not None,model_fault is not None,c);check('mode1-return',ret,wantret,c)
 got=[n.read(p,z).hex()for p,z in [(A,0x1100),(B,0x1100),(D+0x10000,0x1630),(0x93d5f0,0x400),(0x87a7c8,16)]];want=[bytes(rb(p+i)for i in range(z)).hex()for p,z in [(A,0x1100),(B,0x1100),(D+0x10000,0x1630),(0x93d5f0,0x400),(0x87a7c8,16)]]
 check('mode1-complete-prepared-state',got,want,c);check('mode1-downstream-ABI-order',events,model_events,c);transfer_cases.append(dict(context=c,source=source,target=target,camera=c.get('camera',False),initial=segs,nativeState=got,nativeEvents=events,nativeReturn=ret,nativeFault=fault))

def selector_model(vehicle,rider):
 ids=[0x7f1814,0x7f1850,0x7f1934,0x7f1938,0x7f193c,0x7f1940,0x7f1aa4,0x7f1944,0x7f1948,0x7f194c,0x7f1950,0x7f1954,0x7f19bc,0x7f1920];values=[rw(p)for p in ids];t=rw(vehicle+0x1064);clip=rd(rd(rider+0x50)+0xc)
 if t==values[0]:action=0x70
 elif t==values[1]:action=0x83
 elif not rd(0x7f39e4):ww(rider+0x7aa,0x6c);return
 elif rb(rd(rd(vehicle+0x54)+0x24)+0x116)==12:action=0xc4 if rw(vehicle+8+(0x34 if rb(vehicle+8+0x31)else 0x36))in [3,23]else 0xc3
 elif t in values[2:4]:action=0x70
 elif t==values[4]:action=0x83
 elif t in values[5:7]:action=0x84
 elif t==values[7]:action=0x86
 elif t==values[8]:action=0xc0
 elif t in values[9:11]:action=0xc1
 elif t==values[11]:action=0xc2 if rd(clip+0x308)else 0xc1
 elif t==values[12]:action=0xc1
 elif t==values[13]:action=0xc0
 else:ww(rider+0x7aa,0x6c);return
 ww(rider+0x7aa,action if rd(clip+action*4)else 0x6c)
for typeid,subtype,action,missing in itertools.product([100,111,114],[0,12],[3,23,-1],[False,True]):execute_transfer(dict(vehicleType=typeid,subtype=subtype,action=action,missingClips=missing,personalA=0,personalB=1,stateResults={str(B+0x2c8):1}))
unit=json.loads((native.BASE/'reports/script-phase9-20261013-native-fixtures.json').read_text());combined=dict(binarySha256=n.sha256,cases=transfer_cases,interop=[],selectorCases=unit['cases'])
report=dict(binarySha256=n.sha256,nativeChecks=sum(checks.values()),checks=checks,mismatches=len(errors),errors=errors,producerSelectorCases=len(transfer_cases),scope='Original4876a0 +487270 +62f1a0 +reset/clear; remaining script/animation/camera explicit adapters.')
(native.BASE/'reports/script-phase9-20261013-combined-fixtures.json').write_text(json.dumps(combined,indent=2));(native.BASE/'reports/script-phase9-20261013-interop-tests.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
