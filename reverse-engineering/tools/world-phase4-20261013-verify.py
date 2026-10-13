import importlib.util,json,struct,itertools,hashlib,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));mod=importlib.util.module_from_spec(s);s.loader.exec_module(mod);n=mod.NativeX86();B=mod.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_EDX
WORLD=D;PATH=D+0x1000;INPUT=D+0x20000;OUT=D+0x40000;GLOBAL=0x92b0c8;ARCHIVE=0x91ee88;SPECIAL=0x91ee94;ERROR=0x91eea4;HANDLE=0x7777;REGIONS=[(ARCHIVE,4),(SPECIAL,4),(ERROR,4),(GLOBAL,0x10010),(D,0x60000)]
API={0x4fb960:('Archive',4),0x4ff120:('Exists',1),0x4fa3f0:('Open',4),0x4fcc60:('Special',3),0x4f6b40:('Length',1),0x4fb550:('Read',3),0x4f99e0:('Close',1),0x4ef7b0:('Pump',0),0x4f6de0:('Seek',4),0x6e69ef:('Format',3)}
class Image:
 def __init__(self):self.regions={a:bytearray([0x6d])*z for a,z in REGIONS}
 def locate(self,a,z):
  for base,data in self.regions.items():
   if base<=a and a+z<=base+len(data):return data,a-base
  raise AssertionError((hex(a),z))
 def read(self,a,z):data,o=self.locate(a,z);return bytes(data[o:o+z])
 def write(self,a,b):data,o=self.locate(a,len(b));data[o:o+len(b)]=b
 def get(self,a):return struct.unpack('<I',self.read(a,4))[0]
 def put(self,a,v):self.write(a,struct.pack('<I',v&0xffffffff))
 def string(self,a):
  b=bytearray()
  while self.read(a,1)!=b'\0':b+=self.read(a,1);a+=1
  return b.decode('latin1')
 def text(self,a,t):self.write(a,t.encode('latin1')+b'\0')
 def sha(self):return hashlib.sha256(b''.join(self.regions[a] for a,z in REGIONS)).hexdigest()
def options(o):
 p=dict(kind='Produce',text='value=1,2\n#comment\n',path='levels\\test\\test_a',archive=0,archiveReturn=0,archiveError=0,exists=1,open=HANDLE,special=0,specialReturn=None,length=None,readResults=None,seekResults=[0],cursorOffset=1,capacity=0x10000,normalizeSeparators=1,inPlace=False,label='synthetic');p.update(o)
 if p['length'] is None:p['length']=len(p['text'].encode('latin1'))
 if p['readResults'] is None:p['readResults']=[p['length']]
 if p['specialReturn'] is None:p['specialReturn']=len(p['text'].encode('latin1'))
 return p
def setup(p):
 image=Image();image.put(ARCHIVE,p['archive']);image.put(SPECIAL,p['special']);image.put(ERROR,0xdeadbeef);image.text(WORLD+0x80,p['path']);image.put(WORLD+0x104,INPUT+p['cursorOffset']);image.put(WORLD+0x10c,0x11223344);image.text(PATH,p['path']+'.txt')
 if p['kind']=='Normalize':image.text(INPUT,p['text'])
 return image
current=None;state=None;trace=[];rows=[];errors=[];authored=[]
def fresh():return dict(read=0,seek=0)
def emit(t,name,**fields):t.append(dict(name=name,**fields))
def feed(image,p,destination,count):
 count=max(0,min(count,len(p['text'].encode('latin1'))));image.write(destination,p['text'].encode('latin1')[:count])
def backend(image,p,s,t,name,args,path=None):
 if name=='Archive':
  archive,destination,limit=args;emit(t,name,archive=archive,path=path,destination=destination,limit=limit);image.put(ERROR,p['archiveError']);feed(image,p,destination,p['archiveReturn']);return p['archiveReturn']
 if name=='Exists':emit(t,name,path=path);return p['exists']
 if name=='Open':emit(t,name,path=path,mode=args[0],archive=args[1],flags=args[2]);return p['open']
 if name=='Special':handle,destination,limit=args;emit(t,name,handle=handle,destination=destination,limit=limit);feed(image,p,destination,p['specialReturn']);return p['specialReturn']
 if name=='Length':emit(t,name,handle=args[0]);return p['length']
 if name=='Read':
  handle,destination,count=args;value=p['readResults'][min(s['read'],len(p['readResults'])-1)];s['read']+=1;emit(t,name,handle=handle,destination=destination,count=count,result=value)
  if value>=0:feed(image,p,destination,min(value,count))
  return value
 if name=='Close':emit(t,name,handle=args[0]);return 0
 if name=='Pump':emit(t,name);return 0
 if name=='Seek':
  value=p['seekResults'][min(s['seek'],len(p['seekResults'])-1)];s['seek']+=1;emit(t,name,handle=args[0],low=args[1],high=args[2],origin=args[3],result=value);return value
 raise AssertionError(name)
