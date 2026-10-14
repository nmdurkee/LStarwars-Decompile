import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent;s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
print(json.dumps({'aspectWords':list(n.unpack('<3I',0x7519a8)),'jumpTable':list(n.unpack('<4I',0x6e2ad8))},indent=2))
