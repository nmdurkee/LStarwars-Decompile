import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32)
rows=[dict(address=hex(a),endExclusive=hex(b),bytes=n.read(a,b-a).hex(),instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)])for a,b in [(0x514990,5327256),(0x5149a0,5327269),(0x5149f0,5327357),(0x514ae0,5327603),(0x514b00,5327635),(0x514b20,5327671),(0x514b40,5327712),(0x514b60,5327748),(0x514b90,5327778),(0x514bb0,5327818),(0x514f90,5328803),(0x5151c0,5329367),(0x5157b0,5330888)]]
(m.BASE/'reports/script-phase27-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=rows),indent=2));print(sum(len(r['instructions'])for r in rows))
