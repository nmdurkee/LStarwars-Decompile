"""Bounded observation: physical zero-read beforedeclaredEOF leavesoriginal4fb550 nonprogress loop; not paired/credited."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase77-20261013-verify.py').read_text().split('\nfor handle,wanted')[0])
config=dict(handle=1,wanted=1,size=1,physicalSize=0,cache=0,position=0,hasBuffer=True,chunk=1024);setup77(config);events=[];backend=0;stop=None
try:n.call(0x4fb550,[1,OUT,1],count=20000)
except RuntimeError as error:stop=str(error)
report=dict(binarySha256=n.sha256,classification='Unsupportedoriginalnonprogress observation, no pairedcoveragecredit',hostInstructionBudget=20000,stop=stop,readFileCalls=sum(e['name']=='ReadFile'for e in events),streamRecord=n.read(0x8ceb50,64).hex(),sourceQualification='PreparedScriptBufferedRead requires boundedpositiveprogress/EOF; its8192loop budget raises instead ofinfinite original behavior.')
(nm.BASE/'reports/script-phase77-20261013-nonprogress.json').write_text(json.dumps(report,indent=2));print(json.dumps(report))
