import importlib.util,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
def text(a):
 b=[]
 while n.read(a,1)!=b'\0':b.append(n.read(a,1)[0]);a+=1
 return bytes(b).decode('latin1')
for i in range(16):
 a,c=n.unpack('<2I',0x810470+i*8)
 print(hex(0x810470+i*8),hex(a),text(a) if a else '',hex(c))
 if not a:break
