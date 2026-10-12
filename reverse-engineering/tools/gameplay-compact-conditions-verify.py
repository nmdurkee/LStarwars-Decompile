"""Six original PC condition entrypoints plus their three initializers.
Named actor lookup in OffScreenTimer's initializer is the only callback adapter.
All condition bodies, scalar parsing and condition comparisons run original bytes.
"""
import importlib.util,json,struct,itertools,random,re,math
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;CREATURE=D+0x1000;PACKET=D+0x2000;REFERENCE=D+0x3000;OBJECT=D+0x4000;BOUND_OBJECT=D+0x6000;BOUND_REFERENCE=D+0x8000;TEXT=D+0x9000;RESULT=D+0xa000;LIST=D+0xb000;COND=D+0xb100;DEF=D+0xb200;ADAPTER=n.STOP+0x100
COUNTS=0x876847;report={'binarySha256':n.sha256,'checks':0,'mismatches':0,'groups':{},'errors':[]};vectors=[];bindings={};named_calls=[]
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def frombits(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def f32(v):return frombits(bits(v))
def parse_float(t):
 i=0;v=0.;d=1.
 if t.startswith('-'):d=-1.;i=1
 while i<len(t) and '0'<=t[i]<='9':v=f32(f32(v*10)+int(t[i]));i+=1
 if i<len(t) and t[i]=='.':
  i+=1
  while i<len(t) and '0'<=t[i]<='9':d=f32(d*10);v=f32(f32(v*10)+int(t[i]));i+=1
 return f32(v/d)
def parse_int(t):
 i=0;v=0;negative=t.startswith('-')
 if negative:i=1
 while i<len(t) and '0'<=t[i]<='9':v=(v*10+int(t[i]))&0xffffffff;i+=1
 if negative:v=(-v)&0xffffffff
 return v if v<0x80000000 else v-0x100000000
def set_selector(t):
 if t is None:return 0
 if t.lower()=='myset':return -1
 v=parse_int(t);return v if 1<=v<=16 else 0
def cstring(a):return n.read(a,256).split(b'\0')[0].decode('ascii')
def named(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);name=cstring(n.unpack('<I',sp+8)[0]);named_calls.append(name);result=bindings.get(name,0)
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,named,begin=ADAPTER,end=ADAPTER)
def check(group,got,want,meta=None):
 report['checks']+=1;g=report['groups'].setdefault(group,{'checks':0,'mismatches':0});g['checks']+=1
 if got!=want:
  report['mismatches']+=1;g['mismatches']+=1
  if len(report['errors'])<25:report['errors'].append(dict(group=group,got=got,want=want,input=meta))
def init(creature=True,opponent=False,distance=4.5,actor=True,actor_object=True,offscreen=6.25,bound_time=12.5,freeplay=1,set_id=7,seed=13):
 n.write(D,bytes(0xc000));n.pack('<I',CREATURE+0xe4,0xdeadbeef if opponent else 0);n.pack('<f',CREATURE+0xe8,distance);n.pack('<I',CREATURE+0xd0,REFERENCE if actor else 0);n.pack('<I',REFERENCE,OBJECT if actor_object else 0);n.pack('<I',BOUND_REFERENCE,BOUND_OBJECT);n.pack('<f',OBJECT+0xf10,offscreen);n.pack('<f',BOUND_OBJECT+0xf10,bound_time);n.pack('<i',0x93b2a4,freeplay);n.pack('<B',PACKET+0xb0,set_id)
 counts=bytes(((i*31+seed)&255) for i in range(256));n.write(COUNTS,counts);n.pack('<I',0x923904,0);bindings.clear();bindings.update({'named':BOUND_REFERENCE,'empty-object':REFERENCE});named_calls.clear()
 return dict(creature=creature,opponent=opponent,distanceBits=bits(distance),actor=actor,actorObject=actor_object,offscreenBits=bits(offscreen),boundTimeBits=bits(bound_time),freePlay=freeplay,setId=set_id,countSeed=seed)
def token(text):
 if text is None:return 0
 n.write(TEXT,text.encode()+b'\0');return TEXT
