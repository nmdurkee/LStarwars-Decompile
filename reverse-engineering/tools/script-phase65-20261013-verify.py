"""Original3origincallbacks, nullscratchactual5becc0/mathchildren, final923908 callback only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase60-20261013-verify.py').read_text().split('\nvalues60=')[0])
n=nm.NativeX86();ORIGIN65=D+0xf000;RECORDS65=D+0x10000;OTHER65=D+0xc000;CB65=n.STOP+0x700;segments+=[(D+0x10000,0xb000),(0x923908,4)];events=[]
def callback65(system,actor,model):
 events.append(dict(callback=CB65,args=[system,actor]))
 for p,size,value in config.get('patches',[]):
  if model:
   for i in range(size):wb(p+i,value>>(8*i))
  else:n.write(p,int(value).to_bytes(size,'little'))
 return config.get('originResult',ORIGIN65)
def hook65(mu,address,size,data):
 if address!=CB65:return
 sp=mu.reg_read(UC_X86_REG_ESP);system,actor=n.unpack('<2I',sp+4);value=callback65(system,actor,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook65)
def choose65(system,actor):
 if rd(0x923908):
  value=callback65(system,actor,True)
  if value:return value
 if not system:return 0
 selector=rb(actor+0x138);return 0 if selector==255 else(rd(system+0x18)+selector*0xa4+0x20)&0xffffffff

def execute65(address,c):
 global config,shadow,events,checks
 config=c;setup27(dict(c,callback=False),address);n.write(D+0x10000,bytes(0xb000));n.pack('<I',0x923908,CB65 if c.get('callback')else 0);n.pack('<I',SYS+0x18,RECORDS65);n.write(ACTOR+0x138,bytes([c.get('selector',0)]));n.pack('<I',ACTOR+0xe4,0 if c.get('noOpponent')else REFERENCE);n.pack('<I',SYS+0x138c,0 if c.get('noPlayer')else REFERENCE)
 for p,key,default in[(ACTOR+0x14c,'actorPosition',[1.,2.,3.]),(REFERENCE+0x5c,'referencePosition',[4.,6.,8.]),(OTHER65+0x5c,'otherPosition',[-1.,-2.,-3.]),(ORIGIN65,'origin',[0.,0.,0.])]+[(RECORDS65+i*0xa4+0x20,'fallbackOrigin',[7.,8.,9.])for i in[0,1,254]]:n.pack('<3f',p,*c.get(key,default))
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};system=0 if c.get('nullSystem')else SYS;actor=0 if c.get('nullActor')else ACTOR;events=[];fault=False;want=0
 try:
  fallback=0 if address==0x515360 else rd(0x75ecf0)
  if not actor or address==0x5153c0 and not rd(actor+0xe4)or address==0x515450 and(not system or not rd(system+0x138c)):want=fallback
  else:
   origin=choose65(system,actor)
   if not origin:want=fallback
   else:position=actor+0x14c if address==0x515360 else rd(actor+0xe4)+0x5c if address==0x5153c0 else rd(system+0x138c)+0x5c;want=distance60(position,origin,False)
  wd(OUT+0x40,want)
 except KeyError:fault=True
 mf=snapshot(True);me=events.copy();events=[];nfault=False;got=0
 try:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(address,[system,P,actor,TEXT,0],count=4000000);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 except RuntimeError:nfault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in [('fault',nfault,fault),('return',0 if nfault else got,0 if fault else want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(system=system,actor=actor),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=nf,nativeEvents=ne))
for address,callback,result,selector,nullSystem in itertools.product([0x515360,0x5153c0,0x515450],[False,True],[0,ORIGIN65],[0,1,254,255],[False,True]):execute65(address,dict(callback=callback,originResult=result,selector=selector,nullSystem=nullSystem))
rng=random.Random(0x51536065)
for address in[0x515360,0x5153c0,0x515450]:
 for i in range(16):execute65(address,dict(callback=True,actorPosition=[rng.uniform(-100000,100000)for _ in range(3)],referencePosition=[rng.uniform(-100000,100000)for _ in range(3)],origin=[rng.uniform(-100000,100000)for _ in range(3)]))
for address,c in itertools.product([0x515360,0x5153c0,0x515450],[dict(nullActor=True,callback=True),dict(noOpponent=True,callback=True),dict(noPlayer=True,callback=True),dict(callback=True,patches=[[ACTOR+0xe4,4,OTHER65]]),dict(callback=True,patches=[[SYS+0x138c,4,OTHER65]]),dict(callback=True,originResult=0,patches=[[ACTOR+0x138,1,255]]),dict(callback=True,originResult=0,patches=[[ACTOR+0x138,1,1]]),dict(callback=True,originResult=0,patches=[[SYS+0x18,4,RECORDS65+0xa4]]),dict(callback=True,patches=[[ACTOR+0xe4,4,0]])]):execute65(address,c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=['923908 optionaloriginresolver'],refinements=['515360'],closure='actual5becc0nullscratch→5c0240→6e9530sqrt')
(nm.BASE/'reports/script-phase65-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase65-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
