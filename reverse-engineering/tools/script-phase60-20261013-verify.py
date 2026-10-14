"""Rawlocator/node rangecallbacks→actual5becc0/5bed80 scratchmath→actual5c0240/6e9530sqrt."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase51-20261013-verify.py').read_text().split('\nfor address,flags,ref')[0])
import math
n=nm.NativeX86();LOC60=D+0xb000;NODE60=D+0xb200;segments.append((0x75ecf0,4))
def vector60(p):return [fl(rd(p+i*4))for i in range(3)]
def distance60(a,b,xz):
 x=[]
 for i,(left,right)in enumerate(zip(vector60(a),vector60(b))):x.append(0. if xz and i==1 else w.store(w.add(w.wide(left),w.wide(-right))))
 square=w.dot3_plus_constant(*x,*x,0.);return bits(math.sqrt(square))
def execute60(address,c):
 global config,shadow,checks
 config=c;setup27(dict(c,callback=False),address);n.pack('<I',ACTOR+0xd0,0 if c.get('noController')else c.get('controller',CONTROL));n.pack('<I',P+0xa4,0 if c.get('noSelected')else LOC60)
 for p,key in[(ACTOR+0x14c,'a'),(CONTROL+0x5c,'controllerPosition'),(LOC60+0x10,'b'),(NODE60+4,'b')]:n.pack('<3f',p,*c.get(key,c.get('a',[1.,2.,3.])if key=='controllerPosition'else [4.,6.,8.]if key=='b'else [1.,2.,3.]))
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};actor=0 if c.get('nullActor')else ACTOR;packet=0 if c.get('nullPacket')else P;bound=0 if c.get('noBound')else NODE60 if address==0x514f50 else LOC60 if c.get('explicit')else 0;fault=False;want=0
 try:
  controller=rd(actor+0xd0)if actor else 0
  if not actor or not controller:want=rd(0x75ecf0)
  elif address==0x514f50:want=distance60(bound+4,controller+0x5c,False)if bound else rd(0x75ecf0)
  else:
   locator=bound or rd(packet+0xa4);want=distance60(actor+0x14c,locator+0x10,address==0x514a50)if locator else rd(0x75ecf0)
  wd(OUT+0x40,want)
 except KeyError:fault=True
 mf=snapshot(True);nfault=False;got=0
 try:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(address,[SYS,packet,actor,TEXT,bound],count=4000000);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 except RuntimeError:nfault=True
 nf=snapshot()
 for group,a,b in [('fault',nfault,fault),('return',0 if nfault else got,0 if fault else want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(actor=actor,packet=packet,bound=bound),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=nf))
values60=[[0.,0.,0.],[1.,2.,3.],[-1.,-2.,-3.],[10000.,-9999.,.125],[2.**-20,-2.**-30,2.**-10],[3.,4.,12.]]
for address,a,b in itertools.product([0x514a00,0x514a50,0x514f50],values60,values60):execute60(address,dict(a=a,b=b))
rng=random.Random(0x514a0050)
for address in[0x514a00,0x514a50,0x514f50]:
 for i in range(32):execute60(address,dict(a=[rng.uniform(-100000,100000)for _ in range(3)],b=[rng.uniform(-100000,100000)for _ in range(3)],controllerPosition=[rng.uniform(-100000,100000)for _ in range(3)],explicit=i%2==0))
for address,c in itertools.product([0x514a00,0x514a50,0x514f50],[dict(nullActor=True,nullPacket=True),dict(noController=True,nullPacket=True),dict(noSelected=True),dict(noBound=True),dict(explicit=True,nullPacket=True),dict(controller=0xdeadbeef)]):execute60(address,c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=[],refinements=['514a00','514a50'],closure='actualmath5becc0/5bed80→5c0240→6e9530sqrt')
(nm.BASE/'reports/script-phase60-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase60-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
