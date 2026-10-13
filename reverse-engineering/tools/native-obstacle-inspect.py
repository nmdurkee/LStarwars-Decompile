import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=m.NativeX86();cs=Cs(CS_ARCH_X86,CS_MODE_32);out={}
for a,length in [(0x4408b0,0x30),(0x4408e0,0x30),(0x440910,0x30),(0x440940,0x30),(0x440970,0x40),(0x4409b0,0x30),(0x558780,0xb0),(0x5ae3a0,0x80),(0x5a1170,0x40),(0x44ea70,0x1d0),(0x465590,0x190),(0x465720,0x140),(0x557960,0x70),(0x5579d0,0x70),(0x558970,0x20),(0x558990,0x20),(0x55a1b0,0x70),(0x5a0670,0xb0),(0x5a1030,0x160),(0x5a11b0,0x40),(0x5a11f0,0x40),(0x5a1230,0x40),(0x5a1270,0xc0)]:out[hex(a)]=[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str}for i in cs.disasm(n.read(a,length),a)]
out['strings']={hex(a):n.read(a,80).split(b'\0')[0].decode('latin1')for a in [0x758a60,0x757e88]}
(m.BASE/'reports/native-obstacle-assembly.json').write_text(json.dumps(out,indent=2)+'\n')
for a in []:
 print(hex(a))
 for row in out[hex(a)]:print(row['address'],row['instruction'])
print(out['strings'])
