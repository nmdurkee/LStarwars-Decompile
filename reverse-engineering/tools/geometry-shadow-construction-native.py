"""Original shadow context pools and full constructor chains, no stubs."""
import importlib.util,json,struct,gzip,hashlib,base64,random,collections,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';p=B/'tools/native-x86.py';sp=importlib.util.spec_from_file_location('nx',p);nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86();D=0x974000;SIZE=0x4500;CP=0x9740a8;HP=0x974020;SP=0x978230;cases=[];counts=collections.Counter();calls=[]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
def hook(mu,address,size,user):calls.append(address)
addresses=[0x5f20c0,0x5f2160,0x5f2200,0x5f5ce0,0x5f5d90,0x5f7420,0x5fca40]
for a in addresses:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def u(b,p):return struct.unpack_from('<I',b,p-D)[0]
def w(b,p,v):struct.pack_into('<I',b,p-D,v&0xffffffff)
def alloc(b,p,stride,trace,address):
 trace.append(address);cursor=u(b,p+8*stride+4);mask=b[p+8*stride-D]
 for offset in range(8):
  i=(cursor+offset)&7
  if mask>>i&1==0:b[p+8*stride-D]=mask|(1<<i);w(b,p+8*stride+4,(i+1)&7);return p+i*stride
 return 0
def volume(b,p,trace):
 trace.append(0x5f5ce0)
 for off,value in [(0x100,0x3c23d70a),(0x104,0x3a83126f),(0x374,0),(0x110,0x3f800000),(0x260,0)]:w(b,p+off,value)
 for i in range(2):
  head=alloc(b,HP,16,trace,0x5f2200);w(b,p+0x334+i*4,head);shader=alloc(b,SP,64,trace,0x5f2160);w(b,p+0x32c+i*4,shader);assert head and shader
  record=p+0x2a4+i*0x44;b[record-D:record-D+0x44]=bytes(0x44);w(b,record+16,head);b[head-D]=0x8d;w(b,head+4,0);b[head-D+1]=1;w(b,record+20,head);w(b,record+8,shader);trace.append(0x5fca40)
  for off,val in [(8,0),(20,0xffffffff),(32,0xffffffff)]:w(b,shader+off,val)
  for off in [0x24,0x2c,0x2e,0x1e]:struct.pack_into('<H',b,shader-D+off,65535)
  w(b,record+20,u(b,record+16))
 return p
def context(b,p,trace):
 trace.append(0x5f5d90);volume(b,p,trace);volume(b,p+0x380,trace)
 for off,val in [(0x810,0x40800000),(0x808,0),(0x710,0),(0x814,0x3e800000),(0x800,0),(0x804,0),(0x80c,0x3f4ccccd),(0x824,0),(0x818,0),(0x70c,2),(0x81c,0x42c80000),(0x820,0x42dc0000)]:w(b,p+off,val)
 return p
def model(before,op,arg):
 b=bytearray(before);trace=[]
 if op=='context-pool':ret=alloc(b,CP,0x830,trace,0x5f20c0)
 elif op=='shader-pool':ret=alloc(b,SP,64,trace,0x5f2160)
 elif op=='command-pool':ret=alloc(b,HP,16,trace,0x5f2200)
 elif op=='volume':ret=volume(b,arg,trace)
 elif op=='context':ret=context(b,arg,trace)
 elif op=='create':
  trace.append(0x5f7420);ret=alloc(b,CP,0x830,trace,0x5f20c0)
  if ret:context(b,ret,trace)
 else:raise ValueError(op)
 return b,ret,trace
def setup(index):
 b=bytearray(bytes((i*37+index*19)&255 for i in range(256))*(SIZE//256))
 for p,stride in [(CP,0x830),(HP,16),(SP,64)]:b[p+stride*8-D]=0;w(b,p+stride*8+4,index&7)
 return b
def execute(before,op,arg,index):
 want,ret,trace=model(before,op,arg);address=dict(zip(['context-pool','shader-pool','command-pool','volume','context','create'],addresses[:6]))[op];n.write(D,before);calls.clear();actualRet=n.call(address,regs={UC_X86_REG_ECX:arg},count=100000);actual=n.read(D,SIZE)
 if actual!=want or actualRet!=ret or calls!=trace:raise AssertionError(dict(op=op,index=index,nativeReturn=actualRet,expectedReturn=ret,calls=calls,trace=trace,offsets=[i for i,(a,b)in enumerate(zip(actual,want))if a!=b][:20]))
 counts['cases']+=1;counts[op]+=1;counts['checkedBytes']+=SIZE;cases.append(dict(operation=op,arg=arg,label=index,beforeZ=base64.b64encode(gzip.compress(before,mtime=0)).decode(),nativeReturn=actualRet,nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeCalls=trace));return bytearray(actual)
for op,p,stride in [('context-pool',CP,0x830),('shader-pool',SP,64),('command-pool',HP,16)]:
 for mask,cursor in itertools.product(range(256),range(8)):
  b=setup(mask*8+cursor);b[p+stride*8-D]=mask;w(b,p+stride*8+4,cursor);execute(b,op,p,[mask,cursor])
rng=random.Random(0x5f5ce0)
for i in range(768):
 op=['volume','context','create'][i%3];b=setup(i);minimumFree=2 if op=='volume'else 4
 for p,stride in [(HP,16),(SP,64)]:
  mask=rng.randrange(256)
  while mask.bit_count()>8-minimumFree:mask=rng.randrange(256)
  b[p+stride*8-D]=mask;w(b,p+stride*8+4,rng.randrange(8))
 b[CP+0x4180-D]=rng.randrange(256);w(b,CP+0x4184,rng.randrange(8));arg=CP+(i%8)*0x830
 if op=='volume':arg+=(i//8%2)*0x380
 execute(b,op,arg,i)
for i in range(8):
 b=setup(i);b[CP+0x4180-D]=255;b[HP+0x80-D]=255;b[SP+0x200-D]=255;execute(b,'create',0,['exhausted',i])
for i in range(32):
 b=setup(i)
 for step in range(2):b=execute(b,'create',0,['sequential',i,step])
fp=R/'geometry-shadow-construction-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,contextPool=CP,commandPool=HP,shaderPool=SP,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-construction-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['All original pool scan/allocation, volume/context construction, memset and5fca40 cache-reset instructions execute unchanged. Observation hooks only.','Exhaustive256 occupancy masks times8 valid cursors for all three8-slot pools; complete original returned pointer and every persistent image byte compared.','Volume/context/create chains require successful subordinate pool capacity (2/4 command and shader slots). Original constructor dereferencesnull on subordinate exhaustion; no invented recovery policy. Context-pool exhaustion returns0 before subordinate use.','Exactly two0x380 volumes fit a0x830 context; default values and two0x44 packet records per volume preserved. Uninitialized/untouched fields retain their original input bytes.','Controlled persistent pool image at original logical globals, no game process/device services. Plane production, context enable/update, GPU rendering and managed equality remain separate.']);(R/'geometry-shadow-construction-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
