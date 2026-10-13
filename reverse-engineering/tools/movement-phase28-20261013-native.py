"""Actor creator own-body comparison, with real pool/initializer CPU chain."""
from pathlib import Path
p=Path(__file__).with_name('movement-phase27-20261013-native.py');q={"__file__":str(p)};exec(compile(p.read_text().split('for typ,mode in itertools.product')[0],str(p),'exec'),q)
globals().update({k:v for k,v in q.items() if k not in ['__name__','__file__']})
import math
n=m.NativeX86();SIZE=0xc0000;POOL=D+0x50000;ACT=POOL;POSITIONS=D+0x47000;SOURCE_TABLE=D+0x48000;POS=D+0x49000;DESC=D+0x4a000;FORMATION=D+0xa0000;PATH=D+0xb0000;SCR=D+0xf0000;SIN=0x29899a0
extra={0x41b0a0:1,0x41af70:1,0x54a7f0:1,0x5728a0:1,0x572660:2,0x55d6a0:5,0x52f800:5,0x514640:9,0x498a40:1,0x4b6b80:1,0x518040:2,0x51a7c0:2,0x51b890:4,0x541bc0:5,0x53f380:1,0x553570:4,0x550a20:6}
SERVICES.update(extra);CPUS.extend([0x43d890,0x475850,0x41f8f0,0x55c9f0,0x62a870,0x55c980,0x5b35a0,0x5b3620,0x5b37d0,0x5b3710]);sine=struct.unpack('<32768f',(m.BASE/'references/native-animation-sine-table.f32').read_bytes());cfg28={};cfg27={}
for mod in[q,q25,q26]:
 for key in['D','ACT','WORLD','GAME','REG','MAP','RECORDS','MODELS','DATA','CLIPS','SCENE','POSITIONS','SOURCE_TABLE','PAD','PADSIZE','CB','n']:mod[key]=globals()[key]

def mutate28(addr,args,read,put,byte,pw):
 if addr==0x518040:
  put(ACT+0x40c,args[0]);byte(ACT+0x410,cfg28.get('member',3));byte(ACT+0x411,cfg28.get('column',0));byte(ACT+0x412,cfg28.get('row',1))
 if addr==0x553570:put(ACT+0xe64,args[1]);put(ACT+0xe80,args[3]);byte(ACT+0xe6a,cfg28.get('splineIndex',255))
 if addr==0x550a20:
  for j,v in enumerate([1.25,-2.5,3.75]):put(args[2]+j*4,struct.unpack('<I',struct.pack('<f',v))[0])
  put(args[3],cfg28.get('sampleHeading',0x1234));pw(args[4],cfg28.get('samplePitch',0x2345));pw(args[4]+2,0x3456)
 if cfg28.get('mutate'):
  if addr==0x41b0a0:put(POS,0xc0400000);put(ACT+0x54,RECORDS+3*0x4c)
  if addr==0x41af70:put(ACT+0x5c,0x40b00000)
  if addr==0x514640:
   for j in range(6):put(ACT+0x420+j*4,0x11110000+j)
  if addr==0x498a40:put(ACT+0x5c,0xc0f00000)
 if addr==0x51b890 and cfg28.get('boundPath'):put(ACT+0x424,1)

def hook28(mu,a,size,user):
 if a in CPUS:counts[hex(a)]=counts.get(hex(a),0)+1
 if a not in SERVICES:return
 sp=mu.reg_read(m.UC_X86_REG_ESP);implicit=mu.reg_read(m.UC_X86_REG_ESI);args=list(n.unpack('<'+'I'*SERVICES[a],sp+4))if SERVICES[a]else[];norm=args.copy()
 if a==0x550a20:norm[2:5]=[SCR,SCR+0x10,SCR+0x14]
 events.append(dict(address=hex(a),actor=implicit,args=norm,flags=n.unpack('<I',ACT+0x1f8)[0],radius=n.unpack('<2I',ACT+0x1dc),packet=n.unpack('<I',ACT+0xca4)[0]))
 mutate28(a,args,lambda p:n.unpack('<I',p)[0],lambda p,v:n.pack('<I',p,v&0xffffffff),lambda p,v:n.pack('<B',p,v&255),lambda p,v:n.pack('<H',p,v&65535))
 mu.reg_write(m.UC_X86_REG_EAX,1 if a==0x415050 else 0);mu.reg_write(m.UC_X86_REG_ESP,sp+4);mu.reg_write(m.UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook28)
