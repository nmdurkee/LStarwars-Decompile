"""Original actor base/path reset and signed type predicate, child services explicit."""
from pathlib import Path
import importlib.util,json,struct,gzip,base64,itertools,random
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);n=m.NativeX86()
from unicorn import UC_HOOK_CODE
D=n.DATA;SIZE=0x40000;ACT=D+0x1000;META=D+0x4000;DATA=D+0x5000;SUIT=D+0x6000;WORLD=D+0x8000;TABLE=D+0x18000;CB=n.STOP+0x700;cfg={};events=[];counts={};services={0x407b60:1,0x481740:1,0x4cbe50:1,0x52f800:5,CB:1}
def u(p):return n.unpack('<I',p)[0]
def hook(mu,a,size,user):
 if a in[0x41b0a0,0x414ad0,0x55e470,0x6e6950,0x6e69d0]:counts[hex(a)]=counts.get(hex(a),0)+1
 if a not in services:return
 sp=mu.reg_read(m.UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*services[a],sp+4));events.append(dict(address=hex(a),args=args,actorImage=n.read(ACT,0x10d8).hex()))
 if cfg.get('mutate'):
  if a in[0x407b60,0x481740,0x4cbe50]:n.pack('<H',ACT+0x1064,7);n.pack('<I',ACT+0x54,META+0x100);n.pack('<I',ACT+0x1f8,u(ACT+0x1f8)^0x400)
  elif a==CB:n.pack('<I',ACT+0x54,META+0x200);n.pack('<2I',0x802528,0xabcddcba,0x11223344);n.pack('<I',0x855f74,0xbf800000)
  elif a==0x52f800:n.pack('<I',ACT+0x420,0xdeadbeef);n.pack('<I',ACT+0x5c,0x12345678)
 mu.reg_write(m.UC_X86_REG_EAX,cfg.get('maskReturn',0)if a==CB else 0);mu.reg_write(m.UC_X86_REG_ESP,sp+4);mu.reg_write(m.UC_X86_REG_EIP,u(sp))
n.mu.hook_add(UC_HOOK_CODE,hook)
def setup29(c):
 global cfg
 cfg=c;seed=c.get('seed',123);r=random.Random(seed);n.write(D,bytes(r.randrange(256)for _ in range(SIZE))if c.get('random')else bytes([0xa5])*SIZE);n.pack('<I',ACT+0x54,META);n.pack('<h',ACT+0x1064,c.get('type',1));n.pack('<I',ACT+0x1f8,c.get('actorFlags',0));n.pack('<I',ACT+0xcbc,SUIT if c.get('suit')else 0);n.pack('<I',SUIT+4,0x87654321);n.pack('<B',ACT+0x280,c.get('player',255));n.pack('<I',ACT+0xcd0,c.get('companion',0));n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x2ae8,0xabcdef00);n.pack('<I',0x93b274,TABLE);n.pack('<I',0x876580,c.get('alternate',0));n.pack('<I',0x7f39e4,c.get('special',0));n.pack('<I',0x93b2a4,c.get('defaultMask',0));n.pack('<I',0x923888,CB if c.get('callback',True)else 0);n.pack('<2I',0x802528,0x76543210,0xfedcba98);n.pack('<I',0x855f74,c.get('duration',0x3f800000))
 for j in range(-128,340):n.pack('<I',TABLE+j*0x4c+4,c.get('typeFlags',0x40088))
 for j in range(3):n.pack('<I',META+j*0x100+4,c.get('metadataFlags',0x8004080)^(j<<14));n.pack('<I',META+j*0x100+0xc,0x13572468+j);n.pack('<I',META+j*0x100+0x24,DATA+j*0x100);n.pack('<I',DATA+j*0x100+0x90,c.get('dataFlags',0x2000)^j*0x2000)
 if 'metaOffset'in c:
  chosen=ACT+c['metaOffset'];n.pack('<I',ACT+0x54,chosen);n.pack('<I',chosen+4,c.get('metadataFlags',0x8004080));n.pack('<I',chosen+0x24,DATA)
 events.clear()
