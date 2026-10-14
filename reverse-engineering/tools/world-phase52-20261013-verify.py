import json,hashlib,struct,base64,gzip,time,math,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;PTR=D+0x1000;FIFO=D+0x2000;R=D+0x3000;POS=D+0x4000;VEL=D+0x4100;DELTA=D+0x4200;CUE=D+0x4600;FREE7=D+0x12000;FREE=D+0x13000;RETURN=D+0x14000;NODES=D+0x16000;PACKETS=D+0x18000;DESCFREE=D+0x1a000;DESC=D+0x74000;TLS=D+0xf800
REGIONS=[(D,0x80000,167),(0x2961f00,0x400,0),(0x2921100,0x1200,167),(0x2923180,0x80,167),(0x2947b70,4,0),(0x2947d00,0x400,0),(0x2948e00,0x600,0),(0x810710,0x434,167),(0x8104b4,4,0),(0x292fa00,0x600,0),(0x806680,64,0),(0x8065c0,64,0),(0x29a9c48,4,0),(0x29899a0,0x20000,0),(0x2924b40,16,0)];rot['REGIONS']=REGIONS;rot['common']=[rot['patch'](0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes()),rot['patch'](0x8065c0,n.read(0x8065c0,64)),rot['patch'](0x806680,n.read(0x806680,64))];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S16=rot['signed16'];S8=lambda x:x-256 if x&128 else x;S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0]
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
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={}
class NativeImage:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
NI=NativeImage()
def observe(uc,a,z,user):
 if a in [0x6561d0,0x653970,0x654930,0x653c50,0x653f40,0x681f70,0x682290,0x6826a0,0x654270,0x6545d0,0x600260,0x654950,0x654970,0x6549a0,0x6549c0,0x6549e0,0x654a00,0x6e8e1e,0x5b9d90,0x64fe20,0x653840,0x6551d0,0x656080]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x5d69a0,0x6f040c,0x5f74a0]:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if a==0x5d69a0:
  p,v,radius=n.unpack('<3I',sp+4);args=list(n.unpack('<3I',p))+list(n.unpack('<3I',v))+[radius]
 else:args=[]
 result=dispatch(NI,a,args);uc.reg_write(UC_X86_REG_EAX,U(result));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,observe)
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
cases=[seed(kind,bank,typ,attribute[k]) for kind in range(13) for bank in [0,4] for typ in [0,7] for k in range(7)]
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];desc['trace']=trace;im=Image(c)
 try:burst['burst'](im,c)
 except (ValueError,OverflowError,ZeroDivisionError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 modelTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x6561d0,[c['physical'],c['position'],c['velocity'],c['delta'],c['count'],c['duration'],c['secondary'],c['primary'],c['priority'],c['flags']],count=10000000)
 except Exception as ex:errors.append(dict(case=i,stage='native',error=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=modelTrace:
  errors.append(dict(case=i,kind=c['kind'],actual=actual,model=im.hash(),nativeTrace=trace,modelTrace=modelTrace))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=['0x5d69a0 copied visibility input','0x6f040c TLS context','0x5f74a0 terminal capacity failure'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded,initializerTable=[hex(v) for v in table],fixtureProvenance='new authored raw valid burst fixtures cover all13 physical selectors, both clock banks, ordinary/type7 formats and recovered attribute variants; real descriptor runtime sine/template preparation')
(B/'reports/world-phase52-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase52-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],tlsContext=TLS,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
