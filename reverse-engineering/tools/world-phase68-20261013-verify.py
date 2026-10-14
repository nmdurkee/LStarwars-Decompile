import json,hashlib,struct,base64,gzip,time,math,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;PTR=D+0x1000;FIFO=D+0x2000;R=D+0x3000;POS=D+0x4000;VEL=D+0x4100;DELTA=D+0x4200;CUE=D+0x4600;FREE7=D+0x12000;FREE=D+0x13000;RETURN=D+0x14000;NODES=D+0x16000;PACKETS=D+0x18000;DESCFREE=D+0x1a000;DESC=D+0x74000;TLS=D+0xf800
REGIONS=[(0x2854ce8,4,0),(0x2962928,4,0),(D,0x80000,167),(0x2961f00,0x400,0),(0x2921100,0x1200,167),(0x2923180,0x80,167),(0x2947b70,4,0),(0x2947d00,0x400,0),(0x2948e00,0x600,0),(0x810710,0x434,167),(0x8104b4,4,0),(0x292fa00,0x600,0),(0x806680,64,0),(0x8065c0,64,0),(0x29a9c48,4,0),(0x29899a0,0x20000,0),(0x2924b40,16,0)];rot['REGIONS']=REGIONS;rot['common']=[rot['patch'](0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes()),rot['patch'](0x8065c0,n.read(0x8065c0,64)),rot['patch'](0x806680,n.read(0x806680,64))];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S16=rot['signed16'];S8=lambda x:x-256 if x&128 else x;S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0]
class Image(rot['Image']):
 def read(self,a,z):return super().read(U(a),z)
 def write(self,a,v):return super().write(U(a),v)
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))
common=dict(rot=rot,N=N,U=U,F=F,bits=bits,math=math,struct=struct,S=S,S16=S16,S8=S8,D=D,R=R,EM=EM,CUE=CUE,CTX=TLS,GLOBAL=0x29620a4,NEXT=0x29211e8,SINE=0x29899a0)
# Load only previously retained pure model function definitions. No extra native instances, setup, observers or test loops.
def model(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);t=ast.parse(p.read_text());selected=ast.Module(body=[x for x in t.body if isinstance(x,(ast.FunctionDef,ast.AsyncFunctionDef))],type_ignores=[]);ctx=dict(common,__file__=str(p));exec(compile(selected,str(p),'exec'),ctx);return ctx
ctor=model(21);links=model(24);unlinks=model(26);events=model(33);scalar=model(34);maths=model(36);init=model(37);attrs=model(38);desc=model(40);sphere=model(42);polar=model(43);inv=model(44);cone=model(45);lobed=model(46);ellipsoid=model(47);roots=model(48);quadratic=model(49);plane=model(51);burst=model(35)
events['row']=lambda im,e,f:U(e+S16(im.H(e+0x2c8))*28+f)
commonBase=dict(common,maths=maths,nextRandom=init['nextRandom'],randomAxis=init['randomAxis'],CALLBACK=0x10303000)
for ctx in [init,ellipsoid]:ctx.update(maths=maths)
for ctx in [sphere,polar,cone,lobed,quadratic,plane]:ctx.update(base=commonBase,roots=roots,links=links)
quadratic['node']=lambda im:im.W(im.W(0x2923198)+im.W(0x2947b70)*4)
plane['node']=quadratic['node']
cone['inv']=inv;ellipsoid['inv']=inv;burst.update(ctor=ctor,links=links,unlinks=unlinks,events=events,scalar=scalar);initializerMap={0x653970:init,0x654930:init,0x653c50:sphere,0x653f40:polar,0x681f70:ellipsoid,0x682290:quadratic,0x6826a0:plane,0x654270:cone,0x6545d0:lobed};case={};trace=[]
def dispatch(im,address,args):
 if address in initializerMap:return initializerMap[address]['initialize'](im,dict(emitter=args[0],record=args[1],time=args[2]))
 if address==0x600260:desc['produce'](im,args[0]);return 0
 if address in [0x654950,0x654970,0x6549a0,0x6549c0,0x6549e0,0x654a00]:attrs['attr'](im,dict(entry=address,record=args[1],particle=args[2]));return 0
 if address==0x5d69a0:trace.append([address,args]);return 1
 if address==0x6f040c:trace.append([address,args]);return TLS
 if address==0x5f74a0:trace.append([address,args]);return 0
 raise ValueError('unbound recovered composition '+hex(address))
