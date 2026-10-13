import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import *
cs=Cs(CS_ARCH_X86,CS_MODE_32)
for a,z in [(0x54a3e0,310),(0x54a850,130),(0x6e6b90,140),(0x5a03d0,100)]:
 print(hex(a));print('\n'.join(hex(i.address)+' '+i.mnemonic+' '+i.op_str for i in cs.disasm(n.read(a,z),a)))

print('scale',n.unpack('<d',0x7531f8)[0])
