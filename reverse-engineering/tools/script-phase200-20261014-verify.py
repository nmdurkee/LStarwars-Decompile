"""Original CRT strrchr45 and strncpy292 bytes; no hooks, prepared padded backing."""
import importlib.util,json,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn.x86_const import UC_X86_REG_EFLAGS
D=n.DATA;cases=[];checks=0;errors=[]
def run(method,payload,sa,da,count=0,target=0,same=False):
 global checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x1000)));source=D+0x100+sa;destination=source if same else D+0x800+da;n.write(source,payload+b'\0');before=n.read(D,0x1000);model=bytearray(before)
 if method=='Copy':
  if count:
   for i in range(count):model[destination-D+i]=payload[i]if i<len(payload)else 0
  want=destination;address=0x6e7c00;args=[destination,source,count]
 else:
  char=target&255;index=(payload+b'\0').rfind(bytes([char]));want=source+index if index>=0 else 0;address=0x6e7d30;args=[source,target]
 actual=n.call(address,args,count=1000000);after=n.read(D,0x1000)
 for group,a,b in[('return',actual,want),('images',after,bytes(model)),('directionFlag',n.mu.reg_read(UC_X86_REG_EFLAGS)&0x400,0)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,method=method,sourceAlignment=sa,destinationAlignment=da,count=count,target=target,native=a if group!='images'else [[hex(D+i),u,v]for i,(u,v)in enumerate(zip(a,b))if u!=v][:10],model=b if group!='images'else'diff'))
 cases.append(dict(method=method,inputs=dict(destination=destination,source=source,count=count,target=target),initial=[dict(address=D,bytes=before.hex())],final=[dict(address=D,bytes=after.hex())],returnValue=actual,directionFlag=n.mu.reg_read(UC_X86_REG_EFLAGS)&0x400))
payloads=[b'',b'A',b'AB',b'ABC',b'ABCD',b'A'*7,b'A'*17,bytes(range(1,129))]
for payload,sa,da,count,same in itertools.product(payloads,range(4),range(4),[0,1,2,3,4,7,17,129],[False,True]):run('Copy',payload,sa,da,count=count,same=same)
for payload,sa,target in itertools.product(payloads,range(4),[0,65,66,128,255,0x100,0x141,0xffffffff]):run('Last',payload,sa,0,target=target)
# Zero count does not dereference either pointer, including null/unmapped source and destination.
for destination,source in itertools.product([0,D+0x800,0xdead0000],[0,D+0x100,0xdead0000]):
 before=n.read(D,0x1000);actual=n.call(0x6e7c00,[destination,source,0]);checks+=2
 if actual!=destination or n.read(D,0x1000)!=before:errors.append(dict(group='zeroCount',destination=destination,source=source))
 cases.append(dict(method='Copy',inputs=dict(destination=destination,source=source,count=0,target=0),initial=[dict(address=D,bytes=before.hex())],final=[dict(address=D,bytes=before.hex())],returnValue=actual,directionFlag=0))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=2,ports=[],closure='Whole original45-byte reverse search and292-byte padded/truncated copy, no adapters, exact disjoint/identical backing andzero-count pointer freedom')
(nm.BASE/'reports/script-phase200-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase200-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
