"""Original dynamic command support helpers and bounded dispatch predicate."""
import importlib.util,json,gzip,struct,hashlib,random,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86();BASE=n.DATA;SIZE=0x8000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESI,UC_X86_REG_EAX,UC_X86_REG_EDI
def u(b,p):return struct.unpack_from('<I',b,p-BASE)[0]
def w(b,p,v):struct.pack_into('<I',b,p-BASE,v&0xffffffff)
def quiet(word):return word|0x400000 if(word&0x7f800000)==0x7f800000 and(word&0x7fffff)else word
def alpha(word):
 word=quiet(word);value=struct.unpack('<f',struct.pack('<I',word))[0];return 0 if value<0 else 0x3f800000 if value>1 else word
def selected(opcode,previous,flags,count,mode):return 0x5e0490 if opcode==0x8f else 0x5e0390 if mode else 0x5e02b0 if flags&0x80000000 and count>1 and previous in[0xb0,0xae,0xaf]else 0x5e0200
def model(kind,before,args):
 b=bytearray(before);ret=None
 if kind=='reserve':
  control,record,count=args;p=(u(b,control)+15)&~15;w(b,control,p);w(b,u(b,record+0x14)+4,p);w(b,record+0x24,p);p+=count*16;w(b,control,p);b[p-BASE]=0x8d;b[p-BASE+1]=1;w(b,p+4,u(b,record+0x18)+16);w(b,record+0x14,p);w(b,control,p+16);ret=control
 elif kind=='alpha':command,word=args;w(b,u(b,command+4)+60,alpha(word))
 elif kind=='metadata':
  command,word=args;value=word-0x100000000 if word>=0x80000000 else word;struct.pack_into('<f',b,u(b,command+4)-BASE+56,float(value))
 elif kind=='override':
  shader,first,second,word,fourth,material=args;w(b,shader+0xf8,quiet(word));w(b,shader+0xfc,material);w(b,shader+0x20,u(b,shader+0x20)+1);struct.pack_into('<H',b,shader-BASE+0x1e,(struct.unpack_from('<H',b,shader-BASE+0x1e)[0]+1)&65535);w(b,shader+0xf4,first);w(b,shader+0x180,0)
 else:raise ValueError(kind)
 return bytes(b),ret
errors=[];cases=[];branches=[];excluded=[];counts={'reserve':0,'alpha':0,'metadata':0,'override':0,'dispatch':0,'checkedBytes':0};rng=random.Random(0x603530)
def setup(seed):
 b=bytearray(((i*37+seed*19)^(i>>3))&255 for i in range(SIZE));control=BASE;record=BASE+0x100;command=BASE+0x200;matrix=BASE+0x300;shader=BASE+0x400;w(b,command+4,matrix);w(b,record+0x14,BASE+0x700);w(b,record+0x18,BASE+0x720);return b,control,record,command,shader
def run(kind,b,args):
 before=bytes(b);expected,ret=model(kind,b,args);n.write(BASE,b)
 if kind=='reserve':entry=0x603530;control,record,count=args;n.pack('<I',0x9736e0,control);nativeargs=[record,count]
 elif kind=='alpha':entry=0x603ad0;nativeargs=[args[0],0xfeedface,args[1]]
 elif kind=='metadata':entry=0x603b10;nativeargs=[args[0],0xfeedface,args[1]]
 else:entry=0x5fd220;n.write(0x9868a0,b[args[0]-BASE:args[0]-BASE+420]);nativeargs=args[1:]
 actualret=n.call(entry,args=nativeargs);actual=bytearray(n.read(BASE,SIZE))
 if kind=='override':actual[args[0]-BASE:args[0]-BASE+420]=n.read(0x9868a0,420)
 if kind in ['alpha','override']:
  word=args[1]if kind=='alpha'else args[3]
  if(word&0x7f800000)==0x7f800000 and(word&0x7fffff)and not(word&0x400000):
   target=u(b,args[0]+4)+60 if kind=='alpha'else args[0]+0xf8
   excluded.append({'kind':kind,'args':args,'inputWord':word,'observedUnicornWord':u(actual,target),'before':before.hex(),'reason':'Signaling-NaN load/store domain excluded from source; emulator preserves signaling bit. This observation is not a physical-PC floating-point claim.'});return
 if bytes(actual)!=expected and len(errors)<20:errors.append({'kind':kind,'args':args,'offsets':[i for i,(x,y)in enumerate(zip(actual,expected))if x!=y][:20]})
 if ret is not None and ret!=actualret:errors.append({'kind':kind,'return':actualret,'expected':ret})
 counts[kind]+=1;counts['checkedBytes']+=SIZE;cases.append({'kind':kind,'before':before.hex(),'args':args,'nativeSHA256':hashlib.sha256(actual).hexdigest(),'nativeReturn':actualret if ret is not None else None})
