"""Bounded PC locomotion contracts using original functions and synthetic state.
No game, OS calls, terrain query, or unbounded gameplay state machine is executed.
"""
import importlib.util,struct,json,math,random,sys
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
n=native.NativeX86();BASE=native.BASE
OBJ=n.DATA;CHAR=OBJ+0x3000;GAME=OBJ+0x4000;WORLD=OBJ+0x5000;LEVEL=OBJ+0x9000;CONTEXT=OBJ+0xa100;PAD=OBJ+0xb000;PHYSICAL=OBJ+0xc000;SCALAR=OBJ+0xd000
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
report={'binarySha256':n.sha256,'method':'Original PC routines and original arithmetic callees, isolated Unicorn x86-32, synthetic bounded object/world/character/pad state. Input tests use an existing early-return context after input processing, before locomotion dispatch. No OS API, game process, collision resolution or full context state machine.','contracts':{},'failures':[]}
n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,LEVEL);n.pack('<I',0x7fb0e4,CONTEXT);n.write(0x29899a0,(BASE/'references/native-animation-sine-table.f32').read_bytes())
n.pack('<i',0x800944,0);n.pack('<h',0x921454,-1);n.pack('<I',0x7f1138,0)
def reset():
 n.write(OBJ,bytes(0x2000));n.write(CHAR,bytes(0x100));n.write(GAME,bytes(0x200));n.write(PAD,bytes(0x100));n.write(PHYSICAL,bytes(0x100))
 n.pack('<I',OBJ+0x54,CHAR);n.pack('<I',CHAR+0x24,GAME);n.pack('<I',OBJ+0xca4,PAD);n.pack('<I',PAD,PHYSICAL);n.pack('<f',OBJ+0x1028,1e9);n.pack('<f',OBJ+0x21c,2e6);n.pack('<f',OBJ+0x220,2e6);n.pack('<f',OBJ+0xa8,1)
 n.pack('<h',OBJ+0x1064,-99);n.pack('<f',0x925018,1/60)
def contract(name,addresses):
 r={'functions':addresses,'cases':0,'mismatches':0,'maxAbsoluteError':0,'examples':[]};report['contracts'][name]=r;return r
def check(r,expected,actual,meta,eps=2e-6):
 r['cases']+=1;err=max([0]+[abs(a-e)for a,e in zip(actual,expected)]);r['maxAbsoluteError']=max(r['maxAbsoluteError'],err)
 if any(not math.isfinite(a)or abs(a-e)>eps*max(1,abs(a),abs(e))for a,e in zip(actual,expected)):
  r['mismatches']+=1
  if len(r['examples'])<20:r['examples'].append({**meta,'expected':expected,'actual':actual})
def run_input(x,y,buttons=0,no_tiptoe=False,restricted=False):
 n.pack('<BBBB',PHYSICAL+0x90,0,0,x,y);n.pack('<I',PAD+4,buttons);n.pack('<f',PAD+0x28,0);n.pack('<I',GAME+0x90,8 if no_tiptoe else 0);n.pack('<I',CHAR+4,32 if restricted else 0);n.call(0x416190,[OBJ]);return n.unpack('<f',PAD+0x28)[0]
def expected_speed(x,y,buttons=0,no_tiptoe=False,restricted=False):
 if buttons&0xf000:
  dx=-127.5 if buttons&0x8000 else 127.5 if buttons&0x2000 else 0;dz=-127.5 if buttons&0x4000 else 127.5 if buttons&0x1000 else 0
 else:
  dx=x-127.5;dz=-(y-127.5)
  if dx*dx+dz*dz<1806.25:dx=dz=0
 magnitude=max(abs(dx),abs(dz))/127.5
 return f32(0 if magnitude<.2 else .6 if restricted else .153867 if magnitude<.5 and not no_tiptoe else .6 if magnitude<.8 else 1.2)
try:
 reset();n.pack('<I',OBJ+0x1fc,0x80);n.pack('<B',OBJ+0x7b5,59);n.pack('<B',OBJ+0x280,255);n.pack('<B',OBJ+0x107f,2);n.pack('<fff',GAME+0x14,.153867,.6,1.2)
 r=contract('player_speed_bands',['0x416190','0x5be2d0','0x5b3620','0x5c0240']);r['fixtureSpeeds']={'tiptoe':.153867,'walk':.6,'run':1.2};r['earlyReturnContext']=59
 for x in range(256):
  for y in range(256):check(r,[expected_speed(x,y)],[run_input(x,y)],{'x':x,'y':y},0)
 for mode in ['no_tiptoe','restricted']:
  for x in range(256):
   check(r,[expected_speed(x,127,**{mode:True})],[run_input(x,127,**{mode:True})],{'x':x,'y':127,'mode':mode},0)
 for buttons in range(16):
  mask=buttons<<12;check(r,[expected_speed(255,0,mask)],[run_input(255,0,mask)],{'buttons':mask},0)
 print('input',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'input','error':str(e)})
