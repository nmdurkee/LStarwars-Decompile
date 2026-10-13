import importlib.util,json,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x650f20,0x550),(0x696be0,0x10),(0x5b9d90,0x80),(0x6951c0,0x100)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
r=dict(binarySha256=n.sha256,procedures=procedures,constants={hex(a):n.unpack('<d',a)[0] for a in [0x76d238,0x76d230,0x7516d8,0x755b48]});(m.BASE/'reports/native-sound-playback-assembly.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(dict(constants=r['constants'],procedures=[dict(address=p['address'],instructions=len(p['instructions'])) for p in procedures]),indent=2))
