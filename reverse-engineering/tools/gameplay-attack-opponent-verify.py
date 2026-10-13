"""Native AttackOpponent orchestration; no damage implementation substitution."""
import importlib.util,json,copy,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('engage',Path(__file__).with_name('gameplay-engage-opponent-verify.py'));e=importlib.util.module_from_spec(s);s.loader.exec_module(e)
a=e.a;n=e.n;t=e.t;BASE=e.BASE;INPUT=a.D+0x76000;checks={};errors=[];vectors=[];executed=set()
from unicorn import UC_HOOK_CODE
def trace(mu,address,size,user):executed.add(address)
n.mu.hook_add(UC_HOOK_CODE,trace,begin=0x447ac0,end=0x447ef4)
uses=next(r['uses'] for r in a.ledger['rows'] if r['name']=='AttackOpponent')
def sum3(x,y,z):return t.wide.store(t.wide.add(t.wide.add(t.wide.wide(x),t.wide.wide(y)),t.wide.wide(z)))
def setup(tokens,o):
 c,fields=e.setup(tokens,o);n.write(INPUT,bytes(0x500))
 for i in range(8):n.pack('<I',a.actor(i)+0xca4,INPUT+i*128);n.pack('<I',INPUT+i*128+8,fields[i]['input8']);n.pack('<H',INPUT+i*128+0x5a,o.get('input5a',0x100))
 n.pack('<B',a.PACK+0x69,o.get('jedi',0));n.pack('<f',a.PACK+0x70,o.get('attackRange',.2));n.pack('<f',a.CRE+0x120,o.get('followRadius',.25));return c,fields
def snapshot():
 state=e.snapshot();state['jedi']=n.unpack('<B',a.PACK+0x69)[0];state['input5a']=[n.unpack('<H',INPUT+i*128+0x5a)[0] for i in range(8)]
 for i in range(8):state['actors'][i][4]=n.unpack('<I',INPUT+i*128+8)[0]
 return state
def model(tokens,c,fields,o,first,before):
 st=copy.deepcopy(before);calls=[];actors=c['actors']
 def finish(value):return dict(result=value,state=st,events=[],intents=calls)
 def intent(target,radius,mode,goal):calls.append(['intent',target,e.bits(radius),mode,e.bits(goal)]);st.update(point=e.vec(fields[target]['path']),radius=e.bits(radius),words=fields[target]['words'],intentGoal=e.bits(goal),flags=(st['flags']&~7)|(mode&7),mode=0)
 ref=c['reference'] if c['creature'] else -1;own=actors[ref]['world'] if ref>=0 else -1
 if own<0:return finish(1)
 st['touched']=1
 if first:
  for token in tokens:
   low=token.lower()
   if 'goalrange' in low:st['goal']=e.bits(a.number(token[low.index('goalrange')+10:]))
   elif 'range' in low:st['goal']=e.bits(a.number(token[low.index('range')+6:]))
   elif low=='jedigoodie_attack':st['jedi']=1
   elif 'attack_override' in low:
    value=token[low.index('attack_override')+16:].lower();names=['punch_1','punch_2','punch_3','punch_behind','punch_special','block','shoot'];st['override']=names.index(value)+1 if value in names else 0
  st['fireRange']=e.bits(.2)
 if st['override']:st['actors'][own][2]=st['override']&255
 reference=o.get('opponent',1)
 if reference<0 or not fields[reference]['controller']:return finish(0)
 target=actors[reference]['world'];assert target>=0;st['actors'][own][0]|=0x20;ownf=fields[own];b=fields[target];af=actors[target]['state'][1]
 if af&0x1001!=0x1001 or b['blocked'] or b['mode']==0x2b or (af&0x80 and b['ownerTimer']>1.5):return finish(0)
 distance=t.sq(t.sub(actors[target]['position'],actors[ref]['position']))
 if ownf['ef4']&0x2000:
  allowed=ownf['assigned']!=255 and c['players'][ownf['assigned']]==actors[ownf['ref3ac']]['world']
  if allowed:st['goal']=0;st['packetFlags']&=~2
  else:
   row=fields[ownf['ref3ac']]['personal'];goal=.75
   if 0<=row<=8:
    goal=e.f(o.get('bandBase',.75));count=band=0
    for p in o.get('attackerRows',{}).get(str(row),[])[:17]:
     if p<0:break
     if p==own:goal=t.wide.store(t.wide.add(t.wide.mul(t.wide.wide(band),t.wide.wide(e.f(o.get('bandStep',.75)))),t.wide.wide(e.f(o.get('bandBase',.75)))));break
     if fields[p]['assigned']==255:count+=1
     if count>=o.get('bandThreshold',32):band+=1;count=0
   st['goal']=e.bits(goal);st['packetFlags']|=2
 goal=e.fl(st['goal']);follow=e.f(o.get('followRadius',.25))
 if not st['packetFlags']&2:intent(target,0,1,sum3(b['followRadius'],goal,follow))
 elif distance<(goal-.5)*(goal-.5):intent(target,follow,2,goal)
 elif distance<=(goal+.5)*(goal+.5):st['look']=target
 else:intent(target,follow,1,goal)
 attackRange=e.fl(st['fireRange'])
 if attackRange<=0:st['input5a'][own]|=2
 else:
  if b['mode']==0x5a:return finish(0)
  radius=sum3(b['followRadius'],attackRange,ownf['followRadius'])
  if e.f(radius*radius)<=distance:return finish(0)
 st['actors'][own][4]|=o.get('fireButton',0x800)
 if st['jedi']:st['actors'][own][0]|=0x400
 return finish(0)
