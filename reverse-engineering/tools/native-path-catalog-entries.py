"""Preserve independently verified path callback entry boundaries absent from Ghidra exports."""
import json,hashlib,importlib.util
from pathlib import Path
p=Path(__file__).with_name('native-x86.py');s=importlib.util.spec_from_file_location('native_path_catalog',p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
dis=Cs(CS_ARCH_X86,CS_MODE_32);index_path=B/'reports/native-verified-entry-index.json';index=json.loads(index_path.read_text());assert index['binarySha256']==n.sha256
entries={r['address']:r for r in index['items']}
for address,end,name,evidence,provenance in [(0x4813d0,0x4814fe,'PathActionDispatchVariant1','reports/gameplay-path-dispatch-assembly.json;reports/gameplay-path-dispatch-audit.json;reports/gameplay-path-dispatch-tests.json','Registered4816b0 ->520440 ->global9238fc; original callback execution; RET4814fd followed byINT3 padding to481500.')]:
 raw=n.read(address,end-address);instructions=list(dis.disasm(raw,address));assert instructions[-1].mnemonic=='ret'and instructions[-1].address+instructions[-1].size==end
 rel='native-disassembly/'+hex(address)[2:]+'.asm';lines=['; Original PC disassembly, not original source or decompiler pseudocode.','; '+provenance,'; Binary SHA256 '+n.sha256,'; Range '+hex(address)+'..'+hex(end)+' exclusive; bytes SHA256 '+hashlib.sha256(raw).hexdigest()]+[hex(i.address)+'  '+i.bytes.hex()+'  '+i.mnemonic+' '+i.op_str for i in instructions]
 (B/rel).write_text('\n'.join(lines)+'\n');entries[hex(address)]=dict(address=hex(address),name=name,file=rel,status='ok',evidence=evidence)
index.update(expected=len(entries),processed=len(entries),failed=0,items=sorted(entries.values(),key=lambda x:int(x['address'],16)));index_path.write_text(json.dumps(index,indent=2)+'\n');print(json.dumps({'verifiedEntries':len(entries),'addedPathEntries':1}))