def setup28(c):
 global cfg28,cfg27
 cfg28=dict(c);cfg27={};setup();n.write(SIN,struct.pack('<32768f',*sine));n.pack('<I',WORLD+0x298c,0 if c.get('nullDescriptor')else DESC);n.pack('<2I',DESC,0x10d8,POOL);n.pack('<I',0x93d504,POOL);n.pack('<I',0x93d500,0xdeadbeef)
 for j in range(64):n.pack('<I',POOL+j*0x10d8+0x1fc,1 if j<c.get('free',0)else 0)
 n.pack('<I',0x87b504,c.get('typeLock',0));n.pack('<h',0x7f191c,c.get('hero',1));n.pack('<I',0x93b324,c.get('contextActive',0));n.pack('<B',0x7fa190,c.get('contextIndex',0)&255);n.pack('<I',WORLD+0x2988,0);n.pack('<I',WORLD+0x13c,SCENE);n.pack('<I',WORLD+0x2ae8,REG);n.pack('<I',0x8765c4,c.get('refresh',0));n.pack('<17B',0x876847,*([c.get('groupCount',0)]*17));n.pack('<3I',0x93d620,0x12345678,0x23456789,0x3456789a);n.pack('<i',0x803874,-1);n.pack('<i',0x801e38,23)
 n.pack('<3f',POS,11.125,-2.25,7.5);n.pack('<4f',DATA+0x64,1.125,2.25,3.5,4.75);n.pack('<I',0x93d508,CB)
 for j in range(340):n.pack('<I',RECORDS+j*0x4c+4,c.get('typeFlags',0))
 n.pack('<I',FORMATION+8,c.get('width',4));n.pack('<I',FORMATION+0x4c,0x12340000);n.pack('<2f',FORMATION+0x128,c.get('xspacing',2.25),c.get('zspacing',3.5));n.pack('<2IB',PATH,REG,0x1234,255)
 if c.get('missing'):n.pack('<H',MAP+(c.get('type',1)&0x153)*2,65535)
 if c.get('rooms'):
  rooms=D+0x4b000;table=D+0x4c000;n.pack('<I',WORLD+0x2988,rooms);n.pack('<I',rooms,table);n.pack('<B',table+c.get('selected',0)*0x13c+0x32,c.get('selectedActive',1));n.pack('<i',0x803874,c.get('selected',0))
 events.clear();counts.clear()

