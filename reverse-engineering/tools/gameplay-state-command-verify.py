"""Original PC SetScriptState: token scan, self/group selection and native binding.
Named-character resolution is an explicit callback adapter; all binding is original.
"""
import importlib.util, json, struct, itertools, math
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;CREATURE=D+0x1000;CALLER=D+0x2000;ACTORS=D+0x4000;PACKETS=D+0x15000;SCRIPTS=D+0x20000;STATES=D+0x22000;ARGS=D+0x30000;TEXT=D+0x31000;NAMES=D+0x36000;ADAPTER=n.STOP+0x100
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text());uses=next(r['uses'] for r in ledger['rows'] if r['name']=='SetScriptState')
names=['Base','Target','CurrentOnly']+sorted({t[6:] for u in uses for t in u['args'] if t.lower().startswith('state=')}-{'Base','Target','CurrentOnly'})
checks={};errors=[];vectors=[];named_calls=[];bindings={}
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def actor(i):return ACTORS+0x10d8*i
def packet(i):return PACKETS+0x200*i
def state(i,j):return STATES+0x1000*i+0x40*j
def string(p):return n.read(p,128).split(b'\0')[0].decode('ascii')
def named(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);name=string(n.unpack('<I',sp+8)[0]);named_calls.append(name);result=bindings.get(name.lower(),0)
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,named,begin=ADAPTER,end=ADAPTER)
def check(group,got,want,meta=None):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def init(ts,flags=None,groups=None,first=True,self_actor=True,named_adapter=False,missing_target=False):
 n.write(D,bytes(0x40000));named_calls.clear();bindings.clear();bindings.update({'self':actor(0),'other':actor(1)})
 n.pack('<I',0x923904,ADAPTER if named_adapter else 0);n.pack('<I',0x93d500,8);n.pack('<I',0x93d504,ACTORS);n.pack('<I',CREATURE+0xd0,actor(0) if self_actor else 0);n.pack('<I',CALLER+4,SCRIPTS)
 n.pack('<4f',CALLER+0x14,2.75,1.,3.,4.)
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.write(NAMES+0x800+32*i,name.encode()+b'\0');n.pack('<I',SCRIPTS+0x18+i*8,NAMES+0x800+32*i)
 for i,name in enumerate(names):n.write(NAMES+64*i,name.encode()+b'\0')
 for script in range(2):
  n.pack('<II',SCRIPTS+script*0x100+0x10,state(script,0),state(script,len(names)-1))
  for j in range(4):n.pack('<f',SCRIPTS+script*0x100+0x1c+8*j,10*script+j+.25)
  for j,name in enumerate(names):
   n.pack('<I',state(script,j),state(script,j+1) if j+1<len(names) else 0);n.pack('<I',state(script,j)+0x18,NAMES+j*64)
   # Leave CurrentOnly absent in the base script; states remain linked.
   if script==0 and (name=='CurrentOnly' or (missing_target and name=='Target')):n.pack('<I',state(script,j)+0x18,NAMES+64*names.index('Base'))
 for i in range(8):
  n.pack('<I',actor(i)+4,packet(i));n.pack('<I',actor(i)+0x1fc,(flags or [0x1001]*8)[i]);n.pack('<B',actor(i)+0x378,(groups or [0,1,2,3,16,2,1,255])[i])
  n.pack('<II',packet(i),SCRIPTS,SCRIPTS+0x100);n.pack('<I',packet(i)+8,state(1,2));n.pack('<I',packet(i)+0x10,state(1,1));n.pack('<4f',packet(i)+0x14,9.,8.,7.,6.);n.pack('<f',packet(i)+0x24,3.5);n.pack('<I',packet(i)+0x50,0x24);n.pack('<I',packet(i)+0x64,3);n.pack('<H',packet(i)+0xb2,0x7654);n.pack('<B',packet(i)+0xb4,7);n.pack('<f',packet(i)+0xb8,8.);n.pack('<I',packet(i)+0xbc,state(1,1))
 for i,t in enumerate(ts):n.write(TEXT+256*i,t.encode()+b'\0');n.pack('<I',ARGS+4*i,TEXT+256*i)