for ctx in [init,ellipsoid,burst]:ctx['service']=dispatch
commonBase['service']=dispatch;attrs['tls']=lambda im:dispatch(im,0x6f040c,[])
table=[0x653970]+[0x654930]*5+[0x653c50,0x653f40,0x681f70,0x682290,0x6826a0,0x654270,0x6545d0];attribute=[0,0x654950,0x654970,0x6549a0,0x6549c0,0x6549e0,0x654a00]
def seed(kind,bank,typ,callback):
 c=dict(kind=kind,callback=callback,physical=1,position=POS,velocity=VEL,delta=DELTA,count=4,duration=bits(1),primary=0,secondary=0,priority=30000,flags=0x56,writes=[patch(EM-0x330,bytes(0x8000)),patch(R,bytes(0x440)),word(0x2962050,0),word(0x8104b4,1),word(0x2962098,4),word(0x296209c,PTR),word(PTR+4,R),word(0x2962094,16),word(0x2962084,FIFO),word(0x29211e8,0),word(0x29620a4,EM),word(0x29620b8,0),word(0x810908,bits(1)),byte(R+0x13,0),byte(R+0x2f1,bank),byte(R+0x2e,typ),byte(R+0x2c,kind),byte(R+0x2d,0),word(R+0x2f4,bits(1)),word(R+0x38,bits(1)),byte(R+0x410,1),byte(R+0x411,8),byte(R+0x2f0,1),word(R+0x414,bits(0.25)),word(R+0x418,bits(0.5)),word(R+0x41c,bits(0.25)),word(R+0xa0,bits(0.25)),word(R+0xa4,bits(5)),word(0x296205c,bits(10)),word(0x2962060,bits(20)),patch(POS,struct.pack('<3f',1.25,-2.5,-0.0)),patch(VEL,struct.pack('<3f',0.5,0.25,-0.0)),patch(DELTA,struct.pack('<3f',0.25,-0.5,0.125)),word(0x29211fc,FREE7),word(0x2921200,FREE),word(0x2923198,RETURN),word(0x2961fec,PACKETS),word(0x2947b70,0),word(0x2947d84,0),word(0x2948e98,0),word(0x8108e8,33),word(0x8108ec,33),word(0x2962058,0),patch(0x292fa00,bytes(0x600)),word(0x810900,0x12345678),word(TLS+20,0xabcdef01),word(0x2924b44,0),word(0x8108fc,8),word(0x2962090,DESCFREE),word(R+0x2a8,0),patch(R+0x48,struct.pack('<10f',0.75,1,2,3,1.25,-0.5,0.75,0.25,0.5,0.75))])
 for j,a in enumerate(table):c['writes'] += [word(0x810910+j*4,a)]
 c['writes'] += [word(0x810944,callback)]
 for i in range(16):c['writes'] += [half(FIFO+i*2,i),word(EM+i*0x330+0x2cc,0),word(EM+i*0x330+0x2e0,bits(1)),word(EM+i*0x330+0x2e4,bits(0.9)),half(EM+i*0x330+0x2de,8192)]
 for i in range(8):c['writes'] += [half(R+0x3d0+i*2,65535),word(DESCFREE+i*4,DESC+i*0x1000)]
 for i in range(-4,64):c['writes'] += [word(FREE7+i*4,D+0x20000+(i+4)*0x500),word(FREE+i*4,D+0x40000+(i+4)*0x500)]
 for i in range(132):c['writes'] += [word(RETURN+i*4,NODES+i*0x40),word(NODES+i*0x40,0),word(NODES+i*0x40+16,0)]
 for i in range(66):c['writes'] += [word(PACKETS+i*0x64,0),word(PACKETS+i*0x64+0x58,0),word(PACKETS+i*0x64+0x5c,0)]
 for field,value in [(0x150,256),(0x190,128),(0x1d8,8192),(0x100,100)]:
  for i in range(8):c['writes'] += [word(R+field+i*8,bits(i/7)),word(R+field+i*8+4,bits(value+i*value/8))]
 for i in range(8):c['writes'] += [word(R+0xc0+i*8,bits(i/7)),patch(R+0xc4+i*8,bytes([i*31,255-i*31,(i*53)&255,0]))]
 return c
