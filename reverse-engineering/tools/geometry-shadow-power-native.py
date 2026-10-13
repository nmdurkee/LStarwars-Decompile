"""Actual PC power cache with original CRT; cache model has explicit math boundary."""
import importlib.util,json,struct,gzip,hashlib,random,collections,math
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
P=n.DATA;OUT=P+0x100;BASE=0x95e400;SIZE=0x250;FLAG=0x8066c4
VALUES=0x148;EXPONENTS=0x40;RESULTS=0xc0;NEXT=0x244
# Fixture-only caller pushes two cdecl arguments and stores native ST0 to float32.
n.write(P,b'\xff\x74\x24\x08'*2+b'\xe8'+struct.pack('<i',0x5be630-(P+13))+b'\xd9\x1d'+struct.pack('<I',OUT)+b'\x83\xc4\x08\xc3')
bits=lambda f:struct.unpack('<I',struct.pack('<f',f))[0]
value=lambda w:struct.unpack('<f',struct.pack('<I',w))[0]
u=lambda b,p:struct.unpack_from('<I',b,p)[0]
put=lambda b,p,w:struct.pack_into('<I',b,p,w)
observed=[]
def hook(uc,address,size,user):
 if address in (0x6e9040,0x6e8fac):observed.append(hex(address))
n.mu.hook_add(UC_HOOK_CODE,hook,begin=0x6e8fac,end=0x6e9040)
cases=[];counts=collections.Counter();rng=random.Random(0x5be630)
def initial(index,flag=0,next_slot=0):
 b=bytearray((j*37+index*19)&255 for j in range(SIZE))
 for j in range(32):
  put(b,VALUES+j*4,bits(10+j));put(b,EXPONENTS+j*4,bits(-20-j));put(b,RESULTS+j*4,bits((j-16)*.25))
 put(b,NEXT,next_slot)
 return flag,b
def execute(kind,before,input_word,exponent_word):
 flag,raw=before;raw=bytearray(raw);expected=bytearray(raw);expected_flag=flag
 a=value(input_word);exponent=value(exponent_word);slot=None
 if a==0:branch='zero';expected_word=0
 else:
  if flag:
   expected_flag=0
   for i in range(32):put(expected,VALUES+4*i,0x7f7fffff)
  for i in range(32):
   if a==value(u(expected,VALUES+4*i)) and exponent==value(u(expected,EXPONENTS+4*i)):slot=i;break
  branch='hit' if slot is not None else 'miss'
  if branch=='hit':expected_word=u(expected,RESULTS+4*slot)
 observed.clear();n.write(BASE,raw);n.pack('<I',FLAG,flag);n.pack('<I',0x29a9c44,0)
 n.call(P,[input_word,exponent_word],count=1000000);native_word=n.unpack('<I',OUT)[0];native_flag=n.unpack('<I',FLAG)[0];actual=n.read(BASE,SIZE)
 if branch=='miss':
  # Deliberate backend seam: original CRT result is supplied to cache model.
  expected_word=native_word;slot=u(expected,NEXT);assert slot<32
  put(expected,VALUES+4*slot,input_word);put(expected,EXPONENTS+4*slot,exponent_word);put(expected,RESULTS+4*slot,native_word);put(expected,NEXT,(slot+1)&31)
 wanted_calls=['0x6e9040','0x6e8fac'] if branch=='miss' else []
 assert actual==expected and native_flag==expected_flag and native_word==expected_word and observed==wanted_calls,dict(kind=kind,index=len(cases),branch=branch,slot=slot,got=native_word,want=expected_word,calls=observed,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:12])
 assert math.isfinite(value(native_word))
 digest=hashlib.sha256(struct.pack('<I',native_flag)+actual).hexdigest()
 cases.append(dict(kind=kind,branch=branch,flag=flag,before=bytes(raw).hex(),valueWord=input_word,exponentWord=exponent_word,resultWord=native_word,backendCalls=int(branch=='miss'),nativeSHA256=digest))
 counts['cases']+=1;counts[branch]+=1;counts[kind]+=1;counts['persistentBytes']+=SIZE+4
 return native_flag,bytearray(actual)
