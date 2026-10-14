from pathlib import Path
import importlib.util,json
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for a,z in [(0x536330,975)]for i in c.disasm(n.read(a,z),a)]
r=dict(binarySha256=n.sha256,instructions=rows);(nm.BASE/'reports/script-phase149-20261013-assembly.json').write_text(json.dumps(r,indent=2));print(json.dumps(dict(instructions=len(rows))))
