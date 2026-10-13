"""Bounded local probe for the full PC steering entry; no live game launch."""
import importlib.util,json
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=load('reinit','gameplay-reinitialization-verify.py');n=r.x.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
rows=[]
for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x51d7b0,0x1200),0x51d7b0):
 if i.mnemonic=='int3':break
 rows.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str))
report=dict(binarySha256=n.sha256,entry='0x51d7b0',endExclusive=hex(int(rows[-1]['address'],16)+len(bytes.fromhex(rows[-1]['bytes']))),constants={hex(a):dict(hex=n.read(a,4).hex(),value=n.unpack('<f',a)[0]) for a in [0x801c8c,0x801c90]},instructions=rows)
(r.BASE/'reports/gameplay-path-steering-assembly.json').write_text(json.dumps(report,indent=2),encoding='utf8');print(json.dumps(dict(instructions=len(rows),constants=report['constants'],end=report['endExclusive'])))
