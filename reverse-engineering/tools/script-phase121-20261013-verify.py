"""Real4f8a70 byte substring and real51ac10→4f8b10 full-byte lookup; no adapters."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86();D=n.DATA;SYS=D+0x100;ROWS=D+0x200;TEXT=D+0x600;PAT=D+0x800;cases=[];errors=[];checks=0
fold=lambda c:(c-32)&255 if 97<=c<=122 or c>=224 else c
def contains(a,b):
 for i in range(len(a)):
  if i+len(b)<=len(a)and all(fold(x)==fold(y)for x,y in zip(a[i:i+len(b)],b)):return TEXT+i
 return 0
def execute(method,c):
 global checks
 n.write(D,bytes(0x1000));q=PAT
 if method=='Substring':
  a=bytes(c['text']);b=bytes(c['pattern']);n.write(TEXT,a+b'\0');n.write(PAT,b+b'\0');want=contains(a,b);address=0x4f8a70;args=[TEXT,PAT]
 else:
  names=[bytes(x)for x in c['names']];count=c.get('count',len(names));n.pack('<I',SYS+0x24,count&0xffffffff);n.pack('<I',SYS+0x28,ROWS)
  for i,value in enumerate(names):n.write(ROWS+i*0x3c,value+b'\0')
  query=bytes(c['query']);n.write(PAT,query+b'\0');system=0 if c.get('nullSystem')else SYS;want=0
  if system:
   for i in range(max(0,count)):
    name=names[i]if i<len(names)else b''
    if bytes(map(fold,name))==bytes(map(fold,query)):want=ROWS+i*0x3c;break
  address=0x51ac10;args=[system,q]
 initial=[dict(address=D,bytes=n.read(D,0x1000).hex())];got=n.call(address,args);final=[dict(address=D,bytes=n.read(D,0x1000).hex())]
 for group,a,b in [('return',got,want),('images',final,initial)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(text=TEXT,pattern=PAT,system=args[0]if method=='Locator'else 0,query=q),initial=initial,returnValue=got,final=final))
for value in range(1,256):
 for a,b in[([value],[fold(value)]),([49,value,50],[fold(value)]),([value],[value,49])]:execute('Substring',dict(text=a,pattern=b))
for a,b in itertools.product([[],list(b'AbCd'),list(b'aaaaa'),[224,255,65,66]], [[],list(b'BC'),list(b'Aa'),[192,223],[1]]):execute('Substring',dict(text=a,pattern=b))
for value in range(1,256):execute('Locator',dict(names=[[49],[value],[fold(value)]],query=[fold(value)]))
for count,query,nullSystem in itertools.product([-2,-1,0,1,2,3,5], [[],list(b'ALPHA'),list(b'omega'),[223]], [False,True]):execute('Locator',dict(names=[list(b'Alpha'),list(b'ALPHA'),[255],list(b'beta'),[]],query=query,count=count,nullSystem=nullSystem))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,refinements=['4f8a70','51ac10'],ports=[])
(nm.BASE/'reports/script-phase121-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase121-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
