"""Original path normalizer, flat container index and provider routing with real registered prefix comparator."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase71-20261013-verify.py').read_text().split('\nfor free,length')[0])
PATH=DATA;CTX=D+0x6000;CON=D+0x6100;HASHES=D+0x6200;NAMES=D+0x6301;PROVIDERS=0x29803e0;PCOUNT=0x297e064;FLAG=0x91ee84;segments=[(PATH,512),(CTX,32),(CON,48),(HASHES,32),(NAMES-1,1024),(PROVIDERS,0x8d0),(PCOUNT,4),(FLAG,4)];cases=[];checks=0;errors=[]
def rw(p):return rb(p)|(rb(p+1)<<8)
def signed16(v):return v-65536 if v&32768 else v
def length90(p):
 z=0
 while rb(p+z):z+=1
 return z
def normalize90(context,path):
 separator=92 if not context else rb(context+16);preserve=rd(FLAG)!=0;p=path
 while rb(p):
  c=rb(p)
  if c in[47,92]:wb(p,separator)
  elif not preserve and 97<=c<=122:wb(p,c-32)
  p+=1

def hash90(path):
 value=0x811c9dc5;p=path
 while rb(p):value=((value^(rb(p)if rb(p)<128 else(rb(p)-256)&0xffffffff))*0x199933)&0xffffffff;p+=1
 return value

def flat90(container,path):
 value=hash90(path);count=signed(rd(container+4))
 if count>0:
  hashes=rd(container+28)
  for i in range(count):
   if rd(hashes+i*4)==value:return i
 additional=signed(rd(container+32))
 if not additional:return 0xffffffff
 name=rd(container+40)
 if additional<0:return 0xffffffff
 for i in range(additional):
  z=0;equal=True
  while True:
   a=rb(name+z);b=rb(path+z)
   if a!=b:equal=False;break
   z+=1
   if not a:break
  length=length90(name)
  if equal:
   p=name+length+1;p+=p&1;return signed16(rw(p))&0xffffffff
  name=name+length+3;name+=name&1
 return 0xffffffff

def fold90(c):return c-32 if 97<=c<=122 else c
def compare90(a,b,count):
 if not count:return 0
 if count==0xffffffff:count=length90(a)
 elif count==0xfffffffe:count=length90(b)
 i=0
 while True:
  x=fold90(rb(a+i));y=fold90(rb(b+i))
  if x!=y:return 1 if x>y else-1
  i+=1;count=(count-1)&0xffffffff
  if not x or not y or not count:return 0

def provider90(path):
 colon=0
 while colon<8 and rb(path+colon)!=58:colon+=1
 if colon==8:return 0
 for i in range(max(0,signed(rd(PCOUNT)))):
  name=PROVIDERS+52+i*0x234
  if compare90(path,name,rd(name+16))==0:return PROVIDERS+i*0x234
 return 0

def execute90(c):
 global shadow,checks
 for p,z in segments:n.write(p,bytes(z))
 method=c['method'];payload=bytes.fromhex(c.get('path','70633a66696c652e646174'))+b'\0';n.write(PATH,payload);n.pack('<I',FLAG,c.get('preserve',0));n.write(CTX+16,bytes([c.get('separator',92)]));context=0 if c.get('noContext')else CTX
 if method=='Flat':
  n.pack('<I',CON+4,c.get('count',4));n.pack('<I',CON+28,HASHES);n.pack('<I',CON+32,c.get('additional',3));n.pack('<I',CON+40,NAMES)
  #Normalize reference hash from standalone source bytes, independent of target implementation.
  h=0x811c9dc5
  for b in payload[:-1]:h=((h^(b if b<128 else(b-256)&0xffffffff))*0x199933)&0xffffffff
  for i in range(8):n.pack('<I',HASHES+i*4,h if i==c.get('hit',-1)else(h+i+1)&0xffffffff)
  names=[b'OTHER',bytes.fromhex(c.get('name',c.get('path','70633a66696c652e646174'))),b'LAST'];pointer=NAMES
  for i,name in enumerate(names):
   n.write(pointer,name+b'\0');p=pointer+len(name)+1;p+=p&1;n.pack('<h',p,c.get('value',-7)if i==1 else i+17);pointer=pointer+len(name)+3;pointer+=pointer&1
 elif method=='Provider':
  n.pack('<I',PCOUNT,c.get('count',4))
  for i,name in enumerate([b'pc:',b'network:',b'C:',b'pc:']):n.write(PROVIDERS+i*0x234+52,name+b'\0');n.pack('<I',PROVIDERS+i*0x234+68,c.get('length',len(name)))
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 if method=='Normalize':want=None;normalize90(context,PATH);address=0x4efdf0;args=[context,PATH];inputs=dict(context=context,path=PATH)
 elif method=='Flat':want=flat90(CON,PATH);address=0x4f76f0;args=[CON,PATH];inputs=dict(container=CON,path=PATH)
 else:want=provider90(PATH);address=0x4f98c0;args=[PATH];inputs=dict(path=PATH)
 model=snap(True);actual=n.call(address,args);final=snap()
 if want is not None:
  checks+=1
  if actual!=want:errors.append(dict(group='return',context=c,native=actual,model=want))
 checks+=1
 if final!=model:errors.append(dict(group='images',context=c,differences=[dict(address=x['address'],native=x['bytes'],model=y['bytes'])for x,y in zip(final,model)if x!=y][:1]))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,returnValue=actual if want is not None else None,final=final))
for path,preserve,separator in itertools.product(['','61622f63445c6566',''+bytes(range(1,256)).hex()],[0,1,0xffffffff],[0,47,92,255]):execute90(dict(method='Normalize',path=path,preserve=preserve,separator=separator))
execute90(dict(method='Normalize',path='61622f63445c6566',noContext=True))
for path,count,hit,additional,value in itertools.product(['46494c452e444154','e0ff412f61'],[0,4,0xffffffff],[-1,0,3],[0,3],[0,-7,32767,-32768]):execute90(dict(method='Flat',path=path,count=count,hit=hit,additional=additional,value=value))
for path,count,length in itertools.product(['70633a66696c65','50433a66696c65','6e6574776f726b3a66','433a66696c65','787878787878783a66','78787878787878783a66','00783a'],[0,1,4,0xffffffff],[0,1,3,0xffffffff,0xfffffffe,0xfffffffd]):execute90(dict(method='Provider',path=path,count=count,length=length))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=3,ports=[],closure='Original4efdf0 jump-table normalizer,4f76f0 signed-byte hash/packed names,4f98c0→actual4f8b80/4f1ff0 provider routing; no adapters')
(nm.BASE/'reports/script-phase90-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase90-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
