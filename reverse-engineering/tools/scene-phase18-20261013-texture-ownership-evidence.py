import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent;s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
out={}
for entry,length in [(0x5f7b40,0xff),(0x605800,0x8a),(0x605890,0x7b),(0x5f81f0,0x184)]:
 values=[]
 for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(entry,length),entry):
  values.append({'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})

 out[hex(entry)]=values
print(json.dumps({'binarySHA256':n.sha256,'instructions':out},indent=2))
