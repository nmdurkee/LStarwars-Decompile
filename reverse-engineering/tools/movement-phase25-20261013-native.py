"""Character initializer primitives: original bodies and finite exact numeric stores."""
from pathlib import Path
p=Path(__file__).with_name('movement-phase24-20261013-native.py');exec(compile(p.read_text().split('for k,free in itertools.product')[0],str(p),'exec'))
from fractions import Fraction
p4=Path(__file__).with_name('movement-phase4-20261013-native.py').read_text();exec(p4[p4.index('def quant('):p4.index('def readstr(')])
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
val=lambda v:struct.unpack('<f',struct.pack('<I',v))[0]
SIZE=0x10000;ACT=D+0x1000;TYPE=D+0x3000;DATA=D+0x4000;TABLE=0x93d5a0;PAD=0x9253b0;PADSIZE=0x1800;vectors=[];errors=[];groups={};r=random.Random(20261027)
def setup25(c):
 n.write(D,bytes([0xa5])*SIZE);ty=c.get('typePointer',TYPE);n.pack('<I',ACT+0x54,ty);n.pack('<4f',ty+0x2c,*c.get('tuning',[1.125,2.25,-3.5,4.75]));n.pack('<f',ty+0x3c,c.get('scale',1.5));n.pack('<f',ACT+0xa8,c.get('actorScale',1.75));n.pack('<f',ACT+0xffc,c.get('actorRadius',2.125));n.pack('<f',ACT+0x1004,c.get('factor',.875));n.pack('<f',ACT+0xff8,c.get('heightScale',.625));n.pack('<I',ty+0x24,DATA);n.pack('<I',DATA+0x90,c.get('dataFlags',0xffffffff));n.pack('<I',ACT+0x1f8,c.get('flags',0xa5a5a5a5));n.pack('<B',ACT+0x280,c.get('player',255));n.pack('<B',ACT+0x28d,c.get('fallback',3));
 for j in range(8):n.pack('<4I',TABLE+j*16,c.get('pointers',[0x12340000+j*0x400 for j in range(8)])[j],0xa5a5a5a5,0xdeadbeef,0xffffffff)
 return bytearray(n.read(D,SIZE))
def model25(k,c,img):
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def fl(p):return struct.unpack_from('<f',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 def pf(p,v):struct.pack_into('<f',img,p-D,v)
 if k=='start':
  player=img[ACT-D+0x280];player=player if player<128 else player-256;idx=player if 0<=player<=7 else img[ACT-D+0x28d];idx&=7;pointers=c.get('pointers',[0x12340000+j*0x400 for j in range(8)]);return pointers[idx]or pointers[0]
 if k=='flag':
  data=u(u(ACT+0x54)+0x24);put(ACT+0x1f8,u(ACT+0x1f8)|0x20000 if u(data+0x90)&0x8000 else u(ACT+0x1f8)&0xfffdffff);return 0
 ty=u(ACT+0x54)
 if k=='install':
  for dest,src in[(0xa8,0x3c),(0xffc,0x30),(0xff0,0x34),(0xff4,0x38)]:put(ACT+dest,u(ty+src))
 pf(ACT+0xa4,(X.fl(fl(ty+0x2c))*X.fl(fl(ACT+0xa8))).flstore());rad=(X.fl(fl(ACT+0xffc))*X.fl(fl(ACT+0xa8))).flstore();pf(ACT+0xac,rad);pf(ACT+0xb0,(X.fl(rad)*X.fl(fl(ACT+0x1004))).flstore());pf(ACT+0xb4,((X.fl(fl(ty+0x38))-X.fl(fl(ty+0x34)))*X.fl(fl(ACT+0xff8))).flstore());return 0

def run25(k,c,group):
 before=setup25(c);expected=bytearray(before);ret=model25(k,c,expected);addr={'start':0x55e300,'flag':0x414ce0,'dimensions':0x55ccd0,'install':0x414ca0}[k];result=n.call(addr,[]if k=='flag'else[ACT],regs={m.UC_X86_REG_EAX:ACT}if k=='flag'else{});after=n.read(D,SIZE);groups[group]=groups.get(group,0)+1
 if after!=expected or(k=='start'and result!=ret):errors.append(dict(kind=k,input=c,result=[result,ret],diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12]))
 vectors.append(dict(kind=k,input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result))
