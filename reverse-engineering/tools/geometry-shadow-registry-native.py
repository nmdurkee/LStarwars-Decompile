"""Original PC registration/reset/query helpers; no computation replacement."""
import importlib.util,json,struct,gzip,hashlib,base64,itertools,random,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';p=B/'tools/native-x86.py';spec=importlib.util.spec_from_file_location('nx',p);nx=importlib.util.module_from_spec(spec);spec.loader.exec_module(nx);n=nx.NativeX86();D=n.DATA;SIZE=0x6000;contexts=[D+0x100+i*0x900 for i in range(8)];cases=[];counts=collections.Counter();errors=[]
u=lambda b,p:struct.unpack_from('<I',b,p-D)[0]
def w(b,p,v):struct.pack_into('<I',b,p-D,v&0xffffffff)
def setup(count,flag,index):
 b=bytearray(bytes([index&255])*SIZE)
 for i,p in enumerate(contexts):w(b,p+0x808,[0,1,0x80000000,0xffffffff][(index+i)%4]);w(b,p+0x824,[0,1,0x80000000,0xffffffff][(index+i//2)%4])
 return b,dict(count=count,flag=flag,contexts=contexts[2:]+contexts[:2],masks=[0,1,0x80000000,0xffffffff,0x7fffffff,2,0xa5a5a5a5,0xdeadbeef])
def model(before,state,operation,arg):
 b=bytearray(before);s=json.loads(json.dumps(state));ret=None
 if operation=='register':
  if s['count']<4 and u(b,arg+0x808)!=0 and u(b,arg+0x824)==0:w(b,arg+0x824,1);s['contexts'][s['count']]=arg;s['count']+=1;s['flag']=0
 elif operation=='reset':
  for p in s['contexts'][:s['count']]:w(b,p+0x824,0)
  s['count']=0;s['flag']=0
 elif operation=='count':ret=s['count']&0xffffffff
 elif operation=='any':ret=int(s['count']>0)
 elif operation=='context':ret=s['contexts'][arg]
 elif operation=='mask':ret=s['masks'][arg]if s['flag']else 0xffffffff
 else:raise ValueError(operation)
 return b,s,ret
def execute(before,state,operation,arg=0,address=None,label=None):
 address=address or dict(register=0x5d0560,reset=0x5d05b0,count=0x5d05f0,any=0x5d0600,context=0x5d0610,mask=0x5d0630)[operation];want,expected,ret=model(before,state,operation,arg)
 n.write(D,before);n.pack('<I',0x966384,state['count']&0xffffffff);n.pack('<I',0x9715a0,state['flag']);n.pack('<8I',0x96d9d0,*state['contexts']);n.pack('<8I',0x96e550,*state['masks']);actualRet=n.call(address,[arg]if operation in ['register','context','mask']else[],count=10000);actual=n.read(D,SIZE);s=dict(count=n.unpack('<i',0x966384)[0],flag=n.unpack('<I',0x9715a0)[0],contexts=list(n.unpack('<8I',0x96d9d0)),masks=list(n.unpack('<8I',0x96e550)))
 if actual!=want or s!=expected or ret is not None and ret!=actualRet:
  errors.append(dict(label=label,address=hex(address),state=s,expectedState=expected,nativeReturn=actualRet,expectedReturn=ret,offsets=[i for i,(a,b)in enumerate(zip(actual,want))if a!=b][:20]));raise AssertionError(errors[-1])
 counts[operation]+=1;counts['cases']+=1;counts['checkedBytes']+=SIZE+72;cases.append(dict(label=label,address=hex(address),operation=operation,arg=arg,beforeZ=base64.b64encode(gzip.compress(before,mtime=0)).decode(),state=state,nativeState=s,nativeReturn=ret,nativeSHA256=hashlib.sha256(actual).hexdigest()));return bytearray(actual),s
flags=[0,1,0x80000000,0xffffffff]
for i,(count,flag,enabled,registered)in enumerate(itertools.product(range(5),flags,[0,1,0x80000000,0xffffffff],[0,1,0x80000000,0xffffffff])):
 b,s=setup(count,flag,i);p=contexts[i%8];w(b,p+0x808,enabled);w(b,p+0x824,registered);execute(b,s,'register',0 if count==4 and i&1 else p,label=['registration',i])
for i,(count,flag,address,duplicates)in enumerate(itertools.product(range(5),flags,[0x5d05b0,0x596950,0x596970],[False,True])):
 b,s=setup(count,flag,i)
 if duplicates:s['contexts'][:4]=[contexts[i%8]]*4
 execute(b,s,'reset',address=address,label=['reset',i])
for i,(count,flag)in enumerate(itertools.product([-2147483648,-1,0,1,4,5,2147483647],flags)):
 b,s=setup(count,flag,i)
 for op in ['count','any']:execute(b,s,op,label=['signed-query',i,op])
 for slot in range(4):
  for op in ['context','mask']:execute(b,s,op,slot,label=['query',i,slot,op])
 if flag==0:execute(b,s,'mask',-2147483648,label=['uncached-no-slot-read',i])
rng=random.Random(0x5d0560)
for sequence in range(32):
 b,s=setup(0,flags[sequence%4],sequence)
 for step in range(40):
  choice=rng.randrange(8);op='register'if choice<4 else'reset'if choice==4 else'count'if choice==5 else'context'if choice==6 else'mask';arg=contexts[rng.randrange(8)]if op=='register'else rng.randrange(4)
  if op=='register'and step%3==0:w(b,arg+0x808,1);w(b,arg+0x824,0)
  b,s=execute(b,s,op,arg,label=['sequence',sequence,step])
fp=R/'geometry-shadow-registry-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-registry-native-v1',passed=not errors,binarySHA256=n.sha256,counts=dict(counts),errors=errors,fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['All six original helpers plus two direct reset entry thunks execute without replacements. Void helper EAX is not assigned a semantic result.','Mutating count0..4, four addressable slots plus four unchanged guard slots, valid disjoint context records and globals. Query helpers separately cover negative/min/max signed counts.','Full registry returns before reading context; uncached mask lookup returnsffffffff before reading even an invalid index. Positive count query uses signed>0.','Reset clears active context+824 fields, count and cache flag, leaving pointer slots/masks untouched; repeated pointers are permitted.','Synthetic exact layouts and32 sequential40-operation scenarios; no claim of original context/volume construction, GPU behavior or managed execution.']);(R/'geometry-shadow-registry-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
