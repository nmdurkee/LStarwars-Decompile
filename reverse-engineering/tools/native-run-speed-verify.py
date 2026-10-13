import importlib.util,json,struct,random,copy,math
from pathlib import Path
s=importlib.util.spec_from_file_location('actor',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a);n=a.n;B=a.BASE
s=importlib.util.spec_from_file_location('distance',Path(__file__).with_name('native-distance-rounding-verify.py'));d=importlib.util.module_from_spec(s);s.loader.exec_module(d);v=d.v
TUNE=a.D+0x58000;rows=[];errors=[];groups={};memory=0
uses=next(x['uses'] for x in a.ledger['rows'] if x['name']=='SetRunSpeed')
def store(x,approx=None):
 f=d.store(x)
 if f==0 and approx is not None:return math.copysign(0.,approx)
 return f
def product(x,y):return store(v.mul(x,y),x*y)
def seek(x,target,rate,delta):
 step=product(rate,delta)
 if step>1:step=1.
 return store(v.add(x,v.mul(step,v.add(target,-x))),x+step*(target-x))
def model(c,o,tokens,first,state):
 state=copy.deepcopy(state);result=1;target=c['actors'][c['reference']]['world'] if c['creature'] and c['reference']>=0 else -1
 if target<0:return state,result
 speed=state['speeds'][target];rate=state['rate'];goal=state['goal']
 if first:
  requested=1e9;mul=1.;maximum=1e9;minimum=0.;multiply=False
  for token in tokens:
   token=token.split('\0')[0];low=token.lower()
   if 'multiply='in low:mul=a.number(token[low.index('multiply=')+9:]);multiply=True
   elif low=='max=default':maximum=o['defaults'][target]
   elif low=='default':requested=o['defaults'][target]
   elif low=='clear':pass
   elif 'max='in low:maximum=a.number(token[low.index('max=')+4:])
   elif 'min='in low:minimum=a.number(token[low.index('min=')+4:])
   elif 'seek='in low:rate=a.number(token[low.index('seek=')+5:])
   elif 'player_run_speed'in low:requested=o['defaults'][c['primary']]
   else:requested=a.number(token)
  minimum=abs(minimum);maximum=abs(maximum)
  def clamp(value):
   if value>=0:
    if value>maximum:return maximum
    if minimum<maximum and value<minimum:return minimum
   else:
    if value<-maximum:return -maximum
    if minimum<maximum and value>-minimum:return -minimum
   return value
  if rate==0:
   if not multiply:speed=requested
   else:
    if speed==1e9:speed=o['defaults'][target]
    speed=clamp(product(mul,speed))
   state.update(rate=rate,goal=goal);state['speeds'][target]=speed;return state,1
  if multiply:
   if speed==1e9:goal=o['defaults'][target]
   goal=clamp(product(mul,goal))
  else:goal=requested
 if rate>0 and speed<1e9:
  speed=seek(speed,goal,rate,o['delta']);difference=store(v.add(speed,-goal))
  if abs(difference)<v.f(.01):speed=goal
  else:result=0
 state.update(rate=rate,goal=goal);state['speeds'][target]=speed;return state,result

