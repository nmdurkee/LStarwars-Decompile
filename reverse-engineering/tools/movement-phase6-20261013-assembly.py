import importlib.util,json
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from capstone import *
n=m.NativeX86();cs=Cs(CS_ARCH_X86,CS_MODE_32);rows={}
for va,size in[(0x446b30,0x400),(0x5b9e90,0x100)]:
 out=[]
 for i in cs.disasm(n.read(va,size),va):
  out.append({'va':hex(i.address),'bytes':i.bytes.hex(),'assembly':i.mnemonic+' '+i.op_str})
  if i.mnemonic=='ret':break
 rows[hex(va)]=out
(m.BASE/'reports/movement-phase6-20261013-assembly.json').write_text(json.dumps({'binarySha256':n.sha256,'rows':rows},indent=2)+'\n')
print(json.dumps({k:len(v)for k,v in rows.items()}))
