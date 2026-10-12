"""Emulate the observed PC stick-transform bytes; never launch the game process."""
import sys, struct, json, hashlib, math, random
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent
sys.path.insert(0,str(BASE/'tools/python-packages'))
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UC_HOOK_MEM_INVALID
from unicorn.x86_const import *
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
blob=(BASE/'binary/LEGOStarWarsSaga.packed.exe.unpacked.exe').read_bytes()
def u16(o): return struct.unpack_from('<H',blob,o)[0]
def u32(o): return struct.unpack_from('<I',blob,o)[0]
p=u32(0x3c); opt=p+24; imagebase=u32(opt+28); size=u32(opt+56)
mu=Uc(UC_ARCH_X86,UC_MODE_32); mu.mem_map(imagebase,(size+4095)&~4095)
mu.mem_write(imagebase,blob[:u32(opt+60)])
for i in range(u16(p+6)):
 q=opt+u16(p+20)+40*i; rva,rawsize,rawoff=u32(q+12),u32(q+16),u32(q+20)
 if rawsize: mu.mem_write(imagebase+rva,blob[rawoff:rawoff+rawsize])
STACK=0x10000000;DATA=0x10010000;STOP=0x10020000
mu.mem_map(STACK,0x10000);mu.mem_map(DATA,0x1000);mu.mem_map(STOP,0x1000)
mu.reg_write(UC_X86_REG_FPCW,0x37f);mu.reg_write(UC_X86_REG_FPSW,0);mu.reg_write(UC_X86_REG_FPTAG,0xffff)
context=mu.context_save();md=Cs(CS_ARCH_X86,CS_MODE_32);trace=[]
def hook(uc,address,size,user):
 trace.append(hex(address))
 if len(trace)>200:trace.pop(0)
trace_hook=mu.hook_add(UC_HOOK_CODE,hook)
def run(x,y):
 mu.context_restore(context);mu.mem_write(DATA,struct.pack('<hh',x,y));sp=STACK+0xf000
 mu.mem_write(sp,struct.pack('<III',STOP,DATA,DATA+2));mu.reg_write(UC_X86_REG_ESP,sp)
 try:mu.emu_start(0x6d4880,STOP,count=10000)
 except UcError as e:
  code=[]
  for a in trace[-16:]:
   address=int(a,16)
   try:
    ins=next(md.disasm(mu.mem_read(address,16),address));code.append(f'{a}: {ins.mnemonic} {ins.op_str}')
   except Exception:code.append(a)
  raise RuntimeError(str(e)+' at '+hex(mu.reg_read(UC_X86_REG_EIP))+'\n'+'\n'.join(code))
 if mu.reg_read(UC_X86_REG_EIP)!=STOP:raise RuntimeError('Instruction limit reached')
 return struct.unpack('<hh',mu.mem_read(DATA,4))
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def reconstructed(x,y):
 maximum=max(abs(x),abs(y));magnitude=f32(math.sqrt(f32(x*x+y*y)))
 ratio=f32(32767/maximum) if maximum else 1.0
 scaled_magnitude=f32(ratio*magnitude)
 scale=f32(scaled_magnitude/32768)
 return tuple(math.trunc(min(32767,max(-32767,f32(v*scale)))) for v in (x,y))
samples=[(0,0),(1,0),(32767,0),(0,32767),(16384,16384),(-32768,-32768),(10000,20000),(20000,10000),(-16384,16384)]
results=[]
for v in samples:results.append({'input':v,'machine':run(*v),'reconstructed':reconstructed(*v)})
mu.hook_del(trace_hook)
rng=random.Random(0x6d4880)
points=samples+[(rng.randint(-32768,32767),rng.randint(-32768,32767)) for _ in range(10000)]
mismatches=[];maxdiff=0;vectors=[];mismatch_count=0
for v in points:
 actual=run(*v);expected=reconstructed(*v)
 vectors.append({'contract':'circleToSquare','input':v,'native':actual})
 if actual!=expected:mismatch_count+=1
 diff=max(abs(actual[i]-expected[i]) for i in range(2));maxdiff=max(maxdiff,diff)
 if actual!=expected and len(mismatches)<40:mismatches.append({'input':v,'machine':actual,'reconstructed':expected})
report={'binarySha256':hashlib.sha256(blob).hexdigest(),'address':'0x6d4880','emulator':'Unicorn 2.1.4 x86-32','method':'Original PE section bytes mapped into isolated emulator; original callees executed; no replacement math hooks and no OS/API execution. Fresh CPU context per sample.','fpuControlWord':'0x037f','samples':results,'vectorsChecked':len(points),'maxIntegerDifference':maxdiff,'mismatchExamples':mismatches,'limits':['Emulation of isolated math, not observed game execution.','Formula preserves observed float32 stores with host-double intermediates; x87 extended precision may create rare rounding differences outside sampled points.']}
(BASE/'reports/native-stick-emulation.json').write_text(json.dumps(report,indent=2))
print(json.dumps(report,indent=2))

(BASE/'reports/native-stick-vectors.json').write_text(json.dumps({'binarySha256':hashlib.sha256(blob).hexdigest(),'vectors':vectors},separators=(',',':'))+'\n')
raise SystemExit(1 if mismatch_count else 0)
