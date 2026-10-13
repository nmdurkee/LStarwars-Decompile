"""Portable saved-fixture readback of same Python model; no new native coverage."""
import json,ast,struct
from pathlib import Path
base=Path(__file__).resolve().parent.parent
source=(base/'tools/script-phase19-20261013-verify.py').read_text();tree=ast.parse(source)
D=0x10100000;P=D+0x1000;L=D+0x2000;N=L+0x100;DESC=D+0x3000;SCRIPT=D+0x4000;IDLE=SCRIPT+0x100;TARGET=SCRIPT+0x200;REF=SCRIPT+0x300;ACTOR=D+0x5000;SYS=D+0x6000
for node in tree.body:
 if isinstance(node,ast.FunctionDef)and node.name in ['bits','fl','signed','rb','wb','rd','wd','rw','ww','slot','cache','port','expr','finish','evaluate','enter','bind','scan']:exec(compile(ast.Module(body=[node],type_ignores=[]),str(base/'tools/script-phase19-20261013-verify.py'),'exec'))
fixture=json.loads((base/'reports/script-phase19-20261013-native-fixtures.json').read_text());checks=0;errors=[]
for index,c in enumerate(fixture['cases']):
 config=c['context'];shadow={row['address']+i:x for row in c['initial']for i,x in enumerate(bytes.fromhex(row['bytes']))};events=[];ordinal={};i=c['inputs'];method=c['method'];result=0;fault=False
 try:
  if method=='Evaluate':result=evaluate(i['bank'],i['system'],i['list'],i['actor'],i['packet'])
  elif method=='Finish':finish(i['bank'],i['list'],i['actor'],i['packet'],i['current'])
  elif method=='Scan':result=scan(i['system'],i['actor'],i['packet'])
  elif i['packet']and rd(i['packet']+4):
   packet=i['packet']
   if not scan(i['system'],i['actor'],packet):
    state=rd(packet+8)
    if state:
     match=evaluate(0,i['system'],state+8,i['actor'],packet)
     if match:message=rw(match+0xe);flags=rd(packet+0x50);wd(packet+0x50,flags^(((message*2)^flags)&4));enter(packet,rd(match+0x24))
 except RuntimeError:fault=True
 state=[dict(address=row['address'],bytes=bytes(shadow[row['address']+i]for i in range(len(row['bytes'])//2)).hex())for row in c['initial']]
 comparisons=[('fault',fault,c['fault']is not None),('events',events,c['nativeEvents']),('state',state,c['final'])]
 if method not in ['Finish','Tick']and not fault:comparisons.append(('return',result,c['returnValue']))
 for group,got,want in comparisons:
  checks+=1
  if got!=want:errors.append(dict(index=index,group=group,got=got,want=want))
report=dict(checks=checks,cases=len(fixture['cases']),mismatches=len(errors),errors=errors,scope='Portable retained-fixture same-model replay; no native binary or Unicorn dependency, no additional native coverage.')
(base/'reports/script-phase19-20261013-fixture-replay.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
