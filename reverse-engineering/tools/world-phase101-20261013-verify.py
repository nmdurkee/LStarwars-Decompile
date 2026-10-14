import json,hashlib,struct,base64,gzip,time,math,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;PTR=D+0x1000;FIFO=D+0x2000;R=D+0x3000;POS=D+0x4000;VEL=D+0x4100;DELTA=D+0x4200;CUE=D+0x4600;FREE7=D+0x12000;FREE=D+0x13000;RETURN=D+0x14000;NODES=D+0x16000;PACKETS=D+0x18000;DESCFREE=D+0x1a000;DESC=D+0x74000;TLS=D+0xf800
REGIONS=[(0x9868a0,0x1a4,0),(0x9738a4,4,0),(0x297dc00,4,0),(0x963f78,16,0),(0x971690,0x40,0),(0x97396c,4,0),(0x9209d8,24,0),(0x91ef80,8,0),(0x96d9c0,0x20,167),(0x96e53c,4,0),(0x971580,0x40,167),(0x9736e0,8,0),(0x9736e8,120,167),(0x80b708,48,0),(0x97f978,64,167),(0x987500,16,167),(0x2974d1c,4,0),(0x280d3cc,64,0),(0x97acd0,64,167),(0x80bfa8,96,0),(0x2854ce0,0x80,0),(0x2962928,4,0),(D,0x100000,167),(0x2961f00,0x400,0),(0x2921100,0x1200,167),(0x2923180,0x80,167),(0x2947b70,4,0),(0x2947d00,0x400,0),(0x2948e00,0x600,0),(0x810710,0x434,167),(0x8104b4,4,0),(0x292fa00,0x600,0),(0x806680,64,0),(0x8065c0,64,0),(0x29a9c48,4,0),(0x29899a0,0x20000,0),(0x2924b40,16,0),(0x297cc6c,4,0),(0x297cc70,0x808,0),(0x297bea0,4,0),(0x297ae20,4,0),(0x29765c8,0x658,0),(0x854260,8,0),(0x297d690,0x420,0)];rot['REGIONS']=REGIONS;rot['common']=[rot['patch'](0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes()),rot['patch'](0x8065c0,n.read(0x8065c0,64)),rot['patch'](0x806680,n.read(0x806680,64))];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S16=rot['signed16'];S8=lambda x:x-256 if x&128 else x;S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0]
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
common['P']=D+0x2000;box=model(69);box['Fraction']=rot['Fraction'];rot['common'].append(rot['patch'](0x80bfa8,n.read(0x80bfa8,96)))
bound=model(65);eviction=model(58);CAMERA=D+0x7c000;MATERIAL=D+0x6c000;ENV=D+0x7b000
from fractions import Fraction
PROFILE=D+0x7e000;PTICKS=PROFILE+0x100;PMODES=PROFILE+0x200;PLABEL=PROFILE+0x300;ownerModel=model(82);ownerPayload=model(81);ownerPayload['quiet']=lambda w:w|0x400000 if w&0x7fffffff>0x7f800000 else w;ownerCommand=model(80);ownerModel.update(payload=ownerPayload,command=ownerCommand,quiet=lambda w:w|0x400000 if w&0x7fffffff>0x7f800000 else w);submission=model(78);smatrix=model(76);smatrix['quiet']=lambda w:w|0x400000 if w&0x7fffffff>0x7f800000 else w;slink=model(77);slink['trunc8']=lambda i:i//8 if i>=0 else -((-i)//8);slink['ownerModel']=ownerModel
p=Path(__file__).with_name('world-phase77-20261013-verify.py');ts=p.read_text();tt=ast.parse(ts);body=ast.get_source_segment(ts,next(x for x in tt.body if isinstance(x,ast.FunctionDef) and x.name=='apply'));body=body.replace('trace=[[0x607590,[owner,0x9868a0]]]','trace=[]').replace(" for p in c.get('mutations',[]):im.write(p['address'],base64.b64decode(p['data']))"," ownerModel['emit'](im,dict(owner=owner,shader=0x9868a0))");exec(compile(body,str(p),'exec'),slink)
submission.update(matrices=smatrix,link=slink);visibility=model(73);profile=model(71);profile.update(PROBE=D+0x7fff0,base64=base64);clockIndex=0

