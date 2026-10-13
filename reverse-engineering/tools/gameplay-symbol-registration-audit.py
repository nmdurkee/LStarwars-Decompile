"""PE reference audit and bounded original startup callback registration."""
import importlib.util,json,struct,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();b=n.blob;BASE=m.BASE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from unicorn import UC_HOOK_CODE,UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
u16=lambda o:struct.unpack_from('<H',b,o)[0];u32=lambda o:struct.unpack_from('<I',b,o)[0];pe=u32(0x3c);opt=pe+24;base=u32(opt+28);sections=[]
for i in range(u16(pe+6)):
 q=opt+u16(pe+20)+40*i;sections.append(dict(name=b[q:q+8].split(b'\0')[0].decode(),va=base+u32(q+12),virtualSize=u32(q+8),rawSize=u32(q+16),rawOffset=u32(q+20),flags=u32(q+36)))
references={}
for target in [0x9238c0,0x517020,0x517040]:
 literals=[];branches=[]
 for section in sections:
  va=section['va'];blob=b[section['rawOffset']:section['rawOffset']+section['rawSize']];needle=struct.pack('<I',target);index=blob.find(needle)
  while index>=0:literals.append(dict(section=section['name'],address=hex(va+index)));index=blob.find(needle,index+1)
  if section['flags']&0x20000000:
   for index,opcode in enumerate(blob[:-4]):
    if opcode in [0xe8,0xe9] and va+index+5+struct.unpack_from('<i',blob,index+1)[0]==target:branches.append(dict(section=section['name'],address=hex(va+index),opcode=hex(opcode)))
 references[hex(target)]=dict(literals=literals,relativeBranches=branches)
d=Cs(CS_ARCH_X86,CS_MODE_32);instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str) for i in d.disasm(n.read(0x43c830,0x161),0x43c830)]
initial=n.unpack('<I',0x9238c0)[0];tail=[];writes=[];rows=[];errors=[]
def tail_hook(mu,address,size,user):
 tail.append(hex(address));sp=mu.reg_read(UC_X86_REG_ESP);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
def write_hook(mu,access,address,size,value,user):writes.append(dict(address=hex(address),size=size,value=value))
for address in [0x4816b0,0x4cbda0,0x407ad0]:n.mu.hook_add(UC_HOOK_CODE,tail_hook,begin=address,end=address)
n.mu.hook_add(UC_HOOK_MEM_WRITE,write_hook,begin=0x9238c0,end=0x9238c3)
for pointer,firstMode,secondMode in itertools.product([0,0x12345678,0xdeadbeef],[0,1],[0,1]):
 n.pack('<I',0x9238c0,pointer);n.pack('<I',0x876580,firstMode);n.pack('<I',0x7f39e4,secondMode);tail.clear();writes.clear();n.call(0x43c830,[],count=20000)
 got=dict(symbolCallback=n.unpack('<I',0x9238c0)[0],movementCallback=n.unpack('<I',0x9238b0)[0],symbolWrites=writes.copy(),tail=tail.copy());want=dict(symbolCallback=pointer,movementCallback=0x43c0c0,symbolWrites=[],tail=[hex(0x4816b0 if firstMode else 0x4cbda0 if secondMode else 0x407ad0)])
 if got!=want:errors.append(dict(pointer=hex(pointer),modeFlags=[firstMode,secondMode],got=got,want=want))
 rows.append(dict(initialSymbolCallback=hex(pointer),modeFlags=[firstMode,secondMode],native=got))
section=next(s for s in sections if s['va']<=0x9238c0<s['va']+max(s['virtualSize'],s['rawSize']))
report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),errors=errors,initialLoadedSymbolCallback=initial,containingSection=section,references=references,registrationCases=rows,startupInstructions=instructions,sourceEvidence=['reverse-engineering/decompiled/corpus-expanded/FUN_43c830.c','reverse-engineering/decompiled/corpus-expanded/FUN_517020.c','reverse-engineering/decompiled/corpus-expanded/FUN_513230.c','reverse-engineering/decompiled/corpus-expanded/FUN_514850.c'],conclusion='No actual game-symbol producer was found in this PC startup registration. The loaded callback pointer is zero, and original43c830 leaves it unchanged while registering the real movement callback43c0c0. Setter517020 has no literal pointer or directE8/E9 reference in the full stored PE scan; the callback global has only the two resolver reads and setter write as literal references.',bounds=['Original43c830 and every callback/table setter run unchanged. Its three downstream startup tail targets are explicit return adapters; no full game launch occurs.','Raw literal/direct-relative-reference absence cannot exclude computed indirect calls, pointer arithmetic writes, external modifications, or a later startup path. Production callback availability remains qualified, not globally proven impossible.','No portable source or new native-function mappings are credited; this is registration/reference evidence.'])
(BASE/'reports/gameplay-symbol-registration-audit.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-symbol-registration-audit.txt').write_text('\n'.join([report['conclusion'],'',f'{len(rows)} original startup registration cases; {len(errors)} mismatches. Loaded callback pointer: {initial}.','','Scope',*report['bounds']])+'\n',encoding='utf8');print(json.dumps({k:report[k] for k in ['checks','mismatches','initialLoadedSymbolCallback','references','conclusion']}))
if errors:raise SystemExit(1)
