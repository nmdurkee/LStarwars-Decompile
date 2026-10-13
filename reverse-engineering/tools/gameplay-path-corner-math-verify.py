"""Finite3D line parameters and16-bit angle wrapping used by path corners."""
import importlib.util,json,struct,random,itertools,math
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
x=load('native','native-x86.py');wide=load('wide','animation-x87.py');n=x.NativeX86();BASE=x.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def f(v):return fl(bits(v))
class W:
 def __init__(self,v):self.exact=wide.wide(v);self.approx=v
 @staticmethod
 def make(e,a):v=W(0);v.exact=e;v.approx=a;return v
 def __add__(self,b):return W.make(wide.add(self.exact,b.exact),self.approx+b.approx)
 def __sub__(self,b):return W.make(wide.add(self.exact,(-b.exact[0],b.exact[1])),self.approx-b.approx)
 def __mul__(self,b):return W.make(wide.mul(self.exact,b.exact),self.approx*b.approx)
 def __truediv__(self,b):return W.make(wide.div(self.exact,b.exact),self.approx/b.approx)
 def store(self):
  s=wide.store(self.exact);return fl(0x80000000 if math.copysign(1,self.approx)<0 else 0) if s==0 else s
def model(p,d,q,e):
 d=list(map(W,d));e=list(map(W,e));cross=[W((d[1]*e[2]-d[2]*e[1]).store()),W((d[2]*e[0]-d[0]*e[2]).store()),W((d[0]*e[1]-e[0]*d[1]).store())];cx,cy,cz=cross;length=f(math.sqrt((cy*cy+cx*cx+cz*cz).store()));inverse=0. if length==0 else (W(1)/W(length)).store();scale=W((W(inverse)*W(inverse)).store());dx,dy,dz=[W((W(a)-W(b)).store()) for a,b in zip(q,p)];first=W(((e[1]*cz-e[2]*cy)*dx-dy*(cz*e[0]-cx*e[2])+dz*(cy*e[0]-cx*e[1])).store());second=W(((cz*d[1]-cy*d[2])*dx-(d[0]*cz-cx*d[2])*dy+dz*(cy*d[0]-d[1]*cx)).store());return int(scale.store()!=0),bits((first*scale).store()),bits((second*scale).store())
cases=[];errors=[];counts={};executed=set();ranges=[(0x5bee20,0x5befef),(0x5be590,0x5be5ac),(0x5be5b0,0x5be5ca)]
for a,end in ranges:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=a,end=end-1)
def run(p,d,q,e):
 vectors=[[f(v) for v in row] for row in [p,d,q,e]]
 for i,row in enumerate(vectors):n.pack('<3f',D+i*0x20,*row)
 n.pack('<II',D+0x100,0xdeadbeef,0xabcdef01);value=n.call(0x5bee20,[D,D+0x20,D+0x40,D+0x60,D+0x100,D+0x104]);got=[value,*n.unpack('<II',D+0x100)];want=list(model(*vectors));cases.append(dict(kind='lines',vectors=[[bits(v) for v in row] for row in vectors],native=got));counts['lines']=counts.get('lines',0)+1
 if got!=want:errors.append(dict(vectors=vectors,got=got,want=want))
def angle(a,b,kind):
 native=n.call(0x5be590 if kind=='add' else 0x5be5b0,[a,b]);want=((a+b if kind=='add' else a-b)+32768)%65536-32768;want&=0xffffffff;cases.append(dict(kind=kind,input=[a,b],native=native));counts[kind]=counts.get(kind,0)+1
 if native!=want:errors.append(cases[-1]|dict(want=want))
def main():
 directions=[[0,0,0],[1,0,0],[0,1,0],[0,0,1],[1,1,1],[-1,0,0],[1,0,.00001],[1,.00001,0]]
 for d,e,p,q in itertools.product(directions,directions,[[0,0,0],[1,2,3]],[[0,0,0],[2,-1,3]]):run(p,d,q,e)
 rng=random.Random(0x5bee20)
 for i in range(4096):run(*[[f(rng.uniform(-100,100)) for _ in range(3)] for _ in range(4)])
 for a,b in itertools.product([0,1,0x7fff,0x8000,0xffff,0x10000,0xffffffff],repeat=2):angle(a,b,'add');angle(a,b,'subtract')
 for i in range(1024):
  a,b=rng.randrange(2**32),rng.randrange(2**32);angle(a,b,'add');angle(a,b,'subtract')
 assembly=[]
 for a,end in ranges:
  ins=[]
  for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,end-a),a):
   if i.mnemonic=='int3':break
   ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed))
  assembly.append(dict(address=hex(a),endExclusive=hex(int(ins[-1]['address'],16)+len(bytes.fromhex(ins[-1]['bytes']))),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=len(cases),counts=counts,mismatches=len(errors),examples=errors[:5],instructionCoverage=dict(total=sum(len(s['instructions']) for s in assembly),executed=sum(i['executed'] for s in assembly for i in s['instructions']),missing=[i['address'] for s in assembly for i in s['instructions'] if not i['executed']]))
 (BASE/'reports/gameplay-path-corner-math-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-corner-math-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-corner-math-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,ranges=assembly),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