PREP=0x10300000;COMPILE=PREP+0x100;IENTER=PREP+0x400;IEXIT=PREP+0x500;DECL_TARGET=PREP+0x600;PROGRAMS=D+0x80000;VTABLE=D+0x7f000;DECL_DEVICE=D+0x7f400;DECL_TABLE=D+0x7f600
n.mu.mem_map(PREP,0x1000)
for address in [PREP,COMPILE,IENTER,IEXIT,DECL_TARGET]:n.write(address,b'\xc3')
n.write(0x7510b8,struct.pack('<I',IENTER));n.write(0x7510b4,struct.pack('<I',IEXIT))
materialEnv=dict(rot=rot,N=N,U=U,F=F,struct=struct,S=S,S16=S16,S8=S8,base64=base64,ast=ast,Path=Path,D=D,n=n,__file__=__file__,PREP=PREP,COMPILE=COMPILE,IENTER=IENTER,IEXIT=IEXIT,DECL_TARGET=DECL_TARGET,entries={},firstProgram=0,lastToken=0,tokens=[])
exec("trace=[];case={};counts={}\ndef service(im,address,args):\n key=hex(address);index=counts.get(key,0);counts[key]=index+1\n if address not in [0x744b70,0x7418c0]:trace.append([address,args])\n for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))\n seq=case.get('sequenceWrites',{}).get(key,[])\n if index<len(seq):\n  for p in seq[index]:im.write(p['address'],base64.b64decode(p['data']))\n if address==0x7418c0:return declarations['resolve'](im,dict(flags=args[0]))\n if address==0x744b70:\n  global lastToken\n  lastToken=tokenValue(im,args);tokens.append(lastToken);return lastToken\n if address==COMPILE:\n  global firstProgram\n  program=args[11];slot=args[12];im.W(program,slot);im.W(program+4,0);im.W(program+8,lastToken)\n  if index==0:firstProgram=program\n  elif case.get('mutateFirst',False):im.H(firstProgram,111)\n  return 1\n if address in [PREP,0x7510b8,0x7510b4]:return 0\n values=case['responses'].get(key,[0]);return values[min(index,len(values)-1)]\ndef channel(im,at):\n f=F(im.W(at));t=f*255\n if not __import__('math').isfinite(t):return 0\n value=int(t);return value&255 if -2147483648<=value<2147483648 else 0\nctx=dict(rot=rot,N=N,U=U,F=F,struct=struct,S=S,S16=S16,S8=S8,base64=base64)\np=Path(__file__).with_name('world-phase86-20261013-verify.py');tree=ast.parse(p.read_text());node=next(x for x in tree.body if isinstance(x,ast.FunctionDef) and x.name=='invoke');exec(compile(ast.Module(body=[node],type_ignores=[]),str(p),'exec'),ctx);leafService=service;ctx['port']=leafService\ndef loader(num):\n p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);tree=ast.parse(p.read_text());selected=ast.Module(body=[x for x in tree.body if isinstance(x,ast.FunctionDef)],type_ignores=[]);env=dict(ctx,__file__=str(p));exec(compile(selected,str(p),'exec'),env);return env\ndeclarations=loader(98);declarations['CACHE']=0x297cc78\ndef declarationPort(im,target,device,pointer,output,data):\n trace.append([target,[device,pointer,output],base64.b64encode(data).decode()])\n if case['declarationWrites']:im.W(output,case['declarationHandle'])\n for p in case.get('declarationMutations',[]):im.write(p['address'],base64.b64decode(p['data']))\n return case['declarationStatus']\ndeclarations['port']=declarationPort\nDECL_TARGET=PREP+0x600;DECL_DEVICE=D+0xa000;DECL_TABLE=D+0xb000\ndef declarationBytes(p):\n data=bytearray()\n for i in range(32):\n  b=n.read(p+i*8,8);data.extend(b)\n  if struct.unpack_from('<H',b)[0]==255:return bytes(data)\n raise ValueError('missingboundeddeclarationterminator')\ndescriptor=loader(95);descriptor.update(pred=loader(94),TABLE=0x297d698);crc=loader(93);crc['TABLE']=0x297d698\nclass KeyImage:\n def __init__(self,im,words):self.im=im;self.words=words\n def W(self,a,v=None):\n  if 0x10310000<=a<0x10310024:assert v is None;return self.words[(a-0x10310000)//4]\n  return self.im.W(a,v)\n def B(self,a,v=None):return self.im.B(a,v)\n def read(self,a,z):return self.im.read(a,z)\n def write(self,a,v):return self.im.write(a,v)\ndef tokenValue(im,values):\n descriptor['case']=case;descriptor['port']=leafService;wrapper=KeyImage(im,values[:9]);blob=descriptor['blob'](wrapper,dict(key=0x10310000,force=values[9]));return (descriptor['crcValues'](im,blob,True)<<16)|descriptor['crcValues'](im,blob,False)\nshaderKey=loader(89);slot=loader(90);slot['service']=leafService\np=Path(__file__).with_name('world-phase90-20261013-verify.py');ts=p.read_text();tt=ast.parse(ts);body=ast.get_source_segment(ts,next(x for x in tt.body if isinstance(x,ast.FunctionDef) and x.name=='select'));body=body.replace('if not found:return 0','if not found:return (0,None)').replace('im.W(out,selected);return p','return (p,selected)');exec(compile(body,str(p),'exec'),slot)\ndef factory(im,args):\n manager,runtime,material,mode,fourth,fifth=args;target=im.W(im.W(manager)+8);leafService(im,target,[manager,runtime,material]);key=shaderKey['values'](im,dict(args=[0,runtime,material,mode,fourth]));token=leafService(im,0x744b70,key+[int((fifth&255)!=0)])\n for i in range(400):\n  if im.W(manager+i*0x4d8+12)!=token:continue\n  p=U(manager+i*0x4d8+4)\n  if p:im.W(p+4,U(im.W(p+4)+1));return p\n  break\n p,index=slot['select'](im,manager,0);index=runtime if not p else index;target=im.W(im.W(manager)+4);rv=leafService(im,target,[manager]+key+[fifth,p,U(index)])\n if not rv&255:return 0\n im.W(p+4,U(im.W(p+4)+1));return p\n# Platformwrapper import is guarded bytoken1..12.\ndef platform(im,address,args):\n token=args[0]\n if U(token-1)<=11:leafService(im,0x7510b8 if address==0x4ffaa0 else 0x7510b4,[0x91ef70+token*24])\n return 0\nclosed=[0x741620,0x7415b0,0x741770,0x741790,0x6e27d0,0x6e27f0,0x6df300,0x6df310]\ndef service(im,address,args):\n if address==0x7416a0:return factory(im,args)\n if address in [0x4ffaa0,0x4ffac0]:return platform(im,address,args)\n return ctx['invoke'](im,address,args) if address in closed else leafService(im,address,args)\nctx['port']=service\ndef refresh(im,c):\n m=c['material'];service(im,0x6df300,[]);count=S16(im.H(m+0x74))\n if count>0:\n  im.W(m+0xb8,count)\n  if im.B(m+0x15c)==0:im.B(m+0x15c,1)\n  b=im.W(m+0x1f0)\n  if b&0x3800==0:im.W(m+0x1f0,(b&0xffffcfff)|0x800)\n if im.W(m+0x44)&0x800000 and not im.W(m+0x3c):im.W(m+0x1f0,im.W(m+0x1f0)|0x40000)\n old=S16(im.H(m+0x1f4))\n if old>0:p=service(im,0x741620,[old]);service(im,0x7415b0,[p])\n old=S16(im.H(m+0x1f6))\n if old>0:p=service(im,0x741620,[old]);service(im,0x7415b0,[p])\n if im.W(m+0x44)&0x800000 and not im.W(m+0x3c):p=service(im,0x741770,[m+0xb4,m]);im.H(m+0x1f4,im.H(p))\n else:\n  mode=service(im,0x6e27d0,[0x29765c8]);a=service(im,0x741790,[m+0xb4,m,mode]);mode=service(im,0x6e27f0,[0x29765c8]);b=service(im,0x741790,[m+0xb4,m,mode]);im.H(m+0x1f4,im.H(a));im.H(m+0x1f6,im.H(b))\n declaration=service(im,0x7418c0,[im.W(m+0x1f0)]);color=im.H(m+0x74)==0;im.W(m+0x2bc,declaration)\n if color:blue=channel(im,m+0x5c);green=channel(im,m+0x58);red=channel(im,m+0x54);im.W(m+0xc8,0xff000000|(blue<<16)|(green<<8)|red)\n service(im,0x6df310,[])\n",materialEnv)
materialObserveText="def observe(uc,a,z,user):\n if a in [0x601030,0x741620,0x7415b0,0x741770,0x741790,0x6e27d0,0x6e27f0,0x6df300,0x6df310,0x4ffaa0,0x4ffac0,0x7416a0,0x744320,0x7414c0,0x744010,0x7422d0,0x743930,0x744b70,0x744600,0x744430,0x7444b0,0x7445b0,0x7462f0,0x7462b0,0x7418c0,0x741860,0x6e4850,0x4ef660]:entries[hex(a)]=entries.get(hex(a),0)+1\n if a==0x7416f1:\n  global lastToken\n  sp=uc.reg_read(UC_X86_REG_ESP);lastToken=n.unpack('<I',sp+0x44)[0];tokens.append(lastToken);return\n if a==DECL_TARGET:\n  sp=uc.reg_read(UC_X86_REG_ESP);device,pointer,output=n.unpack('<3I',sp+4);rv=declarationPort(ni,a,device,0,output,declarationBytes(pointer));uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+16);return\n if a not in [PREP,COMPILE,IENTER,IEXIT]:return\n sp=uc.reg_read(UC_X86_REG_ESP)\n if a==PREP:args=[uc.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<2I',sp+4));cleanup=12;logical=a\n elif a==COMPILE:p,fifth,program,index=n.unpack('<4I',sp+4);args=[uc.reg_read(UC_X86_REG_ECX)]+list(n.unpack('<9I',p))+[fifth,program,index];cleanup=20;logical=a\n elif a in [IENTER,IEXIT]:args=list(n.unpack('<I',sp+4));cleanup=8;logical=0x7510b8 if a==IENTER else 0x7510b4\n elif a==0x7418c0:args=list(n.unpack('<I',sp+4));cleanup=4;logical=a\n else:out,p,flag=n.unpack('<3I',sp+4);args=list(n.unpack('<9I',p))+[flag];cleanup=4;logical=a\n rv=leafService(ni,logical,args)\n if a==0x744b70:n.write(out,struct.pack('<I',rv))\n uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+cleanup)\n"
materialCounts={}

