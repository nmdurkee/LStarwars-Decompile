import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32)
o={}
for a,size in[(0x6e5340,0x100)]:
 out=[]
 for i in c.disasm(n.read(a,size),a):
  out.append({'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})
  if i.mnemonic=='ret':break
 o[hex(a)]=out
print(json.dumps({'binarySHA256':n.sha256,'functions':o,'renderStateSelectors':list(n.read(0x6e5424,186)),'renderStateTargets':list(n.unpack('<13I',0x6e53f0))},indent=2))
