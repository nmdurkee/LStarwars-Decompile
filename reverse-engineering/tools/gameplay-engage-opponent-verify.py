"""Original EngageOpponent with real parsing, RNG, movement and targeting helpers."""
import importlib.util,json,struct,itertools,math,random,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('targeting',Path(__file__).with_name('gameplay-opponent-targeting-verify.py'));t=importlib.util.module_from_spec(s);s.loader.exec_module(t)
a=t.a;n=a.n;BASE=a.BASE;D=a.D;GAME=D+0x70000;MATRIX=D+0x73000;TUNE=D+0x74000;INPUT=D+0x75000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
uses=next(r['uses'] for r in a.ledger['rows'] if r['name']=='EngageOpponent');checks={};errors=[];vectors=[];calls=[];executed=set()
def f(v):return a.f(v)
def bits(v):return a.bits(v)
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def vec(v):return list(map(bits,v))
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x52fcb0:calls.append(['intent',a.aid(arg(1)-0x438),arg(2),arg(4),arg(5)])
for address in [0x52fcb0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def trace(mu,address,size,user):executed.add(address)
n.mu.hook_add(UC_HOOK_CODE,trace,begin=0x447f00,end=0x448820)
def setup(tokens,o):
 c=a.context(o);a.setup(c,tokens);calls.clear();states=[]
 n.write(GAME,bytes(0x6000));n.pack('<I',0x802c54,GAME);n.pack('<I',GAME+0x298c,MATRIX)
 for row in range(256):n.pack('<II',MATRIX+8+row*8,*o.get('matrixRows',{}).get(str(row),[0xffffffff,0xffffffff] if o.get('permission',True) else [0,0]))
 for i,ac in enumerate(c['actors']):
  e=dict(origin=ac['position'],radius=.25,ef4=0,assigned=255,personal=i,ref3ac=1,blocked=0,visible=1,matrixIndex=i,mode=0,attack=12,blockedTimer=0.,ownerTimer=0.,followRadius=.5,tuning=0,input8=0x10,controller=True,path=[11.+i,12.+i,13.+i],words=[20+i*6+j for j in range(6)],attackTarget=-1)
  e.update(o.get('fields',{}).get(str(i),{}));states.append(e);p=a.actor(i)
  for key in ['radius','blockedTimer','ownerTimer','followRadius']:e[key]=f(e[key])
  for key in ['origin','path']:e[key]=list(map(f,e[key]))
  n.pack('<I',p+4,a.CRE+0x400+i*0x300 if e['controller'] else 0);n.pack('<3f',p+0x80,*e['origin']);n.pack('<f',p+0x1dc,e['radius']);n.pack('<I',p+0xef4,e['ef4']);n.pack('<B',p+0x1084,e['assigned']);n.pack('<b',p+0x280,e['personal']);n.pack('<I',p+0x3ac,a.actor(e['ref3ac']))
  for off,key in [(0x28b,'blocked'),(0x288,'visible'),(0x28d,'matrixIndex'),(0x7b5,'mode'),(0x1085,'attack')]:n.pack('<B',p+off,e[key])
  for off,key in [(0x1010,'blockedTimer'),(0x1000,'ownerTimer'),(0x3e8,'followRadius')]:n.pack('<f',p+off,e[key])
  n.pack('<I',a.DEF+ac['definition']*0x4c+0x24,TUNE+i*0x100);n.pack('<I',TUNE+i*0x100+0x90,e['tuning']);n.pack('<I',p+0xca4,INPUT+i*16);n.pack('<I',INPUT+i*16+8,e['input8']);n.pack('<3f',p+0x438,*e['path']);n.pack('<6I',p+0x420,*e['words']);n.pack('<I',p+0xea0,a.actor(e['attackTarget']))
 n.pack('<I',a.CRE+0xe4,a.actor(o.get('opponent',1)));n.pack('<f',a.CRE+0x180,o.get('goal',2.));n.pack('<B',a.CRE+0x13f,o.get('mode',9));n.pack('<I',a.CRE+0x1e8,o.get('flags',0x80000000));n.pack('<3f',a.CRE+0x1b4,90.,91.,92.);n.pack('<ff',a.CRE+0x1c0,.25,.5);n.pack('<6I',a.CRE+0x1cc,*range(10,16));n.pack('<I',a.CRE+0x1e4,a.actor(o['look'])+0x5c if o.get('look',-1)>=0 else 0)
 n.pack('<BH',a.PACK+0x68,o.get('packetFlags',0),0);n.pack('<H',a.PACK+0x6a,o.get('override',0));n.pack('<I',a.PACK+0x6c,a.actor(o.get('cached',-1)));n.pack('<ff',a.PACK+0x70,o.get('fireRange',3.),o.get('interval',1.5));n.pack('<f',a.PACK+0x9c,o.get('timer',.25))
 n.pack('<I',0x876cd0,o.get('touched',0));n.pack('<I',0x876584,int(o.get('nearMode',False)));n.pack('<I',0x855de0,int(o.get('minicut',False)));n.pack('<I',0x7f39e4,int(o.get('alternative',False)));n.pack('<I',0x80227c,o.get('fireButton',0x800));n.pack('<I',0x95e5d4,o.get('seed',123));n.pack('<fff',0x7f6824,1.5,1.5,.5)
 n.pack('<iff',0x7f671c,o.get('bandThreshold',32),o.get('bandStep',.75),o.get('bandBase',.75));n.write(0x876858,bytes(9*17*8+8))
 for row,entries in o.get('attackerRows',{}).items():
  for j,ix in enumerate(entries):n.pack('<I',0x876858+(int(row)*17+j)*8,a.actor(ix))
 return c,states
def snapshot():
 look=n.unpack('<I',a.CRE+0x1e4)[0]
 return dict(packetFlags=n.unpack('<B',a.PACK+0x68)[0],override=n.unpack('<H',a.PACK+0x6a)[0],cached=a.aid(n.unpack('<I',a.PACK+0x6c)[0]),fireRange=n.unpack('<I',a.PACK+0x70)[0],interval=n.unpack('<I',a.PACK+0x74)[0],timer=n.unpack('<I',a.PACK+0x9c)[0],goal=n.unpack('<I',a.CRE+0x180)[0],mode=n.unpack('<B',a.CRE+0x13f)[0],flags=n.unpack('<I',a.CRE+0x1e8)[0],point=list(n.unpack('<3I',a.CRE+0x1b4)),radius=n.unpack('<I',a.CRE+0x1c0)[0],intentGoal=n.unpack('<I',a.CRE+0x1c4)[0],words=list(n.unpack('<6I',a.CRE+0x1cc)),look=a.aid(look-0x5c) if look else -1,touched=n.unpack('<I',0x876cd0)[0],rng=n.unpack('<I',0x95e5d4)[0],actors=[[n.unpack('<I',a.actor(i)+0xeec)[0],n.unpack('<I',a.actor(i)+0xef0)[0],n.unpack('<B',a.actor(i)+0x1085)[0],a.aid(n.unpack('<I',a.actor(i)+0xea0)[0]),n.unpack('<I',INPUT+i*16+8)[0]] for i in range(8)])
def model(tokens,c,fields,o,first,delta,before):
 st=copy.deepcopy(before);ev=[];ic=[];actors=c['actors']
 def finish(value):return dict(result=value,state=st,events=ev,intents=ic)
 def draw():st['rng']=(st['rng']*0x19660d+0x3c6ef35f)&0xffffffff;return (st['rng']&0x7fffff)/(1<<23)
 def allowed(own,target):return not fields[own]['ef4']&0x2000 or (fields[own]['assigned']!=255 and c['players'][fields[own]['assigned']]==target)
 def permission(row,target):
  lo,hi=o.get('matrixRows',{}).get(str(row),[0xffffffff,0xffffffff] if o.get('permission',True) else [0,0]);return target<64 and bool(((hi<<32)|lo)&(1<<target))
 def intent(target,radius,mode,goal):
  ic.append(['intent',target,bits(radius),mode,bits(goal)]);st.update(point=vec(fields[target]['path']),radius=bits(radius),words=fields[target]['words'],intentGoal=bits(goal),flags=(st['flags']&~7)|(mode&7))
 def obstruction(own,target):
  if actors[own]['state'][0]&5:return False
  origin=fields[own]['origin'];d=t.sub(fields[target]['origin'],origin);distance=t.sq(d);length=f(math.sqrt(distance));scale=f(1/length) if length else 0;direction=[f(x*scale) for x in d]
  for p in c['players']:
   if p<0 or p in [own,target] or actors[p]['state'][1]&0x1001!=0x1001:continue
   if t.sq(t.sub(origin,fields[p]['origin']))>=distance:continue
   radius=f(fields[p]['radius']+.125)
   if t.sphere(origin,direction,fields[p]['origin'],f(radius*radius),0)['result']:return True
  return False
 ref=c['reference'] if c['creature'] else -1;own=actors[ref]['world'] if ref>=0 else -1
 if own<0:return finish(1)
 st['touched']=1
 if first:
  st['interval']=bits(1.5);st['goal']=bits(1.5);random=draw();explicit=False
  for token in tokens:
   low=token.lower()
   if 'firerange' in low:st['fireRange']=bits(a.number(token[low.index('firerange')+10:]));explicit=True
   elif 'goalrange' in low:st['goal']=bits(a.number(token[low.index('goalrange')+10:]))
   elif 'minrange=' in low:st['goal']=bits(a.number(token[low.index('minrange=')+9:]));st['packetFlags']|=2
   elif 'static' in low:st['goal']=0
   elif 'offscreen' in low:st['packetFlags']|=1
   elif 'no_fire_in_minicut' in low:st['packetFlags']|=4
   elif 'circle' in low:st['flags']^=0x200;st['packetFlags']|=8
   elif 'fireinterval' in low:st['interval']=bits(a.number(token[low.index('fireinterval')+13:]))
   elif 'opponent=' in low:
    name=token[low.index('opponent=')+9:];p=-1
    if c['callback']:ev.append(['name',name]);p=a.resolve_name(c,name)
    st['cached']=actors[p]['world'] if p>=0 else -1
   elif 'instant' in low:random=0
   elif 'attack_override' in low:
    name=token[low.index('attack_override')+16:].lower();st['override']=['','punch_1','punch_2','punch_3','punch_behind','punch_special','block','shoot'].index(name) if name in ['punch_1','punch_2','punch_3','punch_behind','punch_special','block','shoot'] else 0
  if o.get('nearMode'):st['packetFlags']|=0x20
  st['timer']=bits(fl(st['interval'])*random)
  if not explicit:st['fireRange']=bits(fl(st['goal'])+.5 if fl(st['goal'])!=0 else 9999.9)
 target=st['cached']
 if target>=0 and (actors[target]['state'][1]&0x1001!=0x1001 or (fields[target]['blocked'] and fields[target]['blockedTimer']<=0)):target=-1
 if st['override']:st['actors'][own][2]=st['override']&255
 if target<0:
  op=o.get('opponent',1)
  if op<0 or not fields[op]['controller'] or actors[op]['world']<0:return finish(0)
  target=actors[op]['world']
 st['actors'][own][0]|=0x20;ownf=fields[own];targetf=fields[target];ta=actors[target]['state'][1]
 if ta&0x1001!=0x1001 or targetf['blocked'] or targetf['mode']==0x2b or (ta&0x80 and targetf['ownerTimer']>1.5):return finish(0)
 distance=t.sq(t.sub(actors[target]['position'],actors[ref]['position']))
 goal=fl(st['goal'])
 if ownf['ef4']&0x2000:
  if allowed(own,actors[ownf['ref3ac']]['world']):st['packetFlags']&=~2;goal=f(.1)
  else:
   row=fields[ownf['ref3ac']]['personal'];goal=.75
   if 0<=row<=8:
    goal=f(o.get('bandBase',.75));cnt=band=0
    for p in o.get('attackerRows',{}).get(str(row),[])[:17]:
     if p<0:break
     if p==own:goal=t.wide.store(t.wide.add(t.wide.mul(t.wide.wide(band),t.wide.wide(f(o.get('bandStep',.75)))),t.wide.wide(f(o.get('bandBase',.75)))));break
     if fields[p]['assigned']==255:cnt+=1
     if cnt>=o.get('bandThreshold',32):band+=1;cnt=0
   st['packetFlags']|=2
 elif not (goal==0 or ((not ta&0x80 or ownf['visible']) and permission(fields[ref]['matrixIndex'],targetf['matrixIndex']))):goal=f(.1)
 special=bool(ownf['tuning']&0x100);efbit=bool(st['actors'][own][1]&0x10000)
 if goal==0:
  if not special:st['look']=target
 else:
  radius=min(goal,targetf['followRadius']);inner=(goal-.5)*(goal-.5);outer=(goal+.5)*(goal+.5)
  if not efbit:st['packetFlags']&=~0x10
  if efbit and special:
   if not st['packetFlags']&0x10:
    if distance<inner:st['packetFlags']|=0x10
   elif outer<distance:st['packetFlags']&=~0x10
   if st['packetFlags']&0x10:intent(target,radius,2,goal);st['mode']=1;st['actors'][own][1]|=0x8000
   else:intent(target,0,1,f(.01));st['mode']=0
  elif (special or st['packetFlags']&0x20) and distance<inner:
   intent(target,radius,2,goal);st['mode']=1
   if special:st['actors'][own][1]|=0x8000
  else:
   mode=0;ig=goal
   if not o.get('alternative') and outer>distance/10.+distance and st['packetFlags']&2:mode=2;ig=f(fl(st['goal'])+.5)
   elif distance>outer and (not o.get('alternative') or not st['packetFlags']&2):mode=1
   elif st['packetFlags']&8:mode=3
   elif not special:st['look']=target
   if mode:intent(target,radius,mode,ig);st['mode']=0
 if permission(ownf['matrixIndex'],targetf['matrixIndex']) and (not special or not efbit) and (ownf['visible'] or st['packetFlags']&1) and distance<fl(st['fireRange'])*fl(st['fireRange']):
  if not special:st['look']=target
  st['timer']=bits(t.wide.store(t.wide.add(t.wide.mul(t.wide.wide(draw()),t.wide.wide(fl(st['interval']))),t.wide.wide(2))) if o.get('minicut') and st['packetFlags']&4 else fl(st['timer'])-delta)
  st['actors'][own][3]=target
  if fl(st['timer'])<=0:
   st['timer']=bits(t.wide.store(t.wide.add(t.wide.mul(t.wide.wide(fl(st['interval'])),t.wide.wide(.5)),t.wide.mul(t.wide.wide(draw()),t.wide.wide(fl(st['interval']))))))
   if not obstruction(own,target) and allowed(own,target):st['actors'][own][4]|=o.get('fireButton',0x800)
 return finish(0)
def run(tokens,o=None,first=True,delta=.1,source=None,kind='branches',runtime=None,sequence=None):
 o=o or {};delta=f(delta);c,fields=setup(tokens,o) if runtime is None else runtime;calls.clear();a.events.clear();before=snapshot();got_result=n.call(0x447f00,[a.SYS if c['system'] else 0,a.PACK,a.CRE if c['creature'] else 0,a.ARGS,len(tokens),int(first),bits(delta)],count=1000000);got=dict(result=got_result,state=snapshot(),events=a.events.copy(),intents=calls.copy());want=model(tokens,c,fields,o,first,delta,before)
 checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(tokens=tokens,options=o,first=first,delta=delta,got=got,want=want))
 vectors.append(dict(tokens=tokens,options=o,first=first,delta=delta,source=source,native=got,sequence=sequence));return c,fields
