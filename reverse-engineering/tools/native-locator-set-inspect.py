import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
d=Cs(CS_ARCH_X86,CS_MODE_32);out=[]
for a,z in [(0x5b3c50,0xb0),(0x43c7a0,0x60),(0x453aa0,0x480),(0x440660,0x180),(0x51fe60,0x90),(0x51fef0,0x190),(0x520080,0x1a0),(0x520220,0x1d0),(0x5d6620,0xed),(0x5b3ec0,0x8f)]:
 rows=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in d.disasm(n.read(a,z),a)];out.append(dict(address=hex(a),instructions=rows))
 if a==0x5b3c50:print(json.dumps(rows,indent=2))
 if False and a==0x453aa0:
  for i,row in enumerate(rows):
   if row['mnemonic']=='call'and row['operands']in['0x440660','0x520220','0x520080','0x51fef0']:print(json.dumps(rows[max(0,i-16):i+4],indent=2))
print('Token at758330: '+n.read(0x758330,64).split(b'\0')[0].decode());(m.BASE/'reports/native-locator-set-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,procedures=out),indent=2)+'\n')
