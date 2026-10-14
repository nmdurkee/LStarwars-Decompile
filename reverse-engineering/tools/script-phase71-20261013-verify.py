"""Actual memory-file allocation4f02d0 and read4fb4f0 including public4fb550 transport dispatch; disjoint prepared memory and20slots."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86();D=n.DATA;TABLE=0x2983740;DATA=D+0x1000;OUT=D+0x4000
segments=[(TABLE,400),(DATA,0x1000),(OUT,0x2000)];shadow={};checks=0;errors=[];cases=[]
def rb(p):return shadow[p]
def wb(p,v):shadow[p]=v&255
def rd(p):return sum(rb(p+i)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):wb(p+i,v>>(8*i))
def signed(v):return v-0x100000000 if v&0x80000000 else v
def snap(model=False):return[dict(address=p,bytes=bytes(rb(p+i)for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def open71(data,length,mode):
 if signed(length)<=0 or mode not in[0,1]:return 0
 for i in range(20):
  slot=TABLE+i*20
  if not rd(slot+16):wd(slot+4,(data+length-1)&0xffffffff);wd(slot+12,mode);wd(slot,data);wd(slot+8,data);wd(slot+16,1);return 0x400+i
 return 0
def read71(handle,out,length):
 slot=TABLE+(handle-0x400)*20;cursor=rd(slot+8);remaining=signed((rd(slot+4)-cursor+1)&0xffffffff);count=min(signed(length),remaining)
 assert count>=0
 for i in range(count):wb(out+i,rb(cursor+i))
 if count:wd(slot+8,(rd(slot+8)+count)&0xffffffff)
 return count

def setup71(c):
 n.write(TABLE,bytes(400));n.write(DATA,bytes((i*37+11)&255 for i in range(4096)));n.write(OUT,bytes([0xa5])*0x2000)
 for i in range(20):n.pack('<5I',TABLE+i*20,0x11111111+i,0x22222222+i,0x33333333+i,0x44444444+i,0 if i in c.get('freeSlots',[0])else c.get('liveValue',1))
 if c['method']!='Open':
  index=c['index'];slot=TABLE+index*20;size=c['size'];n.pack('<5I',slot,DATA,DATA+size-1,DATA+c['position'],c.get('mode',0),c.get('live',1))
def execute71(c):
 global shadow,checks
 setup71(c);initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 if c['method']=='Open':inputs=dict(data=c.get('data',DATA),length=c['length'],mode=c['mode']);wanted=open71(**inputs);actual=n.call(0x4f02d0,list(inputs.values()))
 else:inputs=dict(handle=0x400+c['index'],out=OUT+c.get('outOffset',0),length=c['wanted']);wanted=read71(**inputs);actual=n.call(0x4fb550 if c['method']=='PublicRead'else 0x4fb4f0,list(inputs.values()))
 final=snap();model=snap(True)
 for group,a,b in [('return',actual,wanted),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method=c['method'],context=c,inputs=inputs,initial=initial,returnValue=actual,final=final))
for free,length,mode,data in itertools.product([[0],[1],[7],[19],[],[3,7,19]],[0,1,17,1024,0x80000000,0xffffffff],[0,1,2,0xffffffff],[0,DATA]):execute71(dict(method='Open',freeSlots=free,length=length,mode=mode,data=data))
for method,index,size,position,wanted in itertools.product(['Read','PublicRead'],[0,7,19],[1,17,1024],[0,1],[0,1,2,16,17,1023,1024,2048]):
 if position>size:continue
 execute71(dict(method=method,index=index,size=size,position=position,wanted=wanted))
rng=random.Random(0x4fb4f0)
for i in range(256):
 size=rng.randrange(1,2049);position=rng.randrange(size+1);execute71(dict(method='PublicRead'if i&1 else 'Read',index=rng.randrange(20),size=size,position=position,wanted=rng.randrange(4097),outOffset=rng.randrange(32),mode=i&1,live=0 if i&2 else 7))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=2,ports=[],closure='Original4f02d0→20slot memoryfile table; original4fb550→4fb4f0→6e6d90 memory copy; no reader/allocation adapters')
(nm.BASE/'reports/script-phase71-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase71-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