common["identity"]=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]
bound=model(65);eviction=model(58);CAMERA=D+0x7c000;MATERIAL=D+0x6c000;ENV=D+0x7b000
from fractions import Fraction
trace=[];case={};desc['trace']=trace
def external(im,a,args):
 trace.append([a,args]);writes=case.get('serviceWrites',{}).get(hex(a),[])
 for x in writes:im.write(x['address'],base64.b64decode(x['data']))
 if a==0x5d6170:return CAMERA
 if a in [0x5da3b0,0x6042e0]:return case.get('visibility',1) if a==0x5da3b0 else case.get('bounds',1)
 if a==0x6f040c:return TLS
 return 0
# The imported D3DX child is a mutable explicit identity/camera-output service in these fixtures.
def camera(im,left,right):
 external(im,0x5c0500,left[:]+[right])
 for x in case.get('cameraWrites',[]):left[x['index']]=x['value']
def translate(im,left,point):
 for i in range(3):left[12+i]=(N.word(left[12+i])+N.word(point[i])).store()
def distance(im,p):
 ref=im.W(0x2962080)
 if not ref:return 0
 d=[]
 for i in range(3):b=N.word(im.W(ref+i*4));d.append(N.word((N.word(im.W(p+i*4))+N(-b.v,not b.neg)).store()))
 x,y,z=d;return bits(math.sqrt(F((x*x+y*y+z*z).store())))
def point(im,p):return [im.W(p+i*4) for i in range(3)]
def matrix(im,p):return [im.W(p+i*4) for i in range(16)]
def render(im,c):
 bank=c['bank']
 if im.W(0x2962050):return
 external(im,0x5d8400,[0,12,0x76e1f4]);im.H(im.W(0x292fd68)+0x74,im.H(0x29620b0));packet=im.W(0x292fd30+bank*4);any=False;iterations=0
 while packet:
  iterations+=1
  if iterations>128:raise ValueError('render list nonterminating')
  if im.W(packet):
   r=im.W(packet+4);e=im.W(packet+8)
   if (not im.W(0x296204c) or not im.B(r+0x12)) and (im.W(0x810904)==0xffffffff or not e or im.W(e+0x2d4)!=im.W(0x810904)):
    if not im.W(r+0x2a8):
     if im.W(0x2924b44)==im.W(0x8108fc):eviction['evict'](im,dict(entry=0x657e70))
     desc['produce'](im,r)
    if im.W(r+0x2a8):
     allowed=True;matched=False;left=None;pos=None
     if not e:
      if F(im.W(r+0x3c))>0 and not im.B(r+0x2f3) and F(distance(im,packet+0x4c))>F(im.W(r+0x3c)):allowed=False
      if allowed:left=matrix(im,packet+12);pos=point(im,packet+0x4c)
     else:
      for i in range(8):
       id=im.H(r+0x3d0+i*2)
       if id!=65535 and U(im.W(0x29620a4)+S16(id)*0x330)==e:matched=True;break
      if not matched and F(im.W(r+0x3c))>0 and not im.B(r+0x2f3) and F(im.W(r+0x3c))<F(im.W(e+0x31c)):allowed=False
      if not im.B(e+0x2f7):allowed=False
      if bank!=4 and allowed and not im.B(r+0x2c) and not im.B(r+0x2f3) and not matched:
       if F(im.W(e+0x300))==0 or im.W(im.W(0x8109d4)):bound['bounds'](im,dict(record=r,emitter=e))
       if not im.W(0x2962928) and im.W(e+0x2fc) and im.H(e+0x2f2)!=65535:
        if not external(im,0x5da3b0,[im.W(e+0x2fc)]+point(im,e+0x190)+[im.W(e+0x300),im.H(e+0x2f2)]):allowed=False
       if not external(im,0x6042e0,[im.W(e+f) for f in [0x304,0x308,0x30c,0x310,0x314,0x318]]+[e,0,0]):allowed=False
      if allowed:left=matrix(im,e+0x40);pos=point(im,e+0x190)
     if allowed:
      any=True;translate(im,left,pos)
      if bank==4:camera(im,left,external(im,0x5d6170,[]));backup=im.W(0x2962068);clock=im.W(0x2962060)
      else:backup=im.W(0x2962064);clock=im.W(0x296205c)
      im.W(r+0x2ac,clock);modifier=e+0xc0 if e and im.B(e+0x2fa) else 0x2947c20 if im.B(r+0x412) else 0;im.W(0x2854ce8,modifier);scale=N.word(im.W(0x810968))
      for i in range(3):left[i]=(N.word(left[i])*scale).store()
      if im.B(r+0x2e)==7:flags=4
      elif im.B(r+0x2f3):external(im,0x5d4380,[r+0x2f8]);flags=6
      else:flags=0
      color=im.W(r+0x44);life=im.W(r+0x38);second=im.W(r+0x144);first=im.W(r+0x140);live=im.W(packet+4);type=S8(im.B(live+0x2e));material=im.W(0x292fd4c+type*4);descriptor=im.W(live+0x2a8);chunk=im.W(packet);external(im,0x60c410,[chunk,descriptor,material,backup]+left+[flags,first,second,life,color])
  packet=im.W(packet+0x5c)
 if any:im.W(0x29620c4,1 if not im.W(0x29620c4) else 0)
 external(im,0x5d8440,[0,12])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={}
