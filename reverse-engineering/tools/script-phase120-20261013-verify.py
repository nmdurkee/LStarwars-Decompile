"""Original registered43c3a0 and three real origin predicates; no native adapters."""
import importlib.util,json,struct,itertools,random,math
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
s=importlib.util.spec_from_file_location('w',Path(__file__).with_name('animation-x87.py'));w=importlib.util.module_from_spec(s);s.loader.exec_module(w)
D=n.DATA;SYS=D+0x1000;ACTOR=D+0x3000;REF=D+0x4000;BASE=D+0x10000;OUT=D+0x5000;TABLE=0x29899a0
checks=0;errors=[];cases=[];shadow={};segments=[]
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def fl(b):return struct.unpack('<f',struct.pack('<I',b))[0]
def rb(p):return shadow[p]
def rd(p):return sum(rb(p+i)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):
  if p+i not in shadow:raise KeyError(p+i)
  shadow[p+i]=(v>>(i*8))&255
def product(a,b):return fl((bits(a)^bits(b))&0x80000000)if a==0 or b==0 else w.store(w.mul(w.wide(a),w.wide(b)))
def add(a,b):return fl(bits(a)&bits(b)&0x80000000)if a==0 and b==0 else w.store(w.add(w.wide(a),w.wide(b)))
def products(a,b,c,d):return fl((bits(a)^bits(b))&(bits(c)^bits(d))&0x80000000)if(a==0 or b==0)and(c==0 or d==0)else w.store(w.add(w.mul(w.wide(a),w.wide(b)),w.mul(w.wide(c),w.wide(d))))
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def origin(system,actor):
 if not system or not actor:return 0
 selector=rb(actor+0x138)
 if selector==255:return 0
 if not rb(actor+0x1ec)&8:
  record=(rd(system+0x18)+selector*0xa4)&0xffffffff;column=rb(actor+0x149);x=product((column+1)//2,fl(rd(record+0x5c)))
  if column&1:x=fl(bits(x)^0x80000000)
  z=product(rb(actor+0x14a),fl(rd(record+0x60)^0x80000000));angle=rd(record+0x2c);ci=((angle+0x4000)>>1)&0x7fff;si=(angle>>1)&0x7fff;c=fl(rd(TABLE+ci*4));s=fl(rd(TABLE+si*4));rx=products(s,z,c,x);rz=products(c,z,fl(bits(s)^0x80000000),x)
  for i,value in enumerate([rx,0.,rz]):wd(actor+0xf8+i*4,bits(add(value,fl(rd(record+0x20+i*4)))))
  wd(actor+0x1ec,rd(actor+0x1ec)|8)
 return(actor+0xf8)&0xffffffff

def distance(a,b):
 delta=[add(fl(rd(a+i*4)),-fl(rd(b+i*4)))for i in range(3)]
 return bits(math.sqrt(w.dot3_plus_constant(*delta,*delta,0.)))
def evaluate(address,system,actor):
 if address==0x43c3a0:return origin(system,actor)
 fallback=0 if address==0x515360 else rd(0x75ecf0)
 if not actor or address==0x5153c0 and not rd(actor+0xe4)or address==0x515450 and(not system or not rd(system+0x138c)):return fallback
 selected=origin(system,actor)
 if not selected:
  if not system:return fallback
  selector=rb(actor+0x138)
  if selector==255:return fallback
  selected=rd(system+0x18)+selector*0xa4+0x20
 p=actor+0x14c if address==0x515360 else rd(actor+0xe4)+0x5c if address==0x5153c0 else rd(system+0x138c)+0x5c
 return distance(p,selected)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
CTRL=D+0x5000;ORIGIN120=D+0x6000;CB=n.STOP+0x700;events=[];config={}
def callback120(system,actor,model):
 events.append(dict(callback=CB,args=[system,actor]))
 for p,z,v in config.get('patches',[]):
  if model:
   for i in range(z):shadow[p+i]=(v>>(i*8))&255
  else:n.write(p,int(v).to_bytes(z,'little'))
 return config.get('callbackResult',ORIGIN120)
def hook120(mu,address,size,data):
 if address!=CB:return
 sp=mu.reg_read(UC_X86_REG_ESP);system,actor=n.unpack('<2I',sp+4);value=callback120(system,actor,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook120)
def execute_model(system,actor):
 if not actor or not system:return 1
 source=0;callback=rd(0x923908)
 if callback:source=origin(system,actor)if callback==0x43c3a0 else callback120(system,actor,True)
 controller=rd(actor+0xd0)
 if not source:
  if not controller or not rd(controller+0x1f8)&0x400:return 1
  selector=rb(actor+0x138)
  if selector==255:return 1
  source=(rd(system+0x18)+selector*0xa4+0x20)&0xffffffff
 output=(controller+0x5c)&0xffffffff
 for i in range(3):wd(output+i*4,rd(source+i*4))
 return 1
def execute120(c):
 global shadow,segments,checks,events,config
 config=c;n.write(D,bytes(0x30000));selector=c.get('selector',0);record=BASE+min(selector,254)*0xa4;controller=0 if c.get('noController')else CTRL
 if 'overlap'in c:controller=ORIGIN120+c['overlap']-0x5c
 callback=c.get('callback','none');cb=0 if callback=='none'else 0x43c3a0 if callback=='game'else CB
 n.pack('<I',SYS+0x18,(record-selector*0xa4)&0xffffffff);n.pack('<I',ACTOR+0xd0,controller);n.pack('<I',0x923908,cb);n.write(ACTOR+0x138,bytes([selector]));n.write(ACTOR+0x149,bytes([c.get('column',1),c.get('row',2)]));n.pack('<I',ACTOR+0x1ec,c.get('cacheFlags',0));n.pack('<I',record+0x2c,c.get('angle',0)&0xffffffff);n.pack('<2f',record+0x5c,*c.get('spacing',[2.,3.]));n.pack('<3I',record+0x20,*c.get('vectorBits',[bits(7.),bits(8.),bits(9.)]));n.pack('<3I',ORIGIN120,*c.get('customBits',[0x7fc01234,0x80000000,0xabcdef01]));n.pack('<f',TABLE+0x4000//2*4,1.);n.pack('<f',TABLE,0.)
 if controller:n.pack('<I',controller+0x1f8,c.get('controllerFlags',0x400))
 rawSegments=[(BASE+2*0xa4,0xa4),(SYS,0x40),(ACTOR,0x300),(record,0xa4),(ORIGIN120,0x100),(0x923908,4),(TABLE,4),(TABLE+0x8000,4)]
 if controller:rawSegments.append((controller,0x220))
 for p,z,v in c.get('patches',[]):rawSegments.append((p,z))
 merged=[]
 for p,z in sorted(rawSegments):
  if merged and p<=merged[-1][0]+merged[-1][1]:merged[-1][1]=max(merged[-1][1],p+z-merged[-1][0])
  else:merged.append([p,z])
 segments=[tuple(r)for r in merged];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};system=0 if c.get('nullSystem')else SYS;actor=0 if c.get('nullActor')else ACTOR;events=[];mfault=False;want=0
 try:want=execute_model(system,actor)
 except KeyError:mfault=True
 model=snap(True);me=events.copy();events=[];nfault=False;got=0
 try:got=n.call(0x516ac0,[system,0xdeadbeef,actor,0x87654321])
 except RuntimeError:nfault=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nfault,mfault),('return',0 if nfault else got,0 if mfault else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(system=system,actor=actor),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=native,nativeEvents=ne))
