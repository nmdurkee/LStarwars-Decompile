import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[]
for a,z in [(0x55ffb0,0x1f0),(0x55f470,0x84),(0x55f500,0x26),(0x560630,0x9a)]:
 r=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)]; rows.append(dict(address=hex(a),instructions=r))
(m.BASE/'reports/world-loading-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=rows),indent=2)+'\n')
print(json.dumps(dict(procedures=len(rows),binarySha256=n.sha256)))
