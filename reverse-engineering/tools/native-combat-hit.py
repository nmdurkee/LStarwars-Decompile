"""Original general hit routine with bounded world/objects and media-boundary hooks."""
import importlib.util,struct,json,itertools,random
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;OBJ=n.DATA;ATT=OBJ+0x2000;CHAR=OBJ+0x4000;GAME=OBJ+0x5000;CHEAT=OBJ+0x6000;PAD=OBJ+0x7000;PHYS=OBJ+0x7100;MODEL=OBJ+0x8000;ANIMS=OBJ+0x9000;WORLD=OBJ+0x10000;LEVEL=OBJ+0x15000
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
report={'binarySha256':n.sha256,'method':'Original ObjHitObj0x438230 with original health, protection, context cleanup, RNG, no-script lookup and hit-reaction callees. Synthetic bounded state. Only media/rumble/alert boundaries intercepted.','contracts':{},'failures':[]};events=[]
hooks={0x4399e0:'AlertSurroundingCreatures',0x547930:'GameAudio_PlaySfx',0x681e90:'PlayIndexedSfx',0x681f40:'PlayNamedSfx',0x54a8a0:'NewBuzz',0x54a850:'NewRumble',0x54aae0:'TakeHitRumble',0x54aa70:'AttackerHitRumble',0x54aa10:'KillRumble'}
def boundary(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];events.append(hex(address));mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for address in hooks:n.mu.hook_add(UC_HOOK_CODE,boundary,begin=address,end=address)
def reset():
 n.write(OBJ,bytes(0x16000));events.clear();n.pack('<I',0x8032c4,CHEAT);n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,LEVEL);n.pack('<I',WORLD+0x12c,LEVEL+0x100);n.pack('<I',0x800944,0);n.pack('<h',0x921454,-1);n.pack('<I',0x7f1138,0);n.pack('<I',0x855de0,0);n.pack('<I',0x80253c,0x1234);n.write(0x95556c,bytes(24));n.pack('<I',0x93d828,0);n.pack('<I',0x924de0,0);n.pack('<f',0x925018,1/60)
 for obj in [OBJ,ATT]:
  n.pack('<I',obj+0x54,CHAR);n.pack('<I',obj+0x50,MODEL);n.pack('<I',obj+0xca4,PAD);n.pack('<I',obj+0x1fc,0x1001);n.pack('<b',obj+0x280,-1);n.pack('<h',obj+0x1064,-99);n.pack('<B',obj+0x107e,4);n.pack('<B',obj+0x107f,4);n.pack('<B',obj+0xe39,4)
 n.pack('<I',CHAR+0x24,GAME);n.pack('<I',MODEL+0xc,ANIMS);n.pack('<I',PAD,PHYS)
def snapshot():return {'hp':n.read(OBJ+0x107f,1)[0],'timer':n.unpack('<f',OBJ+0x1018)[0],'flags':n.unpack('<I',OBJ+0xeec)[0],'lastAttacker':n.unpack('<I',OBJ+0x10a8)[0],'context':n.read(OBJ+0x7b5,1)[0],'rng':n.unpack('<I',0x80253c)[0]}
def check(r,want,got,meta):
 r['cases']+=1
 if want!=got:
  r['mismatches']+=1
  if len(r['examples'])<15:r['examples'].append({'input':meta,'expected':want,'actual':got})
