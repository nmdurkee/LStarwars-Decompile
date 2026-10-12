"""Generate C# differential cases from unmodified original PC context code.
DieAir/StunDie runs stop immediately before the original KillParts call; returned
effect requests must be completed by an engine adapter, not a simulated callback.
"""
import importlib.util,struct,json,random,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
n=native.NativeX86();BASE=native.BASE;SIZE=0x10d8;O=n.DATA;C=O+0x2000;G=O+0x3000;M=O+0x4000;A=O+0x5000;D=O+0x6000;H=O+0x7000;DEF=O+0x7100;SET=O+0x8000;MAP=O+0x8100;SUIT=O+0x9000;SFX=O+0xa000;OUT=O+0xb000
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
n.pack('<I',0x29130e4,SET);n.pack('<I',SET,1);n.pack('<I',SET+8,233);n.pack('<II',SET+0x18,M,MAP);n.pack('<H',MAP,0);n.pack('<I',0x8020bc,SFX);n.write(SFX+0x158,bytes([255])*16);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.pack('<I',0x93b324,0)
effect=0
def frontier(mu,address,size,userdata):
 global effect
 sp=mu.reg_read(native.UC_X86_REG_ESP);effect=2 if n.unpack('<I',sp+20)[0]else 1;mu.emu_stop()
n.mu.hook_add(UC_HOOK_CODE,frontier,begin=0x49c1c1,end=0x49c1c1)
def reset():
 n.write(O,bytes(SIZE));n.write(C,bytes(0x100));n.write(G,bytes(0x200));n.write(M,bytes(0x80));n.write(A,bytes(0x400));n.write(D,bytes(0x400));n.write(DEF,bytes(0x80));n.write(SUIT,bytes(0x100));n.pack('<II',M+8,D,A);n.pack('<I',O+0x50,M);n.pack('<I',O+0x54,C);n.pack('<I',C+0x24,G);n.pack('<h',O+0x1064,0);n.pack('<f',0x925018,1/60)