trace=[];case={};desc['trace']=trace
def regionValues(im,args):
 region=args[0];selection=args[5]&65535
 if not im.W(region+0x6c) or S16(selection)==S(im.W(region+0xe0)):return 1
 for i in range(S(im.W(region+0xdc))):
  candidate=im.W(region+0x9c+i*4)
  if candidate and im.H(candidate+0x9e)==selection:
   v=visibility['sphere'](im,args[1:5],candidate)
   if v:return v
 return 0
def submitChild(im,address,args):
 if address==0x60b5d0:args=args[:4]+drawMatrix[:]+args[5:]
 return external(im,address,args)
def external(im,a,args):
 if a==0x6e5b90:
  allocator=args[4];target=im.W(im.W(allocator)+0x2c);value=external(im,target,[allocator]+args[:4]);im.W(0x297bea0,value);return value
 if a==0x601030:
  materialEnv.update(trace=trace,case=case,counts=materialCounts);materialEnv['refresh'](im,dict(material=args[0]));return 0
 if a==0x60c410:
  global drawMatrix
  drawMatrix=args[4:20];submission['case']=case;submission['trace']=trace;submission['service']=submitChild
  submission['submit'](im,dict(args=args[:4]+[0]+args[20:]));return 0
 if a==0x5d6170:return 0x9736e8
 if a==0x5da3b0:return regionValues(im,args)
 if a==0x5d4380:box['prepare'](im,dict(size=args[0]));return 0
 if a in [0x5d8400,0x5d8440]:
  global clockIndex
  q=case['counterSequence'][min(clockIndex,len(case['counterSequence'])-1)];c=dict(entry=a,args=args,counter=q,mutations=case.get('serviceWrites',{}).get('0x751110',[]));value,calls=profile['apply'](im,c);trace.extend(calls);clockIndex+=len(calls);return value or 0
 trace.append([a,args]);writes=case.get('serviceWrites',{}).get(hex(a),[])
 for x in writes:im.write(x['address'],base64.b64decode(x['data']))
 if a==ALLOC_TARGET:
  if case['allocatorWrites']:im.W(args[3],1)
  return case['allocatorResult']
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
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
entries={}
class NativeImage:
 def write(self,a,v):n.write(a,v)
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',a)[0]
  n.write(a,struct.pack('<I',U(v)))
 def H(self,a,v=None):
  if v is None:return n.unpack('<H',a)[0]
  n.write(a,struct.pack('<H',v&65535))
