"""Originalcachedopponentrange callbacks; rawscalarpresence words, no children or services."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase51-20261013-verify.py').read_text().split('\nfor address,flags,ref')[0])
segments.append((0x75ecf0,4));originalSetup52=setup27

def setup27(c,address):
 originalSetup52(c,address);n.pack('<I',ACTOR+0xe4,c.get('presence',1));n.pack('<I',ACTOR+0xd4,c.get('presence',1));n.pack('<I',ACTOR+0xe8,c.get('value',0));n.pack('<I',ACTOR+0xd8,c.get('value',0))
def predicate51(address,actor,packet,arg14,arg18):
 ref,value=(0xe4,0xe8)if address==0x515250 else(0xd4,0xd8)
 return rd(actor+value)if actor and rd(actor+ref)else rd(0x75ecf0)
values52=[0,0x80000000,1,0x7fffff,0x7f7fffff,0xff7fffff,0x7f800000,0xff800000,0x7fc12345,0xffc12345,bits(-2.),bits(4.)];rng=random.Random(0x515250)
for i in range(32):
 value=rng.randrange(1<<32)
 if value&0x7f800000!=0x7f800000:values52.append(value)
for address,value,presence,nullActor in itertools.product([0x515250,0x515270],values52,[0,1,0xffffffff,0x80000000],[False,True]):execute51(address,dict(value=value,presence=presence,nullActor=nullActor))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=[])
(nm.BASE/'reports/script-phase52-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase52-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
