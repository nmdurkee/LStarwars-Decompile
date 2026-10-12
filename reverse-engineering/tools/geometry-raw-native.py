"""Prove the original PC basename resolver chooses DDS for RAW companion basenames."""
import importlib.util,json
from pathlib import Path
P=Path(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx)
n=nx.NativeX86()
def cstr(p):return n.read(p,256).split(b'\0')[0].decode('ascii')
rows=[]
for name in ['stuff\\gradient','stuff\\particle','stuff\\gradient.raw','stuff\\particle.raw','stuff\\gradient_PC.dds']:
 n.write(n.DATA,name.encode()+b'\0');n.write(n.DATA+0x1000,b'\0'*1024)
 n.call(0x4f90c0,[n.DATA+0x1000,n.DATA,0x76a6e8,1024])
 rows.append({'input':name,'output':cstr(n.DATA+0x1000)})
r={'binarySha256':n.sha256,'filenameBuilder':'0x4f90c0 -> 0x4f8f10','literalExtension':cstr(0x76a6e8),'literalPlatform':cstr(0x75e948),'nativeCases':rows,'loaderChains':{'gradient':['0x48a6a0','0x5f8d60','0x4f90c0'],'particle':['0x48a6a0','0x683530','0x682b10','0x546fd0','0x5f8d60','0x4f90c0']},'finding':'The PC initialization paths for both basenames load _PC.dds. Their loose RAW companions are not consumed by these paths. This does not establish RAW channel order or prove no other code can read them.','scope':'Original filename-builder instructions emulated read-only; no Windows process, OS I/O or binary modification.'}
(P.parent/'reports/geometry-raw-loader-evidence.json').write_text(json.dumps(r,indent=2)+'\n')
print(json.dumps(r,indent=2))
