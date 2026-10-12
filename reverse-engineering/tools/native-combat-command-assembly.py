import importlib.util,json
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=m.NativeX86();cs=Cs(CS_ARCH_X86,CS_MODE_32)
result={}
for address,length in [(0x44b150,320),(0x5147c0,142),(0x5aac00,320)]:
 result[hex(address)]=[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str}for i in cs.disasm(n.read(address,length),address)]
(m.BASE/'reports/native-combat-command-assembly.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps([i for i in result['0x5aac00'] if i['instruction'].startswith('call')],indent=2))
