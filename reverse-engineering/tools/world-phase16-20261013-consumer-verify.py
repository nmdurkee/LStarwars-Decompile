import json,struct,hashlib,base64,time
from pathlib import Path
peer=Path(__file__).with_name('world-phase16-20261013-verify.py');src=peer.read_text();scope={'__file__':str(peer)};exec(compile(src[:src.rindex('cases=[];provenance=[]')],str(peer),'exec'),scope)
p=src.index('# Prepare readable audio names');e=src.index('for c in cases:',p);exec(compile(src[p:e],str(peer),'exec'),scope);scope['audio']=scope['loaded_audio'];n=scope['n'];B=scope['B'];io=scope['io'];assets=scope['assets'];REGIONS=scope['REGIONS'];data=json.loads((B/'reports/world-phase16-20261013-vectors.json').read_text());rows=[];calls=0;checks=0;skipped=0;failures=[];start=time.time()
for c in data['cases']:
 io['current']=c;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;scope['audioHash']=hashlib.sha256();scope['audioCalls']=0;scope['services']=[];m=scope['Image'](c);result=scope['load'](m,c);checks+=1;assert m.digest()==c['expected']['sha256']
 for a,z in REGIONS:n.write(a,m.read(a,z))
 probes=[]
 if result!=0xffffffff:
  for slot in range(1,min(m.word(0x2962a24),9)):
   record=m.word(m.word(0x296209c)+slot*4)
   if not record:continue
   query=m.read(record,16)
   if 0 not in query:skipped+=1;continue
   general=n.call(0x658330,[record,result,0],count=1000000);fast=n.call(0x658490,[record,result],count=1000000);calls+=2
   expectedGeneral=assets['particle'](m,query,result,False,0);expectedFast=assets['particle'](m,query,result,True,0);checks+=2
   if (general,fast)!=(expectedGeneral,expectedFast):failures.append(dict(case=len(rows),slot=slot,general=general,fast=fast,expectedGeneral=expectedGeneral,expectedFast=expectedFast));raise AssertionError(failures[-1])
   probes.append(dict(slot=slot,record=record,general=general,fast=fast))
 c['consumers']=probes;rows.append(c)
report=dict(binarySha256=n.sha256,cases=len(rows),checks=checks,nativeConsumerCalls=calls,mismatches=len(failures),skippedNonterminatedNames=skipped,seconds=round(time.time()-start,3),scope='Reconstruct each retained original loader image with saved raw input and compare full native hash first, then execute unchanged native658330/658490 against exactly that published table and compare to raw loaded bindings. No extra entry mapping credit.')
(B/'reports/world-phase16-20261013-consumer-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/world-phase16-20261013-consumer-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=data['regions'],authoredFiles=data['authoredFiles'],cases=rows),separators=(',',':'))+'\n');print(json.dumps(report))
