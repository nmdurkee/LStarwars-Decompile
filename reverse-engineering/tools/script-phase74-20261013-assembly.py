import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
for address,size in[(0x4f9de0,134),(0x4f0f30,114),(0x4f8b10,100)]:
 data=n.read(address,size);functions.append(dict(address=hex(address),size=size,bytes=data.hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(data,address)]))
(nm.BASE/'reports/script-phase74-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2))
print(json.dumps(dict(functions=len(functions),binarySha256=n.sha256)))
