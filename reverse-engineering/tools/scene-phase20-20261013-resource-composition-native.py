"""Original resource caller and mesh CPU body. Only named resource/COM/file edges adapted."""
import importlib.util,struct,json,gzip,random,copy,ast
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase20-20261013-resource-composition'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');n=nx.NativeX86();x=load('x','animation-x87.py');W=x.wide;A=x.add;M=x.mul;D=x.div;S=x.store
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
B=0x29765c8;CACHE=0x297bea0;SET=0x826070;POOL=0x986f00;SCREEN=0x973900;CONFIG=0x2974d1c;DEV=n.DATA+0x3000;DVT=n.DATA+0x4000;OVT=n.DATA+0x21000;BVT=n.DATA+0x22000;TVT=n.DATA+0x23000;SP=n.STACK+0xe000
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def i32(v):return (v+0x80000000)%0x100000000-0x80000000
def word(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def sub(a,b):return A(a,M(b,W(-1)))
def trunc(a):return (abs(a[0])<<a[1] if a[1]>=0 else abs(a[0])>>-a[1])*(-1 if a[0]<0 else 1)
EDGES={};COUNTS={}
for j,(kind,off,count) in enumerate([('device',0x48,4),('device',0xa0,1),('device',0x68,6),('device',0x6c,6),('object',8,0),('object',0x2c,4),('object',0x30,0),('texture',0x48,2),('device',0x5c,8),('device',0x74,8),('texture',0x34,0)]):
 edge=n.STOP+0x100+j*0x40;EDGES[edge]=(kind,off);COUNTS[edge]=count;vt=DVT if kind=='device'else TVT if kind=='texture'else BVT if off!=8 else OVT;n.pack('<I',vt+off,edge)
for edge,kind,count in [(0x6e8b9e,'settings-open',2)]:EDGES[edge]=(kind,0);COUNTS[edge]=count
n.pack('<I',DEV,DVT)
releaseEdge=next(k for k,v in EDGES.items()if v==('object',8))
n.pack('<I',BVT+8,releaseEdge);n.pack('<I',TVT+8,releaseEdge)
USED=0x280d7e0;ACCOUNT=0x2854bc0
for j in range(24):n.pack('<I',n.DATA+0x10000+j*0x40,OVT)
for j in range(4):n.pack('<I',n.DATA+0x12000+j*0x100,BVT)
for j in range(32):n.pack('<I',n.DATA+0x18000+j*0x40,TVT)
case=0;registry=[];events=[];checks=0;errors=[];fixtures=[]
visited={}
def entryHook(mu,address,size,_):visited[hex(address)]=visited.get(hex(address),0)+1
for a in ["0x6e2d20","0x6e2170","0x5f7b40","0x605800","0x605890","0x5f81f0","0x5f7980","0x5f79e0","0x6e47d0","0x6e46b0","0x6e2130","0x6e2610","0x6e4810","0x6e46f0","0x6e5b90","0x6e5bc0","0x6e5bd0","0x6e5c00"]:n.mu.hook_add(UC_HOOK_CODE,entryHook,begin=int(a,16),end=int(a,16))
def encode(s):return {'backendHex':s['backend'].hex(),'cacheHex':s['cache'].hex(),'settingsHex':s['settings'].hex(),'poolHex':s['pool'].hex(),'screen':s['screen'][:],'configuration':s['configuration'],'usedHex':s['used'].hex(),'account':s['account'],'buffers':[{'handle':z['handle'],'token':z['token'],'size':z['size'],'hex':z['data'].hex()}for z in s['buffers']]}
def decode(t):return {'backend':bytearray.fromhex(t['backendHex']),'cache':bytearray.fromhex(t['cacheHex']),'settings':bytearray.fromhex(t['settingsHex']),'pool':bytearray.fromhex(t['poolHex']),'screen':t['screen'][:],'configuration':t['configuration'],'used':bytearray.fromhex(t['usedHex']),'account':t['account'],'buffers':[dict(z,data=bytearray.fromhex(z['hex']))for z in t['buffers']]}
def snapshot():return {'backend':bytearray(n.read(B,0x800)),'cache':bytearray(n.read(CACHE,0x300)),'settings':bytearray(n.read(SET,0x460)),'pool':bytearray(n.read(POOL,0x600)),'screen':list(n.unpack('<2i',SCREEN)),'configuration':n.unpack('<i',CONFIG)[0],'used':bytearray(n.read(USED,32)),'account':n.unpack('<I',ACCOUNT)[0],'buffers':[dict(z,data=bytearray(n.read(z['token']-16,z['size']+32)))for z in registry]}
def upload(s):
 for key,address in [('backend',B),('cache',CACHE),('settings',SET),('pool',POOL)]:n.write(address,s[key])
 n.pack('<2i',SCREEN,*s['screen']);n.pack('<i',CONFIG,s['configuration']);n.write(USED,s['used']);n.pack('<I',ACCOUNT,s['account'])
 for z in s['buffers']:n.write(z['token']-16,z['data'])
def service(s,kind,receiver,off,args,out):
 if kind=='texture-free':return freeModel(s,args[0],args[0],out),None
 if kind in ['texture-create','texture-format']:
  b=s['backend'];fmt=reverse.get(u(b,0x140),0)if kind=='texture-create'else args[2];height=u(b,0x13c)//args[0];width=u(b,0x138)//args[0];slot=next(j for j in range(32)if s['used'][j]==0);s['used'][slot]=1;owner=POOL+slot*48;initModel(s,[owner,width,height,args[1],1,0,fmt],out);at=slot*48;w(s['pool'],at+0x20,(u(s['pool'],at+0x20)&0xffffdbff)|0x1b00);return owner,None
 index=len(out);out.append({'kind':kind,'receiver':receiver,'offset':off,'arguments':args[:],'before':encode(s)})
 result=(0x80004005 if (case+index)%3==0 else (case*0x103+index*17))&0xffffffff;output=None
 if kind=='device':
  if off in [0x48,0xa0]:output=n.DATA+0x10000+(20 if off==0x48 else 21)*0x40;w(s['backend'],args[-1]-B,output)
  elif off in [0x5c,0x74]:
   output=n.DATA+0x18000+((args[6]-POOL)//48)*0x40;w(s['pool'],args[6]-POOL,output)
  elif off in [0x68,0x6c]:
   j=len(s['buffers']);handle=n.DATA+0x12000+j*0x100;token=n.DATA+0x40000+j*0x10000+16;size=args[0];assert size<0xff00
   s['buffers'].append({'handle':handle,'token':token,'size':size,'data':bytearray([0xa7])*(size+32)});w(s['backend'],args[4]-B,handle)
   if j==0 and case%4==0:w(s['backend'],0x138,0x12345678) # rectangle already captured
 elif kind=='object':
  if off==8 and case%5==0:
   for at in [0x6b0,0x6ec,0x690,0x694,0x698,0x688,0x6c4,0x6c8,0x6cc,0x6d0]:
    if u(s['backend'],at)==receiver:w(s['backend'],at,0xbad00bad);break
  if off==0x2c:output=next(z['token']for z in s['buffers']if z['handle']==receiver)
  if off==0x30 and receiver==n.DATA+0x12100 and case%4==1:s['screen']=[320,320+case%17*20]
 elif kind in ['texture-create','texture-format']:
  j=sum(z['kind']in ['texture-create','texture-format']for z in out)-1;output=POOL+j*48;w(s['pool'],j*48,n.DATA+0x18000+j*0x40);result=output
 elif kind=='texture':
  if off==0x34:
   result=[1,2,0x10001,0xffff][case%4]
   if case%4==2:
    slot=(receiver-n.DATA-0x18000)//0x40;struct.pack_into('<2H',s['pool'],slot*48+4,65535,65535);s['account']=(s['account']+0x80000000)&0xffffffff
  else:output=n.DATA+0x10000+(16+((args[1]-B-0x6c4)//4))*0x40;w(s['backend'],args[1]-B,output)
 elif kind=='settings-open':result=0
 return result,output

def hook(mu,address,size,_):
 global registry
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];kind,off=EDGES[address];count=COUNTS[address];com=kind in ['device','object','texture'];receiver=n.unpack('<I',sp+4)[0]if com else 0;args=list(n.unpack('<'+str(count)+'I',sp+(8 if com else 4)))if count else []
 s=snapshot();result,output=service(s,kind,receiver,off,args,events);upload(s);registry=[{k:z[k]for k in ['handle','token','size']}for z in s['buffers']]
 if kind=='object'and off==0x2c:n.pack('<I',args[2],output)
 mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+4+(count+1)*4 if com else sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for edge in EDGES:n.mu.hook_add(UC_HOOK_CODE,hook,begin=edge,end=edge)
def modelFeatures(s,out):
 b=s['backend'];p=s['settings'];c=s['configuration'];w(p,0x44c,u(p,0x450));w(p,0x440,u(p,0x444));p[0x455]=1;w(p,0x44c,1 if p[0x457]==0 else 2)
 if c<2:
  if p[0x454]and i32(u(p,0x44c))>1:w(p,0x44c,1)
  if p[0x448]and i32(u(p,0x440))>1:w(p,0x440,1)
 if c<=2 and p[0x454]and i32(u(p,0x44c))>1:w(p,0x44c,1)
 if u(b,0x638):
  if p[0x454]and i32(u(p,0x44c))>1:w(p,0x44c,0)
  if p[0x448]and i32(u(p,0x440))>1:w(p,0x440,1)
 mask,types=(0x21,0x13)if u(p,0x44c)==2 else(1,1)
 if u(p,0x440):mask|=4
 if u(p,0x440)==2:types|=2
 if p[0x455]:mask|=0x80
 w(b,0x654,mask);w(b,0x658,types);k=0
 for enabled,t in [(u(b,0x638)==0,0),(types&2,1),(types&4,2),(types&0x10,3)]:
  if enabled:w(b,0x6d4+k*4,t);k+=1
 struct.pack_into('<H',b,0x66c,k);return service(s,'settings-open',0,0,[0x826074,0x76f4d8],out)[0]
def model(s,out):
 b=s['backend'];cache=s['cache']
 def call(kind,off,args,receiver=0):return service(s,kind,u(b,4)if kind=='device'else receiver,off,args,out)
 def release(at):
  token=u(b,at)
  if token:call('object',8,[],token);w(b,at,0)
 def create(at,size,index=False):
  args=[size,8|(0x10 if s['configuration']==0 else 0),0x65 if index else 0,0,B+at,0];r,_=call('device',0x6c if index else 0x68,args);w(cache,0,r)
 def lock(at,size):
  r,t=call('object',0x2c,[0,size,SP-0x94,0],u(b,at));w(cache,0,r);return next(z for z in s['buffers']if z['token']==t)
 def unlock(at):return call('object',0x30,[],u(b,at))[0]
 for at in [0x6b0,0x6ec,0x690,0x694,0x698,0x688]:release(at)
 call('device',0x48,[0,0,0,B+0x6b0]);call('device',0xa0,[B+0x6ec]);modelFeatures(s,out)
 for j in range(4):release(0x6c4+j*4);call('texture-free',0,[u(b,0x6b4+j*4)]);w(b,0x6b4+j*4,0);w(b,0x6f0+j*4,0)
 count=min(struct.unpack_from('<H',b,0x66c)[0],4);struct.pack_into('<H',b,0x6e4,count)
 for j in range(count):
  t=u(b,0x6d4+j*4)
  if t in [0,1]:w(b,0x6b4+j*4,call('texture-create',0,[1,1])[0])
  elif t==3:w(b,0x6b4+j*4,call('texture-format',0,[1,1,10])[0])
  owner=u(b,0x6b4+j*4)
  if owner:call('texture',0x48,[0,B+0x6c4+j*4],u(s['pool'],owner-POOL))
 quad=[0xbf800000,0x3f800000,0,0,0,0xbf800000,0xbf800000,0,0,0x3f800000,0x3f800000,0x3f800000,0,0x3f800000,0,0x3f800000,0xbf800000,0,0x3f800000,0x3f800000]
 rectangle=[0,0,0,0,0,word(S(M(W(u(b,0x13c)),W(3)))),0,0x40400000,word(S(M(W(u(b,0x138)),W(3)))),0,0x40400000,0]
 create(0x690,80);create(0x688,48)
 for at,packet in [(0x690,quad),(0x688,rectangle)]:z=lock(at,len(packet)*4);struct.pack_into('<'+str(len(packet))+'I',z['data'],16,*packet);unlock(at)
 w(b,0x6a0,16);rows=trunc(M(D(W(s['screen'][1]),W(s['screen'][0])),W(16)));assert 1<=rows<=128;w(b,0x69c,rows);w(b,0x6a4,(rows+1)*17);w(b,0x6a8,rows*32);create(0x694,u(b,0x6a4)*20);create(0x698,u(b,0x6a8)*6,True)
 z=lock(0x694,u(b,0x6a4)*20);at=16;rows=u(b,0x69c);cols=u(b,0x6a0)
 for row in range(rows+1):
  rf=S(W(row))
  for col in range(cols+1):
   cf=S(W(col));xx=D(W(cf),W(cols));yy=D(W(rf),W(rows));words=[word(S(sub(M(xx,W(2)),W(1)))),word(S(sub(W(1),M(yy,W(2))))),0,word(S(xx)),word(S(yy))];struct.pack_into('<5I',z['data'],at,*words);at+=20
 unlock(0x694);z=lock(0x698,u(b,0x6a8)*6);at=16;rows=u(b,0x69c);cols=u(b,0x6a0)
 for row in range(rows):
  for col in range(cols):a=(cols+1)*row+col;c=(cols+1)*(row+1)+col;struct.pack_into('<6H',z['data'],at,*[v&0xffff for v in [a,a+1,c,c,a+1,c+1]]);at+=12
 return unlock(0x698)
def ck(actual,expected,label):
 global checks
 checks+=1
 if actual!=expected and len(errors)<12:errors.append({'case':case,'label':label,'native':actual,'model':expected})

# Load only the sealed pure CPU models, never their native test main bodies.
def pure(file,name,env):
 tree=ast.parse((P/file).read_text());nodes=[z for z in tree.body if isinstance(z,ast.FunctionDef)and z.name==name];exec(compile(ast.Module(body=nodes,type_ignores=[]),file,'exec'),env);return env[name]
reverse={21:2,22:2,75:4,83:5};forward={1:22,2:21,4:75,5:83,10:114};samples=[0,2,4,8,16]
def half(b,o):return struct.unpack_from('<H',b,o)[0]
def putHalf(b,o,v):struct.pack_into('<H',b,o,v&0xffff)
def finalCom(s,kind,args,out,receiver=None):
 r,_=service(s,'device'if kind!='levels'else'texture',u(s['backend'],4)if receiver is None else receiver,{'create':0x5c,'depth':0x74,'levels':0x34}[kind],args,out)
 if kind!='levels':w(s['cache'],0,r)
 return r
freeEnv={'POOL':POOL,'u':u,'w':w,'i32':i32,'struct':struct,'release':lambda s,token,out:service(s,'object',token,8,[],out)[0]}
freeModel=pure('scene-phase18-20261013-texture-ownership-native.py','model',freeEnv)
initEnv={'u':u,'w':w,'h':half,'ph':putHalf,'i32':i32,'samples':samples,'forward':forward,'POOL':POOL,'com':finalCom}
initModel=pure('scene-phase19-20261013-texture-allocation-native.py','initialize',initEnv)
def modelRelease(s,out):
 b=s['backend']
 def release(at):
  token=u(b,at)
  if token:service(s,'object',token,8,[],out);w(b,at,0)
 for at in [0x6b0,0x6ec,0x690,0x694,0x698,0x688]:release(at)
 for j in range(4):release(0x6c4+j*4);result=freeModel(s,u(b,0x6b4+j*4),u(b,0x6b4+j*4),out);w(b,0x6b4+j*4,0);w(b,0x6f0+j*4,0)
 return result

rng=random.Random(0x6e2d2020)
for case in range(256):
 registry=[];events=[];b=bytearray(rng.randbytes(0x800));cache=bytearray(rng.randbytes(0x300));settings=bytearray(rng.randbytes(0x460));pool=bytearray(rng.randbytes(0x600));w(b,4,DEV);w(b,0x138,[640,0xffffffff,0x80000000,1][case%4]);w(b,0x13c,[480,0x80000001,1,0xffffffff][case%4]);w(b,0x638,[0,1,4,2][case%4]);w(b,0x140,[21,22,83,114][case%4]);used=bytearray([0]*8+[255]*24)
 for j in range(8,12):w(pool,j*48,n.DATA+0x18000+j*0x40);w(pool,j*48+0x28,0);w(pool,j*48+0x2c,0xffffffff)
 for j,at in enumerate([0x6b0,0x6ec,0x690,0x694,0x698,0x688,0x6c4,0x6c8,0x6cc,0x6d0]):w(b,at,0 if (case+j)%3==0 else n.DATA+0x10000+j*0x40)
 for j in range(4):w(b,0x6b4+j*4,0 if (case+j)%2 else POOL+(j+8)*48)
 for at in [0x444,0x450]:w(settings,at,[0,1,2,3,0xffffffff,0x80000000,0x7fffffff][(case+at)%7])
 for at in [0x448,0x454,0x457]:settings[at]=[0,1,0xff][(case+at)%3]
 c=[-2147483648,-1,0,1,2,3,0x7fffffff][case%7];screen=[1024,[64,128,224,480,720,1024,2048,4096,8192][case%9]]
 initial={'backend':b,'cache':cache,'settings':settings,'pool':pool,'screen':screen,'configuration':c,'used':used,'account':rng.getrandbits(32),'buffers':[]};before=encode(initial);upload(initial)
 native=n.call(0x6e2d20,regs={UC_X86_REG_ECX:B},count=3000000);after=encode(snapshot());expected=decode(before);expectedEvents=[];result=model(expected,expectedEvents)
 ck(native,result,'return');ck(after,encode(expected),'full images and guarded buffers');ck(events,expectedEvents,'ordered boundary states and arguments');ck(n.mu.reg_read(UC_X86_REG_ESP),SP+4,'thiscall stack')
 fixtures.append({'kind':'build','before':before,'events':events,'after':after,'return':native})
 beforeRelease=after;events=[];nativeRelease=n.call(0x6e2170,regs={UC_X86_REG_ECX:B},count=300000);afterRelease=encode(snapshot());releaseState=decode(beforeRelease);releaseEvents=[];releaseResult=modelRelease(releaseState,releaseEvents);ck(nativeRelease,releaseResult,'release return');ck(afterRelease,encode(releaseState),'release full images');ck(events,releaseEvents,'release ordered final boundary states');ck(n.mu.reg_read(UC_X86_REG_ESP),SP+4,'release stack');fixtures.append({'kind':'release','before':beforeRelease,'events':events,'after':afterRelease,'return':nativeRelease})
report={'status':'passed'if not errors else'failed','binarySHA256':n.sha256,'cases':len(fixtures),'checks':checks,'failures':errors,'adaptedBoundaryEvents':sum(len(z['events'])for z in fixtures),'originalCPUEntries':sorted(visited),'entryVisits':visited,'scope':'Single shared backend/pool original build then release. Real texture allocation/free CPU graphs run unchanged; only final COM and settings fopen failure explicit. Resolved stable/disjoint buffers, rows1..128, available slots, sample index0..4, FPCW37f. No game, OS, managed program, or settings file launched/written.'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2))
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt')as f:json.dump({'report':report,'fixtures':fixtures},f,separators=(',',':'))
print(json.dumps({k:v for k,v in report.items()if k!='failures'},indent=2));print('failures',[(z['case'],z['label'])for z in errors]);raise SystemExit(bool(errors))
