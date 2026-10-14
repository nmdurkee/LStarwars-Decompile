import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import *
cs=Cs(CS_ARCH_X86,CS_MODE_32)
for a,z in [(0x52b3f0,1536),(0x512ea0,176),(0x513100,160),(0x5132f0,400)]:
 print(hex(a));print('\n'.join(hex(i.address)+' '+i.mnemonic+' '+i.op_str for i in cs.disasm(n.read(a,z),a)))
