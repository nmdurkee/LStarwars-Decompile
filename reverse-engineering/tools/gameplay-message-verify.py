"""Original-PC named-message fixtures. Only bounded CRT string formatting is adapted.

No game process, allocation, OS imports, user save files, or replacement gameplay code.
"""
import importlib.util, itertools, json, struct, random
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'))
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;D=n.DATA
REG=D;RECORDS=D+0x100;PACK=D+0x2000;SCRIPT=D+0x3000;NAMES=D+0x4000;ARGS=D+0x5000;TEXT=D+0x6000;RESULT=D+0xa000
report={'binarySha256':n.sha256,'checks':0,'mismatches':0,'groups':{},'examples':[],
 'method':'Original PC message registry, condition initializer/reader, SCP SetMessage/CopyMessage, GIT SetAIMessage, numeric resolver and string/list helpers. Synthetic preallocated linked records and script packet; only CRT sprintf %s/%s%s is adapted. Original binary bytes are unchanged.',
 'adapters':[{'address':'0x6e69ef','kind':'CRT string-format adapter','scope':'Only %s or %s%s, ASCII fixtures and bounded output <32 bytes. Does not model CRT locale, allocator or OS imports.'}],
 'limits':['ASCII names only; embedded NUL and overlong names already containing msg_ are excluded because original sprintf lacks a bound on that branch.',
 'GIT SetAIMessage requires a valid registry, name and available record. Original handler dereferences a failed lookup; portable source will explicitly reject that invalid input.',
 'Registry lifecycle/allocation/reset and inter-level message persistence are not established by these isolated fixtures.',
 'Native reference fixtures are not a compiled C# differential pass.']}
vectors=[];formatter_calls=0
def string(a):return n.read(a,1024).split(b'\0')[0].decode('ascii') if a else None
def sprintf(mu,address,size,user):
 global formatter_calls
 sp=mu.reg_read(UC_X86_REG_ESP);dst,fmt=n.unpack('<II',sp+4);template=string(fmt)
 assert template in ('%s','%s%s'),template
 out=''.join(string(n.unpack('<I',sp+12+4*i)[0]) for i in range(template.count('%s')))
 assert len(out)<32,(template,out)
 n.write(dst,out.encode()+b'\0');formatter_calls+=1
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,len(out));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,sprintf,begin=0x6e69ef,end=0x6e69ef)
def f32(x):return struct.unpack('<f',struct.pack('<f',x))[0]
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def parse_float(t):
 i=0;v=0.;d=1.
 if t.startswith('-'):d=-1.;i=1
 while i<len(t) and '0'<=t[i]<='9':v=f32(f32(v*10)+int(t[i]));i+=1
 if i<len(t) and t[i]=='.':
  i+=1
  while i<len(t) and '0'<=t[i]<='9':d=f32(d*10);v=f32(f32(v*10)+int(t[i]));i+=1
 return f32(v/d)
PARAMS=[2.25,-3.5,7.125,16.75];PARAM_NAMES=['alpha','beta','gamma','delta']
def number(t,packet=True):
 if packet:
  if 'param' in t.lower():return PARAMS[0] # original passes match start, not suffix, to atoi
  for i,name in enumerate(PARAM_NAMES):
   if t.lower()==name:return PARAMS[i]
 return parse_float(t)
def init(count=8,values=None,registry=True):
 n.write(D,bytes(0xb000));n.pack('<I',0x95df4c,REG if registry else 0)
 if count:
  n.pack('<II',REG+8,RECORDS,RECORDS+44*(count-1))
  for i in range(count):n.pack('<II',RECORDS+44*i,RECORDS+44*(i+1) if i+1<count else 0,RECORDS+44*(i-1) if i else 0);n.pack('<f',RECORDS+44*i+40,(values or [0.]*count)[i])
 n.pack('<I',PACK+4,SCRIPT);n.pack('<4f',PACK+0x14,*PARAMS)
 for i,t in enumerate(PARAM_NAMES):n.write(NAMES+32*i,t.encode()+b'\0');n.pack('<I',SCRIPT+0x18+8*i,NAMES+32*i)
def tokens(ts):
 n.write(ARGS,bytes(0x4000))
 for i,t in enumerate(ts):n.write(TEXT+256*i,t.encode()+b'\0');n.pack('<I',ARGS+4*i,TEXT+256*i)
 return ARGS
