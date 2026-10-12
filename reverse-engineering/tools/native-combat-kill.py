"""Kill SCP command: original x86 parsing/selection, recorded service boundaries."""
import importlib.util, itertools, json, random, struct, math, hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE
POOL=n.DATA;STRIDE=0x10d8;COUNT=8;SCRIPT=POOL+0x10000;WEAK=POOL+0x11000;ARGS=POOL+0x12000;TEXT=POOL+0x13000;CONTEXT=POOL+0x18000;DEF=POOL+0x18100;NAMES=POOL+0x18200;BIND=n.STOP+0x100
params=[5.9,-1.2,16.75,.25];names={'self':0,'other':1,'player':0,'player_2':1,'ai_dooku':2,'ai_vader':3,'ai_spy':4}
calls=[];vectors=[];failures=[];mismatches=[];counts={};active_case=None

def read_string(addr):return n.read(addr,512).split(b'\0')[0].decode('latin1')
def return_int(mu,value):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
def boundary(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address in [BIND,0x440120]:
  name=read_string(n.unpack('<I',sp+8)[0]);idx=names.get(name.lower(),-1);calls.append(['find'if address==BIND else'reference',name,idx]);return_int(mu,0 if idx<0 else WEAK+4*idx if address==BIND else POOL+STRIDE*idx)
 elif address==0x437770:
  args=list(n.unpack('<7I',sp+4));calls.append(['parts',(args[0]-POOL)//STRIDE,*args[1:]]);return_int(mu,0)
 else:
  args=list(n.unpack('<3I',sp+4));calls.append(['death',(args[0]-POOL)//STRIDE,*args[1:]]);return_int(mu,0)
for a in [BIND,0x440120,0x437770,0x4364e0]:n.mu.hook_add(UC_HOOK_CODE,boundary,begin=a,end=a)

def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def floatval(b):return struct.unpack('<f',struct.pack('<I',b))[0]
def actor(flags=0x1001,identity=0x400,death=0,timer=0,set_id=1,hit=0xfedcba98):return {'flags':flags,'identity':identity,'death':death,'timerBits':bits(timer),'set':set_id,'hit':hit}
def setup(case):
 n.write(POOL,bytes(0x19000));calls.clear()
 n.pack('<II',0x93d500,len(case['actors']),POOL);n.pack('<I',0x923904,BIND if case['resolver']else 0)
 n.pack('<I',SCRIPT+0xd0,WEAK+case['self']*4 if case['self']>=0 else 0);n.pack('<I',SCRIPT+0xe4,WEAK+case['opponent']*4 if case['opponent']>=0 else WEAK+COUNT*4 if case['opponent']==-2 else 0)
 for i,a in enumerate(case['actors']):
  obj=POOL+i*STRIDE;n.pack('<I',WEAK+i*4,obj);n.pack('<II',obj+0x1f8,a['identity'],a['flags']);n.pack('<B',obj+0x28b,a['death']);n.pack('<B',obj+0x378,a['set']);n.pack('<I',obj+0xeec,a['hit']);n.pack('<I',obj+0x1010,a['timerBits'])
 for i,t in enumerate(case['tokens']):n.write(TEXT+i*256,t.encode('latin1')+b'\0');n.pack('<I',ARGS+4*i,TEXT+i*256)
 n.pack('<I',CONTEXT+4,DEF);n.pack('<4f',CONTEXT+0x14,*params)
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.write(NAMES+i*32,name.encode()+b'\0');n.pack('<I',DEF+0x18+i*8,NAMES+i*32)
 return CONTEXT if case['parameters']else 0

def oracle(case):
 output={'result':1,'hits':[a['hit']for a in case['actors']],'calls':[]}
 if not case['first']:return output
 selected=case['self'];pool=False;exclude=-1;set_id=0;respawn=False;origin=False;check=False;debris=False;parts=False
 for raw in case['tokens']:
  token=raw.split('\0')[0];low=token.lower()
  if 'character'in low:
   name=token[low.index('character')+10:];selected=names.get(name.lower(),-1)if case['resolver']else-1
   if case['resolver']:output['calls'].append(['find',name,selected])
  elif 'opponent'in low:
   if case['opponent']!=-1:selected=max(-1,case['opponent'])
  elif low=='respawn':respawn=True
  elif low=='respawn_at_origin':respawn=True;origin=True
  elif 'all_ai_except'in low:
   name=token[low.index('all_ai_except')+14:];exclude=names.get(name.lower(),-1);pool=True;output['calls'].append(['reference',name,exclude])
  elif low=='all_ai':pool=True
  elif low=='check_if_dead':check=True
  elif low=='debris':debris=True
  elif low=='parts_on':parts=True
  elif 'set='in low:
   value=token[low.index('set=')+4:];vlow=value.lower()
   if case['parameters']and vlow in ['alpha','beta','gamma','delta']:number=params[['alpha','beta','gamma','delta'].index(vlow)]
   elif case['parameters']and'param'in vlow:number=params[0]
   else:
    try:number=float(value)
    except ValueError:number=0
   set_id=math.trunc(number);set_id=set_id if 0<=set_id<=16 else 0
 for i,a in enumerate(case['actors']):
  if pool or set_id:
   eligible=(a['flags']&0x1001)==0x1001 and ((bool(a['identity']&0x400)and i!=exclude)if pool else a['set']==set_id)
   if check:eligible=eligible and a['death']==0 and floatval(a['timerBits'])<=0
  else:eligible=i==selected and(not check or(a['death']==0 and floatval(a['timerBits'])<=0))
  if not eligible:continue
  output['hits'][i]=(a['hit']&0xffcfffff)|((int(origin)*2|int(respawn))<<20)
  if parts:output['calls'].append(['parts',i,0xffffffff,0xffffffff,1,0,0,0])
  output['calls'].append(['death',i,2 if debris else 4,0])
 return output

def run(group,case,source=None):
 global active_case
 active_case={'group':group,'input':case,'source':source};context=setup(case);before=[n.read(POOL+i*STRIDE,STRIDE)for i in range(len(case['actors']))]
 got={'result':n.call(0x445230,[0,context,SCRIPT,ARGS,len(case['tokens']),case['first']],count=1000000),'hits':[n.unpack('<I',POOL+i*STRIDE+0xeec)[0]for i in range(len(case['actors']))],'calls':calls.copy()}
 want=oracle(case);counts[group]=counts.get(group,0)+1
 unexpected=[]
 for i,old in enumerate(before):
  new=n.read(POOL+i*STRIDE,STRIDE);unexpected.extend([i,j,x,y]for j,(x,y)in enumerate(zip(old,new))if x!=y and not 0xeec<=j<0xef0)
 if got!=want or unexpected:
  if len(mismatches)<30:mismatches.append({'group':group,'input':case,'expected':want,'native':got,'unexpectedWrites':unexpected[:20]})
 vectors.append({'group':group,'input':case,'native':got,'source':source})

def fixture(tokens=(),first=1,self_id=0,opponent=1,resolver=True,parameters=True,actors=None):return {'tokens':list(tokens),'first':first,'self':self_id,'opponent':opponent,'resolver':resolver,'parameters':parameters,'actors':actors if actors is not None else[actor(set_id=i%5+1,hit=0xfedcba98+i)for i in range(COUNT)]}
try:
 forms=[[],['debris\0ignored'],['ignored\0character=other'],['character=other\0opponent'],['respawn'],['respawn_at_origin'],['respawn_at_origin','respawn'],['debris','parts_on'],['all_ai'],['all_ai_except=other','check_if_dead'],['character=missing'],['character=other','opponent'],['opponent','character=self'],['character=missing','opponent'],['prefixCHARACTER=other','PARTS_ON','DeBrIs'],['opponentsuffix'],['all_ai_except=missing'],['all_ai_except=other','all_ai'],['all_ai','set=2'],['all_ai_except=other','all_ai_except=self'],['set=1'],['set=2','set=0'],['set=-1'],['set=17'],['set=16.99'],['set=alpha'],['set=beta'],['set=gamma'],['set=param3'],['set=delta'],['xxSeT=2','check_if_dead'],['ignored'],['character=self','character=other']]
 for ts,first,self_id,opponent,resolver,parameters in itertools.product(forms,[0,1],[-1,0],[-2,-1,1],[False,True],[False,True]):run('token_order_and_adapters',fixture(ts,first,self_id,opponent,resolver,parameters))
 for mode,check,death,timer,flags,identity in itertools.product([[],['all_ai'],['set=1']],[False,True],[0,1,255],[-1.,0.,1.,float('nan')],[0,1,0x1000,0x1001],[0,0x400]):
  ts=mode+(['check_if_dead']if check else[])+['parts_on','debris','respawn_at_origin'];run('selection_boundaries',fixture(ts,actors=[actor(flags,identity,death,timer)]))
 rng=random.Random(0x445230)
 options=['character=other','character=self','character=missing','opponent','respawn','respawn_at_origin','all_ai_except=other','all_ai','check_if_dead','debris','parts_on','set=1','set=2','set=0','set=16','unknown']
 for iteration in range(4096):
  acts=[actor(flags=rng.getrandbits(32),identity=rng.getrandbits(32),death=rng.choice([0,0,1,2,255]),timer=rng.choice([-10.,-.001,0.,.001,10.]),set_id=rng.randrange(18),hit=rng.getrandbits(32))for i in range(COUNT)]
  run('random_complete_actor_images',fixture(rng.choices(options,k=rng.randrange(12)),rng.randrange(2),rng.choice([-1,0]),rng.choice([-1,1]),bool(rng.randrange(2)),bool(rng.randrange(2)),acts))
 catalog=json.loads((BASE/'reports/gameplay-catalog/scripts.json').read_text(encoding='utf-8-sig'));authored=[]
 for script in catalog['scripts']:
  for state in script['states']:
   for action in state.get('actions',[]):
    if action.get('key','').lower()!='kill':continue
    source={'source':script['source'],'state':state['name'],'line':action['line'],'text':action['text']};authored.append(dict(source,tokens=action['args']))
    for first,dead in itertools.product([0,1],[False,True]):
     acts=[actor(death=1 if dead and i%2 else 0,timer=1 if dead and i%3==0 else 0,set_id=i%5+1,hit=0xfedcba98+i)for i in range(COUNT)]
     run('authored_Kill_commands',fixture(action['args'],first,actors=acts),source)
except Exception as e:failures.append({'error':str(e),'case':active_case})
source=BASE/'decompiled/corpus-expanded/FUN_445230.c'
report={'binarySha256':n.sha256,'address':'0x445230','method':'Execute original Kill handler plus original case-insensitive string matching and numeric evaluator/float truncation in isolated x86. Record named lookup/reference lookup, parts activation and death-cleanup boundaries. Independently compare return, all actor hit flags, ordered callback arguments and every other byte in each actor image.','sourceEvidence':{'path':str(source.relative_to(BASE)).replace('\\','/'),'sha256':hashlib.sha256(source.read_bytes()).hexdigest()},'totals':{'cases':len(vectors),'mismatches':len(mismatches),'failures':len(failures),'authoredCommandUses':len(authored)if'authored'in globals()else 0},'groups':counts,'mismatchExamples':mismatches,'failures':failures,'limits':['Standalone command with valid script and allocated contiguous actor pool. Malformed tokens without required separators are outside bounds.','Name/reference lookup callbacks are explicit fixture adapters, not reconstructed world binding.','Parts and death cleanup are captured dispatches; no downstream death, FX, audio, stud or body-part behavior is asserted.','Numeric evaluator has original PC finite literal/parameter execution; portable command uses an explicit numeric service.','Instruction audit corrects misleading pseudocode: single and pool paths all reject unordered NaN spawn timers when check_if_dead is enabled.','Authored commands execute against documented synthetic world bindings, not their live levels.','Managed opponent and pool references assume stable canonical bindings during service callbacks; callback mutation of native weak slots or pool membership is outside the contract.']}
(BASE/'reports/native-combat-kill.json').write_text(json.dumps(report,indent=2)+'\n');(BASE/'reports/native-combat-kill-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'parameterValues':params,'vectors':vectors},separators=(',',':'))+'\n')
if'authored'in globals():(BASE/'reports/native-combat-kill-usage.json').write_text(json.dumps({'command':'Kill','address':'0x445230','count':len(authored),'uses':authored},indent=2)+'\n')
print(json.dumps(report['totals']));print(json.dumps(mismatches[:2]));print(json.dumps(failures))
raise SystemExit(1 if mismatches or failures else 0)