def run(tokens,o=None,first=True,source=None,kind='branches'):
 o=o or {};c,fields=setup(tokens,o);before=snapshot();result=n.call(0x447ac0,[a.SYS,a.PACK,a.CRE if c['creature'] else 0,a.ARGS,len(tokens),int(first)],count=1000000);got=dict(result=result,state=snapshot(),events=a.events.copy(),intents=e.calls.copy());want=model(tokens,c,fields,o,first,before);checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(tokens=tokens,options=o,first=first,got=got,want=want))
 vectors.append(dict(tokens=tokens,options=o,first=first,source=source,native=got))
def main():
 for use in uses:
  for o,first in [({},True),({'goal':0.,'attackRange':0.},False),({'fields':{'0':{'ef4':0x2000,'assigned':255}},'attackerRows':{'1':[2,3,0]},'bandThreshold':1},True),({'actorOverrides':{'0':{'position':[0,0,0]},'1':{'position':[0,0,.2]}}},True)]:run(use['args'],o,first,{k:use[k] for k in ['source','line','state']},'authored')
 for token in ['','goalrange 3','range 2','prefiXrange=param3','firerange alpha','jediGoodie_attack','JEDIGOODIE_ATTACK','prefixjediGoodie_attack']+['attack_override '+x for x in ['PUNCH_1','PUNCH_2','PUNCH_3','PUNCH_BEHIND','PUNCH_SPECIAL','BLOCK','SHOOT','unknown']]:
  for o in [{},{'creature':False},{'reference':-1},{'opponent':-1},{'fields':{'1':{'controller':False}}},{'actorOverrides':{'0':{'world':-1}}},{'actorOverrides':{'0':{'world':2}}}]:run([token] if token else [],o)
 for distance,goal,flags,follow,first in itertools.product([0,.5,.75,1.,1.5,2.,2.5,2.50000024,3.,10.],[-1.,0.,.5,1.,2.],[0,2,0xff],[0.,.25,1.],[False,True]):run([],dict(actorOverrides={'0':{'position':[0,0,0]},'1':{'position':[distance,0,0]}},goal=goal,packetFlags=flags,followRadius=follow),first,kind='movement')
 for attackRange,mode,active,blocked,timer,jedi in itertools.product([-1.,0.,.2,3.],[0,0x2b,0x5a],[0,0x1001,0x1081],[0,1],[0.,1.5,1.50000012],[0,1]):run([],dict(attackRange=attackRange,jedi=jedi,fields={'1':{'mode':mode,'blocked':blocked,'ownerTimer':timer}},actorOverrides={'1':{'active':active}}),False,kind='eligibilityAndInput')
 for assigned,row,threshold in itertools.product([0,1,7,255],[-1,1,8,9],[0,1,2,32]):run([],dict(fields={'0':{'ef4':0x2000,'assigned':assigned},'1':{'personal':row}},attackerRows={'1':[2,3,4,0],'8':[4,3,2,0]},bandThreshold=threshold),kind='assignment')
 for p in itertools.permutations([1.,2**-12,2**-27]):run([],dict(goal=.5,packetFlags=2,actorOverrides={'0':{'position':[0,0,0]},'1':{'position':list(p)}}),False,kind='midpoint')
 for weapon,jedi,input5a,range70 in itertools.product([0,0x20,0x400,0xffffffff],[0,1],[0,2,0xfffd,0xffff],[-1.,0.,.2]):run([],dict(attackRange=range70,jedi=jedi,input5a=input5a,actorOverrides={'0':{'position':[0,0,0],'state':[0x400,0x1001,weapon,0,0,0,0,0,0]},'1':{'position':[0,0,.1]}}),False,kind='retainedInputBits')
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in d.disasm(n.read(0x447ac0,0x435),0x447ac0)]
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:8],authoredOccurrences={'AttackOpponent':len(uses)},instructionCoverage=dict(total=len(assembly),executed=len(executed),notExecuted=[i['address'] for i in assembly if not i['executed']]),method='Original0x447ac0 and all numeric, string, assignment, band, distance and ordinary-intent callees execute unchanged; no behavior callbacks are substituted. Independent Python state/input/intent projection compared after every invocation.',limits=['Finite valid record attachments; opponent reference with nonnull controller must have a nonnull world pointer as required by original dereference.','Ordinary movement intent and queued attack input only; actual attacks, damage and formations remain downstream systems.','Authored operands run in supplied contexts; local script-variable values are external.','Managed core/replay compile only.'])
 (BASE/'reports/gameplay-attack-opponent-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-attack-opponent-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-attack-opponent-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,entry='0x447ac0',endExclusive='0x447ef5',instructions=assembly),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
