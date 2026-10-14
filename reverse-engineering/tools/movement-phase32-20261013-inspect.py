from pathlib import Path
import importlib.util,json
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in c.disasm(n.read(0x4d9760,0x4d9ee0-0x4d9760),0x4d9760)]
(m.BASE/'reports/movement-phase32-20261013-assembly-draft.json').write_text(json.dumps(dict(binarySha256=n.sha256,instructions=ins),indent=2)+'\n')
for i in ins:print(i['address'],i['mnemonic'],i['operands'])
