import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32)
o={}
for a,size in [(0x6e54e0,0x90),(0x6e5570,0x20),(0x6e45e0,0x40),(0x6e5850,0x20),(0x6e4a40,0x20),(0x6e66b0,0x90),(0x4ffaa0,0x20),(0x4ffac0,0x20)]:
 out=[]
 for i in c.disasm(n.read(a,size),a):
  out.append({'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})
  if i.mnemonic=='ret':break
 o[hex(a)]=out
print(json.dumps({'binarySHA256':n.sha256,'functions':o,'vendorTableHex':n.read(0x8283e8,0x10c0).hex()},indent=2))
