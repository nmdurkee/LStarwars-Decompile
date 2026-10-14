from pathlib import Path
import importlib.util,json
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32)
r=[]
for i in c.disasm(n.read(0x43c3a0,0xd6),0x43c3a0):
 r.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str))
report=dict(binarySha256=n.sha256,address='0x43c3a0',instructions=r,reaDiagnostic='reports/rea-continuous/4190-script110-origin-resolver.result.json',limits=['Ghidra FunctionManager lacks this registered callback; original bytes decoded from the immutable bound PE.'])
(nm.BASE/'reports/script-phase110-20261013-assembly.json').write_text(json.dumps(report,indent=2))
print(json.dumps(report))
