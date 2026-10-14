"""Exact original4ef660 byte move: unsigned direction choice, live overlapping bytes and branch-specific EAX; no adapters."""
from pathlib import Path
import importlib.util,json,itertools
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86();D=n.DATA;cases=[];checks=0;errors=[]
for destination,source,count in itertools.product([0,1,8,32,64,128],[0,1,8,32,64,128],[0,1,2,3,7,8,15,16,17,31,32,65,127]):
 original=bytes((i*37+19)&255 for i in range(512));n.write(D,original);model=bytearray(original)
 if destination<source:
  for i in range(count):model[destination+i]=model[source+i]
  wanted=D+destination+count
 else:
  for i in range(count-1,-1,-1):model[destination+i]=model[source+i]
  wanted=0
 actual=n.call(0x4ef660,[D+destination,D+source,count],count=20000);final=n.read(D,512)
 for group,a,b in [('return',actual,wanted),('image',final.hex(),bytes(model).hex())]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=dict(destination=destination,source=source,count=count),native=a,model=b))
 cases.append(dict(context=dict(destination=destination,source=source,count=count),inputs=dict(destination=D+destination,source=D+source,count=count),initial=[dict(address=D,bytes=original.hex())],final=[dict(address=D,bytes=final.hex())],returnValue=actual))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=[],closure='Whole4ef660 actual byte move, both direction branches, alias/live overlapping input and native EAX')
(nm.BASE/'reports/script-phase105-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase105-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
