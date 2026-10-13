import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
functions=[]
for a,end in [(0x5728a0,0x572ac0),(0x572440,0x572660),(0x54fec0,0x54ff40),(0x5b35a0,0x5b3610),(0x67a600,0x67a620),(0x67a670,0x67a690),(0x67a690,0x67a6b0),(0x67a6e0,0x67a730)]:
 rows=[]
 for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,end-a),a):
  if i.mnemonic=='int3':break
  rows.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str))
 functions.append(dict(address=hex(a),endExclusive=hex(int(rows[-1]['address'],16)+len(bytes.fromhex(rows[-1]['bytes']))),instructions=rows))
report=dict(binarySha256=n.sha256,functions=functions,defaults={hex(a):n.read(a,size).hex() for a,size in [(0x8034cc,32*12),(0x802500,12),(0x8034c4,4)]});(x.BASE/'reports/gameplay-terrain-state-assembly.json').write_text(json.dumps(report,indent=2),encoding='utf8');print(json.dumps([dict(address=f['address'],end=f['endExclusive'],count=len(f['instructions'])) for f in functions]))

