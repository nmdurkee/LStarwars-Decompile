"""Original general hit routine with bounded world/objects and media-boundary hooks."""
import importlib.util,struct,json,itertools,random
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;OBJ=n.DATA;ATT=OBJ+0x2000;CHAR=OBJ+0x4000;GAME=OBJ+0x5000;CHEAT=OBJ+0x6000;PAD=OBJ+0x7000;PHYS=OBJ+0x7100;MODEL=OBJ+0x8000;ANIMS=OBJ+0x9000;WORLD=OBJ+0x10000;LEVEL=OBJ+0x15000
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
report={'binarySha256':n.sha256,'method':'Original ObjHitObj0x438230 with original health, protection, context cleanup, RNG, no-script lookup and hit-reaction callees. Synthetic bounded state. Only media/rumble/alert boundaries intercepted.','contracts':{},'failures':[]};events=[]
hooks={0x4399e0:'AlertSurroundingCreatures',0x547930:'GameAudio_PlaySfx',0x681e90:'PlayIndexedSfx',0x681f40:'PlayNamedSfx',0x54a8a0:'NewBuzz',0x54a850:'NewRumble',0x54aae0:'TakeHitRumble',0x54aa70:'AttackerHitRumble',0x54aa10:'KillRumble'}
def boundary(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];events.append(hex(address));mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for address in hooks:n.mu.hook_add(UC_HOOK_CODE,boundary,begin=address,end=address)
def reset():
 n.write(OBJ,bytes(0x16000));events.clear();n.pack('<I',0x8032c4,CHEAT);n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,LEVEL);n.pack('<I',WORLD+0x12c,LEVEL+0x100);n.pack('<I',0x800944,0);n.pack('<h',0x921454,-1);n.pack('<I',0x7f1138,0);n.pack('<I',0x855de0,0);n.pack('<I',0x80253c,0x1234);n.write(0x95556c,bytes(24));n.pack('<I',0x93d828,0);n.pack('<I',0x924de0,0);n.pack('<f',0x925018,1/60)
 for obj in [OBJ,ATT]:
  n.pack('<I',obj+0x54,CHAR);n.pack('<I',obj+0x50,MODEL);n.pack('<I',obj+0xca4,PAD);n.pack('<I',obj+0x1fc,0x1001);n.pack('<b',obj+0x280,-1);n.pack('<h',obj+0x1064,-99);n.pack('<B',obj+0x107e,4);n.pack('<B',obj+0x107f,4);n.pack('<B',obj+0xe39,4)
 n.pack('<I',CHAR+0x24,GAME);n.pack('<I',MODEL+0xc,ANIMS);n.pack('<I',PAD,PHYS)
def snapshot():return {'hp':n.read(OBJ+0x107f,1)[0],'timer':n.unpack('<f',OBJ+0x1018)[0],'flags':n.unpack('<I',OBJ+0xeec)[0],'lastAttacker':n.unpack('<I',OBJ+0x10a8)[0],'context':n.read(OBJ+0x7b5,1)[0],'rng':n.unpack('<I',0x80253c)[0]}
def check(r,want,got,meta):
 r['cases']+=1
 if want!=got:
  r['mismatches']+=1
  if len(r['examples'])<15:r['examples'].append({'input':meta,'expected':want,'actual':got})
def contract(name):
 r={'cases':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r
