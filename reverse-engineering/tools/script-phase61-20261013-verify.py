"""Player/nearest rangecallbacks +originalsquaremath5b3c50/5b3cf0 andsqrt5c0240/6e9530."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase60-20261013-verify.py').read_text().split('\nvalues60=')[0])
n=nm.NativeX86();PLAYER261=D+0xc000;segments.append((0x760008,8))
def square61(a,b,xz):
 x=[]
 for i,(left,right)in enumerate(zip(vector60(a),vector60(b))):x.append(0. if xz and i==1 else w.store(w.add(w.wide(left),w.wide(-right))))
 return w.dot3_plus_constant(*x,*x,0.)
def execute61(address,c):
 global config,shadow,checks
 config=c;setup27(dict(c,callback=False),address);n.pack('<I',ACTOR+0xd0,0 if c.get('noController')else c.get('controller',CONTROL));n.pack('<I',SYS+0x138c,0 if c.get('noPlayer1')else REFERENCE);n.pack('<I',SYS+0x1390,0 if c.get('noPlayer2')else PLAYER261)
 for p,key,default in[(ACTOR+0x14c,'actorPosition',[1234.,1234.,1234.]),(CONTROL+0x5c,'a',[0.,0.,0.]),(REFERENCE+0x5c,'b',[3.,4.,0.]),(PLAYER261+0x5c,'c',[0.,100.,2.])]:n.pack('<3f',p,*c.get(key,default))
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};actor=0 if c.get('nullActor')else ACTOR;system=0 if c.get('nullSystem')else SYS;fault=False;want=0
 try:
  fallback=rd(0x75ecf0);control=rd(actor+0xd0)if actor else 0
  if not actor or not control or not system:want=fallback
  else:
   player=rd(system+0x138c)
   if address==0x514c30:want=distance60(player+0x5c,control+0x5c,False)if player else fallback
   else:
    xz=address==0x514d50;best=square61(player+0x5c,control+0x5c,xz)if player else fl(fallback);player=rd(system+0x1390)
    if player:
     other=square61(player+0x5c,rd(actor+0xd0)+0x5c,xz)
     if other<best:best=other
    want=bits(best if best==n.unpack('<d',0x760008)[0]else math.sqrt(best))
  wd(OUT+0x40,want)
 except KeyError:fault=True
 mf=snapshot(True);nfault=False;got=0
 try:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(address,[system,P,actor,TEXT,0],count=4000000);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 except RuntimeError:nfault=True
 nf=snapshot()
 for group,a,b in [('fault',nfault,fault),('return',0 if nfault else got,0 if fault else want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(actor=actor,system=system),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=nf))
values61=[[0.,0.,0.],[1.,2.,3.],[-1.,-2.,-3.],[3.,4.,12.],[10000.,-9999.,.125],[2.**-20,-2.**-30,2.**-10]]
for address,b,c in itertools.product([0x514c30,0x514c80,0x514d50],values61,values61):execute61(address,dict(b=b,c=c))
rng=random.Random(0x514c8050)
for address in[0x514c30,0x514c80,0x514d50]:
 for i in range(32):execute61(address,dict(a=[rng.uniform(-100000,100000)for _ in range(3)],b=[rng.uniform(-100000,100000)for _ in range(3)],c=[rng.uniform(-100000,100000)for _ in range(3)]))
for address,c in itertools.product([0x514c30,0x514c80,0x514d50],[dict(nullActor=True),dict(noController=True),dict(nullSystem=True),dict(noPlayer1=True),dict(noPlayer2=True),dict(noPlayer1=True,noPlayer2=True),dict(controller=0xdeadbeef)]):execute61(address,c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=[],refinements=['514c30','514c80'],closure='5b3c50/5b3cf0sqmath→5c0240→6e9530sqrt')
(nm.BASE/'reports/script-phase61-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase61-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
