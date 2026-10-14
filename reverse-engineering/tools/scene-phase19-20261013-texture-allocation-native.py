"""Original texture factory/initializer chain with only final COM adapted."""
import importlib.util,json,gzip,struct,random,copy
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase19-20261013-texture-allocation'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_FPCW
B=0x29765c8;CACHE=0x297bea0;POOL=0x986f00;USED=0x280d7e0;ACCOUNT=0x2854bc0;DEV=n.DATA+0x3000;DVT=n.DATA+0x4000;TEX=n.DATA+0x10000;TVT=n.DATA+0x20000
EDGES={n.STOP+0x100:('create',0x5c,8),n.STOP+0x180:('depth',0x74,8),n.STOP+0x200:('levels',0x34,0)}
n.pack('<I',DEV,DVT)
for j in range(4):n.pack('<I',TEX+j*0x100,TVT)
for edge,(kind,off,count)in EDGES.items():n.pack('<I',(TVT if kind=='levels'else DVT)+off,edge)
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def h(b,o):return struct.unpack_from('<H',b,o)[0]
def ph(b,o,v):struct.pack_into('<H',b,o,v&0xffff)
def i32(v):return ((v+0x80000000)&0xffffffff)-0x80000000
forward={1:22,2:21,4:75,5:83,10:114};reverse={21:2,22:2,75:4,83:5};samples=[0,2,4,8,16]
def snap():return {'backend':bytearray(n.read(B,0x800)),'cache':bytearray(n.read(CACHE,0x300)),'pool':bytearray(n.read(POOL,0x600)),'used':bytearray(n.read(USED,32)),'account':n.unpack('<I',ACCOUNT)[0]}
def enc(s):return dict({z+'Hex':s[z].hex()for z in ['backend','cache','pool','used']},account=s['account'])
def dec(s):return dict({z:bytearray.fromhex(s[z+'Hex'])for z in ['backend','cache','pool','used']},account=s['account'])
def seed(s):
 for z,at in [('backend',B),('cache',CACHE),('pool',POOL),('used',USED)]:n.write(at,s[z])
 n.pack('<I',ACCOUNT,s['account'])
case=0;plan={};events=[];checks=0;errors=[];fixtures=[]
def service(s,kind,receiver,args,out):
 out.append({'kind':kind,'receiver':receiver,'arguments':args[:],'before':enc(s)})
 at=plan['offset'];result=plan['levelWord']if kind=='levels'else plan['return']
 if kind in ['create','depth']:w(s['pool'],args[6]-POOL,0 if plan['null']else TEX+(case%4)*0x100)
 for o,v in plan['words']:w(s['pool'],at+o,v)
 for o,v in plan['halves']:ph(s['pool'],at+o,v)
 for o,v in plan['backend']:w(s['backend'],o,v)
 w(s['cache'],0,plan['cacheWord']);s['account']=plan['account'];return result

def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];kind,off,count=EDGES[address];receiver=n.unpack('<I',sp+4)[0];args=list(n.unpack('<'+str(count)+'I',sp+8))if count else [];state=snap();result=service(state,kind,receiver,args,events);seed(state);mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+4+(count+1)*4);mu.reg_write(UC_X86_REG_EIP,ret)
for edge in EDGES:n.mu.hook_add(UC_HOOK_CODE,hook,begin=edge,end=edge)
def com(s,kind,args,out,receiver=None):
 r=service(s,kind,u(s['backend'],4)if receiver is None else receiver,args,out)
 if kind!='levels':w(s['cache'],0,r)
 return r

def initialize(s,args,out):
 owner,width,height,levels,render,pool,fmt=args;at=owner-POOL;p=s['pool'];b=s['backend'];ph(p,at+4,width);ph(p,at+6,height);ph(p,at+10,levels);ph(p,at+12,levels);w(p,at+0x1c,pool);ph(p,at+8,0)
 for o,v in [(0x10,1),(0x14,fmt),(0x18,render),(0x2c,0xffffffff),(0x28,0),(0x24,0),(0x20,0x12449d0)]:w(p,at+o,v)
 if fmt==4:
  w(p,at+0x1c,0);ph(p,at+10,1);index=u(b,0x638);quality=u(b,0x640+index*4);com(s,'depth',[h(p,at+4),h(p,at+6),75,samples[index],quality,0,owner+0x28,0],out);width=h(p,at+4);s['account']=(s['account']+width*h(p,at+6)*4)&0xffffffff;return width
 usage=(2 if fmt in [5,6,7]else 1)if u(p,at+0x18)==1 else 0;com(s,'create',[h(p,at+4),h(p,at+6),h(p,at+10),usage,forward.get(fmt,0xffffffff),u(p,at+0x1c),owner,0],out);token=u(p,at)
 if not token:return 0
 count=com(s,'levels',[],out,token);ph(p,at+10,count);area=i32(h(p,at+4)*h(p,at+6)*4);amount=int(area*(1 if count&0xffff==1 else 1.5));s['account']=(s['account']+amount)&0xffffffff;return 0xf7f

