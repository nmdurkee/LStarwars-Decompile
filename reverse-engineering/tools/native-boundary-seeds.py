"""Create transparent boundary hypotheses for Ghidra; never edit the input binary."""
import sys, json, struct, hashlib
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent
sys.path.insert(0,str(BASE/'tools/python-packages'))
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
blob=(BASE/'binary/LEGOStarWarsSaga.packed.exe.unpacked.exe').read_bytes()
report=json.loads((BASE/'reports/native-boundary-candidates.json').read_text())
md=Cs(CS_ARCH_X86,CS_MODE_32)
# Original PE mapping has text raw offset equal to RVA, independently recorded in unpacked-pe/pe.json.
text_start=0x401000;text_end=text_start+3471070
calls={};pointers={}
for off in range(0x1000,0x1000+3471070-5):
    if blob[off]==0xe8:
        target=0x400000+off+5+struct.unpack_from('<i',blob,off+1)[0]
        if text_start<=target<text_end:calls.setdefault(target,[]).append(hex(0x400000+off))
for off in range(3477504,4124672+417792-3,4):
    target=struct.unpack_from('<I',blob,off)[0]
    if text_start<=target<text_end:pointers.setdefault(target,[]).append(hex(0x400000+off))
rows=[];selected=[]
banned={'in','out','insb','insd','outsb','outsd','hlt','cli','sti','iret','iretd','int','int3','ud2','aaa','aas','aam','aad','daa','das','bound','arpl','into'}
for candidate in [{'address':'0x401000','padding':0,'sectionEntry':True}]+report['candidates']:
    a=int(candidate['address'],16);off=a-0x400000
    ins=list(md.disasm(blob[off:off+32],a))
    prefix=[]
    for i in ins:
        if i.mnemonic=='int3':break
        prefix.append({'address':hex(i.address),'size':i.size,'mnemonic':i.mnemonic,'operands':i.op_str})
        if i.mnemonic.startswith('ret') or i.mnemonic=='jmp':break
    plausible=bool(prefix) and not any(i['mnemonic'] in banned for i in prefix)
    observed_calls=calls.get(a,[]);observed_pointers=pointers.get(a,[])
    accepted=plausible and (candidate['padding']>=2 or observed_calls or observed_pointers or candidate.get('sectionEntry'))
    row={**candidate,'prefix':prefix,'candidateDirectCallByteLocations':observed_calls,'alignedDataPointers':observed_pointers,'accepted':bool(accepted),'reason':'plausible instruction prefix and INT3 boundary or reference' if accepted else 'ambiguous boundary or implausible instruction prefix'}
    rows.append(row)
    if accepted:selected.append(a)
old=(BASE/'references/native-analysis-seeds.tsv').read_text()
old_addresses=[int(l.split()[0],16) for l in old.splitlines() if l and not l.startswith('#')]
addresses=sorted(set(old_addresses+selected))
seed='# Caller-asserted function hypotheses, including INT3 boundary candidates. See reports/native-boundary-seeds.json.\n'+''.join(f'{a:#x}\tfunction\n' for a in addresses)
(BASE/'references/native-expanded-seeds.tsv').write_text(seed)
out={'binarySha256':hashlib.sha256(blob).hexdigest(),'seedSha256':hashlib.sha256((BASE/'references/native-expanded-seeds.tsv').read_bytes()).hexdigest(),'seedCount':len(addresses),'priorDispatchSeeds':len(old_addresses),'boundaryCandidates':len(rows),'acceptedNewCandidates':len(selected),'method':'Previously unrecognized, 16-byte aligned initialized .text addresses immediately after INT3 bytes. Decode a bounded x86 instruction prefix; reject privileged/invalid-looking prefixes. Require >=2 padding bytes, a candidate direct CALL-byte reference, an aligned data pointer, or .text entry. Preserve all prior dispatch seeds.','limits':['These are caller assertions for additional analysis, not verified original function boundaries or symbol identities.','Raw E8 and pointer scans can include coincidental bytes and do not alone prove instruction references.','Some valid functions are unaligned or lack INT3 padding; this is not a complete function inventory.'],'candidates':rows}
(BASE/'reports/native-boundary-seeds.json').write_text(json.dumps(out,indent=2))
print(json.dumps({k:v for k,v in out.items() if k!='candidates'},indent=2))