try:
 r=contract('gravity_basic_and_grounded',['0x4abac0']);rng=random.Random(0x4abac0)
 for i in range(3000):
  reset();v=f32(rng.uniform(-20,20));g=f32(rng.uniform(-20,-.1));dt=f32(rng.choice([0,1/120,1/60,1/30,.05,.1]));ground=rng.choice([0,0,0,1,2,4]);explicit=i%2==0
  n.pack('<f',OBJ+0x6c,v);n.pack('<f',GAME+0x24,g);n.pack('<f',0x925018,dt);n.pack('<B',OBJ+0x281,ground);n.pack('<f',SCALAR,g)
  n.call(0x4abac0,[OBJ,SCALAR if explicit else 0,bits(0),bits(0),0]);actual=n.unpack('<f',OBJ+0x6c)[0]
  expected=0 if ground&1 else f32(v+dt*g)if ground in[0,2]else v
  check(r,[expected],[actual],{'velocity':v,'gravity':g,'dt':dt,'groundFlags':ground,'explicit':explicit})
 print('gravity',r['cases'],r['mismatches'],flush=True)
 r=contract('gravity_hold_apex',['0x4abac0'])
 for player in[False,True]:
  for duration in[0,.2,.8]:
   for variant in[0,1,2,3]:
    for held in[False,True]:
     for v in[.05,1.0,-.2]:
      reset();dt=f32(1/60);g=-6.0;n.pack('<f',OBJ+0x6c,v);n.pack('<f',GAME+0x24,g);n.pack('<f',GAME+0x48,duration);n.pack('<I',OBJ+0x1fc,128 if player else 0);n.pack('<B',OBJ+0x7b8,5);n.pack('<B',OBJ+0xe32,variant);n.pack('<I',PAD+4,64 if held else 0)
      n.call(0x4abac0,[OBJ,0,0,0,0]);actual=[n.unpack('<f',OBJ+0x6c)[0],n.unpack('<f',OBJ+0xd64)[0],n.read(OBJ+0xe32,1)[0]]
      initial=f32(v);timer=0;state=variant
      if held and variant==2:vy=0
      elif held and variant==3:vy=f32(initial-dt)
      else:
       vy=f32(initial+g*dt)
       if not held and variant==2:state=3
       if held and initial>0 and vy<=0:
        if duration>0:vy=0;timer=f32(f32(duration)*(1 if player else 1.5));state=2
        else:state=3
      check(r,[vy,timer,state],actual,{'player':player,'duration':duration,'variant':variant,'held':held,'velocity':v})
 print('hold',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'gravity','error':str(e)})
try:
 r=contract('velocity_smoothing',['0x54fb40']);rng=random.Random(0x54fb40);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',SCALAR))
 for i in range(2000):
  a=f32(rng.uniform(-100,100));b=f32(rng.uniform(-100,100));rate=f32(rng.uniform(0,100));dt=f32(rng.choice([0,1/120,1/60,1/30,.1,.2]));n.pack('<f',0x925018,dt);n.call(0x54fb40,[bits(a),bits(b),bits(rate)]);n.mu.emu_start(n.STOP,n.STOP+6)
  check(r,[f32(a+min(f32(dt*rate),1)*(b-a))],[n.unpack('<f',SCALAR)[0]],{'current':a,'target':b,'rate':rate,'dt':dt})
 print('seek',r['cases'],r['mismatches'],flush=True)
 r=contract('predicted_collision_origin',['0x55d2b0']);rng=random.Random(0x55d2b0)
 for i in range(2000):
  reset();p=[f32(rng.uniform(-100,100))for _ in range(3)];v=[f32(rng.uniform(-10,10))for _ in range(3)];dt=f32(rng.choice([0,1/120,1/60,1/30,.1]));bottom=f32(rng.uniform(-.3,0));top=f32(rng.uniform(.1,.5));scale=f32(rng.uniform(.5,2))
  n.pack('<fff',OBJ+0x5c,*p);n.pack('<fff',OBJ+0x74,*v);n.pack('<f',OBJ+0xff0,bottom);n.pack('<f',OBJ+0xff4,top);n.pack('<f',OBJ+0xa8,scale);n.pack('<f',0x925018,dt);n.call(0x55d2b0,[OBJ])
  expected=[f32(p[0]+v[0]*dt),f32(p[1]+v[1]*dt+(bottom+top)*scale*.5),f32(p[2]+v[2]*dt)];check(r,expected,list(n.unpack('<fff',OBJ+0x80)),{'position':p,'velocity':v,'dt':dt,'bottom':bottom,'top':top,'scale':scale})
 print('origin',r['cases'],r['mismatches'],flush=True)
 r=contract('jump_reach_height',['0x561ca0']);rng=random.Random(0x561ca0)
 for i in range(1000):
  reset();vy=f32(rng.uniform(-5,5));start=f32(rng.uniform(-2,2));bottom=f32(rng.uniform(-2,2));height=f32(rng.uniform(0,3));g=f32(rng.uniform(-20,-1));force=i%2
  n.pack('<f',OBJ+0x6c,vy);n.pack('<f',OBJ+0x78c,start);n.pack('<f',OBJ+0x17c,bottom);n.pack('<f',GAME+0x24,g);n.call(0x561ca0,[OBJ,bits(height),force]);remaining=f32(height-(bottom-start));target=f32(math.sqrt(-2*g*remaining))if remaining>0 else 0;want=target if force or remaining>0 and target>vy else vy
  check(r,[want],[n.unpack('<f',OBJ+0x6c)[0]],{'velocity':vy,'start':start,'bottom':bottom,'height':height,'gravity':g,'force':force})
 print('reach',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'math-origin-jump','error':str(e)})