# Zero bypasses even invalid ring cursor, pending initialization and nonfinite exponent.
for flag in [0,1,0xffffffff]:
 for v in [0,0x80000000]:
  for exponent in [0,0x80000000,bits(3),0x7fc12345,0xffc54321,0x7f800000,0xff800000]:execute('zero-bypass',initial(len(cases),flag,0xdeadbeef),v,exponent)
# Every linear hit position, duplicate first match, signed exponent equality.
for slot in range(32):
 for negative in [False,True]:
  flag,b=initial(len(cases),0,0xdeadbeef);a=-.75 if negative else .75
  put(b,VALUES+slot*4,bits(a));put(b,EXPONENTS+slot*4,0x80000000);put(b,RESULTS+slot*4,0x80000000 if slot%2 else bits(slot+.125))
  if slot<31:put(b,VALUES+(slot+1)*4,bits(a));put(b,EXPONENTS+(slot+1)*4,0);put(b,RESULTS+(slot+1)*4,bits(999))
  execute('ordered-hit', (flag,b),bits(a),0)
# Initialization creates genuine stale-result hits for Float32.MaxValue.
for slot in range(32):
 flag,b=initial(len(cases),0xffffffff,(slot+7)&31);put(b,EXPONENTS+slot*4,bits(3));put(b,RESULTS+slot*4,bits(slot+.5))
 execute('initialization-stale-hit',(flag,b),0x7f7fffff,bits(3))
# Every ring slot, with and without initialization. CRT stays original.
for slot in range(32):
 for flag in [0,1]:execute('ring-miss',initial(len(cases),flag,slot),bits((slot+1)/33),bits(3))
# Finite negative cache keys are legal hits; NaN cache keys never compare equal.
for slot in range(32):
 for matching_base in [False,True]:
  flag,b=initial(len(cases),0,slot)
  for i in range(32):put(b,VALUES+4*i,bits(.5) if matching_base else 0x7fc10000+i);put(b,EXPONENTS+4*i,0x7fc20000+i)
  execute('nan-slot-miss',(flag,b),bits(.5),bits(slot/16))
# Stateful eviction, wrap, hits with result signs preserved and varied exponents.
state=initial(77,1,27);history=[]
for i in range(1024):
 if i%5==4 and history:a,e=history[-1]
 else:
  a=bits((rng.randrange(1,4096))/4096);e=bits(rng.choice([-8,-3,-1,0,1,2,3,8])+rng.choice([0,.125,.5]));history.append((a,e))
 state=execute('stateful-sequence',state,a,e)
fp=R/'geometry-shadow-power-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(cacheBase=BASE,cacheBytes=SIZE,flagAddress=FLAG,valueOffset=VALUES,exponentOffset=EXPONENTS,resultOffset=RESULTS,nextOffset=NEXT,cases=cases),separators=(',',':')).encode(),mtime=0))
report=dict(schema='geometry-shadow-power-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Actual5be630 and actualCRT6e9040/6e8fac execute unchanged; a fixture-only caller stores ST0 tofloat32. CRT policy29a9c44=0.', 'Cache model takes original storedfloat32 missresult as explicit mathematical backend; cache, mutation, ordering and invocation counts are verified, not independently reconstructed transcendental equivalence.', 'Zero inputs bypass state/exponent; nonzero inputs finite, misses positive, finite returned results. Arbitrary quietNaN cache keys are ignored. No claim about negative-miss CRT behavior or signalingNaN results.', 'Initialization clears only32basewords to7f7fffff; ringcursor/exponents/results retained. Rings0..31 onmiss; invalid cursors tested only zero/hit branches where notread.', 'Stateful1024calls cover ringwrap and eviction; all32linearhit/ringpositions, staleinitializationhits, signedzeros and firstduplicate precedence included.', 'Persistent byte totals cover cache region+initflag, not internal CRT globals. Portable compiled execution remains pending.'])
(R/'geometry-shadow-power-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
