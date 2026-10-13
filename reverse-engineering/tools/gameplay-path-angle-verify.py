"""Original table-angle helpers used by moving path points; no atan substitution."""
import importlib.util,json,struct,random
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
x=load('native','native-x86.py');w=load('wide','animation-x87.py');n=x.NativeX86();BASE=x.BASE
from unicorn import UC_HOOK_CODE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
W=w.wide;M=w.mul;V=w.div;S=w.store
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def f(v):return fl(bits(v))
def trunc(v):
 m,e=v;r=abs(m)<<e if e>=0 else abs(m)>>-e;return -r if m<0 else r
TABLE=struct.unpack('<513H',n.read(0x8066c8,1026));SCALE=n.unpack('<d',0x75bfd0)[0];BACK=n.unpack('<d',0x755d18)[0]
def quadrant(a,b):
 return 0x4000-TABLE[trunc(V(M(W(b),W(512)),W(a)))] if b<a else TABLE[trunc(V(M(W(a),W(512)),W(b)))]
def direction(a,b):
 if a==0:return 0x8000 if b<0 else 0
 if b==0:return 0xc000 if a<0 else 0x4000
 q=quadrant(abs(a),abs(b))
 return q+0x8000 if a<0 and b<0 else -q if a<0 else 0x8000-q if b<0 else q
def radians(a,b):return S(M(W(direction(a,b)),W(SCALE)))
def heading(a,b):return trunc(M(W(radians(a,b)),W(BACK)))&65535
executed=set();ranges=[(0x5be030,0x5be079),(0x5be2d0,0x5be3a7),(0x5bfe00,0x5bfe32)]
for a,b in ranges:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=a,end=b-1)
n.write(n.DATA,b'\xff\x74\x24\x08'*2+b'\xe8'+struct.pack('<i',0x5bfe00-(n.DATA+13))+b'\xd9\x1d'+struct.pack('<I',n.DATA+0x100)+b'\x83\xc4\x08\xc3')
def native_float(a,b):
 # A tiny fixture caller stores the native ST0 result; the helper is unchanged.
 n.call(n.DATA,[bits(a),bits(b)]);return n.unpack('<I',n.DATA+0x100)[0]
def main():
 records=[];errors=[];counts={'quadrant':0,'direction':0,'radians':0}
 pairs=set()
 for i in range(513):
  for word in range(max(0,bits(f(i/512))-2),bits(f(i/512))+3):
   value=fl(word)
   if value<=1:
    for scale in [1,128,.00390625]:pairs.add((bits(f(value*scale)),bits(f(scale))))
 rng=random.Random(0x5be030)
 for _ in range(2048):pairs.add((bits(f(rng.uniform(.0001,1e8))),bits(f(rng.uniform(.0001,1e8)))))
 for a,b in sorted(pairs):
  aa,bb=fl(a),fl(b);native=n.call(0x5be030,[a,b])&65535;want=quadrant(aa,bb);records.append(['quadrant',a,b,native]);counts['quadrant']+=1
  if native!=want:errors.append(records[-1]+[want])
 signed=set()
 for a,b in list(sorted(pairs))[::7]:
  for sa in [0,0x80000000]:
   for sb in [0,0x80000000]:signed.add((a^sa,b^sb));signed.add((b^sa,a^sb))
 for a in [0,0x80000000,1,0x80000001,0x3f800000,0xbf800000]:
  for b in [0,0x80000000,1,0x80000001,0x3f800000,0xbf800000]:signed.add((a,b))
 for a,b in sorted(signed):
  aa,bb=fl(a),fl(b)
  for kind in ['direction','radians']:
   if kind=='direction':native=n.call(0x5be2d0,[a,b]);want=direction(aa,bb)&0xffffffff
   else:native=native_float(aa,bb);want=bits(radians(aa,bb))
   counts[kind]+=1;records.append([kind,a,b,native])
   if native!=want:errors.append(records[-1]+[want])
 assembly=[]
 for a,b in ranges:
  ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,b-a),a)]
  assembly.append(dict(address=hex(a),endExclusive=hex(b),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=len(records),counts=counts,mismatches=len(errors),examples=errors[:10],constants=dict(radiansScale=SCALE,headingScale=BACK,ratioScale=512),instructionCoverage=dict(total=sum(len(r['instructions']) for r in assembly),executed=len(executed),missing=[i['address'] for r in assembly for i in r['instructions'] if not i['executed']]))
 (BASE/'reports/gameplay-path-angle-table.u16').write_bytes(struct.pack('<513H',*TABLE));(BASE/'reports/gameplay-path-angle-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-angle-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,table=list(TABLE),cases=records),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-angle-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,ranges=assembly),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
