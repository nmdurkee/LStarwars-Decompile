import importlib.util,json,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[]
for a,e in [(0x6561d0,0x6563e9),(0x6563f0,0x656cee),(0x653940,0x653954)]:
 ins=list(c.disasm(n.read(a,e-a),a));rows.append(dict(address=hex(a),endExclusive=hex(e),bytesSha256=hashlib.sha256(n.read(a,e-a)).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in ins]))
(m.BASE/'reports/world-phase35-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=rows,initializerTable=list(n.unpack('<13I',0x810910)),updateTable=list(n.unpack('<13I',0x810944))),indent=2)+'\n')
print(json.dumps(dict(initializerTable=[hex(v) for v in n.unpack('<13I',0x810910)],updateTable=[hex(v) for v in n.unpack('<13I',0x810944)])))
