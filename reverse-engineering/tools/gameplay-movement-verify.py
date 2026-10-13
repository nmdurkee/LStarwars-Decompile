"""Original GoToLocator/FollowPlayer, real intent and route-selection helpers.
Only movement-token/world callbacks and formation expansion are adapters.
"""
import importlib.util,json,struct,itertools,math,random
from pathlib import Path
s=importlib.util.spec_from_file_location('binding',Path(__file__).with_name('gameplay-locator-binding-verify.py'));b=importlib.util.module_from_spec(s);s.loader.exec_module(b)
n=b.n;D=b.D;BASE=b.BASE;SYS=b.SYS;CRE=b.CRE;CALLER=b.CALLER;LOC=b.LOC;ARGS=b.ARGS;TEXT=b.TEXT
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX
TOKEN=n.STOP+0x180;COMPLETION=n.STOP+0x190;PATH=D+0x60000;NODES=D+0x61000;ROWS=D+0x62000;ROUTES=D+0x63000;INPUTS=D+0x64000;RESULT=D+0x65000
def controller(i):return CRE+0x300*i
def bits(x):return b.bits(x)
def f(x):return b.f(x)
def fl(x):return b.fl(x)
def vec(x):return [bits(v) for v in x]
uses={r['name']:r['uses'] for r in b.ledger['rows'] if r['name'] in ['GoToLocator','FollowPlayer']}
checks={};errors=[];vectors=[];options={}
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);a=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==TOKEN:
  text=b.string(a(0));mode={'walk':17,'run':34,'tiptoe':51}.get(text.lower());b.events.append(['token',text,mode is not None])
  if mode is not None:n.pack('<B',a(1),mode)
  b.ret(mu,1 if mode is not None else 0)
 elif address==COMPLETION:b.events.append(['completion',b.aid(a(0)),b.idx(a(1)-0x10)]);b.ret(mu,int(options.get('completionResult',False)))
 elif address==0x52fcb0:b.events.append(['intent',list(n.unpack('<3I',a(1))) if a(1) else None,a(2),list(n.unpack('<6I',a(3))) if a(3) else None,a(4),a(5)])
 elif address==0x514920:b.events.append(['expression',b.string(a(2))])
for address in [TOKEN,COMPLETION,0x52fcb0,0x514920]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)

