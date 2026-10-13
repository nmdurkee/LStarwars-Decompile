"""Original prepared character initializer with declared child services and recovered CPU helper composition."""
from pathlib import Path
p=Path(__file__).with_name('movement-phase27-20261013-probe.py');exec(compile(p.read_text().split('setup();result=')[0],str(p),'exec'))
import gzip,base64,itertools,random
q25={'__file__':__file__};p25=Path(__file__).with_name('movement-phase25-20261013-native.py');exec(compile(p25.read_text().split('for player,fb,pointers in itertools.product')[0],str(p25),'exec'),q25)
q26={'__file__':__file__};p26=Path(__file__).with_name('movement-phase26-20261013-native.py');exec(compile(p26.read_text().split('for j in range(512):')[0],str(p26),'exec'),q26)
# The probe machine keeps original CPU helpers and only declared child ports.
# Next: replace probe event adapter with mutation-capable service model, then compare
# complete retained DATA/PAD images, global emitter/RNG, result and ordered traces.

import struct
vectors=[];errors=[]
def oracle(typ,mode,img,pad):
 ev=[];rng=globals().get('cfg27',{}).get('seed',123)
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def word(p):return struct.unpack_from('<H',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 def pw(p,v):struct.pack_into('<H',img,p-D,v&65535)
 def port(addr,args):
  ev.append(dict(address=hex(addr),actor=ACT,args=args,flags=u(ACT+0x1f8),radius=(u(ACT+0x1dc),u(ACT+0x1e0)),packet=u(ACT+0xca4)))
  c=globals().get('cfg27',{})
  if c.get('mutate'):
   if addr==0x4148a0:put(ACT+0x54,RECORDS+2*0x4c);img[ACT-D+0x1079]=1;put(ACT+0xd30,0x3f800000);img[ACT-D+0x28c]=1
   elif addr==CB:put(ACT+0x50,MODELS+0x54)
   elif addr==0x4150d0:struct.pack_into('<2f',img,ACT-D+0x1dc,7.125,8.125)
   elif addr==0x595840:struct.pack_into('<f',img,ACT-D+0x1dc,4.875)
   elif addr==0x55d2b0:struct.pack_into('<3f',img,ACT-D+0x5c,-1.,-2.,-3.);pw(ACT+0x1064,c.get('lateType',9));put(ACT+0x54,RECORDS+3*0x4c)
   elif addr in[0x41a9c0,0x41ab00,0x41ab90,0x41ac40]:put(u(u(ACT+0x54)+0x24)+0x90,0)
  return c.get('moves',1) if addr==0x415050 else c.get('suit',0) if addr==0x4cca00 else 0
 if typ<0 or typ>=340:return 0,rng,ev
 if word(MAP+typ*2)==65535:return 0,rng,ev
 rec=RECORDS+typ*0x4c;put(ACT+0x54,rec);put(ACT+0x1048,u(u(rec+0x24)+0xa0));put(ACT+0x1f8,0);pw(ACT+0x1070,65535);img[ACT-D+0x6c4:ACT-D+0xe4c]=bytes(0x788);img[ACT-D+0x280]=255;idx=img[ACT-D+0x28d]&7;pos=u(SOURCE_TABLE+idx*16)or u(SOURCE_TABLE);xyz=[u(pos+k*4)for k in range(3)];put(ACT+0x1f8,u(ACT+0x1f8)|2|(0x4000 if mode else 0))
 if not(u(GAME+0x64)&0x40000):put(ACT+0x1f8,u(ACT+0x1f8)|0x40)
 packet=0
 for j in range(64):
  if not pad[j*0x60+0x5a]&1:pad[j*0x60+0x5a]|=1;packet=PAD+j*0x60;break
 put(ACT+0xca4,packet);pad[packet-PAD+0x25]=1;data=u(u(ACT+0x54)+0x24);state=img[data-D+0xf4];img[ACT-D+0x107e]=state;img[ACT-D+0x107f]=state;port(0x4148a0,[ACT+0x6c4,u(ACT+0x54)])
 for k,v in enumerate([7.,8.,9.]):struct.pack_into('<f',img,ACT-D+0x200+k*4,v)
 data=u(u(ACT+0x54)+0x24);img[ACT-D+0xe38]=img[data-D+0xf5];img[ACT-D+0xe39]=4;pw(ACT+0x1064,typ);mi=word(MAP+typ*2);mi=mi if mi<32768 else mi-65536;put(ACT+0x50,MODELS+mi*0x54);put(ACT+0xcbc,port(0x4cca00,[typ]));img[ACT-D+0x400]=255;q25['model25']('install',{},img);put(ACT+0x100c,0x3f000000)
 for v,offsets in zip(xyz,[[0x8c,0x5c,0x98,0x80],[0x90,0x60,0x9c,0x84],[0x94,0x64,0xa0,0x88]]):
  for off in offsets:put(ACT+off,v)
 q26['oracle26']('height',{},img);q26['oracle26']('update',{'callback':False},img);port(CB,[ACT]);model=u(ACT+0x50);pw(ACT+0x3e,1)
 if model:
  clips=u(model+0xc)
  if not u(clips+4):
   for j in range(233):
    if u(clips+j*4):pw(ACT+0x3e,j);break
 port(0x62e650,[ACT+8,word(ACT+0x3e)]);moves=port(0x415050,[ACT]);port(0x4150d0,[ACT,2,moves]);port(0x595840,[ACT+0x5c,ACT+0x4d8,u(WORLD+0x2ab4)]);f=struct.unpack_from('<f',img,ACT-D+0x1dc)[0];padding=n.unpack('<f',0x7f2374)[0];x=q25['X'].fl(f)+q25['X'].fl(padding);struct.pack_into('<f',img,ACT-D+0x3e8,x.flstore());port(0x55d2b0,[ACT]);xyz=[u(ACT+0x5c+j*4)for j in range(3)]
 for off,v in[(0x1b4,xyz[0]),(0x10bc,xyz[0]),(0x1b8,xyz[1]),(0x1bc,xyz[2]),(0x10c0,xyz[1]),(0x10c4,xyz[2])]:put(ACT+off,v)
 data=u(u(ACT+0x54)+0x24);fl=u(ACT+0xef4);put(ACT+0xef4,fl^(((u(data+0x90)>>6)^fl)&0x800));actual=word(ACT+0x1064)
 if actual in[5,6,7,8]:port([0x41a9c0,0x41ab00,0x41ab90,0x41ac40][actual-5],[])
 elif actual==9:rng=(rng*0x24cd+1)&65535;fl=u(ACT+0xef0);put(ACT+0xef0,fl^(((0x200 if rng<32768 else 0)^fl)&0x200))
 q25['model25']('flag',{},img);return 1,rng,ev
for typ,mode in itertools.product([-1,0,1,5,6,7,8,9,339,340],[0,1,0xffffffff]):
 setup();before=bytearray(n.read(D,SIZE));padBefore=bytearray(n.read(PAD,PADSIZE));expected=bytearray(before);padExpected=bytearray(padBefore);ret,rng,ev=oracle(typ,mode,expected,padExpected);result=n.call(0x41c7c0,[ACT,typ,mode],count=1000000);after=n.read(D,SIZE);padAfter=n.read(PAD,PADSIZE);actualrng=n.unpack('<I',0x80253c)[0];actualemitter=n.unpack('<I',0x855f80)[0];trace=json.dumps(events)==json.dumps(ev)
 if after!=expected or padAfter!=padExpected or result!=ret or actualrng!=rng or not trace or actualemitter!=0:errors.append(dict(type=typ,mode=mode,result=[result,ret],rng=[actualrng,rng],data=after==expected,pad=padAfter==padExpected,trace=trace,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12],events=[events.copy(),ev]))
 vectors.append(dict(type=typ,mode=mode,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),padBefore=base64.b64encode(gzip.compress(padBefore)).decode(),padAfter=base64.b64encode(gzip.compress(padAfter)).decode(),result=result,rng=actualrng,emitter=actualemitter,events=events.copy()))
