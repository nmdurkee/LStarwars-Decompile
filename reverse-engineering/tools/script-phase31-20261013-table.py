import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32)

for at in range(0x801720,0x801768,8):
 p,f=n.unpack('<II',at);s=[]
 if not p:break
 while n.unpack('<B',p)[0]:s.append(n.unpack('<B',p)[0]);p+=1
 print(hex(at),bytes(s),hex(f))
