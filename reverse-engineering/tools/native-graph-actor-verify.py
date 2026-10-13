import importlib.util,json,struct,itertools,copy,random,gzip
from pathlib import Path
s=importlib.util.spec_from_file_location('gizmo',Path(__file__).with_name('native-gizmo-conditions-verify.py'));q=importlib.util.module_from_spec(s);s.loader.exec_module(q);n=q.n;B=q.B;D=q.D
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
WORLDS=[D+0x20000,D+0x31000];SYSTEMS=[D+0x23000,D+0x34000];SPAWNS=[D+0x24000,D+0x35000];ACT=D+0x40000;GIT=D+0x44000;ARGS=D+0x45000;TEXT=D+0x46000
current={};releases=0;getters=0;rows=[];errors=[];excluded=[];groups={};visited=set()
def actor(i):return 0 if i<0 else ACT+i*0x1100
def aid(p):return -1 if not p else (p-ACT)//0x1100
def obj(t,i):return q.OBJECTS+t*0x1000+i*0x100
def oid(p):return None if not p else [(p-q.OBJECTS)//0x1000,((p-q.OBJECTS)%0x1000)//0x100]
def word(t,i):return [0x3f800000+t*0x10000+i,0x80000000,0xc0400000+i]
def heading(t,i):return (t*17001+i*11003)&65535
def cstr(p):
 if not p:return None
 b=bytearray()
 while n.read(p,1)!=b'\0':b.extend(n.read(p,1));p+=1
 return b.decode('ascii')
def options(o):
 p=q.options({});p.update(tokens=['name=alpha'],count=None,buildType=0,primary=0,secondary=1,actors=[dict(flags=0x1001,blocked=0,spawn=0),dict(flags=0x1001,blocked=0,spawn=1),dict(flags=0x1001,blocked=0,spawn=2)],world=0,success=True,releaseMutation='none',placementMutation=False);p.update(copy.deepcopy(o));return p
def setup(o):
 global releases,getters
 q.setup(o,None);n.write(D+0x1b000,bytes(0x35000));current.clear();current.update(o);releases=0;getters=0
 n.pack('<I',0x802c54,0 if o['world']<0 else WORLDS[o['world']]);n.pack('<i',0x804e44,o['buildType']);n.pack('<I',GIT,q.REG if o['registry'] else 0)
 for w in range(2):
  n.pack('<I',WORLDS[w]+0x2ae8,SYSTEMS[w]);n.pack('<I',SYSTEMS[w]+0x18,SPAWNS[w])
  for i in range(256):n.write(SPAWNS[w]+i*0xa4,(['alpha','beta','alpha'] if w==0 else ['beta','alpha','beta'])[i%3].encode()+b'\0')
 for i,a in enumerate(o['actors']):n.pack('<I',actor(i)+0x1fc,a['flags']);n.pack('<B',actor(i)+0x28b,a['blocked']);n.pack('<B',actor(i)+0x400,a['spawn'])
 n.pack('<II',0x93d7f0,actor(o['primary']),actor(o['secondary']))
 for t in range(5):
  for i in range(4):n.pack('<3I',obj(t,i)+0x34,*word(t,i));n.pack('<H',obj(t,i)+0x74,heading(t,i))
 offset=0
 for i,token in enumerate(o['tokens']):
  n.pack('<I',ARGS+i*4,TEXT+offset);b=token.encode()+b'\0';n.write(TEXT+offset,b);offset+=len(b)
def observe(mu,address,size,user):
 global releases,getters
 if 0x4648e0<=address<0x464ad2 or 0x55f450<=address<0x55f456:visited.add(address)
 if address==0x55f450:getters+=1;return
 if address not in [0x41f6d0,0x414c50,0x4882d0,0x590690]:return
 sp=mu.reg_read(UC_X86_REG_ESP);a=n.unpack('<3I',sp+4);ret=0
 if address==0x41f6d0:
  target=a[1]-0x34 if a[1] else 0;q.events.append(['activate',cstr(a[0]),oid(target),list(n.unpack('<3I',a[1])) if a[1] else None,a[2]])
  if target and current['placementMutation']:n.pack('<I',target+0x34,0x40a00000)
  ret=actor(2) if current['success'] else 0
 elif address==0x414c50:q.events.append(['deactivate',cstr(a[0])])
 elif address==0x590690:q.events.append(['effects',oid(a[0])])
 else:
  q.events.append(['release',aid(a[0]),a[1]]);releases+=1
  if releases==1:
   kind=current['releaseMutation']
   if kind=='swap':n.pack('<II',0x93d7f0,*reversed(n.unpack('<II',0x93d7f0)))
   elif kind=='clear-primary':n.pack('<I',0x93d7f0,0)
   elif kind=='replace-primary':n.pack('<I',0x93d7f0,actor(2))
   elif kind=='change-world':n.pack('<I',0x802c54,WORLDS[1-current['world']])
   elif kind=='change-spawn':n.write(SPAWNS[current['world']]+current['actors'][current['primary']]['spawn']*0xa4,b'gamma\0')
   elif kind=='secondary-inactive' and current['secondary']>=0:n.pack('<I',actor(current['secondary'])+0x1fc,0)
 mu.reg_write(UC_X86_REG_EAX,ret);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for address in [0x41f6d0,0x414c50,0x4882d0,0x590690,0x55f450]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x4648e0,end=0x464ad1)
