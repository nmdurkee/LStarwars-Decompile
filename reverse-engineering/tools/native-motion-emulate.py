"""Check original PC camera-relative input and generic pad edge/deadzone behavior."""
import sys, importlib.util, json, struct, random, math
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'))
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESI
n=native.NativeX86();BASE=native.BASE;rng=random.Random(0x54b3d0)
OBJECT=n.DATA;PAD=OBJECT+0x2000;WORLD=OBJECT+0x4000;SOCKSYS=OBJECT+0x8000;SOCKS=OBJECT+0x9000;CAM=OBJECT+0xa000;PAIR=OBJECT+0xb000
n.pack('<I',0x8021b4,CAM);n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x2988,SOCKSYS);n.pack('<I',SOCKSYS,SOCKS)
errors=[];samples=[];vectors=[]
for i in range(4096):
    charflag=rng.choice([0,128]);idx=rng.choice([-1,0,3]);socketflag=rng.choice([0,64]);angle=rng.randrange(65536);camyaw=rng.randrange(65536);objyaw=rng.randrange(65536);sockyaw=rng.randrange(65536)
    n.pack('<B',OBJECT+0x1fc,charflag);n.pack('<b',OBJECT+0x671,idx);n.pack('<H',OBJECT+0x696,objyaw);n.pack('<H',PAD+0x26,angle);n.pack('<I',CAM+0x1fc,camyaw)
    if idx>=0:n.pack('<B',SOCKS+idx*0x13c+0x68,socketflag);n.pack('<H',SOCKS+idx*0x13c+0x6e,sockyaw)
    want=angle+(objyaw+sockyaw if charflag==128 and idx!=-1 and socketflag==64 else camyaw)
    actual=n.call(0x54b3d0,[OBJECT,PAD])
    vectors.append({'contract':'movementAngle','input':{'player':bool(charflag),'socketIndex':idx,'socketFlag40':bool(socketflag),'stickAngle':angle,'cameraYaw':camyaw,'objectYaw':objyaw,'socketYaw':sockyaw},'native':actual})
    if actual!=want:errors.append({'kind':'angle','index':i,'actual':actual,'expected':want})
    if i<8:samples.append({'objectFlag80':bool(charflag),'socketIndex':idx,'socketFlag40':bool(socketflag),'stickAngle':angle,'cameraYaw':camyaw,'objectYaw':objyaw,'socketYaw':sockyaw,'machineResult':actual,'wrappedAngle':actual&65535})
# Exhaustive signed 8-bit stick grid at the built-in Xbox deadzone 16, default radial mode.
n.pack('<B',0x91eef6,0)
zero_count=0
for x in range(-128,128):
    for y in range(-128,128):
        n.pack('<ii',PAIR,x,y)
        n.call(0x4f4110,[16],{UC_X86_REG_EAX:PAIR,UC_X86_REG_ESI:PAIR+4})
        actual=n.unpack('<ii',PAIR);want=(0,0) if x*x+y*y<256 else (x,y)
        if actual==(0,0):zero_count+=1
        if actual!=want:errors.append({'kind':'deadzone','input':[x,y],'actual':actual,'expected':want})
# Full pad routine confirms button edge semantics and normalized axes for both stick pairs.
edgecases=[];previous=0
for held in [0,64,64,96,32,0,65535,0]:
    n.write(PAD,bytes(0x84));n.pack('<4B',PAD+8,160,100,128,128);n.pack('<I',PAD+0x10,held);n.pack('<I',PAD+0x1c,previous);n.pack('<I',PAD+0x20,1);n.pack('<I',PAD+0x34,16)
    n.call(0x4f4370,[PAD])
    pressed,released,stored=n.unpack('<III',PAD+0x14)
    want_pressed=held&~previous;want_released=previous&~held
    if (pressed,released,stored)!=(want_pressed,want_released,held):errors.append({'kind':'edges','held':held,'previous':previous,'actual':[pressed,released,stored]})
    axes=n.unpack('<iiii',PAD+0x24);norm=n.unpack('<ff',PAD+0x38)+n.unpack('<ff',PAD+0x58)
    if axes!=(32,28,0,0) or norm!=(0.25,0.21875,0.0,0.0):errors.append({'kind':'normalization','axes':axes,'normalized':norm})
    edgecases.append({'held':held,'previous':previous,'pressed':pressed,'released':released,'signedAxes':axes,'normalizedAxes':norm});previous=held
report={'binarySha256':n.sha256,'method':'Original isolated x86 function bytes and original callees under Unicorn 2.1.4, fresh CPU context per call. Synthetic bounded object/world/socket/camera fixtures; no OS APIs or running game.','functions':{'cameraRelativeInput':'0x54b3d0','radialDeadzone':'0x4f4110','genericPadProcess':'0x4f4370'},'cameraCases':4096,'cameraSamples':samples,'radialDeadzone':{'modeByte':'0x91eef6 = 0','deadzone':16,'inputGrid':'-128..127 on each axis','vectorsChecked':65536,'zeroOutputVectors':zero_count,'formula':'Zero both axes if x*x+y*y < 16*16; retain original signed integers outside. For this 8-bit input grid only.'},'buttonSequence':edgecases,'mismatches':len(errors),'mismatchExamples':errors[:30],'limits':['Camera frame update and gameplay object movement are not emulated here.','Socket-relative branch verified with synthetic valid socket entries.','Per-axis alternate deadzone mode and nonzero bias fields are not covered by this check.']}
(BASE/'reports/native-motion-emulation.json').write_text(json.dumps(report,indent=2))
print(json.dumps({k:v for k,v in report.items() if k not in ('cameraSamples','buttonSequence')},indent=2))
(BASE/'reports/native-movement-angle-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'vectors':vectors},separators=(',',':'))+'\n')
if errors:sys.exit(1)
