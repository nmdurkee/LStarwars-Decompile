"""Original display bounds producer and finite independent arithmetic model."""
from pathlib import Path
import importlib.util,struct,math
s=importlib.util.spec_from_file_location('pose',Path(__file__).with_name('scene-animation-pose-fixture.py'));p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
nx=p.nx;B=p.B;W=p.W;bits=p.bits;value=p.value;f32=p.f32;S=p.S
def calculate(matrix,lo,hi,center):
 half=[(S(W(b)-W(a))*W(.5)).store()for a,b in zip(lo,hi)];local=[(S(W(a)+W(b))*W(.5)).store()for a,b in zip(lo,hi)]
 ext=[]
 for c in range(3):ext.append((W(abs(matrix[c]))*W(half[0])+W(abs(matrix[4+c]))*W(half[1])+W(abs(matrix[8+c]))*W(half[2])).store())
 point=[(W(matrix[c])*W(local[0])+W(matrix[4+c])*W(local[1])+W(matrix[8+c])*W(local[2])+W(matrix[12+c])).store()for c in range(3)]
 total=(W(ext[1])+W(ext[0])+W(ext[2])).store();radius=0. if total<0 else f32(math.sqrt(total))
 if center:return[bits(v)for v in point]+[bits(radius)]+[bits(v)for v in ext]+[None]
 return[bits((W(a)-W(b)).store())for a,b in zip(point,ext)]+[None]+[bits((W(a)+W(b)).store())for a,b in zip(point,ext)]+[None]
class Oracle:
 def __init__(self):self.n=nx.NativeX86();self.d=self.n.DATA
 def run(self,matrix,fallback,lo,hi,mode=2,pointer=1,center=False,flags=0,gate=0x10000,present=True,scene=True,descriptor=True,notify=True,padding=0x12345678):
  n=self.n;d=self.d;reference=d;world=d+0x100;desc=d+0x400;special=d+0x800;normal=d+0xa00;instance=d+0xb00;animated=d+0xc00;table=d+0x1000
  n.write(d,bytes(0x2000));n.write(n.STACK,struct.pack('<I',padding)*16384)
  n.pack('<III',reference,world if scene else 0,normal if mode==1 else 0,special if present else 0);n.pack('<I',world+0x110,desc if descriptor else 0);n.pack('<I',desc+0x44,table);n.pack('<I',desc+0x74,gate|(0x4000 if center else 0));n.pack('<I',normal+0x40,instance)
  n.pack('<16f',instance,*fallback);n.pack('<16f',special+0x40,*fallback);n.pack('<16f',animated,*matrix);n.pack('<I',instance+0x48,animated if pointer==1 else 0);n.pack('<I',special+0xc4,animated if pointer==1 else 0xffffffff if pointer==-1 else 0)
  n.pack('<3f',special+0x80,*lo);n.pack('<3f',special+0x90,*hi);n.pack('<II',special+0xb8,flags,0);n.pack('<I',special+0xc0,1);n.write(table,b'\xa5'*96)
  n.call(0x5ea660 if notify else 0x5df480,[reference if mode else 0]);raw=list(n.unpack('<8I',table+32));result={'flags':n.unpack('<I',special+0xb8)[0],'record':raw.copy(),'untargetedPreserved':n.read(table,32)==b'\xa5'*32 and n.read(table+64,32)==b'\xa5'*32}
  active=not notify or bool(mode and present and scene and descriptor and gate&0x10000)
  if active:
   if not center:result['record'][3]=None
   result['record'][7]=None
  return result,raw
 def pose_chain(self,raw,frame,previous,matrix,fallback,lo,hi,center=False):
  # Establish a genuine reference graph with bounds owner initially disabled.
  self.run(matrix,fallback,lo,hi,gate=0);n=self.n;d=self.d;clip=p.Clip(raw)
  if not hasattr(self,'mappedClip'):
   n.mu.mem_map(0x11000000,0x400000);self.mappedClip=True;n.write(0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes())
  blob=bytearray(raw)
  for i in (36,40,44,48,52,56):
   at=clip.ptr(i)
   if at:struct.pack_into('<I',blob,i,0x11000000+at)
  n.write(0x11000000,blob);n.pack('<I',0x973880,d+0x5000);n.pack('<I',d+0x5008,d+0x6000);n.write(0x9737dd,b'\0\0')
  n.pack('<III',d+0x100+0x4c,d+0xc00,d+0x2000,d+0x3000);n.pack('<I',d+0x3000,0x11000000);n.pack('<I',d+0x400+0x74,0x10000|(0x4000 if center else 0));n.pack('<f',d+0xc00+0x58,previous);n.write(d+0x2000,bytes(64))
  n.call(0x552760,[d,bits(frame)]);record=list(n.unpack('<8I',d+0x1000+32));changed=frame!=previous
  if changed:
   if not center:record[3]=None
   record[7]=None
  return {'target':list(n.unpack('<16I',d+0xc00)),'cache':list(n.unpack('<16I',d+0x2000)),'previous':n.unpack('<I',d+0xc00+0x58)[0],'flags':n.unpack('<I',d+0x800+0xb8)[0],'record':record}