def setup(command,tokens,o):
 global options
 options=o
 names=[]
 for i,t in enumerate(tokens[:-1]):
  if 'name' in t.lower() or 'teleport' in t.lower():names.append('name='+tokens[i+1])
 c=b.context(tokens+names,o);b.setup(c,tokens)
 # Shared controller records supply actual paths, next-hop ordinals and targets.
 route=o.get('route',[[0,1,2],[0,1,2],[0,1,2]])
 for i in range(3):
  cp=controller(i);n.pack('<I',b.actor(i)+4,cp);n.pack('<I',cp+0xd0,b.actor(i));n.pack('<I',cp+0x158,PATH if o.get('path',True) or i else 0);n.pack('<I',cp+0x15c,NODES+0x40*i if o.get('node',True) or i else 0)
  n.pack('<I',cp+0x160,0x12340000+i);n.pack('<I',cp+0x164,0x22340000+i);n.pack('<B',cp+0x166,o.get('targetNodeFlags',0) if i==1 else 0);n.pack('<II',cp+0x168,0x33440000+i,0x44550000+i)
  n.pack('<3f',cp+0x170,3.+i,4.+i,5.+i);n.pack('<f',cp+0x120,1.25+i);n.pack('<3I',cp+0x14c,*(c['position'] if i==0 else vec([25.+i,35.+i,45.+i])));n.pack('<3f',cp+0x1b4,90.,91.,92.);n.pack('<6I',cp+0x1cc,*range(10,16));n.pack('<ffI',cp+0x1c0,.25,.5,0);n.pack('<I',cp+0x1e8,o.get('flags',0x80000000));n.pack('<I',cp+0x1e4,0)
  n.pack('<B',NODES+0x40*i+0x10,i);n.pack('<I',ROWS+4*i,ROUTES+16*i);n.write(ROUTES+16*i,bytes(route[i]));n.pack('<I',b.actor(i)+0xca4,INPUTS+i*16);n.pack('<II',INPUTS+i*16+4,0x10,0x20)
 n.pack('<I',PATH+0x84,ROWS)
 if o.get('differentPath'):n.pack('<I',controller(1)+0x158,PATH+0x100)
 if o.get('sameNode'):n.pack('<I',controller(1)+0x15c,NODES)
 if not c['reference']:n.pack('<I',CRE+0xd0,0)
 n.pack('<I',CRE+0xe4,b.actor(2) if o.get('opponent') else 0);n.pack('<f',CRE+0x180,o.get('goal',0.));n.pack('<f',b.actor(0)+0x22c,o.get('speed',.75));n.pack('<B',b.actor(0)+0x281,o.get('ground',1));n.pack('<B',CRE+0x13f,o.get('mode',9))
 n.pack('<I',SYS+0x138c,1 if o.get('system',True) else 0);n.pack('<I',0x9238b0,0 if o.get('noTokenCallback') else TOKEN);n.pack('<I',0x9238b8,COMPLETION if o.get('completionCallback') else 0);n.pack('<I',0x9238c0,0)
 n.pack('<I',0x93d810,b.actor(o.get('player0',1)) if o.get('player0',1)>=0 else 0);n.pack('<I',0x93d814,b.actor(o.get('player1',2)) if o.get('player1',2)>=0 else 0)
 n.pack('<f',0x876ce4,o.get('partyOverride',0.));n.pack('<I',0x802280,0x800);n.pack('<I',0x95e5d4,o.get('floatSeed',123))
 for i in range(-128,128):n.pack('<f',0x876c98+4*i,i*.25)
 # The indexed table includes the neighboring override global, which is distinct.
 n.pack('<f',0x876ce4,o.get('partyOverride',0.))
 n.pack('<BB',CALLER+0x68,o.get('packetFlags',0xa0),o.get('hold',0));n.pack('<I',CALLER+0x6c,LOC+o.get('active',0)*0x3c if command=='GoToLocator' and o.get('active',0)>=0 else (b.actor(o['cachedTarget']) if o.get('cachedTarget',-1)>=0 else 0));n.pack('<I',CALLER+0xa4,LOC+c['selected']*0x3c if c['selected']>=0 else 0);n.pack('<f',CALLER+0x9c,o.get('wait',0.));n.pack('<3f',CALLER+0x78,101.,102.,103.)
 for ix,val in [(0,0.),(0x2000,1.),(0x4000,0.),(0x6000,-1.)]:n.pack('<f',0x29899a0+ix*4,val)
 for i,r in enumerate(c['records']):r['heading']=[0,0x4000,0x8000][i%3];n.pack('<I',LOC+i*0x3c+0x1c,r['heading'])
 if 'actorPositions' in o:
  for i,p in enumerate(o['actorPositions']):n.pack('<3f',b.actor(i)+0x5c,*p)
 c['pathWords']=[list(n.unpack('<6I',controller(i)+0x158)) for i in range(3)]
 c['actorPositions']=[list(n.unpack('<3I',b.actor(i)+0x5c)) for i in range(3)]
 c['controllerPositions']=[list(n.unpack('<3I',controller(i)+0x14c)) for i in range(3)]
 c['pathPoints']=[list(n.unpack('<3I',controller(i)+0x170)) for i in range(3)]
 return c
