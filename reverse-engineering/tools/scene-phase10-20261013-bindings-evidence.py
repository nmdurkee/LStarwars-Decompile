import importlib.util,struct,json
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);c.skipdata=True
data=n.read(0x401000,0x349000);addresses=[0x80e694,0x80e698,0x80202c,0x802030,0x80e9bc,0x80e9c8,0x80e9d8]
results={}
for target in addresses:
 refs=[];needle=struct.pack('<I',target);start=0
 while True:
  at=data.find(needle,start)
  if at<0:break
  va=0x401000+at;start=at+1;candidates=[]
  for begin in range(max(0,at-10),at):
   ins=list(c.disasm(data[begin:at+16],0x401000+begin,count=1))
   if ins and ins[0].address+len(ins[0].bytes)>=va+4 and ins[0].address<=va:
    i=ins[0];candidates.append({'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})
  refs.append({'encodedAddress':hex(va),'candidates':candidates})
 results[hex(target)]=refs
print(json.dumps({'binarySHA256':n.sha256,'references':results},indent=2))