def cstring(a):
 out=bytearray()
 while n.read(a,1)!=b'\0':out+=n.read(a,1);a+=1
 return out.decode('latin1')
def capture():
 image=Image()
 for a,z in REGIONS:image.regions[a][:]=n.read(a,z)
 return image
def load(image):
 for a,data in image.regions.items():n.write(a,data)
def observe(mu,address,size,user):
 if address not in API:return
 name,count=API[address];sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*count,sp+4)) if count else []
 if name=='Format':
  output,format,source=args;assert cstring(format)=='%s.txt';path=cstring(source)+'.txt';n.write(output,path.encode('latin1')+b'\0');emit(trace,'Format',format='%s.txt',source=cstring(source),path=path);value=len(path)
 else:
  image=capture();path=None
  if name=='Archive':path=cstring(args[1]);args=[args[0],args[2],args[3]]
  elif name in ['Exists','Open']:path=cstring(args[0]);args=args[1:]
  value=backend(image,current,state,trace,name,args,path);load(image)
 mu.reg_write(UC_X86_REG_EAX,value&0xffffffff)
 if name=='Seek':mu.reg_write(UC_X86_REG_EDX,(value>>32)&0xffffffff)
 mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for address in API:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
def normalize(image,source,out,convert):
 end=source+len(image.string(source));count=0
 while True:
  c=image.read(source,1)[0];comment=c in [59,35]
  if c==47:source+=1;comment=image.read(source,1)[0]==47
  if comment:
   source+=1
   while image.read(source,1)[0] not in [0,10,13]:source+=1
  c=image.read(source,1)[0];source+=1
  if convert and c in [61,44]:c=32
  image.write(out,bytes([c]));out+=1;count+=1
  if source>end:break
 image.write(out,b'\0');return count

def read_whole(image,p,s,t,path,destination,limit):
 image.put(ERROR,0);archive=image.get(ARCHIVE)
 if archive:
  result=backend(image,p,s,t,'Archive',[archive,destination,limit],path)
  if image.get(ERROR)==0xffffffff:return 0
  if result!=0:return result
 if not backend(image,p,s,t,'Exists',[],path):image.put(ERROR,-2);return 0
 handle=backend(image,p,s,t,'Open',[0,image.get(ARCHIVE),0],path)
 if not handle:image.put(ERROR,-3);return 0
 if image.get(SPECIAL):result=backend(image,p,s,t,'Special',[handle,destination,limit]);backend(image,p,s,t,'Close',[handle]);return result
 length=backend(image,p,s,t,'Length',[handle])
 if length>limit or length==0:image.put(ERROR,-1);length=0
 else:
  got=backend(image,p,s,t,'Read',[handle,destination,length])
  while got<0:
   while True:
    backend(image,p,s,t,'Pump',[]);seek=backend(image,p,s,t,'Seek',[handle,0,0,0])
    if seek>=0:break
   got=backend(image,p,s,t,'Read',[handle,destination,length])
 backend(image,p,s,t,'Close',[handle]);return length

def run(inputs):
 global current,state,trace
 p=options(inputs);current=p;state=fresh();trace=[];expected=setup(p);load(expected);wantTrace=[];wantState=fresh();wantReturn=None
 if p['kind']=='Normalize':wantReturn=normalize(expected,INPUT,INPUT if p['inPlace'] else OUT,p['normalizeSeparators']);got=n.call(0x54be70,[INPUT,INPUT if p['inPlace'] else OUT,p['normalizeSeparators']],count=10000000)
 elif p['kind']=='Read':wantReturn=read_whole(expected,p,wantState,wantTrace,p['path']+'.txt',INPUT,p['capacity']);got=n.call(0x4fd5d0,[PATH,INPUT,p['capacity']],count=10000000)
 else:
  expected.write(GLOBAL,b'\0');path=expected.string(WORLD+0x80)+'.txt';emit(wantTrace,'Format',format='%s.txt',source=expected.string(WORLD+0x80),path=path);cursor=(expected.get(WORLD+0x104)+3)&0xfffffffc;expected.put(WORLD+0x104,cursor);value=read_whole(expected,p,wantState,wantTrace,path,cursor,0x10000);expected.put(WORLD+0x10c,value)
  if value>0:expected.write(cursor+value,b'\0');count=normalize(expected,cursor,GLOBAL,1);expected.put(WORLD+0x10c,count)
  got=n.call(0x57a420,[WORLD],count=10000000)
 actual=capture();bad=[]
 if wantReturn is not None and got!=(wantReturn&0xffffffff):bad.append(dict(result=got,want=wantReturn))
 if actual.sha()!=expected.sha():
  diffs=[]
  for a,z in REGIONS:diffs.extend(hex(a+i) for i,(x,y) in enumerate(zip(actual.regions[a],expected.regions[a])) if x!=y)
  bad.append(dict(differences=diffs[:24]))
 if trace!=wantTrace:bad.append(dict(trace=trace,want=wantTrace))
 if state!=wantState:bad.append(dict(state=state,want=wantState))
 if bad:errors.append(dict(index=len(rows),options={k:v for k,v in p.items() if k!='text'},bad=bad))
 rows.append(dict(options=p,nativeSha=actual.sha(),nativeReturn=got if wantReturn is not None else None,count=actual.get(WORLD+0x10c),cursor=actual.get(WORLD+0x104),error=actual.get(ERROR),trace=trace.copy()))

