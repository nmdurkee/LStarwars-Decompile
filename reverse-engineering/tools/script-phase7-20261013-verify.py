"""Inline native 4882d0 + unmodified 4871a0; explicit downstream ABI adapters.
Adapters are recorded, never counted as recovered callee implementations.
"""
import importlib.util,json,struct,itertools,random,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_EAX
n=native.NativeX86();D=n.DATA;A=D+0x1000;B=D+0x4000;DEF_A=D+0x8000;DEF_B=D+0x8100;CLASS_A=D+0x9000;CLASS_B=D+0x9200;MODEL_A=D+0xa000;MODEL_B=D+0xa200;SYS=D+0xb000;OUT=D+0xc000
cs=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for address,size in [(0x4882d0,0x360),(0x4871a0,93),(0x486f20,1)]:assembly.append(dict(address=hex(address),size=size,bytes=n.read(address,size).hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(address,size),address)]))
callees={0x4876a0:('Transfer',5),0x415000:('Rebind',1),0x55d2b0:('RefreshPose',1),0x5a01f0:('Eject',2),0x5a0320:('VehicleResponse',2),0x4c99b0:('DistanceFactor',2),0x561e20:('DirectedJump',6),0x54a3e0:('Camera',4),0x52c790:('ChangeReleasedState',2),0x52cc90:('RunScript',5)}
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
 name,count=callees[a];sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*count,sp+4));events.append(dict(name=name,args=args))
 if a==0x4876a0 and config.get('originalBlockedTransfer'):return
 for p,value in config.get('patches',{}).get(name,[]):n.pack('<I',p,value)
 if name=='DistanceFactor':
  n.pack('<I',OUT+0x100,config.get('factorBits',bits(.375)));n.write(n.STOP+0x100,b'\xd9\x05'+struct.pack('<I',OUT+0x100)+b'\xc3');mu.reg_write(UC_X86_REG_EIP,n.STOP+0x100);return
 ret=config.get('transferResult',1)if name=='Transfer'else config.get('stateResults',{}).get(str(args[0]),0)if name=='ChangeReleasedState'else 0
 mu.reg_write(UC_X86_REG_EAX,ret);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,hook)
def service(name,args):
 model_events.append(dict(name=name,args=args))
 for p,value in config.get('patches',{}).get(name,[]):wd(p,value)
 return config.get('transferResult',1)if name=='Transfer'else config.get('stateResults',{}).get(str(args[0]),0)if name=='ChangeReleasedState'else 0
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
  n.write(actor,bytes(rng.randrange(256)for _ in range(0x1100)));n.pack('<I',actor+0x54,df);n.pack('<I',actor+0x50,mo);n.pack('<II',df+0xc,0x12345678,0);n.pack('<I',df+0x24,cl);n.pack('<I',actor+0x1fc,c.get('flagA'if actor==A else'flagB',0x81234567));n.pack('<B',actor+0x280,c.get('personalA'if actor==A else'personalB',255));n.pack('<I',actor+0xe20,0xffffffff);n.pack('<3f',actor+0x5c,1.25 if actor==A else-8.,2.5,3.75);n.pack('<f',actor+0x194,17.25);n.pack('<f',actor+0x6c,c.get('velocityA'if actor==A else'velocityB',3.5 if actor==A else-7.25));n.pack('<B',cl+0x113,c.get('seat',-1)&255);n.pack('<I',cl+0x28,c.get('classBits',bits(1.)));n.pack('<I',cl+0x94,c.get('classFlags',0));n.pack('<B',actor+0xef4,c.get('skipTransfer',False)*2);n.pack('<H',actor+0x1064,77);n.pack('<H',actor+0x58,0xabcd if actor==A else 0x1357)
  index=c.get('seat',-1)
  if index!=-1:n.pack('<I',mo+0x14+index*4,1 if c.get('matrix',True)else 0);n.pack('<III',actor+0x834+index*64,0x3f800001,0x80000000,0x7fc54321)
 n.pack('<II',A+0xcd0,B,0);n.pack('<I',B+0xcd0,A);n.pack('<B',A+0x7b5,c.get('contextA',59));n.pack('<B',B+0x7b5,c.get('contextB',0));n.pack('<I',0x951c5c,1 if c.get('originalBlockedTransfer')else 0);n.pack('<I',0x802c54,SYS);n.pack('<I',0x8021b4,D+0xd000);n.pack('<H',0x7f1914,77 if c.get('special',False)else 88);n.pack('<I',SYS+0x128,c.get('level',123));n.pack('<I',0x87b234,c.get('levelGate',123));n.pack('<I',SYS+0x2ae8,D+0xe000);n.pack('<I',0x925018,bits(.016));n.pack('<II',0x7fa56c,bits(11.25),bits(2.75))
 if c.get('noLink'):n.pack('<I',(B if c.get('inputB')else A)+0xcd0,0)
 if c.get('selfLink'):n.pack('<I',(B if c.get('inputB')else A)+0xcd0,B if c.get('inputB')else A)
 if c.get('nullDef'):n.pack('<I',B+0x54,0)
 segs=[dict(address=p,bytes=n.read(p,z).hex())for p,z in [(A,0x1100),(B,0x1100),(DEF_A,0x100),(DEF_B,0x100),(CLASS_A,0x200),(CLASS_B,0x200),(MODEL_A-0x200,0x500),(SYS+0x128,4),(SYS+0x2ae8,4),(OUT,12),(0x802c54,4),(0x8021b4,4),(0x7f1914,2),(0x87b234,4),(0x925018,4),(0x7fa56c,8)]]
 return segs
