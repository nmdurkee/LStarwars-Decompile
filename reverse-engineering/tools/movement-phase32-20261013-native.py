"""Original pod frame motion/guards/pose excluding inline projectile-producing contexts."""
from pathlib import Path
import json,struct,gzip,base64,itertools,math,random
p22=Path(__file__).with_name('movement-phase22-20261013-native.py');q22={'__file__':str(p22)};exec(compile(p22.read_text().split('for mode,factor,delta in itertools.product')[0],str(p22),'exec'),q22)
p20=Path(__file__).with_name('movement-phase20-20261013-native.py');q20={'__file__':str(p20)};exec(compile(p20.read_text().split('for count,param in itertools.product')[0],str(p20),'exec'),q20)
n=q22['n'];m=q22['m'];D=n.DATA;SIZE=0x30000;POD=D+0x2000;ACT=D+0x4000;WORLD=D+0x8000;GAME=D+0x9000;CURVE=D+0xa000;TIME=D+0x10000;SCR=D+0xf0000;X=q22['X'];quant=q22['quant'];f32=q22['f32'];bits=q22['bits'];cfg32={};calls={}
q22.update(POD=POD,MATRIX=POD,D=D);q20.update(CURVE=CURVE,D=D)
from unicorn import UC_HOOK_CODE

def hook32(mu,a,size,user):
 if a in[0x4d9760,0x40eff0,0x5c0240,0x4d94f0,0x5b3470,0x5b40b0,0x5b4270,0x5b4430]:calls[hex(a)]=calls.get(hex(a),0)+1
 if a==0x4d97a7:n.pack('<I',mu.reg_read(m.UC_X86_REG_ESP)+0x1c,cfg32.get('stackWord',0))
n.mu.hook_add(UC_HOOK_CODE,hook32)
def setup32(c):
 global cfg32,ACT
 ACT=POD+c['poseOffset']-0xc04 if 'poseOffset'in c else D+0x4000
 cfg32=c;n.write(D,bytes([0xa5])*SIZE);n.write(POD,bytes(0xa0));n.write(ACT,bytes(0x10d8));n.pack('<I',POD+0x80,0 if c.get('inactive')else CURVE);n.pack('<I',POD+0x90,0 if c.get('nullActor')else ACT);n.pack('<I',ACT+0x1fc,c.get('actorFlags',1));n.pack('<B',ACT+0x28b,c.get('actorDisabled',0));n.pack('<I',0x882a6c,TIME);n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,GAME);n.pack('<I',0x87b090,GAME if c.get('special')else 0);n.pack('<I',0x882a70,c.get('mode',1));n.pack('<I',0x87b08c,0);n.pack('<H',0x7f1b1c,0x1234);n.pack('<f',0x925018,c.get('delta',f32(1/60)));n.pack('<f',0x7f15e0,c.get('lookAhead',f32(.001)));n.pack('<3f',TIME+0xb000,c.get('freeze',0),c.get('timer',.25),0);n.pack('<f',TIME+0xb00c,c.get('duration',1))
 matrix=c.get('matrix',[[1.,0.,0.,0.],[0.,1.,0.,0.],[0.,0.,1.,0.],[0.,0.,0.,1.]])
 for j,v in enumerate(matrix):n.pack('<4f',POD+j*16,*v)
 n.pack('<3f',POD+0x30,*c.get('position',[0.,0.,0.]));n.pack('<3f',POD+0x40,*c.get('velocity',[1.,0.,2.]));n.pack('<4f',POD+0x50,*c.get('target',[5.,0.,8.,1234.]));n.pack('<f',POD+0x7c,c.get('speed',3.5));n.pack('<f',POD+0x84,c.get('phase',.5));n.pack('<H',POD+0x88,7)
 count=c.get('count',4);points=c.get('points',[[f32(j*2),f32(j*.5),f32(j*3),f32(j*.125)]for j in range(count+2)])
 for j,v in enumerate(points):n.pack('<4f',CURVE+j*16,*v)
 n.pack('<I',CURVE+0x400,count);n.pack('<2f',CURVE+0x404,.25,-.5);n.pack('<I',0x93d810,0)
 if 'poseOffset'in c and c['poseOffset']<=0x90<c['poseOffset']+64:n.pack('<I',POD+0x90-c['poseOffset'],D+0x4000)
 calls.clear();return bytearray(n.read(D,SIZE))

