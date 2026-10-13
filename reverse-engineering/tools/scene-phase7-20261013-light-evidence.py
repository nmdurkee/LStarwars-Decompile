import sys,importlib.util,json
from pathlib import Path
p=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('nx',p/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32)
o={}
for a,size in [(0x5ff820,0x100),(0x5ff830,0x100),(0x5ff840,0x800),(0x5b3d80,0x200),(0x5b3470,0x200),(0x5b3200,0x200),(0x5b3b30,0x200),(0x5b39e0,0x100),(0x5c0240,0x100),(0x5fcc10,0x100),(0x5b37b0,0x100)]:
 out=[]
 for i in c.disasm(n.read(a,size),a):
  out.append({'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})
  if i.mnemonic=='ret' and (a not in(0x5dad10,0x5c0240) or a==0x5dad10 and i.address>=0x5dae64 or a==0x5c0240 and i.address>=0x5c0252):break
 o[hex(a)]=out
print(json.dumps(o,indent=2))
