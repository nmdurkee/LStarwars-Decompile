import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path('reverse-engineering/tools/native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import *
c=Cs(CS_ARCH_X86,CS_MODE_32);ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in c.disasm(n.read(0x43d890,0x43e130-0x43d890),0x43d890)]
(m.BASE/'reports/movement-phase28-20261013-assembly-draft.json').write_text(json.dumps(dict(binarySha256=n.sha256,instructions=ins),indent=2)+'\n')
for i in ins:print(i['address'],i['mnemonic'],i['operands'])