def snapshot(command):
 look=n.unpack('<I',CRE+0x1e4)[0]
 return dict(packetFlags=n.unpack('<B',CALLER+0x68)[0],hold=n.unpack('<B',CALLER+0x69)[0],target=b.idx(n.unpack('<I',CALLER+0x6c)[0]) if command=='GoToLocator' else b.aid(n.unpack('<I',CALLER+0x6c)[0]),wait=n.unpack('<I',CALLER+0x9c)[0],facing=list(n.unpack('<3I',CALLER+0x78)),goal=n.unpack('<I',CRE+0x180)[0],mode=n.unpack('<B',CRE+0x13f)[0],flags=n.unpack('<I',CRE+0x1e8)[0],point=list(n.unpack('<3I',CRE+0x1b4)),radius=n.unpack('<I',CRE+0x1c0)[0],intentGoal=n.unpack('<I',CRE+0x1c4)[0],words=list(n.unpack('<6I',CRE+0x1cc)),look='opponent' if look==b.actor(2)+0x5c else 'packet' if look==CALLER+0x78 else None,actorPosition=list(n.unpack('<3I',b.actor(0)+0x5c)),inputWords=[list(n.unpack('<II',INPUTS+i*16+4)) for i in range(3)],rng=n.unpack('<I',0x8066c0)[0],floatRng=n.unpack('<I',0x95e5d4)[0])
