import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32)
out={}
for a,length in[(0x6e3440,0xe0),(0x6e3720,0x240)]:out[hex(a)]=[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str}for i in c.disasm(n.read(a,length),a)]
print(json.dumps({'binarySHA256':n.sha256,'ranges':out,'defaults':{'source':n.unpack('<2i',0x80e694),'origin':n.unpack('<2i',0x80202c),'aim':n.unpack('<3f',0x80e9bc),'direction':n.unpack('<3f',0x80e9d8),'colorWords':n.unpack('<4I',0x80e9c8)}},indent=2))
