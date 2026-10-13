"""Original facing commands and actual movement-token/head-look/vector helpers."""
import importlib.util,json,struct,itertools,math,random
from pathlib import Path
s=importlib.util.spec_from_file_location('movement',Path(__file__).with_name('gameplay-movement-verify.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
b=m.b;n=m.n;BASE=b.BASE;D=m.D;CRE=m.CRE;P=m.CALLER
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
bits=m.bits;f=m.f;fl=m.fl;vec=m.vec;HEAD=D+0x72000;PRIOR=D+0x73000;SCRATCH=D+0x74000
ADDRESSES={'FacePlayer':0x515ca0,'FaceOpponent':0x515e70,'FaceCamera':0x451f20,'FaceCharacter':0x4520f0,'FaceLocator':0x52d220,'SpinOnSpot':0x4521d0}
uses={r['name']:r['uses'] for r in b.ledger['rows'] if r['name'] in ADDRESSES}
sine_bytes=(BASE/'references/native-animation-sine-table.f32').read_bytes();sines=struct.unpack('<32768f',sine_bytes)
checks={};errors=[];vectors=[];helper_vectors=[]
SC=CRE
def headid(p):return 3 if p==0x973718 else (p-HEAD)//16 if p else -1
def eventhook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x43c0c0:b.events.append(['token',b.string(arg(0))])
 elif address==0x58bee0:b.events.append(['look',b.aid(arg(0)),headid(arg(1)),arg(2)&255,arg(3),arg(4),arg(5)])
for a in [0x43c0c0,0x58bee0]:n.mu.hook_add(UC_HOOK_CODE,eventhook,begin=a,end=a)
def headstate(i):
 a=b.actor(i);p=n.unpack('<I',a+0xfd8)[0]
 return dict(target=headid(p),position=list(n.unpack('<3I',a+0xfdc)),priority=n.unpack('<b',a+0x1080)[0],duration=n.unpack('<I',a+0xfe8)[0],delay=n.unpack('<I',a+0xfec)[0])
def targetid(p):
 if not p:return None
 if p==PRIOR:return 'prior'
 if p==P+0x78:return 'packet'
 if p==0x973718:return 'camera'
 for i in range(3):
  if p==b.actor(i)+0x5c:return 'actor:'+str(i)
 if m.LOC+0x10<=p<m.LOC+0x1000:return 'locator:'+str(b.idx(p-0x10))
 raise ValueError(hex(p))
def snapshot(command):
 return dict(wait=n.unpack('<I',P+0x9c)[0],flags=n.unpack('<B',P+0x68)[0],angle=n.unpack('<H',P+0x6a)[0],offset=n.unpack('<I',P+0x70)[0],point=list(n.unpack('<3I',P+0x78)),bound=b.idx(n.unpack('<I',P+0x6c)[0]) if command=='FaceLocator' else b.aid(n.unpack('<I',P+0x6c)[0]),mode=n.unpack('<B',SC+0x13f)[0],look=targetid(n.unpack('<I',SC+0x1e4)[0]),floatRng=n.unpack('<I',0x95e5d4)[0],qrand=n.unpack('<I',0x80253c)[0],head=[headstate(i) for i in range(3)])
def setup(command,tokens,o):
 global SC
 SC=CRE
 c=m.setup('GoToLocator',tokens,o);n.write(0x29899a0,sine_bytes);n.pack('<I',0x9238b0,0 if o.get('noTokenCallback') else 0x43c0c0);n.pack('<I',m.SYS+0x138c,b.actor(o.get('player',1)) if o.get('player',1)>=0 else 0)
 n.pack('<I',CRE+0xe4,b.actor(o.get('opponent',1)) if o.get('opponent',1)>=0 else 0);n.pack('<I',CRE+0xd4,b.actor(o.get('nearest',2)) if o.get('nearest',2)>=0 else 0);n.pack('<I',CRE+0x1e4,PRIOR)
 n.pack('<Hf',P+0x6a,o.get('angle',0x4321),1.) # write gap independently below
 n.pack('<f',P+0x70,o.get('offset',0.));n.pack('<I',P+0x6c,(m.LOC+0x3c*o.get('active',0) if o.get('active',0)>=0 else 0) if command=='FaceLocator' else (b.actor(o['bound']) if o.get('bound',-1)>=0 else 0))
 n.pack('<I',0x80253c,o.get('qrand',123));headpoints=[[f(1.25+i),f(2.5+i),f(3.75+i)] for i in range(3)]
 for i,pos in enumerate(headpoints):n.pack('<3f',HEAD+16*i,*pos)
 for i in range(3):
  a=b.actor(i);n.pack('<I',a+0x4ac,HEAD+16*o.get('lookPoint',0) if o.get('lookPoint',0)>=0 else 0);n.pack('<I',a+0xfd8,HEAD+16*o.get('oldLook',1) if o.get('oldLook',1)>=0 else 0);n.pack('<3f',a+0xfdc,90.,91.,92.);n.pack('<ff',a+0xfe8,2.,3.);n.pack('<b',a+0x1080,o.get('priority',0));n.pack('<H',a+0x27a,o.get('actorAngle',0x1234));n.pack('<3f',a+0x80,1.25+i,2.5+i,3.75+i)
 if o.get('opponentController') is False:n.pack('<I',b.actor(o.get('opponent',1))+4,0)
 headpoints.append([30.,40.,50.]);n.pack('<3f',0x973718,*headpoints[3])
 c.update(headpoints=[vec(p) for p in headpoints],origins=[list(n.unpack('<3I',b.actor(i)+0x80)) for i in range(3)],actorAngles=[n.unpack('<H',b.actor(i)+0x27a)[0] for i in range(3)])
 if o.get('embeddedCreature'):SC=b.actor(0)+0x2c8;n.write(SC,n.read(CRE,0x300))
 b.events.clear();return c
def normalize(v):
 length=f(math.sqrt(f(v[0]*v[0]+v[1]*v[1]+v[2]*v[2])));reciprocal=f(1./length) if length>0 else 0.
 return [f(reciprocal*x) for x in v]
def request(state,target,priority,duration,minimum,maximum,seed,positions):
 out=dict(state)
 if target<0:out.update(target=-1,priority=0,duration=0,delay=0);return out,seed
 if out['target']<0 or (out['target']!=target and out['priority']<=priority):
  seed=(seed*0x24cd+1)&65535;fraction=f(seed*1.5259021893143654e-5);delay=f((1.-fraction)*minimum+maximum*fraction);out.update(target=target,priority=priority,delay=bits(delay),duration=bits(f(delay+duration)))
 out['position']=positions[out['target']];return out,seed
def model(command,tokens,c,o,first,delta,before):
 out=json.loads(json.dumps(before));events=[]
 def evaluate(t):events.append(['expression',t]);return b.number(t)
 def token(t):
  if o.get('noTokenCallback'):return False
  events.append(['token',t]);v={'run':0,'walk':1,'tiptoe':2}.get(t.lower())
  if v is not None:out['mode']=v;return True
  return False
 def draw():out['floatRng']=b.u(out['floatRng']*0x19660d+0x3c6ef35f);return (out['floatRng']&0x7fffff)/(1<<23)
 def finish(v):return dict(state=out,events=events,result=v)
 if command in ['FacePlayer','FaceOpponent'] and not c['creature']:return finish(1)
 if command in ['FaceCamera','FaceLocator','SpinOnSpot'] and not (c['creature'] and c['reference'] and c['worldObject']>=0):return finish(1)
 if command=='FaceLocator':
  if not o.get('path',True) or not o.get('node',True):return finish(1)
  if first:
   out['bound']=c['selected'];i=0
   while i<len(tokens):
    t=tokens[i];low=t.lower()
    if not token(t) and 'name' in low:
     name=t[low.index('name')+5:];events.append(['find',name]);out['bound']=next((j for j,r in enumerate(c['records']) if r['name'].lower()==name.lower()),-1);i+=1
    i+=1
  if out['bound']<0:return finish(0)
  out['look']='locator:'+str(out['bound']);return finish(1)
 if first:
  minimum=maximum=0.
  for t in tokens:
   low=t.lower()
   if command=='FaceCharacter':
    if 'character=' in low:
     name=t[low.index('character=')+10:]
     if not c['callback']:out['bound']=-1
     else:events.append(['reference',name]);out['bound']=b.named(name)
    else:out['wait']=bits(b.number(t))
   elif command=='SpinOnSpot':
    if 'mintime=' in low:minimum=evaluate(t[low.index('mintime=')+8:])
    elif 'maxtime=' in low:maximum=evaluate(t[low.index('maxtime=')+8:])
    elif 'time=' in low:out['wait']=bits(evaluate(t[low.index('time=')+5:]))
    elif 'rot_rate=' in low:out['offset']=bits(float(int(evaluate(t[low.index('rot_rate=')+9:])*182.04444885253906)))
   else:
    if command=='FaceOpponent' and token(t):continue
    if command=='FaceCamera' and low=='look_at_camera':out['flags']=1
    elif 'mintime' in low:minimum=evaluate(t[low.index('mintime')+8:])
    elif 'maxtime' in low:maximum=evaluate(t[low.index('maxtime')+8:])
    elif command=='FaceOpponent' and 'faceoffset' in low:out['offset']=bits(evaluate(t[low.index('faceoffset')+11:]))
    elif command=='FaceOpponent' and low=='nearest_opponent':out['flags']=1
    else:out['wait']=bits(b.number(t) if command=='FaceCamera' else evaluate(t))
  if command=='SpinOnSpot':
   if minimum!=maximum:out['wait']=bits(draw()*(maximum-minimum)+minimum)
   out['angle']=c['actorAngles'][c['worldObject']]
  elif command!='FaceCharacter' and fl(out['wait'])==0 and minimum<maximum:out['wait']=bits(draw()*(maximum-minimum)+minimum)
 if command=='FacePlayer':
  if o.get('player',1)>=0:out['look']='actor:'+str(o.get('player',1))
 elif command=='FaceCharacter':
  if c['creature'] and out['bound']>=0:out['look']='actor:'+str(out['bound'])
 elif command=='FaceCamera':
  out['look']='camera'
  if out['flags']:
   a=c['worldObject'];point=3 if o.get('embeddedCreature') and a==0 else o.get('lookPoint',0);events.append(['look',a,point,6,bits(1.),0,0]);out['head'][a],out['qrand']=request(out['head'][a],point,6,1.,0.,0.,out['qrand'],c['headpoints'])
 elif command=='FaceOpponent':
  opponent=o.get('nearest',2) if out['flags'] else o.get('opponent',1)
  if opponent>=0 and not (o.get('opponentController') is False and opponent==o.get('opponent',1)):
   if fl(out['offset'])==0:out['look']='actor:'+str(opponent)
   else:
    a=[fl(x) for x in c['actorPositions'][opponent]];own=[fl(x) for x in c['actorPositions'][0]];side=normalize([f(a[2]-own[2]),0.,f(own[0]-a[0])]);out['point']=vec([fl(out['offset'])*side[0]+a[0],a[1],fl(out['offset'])*side[2]+a[2]]);out['look']='packet'
 elif command=='SpinOnSpot':
  out['angle']=(out['angle']+int(fl(out['offset'])*delta))&65535;a=out['angle'];v=[sines[(a>>1)&32767],0.,sines[((a+16384)>>1)&32767]];out['point']=vec([f(x+fl(y)) for x,y in zip(v,c['origins'][c['worldObject']])]);out['look']='packet'
 if fl(out['wait'])>0:
  out['wait']=bits(f(fl(out['wait'])-delta))
  if fl(out['wait'])<=0:out['wait']=0;return finish(1)
 return finish(0)
def check(group,got,want,meta):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
def run(command,tokens,o=None,first=True,delta=.125,source=None):
 o=o or {};c=setup(command,tokens,o);before=snapshot(command);delta=f(delta);value=n.call(ADDRESSES[command],[m.SYS,P,SC if c['creature'] else 0,m.ARGS,len(tokens),int(first),bits(delta)],count=1000000);got=dict(state=snapshot(command),events=list(b.events),result=value);want=model(command,tokens,c,o,first,delta,before)
 for key in got:check(command+'-'+key,got[key],want[key],dict(tokens=tokens,options=o,first=first,delta=delta,source=source))
 vectors.append(dict(command=command,tokens=tokens,options=o,first=first,delta=bits(delta),source=source,context=c,before=before,native=got))
if __name__=='__main__':
 for command,records in uses.items():
  for use in records:
   for first,wait in [(True,0.),(False,.125),(False,0.)]:run(command,use['args'],dict(wait=wait),first=first,source={k:use[k] for k in ['source','line','text']})
 for command in ADDRESSES:
  for tokens in [[],['.125'],['0'],['-1'],['mintime=.25','maxtime=.5'],['mintime=2','maxtime=1'],['time=.125','rot_rate=3.5'],['run','walk','tiptoe'],['name=Target','name=Ignored','walk'],['character=Other'],['character=missing'],['nearest_opponent','faceoffset=2'],['faceoffset=-.75'],['look_at_camera']]:
   for o in [{},{'wait':.125},{'wait':-.25},{'creature':False},{'player':-1,'opponent':-1,'nearest':-1}]:run(command,tokens,o)
 for first,offset,nearest,mode,delta in itertools.product([True,False],[-4.,0.,3.5],[0,1],[0,255],[0.,.125,.5]):run('FaceOpponent',[],dict(offset=offset,packetFlags=nearest,mode=mode,wait=.25),first,delta)
 for flags,point,old,priority in itertools.product([0,1,255],[-1,0,1],[-1,0,1],[-1,6,7,127]):run('FaceCamera',[],dict(packetFlags=flags,lookPoint=point,oldLook=old,priority=priority))
 for rate,delta,angle in itertools.product([-65537.,-3.,-1.,0.,1.,3.,65537.],[.5,1.,1.5],[0,65535]):run('SpinOnSpot',[],dict(offset=rate,angle=angle),False,delta)
 for rate in ['-10000','-.125','1.999999','3.5','45','90','180','360','10000.5']:
  for delta in [.016666667,.5,1.]:run('SpinOnSpot',['rot_rate='+rate,'time=.25'],delta=delta)
 for world,priority,flags,first in itertools.product([0,1],[-128,6,127],[0,1,255],[False,True]):run('FaceCamera',['look_at_camera','.125'],dict(embeddedCreature=True,worldObject=world,priority=priority,packetFlags=flags),first)
 result=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:10],cases=len(vectors),authoredOccurrences={k:len(v) for k,v in uses.items()},method='Original command bodies, actual registered movement callback, expression/RNG/vector/angle/camera/priority-look helpers. Only the inherited named-reference and bounded CRT formatting services are adapted.',limits=['Synthetic actor/world bindings and explicit camera projection; no character turning consumer or head animation integration yet.','FaceLocator and SpinOnSpot have dispatch bindings but zero authored occurrences in this source catalog.','Finite scalar/position/rate domains; no invalid-pointer or NaN behavior claim.','Portable managed comparison remains pending.'])
 (BASE/'reports/gameplay-facing-tests.json').write_text(json.dumps(result,indent=2),encoding='utf8');(BASE/'reports/gameplay-facing-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');print(json.dumps(result))
 if errors:raise SystemExit(1)
