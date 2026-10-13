import importlib.util,json,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[]
for a,e in [(0x64ae50,0x64afd0),(0x644000,0x644140),(0x5b9d90,0x5b9dd0)]:
 ins=list(c.disasm(n.read(a,e-a),a))
 while ins and ins[-1].mnemonic=='int3':ins.pop()
 end=ins[-1].address+ins[-1].size;rows.append(dict(address=hex(a),endExclusive=hex(end),bytesSha256=hashlib.sha256(n.read(a,end-a)).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in ins]))
(m.BASE/'reports/world-phase13-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=rows),indent=2)+'\n')
print(json.dumps([(r['address'],r['endExclusive']) for r in rows]))