class NativeImage:
 def write(self,a,v):n.write(a,v)
NI=NativeImage()
def observe(uc,a,z,user):
 if a in [0x685770,0x600260,0x657e70,0x656e50,0x6585a0,0x5becc0,0x5c0240,0x64ff80,0x5b4900,0x5b4c90,0x5ffd40]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x5d8400,0x5d8440,0x5da3b0,0x6042e0,0x5d6170,0x5c0500,0x5d4380,0x60c410,0x6f040c,0x5f74a0]:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if a==0x5c0500:
  dst,left,right=n.unpack('<3I',sp+4);values=list(n.unpack('<16I',left));camera(NI,values,right);n.write(dst,struct.pack('<16I',*values));result=dst
 else:
  if a==0x5d8400:args=list(n.unpack('<3I',sp+4))
  elif a==0x5d8440:args=list(n.unpack('<2I',sp+4))
  elif a==0x5da3b0:
   obj,p,radius,region=n.unpack('<4I',sp+4);args=[obj]+list(n.unpack('<3I',p))+[radius,region]
  elif a==0x6042e0:
   lo,hi,e,aa,bb=n.unpack('<5I',sp+4);args=list(n.unpack('<3I',lo))+list(n.unpack('<3I',hi))+[e,aa,bb]
  elif a==0x60c410:
   raw=list(n.unpack('<10I',sp+4));args=raw[:4]+list(n.unpack('<16I',raw[4]))+raw[5:]
  elif a==0x5d4380:args=[n.unpack('<I',sp+4)[0]]
  else:args=[]
  result=external(NI,a,args)
 uc.reg_write(UC_X86_REG_EAX,U(result));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,observe)
identity=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]
baseSeed=seed
def frame(bank=0,owner=True,typ=0,published=True,matched=False):
 c=baseSeed(0,0,0,0);c.update(bank=bank,visibility=1,bounds=1);c['writes'] += [word(0x2962050,0),word(0x296204c,0),word(0x810904,0xffffffff),word(0x810968,bits(1)),word(0x8109d4,ENV),word(ENV,0),word(0x2962928,0),word(0x2962080,0),word(0x2962064,bits(9)),word(0x2962068,bits(19)),word(0x29620c4,0),half(0x29620b0,17),word(0x292fd68,MATERIAL),word(0x292fd30 if bank==0 else 0x292fd40,PACKETS),word(PACKETS,D+0x20000),word(PACKETS+4,R),word(PACKETS+8,EM if owner else 0),word(PACKETS+0x58,0),word(PACKETS+0x5c,0),patch(PACKETS+12,struct.pack('<16f',*identity)),patch(PACKETS+0x4c,struct.pack('<3f',1.25,-2.5,3.75)),byte(R+0x2e,typ),byte(R+0x12,0),byte(R+0x2f3,0),byte(R+0x412,0),word(R+0x3c,0),word(R+0x44,bits(.5)),word(R+0x140,bits(.25)),word(R+0x144,bits(.75)),word(R+0x2a8,DESC if published else 0),word(R+0x2ac,0),byte(EM+0x2f7,1),byte(EM+0x2fa,0),word(EM+0x2d4,0xffffffff),word(EM+0x2fc,0),half(EM+0x2f2,65535),word(EM+0x300,0),word(EM+0x31c,bits(3)),patch(EM+0x40,struct.pack('<16f',*identity)),patch(EM+0x80,struct.pack('<16f',*identity)),patch(EM+0x190,struct.pack('<3f',1.25,-2.5,3.75)),patch(CAMERA,struct.pack('<16f',*identity)),word(R+0x1c,bits(1)),word(R+0x20,bits(2))]
 for i in range(8):c['writes'] += [word(0x292fd4c+i*4,MATERIAL+i*0x100),half(R+0x3d0+i*2,0 if matched and i==0 else 65535)]
 return c