for callback,selector,flags,noController,nullSystem,nullActor in itertools.product(['none','game','custom'],[0,1,254,255],[0,0x400],[False,True],[False,True],[False,True]):execute120(dict(callback=callback,selector=selector,controllerFlags=flags,noController=noController,nullSystem=nullSystem,nullActor=nullActor))
for shift in[-8,-4,0,4,8]:execute120(dict(callback='custom',overlap=shift))
for c in[dict(callback='custom',callbackResult=0),dict(callback='custom',callbackResult=0,controllerFlags=0),dict(callback='custom',callbackResult=0,patches=[[ACTOR+0x138,1,255]]),dict(callback='custom',callbackResult=0,patches=[[ACTOR+0x138,1,1],[SYS+0x18,4,BASE+0xa4]]),dict(callback='custom',patches=[[ACTOR+0xd0,4,0]]),dict(callback='custom',patches=[[ACTOR+0xd0,4,ORIGIN120-0x5c]]),dict(callback='custom',patches=[[ACTOR+0x138,1,255]]),dict(callback='game',cacheFlags=8),dict(callback='game',column=255,row=255)]:execute120(c)
rng=random.Random(0x516ac0120)
for i in range(80):execute120(dict(callback='none',vectorBits=[rng.randrange(0x100000000)for _ in range(3)],selector=rng.choice([0,1,254])))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=['custom origin callback only when explicitly supplied'],closure='actual516ac0→registered43c3a0→rotation/addition; absent-callback fallback is raw DWORD copy')
(nm.BASE/'reports/script-phase120-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase120-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
