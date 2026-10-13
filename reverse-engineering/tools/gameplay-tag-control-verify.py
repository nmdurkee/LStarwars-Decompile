"""Original SetTaggable -> candidate selection -> player refresh chain.
Character transfer and takeover release are explicit observable world services.
"""
import importlib.util,json,itertools,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('actors',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
n=a.n;BASE=a.BASE;D=a.D;current={};checks={};errors=[];vectors=[]
uses=next(r['uses'] for r in a.ledger['rows'] if r['name']=='SetTaggable')
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x4876a0:
  x,y=a.aid(arg(0)),a.aid(arg(1));a.events.append(['transfer',x,y,arg(2),arg(3),arg(4)])
  if current.get('mutateTransfer'):
   for ix in [x,y]:n.pack('<I',a.actor(ix)+0x1fc,n.unpack('<I',a.actor(ix)+0x1fc)[0]^0x1080)
  a.ret(mu,current.get('transferResult',1))
 elif address==0x4882d0:
  x=a.aid(arg(0));a.events.append(['release',x])
  if current.get('mutateRelease'):n.pack('<I',a.actor(x)+0x1fc,n.unpack('<I',a.actor(x)+0x1fc)[0]^0x80)
  a.ret(mu,0)
for address in [0x4876a0,0x4882d0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def context(o):
 options=copy.deepcopy(o);options.setdefault('primary',0);options.setdefault('players',[0,1,2,3,4,5,6,7]);options.setdefault('actorOverrides',{});options['actorOverrides'].setdefault('0',{});options['actorOverrides']['0'].setdefault('active',0x1081)
 c=a.context(options);c['secondary']=o.get('secondary',7);c['tags']=[]
 for i in range(8):
  t=dict(flags=0xa8,blocked=0,linked=-1,wait=a.bits(1.25),target=-1);t.update(o.get('tagOverrides',{}).get(str(i),{}));c['tags'].append(t)
 return c
def setup(c,tokens,o):
 global current
 current=o;a.setup(c,tokens);n.pack('<I',0x93d814,a.actor(c['secondary']))
 for i,t in enumerate(c['tags']):
  p=a.actor(i);n.pack('<B',p+0x7c5,t['flags']);n.pack('<B',p+0x28b,t['blocked']);n.pack('<I',p+0xcd0,a.actor(t['linked']));n.pack('<I',p+0x7c0,t['wait']);n.pack('<I',p+0x7c8,a.actor(t['target']))
def snapshot():
 return dict(primary=a.aid(n.unpack('<I',0x93d810)[0]),secondary=a.aid(n.unpack('<I',0x93d814)[0]),actors=[[n.unpack('<I',a.actor(i)+0x1fc)[0],n.unpack('<B',a.actor(i)+0x7c5)[0],n.unpack('<I',a.actor(i)+0x7c0)[0],a.aid(n.unpack('<I',a.actor(i)+0x7c8)[0])] for i in range(8)])
def model(kind,tokens,c,o,first=True,target=-1):
 state=dict(primary=c['primary'],secondary=c['secondary'],actors=[[x['state'][1],t['flags'],t['wait'],t['target']] for x,t in zip(c['actors'],c['tags'])]);events=[]
 def refresh():
  p,q=c['players'][:2];p=p if p>=0 and state['actors'][p][0]&0x80 else -1;q=q if q>=0 and state['actors'][q][0]&0x80 else -1
  if p<0 and q<0:state['primary']=-1;return
  state['primary']=p if p>=0 else q;state['secondary']=q if p>=0 else -1
 def candidate(own,preferred):
  def valid(ix):return ix>=0 and ix!=own and (state['actors'][ix][0]&0x1081)==0x1001 and not c['tags'][ix]['blocked'] and not state['actors'][ix][1]&2
  chosen=preferred if valid(preferred) else next((i for i in c['players'] if valid(i)),-1)
  if chosen<0:return 0
  oldOwn,oldTarget=state['actors'][own][0],state['actors'][chosen][0];events.append(['transfer',own,chosen,0,0,o.get('transferArgument',0)])
  if o.get('mutateTransfer'):
   for i in [own,chosen]:state['actors'][i][0]^=0x1080
  result=o.get('transferResult',1)
  if result==2:state['actors'][own][2]=a.bits(3.);state['actors'][own][3]=chosen;state['actors'][own][1]=(state['actors'][own][1]&~8)|4;return 0
  if result==0:return 0
  state['actors'][chosen][0]=(state['actors'][chosen][0]&~0x80)|(oldOwn&0x80);state['actors'][own][0]=(state['actors'][own][0]&~0x80)|(oldTarget&0x80);return 1
 if kind=='refresh':refresh();result=None
 elif kind=='candidate':result=candidate(o.get('own',0),target)
 else:
  result=1
  if first:
   ref=c['reference'] if c['creature'] else -1;who=c['actors'][ref]['world'] if ref>=0 else -1;tag=-1;disabled=False
   for t in tokens:
    low=t.lower()
    if 'character=' in low or 'tag_to=' in low:
     key='character=' if 'character=' in low else 'tag_to=';name=t[low.index(key)+len(key):];ix=-1
     if c['callback']:events.append(['name',name]);ix=a.resolve_name(c,name)
     found=c['actors'][ix]['world'] if ix>=0 else -1
     if key=='character=':who=found
     else:tag=found
    elif low=='false':disabled=True
   if who>=0:
    if disabled and state['actors'][who][0]&0x80:
     if c['tags'][who]['linked']<0:
      if candidate(who,tag)==0:disabled=False
     else:
      events.append(['release',who])
      if o.get('mutateRelease'):state['actors'][who][0]^=0x80
     refresh()
    state['actors'][who][1]=(state['actors'][who][1]&~2)|(2 if disabled else 0)
 return dict(result=result,state=state,events=events)
def run(kind='command',tokens=None,o=None,first=True,target=-1,source=None):
 tokens=tokens or [];o=o or {};c=context(o);setup(c,tokens,o)
 if kind=='command':result=n.call(0x44f930,[a.SYS if c['system'] else 0,a.PACK,a.CRE if c['creature'] else 0,a.ARGS,len(tokens),int(first)],count=1000000)
 elif kind=='candidate':result=n.call(0x487ca0,[a.actor(o.get('own',0)),a.actor(target),o.get('transferArgument',0)])
 else:n.call(0x55e410,[]);result=None
 got=dict(result=result,state=snapshot(),events=a.events.copy());want=model(kind,tokens,c,o,first,target);checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,tokens=tokens,options=o,first=first,target=target,got=got,want=want))
 vectors.append(dict(kind=kind,tokens=tokens,options=o,context=c,first=first,target=target,source=source,native=got))
