"""Originalseven trigger callbacks +five nullablebindingbodies; x86shift32/CDQ masksemantics."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase51-20261013-verify.py').read_text().split('\nfor address,flags,ref')[0])
n=nm.NativeX86();AREA58=D+0xb000;OWNER58=D+0xb100;PLAYER258=D+0xc000

def hook58(mu,address,size,data):
 if address!=0x51acd0:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<2I',sp+4));events.append(dict(callback=address,args=args));ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,config.get('bindResult',AREA58));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook58)
def select58(packet,bound):return bound or rd(packet+0xa0)
def member58(area,creature):
 if not area:return 0
 owner=rd(area+0x38)
 if not owner:return 0
 delta=(area-rd(owner+0x38))&0xffffffff;delta=delta if delta<0x80000000 else delta-0x100000000;index=delta>>6;lo=1<<(index&31);hi=0xffffffff if lo&0x80000000 else 0;return boolean(rd(creature+0x2b0)&lo or rd(creature+0x2b4)&hi)
def eval58(address,system,packet,actor,bound,name):
 if address>=0x520000:
  if not name:return 0
  events.append(dict(callback=0x51acd0,args=[system,name]));return config.get('bindResult',AREA58)
 if address in[0x515100,0x515130]:area=select58(packet,bound);return boolean(area and rb(area+0x2a)&(4 if address==0x515100 else 2))
 if address==0x514bd0:
  if not actor:return 0
  controller=rd(actor+0xd0);return member58(select58(packet,bound),controller)if controller else 0
 if address==0x515160:
  if not actor:return 0
  opponent=rd(actor+0xe4)
  if not opponent or not rd(actor+0xd0):return 0
  return member58(select58(packet,bound),opponent)
 if not system:return 0
 if address==0x514fb0:
  player=rd(system+0x138c)
  if not player or not rd(system+0x38):return 0
  return member58(select58(packet,bound),player)
 if address==0x515010:
  player=rd(system+0x1390);return member58(select58(packet,bound),player)if player else 0
 area=select58(packet,bound)
 if not area:return 0
 player=rd(system+0x138c)
 if player and member58(area,player):return bits(1.)
 player=rd(system+0x1390);return member58(area,player)if player else 0

def execute58(address,c):
 global config,shadow,events,checks
 config=c;setup27(dict(c,text='area',callback=False),address);n.pack('<I',ACTOR+0xd0,0 if c.get('noController')else CONTROL);n.pack('<I',ACTOR+0xe4,0 if c.get('noOpponent')else REFERENCE);n.pack('<I',SYS+0x138c,0 if c.get('noPlayer1')else REFERENCE);n.pack('<I',SYS+0x1390,0 if c.get('noPlayer2')else PLAYER258);n.pack('<I',SYS+0x38,c.get('world',1));n.pack('<I',AREA58+0x38,0 if c.get('noOwner')else OWNER58);n.pack('<I',OWNER58+0x38,(AREA58-c.get('delta',0))&0xffffffff);n.write(AREA58+0x2a,bytes([c.get('flags',0)]));n.pack('<I',P+0xa0,0 if c.get('noSelected')else AREA58)
 for p,key in[(CONTROL,'mask'),(REFERENCE,'mask'),(PLAYER258,'secondMask')]:mask=c.get(key,0);n.pack('<II',p+0x2b0,mask&0xffffffff,mask>>32)
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];system=0 if c.get('nullSystem')else SYS;packet=0 if c.get('nullPacket')else P;actor=0 if c.get('nullActor')else ACTOR;bound=AREA58 if c.get('explicit')else 0;name=0 if c.get('nullName')else TEXT;fault=False;want=0
 try:
  want=eval58(address,system,packet,actor,bound,name)
  if address<0x520000:wd(OUT+0x40,want)
 except KeyError:fault=True
 mf=snapshot(True);me=events.copy();events=[];nfault=False;got=0
 try:
  if address>=0x520000:got=n.call(address,[system,name])
  else:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(address,[system,packet,actor,TEXT,bound]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 except RuntimeError:nfault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in [('fault',nfault,fault),('return',0 if nfault else got,0 if fault else want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(system=system,actor=actor,packet=packet,bound=bound,name=name),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=nf,nativeEvents=ne))
handlers58=[0x514bd0,0x514fb0,0x515010,0x515070,0x515160]
for address,delta,mask in itertools.product(handlers58,[-4096,-65,-64,-1,0,1,64,1920,1984,2048,4032,4096],[0,1,0x80000000,0x100000000,0x8000000000000000]):execute58(address,dict(delta=delta,mask=mask))
for address,flags in itertools.product([0x515100,0x515130],range(256)):execute58(address,dict(flags=flags))
for address,c in itertools.product(handlers58+[0x515100,0x515130],[dict(nullSystem=True,nullPacket=True),dict(nullActor=True,nullPacket=True),dict(noController=True,nullPacket=True),dict(noOwner=True),dict(noSelected=True),dict(noPlayer1=True),dict(noPlayer2=True),dict(noOpponent=True),dict(world=0),dict(explicit=True,nullPacket=True),dict(mask=0,secondMask=1)]):execute58(address,c)
for address,c in itertools.product([0x52d0b0,0x52d160,0x52d180,0x52d1a0,0x52d1c0],[dict(nullName=True),dict(nullSystem=True),dict(bindResult=0),dict(bindResult=0xffffffff)]):execute58(address,c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=6,ports=['51acd0 finaltriggerlookup'])
(nm.BASE/'reports/script-phase58-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase58-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
