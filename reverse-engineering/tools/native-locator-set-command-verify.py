import importlib.util,json,random,struct,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('selection',Path(__file__).with_name('native-locator-selection-verify.py'));sel=importlib.util.module_from_spec(s);s.loader.exec_module(sel);r=sel.r;a=r.a;n=r.n;v=sel.v;B=r.B
s=importlib.util.spec_from_file_location('traversal',Path(__file__).with_name('native-locator-traversal-verify.py'));tr=importlib.util.module_from_spec(s);s.loader.exec_module(tr)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
ARRAY=a.D+0x80000;WORLD=a.D+0x90000
rows=[];errors=[];groups={};memory=0;calls=[]
uses=next(x['uses'] for x in a.ledger['rows'] if x['name']=='GetLocatorFromSet')
def observe(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x51ac70:calls.append(['set',a.string(n.unpack('<I',sp+8)[0])])
 elif address==0x5147c0:calls.append(['number',a.string(n.unpack('<I',sp+8)[0])])
 else:calls.append(['select',{0x440660:'next',0x520220:'random',0x520080:'farthest',0x51fef0:'nearest'}[address]])
for address in [0x51ac70,0x5147c0,0x440660,0x520220,0x520080,0x51fef0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)

def model(c,o,indices,owners,tokens,first,names):
 result=dict(result=1,selected=[x['selected'] for x in c['actors']],owners=owners[:],flags=[x['state'][1] for x in c['actors']],random=o['random'],qrandom=o.get('qrandom',12345),events=[]);log=[]
 if not first:return result,log
 target=c['actors'][c['reference']]['world'] if c['creature'] and c['reference']>=0 else -1
 ran=radius=0.;ignore=-1;name=None;flags=set()
 for token in tokens:
  token=token.split('\0')[0];low=token.lower()
  if 'character='in low:
   nameArg=token[low.index('character=')+10:];ix=a.resolve_name(c,nameArg) if c['callback'] else -1
   if c['callback']:result['events'].append(['name',nameArg])
   target=c['actors'][ix]['world'] if ix>=0 else -1
  else:
   matched=False
   for key,mark in [('max_range=',''),('max_player_range=','primary'),('max_opponent_range=','opponent'),('off_screen_radius=','radius'),('name=','name')]:
    if key not in low:continue
    value=token[low.index(key)+len(key):];matched=True
    if mark=='name':name=value
    else:
     log.append(['number',value]);number=a.number(value)
     if mark=='radius':radius=number
     else:ran=number
     if mark in ['primary','opponent']:flags.add(mark)
    break
   if matched:continue
   if low in ['random','next','first','looping','finish_at_end']:flags.add(low)
   elif low=='ignore_assigned=true':ignore=1
   elif low=='ignore_assigned=false':ignore=0
   elif low=='furthest_from_opponent':flags.update(['opponent','farthest'])
   elif low=='furthest_from_either_player':flags.update(['primary','secondary','farthest'])
   elif low=='nearest_either_player':flags.update(['primary','secondary'])
 if ignore<0:ignore=0 if 'next'in flags else 1
 if target<0:return result,log
 present=o.get('currentSet',True)
 if name is not None:
  log.append(['set',name]);present=o.get('globalSetSystem',True) and any(x.lower()==name.lower() for x in names[:max(0,o.get('collectionCount',len(names)))])
 if not present:return result,log
 if 'first'in flags:
  if o.get('setCount',8)!=0:result['selected'][target]=indices[0];result['owners'][0]=c['actors'][target]['ownerId']
  return result,log
 if 'next'in flags:
  log.append(['select','next']);z=tr.model(c,dict(o,target=target,random=result['qrandom'],ignoreAssigned=bool(ignore),looping='looping'in flags,finishAtEnd='finish_at_end'in flags),indices,owners);result.update(selected=z['selected'],owners=z['owners'],flags=z['flags'],qrandom=z['random']);return result,log
 ref=target
 if 'primary'in flags:ref=c['primary']
 elif 'opponent'in flags and o.get('opponents',[3]*8)[target]>=0:ref=o.get('opponents',[3]*8)[target]
 primary=c['actors'][ref]['position'];second=c['actors'][o.get('secondaryPlayer',2)]['position'] if 'secondary'in flags and o.get('secondaryPlayer',2)>=0 else None
 kind='random' if 'random'in flags else 'farthest' if 'farthest'in flags else 'nearest';log.append(['select',kind]);z=sel.model(c,dict(o,target=target,range=ran,radius=radius,primary=primary,secondary=second,ignoreAssigned=bool(ignore)),indices,owners,kind);result.update(selected=z['selected'],owners=z['owners'],random=z['random']);return result,log

def run(tokens,options={},first=True,source=None):
 global memory
 o=sel.defaults(options);c=r.case_context(dict(o,primary=o.get('primaryPlayer',1)));indices,owners=r.setup(c,tokens,o)
 names=o.get('names',['SetA','Other','seta'])
 if o.get('bindAuthored',False):
  found=[x[x.lower().index('name=')+5:] for x in tokens if 'name='in x.lower()]
  if found:names=[found[-1],'Other',found[-1].upper()]
 for name in names:assert len(name)<16
 n.write(ARRAY,bytes(0x1000));n.write(WORLD,bytes(0x3000));n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x2ae8,a.SYS if o.get('globalSetSystem',True) else 0);n.pack('<iI',a.SYS+0x2c,o.get('collectionCount',len(names)),ARRAY);n.pack('<I',a.PACK+0xa8,r.SET if o.get('currentSet',True) else 0)
 for i,name in enumerate(names):n.write(ARRAY+i*0x1c,name.encode()+b'\0');n.pack('<b',ARRAY+i*0x1c+0x10,o.get('setCount',8));n.pack('<II',ARRAY+i*0x1c+0x14,r.IND,r.OWN)
 for i,p in enumerate(o['positions']):n.pack('<3f',r.LOC+i*0x3c+0x10,*p)
 for i,ix in enumerate(o.get('opponents',[3]*8)):n.pack('<I',a.actor(i)+0x3ac,a.actor(ix))
 n.pack('<I',0x93d814,a.actor(o.get('secondaryPlayer',2)));n.pack('<16f',0x806680,*o['object']);n.pack('<16f',0x80b708,*o['view']);n.pack('<16f',0x80b988,*o['planes']);n.pack('<2f',0x973730,o['near'],o['far']);n.pack('<I',0x95e5d4,o['random']);n.pack('<I',0x80253c,o.get('qrandom',12345));calls.clear()
 want,log=model(c,o,indices,owners,tokens,first,names);regions=[(a.ACT,8*0x10d8),(r.OWN,len(owners)),(r.PK,8*0x100),(a.PACK,0x100),(ARRAY,0x1000)];expected=[bytearray(n.read(p,z)) for p,z in regions]
 for i in range(8):struct.pack_into('<I',expected[0],i*0x10d8+0x1fc,want['flags'][i]);struct.pack_into('<I',expected[2],i*0x100+0xa4,0 if want['selected'][i] is None else r.LOC+want['selected'][i]*0x3c)
 expected[1][:]=bytes(want['owners']);ret=n.call(0x453aa0,[a.SYS if c['system'] else 0,a.PACK,a.CRE if c['creature'] else 0,a.ARGS,len(tokens),int(first)])
 got=dict(result=ret,selected=[None if n.unpack('<I',r.PK+i*0x100+0xa4)[0]==0 else (n.unpack('<I',r.PK+i*0x100+0xa4)[0]-r.LOC)//0x3c for i in range(8)],owners=list(n.read(r.OWN,len(owners))),flags=[n.unpack('<I',a.actor(i)+0x1fc)[0] for i in range(8)],random=n.unpack('<I',0x95e5d4)[0],qrandom=n.unpack('<I',0x80253c)[0],events=copy.deepcopy(a.events));bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if calls!=log:bad.append(dict(calls=calls,wantCalls=log))
 for i,(p,z) in enumerate(regions):
  memory+=1
  if n.read(p,z)!=expected[i]:bad.append(dict(region=i))
 if bad:errors.append(dict(tokens=tokens,options=o,bad=bad))
 rows.append(dict(tokens=tokens,options=o,context=c,indices=indices,owners=owners,names=names,first=first,source=source,native=got,calls=copy.deepcopy(calls)));groups['authored' if source else 'synthetic']=groups.get('authored' if source else 'synthetic',0)+1

def main():
 for use in uses:
  for options,first in [({'bindAuthored':True},True),({'currentSet':False},True),({'bindAuthored':True},False)]:run(use['args'],options,first,use)
 tokenLists=[[],['first'],['next'],['random'],['furthest_from_opponent'],['furthest_from_either_player'],['nearest_either_player'],['first','next','random'],['next','random'],['random','furthest_from_either_player'],['name=SetA'],['name=missing'],['name=missing','NAME=Other'],['character=missing'],['character=Player'],['character=Beta','character=missing'],['character=missing','xxCHARACTER=Beta'],['max_range=5'],['max_player_range=5'],['max_opponent_range=5'],['max_player_range=5','max_range=2'],['max_player_range=alpha','max_opponent_range=param3'],['off_screen_radius=1','random'],['off_screen_radius=1','nearest_either_player'],['ignore_assigned=TRUE','next'],['ignore_assigned=FALSE'],['ignore_assigned=FALSE','ignore_assigned=TRUE'],['xxmax_range=3name=missing'],['name=SetAcharacter=Beta'],['NEXT','looping'],['next','finish_at_end']]
 for tokens in tokenLists:
  for o in [{},{'creature':False},{'reference':-1},{'callback':False},{'opponents':[-1]*8},{'secondaryPlayer':-1},{'globalSetSystem':False},{'setCount':0},{'setCount':-1},{'collectionCount':-1},{'actorOverrides':{'1':{'world':4}}},{'owners':[128]*8,'reservationOverrides':{'0':{'selected':7}}}]:run(tokens,o)
 rng=random.Random(453000)
 for i in range(200):
  tokens=rng.sample(['next','random','first','looping','finish_at_end','nearest_either_player','furthest_from_opponent','max_range=5','max_player_range=10','max_opponent_range=7','ignore_assigned=TRUE','ignore_assigned=FALSE','name=SetA','name=missing','character=Player','character=Beta','off_screen_radius=2'],rng.randrange(1,7));run(tokens,dict(random=rng.randrange(2**32),qrandom=rng.randrange(2**32),actorOverrides={'0':{'active':rng.choice([0x1001,0x101001])}}))
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,authoredUses=131,fullRegionComparisons=memory,examples=errors[:8],method='Full original453aa0 with real ordered parsing/numeric resolver/name callback/set lookup/reservation refresh/selection/culling/RNG. Only bounded CRT Player%d formatting is replaced. Separate helper-order and complete region comparisons.',limits=['Valid prepared runtime actor/packet/locator collections and primary player when a selector reads that position. ASCII tokens and bounded numeric operands.','Original world-owned name collection and caller-owned locator base remain distinct supplied records; attached set records may share index/owner arrays.','Managed replay pending; no live navigation/locomotion or world-loader equivalence.'])
 (B/'reports/native-locator-set-command-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-locator-set-command-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