def contract(name):
 r={'cases':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r
try:
 r=contract('ordinary_health_and_probe');r['fixture']='Null attacker; normal context/action; active collidable target; no armor, level exceptions or scripts; media hooks only. lethal paths use original probe argument1.'
 for hp,damage,player,invincible,probe in itertools.product([1,2,4,10,100],[-3,-2,-1,0,1,2,4,99],[0,1],[0,1],[0,1]):
  lethal=damage==-1 or hp-damage<=0
  if lethal and not probe:continue
  reset();n.pack('<B',OBJ+0x107f,hp);n.pack('<I',OBJ+0x1fc,0x1001|player*128);n.pack('<I',CHEAT+8,invincible*128);result=n.call(0x438230,[0,OBJ,damage,1,probe,1],count=500000);state=snapshot();wantHp=hp;wantTimer=0.0;wantReturn=0
  if damage==-1:wantReturn=2
  elif not(player and invincible):
   if lethal:wantReturn=2
   else:wantHp=(hp-damage)&255;wantTimer=f32(.4)if damage!=0 else 0.0;wantReturn=1
  wantFlags=1 if damage>0 or damage==-1 else 0
  check(r,[wantHp,wantTimer,wantFlags,wantReturn],[state['hp'],state['timer'],state['flags'],result],{'hp':hp,'damage':damage,'player':player,'invincible':invincible,'probe':probe})
 print('health',r['cases'],r['mismatches'],flush=True)
 r=contract('early_target_guards')
 for active,collidable,disabled,spawn in itertools.product([0,1],[0,1],[0,1],[-1,0,.001,1]):
  if active and collidable and not disabled and spawn<=0:continue
  reset();n.pack('<I',OBJ+0x1fc,active|collidable*4096);n.pack('<B',OBJ+0x28b,disabled);n.pack('<f',OBJ+0x1010,spawn);result=n.call(0x438230,[0,OBJ,1,1,0,1]);state=snapshot();check(r,[4,0.0,0,0x1234,0],[state['hp'],state['timer'],state['flags'],state['rng'],result],{'active':active,'collidable':collidable,'disabled':disabled,'spawn':spawn})
 reset();result=n.call(0x438230,[0,0,1,1,0,1]);check(r,0,result,{'target':None})
 r=contract('post_hit_protection_and_instant_kill')
 for timer,damage,probe in itertools.product([-1,0,.001,.4],[-1,0,1,3],[0,1]):
  if damage==-1 and not probe:continue
  reset();n.pack('<f',OBJ+0x1018,timer);result=n.call(0x438230,[0,OBJ,damage,1,probe,1]);state=snapshot();wantHp=4;wantTimer=f32(timer);wantReturn=0
  if damage==-1:wantReturn=2
  elif timer<=0:wantHp=4-damage;wantReturn=1;wantTimer=f32(.4)if damage else f32(timer)
  check(r,[wantHp,wantTimer,wantReturn,1 if damage>0 or damage==-1 else 0],[state['hp'],state['timer'],result,state['flags']],{'timer':timer,'damage':damage,'probe':probe})
 r=contract('damage_type_restrictions')
 for flags,player,identity,cut,cap,armor in itertools.product([0,1,2,4,8,0xc,0x80,0x81,0x804],[0,1],[0,0x400,0x401],[0,1],[0,1],[0,1]):
  reset();n.pack('<I',OBJ+0x1fc,0x1001|player*128);n.pack('<I',OBJ+0x1f8,identity);n.pack('<I',0x855de0,cut);n.pack('<I',OBJ+0xeec,(0x8000000 if cap else 0)|(0x80000 if armor else 0));damage=3
  effective=1 if cap else damage
  if armor and flags&128:effective=0
  elif not flags&1:
   if flags&2 and not player:effective=0
   elif flags&4 and identity&0x400 and not identity&0x10005:effective=0
   elif flags&8 and not flags&4 and player:effective=0
   elif cut and player:effective=0
  result=n.call(0x438230,[0,OBJ,damage,flags,0,1]);state=snapshot();check(r,[4-effective,f32(.4)if effective else 0.0,1],[state['hp'],state['timer'],result],{'flags':flags,'player':player,'identity':identity,'cut':cut,'cap':cap,'armor':armor})
 print('restrictions',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'error':str(e)})
report['boundaryHooks']=[{'address':hex(k),'role':v,'behavior':'record call and return0'}for k,v in hooks.items()];report['totals']={'cases':sum(r['cases']for r in report['contracts'].values()),'mismatches':sum(r['mismatches']for r in report['contracts'].values()),'failures':len(report['failures'])};report['limits']=['Lethal paths use the original probe flag; full death effects, dismemberment, rescue and respawn are not validated.','Probe mode is not pure: nonlethal damage and attempt flags can still mutate state.','No script definitions are attached; native script-name lookup takes its no-script branch.','Specific level, vehicle, special context and attacker interactions remain outside this fixture set.','Audio/rumble and neighborhood alerts are boundary hooks, not live playback.'];(BASE/'reports/native-combat-hit-verification.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report['totals']));print(report['failures']);print({k:v['examples'][:4]for k,v in report['contracts'].items()if v['mismatches']})

raise SystemExit(1 if report['totals'].get('mismatches',0) or report['totals'].get('failures',0) else 0)
