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
report['method']='Original0x4364e0 death cleanup and bounded lethal0x438230 paths in Unicorn. NPC synthetic state; original cleanup callees execute. Only inherited media/rumble/alert boundaries hooked.'
def contract(name):
 r={'cases':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r
def check(r,want,got,meta):
 r['cases']+=1
 if want!=got:
  r['mismatches']+=1
  if len(r['examples'])<10:r['examples'].append({'input':meta,'expected':want,'actual':got})
clear_fields=[0x1008,0x39c,0x3a4,0x3b4,0x2a8,0x2ac,0xeb0,0xeb4,0x10a4,0x3ac,0xec0]
try:
 r=contract('npc_death_state_velocity_timers_and_cleanup');rng=random.Random(0x4364e0)
 for reason,vehicle,respawn,linked,i in itertools.product(range(6),[False,True],[0,0x100000,0x200000],[False,True],range(8)):
  reset();n.pack('<I',0x81020c,0);n.pack('<I',CHAR+4,0x2000 if vehicle else 0);n.pack('<I',OBJ+0xeec,respawn);v=[f32(rng.uniform(-20,20))for _ in range(3)];p=[f32(rng.uniform(-100,100))for _ in range(3)];n.pack('<fff',OBJ+0x68,*v);n.pack('<fff',OBJ+0x5c,*p);n.pack('<fff',OBJ+0x8c,10,20,30);mask=rng.getrandbits(32);n.pack('<I',OBJ+0x4b0,mask);n.pack('<h',OBJ+0xe18,12);n.pack('<f',OBJ+0x1008,3);n.pack('<f',OBJ+0x100c,4)
  for off in clear_fields:n.pack('<I',OBJ+off,0x3f000000)
  if linked:n.pack('<I',OBJ+0xea4,ATT);n.pack('<I',ATT+0xea4,OBJ)
  result=n.call(0x4364e0,[OBJ,reason,0],count=1000000);state=1 if reason in[0,1]else 2;timer=.5 if state==1 else 0.0;collidable=not(reason==5 or reason==4 and not respawn&0x100000);wantV=[f32(x*.5)for x in v]if vehicle else[0.0,v[1],0.0];wantSpawn=1.0 if reason==4 and respawn&0x100000 else 0.0;wantPosition=p if state==1 else[10.0,20.0,30.0]
  want=[1,0,state,timer,12 if state==1 else 0,mask&0xffffafff,0x1001 if collidable else 1,4 if not collidable else 0,wantSpawn,wantV,wantPosition,[0]*len(clear_fields),0,0]
  got=[result,n.read(OBJ+0x107f,1)[0],n.read(OBJ+0x28b,1)[0],n.unpack('<f',OBJ+0x100c)[0],n.unpack('<h',OBJ+0xe18)[0],n.unpack('<I',OBJ+0x4b0)[0],n.unpack('<I',OBJ+0x1fc)[0],n.read(OBJ+0x406,1)[0],n.unpack('<f',OBJ+0x1010)[0],list(n.unpack('<fff',OBJ+0x68)),list(n.unpack('<fff',OBJ+0x8c)),[n.unpack('<I',OBJ+off)[0]for off in clear_fields],n.unpack('<I',OBJ+0xea4)[0],n.unpack('<I',ATT+0xea4)[0]];check(r,want,got,{'reason':reason,'vehicle':vehicle,'respawnFlags':respawn,'linked':linked,'velocity':v})
 print('death',r['cases'],r['mismatches'],flush=True)
 r=contract('lethal_hit_no_parts_native_branch')
 for hp,damage,probe in itertools.product([1,2,4,10],[-1,1,2,4,10,99],[0,1]):
  if damage!=-1 and damage<hp:continue
  reset();n.pack('<I',0x81020c,0);n.pack('<I',CHAR+4,0x2000000);n.pack('<B',OBJ+0x107f,hp);result=n.call(0x438230,[0,OBJ,damage,1,probe,1],count=1000000);want=[2,hp if probe else 0,0 if probe else 2];got=[result,n.read(OBJ+0x107f,1)[0],n.read(OBJ+0x28b,1)[0]];check(r,want,got,{'hp':hp,'damage':damage,'probe':probe})
except Exception as e:report['failures'].append({'error':str(e)})
report['boundaryHooks']=[{'address':hex(k),'role':v,'behavior':'record call and return0'}for k,v in hooks.items()];report['totals']={'cases':sum(r['cases']for r in report['contracts'].values()),'mismatches':sum(r['mismatches']for r in report['contracts'].values()),'failures':len(report['failures'])};report['limits']=['NPC state only: player stud loss, rescue/respawn placement and level-specific death behavior remain unverified.','World registries empty and no scripts attached; global0x81020c explicitly set0 to represent no registry entries.','Lethal hit suite sets original character flag0x2000000 so original KillParts takes its no-parts branch. Debris rendering and drops are not simulated.','No named character special cases, respawn-group scheduling or populated AI squads.','Particle/audio/rumble-related live behavior is not established.'];(BASE/'reports/native-combat-death-verification.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report['totals']));print(report['failures']);print({k:v['examples'][:3]for k,v in report['contracts'].items()if v['mismatches']})

raise SystemExit(1 if report['totals'].get('mismatches',0) or report['totals'].get('failures',0) else 0)
