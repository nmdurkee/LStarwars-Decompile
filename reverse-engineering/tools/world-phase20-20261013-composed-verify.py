import json,hashlib,struct,base64,gzip,time,os
from pathlib import Path
p=Path(__file__).with_name('world-phase18-20261013-verify.py');producer={'__file__':str(p)};src=p.read_text();exec(compile(src[:src.index('for i,pv in enumerate(provenance)')],str(p),'exec'),producer)
p=Path(__file__).with_name('world-phase19-20261013-verify.py');consumer={'__file__':str(p)};src=p.read_text();exec(compile(src[:src.index('cases=[]')],str(p),'exec'),consumer)
p=Path(__file__).with_name('world-phase20-20261013-verify.py');orientation={'__file__':str(p)};src=p.read_text();exec(compile(src[:src.index('cases=[];rng=')],str(p),'exec'),orientation)
n=producer['n'];B=producer['B'];REGIONS=producer['REGIONS'];publicationRegions=list(REGIONS);REGIONS.extend([(0x2948eb0,32),(0x810ad8,4),(0x8065c0,64),(0x29899a0,0x20000)]);producer['io']['REGIONS']=REGIONS;consumer['n']=n;orientation['REGIONS']=REGIONS
common=[producer['patch'](0x8065c0,orientation['template']),producer['patch'](0x29899a0,orientation['sine'])]
class MatrixAdapter:
 def __init__(self,m):self.m=m
 def W(self,a,v=None):return self.m.word(a,v)
 def B(self,a,v):self.m.write(a,bytes([v&255]))
readonlyPorts=consumer['PORTS'];realPorts={0x684640:'primary',0x6846a0:'secondary',0x684720:'mode'}
oldservice=consumer['service']
def recovered(im,address,args):
 result=oldservice(im,address,args)
 if address in realPorts:
  c=dict(kind=realPorts[address],id=args[0],angles=args[1:] if address!=0x684720 else args[2:],mode=args[1] if address==0x684720 else 0);orientation['orientation'](MatrixAdapter(im),c)
 return result
consumer['service']=recovered
for address in realPorts:del readonlyPorts[address]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
n.mu.hook_add(UC_HOOK_CODE,consumer['hook'])
def observe(uc,address,size,user):
 if address in [0x684640,0x6846a0,0x684720,0x64ff80,0x64ffe0,0x6500c0,0x6501a0]:orientation['entries'][hex(address)]=orientation['entries'].get(hex(address),0)+1
 if address in realPorts:
  sp=uc.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*(3 if address==0x684640 else 4),sp+4));oldservice(consumer['NativeImage'](),address,args)
n.mu.hook_add(UC_HOOK_CODE,observe)
data=json.loads(gzip.decompress((B/'reports/world-phase19-20261013-composed-vectors.json.gz').read_bytes()));cases=data['cases'];rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 if i%20==0:(B/'reports/world-phase20-20261013-composed-progress.json').write_text(json.dumps(dict(status='unsealed running',pid=os.getpid(),case=i,total=len(cases),seconds=round(time.time()-start,2)))+'\n')
 c=dict(c);c['writes']=list(c['writes'])+common;io=producer['io'];io['current']=c;im=producer['env']['Image'](c);producer['services']=[];producer['allocations']=[];producer['effects']=[];producer['env']['audioHash']=hashlib.sha256();producer['env']['audioCalls']=0;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0
 producer['load'](im,c);published=hashlib.sha256(b''.join(im.read(a,z) for a,z in publicationRegions)).hexdigest();checks+=1
 if published!=c['phase18Sha256']:errors.append(dict(case=i,key='prepared producer image provenance',expected=c['phase18Sha256'],actual=published));break
 # Seed from the exact publication projection whose full image SHA is authenticated by prior original execution.
 for a,z in REGIONS:n.write(a,im.read(a,z))
 consumer['case']={};consumer['marker']=None;consumer['trace']=[];consumer['lookups']=[];n.call(0x68e4f0,count=10000000)
 actual=dict(sha256=hashlib.sha256(b''.join(n.read(a,z) for a,z in REGIONS)).hexdigest(),trace=consumer['trace'].copy(),lookups=consumer['lookups'].copy(),selected=n.unpack('<I',0x29231a8)[0])
 consumer['case']={};consumer['marker']=None;consumer['trace']=[];consumer['lookups']=[];consumer['activate'](im);predicted=dict(sha256=im.digest(),trace=consumer['trace'].copy(),lookups=consumer['lookups'].copy(),selected=im.word(0x29231a8))
 for k in actual:
  checks+=1
  if actual[k]!=predicted[k]:errors.append(dict(case=i,key=k,actual=actual[k],model=predicted[k]))
 if errors:break
 c['expected']=actual;rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors[:5],activationEntries=consumer['entries'],orientationEntries=orientation['entries'],authoredDeclarations=sum(len(c['expected']['lookups']) for c in rows),binarySha256=n.sha256,seconds=round(time.time()-start,3),producerWasFreshNativeExecution=False,producerSeedVerifiedAgainstPreviousFullNativeImage=True,fullImageBytes=sum(z for a,z in REGIONS),reaReads='queued2003..2009 independently; not a managed/game execution')
(B/'reports/world-phase20-20261013-composed-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase20-20261013-composed-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==producer['D'] else 0) for a,z in REGIONS],publicationRegions=[dict(address=a,length=z) for a,z in publicationRegions],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