NI=NativeImage()
def observe(uc,a,z,user):
 if a in [0x685770,0x600260,0x657e70,0x656e50,0x6585a0,0x5becc0,0x5c0240,0x64ff80,0x5b4900,0x5b4c90,0x5ffd40,0x5d4380,0x5d8400,0x5d8440,0x4f3bd0,0x4f3bf0,0x4f3ca0,0x4ffb20,0x4ffb90,0x5da3b0,0x5d94a0,0x5d6170,0x60c410,0x5e4b00,0x5d60c0,0x5edd70,0x607cb0,0x607590,0x6034b0,0x5fcdf0,0x5fcef0,0x5fcf30,0x5fcf60,0x5fcfd0,0x6e6950,0x6e5b90]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [IMPORT,0x6042e0,0x5c0500,ALLOC_TARGET,0x60b5d0,0x6f040c,0x5f74a0]:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if a==ALLOC_TARGET:
  args=list(n.unpack('<5I',sp+4));rv=external(NI,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_ESP,sp+24);uc.reg_write(UC_X86_REG_EIP,ret);return
 if a==IMPORT:
  global clockIndex
  trace.append([0x751110,[]]);dest=n.unpack('<I',sp+4)[0];q=case['counterSequence'][min(clockIndex,len(case['counterSequence'])-1)];clockIndex+=1
  for p in case.get('serviceWrites',{}).get('0x751110',[]):n.write(p['address'],base64.b64decode(p['data']))
  n.write(dest,struct.pack('<2I',*q));uc.reg_write(UC_X86_REG_EAX,1);uc.reg_write(UC_X86_REG_ESP,sp+8);uc.reg_write(UC_X86_REG_EIP,ret);return
 if a==0x5c0500:
  dst,left,right=n.unpack('<3I',sp+4);values=list(n.unpack('<16I',left));camera(NI,values,right);n.write(dst,struct.pack('<16I',*values));result=dst
 else:
  if a==0x5d8400:args=list(n.unpack('<3I',sp+4))
  elif a==0x5d8440:args=list(n.unpack('<2I',sp+4))
  elif a==0x5da3b0:
   obj,p,radius,region=n.unpack('<4I',sp+4);args=[obj]+list(n.unpack('<3I',p))+[radius,region]
  elif a==0x6042e0:
   lo,hi,e,aa,bb=n.unpack('<5I',sp+4);args=list(n.unpack('<3I',lo))+list(n.unpack('<3I',hi))+[e,aa,bb]
  elif a==0x60b5d0:
   raw=list(n.unpack('<10I',sp+4));args=raw[:4]+list(n.unpack('<16I',raw[4]))+raw[5:]
  elif a==0x601030:args=list(n.unpack('<I',sp+4))
  elif a==0x607590:args=list(n.unpack('<2I',sp+4))
  elif a==0x6e5b90:args=list(n.unpack('<5I',sp+4))
  elif a==0x5d4380:args=[n.unpack('<I',sp+4)[0]]
  else:args=[]
  result=external(NI,a,args)
 uc.reg_write(UC_X86_REG_EAX,U(result));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
