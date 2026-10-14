"""Enlarged-bank original rawfile pipeline proves admissionthrough expression slot255 then wrapped0."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase26-20261013-verify.py').read_text().split('\nfiles=')[0])
for chunk,callback,handled in itertools.product([1,17,4096],[False,True],[0,1]):
 execute26(dict(file='\n'.join(['IF AlwaysTrue = symbol and']*257)+'\n}',lines=[],chunk=chunk,callback=callback,handled=handled,bottom=BANK+0x5000));node=n.unpack('<I',LIST)[0];slots=[];nodes=0
 while node:
  nodes+=1
  if n.unpack('<H',node+14)[0]&8:slots.append(n.unpack('<B',node+13)[0])
  node=n.unpack('<I',node)[0]
 wanted=[]if callback and handled else list(range(256))+[0];checks+=1
 if nodes!=257 or slots!=wanted:errors.append(dict(group='admissionAndSlots',context=cases[-1]['context'],nodes=nodes,slots=slots,wanted=wanted))
 cases[-1]['nativeProjection']=dict(nodes=nodes,expressionSlots=slots)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],scope='257 admittedconditions with20KiBbank; native cache slotbytewrap255→0 verified, handledcallbackcontrol hasnocachedexpressions',managedExecution=False)
(nm.BASE/'reports/script-phase26-20261013-expanded-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase26-20261013-expanded-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