def model(command,tokens,c,o,first,delta,before):
 state=json.loads(json.dumps(before));events=[]
 def lookup(name):events.append(['find',name]);return next((i for i,r in enumerate(c['records']) if r['name'].lower()==name.lower()),-1)
 def draw():state['rng']=b.rng(state['rng']);return b.si(state['rng'])
 def token(text):
  if o.get('noTokenCallback'):return False
  mode={'walk':17,'run':34,'tiptoe':51}.get(text.lower());events.append(['token',text,mode is not None])
  if mode is not None:state['mode']=mode
  return mode is not None
 def evaluate(text):events.append(['expression',text]);return b.number(text)
 def intent(point,radius,words,mode,goal):
  events.append(['intent',point,radius,words,mode,goal]);state.update(point=point,radius=radius,words=words,intentGoal=goal,flags=(state['flags']&~7)|(mode&7))
 def finish(result):return dict(state=state,events=events,result=result)
 valid=c['creature'] and c['reference'] and c['worldObject']>=0
 if command=='GoToLocator':
  if not valid or not o.get('path',True) or not o.get('node',True):return finish(1)
  if first:
   state['packetFlags']=0;state['target']=c['selected'];personal=indexed=False;rand=0;minimum=maximum=0.;i=0
   while i<len(tokens):
    text=tokens[i];low=text.lower()
    if token(text):i+=1;continue
    if 'name' in low or 'teleport' in low:
     i+=1
     if i<len(tokens):
      name=tokens[i]
      if indexed and c['indices'][0]!=-1:name+='_'+str(c['indices'][0])
      elif personal and c['characterNames'][0] is not None:name+='_'+c['characterNames'][0]
      elif rand:name+='_'+str(draw()%abs(rand))
      state['target']=lookup(name)
     if 'teleport' in low:
      if state['target']>=0:state['actorPosition']=c['records'][state['target']]['position']
      return finish(1)
    elif 'personal' in low:personal=True
    elif 'indexed' in low:indexed=True
    elif 'random' in low:rand=int(evaluate(text[low.index('random')+7:]))
    elif 'waittime' in low:state['wait']=bits(evaluate(text[low.index('waittime')+9:]))
    elif 'mintime' in low:minimum=evaluate(text[low.index('mintime')+8:])
    elif 'maxtime' in low:maximum=evaluate(text[low.index('maxtime')+8:])
    elif 'goalrange' in low:state['goal']=bits(evaluate(text[low.index('goalrange')+10:]))
    elif low in ['on_ground','xz_rangecheck','face_opponent','ignore_path','must_reach_destination']:state['packetFlags']|=[1,2,4,8,16][['on_ground','xz_rangecheck','face_opponent','ignore_path','must_reach_destination'].index(low)]
    else:state['goal']=bits(evaluate(text))
    i+=1
   if fl(state['wait'])==0:
    if maximum<=minimum:state['wait']=bits(.01)
    else:state['floatRng']=b.u(state['floatRng']*0x19660d+0x3c6ef35f);value=(state['floatRng']&0x7fffff)/(1<<23);state['wait']=bits(value*(maximum-minimum)+minimum)
   if state['target']<0:return finish(1)
   r=c['records'][state['target']];intent(r['position'],0,r['orientation'],7 if state['packetFlags']&8 else 1,state['goal']);x,y,z=[fl(x) for x in r['position']];dx,dz={0:(0.,1.),0x4000:(1.,0.),0x8000:(0.,-1.)}[r['heading']];state['facing']=vec([f(x+dx),y,f(z+dz)]);return finish(0)
  if state['target']<0:return finish(1)
  r=c['records'][state['target']];intent(r['position'],0,r['orientation'],7 if state['packetFlags']&8 else 1,state['goal'])
  if state['packetFlags']&4 and o.get('opponent'):state['look']='opponent'
  if state['packetFlags']&1 and not o.get('ground',1):return finish(0)
  d=[f(fl(x)-fl(y)) for x,y in zip(c['position'],r['position'])]
  if state['packetFlags']&2:d[1]=0.
  distance=f(sum(x*x for x in d));threshold=f(delta*o.get('speed',.75)+f(fl(state['goal'])+fl(bits(.1))))
  if distance>=threshold*threshold:
   if state['flags']&0x400000 and state['packetFlags']&16 and o.get('completionCallback'):
    events.append(['completion',0,state['target']]);return finish(int(o.get('completionResult',False)))
   return finish(0)
  if not state['packetFlags']&4 or not o.get('opponent'):state['look']='packet'
  if fl(state['wait'])>0:state['wait']=bits(max(0.,f(fl(state['wait'])-delta)));return finish(0)
  return finish(1)
 if not valid or not o.get('system',True):return finish(1)
 if first:
  for text in tokens:
   low=text.lower()
   if token(text):continue
   if low=='ignore_radius':state['packetFlags']|=2
   elif low=='can_go_off_path':state['packetFlags']|=1
   elif low=='hold_special_button':state['hold']=1
   elif low=='nearest':
    p0=o.get('player0',1);p1=o.get('player1',2)
    if p0<0 or p1<0:state['target']=p0
    else:
     pos=[fl(x) for x in c['actorPositions'][0]]
     distances=[f(math.sqrt(f(sum(f(a-fl(v))**2 for a,v in zip(pos,c['actorPositions'][p]))))) for p in [p0,p1]]
     state['target']=p1 if distances[1]<distances[0] else p0
   elif fl(state['goal'])==0:state['goal']=bits(b.number(text))
 p0=o.get('player0',1)
 if state['target']<0 and p0<0:return finish(0)
 goal=fl(state['goal']);ix=c['indices'][0]
 if ix!=-1:goal=.01 if o.get('partyOverride',0)>0 else f(ix*.25+goal)
 flags=state['packetFlags'];direct=False
 if flags&1:
  direct=not o.get('path',True) or o.get('differentPath',False)
  if not direct:direct=(not o.get('targetNodeFlags',0)&1 and o.get('sameNode',False)) or not o.get('node',True) or bool(state['flags']&0x100000)
  if not direct:targetix=0 if o.get('sameNode') else p0;direct=o.get('route',[[0,1,2],[0,1,2],[0,1,2]])[0][targetix]==255 and targetix!=0
 intent(c['controllerPositions'][p0] if direct else c['pathPoints'][p0],0 if flags&2 else bits(1.25+p0),c['pathWords'][p0],7 if direct else 1,bits(goal))
 if state['hold']:j=c['worldObject'];state['inputWords'][j]=[x|0x800 for x in state['inputWords'][j]]
 return finish(0)
def check(kind,got,want,meta):
 checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,got=got,want=want,input=meta))
