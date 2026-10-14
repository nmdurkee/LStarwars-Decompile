from pathlib import Path
p=Path(__file__).with_name('movement-phase22-20261013-native.py');q={'__file__':str(p)};exec(compile(p.read_text().split('for mode,factor,delta in itertools.product')[0],str(p),'exec'),q)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=q['n'];cs=Cs(CS_ARCH_X86,CS_MODE_32)
print('\n'.join(hex(i.address)+' '+i.mnemonic+' '+i.op_str for i in cs.disasm(n.read(0x4d9710,0x50),0x4d9710)))
