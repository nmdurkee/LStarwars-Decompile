"""Original PC health command handlers and signed HitPoints condition."""
import importlib.util,struct,json,itertools,math
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;OBJ=n.DATA;OTHER=OBJ+0x2000;CHAR=OBJ+0x4000;GAME=OBJ+0x5000;SCRIPT=OBJ+0x6000;WEAK=OBJ+0x7000;OTHERWEAK=OBJ+0x7010;ARGS=OBJ+0x8000;TEXT=OBJ+0x9000;SCALAR=OBJ+0xa000
report={'binarySha256':n.sha256,'method':'Original PC command/condition functions with original string matching, decimal conversion and float-to-integer truncation. Synthetic character/actor state; no OS calls. TakeDamage dispatch alone records its final hit-handler boundary separately.','contracts':{},'failures':[]};vectors=[]
def reset(tokens=(),actor=True):
 n.write(OBJ,bytes(0xb000));n.pack('<I',OBJ+0x54,CHAR);n.pack('<I',CHAR+0x24,GAME);n.pack('<I',SCRIPT+0xd0,WEAK if actor else 0);n.pack('<I',WEAK,OBJ);n.pack('<I',OTHERWEAK,OTHER);n.pack('<B',GAME+0xf4,4);n.pack('<B',GAME+0xf5,6);n.pack('<BB',OBJ+0x107e,17,19);n.pack('<B',OBJ+0xe38,23);n.pack('<I',0x923904,0)
 for i,t in enumerate(tokens):n.write(TEXT+i*128,t.encode()+b'\0');n.pack('<I',ARGS+i*4,TEXT+i*128)
def contract(name):
 r={'cases':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r
def check(r,want,got,meta):
 vectors.append({'contract':next(k for k,v in report['contracts'].items() if v is r),'input':meta,'native':got})
 r['cases']+=1
 if want!=got:
  r['mismatches']+=1
  if len(r['examples'])<12:r['examples'].append({'input':meta,'expected':want,'actual':got})
def gethp(direct=0,actor=SCRIPT):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',SCALAR));n.call(0x441e20,[0,0,actor,0,direct]);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<f',SCALAR)[0]
try:
 r=contract('HitPoints_signed_byte_and_actor_resolution')
 for v,direct in itertools.product(range(256),[False,True]):
  reset();n.pack('<B',OBJ+0x107f,v);check(r,float(v if v<128 else v-256),gethp(OBJ if direct else 0),{'storedByte':v,'direct':direct})
 reset(actor=False);check(r,0.0,gethp(),{'missingWeakRef':True});check(r,0.0,gethp(actor=0),{'nullActor':True});n.pack('<I',SCRIPT+0xd0,WEAK);n.pack('<I',WEAK,0);check(r,0.0,gethp(),{'nullWeakValue':True})
 r=contract('SetHitPoints_defaults_truncation_and_maximum')
 tokens=[[],['default'],['dont_set_max'],['default','dont_set_max']]+[[x]for x in ['-257','-2','-1','-1.9','0','0.9','1.9','4','127','128','255','256','257','1000','+2','1e3','0.75___3.887']]
 for ts,first,actor in itertools.product(tokens,[0,1],[False,True]):
  reset(ts,actor);result=n.call(0x44b150,[0,0,SCRIPT,ARGS,len(ts),first]);want=[17,19,1]
  if first and actor:
   value=-1
   for token in ts:
    if token in ['default','dont_set_max']:continue
    import re
    match=re.match(r'-?[0-9]*(?:\.[0-9]*)?',token);prefix=match.group(0);value=math.trunc(float(prefix))if prefix not in['','-','.','-.']else 0
   if value==-1:value=4
   v=value&255;want=[17 if 'dont_set_max'in ts else v,v,1]
  check(r,want,[*n.unpack('<BB',OBJ+0x107e),result],{'tokens':ts,'firstCall':first,'actor':actor})
 r=contract('SetShieldHitPoints_defaults_and_truncation')
 for token,first,actor in itertools.product([None,'-257','-2','-1','-1.9','0','1.9','6','127','128','255','256','257'],[0,1],[False,True]):
  ts=[]if token is None else[token];reset(ts,actor);result=n.call(0x44b290,[0,0,SCRIPT,ARGS,len(ts),first]);v=23
  if first and actor:
   parsed=-1 if token is None else math.trunc(float(token));v=(6 if parsed==-1 else parsed)&255
  check(r,[v,1],[n.read(OBJ+0xe38,1)[0],result],{'token':token,'firstCall':first,'actor':actor})
except Exception as e:report['failures'].append({'contract':'health_commands','error':str(e)})
calls=[]
def hit(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);calls.append(list(n.unpack('<IIIIII',sp+4)));ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,1);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hit,begin=0x438230,end=0x438230)
try:
 r=contract('TakeDamage_command_hit_dispatch');r['hook']='Original final0x438230 boundary records all six arguments and returns1; actual damage separately verified by native-combat-hit.py.'
 for ts,first,actor,opponent in itertools.product([[],['damage=2'],['damage=-1'],['damage=1.9'],['damage=+3'],['character=missing'],['hitter=missing'],['opponent'],['opponent','damage=3']],[0,1],[False,True],[False,True]):
  reset(ts,actor);calls.clear();n.pack('<I',SCRIPT+0xe4,OTHERWEAK if opponent else 0);result=n.call(0x44fd10,[0,0,SCRIPT,ARGS,len(ts),first]);target=OBJ if actor else 0;attacker=0;damage=1
  for token in ts:
   if token=='opponent' and opponent:target=OTHER;attacker=OBJ if actor else 0
   elif token=='character=missing':target=0
   elif token.startswith('damage='):damage=0 if token[7:].startswith('+')else math.trunc(float(token[7:]))
  want=[[attacker,target,damage&0xffffffff,0,0,1]]if first and target else[];check(r,[want,1],[calls.copy(),result],{'tokens':ts,'firstCall':first,'actor':actor,'opponent':opponent})