def lookup(name,cache=0,reg=REG):
 n.write(TEXT,name.encode()+b'\0')
 return n.call(0x5aac00,[reg,TEXT,cache])
def float_call(address,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(address,args);n.mu.emu_start(n.STOP,n.STOP+6)
 return n.unpack('<I',RESULT)[0]
def active():
 out=[];p=n.unpack('<I',REG+16)[0]
 while p:out.append({'name':string(p+8),'bits':n.unpack('<I',p+40)[0]});p=n.unpack('<I',p)[0]
 return out
def check(group,got,want,meta=None):
 report['checks']+=1;g=report['groups'].setdefault(group,{'checks':0,'mismatches':0});g['checks']+=1
 if got!=want:
  report['mismatches']+=1;g['mismatches']+=1
  if len(report['examples'])<25:report['examples'].append(dict(group=group,got=got,want=want,input=meta))
def canonical(name):
 if 'msg_' in name.lower():return name
 return 'msg_'+name if len(name)<=26 else None
def operation(ts,git=False):
 name=None;value=0.;mode=0
 for t in ts:
  tl=t.lower();keys=['name','val','increment=','decrement='] if git else ['name=','value=','increment=','decrement=']
  for j,key in enumerate(keys):
   at=tl.find(key)
   if at<0:continue
   v=t[at+len(key)+(1 if git and j<2 else 0):]
   if j==0:name=v
   else:
    value=number(v,not git)
    if j>=2:mode=1 if j==2 else -1
   break
 return name,value,mode
def expected_operation(ts,git=False,initial=1.25,first=True,registry=True):
 name,value,mode=operation(ts,git)
 if not registry or not first or name is None:return []
 cname=canonical(name)
 if cname is None:return []
 out=f32(initial-value) if mode==-1 else f32(initial+value) if mode==1 else value
 return [{'name':cname,'bits':bits(out)}]

# Registry canonicalization, case-insensitive first match, cached-pointer path,
# free/active list transfer, strict unprefixed length boundary and retained values.
for name in ['', 'Spinner','MSG_Spinner','prefixmsg_Spinner','msg_','a'*26,'a'*27,'a'*31]:
 init(values=[9.5]*8);p=lookup(name);c=canonical(name)
 check('registry-creation',p,RECORDS if c is not None else 0,name)
 check('registry-name-and-preserved-value',active(),[{'name':c,'bits':bits(9.5)}] if c is not None else [],name)
 if p:check('registry-case-fold',lookup(name.swapcase()),p,name)
init(2,values=[3.25,-8.5]);a=lookup('one');b=lookup('two');c=lookup('three')
check('registry-exhaustion',[a,b,c],[RECORDS,RECORDS+44,0]);check('registry-list-head-tail',list(n.unpack('<4I',REG+8)),[0,0,RECORDS,RECORDS+44])
for reg,cache in itertools.product([0,REG],[0,0x12345678]):
 init();check('registry-cached-pointer',lookup('x',cache,reg),cache if reg and cache else RECORDS if reg else 0)

# Initializer binds once to the persistent record, and reader reflects later changes.
for enabled,name in itertools.product([False,True],['flag','MSG_FLAG']):
 init();n.write(TEXT,name.encode()+b'\0');p=n.call(0x442480,[int(enabled),TEXT,0]);check('condition-initializer',p,RECORDS if enabled else 0)
 for value in [-20.,-0.,0.,.25,1.,123456.75]:
  if p:n.pack('<f',p+40,value)
  check('condition-live-read',float_call(0x4424b0,[0,0,0,0,p]),bits(value) if p else 0)
for reg,name,enabled in [(False,True,True),(True,False,True),(True,True,False)]:
 init(registry=reg);n.write(TEXT,b'flag\0');check('condition-initializer-null-guards',n.call(0x442480,[int(enabled),TEXT if name else 0,0]),0)

numeric=['0','-0','1.25','.75___3.887','2.85___3.887','16777217','123456.789','1e3','+5',' 7','param0','param1','PARAM2','param999','prefixPaRaM99','alpha','BETA','gamma','delta','unknown']
for packet,t in itertools.product([False,True],numeric):
 init();n.write(TEXT,t.encode()+b'\0');check('numeric-operand-resolution',float_call(0x5147c0,[PACK if packet else 0,TEXT]),bits(number(t,packet)),dict(token=t,packet=packet))

# Token order matters: value= overwrites amount without resetting increment/decrement mode.
forms=[[],['name=flag'],['value=9'],['name=flag','value=2'],['name=flag','increment=2'],['name=flag','decrement=2'],['name=flag','increment=2','value=7'],['name=flag','decrement=2','value=7'],['name=flag','value=2','increment=7'],['name=first','name=second','value=-4.5'],['prefixNAME=flag','VALUE=.25'],['Name=flag','name=msg_flag','value=1']]
forms += [['name=flag',k+'='+v] for k,v in itertools.product(['value','increment','decrement'],numeric)]
forms += [['name=flag']+list(p) for p in itertools.permutations(['increment=2','value=3','decrement=4'])]
for first,registry,ts in itertools.product([False,True],[False,True],forms):
 init(values=[1.25]*8,registry=registry);tokens(ts);ret=n.call(0x44b360,[0,PACK,0,ARGS,len(ts),int(first)]);got=active();want=expected_operation(ts,first=first,registry=registry)
 check('SetMessage-result',ret,1);check('SetMessage-operation',got,want,dict(tokens=ts,first=first,registry=registry))
 vectors.append(dict(command='SetMessage',tokens=ts,first=first,registry=registry,initialBits=bits(1.25),native=got))

gitforms=[['Name=flag','Val=3'],['prefixNAME=flag','VAL=.5'],['Name=flag','increment=2','Val=9'],['Name=flag','decrement=3','Val=1'],['Name=flag','Val=param0'],['Name=flag'],['Name=first','Name=last','Val=-2']]
gitforms += [['Name=flag',k+'='+v] for k,v in itertools.product(['Val','increment','decrement'],numeric)]
for ts in gitforms:
 init(values=[1.25]*8);tokens(ts);n.call(0x464f40,[0,0,ARGS,len(ts)]);got=active();check('SetAIMessage-operation',got,expected_operation(ts,True),ts)
 vectors.append(dict(command='SetAIMessage',tokens=ts,initialBits=bits(1.25),native=got))

# Copy is bit preserving, including quiet NaN and negative zero, and source lookup
# may create a new zero/value-preserving record before destination allocation fails.
for raw,first,ts in itertools.product([0,0x80000000,0x7fc12345,0x3f800000,0xc0600000],[False,True],[['from=source','to=dest'],['prefixFROM=SOURCE','TO=Dest'],['from=source','to=source'],['from=source'],['to=dest']]):
 init();p=lookup('source');n.pack('<I',p+40,raw);tokens(ts);ret=n.call(0x44b680,[0,PACK,0,ARGS,len(ts),int(first)]);want=[{'name':'msg_source','bits':raw}]
 if first and len(ts)==2 and ts[0].lower().find('from=')>=0 and ts[1].lower().find('to=')>=0 and not ts[1].lower().endswith('source'):want.append({'name':'msg_'+ts[1][ts[1].lower().find('to=')+3:],'bits':raw})
 check('CopyMessage-result',ret,1);check('CopyMessage-raw-bits',active(),want,dict(raw=raw,first=first,tokens=ts))
 vectors.append(dict(command='CopyMessage',tokens=ts,first=first,sourceBits=raw,native=active()))
init(1,values=[8.5]);tokens(['from=missing','to=missing2']);n.call(0x44b680,[0,PACK,0,ARGS,2,1]);check('CopyMessage-exhaustion-side-effect',active(),[{'name':'msg_missing','bits':bits(8.5)}])

# Every shipped occurrence executes its original command with controlled initial
# state. Conditions exercise original binding/reader separately from comparisons.
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text())
shipped=[]
for row in ledger['rows']:
 if row['name'] not in ['Message','SetMessage','CopyMessage','SetAIMessage']:continue
 for use in row['uses']:
  ts=use['args'];init(values=[1.25]*8)
  if row['name']=='Message':
   name=ts[0];n.write(TEXT,name.encode()+b'\0');p=n.call(0x442480,[1,TEXT,0]);got=float_call(0x4424b0,[0,0,0,0,p]);check('shipped-Message-binding-reader',got,bits(1.25),use);native_result=active()
  elif row['name'] in ['SetMessage','SetAIMessage']:
   tokens(ts);git=row['name']=='SetAIMessage';n.call(0x464f40 if git else 0x44b360,[0,0,ARGS,len(ts)] if git else [0,PACK,0,ARGS,len(ts),1]);native_result=active();check('shipped-'+row['name'],native_result,expected_operation(ts,git),use)
  else:
   tokens(ts);n.call(0x44b680,[0,PACK,0,ARGS,len(ts),1]);native_result=active();check('shipped-CopyMessage',len(native_result),2,use);check('shipped-CopyMessage-values',[x['bits'] for x in native_result],[bits(1.25)]*2,use)
  shipped.append(dict(command=row['name'],source=use['source'],line=use['line'],tokens=ts,native=native_result))

