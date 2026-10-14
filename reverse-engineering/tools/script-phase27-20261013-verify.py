"""Actual compactbuiltin callbacks and actual52c880 interoperation; onlygame-symbol callback supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase20-20261013-verify.py').read_text().split('\ntexts=')[0])
SYS=D+0x8000;ACTOR=D+0x6000;REFERENCE=D+0x9000;CONTROL=D+0x9200;LIST=D+0xa000;NODE=D+0xa100;DESC=D+0xa200
segments[0]=(D,0x10000);handlers=[0x514990,0x5149a0,0x5149f0,0x514ae0,0x514b00,0x514b20,0x514b40,0x514b60,0x514b90,0x514bb0,0x514f90,0x5151c0,0x5157b0]
def boolean(v):return bits(1.)if v else 0

def predicate(address,system,packet,actor,arg14,arg18):
 if address==0x514990:return rd(packet+0x24)
 if address==0x5149a0:state=(rd(0x95e5d4)*0x19660d+0x3c6ef35f)&0xffffffff;wd(0x95e5d4,state);return bits((state&0x7fffff)/(1<<23))
 if address==0x5149f0:return arg18
 if address==0x514ae0:return boolean(rd(packet+0xa4))
 if address==0x514b00:return boolean(rd(packet+0xa8))
 if address==0x514b20:return boolean(actor and rb(actor+0x166)&1)
 if address==0x514b40:reference=rd(system+0x138c);return boolean(reference and rb(rd(reference+4)+0x166)&1)
 if address==0x514b60:
  if not actor:return 0
  reference=rd(actor+0xe4);return boolean(reference and rb(rd(reference+4)+0x166)&1)
 if address==0x514b90:return rd(actor+0x208)if actor else 0
 if address==0x514bb0:return boolean(arg18 and rd(packet+0xa4)==arg18)
 if address==0x514f90:return boolean(rd(packet+0xa0))
 if address==0x5151c0:return boolean(actor and rd(actor+0xe4))
 if address==0x5157b0:return evaluate(actor,packet,arg14)
 raise ValueError('unsupported')
def setup27(c,address):
 n.write(D,bytes(0x10000));setup(c);n.pack('<I',P+0x24,c.get('value',bits(1.)));n.pack('<I',P+0xa0,c.get('presence',1));n.pack('<I',P+0xa4,c.get('presence',1));n.pack('<I',P+0xa8,c.get('presence',1));n.write(ACTOR+0x166,bytes([c.get('flags',1)]));n.pack('<I',ACTOR+0x208,c.get('value',bits(1.)));n.pack('<I',ACTOR+0xe4,REFERENCE if c.get('reference',True)else 0);n.pack('<I',SYS+0x138c,REFERENCE if c.get('reference',True)else 0);n.pack('<I',REFERENCE+4,CONTROL if c.get('controller',True)else 0);n.write(CONTROL+0x166,bytes([c.get('flags',1)]));n.pack('<I',LIST,NODE);n.pack('<I',NODE+0x1c,DESC);n.pack('<I',DESC+4,address);n.pack('<I',NODE+0x14,TEXT);n.pack('<I',NODE+0x18,c.get('arg18',bits(1.)));n.pack('<I',NODE+8,c.get('right',bits(1.)));n.write(NODE+0xc,bytes([c.get('op',0)]));n.write(P+0x38,b'\1\1')
def execute27(address,c,method='Predicate'):
 global config,events,ordinal,shadow,checks
 config=c;setup27(c,address);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0;system=0 if c.get('nullSystem')else SYS;packet=0 if c.get('nullPacket')else P;actor=0 if c.get('nullActor')else ACTOR;arg14=TEXT;arg18=c.get('arg18',bits(1.));modelFault=False;want=0
 try:
  if method=='Predicate':want=predicate(address,system,packet,actor,arg14,arg18);wd(OUT+0x40,want)
  else:
   left=predicate(address,system,packet,actor,arg14,arg18);right=rd(NODE+8);a,b=fl(left),fl(right);op=c.get('op',0);match=[a==b,a<b,a>b,a<=b,a>=b,a!=b][op];want=NODE if match else 0;wb(P+0x39,0);wb(P+0x38,0)
 except(KeyError,ValueError):modelFault=True
 modelEvents=events.copy();modelFinal=snapshot(True);events=[];ordinal=0;nativeFault=False;got=0
 try:
  if method=='Predicate':n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(address,[system,packet,actor,arg14,arg18]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
  else:got=n.call(0x52c880,[system,LIST,actor,packet],regs={UC_X86_REG_EAX:0})
 except RuntimeError:nativeFault=True
 nativeEvents=events.copy();nativeFinal=snapshot()
 for group,a,b in [('fault',nativeFault,modelFault),('return',got if not nativeFault else 0,want if not modelFault else 0),('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,address=address,context=c,inputs=dict(system=system,packet=packet,actor=actor,arg14=arg14,arg18=arg18,list=LIST),initial=initial,fault=nativeFault,returnValue=got if not nativeFault else 0,final=nativeFinal,nativeEvents=nativeEvents))
values=[0,0x80000000,bits(1.),bits(-1.),0x7f7fffff,0x7f800000,0xff800000,0x7fc12345,0xffc12345]
for address,value in itertools.product([0x514990,0x5149f0,0x514b90],values):execute27(address,dict(value=value,arg18=value,callback=False))
for address in [0x514b20,0x514b40,0x514b60]:
 for flags in range(256):execute27(address,dict(flags=flags,callback=False))
for address,presence,arg18 in itertools.product([0x514ae0,0x514b00,0x514bb0,0x514f90],[0,1,0xffffffff,0x80000000],[0,1,0xffffffff]):execute27(address,dict(presence=presence,arg18=arg18,callback=False))
for address,c in itertools.product(handlers,[dict(nullSystem=True),dict(nullPacket=True),dict(nullActor=True),dict(reference=False),dict(controller=False)]):
 if address==0x5157b0:c={**c,'text':'1'}
 execute27(address,{**c,'callback':False})
rng=random.Random(0x5149a0)
for seed in [0,1,0xffffffff,0x80000000]+[rng.randrange(1<<32)for _ in range(512)]:execute27(0x5149a0,dict(seed=seed,callback=False))
for expressionText,callback,handled in itertools.product(['1+2','1/2','alpha','beta','param3','Rand','true','custom','alpha+beta','-(alpha+beta)'],[False,True],[0,1]):execute27(0x5157b0,dict(text=expressionText,callback=callback,handled=handled))
for address,op,value in itertools.product(handlers,range(6),[0,bits(1.),0x7fc12345]):execute27(address,dict(value=value,arg18=value,right=bits(1.),op=op,callback=False,text='alpha'),'Conditions')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),handlers=len(handlers),actualParent='0x52c880',remainingPorts=['GameSymbol9238c0 forParam'],managedExecution=False)
(nm.BASE/'reports/script-phase27-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase27-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
