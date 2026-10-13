import importlib.util,json,struct,copy,random,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('actors',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
n=a.n;B=a.BASE;D=n.DATA;OUT=D+0x58000
ADDR={'bindHit':0x441d50,'bindTaken':0x443020,'BeenHit':0x441d80,'TakenOver':0x443050,'HasTakeOverTarget':0x4435e0,'PlayerOnGround':0x441830}
rows=[];errors=[];groups={};memory=0;excluded=0
def context(o):
 c=a.context(o)
 for i,x in enumerate(c['actors']):
  x['state'][2]=(x['state'][2]&~1)|(i%2)
  x['status']=dict(opponent=(i+1)%8,takeover=(i+2)%8 if i%2 else -1,linked=(i+3)%8 if i%3 else -1,state7b5=[0,8,59,255][i%4],ground281=i%2,ground282=i%3,hitTimer=[0.,0.5,-1.,2.][i%4]);x['status'].update(o.get('statusOverrides',{}).get(str(i),{}))
 return c

def setup(c,operand):
 a.setup(c,[])
 for i,x in enumerate(c['actors']):
  p=a.actor(i);s=x['status'];n.pack('<I',p+0x3ac,a.actor(s['opponent']));n.pack('<I',p+0xea4,a.actor(s['takeover']));n.pack('<I',p+0xcd0,a.actor(s['linked']));n.pack('<B',p+0x7b5,s['state7b5']);n.pack('<BB',p+0x281,s['ground281'],s['ground282']);n.pack('<f',p+0x1018,s['hitTimer'])
 if operand is not None:n.write(a.TEXT,operand.encode()+b'\0')

def model(kind,c,operand,bound):
 ev=[];reference=c['reference'] if c['creature'] else -1;own=c['actors'][reference]['world'] if reference>=0 else -1
 if kind.startswith('bind'):
  actor=-1
  if operand is not None and c['callback'] and (kind!='bindTaken' or c['system']):
   ev.append(['name',operand.split('\0')[0]]);ref=a.resolve_name(c,operand.split('\0')[0]);actor=c['actors'][ref]['world'] if ref>=0 else -1
  return dict(result=actor,events=ev)
 if kind=='BeenHit':
  actor=bound if bound>=0 else own;yes=actor>=0 and (c['actors'][actor]['status']['hitTimer']>0 or c['actors'][actor]['state'][2]&1)
 elif kind=='HasTakeOverTarget':yes=own>=0 and c['actors'][own]['status']['takeover']>=0
 elif kind=='PlayerOnGround':
  actor=c['primary'];yes=actor>=0 and (c['actors'][actor]['status']['ground281'] or c['actors'][actor]['status']['ground282'])
 else:
  actor=bound
  if actor<0:
   low=None if operand is None else operand.split('\0')[0].lower()
   if low is None:actor=own
   elif low=='opponent':
    assert own>=0;op=c['actors'][own]['status']['opponent'];actor=c['actors'][op]['world'] if op>=0 else -1
   elif low=='takeovertarget':
    assert reference>=0;actor=c['actors'][own]['status']['takeover'] if own>=0 else -1
  yes=actor>=0 and c['actors'][actor]['status']['linked']>=0 and c['actors'][actor]['status']['state7b5']!=59
 return dict(result=a.bits(1. if yes else 0.),events=ev)

def run(kind,o=None,operand=None,bound=-1,source=None):
 global memory,excluded
 o=o or {};c=context(o);reference=c['reference'] if c['creature'] else -1;own=c['actors'][reference]['world'] if reference>=0 else -1
 if kind=='TakenOver' and bound<0 and operand is not None and ((operand.lower()=='opponent' and own<0) or (operand.lower()=='takeovertarget' and reference<0)):excluded+=1;return
 setup(c,operand);before=n.read(D,0x57000);expected=model(kind,c,operand,bound)
 if kind.startswith('bind'):result=a.aid(n.call(ADDR[kind],[a.SYS if c['system'] else 0,a.TEXT if operand is not None else 0]))
 else:
  n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(ADDR[kind],[a.SYS if c['system'] else 0,a.PACK,a.CRE if c['creature'] else 0,a.TEXT if operand is not None else 0,a.actor(bound)]);n.mu.emu_start(n.STOP,n.STOP+6);result=n.unpack('<I',OUT)[0]
 got=dict(result=result,events=a.events.copy());memory+=1;bad=[]
 if got!=expected:bad.append(dict(got=got,want=expected))
 if n.read(D,0x57000)!=before:bad.append('input memory changed')
 if bad:errors.append(dict(kind=kind,options=o,operand=operand,bound=bound,bad=bad))
 rows.append(dict(kind=kind,context=c,operand=operand,bound=bound,native=got,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());uses={r['name']:r['uses'] for r in ledger['rows'] if r['name'] in ADDR}
 for kind in ['bindHit','bindTaken']:
  for operand in [None,'','Alpha','Beta','player','Player7','player_2','missing','Opponent','TakeoverTarget','alpha\0later']:
   for system,callback in itertools.product([False,True],repeat=2):run(kind,dict(system=system,callback=callback),operand)
 options=[{},dict(statusOverrides={'1':{'ground281':0,'ground282':0}}),dict(statusOverrides={'1':{'ground281':0,'ground282':128}}),dict(creature=False),dict(reference=-1),dict(primary=-1),dict(actorOverrides={'0':{'world':-1}}),dict(actorOverrides={'0':{'world':2},'1':{'world':3}}),dict(statusOverrides={'0':{'opponent':-1,'takeover':-1},'1':{'linked':-1}})]
 for kind in ['BeenHit','TakenOver','HasTakeOverTarget','PlayerOnGround']:
  for o in options:
   for operand in [None,'Opponent','opPonent','TakeoverTarget','unknown','']:
    for bound in [-1,0,1,2,3,7]:run(kind,o,operand,bound)
 rng=random.Random(443050)
 for i in range(512):
  changes={str(j):dict(state7b5=rng.randrange(256),ground281=rng.randrange(256),ground282=rng.randrange(256),hitTimer=rng.choice([-2.,0.,2**-149,1.,1.e20]),opponent=rng.randrange(-1,8),takeover=rng.randrange(-1,8),linked=rng.randrange(-1,8)) for j in range(8)}
  o=dict(statusOverrides=changes,reference=rng.randrange(-1,8),primary=rng.randrange(-1,8));run(rng.choice(['BeenHit','TakenOver','HasTakeOverTarget','PlayerOnGround']),o,rng.choice([None,'Opponent','TakeoverTarget','none']),rng.randrange(-1,8))
 for kind,authored in uses.items():
  for source in authored:
   args=source['args'];operand=args[0] if args and args[0] not in ['0','1','<','>','<=','>='] else None
   for bound in [-1,1,2]:run(kind,{},operand,bound,source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,authoredUses={k:len(v) for k,v in uses.items()},excludedInvalidPointerChains=excluded,examples=errors[:6],method='Original condition readers and both initializers run with real registered43c220 name resolution. Only existing CRT Player%d formatting adapter; exact float32 returns, lookup events and full input memory checked.',limits=['Finite hit timer and readable attached actor/world/tag records; special TakenOver operands require the native self pointer chain, invalid dereference cases explicitly excluded.','World ownership, producer/update semantics for status fields and complete takeover transitions remain external.','Authored rows cover condition bodies on prepared states, not original source loading or whole-script execution. Managed replay pending.'])
 (B/'reports/native-actor-status-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-actor-status-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
