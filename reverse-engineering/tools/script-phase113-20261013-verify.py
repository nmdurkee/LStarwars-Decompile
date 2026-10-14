"""Original provider root setters/getter and raw registration→actual released warning. No hooks."""
from pathlib import Path
import importlib.util,json,itertools
spec=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(spec);spec.loader.exec_module(nm);n=nm.NativeX86()
from unicorn.x86_const import UC_X86_REG_EAX
D=n.DATA;P=D+0x2000;SRC=D+0x400;DST=D+0x800;T=D+0x1000;R=0x29803e0;C=0x297e064;G=0x800478
segments=[(D,0x4000),(R-0x400,0x234*21+0x400),(C,4),(G,4)];shadow={};cases=[];errors=[];checks=0

def snap(model=False):return[dict(address=p,bytes=(bytes(shadow[p+i]for i in range(z))if model else n.read(p,z)).hex())for p,z in segments]
def rb(p):return shadow[p&0xffffffff]
def wb(p,v):shadow[p&0xffffffff]=v&255
def rd(p):return sum(rb(p+i)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):wb(p+i,v>>(8*i))
def copy(d,s):
 length=0;c=rb(s)
 while c:
  s+=1;wb(d,c);c=rb(s);d+=1;length+=1
  if length>1024:raise ValueError('bounded copy')
 wb(d,0);return length

def getroot(d,eax):
 s=rd(G)+0xac;copy(d,s);return eax&0xffffff00

def setroot(s):
 p=rd(G)
 if rb(s)==0:wb(p+0xac,0);return p
 length=copy(p+0xac,s);last=rb(s+length-1);value=(length&0xffffff00)|last
 if last in[47,92]:return value
 sep=rb(rd(G)+16);end=rd(G)+0xac+length;wb(end,sep)
 if sep:wb(end+1,0);return end+2
 return end+1

def register(template):
 count=rd(C);signed=count if count<0x80000000 else count-0x100000000;destination=(R+signed*0x234)&0xffffffff
 for i in range(0x8d):wd(destination+i*4,rd(template+i*4))
 p=rd(G)
 for offset in[0xac,0x12c,0x1ac]:copy(destination+offset,p+offset)
 wd(C,(count+1)&0xffffffff);return destination

def run(c):
 global shadow,checks
 for p,z in segments:n.write(p,b'\xa5'*z)
 n.pack('<I',G,P);n.pack('<I',C,c.get('count',0)&0xffffffff);n.write(T,bytes((i*37+11)&255 for i in range(0x234)));
 for off in[0xac,0x12c,0x1ac]:n.write(T+off,b'TEMPLATE/\0')
 text=bytes.fromhex(c.get('text',''));n.write(SRC,text+b'\0');n.write(P+16,bytes([c.get('separator',92)]));
 for off,key in[(0xac,'root'),(0x12c,'user'),(0x1ac,'save')]:n.write(P+off,bytes.fromhex(c.get(key,b'base/'.hex()))+b'\0')
 method=c['method'];src=SRC;dst=DST;template=T
 if c.get('alias')=='same':
  if method=='SetRoot':src=P+0xac;n.write(src,text+b'\0')
  elif method=='GetRoot':dst=P+0xac
  else:template=R+c['count']*0x234;n.write(template,n.read(T,0x234))
 if c.get('alias')=='before':
  if method=='SetRoot':src=P+0xac+16;n.write(src,text+b'\0')
  elif method=='GetRoot':dst=P+0xac-16
  else:template=R+c['count']*0x234-1;n.write(template,n.read(T,0x234))
 if c.get('currentTarget'):
  p=R+c['count']*0x234;n.pack('<I',G,p)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};seed=c.get('seed',0);wanted=setroot(src)if method=='SetRoot'else getroot(dst,seed)if method=='GetRoot'else register(template);model=snap(True);actual=n.call({'SetRoot':0x4f6930,'GetRoot':0x4f6900,'Register':0x4f6820}[method],[src if method=='SetRoot'else dst if method=='GetRoot'else template],regs={UC_X86_REG_EAX:seed},count=4000000);final=snap()
 for group,a,b in[('return',actual,wanted),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group=='return'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:8],model=b if group=='return'else'diff'))
 cases.append(dict(method=method,context=c,inputs=dict(source=src,destination=dst,template=template,seed=seed),initial=initial,final=final,returnValue=actual))
for text,sep,alias in itertools.product([b'',b'a',b'folder',b'folder/',b'folder\\',b'C:\\folder',b'x'*127,b'y'*128,b'z'*129],[0,47,92,33,255],['none','same','before']):run(dict(method='SetRoot',text=text.hex(),separator=sep,alias=alias))
for root,seed,alias in itertools.product([b'',b'a',b'folder/',b'folder\\',b'x'*127,b'y'*128,b'z'*129],[0,0xffffffff,0x12345678,0x80000000],['none','same','before']):run(dict(method='GetRoot',root=root.hex(),seed=seed,alias=alias))
for count,paths,alias in itertools.product([-1,0,1,15,16,17],[(b'',b'',b''),(b'ROOT/',b'USER/',b'SAVE/'),(b'a'*127,b'b'*128,b'c'*129)],['none','same','before']):run(dict(method='Register',count=count,root=paths[0].hex(),user=paths[1].hex(),save=paths[2].hex(),alias=alias))
for count in[0,1,15,16]:run(dict(method='Register',count=count,currentTarget=True))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=2,rawEntryConsumers=['0x4f6820'],ports=[],closure='Wholeprovider root4f6930→actual4f1e80 append and4f6900 copy; rawregistration4f6820 full8dDWORDcopy+threecurrent-provider paths+count/releasewarning; no hooks')
(nm.BASE/'reports/script-phase113-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase113-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
