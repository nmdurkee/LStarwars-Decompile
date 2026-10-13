import importlib.util,json
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from capstone import *
n=m.NativeX86();cs=Cs(CS_ARCH_X86,CS_MODE_32);rows={}
for va,size in[(0x449f70,0x240),(0x5d0690,0xb0),(0x5d0740,0x100),(0x4f8b80,0x100)]:rows[hex(va)]=[{'va':hex(i.address),'bytes':i.bytes.hex(),'assembly':i.mnemonic+' '+i.op_str}for i in cs.disasm(n.read(va,size),va)]
(m.BASE/'reports/movement-phase9-20261013-assembly.json').write_text(json.dumps({'binarySha256':n.sha256,'rows':rows},indent=2)+'\n')
print('\n'.join(r['va']+' '+r['assembly']for r in rows['0x449f70'][-65:]))
