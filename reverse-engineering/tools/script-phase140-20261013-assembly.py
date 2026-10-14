from pathlib import Path
import importlib.util,json
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);records=[]
for address,next in[(0x535940,0x535aa0),(0x535aa0,0x535c00),(0x535c00,0x535d60),(0x535d60,0x535e90),(0x535e90,0x535fc0)]:
 rows=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in c.disasm(n.read(address,next-address),address)]
 while rows and rows[-1]['mnemonic']=='int3':rows.pop()
 records.append(dict(address=hex(address),bodyBytes=sum(len(i['bytes'])//2 for i in rows),instructions=rows))
r=dict(binarySha256=n.sha256,procedures=records,limitations=['CurrentGhidraFunctionManager lacks allfive registered entries; complete originalimmutablePE bytes andexistingboundeddispatchtable evidence retained.']);(nm.BASE/'reports/script-phase140-20261013-assembly.json').write_text(json.dumps(r,indent=2));print(json.dumps([dict(address=r['address'],bodyBytes=r['bodyBytes'],tail=r['instructions'][-28:])for r in records]))
