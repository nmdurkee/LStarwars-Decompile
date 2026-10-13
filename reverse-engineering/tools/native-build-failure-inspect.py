import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x590690,0x120),(0x571c50,0x26),(0x571c80,0x6c)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
(m.BASE/'reports/native-build-failure-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=procedures),indent=2)+'\n')
for p in procedures:
 print(p['address'])
 for r in p['instructions']:print(r['address'],r['mnemonic'],r['operands'])

print('constants',(hex(n.unpack('<Q',0x751700)[0]),n.unpack('<d',0x751700)[0]),n.unpack('<d',0x753178))
