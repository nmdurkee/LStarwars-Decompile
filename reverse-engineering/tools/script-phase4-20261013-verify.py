"""Original AddToSet/OnSpeederBike, original packet numeric resolver and parser.
Named-character callback alone adapted; no producer/loader or game execution.
"""
import importlib.util,json,struct,itertools,re,hashlib,random
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;PACK=D+0x1000;SCRIPT=D+0x2000;CRE=D+0x3000;REF=D+0x4000;ACTORS=D+0x6000;VEHICLES=D+0xa000;ARGS=D+0xe000;TEXT=D+0xf000;NAMES=D+0x15000;RESULT=D+0x16000;LIST=D+0x17000;COND=D+0x17100;DEF=D+0x17200;ADAPTER=n.STOP+0x100;COUNTS=0x876847
checks={};errors=[];setcases=[];bikecases=[];initializers=[];shipped=[];calls=[];bindings={}
def check(group,got,want,meta=None):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def fl(x):return struct.unpack('<f',struct.pack('<I',x))[0]
def f32(x):return fl(bits(x))
def actor(i):return ACTORS+i*0x1100
def reference(i):return REF+i*0x100
def vehicle(i):return VEHICLES+i*0x1100
def string(p):return n.read(p,512).split(b'\0')[0].decode('ascii')if p else None
def callback(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);system=n.unpack('<I',sp+4)[0];name=string(n.unpack('<I',sp+8)[0]);calls.append(dict(system=system!=0,name=name));result=bindings.get((name or '').lower(),0);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,callback,begin=ADAPTER,end=ADAPTER)
def init(tokens=None,c=None):
 tokens=tokens or [];c=c or {};n.write(D,bytes(0x18000));calls.clear();bindings.clear();bindings.update({'self':reference(0),'other':reference(1),'empty':reference(2)})
 n.pack('<I',0x923904,ADAPTER if c.get('callback',True)else 0);n.pack('<h',0x7f1948,c.get('bikeType',7));n.pack('<I',CRE+0xd0,reference(0)if c.get('reference',True)else 0)
 for i in range(2):
  n.write(actor(i),bytes([0x5a+i])*0x1100);n.pack('<I',reference(i),actor(i)if i!=0 or c.get('worldObject',True)else 0);n.pack('<B',actor(i)+0x378,c.get('initialSet',5));n.pack('<B',actor(i)+0x7b5,c.get('contextByte',59)if i==0 else c.get('boundContextByte',59));n.pack('<I',actor(i)+0xcd0,vehicle(i)if c.get('linked',True)and(i==0 or c.get('boundLinked',True))else 0);n.pack('<h',vehicle(i)+0x1064,c.get('vehicleType',7)if i==0 else c.get('boundVehicleType',7))
 counters=c.get('counts',[(i*13+c.get('countSeed',11))&255 for i in range(17)]);n.write(COUNTS,bytes(counters));n.pack('<I',PACK+4,SCRIPT if c.get('script',True)else 0)
 values=c.get('parameters',[2.75,1.,16.,17.]);n.pack('<4f',PACK+0x14,*values)
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.write(NAMES+i*128,name.encode()+b'\0');n.pack('<I',SCRIPT+0x18+i*8,NAMES+i*128)
 for i,t in enumerate(tokens):
  if t is None:n.pack('<I',ARGS+i*4,0)
  else:n.write(TEXT+i*512,t.encode()+b'\0');n.pack('<I',ARGS+i*4,TEXT+i*512)
def token(t):
 if t is None:return 0
 n.write(TEXT+0x5000,t.encode()+b'\0');return TEXT+0x5000
def number(t,c):
 if t is None:return 0.
 if c.get('packet',True):
  if 'param' in t.lower():return f32(c.get('parameters',[2.75,1.,16.,17.])[0])
  if c.get('script',True)and t.lower()in ['alpha','beta','gamma','delta']:return f32(c.get('parameters',[2.75,1.,16.,17.])[['alpha','beta','gamma','delta'].index(t.lower())])
 i=0;v=0.;d=1.
 if t.startswith('-'):d=-1.;i=1
 while i<len(t)and'0'<=t[i]<='9':v=f32(f32(v*10)+int(t[i]));i+=1
 if i<len(t)and t[i]=='.':
  i+=1
  while i<len(t)and'0'<=t[i]<='9':d=f32(d*10);v=f32(f32(v*10)+int(t[i]));i+=1
 return f32(v/d)
