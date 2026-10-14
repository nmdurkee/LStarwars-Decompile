import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent;s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
print(json.dumps({'factorWord':n.unpack('<I',0x751ab8)[0],'forward':list(n.unpack('<10I',0x5f79b4)),'reverseBranches':list(n.unpack('<4I',0x5f7a0c)),'reverseBytes':n.read(0x5f7a1c,63).hex(),'multisample':list(n.unpack('<5I',0x828230))},indent=2))
