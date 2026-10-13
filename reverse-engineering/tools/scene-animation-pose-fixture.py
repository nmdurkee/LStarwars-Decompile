"""Exact finite original-PC scene scalar/matrix model and isolated oracle."""
from pathlib import Path
import importlib.util,struct,math
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=module('scene_pose_native','native-x86.py');x=module('scene_pose_wide','animation-x87.py');B=nx.BASE
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def value(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def f32(v):return value(bits(v))
class W:
 def __init__(self,v):self.w=x.wide(v);self.approx=float(v)
 @staticmethod
 def make(w,a):r=W(0);r.w=w;r.approx=a;return r
 def __add__(a,b):return W.make(x.add(a.w,b.w),a.approx+b.approx)
 def __sub__(a,b):return W.make(x.add(a.w,(-b.w[0],b.w[1])),a.approx-b.approx)
 def __mul__(a,b):return W.make(x.mul(a.w,b.w),a.approx*b.approx)
 def __truediv__(a,b):return W.make(x.div(a.w,b.w),a.approx/b.approx)
 def store(self):
  v=x.store(self.w);return math.copysign(0.,self.approx)if v==0 else v
 def trunc(self):
  s,e=self.w;v=abs(s)<<e if e>=0 else abs(s)>>-e
  return -v if s<0 else v
def S(v):return W(v.store())
class Clip:
 def __init__(self,raw):
  self.raw=bytes(raw);self.magic=self.u32(0);assert self.magic in (0x414e4934,0x414e4935)
  self.count=self.u16(6);self.stride=self.u16(8);self.frames=self.u16(10);self.first=self.u16(14)
  assert self.u16(4)==1 and self.u16(12)==9 and self.count>0 and (self.count==1 or self.frames>1)
  self.scales,self.constants,self.types,self.keys,self.flags=[self.ptr(i)for i in (36,40,44,48,52)]
  self.flag=self.raw[self.flags]
 def u16(self,p):return struct.unpack_from('<H',self.raw,p)[0]
 def u32(self,p):return struct.unpack_from('<I',self.raw,p)[0]
 def flt(self,p):return struct.unpack_from('<f',self.raw,p)[0]
 def ptr(self,p):
  v=struct.unpack_from('<i'if self.magic==0x414e4935 else'<I',self.raw,p)[0];return 0 if not v else v+(p if self.magic==0x414e4935 else 0)
 def sample(self,frame):
  if self.count==1:key=0.
  else:key=S(S(S(W(frame)-W(self.first))*W(self.count-1))/W(self.frames-1)).store();key=max(0.,min(float(self.count-1),key))
  whole=int(key);q=whole&3;fraction=f32(key-whole);p=self.keys+(whole//4)*self.stride;sc=self.scales;out=[]
  for i in range(9):
   t=self.u16(self.types+2*i);f=0. if self.raw[self.types+18+i]&1 else fraction
   if t>=16:v=(W(self.u16(self.constants+2*(t-16+self.raw[17])))*W(self.flt(32))+W(self.flt(28))).store()
   else:
    scale=self.flt(sc);minimum=self.flt(sc+4);sc+=8
    if t==6:
     factor=lambda p,q:S(W((self.u32(p)>>(8+6*q))&63)*W(0.015873020514845848))
     a,b=W(self.raw[p]),W(self.raw[p+self.stride]);fa=factor(p,q)
     if q<3:v=a+S(fa+W(f)*(factor(p,q+1)-fa))*(b-a)
     else:
      start=S(a+fa*(b-a));end=S(b+(W(self.raw[p+2*self.stride])-b)*factor(p+self.stride,0));v=start+W(f)*(end-start)
     p+=4
    elif t==7:
     v=W(packed16(self.raw,p,q,self.stride,f,scale,minimum));p+=8;out.append(v.store());continue
    else:raise ValueError('unsupported scene curve '+str(t))
    v=(v*W(scale)+W(minimum)).store()
   out.append(v)
  return out
def packed16(raw,p,q,stride,f,scale,minimum):
 u=lambda off:struct.unpack_from('<H',raw,off)[0]
 def factor(at,j):
  a,b,c=u(at+2),u(at+4),u(at+6);return ((b&0xf000)>>8)|((c&0xf000)>>4)|(a>>12)if j==3 else(a,b,c)[j]&4095
 a,b=W(u(p)),W(u(p+stride))
 if q<3:
  ratio=S((W(factor(p,q))+W(f)*(W(factor(p,q+1))-W(factor(p,q))))/W(4095));v=a+ratio*(b-a)
 else:
  first=S(a+W(factor(p,3))*(b-a)/W(4095));second=S(b+W(factor(p+stride,0))*(W(u(p+2*stride))-b)/W(4095));v=first+W(f)*(second-first)
 return (v*W(scale)+W(minimum)).store()
table=struct.unpack('<32768f',(B/'references/native-animation-sine-table.f32').read_bytes())
def rotation(angles):
 sn=lambda a:W(table[(a>>1)&32767]);cs=lambda a:W(table[((a+16384)>>1)&32767])
 a,b,c=angles;sx,sy,sz=sn(a),sn(b),sn(c);cx,cy,cz=cs(a),cs(b),cs(c)
 return [v.store()if isinstance(v,W)else float(v)for v in [cy*cz,sz*cy,-table[(b>>1)&32767],0,sx*sy*cz-sz*cx,cz*cx+sz*(sx*sy),cy*sx,0,sz*sx+cz*(sy*cx),(sy*cx)*sz-cz*sx,cy*cx,0,0,0,0,1]]
def pose(values,flags):
 m=rotation([(W(v)*W(10430.3779296875)).trunc()for v in values[3:6]])if flags&1 else[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.]
 if flags&8:
  for r in range(3):
   for c in range(3):m[r*4+c]=(W(m[r*4+c])*W(values[r+6])).store()
 for i in range(3):m[12+i]=(W(m[12+i])+W(values[i])).store()
 for i in (2,6,8,9,11,14):m[i]=-m[i]
 return m
class Oracle:
 def __init__(self):
  self.n=nx.NativeX86();self.n.mu.mem_map(0x11000000,0x400000);self.base=0x11000000;self.out=self.n.DATA+0x1000;self.matrix=self.n.DATA+0x2000
  self.n.write(0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes());self.n.pack('<I',0x973880,self.n.DATA);self.n.pack('<I',self.n.DATA+8,self.out)
  self.n.write(0x9737dd,b'\0\0')
  self.bounds=[];self.captureBounds=False
  from unicorn import UC_HOOK_CODE
  def bound(mu,address,size,user):
   if self.captureBounds:self.bounds.append({'target':list(self.n.unpack('<16I',self.n.DATA+0x12000)),'cache':list(self.n.unpack('<16I',self.n.DATA+0x13000))})
  self.n.mu.hook_add(UC_HOOK_CODE,bound,begin=0x5ea660,end=0x5ea660)
 def load(self,raw):
  c=Clip(raw);data=bytearray(raw)
  for p in (36,40,44,48,52,56):
   q=c.ptr(p)
   if q:struct.pack_into('<I',data,p,self.base+q)
  self.n.write(self.base,data)
 def sample(self,frame):
  self.n.call(0x5ce350,[self.base,bits(frame),self.out,0,0]);return list(self.n.unpack('<9I',self.out))
 def pose(self,frame):
  self.n.call(0x5ea390,[self.base,0,bits(frame),self.matrix]);return list(self.n.unpack('<16I',self.matrix))
 def application(self,frame,previous,base,cached,target,kind=2,present=True,clip=True,tick=False):
  d=self.n.DATA;s=d+0x10000;ref=d+0x11000;t=d+0x12000;c=d+0x13000;display=d+0x14000;normal=d+0x15000;instance=d+0x16000;desc=d+0x17000;table=d+0x18000
  self.n.write(s,bytes(0x9000));self.n.pack('<II',s+0x48,0x10001,t);self.n.pack('<II',s+0x50,c,table);self.n.pack('<I',s+0x110,desc);self.n.pack('<I',desc+0x70,display);self.n.pack('<I',table,self.base if clip else 0)
  self.n.pack('<III',ref,s,normal if kind==1 else 0,display if kind==2 else 0);self.n.pack('<I',normal+0x40,instance);self.n.pack('<I',instance+0x48,t if present else 0);self.n.pack('<I',display+0xc4,t if present else 0);self.n.pack('<I',display+0xb8,2)
  self.n.pack('<3f',instance+0x30,*base);self.n.pack('<3f',display+0x70,*base);self.n.pack('<16f',t,*target);self.n.pack('<16f',c,*cached);self.n.pack('<f',t+0x4c,frame);self.n.pack('<f',t+0x58,previous);self.n.pack('<HH',t+0x5c,0,0)
  before=self.n.read(t+0x40,0x20);self.bounds.clear();self.captureBounds=True
  self.n.call(0x5f4b90 if tick else 0x552760,[s,bits(0.)]if tick else[ref,bits(frame)])
  self.captureBounds=False;after=self.n.read(t+0x40,0x20)
  return {'target':list(self.n.unpack('<16I',t)),'cache':list(self.n.unpack('<16I',c)),'previous':self.n.unpack('<I',t+0x58)[0],'bounds':self.bounds.copy(),'otherTargetBytesPreserved':before[:24]+before[28:]==after[:24]+after[28:]}