def setcase(tokens,c,group,source=None):
 init(tokens,c);before=n.read(actor(0),0x1100);oldcounts=list(n.read(COUNTS,17));selected=c.get('initialSet',5);expectedcounts=list(oldcounts)
 if c.get('first',True)and c.get('creature',True)and c.get('reference',True)and c.get('worldObject',True):
  for t in tokens:
   if t is not None and t.lower()=='reset':selected=0
   else:
    value=number(t,c);assert -2147483648<=value<2147483648;selector=int(value)
    if 1<=selector<=16:selected=selector;expectedcounts[selector]=(expectedcounts[selector]+1)&255
 ret=n.call(0x4499b0,[SYS,PACK if c.get('packet',True)else 0,CRE if c.get('creature',True)else 0,ARGS,len(tokens),int(c.get('first',True))]);got=n.unpack('<B',actor(0)+0x378)[0];counts=list(n.read(COUNTS,17));expected=bytearray(before);expected[0x378]=selected;confined=n.read(actor(0),0x1100)==bytes(expected);check(group+'-return',ret,1);check(group+'-set-and-counts',[got,counts],[selected,expectedcounts],dict(tokens=tokens,context=c));check(group+'-actor-write-confinement',confined,True)
 row=dict(tokens=tokens,context=c,nativeReturn=ret,nativeSet=got,nativeCounts=counts,writesConfined=confined)
 if source:row['source']=source
 setcases.append(row)
