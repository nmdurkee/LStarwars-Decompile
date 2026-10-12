"""Read-only isolated x86 function harness. Does not run the Windows game or OS APIs."""
import sys, struct, hashlib
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent
sys.path.insert(0,str(BASE/'tools/python-packages'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UcError
from unicorn.x86_const import *
class NativeX86:
    STACK=0x10000000
    DATA=0x10100000
    STOP=0x10200000
    def __init__(self):
        self.blob=(BASE/'binary/LEGOStarWarsSaga.packed.exe.unpacked.exe').read_bytes()
        self.sha256=hashlib.sha256(self.blob).hexdigest()
        u16=lambda o:struct.unpack_from('<H',self.blob,o)[0]
        u32=lambda o:struct.unpack_from('<I',self.blob,o)[0]
        p=u32(0x3c); opt=p+24; base=u32(opt+28); size=u32(opt+56)
        self.mu=Uc(UC_ARCH_X86,UC_MODE_32)
        self.mu.mem_map(base,(size+4095)&~4095)
        self.mu.mem_write(base,self.blob[:u32(opt+60)])
        for i in range(u16(p+6)):
            q=opt+u16(p+20)+40*i; rva,rawsize,rawoff=u32(q+12),u32(q+16),u32(q+20)
            if rawsize:self.mu.mem_write(base+rva,self.blob[rawoff:rawoff+rawsize])
        self.mu.mem_map(self.STACK,0x10000)
        self.mu.mem_map(self.DATA,0x100000)
        self.mu.mem_map(self.STOP,0x1000)
        self.mu.reg_write(UC_X86_REG_FPCW,0x37f)
        self.mu.reg_write(UC_X86_REG_FPSW,0)
        self.mu.reg_write(UC_X86_REG_FPTAG,0xffff)
        self.context=self.mu.context_save()
    def write(self,address,value):self.mu.mem_write(address,bytes(value))
    def read(self,address,size):return bytes(self.mu.mem_read(address,size))
    def unpack(self,fmt,address):return struct.unpack(fmt,self.read(address,struct.calcsize(fmt)))
    def pack(self,fmt,address,*values):self.write(address,struct.pack(fmt,*values))
    def call(self,address,args=(),regs=None,count=200000):
        self.mu.context_restore(self.context)
        sp=self.STACK+0xe000
        self.pack('<'+'I'*(1+len(args)),sp,self.STOP,*[(a&0xffffffff) for a in args])
        self.mu.reg_write(UC_X86_REG_ESP,sp)
        for r,v in (regs or {}).items():self.mu.reg_write(r,v)
        try:self.mu.emu_start(address,self.STOP,count=count)
        except UcError as e:raise RuntimeError(f'{e} at {self.mu.reg_read(UC_X86_REG_EIP):#x} in function {address:#x}') from e
        if self.mu.reg_read(UC_X86_REG_EIP)!=self.STOP:raise RuntimeError(f'Instruction limit in function {address:#x}')
        return self.mu.reg_read(UC_X86_REG_EAX)
