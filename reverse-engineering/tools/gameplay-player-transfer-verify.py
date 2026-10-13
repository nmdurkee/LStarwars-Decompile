"""Ordinary (mode0) PC player transfer, executing reset/clear/bind/feedback wrappers.
Script initialization0x514640 and platform feedback0x698900 remain explicit services.
"""
import importlib.util,json,struct,itertools,copy,hashlib,random
from pathlib import Path
s=importlib.util.spec_from_file_location('actors',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
n=a.n;BASE=a.BASE;D=a.D
AUX=D+0x60000;INPUT=D+0x64000;SCRIPT=D+0x65000;TUNING=D+0x68000;GAME=D+0x6c000
WORDS=[0xda8,0x7fc,0xdec,0xea8,0x1000,0xd60,0xda4,0xef0,0xee4,0xee8,0x7c0,0xd80,0xd84,0xd14,0xd90,0xd18,0xd88,0x32c]
checks={};errors=[];vectors=[];helper_vectors=[];current={}
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x514640:
  who=a.aid(arg(1)-0x2c8);a.events.append(['script',who,(arg(7)-SCRIPT)//0x100,arg(8)])
  assert arg(1)==arg(2) and all(arg(i)==0 for i in [3,4,5,6]);a.ret(mu,0)
 elif address==0x698900:
  a.events.append(['feedback',arg(0),arg(1),arg(2),arg(3),arg(4)]);a.ret(mu,0)
for address in [0x514640,0x698900]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def context(o):
 c=dict(blocked=False,specialLevel=False,defaultMax=4,transferTime=a.bits(.75),feedbackDivisor=30.,players=[0,1,2,3,4,5,6,7],pairFrom=0,pairTo=1,pairWords=[a.bits(7.5),0x12345678],alias=False,primary=0,secondary=7,tagFlags=[0xa8,0xa9],targetBlocked=0)
 c.update(o);c['records']=[]
 for i in range(2):
  r=dict(flags=0x5aa501a5^(i*0x12345),active=0x1081 if i==0 else 0x1001,input=i,aux=i,index=i,maximum=5+i,health=3+i,alternate=2+i,definitionFlags=0,tuningMax=8+i,linked=-1,script=i,scriptState=0xabc00000+i,handle=0x12340000+i,words=[0x3f010000+i*0x100+j for j in range(len(WORDS))])
  r.update(o.get('records',{}).get(str(i),{}));c['records'].append(r)
 return c
def setup(c):
 global current
 current=c;bc=a.context({});a.setup(bc,[]);n.write(AUX,bytes(0x10000));n.pack('<I',0x951c5c,int(c['blocked']));n.pack('<I',0x802c54,GAME);n.pack('<I',GAME+0x128,11 if c['specialLevel'] else 12);n.pack('<I',0x87b160,11);n.pack('<I',GAME+0x2ae8,0x11223344)
 n.pack('<B',0x802bd4,c['defaultMax']);n.pack('<I',0x802be8,c['transferTime']);n.pack('<f',0x925024,c['feedbackDivisor']);n.pack('<II',0x87a7c8,a.actor(c['pairFrom']),a.actor(c['pairTo']));n.pack('<2I',0x87a7d0,*c['pairWords'])
 for i,ix in enumerate(c['players']):n.pack('<I',0x93d7f0+i*4,a.actor(ix))
 n.pack('<II',0x93d810,a.actor(c['primary']),a.actor(c['secondary']))
 for i,r in enumerate(c['records']):
  p=a.actor(i);n.pack('<II',p+0x1f8,r['flags'],r['active']);n.pack('<I',p+0xca4,INPUT+r['input']*0x100);n.pack('<I',INPUT+i*0x100,r['handle']);n.pack('<I',p+0x800,AUX+r['aux']*0x1000 if r['aux']>=0 else 0);n.write(AUX+i*0x1000,bytes([0xa1+i])*0x630)
  n.pack('<b',p+0x280,r['index']);n.pack('<BB',p+0x107e,r['maximum'],r['health']);n.pack('<B',p+0xe39,r['alternate']);n.pack('<I',a.DEF+i*0x4c+4,r['definitionFlags']);n.pack('<I',a.DEF+i*0x4c+0x24,TUNING+i*0x200);n.pack('<B',TUNING+i*0x200+0xf4,r['tuningMax']);n.pack('<I',p+0xcd0,a.actor(r['linked']));n.pack('<I',p+0x2c8,SCRIPT+r['script']*0x100 if r['script']>=0 else 0);n.pack('<I',SCRIPT+i*0x100+0x38,r['scriptState'])
  for off,value in zip(WORDS,r['words']):n.pack('<I',p+off,value)
  n.pack('<B',p+0x7c5,c['tagFlags'][i]);n.pack('<B',p+0x28b,c['targetBlocked'] if i==1 else 0)
 a.events.clear()
def snapshot():
 out=[]
 for i in range(2):
  p=a.actor(i);aux=n.unpack('<I',p+0x800)[0];out.append(dict(flags=n.unpack('<I',p+0x1f8)[0],active=n.unpack('<I',p+0x1fc)[0],input=(n.unpack('<I',p+0xca4)[0]-INPUT)//0x100,aux=(aux-AUX)//0x1000 if aux else -1,index=n.unpack('<b',p+0x280)[0],maximum=n.unpack('<B',p+0x107e)[0],health=n.unpack('<B',p+0x107f)[0],words=[n.unpack('<I',p+off)[0] for off in WORDS]))
 return dict(records=out,players=[a.aid(n.unpack('<I',0x93d7f0+i*4)[0]) for i in range(8)],pairFrom=a.aid(n.unpack('<I',0x87a7c8)[0]),pairTo=a.aid(n.unpack('<I',0x87a7cc)[0]),pairWords=list(n.unpack('<2I',0x87a7d0)),auxiliaryHashes=[hashlib.sha256(n.read(AUX+i*0x1000,0x630)).hexdigest() for i in range(2)],primary=a.aid(n.unpack('<I',0x93d810)[0]),secondary=a.aid(n.unpack('<I',0x93d814)[0]),tagFlags=[n.unpack('<B',a.actor(i)+0x7c5)[0] for i in range(2)])
def model(c):
 fields=['flags','active','input','aux','index','maximum','health','words'];out=dict(records=[{k:copy.deepcopy(r[k]) for k in fields} for r in c['records']],players=c['players'].copy(),pairFrom=c['pairFrom'],pairTo=c['pairTo'],pairWords=c['pairWords'].copy(),auxiliaryHashes=[hashlib.sha256(bytes([0xa1+i])*0x630).hexdigest() for i in range(2)],primary=c['primary'],secondary=c['secondary'],tagFlags=c['tagFlags'].copy());events=[]
 if c['blocked']:return dict(result=0,state=out,events=events)
 x=out['records'][0];y=out['records'][0 if c['alias'] else 1];xi=0;yi=0 if c['alias'] else 1;oldHealth=x['health'];oldOther=y['health'];oldFlags=x['active'];oldOtherFlags=y['active']
 def put(r,off,v):r['words'][WORDS.index(off)]=v
 def get(r,off):return r['words'][WORDS.index(off)]
 for r in [x,y]:
  for off in [0xd80,0xd84,0xd14,0xd90,0xd18]:put(r,off,0)
  put(r,0xd88,0x3e4ccccd)
 for field in ['input','index','aux']:x[field],y[field]=y[field],x[field]
 x['active']=(x['active']&~0x80)|(oldOtherFlags&0x80);y['active']=(y['active']&~0x80)|(oldFlags&0x80)
 for off in [0xda8,0x7fc,0xdec,0xea8,0x1000]:v=get(x,off);put(x,off,get(y,off));put(y,off,v)
 for r in [x,y]:
  if r['aux']>=0:out['auxiliaryHashes'][r['aux']]=hashlib.sha256(bytes(0x630)).hexdigest()
 flags=x['flags'];mask=0x46f8;x['flags']=(x['flags']&~mask)|(y['flags']&mask);y['flags']=(y['flags']&~mask)|(flags&mask)
 if c['records'][0]['script']>=0:events.append(['script',0,c['records'][0]['script'],c['records'][c['records'][0]['script']]['scriptState']]);put(x,0x32c,0)
 put(x,0xd60,0);put(x,0xda4,c['transferTime']);put(x,0xef0,(get(x,0xef0)&0xffe7ffff)|0x80);put(x,0xee4,0);put(x,0xee8,0);put(y,0xd60,a.bits(2.));put(y,0xef0,get(y,0xef0)|0x80);put(y,0xda4,c['transferTime'])
 handle=c['records'][y['input']]['handle']
 if handle:events.append(['feedback',handle,a.bits(2./a.f(c['feedbackDivisor'])),0,0,0])
 for i,r in [(xi,x),(yi,y)]:
  source=c['records'][i]
  if r['index']!=-1:out['players'][r['index']]=i
  if r['index']==-1 or source['linked']>=0:r['maximum']=source['tuningMax']
  elif not c['specialLevel']:r['maximum']=c['defaultMax']
 y['health']=oldHealth
 if y['maximum']<(oldHealth if oldHealth<128 else oldHealth-256):y['health']=y['maximum']
 if y['health']==0 and y['maximum']!=0:y['health']=1
 if c['specialLevel'] or x['active']&0x80:x['health']=oldOther
 else:x['health']=c['records'][xi]['alternate'] if c['records'][xi]['definitionFlags']&0x20 else x['maximum']
 put(y,0xef0,get(y,0xef0)&0xffe7ffff);put(y,0xee4,0);put(y,0xee8,0);put(y,0x7c0,a.bits(1.))
 if c['pairFrom']==xi and c['pairTo']!=yi:out.update(pairFrom=-1,pairTo=-1,pairWords=[0,0])
 return dict(result=1,state=out,events=events)
def tag_model(c,first):
 initial=copy.deepcopy(c);initial['blocked']=True;want=model(initial);want['result']=1
 if not first:return want
 disabled=True
 if c['records'][0]['active']&0x80:
  target=c['records'][1]
  valid=(target['active']&0x1081)==0x1001 and not c['targetBlocked'] and not c['tagFlags'][1]&2
  if valid:want=model(c);disabled=want['result']!=0;want['result']=1
  else:disabled=False
  state=want['state'];p,q=state['players'][:2];p=p if p>=0 and state['records'][p]['active']&0x80 else -1;q=q if q>=0 and state['records'][q]['active']&0x80 else -1
  if p<0 and q<0:state['primary']=-1
  else:state['primary']=p if p>=0 else q;state['secondary']=q if p>=0 else -1
 want['state']['tagFlags'][0]=(want['state']['tagFlags'][0]&~2)|(2 if disabled else 0)
 return want
def run(o=None,kind='transfer',first=True):
 c=context(o or {});setup(c)
 if kind=='tag':
  n.write(a.TEXT,b'FALSE\0');n.pack('<I',a.ARGS,a.TEXT);result=n.call(0x44f930,[a.SYS,a.PACK,a.CRE,a.ARGS,1,int(first)],count=1000000);want=tag_model(c,first)
 else:result=n.call(0x4876a0,[a.actor(0),a.actor(0 if c['alias'] else 1),0,0,0],count=1000000);want=model(c)
 got=dict(result=result,state=snapshot(),events=a.events.copy());checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(options=o,got=got,want=want))
 vectors.append(dict(kind=kind,first=first,context=c,native=got))
def main():
 for blocked,special,index0,index1,linked,script in itertools.product([False,True],[False,True],[-1,0,7],[-1,1,6],[-1,1],[-1,0]):run(dict(blocked=blocked,specialLevel=special,records={'0':dict(index=index0,linked=linked,script=script),'1':dict(index=index1)}))
 for health,maximum,oldOther,side in itertools.product([0,1,3,127,128,255],[0,1,5,127,128,255],[0,4,255],[0,0x20]):run(dict(defaultMax=maximum,records={'0':dict(health=health,definitionFlags=side),'1':dict(health=oldOther)}))
 for au0,au1,inp0,inp1 in itertools.product([-1,0,1],[-1,0,1],[0,1],[0,1]):run(dict(records={'0':dict(aux=au0,input=inp0),'1':dict(aux=au1,input=inp1)}))
 for pairFrom,pairTo in itertools.product([-1,0,1],[-1,0,1]):run(dict(pairFrom=pairFrom,pairTo=pairTo))
 for alias,special,controlled in itertools.product([False,True],[False,True],[0x1001,0x1081]):run(dict(alias=alias,specialLevel=special,records={'0':dict(active=controlled),'1':dict(handle=0)}))
 rng=random.Random(0x4876a0)
 for i in range(64):run(dict(records={str(j):dict(flags=rng.randrange(1<<32),active=rng.randrange(1<<32),words=[rng.randrange(1<<32) for k in WORDS]) for j in range(2)}))
 for blocked,controlled,targetActive,tagDisabled,first in itertools.product([False,True],[0x1001,0x1081],[0x1001,0x1081],[0,2],[False,True]):
  run(dict(blocked=blocked,players=[0,1,-1,-1,-1,-1,-1,-1],tagFlags=[0xaa,0xa8|tagDisabled],records={'0':dict(active=controlled),'1':dict(active=targetActive)}),'tag',first)
 for amount,divisor,handle in itertools.product([0,1,2,-2,16777217,2147483647,-2147483648],[30.,.016666667,1.,-1.],[0,0x12345678]):
  n.pack('<f',0x925024,divisor);a.events.clear();n.call(0x54a8d0,[handle,amount]);got=a.events.copy();want=[['feedback',handle,a.bits(amount/a.f(divisor)),0,0,0]] if handle else [];checks['feedback']=checks.get('feedback',0)+1
  if got!=want:errors.append(dict(kind='feedback',amount=amount,divisor=divisor,handle=handle,got=got,want=want))
  helper_vectors.append(dict(amount=amount,divisor=a.bits(divisor),handle=handle,native=got))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:8],method='Unmodified ordinary mode0 transfer4876a0 with original reset4a4ca0, buffer-clear466820, rebind wrapper415000 and feedback wrapper54a8d0. Only deep script initialization514640 and platform feedback698900 are substituted.',limits=['Mode1 takeover is explicitly excluded; this is the exact mode0 path called by tag candidate selector487ca0.','Valid two-actor records, nullable auxiliary buffers, signed personal index-1 or0..7, finite nonzero feedback divisor.','Deep script initialization and platform feedback remain service adapters; managed replay comparison pending.'])
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);assembly=dict(binarySha256=n.sha256,entry='0x54a8d0',endExclusive='0x54a906',reason='Signed integer amount is loaded directly by FILD before division; no float32 rounding precedes FDIV. Result is rounded by FSTP before platform call.',instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str) for i in d.disasm(n.read(0x54a8d0,0x36),0x54a8d0)])
 (BASE/'reports/gameplay-player-transfer-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8')
 (BASE/'reports/gameplay-player-transfer-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-player-transfer-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,wordOffsets=WORDS,cases=vectors,feedback=helper_vectors),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
