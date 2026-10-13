"""Inspect exact original instructions for frame-reset contracts."""
import importlib.util,json
from pathlib import Path
B=Path(__file__).resolve().parent.parent
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);out={}
for a,size in [(0x5dfab0,0x100),(0x5ddd10,0x140),(0x5fca40,0x40),(0x5fd100,0x60),(0x5fd160,0x70),(0x4ef6e0,0x30)]:
 rows=[]
 for ins in c.disasm(n.read(a,size),a):
  rows.append({'address':hex(ins.address),'bytes':ins.bytes.hex(),'mnemonic':ins.mnemonic,'operands':ins.op_str})
  if ins.mnemonic=='ret' or (a==0x4ef6e0 and ins.mnemonic=='jmp'):break
 out[hex(a)]=rows
(B/'reports/geometry-frame-reset-assembly.json').write_text(json.dumps(out,indent=2)+'\n')
for a,rows in out.items():
 print(a)
 for r in rows:print(r['address'],r['mnemonic'],r['operands'])

