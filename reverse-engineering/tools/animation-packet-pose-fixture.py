"""Original default-layer packet dispatch, without morph or POI output requests."""
from pathlib import Path
import importlib.util,struct
s=importlib.util.spec_from_file_location('packet_pose_skeletal',Path(__file__).with_name('animation-skeletal-blend-fixture.py'));p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
B=p.B;W=p.W;bits=p.bits;value=p.value;f32=p.f32
def select(packet,present):
 short=lambda at:struct.unpack_from('<h',packet,at)[0];flt=lambda at:struct.unpack_from('<f',packet,at)[0];valid=lambda i:0<=i<len(present)and present[i]
 if packet[0x31]:
  a,b=short(0x32),short(0x34)
  if valid(a)and valid(b):return {'kind':'blend','source':a,'target':b,'sourceFrame':bits(flt(0x10)),'targetFrame':bits(flt(0x14)),'weight':bits((W(flt(8))/W(flt(12))).store())}
  if valid(b):return {'kind':'single','clip':b,'frame':bits(flt(0x14))}
  if valid(a):return {'kind':'single','clip':a,'frame':bits(flt(0x10))}
 else:
  a=short(0x36)
  if valid(a):return {'kind':'single','clip':a,'frame':bits(flt(0))}
 return {'kind':'bind'}
def bind(joints,local):
 out=[]
 for i,j in enumerate(joints):out.append(local[i].copy()if j['parent']==255 else p.p.multiply(local[i],out[j['parent']]))
 return [[bits(x)for x in row]for row in out]
class Oracle(p.Oracle):
 def __init__(self):
  super().__init__();self.requests=[];self.capture=False;self.slotPointers=[]
  from unicorn import UC_HOOK_CODE
  from unicorn.x86_const import UC_X86_REG_ESP
  def observe(mu,address,size,user):
   if not self.capture:return
   sp=mu.reg_read(UC_X86_REG_ESP)
   if address==0x5d36d0:request={'kind':'bind'}
   elif address==0x5f38c0:
    hierarchy,clip,frame=self.n.unpack('<III',sp+4);request={'kind':'single','clip':self.slotPointers.index(clip),'frame':frame}
   else:
    hierarchy,a,af,b,bf,weight=self.n.unpack('<6I',sp+4);request={'kind':'blend','source':self.slotPointers.index(a),'target':self.slotPointers.index(b),'sourceFrame':af,'targetFrame':bf,'weight':weight}
   self.requests.append(request)
  for address in(0x5d36d0,0x5f38c0,0x5f38f0):self.n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
 def layer_ids(self,count,mask,present=True):
  d=self.n.DATA;model=d+0x48000;array=d+0x49000;self.n.write(array,b'\xa5'*64);self.n.pack('<I',model+4,self.hierarchy);self.n.pack('<i',self.hierarchy+0x190,count)
  total=self.n.call(0x62e190,[model if present else 0,array,mask]);return {'ids':list(self.n.unpack('<'+'H'*total,array)),'untouchedTail':self.n.read(array+total*2,64-total*2)==b'\xa5'*(64-total*2)}
 def dispatch(self,packet,raws,joints,local,layerCount,mask,present=True):
  self.prepare_pose([[0.]*9 for _ in joints],[0]*len(joints),joints,len(joints));self.slotPointers=[];at=self.base
  for raw in raws:
   if raw is None:self.slotPointers.append(0);continue
   clip=p.p.Clip(raw);data=bytearray(clip.raw)
   for q in(36,40,44,48,52,56):
    off=clip.u32(q)
    if off:struct.pack_into('<I',data,q,at+off)
   self.n.write(at,data);self.slotPointers.append(at);at=(at+len(data)+0xfff)&~0xfff
  assert at<self.base+0x400000
  d=self.n.DATA;model=d+0x48000;slots=d+0x49000;registry=d+0x4a000;state=d+0x4b000;localAt=d+0x4c000
  self.n.write(model,bytes(0x100));self.n.pack('<I',model+4,self.hierarchy);self.n.pack('<I',model+0xc,slots);self.n.pack('<'+'I'*len(raws),slots,*self.slotPointers);self.n.pack('<I',0x29130e4,registry);self.n.pack('<i',registry+8,len(raws));self.n.pack('<i',self.hierarchy+0x190,layerCount);self.n.pack('<I',self.hierarchy+0x170,localAt)
  for i,m in enumerate(local):self.n.pack('<16f',localAt+i*64,*m)
  self.n.write(state,packet);self.n.pack('<I',0x80fb94,0x62e190);self.n.pack('<I',0x973880,self.buffer);self.n.pack('<H',self.buffer+4,len(joints));self.n.write(0x9737de,b'\0');self.n.pack('<I',0x973888,0);self.n.pack('<I',0x973884,0);self.n.pack('<I',0x827730,d+0x20000);self.requests.clear();self.capture=True
  self.n.call(0x62e290,[model if present else 0,state,0,self.matrices,0,0,0,mask],count=5000000);self.capture=False
  return {'matrices':[list(self.n.unpack('<16I',self.matrices+i*64))for i in range(len(joints))],'requests':self.requests.copy(),'packetPreserved':self.n.read(state,72)==packet,'arenaRestored':self.n.unpack('<I',0x827730)[0]==d+0x20000}
