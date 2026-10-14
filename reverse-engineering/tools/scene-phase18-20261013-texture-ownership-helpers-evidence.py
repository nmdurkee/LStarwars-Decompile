import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent;s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
out={}
for entry,length in [(0x5f7980,0x34),(0x5f79e0,0x2b),(0x6e47d0,0x38),(0x6e46b0,0x3b),(0x6e2130,0xe),(0x5f7490,1)]:
 values=[]
 for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(entry,length),entry):
  values.append({'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})

 out[hex(entry)]=values
print(json.dumps({'binarySHA256':n.sha256,'instructions':out},indent=2))
