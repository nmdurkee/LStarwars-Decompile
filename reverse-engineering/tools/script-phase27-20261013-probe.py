import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import *
cs=Cs(CS_ARCH_X86,CS_MODE_32)
for a,z in [(0x514990,16),(0x5149a0,16),(0x5149f0,16),(0x514ae0,32),(0x514b00,32),(0x514b20,32),(0x514b40,32),(0x514b60,48),(0x514b90,32),(0x514bb0,32),(0x514f90,32),(0x5151c0,32),(0x5157b0,48)]:
 print(hex(a));print('\n'.join(hex(i.address)+' '+i.mnemonic+' '+i.op_str for i in cs.disasm(n.read(a,z),a)))