for offset,count in itertools.product(range(16),[0,1,2,3,8,16,255,512]):
 b,control,record,command,shader=setup(offset+count);w(b,control,BASE+0x1000+offset);run('reserve',b,[control,record,count])
words=[0,0x80000000,1,0x80000001,0x007fffff,0x807fffff,0x3f7fffff,0x3f800000,0x3f800001,0xbf800000,0x7f800000,0xff800000,0x7fc12345,0xffc12345,0x7f800001,0xff800001,0x7fbfffff]+[rng.getrandbits(32)for _ in range(512)]
for i,word in enumerate(words):
 b,control,record,command,shader=setup(i);run('alpha',b,[command,word])
integerWords=[0,1,0xffffffff,0x80000000,0x7fffffff]+[(sign*value)&0xffffffff for sign in[1,-1]for value in range(2**24-4,2**24+9)]+[rng.getrandbits(32)for _ in range(512)]
for i,word in enumerate(integerWords):
 b,control,record,command,shader=setup(i);run('metadata',b,[command,word])
for i,word in enumerate(words[:17]):
 for counter in[0,1,0xffff,0xffffffff]:
  b,control,record,command,shader=setup(i);w(b,shader+0x20,counter);struct.pack_into('<H',b,shader-BASE+0x1e,counter&65535);run('override',b,[shader,counter,i*37,word,0xabcdef01,0xfedcba98])
targets={0x5e0490:3,0x5e0390:6,0x5e02b0:4,0x5e0200:5};observed=[]
def boundary(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);observed.append({'target':address,'args':list(n.unpack('<'+'I'*targets[address],sp+4)),'eax':mu.reg_read(UC_X86_REG_EAX),'edi':mu.reg_read(UC_X86_REG_EDI)})
 mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for address in targets:n.mu.hook_add(UC_HOOK_CODE,boundary,begin=address,end=address)
inputs=list(itertools.product([0,0x82,0x8f,0xff],[0,0xae,0xaf,0xb0,0xb1],[0,0x7fffffff,0x80000000,0xffffffff],[-2147483648,-1,0,1,2,2147483647],[0,1,-1]))
inputs.extend((opcode,0xae,0x80000000,2,0)for opcode in range(256))
for i,(opcode,previous,flags,count,mode)in enumerate(inputs):
 material=BASE+0x100;command=BASE+0x400;n.write(BASE,bytes(0x800));n.pack('<I',material+0xb4,flags);n.write(command,bytes([opcode]));n.write(command-0x20,bytes([previous]));observed.clear();n.call(0x5e0530,args=[material,count,0x11223344,0x55667788,mode,0x12345678,0x3e800000,0x87654321],regs={UC_X86_REG_ECX:command,UC_X86_REG_EDX:0xabcd0123,UC_X86_REG_ESI:0xbcde1234});target=selected(opcode,previous,flags,count,mode)
 if len(observed)!=1 or observed[0]['target']!=target:
  if len(errors)<20:errors.append({'kind':'dispatch','input':[opcode,previous,flags,count,mode],'native':observed,'expected':target})
 branches.append({'input':[opcode,previous,flags,count,mode],'native':observed[0]});counts['dispatch']+=1
fp=R/'geometry-dynamic-command-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases,'dispatch':branches,'excludedSignalingNan':excluded},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-dynamic-command-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'errors':errors,'excludedSignalingNanCount':len(excluded),'excludedSignalingNan':[{k:v for k,v in row.items()if k!='before'}for row in excluded],'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'limits':['Reserve/alpha/metadata/override helpers execute unchanged; whole memory and reserve return checked.','Dispatcher executes unchanged until one selected downstream packet writer; that writer is recorded then skipped. Only routine-selection branch projection claimed.','Finite disjoint storage and reserve count0..512 tested; no negative or overflowing arena dimensions.','Compared float domain includes signed zero,infinities and quiet NaNs. Signaling NaNs retained separately as Unicorn observations, excluded from portable source because physical-PC load/store behavior not established.','No managed executable or GPU launched.']};(R/'geometry-dynamic-command-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','fixtureBytes','excludedSignalingNanCount']}));raise SystemExit(bool(errors))
