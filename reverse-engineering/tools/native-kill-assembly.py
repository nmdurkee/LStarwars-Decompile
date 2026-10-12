import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=m.NativeX86();rows=[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x445230,0x500),0x445230)]
(m.BASE/'reports/native-combat-kill-assembly.json').write_text(json.dumps({'binarySha256':n.sha256,'rows':rows},indent=2)+'\n')
for j,row in enumerate(rows):
 if '0x1010' in row['instruction']:
  for x in rows[max(0,j-3):j+10]:print(x['address'],x['instruction'])
