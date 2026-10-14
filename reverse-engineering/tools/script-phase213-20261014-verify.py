"""Four original raw byte swap and file-endian state bodies, no ports."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
from unicorn.x86_const import UC_X86_REG_EAX
ENDIAN=0x91eea0;cases=[];checks=0;errors=[]
def run213(method,seed,value,alignment=0,alias=False):
 global checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x1000)));n.write(ENDIAN,bytes((i*19+7)&255 for i in range(8)));n.pack('<I',ENDIAN,seed);p=(ENDIAN if alias else D+0x100)+alignment
 if method in['Swap16','Swap32']:n.pack('<I',p,value)
 initial=[dict(address=a,bytes=n.read(a,z).hex())for a,z in[(D,0x1000),(ENDIAN,8)]];shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};args=[];regs={}
 if method in['Swap16','Swap32']:
  width=2 if method=='Swap16'else 4;data=bytes(shadow[p+i]for i in range(width))[::-1]
  for i,b in enumerate(data):shadow[p+i]=b
  want=p;regs={UC_X86_REG_EAX:p};address=0x4efd80 if width==2 else 0x4efda0
 elif method=='Exchange':
  want=int.from_bytes(n.read(ENDIAN,4),'little');args=[value];address=0x4efdd0
  for i,b in enumerate(value.to_bytes(4,'little')):shadow[ENDIAN+i]=b
 else:want=int.from_bytes(n.read(ENDIAN,4),'little');address=0x4efde0
 expected=[dict(address=r['address'],bytes=bytes(shadow[r['address']+i]for i in range(len(r['bytes'])//2)).hex())for r in initial];actual=n.call(address,args,regs=regs,count=1000000);final=[dict(address=r['address'],bytes=n.read(r['address'],len(r['bytes'])//2).hex())for r in initial]
 for group,a,b in [('return',actual,want),('images',final,expected)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,method=method,seed=seed,value=value,alignment=alignment,alias=alias,native=a if group!='images'else'diff',model=b if group!='images'else'diff'))
 cases.append(dict(method=method,inputs=dict(pointer=p,value=value),initial=initial,final=final,returnValue=actual))
values=[0,1,0x01020304,0x80000000,0x7fffffff,0xffffffff]
for method,seed,value,alignment,alias in itertools.product(['Swap16','Swap32'],values,values,range(4),[False,True]):run213(method,seed,value,alignment,alias)
for seed,value in itertools.product(values,values):run213('Exchange',seed,value)
for seed in values:run213('Get',seed,0)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,ports=[],rawEntryConsumers=['0x4efd80','0x4efda0','0x4efdd0','0x4efde0'],closure='Whole raw word/dword byte-reversal and live endian exchange/get bodies; unaligned pointers andalias into state DWORD, zeroports')
(nm.BASE/'reports/script-phase213-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase213-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
