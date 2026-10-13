"""Original enable, selective shallow copy and copy-before-reset snapshot."""
import importlib.util,json,struct,gzip,hashlib,base64,itertools,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';p=B/'tools/native-x86.py';sp=importlib.util.spec_from_file_location('nx',p);nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86();D=n.DATA;SIZE=0x10000;SOURCE=D+0x1000;DEST=D+0x2000;CONTROL=D+0x100;cases=[];counts=collections.Counter();calls=[]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
addresses={'enable':0x55f3e0,'volume':0x5c8a00,'context':0x5e8da0,'snapshot':0x5f3020}
def hook(mu,address,size,user):calls.append(address)
for a in list(addresses.values())+[0x5fca40]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def u(b,p):return struct.unpack_from('<I',b,p-D)[0]
def si(b,p):return struct.unpack_from('<i',b,p-D)[0]
def w(b,p,v):struct.pack_into('<I',b,p-D,v&0xffffffff)
def words(b,dst,src,start,end):
 for off in range(start,end,4):w(b,dst+off,u(b,src+off))
def copyVolume(b,dst,src,trace):
 trace.append(0x5c8a00)
 for start,end in [(0,0x114),(0x120,0x264),(0x270,0x378)]:words(b,dst,src,start,end)
def copyContext(b,dst,src,trace):
 trace.append(0x5e8da0);copyVolume(b,dst,src,trace);copyVolume(b,dst+0x380,src+0x380,trace)
 for start,end in [(0x700,0x714),(0x720,0x828)]:words(b,dst,src,start,end)
def model(before,op,arg):
 b=bytearray(before);trace=[];ret=None
 if op=='volume':copyVolume(b,arg,SOURCE,trace)
 elif op=='context':copyContext(b,arg,SOURCE,trace)
 elif op=='enable':
  trace.append(0x55f3e0)
  if arg and u(b,SOURCE+0x808)==0:
   for i in range(si(b,SOURCE+0x70c)):
    for alternate in range(2):p=SOURCE+i*0x380+0x2a4+alternate*0x44;w(b,p+0x14,u(b,p+0x10))
  w(b,SOURCE+0x808,arg)
 elif op=='snapshot':
  trace.append(0x5f3020);ret=(u(b,CONTROL)+31)&~31;w(b,CONTROL,ret+0x830);copyContext(b,ret,SOURCE,trace)
  for i in range(si(b,SOURCE+0x70c)):
   p=SOURCE+i*0x380;w(b,p+0x374,0)
   for alternate in range(2):
    record=p+0x2a4+alternate*0x44;shader=u(b,record+8);trace.append(0x5fca40)
    for off,v in [(8,0),(20,0xffffffff),(32,0xffffffff)]:w(b,shader+off,v)
    for off in [0x24,0x2c,0x2e,0x1e]:struct.pack_into('<H',b,shader-D+off,65535)
    head=u(b,record+16);w(b,record+20,head);b[head-D]=0x8d;w(b,head+4,0);b[head-D+1]=1
 else:raise ValueError(op)
 return b,ret,trace
def setup(index,count=2,enabled=0):
 b=bytearray(bytes((i*29+index*13)&255 for i in range(256))*(SIZE//256));w(b,CONTROL,D+0x7000+(index&31));w(b,SOURCE+0x70c,count);w(b,SOURCE+0x808,enabled)
 for vi in range(2):
  for alt in range(2):
   record=SOURCE+vi*0x380+0x2a4+alt*0x44;w(b,record+8,D+0x5000+vi*128+alt*64);w(b,record+16,D+0x6000+vi*32+alt*16)
 return b
def execute(before,op,arg,label):
 want,ret,trace=model(before,op,arg);n.write(D,before);calls.clear();ecx=arg if op in ['volume','context']else SOURCE;actualRet=n.call(addresses[op],args=[SOURCE]if op in ['volume','context']else[CONTROL]if op=='snapshot'else[arg],regs={UC_X86_REG_ECX:ecx},count=100000);actual=n.read(D,SIZE)
 if actual!=want or calls!=trace or ret is not None and actualRet!=ret:raise AssertionError(dict(op=op,label=label,offsets=[i for i,(a,b)in enumerate(zip(actual,want))if a!=b][:24],nativeReturn=actualRet,expectedReturn=ret,calls=calls,trace=trace))
 counts['cases']+=1;counts[op]+=1;counts['checkedBytes']+=SIZE;cases.append(dict(operation=op,arg=arg,label=label,beforeZ=base64.b64encode(gzip.compress(before,mtime=0)).decode(),nativeReturn=ret,nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeCalls=trace));return bytearray(actual)
for i,(count,old,new)in enumerate(itertools.product([-1,0,1,2],[0,1,0x80000000,0xffffffff],[0,1,0x80000000,0xffffffff])):execute(setup(i,count,old),'enable',new,['enable',count,old,new])
for i in range(512):
 for op in ['volume','context']:execute(setup(i),'%s'%op,SOURCE if i%5==0 else DEST,['copy',i])
for i,(count,align)in enumerate(itertools.product([-1,0,1,2],range(32))):
 b=setup(i,count);w(b,CONTROL,D+0x7000+align);execute(b,'snapshot',0,['snapshot',count,align])
for i in range(64):
 b=setup(i,i%3);b=execute(b,'enable',1,['sequence-enable',i]);b=execute(b,'snapshot',0,['sequence-first',i]);b=execute(b,'snapshot',0,['sequence-second',i])
fp=R/'geometry-shadow-lifecycle-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,source=SOURCE,control=CONTROL,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-lifecycle-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Four original helpers and actual selective-copy/cache-reset dependencies execute unchanged, observations only.','Disjoint source/destination/resource buffers or exact self-copy; partial overlap remains unsupported. Pure bit copies preserve arbitrary words, including float bit patterns without interpreting them.','Constructed volume capacity0..2 (negative count exercises native no-loop behavior), all32 snapshot alignments, repeated snapshots and enable transitions.','Snapshot captures the shallow context before resetting original source frame counts/tails and shared pointed-to cache/head resources. Padding gaps remain untouched.','No context-plane construction, GPU work or managed runtime equality claim.']);(R/'geometry-shadow-lifecycle-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
