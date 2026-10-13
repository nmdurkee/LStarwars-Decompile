import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x58a900,0x30),(0x442aa0,0x30),(0x442bb0,0x30),(0x491b30,0x40),(0x491b70,0x30),(0x442320,0x90),(0x4423b0,0x40)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
(m.BASE/'reports/native-level-mode-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=procedures),indent=2)+'\n')
names=[]
for i in range(10):
 p=n.unpack('<I',0x7fab24+i*4)[0];name=n.read(p,80).split(b'\0')[0].decode('ascii');names.append(name)
(m.BASE/'reports/native-hub-area-names.json').write_text(json.dumps(dict(binarySha256=n.sha256,table='0x7fab24',names=names),indent=2)+'\n')
print(json.dumps(dict(procedures=len(procedures),hubNames=names)))
