import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32)
for phase,functions in [(20,[(0x5147c0,0x51484e),(0x514850,0x51491e),(0x514920,0x514984),(0x4f8420,0x4f8708),(0x4f8790,0x4f8803),(0x4f8830,0x4f8880),(0x4f8880,0x4f88d2),(0x4f88e0,0x4f8910)]),(21,[(0x53d5d0,0x53d612),(0x53d940,0x53db29),(0x53db30,0x53db4a)]),(22,[(0x60e590,0x60e5ec),(0x60ee80,0x60ef10),(0x60f190,0x60f294)])]:
 rows=[dict(address=hex(a),endExclusive=hex(b),bytes=n.read(a,b-a).hex(),instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)])for a,b in functions]
 (m.BASE/'reports'/f'script-phase{phase}-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=rows),indent=2))
 print(phase,sum(len(row['instructions'])for row in rows))
