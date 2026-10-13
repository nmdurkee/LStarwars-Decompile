"""Finite Euler skeletal model and original x86 oracle; no game/OS execution."""
from pathlib import Path
import importlib.util,struct,hashlib,math
s=importlib.util.spec_from_file_location('skeletal_pose_base',Path(__file__).with_name('scene-animation-pose-fixture.py'));p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
B=p.B;W=p.W;S=p.S;bits=p.bits;value=p.value;f32=p.f32
IDENTITY=[float(i%5==0)for i in range(16)]
def normalize(raw):
 raw=bytes(raw)
 if struct.unpack_from('<I',raw)[0]==0x414e4934:return raw
 assert struct.unpack_from('<I',raw,4)[0]==0x414e4935
 data=bytearray(raw[4:]);struct.pack_into('<I',data,0,0x414e4934)
 for q in (36,40,44,48,52,56):
  v=struct.unpack_from('<i',data,q)[0]
  if v:struct.pack_into('<I',data,q,q+v)
 return bytes(data)
class Clip:
 def __init__(self,raw):
  self.raw=normalize(raw);self.nodes=self.u16(4);self.count=self.u16(6);self.stride=self.u16(8);self.frames=self.u16(10);self.first=self.u16(14)
  assert self.raw[19]&1==0 and self.u16(12)==9 and 0<self.nodes<=256 and self.count>0 and(self.count==1 or self.frames>1)
  self.scales,self.constants,self.types,self.keys,self.flags=[self.u32(i)for i in(36,40,44,48,52)]
 def u16(self,p):return struct.unpack_from('<H',self.raw,p)[0]
 def u32(self,p):return struct.unpack_from('<I',self.raw,p)[0]
 def flt(self,p):return struct.unpack_from('<f',self.raw,p)[0]
 def sample(self,frame):
  key=0. if self.count==1 else max(0.,min(float(self.count-1),S(S(S(W(frame)-W(self.first))*W(self.count-1))/W(self.frames-1)).store()))
  whole=int(key);q=whole&3;fraction=f32(key-whole);at=self.keys+(whole//4)*self.stride;sc=self.scales;out=[]
  for node in range(self.nodes):
   flag=self.raw[self.flags+node];v=[]
   for i in range(9):
    t=self.u16(self.types+2*(node*9+i))
    if not flag&[2,1,8][i//3]:v.append(1. if i>=6 else 0.);continue
    if t>=16:v.append((W(self.u16(self.constants+2*(t-16)))*W(self.flt(32))+W(self.flt(28))).store());continue
    assert t==6
    factor=lambda at,q:S(W((self.u32(at)>>(8+6*q))&63)*W(0.015873020514845848))
    a,b=W(self.raw[at]),W(self.raw[at+self.stride]);fa=factor(at,q)
    if q<3:val=a+S(fa+W(fraction)*(factor(at,q+1)-fa))*(b-a)
    else:
     first=S(a+fa*(b-a));second=S(b+(W(self.raw[at+2*self.stride])-b)*factor(at+self.stride,0));val=first+W(fraction)*(second-first)
    v.append((val*W(self.flt(sc))+W(self.flt(sc+4))).store());at+=4;sc+=8
   out.append(v)
  return out
def linear(a,b):
 out=IDENTITY.copy()
 for r in range(3):
  for c in range(3):out[r*4+c]=((W(a[r*4])*W(b[c])+W(a[r*4+1])*W(b[4+c]))+W(a[r*4+2])*W(b[8+c])).store()
 return out
def multiply(a,b):
 return[(((W(a[r*4])*W(b[c])+W(a[r*4+1])*W(b[4+c]))+W(a[r*4+2])*W(b[8+c]))+W(a[r*4+3])*W(b[12+c])).store()for r in range(4)for c in range(4)]
def pose(values,flags,joints,clipCount=None):
 world=[];scales=[];locals=[]
 if clipCount is None:clipCount=len(values)
 for i,joint in enumerate(joints):
  if i>=clipCount:world.append(IDENTITY.copy());continue
  v=values[i];flag=flags[i];parent=joint['parent'];ps=[1.,1.,1.]if parent==255 else scales[parent]
  if flag&1:
   m=p.rotation([(W(x)*W(10430.3779296875)).trunc()for x in v[3:6]])
   if flag&32:m=linear(m,joint['bind'])
  else:m=[float(x)for x in joint['bind']]if flag&32 else IDENTITY.copy()
  scale=ps.copy()
  if flag&8:
   for r in range(3):
    for c in range(3):m[r*4+c]=(W(m[r*4+c])*W(v[6+r])).store()
   scale=[(W(ps[k])*W(v[6+k])).store()for k in range(3)]
  if flag&16:
   inv=[(W(1)/W(x)).store()for x in ps]if all(x!=0 for x in ps)else[0.,0.,0.]
   scale=[(W(scale[k])*W(inv[k])).store()for k in range(3)]if all(x!=0 for x in ps)else[0.,0.,0.]
   for r in range(4):
    for c in range(3):m[r*4+c]=(W(m[r*4+c])*W(inv[c])).store()
  if flag&2:
   for k in range(3):m[12+k]=(W(m[12+k])+W(v[k])).store()
  for k in(2,6,8,9,11,14):m[k]=-m[k]
  if parent==255 and flag&64:scale=[1.,1.,1.]
  scales.append(scale);locals.append(m.copy());world.append(m if parent==255 else multiply(m,world[parent]))
 return {'world':[[bits(x)for x in row]for row in world],'scales':[[bits(x)for x in row]for row in scales]}
def load_original_d3dx(n):
 path=Path(r'C:\Windows\SysWOW64\d3dx9_35.dll');raw=path.read_bytes();assert hashlib.sha256(raw).hexdigest()=='2198022938156b790e9cfb0f7997494b66a11a1ad49b395be58251d635b66b26','Unexpected D3DX source binary';u16=lambda o:struct.unpack_from('<H',raw,o)[0];u32=lambda o:struct.unpack_from('<I',raw,o)[0]
 pe=u32(60);opt=pe+24;base=u32(opt+28);mapped=0x20000000;size=u32(opt+56);n.mu.mem_map(mapped,(size+4095)&~4095);n.write(mapped,raw[:u32(opt+60)])
 for i in range(u16(pe+6)):
  q=opt+u16(pe+20)+40*i;rva,count,offset=u32(q+12),u32(q+16),u32(q+20)
  if count:n.write(mapped+rva,raw[offset:offset+count])
 relocation,size=u32(opt+136),u32(opt+140);at=mapped+relocation;end=at+size;count=0
 while at<end:
  page,block=n.unpack('<II',at)
  if not block:break
  for off in range(8,block,2):
   entry=n.unpack('<H',at+off)[0];kind=entry>>12
   if kind==0:continue
   assert kind==3
   field=mapped+page+(entry&4095);n.pack('<I',field,(n.unpack('<I',field)[0]+mapped-base)&0xffffffff);count+=1
  at+=block
 entry=mapped+0x163599;n.pack('<I',0x751324,entry)
 return {'path':str(path),'sha256':hashlib.sha256(raw).hexdigest(),'bytes':len(raw),'preferredBase':hex(base),'mappedBase':hex(mapped),'matrixImplementationRva':'0x163599','highlowRelocations':count,'binding':'Game IAT0x751324 explicitly bound to original scalar implementation; export CPU/config dispatch is not run.'}
class Oracle:
 def __init__(self):
  self.n=p.nx.NativeX86();self.base=0x11000000;self.n.mu.mem_map(self.base,0x400000);self.dll=load_original_d3dx(self.n)
  self.n.write(0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes());self.n.write(0x9737de,b'\0')
  d=self.n.DATA;self.buffer=d;self.samples=d+0x1000;self.flags=d+0x5000;self.hierarchy=d+0x6000;self.joints=d+0x7000;self.matrices=d+0x10000;self.header=d+0x15000
 def load(self,raw):
  c=Clip(raw);data=bytearray(c.raw)
  for q in(36,40,44,48,52,56):
   at=c.u32(q)
   if at:struct.pack_into('<I',data,q,self.base+at)
  self.n.write(self.base,data);self.clip=c
 def sample(self,frame,count=None,start=0):
  if count is None:count=self.clip.nodes
  total=self.clip.nodes;self.n.write(self.samples,b'\xa5'*(total*48));self.n.write(self.flags,b'\xa5'*total);self.n.pack('<IHBBII',self.buffer,total,total,0x7f,0,self.samples,self.flags)
  result=self.n.call(0x5cc0d0,[self.base,bits(frame),self.buffer,count,start],count=2000000)
  raw=self.n.read(self.samples,total*48);values=[[struct.unpack_from('<I',raw,j*48+(c//3)*16+(c%3)*4)[0]for c in range(9)]for j in range(total)]
  return {'values':values,'flags':list(self.n.read(self.flags,total)),'quaternion':self.n.read(self.buffer+6,1)[0],'return':result,'paddingPreserved':all(raw[j*48+c:j*48+c+4]==b'\xa5'*4 for j in range(total)for c in(12,28,44))}
 def prepare_pose(self,values,flags,joints,clipCount=None):
  if clipCount is None:clipCount=len(values)
  self.n.pack('<IHBBII',self.buffer,len(values),len(values),0,0,self.samples,self.flags);self.n.write(self.samples,bytes(max(1,len(values))*48))
  for i,row in enumerate(values):
   for j,v in enumerate(row):self.n.pack('<f',self.samples+i*48+(j//3)*16+(j%3)*4,v)
  self.n.write(self.flags,bytes(flags));self.n.pack('<II',self.hierarchy+0x168,len(joints),self.joints);self.n.pack('<H',self.header+4,clipCount);self.n.write(self.joints,bytes(len(joints)*96))
  for i,j in enumerate(joints):self.n.pack('<16f',self.joints+i*96,*j['bind']);self.n.write(self.joints+i*96+0x50,bytes([j['parent']]))
  self.n.write(0x973874,bytes(12));self.n.write(0x97ade8,b'\xa5'*(255*12));self.n.write(self.matrices,b'\xa5'*(len(joints)*64))
 def result(self,joints,clipCount):
  return {'world':[list(self.n.unpack('<16I',self.matrices+i*64))for i in range(len(joints))],'scales':[list(self.n.unpack('<3I',0x97ade8+i*12))for i in range(min(len(joints),clipCount))]}
 def pose(self,values,flags,joints,clipCount=None):
  if clipCount is None:clipCount=len(values)
  self.prepare_pose(values,flags,joints,clipCount);self.n.call(0x5e9d90,[self.buffer,self.hierarchy,self.matrices,self.header,0,0,0],count=3000000)
  return self.result(joints,clipCount)
 def evaluate(self,raw,frame,joints):
  self.load(raw);self.prepare_pose([[0.]*9 for _ in joints],[0]*len(joints),joints,self.clip.nodes)
  arena=self.n.DATA+0x20000;self.n.write(arena,bytes(0x20000));self.n.pack('<I',0x827730,arena);self.n.pack('<I',0x973880,self.buffer);self.n.pack('<H',self.buffer+4,max(len(joints),self.clip.nodes));self.n.pack('<I',0x973884,0)
  self.n.call(0x5eb790,[self.hierarchy,self.base,bits(frame),0,0,self.matrices,0,0],count=3000000)
  result=self.result(joints,self.clip.nodes);result['arenaRestored']=self.n.unpack('<I',0x827730)[0]==arena;return result
