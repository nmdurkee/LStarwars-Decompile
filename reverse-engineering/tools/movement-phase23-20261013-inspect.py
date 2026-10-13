import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path('reverse-engineering/tools/native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import *
c=Cs(CS_ARCH_X86,CS_MODE_32)
a=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in c.disasm(n.read(0x4dd810,0x4dddb0-0x4dd810),0x4dd810)]
(m.BASE/'reports/movement-phase23-20261013-assembly-draft.json').write_text(json.dumps(dict(binarySha256=n.sha256,instructions=a),indent=2))
for i in a:print(i['address'],i['mnemonic'],i['operands'])
print('step',n.unpack('<f',0x7f15e0),'matrix',n.unpack('<16I',0x8065c0))