def execute(c):
 global config,events,shadow,model_events
 config=c;events=[];segs=prepare(c);shadow={}
 for seg in segs:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 inp=0 if c.get('nullInput')else B if c.get('inputB')else A;model_events=[];fault=None;model_fault=None
 try:model(inp)
 except RuntimeError as e:model_fault=str(e)
 try:n.call(0x4882d0,[inp])
 except RuntimeError as e:fault=str(e)
 check('native-fault-parity',fault is not None,model_fault is not None,c)
 got=[n.read(p,0x1100).hex()for p in [A,B]];want=[bytes(rb(p+i)for i in range(0x1100)).hex()for p in [A,B]]
 check('inline-complete-actor-state',got,want,c);check('downstream-ABI-order',events,model_events,c)
 cases.append(dict(context=c,input=inp,initial=segs,nativeActors=got,nativeEvents=events,nativeFault=fault))
# Branches, role orientation, packet/body aliasing, callee writes, early faults.
for c in [dict(noLink=True),dict(transferResult=0),dict(nullDef=True,skipTransfer=True)]:execute(c)
for c in [dict(nullInput=True),dict(originalBlockedTransfer=True,transferResult=0),dict(selfLink=True,skipTransfer=True),dict(selfLink=True,inputB=True),dict(special=True,levelGate=999),dict(skipTransfer=True,seat=0,matrix=False)]:execute(c)
for skip,inputB,special,cls,flags,personal,seatidx in itertools.product([False,True],[False,True],[False,True],[bits(-1.),0,bits(2.),0x7fc12345],[0,0x20000],[False,True],[-1,0]):
 c=dict(skipTransfer=skip,inputB=inputB,special=special,classBits=cls,classFlags=flags,personalA=0 if personal else 255,seat=seatidx,seed=13,flagA=0xaabbcd00,flagB=0x11223200)
 # Native caller snapshots before these injected transfer mutations.
 c['patches']={'Transfer':[[A+0x2c8,0x11112222],[B+0x2c8,0x33334444],[A+0x1fc,0xdeadbeef],[B+0x1fc,0xcafebabe]],'Rebind':[[A+0x1fc,0x01010101],[B+0x1fc,0x02020202]],'RefreshPose':[[A+0x6c,bits(1.75)],[B+0x6c,bits(-2.25)]],'Eject':[[A+0x5c,bits(31.)],[B+0x5c,bits(-47.)]],'ChangeReleasedState':[[A+0x32c,0x98765432],[B+0x32c,0x76543210]]}
 c['stateResults']={str(A+0x2c8):1,str(B+0x2c8):1};execute(c)
for seatidx,matrix,ctx in itertools.product([-2,-1,0,1,2],[False,True],[0,58,59,60,255]):execute(dict(seat=seatidx,matrix=matrix,contextA=ctx,skipTransfer=True))
# Source-visible state mutation ordering and return-zero retained state.
for transferResult in [0,1]:
 for p in [A,B]:execute(dict(transferResult=transferResult,patches={'Transfer':[[p+0xcd0,0],[p+0x2c8,0x87654321],[p+0x378,0x10203040]],'Rebind':[[A+0xcd0,0]],'RunScript':[[B+0x2c8,0x11223344]]},stateResults={str(A+0x2c8):1,str(B+0x2c8):0}))
for va,vb in itertools.product([0.,-0.,1.,-1.,16777216.,1.0000001192092896],[0.,-0.,1.,-1.,16777216.,1.0000001192092896]):execute(dict(skipTransfer=True,velocityA=va,velocityB=vb))
# Standalone real seat projection including output overlap and negative index backing.
for seatidx,matrix,overlap in itertools.product([-2,-1,0,1,2],[False,True],[0,1,2,3]):
 c=dict(seat=seatidx,matrix=matrix);segs=prepare(c);out=OUT if overlap==0 else A+0x834+seatidx*64+overlap*4 if seatidx!=-1 else A+0x5c+overlap*4
 shadow={}
 for seg in segs:
  for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
 for i in range(12):shadow.setdefault(out+i,0)
 seat(A,out);n.call(0x4871a0,[A,out]);got=n.read(out,12).hex();want=bytes(rb(out+i)for i in range(12)).hex();check('unmodified-seat-overlap',got,want,c);seats.append(dict(context=c,actor=A,output=out,initial=segs,native=got))
# Identity stub must preserve EAX even with bogus name arguments.
for eax in [0,A,B,0xffffffff]:check('486f20-ret-preserves-eax',n.call(0x486f20,[0,0xffffffff],{UC_X86_REG_EAX:eax}),eax)
report=dict(binarySha256=n.sha256,nativeChecks=sum(checks.values()),checks=checks,mismatches=len(errors),errors=errors,releaseCases=len(cases),seatCases=len(seats),adapters={hex(a):dict(name=v[0],argc=v[1])for a,v in callees.items()},limitations=['Downstream callees are explicit recorded ABI adapters; this tests original inline release and unmodified seat helper, not callee implementations.','Finite arithmetic/fallback seat domain; native faults and all prepared mutations retained.'])
for suffix,obj in [('tests',report),('native-fixtures',dict(binarySha256=n.sha256,cases=cases,seats=seats)),('assembly',dict(binarySha256=n.sha256,functions=assembly))]:
 (native.BASE/'reports'/('script-phase7-20261013-'+suffix+'.json')).write_text(json.dumps(obj,indent=2))
print(json.dumps(report))