IMPORT=0x10308000;n.mu.mem_map(IMPORT,0x1000);n.write(IMPORT,b'\xc3');n.write(0x751110,struct.pack('<I',IMPORT));n.mu.hook_add(UC_HOOK_CODE,observe)
materialEnv.update(UC_X86_REG_ESP=UC_X86_REG_ESP,UC_X86_REG_EIP=UC_X86_REG_EIP,UC_X86_REG_EAX=UC_X86_REG_EAX,UC_X86_REG_ECX=UC_X86_REG_ECX,ni=NI,declarationBytes=lambda pointer:b''.join(n.read(pointer+i*8,8) for i in range(32) if True))
# Capture through the first declaration terminator, retaining byte order.
def declarationBytes(pointer):
 data=bytearray()
 for i in range(32):
  b=n.read(pointer+i*8,8);data.extend(b)
  if struct.unpack_from('<H',b)[0]==255:return bytes(data)
 raise ValueError('declarationterminatormissing')
materialEnv['declarationBytes']=declarationBytes
exec(materialObserveText,materialEnv);n.mu.hook_add(UC_HOOK_CODE,materialEnv['observe'])
identity=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]
baseSeed=seed
def frame(bank=0,owner=True,typ=0,published=True,matched=False):
 c=baseSeed(0,0,0,0);c.update(bank=bank,visibility=1,bounds=1);c['writes'] += [patch(0x9736e8,struct.pack('<16f',*identity)),patch(0x97acd0,struct.pack('<16f',*identity)),word(0x96e53c,0),word(0x2962050,0),word(0x296204c,0),word(0x810904,0xffffffff),word(0x810968,bits(1)),word(0x8109d4,ENV),word(ENV,0),word(0x2962928,0),word(0x2962080,0),word(0x2962064,bits(9)),word(0x2962068,bits(19)),word(0x29620c4,0),half(0x29620b0,17),word(0x292fd68,MATERIAL),word(0x292fd30 if bank==0 else 0x292fd40,PACKETS),word(PACKETS,D+0x20000),word(PACKETS+4,R),word(PACKETS+8,EM if owner else 0),word(PACKETS+0x58,0),word(PACKETS+0x5c,0),patch(PACKETS+12,struct.pack('<16f',*identity)),patch(PACKETS+0x4c,struct.pack('<3f',1.25,-2.5,3.75)),byte(R+0x2e,typ),byte(R+0x12,0),byte(R+0x2f3,0),byte(R+0x412,0),word(R+0x3c,0),word(R+0x44,bits(.5)),word(R+0x140,bits(.25)),word(R+0x144,bits(.75)),word(R+0x2a8,DESC if published else 0),word(R+0x2ac,0),byte(EM+0x2f7,1),byte(EM+0x2fa,0),word(EM+0x2d4,0xffffffff),word(EM+0x2fc,0),half(EM+0x2f2,65535),word(EM+0x300,0),word(EM+0x31c,bits(3)),patch(EM+0x40,struct.pack('<16f',*identity)),patch(EM+0x80,struct.pack('<16f',*identity)),patch(EM+0x190,struct.pack('<3f',1.25,-2.5,3.75)),patch(CAMERA,struct.pack('<16f',*identity)),word(R+0x1c,bits(1)),word(R+0x20,bits(2))]
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
  elif gate=='begin':c['serviceWrites']={'0x751110':[half(0x29620b0,123)]}
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
for bank in [0,4]:
 for mode in [0,1]:
  for sizes in [(0,0,0),(1,2,3),(-1,-2,-3)]:
   c=frame(bank);c['writes'] += [byte(R+0x2f3,1),word(0x96e53c,mode),patch(R+0x2f8,struct.pack('<3f',*sizes))];cases.append(c)