cases=[frame(bank,owner,typ,published,matched) for bank in [0,4] for owner in [False,True] for typ in [0,2,3,7] for published in [False,True] for matched in [False,True]]
for gate in ['disabled','empty','hidden','filter','inactive','distance','billboard','modifier','forcing','region','bounds','begin','drawnext','camera']:
 for bank in [0,4]:
  c=frame(bank)
  if gate=='disabled':c['writes'].append(word(0x2962050,1))
  elif gate=='empty':c['writes'].append(word(PACKETS,0))
  elif gate=='hidden':c['writes'] += [word(0x296204c,1),byte(R+0x12,1)]
  elif gate=='filter':c['writes'] += [word(0x810904,123),word(EM+0x2d4,123)]
  elif gate=='inactive':c['writes'].append(byte(EM+0x2f7,0))
  elif gate=='distance':c['writes'].append(word(R+0x3c,bits(1)))
  elif gate=='billboard':c['writes'].append(byte(R+0x2f3,1))
  elif gate=='modifier':c['writes'].append(byte(EM+0x2fa,1))
  elif gate=='forcing':c['writes'] += [word(ENV,1),word(EM+0x300,bits(3))]
  elif gate=='region':c['writes'] += [word(EM+0x2fc,D+0x60000),half(EM+0x2f2,2)];c['visibility']=0
  elif gate=='bounds':c['bounds']=0
  elif gate=='begin':c['serviceWrites']={'0x5d8400':[half(0x29620b0,123)]}
  elif gate=='drawnext':c['serviceWrites']={'0x60c410':[word(PACKETS+0x5c,0),word(0x29620c4,7)]}
  elif gate=='camera':c['cameraWrites']=[dict(index=12,value=bits(4))];c['serviceWrites']={'0x5c0500':[word(0x2962068,bits(7))]}
  cases.append(c)
for bank in [0,4]:
 for reference in [0,D+0x7a000]:
  for limit in [0,.01,1,10,1000]:
   c=frame(bank,False);c['writes'] += [word(0x2962080,reference),patch(D+0x7a000,struct.pack('<3f',0,0,0)),word(R+0x3c,bits(limit))];cases.append(c)
for bank in [0,4]:
 for redirected in [False,True]:
  c=frame(bank);next=PACKETS+100;c['writes'] += [word(next,D+0x20400),word(next+4,R),word(next+8,0),word(next+0x58,PACKETS),word(next+0x5c,0),patch(next+12,struct.pack('<16f',*identity)),patch(next+0x4c,struct.pack('<3f',-1,2.5,.25))]
  if redirected:c['serviceWrites']={'0x60c410':[word(PACKETS+0x5c,next)]}
  else:c['writes'].append(word(PACKETS+0x5c,next))
  cases.append(c)
# Full capacity must run real eviction before real descriptor construction.
c=frame(published=False);c['writes'] += [word(0x2924b44,8),word(PTR+8,R+0x500),word(PTR+12,0),word(R+0x500+0x2a8,DESC+0x1000),word(R+0x500+0x2ac,bits(0)),byte(R+0x500+0x2f1,0)];cases.append(c)
c=frame(published=False);c['writes'] += [word(0x2962098,2),word(0x8108fc,0),word(0x2924b44,0)];cases.append(c)
for toggle in [0,1,7,0xffffffff]:c=frame();c['writes'].append(word(0x29620c4,toggle));cases.append(c)
# Billboard service changes physical type after the flag6 decision but before live material lookup.
c=frame();c['writes'].append(byte(R+0x2f3,1));c['serviceWrites']={'0x5d4380':[byte(R+0x2e,7),word(R+0x44,bits(.25))]};cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];desc['trace']=trace;im=Image(c)
 try:render(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 modelTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x685770,[0,c['bank']],count=10000000)
 except Exception as ex:errors.append(dict(case=i,nativeError=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=modelTrace:
  errors.append(dict(case=i,actual=actual,model=im.hash(),nativeTrace=trace,modelTrace=modelTrace))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]))
  break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=['device state begin/end','5da3b0 region visibility','6042e0 dynamic box query','5d6170 camera pointer','5c0500 imported D3DX mutable matrix policy','5d4380 billboard preparation','60c410 GPU draw submission','6f040c TLS context','5f74a0 descriptor capacity failure'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase68-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase68-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],cameraPointer=CAMERA,tlsContext=TLS,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
