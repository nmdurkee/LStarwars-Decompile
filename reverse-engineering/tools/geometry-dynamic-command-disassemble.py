import importlib.util,json
from pathlib import Path
B=Path(__file__).resolve().parent.parent
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);out={}
for a,size in [(0x603530,0x50),(0x603ad0,0x40),(0x603b10,0x20),(0x5fd220,0x40),(0x5e0530,0xc0)]:
 rows=[]
 for ins in c.disasm(n.read(a,size),a):rows.append({'address':hex(ins.address),'bytes':ins.bytes.hex(),'mnemonic':ins.mnemonic,'operands':ins.op_str})
 out[hex(a)]=rows
(B/'reports/geometry-dynamic-command-assembly.json').write_text(json.dumps(out,indent=2)+'\n')
for a,rows in out.items():
 print(a)
 for r in rows:print(r['address'],r['mnemonic'],r['operands'])
