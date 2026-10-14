"""Actualnode-index predicates andthreeidentical guarded binding tailentries; final51ad80 only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase51-20261013-verify.py').read_text().split('\nfor address,flags,ref')[0])
n=nm.NativeX86();LEVEL56=D+0xb000;WORLD56=D+0xb100;REF256=D+0x9600;CONTROL256=D+0x9700;BASE56=D+0x4000

def hook56(mu,address,size,data):
 if address!=0x51ad80:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<3I',sp+4));events.append(dict(callback=address,args=args));ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,config.get('bindResult',0x12345678));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook56)
def index56(system,bound):
 basis=rd(rd(rd(system+0x10)+8)+0x7c);delta=(bound-basis)&0xffffffff;delta=delta if delta<0x80000000 else delta-0x100000000;return(abs(delta)//92)*(-1 if delta<0 else 1)
def node56(p):value=rb(p+0x124)|(rb(p+0x125)<<8);return value if value<0x8000 else value-0x10000
def eval56(address,system,actor,bound,name):
 if address in[0x52d0d0,0x52d100,0x52d130]:
  if not system:return 0
  level=rd(system+0x10)
  if not level or not rb(level):return 0
  world=rd(level+8);events.append(dict(callback=0x51ad80,args=[system,world,name]));return config.get('bindResult',0x12345678)
 if address==0x514e20:return boolean(actor and bound and system and node56(actor)==index56(system,bound))
 if address==0x514e70:
  if not system:return 0
  ref=rd(system+0x138c)
  if not ref or not bound:return 0
  index=index56(system,bound);return boolean(node56(rd(ref+4))==index)
 if not system or not bound:return 0
 ref=rd(system+0x138c)
 if ref:
  index=index56(system,bound)
  if node56(rd(ref+4))==index:return bits(1.)
 ref=rd(system+0x1390)
 if not ref:return 0
 index=index56(system,bound);return boolean(node56(rd(ref+4))==index)

def execute56(address,c):
 global config,shadow,events,checks
 config=c;setup27(dict(c,text='node',callback=False),address);n.pack('<I',SYS+0x10,0 if c.get('nullLevel')else LEVEL56);n.write(LEVEL56,bytes([c.get('levelFlag',1)]));n.pack('<I',LEVEL56+8,0 if c.get('nullWorld')else WORLD56);n.pack('<I',WORLD56+0x7c,c.get('basis',BASE56));n.pack('<I',SYS+0x138c,0 if c.get('noPlayer1')else REFERENCE);n.pack('<I',SYS+0x1390,0 if c.get('noPlayer2')else REF256);n.pack('<I',REFERENCE+4,0 if c.get('nullControl1')else CONTROL);n.pack('<I',REF256+4,0 if c.get('nullControl2')else CONTROL256)
 for p,key in[(ACTOR,'actorNode'),(CONTROL,'playerNode'),(CONTROL256,'player2Node')]:n.pack('<H',p+0x124,c.get(key,0)&65535)
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];system=0 if c.get('nullSystem')else SYS;actor=0 if c.get('nullActor')else ACTOR;bound=0 if c.get('nullBound')else (c.get('basis',BASE56)+c.get('delta',0))&0xffffffff;name=0 if c.get('nullName')else TEXT;fault=False;want=0
 try:
  want=eval56(address,system,actor,bound,name)
  if address<0x520000:wd(OUT+0x40,want)
 except KeyError:fault=True
 mf=snapshot(True);me=events.copy();events=[];nfault=False;got=0
 try:
  if address>=0x520000:got=n.call(address,[system,name,0])
  else:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(address,[system,P,actor,TEXT,bound]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 except RuntimeError:nfault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in [('fault',nfault,fault),('return',0 if nfault else got,0 if fault else want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(system=system,actor=actor,bound=bound,name=name),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=nf,nativeEvents=ne))
for address,delta,offset in itertools.product([0x514e20,0x514e70,0x514ec0],[-2147483648,-3014656,-184,-93,-92,-91,-1,0,1,91,92,93,184,3014564,2147483647],[-1,0,1]):
 index=abs(delta)//92*(-1 if delta<0 else 1);execute56(address,dict(delta=delta,actorNode=index+offset,playerNode=index+offset,player2Node=index+offset))
for address,c in itertools.product([0x514e20,0x514e70,0x514ec0],[dict(nullSystem=True),dict(nullActor=True),dict(nullBound=True),dict(noPlayer1=True),dict(noPlayer2=True),dict(noPlayer1=True,noPlayer2=True),dict(nullControl1=True),dict(nullControl2=True,playerNode=1),dict(nullLevel=True),dict(nullWorld=True)]):execute56(address,c)
for address,c in itertools.product([0x52d0d0,0x52d100,0x52d130],[dict(nullSystem=True),dict(nullLevel=True),dict(levelFlag=0),dict(levelFlag=255),dict(nullWorld=True),dict(nullName=True),dict(bindResult=0),dict(bindResult=0xffffffff)]):execute56(address,c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=6,ports=['51ad80 boundnodefinalresolver'])
(nm.BASE/'reports/script-phase56-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase56-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
