import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x571ba0,0xb0),(0x5bec80,0x30),(0x5c0240,0x40),(0x650430,0xb0),(0x650dc0,0x80),(0x681eb0,0x20)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
(m.BASE/'reports/native-build-sound-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=procedures),indent=2)+'\n')
for p in procedures:
 print(p['address'])
 for r in p['instructions']:print(r['address'],r['mnemonic'],r['operands'])

print('scale',n.unpack('<d',0x751690));print('conversion-mode',n.unpack('<I',0x29a9c48));print('sqrt-flags',n.unpack('<I',0x29a9c38));print('table-prefix',n.unpack('<4I',0x29899a0))
