import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32)
rows=[]
for a,b in [(0x5155c0,0x515614),(0x515620,0x5156ee)]:
 rows.append(dict(address=hex(a),endExclusive=hex(b),bytes=n.read(a,b-a).hex(),instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)]))
(m.BASE/'reports/script-phase64-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=rows),indent=2))
for r in rows:
 print(r['address']);print('\n'.join(i['address']+' '+i['mnemonic']+' '+i['operands']for i in r['instructions']))
print('extension',n.read(0x75ffd8,16))
