"""Bounded original PC character context/animation contracts, no game/OS launch."""
import importlib.util,struct,json,random,math
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
n=native.NativeX86();BASE=native.BASE
OBJ=n.DATA;CHAR=OBJ+0x2000;GAME=OBJ+0x3000;MODEL=OBJ+0x4000;ANIMS=OBJ+0x5000;SET=OBJ+0x6000;SUIT=OBJ+0x7000;ATTACKER=OBJ+0x8000;SFX=OBJ+0xa000;OUT=OBJ+0xb000
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
n.pack('<I',0x29130e4,SET);n.pack('<I',SET+8,233);n.pack('<I',0x8020bc,SFX);n.write(SFX+0x158,bytes([255])*16);n.pack('<h',0x7f1884,77);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT))
report={'binarySha256':n.sha256,'method':'Unmodified original PC functions in isolated Unicorn x86, bounded synthetic object/model/animation-pointer state. Original arithmetic, random selection and animation-reset callees execute. No OS, game process, collision or damage callback.','contracts':{},'failures':[]}
def reset():
 n.write(OBJ,bytes(0x2000));n.write(CHAR,bytes(0x100));n.write(GAME,bytes(0x200));n.write(MODEL,bytes(0x80));n.write(ANIMS,bytes(0x400));n.write(SUIT,bytes(0x100));n.write(ATTACKER,bytes(0x2000))
 n.pack('<I',OBJ+0x54,CHAR);n.pack('<I',CHAR+0x24,GAME);n.pack('<I',OBJ+0x50,MODEL);n.pack('<I',MODEL+0xc,ANIMS);n.pack('<h',OBJ+0x1064,-99);n.pack('<f',0x925018,1/60)
def contract(name,functions):
 r={'functions':functions,'cases':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r
def check(r,want,actual,meta):
 r['cases']+=1
 if want!=actual:
  r['mismatches']+=1
  if len(r['examples'])<16:r['examples'].append({**meta,'expected':want,'actual':actual})
def availability(ids):
 for i in ids:n.pack('<I',ANIMS+i*4,1)
try:
 r=contract('block_animation_choice',['0x58dfa0','0x54fa60']);rng=random.Random(0x58dfa0)
 for i in range(1400):
  reset();ids=[26+j for j in range(3)if(i%8)&(1<<j)];availability(ids);previous=rng.choice([-1,26,27,28]);seed=rng.randrange(65536);n.pack('<h',OBJ+0xe10,previous);n.pack('<h',OBJ+0x7aa,99);n.pack('<I',0x80253c,seed)
  state=seed;chosen=99;prev=previous;result=0
  if ids:
   result=1;chosen=ids[0]
   if len(ids)>1:
    while True:
     state=(state*0x24cd+1)&65535;chosen=ids[state//(65535//len(ids)+1)]
     if chosen!=previous:break
   prev=chosen
  ret=n.call(0x58dfa0,[OBJ]);actual=[ret,n.unpack('<h',OBJ+0x7aa)[0],n.unpack('<h',OBJ+0xe10)[0],n.unpack('<I',0x80253c)[0]]
  check(r,[result,chosen,prev,state],actual,{'available':ids,'previous':previous,'seed':seed})
 print('block choice',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'block choice','error':str(e)})
try:
 r=contract('new_block_source_capture',['0x49e370','0x58dfa0']);rng=random.Random(0x49e370)
 for mode in['bolt','part','special','melee']:
  for available in[False,True]:
   for stage in range(0,256,7):
    reset();n.pack('<b',OBJ+0x7b5,-1);n.pack('<h',OBJ+0x7aa,99);n.pack('<h',OBJ+0xe10,-1);n.pack('<B',OBJ+0xe2f,1);n.pack('<I',OBJ+0xe20,0x108);n.pack('<B',ATTACKER+0x7b2,stage);n.pack('<H',ATTACKER+0x7aa,stage)
    if available:availability([26])
    offsets={'bolt':0xd04,'part':0xcb0,'special':0xd00,'melee':0xcfc};n.pack('<I',OBJ+offsets[mode],ATTACKER)
    ret=n.call(0x49e370,regs={native.UC_X86_REG_ESI:OBJ});actual=[ret,n.unpack('<b',OBJ+0x7b5)[0],n.read(OBJ+0xe2f,1)[0],n.unpack('<h',OBJ+0x7aa)[0],n.unpack('<f',OBJ+0x77c)[0],n.unpack('<I',OBJ+0xcf8)[0],n.unpack('<I',OBJ+0xd08)[0],n.unpack('<I',OBJ+0xcb4)[0],n.read(OBJ+0xe2e,1)[0],n.unpack('<I',OBJ+0xe20)[0]]
    want=[0,-1,1,99,0,0,0,0,0,0x108]if not available else[1,12,0,26,f32(.3 if mode in['bolt','part']else .1),ATTACKER if mode in['special','melee']else 0,ATTACKER if mode=='bolt'else 0,ATTACKER if mode=='part'else 0,stage if mode=='special'else(stage+1)&255 if mode=='melee'else 0,0x20000108 if mode=='special'else 0x108]
    check(r,want,actual,{'mode':mode,'available':available,'stage':stage})
 print('new block',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'new block','error':str(e)})
