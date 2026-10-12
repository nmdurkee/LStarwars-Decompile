"""Independent finite-state PC animation packet reconstruction, verified against bytes."""
import struct,importlib.util
from pathlib import Path
_spec=importlib.util.spec_from_file_location('animation_x87',Path(__file__).with_name('animation-x87.py'));x87=importlib.util.module_from_spec(_spec);_spec.loader.exec_module(x87)
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
class Packet:
 def __init__(self,data=None):self.b=bytearray(data if data is not None else bytes(72))
 def u8(self,p):return self.b[p]
 def i16(self,p):return struct.unpack_from('<h',self.b,p)[0]
 def f(self,p):return struct.unpack_from('<f',self.b,p)[0]
 def b8(self,p,v):self.b[p]=v&255
 def s16(self,p,v):struct.pack_into('<h',self.b,p,v)
 def put(self,p,v):struct.pack_into('<f',self.b,p,v)
 def flag(self,v):self.b[0x30]|=v
def reset(p,action):
 for at in [0,4,0x14]:p.put(at,1)
 for at in [0x36,0x38,0x3a]:p.s16(at,action)
 p.b8(0x31,0);p.b8(0x30,4);p.s16(0x42,-1)
 for at in [0x3c,0x3d,0x3e]:p.b8(at,0)
def timer(p,clip,time,step,movement,events,reverseOffset,backwards,backwardsMultiplier):
 rate=clip['fps'];reference=clip['movementReference'];cap=clip['rateCap']
 if reference>0:
  rate=x87.scaled_rate(movement,reference,rate)
  if rate<0:
   if cap<0 and rate<cap:rate=cap
  elif cap>0 and rate>cap:rate=cap
 delta=x87.frame_delta(step,backwardsMultiplier,rate,p.u8(reverseOffset))
 time=f32(time+delta);end=clip['endFrame'];looped=False
 if delta<0:
  if events:p.flag(8)
  if time>=1:return time
  if not clip['flags']&2:
   if events:p.flag(1)
   return 1.
  if end>1:
   while time<1:time=f32(time+(end-1))
  else:time=1.
  looped=True
 else:
  if time<=end:return time
  if not clip['flags']&2:
   if events:p.flag(1)
   return end
  if end>1:
   while time>end:time=f32(time-(end-1))
  else:time=1.
  looped=True
 if looped:
  if events:p.flag(2)
  if p.u8(reverseOffset):
   if not backwards:p.b8(reverseOffset,0)
  elif backwards and clip['flags']&128:p.b8(reverseOffset,1)
 return time
def update(p,clips,step,movement,blendStep,backwardsMultiplier,blendMode):
 has=lambda a:a in clips and clips[a]is not None
 end=lambda a:clips[a]['endFrame']
 backwards=movement<0;movement=abs(movement);oldflags=p.u8(0x30);p.b8(0x30,0)
 p.put(4,p.f(0x14 if p.u8(0x31)else 0))
 if step==0:p.b8(0x30,32);return
 if p.i16(0x42)==-1:
  requested=p.i16(0x3a);begin=True;interrupted=False
  if p.u8(0x31):
   if requested!=-1 and requested!=p.i16(0x34)and has(requested)and clips[requested]['blendIn']==0:
    p.s16(0x36,requested);reverse=backwards and has(requested)and clips[requested]['flags']&128
    p.b8(0x3e,1 if reverse else 0);p.put(0,end(requested)if reverse else 1);p.flag(4);p.b8(0x31,0);p.put(4,p.f(0));begin=False
   else:
    elapsed=f32(p.f(8)+blendStep);p.put(8,elapsed)
    if elapsed>=p.f(12):
     p.b8(0x31,0);p.put(0,p.f(0x14));p.s16(0x36,p.i16(0x34));p.b8(0x3e,p.u8(0x3d));p.b8(0x30,64);begin=False
    elif blendMode!=1 or requested==p.i16(0x34)or not has(requested):begin=False
    else:
     interrupted=True
     if elapsed>=p.f(12)*.5:p.s16(0x38,p.i16(0x34));p.put(0x10,p.f(0x14))
     else:p.s16(0x38,p.i16(0x32))
  elif requested==p.i16(0x38)and(not oldflags&128 or requested!=p.i16(0x36)or not has(p.i16(0x36))):
   p.s16(0x36,requested);p.b8(0x31,0);begin=False
  if begin:
   previous=p.i16(0x38)
   if has(previous)and has(requested)and clips[previous]['blendOut']>blendStep and clips[requested]['blendIn']>blendStep:
    a=clips[previous];b=clips[requested];p.b8(0x31,1);p.s16(0x32,previous);p.s16(0x34,requested)
    if not interrupted:p.put(0x10,p.f(0))
    p.b8(0x3c,p.u8(0x3e)) # Native overwrites the interrupted reverse choice.
    reverse=backwards and b['flags']&128
    p.b8(0x3d,1 if reverse else 0)
    if a['flags']&2 and b['flags']&2 and a['fps']==b['fps']and a['endFrame']==b['endFrame']:p.put(0x14,p.f(0x10))
    else:p.put(0x14,b['endFrame']if reverse else 1)
    p.put(8,0);p.put(12,min(a['blendOut'],b['blendIn']));p.flag(4)
   else:
    p.s16(0x36,requested);reverse=backwards and has(requested)and clips[requested]['flags']&128
    p.b8(0x3e,1 if reverse else 0);p.put(0,end(requested)if reverse else 1);p.b8(0x31,0);p.put(4,p.f(0));p.flag(4)
 if p.i16(0x42)!=-1:
  a=p.i16(0x3a);b=p.i16(0x42)
  if has(a)and has(b):
   p.put(0x10,timer(p,clips[a],p.f(0x10),step,movement,False,0x3c,backwards,backwardsMultiplier))
   p.put(0x14,timer(p,clips[b],p.f(0x14),step,movement,True,0x3d,backwards,backwardsMultiplier))
 elif p.u8(0x31):
  a=p.i16(0x32);b=p.i16(0x34)
  if has(a)and has(b):
   p.put(0x10,timer(p,clips[a],p.f(0x10),step,movement,False,0x3c,backwards,backwardsMultiplier))
   p.put(0x14,timer(p,clips[b],p.f(0x14),step,movement,True,0x3d,backwards,backwardsMultiplier))
 elif has(p.i16(0x36)):
  a=p.i16(0x36);p.put(0,timer(p,clips[a],p.f(0),0 if oldflags&16 else step,movement,True,0x3e,backwards,backwardsMultiplier))
 else:
  requested=p.i16(0x3a);reset(p,-1);p.s16(0x3a,requested)
