"""Entire356-byte allocation-list canary scan; original release diagnostic RET, no adapters."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
from unicorn import UC_HOOK_CODE
HEAD=0x88ab18;PATTERN=0x800444;cases=[];checks=0;errors=[];bodyExecutions={}
def trace209(mu,address,size,data):
 if address in[0x4ef450,0x4eedc0]:bodyExecutions[hex(address)]=bodyExecutions.get(hex(address),0)+1
n.mu.hook_add(UC_HOOK_CODE,trace209)
def run209(c):
 global checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x4000)));n.write(PATTERN,bytes((i*19+7)&255 for i in range(28)));nodes=[D+0x1000+i*0x500 for i in range(c['count'])];n.pack('<I',HEAD,nodes[0]if nodes else 0)
 for i,p in enumerate(nodes):
  n.pack('<5I',p,nodes[i+1]if i+1<len(nodes)else 0,nodes[i-1]if i else 0,0x12345678,0xffffffff,c['size']);n.write(p+20,n.read(PATTERN,12));n.write(p+c['size']+32,n.read(PATTERN+16,12))
 for node,side,offset in c.get('corruptions',[]):
  p=nodes[node]+(20 if side=='prefix'else c['size']+32)+offset;n.write(p,bytes([n.read(p,1)[0]^255]))
 initial=[dict(address=p,bytes=n.read(p,z).hex())for p,z in[(D,0x4000),(HEAD,4),(PATTERN,28)]];want=0
 for p in nodes:
  if n.read(p+20,12)!=n.read(PATTERN,12):want=p;break
  if n.read(p+c['size']+32,12)!=n.read(PATTERN+16,12):want=p+c['size']+32;break
 actual=n.call(0x4ef450,[],count=1000000);final=[dict(address=r['address'],bytes=n.read(r['address'],len(r['bytes'])//2).hex())for r in initial]
 for group,a,b in [('return',actual,want),('images',final,initial)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else'diff',model=b if group!='images'else'unchanged'))
 cases.append(dict(context=c,inputs={},initial=initial,final=final,returnValue=actual))
for count,size in itertools.product(range(5),[0,1,16,256]):
 run209(dict(count=count,size=size))
 for node,side,offset in itertools.product(range(count),['prefix','suffix'],range(12)):run209(dict(count=count,size=size,corruptions=[[node,side,offset]]))
for corruptions in[[[0,'prefix',0],[0,'suffix',0]],[[0,'suffix',11],[1,'prefix',0]],[[1,'prefix',5],[2,'suffix',3]],[[2,'suffix',0],[3,'prefix',9]]]:run209(dict(count=4,size=16,corruptions=corruptions))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,bodyExecutions=bodyExecutions,ports=[],closure='Whole356-byte scan through allpreviousallocation links andboth12-byte guards; returns first corruptprefix block base orsuffix pointer, actualreleaseRETdiagnostic')
(nm.BASE/'reports/script-phase209-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase209-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
