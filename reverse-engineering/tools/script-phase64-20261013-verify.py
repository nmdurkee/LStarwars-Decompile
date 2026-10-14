"""Player→locator single/nearest originalcallbacks, actor rawpresenceonly, actualdistance/square/sqrtchildren."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase61-20261013-verify.py').read_text().split('\nvalues61=')[0])
n=nm.NativeX86()
def execute64(address,c):
 global config,shadow,checks
 config=c;setup27(dict(c,callback=False),address);n.pack('<I',ACTOR+0xd0,0);n.pack('<I',SYS+0x138c,0 if c.get('noPlayer1')else REFERENCE);n.pack('<I',SYS+0x1390,0 if c.get('noPlayer2')else PLAYER261);n.pack('<I',P+0xa4,0 if c.get('noSelected')else LOC60)
 for p,key,default in[(LOC60+0x10,'a',[0.,0.,0.]),(REFERENCE+0x5c,'b',[3.,4.,0.]),(PLAYER261+0x5c,'c',[0.,100.,2.])]:n.pack('<3f',p,*c.get(key,default))
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};actor=0 if c.get('nullActor')else c.get('actor',ACTOR);system=0 if c.get('nullSystem')else SYS;packet=0 if c.get('nullPacket')else P;bound=c.get('bound',LOC60 if c.get('explicit')else 0);fault=False;want=0
 try:
  fallback=rd(0x75ecf0)
  if not actor or not system:want=fallback
  elif address==0x5155c0:
   player=rd(system+0x138c)
   if not player:want=fallback
   else:locator=bound or rd(packet+0xa4);want=distance60(player+0x5c,locator+0x10,False)if locator else fallback
  else:
   best=fl(fallback);locator=bound or rd(packet+0xa4)
   if locator:
    player=rd(system+0x138c)
    if player:best=square61(player+0x5c,locator+0x10,False)
    player=rd(system+0x1390)
    if player:
     other=square61(player+0x5c,locator+0x10,False)
     if other<best:best=other
   want=bits(best if best==n.unpack('<d',0x760008)[0]else math.sqrt(best))
  wd(OUT+0x40,want)
 except KeyError:fault=True
 mf=snapshot(True);nfault=False;got=0
 try:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(address,[system,packet,actor,TEXT,bound],count=4000000);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 except RuntimeError:nfault=True
 nf=snapshot()
 for group,a,b in [('fault',nfault,fault),('return',0 if nfault else got,0 if fault else want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(actor=actor,system=system,packet=packet,bound=bound),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=nf))
values64=[[0.,0.,0.],[1.,2.,3.],[-1.,-2.,-3.],[3.,4.,12.],[10000.,-9999.,.125],[2.**-20,-2.**-30,2.**-10]]
for address,b,c in itertools.product([0x5155c0,0x515620],values64,values64):execute64(address,dict(b=b,c=c))
rng=random.Random(0x5155c0620)
for address in[0x5155c0,0x515620]:
 for i in range(32):execute64(address,dict(a=[rng.uniform(-100000,100000)for _ in range(3)],b=[rng.uniform(-100000,100000)for _ in range(3)],c=[rng.uniform(-100000,100000)for _ in range(3)],explicit=i%2==0))
for address,c in itertools.product([0x5155c0,0x515620],[dict(nullActor=True,nullPacket=True),dict(nullSystem=True,nullPacket=True),dict(noPlayer1=True),dict(noPlayer2=True),dict(noPlayer1=True,noPlayer2=True),dict(noSelected=True),dict(explicit=True,nullPacket=True),dict(actor=0xdeadbeef),dict(bound=0xdeadbeef),dict(bound=0xdeadbeef,noPlayer1=True,noPlayer2=True),dict(noPlayer1=True,noPlayer2=True,nullPacket=True)]):execute64(address,c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=[],refinements=['515620'],closure='5becc0/5b3c50→5c0240→6e9530sqrt')
(nm.BASE/'reports/script-phase64-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase64-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