except Exception as e:report['failures'].append({'contract':'TakeDamage','error':str(e)})

POOL=OBJ+0xc000
pool_ids=[1,2,16,1,2,16]
pool_flags=[1,1,1,0,128,129]
def setup_pool(count=6):
 n.write(POOL,bytes(0x7000));n.pack('<I',0x93d500,count);n.pack('<I',0x93d504,POOL)
 for i,(group,flags) in enumerate(zip(pool_ids,pool_flags)):
  n.pack('<I',POOL+i*0x10d8+0x1fc,flags);n.pack('<B',POOL+i*0x10d8+0x378,group)
def wanted_calls(ts,first,actor,opponent,count):
 target=OBJ if actor else 0;attacker=0;damage=1;selector=0
 for token in ts:
  if token=='opponent' and opponent:target=OTHER;attacker=OBJ if actor else 0
  elif token=='character=missing':target=0
  elif token=='hitter=missing':attacker=0
  elif token.startswith('damage='):damage=0 if token[7:].startswith('+')else math.trunc(float(token[7:]))
  elif token.startswith('set='):
   selector=math.trunc(float(token[4:]));selector=selector if 0<=selector<=16 else 0
 if not first:return []
 if selector:return [[attacker,POOL+i*0x10d8,damage&0xffffffff,0,0,1]for i in range(count)if pool_flags[i]&1 and pool_ids[i]==selector]
 return [[attacker,target,damage&0xffffffff,0,0,1]]if target else[]
try:
 r=contract('TakeDamage_set_selection_and_order');r['hook']='Only downstream hit handler0x438230 is intercepted to record dispatch; original set scan executes unchanged.'
 for ts,first,actor,opponent,count in itertools.product([[x]for x in ['set=-1','set=0','set=1','set=2','set=3','set=16','set=17','set=1.9']]+[['opponent','set=1'],['character=missing','set=2','damage=-1'],['set=1','set=2'],['set=2','set=0']],[0,1],[False,True],[False,True],[0,1,6]):
  reset(ts,actor);setup_pool(count);calls.clear();n.pack('<I',SCRIPT+0xe4,OTHERWEAK if opponent else 0);result=n.call(0x44fd10,[0,0,SCRIPT,ARGS,len(ts),first]);check(r,[wanted_calls(ts,first,actor,opponent,count),1],[calls.copy(),result],{'tokens':ts,'firstCall':first,'actor':actor,'opponent':opponent,'poolCount':count})
 r=contract('all_authored_combat_command_forms');uses=json.loads((BASE/'reports/native-combat-script-usage.json').read_text())['uses']
 for use in uses:
  ts=use['args'];reset(ts);setup_pool();calls.clear();n.pack('<I',SCRIPT+0xe4,OTHERWEAK)
  if use['key']=='TakeDamage':
   result=n.call(0x44fd10,[0,0,SCRIPT,ARGS,len(ts),1]);want=[wanted_calls(ts,1,True,True,6),1];got=[calls.copy(),result]
  elif use['key']=='SetHitPoints':
   result=n.call(0x44b150,[0,0,SCRIPT,ARGS,len(ts),1]);value=-1
   for token in ts:
    if token not in ['default','dont_set_max']:value=math.trunc(float(token))
   if value==-1:value=4
   value &=255;want=[17 if 'dont_set_max' in ts else value,value,1];got=[*n.unpack('<BB',OBJ+0x107e),result]
  else:raise RuntimeError('Uncovered authored command '+use['key'])
  check(r,want,got,{'source':use['source'],'line':use['line'],'key':use['key'],'tokens':ts})
except Exception as e:report['failures'].append({'contract':'TakeDamage_set_or_authored','error':str(e)})

report['totals']={'cases':sum(r['cases']for r in report['contracts'].values()),'mismatches':sum(r['mismatches']for r in report['contracts'].values()),'failures':len(report['failures'])};report['limits']=['Numeric literal and default paths are covered; messageval lookup, dynamic variables and live named-character resolution remain outside these fixtures.','Signed health bytes above127 are deliberately tested as representation boundaries, not asserted normal gameplay values.','The separate TakeDamage dispatch suite hooks only its downstream hit call; no claim of end-to-end gameplay execution.','TakeDamage set= selection is verified with bounded pools, active/inactive entries, selectors0..16, invalid selectors, token order and all69 authored combat command instances.'];(BASE/'reports/native-combat-health-commands.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report['totals']));print(report['failures']);print({k:{'cases':v['cases'],'mismatches':v['mismatches'],'examples':v['examples'][:3]}for k,v in report['contracts'].items()})

(BASE/'reports/native-combat-health-command-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'vectors':vectors},separators=(',',':'))+'\n')

raise SystemExit(1 if report['totals'].get('mismatches',0) or report['totals'].get('failures',0) else 0)