def clips(ids,frames=61,fps=30,blend=0,flags=0):
 n.pack('<f',H,frames);n.pack('<I',DEF+4,flags);n.pack('<ff',DEF+0x14,blend,fps)
 for i in ids:n.pack('<I',A+i*4,H);n.pack('<I',D+i*4,DEF)
 return [sum(1<<(i%32)for i in ids if i//32==j)for j in range(8)]
target=BASE/'reports/animation-portable-cases.bin';out=target.open('wb');out.write(b'ANIMCS01'+struct.pack('<I',0));counts={};failures=[];rng=random.Random(0x49c080)
def record(kind,params,before,ret=0,rngstate=0):
 out.write(struct.pack('<II',kind,len(params)));out.write(struct.pack('<'+'I'*len(params),*[v&0xffffffff for v in params]));out.write(before);out.write(n.read(O,SIZE));out.write(struct.pack('<II',ret&0xffffffff,rngstate));counts[kind]=counts.get(kind,0)+1
try:
 for i in range(700):
  raw=rng.randbytes(SIZE);n.write(O,raw);n.call(0x41b420,[O,0,0,0]);record(1,[],raw)
 print('reset cases',counts,flush=True)
 for i in range(7000):
  reset();context=rng.choice([21,90,95,96,-1,5]);animation=rng.choice([-1,61,62,167,168,169,170,171,172,185,6,184,1]);dt=f32(rng.choice([0,1/120,1/60,1/30,.1]));fps=f32(rng.choice([15,24,30,60]));frames=f32(rng.choice([2,16,31,61,121]));blend=f32(rng.choice([0,.1,.25]));clipflags=2 if i%3==0 else 0;ids={a for a in[1,6,61,62,167,168,169,170,171,172,184,185]if rng.randrange(2)};mask=clips(ids,frames,fps,blend,clipflags)
  n.pack('<b',O+0x7b5,context);n.pack('<h',O+0x7aa,animation);n.pack('<B',O+0x7b3,rng.choice([0,0,0,1,2]));n.pack('<f',O+0x77c,rng.uniform(-.1,2.1));n.pack('<f',O+0x784,rng.choice([.2,.5,1,2]));n.pack('<f',O+0x778,rng.uniform(0,2));n.pack('<f',O+0xdfc,rng.choice([-1,0,1]));n.pack('<B',O+0x281,rng.randrange(2));n.pack('<B',O+0x1078,rng.randrange(2));n.pack('<f',O+0x1030,rng.uniform(0,1));n.pack('<I',O+0xe24,rng.getrandbits(32));n.pack('<B',O+0x39,rng.randrange(2));n.pack('<h',O+0x3e,animation if rng.randrange(2)else -1);n.pack('<h',O+0x3c,animation if rng.randrange(2)else -1);n.pack('<f',0x925018,dt)
  before=n.read(O,SIZE);effect=0
  try:n.call(0x49c080,[O])
  except RuntimeError:
   if not effect:raise
  record(2,[bits(dt),bits(frames),bits(fps),bits(blend),clipflags]+mask,before,effect)
 # Deterministic branch coverage: random timers seldom exercise StunDie or
 # all three stun remaps. These original-code cases do not consume the RNG.
 for context in [21,90,95,96]:
  for animation in [-1,61,167,168,169,185,184]:
   for substate in [0,1,2]:
    for readiness in ['missing','ready','blending-ready','not-ready']:
     for timer in [-.01,0,.499,.5,.501,1,2]:
      reset();dt=f32(1/60);frames=f32(31);fps=f32(30);blend=f32(.1);clipflags=0
      ids={1,61,167,168,169,170,171,172,184,185}
      if readiness=='missing':ids.discard(animation)
      mask=clips(ids,frames,fps,blend,clipflags)
      n.pack('<b',O+0x7b5,context);n.pack('<h',O+0x7aa,animation);n.pack('<B',O+0x7b3,substate);n.pack('<f',O+0x77c,timer);n.pack('<f',O+0x784,1);n.pack('<f',O+0x778,2);n.pack('<f',O+0xdfc,0)
      n.pack('<B',O+0x39,1 if readiness=='blending-ready' else 0);n.pack('<h',O+0x3e,animation if readiness=='ready' else -1);n.pack('<h',O+0x3c,animation if readiness=='blending-ready' else -1);n.pack('<f',0x925018,dt)
      before=n.read(O,SIZE);effect=0
      try:n.call(0x49c080,[O])
      except RuntimeError:
       if not effect:raise
      record(2,[bits(dt),bits(frames),bits(fps),bits(blend),clipflags]+mask,before,effect)
 print('death context cases',counts,flush=True)
 for i in range(3000):
  reset();tip=f32(rng.uniform(.1,.3));walk=f32(rng.uniform(.4,.8));run=f32(rng.uniform(1,2));speed=f32(rng.uniform(0,2.2));allowweapon=rng.randrange(2);allowtip=rng.randrange(2);n.pack('<fff',G+0x14,tip,walk,run);n.pack('<f',O+0xd3c,rng.randrange(2));n.pack('<B',O+0xe33,rng.randrange(2));n.pack('<I',O+0xef0,0x4000 if rng.randrange(2)else 0);n.pack('<BB',O+0x7b5,67 if rng.randrange(2)else 0,5 if rng.randrange(2)else 0)
  magnetic=rng.randrange(2);n.pack('<I',O+0xcbc,SUIT if magnetic else 0);n.pack('<B',SUIT+0xc,0x40);mask=clips({a for a in[0,3,4,23,63,64,80,198,199,200]if rng.randrange(2)});before=n.read(O,SIZE);n.call(0x4a54b0,[bits(speed),allowtip],regs={native.UC_X86_REG_ECX:O,native.UC_X86_REG_EDX:allowweapon});record(3,[bits(speed),allowweapon,allowtip,bits(tip),bits(walk),bits(run),magnetic]+mask,before)
 for i in range(2400):
  reset();dt=f32(rng.choice([0,1/60,.1]));delay=f32(rng.choice([0,.05,.1,.5]));mask=clips({a for a in[5,181]if rng.randrange(2)});animation=rng.choice([6,9,73,200]);n.pack('<I',O+0x7bc,0x8000 if rng.randrange(2)else 0);n.pack('<B',O+0x7b8,rng.randrange(11));n.pack('<h',O+0x7aa,animation);n.pack('<h',O+0x3e,animation if rng.randrange(2)else -1);n.pack('<BB',O+0x38,rng.randrange(2),rng.randrange(2));n.pack('<f',O+0xd2c,rng.uniform(0,.5));n.pack('<f',O+0xda0,rng.choice([2e6,.1,.35,.5]));n.pack('<f',0x7fc094,delay);n.pack('<f',0x925018,dt);before=n.read(O,SIZE);n.call(0x4a7360,regs={native.UC_X86_REG_ECX:O});record(4,[bits(dt),bits(delay)]+mask,before)
 for i in range(1400):
  reset();mask=clips({a for a in[26,27,28]if rng.randrange(2)});seed=rng.randrange(65536);n.pack('<I',0x80253c,seed);n.pack('<h',O+0xe10,rng.choice([-1,26,27,28]));n.pack('<h',O+0x7aa,99);before=n.read(O,SIZE);ret=n.call(0x58dfa0,[O]);record(5,[seed]+mask,before,ret,n.unpack('<I',0x80253c)[0])
 for i in range(800):
  reset();variant=rng.randrange(2);speed=f32(rng.uniform(0,8));n.pack('<f',G+0x38,speed);n.pack('<I',O+0x7bc,rng.getrandbits(32));n.pack('<I',O+0xe20,rng.getrandbits(32));n.pack('<I',O+0xeec,rng.getrandbits(32));n.pack('<I',O+0x1fc,128 if rng.randrange(2)else 0);n.pack('<B',O+0x281,1);n.pack('<H',O+0x1050,400)
  for offset in[0x77c,0xd48,0xd2c,0xd1c]:n.pack('<f',O+offset,rng.uniform(0,3))
  before=n.read(O,SIZE);n.call(0x49e2b0,[variant],regs={native.UC_X86_REG_ESI:O});record(6,[variant,bits(speed)],before)
 for i in range(2400):
  reset();frames=f32(rng.uniform(2,240));fps=f32(rng.choice([15,24,25,30,48,60]));blend=f32(rng.uniform(0,.5));start=f32(rng.uniform(0,300));end=f32(rng.uniform(0,300));subtract=rng.randrange(2);clips({6},frames,fps,blend);before=n.read(O,SIZE);n.call(0x62e040,[0,6,bits(start),bits(end),subtract]);n.mu.emu_start(n.STOP,n.STOP+6);record(7,[bits(frames),bits(fps),bits(blend),bits(start),bits(end),subtract],before,n.unpack('<I',OUT)[0])
except Exception as e:failures.append(str(e));print('FAIL',e,flush=True)
out.seek(8);out.write(struct.pack('<I',sum(counts.values())));out.close();report={'binarySha256':n.sha256,'caseFile':str(target.relative_to(BASE)),'caseFileSha256':hashlib.sha256(target.read_bytes()).hexdigest(),'objectImageSize':SIZE,'counts':counts,'total':sum(counts.values()),'failures':failures,'typeNames':{1:'ResetPlayer resetMoves=0',2:'TakeHitCode timed death/stun progression',3:'Movement animation selection',4:'Jump animation selection',5:'Block animation selection',6:'Block combat jump initialization',7:'Animation duration'},'frontier':{'address':'0x49c1c1','operation':'Original call to KillParts0x437770','behavior':'Stop before call; record kill mode and all object changes. No replacement callback, cleanup, drops or death side effect is executed by this suite.','arcadeGlobal':'0x93b324=0; arcade score callback not covered'},'limits':['Full respawn placement/resetMoves=1 requires terrain/socket/portal and larger reset-state integration, not covered.','Death input clips use synthetic legacy duration headers and exact PC model/action pointer layout.','Finite scalar fixtures only; pathological NaNs or invalid pointer state are outside contract.']};(BASE/'reports/animation-portable-native-cases.json').write_text(json.dumps(report,indent=2));print(json.dumps(report,indent=2))
if failures:raise SystemExit(1)
