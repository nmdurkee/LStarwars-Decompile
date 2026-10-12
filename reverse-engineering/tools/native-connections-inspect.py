import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=m.NativeX86();cs=Cs(CS_ARCH_X86,CS_MODE_32);out={}
for a,length in [(0x44d870,0x90),(0x43cfb0,0x100),(0x44d900,0x650),(0x43cca0,0x2d0),(0x43d0c0,0x350)]:out[hex(a)]=[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str}for i in cs.disasm(n.read(a,length),a)]
(m.BASE/'reports/native-connections-assembly.json').write_text(json.dumps(out,indent=2)+'\n')
for a in [0x43d0c0]:
 for row in out[hex(a)]:print(row['address'],row['instruction'])
for a in [0x757c50,0x757dfc,0x757d6c,0x757938,0x757d4c,0x757d38,0x757d20,0x751850]:print(hex(a),repr(n.read(a,64).split(b'\0')[0]))
