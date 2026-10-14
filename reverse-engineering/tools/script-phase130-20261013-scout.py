from pathlib import Path
import importlib.util,struct
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);cs.skipdata=True;pe=struct.unpack_from('<I',n.blob,0x3c)[0];opt=pe+24;base=struct.unpack_from('<I',n.blob,opt+28)[0]
for i in range(struct.unpack_from('<H',n.blob,pe+6)[0]):
 at=opt+struct.unpack_from('<H',n.blob,pe+20)[0]+i*40;rva,raw,off=struct.unpack_from('<III',n.blob,at+12);flags=struct.unpack_from('<I',n.blob,at+36)[0]
 if not flags&0x20000000:continue
 for ins in cs.disasm(n.blob[off:off+raw],base+rva):
  if any(x in ins.op_str for x in ['0x6dee60','0x6dee90']):print(hex(ins.address),ins.mnemonic,ins.op_str)
