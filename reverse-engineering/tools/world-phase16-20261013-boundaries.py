import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32)
for a in [0x66a190,0x68df20]:
 ins=list(c.disasm(n.read(a,0x2000),a));end=next(i.address for i in ins if i.mnemonic=='int3');print(hex(a),hex(end));print('\n'.join('%x %s %s'%(i.address,i.mnemonic,i.op_str) for i in ins if end-100<=i.address<end))
