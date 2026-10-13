"""Readback check of every retained standalone/pipeline fixture; not an independent native implementation."""
from pathlib import Path
import json
base=Path(__file__).resolve().parent
producer=base/'script-phase17-20261013-verify.py'
exec(compile(producer.read_text().split('for context,configured,retry in itertools.product')[0],str(producer),'exec'))
fixture=json.loads((native.BASE/'reports/script-phase17-20261013-native-fixtures.json').read_text())
ranges=[(A,0x1100),(B,0x1100),(INPUT,0x100),(ALTINPUT,0x100),(ALT,0x100),(CL,0x400),(AUX_A,0x1630),(0x93d5f0,0x400),(0x87a7c8,16),(0x80253c,4),(D+0x30000,0x1300),(0x29a99a4,4),(CAM,0x240),(PART,0x1000)]
checks={};errors=[]
for kind in ['unitCases','cases']:
 for index,c in enumerate(fixture[kind]):
  config=c['context'];shadow={};model_events=[];model_occurrences={}
  for seg in c['initial']:
   for i,x in enumerate(bytes.fromhex(seg['bytes'])):shadow[seg['address']+i]=x
  fault=False
  try:
   result=0
   if kind=='unitCases':
    if c['method']=='Change':result=change_base(c['packet'],c['name'])
    else:
     for call in range(c['calls']):timer(c['actor'],c['retry'])
   else:
    for call in range(c['calls']):release_model(c['input'])
  except RuntimeError:fault=True
  check(kind+'-fault',fault,c['nativeFault'] is not None,index)
  check(kind+'-whole-state',[bytes(rb(p+i)for i in range(z)).hex()for p,z in ranges],c['nativeState'],index)
  check(kind+'-callbacks',model_events,c['nativeEvents'],index)
  if kind=='unitCases'and c['method']=='Change'and not fault:check('unitCases-result',result,c['nativeResult'],index)
report=dict(checks=sum(checks.values()),groups=checks,mismatches=len(errors),errors=errors,scope='Lossless fixture-backing replay of same Python contract model; no new native coverage claim.')
(native.BASE/'reports/script-phase17-20261013-fixture-replay.json').write_text(json.dumps(report,indent=2))
print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
