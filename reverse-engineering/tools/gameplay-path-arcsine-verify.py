"""Finite512900 approximate arcsine, exact polynomial ordering and native sqrt."""
import importlib.util,json,struct,math,random
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
x=load('native','native-x86.py');w=load('wide','animation-x87.py');n=x.NativeX86();BASE=x.BASE
from unicorn import UC_HOOK_CODE
executed=set();n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,s,u:executed.add(a),begin=0x512900,end=0x512a3f)
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def f(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
W=w.wide;A=w.add;M=w.mul;S=w.store
constants={hex(a):dict(bytes=n.read(a,8).hex(),value=n.unpack('<d',a)[0]) for a in [0x751738,0x751740,0x751748,0x751750,0x751758,0x751760,0x751770,0x751778,0x751780]}
def trunc(v):
 m,e=v;result=abs(m)<<e if e>=0 else abs(m)>>-e;return -result if m<0 else result
def model(value):
 x=W(value);scale=W(constants['0x751778']['value']);root=f(math.sqrt(max(0.,S(A(W(1),M(W(-1),M(x,x)))))));minimum=min(root,abs(value));clamp=lambda x:max(-1.,min(1.,S(x)))
 b=clamp(M(A(W(abs(value)),W(-constants['0x751780']['value'])),scale));c=clamp(M(x,scale));bc=M(W(b),W(c));t=M(W(minimum),bc);t2=M(t,t);t3=M(t2,t);t4=M(t2,t2);d=S(A(W(c),bc))
 total=A(M(W(d),W(constants['0x751760']['value'])),M(W(-1),t));total=A(total,M(M(W(constants['0x751758']['value']),t),t2));total=A(total,M(M(W(constants['0x751750']['value']),t2),t3));total=A(total,M(M(W(constants['0x751748']['value']),t3),t4));total=A(total,M(M(W(constants['0x751740']['value']),t4),M(t2,t3)));return trunc(M(total,W(constants['0x751738']['value'])))
def main():
 values=set(bits(f(i/8192)) for i in range(-8192,8193));rng=random.Random(0x512900)
 for _ in range(4096):values.add(bits(f(rng.uniform(-1,1))))
 for center in [0,1,0x007fffff,0x00800000,0x3f3504f3,0x3f800000]:
  for delta in range(-16,17):
   word=center+delta
   if 0<=word<=0x3f800000:values.add(word);values.add(word|0x80000000)
 vectors=[];errors=[]
 for word in sorted(values):
  value=fl(word);native=n.call(0x512900,[word]);native=native if native<2**31 else native-2**32;expected=model(value)
  if native!=expected:errors.append(dict(word=word,native=native,expected=expected))
  vectors.append([word,native])
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x512900,0x140),0x512900)]
 report=dict(binarySha256=n.sha256,checks=len(vectors),mismatches=len(errors),examples=errors[:5],constants=constants,instructionCoverage=dict(total=len(instructions),executed=sum(i['executed'] for i in instructions),missing=[i['address'] for i in instructions if not i['executed']]),method='Original512900 executes actual5c0240 and CRT float-to-integer tail6e6b90. Independent ordered64-significand model uses exact PC constants; finite[-1,1] domain, uniform grid plus random and subnormal/threshold neighborhoods.')
 (BASE/'reports/gameplay-path-arcsine-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-arcsine-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-arcsine-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,address='0x512900',endExclusive='0x512a40',instructions=instructions),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
