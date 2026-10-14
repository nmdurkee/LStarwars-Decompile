"""Original private pool wrapper/core/split/free/unlink, complete native graph, no ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
from unicorn import UC_HOOK_CODE
POOL=D+0x100;BASE=D+0x1000;ROOT=BASE+16;FIRST=BASE+32;shadow={};cases=[];checks=0;errors=[];bodyExecutions={}
U=lambda v:v&0xffffffff
def rd(p):return sum(shadow[U(p+i)]<<(i*8)for i in range(4))
def wr(p,v):
 for i in range(4):shadow[U(p+i)]=(v>>(i*8))&255
def snap(model=False):return[dict(address=D,bytes=bytes(shadow[D+i]for i in range(0x4000)).hex()if model else n.read(D,0x4000).hex())]
def trace(mu,address,size,data):
 if address in[0x4f6740,0x4efa40,0x4ef8a0,0x4efb00,0x4ef870]:bodyExecutions[hex(address)]=bodyExecutions.get(hex(address),0)+1
n.mu.hook_add(UC_HOOK_CODE,trace)
def unlink(p):
 prev=rd(p+8)
 if prev:wr(prev+4,rd(p+4))
 nxt=rd(p+4)
 if nxt:wr(nxt+8,rd(p+8))
def split(p,size,align):
 remaining=U((rd(p)&0x7fffffff)-size-16);allocated=U(p+remaining+16)
 if align:
  user=U(allocated+12);rounded=U(user+align-1)&U(~(align-1));shift=U(rounded-user);allocated=U(allocated+shift);size=U(size-shift);remaining=U(remaining+shift)
 wr(allocated,rd(allocated)|0x80000000);wr(allocated,(rd(allocated)&0x80000000)|size);wr(allocated+4,0);wr(allocated+8,0);wr(U(allocated+(rd(allocated)&0x7fffffff)+12),allocated);wr(p,rd(p)&0x7fffffff);wr(p,(rd(p)&0x80000000)|remaining);wr(p+4,0);wr(p+8,0);wr(U(p+(rd(p)&0x7fffffff)+12),p);return allocated,p
def allocate(pool,size,align):
 root=U(rd(pool)+16)
 if not size:return 0
 total=U(size+align);needed=U(total+16);p=root
 while p:
  if(rd(p)&0x7fffffff)>needed:break
  p=rd(p+4)
 if not p:return 0
 unlink(p);allocated,remainder=split(p,total,align);head=rd(root+4)
 if head:wr(head+8,remainder)
 wr(remainder+4,rd(root+4));wr(remainder+8,root);wr(root+4,remainder);wr(pool+8,U(rd(pool+8)+1));wr(pool+12,U(rd(pool+12)+(rd(allocated)&0x7fffffff)+16));return allocated+12
def free(pool,pointer):
 base=rd(pool);root=U(base+16)
 if not pointer or pointer<base or pointer>U(base+rd(pool+4)):return
 p=U(pointer-12);wr(p,rd(p)&0x7fffffff);wr(pool+8,U(rd(pool+8)-1));size=rd(p)&0x7fffffff;wr(pool+12,U(rd(pool+12)-size-16));head=rd(root+4)
 if head:wr(head+8,p)
 wr(p+8,root);wr(p+4,rd(root+4));wr(root+4,p);nxt=U(p+(rd(p)&0x7fffffff)+16)
 if not rd(nxt)&0x80000000:
  unlink(nxt);size=U((rd(p)&0x7fffffff)+(rd(nxt)&0x7fffffff)+16);wr(p,(rd(p)&0x80000000)|size);wr(U(p+(rd(p)&0x7fffffff)+12),p)
 prev=rd(p-4)
 if not rd(prev)&0x80000000:
  unlink(p);size=U((rd(p)&0x7fffffff)+(rd(prev)&0x7fffffff)+16);wr(prev,(rd(prev)&0x80000000)|size);wr(U(prev+(rd(prev)&0x7fffffff)+12),prev)
def execute(c):
 global shadow,checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x4000)));n.pack('<4I',POOL,BASE,2048,0,0);n.pack('<3I',ROOT,0x80000000,FIRST,0);method=c['method'];size=c.get('size',32);align=c.get('alignment',4);capacity=c.get('capacity',512)
 if method in['Allocate','Core','Cycle']:
  n.pack('<3I',FIRST,capacity,0,ROOT);n.pack('<I',FIRST-4,ROOT);n.pack('<I',FIRST+capacity+12,FIRST);n.pack('<I',FIRST+capacity+16,0x80000000)
 elif method=='Free':
  prev=FIRST;p=prev+64;nxt=p+96;end=nxt+80;n.pack('<4I',POOL,BASE,2048,c.get('count',1),96);n.pack('<I',ROOT+4,0);n.pack('<I',prev,48|(0x80000000 if c['previousBusy']else 0));n.pack('<I',p,80|0x80000000);n.pack('<I',nxt,64|(0x80000000 if c['nextBusy']else 0));n.pack('<I',end,0x80000000);n.pack('<I',prev-4,ROOT);n.pack('<I',p-4,prev);n.pack('<I',nxt-4,p);n.pack('<I',end-4,nxt);nodes=[q for q,busy in[(prev,c['previousBusy']),(nxt,c['nextBusy'])]if not busy];n.pack('<I',ROOT+4,nodes[0]if nodes else 0)
  for i,q in enumerate(nodes):n.pack('<2I',q+4,nodes[i+1]if i+1<len(nodes)else 0,nodes[i-1]if i else ROOT)
  pointer=p+12
 else:pointer=c['pointer']
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};results=[]
 if method in['Allocate','Core','Cycle']:
  pointer=allocate(POOL,size,align);results.append(pointer)
  if method=='Cycle'and pointer:free(POOL,pointer)
 else:free(POOL,pointer)
 model=snap(True);nativeResults=[]
 if method in['Allocate','Core','Cycle']:
  pointer=n.call(0x4efa40 if method=='Core'else 0x4f6740,[POOL,size,align,c.get('reserved',0)]if method=='Core'else[POOL,size,align],count=1000000);nativeResults.append(pointer)
  if method=='Cycle'and pointer:n.call(0x4efb00,[POOL,pointer],count=1000000)
 else:n.call(0x4efb00,[POOL,pointer],count=1000000)
 final=snap()
 for group,a,b in [('images',final,model),('results',nativeResults,results)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(x['address']+i),u,v]for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=method,context=c,inputs=dict(pool=POOL,size=size,alignment=align,pointer=pointer),initial=initial,final=final,results=nativeResults))
for method,size,alignment,capacity in itertools.product(['Allocate','Core','Cycle'],[0,1,15,16,17,128,511],[0,1,2,4,8,16,32,64],[32,64,512]):execute(dict(method=method,size=size,alignment=alignment,capacity=capacity,reserved=0xffffffff))
for prev,nxt,count in itertools.product([False,True],[False,True],[0,1,0xffffffff]):execute(dict(method='Free',previousBusy=prev,nextBusy=nxt,count=count))
for pointer in[0,BASE-1,BASE+2049,0xffffffff]:execute(dict(method='Ignore',pointer=pointer))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=5,bodyExecutions=bodyExecutions,ports=[],closure='Whole wrapper26/core179/split177/free227/unlink27 bytes, allocationfromtail withalignment, strictcapacitycomparison, exact freelistlinks/counters/boundarytags and both-neighborcoalescing; no ports')
(nm.BASE/'reports/script-phase207-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase207-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
