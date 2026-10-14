import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32)
import struct
for a,z in [(0x759760,4)]:print(hex(a),n.read(a,z).hex(),struct.unpack('<d' if z==8 else '<f',n.read(a,z))[0])