def oracle32(c,img):
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 def b(p):return img[p-D]
 def f(p):return struct.unpack_from('<f',img,p-D)[0]
 def pf(p,v):struct.pack_into('<f',img,p-D,v)
 def div(a,b):return X(quant(a.v/b.v,64),a.neg!=b.neg)
 def commit():
  pf(POD+0x3c,1);actor=u(POD+0x90)
  if actor:
   for j in range(16):put(actor+0xc04+j*4,u(POD+j*4))
   actor=u(POD+0x90)
   for j in range(3):put(actor+0x5c+j*4,u(actor+0xc34+j*4))
   actor=u(POD+0x90)
   for j in range(3):put(actor+0x10bc+j*4,u(actor+0x5c+j*4))
 def difference():
  d=[(X.fl(f(POD+0x50+j*4))-X.fl(f(POD+0x30+j*4))).flstore()for j in range(3)];x,y,z=map(X.fl,d);square=(y*y+x*x+z*z).flstore();dot=(y*X.fl(f(POD+0x24))+x*X.fl(f(POD+0x20))+z*X.fl(f(POD+0x28))).flstore();return d,square,dot
 if not u(POD+0x80):return 0
 actor=u(POD+0x90)
 if not actor or not b(actor+0x1fc)&1 or b(actor+0x28b):img[POD-D:POD-D+0xa0]=bytes(0xa0);return 0
 if f(TIME+0xb000)>0:commit();return 1
 d,square,dot=difference()
 if f(POD+0x84)<=1:
  guard=0
  while square<1 or dot<0:
   guard+=1
   if guard>8192:raise ValueError('Nonterminating/out-of-domain lookahead')
   phase=(X.fl(f(POD+0x84))+X.fl(c.get('lookAhead',f32(.001)))).flstore();pf(POD+0x84,phase)
   if phase>1:pf(POD+0x84,1);break
   q20['normalized'](img,POD+0x50,phase);d,square,dot=difference()
 length=f32(math.sqrt(square));moved=False
 if f(POD+0x84)<1:
  if length!=0:
   speed=f(POD+0x7c);ratio=div(X.fl(f(TIME+0xb004)),X.fl(f(TIME+0xb00c))).flstore();ratio=min(ratio,1.)
   if c.get('special')and c.get('mode',1)==1:
    speed=div(X.fl(speed),X.fl(f32(.995))).flstore();desired=div(X.fl(speed)*X.fl(ratio),X.fl(f32(.01)))if ratio<f32(.01)else X.fl(speed)*X.fl(1.5)-(X.fl(ratio)-X.fl(f32(.01)))*X.fl(speed)
   else:desired=X.fl(speed)*X.fl(1.5)-X.fl(ratio)*X.fl(speed)
   target=desired.flstore();scale=div(X.fl(target),X.fl(length)).flstore()
   for j in range(3):pf(POD+0x40+j*4,(X.fl(scale)*X.fl(d[j])).flstore())
   moved=True
 else:moved=True
 if moved:
  for j in range(3):pf(SCR+j*4,(X.fl(c.get('delta',f32(1/60)))*X.fl(f(POD+0x40+j*4))).flstore())
  put(SCR+0xc,c.get('stackWord',0))
  for j in range(3):pf(POD+0x30+j*4,(X.fl(f(POD+0x30+j*4))+X.fl(f(SCR+j*4))).flstore())
  factor=div(X.fl(length),X.fl(5.)).flstore();q22['heading'](dict(source=SCR,factor=factor,delta=c.get('delta',f32(1/60)),mode=0),img)
  for j in range(4):put(POD+0x60+j*4,u(SCR+j*4))
 commit();return 1