def oracle28(args,img,pad,c):
 typ,position,heading,state,path,formation,snap,spline,offset,time,group=args;rng=123;emitter=0xdeadbeef;highest=0xdeadbeef;last=[0x12345678,0x23456789,0x3456789a];groups=[c.get('groupCount',0)]*17;room=23;ev=[];scratch=bytearray(0x40)
 def u(p):return struct.unpack_from('<I',scratch if SCR<=p<SCR+0x40 else img,p-SCR if SCR<=p<SCR+0x40 else p-D)[0]
 def put(p,v):struct.pack_into('<I',scratch if SCR<=p<SCR+0x40 else img,p-SCR if SCR<=p<SCR+0x40 else p-D,v&0xffffffff)
 def word(p):return u(p)&65535
 def pw(p,v):
  for j in range(2):byte(p+j,v>>(j*8))
 def byte(p,v):
  a=scratch if SCR<=p<SCR+0x40 else img;a[p-SCR if SCR<=p<SCR+0x40 else p-D]=v&255
 def b(p):return img[p-D]
 def f(p):return struct.unpack('<f',struct.pack('<I',u(p)))[0]
 def pf(p,v):put(p,struct.unpack('<I',struct.pack('<f',v))[0])
 def port(addr,a):
  ev.append(dict(address=hex(addr),actor=ACT,args=a,flags=u(ACT+0x1f8),radius=(u(ACT+0x1dc),u(ACT+0x1e0)),packet=u(ACT+0xca4)));mutate28(addr,a,u,put,byte,pw);return 1 if addr==0x415050 else 0
 def rot(v,a,x=False):
  X=q25['X'];s=X.fl(sine[(a>>1)&32767]);co=X.fl(sine[((a+0x4000)>>1)&32767]);v=list(map(X.fl,v))
  return [v[0].flstore(),(co*v[1]-s*v[2]).flstore(),(s*v[1]+co*v[2]).flstore()]if x else[(s*v[2]+co*v[0]).flstore(),v[1].flstore(),(v[2]*co-v[0]*s).flstore()]
 def add(out,a,bb):
  for j in range(3):pf(out+j*4,(q25['X'].fl(f(a+j*4))+q25['X'].fl(f(bb+j*4))).flstore())
 if(not position and not spline)or(c.get('typeLock')and typ!=(c.get('hero',1)&0xffffffff))or(c.get('contextActive')and not c.get('contextIndex',0))or typ>0x153 or word(u(REG+0x1c)+typ*2)==65535:return 0,rng,emitter,highest,last,groups,room,ev
 if not u(WORLD+0x298c)or c.get('free',0)>=64:return 0,rng,emitter,highest,last,groups,room,ev
 # Source pool preparer, initializer oracle (separately sealed), and original execution share exact actor slot.
 j=c.get('free',0);img[ACT-D:ACT-D+0x10d8]=bytes(0x10d8);put(ACT+0x1fc,0x1001);byte(ACT+0x28d,j)
 for at,v in[(0xa8,0x3f800000),(0xff8,0x3f800000),(0x1014,0x49f42400),(0x224,0x49f42400),(0x220,0x49f42400),(0x1048,1),(0x21c,0x49f42400),(0x1e8,(1<<j)&0xffffffff),(0x1ec,(1<<j)>>32)]:put(ACT+at,v)
 for at,v in[(0x671,255),(0x107a,2),(0x284,255),(0x283,255),(0x285,255)]:byte(ACT+at,v)
 highest=j+1;put(ACT,ACT);put(ACT+0x398,ACT);put(ACT+4,ACT+0x2c8);put(ACT+0x2b0,0);put(ACT+0x2b4,0)
 q['ACT']=ACT;q['cfg27']={};q25['ACT']=ACT;q26['ACT']=ACT;_,rng,initial=q['oracle'](typ,0,img,pad);emitter=0;ev+=initial
 put(ACT+0x1f8,u(ACT+0x1f8)|0x400);fl=u(u(REG+0x20)+typ*0x4c+4);put(ACT+0x1f8,u(ACT+0x1f8)|(4 if fl&0x200 else 1 if fl&4 else 0));put(ACT+0x1044,u(ACT+0x1044)|1|(4 if u(u(REG+0x20)+typ*0x4c+4)&0x1000 else 0))
 for j in range(3):put(ACT+0x230+j*4,u(u(u(REG+0x20)+typ*0x4c+0x24)+0x64+j*4))
 lastparam=u(u(u(REG+0x20)+typ*0x4c+0x24)+0x70);put(ACT+0x4b0,u(ACT+0x4b0)&0xffffafff);put(ACT+0xeec,u(ACT+0xeec)&0xfffff7fe);put(ACT+0x23c,lastparam)
 for at in[0x39c,0x454,0x3a4,0x3ac,0x3b4,0x2a8,0x2ac,0xeb0,0xec4,0xeb4,0xecc,0xec0]:put(ACT+at,0)
 pf(ACT+0x3a8,1e9);pf(ACT+0x3b8,1e9);port(0x41b0a0,[ACT]);physical=ACT+0x5c
 if spline:
  port(0x553570,[ACT+0xe64,spline,0,time]);port(0x550a20,[u(ACT+0xe64),u(ACT+0xe80),SCR,SCR+0x10,SCR+0x14,(b(ACT+0xe6a)if b(ACT+0xe6a)<128 else b(ACT+0xe6a)-256)&0xffffffff]);angle=word(SCR+0x10)
  for at in[0x5a,0x58,0x27a]:pw(ACT+at,angle)
  pw(ACT+0x278,-word(SCR+0x14))
  if offset:
   for j in range(3):put(ACT+0xe84+j*4,u(offset+j*4))
   v=[f(ACT+0xe84+j*4)for j in range(3)]
   if any(v):
    v=rot(rot(v,word(ACT+0x278),True),word(ACT+0x27a))
    for j in range(3):pf(SCR+0x20+j*4,v[j])
    add(SCR,SCR,SCR+0x20)
  for j in range(3):put(physical+j*4,u(SCR+j*4))
 else:
  for j in range(3):put(physical+j*4,u(position+j*4))
  for at in[0x27a,0x58,0x5a]:pw(ACT+at,heading)
  if formation:
   port(0x518040,[formation,ACT]);X=q25['X'];xx=(X.fl((b(ACT+0x411)+1)//2)*X.fl(f(formation+0x128))).flstore()
   if b(ACT+0x411)&1:xx=-xx
   zz=(X.fl(b(ACT+0x412))*-X.fl(f(formation+0x12c))).flstore();v=rot([xx,0.,zz],heading)
   for j in range(3):pf(SCR+0x20+j*4,v[j])
   add(physical,physical,SCR+0x20)
 port(0x41af70,[ACT]);xyz=[u(physical+j*4)for j in range(3)]
 for j in range(3):put(ACT+0x80+j*4,xyz[j]);put(ACT+0x98+j*4,xyz[j])
 last=[u(ACT+0x80+j*4)for j in range(3)]
 for j in range(3):put(ACT+0x8c+j*4,u(ACT+0x80+j*4));pf(ACT+0x68+j*4,[7.,8.,9.][j])
 q26['oracle26']('height',{},img);q26['oracle26']('update',{'callback':False},img);port(CB,[ACT]);port(0x54a7f0,[u(ACT+0xca4)+0x40]);port(0x595840,[physical,ACT+0x4d8,u(WORLD+0x2ab4)]);byte(ACT+0x671,255);pw(ACT+0x672,65535)
 rooms=u(WORLD+0x2988)
 if rooms:
  selected=c.get('selected',0)
  if selected!=-1 and b(u(rooms)+selected*0x13c+0x32):room=selected
  port(0x541bc0,[rooms,physical,0xffffffff,0xffffffff,ACT+0x670]);port(0x53f380,[ACT+0x7cc])
 h=word(ACT+0x27a);pf(ACT+0xf30,sine[(h>>1)&32767]);put(ACT+0xf34,0);pf(ACT+0xf38,sine[((h+0x4000)>>1)&32767]);put(ACT+0xef0,u(ACT+0xef0)&0xfffbffff);byte(ACT+0x288,1);byte(ACT+0x1079,0);byte(ACT+0x28c,0)
 if not spline:
  port(0x5728a0,[ACT])
  if snap:port(0x572660,[ACT,0])
 port(0x55d6a0,[ACT,1,1,0xffffffff,u(WORLD+0x13c)])
 if c.get('refresh'):
  data=u(u(ACT+0x54)+0x24);byte(ACT+0x107e,b(data+0xf4));byte(ACT+0x107f,b(data+0xf4));byte(ACT+0xe38,b(u(u(ACT+0x54)+0x24)+0xf5));byte(ACT+0xe39,4)
 put(ACT+0x1fc,u(ACT+0x1fc)&0xfffffffb);put(ACT+0xff8,0x3f800000)
 for at,v in[(0x28b,0),(0x7b5,255),(0x289,0),(0x404,255),(0x405,0)]:byte(ACT+at,v)
 put(ACT+0x1f8,u(ACT+0x1f8)&0xfffffeff)
 for j in range(6):put(ACT+0x420+j*4,0)
 pw(ACT+0x3ec,65535)
 if not spline:
  if path:port(0x51a7c0,[ACT+0x2c8,u(path)]);port(0x51b890,[ACT+0x2c8,physical,u(path+4),b(path+8)])
  if not u(ACT+0x424):port(0x52f800,[u(WORLD+0x2ae8),ACT,ACT+0x2c8,255,(b(ACT+0x281)if b(ACT+0x281)<128 else b(ACT+0x281)-256)&0xffffffff])
 port(0x514640,[u(WORLD+0x2ae8),ACT+0x2c8,ACT+0x2c8,0,state,0,1,0,0]);pf(ACT+0x218,2e6)
 form=u(ACT+0x40c)
 if form:
  shift=lambda v:1<<(v&255)if(v&255)<32 else 0
  put(form+0x4c,u(form+0x4c)|shift(b(ACT+0x410)));rowIndex=b(ACT+0x412);form=u(ACT+0x40c);row=form+0x54+rowIndex*0x34;byte(row+0x2d,b(row+0x2d)|(shift(b(ACT+0x410)-b(form+8)*rowIndex)&255))
  if not b(ACT+0x411):
   for j in range(3):put(row+0x18+j*4,u(physical+j*4))
   for j in range(6):put(row+j*4,u(ACT+0x420+j*4))
   angle=word(ACT+0x27a);put(row+0x30,u(row+0x30)&0xfffffffd);put(row+0x24,angle);put(row+0x28,0)
 for a in[0x498a40,0x4b6b80,0x55d2b0]:port(a,[ACT])
 xyz=[u(physical+j*4)for j in range(3)]
 for at,v in[(0x1b4,xyz[0]),(0x10bc,xyz[0]),(0x1b8,xyz[1]),(0x10c0,xyz[1]),(0x1bc,xyz[2]),(0x10c4,xyz[2])]:put(ACT+at,v)
 if 1<=group<=16:byte(ACT+0x378,group);groups[group]=(groups[group]+1)&255
 return ACT,rng,emitter,highest,last,groups,room,ev

vectors=[];errors=[]
def run28(c):
 global ACT
 ACT=POOL+c.get('free',0)*0x10d8 if c.get('free',0)<64 else POOL
 for mod in[q,q25,q26]:mod['ACT']=ACT
 setup28(c);args=[c.get('type',1),0 if c.get('nullPosition')else POS,c.get('heading',0),c.get('state',0),PATH if c.get('path')else 0,FORMATION if c.get('formation')else 0,c.get('snap',1),PATH if c.get('spline')else 0,POS if c.get('offset')else 0,c.get('time',0x3f000000),c.get('group',1)];before=bytearray(n.read(D,SIZE));padBefore=bytearray(n.read(PAD,PADSIZE));expected=bytearray(before);padExpected=bytearray(padBefore);ret,rng,emitter,highest,last,groups,room,ev=oracle28(args,expected,padExpected,c);result=n.call(0x43d890,args,count=2000000);after=n.read(D,SIZE);padAfter=n.read(PAD,PADSIZE);actual=[result,n.unpack('<I',0x80253c)[0],n.unpack('<I',0x855f80)[0],n.unpack('<I',0x93d500)[0],list(n.unpack('<3I',0x93d620)),list(n.read(0x876847,17)),n.unpack('<i',0x801e38)[0]];target=[ret,rng,emitter,highest,last,groups,room];ok=[after==expected,padAfter==padExpected,actual==target,json.dumps(events)==json.dumps(ev)]
 if not all(ok):errors.append(dict(input=c,checks=ok,actual=actual,target=target,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12],trace=[events.copy(),ev]if not ok[3]else None))
 vectors.append(dict(input=c,args=args,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),padBefore=base64.b64encode(gzip.compress(padBefore)).decode(),padAfter=base64.b64encode(gzip.compress(padAfter)).decode(),globals=actual,events=events.copy()))
