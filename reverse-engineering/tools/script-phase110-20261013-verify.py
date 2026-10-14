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
 for i in range(4):shadow[p+i]=(v>>(i*8))&255
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
def execute(address,c):
 global shadow,segments,checks
 n.write(D,bytes(0x30000));selector=c.get('selector',0);record=BASE+min(selector,254)*0xa4
 if c.get('recordAlias'):record=ACTOR+0xd8
 angle=c.get('angle',0);si=(angle>>1)&0x7fff;ci=((angle+0x4000)>>1)&0x7fff
 segments=[(SYS,0x1400),(ACTOR,0x300),(REF,0x100),(OUT,4),(record,0xa4),(0x923908,4),(0x75ecf0,4),(TABLE+si*4,4),(TABLE+ci*4,4)]
 # record/actor overlap is one shared image, avoid duplicate overlapping region representations.
 if c.get('recordAlias'):segments.pop(4)
 n.pack('<I',SYS+0x18,(record-selector*0xa4)&0xffffffff);n.pack('<I',SYS+0x138c,0 if c.get('noPlayer')else REF);n.pack('<I',ACTOR+0xe4,0 if c.get('noOpponent')else REF)
 n.pack('<3f',ACTOR+0x14c,*c.get('actorPosition',[1.,2.,3.]));n.pack('<3f',REF+0x5c,*c.get('referencePosition',[4.,6.,8.]));n.pack('<3f',record+0x20,*c.get('baseOrigin',[7.,8.,9.]));n.pack('<I',record+0x2c,angle&0xffffffff);n.pack('<2f',record+0x5c,*c.get('spacing',[2.,3.]));n.pack('<f',TABLE+si*4,c.get('sine',0.));n.pack('<f',TABLE+ci*4,c.get('cosine',1.))
 n.write(ACTOR+0x138,bytes([selector]));n.write(ACTOR+0x149,bytes([c.get('column',1),c.get('row',2)]));n.pack('<I',ACTOR+0x1ec,c.get('flags',0x12345000));n.pack('<I',0x923908,0x43c3a0)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};system=0 if c.get('nullSystem')else SYS;actor=0 if c.get('nullActor')else ACTOR;wanted=[];got=[]
 for tick in range(2):
  if tick:
   for p,z,v in c.get('patches',[]):
    for i in range(z):shadow[p+i]=(v>>(i*8))&255
  value=evaluate(address,system,actor)
  if address!=0x43c3a0:wd(OUT,value)
  wanted.append(value)
 model=snap(True)
 for tick in range(2):
  if tick:
   for p,z,v in c.get('patches',[]):n.write(p,int(v).to_bytes(z,'little'))
  if address==0x43c3a0:value=n.call(address,[system,actor])
  else:
   n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(address,[system,0,actor,0,0],count=4000000);n.mu.emu_start(n.STOP,n.STOP+6);value=n.unpack('<I',OUT)[0]
  got.append(value)
 native=snap()
 for group,a,b in [('returns',got,wanted),('images',native,model)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(system=system,actor=actor),initial=initial,returnValues=got,final=native))
for selector,column,row,angle in itertools.product([0,1,254,255],[0,1,2,3,254,255],[0,255],[0,1,0x4000,0x8000,0xffff,-1,0x7fffffff]):execute(0x43c3a0,dict(selector=selector,column=column,row=row,angle=angle,sine=.25,cosine=-.75))
for c in[dict(nullSystem=True),dict(nullActor=True),dict(flags=8),dict(selector=255,flags=8),dict(recordAlias=True),dict(spacing=[-0.,0.],sine=-0.,cosine=0.,baseOrigin=[-0.,-0.,-0.]),dict(patches=[[ACTOR+0x149,1,255],[BASE+0x20,4,bits(999.)]]),dict(patches=[[ACTOR+0x1ec,4,0],[BASE+0x20,4,bits(999.)]])]:execute(0x43c3a0,c)
rng=random.Random(0x43c3a0110)
for i in range(80):execute(0x43c3a0,dict(selector=rng.choice([0,1,254]),column=rng.randrange(256),row=rng.randrange(256),angle=rng.randrange(-0x80000000,0x80000000),sine=rng.uniform(-1,1),cosine=rng.uniform(-1,1),spacing=[rng.uniform(-1000,1000)for _ in range(2)],baseOrigin=[rng.uniform(-1000,1000)for _ in range(3)]))
for address,c in itertools.product([0x515360,0x5153c0,0x515450],[{},dict(selector=255),dict(nullActor=True),dict(nullSystem=True),dict(noOpponent=True),dict(noPlayer=True),dict(column=255,row=255,angle=-1,sine=.25,cosine=-.75),dict(flags=8),dict(patches=[[ACTOR+0x1ec,4,0],[BASE+0x20,4,bits(999.)]])]):execute(address,c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=[],closure='actual43c3a0→5b3620/5b37d0; real515360/5153c0/515450→43c3a0→actual distance/sqrt')
(nm.BASE/'reports/script-phase110-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase110-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
