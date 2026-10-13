import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('gizmo',Path(__file__).with_name('native-gizmo-conditions-verify.py'));q=importlib.util.module_from_spec(s);s.loader.exec_module(q)
n=q.n;B=q.B;D=q.D
PLAYER=D+0x20000;TERR=D+0x30000;RECS=D+0x40000;TRANS=D+0x42000;GROUP=D+0x45000;NODES=D+0x47000;DESC=D+0x60000;OUT=D+0x65000
ADDR={'BindUsingForce':0x440ff0,'BindForcePlatform':0x4410b0,'IsUsingForce':0x4678f0,'PlayerUsingForce':0x441050,'PlayerOnForcePlatform':0x441180}
rows=[];errors=[];groups={};excluded=[]
def obj(pair):return 0 if pair is None else q.OBJECTS+pair[0]*0x1000+pair[1]*0x100
def identity(p):return None if not p else [(p-q.OBJECTS)//0x1000,((p-q.OBJECTS)%0x1000)//0x100]
def options(o):
 p=q.options(dict(forceType=1,platformFlags=0x100,player=True,state=8,forceTarget=[0,0],bound=[0,0],ground=2,groundFlags=[1,0],height=2.,terrainHeights=[0.,1.,2.,3.],terrain=True,transforms=[True]*4,members=[1,2,3],memberGroup=True));p.update(o);return p
def setup(o,name):
 q.setup(o,name);n.write(D+0x1b000,bytes(0x4a004));n.pack('<i',0x7f8cc4,o['forceType']);n.pack('<I',0x93d810,PLAYER if o['player'] else 0);n.pack('<B',PLAYER+0x7b5,o['state']);n.pack('<I',PLAYER+0x10cc,obj(o['forceTarget']));n.pack('<h',PLAYER+0x27e,o['ground']);n.pack('<2B',PLAYER+0x281,*o['groundFlags']);n.pack('<f',PLAYER+0x60,o['height']);n.pack('<I',0x292fc68,TERR if o['terrain'] else 0);n.pack('<I',TERR+0x68,RECS)
 for i,height in enumerate(o['terrainHeights']):n.pack('<I',RECS+i*0x6c+0x40,TRANS+i*0x40 if o['transforms'][i] else 0);n.pack('<f',TRANS+i*0x40+0x34,height)
 for typ in range(5):
  for i in range(4):n.pack('<I',obj([typ,i])+0xa0,o['platformFlags']);n.pack('<I',obj([typ,i])+0x28,GROUP if o['memberGroup'] else 0)
 n.pack('<I',GROUP+0x18,NODES if o['members'] else 0)
 for i,index in enumerate(o['members']):n.pack('<I',NODES+i*0x30,NODES+(i+1)*0x30 if i+1<len(o['members']) else 0);n.pack('<I',NODES+i*0x30+0x24,DESC+i*4);n.pack('<h',DESC+i*4+2,index)
def model(kind,o,name):
 if kind.startswith('Bind'):
  co=dict(o,blowupType=o['forceType']);v=q.model('bindBlowup',co,name)
  if kind=='BindForcePlatform' and not o['platformFlags']&0x100:v['result']=None
  return v
 if kind in ['IsUsingForce','PlayerUsingForce']:value=int(o['bound'] is not None and o['player'] and o['state']==8 and o['forceTarget']==o['bound'])
 else:
  value=0;index=o['ground']
  if o['bound'] is not None and o['player'] and any(o['groundFlags']) and index!=-1:
   if not o['terrain'] or index<0 or index>=len(o['terrainHeights']) or not o['transforms'][index]:return None
   if o['terrainHeights'][index]<=o['height']:
    if not o['memberGroup']:return None
    value=int(index in o['members'])
 return dict(result=value if kind=='IsUsingForce' else q.bits(float(value)),events=[])
def run(kind,inputs=None,name=None,source=None):
 o=options(inputs or {});want=model(kind,o,name)
 if want is None:excluded.append(dict(kind=kind,options=o,reason='Native pointer/index backing is invalid; outside bounded contract.'));return
 setup(o,name);before=n.read(D,0x65000)
 if kind.startswith('Bind'):result=identity(n.call(ADDR[kind],[0,q.TEXT if name is not None else 0,0]))
 elif kind=='IsUsingForce':result=n.call(ADDR[kind],[PLAYER if o['player'] else 0,obj(o['bound'])])
 else:
  n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(ADDR[kind],[0,0,0,0,obj(o['bound'])]);n.mu.emu_start(n.STOP,n.STOP+6);result=n.unpack('<I',OUT)[0]
 got=dict(result=result,events=q.events.copy());bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x65000)!=before:bad.append('Input memory changed')
 if bad:errors.append(dict(kind=kind,options=o,name=name,bad=bad))
 rows.append(dict(kind=kind,options=o,name=name,native=got,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());uses={r['name']:r['uses'] for r in ledger['rows'] if r['name'] in ['PlayerUsingForce','PlayerOnForcePlatform']}
 for kind in ['BindUsingForce','BindForcePlatform']:
  for name,typ,flags,gate in itertools.product([None,'','alpha','ALPHA','beta','gamma','omega','edge','missing','alpha\0ignored'],[-1,0,1,3,4,7],[0,0xff,0x100,0xffffffff],['normal','types','registry']):
   o=dict(forceType=typ,platformFlags=flags)
   if gate!='normal':o[gate]=False
   run(kind,o,name)
 for kind in ['IsUsingForce','PlayerUsingForce']:
  for bound,target,player,state in itertools.product([None,[0,0],[0,1],[1,1]],[None,[0,0],[0,1],[1,1]],[False,True],[0,1,7,8,9,59,255]):run(kind,dict(bound=bound,forceTarget=target,player=player,state=state))
 for player,bound,flags,index,height,members in itertools.product([False,True],[None,[0,0]],[[0,0],[1,0],[0,1],[255,128]],[-1,0,1,2,3],[-1.,0.,1.,2.,3.,4.],[[],[0],[1,2,3],[3,2,1,2],[4,5,-1,-32768,32767]]):run('PlayerOnForcePlatform',dict(player=player,bound=bound,groundFlags=flags,ground=index,height=height,members=members))
 for invalid in [dict(terrain=False),dict(ground=-2),dict(ground=4),dict(transforms=[True,True,False,True]),dict(memberGroup=False)]:
  for gate in [dict(),dict(bound=None),dict(player=False),dict(groundFlags=[0,0]),dict(ground=-1),dict(height=-1.)]:run('PlayerOnForcePlatform',dict(invalid,**gate))
 for kind,authored in uses.items():
  bind='BindUsingForce' if kind=='PlayerUsingForce' else 'BindForcePlatform'
  for source in authored:run(bind,name=source['args'][0],source=source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=len(rows),fullMemoryBytes=len(rows)*0x65000,excludedInvalidPointerCases=len(excluded),authoredUses={k:len(v) for k,v in uses.items()},examples=errors[:6],method='Unchanged original wrappers,4678f0,55a020 and558770; exact pointer identity, float32 returns, accessor order and complete fixture memory compared to independent bounded model.',limits=['Finite heights and readable terrain backing; unsafe negative/out-of-range ground indices, missing transforms and missing platform member groups excluded after actual short-circuit gates.','Ordered finite acyclic member lists projected to short-index arrays. Physical Force simulation and loaded-level binding remain external.','Authored operand names replayed against prepared type/name tables, not a captured loaded level. Managed replay pending.'])
 (B/'reports/native-force-conditions-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-force-conditions-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,names=q.names,cases=rows,excluded=excluded),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
