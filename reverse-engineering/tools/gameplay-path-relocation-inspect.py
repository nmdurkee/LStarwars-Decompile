import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
functions=[]
for a,end in [(0x43c9a0,0x43cc10),(0x572660,0x572770),(0x55e4e0,0x55e600)]:
 rows=[]
 for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,end-a),a):
  if i.mnemonic=='int3':break
  rows.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str))
 functions.append(dict(address=hex(a),endExclusive=hex(int(rows[-1]['address'],16)+len(bytes.fromhex(rows[-1]['bytes']))),instructions=rows))
report=dict(binarySha256=n.sha256,functions=functions,constants={hex(a):dict(hex=n.read(a,size).hex(),floats=list(n.unpack('<'+'f'*(size//4),a))) for a,size in [(0x7f6738,4),(0x806680,64),(0x93b0cc,12)]});(x.BASE/'reports/gameplay-path-relocation-assembly.json').write_text(json.dumps(report,indent=2),encoding='utf8');print(json.dumps(dict(constants=report['constants'],floorInstructions=functions[1]),indent=2))