try:
 r=contract('block_timing_and_release',['0x49e450']);rng=random.Random(0x49e450)
 for mode in['latch','release','npc_guard','refresh','cooldown']:
  for i in range(400):
   reset();timer=f32(rng.uniform(-.1,.5));dt=f32(rng.choice([0,1/120,1/60,1/30,.1]));latch=0 if mode=='latch'else 1;context=-1 if mode=='cooldown'else 12;held=1 if mode=='refresh'else 0;n.pack('<b',OBJ+0x7b5,context);n.pack('<B',OBJ+0xe2f,latch);n.pack('<f',OBJ+0x77c,timer);n.pack('<f',0x925018,dt)
   cooldown=0
   if mode=='npc_guard':n.pack('<h',OBJ+0x1064,77)
   if mode=='refresh':n.pack('<I',OBJ+0xd04,ATTACKER)
   if mode=='cooldown':cooldown=f32(rng.uniform(.0001,.5));n.pack('<f',OBJ+0xdd8,cooldown)
   wanttimer=timer;wantctx=context;wantlatch=latch;wantcool=cooldown
   if mode=='cooldown':wantcool=f32(cooldown-dt)
   elif mode=='refresh':wanttimer=f32(.2)
   else:
    wanttimer=f32(timer-dt)
    if wanttimer<=0:
     if mode=='latch':wantlatch=1;wanttimer=f32(.2)
     else:wantctx=-1;wantcool=1.5 if mode=='npc_guard'else 0
   n.call(0x49e450,[0,held,0,0],regs={native.UC_X86_REG_EAX:OBJ});actual=[n.unpack('<b',OBJ+0x7b5)[0],n.read(OBJ+0xe2f,1)[0],n.unpack('<f',OBJ+0x77c)[0],n.unpack('<f',OBJ+0xdd8)[0]];check(r,[wantctx,wantlatch,wanttimer,wantcool],actual,{'mode':mode,'timer':timer,'dt':dt})
 print('block timing',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'block timing','error':str(e)})
try:
 r=contract('block_combo_jump_initialization',['0x49e2b0','0x547f30','0x62e650']);rng=random.Random(0x49e2b0)
 for i in range(600):
  reset();variant=i%2;player=bool(i%3);speed=f32(rng.uniform(0,8));flags=rng.getrandbits(32);eflags=rng.getrandbits(32);n.pack('<f',GAME+0x38,speed);n.pack('<I',OBJ+0x7bc,flags);n.pack('<I',OBJ+0xe20,eflags);n.pack('<I',OBJ+0x1fc,128 if player else 0);n.pack('<I',OBJ+0xeec,0x100);n.pack('<B',OBJ+0x281,1);n.pack('<H',OBJ+0x1050,123)
  for o in[0x77c,0xd48,0xd2c,0xd1c]:n.pack('<f',OBJ+o,7)
  n.call(0x49e2b0,[variant],regs={native.UC_X86_REG_ESI:OBJ});animation=12 if variant else 18;newflags=flags&0xfffeffff;newflags=(newflags|0x2000)if variant else(newflags&0xffffdfff);newflags&=0xffff6fff
  want=[speed,0,2,animation,newflags,eflags|0x100000,0,0,0,0,0,0,0x900 if player else 0x100,animation,animation,animation]
  actual=[n.unpack('<f',OBJ+0x6c)[0],n.read(OBJ+0x7b5,1)[0],n.read(OBJ+0x7b8,1)[0],n.unpack('<h',OBJ+0x7aa)[0],n.unpack('<I',OBJ+0x7bc)[0],n.unpack('<I',OBJ+0xe20)[0],*[n.unpack('<f',OBJ+o)[0]for o in[0x77c,0xd48,0xd2c,0xd1c]],n.read(OBJ+0x281,1)[0],n.unpack('<H',OBJ+0x1050)[0],n.unpack('<I',OBJ+0xeec)[0],*[n.unpack('<h',OBJ+o)[0]for o in[0x3e,0x40,0x42]]]
  check(r,want,actual,{'variant':variant,'player':player,'speed':speed,'flags':flags})
 print('combo jump',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'combo jump','error':str(e)})