vectors=[];errors=[]
def run32(c):
 before=setup32(c);expected=bytearray(before)+bytearray(0x100000-SIZE);ret=oracle32(c,expected);result=n.call(0x4d9760,[POD,WORLD],count=3000000);after=n.read(D,SIZE)
 if result!=ret or after!=expected[:SIZE]:errors.append(dict(input=c,result=[result,ret],diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:16]))
 vectors.append(dict(input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result,deltaBits=n.unpack('<I',0x925018)[0],lookAheadBits=n.unpack('<I',0x7f15e0)[0],nativeEntryCounts=dict(calls)))
for phase,special,timer in itertools.product([0.,.5,1.,1.5],[False,True],[.001,.01,.25,1.,2.]):run32(dict(phase=phase,special=special,timer=f32(timer)))
for c in[dict(inactive=True),dict(nullActor=True),dict(actorFlags=0),dict(actorDisabled=1),dict(freeze=1),dict(target=[0.,0.,0.,0.],phase=.999),dict(target=[0.,0.,-5.,0.],phase=.99)]:run32(c)
for phase,delta,special,timer,duration in itertools.product([-.125,0.,.75,.999,1.,1.25],[-.125,0.,f32(1/60),.25],[False,True],[f32(.001),f32(.01),f32(.25),1.,2.],[-1.,.125,1.]):run32(dict(phase=phase,delta=delta,special=special,timer=timer,duration=duration))
for flags,disabled,inactive,nullActor in itertools.product([0,1,2,3,0xffffffff],[0,1,128,255],[False,True],[False,True]):run32(dict(actorFlags=flags,actorDisabled=disabled,inactive=inactive,nullActor=nullActor))
for word in[0,1,0x80000000,0x7f800000,0x7fc12345,0x7f812345,0xffffffff]:run32(dict(stackWord=word))
r=random.Random(32)
for j in range(96):run32(dict(position=[f32(r.uniform(-20,20))for _ in range(3)],target=[f32(r.uniform(-20,20))for _ in range(3)]+[f32(r.uniform(-40000,40000))],velocity=[f32(r.uniform(-4,4))for _ in range(3)],phase=f32(r.uniform(0,1.5)),delta=f32(r.uniform(-.05,.2)),special=j%2==0,timer=f32(r.uniform(-.5,2)),duration=f32(r.uniform(.125,2)),speed=f32(r.uniform(-3,8))))
for offset in[-16,-4,0,4,16,32,52,64,80,88,96,112,128,144,160]:run32(dict(freeze=1,poseOffset=offset))
report=dict(status='unsealed motion-only native comparisons',binarySha256=n.sha256,cases=len(vectors),assertionGroups=2*len(vectors),mismatches=len(errors),errors=errors[:5]);(m.BASE/'reports/movement-phase32-20261013-draft-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:2])))

if errors:raise SystemExit('Pod motion mismatches; no paired fixture')
report.update(status='sealed qualified motion/guard/frozen-pose original comparisons; inline projectile remains open',nativeAdapters=0,limits=['Finite consumed motion/matrix/curve/phase/timer/delta arithmetic, representable angle conversions and bounded progressing curve look-ahead; valid full control/header backing and exact sine/513word angle tables.','Inactive/frozen branches copy raw integer words including signaling payloads without arithmetic; declared caller-stack displacement W supplied exactly. Forward pose-copy aliases and fresh actor-pointer retargets included.','Original normalized curve, heading/vector/matrix, square root, CRT and memcpy/memset execute unchanged; projectile-producing contexts excluded from this projection. Managed replay remains unexecuted.'])
(m.BASE/'reports/movement-phase32-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase32-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(sineTable='reverse-engineering/references/native-animation-sine-table.f32',angles=q22['angles'],vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(0x4d9760,0x4d9ec9-0x4d9760),0x4d9760)]
(m.BASE/'reports/movement-phase32-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=[dict(address='0x4d9760',size=0x4d9ec9-0x4d9760,instructions=ins)]),indent=2)+'\n')
