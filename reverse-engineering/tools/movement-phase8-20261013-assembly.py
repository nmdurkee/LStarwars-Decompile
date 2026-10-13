import importlib.util,json
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from capstone import *
n=m.NativeX86();cs=Cs(CS_ARCH_X86,CS_MODE_32);cs.detail=True;rows={};strings={}
def cstr(a):
 b=bytearray()
 for j in range(128):
  v=n.read(a+j,1)[0]
  if not v:return b.decode('ascii')
  b.append(v)
 return None
for va,size in[(0x4505d0,0x270),(0x44d870,0x100),(0x51ad80,0x70),(0x51adf0,0x100),(0x407d00,0x100),(0x4cbf70,0x170),(0x4817e0,0x120)]:
 out=[]
 for i in cs.disasm(n.read(va,size),va):
  out.append({'va':hex(i.address),'bytes':i.bytes.hex(),'assembly':i.mnemonic+' '+i.op_str})
  if i.mnemonic=='push'and len(i.operands)==1 and i.operands[0].type==CS_OP_IMM and 0x750000<=i.operands[0].imm<0x780000:
   try:strings[hex(i.operands[0].imm)]=cstr(i.operands[0].imm)
   except:pass
 rows[hex(va)]=out
(m.BASE/'reports/movement-phase8-20261013-assembly.json').write_text(json.dumps({'binarySha256':n.sha256,'rows':rows,'strings':strings},indent=2)+'\n')
print(json.dumps(strings));print('\n'.join(r['va']+' '+r['assembly']for r in rows['0x44d870']))
