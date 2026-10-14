"""Actual514aa0 controllerY-locatorY +52d070 nullableboundlookupABI, final51ac10 service only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase51-20261013-verify.py').read_text().split('\nfor address,flags,ref')[0])
LOC53=D+0x9800;n=nm.NativeX86();config={}
def hook53(mu,address,size,data):
 if address!=0x51ac10:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<2I',sp+4));events.append(dict(callback=address,args=args));ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,config.get('bound',LOC53));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook53)
def execute53(c,method='Y'):
 global config,shadow,events,checks
 config=c;setup27(dict(c,text='name',callback=False),0x514aa0);n.pack('<I',ACTOR+0xd0,0 if c.get('nullController')else CONTROL);n.pack('<I',CONTROL+0x60,c.get('a',bits(3.)));n.pack('<I',ACTOR+0x150,bits(1234.));n.pack('<I',LOC53+0x14,c.get('b',bits(2.)));n.pack('<I',P+0xa4,0 if c.get('nullSelected')else LOC53);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];actor=0 if c.get('nullActor')else ACTOR;packet=0 if c.get('nullPacket')else P;bound=LOC53 if c.get('explicit')else 0;name=0 if c.get('nullName')else TEXT
 if method=='Bind':want=0 if not name else c.get('bound',LOC53);events=[]if not name else[dict(callback=0x51ac10,args=[SYS,name])]
 else:
  if not actor or not rd(actor+0xd0)or not bound and not rd(packet+0xa4):want=0
  else:a=rd(rd(actor+0xd0)+0x60);b=rd((bound or rd(packet+0xa4))+0x14);want=0x80000000 if a==0x80000000 and b==0 else bits(w.store(w.add(w.wide(fl(a)),w.mul(w.wide(fl(b)),w.wide(-1.)))))
  wd(OUT+0x40,want)
 mf=snapshot(True);me=events.copy();events=[]
 if method=='Bind':got=n.call(0x52d070,[SYS,name])
 else:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(0x514aa0,[SYS,packet,actor,TEXT,bound]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 nf=snapshot();ne=events.copy()
 for group,a,b in [('return',got,want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(system=SYS,name=name,actor=actor,packet=packet,bound=bound),initial=initial,returnValue=got,final=nf,nativeEvents=ne))
values53=[0,0x80000000,1,0x7fffff,0x3f800000,0xbf800000,0x7f7fffff,0xff7fffff];rng=random.Random(0x514aa0)
for i in range(24):
 value=rng.randrange(1<<32)
 if value&0x7f800000!=0x7f800000:values53.append(value)
for a,b,explicit in itertools.product(values53,values53[:8],[False,True]):execute53(dict(a=a,b=b,explicit=explicit))
for c in[dict(nullActor=True,nullPacket=True),dict(nullController=True,nullPacket=True),dict(nullSelected=True),dict(explicit=True,nullPacket=True)]:execute53(c)
for nullName,bound in itertools.product([False,True],[0,LOC53,0xffffffff]):execute53(dict(nullName=nullName,bound=bound),'Bind')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=['51ac10 finalboundlocatorlookup'])
(nm.BASE/'reports/script-phase53-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase53-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
