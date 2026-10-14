"""Original cfltcvt initializer96bytes, raw function pointers, EAX result and all preserved data/registers."""
import importlib.util,json,random,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EBX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESI,UC_X86_REG_EDI
values=[0x6ee9f9,0x6ee09e,0x6ee05c,0x6ee090,0x6ee006,0x6ee9f9,0x6ee973,0x6ee01c,0x6edf86,0x6edf15];rng=random.Random(168);cases=[];errors=[];checks=0;reg=[UC_X86_REG_EAX,UC_X86_REG_EBX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESI,UC_X86_REG_EDI]
for i in range(318):
 before=bytes(rng.randrange(256)for j in range(56));n.write(0x829a78,before);initial=[dict(address=0x829a78,bytes=before.hex())];inputs=[rng.getrandbits(32)for r in reg];got=n.call(0x6e68ac,[],regs=dict(zip(reg,inputs)));registers=[n.mu.reg_read(r)for r in reg];after=n.read(0x829a78,56);expected=before[:8]+struct.pack('<10I',*values)+before[48:];want=[values[0]]+inputs[1:];checks+=7
 if after!=expected or registers!=want:errors.append(dict(group='Initializer',nativeRegisters=registers,expectedRegisters=want,nativeImage=after.hex(),expectedImage=expected.hex()))
 cases.append(dict(initial=initial,returnValue=got,final=[dict(address=0x829a78,bytes=after.hex())],initialRegisters=inputs,finalRegisters=registers))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=[])
(nm.BASE/'reports/script-phase168-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase168-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
