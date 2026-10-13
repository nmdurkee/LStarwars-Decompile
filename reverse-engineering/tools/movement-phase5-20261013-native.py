"""Original formation row dispatcher; only row callback is a declared boundary."""
import importlib.util,json,struct,itertools,base64,gzip
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import *
n=m.NativeX86();D=n.DATA;SIZE=0x4000;CB=n.STOP+0x100;vectors=[];errors=[];events=[];opt={};groups={}
def ret(mu,v):
 sp=mu.reg_read(UC_X86_REG_ESP);dest=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,v&0xffffffff);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,dest)
def mutate(image,row,index,meta):
 def u(p):return struct.unpack_from('<I',image,p)[0]
 def setu(p,v):struct.pack_into('<I',image,p,v&0xffffffff)
 image[row+0x30]^=meta.get('toggleRow',0)
 if meta.get('mutate'):
  image[6]=meta.get('newCount',2);setu(0,u(0)+4);setu(0x50,u(0x50)^4)
  if index+1<255:image[0x54+(index+1)*0x34+0x2d]=1
 return index==meta.get('stop',-1)
def hook(mu,a,s,u):
 if a!=CB:return
 sp=mu.reg_read(UC_X86_REG_ESP);fo,row,prev,owner=n.unpack('<4I',sp+4);index=(row-D-0x54)//0x34;events.append([fo,row,prev,owner]);image=bytearray(n.read(D,SIZE));done=mutate(image,row-D,index,opt);n.write(D,image);ret(mu,int(done))
n.mu.hook_add(UC_HOOK_CODE,hook)
def model(image,callback,meta):
 def u(p):return struct.unpack_from('<I',image,p)[0]
 def setu(p,v):struct.pack_into('<I',image,p,v&0xffffffff)
 ev=[];previous=0;blocked=False
 if callback and u(0x50)&8:
  reverse=bool(u(0x50)&4);ix=image[6]-1 if reverse else 0
  while ix>=0 if reverse else ix<image[6]:
   row=0x54+ix*0x34
   if image[row+0x2d]:
    ev.append([D,D+row,previous,u(0)])
    if mutate(image,row,ix,meta):break
    if image[row+0x30]&2:blocked=True
    previous=D+row
   ix+=-1 if reverse else 1
 setu(0x50,(u(0x50)&~16)|(16 if blocked else 0));return ev

def run(meta,group):
 opt.clear();opt.update(meta);events.clear();image=bytearray([0xa5]*SIZE);struct.pack_into('<I',image,0,0x12345678);image[6]=meta['count'];struct.pack_into('<I',image,0x50,meta['flags'])
 for ix in range(255):image[0x54+ix*0x34+0x2d]=1 if(meta['active']>>(ix%4))&1 else 0;image[0x54+ix*0x34+0x30]=meta.get('rowFlags',2)if ix%2 else 0
 before=bytes(image);expected=bytearray(image);wev=model(expected,meta.get('callback',True),meta);n.write(D,image)
 n.call(0x51d130,[CB if meta.get('callback',True)else 0],regs={UC_X86_REG_ESI:D})
 after=n.read(D,SIZE);groups[group]=groups.get(group,0)+1
 if after!=expected or events!=wev:errors.append({'meta':meta,'events':[events,wev],'diff':[[hex(i),after[i],expected[i]]for i in range(SIZE)if after[i]!=expected[i]][:20]})
 vectors.append({'input':dict(meta),'before':base64.b64encode(gzip.compress(before)).decode(),'after':base64.b64encode(gzip.compress(after)).decode(),'events':list(events)})
for count,flags,active,callback,stop,toggle in itertools.product([0,1,4,255],[0,4,8,12,24,28,0xffffffff],[0,1,5,15],[False,True],[-1,0,1,3],[0,2]):
 run(dict(count=count,flags=flags,active=active,callback=callback,stop=stop,toggleRow=toggle),'dispatch-grid')
for count,flags,active,newCount,stop,toggle in itertools.product([1,4,8],[8,12],[1,5,15],[0,2,5],[-1,0,3],[0,2]):
 run(dict(count=count,flags=flags,active=active,callback=True,stop=stop,toggleRow=toggle,mutate=True,newCount=newCount),'mutable-row-services')
report={'binarySha256':n.sha256,'cases':len(vectors),'assertionGroups':2*len(vectors),'groups':groups,'mismatches':len(errors),'errors':errors,'method':'Original0x51d130 runs using its implicitESI formation convention. Entire16384byte image and exact callback argument sequence compared against own-state oracle; row callback only is a boundary. Managed replay separate/unexecuted.','adapters':['Row callback returns prepared stop value and may mutate row status/count/flags/owner/next-row enable byte.'],'limits':['Valid255row allocation, finite forward progress bounded by unsignedbyte count; callback does not change preservedESI/EDI/EBP registers.','Actual51cbc0 and51c6a0 row path algorithms are not reconstructed here; supplied callback explicit.']}
(m.BASE/'reports/movement-phase5-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase5-20261013-fixtures.json.gz','wt',encoding='utf-8')as o:json.dump({'vectors':vectors},o,separators=(',',':'))
print(json.dumps({'cases':len(vectors),'assertions':2*len(vectors),'mismatches':len(errors),'examples':errors[:3]}))
