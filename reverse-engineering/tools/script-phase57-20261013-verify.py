"""Original51ad80 raw node lookup +allthreeactualguardedbindingtailentries→lookup→4f8b10; no ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
n=nm.NativeX86();SYS57=D+0x8000;LEVEL57=D+0xb000;WORLD57=D+0xb100;ARRAY57=D+0x2000;NAMES57=D+0xc000;ASK57=D+0xb400;segments=[(D,0x10000)]
def lookup57(system,explicit,name):
 world=explicit
 if not world:
  if not system:return 0
  level=rd(system+0x10)
  if not level or not rb(level):return 0
  world=rd(level+8)
  if not world:return 0
 if not rb(world+0x10):return 0
 index=0;offset=0
 while True:
  candidate=rd(rd(world+0x7c)+offset)
  if candidate and name and fold(text(candidate))==fold(text(name)):return rd(world+0x7c)+index*92
  index+=1;offset+=92
  if index>=rb(world+0x10):return 0

def execute57(c,address=0x51ad80):
 global shadow,checks
 n.write(D,bytes(0x10000));n.pack('<I',SYS57+0x10,0 if c.get('nullLevel')else LEVEL57);n.write(LEVEL57,bytes([c.get('flag',1)]));n.pack('<I',LEVEL57+8,0 if c.get('nullWorld')else WORLD57);rows=c.get('rows',['alpha','beta','ALPHA']);count=c.get('count',len(rows));n.write(WORLD57+0x10,bytes([count]));n.pack('<I',WORLD57+0x7c,ARRAY57);n.write(ASK57,c.get('ask','alpha').encode('latin1')+b'\0')
 for i in range(count):
  name=rows[i%len(rows)]if rows else None;p=NAMES57+(i%16)*128
  if name is not None:n.write(p,name.encode('latin1')+b'\0')
  n.pack('<I',ARRAY57+i*92,0 if name is None else p)
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};system=0 if c.get('nullSystem')else SYS57;explicit=WORLD57 if c.get('explicit')else 0;name=0 if c.get('nullName')else ASK57
 if address==0x51ad80:want=lookup57(system,explicit,name);args=[system,explicit,name]
 else:
  level=rd(system+0x10)if system else 0;want=0 if not level or not rb(level)else lookup57(system,rd(level+8),name);args=[system,name,0]
 mf=snapshot(True);got=n.call(address,args,count=4000000);nf=snapshot()
 for group,a,b in [('return',got,want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(system=system,world=explicit,name=name),initial=initial,returnValue=got,final=nf))
for count,ask,explicit in itertools.product([0,1,3,15,255],['alpha','BETA','missing','','\xe0node'],[False,True]):execute57(dict(count=count,ask=ask,explicit=explicit))
for rows,ask in[([None,'beta',None],'beta'),(['same','SAME'],'same'),(['\xe0node','x'],'\xc0NODE'),(['','x'],''),([None,None],'x')]:execute57(dict(rows=rows,ask=ask))
for c in[dict(nullSystem=True),dict(nullLevel=True),dict(flag=0),dict(nullWorld=True),dict(nullName=True),dict(explicit=True,nullSystem=True),dict(explicit=True,nullLevel=True),dict(explicit=True,flag=0),dict(explicit=True,nullWorld=True)]:execute57(c)
for address,c in itertools.product([0x52d0d0,0x52d100,0x52d130],[dict(),dict(nullSystem=True),dict(nullLevel=True),dict(flag=0),dict(nullWorld=True),dict(nullName=True),dict(ask='BETA'),dict(ask='missing')]):execute57(c,address)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,ports=[],refinement='51ad80 rawlive bytecount/namepointer/stride semantics;56bindings noresolverports')
(nm.BASE/'reports/script-phase57-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase57-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
