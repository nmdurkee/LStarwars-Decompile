"""Complete15-byte security cookie gate; mismatch stops at original report-gsfailure boundary."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
import random
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDI,UC_X86_REG_ESI,UC_X86_REG_EBX,UC_X86_REG_ESP,UC_X86_REG_EIP
COOKIE=0x829570;cases=[];errors=[];checks=0;events=[]
def hook203(mu,address,size,data):
 if address!=0x6eeac7:return
 events.append(dict(callback=address,cookie=mu.reg_read(UC_X86_REG_ECX),eaxSeed=mu.reg_read(UC_X86_REG_EAX)))
 mu.reg_write(UC_X86_REG_EIP,n.STOP);mu.emu_stop()
n.mu.hook_add(UC_HOOK_CODE,hook203)
def run203(expected,actual,seed):
 global checks,events
 n.pack('<I',COOKIE,expected);before=n.read(COOKIE,4);events=[];registers={UC_X86_REG_EAX:seed,UC_X86_REG_ECX:actual,UC_X86_REG_EBX:0x12345678,UC_X86_REG_ESI:0xfedcba98,UC_X86_REG_EDI:0x80000000};got=n.call(0x6e693a,[],regs=registers);failure=expected!=actual;wantEvents=[dict(callback=0x6eeac7,cookie=actual,eaxSeed=seed)]if failure else[]
 for group,a,b in [('boundary',bool(events),failure),('return',None if failure else got,None if failure else seed),('image',n.read(COOKIE,4),before),('events',events,wantEvents),('registers',[n.mu.reg_read(r)for r in registers],[registers[r]for r in registers])]:
  checks+=1
  if a!=b:errors.append(dict(group=group,expected=expected,cookie=actual,seed=seed,native=a if group!='image'else a.hex(),model=b if group!='image'else b.hex()))
 cases.append(dict(inputs=dict(cookie=actual,eaxSeed=seed),initial=[dict(address=COOKIE,bytes=before.hex())],final=[dict(address=COOKIE,bytes=before.hex())],failureBoundary=failure,returnValue=None if failure else got,nativeEvents=events.copy()))
values=[0,1,0xffffffff,0x80000000,0x7fffffff,0xbb40e64e]
for expected,actual,seed in itertools.product(values,values,values):run203(expected,actual,seed)
rng=random.Random(203)
for i in range(512):
 expected=rng.getrandbits(32);actual=expected if i&1 else rng.getrandbits(32);run203(expected,actual,rng.getrandbits(32))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],failureBoundaryCases=sum(c['failureBoundary']for c in cases),managedExecution=False,newEntries=1,ports=['6EEAC7 nonreturning report-gsfailure boundary'],closure='Entire cookie compare/normal return/failuretailjump; GPR/eax preservation, live globalcookie read; failure child explicitly stopped, not recovered')
(nm.BASE/'reports/script-phase203-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase203-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
