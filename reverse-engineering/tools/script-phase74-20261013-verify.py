"""Original archive record Find4f9de0 and Information4f0f30 +actualregistered byte comparator; threeheaderlayouts, flags, aliases and invalid-input effects."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86();D=n.DATA;ARCH=D+0x1000;REQUEST=D+0x3000;OUT=D+0x4000;ERROR=0x91eeb8;segments=[(ARCH,0x2000),(REQUEST,0x100),(OUT,0x100),(ERROR,4)];shadow={};checks=0;errors=[];cases=[]
def rb(p):return shadow[p]
def wb(p,v):
 if p not in shadow:raise KeyError(p)
 shadow[p]=v&255
def rd(p):return sum(rb((p+i)&0xffffffff)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):wb((p+i)&0xffffffff,v>>(8*i))
def signed(v):return v-0x100000000 if v&0x80000000 else v
def snap(model=False):return[dict(address=p,bytes=bytes(rb(p+i)for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def fold74(v):return(v-32)&255 if 97<=v<=122 or v>=224 else v
def compare74(a,b):
 if not a:return -1
 if not b:return 1
 while True:
  x,y=fold74(rb(a)),fold74(rb(b));sx=x-256 if x&128 else x;sy=y-256 if y&128 else y
  if sx!=sy:return 1 if sx>sy else -1
  if not x or not y:return 0
  a=(a+1)&0xffffffff;b=(b+1)&0xffffffff
def first74(archive,magic):return(archive+(12 if magic==0x12345678 else 24 if magic==0x1234567a else 20))&0xffffffff
def find74(archive,name):
 magic=rd(archive);wd(ERROR,0);first=first74(archive,magic);count=rd(archive+4)
 for i in range(count):
  record=(first+i*28)&0xffffffff;candidate=(archive+rd(record))&0xffffffff
  if not compare74(candidate,name):return 0 if rb(record+16)&2 else i+1
 return 0
def information74(archive,entry,dataOut,sizeOut):
 index=(entry-1)&0xffffffff;wd(ERROR,0)
 if signed(index)<0 or index>=rd(archive+4):return 0
 record=(first74(archive,rd(archive))+index*28)&0xffffffff
 if rb(record+16)&2:return 0
 if dataOut:wd(dataOut,(rd(record+4)+archive)&0xffffffff)
 if sizeOut:wd(sizeOut,rd(record+8))
 return 1

def execute74(c):
 global shadow,checks
 n.write(ARCH,bytes([0xa5])*0x2000);n.write(REQUEST,bytes(0x100));n.write(OUT,bytes([0x5a])*0x100);n.pack('<I',ERROR,0xabcdef01);n.pack('<II',ARCH,c['magic'],c.get('count',3));first=ARCH+(12 if c['magic']==0x12345678 else 24 if c['magic']==0x1234567a else 20)
 for i in range(3):
  name=ARCH+0x500+i*0x100;value=c.get('names',['alpha','Beta','\xe0name'])[i];n.write(name,value.encode('latin1')+b'\0');offset=(0-ARCH)&0xffffffff if c.get('nullCandidate')and i==0 else name-ARCH;n.pack('<7I',first+i*28,offset,0x1000+i*0x100,17+i,0x55550000+i,c.get('flags',[0,0,0])[i],0x66660000+i,0x77770000+i)
 name=0 if c.get('requested')is None else REQUEST
 if name:n.write(name,c['requested'].encode('latin1')+b'\0')
 archive=c.get('archive',ARCH);method=c['method'];entry=c.get('entry',1);row=first+max(0,min(2,(entry-1)&0xffffffff))*28
 output={'null':0,'out':OUT,'same':OUT,'length':OUT+4,'rowLength':row+8,'rowData':row+4,'archiveCount':ARCH+4,'error':ERROR,'invalid':0xdeadbeef}
 if method=='Find':inputs=dict(archive=archive,name=name);address=0x4f9de0
 else:inputs=dict(archive=archive,entry=entry,dataOut=output[c.get('dataOut','out')],sizeOut=output[c.get('sizeOut','length')]);address=0x4f0f30
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};want=0;modelFault=False
 try:want=find74(**inputs)if method=='Find'else information74(**inputs)
 except KeyError:modelFault=True
 model=snap(True);actual=0;nativeFault=False
 try:actual=n.call(address,list(inputs.values()),count=3000000)
 except RuntimeError:nativeFault=True
 final=snap()
 for group,a,b in [('fault',nativeFault,modelFault),('return',0 if nativeFault else actual,0 if modelFault else want),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,fault=nativeFault,returnValue=0 if nativeFault else actual,final=final))
magics=[0x12345678,0x1234567a,0x12345679]
for magic,count,requested,flags,nullCandidate in itertools.product(magics,[0,1,3],['ALPHA','beTA','\xc0NAME','missing','',None],[[0,0,0],[2,0,0],[0,2,0],[0,0,2],[0xff,0,0]],[False,True]):execute74(dict(method='Find',magic=magic,count=count,requested=requested,flags=flags,nullCandidate=nullCandidate))
for magic,flags in itertools.product(magics,[[0,0,0],[2,0,0]]):execute74(dict(method='Find',magic=magic,requested='Alpha',names=['alpha','ALPHA','alpha'],flags=flags))
for magic,entry,flags,dataOut,sizeOut in itertools.product(magics,[0,1,2,3,4,0x80000000,0x80000001,0xffffffff],[[0,0,0],[2,2,2]],['null','out','rowLength','rowData','archiveCount','error'],['null','length','same','error']):execute74(dict(method='Information',magic=magic,entry=entry,flags=flags,dataOut=dataOut,sizeOut=sizeOut))
for method,archive,entry in itertools.product(['Find','Information'],[0,0xdeadbeef],[0,1,0x80000001]):execute74(dict(method=method,magic=0x12345678,requested='alpha',archive=archive,entry=entry))
for dataOut,sizeOut in [('invalid','length'),('out','invalid')]:execute74(dict(method='Information',magic=0x12345678,entry=1,requested=None,dataOut=dataOut,sizeOut=sizeOut))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=[],closure='Actual4f9de0→4f8b10 names,4f0f30 relative metadata and output aliases; error91eeb8 reset/order preserved')
(nm.BASE/'reports/script-phase74-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase74-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
