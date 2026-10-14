"""Originalcompactactor predicates/ST0 outputs +IAm initializer actualcallbackABI; no game launch."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase27-20261013-verify.py').read_text().split('\nvalues=')[0])
n=nm.NativeX86();IDENT51=D+0x9400;NAME51=D+0x9600;CALL51=D+0xf000;segments+=[(0x923904,4),(0x751768,4)]
def hook51(mu,address,size,data):
 if address!=CALL51:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<2I',sp+4));events.append(dict(callback=address,args=args));ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,config.get('bindResult',0x12345678));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook51)
def predicate51(address,actor,packet,arg14,arg18):
 if address==0x5156f0:return boolean(actor and rd(actor+0x1e8)&0x400000)
 if address==0x515710:return bits(rb(packet+0xb5))if packet else rd(0x751768)
 if address==0x515790:return rd(rd(actor+0xd0)+0x1d8)if actor and rd(actor+0xd0)else 0
 if address==0x5151e0:return boolean(actor and rd(actor+0xe4)and rd(actor+0x1e8)&0x800)
 if address==0x515210:
  if not actor:return 0
  ref=rd(actor+0xe4)
  if not ref:return 0
  path=rd(actor+0x158)
  if not path:return 0
  control=rd(ref+4);return boolean(control and rd(control+0x158)==path)
 if address==0x515750:
  if not actor:return 0
  control=rd(actor+0xd0)
  if not control:return 0
  if control==arg18:return bits(1.)
  ident=rd(control+0x54)
  if not ident:return 0
  name=rd(ident+12);return boolean(name and arg14 and fold(text(name,True))==fold(text(arg14,True)))
 if address==0x515730:
  if not arg14 or not rd(0x923904):return 0
  events.append(dict(callback=rd(0x923904),args=[SYS,arg14]));return config.get('bindResult',0x12345678)
 raise ValueError(address)
def execute51(address,c):
 global config,shadow,events,checks
 config=c;setup27(dict(c,text=c.get('name','alpha'),callback=False,flags=c.get('flags',0)&255),address);n.pack('<I',0x923904,CALL51 if c.get('binding',True)else 0);n.pack('<I',ACTOR+0x1e8,c.get('flags',0));n.pack('<I',ACTOR+0xd0,CONTROL if c.get('controller',True)else 0);n.pack('<I',ACTOR+0x158,c.get('path',1));n.pack('<I',CONTROL+0x158,c.get('otherPath',1));n.pack('<I',CONTROL+0x1d8,c.get('value',bits(3.)));n.pack('<I',CONTROL+0x54,IDENT51 if c.get('identity',True)else 0);n.pack('<I',IDENT51+12,NAME51 if c.get('identityName',True)else 0);n.write(NAME51,c.get('identityText','ALPHA').encode('latin1')+b'\0');n.write(P+0xb5,bytes([c.get('interrupt',0)]));initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];actor=0 if c.get('nullActor')else ACTOR;packet=0 if c.get('nullPacket')else P;arg14=0 if c.get('nullName')else TEXT;arg18=c.get('arg18',0);want=predicate51(address,actor,packet,arg14,arg18)
 if address!=0x515730:wd(OUT+0x40,want)
 mf=snapshot(True);me=events.copy();events=[]
 if address==0x515730:got=n.call(address,[SYS,arg14])
 else:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(address,[SYS,packet,actor,arg14,arg18]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 nf=snapshot();ne=events.copy()
 for group,a,b in [('return',got,want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(system=SYS,packet=packet,actor=actor,arg14=arg14,arg18=arg18),initial=initial,returnValue=got,final=nf,nativeEvents=ne))
for address,flags,ref in itertools.product([0x5156f0,0x5151e0],[0,1,0x800,0x400000,0x400800,0xffffffff],[False,True]):execute51(address,dict(flags=flags,reference=ref))
for interrupt in range(256):execute51(0x515710,dict(interrupt=interrupt))
for path,otherPath,controller,reference in itertools.product([0,1,0xffffffff],[0,1,0xffffffff],[False,True],[False,True]):execute51(0x515210,dict(path=path,otherPath=otherPath,controller=controller,reference=reference))
for value in[0,0x80000000,1,0x7f800000,0xff800000,0x7fc12345,bits(-2.),bits(4.)]:execute51(0x515790,dict(value=value))
for name,identityText,arg18,identity,identityName in itertools.product(['alpha','','\xe0name'],['ALPHA','','\xc0NAME'],[0,CONTROL],[False,True],[False,True]):execute51(0x515750,dict(name=name,identityText=identityText,arg18=arg18,identity=identity,identityName=identityName))
for binding,nullName,bindResult in itertools.product([False,True],[False,True],[0,1,0xffffffff]):execute51(0x515730,dict(binding=binding,nullName=nullName,bindResult=bindResult))
for address,c in itertools.product([0x5156f0,0x515710,0x515750,0x515790,0x5151e0,0x515210],[dict(nullActor=True),dict(nullPacket=True),dict(controller=False),dict(nullName=True)]):execute51(address,c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=3,ports=['923904 identitybindingcallback'])
(nm.BASE/'reports/script-phase51-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase51-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