def oracle29(kind,c,img):
 ev=[];g=dict(low=0x76543210,high=0xfedcba98,duration=c.get('duration',0x3f800000))
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 def b(p):return img[p-D]
 def byte(p,v):img[p-D]=v&255
 def pw(p,v):struct.pack_into('<H',img,p-D,v&65535)
 def port(a,args):
  ev.append(dict(address=hex(a),args=args,actorImage=bytes(img[ACT-D:ACT-D+0x10d8]).hex()))
  if c.get('mutate'):
   if a in[0x407b60,0x481740,0x4cbe50]:pw(ACT+0x1064,7);put(ACT+0x54,META+0x100);put(ACT+0x1f8,u(ACT+0x1f8)^0x400)
   elif a==CB:put(ACT+0x54,META+0x200);g.update(low=0xabcddcba,high=0x11223344,duration=0xbf800000)
   elif a==0x52f800:put(ACT+0x420,0xdeadbeef);put(ACT+0x5c,0x12345678)
  return c.get('maskReturn',0)if a==CB else 0
 def predicate(t):
  fl=u(TABLE+t*0x4c+4);return 0 if fl&0x1000010==0x1000010 else int(bool(fl&0x40088))
 def path():
  put(ACT+0xef0,u(ACT+0xef0)&0xffdfffff);put(ACT+0x1090,0);put(ACT+0x4b0,u(ACT+0x4b0)&0xfffffd9f)
  for at in[0x458,0x45c,0x44c]:put(ACT+at,0)
  byte(ACT+0x1086,0);byte(ACT+0x1087,0);put(ACT+0x108c,0);byte(ACT+0x1088,0);pw(ACT+0x3ee,65535);pw(ACT+0x3f0,65535)
  for at in[0xefc,0xf00,0xf04,0x4c0,0xf08,0x420,0x424,0x428,0x42c,0x430,0x434]:put(ACT+at,0)
  byte(ACT+0x405,0);pw(ACT+0x3ec,65535);byte(ACT+0x404,255);port(0x52f800,[u(WORLD+0x2ae8),ACT,ACT+0x2c8,255,1])
 if kind=='predicate':return predicate(c.get('type',1)),ev,g
 if kind=='path':path();return None,ev,g
 port(0x481740 if c.get('alternate')else 0x4cbe50 if c.get('special')else 0x407b60,[ACT]);t=struct.unpack_from('<h',img,ACT-D+0x1064)[0];v=predicate(t);put(ACT+0x4b0,u(ACT+0x4b0)&0xfffeffff);ef=u(ACT+0xef0);put(ACT+0xef0,ef^(((v<<23)^ef)&0x800000));put(ACT+0x3f8,0);put(ACT+0x3fc,0)
 if c.get('defaultMask')and not u(ACT+0x1f8)&0x400:put(ACT+0x3f8,g['low']);put(ACT+0x3fc,g['high'])
 elif c.get('callback',True):
  suit=u(ACT+0xcbc);index=port(CB,[u(suit+4)if suit else u(u(ACT+0x54)+0xc)])&255
  if index!=255:
   if index>=64:put(ACT+0x3f8,g['low']);put(ACT+0x3fc,g['high'])
   else:put(ACT+0x3f8,1<<index);put(ACT+0x3fc,(1<<index)>>32)
 put(ACT+0xeec,u(ACT+0xeec)|2);ec=u(ACT+0xeec);put(ACT+0xed4,0x4e6e6b28);put(ACT+0xed8,0x4e6e6b28);meta=u(ACT+0x54);byte(ACT+0x378,0);ec=ec|4 if b(meta+4)&0x80 else ec&0xfffffffb;put(ACT+0xef0,u(ACT+0xef0)&0xc7ffe6c0);put(ACT+0x1028,0x4e6e6b28);put(ACT+0xef4,u(ACT+0xef4)&0x31f7e95c);put(ACT+0x102c,0x4e6e6b28);put(ACT+0xef8,u(ACT+0xef8)&0xfffffffc);saved=u(ACT+0xef0);cc=(ec&0x25fffc27)|8;created=bool(u(ACT+0x1f8)&0x400);put(ACT+0xeec,ec);ff=u(ACT+0xef4);put(ACT+0xf14,0);put(ACT+0xeec,cc);put(ACT+0xef4,ff&0xfffbffff if created else ff|0x40000);put(ACT+0x104c,0);put(ACT+0x4b0,u(ACT+0x4b0)&0xefffffff);dur=g['duration']
 put(ACT+0x4b8,dur);f=struct.unpack('<f',struct.pack('<I',dur))[0];fl=u(ACT+0x4b0);fl=(fl&0xf7ffffff)|0x4000000 if f>0 else fl&0xf3ffffff;put(ACT+0xef4,u(ACT+0xef4)&0xfe5fffff);cc&=0xfff3ffff;put(ACT+0xec8,0x3f800000);put(ACT+0x4b0,fl);put(ACT+0xeec,cc);cc=cc|0x100000 if u(meta+4)&0x8000000 else cc&0xffefffff;byte(ACT+0x7c5,b(ACT+0x7c5)&253);put(ACT+0xec4,0);put(ACT+0x4b0,u(ACT+0x4b0)&0xffffafff);put(ACT+0x3a8,0x4e6e6b28);put(ACT+0x3b8,0x4e6e6b28);put(ACT+0x454,0);put(ACT+0xeec,cc);put(ACT+0xeec,u(ACT+0xeec)&0xfadff7fe);put(ACT+0xecc,0);put(ACT+0xef0,saved&0xfeffffff)
 for at in[0xec0,0x39c,0x3a4,0x3ac,0x3b4,0x2a8,0x2ac,0xeb0,0xeb4,0x10a4,0x10a8,0xeb8,0xebc]:put(ACT+at,0)
 img[ACT-D+0xf3c:ACT-D+0xfa4]=bytes(0x68);meta=u(ACT+0x54);byte(ACT+0x107d,0)
 for at in[0xfd8,0x3bc,0x298,0x2a0,0x2a4]:put(ACT+at,0)
 special=bool(u(meta+4)&0x4000)and(b(ACT+0x280)==255 or u(ACT+0xcd0)!=0);put(ACT+0x1fc,u(ACT+0x1fc)|2 if special else u(ACT+0x1fc)&0xfffffffd);data=u(meta+0x24);put(ACT+0xef0,u(ACT+0xef0)|0x80000000 if u(data+0x90)&0x2000 else u(ACT+0xef0)&0x7fffffff);put(ACT+0x1fc,u(ACT+0x1fc)&0xffe7f7ff);put(ACT+0xef4,u(ACT+0xef4)&0xfffffffb);put(ACT+0x1034,0x3f800000);put(ACT+0xef0,u(ACT+0xef0)&0xfbbfffff);put(ACT+0xef8,u(ACT+0xef8)&0xfffffff3);put(ACT+0x1038,0);put(ACT+0x10b4,0);byte(ACT+0x1083,0);put(ACT+0x10cc,0);path();return None,ev,g
