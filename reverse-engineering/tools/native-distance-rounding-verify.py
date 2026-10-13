import importlib.util,json,struct,random,math
from pathlib import Path
from fractions import Fraction as F
s=importlib.util.spec_from_file_location('culling',Path(__file__).with_name('native-locator-culling-verify.py'));v=importlib.util.module_from_spec(s);s.loader.exec_module(v);n=v.n;B=v.B;D=n.DATA
rows=[];errors=[]
def store(x):
 x=F(x)
 if not x:return 0.
 sign=-1 if x<0 else 1;x=abs(x);num,den=x.numerator,x.denominator;e=num.bit_length()-den.bit_length()
 if (F(2)**e)>x:e-=1
 step=max(-149,e-23)
 if step>=0:den <<=step
 else:num <<= -step
 q,r=divmod(num,den)
 if 2*r>den or 2*r==den and q&1:q+=1
 return sign*math.ldexp(q,step)
def run(a,b,xz):
 a=[v.f(x) for x in a];b=[v.f(x) for x in b];n.write(D,bytes(0x80));n.pack('<3f',D,*a);n.pack('<3f',D+0x10,*b);n.pack('<3I',D+0x20,0xa5a5a5a5,0xa5a5a5a5,0xa5a5a5a5);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',D+0x30));n.call(0x5b3cf0 if xz else 0x5b3c50,[D,D+0x10,D+0x20]);n.mu.emu_start(n.STOP,n.STOP+6)
 d=[store(F(x)-F(y)) for x,y in zip(a,b)];mathd=[d[0],0. if xz else d[1],d[2]];want=v.bits(store(v.add(v.add(v.mul(mathd[0],mathd[0]),v.mul(mathd[1],mathd[1])),v.mul(mathd[2],mathd[2]))));got=n.unpack('<I',D+0x30)[0]
 scratch=list(n.unpack('<3I',D+0x20));expect=[v.bits(x) for x in d]
 if xz:expect[1]=0
 if got!=want or scratch!=expect:errors.append(dict(a=a,b=b,xz=xz,got=got,want=want,scratch=scratch,expectedScratch=expect))
 rows.append(dict(a=a,b=b,xz=xz,native=got,scratch=scratch))
def main():
 for xz in [False,True]:
  for a,b in [([1.,2**-12,2**-27],[0.,0.,0.]),([1.,0.,2**-12],[0.,0.,2**-40]),([0.,0.,0.],[0.,0.,0.]),([2**-149,2**-149,2**-149],[0.,0.,0.])]:run(a,b,xz)
 rng=random.Random(532640)
 for i in range(4096):
  a=[math.ldexp(v.f(rng.uniform(-2,2)),rng.randrange(-80,30)) for _ in range(3)];b=[math.ldexp(v.f(rng.uniform(-2,2)),rng.randrange(-80,30)) for _ in range(3)];run(a,b,bool(i%2))
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),examples=errors[:8],addresses=['0x5b3c50','0x5b3cf0'],counterexample=dict(input=[1.,2**-12,2**-27],squaredDistanceBits=rows[0]['native'],oldDoubleBits=v.bits(v.f(1.+2**-24+2**-54)),implication='Range-boundary branches can change, as independently observed in447f00.'),method='Original nonnull scratch distance helpers; returned x87 value capturedtofloat32 plus exact scratch bytes. Reference uses rational64-significand operations and direct integer roundingtofloat32 without intermediate binary64 conversion.',limits=['Finite inputs/differences/squared distance; nonnull nonoverlapping scratch. Null-output ABI remains excluded.','Compiled replay pending; no new native mapping count.'])
 (B/'reports/native-distance-rounding-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-distance-rounding-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
