import importlib.util,json,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[]
for a,e in [(0x654950,0x65496a),(0x654970,0x654992),(0x6549a0,0x6549b4),(0x6549c0,0x6549da),(0x6549e0,0x6549fa),(0x654a00,0x654a8d),(0x6e8e1e,0x6e8e40)]:
 ins=list(c.disasm(n.read(a,e-a),a));rows.append(dict(address=hex(a),endExclusive=hex(e),bytesSha256=hashlib.sha256(n.read(a,e-a)).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in ins]))
(m.BASE/'reports/world-phase38-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=rows,literals=[dict(address=hex(a),rawBytes=n.read(a,8).hex(),binary64=n.unpack('<d',a)[0]) for a in [0x7517a0,0x76d2b0,0x751710,0x758fb8,0x751678,0x7516f8,0x76d2b8,0x758758]]),indent=2)+'\n')
print(json.dumps([(r['address'],r['endExclusive']) for r in rows]))
