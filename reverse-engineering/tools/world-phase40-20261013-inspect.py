import importlib.util,json,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[]
for a,e in [(0x600260,0x60099f)]:
 ins=list(c.disasm(n.read(a,e-a),a));rows.append(dict(address=hex(a),endExclusive=hex(e),bytesSha256=hashlib.sha256(n.read(a,e-a)).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in ins]))
(m.BASE/'reports/world-phase40-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=rows,literals=[dict(address=hex(a),rawBytes=n.read(a,8).hex(),binary64=n.unpack('<d',a)[0]) for a in [0x76a7a0,0x7516b0,0x751690,0x76a7f8,0x7639f0,0x7516e8,0x7516d8,0x7531f8]]),indent=2)+'\n')
print(json.dumps([(r['address'],r['endExclusive']) for r in rows]))