def main():
 for use in uses:
  for o,first in [({},True),({'timer':0.,'seed':987},False),({'fields':{'0':{'tuning':0x100}},'nearMode':True},True),({'permission':False},True)]:run(use['args'],o,first,source={k:use[k] for k in ['source','line','state']},kind='authored')
 tokensets=[[],['circle','circle','instant'],['minrange=1','offscreen','fireinterval 0'],['goalrange 0','attack_override SHOOT','instant'],['opponent=Beta','instant'],['opponent=missing','instant'],['prefiXgoalrange=param3','firerange alpha'],['no_fire_in_minicut','instant'],['firerange 1','firerange 5','goalrange 3','static'],['attack_override PUNCH_1'],['attack_override PUNCH_BEHIND'],['attack_override BLOCK'],['attack_override invalid'],['INSTANT','OFFSCREEN'],['fXirerange 4','sXtatic'],['circle']]
 for tokens,o in itertools.product(tokensets,[{},dict(creature=False),dict(reference=-1),dict(opponent=-1),dict(callback=False),dict(cached=2),dict(override=0x123),dict(actorOverrides={'0':{'world':2}}),dict(fields={'1':{'controller':False}}),dict(nearMode=True),dict(minicut=True),dict(permission=False)]):run(tokens,o)
 for blocked,active,mode,timer in itertools.product([0,1],[0,1,0x1000,0x1001,0x1081],[0,0x2b],[0.,1.5,1.50000012]):run(['instant'],dict(fields={'1':dict(blocked=blocked,mode=mode,ownerTimer=timer)},actorOverrides={'1':{'active':active}}))
 for blocked,delay,cacheactive in itertools.product([0,1],[-1.,0.,1.],[0,0x1001]):run([],dict(cached=2,fields={'2':{'blocked':blocked,'blockedTimer':delay}},actorOverrides={'2':{'active':cacheactive}}))
 for value in ['PUNCH_1','PUNCH_2','PUNCH_3','PUNCH_BEHIND','PUNCH_SPECIAL','BLOCK','SHOOT','shoot','BLOCKextra','unknown','']:
  run(['attack_override '+value,'instant'])
 for o in [dict(actorOverrides={'0':{'world':-1}}),dict(actorOverrides={'1':{'world':-1}}),dict(actorOverrides={'1':{'world':2}}),dict(actorOverrides={'0':{'world':2,'position':[20,30,40]}},matrixRows={'0':[0xffffffff,0xffffffff],'2':[0,0]}),dict(actorOverrides={'0':{'world':2,'position':[20,30,40]}},matrixRows={'0':[0,0],'2':[0xffffffff,0xffffffff]})]:run(['instant','firerange 100'],o)
 for point in itertools.permutations([1.,2**-12,2**-27]):run([],dict(goal=.5,fireRange=0,actorOverrides={'0':{'position':[0,0,0]},'1':{'position':list(point)}}),False,kind='x87MidpointRegression')
 for distance,goal,pflags,special,efbit,alternative in itertools.product([0.,.25,.5,.75,1.,1.5,1.50000012,2.,2.5,2.50000024,3.,5.],[0.,.1,1.,2.], [0,2,8,0x10,0x20,0x3a],[False,True],[False,True],[False,True]):
  run([],dict(actorOverrides={'0':{'position':[0,0,0],'state':[0x400,0x1001,0,0x10000 if efbit else 0,0,0,0,0,0]},'1':{'position':[distance,0,0]}},fields={'0':{'tuning':0x100 if special else 0}},goal=goal,packetFlags=pflags,alternative=alternative,fireRange=0),False,kind='movement')
 for visible,flags,mini,interval,timer,delta in itertools.product([0,1],[0,1,4,5],[False,True],[-1.,0.,.5],[0.,.1,.10000001,3.],[0.,.1,.5]):run([],dict(goal=0,fields={'0':{'visible':visible}},packetFlags=flags,minicut=mini,interval=interval,timer=timer),False,delta,kind='firing')
 for row,col in itertools.product([0,1,31,32,63,64,127,255],[0,1,31,32,63,64,127,255]):
  run(['instant'],dict(fields={'0':{'matrixIndex':row},'1':{'matrixIndex':col}},matrixRows={str(row):[0x80000001,0x80000001]}),kind='matrix')
 for assigned,ref3ac,threshold in itertools.product([0,1,7,255],[1,2],[0,1,2,32]):run(['instant'],dict(fields={'0':{'ef4':0x2000,'assigned':assigned,'ref3ac':ref3ac}},players=[1,2,3,-1,-1,-1,-1,7],attackerRows={'1':[2,3,4,0],'2':[4,3,2,0]},bandThreshold=threshold),kind='assignment')
 for xyz,active,radius in itertools.product([[0,0,-1],[0,0,1],[0,0,5],[.625,0,1],[.62500006,0,1]],[0,0x1001],[0.,.5,1.]):run(['static','instant'],dict(actorOverrides={'0':{'position':[0,0,0]},'1':{'position':[0,0,3]},'2':{'active':active}},fields={'2':{'origin':xyz,'radius':radius}},players=[2,-1,-1,-1,-1,-1,-1,-1]),kind='obstruction')
 for i,(tokens,o) in enumerate(itertools.product([['static','instant'],['static','no_fire_in_minicut'],['circle','minrange=1','fireinterval .1'],['goalrange 1','fireinterval 0']], [{},{'minicut':True},{'fields':{'0':{'tuning':0x100}}},{'permission':False}])):
  runtime=None
  for tick in range(24):runtime=run(tokens,o,tick==0,.1,kind='persistentTicks',runtime=runtime,sequence='chain'+str(i))
 rng=random.Random(0x447f00)
 for i in range(256):run([],dict(actorOverrides={'0':{'position':[f(rng.uniform(-20,20)) for j in range(3)]},'1':{'position':[f(rng.uniform(-20,20)) for j in range(3)]}},fields={'0':{'tuning':0x100 if i&1 else 0}},goal=f(rng.uniform(-5,50)),fireRange=f(rng.uniform(-40,40)),interval=f(rng.uniform(-1,3)),timer=f(rng.uniform(-1,3)),packetFlags=i&255,alternative=bool(i&2)),False,f(rng.uniform(0,1)),kind='finiteRandom')
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 dis=Cs(CS_ARCH_X86,CS_MODE_32);instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in dis.disasm(n.read(0x447f00,0x921),0x447f00)]
 (BASE/'reports/gameplay-engage-opponent-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,entry='0x447f00',endExclusive='0x448821',instructions=instructions),indent=2),encoding='utf8')
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:8],authoredOccurrences={'EngageOpponent':len(uses)},instructionCoverage=dict(total=len(instructions),executed=len(executed),notExecuted=[i['address'] for i in instructions if not i['executed']]),method='Original command plus parsing/numeric/RNG/name/intent/assignment/distance-band/player-obstruction code execute unchanged. Only pre-existing bounded CRT Player%d formatting is substituted if named resolution reaches it. Independent Python state/event model compared after every call.',limits=['Finite valid attached actor and permission-mask data; malformed pointers and out-of-range assigned player slots excluded.','All263 authored argument lists tested in four supplied contexts; runtime script variable values are not reconstructed by this suite. Unbound variable names use actual numeric parser fallback.','Ordinary movement intent updates are real; formation expansion and later navigation/damage/input consumers remain external.','Portable managed comparison pending compile-only instruction.'])
 (BASE/'reports/gameplay-engage-opponent-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-engage-opponent-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
