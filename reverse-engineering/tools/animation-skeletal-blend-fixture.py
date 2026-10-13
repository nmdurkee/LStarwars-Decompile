"""Original Euler blend path with finite endpoint-frame domain."""
from pathlib import Path
import importlib.util,struct
s=importlib.util.spec_from_file_location('skeletal_blend_base',Path(__file__).with_name('animation-skeletal-fixture.py'));p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
B=p.B;W=p.W;S=p.S;bits=p.bits;value=p.value;f32=p.f32
def blend(clip,frame,values,flags,weight,count=None,start=0,root=True):
 assert clip.frames>1 and frame<=clip.first+clip.frames-1
 if count is None:count=clip.nodes
 take=min(count,clip.nodes);assert start+take<=clip.nodes
 sampled=clip.sample(frame);out=[row.copy()for row in values];outFlags=flags.copy();oneMinus=(W(1)-W(weight)).store();translation=[0xa5a5a5a5]*3
 for n in range(start,start+take):
  flag=clip.raw[clip.flags+n];outFlags[n]|=flag
  for i in range(9):
   old=values[n][i];new=sampled[n][i];active=bool(flag&[2,1,8][i//3])
   if active:
    delta=(W(new)-W(old)).store()
    if 3<=i<6 and(delta>3.1415927410125732 or delta< -3.1415927410125732):
     angle=(W(delta)*W(65536)/W(6.2831854820251465)).trunc()&65535;angle=angle-65536 if angle>=32768 else angle;delta=(W(angle)*W(9.58738019107841e-05)).store()
    out[n][i]=(W(delta)*W(weight)+W(old)).store()
   else:out[n][i]=(W(old)*W(oneMinus)+(W(weight)if i>=6 else W(0))).store()if i>=6 else(W(old)*W(oneMinus)).store()
   if root and start==0 and n==0 and i<3:translation[i]=bits((-new if i==2 else new)if active else 0.)
 return {'values':[[bits(x)for x in row]for row in out],'flags':outFlags,'root':translation,'return':0,'paddingPreserved':True,'quaternion':0}
class Oracle(p.Oracle):
 def blend(self,raw,frame,values,flags,weight,count=None,start=0,root=True):
  self.load(raw);n=len(values)
  if count is None:count=self.clip.nodes
  self.n.write(self.samples,b'\xa5'*(n*48));self.n.write(self.flags,bytes(flags));self.n.pack('<IHBBII',self.buffer,n,n,0,0,self.samples,self.flags)
  for i,row in enumerate(values):
   for j,v in enumerate(row):self.n.pack('<f',self.samples+i*48+(j//3)*16+(j%3)*4,v)
  at=self.n.DATA+0x18000;self.n.write(at,b'\xa5'*12);result=self.n.call(0x5cdd50,[self.base,bits(frame),self.buffer,bits(weight),count,start,at if root else 0],count=3000000)
  data=self.n.read(self.samples,n*48)
  return {'values':[[struct.unpack_from('<I',data,i*48+(j//3)*16+(j%3)*4)[0]for j in range(9)]for i in range(n)],'flags':list(self.n.read(self.flags,n)),'root':list(self.n.unpack('<3I',at)),'return':result,'paddingPreserved':all(data[i*48+j:i*48+j+4]==b'\xa5'*4 for i in range(n)for j in(12,28,44)),'quaternion':self.n.read(self.buffer+6,1)[0]}
 def evaluate_blend(self,sourceRaw,sourceFrame,targetRaw,targetFrame,weight,joints,depth=0):
  self.load(sourceRaw);sourceCount=self.clip.nodes;target=p.Clip(targetRaw);assert sourceCount==target.nodes and 0<=depth<4
  second=self.base+0x200000;data=bytearray(target.raw)
  for q in(36,40,44,48,52,56):
   at=target.u32(q)
   if at:struct.pack_into('<I',data,q,second+at)
  self.n.write(second,data);self.prepare_pose([[0.]*9 for _ in joints],[0]*len(joints),joints,sourceCount)
  arena=self.n.DATA+0x20000;self.n.write(arena,bytes(0x20000));self.n.pack('<I',0x827730,arena);self.n.pack('<I',0x973880,self.buffer);self.n.pack('<H',self.buffer+4,max(len(joints),sourceCount));self.n.pack('<I',0x973884,0);self.n.pack('<I',0x973888,depth);self.n.write(0x96e4e8,b'\x33'*4);self.n.write(0x9737de,b'\0')
  self.n.call(0x5ebb90,[self.hierarchy,self.base,bits(sourceFrame),second,bits(targetFrame),bits(weight),0,0,self.matrices,0,0],count=4000000)
  result=self.result(joints,sourceCount);result.update({'arenaRestored':self.n.unpack('<I',0x827730)[0]==arena,'depthRestored':self.n.unpack('<I',0x973888)[0]==depth,'globalRestored':self.n.read(0x9737de,1)==b'\0','stackEntry':self.n.read(0x96e4e8+depth,1)[0]});return result