(m.BASE/'reports/movement-phase27-20261013-baseline-tests.json').write_text(json.dumps(dict(status='unsealed baseline only',cases=len(vectors),checks=5*len(vectors),mismatches=len(errors),errors=errors[:3]),indent=2)+'\n')
print(json.dumps(dict(cases=len(vectors),checks=5*len(vectors),mismatches=len(errors),errors=errors[:2])))

for mutate,late,moves,suit,seed in itertools.product([False,True],[1,5,6,7,8,9],[0,1,0xffffffff],[0,0xdeadbeef],[0,123,0xffffffff]):
 cfg27=dict(mutate=mutate,lateType=late,moves=moves,suit=suit,seed=seed);setup();n.pack('<I',0x80253c,seed);before=bytearray(n.read(D,SIZE));padBefore=bytearray(n.read(PAD,PADSIZE));expected=bytearray(before);padExpected=bytearray(padBefore);ret,rng,ev=oracle(1,0,expected,padExpected);result=n.call(0x41c7c0,[ACT,1,0],count=1000000);after=n.read(D,SIZE);padAfter=n.read(PAD,PADSIZE);actualrng=n.unpack('<I',0x80253c)[0];actualemitter=n.unpack('<I',0x855f80)[0];trace=json.dumps(events)==json.dumps(ev)
 if after!=expected or padAfter!=padExpected or result!=ret or actualrng!=rng or not trace or actualemitter!=0:errors.append(dict(input=cfg27,result=[result,ret],rng=[actualrng,rng],data=after==expected,pad=padAfter==padExpected,trace=trace,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12],events=[events.copy(),ev]))
 vectors.append(dict(input=dict(cfg27),type=1,mode=0,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),padBefore=base64.b64encode(gzip.compress(padBefore)).decode(),padAfter=base64.b64encode(gzip.compress(padAfter)).decode(),result=result,rng=actualrng,emitter=actualemitter,events=events.copy()))
