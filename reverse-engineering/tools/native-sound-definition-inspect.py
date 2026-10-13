import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in c.disasm(n.read(0x6516a0,0x970),0x6516a0)]
strings={hex(a):n.read(a,80).split(b'\0')[0].decode('ascii') for a in [0x75782c,0x75eaf8,0x76d280,0x76d27c,0x763b84,0x76d254,0x76d250,0x76d240]}
r=dict(binarySha256=n.sha256,strings=strings,instructions=instructions);(m.BASE/'reports/native-sound-definition-assembly.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(dict(strings=strings,calls=[i for i in instructions if i['mnemonic']=='call'],returns=[i for i in instructions if i['mnemonic']=='ret']),indent=2))
