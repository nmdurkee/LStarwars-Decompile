"""Original base reset composed with all actual mode capability children."""
from pathlib import Path
import json,gzip,itertools
p29=Path(__file__).with_name('movement-phase29-20261013-native.py');code29=p29.read_text().split("for k in['reset','path','predicate']")[0];code29=code29.replace('0x6e69d0]:','0x6e69d0,0x407b60,0x481740,0x4cbe50]:');code29=code29.replace(' def port(a,args):\n  ev.append',' def port(a,args):\n  if a in[0x407b60,0x481740,0x4cbe50]:\n   oracle30({0x407b60:"normal",0x481740:"alternate",0x4cbe50:"special"}[a],c,img);return 0\n  ev.append');q29={'__file__':str(p29)};exec(compile(code29,str(p29),'exec'),q29)
p30=Path(__file__).with_name('movement-phase30-20261013-native.py');q30={'__file__':str(p30)};exec(compile(p30.read_text().split('for kind,mask,flags in itertools.product')[0],str(p30),'exec'),q30);q29['oracle30']=q30['oracle30'];n=q29['n'];D=q29['D'];ACT=q29['ACT'];m=q29['m'];MODEL=D+0x30000;CLIPS=D+0x32000
for addr in[0x407b60,0x481740,0x4cbe50]:del q29['services'][addr]
oldSetup=q29['setup29']
def setup31(c):
 oldSetup(c);n.pack('<I',ACT+0x50,MODEL);n.pack('<I',MODEL+0xc,CLIPS)
 for j,at in enumerate([0x18,0x220,0x224,0x228,0x22c,0x230,0x334]):n.pack('<I',CLIPS+at,c.get('present',127)&(1<<j))
 n.pack('<H',0x7f17d0,7);n.pack('<H',0x7f18bc,8)
q29['setup29']=setup31
for index,alternate,special in itertools.product(range(256),[0,1],[0,1]):q29['run29']('reset',dict(maskReturn=index,alternate=alternate,special=special,actorFlags=0x400 if index%2 else 0,defaultMask=index%3==0,mutate=index%5==0,suit=index%7==0,present=index&127))
for offset,flags in itertools.product([0x1f4,0x4ac,0xee8],[0,0x80,0x4000,0x8000000,0x8004080,0xffffffff]):q29['run29']('reset',dict(metaOffset=offset,metadataFlags=flags,callback=False))
errors=q29['errors'];vectors=q29['vectors'];checks=3*len(vectors);report=dict(status='sealed original base-reset/mode producer composition; managed replay unexecuted',binarySha256=n.sha256,cases=len(vectors),assertionGroups=checks,mismatches=len(errors),errors=[{k:v for k,v in e.items()if k!='events'}for e in errors[:5]],nativeEntryCounts=q29['counts'],explicitServices=[hex(a)for a in q29['services']],limits=['Actual mode capability functions407b60/481740/4cbe50,type predicate55e470,path reset414ad0,memset and64-bit shift execute unchanged.','Only optional mask callback and52f800 remain adapted; complete valid actor/type/model/clip/suit/metadata/world backing and duration domain inherited from phase29.','No new address/command credit; source parents/children immutable, portable harness supplies actual source graph binding.'])
(m.BASE/'reports/movement-phase31-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),checks=checks,mismatches=len(errors),errors=report['errors'][:2])))
if errors:raise SystemExit('Composition mismatches; no sealed fixture')
with gzip.open(m.BASE/'reports/movement-phase31-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
