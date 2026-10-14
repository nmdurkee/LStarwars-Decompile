"""Actual raw bump-storage creation/destruction→full application/privatepool graph, no ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase208-20261014-verify.py').read_text().split('\nfor method,old,value,one,two,cpu,capacity')[0])
NAME=0x75e93c;OLD=D+0x700;cases=[];errors=[];checks=0;bodyExecutions={}
def trace210(mu,address,size,data):
 if address in[0x4ef720,0x4ef770]:bodyExecutions[hex(address)]=bodyExecutions.get(hex(address),0)+1
n.mu.hook_add(UC_HOOK_CODE,trace210)
def create210(capacity):
 saved=rd(G+8);wr(G+8,0);record=allocate205(U(capacity+16),NAME,0x73);wr(G+8,saved)
 if record:wr(record,capacity);wr(record+4,capacity);wr(record+8,U(record+16))
 return record

def run210(c):
 global shadow,checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x7000)));n.write(G,bytes(32));n.write(PATTERN,bytes((i*19+7)&255 for i in range(28)));n.pack('<I',CPU,c['cpu']);n.pack('<I',G+20,POOL);saved=OLD if c['old']else 0;n.pack('<I',G+8,saved);n.pack('<3I',OLD,32,32,D+0x740);capacity=c['poolCapacity'];n.pack('<4I',POOL,BASE,16384,0,0);n.pack('<3I',ROOT,0x80000000,FIRST,0);n.pack('<3I',FIRST,capacity,0,ROOT);n.pack('<I',FIRST-4,ROOT);n.pack('<I',FIRST+capacity+12,FIRST);n.pack('<I',FIRST+capacity+16,0x80000000);initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};record=create210(c['capacity']);expectedResults=[record]
 if c['method']=='Cycle'and record:
  wr(G+8,record)
  for size in[0,1,15,16,17,0xffffffff]:expectedResults.append(allocate205(size,NAME,0x99))
  if not c['leaveActive']:wr(G+8,saved)
 if c['method']!='Create':release205(record,NAME,0x82)
 expected=snap(True);actualRecord=n.call(0x4ef720,[c['capacity']],count=4000000);actualResults=[actualRecord]
 if c['method']=='Cycle'and actualRecord:
  n.pack('<I',G+8,actualRecord)
  for size in[0,1,15,16,17,0xffffffff]:actualResults.append(n.call(0x4eef40,[size,NAME,0x99],count=1000000))
  if not c['leaveActive']:n.pack('<I',G+8,saved)
 if c['method']!='Create':n.call(0x4ef770,[actualRecord],count=4000000)
 final=snap()
 for group,a,b in [('results',actualResults,expectedResults),('images',final,expected)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(x['address']+i),u,v]for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=c['method'],context=c,inputs=dict(capacity=c['capacity'],filename=NAME),initial=initial,final=final,results=actualResults))
for method,capacity,old,poolCapacity,cpu,leaveActive in itertools.product(['Create','Destroy','Cycle'],[0,1,16,128,256,8192],[False,True],[128,512,16000],[0,1],[False,True]):run210(dict(method=method,capacity=capacity,old=old,poolCapacity=poolCapacity,cpu=cpu,leaveActive=leaveActive))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,bodyExecutions=bodyExecutions,ports=[],closure='Whole raw65-byte bumpcreate/24-bytedestroy→actual application/privatepool/diagnostic/memset/SSE bodies, savedactivebump restored, individualbumpallocs anddangling-globalnativepreservation; zeroports')
(nm.BASE/'reports/script-phase210-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase210-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
