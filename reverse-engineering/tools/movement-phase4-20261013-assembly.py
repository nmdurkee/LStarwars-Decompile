import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
from capstone import *
n=m.NativeX86();c=Cs(CS_ARCH_X86,CS_MODE_32)
rows={}
for a,l in [(0x536330,0x3d0),(0x536dc0,0x200),(0x52fda0,0x170),(0x5b3620,0x90),(0x52fcb0,0xf0),(0x5b3c50,0xa0),(0x5b3cf0,0x80),(0x5b9dd0,0x90)]:
 rows[hex(a)]=[{'va':hex(i.address),'bytes':i.bytes.hex(),'assembly':i.mnemonic+' '+i.op_str}for i in c.disasm(n.read(a,l),a)]
(m.BASE/'reports/movement-phase4-20261013-assembly.json').write_text(json.dumps({'binarySha256':n.sha256,'rows':rows},indent=2)+'\n')
print(json.dumps(rows['0x536dc0'],indent=2))
print(json.dumps(rows['0x536330'][-90:],indent=2))
