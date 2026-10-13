import json,base64,hashlib,time
from pathlib import Path
peer=Path(__file__).with_name('world-phase14-20261013-composed-verify.py');src=peer.read_text();scope={'__file__':str(peer)};exec(compile(src[:src.index("for f in sorted((B/'extracted')")],str(peer),'exec'),scope)
B=scope['B'];ns=scope['ns'];io=scope['io'];Image=scope['Image'];ns['ns']['sprite']=scope['bound_sprite'];data=json.loads((B/'reports/world-phase14-20261013-composed-vectors.json').read_text());summaries=[];checks=0
for c in data['cases']:
 io['current']=c;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;ns['ns']['assetHash']=hashlib.sha256();ns['ns']['assetCounts']={};m=Image(c);ns['load'](m,c);checks+=1;assert m.digest()==c['expected']['sha256']
 records=m.word(0x2920a94);ids=[m.half(0x2913a58+i*376+144+j*2) for i in range(records) for j in range(8)];resolved=sum(x not in [65535,9998,9999] for x in ids);missing=sum(x==9998 for x in ids);special=sum(x==9999 for x in ids)
 summaries.append(dict(path=c['authored'],records=records,catalogEntries=len(c['catalogNamesB64']),resolvedSpriteSlots=resolved,missingSpriteSentinels=missing,specialNullSpriteSlots=special))
report=dict(cases=len(summaries),checks=checks,mismatches=0,records=sum(x['records'] for x in summaries),resolvedSpriteSlots=sum(x['resolvedSpriteSlots'] for x in summaries),missingSpriteSentinels=sum(x['missingSpriteSentinels'] for x in summaries),maxCatalogEntries=max(x['catalogEntries'] for x in summaries),scope='Saved-fixture model replay compared to native full-image hashes; slot counts are derived from those matching images. Catalogs are prepared from declared binding requests, not original scene assets.',details=summaries)
(B/'reports/world-phase14-20261013-replay-summary.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='details'}))
