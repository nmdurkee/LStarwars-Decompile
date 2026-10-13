import sys,importlib.util,json
from pathlib import Path
p=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('nx',p/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32)
o={}
for a,size in [(0x5ff840,0x600),(0x5fcc80,0x500),(0x5d6180,0x80),(0x5d6190,0x80),(0x5dad10,0x200),(0x5daef0,0x200)]:
 out=[]
 for i in c.disasm(n.read(a,size),a):
  out.append({'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})
  if i.mnemonic=='ret' and (a!=0x5dad10 or i.address>=0x5dae64):break
 o[hex(a)]=out
print(json.dumps(o,indent=2))
