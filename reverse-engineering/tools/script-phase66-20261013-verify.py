"""Original515290yaw→actualin-place5b3620→actual5be2d0/tablequadrant; untouchedtrigtables dependencies."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase51-20261013-verify.py').read_text().split('\nfor address,flags,ref')[0])
angleSpec=importlib.util.spec_from_file_location('yaw_angles',Path(__file__).with_name('gameplay-path-angle-verify.py'));angles=importlib.util.module_from_spec(angleSpec);angleSpec.loader.exec_module(angles)
n=nm.NativeX86();sineBytes=(nm.BASE/'references/native-animation-sine-table.f32').read_bytes();sines=struct.unpack('<32768f',sineBytes);n.write(0x29899a0,sineBytes);segments+=[(0x760010,4),(0x760018,8)]
def yaw66(actor):
 if not actor or not rd(actor+0xe4):return rd(0x760010)
 opponent=rd(actor+0xe4);control=rd(actor+0xd0);x=w.store(w.add(w.wide(fl(rd(opponent+0x5c))),w.wide(-fl(rd(control+0x5c)))));z=w.store(w.add(w.wide(fl(rd(opponent+0x64))),w.wide(-fl(rd(control+0x64)))));heading=-(rb(control+0x27a)|(rb(control+0x27b)<<8));s=sines[(heading>>1)&32767];c=sines[((heading+0x4000)>>1)&32767];rx=w.store(w.add(w.mul(w.wide(s),w.wide(z)),w.mul(w.wide(c),w.wide(x))));rz=w.store(w.add(w.mul(w.wide(z),w.wide(c)),w.mul(w.wide(-1.),w.mul(w.wide(x),w.wide(s)))));angle=angles.direction(rx,rz);return bits(w.store(w.mul(w.wide(angle),w.wide(n.unpack('<d',0x760018)[0]))))
def execute66(c):
 global config,shadow,checks
 config=c;setup27(dict(c,callback=False),0x515290);n.pack('<I',ACTOR+0xe4,0 if c.get('noOpponent')else REFERENCE);n.pack('<I',ACTOR+0xd0,0 if c.get('noController')else CONTROL);n.pack('<3f',REFERENCE+0x5c,*c.get('a',[1.,2.,3.]));n.pack('<3f',CONTROL+0x5c,*c.get('b',[0.,0.,0.]));n.pack('<H',CONTROL+0x27a,c.get('heading',0));initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};actor=0 if c.get('nullActor')else ACTOR;fault=False;want=0
 try:want=yaw66(actor);wd(OUT+0x40,want)
 except KeyError:fault=True
 mf=snapshot(True);nfault=False;got=0
 try:n.pack('<I',0x1000dff8,0);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(0x515290,[SYS,P,actor,TEXT,0],count=4000000);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 except RuntimeError:nfault=True
 nf=snapshot()
 for group,a,b in [('fault',nfault,fault),('return',0 if nfault else got,0 if fault else want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(actor=actor),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=nf))
values66=[[0.,0.,0.],[1.,0.,0.],[-1.,0.,0.],[0.,0.,1.],[0.,0.,-1.],[1.,9999.,1.],[-1.,-9999.,1.],[1.,1234.,-1.],[-1.,-1234.,-1.],[1e-20,0.,-1e-20]]
for a,heading in itertools.product(values66,[0,1,2,16383,16384,16385,32767,32768,32769,49151,49152,65534,65535]):execute66(dict(a=a,heading=heading))
rng=random.Random(0x515290)
for i in range(64):execute66(dict(a=[rng.uniform(-100000,100000)for _ in range(3)],b=[rng.uniform(-100000,100000)for _ in range(3)],heading=rng.randrange(65536)))
for c in[dict(nullActor=True),dict(noOpponent=True,noController=True),dict(noController=True)]:execute66(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=[],tables=dict(sine='references/native-animation-sine-table.f32',sineSha256=hashlib.sha256(sineBytes).hexdigest(),angle='reports/gameplay-path-angle-table.u16',angleSha256=hashlib.sha256(n.read(0x8066c8,1026)).hexdigest()),closure='actual5b3620in-place rotation→5be2d0→5be030 originalangle table')
(nm.BASE/'reports/script-phase66-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase66-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,tables=report['tables'],cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
