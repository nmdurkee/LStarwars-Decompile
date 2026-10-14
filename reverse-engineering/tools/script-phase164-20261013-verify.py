"""Original149-byte aulldvrm, every output register, preserved registers, RET16 and caller words."""
import importlib.util,json,random,struct,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_EBX,UC_X86_REG_ECX,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_ESP
cases=[];errors=[];checks=0;corrections=0;low=high=0

def hook(mu,address,size,data):
 global corrections
 if address==0x701fad:corrections+=1
n.mu.hook_add(UC_HOOK_CODE,hook)
regs=[UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_EBX,UC_X86_REG_ECX,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_ESP]
rng=random.Random(164)
def execute(numerator,divisor):
 global checks,low,high
 a=[numerator&0xffffffff,numerator>>32,divisor&0xffffffff,divisor>>32];si=rng.getrandbits(32);di=rng.getrandbits(32);n.call(0x701f40,a,regs={UC_X86_REG_ESI:si,UC_X86_REG_EDI:di,UC_X86_REG_EAX:0xdeadbeef,UC_X86_REG_ECX:0xbadcafe,UC_X86_REG_EBX:0xffffffff});got=[n.mu.reg_read(r)for r in regs];q,r=divmod(numerator,divisor);want=[q&0xffffffff,q>>32,r>>32,r&0xffffffff,si,di,n.STACK+0xe014];actual=n.read(n.STACK+0xe004,16).hex();expected=struct.pack('<4I',*a).hex();checks+=8
 if got!=want or actual!=expected:errors.append(dict(numerator=numerator,divisor=divisor,native=got,model=want,argsNative=actual,argsExpected=expected))
 low+=divisor>>32==0;high+=divisor>>32!=0;cases.append(dict(inputs=dict(numeratorLow=a[0],numeratorHigh=a[1],divisorLow=a[2],divisorHigh=a[3]),registers=got,preservedArgs=actual))
values=[0,1,2,3,31,32,255,65535,0x7fffffff,0x80000000,0xffffffff,0x100000000,0x100000001,0x1ffffffff,0x7fffffffffffffff,0x8000000000000000,0xfffffffffffffffe,0xffffffffffffffff]
for numerator,divisor in itertools.product(values,values[1:]):execute(numerator,divisor)
for i in range(2200):execute(rng.getrandbits(64),rng.getrandbits(64)or 1)
for i in range(1200):execute(rng.getrandbits(64),rng.getrandbits(32)or 1)
for i in range(800):
 divisor=rng.getrandbits(63)or 1;k=rng.randrange(1,min(64,0xffffffffffffffff//divisor)+1)
 for delta in[-1,0,1]:
  numerator=divisor*k+delta
  if 0<=numerator<=0xffffffffffffffff:execute(numerator,divisor)
faults=0
for numerator in values:
 try:n.call(0x701f40,[numerator&0xffffffff,numerator>>32,0,0]);errors.append(dict(group='ZeroDivisor',numerator=numerator))
 except RuntimeError:faults+=1
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],zeroDivisorFaults=faults,lowDivisorPathCases=low,highDivisorPathCases=high,approximationCorrections=corrections,managedExecution=False,newEntries=1,ports=[])
(nm.BASE/'reports/script-phase164-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase164-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
