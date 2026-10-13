"""Original shader-context command emission and payload builders."""
import importlib.util,struct,json,gzip,hashlib,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
BASE=0x11000000;SIZE=0x100000;n.mu.mem_map(BASE,SIZE);memory=bytearray();calls=[];cases=[];errors=[];counts={'payload':0,'emission':0,'nullShader':0,'checkedBytes':0};digest=hashlib.sha256()
def seq(size,seed):return bytes(((i*37+seed*19)^(i>>3))&255 for i in range(size))
def alloc(size,seed):
 p=(len(memory)+15)&~15;memory.extend(bytes(p-len(memory)));memory.extend(seq(size,seed));return BASE+p
def u(b,p):return struct.unpack_from('<I',b,p-BASE)[0]
def w(b,p,v):struct.pack_into('<I',b,p-BASE,v&0xffffffff)
def hh(b,p):return struct.unpack_from('<H',b,p-BASE)[0]
def wh(b,p,v):struct.pack_into('<H',b,p-BASE,v&65535)
def compare(a,e,where):
 counts['checkedBytes']+=len(a);digest.update(a);digest.update(e)
 if a!=e and len(errors)<20:errors.append({'context':where,'actualSize':len(a),'expectedSize':len(e),'firstOffsets':[i for i,(x,y)in enumerate(zip(a,e))if x!=y][:16]})