def bikecase(c,group,source=None):
 init(c=c);bound=actor(1)if c.get('bound',False)else 0;cre=CRE if c.get('creature',True)else 0;n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT))
 if not bound and not cre:
  try:n.call(0x443200,[SYS,PACK,cre,0,bound])
  except RuntimeError as e:check(group+'-fault',True,True);bikecases.append(dict(context=c,nativeFault=str(e)));return
  check(group+'-fault',False,True);return
 n.call(0x443200,[SYS,PACK,cre,0,bound]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',RESULT)[0];present=bool(bound)or(c.get('reference',True)and c.get('worldObject',True));linked=c.get('linked',True)and(not bound or c.get('boundLinked',True));mode=c.get('boundContextByte',59)if bound else c.get('contextByte',59);typ=c.get('boundVehicleType',7)if bound else c.get('vehicleType',7);want=bits(float(present and linked and mode==59 and typ==c.get('bikeType',7)));check(group,got,want,c);row=dict(context=c,nativeBits=got)
 if source:row['source']=source
 bikecases.append(row)
# Numeric token and packet/alias paths; strings map through original6147c0,
# original float parser and6e6b90 integer truncation (no scalar service hook).
sets=[[],[None],['Reset'],['reset','1'],['1','Reset'],['1','1'],['1','2'],['1','17'],['param3'],['prefixPARAMfoo'],['alpha'],['beta','gamma','delta'],['1.9999999'],['16.99999'],['0.99999999'],['0.99999994'],['+1'],[' 1'],['1tail'],['17','-1','2.75'],['Reset','Reset'],['alpha','RESET','gamma','1','1']]+[[str(i)]for i in range(-2,20)]
for tokens,first,creature,reference_present,world,packet,script in itertools.product(sets,[False,True],[False,True],[False,True],[False,True],[False,True],[False,True]):setcase(tokens,dict(first=first,creature=creature,reference=reference_present,worldObject=world,packet=packet,script=script),'set-token-packet-self-gates')
for selector,count in itertools.product(range(1,17),range(256)):
 counts=[0]*17;counts[selector]=count;setcase([str(selector)],dict(counts=counts,initialSet=selector),'set-same-membership-all-count-byte-wraps')
for tokens in [['1','1','1'],['1','2','1','Reset','2'],['Reset','1','Reset']]:setcase(tokens,dict(counts=[255]*17,initialSet=7),'set-ordered-reassignment-reset-without-decrement')
# Bike global comparison is a word, and initialized object bypasses self chain.
for bound,creature,reference_present,obj,linked,mode,match in itertools.product([False,True],[False,True],[False,True],[False,True],[False,True],[0,59,255],[False,True]):bikecase(dict(bound=bound,creature=creature,reference=reference_present,worldObject=obj,linked=linked,contextByte=mode,boundContextByte=mode,vehicleType=7 if match else 8,boundVehicleType=7 if match else 8),'bike-bound-precedence-fallback-pointer-context-type')
for typ in [-32768,-1,0,1,7,32767]:
 for linked_type in [typ,-32768,-1,0,32767]:bikecase(dict(bound=True,creature=False,bikeType=typ,boundVehicleType=linked_type),'bike-runtime-signed-word-global')
for operand,system,callback in itertools.product([None,'','self','other','empty','missing'],[False,True],[False,True]):
 init(c=dict(callback=callback));bound=n.call(0x4431d0,[SYS if system else 0,token(operand)]);want={'self':actor(0),'other':actor(1)}.get(operand,0)if system and callback and operand is not None else 0;check('bike-original-initializer',bound,want);check('bike-original-initializer-callback-gates',len(calls),int(system and callback and operand is not None));initializers.append(dict(operand=operand,system=system,callback=callback,nativePointer=bound,callbackCalls=list(calls)))
# All40authored occurrences. AddToSet runs both first modes; Bike includes named
# failure fallback so missing names do not get incorrectly promoted to false.
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'))
for row in ledger['rows']:
 name=row['name']
 if name not in ['AddToSet','OnSpeederBike']:continue
 for use in row['uses']:
  if name=='AddToSet':
   for first in [False,True]:setcase(use['args'],dict(first=first),'shipped-AddToSet',use)
   shipped.append(dict(command=name,source=use['source'],line=use['line'],text=use['text']))
  else:
   q=re.findall(r'"([^"]*)"',use['text']);operand=q[0]if q else None;c=dict(contextByte=59 if use['line']%2 else 0,boundContextByte=59 if use['line']%2 else 0)
   init(c=c)
   if operand is not None:bindings[operand.lower()]=reference(1)
   bound=n.call(0x4431d0,[SYS,token(operand)]);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(0x443200,[SYS,PACK,CRE,0,bound]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',RESULT)[0];check('shipped-OnSpeederBike-body',got,bits(float(bool(use['line']%2))))
   m=re.search(r'(==|!=)\s*(\d+)(?:\s+(?:goto|and|or)\b|\s*$)',use['text'],re.I);assert m;op=m[1];rhs=float(m[2]);n.pack('<I',LIST,COND);n.pack('<f',COND+8,rhs);n.pack('<B',COND+12,0 if op=='=='else 5);n.pack('<I',COND+0x18,bound);n.pack('<I',COND+0x1c,DEF);n.pack('<II',DEF,0,0x443200);matched=n.call(0x52c880,[SYS,LIST,CRE,PACK],regs={UC_X86_REG_EAX:0})!=0;expected=(fl(got)==rhs)if op=='=='else(fl(got)!=rhs);check('shipped-OnSpeederBike-original-comparison',matched,expected);shipped.append(dict(command=name,source=use['source'],line=use['line'],text=use['text'],operand=operand,context=c,nativePointer=bound,nativeBits=got,callbackCalls=list(calls),comparison=dict(operator=op,thresholdBits=bits(rhs),matched=matched)))
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,z in [(0x4499b0,151),(0x4431d0,44),(0x443200,69),(0x4f298a,21),(0x5147c0,164),(0x6e6b90,173)]:
 code=n.read(a,z);assembly.append(dict(entry=hex(a),size=z,bytes=code.hex(),sha256=hashlib.sha256(code).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in md.disasm(code,a)]))
report=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,errors=errors[:20],savedSetCases=len(setcases),savedBikeCases=len(bikecases),savedInitializers=len(initializers),shippedOccurrences=len(shipped),shippedByName={name:sum(x['command']==name for x in shipped)for name in ['AddToSet','OnSpeederBike']},shippedActionCalls=sum('source'in x for x in setcases),shippedConditionComparisons=sum(x['command']=='OnSpeederBike'for x in shipped),method='Original AddToSet0x4499b0, packet resolver0x5147c0, scalar parsers and integer conversion0x6e6b90; original OnSpeederBike initializer0x4431d0/body0x443200/comparator0x52c880. Complete prepared self actor byte block write-confinement checked for each AddToSet case. Named character callback0x923904 alone adapted.',adapters=[dict(globalAddress='0x923904',fixtureAddress=hex(ADAPTER),scope='Synthetic callback maps ASCII names to references; original initializer extracts target first pointer. Names,world lifetime and alias policy remain external.')],limits=['Original functions execute in isolated x86 Unicorn; no game/world execution.','Native assertions include correlated return/state/write-confinement checks,not independent scenarios.','Finite float32 numeric values within int32 conversion range only; unchecked long integer/NaN/infinity conversion behavior outside source contract.','Named/numeric/script packet inputs and reference lifetimes are host-owned.','Alive-count backing synthetic selected indices1..16; actual table allocation and per-frame count population are not established.','OnSpeederBike fallback dereferences null creature when initialized target is absent; original faults saved and portable exception preserves the boundary.','Vehicle object creation,link updates,context assignment and type-global initialization are external.','Managed behavioral execution pending; no launch retry under known EPERM restriction.'])
(BASE/'reports/script-phase4-20261013-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/script-phase4-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,setCases=setcases,bikeCases=bikecases,initializers=initializers,shipped=shipped),separators=(',',':')),encoding='utf8');(BASE/'reports/script-phase4-20261013-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8');print(json.dumps(report));assert not errors
