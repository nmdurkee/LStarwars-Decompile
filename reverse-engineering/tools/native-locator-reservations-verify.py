"""Original locator reservations and formation release; no game process launch."""
import importlib.util,json,random,copy,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('actors',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
n=a.n;B=a.BASE;D=a.D;SET=D+0x60000;IND=SET+0x100;OWN=SET+0x200;LOC=SET+0x1000;PK=SET+0x10000;FORM=SET+0x18000
vectors=[];errors=[];groups={};memory_checks=0
uses={r['name']:r['uses'] for r in a.ledger['rows'] if r['name'] in ['ReleaseLocator','BreakFormation']}
def case_context(o):
 c=a.context(o)
 for i,r in enumerate(c['actors']):
  r.update(dict(packet=True,selected=i,token=0x12340000+i,state406=0,deathState=0,deathTimer=1.,ownerId=i))
  r.update(o.get('reservationOverrides',{}).get(str(i),{}))
 return c

def setup(c,tokens,o):
 a.setup(dict(c,count=c['count']&0xffffffff),tokens);n.write(SET,bytes(0x19000));n.pack('<I',a.SYS+0x28,LOC);n.pack('<I',0x9238dc,0x43c7a0 if o.get('indexCallback',True) else 0)
 for i,r in enumerate(c['actors']):
  p=a.actor(i);n.pack('<I',p+4,PK+i*0x100 if r['packet'] else 0);n.pack('<I',PK+i*0x100+0xa4,0 if r['selected'] is None else LOC+r['selected']*0x3c)
  n.pack('<I',p+0x36c,r['token']);n.pack('<B',p+0x406,r['state406']);n.pack('<B',p+0x28b,r['deathState']);n.pack('<B',p+0x28d,r['ownerId']);n.pack('<f',p+0x1010,r['deathTimer'])
 count=o.get('setCount',8);indices=o.get('indices',list(range(8)));owners=o.get('owners',list(range(8)))
 n.pack('<b',SET+0x10,count);n.pack('<II',SET+0x14,IND,OWN);n.write(IND,bytes(indices));n.write(OWN,bytes(owners));n.pack('<I',a.CRE+0x144,FORM if o.get('formation',True) else 0);n.pack('<I',FORM+0x50,o.get('formationFlags',0xa5a5a5af))
 return indices,owners

def find(c,index):
 index &=255
 if index>=c['count']:return -1
 r=c['actors'][index];flags=r['state'][1]
 return index if flags&1 and (flags&0x1000 or r['state406']==3) and (not r['deathState'] or r['deathTimer']>0) else -1

def run(kind,o={},tokens=[],first=True,source=None):
 global memory_checks
 c=case_context(o);indices,owners=setup(c,tokens,o)
 regions=[(a.ACT,8*0x10d8),(OWN,len(owners)),(PK,8*0x100),(FORM,0x60)]
 before=[n.read(p,z) for p,z in regions];expected=[bytearray(x) for x in before]
 want=dict(result=None,tokens=[r['token'] for r in c['actors']],selected=[r['selected'] for r in c['actors']],owners=owners[:],formation=o.get('formationFlags',0xa5a5a5af),events=[])
 if kind=='index':
  ix=o.get('index',0);want['result']=find(c,ix);result=a.aid(n.call(0x43c7a0,[ix&0xffffffff]))
 elif kind=='refresh':
  if o.get('set',True) and o.get('indexCallback',True):
   for i in range(max(0,o.get('setCount',8))):
    owner=owners[i]
    if owner in [128,255]:continue
    ix=find(c,owner);selected=255
    if ix>=0 and c['actors'][ix]['packet'] and c['actors'][ix]['selected'] is not None:selected=c['actors'][ix]['selected']&255
    if selected!=indices[i]:want['owners'][i]=255
  expected[1][:]=bytes(want['owners']);n.call(0x51fe60,[a.SYS,SET if o.get('set',True) else 0]);result=None
 elif kind=='release':
  want['result']=1
  if first:
   ref=c['reference'] if c['creature'] else -1;target=c['actors'][ref]['world'] if ref>=0 else -1
   for token in tokens:
    low=token.split('\0')[0].lower();at=low.find('character=')
    if at<0:continue
    name=token.split('\0')[0][at+10:];ix=a.resolve_name(c,name) if c['callback'] else -1
    if c['callback']:want['events'].append(['name',name])
    target=c['actors'][ix]['world'] if ix>=0 else -1
   if target>=0:want['tokens'][target]=0;struct.pack_into('<I',expected[0],target*0x10d8+0x36c,0)
  result=n.call(0x453810,[a.SYS if c['system'] else 0,a.PACK,a.CRE if c['creature'] else 0,a.ARGS,len(tokens),int(first)])
 elif kind=='break':
  want['result']=1
  if c['creature'] and o.get('formation',True):want['formation'] &=0xfffffff7
  struct.pack_into('<I',expected[3],0x50,want['formation']);result=n.call(0x449c90,[a.SYS,a.PACK,a.CRE if c['creature'] else 0,a.ARGS,len(tokens),int(first)])
 else:raise ValueError(kind)
 got=dict(result=result,tokens=[n.unpack('<I',a.actor(i)+0x36c)[0] for i in range(8)],selected=[None if n.unpack('<I',PK+i*0x100+0xa4)[0]==0 else (n.unpack('<I',PK+i*0x100+0xa4)[0]-LOC)//0x3c for i in range(8)],owners=list(n.read(OWN,len(owners))),formation=n.unpack('<I',FORM+0x50)[0],events=copy.deepcopy(a.events))
 failures=[]
 if got!=want:failures.append(dict(got=got,want=want))
 for i,(p,z) in enumerate(regions):
  memory_checks+=1
  actual=n.read(p,z)
  if actual!=expected[i]:failures.append(dict(region=i,firstByte=next(k for k,(x,y) in enumerate(zip(actual,expected[i])) if x!=y)))
 groups[kind]=groups.get(kind,0)+1
 if failures:errors.append(dict(kind=kind,options=o,tokens=tokens,failures=failures))
 vectors.append(dict(kind=kind,options=o,context=c,tokens=tokens,first=first,indices=indices,owners=owners,source=source,native=got))

def main():
 for command,kind in [('ReleaseLocator','release'),('BreakFormation','break')]:
  for use in uses[command]:
   for first in [True,False]:run(kind,tokens=use['args'],first=first,source=use)
 for flags in [0,1,0x1000,0x1001,0xffffffff]:
  for state in [0,3,4,255]:
   for death in [0,1,255]:
    for timer in [-1.,0.,1e-40,2.]:
     run('index',dict(index=0,reservationOverrides={'0':dict(state406=state,deathState=death,deathTimer=timer)},actorOverrides={'0':dict(active=flags)}))
 for index in [-1,0,1,7,8,127,128,255,256,257,511,512]:
  for count in [-1,0,1,8]:run('index',dict(index=index,count=count))
 for owners in [list(range(8)),[255]*8,[128]*8,[7,6,5,4,3,2,1,0],[1,1,1,1,1,1,1,1],[254,127,128,255,0,8,2,7]]:
  for options in [{},{'indexCallback':False},{'set':False},{'setCount':0},{'setCount':-128},{'setCount':1},{'count':0},{'reservationOverrides':{'1':{'selected':None},'2':{'packet':False},'3':{'selected':255},'4':{'selected':256},'5':{'deathState':1,'deathTimer':0.}}}]:
   run('refresh',dict(options,owners=owners))
 rng=random.Random(453810)
 for j in range(160):
  o=dict(owners=[rng.choice([0,1,2,3,4,5,6,7,128,255,127]) for _ in range(8)],indices=[rng.choice(list(range(10))+[255]) for _ in range(8)],reservationOverrides={str(i):dict(selected=rng.choice([None]+list(range(9))+[255,256]),packet=rng.choice([False,True]),state406=rng.randrange(5),deathState=rng.randrange(2),deathTimer=rng.choice([-1.,0.,1.])) for i in range(8)},actorOverrides={str(i):dict(active=rng.choice([0,1,0x1001])) for i in range(8)})
  run('refresh',o)
 for tokens in [[],['character=Player'],['character=Alpha'],['character=missing'],['character=Alpha','character=missing'],['character=missing','xxCHARACTER=Beta'],['character=Player0'],['character=player_2'],['character=Beta\0character=Alpha']]:
  for o in [{},{'creature':False},{'reference':-1},{'callback':False},{'system':False},{'actorOverrides':{'1':{'world':3}}},{'actorOverrides':{'1':{'world':-1}}}]:
   run('release',o,tokens)
 for flags in [0,8,0xffffffff,0xa5a5a5a5]:
  for creature in [True,False]:
   for formation in [True,False]:run('break',dict(formationFlags=flags,creature=creature,formation=formation),first=False)
 report=dict(binarySha256=n.sha256,checks=len(vectors),mismatches=len(errors),groups=groups,fullRegionComparisons=memory_checks,authoredUses={k:len(v) for k,v in uses.items()},examples=errors[:8],method='Original command, index callback, reservation refresh and actual name binding execute unchanged. Only bounded CRT Player%d formatting is substituted. Complete actor, packet, owner and formation memory images are checked for collateral writes.',limits=['Valid nonoverlapping actor/packet/set/formation storage; selected locator indices represent aligned pointers relative to one locator base, no address wrap.','ASCII names, finite death timer, active table backing valid for every reachable index; count and set count preserve signed comparisons.','Managed replay is prepared and compiled, not executed.'])
 (B/'reports/native-locator-reservations-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-locator-reservations-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
