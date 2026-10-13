import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x5cffb0,0x60),(0x67c760,0x60),(0x4418c0,0x50),(0x441910,0x90),(0x5cf5b0,0xe0),(0x5cf510,0xa0)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
(m.BASE/'reports/native-terrain-object-conditions-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=procedures),indent=2)+'\n')
print(json.dumps(dict(procedures=len(procedures))))
