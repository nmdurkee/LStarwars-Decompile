"""Finite shipped legacy morph curves, independent arithmetic and original x86."""
from pathlib import Path
import importlib.util,struct,math
B=Path(__file__).resolve().parent.parent
s=importlib.util.spec_from_file_location('morph_math',B/'tools/scene-animation-pose-fixture.py');p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
W=p.W;S=p.S;bits=p.bits;value=p.value;f32=p.f32
s=importlib.util.spec_from_file_location('morph_native',B/'tools/native-x86.py');native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
class Clip:
 def __init__(self,raw,header=16,originalBase=None):
  self.raw=bytes(raw);self.h=header;self.base=self.u32(4)if originalBase is None else originalBase;self.duration=self.fl(header);self.nodes=self.i16(header+4);self.channels=self.i16(header+6);self.chunks=self.i16(header+8);self.curves=self.ptr(header+12);self.types=self.ptr(header+16);self.fields=[header+12,header+16,header+20]
  for i in range(self.nodes*self.channels):
   t=self.raw[self.types+i];assert t in(0,1,2)
   if t:
    at=self.curves+4*i;d=self.ptr(at);self.fields.extend([at,d,d+4,d+8])
 def u32(self,o):return struct.unpack_from('<I',self.raw,o)[0]
 def u16(self,o):return struct.unpack_from('<H',self.raw,o)[0]
 def i16(self,o):return struct.unpack_from('<h',self.raw,o)[0]
 def i8(self,o):return struct.unpack_from('<b',self.raw,o)[0]
 def fl(self,o):return struct.unpack_from('<f',self.raw,o)[0]
 def ptr(self,o):return self.u32(o)-self.base
 def time(self,frame):
  if frame>=self.duration:
   if self.duration==1:return(1.,0.,0,1,0,0)
   frame=(W(self.duration)-W(.01)).store()
  elif frame<1:frame=1.
  chunk=min((int(frame)-1)>>5,self.chunks-1);local=f32(frame-(chunk<<5));sub=int(local)-1;byte=sub//8;mask=((1<<((sub%8)+1))-1)&255
  return(frame,local,chunk,mask,byte,sub)
 def sample(self,index,time):
  at=self.curves+4*index;kind=self.raw[self.types+index]
  if kind==0:return self.fl(at)
  d=self.ptr(at);masks=self.ptr(d);offsets=self.ptr(d+4);data=self.ptr(d+8);frame,local,chunk,mask,byte,sub=time;packed=self.u32(masks+4*chunk)
  active=sum(((packed>>(8*j))&255).bit_count()for j in range(byte))+(((packed>>(8*byte))&255)&mask).bit_count();key=self.u16(offsets+2*chunk)+active
  if kind==1:
   at=data+(key-1)*16;a,b=map(W,[self.fl(at+8),self.fl(at+24)]);u=S((W(frame)-W(self.fl(at)))*W(self.fl(at+4)));span=S(W(self.fl(at+16))-W(self.fl(at)));m0=S(span*W(self.fl(at+12)));m1=S(span*W(self.fl(at+28)))
  else:
   at=data+4+key*4;span=W(self.raw[at+7]-self.raw[at+3]);reciprocal=S(W(1)/span)if span.store()!=0 else W(0);tangent=W(self.fl(data));scale=W(self.fl(data+4));m0=S(W(self.i8(at+2))*span*tangent);m1=S(W(self.i8(at+6))*span*tangent);a=S(W(self.i16(at))*scale);b=S(W(self.i16(at+4))*scale);u=S((W(frame)-W(1)-W(self.raw[at+3]))*reciprocal)
  delta=a-b;coefficient=S(((u*((delta*W(2)+m0)+m1)-delta*W(3))-m0*W(2))-m1)
  return((coefficient*u+m0)*u+a).store()
 def layer(self,layer,frame):
  if layer>=self.nodes:return[]
  time=self.time(frame);return[self.sample(layer*self.channels+i,time)for i in range(self.channels)]
def single(clip,frame,layers):return None if clip is None or layers==[]else[clip.layer(i,frame)for i in([0]if layers is None else layers)]
def blend(a,af,b,bf,weight,layers):
 if(a is None and b is None)or layers==[]:return None
 out=[];inverse=W(1.0-weight)
 for i in[0]if layers is None else layers:
  aa=[]if a is None else a.layer(i,af);bb=[]if b is None else b.layer(i,bf);out.append([(W(bb[j]if j<len(bb)else 0)*W(weight)+W(aa[j]if j<len(aa)else 0)*inverse).store()for j in range(max(len(aa),len(bb)))])
 return out
