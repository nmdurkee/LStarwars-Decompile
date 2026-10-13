import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
from capstone import *
n=m.NativeX86();c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[{'va':hex(i.address),'bytes':i.bytes.hex(),'assembly':i.mnemonic+' '+i.op_str}for i in c.disasm(n.read(0x51d130,0x120),0x51d130)]
(m.BASE/'reports/movement-phase5-20261013-assembly.json').write_text(json.dumps({'binarySha256':n.sha256,'rows':rows},indent=2)+'\n')
print('\n'.join(r['va']+' '+r['assembly']for r in rows))
