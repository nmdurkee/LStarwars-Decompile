import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
out={}
for a,end in [(0x4078d0,0x407ad0),(0x4813d0,0x481500),(0x4cbba0,0x4cbda0),(0x520440,0x520450)]:
 ins=[]
 for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,end-a),a):
  if i.mnemonic=='int3':break
  ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str))
 out[hex(a)]=ins
tables=[]
for a in [0x7ef2c0,0x7fcf10,0x7fa2d0]:
 rows=[]
 for i in range(64):
  mask,ptr=n.unpack('<II',a+i*8);rows.append(dict(mask=hex(mask),address=hex(ptr)))
  if not ptr:break
 tables.append(dict(address=hex(a),rows=rows))
registration=[]
for a in [0x407ad0,0x4816b0,0x4cbda0]:
 ins=[]
 for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,256),a):
  ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str))
  if i.mnemonic=='call' and i.op_str=='0x520440':break
 registration.append(dict(initializer=hex(a),instructions=ins))
report=dict(binarySha256=n.sha256,functions=out,tables=tables,registration=registration);(x.BASE/'reports/gameplay-path-dispatch-audit.json').write_text(json.dumps(report,indent=2),encoding='utf8')
print(json.dumps(dict(tables=tables,variant=out['0x4813d0']),indent=2))