def model(s,kind,args,out):
 if kind=='initialize':return initialize(s,args,out)
 if kind in ['create','depth']:return com(s,kind,args,out)
 if kind=='multisample':return samples[u(s['backend'],0x638)]
 divisor,levels=args[:2];fmt=reverse.get(u(s['backend'],0x140),0)if kind=='default'else args[2];height=u(s['backend'],0x13c)//divisor;width=u(s['backend'],0x138)//divisor;slot=next(j for j in range(32)if s['used'][j]==0);s['used'][slot]=1;owner=POOL+slot*48;initialize(s,[owner,width,height,levels,1,0,fmt],out);at=slot*48;w(s['pool'],at+0x20,(u(s['pool'],at+0x20)&0xffffdbff)|0x1b00);return owner

def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<12:errors.append({'case':case,'label':label,'native':a,'model':e})
rng=random.Random(0x5f81f019)
for case in range(1024):
 for kind,address in [('default',0x605800),('format',0x605890),('initialize',0x5f81f0),('create',0x6e47d0),('depth',0x6e46b0),('multisample',0x6e2130)]:
  b=bytearray(rng.randbytes(0x800));cache=bytearray(rng.randbytes(0x300));pool=bytearray(rng.randbytes(0x600));used=bytearray([rng.choice([1,255])for _ in range(32)]);slot=case%32;used[slot]=0;at=slot*48;owner=POOL+at;w(b,4,DEV);w(b,0x138,[640,0x80000001,0xffffffff,1][case%4]);w(b,0x13c,[480,0xffffffff,1,0x80000001][case%4]);w(b,0x638,case%5);w(b,0x140,[21,22,75,83,114,0,0xffffffff][case%7]);fmt=[0,1,2,3,4,5,6,7,10,0xffffffff][case%10];divisor=[1,2,3,0xffffffff][case%4];levels=rng.getrandbits(32)
  if kind=='default':args=[divisor,levels]
  elif kind=='format':args=[divisor,levels,fmt]
  elif kind=='initialize':args=[owner,rng.getrandbits(32),rng.getrandbits(32),levels,rng.choice([0,1,2,0xffffffff]),rng.getrandbits(32),fmt]
  elif kind=='create':args=[rng.getrandbits(32)for _ in range(6)]+[owner,0]
  elif kind=='depth':args=[rng.getrandbits(32)for _ in range(6)]+[owner+0x28,rng.getrandbits(32)]
  else:args=[]
  plan={'offset':at,'return':rng.getrandbits(32),'levelWord':[0,1,2,0x10001,0xffff,0xffffffff][case%6],'null':case%3==0,'words':[(0x20,rng.getrandbits(32))]if case%4==0 else [],'halves':[(4,65535),(6,65535)]if case%4==1 else [],'backend':[(0x138,rng.getrandbits(32)),(0x13c,rng.getrandbits(32))],'cacheWord':rng.getrandbits(32),'account':rng.getrandbits(32)}
  initial={'backend':b,'cache':cache,'pool':pool,'used':used,'account':rng.getrandbits(32)};before=enc(initial);seed(initial);events=[];nativeArgs=args[:7]if kind=='create'else args;actual=n.call(address,nativeArgs,regs={UC_X86_REG_ECX:B});after=enc(snap());expected=dec(before);out=[];result=model(expected,kind,args,out);ck(actual,result,kind+'return');ck(after,enc(expected),kind+'images');ck(events,out,kind+'ordered boundary state');ck(n.mu.reg_read(UC_X86_REG_FPCW),0x37f,kind+'control');fixtures.append({'kind':kind,'before':before,'arguments':args,'plan':copy.deepcopy(plan),'events':events,'after':after,'return':actual})
report={'status':'passed'if not errors else'failed','binarySHA256':n.sha256,'calls':len(fixtures),'checks':checks,'failures':errors,'comCalls':sum(len(z['events'])for z in fixtures),'scope':'Whole original six CPU entries unchanged and real format children. Available32-slot pool, divisor nonzero, sample index0..4, FPCW37f; final creation/GetLevelCount COM only. Exhausted-pool invalid-pointer continuation excluded. No managed/game/OS/settings execution.'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2))
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt')as f:json.dump({'report':report,'fixtures':fixtures},f,separators=(',',':'))
print(json.dumps({k:v for k,v in report.items()if k!='failures'},indent=2));print('failures',[(z['case'],z['label'])for z in errors]);raise SystemExit(bool(errors))
