import importlib.util,json,struct
from pathlib import Path
p=Path(__file__).with_name('native-x86.py');s=importlib.util.spec_from_file_location('camera_native',p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
d=Cs(CS_ARCH_X86,CS_MODE_32);out=[]
for a,z in [(0x4509d0,0x710),(0x577790,0xf0),(0x577880,0x100),(0x5765b0,0x50),(0x5b35a0,0x80),(0x5b3620,0x80)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in d.disasm(n.read(a,z),a)];out.append(dict(address=hex(a),instructions=rows))
 if a==0x4509d0:
  for i,row in enumerate(rows):
   if row['mnemonic']=='call'and row['operands']=='0x6e6b90':print(json.dumps(rows[max(0,i-6):i+6],indent=2))
 else:
  if a in [0x577790,0x5765b0]:print(hex(a));print('\n'.join(i['address']+' '+i['mnemonic']+' '+i['operands']for i in rows))
(m.BASE/'reports/native-camera-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=out),indent=2)+'\n')

print(json.dumps(dict(angleConstantBits=n.read(0x7578a0,8).hex(),angleConstant=n.unpack('<d',0x7578a0)[0])))