def run(command,tokens,o=None,first=True,delta=.125,source=None):
 o=o or {};c=setup(command,tokens,o);before=snapshot(command);delta=f(delta)
 value=n.call(0x536700 if command=='GoToLocator' else 0x452570,[SYS,CALLER,CRE if c['creature'] else 0,ARGS,len(tokens),int(first),bits(delta)],count=1000000)
 got=dict(state=snapshot(command),events=list(b.events),result=value);want=model(command,tokens,c,o,first,delta,before)
 for key in got:check(command+'-'+key,got[key],want[key],dict(tokens=tokens,options=o,first=first,source=source))
 vectors.append(dict(command=command,tokens=tokens,options=o,context=c,first=first,delta=bits(delta),source=source,before=before,native=got))
if __name__=='__main__':
 for command in ['GoToLocator','FollowPlayer']:
  for use in uses[command]:
   for first in [True,False]:run(command,use['args'],first=first,source={k:use[k] for k in ['source','line','text']})
 for tokens in [[],['name','Target'],['name=Target'],['teleport','Target'],['walk','name','Target','goalrange=2'],['personal','name','Target'],['indexed','name','Target'],['random=3','name','Target'],['name','Target','indexed'],['waittime=.5'],['mintime=.25','maxtime=1'],['goalrange=2','goalrange=3'],['ignore_path','on_ground','xz_rangecheck','face_opponent','must_reach_destination']]:
  for options in [{},{'selected':-1},{'wait':.5},{'noTokenCallback':True},{'path':False},{'node':False},{'reference':False}]:run('GoToLocator',tokens,options)
 for position,wait,flags,ground,opponent in itertools.product([[10.,20.,30.],[10.1,20.,30.],[15.,25.,35.]],[0.,.125,.1],[0,1,2,4,8,16,31],[0,1],[False,True]):
  run('GoToLocator',[],dict(position=position,wait=wait,packetFlags=flags,ground=ground,opponent=opponent,flags=0x400000,completionCallback=True,completionResult=True),first=False)
 for tokens in [[],['nearest'],['hold_special_button'],['can_go_off_path'],['can_go_off_path','ignore_radius'],['0','1.5','2'],['walk','run','tiptoe'],['add_party_offset']]:
  for options in [{},{'differentPath':True},{'sameNode':True},{'sameNode':True,'targetNodeFlags':1},{'route':[[0,255,255],[0,1,2],[0,1,2]]},{'flags':0x100000},{'partyOverride':1.},{'indices':[-1,-1,-1]},{'system':False},{'player0':-1,'player1':-1},{'path':False}]:run('FollowPlayer',tokens,options)
 rng=random.Random(0x515ca0)
 for i in range(120):
  own=[f(rng.uniform(-100000,100000)) for _ in range(3)];near=[f(rng.uniform(-100000,100000)) for _ in range(3)];other=list(near);other[i%3]=f(other[i%3]+rng.choice([-1,1])*2**rng.randrange(-10,4))
  run('FollowPlayer',['nearest'],dict(actorPositions=[own,near,other]))
 result=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:15],authoredOccurrences={k:len(v) for k,v in uses.items()},cases=len(vectors),method='Original PC handlers, original0x52fcb0 intent writes and0x534e10 route selection, original locator/string/numeric/expression/RNG/vector helpers. CRT formatting and movement-token/completion callbacks are explicit fixture services.',limits=['Synthetic valid path/node/actor relationships; no actual world pathfinder, motion integration or terrain stepping.','Formation record is null in this suite; native formation-mode delegation is a separate boundary.','Movement token callback consumes walk/run/tiptoe using fixture markers, not claimed runtime speed-mode semantics.','Expression evaluation executes original PC code in fixtures; portable general expression evaluation remains a supplied service.','Finite scalar fixtures; arbitrary x87 rounding, NaN/overflow and bad pointer domains are excluded.','Managed compiled comparison remains pending.'])
 (BASE/'reports/gameplay-movement-tests.json').write_text(json.dumps(result,indent=2),encoding='utf8');(BASE/'reports/gameplay-movement-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');print(json.dumps(result))
 if errors:raise SystemExit(1)
