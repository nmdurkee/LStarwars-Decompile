import importlib.util,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
D=n.DATA;n.write(D,bytes(0x60000));n.write(D+0x80,b'levels\\test\\test_a\0');n.pack('<I',D+0x104,D+0x10001);n.pack('<I',0x91ee88,0);n.pack('<I',0x91ee94,0)
def hook(mu,a,z,u):
 if a!=0x4ff120:return
 sp=mu.reg_read(UC_X86_REG_ESP);q=n.unpack('<I',sp+4)[0];print('exists:',n.read(q,100).split(b'\0')[0]);mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,hook,begin=0x4ff120,end=0x4ff120)
n.call(0x57a420,[D],count=10000000);print('cursor',hex(n.unpack('<I',D+0x104)[0]),'count',n.unpack('<I',D+0x10c)[0],'error',hex(n.unpack('<I',0x91eea4)[0]))
