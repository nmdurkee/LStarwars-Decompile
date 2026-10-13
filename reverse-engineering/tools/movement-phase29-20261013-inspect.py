from pathlib import Path
import importlib.util,json
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);func=[]
for a,size in[(0x41b0a0,0x600),(0x55e470,0x70),(0x414ad0,0x130)]:
 ins=[]
 for i in cs.disasm(n.read(a,size),a):
  ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str));print(hex(i.address),i.mnemonic,i.op_str)
  if i.mnemonic=='ret' and a!=0x55e470:break
 func.append(dict(address=hex(a),instructions=ins))
(m.BASE/'reports/movement-phase29-20261013-assembly-draft.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=func),indent=2)+'\n')