def main():
 for row in uses:
  for first in [False,True]:run(tokens=row['args'],first=first,source={k:row[k] for k in ['source','line','state']})
 for tokens,o in itertools.product([[],['FALSE'],['FALSE','TRUE'],['tag_to=Beta','FALSE'],['tag_to=missing','FALSE'],['character=order66','FALSE'],['character=missing','FALSE'],['prefixtag_to=Player2','FALSE'],['character=Alpha','tag_to=Alpha','FALSE']],[{},dict(creature=False),dict(reference=-1),dict(callback=False),dict(transferResult=0),dict(transferResult=2),dict(transferResult=-1),dict(mutateTransfer=True),dict(tagOverrides={'0':dict(linked=1)}),dict(tagOverrides={'0':dict(linked=1)},mutateRelease=True)]):run(tokens=tokens,o=o)
 for active,tag,blocked in itertools.product([0,1,0x80,0x1000,0x1001,0x1081,0xffffffff],[0,2,4,8,0xff],[0,1,255]):
  run('candidate',o=dict(players=[-1]*8,actorOverrides={'1':dict(active=active)},tagOverrides={'1':dict(flags=tag,blocked=blocked)}),target=1)
 for target,result,mutation in itertools.product([-1,0,1,7],[0,1,2,-1],[False,True]):run('candidate',o=dict(transferResult=result,mutateTransfer=mutation,transferArgument=0xabcdef01),target=target)
 for ix in range(8):
  tags={str(i):dict(blocked=int(i!=ix)) for i in range(8)};run('candidate',o=dict(tagOverrides=tags,actorOverrides={'0':dict(active=0x1001)},own=7 if ix==0 else 0),target=-1)
 for p,q,ap,aq,secondary in itertools.product([-1,0,1],[-1,0,1],[0x1001,0x1081],[0x1001,0x1081],[-1,7]):
  run('refresh',o=dict(players=[p,q,-1,-1,-1,-1,-1,-1],actorOverrides={'0':dict(active=ap),'1':dict(active=aq)},secondary=secondary))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:10],authoredOccurrences={'SetTaggable':len(uses)},method='Original SetTaggable, registered name resolver, transfer-candidate selector and primary-player refresh execute as a chain. Only full character transfer0x4876a0, takeover release0x4882d0 and bounded CRT formatting are service fixtures.',limits=['Character transfer/world ownership implementation and vehicle/takeover release side effects remain explicit adapters.','Actor records and player arrays use valid bounded identities; ASCII token strings.','Managed replay compiled only; no generated executable launch.'])
 (BASE/'reports/gameplay-tag-control-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-tag-control-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,typeNames=a.TYPE_NAMES,cases=vectors),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
