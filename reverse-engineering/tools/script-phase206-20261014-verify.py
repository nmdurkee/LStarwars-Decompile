"""Full raw container table lifecycle through actual application allocator/release/memset children."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase205-20261014-verify.py').read_text().split('\nfor size,filename,pool,result,head,cpu')[0])
START=0x91ee80;COUNT=0x91eea8;ONE=0x91eeac;TWO=0x91eeb0;STATE=0x91ce64;NAME=0x75e978;OLDONE=D+0x3000;OLDTWO=D+0x4000;heapCalls=0;cases=[];errors=[];checks=0;bodyExecutions={}
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in[(D,0x7000),(G,32),(PATTERN,28),(CPU,4),(START,52),(STATE,4),(NAME,64)]]
def port205(address,args,model):
 global heapCalls
 events.append(dict(callback=address,args=args))
 if address in[0x6e7570,0x4f6740]:result=config['heapResults'][heapCalls];heapCalls+=1;return result
 return 0

def configure206(value):
 if value!=rd(COUNT):
  if rd(ONE):release205(rd(ONE),NAME,0xa58)
  if rd(TWO):release205(rd(TWO),NAME,0xa59)
  wr(COUNT,value);one=allocate205(U(value<<4),NAME,0xa5d);wr(ONE,one);two=allocate205(U(rd(COUNT)<<4),NAME,0xa5e);wr(TWO,two)
 wr(STATE,0);wr(START,0)
def release206():
 if rd(ONE):release205(rd(ONE),NAME,0xa68);wr(ONE,0)
 if rd(TWO):release205(rd(TWO),NAME,0xa6d);wr(TWO,0)
 wr(COUNT,0)
def run206(c):
 global shadow,events,config,checks,heapCalls
 config=c;n.write(D,bytes((i*37+11)&255 for i in range(0x7000)));n.write(G,bytes(32));n.write(PATTERN,bytes((i*19+7)&255 for i in range(28)));n.pack('<I',CPU,c['cpu']);n.write(START,bytes((i*19+7)&255 for i in range(52)));n.pack('<3I',COUNT,c['old'],OLDONE+32 if c['one']else 0,OLDTWO+32 if c['two']else 0);n.pack('<I',STATE,0x12345678);n.pack('<I',START,0x87654321);n.pack('<I',G+20,c['pool']);n.pack('<I',G+12,0xffffffff)
 blocks=[p for p,on in[(OLDONE,c['one']),(OLDTWO,c['two'])]if on];n.pack('<I',G,blocks[-1]if blocks else 0);n.pack('<I',G+4,len(blocks)*16)
 for i,p in enumerate(blocks):
  n.pack('<5I',p,blocks[i-1]if i else 0,blocks[i+1]if i+1<len(blocks)else 0,77,i,16);n.write(p+20,n.read(PATTERN,12));n.write(p+48,n.read(PATTERN+16,12))
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];heapCalls=0;configure206(c['value'])if c['method']=='Configure'else release206();expected=snap(True);me=events.copy();events=[];heapCalls=0;n.call(0x4f0930 if c['method']=='Configure'else 0x4f09d0,[c['value']]if c['method']=='Configure'else[],count=3000000);final=snap();ne=events.copy()
 for group,a,b in [('images',final,expected),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(x['address']+i),u,v]for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=c['method'],context=c,inputs=dict(value=c['value']),initial=initial,final=final,nativeEvents=ne))
for method,old,value,one,two,pool,cpu,results in itertools.product(['Configure','Release'],[0,1],[0,1,16],[False,True],[False,True],[0,D+0x6500],[0,1],[[HEAP,D+0x2000],[0,D+0x2000],[HEAP,0],[0,0]]):run206(dict(method=method,old=old,value=value,one=one,two=two,pool=pool,cpu=cpu,heapResults=results))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,bodyExecutions=bodyExecutions,ports=['6E7570 CRT allocation','6E7633 CRT free','4F6740 privatepool allocation','4EFB00 privatepool free'],closure='Actual whole4F0930/4F09D0→4EEF40/4EF280→release diagnostics/memset/SSE, complete debugrecord/list/accounting effects; only heap mechanisms explicit')
(nm.BASE/'reports/script-phase206-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase206-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
