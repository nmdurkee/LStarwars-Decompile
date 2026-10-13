"""Unsealed actor creator probe with real pool/initializer/numeric CPU chain."""
from pathlib import Path
p=Path(__file__).with_name('movement-phase27-20261013-probe.py');exec(compile(p.read_text().split('setup();result=')[0],str(p),'exec'))
import json,struct
# Keep immutable initializer probe unchanged; this probe owns a fresh machine/hook.
n=m.NativeX86();SIZE=0xc0000;POOL=D+0x50000;ACT=POOL;POSITIONS=D+0x47000;SOURCE_TABLE=D+0x48000;POS=D+0x49000;DESC=D+0x4a000;FORMATION=D+0xa0000;PATH=D+0xb0000;SIN=0x29899a0
extra={0x41b0a0:1,0x41af70:1,0x54a7f0:1,0x5728a0:1,0x572660:2,0x55d6a0:5,0x52f800:5,0x514640:9,0x498a40:1,0x4b6b80:1,0x518040:2,0x51a7c0:2,0x51b890:4,0x541bc0:5,0x53f380:1,0x553570:4,0x550a20:6}
SERVICES.update(extra);CPUS.extend([0x43d890,0x475850,0x41f8f0,0x55c9f0,0x62a870,0x55c980,0x5b35a0,0x5b3620,0x5b37d0,0x5b3710]);n.mu.hook_add(UC_HOOK_CODE,hook);setup();n.write(SIN,(m.BASE/'references/native-animation-sine-table.f32').read_bytes());n.pack('<I',WORLD+0x298c,DESC);n.pack('<2I',DESC,0x10d8,POOL);n.pack('<I',0x93d504,POOL);n.pack('<I',0x93d500,0xdeadbeef)
for j in range(64):n.pack('<I',POOL+j*0x10d8+0x1fc,0)
n.pack('<I',0x87b504,0);n.pack('<I',0x93b324,0);n.pack('<I',WORLD+0x2988,0);n.pack('<I',WORLD+0x13c,SCENE);n.pack('<I',WORLD+0x2ae8,REG);n.pack('<I',0x8765c4,0);n.pack('<17B',0x876847,*([0]*17));n.pack('<3f',POS,11.125,-2.25,7.5);n.pack('<4f',DATA+0x64,1.125,2.25,3.5,4.75);n.pack('<I',0x93d508,CB);events.clear();counts.clear();result=n.call(0x43d890,[1,POS,0,0,0,0,1,0,0,0,1],count=2000000)
report=dict(status='unsealed native probe; source comparison pending',binarySha256=n.sha256,result=result,expectedFirstSlot=POOL,events=events,nativeEntryCounts=counts,highest=n.unpack('<I',0x93d500)[0],actorPosition=n.unpack('<3I',result+0x5c),actorGroup=n.unpack('<B',result+0x378)[0],groupCount=n.unpack('<B',0x876848)[0]);(m.BASE/'reports/movement-phase28-20261013-probe.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