def floating(address,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(address,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',RESULT)[0]
ADDR={'GotOpponent':0x5151c0,'OpponentRange':0x515250,'OffScreenTimer':0x441800,'FreePlay':0x442a80,'NumInSetAlive':0x442000,'AlwaysTrue':0x5149f0}
def evaluate(name,state,initialized=0):return floating(ADDR[name],[SYS,PACKET,CREATURE if state['creature'] else 0,0,initialized&0xffffffff])
def remember(name,state,initialized,native_value,operand=None):vectors.append(dict(command=name,context=state,initialized=initialized,operand=operand,nativeBits=native_value))
values=[-200.,-0.,0.,frombits(1),.25,1.,7.5,1000.,frombits(0x7f7fffff)]
for creature,opponent,value in itertools.product([False,True],[False,True],values):
 state=init(creature=creature,opponent=opponent,distance=value)
 for name,want in [('GotOpponent',bits(float(creature and opponent))),('OpponentRange',bits(value) if creature and opponent else 0x7f7fffff)]:
  got=evaluate(name,state);check(name+'-reference-and-value',got,want,state);remember(name,state,0,got)

for creature,actor,obj,bound,value in itertools.product([False,True],[False,True],[False,True],[False,True],values):
 state=init(creature=creature,actor=actor,actor_object=obj,offscreen=value,bound_time=value*-.25 if abs(value)<1e30 else 31.5);pointer=BOUND_OBJECT if bound else 0
 got=evaluate('OffScreenTimer',state,pointer);want=state['boundTimeBits'] if bound else bits(value) if creature and actor and obj else 0
 check('OffScreenTimer-bound-or-self-chain',got,want,state);remember('OffScreenTimer',state,1 if bound else 0,got)

initializer_cases=[]
for callback,operand,target in itertools.product([False,True],[None,'','named','missing','empty-object'],[False,True]):
 state=init(actor_object=target);n.pack('<I',0x923904,ADAPTER if callback else 0)
 pointer=n.call(0x4417d0,[SYS,token(operand)]);want=BOUND_OBJECT if callback and operand=='named' else OBJECT if callback and operand=='empty-object' and target else 0
 check('OffScreenTimer-name-initializer',pointer,want,dict(callback=callback,operand=operand,actorObject=target));check('OffScreenTimer-callback-gate',len(named_calls),int(callback and operand is not None))
 got=evaluate('OffScreenTimer',state,pointer);expected=state['boundTimeBits'] if pointer==BOUND_OBJECT else state['offscreenBits'] if target else 0
 check('OffScreenTimer-name-failure-falls-back',got,expected)
 initializer_cases.append(dict(command='OffScreenTimer',operand=operand,callback=callback,actorObject=target,boundKind='named' if pointer==BOUND_OBJECT else 'self' if pointer==OBJECT else None,nativeBits=got))

rng=random.Random(0x442a80);free_values=[-2147483648,-16777217,-2,-1,0,1,2,16,16777215,16777216,16777217,2147483647]+[rng.randrange(-2147483648,2147483648) for _ in range(256)]
for value in free_values:
 state=init(freeplay=value);got=evaluate('FreePlay',state);check('FreePlay-signed-integer-conversion',got,bits(float(value)),value);remember('FreePlay',state,0,got)

operands=[None,'','myset','MYSET','MySet','mysetx',' myset','1.9','01','+1',' 1','0x1','1suffix','4294967297','4294967312','-4294967295','2147483648']+[str(i) for i in range(-20,101)]
for operand in operands:
 state=init();got=n.call(0x441f90,[SYS,token(operand)]);want=set_selector(operand)&0xffffffff;check('NumInSetAlive-selector-initializer',got,want,operand);initializer_cases.append(dict(command='NumInSetAlive',operand=operand,selector=got))
for selector,value in itertools.product(range(17),range(256)):
 state=init();n.pack('<B',COUNTS+selector,value);got=evaluate('NumInSetAlive',state,selector);check('NumInSetAlive-all-literal-indices-and-byte-values',got,bits(float(value)) if selector else 0,dict(selector=selector,value=value))
 vectors.append(dict(command='NumInSetAlive',context=state,initialized=selector,countOverride={'index':selector,'value':value},nativeBits=got))
for own_set in range(256):
 state=init(set_id=own_set);got=evaluate('NumInSetAlive',state,0xffffffff);want=bits(float((own_set*31+13)&255)) if own_set else 0;check('NumInSetAlive-myset-byte-domain',got,want,own_set);remember('NumInSetAlive',state,-1,got)

always_operands=[None,'','0','-0','1','1.75','-3.14','.25','TRUE','param3','+1',' 1','1e3','16777217','0.75___3.887']
for operand in always_operands:
 state=init();got=n.call(0x5149b0,[SYS,token(operand)]);want=bits(1.) if operand in (None,'') else bits(parse_float(operand));check('AlwaysTrue-initializer-EAX-bits',got,want,operand);value=evaluate('AlwaysTrue',state,got);check('AlwaysTrue-live-initialized-value',value,got,operand);remember('AlwaysTrue',state,got,value,operand);initializer_cases.append(dict(command='AlwaysTrue',operand=operand,initializedBits=got))
for value in values:
 state=init();got=evaluate('AlwaysTrue',state,bits(value));check('AlwaysTrue-arbitrary-finite-initialized-value',got,bits(value));remember('AlwaysTrue',state,bits(value),got)

# Source form coverage. Every occurrence invokes the original initializer/body.
# Literal comparisons additionally traverse original condition evaluator 0x52c880.
# Symbolic RHS and malformed control text are recorded rather than guessed.
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf-8'));shipped=[];comparison_omissions=[]
ops={'==':(0,lambda a,b:a==b),'<':(1,lambda a,b:a<b),'>':(2,lambda a,b:a>b),'<=':(3,lambda a,b:a<=b),'>=':(4,lambda a,b:a>=b),'!=':(5,lambda a,b:a!=b)}
for row in ledger['rows']:
 name=row['name']
 if name not in ADDR:continue
 for use in row['uses']:
  quoted=re.findall(r'"([^"]*)"',use['text']);operand=quoted[0] if quoted else None
  state=init(opponent=(use['line']%2)==0,distance=f32((use['line']%41)*.75),offscreen=f32((use['line']%17)*.5),freeplay=use['line']%2,set_id=7,seed=use['line']&255)
  initialized=n.call({'NumInSetAlive':0x441f90,'AlwaysTrue':0x5149b0,'OffScreenTimer':0x4417d0}[name],[SYS,token(operand)]) if name in ['NumInSetAlive','AlwaysTrue','OffScreenTimer'] else 0
  got=evaluate(name,state,initialized)
  if name=='GotOpponent':want=bits(float(state['opponent']))
  elif name=='OpponentRange':want=state['distanceBits'] if state['opponent'] else 0x7f7fffff
  elif name=='OffScreenTimer':want=state['offscreenBits']
  elif name=='FreePlay':want=bits(float(state['freePlay']))
  elif name=='AlwaysTrue':want=bits(1.) if operand in (None,'') else bits(parse_float(operand))
  else:
   selector=set_selector(operand);index=7 if selector==-1 else selector;want=bits(float((index*31+state['countSeed'])&255)) if index else 0
  check('shipped-'+name+'-body',got,want,use)
  comparison=None;m=re.search(r'(==|!=|<=|>=|<|>)\s*(.*?)(?:\s+(?:goto|and|or)(?:\s|$)|$)',use['text'],re.I)
  if m and re.fullmatch(r'-?(?:\d+(?:\.\d*)?|\.\d+)',m[2]):
   op,threshold=m[1],parse_float(m[2]);n.pack('<I',LIST,COND);n.pack('<f',COND+8,threshold);n.pack('<B',COND+12,ops[op][0]);n.pack('<I',COND+0x18,initialized);n.pack('<I',COND+0x1c,DEF);n.pack('<II',DEF,0,ADDR[name])
   matched=n.call(0x52c880,[SYS,LIST,CREATURE,PACKET],regs={UC_X86_REG_EAX:0})!=0;expected=ops[op][1](frombits(got),threshold);check('shipped-'+name+'-original-comparison',matched,expected,use);comparison=dict(operator=op,thresholdBits=bits(threshold),matched=matched)
  else:comparison_omissions.append(dict(source=use['source'],line=use['line'],text=use['text'],reason='Symbolic or malformed RHS/control text; body/initializer tested, source expression/loader binding not guessed.'))
  shipped.append(dict(command=name,source=use['source'],line=use['line'],text=use['text'],operand=operand,context=state,initialized=initialized,nativeBits=got,comparison=comparison))

report.update(method='Original six condition functions, three initializers, integer/float parsers and original condition evaluator. Synthetic object/packet fields and global values. OffScreenTimer named lookup alone is an explicit callback adapter; no condition body or comparator is replaced.',shippedOccurrences=len(shipped),originalShippedComparisons=sum(x['comparison'] is not None for x in shipped),comparisonOmissions=comparison_omissions,
 adapters=[{'global':'0x923904','scope':'Named-character callback in OffScreenTimer initializer maps fixture names to actor references; runtime alias resolution and reference lifetime remain external.'}],
 limits=['World global updates, reference lifetime, range computation, off-screen timer accumulation and alive-count population are external input contracts, not recovered by these readers.','Literal NumInSetAlive initializer admits 1..16 or myset; myset reads an unchecked byte index. Fixtures use a synthetic 256-byte backing region and do not assert the actual global count-table allocation size.','All scalar reader checks compare values at the float32 storage boundary used by the native SCP evaluator; signaling NaN payload behavior is excluded.','Eight symbolic comparison RHS occurrences and one malformed gotoUpdate occurrence retain separate source/loader gaps; their condition bodies were still exercised.','Compiled C# differential execution pending.'])
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
dis=Cs(CS_ARCH_X86,CS_MODE_32)
report['assemblyEvidence']=[{'entry':hex(a),'instructions':[{'address':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str}for i in dis.disasm(n.read(a,size),a)]}for a,size in [(0x5149b0,0x31),(0x442a80,7),(0x442000,0x2b)]]
(BASE/'reports/gameplay-compact-condition-tests.json').write_text(json.dumps(report,indent=2),encoding='utf-8');(BASE/'reports/gameplay-compact-condition-native-fixtures.json').write_text(json.dumps({'binarySha256':n.sha256,'cases':vectors,'initializers':initializer_cases,'shipped':shipped},separators=(',',':')),encoding='utf-8')
print(json.dumps({k:report[k]for k in ['checks','mismatches','groups','shippedOccurrences','originalShippedComparisons','comparisonOmissions','errors']}));assert not report['mismatches']
