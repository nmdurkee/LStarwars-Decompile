import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x44ac40,0x49c),(0x54fb40,0x40)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
 if a==0x44ac40:print(json.dumps([r for r in rows if int(r['address'],16)>=0x44b090],indent=2))
strings={hex(a):n.read(a,32).split(b'\0')[0].decode() for a in [0x757be8,0x757be0]};print(json.dumps(strings));(m.BASE/'reports/native-run-speed-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=procedures,strings=strings),indent=2)+'\n')
