"""Original graph4648e0 -> named lifecycle chain; release/effects stay explicit."""
import importlib.util,copy,json,struct,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('named',Path(__file__).with_name('gameplay-named-lifecycle-verify.py'));l=importlib.util.module_from_spec(s);s.loader.exec_module(l)
a=l.a;b=l.b;BASE=l.BASE;D=l.D;n=b.native.NativeX86();l.n=a.n=b.n=n
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
GIT=D+0x90000;GLOBAL=D+0x90100;TYPES=D+0x90200;REG=D+0x90500;BUCKET=D+0x90600;RECORDS=D+0x90700;OBJECTS=D+0x91000;ARGS=D+0x92000;TEXT=D+0x93000;WORLD2=D+0xb0000;SYS2=D+0xb4000;SPAWN2=D+0xb6000
rows=[];errors=[];groups={};image_sets=[];image_ids={};options={};release_count=0;visited=set();objects=[]
for addr in [0x6e69ef,0x43c220,0x43bc00,0x43bed0]:n.mu.hook_add(UC_HOOK_CODE,b.hook,begin=addr,end=addr)
for addr in [0x41c120,0x4364e0,0x52c790]:n.mu.hook_add(UC_HOOK_CODE,a.hook,begin=addr,end=addr)
for addr in [0x52f800,0x5728a0,0x572660,0x595af0]:n.mu.hook_add(UC_HOOK_CODE,l.extra_hook,begin=addr,end=addr)

def objid(p):return objects.index(p) if p in objects else -1
def word(image,at):return l.word(image,at)
def put(image,at,v,size=4):return l.put(image,at,v,size)
def release_effect(o,players,images,world):
 kind=o.get('releaseMutation','none')
 if kind=='swap':players[0],players[1]=players[1],players[0]
 elif kind=='replace-primary':players[0]=2
 elif kind=='world':world['current']=1
 elif kind=='mission':world['mission']=True
 elif kind=='disable-secondary' and players[1]>=0:put(images[players[1]],0x1fc,0)
 elif kind=='rename':world['renamed']=True

