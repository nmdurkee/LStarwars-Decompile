"""Originalopponent→locator3D/XZ/Y callbacks, wholemathchildren, no ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase60-20261013-verify.py').read_text().split('\nvalues60=')[0])
n=nm.NativeX86()
def execute63(address,c):
 global config,shadow,checks
 config=c;setup27(dict(c,callback=False),address);n.pack('<I',ACTOR+0xe4,0 if c.get('noOpponent')else c.get('opponent',REFERENCE));n.pack('<I',ACTOR+0xd0,0);n.pack('<I',REFERENCE+4,0 if c.get('noOpponentController')else 0xdeadbeef);n.pack('<I',P+0xa4,0 if c.get('noSelected')else LOC60)
 for p,key,default in[(REFERENCE+0x5c,'a',[1.,2.,3.]),(LOC60+0x10,'b',[4.,6.,8.]),(ACTOR+0x14c,'actorPosition',[1234.,1234.,1234.])]:n.pack('<3f',p,*c.get(key,default))
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};actor=0 if c.get('nullActor')else ACTOR;packet=0 if c.get('nullPacket')else P;bound=LOC60 if c.get('explicit')else 0;fault=False;want=0
 try:
  opponent=rd(actor+0xe4)if actor else 0
  if not actor or not opponent:want=rd(0x75ecf0)
  else:
   locator=bound or rd(packet+0xa4)
   if not locator:want=rd(0x75ecf0)
   elif address==0x515580:
    a=rd(opponent+0x60);b=rd(locator+0x14);want=0x80000000 if a==0x80000000 and b==0 else bits(w.store(w.add(w.wide(fl(a)),w.wide(-fl(b)))))
   else:want=distance60(opponent+0x5c,locator+0x10,address==0x515530)
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
values63=[[0.,0.,0.],[0.,-0.,0.],[1.,2.,3.],[-1.,-2.,-3.],[3.,4.,12.],[2.**-20,-2.**-30,2.**-10]]
for address,a,b in itertools.product([0x5154e0,0x515530,0x515580],values63,values63):execute63(address,dict(a=a,b=b))
rng=random.Random(0x5154e0530)
for address in[0x5154e0,0x515530,0x515580]:
 for i in range(32):execute63(address,dict(a=[rng.uniform(-100000,100000)for _ in range(3)],b=[rng.uniform(-100000,100000)for _ in range(3)],explicit=i%2==0))
for address,c in itertools.product([0x5154e0,0x515530,0x515580],[dict(nullActor=True,nullPacket=True),dict(noOpponent=True,nullPacket=True),dict(noSelected=True),dict(explicit=True,nullPacket=True),dict(noOpponentController=True),dict(opponent=0xdeadbeef)]):execute63(address,c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=[],refinements=['515530','515580'],closure='5becc0/5bed80→5c0240→6e9530sqrt;YactualFSUB/FSTP')
(nm.BASE/'reports/script-phase63-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase63-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
