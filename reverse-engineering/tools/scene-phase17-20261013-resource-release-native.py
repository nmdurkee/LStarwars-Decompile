"""Original release CPU body and texture/stream wrappers, with final COM and texture-free graph explicit."""
import importlib.util,struct,json,gzip,random,copy
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase17-20261013-resource-release'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
B=0x29765c8;CACHE=0x297bea0;EN=0x8282b4;DEV=n.DATA+0x3000;VT=n.DATA+0x4000;OBJ=n.DATA+0x10000;OVT=n.DATA+0x20000
EDGES={n.STOP+0x100:('texture',0x104,2),n.STOP+0x180:('stream',0x190,4),n.STOP+0x200:('release',8,0),0x5f7b40:('free',0,1)}
n.pack('<I',DEV,VT)
for edge,(kind,off,count)in EDGES.items():
 if kind in ['texture','stream']:n.pack('<I',VT+off,edge)
 elif kind=='release':n.pack('<I',OVT+off,edge)
for j in range(16):n.pack('<I',OBJ+j*0x40,OVT)
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def snap():return {'backend':bytearray(n.read(B,0x800)),'cache':bytearray(n.read(CACHE,0x300)),'enabled':n.read(EN,1)[0]}
def enc(s):return {'backendHex':s['backend'].hex(),'cacheHex':s['cache'].hex(),'enabled':s['enabled']}
def dec(s):return {'backend':bytearray.fromhex(s['backendHex']),'cache':bytearray.fromhex(s['cacheHex']),'enabled':s['enabled']}
def seed(s):n.write(B,s['backend']);n.write(CACHE,s['cache']);n.write(EN,bytes([s['enabled']]))
case=0;events=[];checks=0;errors=[];fixtures=[];plan={}
def service(s,kind,receiver,args,out):
 out.append({'kind':kind,'receiver':receiver,'arguments':args[:],'before':enc(s)})
 for at,v in plan['backend']:w(s['backend'],at,v)
 for at,v in plan['cache']:w(s['cache'],at,v)
 s['enabled']=plan['enabled'];return (plan['return']+len(out)*0x107)&0xffffffff

def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];kind,off,count=EDGES[address];com=kind!='free';receiver=n.unpack('<I',sp+4)[0]if com else 0;args=list(n.unpack('<'+str(count)+'I',sp+(8 if com else 4)))if count else []
 state=snap();result=service(state,kind,receiver,args,events);seed(state);mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+4+(count+1)*4 if com else sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for edge in EDGES:n.mu.hook_add(UC_HOOK_CODE,hook,begin=edge,end=edge)
def model(s,kind,args,incoming,out):
 b=s['backend'];c=s['cache']
 if kind=='missing':return int(u(b,4)==0)
 if kind=='texture':
  stage,value=args
  if s['enabled']and stage<5:
   at=0x20+stage*4
   if u(c,at)==value:return incoming
   w(c,at,value)
  result=service(s,kind,u(b,4),args,out);w(c,0,result);return result
 if kind=='stream':
  stream,buffer,offset,stride=args
  if s['enabled']:
   if [u(c,z)for z in [0x10,0x14,0x18,0x1c]]==[buffer,stride,stream,offset]:return incoming
   for at,value in [(0x10,buffer),(0x18,stream),(0x14,stride),(0x1c,offset)]:w(c,at,value)
  result=service(s,kind,u(b,4),args,out);w(c,0,result);return result
 def release(at):
  token=u(b,at)
  if token:service(s,'release',token,[],out);w(b,at,0)
 for at in [0x6b0,0x6ec,0x690,0x694,0x698,0x688]:release(at)
 for j in range(4):release(0x6c4+j*4);result=service(s,'free',0,[u(b,0x6b4+j*4)],out);w(b,0x6b4+j*4,0);w(b,0x6f0+j*4,0)
 return result

def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<12:errors.append({'case':case,'label':label,'native':a,'model':e})
rng=random.Random(0x6e217017)
for case in range(2048):
 for kind,address in [('missing',0x6e45a0),('texture',0x6e5630),('stream',0x6e5590),('apply',0x6e2170)]:
  b=bytearray(rng.randbytes(0x800));c=bytearray(rng.randbytes(0x300));w(b,4,0 if kind=='missing'and case%2 else DEV)
  for j,at in enumerate([0x6b0,0x6ec,0x690,0x694,0x698,0x688,0x6c4,0x6c8,0x6cc,0x6d0]):w(b,at,0 if (j+case)%3==0 else OBJ+j*0x40)
  for j in range(4):w(b,0x6b4+j*4,0 if (j+case)%2 else 0x986f00+j*48)
  args=[([0,1,4,5,0xffffffff,0x80000000][case%6]),rng.getrandbits(32)]if kind=='texture'else [rng.getrandbits(32)for _ in range(4)]if kind=='stream'else [];incoming=rng.getrandbits(32);enabled=[0,1,255][case%3]
  if kind=='texture'and args[0]<5 and case%2==0:w(c,0x20+args[0]*4,args[1])
  if kind=='stream'and case%2==0:
   for at,v in zip([0x18,0x10,0x1c,0x14],args):w(c,at,v)
  # Coherent mutations to known valid next handles and cache state at host edges.
  plan={'backend':[(0x6d0,OBJ+9*0x40),(0x6b4+case%4*4,0x986f00+(case%4+8)*48)]if kind=='apply'else[(0x138,rng.getrandbits(32))],'cache':[(0,rng.getrandbits(32)),(0x24,rng.getrandbits(32))],'enabled':rng.choice([0,1,255]),'return':rng.getrandbits(32)}
  initial={'backend':b,'cache':c,'enabled':enabled};before=enc(initial);seed(initial);events=[];actual=n.call(address,args,regs={UC_X86_REG_ECX:B,UC_X86_REG_EAX:incoming});after=enc(snap());expected=dec(before);out=[];result=model(expected,kind,args,incoming,out)
  ck(actual,result,kind+'return');ck(after,enc(expected),kind+'images');ck(events,out,kind+'events');ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe004,kind+'stack')
  fixtures.append({'kind':kind,'before':before,'arguments':args,'incomingEax':incoming,'plan':copy.deepcopy(plan),'events':events,'after':after,'return':actual})
report={'status':'passed'if not errors else'failed','binarySHA256':n.sha256,'calls':len(fixtures),'checks':checks,'failures':errors,'explicitBoundaryEvents':sum(len(z['events'])for z in fixtures),'scope':'Original four CPU bodies unchanged; final COM and texture-free graph explicit; full raw images and cache-hit incoming EAX retained. No game or managed launch.'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2))
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt')as f:json.dump({'report':report,'fixtures':fixtures},f,separators=(',',':'))
print(json.dumps({k:v for k,v in report.items()if k!='failures'},indent=2));print('failures',[(z['case'],z['label'])for z in errors]);raise SystemExit(bool(errors))