try:
 r=contract('locomotion_animation_selection',['0x4a54b0']);rng=random.Random(0x4a54b0);slots=[0,3,4,23,63,64,80,198,199,200]
 for i in range(7000):
  reset();speeds=[f32(.153867),f32(.6),f32(1.2)];n.pack('<fff',GAME+0x14,*speeds);speed=f32(rng.uniform(0,1.5));tiptoe=i%2;weapon=bool(i%3);weaponstate=bool(i%5);weaponalt=bool(i%7);backwards=bool(i%11);magnetic=bool(i%13);excluded=bool(i%17);available={v for v in slots if rng.randrange(2)};availability(available)
  n.pack('<f',OBJ+0xd3c,1 if weaponstate else 0);n.pack('<B',OBJ+0xe33,1 if weaponalt else 0);n.pack('<I',OBJ+0xef0,0x4000 if backwards else 0)
  if magnetic:n.pack('<I',OBJ+0xcbc,SUIT);n.pack('<B',SUIT+0xc,0x40)
  if excluded:n.pack('<BB',OBJ+0x7b5,67,5)
  armed=weapon and(weaponstate or weaponalt)
  if tiptoe and speed<=(speeds[0]+speeds[1])*.5:chosen=63 if armed and 63 in available else 4
  elif speed>(speeds[1]+speeds[2])*.5:chosen=23 if armed and 23 in available else 3
  elif armed and 64 in available:chosen=64
  else:chosen=80 if backwards and 80 in available else 0
  if magnetic and not excluded:
   replacement={4:198,0:199,3:200}.get(chosen)
   if replacement in available:chosen=replacement
  for _ in range(3):
   if chosen in available:break
   chosen={4:0,0:3,3:0}.get(chosen,chosen)
  n.call(0x4a54b0,[bits(speed),tiptoe],regs={native.UC_X86_REG_ECX:OBJ,native.UC_X86_REG_EDX:int(weapon)});check(r,[chosen],[n.unpack('<h',OBJ+0x42)[0]],{'speed':speed,'tiptoe':tiptoe,'weapon':weapon,'available':sorted(available),'magnetic':magnetic,'excluded':excluded})
 print('locomotion selection',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'locomotion selection','error':str(e)})
try:
 r=contract('jump_animation_transition',['0x4a7360']);rng=random.Random(0x4a7360)
 for i in range(4000):
  reset();falling=bool(i%2);state=i%11;animation=rng.choice([6,9,73,200]);available={a for a in[5,181]if rng.randrange(2)};availability(available);packet_matches=bool(i%3);packet_done=bool(i%5);blend=bool(i%7);threshold=f32(rng.choice([0,.05,.1,.5]));timer=f32(rng.uniform(0,.5));dt=f32(rng.choice([0,1/60,.1]));distance=f32(rng.choice([2e6,.1,.35,.5]));flags=0x8000 if falling else 0
  n.pack('<I',OBJ+0x7bc,flags);n.pack('<B',OBJ+0x7b8,state);n.pack('<h',OBJ+0x7aa,animation);n.pack('<h',OBJ+0x3e,animation if packet_matches else -1);n.pack('<BB',OBJ+0x38,1 if packet_done else 0,1 if blend else 0);n.pack('<f',OBJ+0xd2c,timer);n.pack('<f',OBJ+0xda0,distance);n.pack('<f',0x7fc094,threshold);n.pack('<f',0x925018,dt)
  chosen=animation;newtimer=timer;newflags=flags
  if falling and state==8 and 181 in available:chosen=181
  elif falling and 5 in available:chosen=5
  elif not falling and animation!=73 and state in[0,1,6,7,9]:
   if not blend and packet_matches and packet_done:
    if threshold<=0:newflags|=0x8000
    else:newtimer=f32(timer+dt)
   else:newtimer=0
   if threshold>0 and threshold<=newtimer and(distance==2e6 or distance>f32(.35)):newflags|=0x8000
  n.call(0x4a7360,regs={native.UC_X86_REG_ECX:OBJ});check(r,[chosen,newtimer,newflags],[n.unpack('<h',OBJ+0x42)[0],n.unpack('<f',OBJ+0xd2c)[0],n.unpack('<I',OBJ+0x7bc)[0]],{'falling':falling,'state':state,'animation':animation,'available':sorted(available),'threshold':threshold,'timer':timer,'dt':dt,'distance':distance})
 print('jump animation',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'jump animation','error':str(e)})
