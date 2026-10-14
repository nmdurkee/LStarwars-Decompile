import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent;s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
out=[]
for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x6df0e0,0xb5),0x6df0e0):
 out.append({'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})
 if i.mnemonic=='ret':break
print(json.dumps({'binarySHA256':n.sha256,'instructions':out},indent=2))
