import importlib.util
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path('reverse-engineering/tools/native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import *
c=Cs(CS_ARCH_X86,CS_MODE_32)
for a,b in[(0x55cd20,0x55cda0),(0x55cc40,0x55ccd0)]:
 for i in c.disasm(n.read(a,b-a),a):print(hex(i.address),i.mnemonic,i.op_str)