def model(o):
 ev=[];name=None;active=True;build=None;p0=o['primary'];p1=o['secondary'];world=o['world'];flags=[a['flags'] for a in o['actors']];changed=None;changedPlacement=None;releaseCount=0
 count=len(o['tokens']) if o['count'] is None else o['count']
 for token in o['tokens'][:max(0,count)]:
  token=token.split('\0')[0];lower=token.lower();at=lower.find('name=')
  if at>=0:name=token[at+5:]
  elif lower=='true':active=True
  elif lower=='false':active=False
  elif 'buildit=' in lower:
   result=q.model('bindBlowup',dict(o,blowupType=o['buildType']),token[lower.index('buildit=')+8:]);ev+=result['events']
   if result['result'] is not None:build=result['result']
 def eligible(i):return i>=0 and flags[i]&0x1000 and not o['actors'][i]['blocked'] and o['actors'][i]['spawn']!=255
 def matches(i):
  if i<0 or o['world']<0:return None
  index=o['actors'][i]['spawn'];candidate=(['alpha','beta','alpha'] if o['world']==0 else ['beta','alpha','beta'])[index%3]
  if changed==index:candidate='gamma'
  return candidate.lower()==name.lower()
 def release(i):
  nonlocal p0,p1,world,changed,releaseCount
  ev.append(['release',i,0]);releaseCount+=1
  if releaseCount!=1:return
  kind=o['releaseMutation']
  if kind=='swap':p0,p1=p1,p0
  elif kind=='clear-primary':p0=-1
  elif kind=='replace-primary':p0=2
  elif kind=='change-world':world=1-o['world']
  elif kind=='change-spawn':changed=o['actors'][o['primary']]['spawn']
  elif kind=='secondary-inactive' and o['secondary']>=0:flags[o['secondary']]=0
 if name is not None:
  if active:
   ev.append(['activate',name,build,word(*build) if build is not None else None,heading(*build) if build is not None else 0])
   if build is not None and o['placementMutation']:changedPlacement=build
   if not o['success'] and build is not None:ev.append(['effects',build])
  else:
   if eligible(p0):
    match=matches(p0)
    if match is None:return None
    if match:release(p0)
   if eligible(p1):
    match=matches(p0)
    if match is None:return None
    if match:release(p1)
   ev.append(['deactivate',name])
 return dict(events=ev,players=[p0,p1],world=world,flags=flags,changedSpawn=changed,changedPlacement=changedPlacement)
def run(inputs=None,source=None):
 o=options(inputs or {});want=model(o)
 if want is None:excluded.append(dict(options=o,reason='Native unguarded world/primary pointer lookup'));return
 setup(o);before=n.read(D,0x50000);n.call(0x4648e0,[GIT,0,ARGS,len(o['tokens']) if o['count'] is None else o['count']]);got=dict(events=copy.deepcopy(q.events),players=[aid(p) for p in n.unpack('<II',0x93d7f0)],world=-1 if not n.unpack('<I',0x802c54)[0] else WORLDS.index(n.unpack('<I',0x802c54)[0]),flags=[n.unpack('<I',actor(i)+0x1fc)[0] for i in range(3)],changedSpawn=None,changedPlacement=None);expected=bytearray(before)
 for i,f in enumerate(want['flags']):struct.pack_into('<I',expected,actor(i)+0x1fc-D,f)
 if want['changedSpawn'] is not None:
  at=SPAWNS[o['world']]+want['changedSpawn']*0xa4;expected[at-D:at-D+6]=b'gamma\0';got['changedSpawn']=want['changedSpawn'] if n.read(at,6)==b'gamma\0' else -100
 if want['changedPlacement'] is not None:
  at=obj(*want['changedPlacement'])+0x34;struct.pack_into('<I',expected,at-D,0x40a00000);got['changedPlacement']=want['changedPlacement'] if n.unpack('<I',at)[0]==0x40a00000 else [-100,-100]
 bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x50000)!=bytes(expected):bad.append('Complete data image differs')
 if getters!=1:bad.append(dict(getters=getters))
 if n.unpack('<i',0x804e44)[0]!=o['buildType']:bad.append('Build type mutated')
 if bad:errors.append(dict(options=o,bad=bad))
 rows.append(dict(options=o,native=got,source=source));group='authored' if source else 'synthetic';groups[group]=groups.get(group,0)+1

