"""Original ObjHitObj context and protection branches; original nested callees."""
import importlib.util,itertools,json
from pathlib import Path
spec=importlib.util.spec_from_file_location('fixture',Path(__file__).with_name('native-combat-fixture.py'));f=importlib.util.module_from_spec(spec);spec.loader.exec_module(f)
globals().update({k:v for k,v in vars(f).items()if not k.startswith('__')})
report['method']='Original0x438230 context/character/menu immunity, special-context damage suppression, and attacker-dependent protection. Original native callees; only inherited media boundary hooks.'
report['contracts']={};vectors=[]
def check(r,want,got,meta):
 vectors.append({'contract':next(k for k,v in report['contracts'].items()if v is r),'input':meta,'native':got});r['cases']+=1
 if want!=got:
  r['mismatches']+=1
  if len(r['examples'])<12:r['examples'].append({'input':meta,'expected':want,'actual':got})
def invoke(damage=1,flags=1,attacker=0):
 ret=n.call(0x438230,[attacker,OBJ,damage,flags,1,1],count=1000000)
 return [n.read(OBJ+0x107f,1)[0],n.unpack('<I',OBJ+0xeec)[0],ret]
try:
 table=n.unpack('<I',0x7fb0e4)[0];contextflags=[n.unpack('<I',table+i*16+12)[0]for i in range(100)]
 r=contract('all_context_character_immunity')
 for context,damage in itertools.product(range(100),[-1,0,1,3]):
  reset();n.pack('<B',OBJ+0x7b5,context);n.pack('<I',GAME+0x90,0x8000);check(r,[4,0,0],invoke(damage),{'context':context,'characterFlags':0x8000,'contextFlags':contextflags[context],'damage':damage})
 r=contract('original_registry_and_death_context_guards')
 for context,damage,flags in itertools.product(range(100),[-1,0,1,3],[1,0x201]):
  if context not in[95,96]and not contextflags[context]&4:continue
  reset();n.pack('<B',OBJ+0x7b5,context);check(r,[4,0,0],invoke(damage,flags),{'context':context,'contextFlags':contextflags[context],'damage':damage,'flags':flags})
 r=contract('jump_lunge_slam_instant_kill_override')
 for context,action,damage,flags in itertools.product([0,13,14],[3,4],[-1,0,1,3],[1,0x201]):
  reset();n.pack('<B',OBJ+0x7b5,context);n.pack('<B',OBJ+0x7b8,action);allowed=damage==-1 and flags&0x200;check(r,[4,1,2]if allowed else[4,0,0],invoke(damage,flags),{'context':context,'action':action,'damage':damage,'flags':flags})
 r=contract('stunned_attacker_and_substate_guards')
 for substate,attflags,damage in itertools.product([0,1],[None,0,1,128,129],[-1,1]):
  reset();n.pack('<B',OBJ+0x7b5,90);n.pack('<B',OBJ+0x7b3,substate)
  if attflags is not None:n.pack('<I',ATT+0x1fc,attflags)
  blocked=substate==0 or attflags is not None and not attflags&128;want=[4,0,0]if blocked else[4,1,2]if damage==-1 else[3,1,1]
  check(r,want,invoke(damage,1,0 if attflags is None else ATT),{'substate':substate,'attackerFlags':attflags,'damage':damage})
 r=contract('signal_techno_damage_suppression')
 for context,damage in itertools.product([76,81],[-1,0,1,3]):
  reset();n.pack('<B',OBJ+0x7b5,context);check(r,[4,0,1],invoke(damage),{'context':context,'damage':damage})
 r=contract('menu_player_immunity')
 for menu,player in itertools.product(range(-1,22),[False,True]):
  reset();n.pack('<h',0x921454,0);n.pack('<i',0x800aa8,menu);n.pack('<I',OBJ+0x1fc,0x1001|(128 if player else 0));blocked=player and menu in[8,12,13,14,15,16,17];check(r,[4,0,0]if blocked else[3,1,1],invoke(),{'menu':menu,'player':player})
 r=contract('post_hit_protection_depends_on_attacker_player_flag')
 for timer,attflags,damage in itertools.product([0,.1], [None,0,1,128,129],[-1,0,1,3]):
  reset();n.pack('<f',OBJ+0x1018,timer)
  if attflags is not None:n.pack('<I',ATT+0x1fc,attflags)
  blocked=damage!=-1 and timer>0 and(attflags is None or attflags&129!=129);attempt=1 if damage>0 or damage==-1 else 0;want=[4,attempt,0]if blocked else[4,1,2]if damage==-1 else[4-damage,attempt,1]
  check(r,want,invoke(damage,1,0 if attflags is None else ATT),{'timer':timer,'attackerFlags':attflags,'damage':damage})
except Exception as e:report['failures'].append({'error':str(e)})
report['totals']={'cases':sum(r['cases']for r in report['contracts'].values()),'mismatches':sum(r['mismatches']for r in report['contracts'].values()),'failures':len(report['failures'])}
report['limits']=['These are bounded guard paths, not a complete implementation of ObjHitObj.','Original registry is read unchanged; only explicit synthetic object/global state is supplied.','Hit/death uses original probe flag1; nonlethal hits still mutate state.','No scripts, model animations, level exceptions or live audio/rumble.']
(BASE/'reports/native-combat-guards.json').write_text(json.dumps(report,indent=2)+'\n');(BASE/'reports/native-combat-guards-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'vectors':vectors},separators=(',',':'))+'\n')
print(json.dumps(report['totals']));print(report['failures']);print({k:v['examples'][:3]for k,v in report['contracts'].items()if v['mismatches']})

raise SystemExit(1 if report['totals'].get('mismatches',0) or report['totals'].get('failures',0) else 0)
