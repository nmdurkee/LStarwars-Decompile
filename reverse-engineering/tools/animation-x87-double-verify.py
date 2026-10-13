"""Isolated original FSTP qword instruction with explicit finite x87 inputs."""
from pathlib import Path
import importlib.util,struct,json,random,hashlib
B=Path(__file__).resolve().parent.parent
def module(name,path):
 s=importlib.util.spec_from_file_location(name,B/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
x=module('double_wide','tools/animation-x87.py');nx=module('double_native','tools/native-x86.py');n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_FP0,UC_X86_REG_FPTAG,UC_X86_REG_EIP
n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:mu.reg_write(UC_X86_REG_EIP,n.STOP),begin=0x603657,end=0x603657)
def bits(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def value(v):return struct.unpack('<d',struct.pack('<Q',v))[0]
def stored(a):
 sig,e=a
 if not sig:return 0
 sign=0x8000000000000000 if sig<0 else 0;sig=abs(sig);raw=e+1086;q=x.rounded(sig,1<<(11+max(0,1-raw)))
 if raw<=0:return sign|q
 if q==1<<53:q>>=1;raw+=1
 return sign|(0x7ff0000000000000 if raw>=2047 else(raw<<52)|(q&0xfffffffffffff))
rng=random.Random(0x603653);cases=[];errors=[]
def check(op,a,b):
 wa=x.wide(a);wb=x.wide(b);wide=wa if op==0 else x.add(wa,wb)if op==1 else x.mul(wa,wb);sig,e=wide;se=0 if not sig else(e+63+16383)|(0x8000 if sig<0 else 0)
 n.call(0x603653,regs={UC_X86_REG_FP0:(abs(sig),se),UC_X86_REG_FPTAG:0xfffc});actual=n.unpack('<Q',n.STACK+0xe000+0x1c)[0];expected=stored(wide);row=dict(op=op,a=bits(a),b=bits(b),wideSignificand=str(sig),wideExponent=e,nativeBits=actual);cases.append(row)
 if actual!=expected:errors.append(dict(row,expected=expected))
edges=[0,0x8000000000000000,1,0x8000000000000001,0xfffffffffffff,0x10000000000000,0x3fefffffffffffff,0x3ff0000000000000,0x3ff0000000000001,0x7fefffffffffffff,0xffefffffffffffff]
for v in edges:
 for b in[0.,.5,1.,2.,-1.]:
  for op in[0,1,2]:check(op,value(v),b)
for sign in[-1,1]:
 for exponent in[-1074,-1022,-100,-53,-52,0,53,100,1023]:
  a=sign*2.**exponent
  for e in[-66,-65,-64,-63,-54,-53,-52,-51]:
   for delta in[-1.,0.,1.]:
    b=(2.**(exponent+e))*(1.+delta*2.**-23)if exponent+e>=-1074 else 0.
    check(1,a,b)
for i in range(1024):
 words=[rng.getrandbits(64)for _ in range(2)];words=[w if(w>>52)&2047!=2047 else w^(1<<52)for w in words]
 check(i%3,value(words[0]),value(words[1]))
out=B/'reports/animation-x87-double-tests.json';report=dict(binarySha256=n.sha256,instruction=dict(address='0x603653',bytes=n.read(0x603653,4).hex(),operation='fstp qword ptr [esp+0x1c]'),comparisons=len(cases),mismatches=len(errors),examples=errors[:10],cases=cases,method='Execute the unchanged original qword-store instruction with explicit finite80-bit FP0 input and stop before the next instruction. Input values are generated with the existing independently checked wide model; this isolates double-store rounding, not original evaluation of the generating arithmetic.',limits=['Exact zero has the shared representation positive sign. Nonzero underflow preserves sign; overflow follows native masked-exception infinity storage.','This is instruction-level support evidence, not a newly recovered native function. Managed replay is prepared separately and not executed.']);out.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['comparisons','mismatches','examples']}));assert not errors