# Real profiling records and clock state for the original slot12 caller.
for c in cases:
 c['counterSequence']=[[100,0],[200,0]];c['writes'] += [word(0x97396c,1),word(0x9716a4,PROFILE),word(0x9209e0,0),word(0x9209e4,0),word(0x91ef80,1000000),word(0x91ef84,0),word(PROFILE+0x10,PTICKS),word(PROFILE+0x20,PMODES),word(PROFILE+0x24,PLABEL),patch(PTICKS,bytes(128)),patch(PMODES,bytes(64))]
 for i in range(4):c['writes'] += [word(PROFILE+i*4,PROFILE+0x400+i*0x100),patch(PROFILE+0x400+i*0x100,bytes(64))]
for i in range(4):
 import copy
 c=copy.deepcopy(cases[0]);c['writes'] += [word(PMODES+48,i)];cases.append(c)
for q in [[[0xffffffff,0xffffffff],[0,0]],[[0,0],[0,0]],[[0,0x7fffffff],[1,0x80000000]]]:
 import copy
 c=copy.deepcopy(cases[0]);c['counterSequence']=q;cases.append(c)
VREGION=D+0x60000;VCAND=D+0x60400;VPLANES=D+0x60800
for c in cases:
 c['writes'] += [word(VREGION+0x6c,1),word(VREGION+0xe0,0),word(VREGION+0xdc,1),word(VREGION+0x9c,VCAND),half(VCAND+0x9c,0),half(VCAND+0x9e,2),word(VCAND+0x80,VPLANES),patch(0x963f78,struct.pack('<4f',0,0,0,-100000 if c.get('visibility')==0 else 100000))]