def main():
 texts=['','a',';', '#','//','/','a/b','/;a','/#a','/,=','a=1,2;tail\r\nb#comment\nc//comment\r\nd','"quoted;stripped" end\n','"quoted#stripped" end\n','"quoted//stripped" end\n','single/Slash\n','double//Slash\n','before\0after','#comment\r\n=,','a;\nb#\r\nc//\rd','\xff\x80\t=,']
 for text,flag,alias in itertools.product(texts,[0,1,-1],[False,True]):run(dict(kind='Normalize',text=text,normalizeSeparators=flag,inPlace=alias))
 for text,offset,archive,special in itertools.product(texts,[0,1,3,15],[0,0x1234],[0,1]):run(dict(text=text,cursorOffset=offset,archive=archive,special=special))
 for kind,archive,archiveReturn,archiveError,exists,opened,special in itertools.product(['Read','Produce'],[0,0x1234],[0,4],[-1,0,-2],[0,1],[0,HANDLE],[0,1]):run(dict(kind=kind,text='abc\n',archive=archive,archiveReturn=archiveReturn,archiveError=archiveError,exists=exists,open=opened,special=special))
 for kind,capacity,length,results in itertools.product(['Read','Produce'],[0,1,0x10000],[0,1,4,0x10000,0x10001],[[0],[1],[-1,4],[-1,-2,4]]):run(dict(kind=kind,text='abc\n',capacity=capacity,length=length,readResults=results,seekResults=[-0x100000000,-1,0x80000000]))
 for value in [-1,0,1,4]:run(dict(special=1,specialReturn=value))
 for result,error in [(-1,0),(4,-1),(4,-2),(4,7)]:run(dict(archive=0x1234,archiveReturn=result,archiveError=error))
 #Complete supplied source bytes, no Python preprocessing or line extraction.
 for file in sorted((B/'extracted/LEVELS').rglob('*.TXT')):
  raw=file.read_bytes();rel=file.relative_to(B).as_posix();path=file.relative_to(B/'extracted').as_posix()[:-4].replace('/','\\')
  if len(path)+4>=128:authored.append(dict(path=rel,bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest(),status='excluded-path-too-long'));continue
  run(dict(text=raw.decode('latin1'),path=path,label='authored:'+rel));authored.append(dict(path=rel,bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest(),status='native-normal-file-read' if 0<len(raw)<=0x10000 else 'native-empty-or-oversize-rejection'))
 report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(errors),groups={k:sum(r['options']['kind']==k for r in rows) for k in ['Normalize','Read','Produce']},authoredFiles=len(authored),authoredExecuted=sum(r['options']['label'].startswith('authored:') for r in rows),authoredWithinReadLimit=sum(0<a['bytes']<=0x10000 and a['status']!='excluded-path-too-long' for a in authored),authoredEmptyOrOversize=sum(a['status']=='native-empty-or-oversize-rejection' for a in authored),bytesComparedPerCase=sum(z for a,z in REGIONS),examples=errors[:3],method='Original57a420 producer composes original4fd5d0 whole-file control flow and54be70 normalization/4f1ff0 length. Cookie check6e693a executes unchanged. Explicit I/O backend services plus fixed%s.txt formatter6e69ef adapter; originalCRTformatter reaches unavailable imported target0x3ee702. Complete prepared byte images, error/producer outputs and backend trace compare; full authored rawfiles feed without Python preprocessing.',limits=['Prepared disjoint byte regions or exact in-place normalization; terminated input and adequate output/arena backing. Filenames fit native128-byte local, fixed%s.txt pattern only.','Original archive/file transport, compressed reads and OS handle lifecycle are services, not recreated backends. Retried services must eventually return nonnegative read/seek. Advertised lengths0..0x10001; positive producer returns<=0x10000.','Seek preserves original signed64-bitEDX:EAX return semantics. Negative read retries only; nonnegative short read still returns declared file length. Missing/oversize/error paths are bounded, not fixed to claim success.','Normalization is byte-oriented and quote-unaware; single slash advances input even without a second slash. Return includes copied terminatingNUL, followed by anotherNUL.','Authored complete files are byte-hash bound; oversized/empty files retain original rejection. No live level resource load or parser-record allocation is claimed.','Managed replay remains pending; no generated executable retry.'])
 (B/'reports/world-phase4-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/world-phase4-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=REGIONS,cases=rows),separators=(',',':'))+'\n');(B/'reports/world-phase4-20261013-authored-provenance.json').write_text(json.dumps(authored,indent=2)+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
