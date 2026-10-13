import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x450030,0x280),(0x467890,0x60),(0x55bc80,0xa0),(0x441570,0x30),(0x4415a0,0x20)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
(m.BASE/'reports/native-force-action-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=procedures),indent=2)+'\n')
for p in procedures:
 print(p['address'])
 for r in p['instructions']:print(r['address'],r['mnemonic'],r['operands'])
