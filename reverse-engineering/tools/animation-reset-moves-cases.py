"""Full-byte original 0x41af70 oracle for absent-idle/no-suit/no-companion branch."""
import importlib.util,struct,json,random,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
n=native.NativeX86();BASE=native.BASE;O=n.DATA;C=O+0x2000;G=O+0x3000;M=O+0x4000;A=O+0x5000;D=O+0x6000;PAD=O+0x7000;COIN=O+0x7100
SIZE=0x10d8;SUB=0x6c4;f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0];bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
def expected(before,pad,coin,seed,dims,distance):
 o=bytearray(before);pad=bytearray(pad);coin=bytearray(coin)
 def p(fmt,at,*v):struct.pack_into('<'+fmt,o,at,*v)
 def q(fmt,at):return struct.unpack_from('<'+fmt,o,at)[0]
 def r(fmt,at,*v):p(fmt,SUB+at,*v)
 def and32(at,mask):p('I',at,q('I',at)&mask)
 def rand():
  nonlocal seed
  seed=(seed*0x24cd+1)&65535
  return seed
 # Original 0x4148a0, argument is object+0x6c4.
 r('B',0x101,q('B',SUB+0x101)&0xfe)
 for at in [0x660,0x684]:r('I',at,0)
 for at in [0x754,0x756,0x758]:r('H',at,0)
 # Its original 0x55e4e0 callee.
 r('I',0xfc,0);r('B',0x100,255);r('f',0x678,1 if q('B',SUB+0x75e)&1 else 0);r('f',0x67c,5)
 for at in [0x76f,0xf5,0xf4,0xee,0x76e]:r('B',at,0)
 r('B',0xf1,255)
 for at in [0x66c,0x674,0x664,0x65c,0x648,0x694,0x698,0x670,0x6d0,0x6e8,0x700,0x714,0x720,0x724,0x60c]:r('I',at,0)
 r('B',0x77d,rand()>>15);r('H',0xe8,0)
 for at in [0x74c,0x750,0x752]:r('H',at,65535)
 # Controller clear combines 0x55e4e0 and 0x4148a0 flag masks.
 for at in [4,8,12,16,20,24,28,32,0x40,0x44,0x48,0x4c,0x54]:struct.pack_into('<I',pad,at,0)
 struct.pack_into('<H',pad,0x5a,struct.unpack_from('<H',pad,0x5a)[0]&0xffe9)
 and32(SUB+0x75c,0xfffffbff);r('I',0x65c,0)
 # Original 0x589f60 writes five sentinel fields in this same substructure.
 for at in [4,0x18,0x2c,0x40,0x54]:r('f',at,2000000)
 for at in [0x614,0x618,0x61c,0x620,0x624,0x628,0x62c,0x630,0x6b8,0x6d8]:r('I',at,0)
 # Original 0x4a4ca0.
 for at in [0x6bc,0x6c0,0x650,0x6cc,0x654]:r('I',at,0)
 r('f',0x6c4,.2);and32(SUB+0x75c,0xfffffffe);r('f',0x6dc,2000000)
 for at in [0x72c,0x6ec,0x708,0x70c,0x604,0x710,0x718,0x690,0x688,0x784]:r('I',at,0)
 for at in [0x75a,0x74c]:r('H',at,65535)
 r('H',0x74e,79 if rand()>32767 else 38)
 for at in range(0x764,0x768):r('B',at,(rand()>>8)&255)
 and32(SUB+0x760,0xfffff3fe);r('B',0x77f,255);r('fff',0x5d4,0,1,0)
 # Remainder of 0x41af70. All clips absent forces default idle action1.
 p('I',0x103c,0);p('fff',0x200,0,0,0);p('I',0xd60,0);p('f',0xda4,distance);p('I',0xef0,q('I',0xef0)|0x80)
 p('I',0x2bc,0);p('H',0x2c4,1);p('f',0x2c0,rand()*n.unpack('<d',0x751700)[0]*7+8);p('I',0x2b8,0);p('H',0x2c6,65535)
 for at in [8,12,0x1c]:p('f',at,1)
 for at in [0x3e,0x40,0x42,0x4a]:p('H',at,65535)
 for at in [0x39,0x46,0x44,0x45,0x281,0x282]:p('B',at,0)
 p('B',0x38,4)
 base,radius,bottom,top,scale=dims
 p('f',0xa8,scale);p('f',0xffc,radius);p('f',0xff0,bottom);p('f',0xff4,top)
 p('f',0xa4,base*scale);p('f',0xac,radius*scale);p('f',0xb0,q('f',0xac)*q('f',0x1004));p('f',0xb4,(top-bottom)*q('f',0xff8))
 and32(0xe24,0xfff8ffff);p('I',0x1000,0);p('I',0x1018,0)
 if q('I',0x7fc):coin[10]=1;struct.pack_into('<f',coin,4,1);struct.pack_into('<I',coin,12,0)
 and32(0x1fc,0xffffdfff);p('I',0x1d8,0);p('fff',0xe94,0,0,0)
 return bytes(o),bytes(pad),bytes(coin),seed

