"""Original release CRT close/poll leaves and complete public close CRT handle path. No hooks."""
from pathlib import Path
import importlib.util,json,itertools
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_EDI,UC_X86_REG_ESI,UC_X86_REG_EBP
D=n.DATA;segments=[(D,512),(0x829570,4),(0x8ceb50,256)];cases=[];errors=[];checks=0
regs=[UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_EDI,UC_X86_REG_ESI,UC_X86_REG_EBP]
def snap():return[dict(address=p,bytes=n.read(p,z).hex())for p,z in segments]
def run(method,args,seed):
 global checks
 for p,z in segments:n.write(p,bytes((i*37+seed)&255 for i in range(z)))
 initial=snap();inputs=dict(first=args[0]if args else 0,second=args[1]if len(args)>1 else 0,handle=args[0]if args else 0);values={r:(seed+i*0x11223344)&0xffffffff for i,r in enumerate(regs)};values[UC_X86_REG_EAX]=seed;actual=n.call({'CrtClose':0x6dee70,'Poll':0x6dee90,'Close':0x4f99e0}[method],args,regs=values);final=snap();registers=[n.mu.reg_read(r)for r in regs]
 for group,a,b in [('return',actual,0),('images',final,initial),('preservedRegisters',registers,[values[r]for r in regs])]:
  checks+=1
  if a!=b:errors.append(dict(method=method,args=args,seed=seed,group=group,native=a,model=b))
 cases.append(dict(method=method,inputs=inputs,args=args,initial=initial,final=final,returnValue=actual,seed=seed,preservedRegisters=registers))
for method,seed,args in itertools.product(['CrtClose','Poll'],[0,1,0xffffffff,0x80000000,0xdeadbeef],[[],[0],[0,0],[1,0xffffffff],[0xffffffff,1],[D,0x80000000],[1,2,3,4]]):run(method,args,seed)
for handle,seed in itertools.product([0x1000,0x1001,0x1007,0x1fff,0x10000,0x7fffffff],[0,1,0xffffffff,0x80000000,0xdeadbeef]):run('Close',[handle],seed)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=2,ports=[],closure='Actual6dee70/6dee90 release zero leaves; whole4f99e0 CRT descriptor path→actual6dee70, without close/poll hooks')
(nm.BASE/'reports/script-phase112-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase112-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
