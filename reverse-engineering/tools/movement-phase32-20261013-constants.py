from pathlib import Path
import importlib.util,json,struct
sp=importlib.util.spec_from_file_location('nx',Path('reverse-engineering/tools/native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);n=m.NativeX86()
print(json.dumps({hex(a):dict(bits=n.read(a,8).hex(),value=n.unpack('<d',a)[0])for a in[0x75d4f0,0x7531a8,0x751a90,0x7516b8]}))
