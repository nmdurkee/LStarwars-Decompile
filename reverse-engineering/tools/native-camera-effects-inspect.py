import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
d=Cs(CS_ARCH_X86,CS_MODE_32);procedures=[]
for a,z in [(0x451c20,0xd0),(0x44d110,0x100),(0x44d210,0xf0),(0x44d300,0x30),(0x549bb0,0x30),(0x549de0,0xd0),(0x54a2f0,0xf0),(0x576c40,0x20),(0x441c00,0x80)]:
 rows=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in d.disasm(n.read(a,z),a)];procedures.append(dict(address=hex(a),instructions=rows))
 if a==0x441c00:print(json.dumps(rows,indent=2))
strings={hex(a):n.read(a,64).split(b'\0')[0].decode('ascii')for a in [0x757ca8,0x757cd8]};print(json.dumps(strings));(m.BASE/'reports/native-camera-effects-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=procedures,strings=strings),indent=2)+'\n')
