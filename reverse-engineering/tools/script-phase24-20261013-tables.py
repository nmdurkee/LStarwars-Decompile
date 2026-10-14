import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
def text(p):
 b=[]
 while n.read(p,1)!=b'\0':b.append(n.read(p,1)[0]);p+=1
 return bytes(b).decode('latin1')
for p in [0x75ffc8,0x75ffb4,0x75ffb0,0x755ba8,0x75ff74,0x760420,0x758460,0x76041c,0x7533c8,0x7533c4,0x760418,0x760414,0x760410]:print(hex(p),repr(text(p)))
rows=[]
p=0x801768
while n.unpack('<I',p)[0]:
 q=n.unpack('<3I',p);rows.append(dict(address=hex(p),name=text(q[0]),handler=hex(q[1]),word=hex(q[2])));p+=12
print(json.dumps(rows))
