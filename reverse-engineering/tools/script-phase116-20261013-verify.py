"""Actual four release CRT file leaves and complete public size/read/seek/close CRT branches. No hooks."""
from pathlib import Path
import importlib.util,json,itertools
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX
D=n.DATA;segments=[(D,512),(0x8ceb50,256)];cases=[];checks=0;errors=[]
def snap():return[dict(address=p,bytes=n.read(p,z).hex())for p,z in segments]
def run(c):
 global checks
 for p,z in segments:n.write(p,bytes((i*37+c['seed'])&255 for i in range(z)))
 initial=snap();method=c['method'];args=c['args'];input=dict(first=args[0]if args else 0,second=args[1]if len(args)>1 else 0,path=args[2]if len(args)>2 else 0,mode=args[3]if len(args)>3 else 0,reserved=args[4]if len(args)>4 else 0);returns=[]
 if method=='Lifecycle':
  h,buffer,count,lo,hi,origin=args;input=dict(handle=h,destination=buffer,count=count,low=lo,high=hi,origin=origin);r=n.call(0x4f6b40,[h],regs={UC_X86_REG_EAX:c['seed'],UC_X86_REG_EDX:0xffffffff});returns.append(r|(n.mu.reg_read(UC_X86_REG_EDX)<<32));returns.append(n.call(0x4fb550,[h,buffer,count]));r=n.call(0x4f6de0,[h,lo,hi,origin],regs={UC_X86_REG_EDX:0xffffffff});returns.append(r|(n.mu.reg_read(UC_X86_REG_EDX)<<32));returns.append(n.call(0x4f99e0,[h]));actual=returns[-1]
 else:actual=n.call({'CrtOpen':0x6dee30,'CrtSize':0x6dee40,'CrtRead':0x6dee50,'CrtSeek':0x6dee60}[method],args,regs={UC_X86_REG_EAX:c['seed'],UC_X86_REG_EDX:0xffffffff})
 final=snap()
 for group,a,b in[('return',actual,0),('images',final,initial),('lifecycle',returns,[0]*len(returns))]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=input,initial=initial,final=final,returnValue=actual,lifecycleReturns=returns))
for method,seed,args in itertools.product(['CrtOpen','CrtSize','CrtRead','CrtSeek'],[0,1,0xffffffff,0x80000000,0xdeadbeef],[[],[0],[0,0],[1,0xffffffff],[0xffffffff,1],[1,2,3,4,5],[0xffffffff,0x80000000,0,0xffffffff,1]]):run(dict(method=method,seed=seed,args=args))
for h,count,offset in itertools.product([0x1000,0x1001,0x1007,0x10000,0x7fffffff],[0,1,17,0xffffffff,0x80000000],[[0,0,0],[0xffffffff,0x80000000,1],[0x80000000,0xffffffff,2],[123,456,7]]):run(dict(method='Lifecycle',seed=0xffffffff,args=[h,0 if count&1 else D+32,count]+offset))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=4,ports=[],closure='Actual6dee30/40/50/60 releasefilezero leaves; full4f6b40size/4fb550read/4f6de0seek/4f99e0close CRTbranches naturallyusezero bodies, nohooks')
(nm.BASE/'reports/script-phase116-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase116-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
