import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32); rows=[]
for a,z in [(0x552670,0x47),(0x5a05b0,0x3e),(0x62c400,0x153),(0x658330,0x133),(0x658470,0x15),(0x658490,0xd4),(0x5a8090,0xbc),(0x48d063,0x31)]:
 ins=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];rows.append(dict(address=hex(a),instructions=ins))
(m.BASE/'reports/world-phase6-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=rows),indent=2)+'\n')
print(json.dumps(rows))