try:
 r=contract('jump_initialization',['0x561ba0','0x547f30','0x62e650']);r['fixture']='Sound table entries set to -1, taking original no-sound branch; original animation-reset callee executes.'
 SFX=SCALAR+0x1000;n.pack('<I',0x8020bc,SFX);n.write(SFX+0x158,bytes([255])*16);n.pack('<h',0x804bec,6)
 for enabled in[False,True]:
  for state in range(11):
   for speed in[0,.5,1,2.3,3,8]:
    reset();n.pack('<i',0x802838,0 if enabled else -1);n.pack('<B',OBJ+0x7b5,77);n.pack('<B',OBJ+0x7b8,17);n.pack('<B',OBJ+0x7b9,9);n.pack('<h',OBJ+0x7aa,123);n.pack('<f',GAME+0x2c,speed);n.pack('<B',OBJ+0x281,1);n.pack('<H',OBJ+0x1050,9);n.pack('<I',OBJ+0xe20,0x200);n.pack('<I',OBJ+0x7bc,0x1234567);n.pack('<f',OBJ+0x17c,.125);n.pack('<fff',OBJ+0xd1c,4,5,6);n.pack('<f',OBJ+0xd2c,8);n.pack('<f',OBJ+0xd48,9)
    n.call(0x561ba0,[OBJ,state]);actual=[n.unpack('<f',OBJ+0x6c)[0],n.read(OBJ+0x281,1)[0],n.unpack('<H',OBJ+0x1050)[0],n.unpack('<I',OBJ+0xe20)[0],n.unpack('<f',OBJ+0xd1c)[0],n.unpack('<f',OBJ+0xd2c)[0],n.unpack('<f',OBJ+0xd48)[0],n.read(OBJ+0x107a,1)[0],n.read(OBJ+0x7b5,1)[0],n.read(OBJ+0x7b8,1)[0],n.read(OBJ+0x7b9,1)[0],n.unpack('<h',OBJ+0x7aa)[0],n.unpack('<I',OBJ+0x7bc)[0],n.unpack('<f',OBJ+0x78c)[0],n.unpack('<f',OBJ+8)[0]]
    expected=[f32(speed),0,0,0x100200,0,0,0,2,0 if enabled else 77,state if enabled else 17,1 if enabled else 9,6 if enabled else 123,((0x1234567&0xfffe6fff)|(65536 if state in[3,4]else 0))if enabled else 0x1234567,.125 if enabled else 0,1]
    check(r,expected,actual,{'enabled':enabled,'state':state,'speed':speed},0)
 print('start jump',r['cases'],r['mismatches'],flush=True)
except Exception as e:report['failures'].append({'contract':'jump-initialization','error':str(e)})
report['totals']={'cases':sum(r['cases']for r in report['contracts'].values()),'mismatches':sum(r['mismatches']for r in report['contracts'].values()),'failures':len(report['failures'])}
(BASE/'reports/animation-locomotion-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps(report['totals']));print(report['failures']);print({k:v['examples'][:3]for k,v in report['contracts'].items()if v['mismatches']})