vectors=[];errors=[]
def run29(kind,c):
 setup29(c);before=bytearray(n.read(D,SIZE));expected=bytearray(before);ret,ev,g=oracle29(kind,c,expected);result=n.call({'reset':0x41b0a0,'path':0x414ad0,'predicate':0x55e470}[kind],[c.get('type',1)]if kind=='predicate'else[ACT],count=100000);after=n.read(D,SIZE);actualg=dict(low=u(0x802528),high=u(0x80252c),duration=u(0x855f74));ok=[after==expected,events==ev,actualg==g,ret is None or result==ret]
 if not all(ok):errors.append(dict(kind=kind,input=c,checks=ok,result=[result,ret],diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12],events=[events.copy(),ev]if not ok[1]else None))
 vectors.append(dict(kind=kind,input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result,events=events.copy(),globals=actualg))
for k in['reset','path','predicate']:run29(k,{})
for idx,alt,special,created,suit in itertools.product(range(256),[0,1],[0,1],[0,0x400],[False,True]):run29('reset',dict(maskReturn=idx,alternate=alt,special=special,actorFlags=created,suit=suit,mutate=idx%2==0,defaultMask=idx%3==0))
for dur in[0,0x80000000,1,0x80000001,0x3f800000,0xbf800000,0x7f7fffff,0xff7fffff,0x7f800000,0xff800000,0x7fc12345,0xffc12345]:run29('reset',dict(duration=dur,callback=False))
for typ,flags in itertools.product([-128,-1,0,1,7,339],[0,8,0x80,0x40000,0x1000010,0x1040098,0xffffffff]):run29('predicate',dict(type=typ,typeFlags=flags))
for player,comp,metadata,data in itertools.product([0,1,127,128,254,255],[0,1,0xffffffff],[0,0x80,0x4000,0x8000000,0x8004080],[0,0x2000,0xffffffff]):run29('reset',dict(player=player,companion=comp,metadataFlags=metadata,dataFlags=data,callback=False))
for offset,flags in itertools.product([0x1f4,0x4ac,0xee8],[0,0x80,0x4000,0x8000000,0x8004080,0xffffffff]):run29('reset',dict(metaOffset=offset,metadataFlags=flags,callback=False))
for seed in range(8):run29('reset',dict(random=True,seed=seed,maskReturn=seed*33,mutate=seed%2==0))
report=dict(status='unsealed actor base reset comparisons',cases=len(vectors),assertionGroups=sum(4 if v['kind']=='predicate'else 3 for v in vectors),mismatches=len(errors),errors=errors[:10],nativeEntryCounts=counts)
(m.BASE/'reports/movement-phase29-20261013-draft-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=[{k:v for k,v in e.items()if k!='events'}for e in errors[:2]])))

if errors:raise SystemExit('Mismatches; no sealed fixture written')
report.update(status='sealed bounded original x86 comparisons; managed replay unexecuted',binarySha256=n.sha256,explicitServices=[hex(a)for a in services],limits=['Complete base/path reset own bodies and signed type predicate; three mode reset bodies, mask callback and52f800 remain explicit.','Readable bounded actor/type/metadata/data/suit/world backing and finite/quiet-NaN/infinite duration copies; no general signaling-NaN hardware quieting or FPU flags claim.','Original x86 versus Python model; portable source/harness compilation is separate and managed execution remains unexecuted.'])
(m.BASE/'reports/movement-phase29-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase29-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
for a,b in[(0x41b0a0,0x41b414),(0x55e470,0x55e4a0),(0x414ad0,0x414ba8)]:functions.append(dict(address=hex(a),size=b-a,instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)]))
(m.BASE/'reports/movement-phase29-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2)+'\n')
# Two original emulator observations are outside paired hardware/source claim.
observations=[]
for bits in[0x7f812345,0xff812345]:
 setup29(dict(duration=bits,callback=False));n.call(0x41b0a0,[ACT]);observations.append(dict(inputBits=hex(bits),retainedCopyBits=hex(u(ACT+0x4b8)),note='Unicorn retained signaling payload; source domain excludes signaling NaN hardware conversion/FPU behavior. Not added to paired count.'))
(m.BASE/'reports/movement-phase29-20261013-excluded-observations.json').write_text(json.dumps(dict(observations=observations,pairedCountCredit=0),indent=2)+'\n')
