from pathlib import Path
import importlib.util,struct
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);cs.skipdata=True;pe=struct.unpack_from('<I',n.blob,0x3c)[0];opt=pe+24;base=struct.unpack_from('<I',n.blob,opt+28)[0]

for ins in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x4ef440,0x430),0x4ef440):print(hex(ins.address),ins.mnemonic,ins.op_str)
