"""Original PC POI matrix helpers and packet output tail, no instruction stubs."""
from pathlib import Path
import importlib.util,struct
s=importlib.util.spec_from_file_location('points_packet_base',Path(__file__).with_name('animation-packet-pose-fixture.py'));p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
B=p.B;bits=p.bits;value=p.value;f32=p.f32;multiply=p.p.p.multiply
def point(bindings,index,world,joints):
 q=bindings['points'][bindings['lookup'][index]];return multiply(multiply(q['matrix'],joints[q['joint']]),world)
def outputs(bindings,world,joints,position=True,matrix=True):
 positions=[[0xa5a5a5a5]*3 for _ in range(16)];matrices=[[0xa5a5a5a5]*16 for _ in range(16)]
 if position or matrix:
  for i,enabled in enumerate(bindings['enabled']):
   if enabled:
    m=[bits(x)for x in point(bindings,i,world,joints)]
    if position:positions[i]=m[12:15]
    if matrix:matrices[i]=m
 return {'positions':positions,'matrices':matrices}
class Oracle(p.Oracle):
 def prepare_points(self,bindings,world,joints=None):
  d=self.n.DATA;points=d+0x60000;lookup=d+0x66000;self.world=d+0x67000;self.poiMatrices=d+0x68000;self.poiPositions=d+0x6a000
  self.n.pack('<III',self.hierarchy+0x184,points,len(bindings['lookup']),lookup);self.n.write(lookup,bytes(bindings['lookup']));self.n.write(points,bytes(max(1,len(bindings['points']))*80))
  for i,q in enumerate(bindings['points']):self.n.pack('<16f',points+i*80,*q['matrix']);self.n.write(points+i*80+68,bytes([q['joint']]))
  self.n.pack('<16f',self.world,*world);self.n.write(self.poiMatrices,b'\xa5'*(16*64));self.n.write(self.poiPositions,b'\xa5'*(16*12))
  if joints is not None:
   for i,m in enumerate(joints):self.n.pack('<16f',self.matrices+i*64,*m)
 def point(self,bindings,index,world,joints):
  self.prepare_points(bindings,world,joints);at=self.n.DATA+0x6c000;self.n.call(0x5daae0,[self.hierarchy,index,self.world,self.matrices,at]);return list(self.n.unpack('<16I',at))
 def result_points(self):return {'positions':[list(self.n.unpack('<3I',self.poiPositions+i*12))for i in range(16)],'matrices':[list(self.n.unpack('<16I',self.poiMatrices+i*64))for i in range(16)]}
 def outputs(self,bindings,world,joints,position=True,matrix=True):
  self.prepare_points(bindings,world,joints);model=self.n.DATA+0x48000;self.n.pack('<I',model+4,self.hierarchy);self.n.pack('<16I',model+0x14,*bindings['enabled']);self.n.call(0x62e1e0,[model,self.world,self.matrices,self.poiPositions if position else 0,self.poiMatrices if matrix else 0]);return self.result_points()
 def chain(self,packet,raws,joints,local,bindings,world,layerCount,mask,position=True,matrix=True):
  # The inherited dispatcher writes the exact scratch model/clip graph. Its
  # single Python call boundary is configured with POI input/output pointers
  # immediately before original62e290 starts; no emulated service is intercepted.
  call=self.n.call
  def configured(address,args=(),regs=None,count=200000):
   assert address==0x62e290
   self.prepare_points(bindings,world);self.n.pack('<16I',self.n.DATA+0x48000+0x14,*bindings['enabled']);args=list(args);args[2]=self.world;args[5]=self.poiPositions if position else 0;args[6]=self.poiMatrices if matrix else 0
   return call(address,args,regs,count)
  self.n.call=configured
  try:result=super().dispatch(packet,raws,joints,local,layerCount,mask)
  finally:self.n.call=call
  result['skeletalMatrices']=result.pop('matrices');result.update(self.result_points());return result
