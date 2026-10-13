import importlib.util,json
from pathlib import Path
p=Path(__file__).with_name('native-x86.py');s=importlib.util.spec_from_file_location('native',p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
for i in range(1000):
 name,address,word=n.unpack('<3I',0x8019c0+i*12)
 if not name:break
 if 0x516000<=address<0x516c00:print(hex(address),n.read(name,80).split(b'\0')[0].decode('latin1'))

from capstone import Cs,CS_ARCH_X86,CS_MODE_32
for a in [0x43c1a0,0x43c1c0,0x43c1e0,0x43c200]:
 print(hex(a))
 for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,0x20),a):print(hex(i.address),i.mnemonic,i.op_str)