def observe(mu,a,size,_):calls.append(a)
for a in [0x607590,0x6034b0,0x5fcdf0,0x5fcef0,0x5fcf30,0x5fcf60,0x5fcfd0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def align(b,control):
 p=(u(b,control)+15)&~15;w(b,control,p);return p
def payload(b,address,shader,control,descriptor):
 if address==0x5fcfd0 and not descriptor:return 0
 p=align(b,control)
 if address==0x5fcdf0:
  w(b,control,p+188)
  for dst,src in [(0,0x38),(4,0x68),(16,0x44),(8,0x74),(20,0x50),(12,0x80),(24,0x5c)]:
   for j in range(3):w(b,p+(dst+j)*4,u(b,shader+src+j*4))
   w(b,p+(dst+3)*4,0x3f800000)
  for j in range(16):w(b,p+(28+j)*4,u(b,shader+0x90+j*4))
  for j in range(3):w(b,p+(44+j)*4,u(b,shader+0xd0+j*4))
 elif address==0x5fcef0:w(b,p,u(b,shader+0xf8)if u(b,shader+0xf4)else 0x3f800000);w(b,control,p+4)
 elif address==0x5fcf30:w(b,p,u(b,shader+0x194));w(b,control,p+4)
 elif address==0x5fcf60:
  c=u(b,shader+0x16c);w(b,p,c);w(b,control,p+4)
  if c:
   for j,off in enumerate([0x178,0x170,0x174,0x17c]):w(b,p+4+j*4,u(b,shader+off))
   w(b,control,p+20)
 elif address==0x5fcfd0:
  count=b[descriptor-BASE];w(b,p,count);w(b,p+4,b[descriptor-BASE+2]);w(b,control,p+8+((count+3)//4)*16);source=u(b,descriptor+4)
  for j in range(count):
   value=b[source-BASE+j];value=value-256 if value>=128 else value;struct.pack_into('<f',b,p-BASE+8+j*4,value)
 return p
def append(b,control,record,typeCode,p):
 new=align(b,control);w(b,u(b,record+0x14)+4,new);b[new-BASE]=typeCode;b[new-BASE+1]=3;w(b,new+4,p or new+32);b[new-BASE+16]=0x8d;b[new-BASE+17]=1;w(b,new+20,u(b,record+0x18)+16);w(b,record+0x14,new+16);w(b,control,new+32)
def emit(before,record,shader,control,descriptor,globalToken):
 b=bytearray(before);trace=[0x607590]
 if not shader or u(b,u(b,record+8)+0x20)==u(b,shader+0x20):return bytes(b),trace
 ctx=u(b,record+8)
 for key,cache,helper,command in [(0x24,0x34,0x5fcdf0,0x94),(0x2c,0x110,0,0x9a),(0x2e,0x168,0x5fcf60,0xa6),(0x1e,0x180,0x5fcef0,0xa5),(0x32,0x198,0x5fcf30,0xab),(0x30,0,0x5fcfd0,0xa9)]:
  if hh(b,ctx+key)==hh(b,shader+key):continue
  p=0 if not cache else u(b,shader+cache)
  if helper==0x5fcfd0:
   trace.append(helper);p=payload(b,helper,shader,control,descriptor)
  elif not p:
   if helper:trace.append(helper);p=payload(b,helper,shader,control,descriptor);w(b,shader+cache,p)
   else:
    p=align(b,control);w(b,shader+cache,p);k=hh(b,shader+0x2c);k=k-65536 if k>=32768 else k;w(b,p,(k+5)*(u(b,shader+0x20)+13)+globalToken);w(b,control,p+4)
    for j in range(16):w(b,p+4+j*4,u(b,shader+0x114+j*4))
    w(b,control,p+68);local=bytearray(64)
    for dst,src in [(0,0x154),(20,0x158),(40,0x15c),(44,0x160),(56,0x164)]:struct.pack_into('<I',local,dst,u(b,shader+src))
    b[p-BASE+68:p-BASE+132]=local;w(b,control,p+132)
    for j in range(4):w(b,p+132+j*4,u(b,shader+0x184+j*4))
    w(b,control,p+148)
  if p:trace.append(0x6034b0);append(b,control,record,command,p)
  wh(b,ctx+key,hh(b,shader+key))
 w(b,ctx+0x20,u(b,shader+0x20));return bytes(b),trace
def setup(seed,count,offset=0):
 global memory
 memory=bytearray();control=alloc(4,seed);shader=alloc(420,seed+1);record=alloc(68,seed+2);ctx=alloc(52,seed+3);tail=alloc(16,seed+4);saved=alloc(32,seed+5);desc=alloc(8,seed+6)if count is not None else 0;source=alloc(256,seed+7);cached=alloc(256,seed+8);arena=alloc(4096,seed+9)
 if desc:memory[desc-BASE]=count;memory[desc-BASE+2]=(seed*17)&255;w(memory,desc+4,source)
 w(memory,control,arena+offset);w(memory,record+8,ctx);w(memory,record+0x14,tail);w(memory,record+0x18,saved)
 return control,shader,record,ctx,desc,cached
def native_case(kind,label,address,control,shader,record,desc,token,expected,trace,expectedRet=None):
 before=bytes(memory);n.write(BASE,before);n.pack('<I',0x9736e0,control);n.pack('<I',0x9738a4,desc);n.pack('<I',0x297dc00,token);calls.clear();ret=n.call(address,args=[record,shader]if address==0x607590 else[shader],count=300000);after=n.read(BASE,len(before));compare(after,expected,label);compare(struct.pack('<'+'I'*len(calls),*calls),struct.pack('<'+'I'*len(trace),*trace),[label,'calls'])
 if expectedRet is not None:compare(struct.pack('<I',ret),struct.pack('<I',expectedRet),[label,'return'])
 counts[kind]+=1;cases.append({'kind':kind,'entry':address,'before':before.hex(),'control':control,'shader':shader,'record':record,'descriptor':desc,'globalToken':token,'nativeReturn':ret if expectedRet is not None else None,'nativeSHA256':hashlib.sha256(after).hexdigest(),'nativeCalls':list(calls)})
for address,offset,seed in itertools.product([0x5fcdf0,0x5fcef0,0x5fcf30,0x5fcf60,0x5fcfd0],range(16),range(8)):
 count=[None,0,1,3,4,5,127,255][seed];control,shader,record,ctx,desc,cached=setup(seed,count,offset);w(memory,shader+0xf4,[0,1,2,0xffffffff][seed%4]);w(memory,shader+0x16c,[0,1,2,0xffffffff][seed%4]);expected=bytearray(memory);ret=payload(expected,address,shader,control,desc);native_case('payload',[hex(address),offset,seed],address,control,shader,record,desc,0,bytes(expected),[address],ret)
for mask,cachedPresent,idEqual,count in itertools.product(range(64),[False,True],[False,True],[None,0,3,255]):
 seed=mask+int(cachedPresent)*11+int(idEqual)*17;control,shader,record,ctx,desc,cached=setup(seed,count,mask%16);ident=[0,1,0xffffffff,0x80000000,0x7fffffff][mask%5];w(memory,shader+0x20,ident);w(memory,ctx+0x20,ident if idEqual else ident^0xffffffff);w(memory,shader+0xf4,mask&1);w(memory,shader+0x16c,mask&2)
 for bit,key in enumerate([0x24,0x2c,0x2e,0x1e,0x32,0x30]):
  value=[0,1,0x7fff,0x8000,0xffff][(mask+bit)%5];wh(memory,shader+key,value);wh(memory,ctx+key,value^1 if mask&(1<<bit)else value)
 for i,cache in enumerate([0x34,0x110,0x168,0x180,0x198]):w(memory,shader+cache,cached+i*32 if cachedPresent else 0)
 token=(0x98765432+mask*719)&0xffffffff;expected,trace=emit(memory,record,shader,control,desc,token);native_case('emission',['emit',mask,cachedPresent,idEqual,count],0x607590,control,shader,record,desc,token,expected,trace)
for seed in range(16):
 control,shader,record,ctx,desc,cached=setup(seed,3,seed);native_case('nullShader',['null',seed],0x607590,control,0,record,desc,0,bytes(memory),[0x607590])
fp=R/'geometry-shader-emission-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-shader-emission-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'errors':errors,'resultSHA256':digest.hexdigest(),'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'boundaries':{'native':'All six principal helpers, original append6034b0 and CRT memset/copies execute unchanged. Observation hooks do not substitute instructions.','data':'Controlled valid memory images and opaque32-bit data words. All64 combinations of changed context words, cached/uncached modes, matching/different identifiers and absent/empty/nonempty signed-byte arrays.'},'limits':['Synthetic runtime state; this is not an observed live frame.','Finite nonoverlapping writable data/packet memory and valid pointer domains; capacity and uint address overflow excluded.','Full shader emission CPU memory behavior only, not GPU interpretation of command payloads.','No compiled C# execution attempted.']}
(R/'geometry-shader-emission-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in ['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))

