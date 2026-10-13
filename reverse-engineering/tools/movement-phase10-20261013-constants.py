from pathlib import Path
import importlib.util,json
s=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();print(json.dumps({'angleScale':n.unpack('<d',0x7578a0)[0],'goal':n.unpack('<f',0x7552e8)[0],'ahead':n.unpack('<f',0x75170c)[0],'turnWord':n.read(0x75823c,12).hex()}))
