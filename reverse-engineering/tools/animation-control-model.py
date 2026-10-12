"""Independent compact-packet and bounded main-player animation control model."""
import importlib.util,struct
from pathlib import Path
spec=importlib.util.spec_from_file_location('playback',Path(__file__).with_name('animation-playback-model.py'));playback=importlib.util.module_from_spec(spec);spec.loader.exec_module(playback)
Packet=playback.Packet;f32=playback.f32;w=playback.x87

def mini_to_full(mini,full):
 full.b[0:24]=mini.b[0:24];full.b[48:60]=mini.b[24:36]
 full.b[60:63]=bytes(3);full.s16(66,-1)

def full_to_mini(full,mini):mini.b[0:24]=full.b[0:24];mini.b[24:36]=full.b[48:60]

def update_mini(mini,clips,step,speed,blend,mode):
 full=Packet();mini_to_full(mini,full);playback.update(full,clips,step,speed,blend,0.,mode);full_to_mini(full,mini)

def blending(packet,source,target,model_present,available):
 return bool(packet.u8(49) and source!=-1 and target!=-1 and packet.i16(50)==source and packet.i16(52)==target and (not model_present or(available[source]and available[target])))

def current(packet):return packet.i16(52 if packet.u8(49)else 54)

def player(o,clips,ctx):
 o.s16(0x40,o.i16(0x3e));o.s16(0x7f0,o.i16(0x7ee))
 replacement=o.i16(0x3ee)
 if replacement!=-1 and ((replacement==233 and o.u8(0x7b5)!=28)or o.i16(0x42)==replacement):o.s16(0x42,o.i16(0x3f0))
 if not struct.unpack_from('<I',o.b,0x50)[0]or(o.u8(0x28b)!=0 and o.f(0x100c)==0)or o.u8(0x28b)==1:return
 direction=-1 if struct.unpack_from('<I',o.b,0xef0)[0]&0x4000 else 1
 if 1 not in clips or clips[1]is None:
  if ctx['gameFlags']&0x100000:
   speed=w.store(w.add(w.mul(w.wide(o.f(0xf30)),w.wide(o.f(0x68))),w.mul(w.wide(o.f(0xf38)),w.wide(o.f(0x70)))))
   speed=max(speed,0.)
  else:speed=ctx['inputMagnitude']
 else:speed=ctx['movementSpeed']
 p=Packet(o.b[8:80]);playback.update(p,clips,w.store(w.mul(w.wide(ctx['seconds']),w.wide(30.))),f32(speed*direction),ctx['seconds'],ctx['backwardsMultiplier'],ctx['blendMode']);o.b[8:80]=p.b