rng=random.Random(0x41af70);total=1200;errors=[];mismatches=0;failures=[];target=BASE/'reports/animation-reset-moves-cases.bin'
with target.open('wb')as out:
 out.write(b'ARSMV001'+struct.pack('<I',total))
 for case in range(total):
  before=bytearray(rng.randbytes(SIZE));pad=rng.randbytes(96);coin=rng.randbytes(16);seed=rng.randrange(65536);enabled=rng.randrange(2);distance=f32(rng.uniform(.1,3));dims=[f32(rng.uniform(.1,2))for i in range(5)];dims[2]=-dims[2]
  struct.pack_into('<II',before,0x50,M,C);struct.pack_into('<I',before,0xca4,PAD);struct.pack_into('<II',before,0xcbc,0,0);struct.pack_into('<I',before,0x7fc,COIN if enabled else 0);struct.pack_into('<ff',before,0x1004,rng.uniform(0,2),0);struct.pack_into('<f',before,0xff8,rng.uniform(.1,2))
  n.write(O,before);n.write(PAD,pad);n.write(COIN,coin);n.write(C,bytes(0x100));n.write(G,bytes(0x200));n.write(A,bytes(0x400));n.write(D,bytes(0x400));n.pack('<I',C+0x24,G);n.pack('<II',M+8,D,A);n.pack('<fffff',C+0x2c,*dims);n.pack('<I',0x80253c,seed);n.pack('<f',0x802be8,distance)
  try:n.call(0x41af70,[O])
  except Exception as e:failures.append({'case':case,'error':str(e)});break
  actual=(n.read(O,SIZE),n.read(PAD,96),n.read(COIN,16),n.unpack('<I',0x80253c)[0]);want=expected(before,pad,coin,seed,dims,distance)
  if actual!=want:
   mismatches+=1
   if len(errors)<12:
    differences=[{'buffer':name,'offset':hex(i),'actual':a,'expected':b}for name,aa,bb in zip(['object','pad','coin'],actual[:3],want[:3])for i,(a,b)in enumerate(zip(aa,bb))if a!=b]
    errors.append({'case':case,'differences':differences[:12],'actualRng':actual[3],'expectedRng':want[3]})
  out.write(struct.pack('<8I',seed,bits(distance),*[bits(v)for v in dims],enabled));out.write(before);out.write(actual[0]);out.write(pad);out.write(actual[1]);out.write(coin);out.write(actual[2]);out.write(struct.pack('<I',actual[3]))
report={'binarySha256':n.sha256,'entry':'0x41af70','cases':total-len(failures),'mismatches':mismatches,'failures':failures,'examples':errors,'scope':'Entire original ResetPlayerMoves with all animation pointers absent, no suit/companion, valid pad and optional coin. 1200 random full object images, controller bytes, coin bytes, RNG and dimensions. No code/callback replacements.','comparison':'All4312 object bytes,96 pad bytes,16 coin bytes,final RNG against independent source reconstruction.','caseFile':str(target.relative_to(BASE)),'caseFileSha256':hashlib.sha256(target.read_bytes()).hexdigest(),'limits':['Idle clip present and companion/suit branches are outside this contract.','Portable C# comparison still requires permitted harness execution.']}
(BASE/'reports/animation-reset-moves-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps(report,indent=2))
if failures or mismatches:raise SystemExit(1)
