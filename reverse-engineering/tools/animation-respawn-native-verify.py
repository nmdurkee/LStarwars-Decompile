"""Bounded original-PC spawn selection and full reset checks; no callbacks replaced."""
import importlib.util,struct,json,random,collections,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
n=native.NativeX86();BASE=native.BASE;O=n.DATA;C=O+0x2000;G=O+0x3000;M=O+0x4000;A=O+0x5000;D=O+0x6000;PAD=O+0x7000;W=O+0x8000;P=O+0xb000;START=O+0xc000
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
rng=random.Random(0x41b420);groups=collections.Counter();checks=collections.Counter();mismatchCounts=collections.Counter();errors=[];failures=[];traces=[]
def check(group,actual,expected,case,label):
 checks[group]+=1
 if actual!=expected:
  mismatchCounts[group]+=1
  if len(errors)<30:errors.append({'group':group,'case':case,'field':label,'actual':actual,'expected':expected})
try:
 spawnPath=BASE/'reports/animation-spawn-pointer-cases.bin'
 spawnOut=spawnPath.open('wb');spawnOut.write(b'ASPAWN01'+struct.pack('<I',65536))
 for rawslot in range(256):
  slot=rawslot if rawslot<128 else rawslot-256
  for fallback in range(256):
   mask=(rawslot+fallback*17)&255
   pointers=[START+i*16 if mask&(1<<i)else 0 for i in range(8)]
   for i,pointer in enumerate(pointers):n.pack('<I',0x93d5a0+i*16,pointer)
   n.pack('<B',O+0x280,rawslot);n.pack('<B',O+0x28d,fallback)
   selected=slot if 0<=slot<=7 else fallback
   expected=pointers[selected%8]or pointers[0]
   actual=n.call(0x55e300,[O]);check('startPositionPointer',actual,expected,rawslot*256+fallback,'return pointer');groups['startPositionPointer']+=1
   spawnOut.write(struct.pack('<BBH9I',rawslot,fallback,0,*pointers,actual))
 spawnOut.close()
 print('spawn selectors',dict(groups),flush=True)
 evidence=json.loads((BASE/'reports/animation-portable-contract.json').read_text())
 reset=next(x for x in evidence['functions']if x['address']=='0x41b420')
 callsites={int(x['address'],16):x['operands']for x in reset['instructions']if x['mnemonic']=='call'}
 trace=[]
 def observe(mu,address,size,unused):
  if address in callsites:trace.append({'callsite':hex(address),'target':callsites[address],'position':n.unpack('<fff',O+0x5c),'context':n.unpack('<b',O+0x7b5)[0],'deathState':n.unpack('<B',O+0x28b)[0]})
 hook=n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x41b420,end=0x41bb00)
 for case in range(1000):
  n.write(O,bytes(0x10000));n.pack('<I',0x802c54,W);n.pack('<I',O+0x50,M);n.pack('<I',O+0x54,C);n.pack('<I',C+0x24,G);n.pack('<II',M+8,D,A);n.pack('<I',O+0xca4,PAD)
  slot=rng.choice([-1,0,1,2,3,4,5,6,7]);fallback=rng.randrange(8);oldcontext=rng.choice([-1,21,43,90,95,96]);death=rng.randrange(3);mode=rng.choice([0,2,8,10])if slot>=0 else rng.choice([0,2]);health=rng.randrange(9);maximum=rng.randrange(1,9);defaulthealth=rng.randrange(1,9)
  n.pack('<b',O+0x280,slot);n.pack('<B',O+0x28d,fallback);n.pack('<b',O+0x7b5,oldcontext);n.pack('<B',O+0x28b,death);n.pack('<BB',O+0x107e,maximum,health);n.pack('<I',0x93b2ac,mode);n.pack('<B',0x802bd4,defaulthealth)
  n.pack('<I',O+0x1fc,0x1000|0x80 if slot>=0 else 0x1000);n.pack('<I',O+0xe20,rng.getrandbits(32));n.pack('<I',O+0xe24,rng.getrandbits(32));n.pack('<I',O+0xef0,rng.getrandbits(32)&~0x200000);n.pack('<I',O+0x1f8,rng.getrandbits(32));n.pack('<I',0x80253c,rng.randrange(65536))
  dims=[f32(rng.uniform(.1,2))for i in range(5)];dims[2]=-dims[2];n.pack('<fffff',C+0x2c,*dims);n.pack('<f',O+0x1004,1);n.pack('<f',O+0xff8,1)
  oldpos=[f32(rng.uniform(-50,50))for i in range(3)];explicit=[f32(rng.uniform(-50,50))for i in range(3)];n.pack('<fff',O+0x5c,*oldpos);n.pack('<fff',P,*explicit)
  pointers=[];positions=[];headings=[];mask=rng.randrange(256)
  for i in range(8):
   vec=[f32(rng.uniform(-50,50))for j in range(3)];pos=START+i*16;n.pack('<fff',pos,*vec);positions.append(vec);pointers.append(pos if mask&(1<<i)else 0);headings.append(rng.randrange(65536));n.pack('<I',0x93d5a0+i*16,pointers[-1]);n.pack('<H',0x93d5ac+i*16,headings[-1]);n.pack('<B',0x93d519+i*16,(case+i)%9);n.pack('<B',0x93d51b+i*16,(case+i)%2)
  useexplicit=case%3==0;selected=slot if slot>=0 else fallback;pointer=P if useexplicit else pointers[selected]or pointers[0];expectedpos=explicit if useexplicit else positions[selected]if pointers[selected]else positions[0]if pointers[0]else oldpos
  before=n.read(O,0x10d8);trace=[];n.call(0x41b420,[O,1,P if useexplicit else 0,case%2],count=1000000)
  if case<8:traces.append({'case':case,'slot':slot,'source':'explicit'if useexplicit else 'selected table'if pointer else 'unchanged position','calls':trace})
  for offset in [0x5c,0x8c,0x98,0x1b4,0x10bc]:check('fullReset',list(n.unpack('<fff',O+offset)),expectedpos,case,hex(offset)+' position')
  expectedcenter=list(expectedpos);expectedcenter[1]=f32(expectedpos[1]+(dims[2]+dims[3])*dims[4]*.5)
  check('fullReset',list(n.unpack('<fff',O+0x80)),expectedcenter,case,'0x80 predicted bounds center, not origin')
  for offset in [0x68,0xdf8,0x200]:check('fullReset',n.unpack('<fff',O+offset),(0,0,0),case,hex(offset)+' velocity/vector')
  for offset in [0x58,0x5a,0x27a]:check('fullReset',n.unpack('<H',O+offset)[0],headings[selected],case,hex(offset)+' heading')
  for offset in [0x281,0x282,0x28b,0x28c,0x1078,0x1079]:check('fullReset',n.unpack('<B',O+offset)[0],0,case,hex(offset)+' state')
  check('fullReset',n.unpack('<b',O+0x7b5)[0],-1,case,'context');check('fullReset',n.unpack('<h',O+0x42)[0],-1,case,'requested action with missing idle clip')
  expectedhealth=min(maximum,defaulthealth)if mode&2 or death!=0 or slot!=-1 and oldcontext==43 else health
  check('fullReset',n.unpack('<B',O+0x107f)[0],expectedhealth,case,'health')
  check('fullReset',n.unpack('<I',O+0x1f8)[0],struct.unpack_from('<I',before,0x1f8)[0]&~0x100,case,'api flag clear')
  check('fullReset',n.unpack('<f',O+0xff8)[0],1,case,'height scale')
  check('fullReset',n.unpack('<f',O+0xa8)[0],dims[4],case,'character scale')
  check('fullReset',n.unpack('<f',O+0xac)[0],f32(dims[1]*dims[4]),case,'radius')
  check('fullReset',n.unpack('<f',O+0xdc8)[0],0,case,'movement speed')
  check('fullReset',n.unpack('<f',O+0x218)[0],2000000,case,'height sentinel')
  check('fullReset',n.unpack('<f',O+0xc64)[0],-1,case,'reset timer sentinel')
  if mode&8:check('fullReset',n.unpack('<B',O+0xe39)[0],(case+slot)%9,case,'saved inventory value')
  elif mode&2 or death!=0 or slot!=-1 and oldcontext==43:check('fullReset',n.unpack('<B',O+0xe39)[0],4,case,'default inventory value')
  groups['fullReset']+=1
 n.mu.hook_del(hook)
