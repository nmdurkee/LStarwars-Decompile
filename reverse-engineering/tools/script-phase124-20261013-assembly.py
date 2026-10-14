from pathlib import Path
import importlib.util,json
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in c.disasm(n.read(0x535000,0xda),0x535000)]
r=dict(binarySha256=n.sha256,address='0x535000',instructions=rows,reaDiagnostic='reports/rea-continuous/4206-script124-follow-player.result.json');(nm.BASE/'reports/script-phase124-20261013-assembly.json').write_text(json.dumps(r,indent=2));print(json.dumps(rows))
