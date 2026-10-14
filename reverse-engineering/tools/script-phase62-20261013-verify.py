"""Actual51ac10/51ac70 rawinline lookup and4nullablelocatorbindings→lookup→actualfold; no ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
n=nm.NativeX86();SYS62=D+0x8000;ARRAY62=D+0x2000;ASK62=D+0xb400;segments=[(D,0x10000)]
def lookup62(system,name,isSet):
 if not system:return 0
 countOff,arrayOff,stride=(0x2c,0x30,28)if isSet else(0x24,0x28,60);count=rd(system+countOff);count=count if count<0x80000000 else count-0x100000000
 if count<=0:return 0
 index=0;offset=0
 while True:
  record=(rd(system+arrayOff)+offset)&0xffffffff
  if record and name and fold(text(record))==fold(text(name)):return(rd(system+arrayOff)+index*stride)&0xffffffff
  index+=1;offset+=stride;count=rd(system+countOff);count=count if count<0x80000000 else count-0x100000000
  if index>=count:return 0

def execute62(c,address=0x51ac10):
 global shadow,checks
 isSet=address==0x51ac70;countOff,arrayOff,stride=(0x2c,0x30,28)if isSet else(0x24,0x28,60);n.write(D,bytes(0x10000));rows=c.get('rows',['alpha','beta','ALPHA']);count=c.get('count',len(rows));n.pack('<I',SYS62+countOff,count&0xffffffff);n.pack('<I',SYS62+arrayOff,0 if c.get('nullArray')else ARRAY62);n.write(ASK62,c.get('ask','alpha').encode('latin1')+b'\0')
 for i in range(max(0,min(count,255))):name=rows[i%len(rows)]if rows else '';n.write(ARRAY62+i*stride,name.encode('latin1')+b'\0')
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};system=0 if c.get('nullSystem')else SYS62;name=0 if c.get('nullName')else ASK62;fault=False;want=0
 try:want=0 if address>=0x520000 and not name else lookup62(system,name,isSet)
 except KeyError:fault=True
 mf=snapshot(True);nfault=False;got=0
 try:got=n.call(address,[system,name],count=4000000)
 except RuntimeError:nfault=True
 nf=snapshot()
 for group,a,b in [('fault',nfault,fault),('return',0 if nfault else got,0 if fault else want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(system=system,name=name),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=nf))
for address,count,ask in itertools.product([0x51ac10,0x51ac70],[-2147483648,-1,0,1,3,15,255],['alpha','BETA','missing','','\xe0loc']):execute62(dict(count=count,ask=ask),address)
for address,(rows,ask)in itertools.product([0x51ac10,0x51ac70],[(['same','SAME'],'same'),(['\xe0loc','x'],'\xc0LOC'),(['','x'],''),(['a'*15,'x'],'a'*15)]):execute62(dict(rows=rows,ask=ask),address)
for address,c in itertools.product([0x51ac10,0x51ac70],[dict(nullSystem=True),dict(nullName=True),dict(nullArray=True,count=1),dict(nullArray=True,count=2),dict(nullArray=True,nullName=True,count=2)]):execute62(c,address)
for address,c in itertools.product([0x52d070,0x52d090,0x52d1e0,0x52d200],[dict(),dict(nullSystem=True),dict(count=-1),dict(nullName=True),dict(ask='BETA'),dict(ask='missing'),dict(nullArray=True,count=2)]):execute62(c,address)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=[],refinement='raw51ac10/51ac70;4actualnullablelocatorbindingclosures')
(nm.BASE/'reports/script-phase62-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase62-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