import copy
for count in [-1,0,1,2]:
 for offset in [-100000,0,100000]:
  c=copy.deepcopy(cases[16]);c['writes'] += [word(EM+0x2fc,VREGION),half(EM+0x2f2,2),half(VCAND+0x9c,count),patch(0x963f78,struct.pack('<4f',0,0,0,offset)),patch(VPLANES,struct.pack('<8f',1,0,0,0,0,1,0,0))];cases.append(c)
SOWNER=D+0x7d000;SROOT=D+0x7d400;SMASK=D+0x7d800;SCURSOR=D+0x7dc00;SARENA=D+0x6d000;SPREV=D+0x6cf00;SGEO=D+0x6ce00
for c in cases:
 c['writes'] += [word(0x9736e0,SCURSOR),word(SCURSOR,SARENA),word(0x2854d08,0),word(0x2854d00,1),word(0x2854cec,2),word(0x2854cf0,3),word(0x2854cf4,4),word(0x2854cf8,5),word(0x280d3cc+12,6),patch(0x80b708,struct.pack('<12f',1,0,0,0,0,1,0,0,0,0,1,0)),word(SOWNER,SROOT),word(SOWNER+4,7),word(SROOT+0x74,0),word(SROOT+0x58,SMASK),word(SROOT+0x5c,SMASK+0x100),word(SOWNER+0x14,SPREV),word(SOWNER+0x18,SGEO),byte(D+0x20000,0x52),word(D+0x20000+4,0),byte(D+0x20400,0x52),word(D+0x20400+4,0)]
 for i in range(8):c['writes'] += [word(MATERIAL+i*0x100+0x3c,SOWNER),word(MATERIAL+i*0x100+0x40,0x60000),byte(MATERIAL+i*0x100+0x99,0),half(MATERIAL+i*0x100+0x2c0,0)]
 if '0x60c410' in c.get('serviceWrites',{}):c['serviceWrites']['0x60b5d0']=c['serviceWrites'].pop('0x60c410')
SCONTEXT=D+0x7de00;SDESC=D+0x7df00;SSOURCE=D+0x7df40
for c in cases:
 c['writes'] += [word(SOWNER+8,SCONTEXT),patch(SCONTEXT,bytes(0x40)),word(0x9868a0+0x20,1),word(0x9868a0+0xf4,1),word(0x9868a0+0x16c,1),word(0x9738a4,SDESC),byte(SDESC,3),byte(SDESC+2,7),word(SDESC+4,SSOURCE),patch(SSOURCE,bytes([1,128,255])),word(0x297dc00,0x12345678)]
 for i,key in enumerate([0x24,0x2c,0x2e,0x1e,0x32,0x30]):c['writes'] += [half(0x9868a0+key,i+1)]