class Oracle:
 def __init__(self):
  self.n=native.NativeX86();self.base=self.n.DATA+0x10000;self.timeAt=self.n.DATA+0x80000;self.resultAt=self.n.DATA+0x80100;self.layersAt=self.n.DATA+0x81000;self.n.write(0x971760,bytes(i.bit_count()for i in range(256)));self.tramp=self.n.STOP+0x100;self.n.write(self.tramp,b'\xd9\x1d'+struct.pack('<I',self.resultAt)+b'\xe9'+struct.pack('<i',self.n.STOP-(self.tramp+11)))
 def upload(self,c,at=None):
  if c is None:return 0
  at=self.base if at is None else at;raw=bytearray(c.raw)
  for q in set(c.fields):
   value=struct.unpack_from('<I',raw,q)[0]
   if value:struct.pack_into('<I',raw,q,value-c.base+at)
  self.n.write(at,raw);return at+c.h
 def scalar(self,c,index,frame):
  h=self.upload(c);self.n.write(self.timeAt,bytes(24));self.n.call(0x5c9c40,[h,bits(frame),self.timeAt]);self.n.call(0x5c9520,[self.base+c.curves+4*index,self.timeAt,c.raw[c.types+index]],count=100000)
  self.n.mu.emu_start(self.tramp,self.n.STOP,count=10);return self.n.unpack('<I',self.resultAt)[0]
 def get_time(self,c,frame):
  h=self.upload(c);self.n.write(self.timeAt,b'\xa5'*24);self.n.call(0x5c9c40,[h,bits(frame),self.timeAt]);return list(self.n.unpack('<6I',self.timeAt))
 def prepare_pool(self,layers):
  assert layers is None or all(i>=0 for i in layers)
  self.n.pack('<i',0x80e1a8,60000);self.n.pack('<i',0x80e1ac,4096);self.n.write(0x97c230,bytes(4096*4))
  if layers:self.n.pack('<'+'h'*len(layers),self.layersAt,*layers)
 def weights(self,address,count):
  if not address:return None
  rows=[]
  for i in range(count):
   q=self.n.unpack('<I',address+4*i)[0];rows.append(q)
  return rows
 def evaluate(self,a,af,layers,b=None,bf=0.,weight=0.,doBlend=False):
  self.prepare_pool(layers);ap=self.upload(a);bp=self.upload(b,self.base+0x30000);count=1 if layers is None else len(layers);args=[count,0 if layers is None else self.layersAt,ap,bits(af)]
  if doBlend:args.extend([bp,bits(bf),bits(weight)])
  q=self.n.call(0x5d3dc0 if doBlend else 0x5d3a20,args,count=2000000);pointers=self.weights(q,count);out=[]
  if pointers is None:return None
  for layer,at in zip([0]if layers is None else layers,pointers):
   ca=a.channels if a is not None and layer<a.nodes else 0;cb=b.channels if b is not None and layer<b.nodes else 0;size=max(ca,cb)if doBlend else ca;out.append(list(self.n.unpack('<'+'I'*size,at+8)))
  return out
 def packet(self,packet,clips,layerCount,mask):
  self.prepare_pool([]);d=self.n.DATA;model=d+0x83000;hier=d+0x84000;joint=d+0x85000;bind=d+0x86000;slots=d+0x87000;empty=d+0x88000;registry=d+0x89000;state=d+0x8a000;output=d+0x8b000;matrices=d+0x8c000
  self.n.write(model,bytes(0x100));self.n.pack('<I',model+4,hier);self.n.pack('<I',model+0xc,empty);self.n.pack('<I',model+0x10,slots);self.n.write(empty,bytes(4*len(clips)))
  for i,c in enumerate(clips):self.n.pack('<I',slots+4*i,self.upload(c,self.base+0x20000*i))
  self.n.write(hier,bytes(0x200));self.n.pack('<H',hier+0x168,1);self.n.pack('<II',hier+0x16c,joint,bind);self.n.pack('<i',hier+0x190,layerCount);self.n.write(joint,bytes(96));self.n.write(joint+0x50,b'\xff');self.n.pack('<16f',bind,*[float(i%5==0)for i in range(16)]);self.n.write(matrices,b'\xa5'*64)
  self.n.pack('<I',0x29130e4,registry);self.n.pack('<i',registry+8,len(clips));self.n.pack('<I',0x80fb94,0x62e190);self.n.write(state,packet);self.n.pack('<I',output,0xa5a5a5a5)
  self.n.call(0x62e290,[model,state,0,matrices,output,0,0,mask],count=3000000);layers=[i for i in range(min(32,layerCount))if mask&(1<<i)]
  if not layers:return {'untouched':self.n.unpack('<I',output)[0]==0xa5a5a5a5,'rows':None}
  pointer=self.n.unpack('<I',output)[0]
  if not pointer:return {'untouched':False,'rows':None}
  short=lambda at:struct.unpack_from('<h',packet,at)[0];valid=lambda i:0<=i<len(clips)and clips[i]is not None
  if packet[49]:selected=[clips[i]for i in[short(50),short(52)]if valid(i)]
  else:selected=[clips[short(54)]]if valid(short(54))else[]
  rows=[]
  for i,layer in enumerate(layers):
   size=max((c.channels if layer<c.nodes else 0 for c in selected),default=0);at=self.n.unpack('<I',pointer+4*i)[0];rows.append(list(self.n.unpack('<'+'I'*size,at+8)))
  return {'untouched':False,'rows':rows}
