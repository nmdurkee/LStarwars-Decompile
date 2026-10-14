from pathlib import Path
import json
p=Path(__file__).with_name('movement-phase22-20261013-native.py');q={'__file__':str(p)};exec(compile(p.read_text().split('for mode,factor,delta in itertools.product')[0],str(p),'exec'),q)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=q['n'];cs=Cs(CS_ARCH_X86,CS_MODE_32)
for a,b in[(0x5bec80,0x5becb4),(0x5bed80,0x5bee68),(0x49f630,0x49f779)]:
 print(hex(a));print('\n'.join(hex(i.address)+' '+i.mnemonic+' '+i.op_str for i in cs.disasm(n.read(a,b-a),a)))