def snapshot(ret):return dict(result=ret,speeds=[v.bits(n.unpack('<f',a.actor(i)+0xed4)[0]) for i in range(8)],rate=n.unpack('<I',a.PACK+0x70)[0],goal=n.unpack('<I',a.PACK+0x74)[0])
def run(tokens,options={},first=True,source=None,steps=1):
 global memory
 o=dict(defaults=[v.f(2+i*.75) for i in range(8)],speed=1e9,rate=0.,goal=1.25,delta=v.f(1/60));o.update(options);c=a.context(o);a.setup(c,tokens);n.write(TUNE,bytes(0x1000));speeds=o.get('speeds',[o['speed']]*8)
 for i,value in enumerate(o['defaults']):n.pack('<I',a.DEF+i*0x4c+0x24,TUNE+i*0x100);n.pack('<f',TUNE+i*0x100+0x1c,value)
 for i,value in enumerate(speeds):n.pack('<f',a.actor(i)+0xed4,value)
 n.pack('<2f',a.PACK+0x70,o['rate'],o['goal']);n.pack('<f',0x925018,o['delta']);state=dict(speeds=speeds[:],rate=o['rate'],goal=o['goal']);history=[]
 for step in range(steps):
  entry=first and step==0;state,ret=model(c,o,tokens,entry,state);regions=[(a.ACT,8*0x10d8),(a.PACK,0x100)];expected=[bytearray(n.read(p,z)) for p,z in regions]
  for i,value in enumerate(state['speeds']):struct.pack_into('<f',expected[0],i*0x10d8+0xed4,value)
  struct.pack_into('<2f',expected[1],0x70,state['rate'],state['goal']);gotRet=n.call(0x44ac40,[a.SYS,a.PACK,a.CRE if c['creature'] else 0,a.ARGS,len(tokens),int(entry)]);got=snapshot(gotRet);want=dict(result=ret,speeds=[v.bits(x) for x in state['speeds']],rate=v.bits(state['rate']),goal=v.bits(state['goal']));bad=[]
  if got!=want:bad.append(dict(got=got,want=want))
  for i,(p,z) in enumerate(regions):
   memory+=1
   if n.read(p,z)!=expected[i]:bad.append(dict(region=i))
  if bad:errors.append(dict(tokens=tokens,options=o,step=step,bad=bad))
  history.append(dict(first=entry,native=got));groups['commandTicks']=groups.get('commandTicks',0)+1
 rows.append(dict(kind='command',tokens=tokens,options=o,context=c,source=source,history=history,inputBits=dict(defaults=[v.bits(x) for x in o['defaults']],speeds=[v.bits(x) for x in speeds],rate=v.bits(o['rate']),goal=v.bits(o['goal']),delta=v.bits(o['delta']))))

def helper(current,target,rate,delta):
 n.pack('<f',0x925018,delta);out=a.D+0x60000;n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',out));n.call(0x54fb40,[v.bits(current),v.bits(target),v.bits(rate)]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',out)[0];want=v.bits(seek(current,target,rate,delta))
 if got!=want:errors.append(dict(kind='helper',values=[current,target,rate,delta],got=got,want=want))
 rows.append(dict(kind='helper',values=[current,target,rate,delta],valueBits=[v.bits(x) for x in [current,target,rate,delta]],native=got));groups['helper']=groups.get('helper',0)+1

def main():
 for use in uses:
  for opts,first in [({},True),({'speed':1.5,'rate':.75},True),({'speed':2.,'rate':1.},False)]:run(use['args'],opts,first,use)
 tokenLists=[[],['clear'],['default'],['player_run_speed'],['3','clear'],['-3'],['multiply=-2'],['multiply=0'],['multiply=-0'],['multiply=.5','min=2','max=4'],['multiply=5','min=-4','max=-2'],['multiply=-.5','max=default'],['seek=1','4'],['seek=0','4'],['seek=-1','multiply=3'],['max=default','multiply=3'],['default','multiply=2'],['max=1','min=3','multiply=.1'],['unknown'],['alpha'],['param3'],['xxseek=2'],['seek=1','multiply=-2']]
 for tokens in tokenLists:
  for speed in [-3.,-0.,0.,2.,1e9]:
   for rate in [-1.,0.,1.]:run(tokens,dict(speed=speed,rate=rate))
 for gate in [{'creature':False},{'reference':-1},{'actorOverrides':{'0':{'world':-1}}},{'actorOverrides':{'0':{'world':2}}}]:run(['default','seek=2'],gate)
 for rate in [.1,1.,50.,100.]:
  for delta in [0.,v.f(1/60),1.,-.1]:run(['seek='+str(rate),'3.25'],dict(speed=-2.,delta=v.f(delta)),steps=32)
 rng=random.Random(44_400)
 for i in range(600):
  helper(v.f(rng.uniform(-100,100)),v.f(rng.uniform(-100,100)),v.f(rng.uniform(-3,3)),v.f(rng.uniform(-2,2)))
 for x in [-0.,0.,1.,-1.]:
  for goal in [-0.,0.]:
   for rate in [-0.,0.,1.]:helper(x,goal,rate,1.)
 report=dict(binarySha256=n.sha256,checks=sum(groups.values()),mismatches=len(errors),groups=groups,authoredUses=86,fullRegionComparisons=memory,examples=errors[:8],method='Original command, native numeric parsing and interpolation helper execute unchanged, with complete actor/packet region comparison and persistent update sequences. No helper substitutions.',limits=['Finite numeric values with finite intermediate/result storage; runtime actor/definition/primary-player attachment supplied.','Actor world dereference is distinct from controller reference. Existing seek/target packet fields persist unless written by original parsing.','Managed replay pending; downstream locomotion integration separate.'])
 (B/'reports/native-run-speed-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-run-speed-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
