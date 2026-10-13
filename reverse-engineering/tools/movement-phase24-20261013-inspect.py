import importlib.util
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path('reverse-engineering/tools/native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import *
c=Cs(CS_ARCH_X86,CS_MODE_32)
for a,b in [(0x475850,0x4758a0),(0x41f8f0,0x41f950),(0x55c9f0,0x55ca90)]:
 for i in c.disasm(n.read(a,b-a),a):print(hex(i.address),i.mnemonic,i.op_str)
