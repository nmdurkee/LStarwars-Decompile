import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32)
rows=[dict(address=hex(a),endExclusive=hex(b),bytes=n.read(a,b-a).hex(),instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)])for a,b in [(0x514140,5325721),(0x5143a0,5326151),(0x512fc0,5320718),(0x513010,5320949),(0x5149b0,5327329)]]
(m.BASE/'reports/script-phase28-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=rows),indent=2));print(sum(len(r['instructions'])for r in rows))