try:
 r=contract('context_fall_and_block_predicates',['0x562150','0x441ce0']);registry=json.loads((BASE/'reports/animation-context-registry.json').read_text())
 for ctx in registry['contexts']:
  for configured in[-1,5]:
   for present in[False,True]:
    reset();n.pack('<b',OBJ+0x7b5,ctx['id']);n.pack('<i',0x804c0c,configured)
    if present:availability([5])
    check(r,[int(bool(ctx['flags']&8)and configured!=-1 and present)],[n.call(0x562150,[OBJ])],{'context':ctx['id'],'fallConfigured':configured,'present':present})
  for conditional in[False,True]:
   reset();n.pack('<b',OBJ+0x7b5,ctx['id']);n.pack('<I',OBJ+0x7bc,0x20000 if conditional else 0);n.pack('<I',SUIT+0xd0,ATTACKER);n.pack('<I',ATTACKER,OBJ);n.call(0x441ce0,[0,0,SUIT]);n.mu.emu_start(n.STOP,n.STOP+6)
   check(r,[float(bool(ctx['flags']&0x4000000 or(ctx['flags']&0x8000000 and conditional)))],[n.unpack('<f',OUT)[0]],{'context':ctx['id'],'conditionalBit':conditional})
 print('context predicates',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'context predicates','error':str(e)})
try:
 r=contract('block_entry_context_gate',['0x49e450','0x49e370','0x58dfa0'])
 for ctx in registry['contexts']:
  if ctx['id']==12:continue
  for pressed in[0,1]:
   for allow in[0,1]:
    for grounded in[0,1]:
     for enabled in[0,1]:
      reset();availability([26]);n.pack('<b',OBJ+0x7b5,ctx['id']);n.pack('<B',OBJ+0x281,grounded);n.pack('<I',OBJ+0xeec,2 if enabled else 0);n.pack('<I',OBJ+0xd04,ATTACKER);n.pack('<h',OBJ+0x7aa,-1)
      starts=bool(pressed and allow and grounded and enabled and not(ctx['flags']&0x20));n.call(0x49e450,[pressed,0,0,allow],regs={native.UC_X86_REG_EAX:OBJ});check(r,[12 if starts else ctx['id'],26 if starts else -1,f32(.3)if starts else 0],[n.unpack('<b',OBJ+0x7b5)[0],n.unpack('<h',OBJ+0x7aa)[0],n.unpack('<f',OBJ+0x77c)[0]],{'context':ctx['id'],'pressed':pressed,'allowStart':allow,'grounded':grounded,'enabled':enabled})
 print('block entry gate',r['cases'],r['mismatches'],flush=True)
 r=contract('block_attacker_stage_wait',['0x49e450'])
 for special in[False,True]:
  for alive in[False,True]:
   for disabled in[False,True]:
    for context in[-1,5,38]:
     for stage in range(1,5):
      for attacker_stage in range(5):
       reset();n.pack('<b',OBJ+0x7b5,12);n.pack('<I',OBJ+0xcf8,ATTACKER);n.pack('<B',OBJ+0xe2e,stage);n.pack('<f',OBJ+0x77c,.15);n.pack('<I',OBJ+0xe20,0x20000000 if special else 0);n.pack('<I',ATTACKER+0x1fc,0x1000 if alive else 0);n.pack('<B',ATTACKER+0x28b,1 if disabled else 0);n.pack('<b',ATTACKER+0x7b5,context);n.pack('<B',ATTACKER+0x7b2,attacker_stage);n.pack('<H',ATTACKER+0x7aa,attacker_stage);n.pack('<h',ATTACKER+0x1064,-99)
       retained=alive and not disabled and((context==38 and attacker_stage==stage)if special else(context==5 and attacker_stage<stage));n.call(0x49e450,[0,0,0,0],regs={native.UC_X86_REG_EAX:OBJ});check(r,[stage if retained else 0,f32(.15)],[n.read(OBJ+0xe2e,1)[0],n.unpack('<f',OBJ+0x77c)[0]],{'special':special,'alive':alive,'disabled':disabled,'attackerContext':context,'blockedStage':stage,'attackerStage':attacker_stage})
 print('block stage wait',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'block context gate/stages','error':str(e)})
