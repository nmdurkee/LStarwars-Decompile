"""Unsealed initializer body probe; services explicitly adapted, not yet a source comparison."""
import importlib.util,struct,json
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from unicorn import UC_HOOK_CODE
n=m.NativeX86();D=n.DATA;SIZE=0x80000;ACT=D+0x1000;WORLD=D+0x8000;GAME=D+0xb000;REG=D+0xc000;MAP=D+0xd000;RECORDS=D+0x10000;MODELS=D+0x20000;DATA=D+0x30000;CLIPS=D+0x40000;SCENE=D+0x50000;POSITIONS=D+0x51000;SOURCE_TABLE=D+0x52000;PAD=0x9253b0;PADSIZE=0x1800;CB=n.STOP+0x600;events=[];counts={}
SERVICES={0x4148a0:2,0x4cca00:1,0x62e650:2,0x415050:1,0x4150d0:3,0x595840:3,0x55d2b0:1,0x41a9c0:0,0x41ab00:0,0x41ab90:0,0x41ac40:0,CB:1}
CPUS=[0x41c7c0,0x55e300,0x54a5a0,0x414ca0,0x55ccd0,0x55cd20,0x55cc40,0x414ce0,0x54fa60]
def hook(mu,a,size,user):
 if a in CPUS:counts[hex(a)]=counts.get(hex(a),0)+1
 if a not in SERVICES:return
 sp=mu.reg_read(m.UC_X86_REG_ESP);actor=mu.reg_read(m.UC_X86_REG_ESI);args=list(n.unpack('<'+'I'*SERVICES[a],sp+4))if SERVICES[a]else[];events.append(dict(address=hex(a),actor=actor,args=args,flags=n.unpack('<I',ACT+0x1f8)[0],radius=n.unpack('<2I',ACT+0x1dc),packet=n.unpack('<I',ACT+0xca4)[0]));c=globals().get('cfg27',{});result=c.get('moves',1) if a==0x415050 else c.get('suit',0) if a==0x4cca00 else 0
 if c.get('mutate'):
  if a==0x4148a0:n.pack('<I',ACT+0x54,RECORDS+2*0x4c);n.pack('<B',ACT+0x1079,1);n.pack('<f',ACT+0xd30,1);n.pack('<B',ACT+0x28c,1)
  elif a==CB:n.pack('<I',ACT+0x50,MODELS+0x54)
  elif a==0x4150d0:n.pack('<2f',ACT+0x1dc,7.125,8.125)
  elif a==0x595840:n.pack('<f',ACT+0x1dc,4.875)
  elif a==0x55d2b0:n.pack('<3f',ACT+0x5c,-1.,-2.,-3.);n.pack('<H',ACT+0x1064,c.get('lateType',9));n.pack('<I',ACT+0x54,RECORDS+3*0x4c)
  elif a in[0x41a9c0,0x41ab00,0x41ab90,0x41ac40]:n.pack('<I',n.unpack('<I',n.unpack('<I',ACT+0x54)[0]+0x24)[0]+0x90,0)
 mu.reg_write(m.UC_X86_REG_EAX,result);mu.reg_write(m.UC_X86_REG_ESP,sp+4);mu.reg_write(m.UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook)
def setup(typ=1):
 n.write(D,bytes([0xa5])*SIZE);n.write(ACT,bytes(0x10d8));n.pack('<I',ACT+0x1fc,0x1001);n.pack('<f',ACT+0xff8,1);n.pack('<B',ACT+0x28d,7);n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,GAME);n.pack('<I',WORLD+0x2ab4,SCENE);n.pack('<I',GAME+0x64,0);n.pack('<I',0x29130e4,REG);n.pack('<3I',REG+0x18,MODELS,MAP,RECORDS);n.pack('<340h',MAP,*([0]*340));n.pack('<I',0x855f80,0xdeadbeef);n.pack('<3f',0x93b0cc,7,8,9)
 for j in range(340):
  q=RECORDS+j*0x4c;n.pack('<I',q+0x24,DATA);n.pack('<5f',q+0x2c,1.25,2.5,-.75,3.5,1.5)
 n.pack('<I',DATA+0xa0,3);n.pack('<2B',DATA+0xf4,2,3);n.pack('<I',DATA+0x90,0x8000);n.pack('<B',DATA+0x10d,2);n.pack('<f',DATA+0x4c,3.125)
 for j in range(4):n.pack('<I',MODELS+j*0x54+0xc,CLIPS);n.pack('<I',MODELS+j*0x54+0x1c,1)
 n.pack('<233I',CLIPS,*([0]*3+[1]+[0]*229))
 for j in range(8):n.pack('<4f',POSITIONS+j*16,j+1.125,j+2.25,j+3.5,1);n.pack('<4I',0x93d5a0+j*16,POSITIONS+j*16,0,0,0);n.pack('<4I',SOURCE_TABLE+j*16,POSITIONS+j*16,0,0,0)
 n.write(PAD,bytes([0xa5])*PADSIZE)
 for j in range(64):n.pack('<H',PAD+j*0x60+0x5a,0xa5fe|(0 if j==0 else 1))
 for a,v in[(0x7f18d0,5),(0x7f18d4,6),(0x7f18d8,7),(0x7f19dc,8),(0x7f18dc,9)]:n.pack('<H',a,v)
 n.pack('<I',0x80253c,123);n.pack('<I',0x93d508,CB);events.clear();counts.clear()
setup();result=n.call(0x41c7c0,[ACT,1,0],count=1000000);report=dict(status='unsealed native probe only',binarySha256=n.sha256,result=result,events=events,nativeEntryCounts=counts,paddingBits=n.unpack('<I',0x7f2374)[0],actorFlags=n.unpack('<I',ACT+0x1f8)[0],position=n.unpack('<3I',ACT+0x5c),clip=n.unpack('<H',ACT+0x3e)[0]);(m.BASE/'reports/movement-phase27-20261013-probe.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
