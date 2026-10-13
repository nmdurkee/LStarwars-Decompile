import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[]
for a,z in [(0x698cc0,0x150),(0x697690,0x62),(0x696b40,0x30)]:
 instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];rows.append(dict(address=hex(a),instructions=instructions))
 for r in instructions:print(r['address'],r['mnemonic'],r['operands'])
(x.BASE/'reports/native-sound-voices-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=rows),indent=2)+'\n')

import struct
print('fadeMultiplier',struct.unpack('<d',n.read(0x76efa0,8))[0])