def main():
 for tokens in [[],['FALSE'],['name=alpha'],['name=alpha','FALSE'],['name=beta','FALSE'],['name=alpha','FALSE','TRUE'],['name=alpha','TRUE','FALSE'],['xFALSE'],['xname=alpha'],['buildit=beta','name=alpha'],['buildit=beta','buildit=missing','name=alpha'],['buildit=beta','buildit=Alpha','name=beta'],['name=FALSE','name=alpha'],['NAME=ALPHA','false'],['name=alpha\0ignore','FALSE'],['buildit=','name='],['buildit=alphaNAME=beta'],['TRUE','name=alpha','falseTRUE']]:
  for success,typ in itertools.product([False,True],[-1,0,1,3,4,7]):run(dict(tokens=tokens,success=success,buildType=typ,placementMutation=not success))
 for p0,p1,spawn0,spawn1,name,world in itertools.product([-1,0],[-1,1],[0,1,2,255],[0,1,255],['alpha','beta','missing'],[-1,0,1]):
  actors=options({})['actors'];actors[0]['spawn']=spawn0;actors[1]['spawn']=spawn1;run(dict(tokens=['name='+name,'FALSE'],primary=p0,secondary=p1,actors=actors,world=world))
 for idx,flags,blocked in itertools.product([0,1],[0,1,0x1000,0x1001,0xffffffff],[0,1,255]):
  actors=options({})['actors'];actors[idx].update(flags=flags,blocked=blocked)
  for name in ['alpha','beta']:run(dict(tokens=['FALSE','name='+name],actors=actors))
 for mutation,name,p1 in itertools.product(['none','swap','clear-primary','replace-primary','change-world','change-spawn','secondary-inactive'],['alpha','beta'],[-1,1]):run(dict(tokens=['name='+name,'FALSE'],releaseMutation=mutation,secondary=p1))
 for count,world in itertools.product([-2,-1,0],[-1,0,1]):run(dict(tokens=['name=alpha','FALSE'],count=count,world=world))
 for gate in ['types','registry']:
  for value in [False,True]:run(dict(tokens=['buildit=alpha','name=alpha'],**{gate:value}))
 uses=next(r['uses'] for r in json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text())['rows'] if r['name']=='ActivateChar' and r['kind']=='git-action')
 for source in uses:
  for success in [False,True]:run(dict(tokens=source['args'],success=success),source)
 # Standalone getter returns its global verbatim, including null; command covers the same original helper every time.
 opaque=[0,1,0xffffffff,*WORLDS]
 for value in opaque:
  n.pack('<I',0x802c54,value);got=n.call(0x55f450)
  if got!=value:errors.append(dict(getter=got,want=value))
 report=dict(binarySha256=n.sha256,checks=len(rows)+len(opaque),mismatches=len(errors),groups=groups,getterDirectCases=len(opaque),fullRegionComparisons=len(rows),comparedBytes=len(rows)*0x50000,excludedInvalidPointerCases=len(excluded),authoredUses={'ActivateChar':len(uses)},visitedInstructions=len(visited),examples=errors[:5],method='Original4648e0 and55f450 execute with actual4f8a70/4f8b10 parsing and55a020/558770 scenery lookup. Named lifecycle41f6d0/414c50, release4882d0 and build-failure effects590690 are declared mutable services. Exact event order/identity, position words/heading, globals and complete320KiB data image compared.',limits=['Shipped ASCII token/name domain with readable world/system/spawn tables; count<=0 maps to an empty resolved token array. World pointer identity is portable rather than a numeric process address.','Machine code464a88 uses primary spawn index after testing secondary eligibility; preserved, including primary reread after the first release. Eligible secondary with absent primary or active name matching with absent world faults natively and is excluded.','Current world pointer is cached before parsing; release may replace global current world without affecting this caller name-table reference. Mutable release cases also swap players, replace primary, change spawn name and disable secondary.','Named activation/deactivation, player release and build-failure physical effects remain explicit services. This module recovers graph orchestration, not those service internals. Managed replay pending.'])
 (B/'reports/native-graph-actor-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-graph-actor-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,names=q.names,cases=rows,excluded=excluded),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
