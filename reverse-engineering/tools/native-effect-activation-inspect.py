import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x464360,0x100),(0x5a8280,0x50),(0x658490,0xe0),(0x655320,0x20),(0x655340,0x20),(0x48a060,0x110)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
 if a==0x658490:print(json.dumps(rows[:22],indent=2))
 if a==0x464360:
  for i,r in enumerate(rows):
   if r['mnemonic']=='call' and r['operands']=='0x48a060':print(json.dumps(rows[i-10:i+3],indent=2))
(m.BASE/'reports/native-effect-activation-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=procedures),indent=2)+'\n')
