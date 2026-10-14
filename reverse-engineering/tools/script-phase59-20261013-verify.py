"""Actual51acd0 rawinline64bytenames+fivebindingentry→lookup closures; no ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
n=nm.NativeX86();SYS59=D+0x8000;ARRAY59=D+0x2000;ASK59=D+0xb400;segments=[(D,0x10000)]
def lookup59(system,name):
 if not system:return 0
 count=rd(system+0x34);count=count if count<0x80000000 else count-0x100000000
 if count<=0:return 0
 index=0;offset=0
 while True:
  area=(rd(system+0x38)+offset)&0xffffffff
  if name and area and fold(text(name))==fold(text(area)):return area
  index+=1;offset+=64;count=rd(system+0x34);count=count if count<0x80000000 else count-0x100000000
  if index>=count:return 0

def execute59(c,address=0x51acd0):
 global shadow,checks
 n.write(D,bytes(0x10000));rows=c.get('rows',['alpha','beta','ALPHA']);count=c.get('count',len(rows));n.pack('<II',SYS59+0x34,count&0xffffffff,0 if c.get('nullArray')else ARRAY59);n.write(ASK59,c.get('ask','alpha').encode('latin1')+b'\0')
 for i in range(max(0,min(count,255))):name=rows[i%len(rows)]if rows else '';n.write(ARRAY59+i*64,name.encode('latin1')+b'\0')
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};system=0 if c.get('nullSystem')else SYS59;name=0 if c.get('nullName')else ASK59;fault=False;want=0
 try:want=0 if address!=0x51acd0 and not name else lookup59(system,name)
 except KeyError:fault=True
 mf=snapshot(True);nfault=False;got=0
 try:got=n.call(address,[system,name],count=4000000)
 except RuntimeError:nfault=True
 nf=snapshot()
 for group,a,b in [('fault',nfault,fault),('return',0 if nfault else got,0 if fault else want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(address=hex(address),group=group,context=c,native=a,model=b))
 cases.append(dict(address=address,context=c,inputs=dict(system=system,name=name),initial=initial,fault=nfault,returnValue=0 if nfault else got,final=nf))
for count,ask in itertools.product([-2147483648,-1,0,1,3,15,255],['alpha','BETA','missing','','\xe0area']):execute59(dict(count=count,ask=ask))
for rows,ask in[(['same','SAME'],'same'),(['\xe0area','x'],'\xc0AREA'),(['','x'],''),(['a'*63,'x'],'a'*63)]:execute59(dict(rows=rows,ask=ask))
for c in[dict(nullSystem=True),dict(nullName=True),dict(nullArray=True,count=1),dict(nullArray=True,count=2),dict(nullArray=True,nullName=True,count=2)]:execute59(c)
for address,c in itertools.product([0x52d0b0,0x52d160,0x52d180,0x52d1a0,0x52d1c0],[dict(),dict(nullSystem=True),dict(count=-1),dict(nullName=True),dict(ask='BETA'),dict(ask='missing'),dict(nullArray=True,count=2)]):execute59(c,address)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,ports=[],refinement='51acd0 rawlive signedcount/inline64records;58fivebindingsactualclosure')
(nm.BASE/'reports/script-phase59-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase59-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