def snapshot(i):
 p=packet(i);script=n.unpack('<I',p+4)[0];st=n.unpack('<I',p+8)[0]
 pending=n.unpack('<I',p+16)[0];deadline=n.unpack('<I',p+0xbc)[0]
 return {'base':n.unpack('<I',p)[0]-SCRIPTS,'script':script-SCRIPTS,'state':(st-STATES)//0x40,'pending':(pending-STATES)//0x40 if pending else None,'localsBits':list(n.unpack('<4I',p+20)),'timerBits':n.unpack('<I',p+0x24)[0],'flags':n.unpack('<I',p+0x50)[0],'depth':n.unpack('<I',p+0x64)[0],'blocked':n.unpack('<H',p+0xb2)[0],'deadlineBits':n.unpack('<I',p+0xb8)[0],'deadlineState':(deadline-STATES)//0x40 if deadline else None,'marker':n.unpack('<B',p+0xb4)[0]}
def expected_selected(before,j):
 return dict(before,script=0,state=j,pending=None,localsBits=[bits(i+.25) for i in range(4)],flags=0x20,depth=0,blocked=0,deadlineBits=0,deadlineState=None,marker=0)
def run(ts,selected,target='Target',first=True,**kwargs):
 init(ts,first=first,**kwargs);before=[snapshot(i) for i in range(8)]
 ret=n.call(0x445740,[SYS,CALLER,CREATURE,ARGS,len(ts),int(first)])
 check('SetScriptState-completes',ret,1,ts)
 for i in range(8):check('SetScriptState-selection-and-bind',snapshot(i),expected_selected(before[i],names.index(target)) if first and i in selected else before[i],dict(tokens=ts,actor=i,**kwargs))
 vectors.append(dict(tokens=ts,first=first,selected=selected,target=target,options=kwargs,native=[snapshot(i) for i in range(8)],namedCalls=list(named_calls)))

# Self targeting, valid/missing states, exact first-call behavior and invalid group
# values falling back to the self/named path, rather than selecting an invalid set.
for first,t in itertools.product([False,True],['-1','0','0.9','17','999','+4','unknown']):run(['set='+t,'state=Target'],[0],first=first)
for first in [False,True]:
 run(['state=Target'],[0],first=first);run(['prefixSTATE=tArGeT'],[0],first=first)
run(['state=Target'],[],self_actor=False);run(['state=missing'],[]);run([],[]);run(['state=CurrentOnly'],[]);run(['state=Target'],[],missing_target=True)
for ts in [['character=other','state=Target'],['character=missing','state=Target']]:run(ts,[0]) # absent callback preserves default actor
for ts,select in [(['character=other','state=Target'],[1]),(['character=missing','state=Target'],[]),(['character=other','character=self','state=Target'],[0]),(['character=self','character=other','state=Target'],[1])]:run(ts,select,named_adapter=True)

default_groups=[0,1,2,3,16,2,1,255]
for group in range(1,17):run(['set='+str(group),'state=Target'],[i for i,g in enumerate(default_groups) if g==group])
for text,group in [('2.99',2),('param3',2),('alpha',2),('beta',1),('gamma',3),('delta',4)]:run(['set='+text,'state=Target'],[i for i,g in enumerate(default_groups) if g==group])
for flags in [[0,1,0x1000,0x1001,0xffffffff,0x1002,0x1003,0x2001]]:
 run(['set=2','state=Target'],[i for i,f in enumerate(flags) if f&0x1001==0x1001],flags=flags,groups=[2]*8)
for ts,select,target in [(['set=1','set=2','state=Target'],[2,5],'Target'),(['state=Base','state=Target','set=1'],[1,6],'Target'),(['state=Target','state=Base','set=1'],[1,6],'Base'),(['character=missing','set=2','state=Target'],[2,5],'Target')]:run(ts,select,target,named_adapter=True)

# Every authored occurrence. Named lookup itself is adapted to a single known
# actor; set selection, state lookup and binding are unmodified PC functions.
shipped=[]
for use in uses:
 ts=use['args'];init(ts,named_adapter=True);target=None;group=0
 for t in ts:
  tl=t.lower()
  if 'character=' in tl:bindings[t[tl.index('character=')+10:].lower()]=actor(1)
  elif 'set=' in tl:group=int(float(t[tl.index('set=')+4:]))
  elif 'state=' in tl:target=t[tl.index('state=')+6:]
 selected=[i for i,g in enumerate(default_groups) if g==group] if group else [1]
 before=[snapshot(i) for i in range(8)];n.call(0x445740,[SYS,CALLER,CREATURE,ARGS,len(ts),1])
 for i in range(8):check('shipped-SetScriptState',snapshot(i),expected_selected(before[i],names.index(target)) if i in selected else before[i],use)
 shipped.append(dict(**use,selected=selected,target=target,native=[snapshot(i) for i in range(8)],namedCalls=list(named_calls)))

chains=[]
for named_target in [False,True]:
 ts=(['character=other'] if named_target else [])+['state=Target'];init(ts,named_adapter=named_target)
 action0=D+0x39000;action1=D+0x39020;def0=D+0x39100;def1=D+0x39120
 n.pack('<I',state(1,2)+16,action0);n.pack('<4I',action0+8,ARGS,len(ts),def0,0);n.pack('<II',def0,0,0x445740)
 n.pack('<I',state(0,names.index('Target'))+16,action1);n.pack('<I',action1+16,def1);n.pack('<II',def1,0,0x515890)
 n.pack('<I',packet(0)+12,action0);n.pack('<I',packet(0)+16,0);n.pack('<I',packet(0)+0x50,1);n.pack('<I',packet(0)+0x64,0);n.pack('<I',0x9238ac,0)
 n.call(0x52cc90,[SYS,0,CREATURE,packet(0),bits(.125)])
 selected=1 if named_target else 0;got=snapshot(selected)
 check('scheduler-immediate-target-binding',got['state'],names.index('Target'))
 check('scheduler-target-action-timing',got['timerBits'],bits(3.5 if named_target else 0.))
 check('scheduler-target-action-first-call',n.unpack('<I',packet(selected)+0x50)[0]&1,1 if named_target else 0)
 if named_target:
  n.call(0x52cc90,[SYS,0,CREATURE,packet(1),bits(.125)]);check('scheduler-other-actor-later-update',snapshot(1)['timerBits'],0)
 chains.append(dict(tokens=ts,selected=selected,immediate=got,afterTargetUpdate=snapshot(selected)))

report={'binarySha256':n.sha256,'checks':sum(checks.values()),'mismatches':len(errors),'groups':checks,'examples':errors[:20],'shippedOccurrences':len(shipped),
 'method':'Unmodified 0x445740 plus original token matching, packet number resolver, float truncation, ordered state lookup, and 0x514640 binding. Synthetic actors/packets/source-state lists. Named-character resolution alone uses an explicit callback adapter; self and group cases require no replacement call.',
 'adapters':[{'global':'0x923904','scope':'Fixture callback maps supplied names to an existing actor pointer or null. Character/alias resolution policy is not recovered here.'}],
 'limits':['Synthetically resolved script/state lists, not runtime source attachment or whole-level reachability.','Selected group records are required to have a valid packet and base-script pointer; original group path lacks the self-path null checks.','Numeric group fixtures are finite values within int32 conversion range; NaN/infinity/overflow are excluded.','Compiled C# differential execution remains pending.']}
report['schedulerChains']=chains
(BASE/'reports/gameplay-state-command-tests.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
(BASE/'reports/gameplay-state-command-native-fixtures.json').write_text(json.dumps({'binarySha256':n.sha256,'states':names,'cases':vectors,'shipped':shipped},separators=(',',':')),encoding='utf-8')
print(json.dumps(report))
if errors:raise SystemExit(1)
