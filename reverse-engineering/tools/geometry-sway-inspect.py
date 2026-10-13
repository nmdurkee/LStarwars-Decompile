"""Read-only instruction evidence for dynamic sway coefficient/matrix helpers."""
import importlib.util,json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;s=importlib.util.spec_from_file_location('sway_x86',B/'tools/native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
d=Cs(CS_ARCH_X86,CS_MODE_32);windows=[]
for address,size in [(0x5ec3d0,0x1bd),(0x5ec590,0x93),(0x5b9d90,0x2c),(0x6e6b90,0x74)]:
 code=n.read(address,size);rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in d.disasm(code,address)];windows.append(dict(address=hex(address),bytes=size,sha256=hashlib.sha256(code).hexdigest(),instructions=rows))
 for i in rows:print(i['address'],i['mnemonic'],i['operands'])
constants={hex(p):dict(float=n.unpack('<f',p)[0],bits=hex(n.unpack('<I',p)[0]))for p in [0x80b6d8,0x80b6dc,0x97390c]}
report=dict(binarySHA256=n.sha256,windows=windows,initialWords=constants,qualification='Windows may include adjacent code; initialWords are PE-image values, not proof of runtime defaults.');(B/'reports/geometry-sway-assembly.json').write_text(json.dumps(report,indent=2)+'\n');print(constants)
