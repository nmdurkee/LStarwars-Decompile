"""Actual filesystem parser composition with actual default filename formatter; finalOS file APIs only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase95-20261013-verify.py').read_text().split('\nfor data,buffered')[0])
p96=Path(__file__).with_name('script-phase96-20261013-verify.py').read_text();exec(p96[p96.index('def length96'):p96.index('def execute96')]);p97=Path(__file__).with_name('script-phase97-20261013-verify.py').read_text();exec(p97[p97.index('def formatter97'):p97.index('def execute97')]);LOCAL97=D+0x15000
segments +=[(0x75c044,4)]
def format94(provider,destination,path,capacity,model):
 assert model
 for i in range(512):shadow[LOCAL97+i]=0
 return formatter97(provider,destination,path,capacity)
#Instantiate the standard provider fields and actual callback after the earlier input-only setup.
setup94 += "\nfor p in[PROVIDER,PROVIDERS]:\n n.write(p+16,b'\\\\');n.write(p+52,b'\\0');n.write(p+76,b'\\0');n.write(p+172,b'\\0');n.pack('<I',p+0x22c,0x4ff130)\nn.write(0x75c044,b':\\0\\0\\0')"
for data,buffered,close,freeParsers in itertools.product(['','ef','efbb','efbbbf4162','bbefbf4162','feff0041','fffe4100','416263'],[0,1,7],[False,True],[[0],[]]):execute95(dict(data=data,buffered=buffered,close=close,freeParsers=freeParsers,type=0,mode=0,free=0))
for data,cold,close,free in itertools.product(['efbbbf4162','416263'],[False,True],[False,True],[16,17]):execute95(dict(data=data,buffered=7,close=close,freeParsers=[3],cold=cold,type=0,mode=0,free=free))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=0,ports=['CreateFile','SetFilePointerEx','ReadFile','CloseHandle'],closure='Whole filesystem parser composition95 with actual4ff130 filename formatter→actual byte/prefix/normalization/compaction/cookie, no formatter/file transport adapters')
(nm.BASE/'reports/script-phase98-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase98-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
