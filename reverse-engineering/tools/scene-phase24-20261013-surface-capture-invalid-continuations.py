"""Retain original invalid cleanup continuations outside the bounded resolved policy."""
import importlib.util,struct,json
from pathlib import Path
P=Path(__file__).resolve().parent;s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
B=0x29765c8;SP=n.STACK+0xe000;DEV=n.DATA+0x1000;VT=n.DATA+0x2000;EDGE=n.STOP+0x100;n.pack('<I',DEV,VT);n.pack('<I',VT+0x70,EDGE)
def fail(mu,a,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];args=n.unpack('<9I',sp+4);n.pack('<I',args[7],0);mu.reg_write(UC_X86_REG_EAX,0x80004005);mu.reg_write(UC_X86_REG_ESP,sp+40);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,fail,begin=EDGE,end=EDGE)
records=[]
for width,height,residue in [(640,0,0),(1920,0,0),(640,480,0xbad00bad)]:
 n.write(B,bytes(0x800));n.pack('<I',B+4,DEV);n.pack('<I',B+0x138,640);n.pack('<I',0x826494,0);n.pack('<I',SP-8,residue);error=None
 try:n.call(0x6e28e0,[width,height,n.DATA+0x3000],regs={UC_X86_REG_ECX:B})
 except RuntimeError as e:error=str(e)
 assert error and n.mu.reg_read(UC_X86_REG_EIP)==0x6e2ac2
 records.append({'width':width,'height':height,'incomingBufferResidue':residue,'cleanupBufferWord':n.unpack('<I',SP-8)[0],'invalidDereferenceEax':n.mu.reg_read(UC_X86_REG_EAX),'faultInstruction':'0x6e2ac2 mov ecx,[eax]','nativeError':error})
print(json.dumps({'binarySHA256':n.sha256,'cases':records,'interpretation':'Original incoming/local producer is retained, not repaired. Height0 FISTP64 overwrites buffer local; explicit height retains residue. These unresolved-pointer continuations are outside source/native resolved-object scope. No actual OS/game execution.'},indent=2))
