import sys,json,struct
from pathlib import Path
b=Path(__file__).resolve().parent.parent
sys.path.insert(0,str(b/'tools/python-packages'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
blob=(b/'binary/LEGOStarWarsSaga.packed.exe.unpacked.exe').read_bytes();pe=json.loads((b/'reports/unpacked-pe/pe.json').read_text());md=Cs(CS_ARCH_X86,CS_MODE_32)
out=[]
for a in json.loads((b/'reports/native-supplemental-targets.json').read_text()):
 v=int(a,16);sec=next(s for s in pe['sections'] if pe['imageBase']+s['rva']<=v<pe['imageBase']+s['rva']+s['size']);o=v-pe['imageBase']-sec['rva']+sec['offset'];ins=list(md.disasm(blob[o:o+48],v))[:7]
 out.append({'address':a,'bytes':blob[o:o+24].hex(),'instructions':[hex(i.address)+' '+i.mnemonic+' '+i.op_str for i in ins]})
(b/'reports/native-supplemental-entry-inspection.json').write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps(out,indent=2))
