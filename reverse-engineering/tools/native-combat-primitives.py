"""Bounded combat contracts executed in original PC x86 code. No game or OS launch."""
import importlib.util,struct,json,random,math,itertools
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;OBJ=n.DATA;ATT=OBJ+0x2000;CHAR=OBJ+0x4000;GAME=OBJ+0x5000;CHEAT=OBJ+0x6000;PAD=OBJ+0x7000;PHYS=OBJ+0x7100
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
report={'binarySha256':n.sha256,'method':'Original PC functions in Unicorn with bounded synthetic object/character/cheat state. Shield-only audio/rumble/alert callees intercepted; protection and damage arithmetic execute unchanged.','contracts':{},'failures':[]};vectors=[]
def contract(name,addresses):
 r={'functions':addresses,'cases':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r
def check(r,want,got,meta):
 vectors.append({'contract':next(k for k,v in report['contracts'].items() if v is r),'input':meta,'native':got})
 r['cases']+=1
 if want!=got:
  r['mismatches']+=1
  if len(r['examples'])<12:r['examples'].append({'input':meta,'expected':want,'actual':got})
def reset():
 n.write(OBJ,bytes(0x8000));n.pack('<I',OBJ+0x54,CHAR);n.pack('<I',CHAR+0x24,GAME);n.pack('<I',0x8032c4,CHEAT);n.pack('<I',ATT+0xca4,PAD);n.pack('<I',OBJ+0xca4,PAD);n.pack('<I',PAD,PHYS);n.pack('<I',0x855de0,0)
try:
 reset();r=contract('attacker_hit_flags',['0x58b720']);check(r,0,n.call(0x58b720,[0]),{'null':True});rng=random.Random(0x58b720)
 for i in range(4096):
  flags=rng.getrandbits(32);identity=rng.getrandbits(32);n.pack('<I',OBJ+0x1fc,flags);n.pack('<I',OBJ+0x1f8,identity);base=0x804 if flags&128 else 2;want=base|(0x10 if identity&0x10001 else 0x20 if identity&4 else 8);check(r,want,n.call(0x58b720,[OBJ]),{'objectFlags':flags,'identity':identity})
 r=contract('cannot_kill_context_and_character',['0x58b7f0']);table=n.unpack('<I',0x7fb0e4)[0];r['originalRegistry']=hex(table);r['contextsProtected']=[]
 for context in range(-1,100):
  flags=n.unpack('<I',table+context*16+8)[0]
  if flags&0x2000000:r['contextsProtected'].append(context)
  for charflags,slot in itertools.product([0,0x800,0xffffffff,0xfffff7ff],[-1,0,1,7]):
   n.pack('<b',OBJ+0x7b5,context);n.pack('<I',GAME+0x94,charflags);n.pack('<b',OBJ+0x280,slot);want=int(bool(flags&0x2000000 or charflags&0x800 and slot==-1));check(r,want,n.call(0x58b7f0,[OBJ]),{'context':context,'contextFlags':flags,'characterFlags':charflags,'slot':slot})
 r=contract('player_invincibility',['0x55f1d0','0x56e0f0'])
 for null,flags,timer in itertools.product([False,True],[0,1,0x80,0xffffffff],[f32(-100),f32(-.001),0.0,f32(.001),f32(20)]):
  n.pack('<I',CHEAT+8,flags);n.pack('<f',OBJ+0xdec,timer);check(r,int(bool(flags&128 or not null and timer>0)),n.call(0x55f1d0,[0 if null else OBJ]),{'null':null,'cheatFlags':flags,'timer':timer})
 r=contract('post_hit_protection_timer',['0x414ab0']);rng=random.Random(0x414ab0)
 for i in range(1000):
  flags=rng.getrandbits(32);timer=f32(rng.uniform(0,10));n.pack('<I',OBJ+0xe24,flags);n.call(0x414ab0,[OBJ,struct.unpack('<I',struct.pack('<f',timer))[0]]);check(r,[flags&0xfff8ffff,timer],[n.unpack('<I',OBJ+0xe24)[0],n.unpack('<f',OBJ+0x1018)[0]],{'flags':flags,'timer':timer})
except Exception as e:report['failures'].append({'contract':'primitives','error':str(e)})
hook_info={0x4399e0:'AlertSurroundingCreatures',0x547820:'GameAudio_GetPlrSfxBits',0x547930:'GameAudio_PlaySfx',0x54aae0:'TakeHitRumble',0x681f40:'PlayNamedSfx',0x54a8a0:'NewBuzz',0x54a850:'NewRumble'};events=[]
def boundary(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];events.append(hex(address));mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for address in hook_info:n.mu.hook_add(UC_HOOK_CODE,boundary,begin=address,end=address)
report['shieldBoundaryHooks']=[{'address':hex(k),'role':v,'behavior':'record call and return0; health/shield logic is not hooked'}for k,v in hook_info.items()]
try:
 r=contract('shield_hit_arithmetic_and_guards',['0x433be0','0x55f1d0','0x56e0f0']);r['flickerSeconds']=n.unpack('<f',0x7fb0a0)[0]
 for shield,damage,player,cut,invincible,timer,attacker,scale in itertools.product([0,1,4,127,128,255],[-1,0,1,2,4,255,256],[0,1],[0,1],[0,1],[0,.1],['none','inactive','npc','special_npc','player'],[0,1]):
  reset();events.clear();n.pack('<I',OBJ+0x1fc,0x1001|(128 if player else 0));n.pack('<B',OBJ+0xe38,shield);n.pack('<ff',OBJ+0xd30,scale,timer);n.pack('<I',CHEAT+8,128 if invincible else 0);n.pack('<I',0x855de0,cut);flags=0 if attacker=='inactive' else 129 if attacker=='player' else 1;n.pack('<I',ATT+0x1fc,flags);n.pack('<B',ATT+0x7b5,57 if attacker=='special_npc' else 0)
  effective=damage;active=attacker not in ['none','inactive']
  if scale==1 and timer>0 and active and attacker=='npc':effective=0
  if cut and player:effective=0
  hp=shield;tm=f32(timer);sc=float(scale)
  if shield and effective>0:
   if player and invincible:effective=0
   left=shield-effective
   if left>0:hp=left&255;tm=r['flickerSeconds']
   else:hp=0;tm=.5;sc=0.0
  n.call(0x433be0,[0 if attacker=='none' else ATT,OBJ,damage,0]);got=[n.read(OBJ+0xe38,1)[0],n.unpack('<f',OBJ+0xd34)[0],n.unpack('<f',OBJ+0xd30)[0]];check(r,[hp,tm,sc],got,{'shield':shield,'damage':damage,'player':player,'cut':cut,'invincible':invincible,'timer':timer,'attacker':attacker,'scale':scale})
except Exception as e:report['failures'].append({'contract':'shield','error':str(e)})
report['totals']={'cases':sum(r['cases']for r in report['contracts'].values()),'mismatches':sum(r['mismatches']for r in report['contracts'].values()),'failures':len(report['failures'])};report['limits']=['Synthetic states do not prove all combinations occur in ordinary gameplay.','No live audio, feedback, neighborhood alerts, graphics or OS calls.','General ObjHitObj combat orchestration and death side effects are not included in this suite.','Protection booleans tested with finite timer values only; malformed NaN input is not generalized.'];(BASE/'reports/native-combat-primitives.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report['totals']));print(report['failures']);print({k:{'cases':v['cases'],'mismatches':v['mismatches'],'examples':v['examples'][:3]}for k,v in report['contracts'].items()})

(BASE/'reports/native-combat-primitives-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'vectors':vectors},separators=(',',':'))+'\n')

raise SystemExit(1 if report['totals'].get('mismatches',0) or report['totals'].get('failures',0) else 0)
