import importlib.util,json,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[]
for a,e in [(0x68e4f0,0x68e6f0),(0x655f30,0x655fc0)]:
 ins=list(c.disasm(n.read(a,e-a),a));rows.append(dict(address=hex(a),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in ins]))
(m.BASE/'reports/world-phase19-20261013-assembly-draft.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=rows),indent=2)+'\n')
for r in rows:
 print(r['address']);print('\n'.join(i['address']+' '+i['mnemonic']+' '+i['operands'] for i in r['instructions']))
