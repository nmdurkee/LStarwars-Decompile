from pathlib import Path
import importlib.util,json
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[]
for i in c.disasm(n.read(0x516ac0,0x79),0x516ac0):rows.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str))
r=dict(binarySha256=n.sha256,address='0x516ac0',instructions=rows,reaDiagnostic='reports/rea-continuous/4200-script120-origin-position.result.json')
(nm.BASE/'reports/script-phase120-20261013-assembly.json').write_text(json.dumps(r,indent=2));print(json.dumps(rows))
