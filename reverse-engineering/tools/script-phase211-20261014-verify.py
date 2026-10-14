"""Whole private-pool query entries; root-inclusive list traversal and wrapped byte sum."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
POOL=D+0x100;ROOT=D+0x300;cases=[];checks=0;errors=[]
def run211(c):
 global checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x2000)));nodes=[ROOT]+[D+0x400+i*32 for i in range(c['nodes'])];n.pack('<4I',POOL,ROOT-16,2048,c['allocated'],c['used'])
 for i,p in enumerate(nodes):n.pack('<3I',p,c['sizes'][i],nodes[i+1]if i+1<len(nodes)else 0,0)
 if c.get('wrappedRoot'):n.pack('<I',POOL,0xfffffff0);nodes=[]
 before=n.read(D,0x2000);method=c['method'];want=c['allocated']if method=='Allocated'else c['used']if method=='Used'else len(nodes)if method=='Nodes'else sum(c['sizes'][i]&0x7fffffff for i in range(len(nodes)))&0xffffffff;address={'Allocated':0x4efbf0,'Nodes':0x4efc00,'Used':0x4efc20,'FreeBytes':0x4efc30}[method];actual=n.call(address,[POOL],count=1000000);after=n.read(D,0x2000)
 for group,a,b in [('return',actual,want),('images',after,before)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else'diff',model=b if group!='images'else'unchanged'))
 cases.append(dict(method=method,inputs=dict(pool=POOL),initial=[dict(address=D,bytes=before.hex())],final=[dict(address=D,bytes=after.hex())],returnValue=actual))
values=[0,1,0x7fffffff,0x80000000,0xffffffff,0x87654321]
for method,nodes,allocated,used in itertools.product(['Allocated','Nodes','Used','FreeBytes'],range(6),values,values):run211(dict(method=method,nodes=nodes,allocated=allocated,used=used,sizes=[values[i%len(values)]for i in range(nodes+1)]))
for method in['Allocated','Nodes','Used','FreeBytes']:run211(dict(method=method,nodes=0,allocated=0xffffffff,used=0x80000000,sizes=[0xffffffff],wrappedRoot=True))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,ports=[],rawEntryConsumers=['0x4efbf0','0x4efc00','0x4efc20','0x4efc30'],closure='Whole allocation/byte getters and root-inclusive nodecount/maskedwrappedfree sum, zeroports, allinputimagesunchanged')
(nm.BASE/'reports/script-phase211-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase211-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
