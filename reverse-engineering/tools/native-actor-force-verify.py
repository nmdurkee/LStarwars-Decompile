import importlib.util,json,struct,itertools,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('force',Path(__file__).with_name('native-force-conditions-verify.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
n=f.n;B=f.B;D=f.D;q=f.q
ACT=D+0x22000;CRE=D+0x24000;REF=D+0x25000;SECOND=D+0x26000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
ADDR={'UsingForce':0x441020,'EitherPlayerUsingForce':0x441070,'OnForcePlatform':0x4410f0,'OnObject':0x441b00}
rows=[];errors=[];excluded=[];groups={};calls=[]
def observe(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);actor,target=n.unpack('<2I',sp+4);calls.append([{-1:-1,0:-1,ACT:0,f.PLAYER:1,SECOND:2}[actor],f.identity(target)])
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x4678f0,end=0x4678f0)
def options(o):
 p=f.options(dict(creature=True,reference=True,actor=True,objectBound=2,primaryState=7,primaryTarget=[1,1],second=True,secondState=8,secondTarget=[0,0]));p.update(o);return p
def setup(o):
 f.setup(o,None);calls.clear();n.pack('<I',CRE+0xd0,REF if o['reference'] else 0);n.pack('<I',REF,ACT if o['actor'] else 0);n.pack('<B',ACT+0x7b5,o['state']);n.pack('<I',ACT+0x10cc,f.obj(o['forceTarget']));n.pack('<h',ACT+0x27e,o['ground']);n.pack('<2B',ACT+0x281,*o['groundFlags']);n.pack('<f',ACT+0x60,o['height'])
 n.pack('<B',f.PLAYER+0x7b5,o['primaryState']);n.pack('<I',f.PLAYER+0x10cc,f.obj(o['primaryTarget']));n.pack('<2B',f.PLAYER+0x281,0,0);n.pack('<f',f.PLAYER+0x60,999.)
 n.pack('<I',0x93d814,SECOND if o['second'] else 0);n.pack('<B',SECOND+0x7b5,o['secondState']);n.pack('<I',SECOND+0x10cc,f.obj(o['secondTarget']))
def using(bound,actor,state,target,identity,events):events.append([identity if actor else -1,bound]);return bound is not None and actor and state==8 and target==bound
def model(kind,o):
 events=[];value=0;bound=o['bound']
 if kind=='UsingForce':
  if not o['creature'] or not o['reference']:return None
  value=using(bound,o['actor'],o['state'],o['forceTarget'],0,events)
 elif kind=='EitherPlayerUsingForce':value=using(bound,o['player'],o['primaryState'],o['primaryTarget'],1,events) or using(bound,o['second'],o['secondState'],o['secondTarget'],2,events)
 else:
  active=o['creature'] and o['reference']
  if kind=='OnForcePlatform':
   if bound is not None and active:
    if not o['actor']:return None
    answer=f.model('PlayerOnForcePlatform',dict(o,player=True),None)
    if answer is None:return None
    value=answer['result']!=0
  elif active and o['actor'] and o['objectBound']!=-1 and any(o['groundFlags']) and o['ground']==o['objectBound']:
   index=o['ground']
   if not o['terrain'] or index<0 or index>=len(o['terrainHeights']) or not o['transforms'][index]:return None
   value=o['terrainHeights'][index]<=o['height']
 return dict(result=q.bits(float(bool(value))),calls=events)
def run(kind,inputs=None,source=None):
 o=options(inputs or {});want=model(kind,o)
 if want is None:excluded.append(dict(kind=kind,options=o));return
 setup(o);before=n.read(D,0x65000);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',f.OUT));bound=o['objectBound'] if kind=='OnObject' else f.obj(o['bound']);n.call(ADDR[kind],[0,0,CRE if o['creature'] else 0,0,bound]);n.mu.emu_start(n.STOP,n.STOP+6);got=dict(result=n.unpack('<I',f.OUT)[0],calls=calls.copy());bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x65000)!=before:bad.append('Input memory changed')
 if bad:errors.append(dict(kind=kind,options=o,bad=bad))
 rows.append(dict(kind=kind,options=o,native=got,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 for bound,creature,reference,actor,state,target in itertools.product([None,[0,0]],[False,True],[False,True],[False,True],[0,7,8,9],[None,[0,0],[1,1]]):run('UsingForce',dict(bound=bound,creature=creature,reference=reference,actor=actor,state=state,forceTarget=target))
 for bound,first,second,ps,ss,pt,st in itertools.product([None,[0,0]],[False,True],[False,True],[7,8],[7,8],[None,[0,0],[1,1]],[None,[0,0],[1,1]]):run('EitherPlayerUsingForce',dict(bound=bound,player=first,second=second,primaryState=ps,secondState=ss,primaryTarget=pt,secondTarget=st))
 for kind in ['OnObject','OnForcePlatform']:
  for creature,reference,actor,flags,ground,height in itertools.product([False,True],[False,True],[False,True],[[0,0],[1,0],[0,128]],[-1,0,2],[-1.,2.,3.]):run(kind,dict(creature=creature,reference=reference,actor=actor,groundFlags=flags,ground=ground,height=height))
  for ground,bound,height in itertools.product([-2,-1,0,1,2,3,4],[-2,-1,0,1,2,3,4],[-1.,0.,1.,2.,3.,4.]):run(kind,dict(ground=ground,objectBound=bound,height=height))
  for invalid in [dict(terrain=False),dict(transforms=[False]*4),dict(memberGroup=False)]:
   for gate in [dict(),dict(bound=None),dict(creature=False),dict(reference=False),dict(actor=False),dict(groundFlags=[0,0]),dict(ground=-1),dict(height=-1.)]:run(kind,dict(invalid,**gate))
 for members in [[],[0],[2],[2,2],[3,1,2],[4,-1,-32768,32767]]:run('OnForcePlatform',dict(members=members))
 uses={r['name']:r['uses'] for r in json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text())['rows'] if r['name'] in ADDR}
 for kind,items in uses.items():
  for source in items:run(kind,source=source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=len(rows),excludedInvalidPointerCases=len(excluded),authoredUses={k:len(v) for k,v in uses.items()},examples=errors[:4],method='Original441020/441070/4410f0/441b00 and actual4678f0; exact float results, complete input memory, actor identity and first/second-player callback order. No replacements.',limits=['Valid finite terrain heights and readable memory after native guards. Unsafe pointer chains excluded rather than treated as safe false.','93d814 is an independent second global, not inferred from player-slot array. Supplied reference actor differs from primary actor.','Authored command provenance retained on controlled actor/platform queries; no loaded-level name binding or physics integration. Managed replay pending.'])
 (B/'reports/native-actor-force-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-actor-force-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows,excluded=excluded),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
