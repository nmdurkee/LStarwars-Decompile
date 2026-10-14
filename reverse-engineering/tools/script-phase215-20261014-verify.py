"""Original initializer→whole private-pool/application/table lifecycle and actual query/canary bodies, no ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase208-20261014-verify.py').read_text().split('\nfor method,old,value,one,two,cpu,capacity')[0])
CURSOR=D+0x100;cases=[];errors=[];checks=0;bodyExecutions={}
def trace215(mu,address,size,data):
 if address in[0x4ef980,0x4ef450,0x4efbf0,0x4efc00,0x4efc20,0x4efc30]:bodyExecutions[hex(address)]=bodyExecutions.get(hex(address),0)+1
n.mu.hook_add(UC_HOOK_CODE,trace215)
def initialize215(cursor,capacity):
 if capacity<80:return 0
 base=rd(cursor);wr(cursor,U(base+capacity));wr(base+24,0);root=base+16;wr(root,0);free=base+48;wr(root+4,free);wr(root+12,root);wr(base+36,0);wr(base+40,0);wr(base+32,0x80000000);wr(base+44,base+32);last=base+capacity-16;wr(last+4,0);wr(last+8,0);wr(last,0x80000000);wr(last+12,last);remaining=capacity-80;wr(free,remaining);wr(free+4,0);wr(free+8,root);wr(free+(remaining&0x7fffffff)+12,free);wr(base+4,capacity);wr(base+8,0);wr(base+12,0);wr(base,base);return base

def queries215(pool,model):
 if not model:return[n.call(p,[pool])for p in[0x4efbf0,0x4efc20,0x4efc00,0x4efc30]]
 node=U(rd(pool)+16);count=total=0
 while node:count=U(count+1);total=U(total+(rd(node)&0x7fffffff));node=rd(node+4)
 return[rd(pool+8),rd(pool+12),count,total]
def scan215():
 p=rd(G)
 while p:
  if any(rb(p+20+i)!=rb(PATTERN+i)for i in range(12)):return p
  suffix=p+rd(p+16)+32
  if any(rb(suffix+i)!=rb(PATTERN+16+i)for i in range(12)):return suffix
  p=rd(p)
 return 0

def run215(c):
 global shadow,checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x7000)));n.write(G,bytes(32));n.write(PATTERN,bytes((i*19+7)&255 for i in range(28)));n.pack('<I',CPU,c['cpu']);n.write(START,bytes((i*19+7)&255 for i in range(52)));n.pack('<I',COUNT,c['old']);n.pack('<2I',ONE,0,0);n.pack('<I',CURSOR,BASE+c['alignment']);n.pack('<I',STATE,0x12345678);n.pack('<I',START,0x87654321);initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};pool=initialize215(CURSOR,c['capacity']);want=[pool]
 if pool:
  wr(G+20,pool);configure208(c['value']);want.extend([queries215(pool,True),scan215()])
  if c['release']:release208();want.extend([queries215(pool,True),scan215()])
 expected=snap(True);pool=n.call(0x4ef980,[CURSOR,0,c['capacity']]);got=[pool]
 if pool:
  n.pack('<I',G+20,pool);n.call(0x4f0930,[c['value']],count=4000000);got.extend([queries215(pool,False),n.call(0x4ef450,[])])
  if c['release']:n.call(0x4f09d0,[],count=4000000);got.extend([queries215(pool,False),n.call(0x4ef450,[])])
 final=snap()
 for group,a,b in [('results',got,want),('images',final,expected)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(x['address']+i),u,v]for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(context=c,inputs=dict(cursor=CURSOR,capacity=c['capacity'],value=c['value'],release=c['release']),initial=initial,final=final,results=got))
for capacity,alignment,value,old,release,cpu in itertools.product([0,79,80,96,128,512,16384],[0,3],[0,1,16,512,1024],[0,1],[False,True],[0,1]):run215(dict(capacity=capacity,alignment=alignment,value=value,old=old,release=release,cpu=cpu))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,bodyExecutions=bodyExecutions,ports=[],closure='Actual pool initializer→whole table/application/privatepool/memset graph plus rawpoolqueries/canaryscan; zeroports, no manualpoolheaders, realcapacity failures and optional fullcleanup')
(nm.BASE/'reports/script-phase215-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase215-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
