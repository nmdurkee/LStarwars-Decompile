import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x48ce00,0x263),(0x48d64d,0x13),(0x48d695,0x19),(0x55f6c0,0x1d7)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
(m.BASE/'reports/world-phase5-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=procedures),indent=2)+'\n')
print(json.dumps(dict(spans=len(procedures),binarySha256=n.sha256)))