# Original command -> shared record -> Message -> original condition evaluator ->
# original scheduler transition. The graph action call boundary is explicit; graph
# scheduling itself was verified in the independent GIT suite.
chain_traces=[]
SYS=D+0xb000;CREATURE=D+0xb100;STATES=D+0xb800;COND=D+0xba00;DEF=D+0xbb00
for case in [x for x in shipped if x['command']=='SetAIMessage']:
 init();n.write(SYS,bytes(0x1000));n.pack('<B',CREATURE+0x138,0xff);n.pack('<I',0x9238ac,0)
 name,value,mode=operation(case['tokens'],True);n.write(TEXT,name.encode()+b'\0');record=n.call(0x442480,[1,TEXT,0])
 expected=case['native'][0]['bits'];target=struct.unpack('<f',struct.pack('<I',expected))[0]
 # Use a different initial value, then apply the authored command. For additive
 # forms, compute the threshold from a controlled zero-valued record instead.
 n.pack('<f',record+40,-99. if mode==0 else 0.);target=value if mode in (0,1) else -value
 n.pack('<II',PACK,SCRIPT,SCRIPT);n.pack('<I',PACK+8,STATES);n.pack('<II',SCRIPT+0x10,STATES,STATES+0x80);n.pack('<I',SCRIPT+0x38,STATES)
 n.pack('<I',STATES,STATES+0x80);n.pack('<II',STATES+8,COND,COND);n.pack('<f',COND+8,target);n.pack('<B',COND+12,0);n.pack('<I',COND+0x18,record);n.pack('<I',COND+0x1c,DEF);n.pack('<I',COND+0x24,STATES+0x80);n.pack('<II',DEF,0,0x4424b0)
 n.call(0x52cc90,[SYS,0,CREATURE,PACK,bits(.016)]);before=n.unpack('<I',PACK+8)[0]
 # Additive zero operands have no distinguishable before/after value; still
 # exercise delivery and transition, but do not require a pre-write failed guard.
 check('GIT-message-SCP-before',before,STATES if mode==0 or target!=0 else STATES+0x80,case)
 n.pack('<I',PACK+8,STATES);tokens(case['tokens']);n.call(0x464f40,[0,0,ARGS,len(case['tokens'])]);n.call(0x52cc90,[SYS,0,CREATURE,PACK,bits(.016)])
 check('GIT-message-SCP-after',n.unpack('<I',PACK+8)[0],STATES+0x80,case)
 chain_traces.append(dict(source=case['source'],line=case['line'],tokens=case['tokens'],targetValue=target,beforeState=int(before==STATES+0x80),afterState=int(n.unpack('<I',PACK+8)[0]==STATES+0x80)))

report['formatterAdapterCalls']=formatter_calls;report['shippedOccurrences']=len(shipped)
report['originalSchedulerChains']=chain_traces
report['fixtures']='reverse-engineering/reports/gameplay-message-native-fixtures.json'
(BASE/'reports/gameplay-message-native-fixtures.json').write_text(json.dumps({'binarySha256':n.sha256,'parameters':PARAMS,'parameterNames':PARAM_NAMES,'cases':vectors,'shipped':shipped},separators=(',',':')),encoding='utf-8')
(BASE/'reports/gameplay-message-tests.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
print(json.dumps({'checks':report['checks'],'mismatches':report['mismatches'],'groups':report['groups'],'shippedOccurrences':len(shipped),'failures':report['examples']}))
if report['mismatches']:raise SystemExit(1)
