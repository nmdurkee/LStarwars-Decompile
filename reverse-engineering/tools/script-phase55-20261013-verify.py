"""Original515320 comparison withdouble threshold751788; packet/arguments ignored, unguarded controller."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase51-20261013-verify.py').read_text().split('\nfor address,flags,ref')[0])
n=nm.NativeX86();OP54=D+0x9800;segments.append((0x751788,8))
def execute54(c):
 global config,shadow,events,checks
 config=c;setup27(dict(c,callback=False),0x515320);n.pack('<I',ACTOR+0xe4,0 if c.get('noOpponent')else OP54);n.pack('<I',ACTOR+0xd0,0 if c.get('nullController')else CONTROL);n.pack('<I',OP54+0x60,c['b']);n.pack('<I',CONTROL+0x60,c['a']);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};actor=0 if c.get('nullActor')else ACTOR;fault=bool(actor and rd(actor+0xe4)and c.get('nullController'));want=0
 if actor and rd(actor+0xe4)and not fault:
  a=fl(c['a']);b=fl(c['b']);threshold=n.unpack('<d',0x751788)[0]
  if abs(a)==float('inf')or abs(b)==float('inf')or a!=a or b!=b:match=a-threshold>b
  else:
   left=w.add(w.wide(a),w.wide(-threshold));right=w.wide(b);e=min(left[1],right[1]);match=(left[0]<<(left[1]-e))>(right[0]<<(right[1]-e))
  want=bits(1.)if match else 0
 if not fault:wd(OUT+0x40,want)
 mf=snapshot(True);nfault=False;got=0
 try:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(0x515320,[SYS,P,actor,TEXT,0]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 except RuntimeError:nfault=True
 nf=snapshot()
 for group,a,b in [('fault',nfault,fault),('return',got,want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(actor=actor),initial=initial,fault=nfault,returnValue=got,final=nf))
values55=[0,0x80000000,1,0x80000001,0x7fffff,0x807fffff,bits(.1),bits(-.1),0x7f7fffff,0xff7fffff,0x7f800000,0xff800000,0x7fc12345]
for a,b in itertools.product(values55,values55):execute54(dict(a=a,b=b))
for exp in range(-149,1,3):
 tiny=bits(2.**exp)
 for a,b in [(bits(.1),tiny),(bits(.1),tiny|0x80000000),(tiny,bits(-.1)),(tiny|0x80000000,bits(-.1))]:execute54(dict(a=a,b=b))
rng=random.Random(0x51532055)
for i in range(128):
 a=rng.randrange(1<<32);b=rng.randrange(1<<32)
 if a&0x7f800000==0x7f800000 or b&0x7f800000==0x7f800000:continue
 execute54(dict(a=a,b=b))
for c in[dict(nullActor=True),dict(noOpponent=True,nullController=True),dict(nullController=True)]:execute54(dict(c,a=bits(3.),b=bits(2.)))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,ports=[],refinement='515320 exact64significand subtraction/order; fixes algebraicreassociation cancellation')
(nm.BASE/'reports/script-phase55-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase55-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
