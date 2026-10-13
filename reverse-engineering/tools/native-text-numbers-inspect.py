import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[]
for a,z in [(0x4f28e0,0xbf),(0x4f29a0,0x46),(0x4f8cb0,0x51),(0x4f8100,0x95),(0x4f9e70,0xe2)]:
 instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];rows.append(dict(address=hex(a),instructions=instructions))
 for r in instructions:print(r['address'],r['mnemonic'],r['operands'])
(x.BASE/'reports/native-text-numbers-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=rows),indent=2)+'\n')