def hook(mu,address,size,user):
 global release_count
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x558770:b.events.append(['gizmoName',(arg(0)-RECORDS)//8]);return
 if address==0x590690:b.events.append(['effects',objid(arg(0))]);b.ret(mu,0);return
 ix=b.aid(arg(0));mode=arg(1)
 if mode:b.events.append(['releaseControl',ix,mode]);b.ret(mu,0);return
 b.events.append(['release',ix,0]);release_count+=1
 if release_count==1:
  players=[b.aid(x) for x in n.unpack('<II',0x93d7f0)];images=[bytearray(n.read(b.actor(i),0x10d8)) for i in range(8)];world=dict(current=0,mission=False,renamed=False);release_effect(options,players,images,world)
  n.pack('<II',0x93d7f0,*[b.actor(i) for i in players]);n.pack('<I',0x802c54,WORLD2 if world['current'] else a.WORLD)
  if world['mission']:n.pack('<B',l.MISSION+0x1d,1)
  if world['renamed']:n.write(b.SPAWN,b'changed\0')
  for i,image in enumerate(images):n.write(b.actor(i),image)
 b.ret(mu,0)
for addr in [0x558770,0x590690,0x4882d0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=addr,end=addr)
for start,end in [(0x4648e0,0x464ad2),(0x41f6d0,0x41f913),(0x414c50,0x414ca4)]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,size,u:visited.add(p),begin=start,end=end-1)

def setup(tokens,o):
 global options,release_count,objects
 options=o;release_count=0;c,_=l.setup(o,None,None);n.write(GIT,bytes(0x30000));n.pack('<I',GIT,REG if o.get('registry',True) else 0);n.pack('<i',0x804e44,0);n.pack('<I',0x93b268,GLOBAL if o.get('types',True) else 0);n.pack('<iII',GLOBAL,1,0,TYPES);n.pack('<I',TYPES+0x44,0x558770);n.pack('<I',REG,BUCKET);n.pack('<i',BUCKET+4,2);n.pack('<I',BUCKET+12,RECORDS)
 n.pack('<I',WORLD2+0x2ae8,SYS2);n.pack('<I',WORLD2+0x2ab4,0xabcdef01);n.pack('<I',SYS2+0x18,SPAWN2)
 for i in range(8):n.write(SPAWN2+i*0xa4,b'alternate\0');n.pack('<B',b.actor(i)+0x28b,o.get('blocked',[0]*8)[i])
 objects=[OBJECTS,OBJECTS+0x100]
 if 'placementAlias' in o:objects[0]=b.actor(o['placementAlias']['actor'])+o['placementAlias']['offset']-0x34
 for i,name in enumerate(o.get('buildNames',['buildA','buildB'])):
  n.pack('<I',RECORDS+8*i,objects[i]);n.pack('<B',RECORDS+8*i+6,0);n.write(objects[i],name.encode()+b'\0')
  if i!=0 or 'placementAlias' not in o:n.pack('<III',objects[i]+0x34,*[b.bits(10.25+i),0x80000000,b.bits(-3.5-i)]);n.pack('<H',objects[i]+0x74,0x8765+i)
 offset=0
 for i,t in enumerate(tokens):n.pack('<I',ARGS+4*i,TEXT+offset);data=t.encode()+b'\0';n.write(TEXT+offset,data);offset+=len(data)
 return c

def named_model(kind,name,c,o,images,out,world,ev,position,angle):
 if world['mission'] or name is None:return -1
 ref=-1;ctx=copy.deepcopy(c)
 if world['current']:
  ctx['system']=True
  for actor in ctx['actors']:actor['spawnName']='alternate'
 elif world['renamed']:ctx['actors'][0]['spawnName']='changed'
 ctx['players']=world['players']+c['players'][2:]
 for i,actor in enumerate(ctx['actors']):actor['state'][1]=word(images[i],0x1fc)
 if c['callback']:ev.append(['name',name]);ref=b.resolve_name(ctx,name)
 ix=ctx['actors'][ref]['world'] if ref>=0 else -1
 if ix<0 or (o.get('restricted',0) and not word(images[ix],0x1f8)&0x400) or (kind=='activate' and word(images[ix],0x1fc)&0x1000):return -1
 image=images[ix]
 def call(op,args):ev.append([op,args,[word(image,p) for p in [0x5c,0x60,0x64,0x1fc]]]);l.effect(images,world,op,o)
 def cp(to,fr):image[to:to+12]=image[fr:fr+12]
 if kind=='deactivate':
  oldphase=out['spawnPhase'].copy();a.deactivate(out,ctx,o,ev,ix)
  if world['current']:
   if image[0x400]!=255 and out['actors'][ix]['phase']==0:world['alternatePhase'][image[0x400]]=2
   out['spawnPhase']=oldphase
  put(image,0x1fc,out['actors'][ix]['active']);put(image,0x406,out['actors'][ix]['phase'],1);return -1
 if image[0x400]==255:
  put(image,0x1fc,word(image,0x1fc)|0x1000);out['actors'][ix]['active']=word(image,0x1fc);a.change(out,ctx,o,ev,ix,'Base')
  if position is not None:
   for j in range(3):put(image,0x5c+4*j,word(images[position['actor']],position['offset']+4*j) if 'actor' in position else position['words'][j])
   for at in [0x27a,0x58,0x5a]:put(image,at,angle,2)
   call('resetState',[int(ctx['system']),ix,255,1]);cp(0x80,0x5c);cp(0x98,0x5c);world['origin']=[word(image,0x80+4*j) for j in range(3)];cp(0x8c,0x80)
   for at in [0x1cc,0x1b4,0x10bc]:cp(at,0x5c)
   for j,v in enumerate(world['reset']):put(image,0xdf8+4*j,v);put(image,0x68+4*j,v)
   call('resetTerrain',[ix]);call('clearTerrain',[ix,0])
 else:
  ev.append(['reinitialize',ix,ctx['system']])
  if 'reinitializeGroup' in o:out['actors'][ix]['group']=o['reinitializeGroup']
 call('refresh',[ix,world['refresh']]);out['actors'][ix]['active']=word(image,0x1fc);return ix

def run(tokens,o=None,source=None):
 o=copy.deepcopy(o or {});o.setdefault('primary',0);o.setdefault('players',[0,1,2,-1,-1,-1,-1,7]);c=setup(tokens,o);before=a.snapshot();images=[bytearray(n.read(b.actor(i),0x10d8)) for i in range(8)];new=copy.deepcopy(images);out=copy.deepcopy(before);ev=[]
 world=dict(current=0,renamed=False,players=c['players'][:2],mission=o.get('missionState',True) and bool(o.get('missionEnabled',0)) and bool(o.get('missionPointer',0x12345678)),origin=[0x11111111,0x22222222,0x33333333],reset=o.get('reset',[0,0,0]).copy(),refresh=0xabcdef01,alternatePhase=[0]*8)
 positions=[dict(words=list(n.unpack('<III',obj+0x34))) for obj in objects];angles=[n.unpack('<H',obj+0x74)[0] for obj in objects]
 if 'placementAlias' in o:positions[0]=o['placementAlias']
 name=None;active=True;build=-1
 for token in tokens:
  token=token.split('\0')[0];low=token.lower()
  if 'name=' in low:name=token[low.index('name=')+5:]
  elif low=='true':active=True
  elif low=='false':active=False
  elif 'buildit=' in low and o.get('registry',True) and o.get('types',True):
   lookup=token[low.index('buildit=')+8:].lower()
   for i,candidate in enumerate(o.get('buildNames',['buildA','buildB'])):
    ev.append(['gizmoName',i])
    if candidate.lower()==lookup:build=i;break
 if name is not None:
  if active:
   result=named_model('activate',name,c,o,new,out,world,ev,positions[build] if build>=0 else None,angles[build] if build>=0 else 0)
   if result<0 and build>=0:ev.append(['effects',build])
  else:
   releases=0
   for slot in range(2):
    ix=world['players'][slot]
    if ix<0 or not word(new[ix],0x1fc)&0x1000 or o.get('blocked',[0]*8)[ix] or new[ix][0x400]==255:continue
    primary=world['players'][0]
    if primary<0:raise ValueError('Excluded native null-primary dereference')
    spawn=new[primary][0x400];candidate='changed' if world['renamed'] and spawn==0 else c['actors'][spawn]['spawnName'] if spawn<8 else ''
    if candidate.lower()==name.lower():
     ev.append(['release',ix,0]);releases+=1
     if releases==1:release_effect(o,world['players'],new,world)
   for i in range(8):out['actors'][i]['active']=word(new[i],0x1fc)
   named_model('deactivate',name,c,o,new,out,world,ev,None,0)
 n.call(0x4648e0,[GIT,0,ARGS,len(tokens)]);after=[n.read(b.actor(i),0x10d8) for i in range(8)]
 got=dict(delta=a.delta(before,a.snapshot()),physical=l.phys_delta(images,after),origin=list(n.unpack('<III',0x93d620)),reset=list(n.unpack('<III',0x93b0cc)),refresh=n.unpack('<I',a.WORLD+0x2ab4)[0],players=[b.aid(v) for v in n.unpack('<II',0x93d7f0)],current=int(n.unpack('<I',0x802c54)[0]==WORLD2),events=b.events.copy(),mission=bool(n.unpack('<B',l.MISSION+0x1d)[0] and n.unpack('<I',l.MISSION+4)[0] and n.unpack('<I',0x9553d4)[0]))
 got['alternatePhase']=[n.unpack('<B',SPAWN2+i*0xa4+0x87)[0] for i in range(8)]
 want=dict(delta=a.delta(before,out),physical=l.phys_delta(images,new),origin=world['origin'],reset=world['reset'],refresh=world['refresh'],players=world['players'],current=world['current'],events=ev,mission=world['mission'],alternatePhase=world['alternatePhase'])
 if got!=want:errors.append(dict(tokens=tokens,options=o,got=got,want=want))
 physical=[[[p,word(image,p)] for p in range(0,len(image),4) if not 0x2c8<=p<0x400 and word(image,p)] for image in images];key=json.dumps(physical,separators=(',',':'))
 if key not in image_ids:image_ids[key]=len(image_sets);image_sets.append(physical)
 rows.append(dict(tokens=tokens,options=o,imageSet=image_ids[key],positions=positions,headings=angles,native=got,source=source));group='authored' if source else 'synthetic';groups[group]=groups.get(group,0)+1

def main():
 base=dict(actorOverrides={'0':dict(active=1,spawn=255,spawnName='Alpha')})
 for tokens in [[],['FALSE'],['name=Alpha'],['name=missing'],['name=Alpha','buildit=buildA'],['buildit=buildA','buildit=missing','name=Alpha'],['buildit=buildA','buildit=buildB','name=Alpha'],['name=Alpha','FALSE'],['name=Alpha','FALSE','TRUE'],['name=Alpha','name=missing','buildit=buildB']]:
  for mission in [0,1]:run(tokens,dict(**base,missionEnabled=mission))
 for spawn,active,restricted,flags in itertools.product([0,255],[1,0x1001],[0,1],[0,0x400]):run(['name=Alpha','buildit=buildA'],dict(restricted=restricted,actorOverrides={'0':dict(spawn=spawn,active=active,flags=flags)}))
 for alias in [dict(actor=0,offset=0x58),dict(actor=0,offset=0x60),dict(actor=1,offset=0x58)]:run(['name=Alpha','buildit=buildA'],dict(**base,placementAlias=alias))
 for op in ['resetState','resetTerrain','clearTerrain','refresh']:run(['name=Alpha','buildit=buildA'],dict(**base,effects=[dict(operation=op,offset=0x5c,value=b.bits(75.25))]))
 for mutation in ['none','swap','replace-primary','world','mission','disable-secondary','rename']:
  for name in ['Alpha','Beta','namedOnly']:
   run(['name='+name,'FALSE'],dict(releaseMutation=mutation,actorOverrides={'0':dict(spawnName='namedOnly' if name=='namedOnly' else 'Alpha'),'1':dict(spawnName='Beta'),'2':dict(spawnName='Alpha')}))
 for registry,types,callback,system in itertools.product([False,True],repeat=4):run(['name=Alpha','buildit=buildA'],dict(**base,registry=registry,types=types,callback=callback,system=system))
 for blocked,spawn in itertools.product([0,1,255],[0,255]):run(['name=Alpha','FALSE'],dict(blocked=[blocked]+[0]*7,actorOverrides={'0':dict(spawn=spawn,spawnName='Alpha')}))
 uses=next(row['uses'] for row in b.ledger['rows'] if row['kind']=='git-action' and row['name']=='ActivateChar')
 for source in uses:
  name=next((t[t.lower().index('name=')+5:] for t in reversed(source['args']) if 'name=' in t.lower()),'Alpha');build=next((t[t.lower().index('buildit=')+8:] for t in source['args'] if 'buildit=' in t.lower()),'buildA')
  for mission in [0,1]:run(source['args'],dict(missionEnabled=mission,buildNames=[build,'buildB'],actorOverrides={'0':dict(active=1 if 'FALSE' not in [x.upper() for x in source['args']] else 0x1001,spawnName=name,definition=0),'1':dict(spawnName='different')}),source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,examples=errors[:4],authoredOccurrences=134,additionalAuthoredUseCredit=0,newNativeEntryPointCredit=0,visitedInstructions=len(visited),method='Original4648e0/55f450,55a020/558770,41f6d0/414c50,58a900,440120/43c220,414bb0/52c790 and original script-state helpers execute together. Original graph parsing, cached world, secondary primary-spawn quirk, mutable release and lifecycle mission guard compared.41c120,4882d0,590690 and downstream reset/terrain/refresh calls remain declared service boundaries in this composition suite.')
 (BASE/'reports/gameplay-graph-lifecycle-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-graph-lifecycle-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,typeNames=b.TYPE_NAMES,initialPhysicalImages=image_sets,cases=rows),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
