"""Full application/container private-pool table lifecycle, actual all bodies, no heap/OS ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase205-20261014-verify.py').read_text().split('\nfor size,filename,pool,result,head,cpu')[0])
#207 constructs a fresh NativeX86, intentionally discarding205's allocator hooks.
exec(Path(__file__).with_name('script-phase207-20261014-verify.py').read_text().split('\nfor method,size,alignment,capacity')[0])
G=0x88ab18;PATTERN=0x800444;CPU=0x29a9c48;NAME=0x75e978;START=0x91ee80;COUNT=0x91eea8;ONE=0x91eeac;TWO=0x91eeb0;STATE=0x91ce64;cases=[];errors=[];checks=0;bodyExecutions={}
def trace208(mu,address,size,data):
 if address in[0x4f0930,0x4f09d0,0x4eef40,0x4ef280,0x4eeda0,0x4eedc0,0x6e6950,0x6eec22,0x6eebcb]:bodyExecutions[hex(address)]=bodyExecutions.get(hex(address),0)+1
n.mu.hook_add(UC_HOOK_CODE,trace208)
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in[(D,0x7000),(G,32),(PATTERN,28),(CPU,4),(START,52),(STATE,4),(NAME,64)]]
def zero(p,count):
 if count>20000:raise ValueError('prepared pool-backed allocation')
 for i in range(count):wb(p+i,0)
def port205(address,args,model):
 if address==0x4f6740:return allocate(*args)
 if address==0x4efb00:free(*args);return 0
 raise ValueError('unexpected allocator outside private-pool domain')
def configure208(value):
 if value!=rd(COUNT):
  if rd(ONE):release205(rd(ONE),NAME,0xa58)
  if rd(TWO):release205(rd(TWO),NAME,0xa59)
  wr(COUNT,value);a=allocate205(U(value<<4),NAME,0xa5d);wr(ONE,a);b=allocate205(U(rd(COUNT)<<4),NAME,0xa5e);wr(TWO,b)
 wr(STATE,0);wr(START,0)
def release208():
 if rd(ONE):release205(rd(ONE),NAME,0xa68);wr(ONE,0)
 if rd(TWO):release205(rd(TWO),NAME,0xa6d);wr(TWO,0)
 wr(COUNT,0)
def run208(c):
 global shadow,checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x7000)));n.write(G,bytes(32));n.write(PATTERN,bytes((i*19+7)&255 for i in range(28)));n.pack('<I',CPU,c['cpu']);n.write(START,bytes((i*19+7)&255 for i in range(52)));n.pack('<I',COUNT,c['old']);n.pack('<2I',ONE,0,0);n.pack('<I',G+20,POOL);n.pack('<I',G+12,0xffffffff);n.pack('<I',STATE,0x12345678);n.pack('<I',START,0x87654321);capacity=c['capacity'];n.pack('<4I',POOL,BASE,16384,0,0);n.pack('<3I',ROOT,0x80000000,FIRST,0);n.pack('<3I',FIRST,capacity,0,ROOT);n.pack('<I',FIRST-4,ROOT);n.pack('<I',FIRST+capacity+12,FIRST);n.pack('<I',FIRST+capacity+16,0x80000000)
 if c['one']:n.pack('<I',ONE,n.call(0x4eef40,[16,NAME,0xa5d],count=2000000))
 if c['two']:n.pack('<I',TWO,n.call(0x4eef40,[16,NAME,0xa5e],count=2000000))
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};method=c['method']
 if method in['Configure','Cycle']:configure208(c['value'])
 if method in['Release','Cycle']:release208()
 model=snap(True)
 if method in['Configure','Cycle']:n.call(0x4f0930,[c['value']],count=4000000)
 if method in['Release','Cycle']:n.call(0x4f09d0,[],count=4000000)
 final=snap();checks+=1
 if final!=model:errors.append(dict(context=c,native=[[hex(x['address']+i),u,v]for x,y in zip(final,model)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12]))
 cases.append(dict(method=method,context=c,inputs=dict(value=c['value']),initial=initial,final=final))
for method,old,value,one,two,cpu,capacity in itertools.product(['Configure','Release','Cycle'],[0,1],[0,1,16,512,1024],[False,True],[False,True],[0,1],[128,512,16000]):run208(dict(method=method,old=old,value=value,one=one,two=two,cpu=cpu,capacity=capacity))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,bodyExecutions=bodyExecutions,ports=[],closure='Full raw Configure/Release→application allocator/free→actualprivatepool five bodies+diagnostics/memset/SSE; real capacity-driven failures anddebug/boundary/list/accounting state; zero ports')
(nm.BASE/'reports/script-phase208-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase208-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