except Exception as e:failures.append(str(e))
report={'binarySha256':n.sha256,'groups':dict(groups),'cases':sum(groups.values()),'checks':dict(checks),'mismatches':sum(mismatchCounts.values()),'mismatchCounts':dict(mismatchCounts),'examples':errors,'failures':failures,'method':'Original functions and original callees execute unmodified. No instruction, callback, OS or game process is replaced/launched. Assertions compare independent spawn/state formulas, not a second execution of the same code.','fullResetFixture':{'entry':'0x41b420','resetMoves':1,'model':'Valid character and model pointer arrays; all animation slots absent.','pad':'Valid 0x60-byte controller state at object+0xca4.','world':'Valid empty world; no scene, terrain, socket, light list, navigation or vehicle data.','varied':'1000 finite position, heading, dimensions, player/NPC, mode flags, death/context/health cases; explicit or native table-selected position, retain-position when neither exists.','coverage':'Selected position copies, predicted bounds center, velocity clear, heading assignment, ground/contact/context reset, health restoration, saved inventory, dimensions and common reset tail. Not a complete object-image equivalence proof.'},'trace':traces,'limits':['No loaded terrain/socket/portal scenario, special aircraft, suit, companion or nonempty idle animation.','Game-configurable callback 0x93d508 is null in the loaded image and fixture; registered callback behavior is not covered.','Original PC full-reset fixture succeeds; portable C# full respawn remains unimplemented.']}
(BASE/'reports/animation-respawn-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items()if k!='trace'},indent=2))
if errors or failures:raise SystemExit(1)
