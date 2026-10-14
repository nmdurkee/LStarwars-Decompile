from pathlib import Path
import importlib.util,json
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);rows=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in c.disasm(n.read(0x43c0c0,0x69),0x43c0c0)]
strings=[]
for i in rows:
 if i['mnemonic']=='push'and i['operands'].startswith('0x75'):
  address=int(i['operands'],16);data=n.read(address,64).split(b'\0')[0];strings.append(dict(address=hex(address),bytes=data.hex(),text=data.decode('latin1')))
strings.append(dict(address='0x757e80',bytes=n.read(0x757e80,64).split(b'\0')[0].hex(),text=n.read(0x757e80,64).split(b'\0')[0].decode('latin1')))
r=dict(binarySha256=n.sha256,address='0x43c0c0',instructions=rows,literals=strings);(nm.BASE/'reports/script-phase141-20261013-assembly.json').write_text(json.dumps(r,indent=2));print(json.dumps(r))