try:
 r=contract('pc_hold_callback',['0x428f20','0x404fa0','0x5655d0']);WORLD=OBJ+0xc000;TABLE=OBJ+0xf000;SPECIAL=OBJ+0x11000;n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x2ac0,TABLE);n.pack('<h',0x7f180c,88)
 for global_a in[0,1]:
  for global_b in[0,1]:
   for feature in[0,1]:
    for available in[0,1]:
     for character in[-99,88]:
      reset();n.write(SPECIAL,bytes(0x100));n.write(TABLE,bytes(0x400));n.pack('<I',0x7f39e4,global_a);n.pack('<I',0x876580,global_b);n.pack('<I',GAME+0x90,0x20000000 if feature else 0);n.pack('<I',OBJ+0xcc0,SPECIAL);n.pack('<h',OBJ+0x1064,character);n.pack('<b',OBJ+0x7b5,12);n.pack('<ff',OBJ+0xc5c,1.2,-1.2);idx=51 if character==88 else 50;n.pack('<B',TABLE+idx*16+14,available);ret=n.call(0x428f20,[OBJ]);launch=not(global_a and not global_b)and feature and available
      check(r,[1 if global_a and not global_b else 0 if launch else 2,77 if launch else 12,144 if launch else 0,0x20000 if launch else 0,idx if feature and not(global_a and not global_b)else 0],[ret,n.unpack('<b',OBJ+0x7b5)[0],n.unpack('<h',OBJ+0x7aa)[0],n.unpack('<I',OBJ+0x7bc)[0],n.unpack('<H',SPECIAL+0xac)[0]],{'global7f39e4':global_a,'global876580':global_b,'featureFlag':feature,'specialAvailable':available,'characterId':character})
 print('hold callback',r['cases'],r['mismatches'],flush=True)
 r=contract('hold_start_with_original_callback',['0x58e3b0','0x428f20','0x58dfa0','0x548540']);n.pack('<I',0x955598,0x428f20);n.pack('<I',WORLD+0x2a94,TABLE);n.write(TABLE,bytes(0x400))
 for global_a in[0,1]:
  for global_b in[0,1]:
   for enabled in[False,True]:
    for available in[False,True]:
     reset();n.pack('<I',0x7f39e4,global_a);n.pack('<I',0x876580,global_b);n.pack('<i',0x802820,24 if enabled else -1);n.pack('<b',OBJ+0x7b5,12);n.pack('<f',OBJ+0xde4,9);n.pack('<B',OBJ+0x280,255)
     if available:availability([26])
     callback=1 if global_a and not global_b else 2;started=callback==1 and enabled and available;n.call(0x58e3b0,[OBJ]);check(r,[24 if started else -1,0 if callback==2 else 9,f32(.3)if started else 0],[n.unpack('<b',OBJ+0x7b5)[0],n.unpack('<f',OBJ+0xde4)[0],n.unpack('<f',OBJ+0x77c)[0]],{'global7f39e4':global_a,'global876580':global_b,'contextEnabled':enabled,'blockAnimation':available})
 print('hold start',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'PC hold callback/start','error':str(e)})
report['totals']={'cases':sum(r['cases']for r in report['contracts'].values()),'mismatches':sum(r['mismatches']for r in report['contracts'].values()),'failures':len(report['failures'])};(BASE/'reports/animation-context-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps(report['totals']),json.dumps(report['failures']))
if report['totals']['mismatches']or report['failures']:raise SystemExit(1)
