import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32)
o=[]
for i in c.disasm(n.read(0x6e2d20,0x670),0x6e2d20):
 o.append({'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})
 if i.mnemonic=='ret':break
print(json.dumps({'binarySHA256':n.sha256,'instructions':o},indent=2))