(m.BASE/'reports/movement-phase27-20261013-tests.json').write_text(json.dumps(dict(status='unsealed expanded comparisons',cases=len(vectors),checks=5*len(vectors),mismatches=len(errors),errors=errors[:5]),indent=2)+'\n')
print(json.dumps(dict(cases=len(vectors),checks=5*len(vectors),mismatches=len(errors),errors=errors[:2])))

for slot,game,firstclip in itertools.product([0,1,7,8,31,63,255],[0,0x40000],[0,1,2,232,233]):
 cfg27={};setup();n.pack('<B',ACT+0x28d,slot);n.pack('<I',GAME+0x64,game);n.pack('<233I',CLIPS,*[1 if k==firstclip else 0 for k in range(233)]);before=bytearray(n.read(D,SIZE));padBefore=bytearray(n.read(PAD,PADSIZE));expected=bytearray(before);padExpected=bytearray(padBefore);ret,rng,ev=oracle(1,1,expected,padExpected);result=n.call(0x41c7c0,[ACT,1,1],count=1000000);after=n.read(D,SIZE);padAfter=n.read(PAD,PADSIZE);actualrng=n.unpack('<I',0x80253c)[0];actualemitter=n.unpack('<I',0x855f80)[0];trace=json.dumps(events)==json.dumps(ev);emitter=n.unpack('<I',0x855f80)[0]
 if after!=expected or padAfter!=padExpected or result!=ret or actualrng!=rng or not trace or emitter:errors.append(dict(input=dict(slot=slot,game=game,firstclip=firstclip),data=after==expected,pad=padAfter==padExpected,result=[result,ret],rng=[actualrng,rng],trace=trace,emitter=emitter))
 vectors.append(dict(input={},type=1,mode=1,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),padBefore=base64.b64encode(gzip.compress(padBefore)).decode(),padAfter=base64.b64encode(gzip.compress(padAfter)).decode(),result=result,rng=actualrng,emitter=emitter,events=events.copy()))
for v in vectors:v.setdefault('input',{});v.setdefault('emitter',0)
checks=6*len(vectors);report=dict(status='sealed bounded native comparisons; managed replay unexecuted',binarySha256=n.sha256,cases=len(vectors),assertionGroups=checks,mismatches=len(errors),errors=errors[:10],originalCpuHelpers=CPUS,explicitServices=[hex(a)for a in SERVICES],limits=['Finite prepared tuning/scale/height values, exact supplied world/table/default positions and valid full backing; child reset/clip/suit/bounds/special services explicit.','All returned actor and animation packet pointers retain original addresses in separate byte image banks.','No source or whole-game equivalence claim before bounded sealing; current comparisons are original x86 against Python oracle.'])
(m.BASE/'reports/movement-phase27-20261013-expanded-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase27-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(paddingBits=n.unpack('<I',0x7f2374)[0],vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=checks,mismatches=len(errors),errors=errors[:2])))

from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(0x41c7c0,0x41cb4f-0x41c7c0),0x41c7c0)]
(m.BASE/'reports/movement-phase27-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=[dict(address='0x41c7c0',size=0x41cb4f-0x41c7c0,instructions=ins)]),indent=2)+'\n')
