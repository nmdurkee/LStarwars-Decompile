"""Original texture pool free and format dispatch; only object Release COM adapted."""
import importlib.util,json,gzip,struct,random,copy
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase18-20261013-texture-ownership'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_FPCW
POOL=0x986f00;USED=0x280d7e0;ACCOUNT=0x2854bc0;OBJ=n.DATA+0x1000;VT=n.DATA+0x3000;EDGE=n.STOP+0x100
for j in range(4):n.pack('<I',OBJ+j*0x100,VT)
n.pack('<I',VT+8,EDGE)
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def i32(v):return ((v+0x80000000)&0xffffffff)-0x80000000
def snap():return {'pool':bytearray(n.read(POOL,0x600)),'used':bytearray(n.read(USED,32)),'account':n.unpack('<I',ACCOUNT)[0]}
def enc(s):return {'poolHex':s['pool'].hex(),'usedHex':s['used'].hex(),'account':s['account']}
def dec(s):return {'pool':bytearray.fromhex(s['poolHex']),'used':bytearray.fromhex(s['usedHex']),'account':s['account']}
def seed(s):n.write(POOL,s['pool']);n.write(USED,s['used']);n.pack('<I',ACCOUNT,s['account'])
plan={};events=[];checks=0;errors=[];fixtures=[]
def release(s,token,out):
 out.append({'token':token,'before':enc(s)});at=plan['offset']
 for o,v in plan['words']:w(s['pool'],at+o,v)
 for o,v in plan['halves']:struct.pack_into('<H',s['pool'],at+o,v)
 s['account']=plan['account'];return (plan['return']+len(out))&0xffffffff

def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];token=n.unpack('<I',sp+4)[0];state=snap();result=release(state,token,events);seed(state);mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+8);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook,begin=EDGE,end=EDGE)
def model(s,owner,incoming,out):
 if owner==0:return incoming
 at=(owner-POOL)&0xffffffff
 if at>=0x600 or at%48:return 0x600
 if u(s['pool'],at+0x2c)==0xffffffff:
  for o in [0,0x28]:
   token=u(s['pool'],at+o)
   if token:release(s,token,out);w(s['pool'],at+o,0)
 width,height=struct.unpack_from('<2H',s['pool'],at+4);levels=struct.unpack_from('<H',s['pool'],at+10)[0];area=i32(-width*height*4);delta=int(area*(1 if levels==1 else 1.5));s['account']=(s['account']+delta)&0xffffffff;s['pool'][at:at+48]=bytes(48);s['used'][at//48]=0;return owner

def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<12:errors.append({'case':case,'label':label,'native':a,'expected':e})
rng=random.Random(0x5f7b4018)
for case in range(4096):
 pool=bytearray(rng.randbytes(0x600));used=bytearray(rng.randbytes(32));slot=case%32;at=slot*48;owner=[POOL+at,0,POOL+at+1,0xffffffff,POOL+0x600][case%5];incoming=rng.getrandbits(32);w(pool,at,0 if case%3==0 else OBJ);w(pool,at+0x28,0 if case%4==0 else OBJ+0x100);w(pool,at+0x2c,0xffffffff if case%2==0 else rng.getrandbits(32));struct.pack_into('<2H',pool,at+4,*[(65535 if case%3==0 else rng.randrange(65536))for _ in range(2)]);struct.pack_into('<H',pool,at+10,1 if case%3==0 else rng.randrange(65536))
 initial={'pool':pool,'used':used,'account':rng.getrandbits(32)};plan={'offset':at,'words':[(0,OBJ+0x200),(0x28,OBJ+0x300)]if case%3==1 else [],'halves':[(4,65535),(6,65535),(10,1 if case%4==0 else 2)]if case%3==1 else [],'account':rng.getrandbits(32),'return':rng.getrandbits(32)}
 before=enc(initial);seed(initial);events=[];actual=n.call(0x5f7b40,[owner],regs={UC_X86_REG_EAX:incoming});after=enc(snap());expected=dec(before);out=[];result=model(expected,owner,incoming,out);ck(actual,result,'return');ck(after,enc(expected),'pool usage accounting');ck(events,out,'release boundary states');ck(n.mu.reg_read(UC_X86_REG_FPCW),0x37f,'x87 control restore');fixtures.append({'before':before,'owner':owner,'incomingEax':incoming,'plan':copy.deepcopy(plan),'events':events,'after':after,'return':actual})
forward={1:22,2:21,4:75,5:83,10:114};reverse={21:2,22:2,75:4,83:5};formatProbes=[]
for case,value in enumerate(list(range(256))+[rng.getrandbits(32)for _ in range(4096)]+[0xffffffff,0x80000000]):
 for address,table in [(0x5f7980,forward),(0x5f79e0,reverse)]:
  actual=n.call(address,regs={UC_X86_REG_EAX:value,UC_X86_REG_ECX:0x12345678});expected=table.get(value,0xffffffff if address==0x5f7980 else 0);ck(actual,expected,'format');ck(n.mu.reg_read(UC_X86_REG_ECX),0x12345678,'preserved usage ECX');formatProbes.append({'address':hex(address),'eaxInput':value,'eaxOutput':actual})
report={'status':'passed'if not errors else'failed','binarySHA256':n.sha256,'freeCalls':len(fixtures),'formatCalls':len(formatProbes),'checks':checks,'failures':errors,'releaseComCalls':sum(len(z['events'])for z in fixtures),'scope':'Whole original free and two original EAX format dispatch bodies; original memset unchanged. All16-bit dimensions/levels and signed wrapped accounting; fresh callback mutations and raw return residue. No OS/game/managed execution.'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2))
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt')as f:json.dump({'report':report,'fixtures':fixtures,'formatProbes':formatProbes},f,separators=(',',':'))
print(json.dumps({k:v for k,v in report.items()if k!='failures'},indent=2));print('failures',[(z['case'],z['label'])for z in errors]);raise SystemExit(bool(errors))
