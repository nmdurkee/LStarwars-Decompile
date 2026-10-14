import json,hashlib,struct,base64,gzip,time,os
from pathlib import Path
p=Path(__file__).with_name('world-phase18-20261013-verify.py');producer={'__file__':str(p)};src=p.read_text();exec(compile(src[:src.index('for i,pv in enumerate(provenance)')],str(p),'exec'),producer)
p=Path(__file__).with_name('world-phase19-20261013-verify.py');consumer={'__file__':str(p)};src=p.read_text();exec(compile(src[:src.index('cases=[]')],str(p),'exec'),consumer)
n=producer['n'];B=producer['B'];REGIONS=producer['REGIONS'];publicationRegions=list(REGIONS);REGIONS.extend([(0x2948eb0,32),(0x810ad8,4)]);producer['io']['REGIONS']=REGIONS;consumer['n']=n
from unicorn import UC_HOOK_CODE
n.mu.hook_add(UC_HOOK_CODE,consumer['hook'])
data=json.loads(gzip.decompress((B/'reports/world-phase18-20261013-vectors.json.gz').read_bytes()));cases=[c for c in data['cases'] if c.get('authored')];errors=[];rows=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 if i%10==0:
  print('progress',i,len(cases),flush=True);(B/'reports/world-phase19-20261013-composed-progress.json').write_text(json.dumps(dict(status='unsealed running',pid=os.getpid(),case=i,total=len(cases),seconds=round(time.time()-start,2)))+'\n')
 c=dict(c);c['phase18Sha256']=c['expected']['sha256'];c['writes']=list(c['writes'])+[producer['wp'](0x810ad8,0x12345678)];io=producer['io'];io['current']=c;im=producer['env']['Image'](c)
 for a,z in REGIONS:n.write(a,im.read(a,z))
 producer['services']=[];producer['allocations']=[];producer['effects']=[];producer['env']['audioHash']=hashlib.sha256();producer['env']['audioCalls']=0;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;consumer['case']={};consumer['marker']=None;consumer['trace']=[];consumer['lookups']=[]
 nativeReturn=n.call(0x68df20,[io['PATH'],c['mode'],c['scene']],count=10000000);nativePublished=hashlib.sha256(b''.join(n.read(a,z) for a,z in publicationRegions)).hexdigest()
 n.call(0x68e4f0,count=10000000)
 actual=dict(sha256=hashlib.sha256(b''.join(n.read(a,z) for a,z in REGIONS)).hexdigest(),trace=consumer['trace'].copy(),lookups=consumer['lookups'].copy(),selected=n.unpack('<I',0x29231a8)[0],publicationResult=nativeReturn,publicationSha256=nativePublished)
 consumer['case']={};consumer['marker']=None;consumer['trace']=[];consumer['lookups']=[];producer['services']=[];producer['allocations']=[];producer['effects']=[];producer['env']['audioHash']=hashlib.sha256();producer['env']['audioCalls']=0;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0
 modelReturn=producer['load'](im,c);modelPublished=hashlib.sha256(b''.join(im.read(a,z) for a,z in publicationRegions)).hexdigest();consumer['activate'](im)
 predicted=dict(sha256=im.digest(),trace=consumer['trace'].copy(),lookups=consumer['lookups'].copy(),selected=im.word(0x29231a8),publicationResult=modelReturn,publicationSha256=modelPublished)
 for k in actual:
  checks+=1
  if actual[k]!=predicted[k]:errors.append(dict(case=i,authored=c['authored'],key=k,actual=actual[k],model=predicted[k]))
 checks+=1
 if nativePublished!=c['expected']['sha256']:errors.append(dict(case=i,key='immutable phase18 prepared result',expected=c['expected']['sha256'],actual=nativePublished))
 if errors:break
 c['expected']=actual;rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors[:5],entryCounts=consumer['entries'],authoredFiles=data.get('authoredFiles',producer['provenance']),authoredDeclarations=sum(len(c['expected']['lookups']) for c in rows),binarySha256=n.sha256,seconds=round(time.time()-start,3),fullImageBytes=sum(z for a,z in REGIONS))
(B/'reports/world-phase19-20261013-composed-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase19-20261013-composed-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==producer['D'] else 0) for a,z in REGIONS],publicationRegions=[dict(address=a,length=z) for a,z in publicationRegions],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps({k:v for k,v in report.items() if k!='authoredFiles'}));assert not errors