for c in[{},dict(formation=True),dict(spline=True),dict(spline=True,offset=True),dict(path=True,rooms=True,refresh=1,mutate=True)]:run28(c)
for j in range(65):run28(dict(free=j,type=9 if j%7==0 else 1))
for typ,lock,missing in itertools.product([0,1,5,6,7,8,9,339,340,65535,0xffffffff],[0,1],[False,True]):run28(dict(type=typ,typeLock=lock,missing=missing))
for idx in range(256):run28(dict(contextActive=1,contextIndex=idx))
for j in[0,1,2,15,16,17,255,65535,0xffffffff]:
 for count in[0,254,255]:run28(dict(group=j,groupCount=count))
for col,row,member,width in itertools.product([0,1,2,3,254,255],[0,1,3],[0,7,8,31,32,63,64,127,255],[0,4,255]):run28(dict(formation=True,column=col,row=row,member=member,width=width,heading=0x12345,mutate=col%2==0))
for h,pitch,offset in itertools.product([0,1,0x3fff,0x4000,0x7fff,0x8000,0xffff],[0,1,0x4000,0x8000,0xffff],[False,True]):run28(dict(spline=True,nullPosition=True,offset=offset,sampleHeading=h,samplePitch=pitch,time=0x3f400000,refresh=1))
for fl,mut,path,bound,snap in itertools.product([0,4,0x200,0x204,0x1000,0x1204,0xffffffff],[False,True],[False,True],[False,True],[0,1]):run28(dict(typeFlags=fl,mutate=mut,path=path,boundPath=bound,snap=snap))
for selected,active in itertools.product([-1,0,1,3],[0,1,255]):run28(dict(rooms=True,selected=selected,selectedActive=active))
for c in[dict(nullPosition=True),dict(nullDescriptor=True),dict(hero=-1,typeLock=1),dict(typeLock=1,hero=1,type=1)]:run28(c)
(m.BASE/'reports/movement-phase28-20261013-tests.json').write_text(json.dumps(dict(cases=len(vectors),groups=4*len(vectors),mismatches=len(errors),errors=errors[:5]),indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:2])))

if errors:raise SystemExit('Source-model mismatches; no sealed fixture written')
report=dict(status='sealed bounded original x86 comparisons; managed replay unexecuted',binarySha256=n.sha256,cases=len(vectors),assertionGroups=4*len(vectors),mismatches=0,originalCpuHelpers=CPUS,explicitServices=[hex(a)for a in SERVICES],limits=['Complete own-body actor creator with real native pool and initializer CPU chain; child reset/spline/formation/path/script/geometry/room/bounds services explicit.','Full retained DATA and animation PAD images, seven scalar/vector global groups, return and ordered service trace; caller spline output pointers normalized to disjoint portable scratch.','Finite computed placement/metadata floats and complete valid backing; no machine flags/FPU status/partial faults or whole-game equivalence.'])
(m.BASE/'reports/movement-phase28-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase28-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(paddingBits=n.unpack('<I',0x7f2374)[0],sineTable='reverse-engineering/references/native-animation-sine-table.f32',vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(0x43d890,0x43e03b-0x43d890),0x43d890)]
(m.BASE/'reports/movement-phase28-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=[dict(address='0x43d890',size=0x43e03b-0x43d890,instructions=ins)]),indent=2)+'\n')