rot['common'] += [word(PROGRAMS,VTABLE),word(VTABLE+8,PREP),word(VTABLE+4,COMPILE),word(PROGRAMS+0x79184,0xffffffff),word(0x297cc6c,PROGRAMS),word(0x297ae20,0),word(0x297cc70,0),word(0x29765cc,DECL_DEVICE),word(DECL_DEVICE,DECL_TABLE),word(DECL_TABLE+0x158,DECL_TARGET),word(0x2974d1c,2)]
for i in range(400):rot['common'] += [word(PROGRAMS+i*0x4d8+8,0),word(PROGRAMS+i*0x4d8+12,0xffffffff),word(PROGRAMS+i*0x4d8+4+0x4cc,0),word(PROGRAMS+i*0x4d8+4+0x4d0,0)]
for c in cases:
 c.update(responses={},declarationHandle=0x09090909,declarationStatus=0,declarationWrites=True)
 # Preserve eight material pointers and their existing owner; prepare overlapping physical records before setting fields.
 for i in range(8):c['writes'] += [patch(MATERIAL+i*0x100,bytes(0x300))]
 for i in range(8):c['writes'] += [word(MATERIAL+i*0x100+0x3c,SOWNER),word(MATERIAL+i*0x100+0x40,0),word(MATERIAL+i*0x100+0x1f0,0x0c000000),half(MATERIAL+i*0x100+0x1f4,0),half(MATERIAL+i*0x100+0x1f6,0),patch(MATERIAL+i*0x100+0x54,struct.pack('<3f',.25,.5,.75)),half(MATERIAL+i*0x100+0x74,0),byte(MATERIAL+i*0x100+0x99,0),half(MATERIAL+i*0x100+0x2c0,0)]
# Returned failure does not roll back declaration publication; prepared out-pointer mutations affect later submission.
for status in [0,0x80004005,0xffffffff]:
 c=copy.deepcopy(cases[0]);c['declarationStatus']=status;c['declarationWrites']=False;cases.append(c)
for field in [0x1f0,0x1f4,0x1f6]:
 c=copy.deepcopy(cases[0]);c['declarationMutations']=[word(MATERIAL+field,0)];cases.append(c)


ALLOC=D+0x7f800;ALLOC_TABLE=D+0x7fa00;ALLOC_TARGET=PREP+0x700;REDIRECT_COMMAND=D+0x7fb00
n.write(ALLOC_TARGET,b'\xc3')
for c in cases:
 c.update(allocatorResult=0x80004005,allocatorWrites=True)
 c['writes'] += [word(0x2854d00,0),word(0x280d3cc+12,ALLOC),word(ALLOC,ALLOC_TABLE),word(ALLOC_TABLE+0x2c,ALLOC_TARGET)]
for status in [0,1,0xffffffff,0x7fffffff]:
 c=copy.deepcopy(cases[0]);c['allocatorResult']=status;cases.append(c)
for at in [ALLOC,ALLOC_TABLE+0x2c,0x2854d00,0x297bea0]:
 c=copy.deepcopy(cases[0]);c['serviceWrites']={hex(ALLOC_TARGET):[word(at,0x12345678)]};cases.append(c)
c=copy.deepcopy(cases[0]);c['serviceWrites']={hex(ALLOC_TARGET):[word(0x2854d04,REDIRECT_COMMAND),patch(REDIRECT_COMMAND,bytes(0x20)),word(REDIRECT_COMMAND+0x10,MATERIAL)]};cases.append(c)

rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 assert n.call(0x5d6170)==0x9736e8
 case=c;trace=[];clockIndex=0;materialCounts={};materialEnv.update(trace=trace,case=case,counts=materialCounts,tokens=[],lastToken=0);desc['trace']=trace;im=Image(c);materialEnv['crc']['initialize'](im,dict(receiver=0))
 try:render(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 modelTrace=trace[:];modelTokens=materialEnv['tokens'][:];trace=[];clockIndex=0;materialCounts={};materialEnv.update(trace=trace,case=case,counts=materialCounts,tokens=[],lastToken=0);initial=Image(c);materialEnv['crc']['initialize'](initial,dict(receiver=0))
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x685770,[0,c['bank']],count=10000000)
 except Exception as ex:errors.append(dict(case=i,nativeError=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=modelTrace or materialEnv['tokens']!=modelTokens:
  errors.append(dict(case=i,actual=actual,model=im.hash(),nativeTrace=trace,modelTrace=modelTrace))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]))
  break
 c['expected']=dict(sha256=actual,trace=trace,tokens=materialEnv['tokens']);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*4,mismatches=len(errors),errors=errors[:8],entries=dict(entries,**materialEnv['entries']),binarySha256=n.sha256,nativeAdapters=['imported QueryPerformanceCounter751110','6042e0 dynamic box query','5c0500 imported D3DX mutable matrix policy','allocatorvtable+2c value/mutation port','60b5d0 deepGPUdraw','6f040c TLS context','5f74a0 descriptor capacity failure'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase101-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase101-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],cameraPointer=CAMERA,tlsContext=TLS,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
