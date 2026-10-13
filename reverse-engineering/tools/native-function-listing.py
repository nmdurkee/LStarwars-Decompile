"""Linear capstone listing of one original PC function, ending at its final ret.
Usage: native-function-listing.py <entry-hex> <end-hex> <output>
The end address is the address of the closing ret; listings use the
"address  mnemonic operands" format of the existing *-assembly.txt reports.
"""
import sys,struct
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent
sys.path.insert(0,str(BASE/'tools/python-packages'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
blob=(BASE/'binary/LEGOStarWarsSaga.packed.exe.unpacked.exe').read_bytes()
u16=lambda o:struct.unpack_from('<H',blob,o)[0];u32=lambda o:struct.unpack_from('<I',blob,o)[0]
p=u32(0x3c);opt=p+24;image=u32(opt+28)
def offset(va):
    for i in range(u16(p+6)):
        q=opt+u16(p+20)+40*i;rva,vsize,rawsize,rawoff=u32(q+12),u32(q+8),u32(q+16),u32(q+20)
        if image+rva<=va<image+rva+max(vsize,rawsize):return rawoff+va-image-rva
    raise ValueError(hex(va))
entry,end=int(sys.argv[1],16),int(sys.argv[2],16)
code=blob[offset(entry):offset(end)+16]
lines=[]
for ins in Cs(CS_ARCH_X86,CS_MODE_32).disasm(code,entry):
    lines.append(f'{ins.address:08x}  {ins.mnemonic} {ins.op_str}'.rstrip())
    if ins.address>=end:break
Path(sys.argv[3]).write_text('\n'.join(lines)+'\n',encoding='utf8')
print(len(lines),'instructions')