for player,fb,pointers in itertools.product(range(256),[0,7,8,31,255],[[0x12340000+j*0x400 for j in range(8)],[0]*8,[0x12345678]+[0]*7]):run25('start',dict(player=player,fallback=fb,pointers=pointers),'signed-player-and-fallback-modulo-eight')
for flag,typ in itertools.product([0,0xffffffff,0x8000,0x7fff,0x80000000],[TYPE,ACT+0x180]):run25('flag',dict(dataFlags=flag,typePointer=typ),'raw-type-flag-dereference')
for k,j in itertools.product(['dimensions','install'],range(512)):
 c=dict(tuning=[f32(r.uniform(-1e4,1e4))for j in range(4)],scale=f32(r.uniform(-10,10)),actorScale=f32(r.uniform(-10,10)),actorRadius=f32(r.uniform(-1e4,1e4)),factor=f32(r.uniform(-10,10)),heightScale=f32(r.uniform(-10,10)));run25(k,c,'finite-dimension-x87-stores')
for k,ty in itertools.product(['dimensions','install'],[ACT+0x70,ACT+0x74,ACT+0x78,ACT+0xfc8,ACT+0xfcc,ACT+0xfd0]):run25(k,dict(typePointer=ty),'cached-type-live-field-aliases')
for k,neg in itertools.product(['dimensions','install'],[False,True]):run25(k,dict(tuning=[-0. if neg else 0.]*4,scale=-1.,actorScale=-1.,actorRadius=-0.,factor=-1.,heightScale=-1.),'signed-zero-products')
for free,upper in itertools.product(range(65),[0,0xff00,0xa5fe]):
 n.write(PAD,bytes([0xa5])*PADSIZE)
 for j in range(64):n.pack('<H',PAD+j*0x60+0x5a,upper|(0 if j==free else 1))
 before=bytearray(n.read(PAD,PADSIZE));expected=bytearray(before);ret=0
 for j in range(64):
  if not expected[j*0x60+0x5a]&1:expected[j*0x60+0x5a]|=1;ret=PAD+j*0x60;break
 result=n.call(0x54a5a0);after=n.read(PAD,PADSIZE);groups['animation-pool-all-slots-preserve-flagword']=groups.get('animation-pool-all-slots-preserve-flagword',0)+1
 if result!=ret or after!=expected:errors.append(dict(kind='pad',input=dict(free=free,upper=upper),result=[result,ret],image=after==expected))
 vectors.append(dict(kind='pad',input=dict(free=free,upper=upper),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result))
n.write(PAD,bytes([0xa5])*PADSIZE)
for j in range(64):n.pack('<H',PAD+j*0x60+0x5a,0xfffe)
for j in range(65):
 before=bytearray(n.read(PAD,PADSIZE));expected=bytearray(before);ret=0
 for k in range(64):
  if not expected[k*0x60+0x5a]&1:expected[k*0x60+0x5a]|=1;ret=PAD+k*0x60;break
 result=n.call(0x54a5a0);after=n.read(PAD,PADSIZE)
 if result!=ret or after!=expected:errors.append(dict(kind='pad',step=j,result=[result,ret],image=after==expected))
 vectors.append(dict(kind='pad',input=dict(sequenceStep=j),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result));groups['animation-pool-repeated-reservations']=groups.get('animation-pool-repeated-reservations',0)+1
checks=sum(2 if v['kind']in['pad','start']else 1 for v in vectors);report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=checks,groups=groups,mismatches=len(errors),errors=errors[:20],nativeAdapters=0,limits=['Valid raw pointer backing; finite consumed tuning/scale/dimension values and outputs.','Animation allocation only sets active bit of preserved flag word; source start pointer hydration reuses existing 55e300 mapping without new distinct entry credit.','Full character initializer and actor creator remain open.'])
(m.BASE/'reports/movement-phase25-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase25-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);fun=[]
for a,b in[(0x54a5a0,0x54a5d1),(0x55ccd0,0x55cd1f),(0x414ca0,0x414cd4),(0x414ce0,0x414d08)]:fun.append(dict(address=hex(a),instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)]))
(m.BASE/'reports/movement-phase25-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=fun),indent=2)+'\n')
print(json.dumps(dict(cases=len(vectors),checks=checks,mismatches=len(errors),errors=errors[:3])))
