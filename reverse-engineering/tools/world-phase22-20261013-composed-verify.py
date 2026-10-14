import json,hashlib,struct,base64,gzip,time,os
from pathlib import Path
p=Path(__file__).with_name('world-phase18-20261013-verify.py');producer={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('for i,pv in enumerate(provenance)')],str(p),'exec'),producer)
p=Path(__file__).with_name('world-phase19-20261013-verify.py');consumer={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[]')],str(p),'exec'),consumer)
p=Path(__file__).with_name('world-phase21-20261013-verify.py');ctor={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),ctor)
p=Path(__file__).with_name('world-phase22-20261013-verify.py');tim={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),tim)
n=producer['n'];B=producer['B'];D=producer['D'];REGIONS=producer['REGIONS'];publicationRegions=list(REGIONS)
REGIONS.extend([(0x2948eb0,32),(0x810ad8,4),(0x8065c0,64),(0x29899a0,0x20000),(0x810710,0x2b8),(0x8109d0,0x108),(0x810adc,0x68),(0x29620a8,4),(0x296205c,8),(0x2962084,4),(0x2962094,4),(0x29211e8,4),(0x29a9c48,4)])
producer['io']['REGIONS']=REGIONS;consumer['n']=n
common=[producer['patch'](0x8065c0,ctor['rot']['template']),producer['patch'](0x29899a0,ctor['rot']['sine']),producer['patch'](0x810710,n.read(0x810710,0x2b8)),producer['patch'](0x8109d0,n.read(0x8109d0,0x108)),producer['patch'](0x810adc,n.read(0x810adc,0x68))]
class Adapter:
 def __init__(self,m):self.m=m
 def W(self,a,v=None):return self.m.word(a,v)
 def H(self,a,v=None):return self.m.half(a,v)
 def B(self,a,v=None):
  if v is None:return self.m.byte(a)
  self.m.write(a,bytes([v&255]))
 def read(self,a,z):return self.m.read(a,z)
 def write(self,a,b):return self.m.write(a,b)
def service(im,address,args):
 if address==0x684ee0:
  consumer['marker']=args[0];ctor['create'](Adapter(im),args[0],args[1],args[2:]);return 0
 if address in [0x684640,0x6846a0,0x684720]:
  ctor['rot']['orientation'](Adapter(im),dict(kind={0x684640:'primary',0x6846a0:'secondary',0x684720:'mode'}[address],id=args[0],angles=args[1:] if address!=0x684720 else args[2:],mode=args[1] if address==0x684720 else 0));return 0
 marker=consumer['marker'];consumer['trace'].append([address,args.copy(),im.word(0x29620a4),im.word(marker) if marker is not None else None])
 if address==0x655c30:tim['timing'](Adapter(im),args[0],args[1]);return 0
 if address==0x5d92b0:im.write(args[1],struct.pack('<3f',17,18,19));return 0x12340000
 raise ValueError(hex(address))
consumer['service']=service;ctor['timer']=lambda im,p,t:service(im.m,0x655c30,[p,t])
for a in [0x684ee0,0x684640,0x6846a0,0x684720,0x655c30]:del consumer['PORTS'][a]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
n.mu.hook_add(UC_HOOK_CODE,consumer['hook']);entries={}
def observe(uc,a,z,user):
 if a in [0x684ee0,0x6550b0,0x655940,0x655ba0,0x655da0,0x684640,0x6846a0,0x684720,0x64ff80,0x64ffe0,0x6500c0,0x6501a0,0x655c30,0x6e6b90,0x5b9d90]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a==0x684ee0:consumer['marker']=n.unpack('<I',uc.reg_read(UC_X86_REG_ESP)+4)[0]
 if a==0x655c30:
  sp=uc.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<2I',sp+4));marker=consumer['marker'];consumer['trace'].append([a,args,n.unpack('<I',0x29620a4)[0],n.unpack('<I',marker)[0] if marker is not None else None])
n.mu.hook_add(UC_HOOK_CODE,observe)
data=json.loads(gzip.decompress((B/'reports/world-phase19-20261013-composed-vectors.json.gz').read_bytes()));rows=[];errors=[];checks=0;start=time.time();successful=failed=0
constructionWrites=[producer['wp'](0x810900,0x12345678),producer['wp'](0x29a9c48,0),producer['wp'](0x2962094,16),producer['wp'](0x2962084,D+0xe5000),producer['wp'](0x29211e8,0),producer['wp'](0x29620a8,0),producer['wp'](0x296205c,0x41200000),producer['wp'](0x2962060,0x41a00000),producer['patch'](D+0xe5000,struct.pack('<16H',*range(16)))]
for i,c in enumerate(data['cases']):
 if i%20==0:(B/'reports/world-phase22-20261013-composed-progress.json').write_text(json.dumps(dict(status='unsealed running',pid=os.getpid(),case=i,total=len(data['cases']),seconds=round(time.time()-start,2)))+'\n')
 c=dict(c);c['writes']=list(c['writes'])+common;c['constructionWrites']=constructionWrites;io=producer['io'];io['current']=c;im=producer['env']['Image'](c);producer['services']=[];producer['allocations']=[];producer['effects']=[];producer['env']['audioHash']=hashlib.sha256();producer['env']['audioCalls']=0;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0
 producer['load'](im,c);published=hashlib.sha256(b''.join(im.read(a,z) for a,z in publicationRegions)).hexdigest();checks+=1
 if published!=c['phase18Sha256']:errors.append(dict(case=i,key='publication provenance',expected=c['phase18Sha256'],actual=published));break
 for p in constructionWrites:im.write(p['address'],base64.b64decode(p['data']))
 for a,z in REGIONS:n.write(a,im.read(a,z))
 consumer['case']={};consumer['marker']=None;consumer['trace']=[];consumer['lookups']=[];n.call(0x68e4f0,count=20000000)
 actual=dict(sha256=hashlib.sha256(b''.join(n.read(a,z) for a,z in REGIONS)).hexdigest(),trace=consumer['trace'].copy(),lookups=consumer['lookups'].copy(),selected=n.unpack('<I',0x29231a8)[0],allocationCursor=n.unpack('<I',0x29211e8)[0])
 consumer['case']={};consumer['marker']=None;consumer['trace']=[];consumer['lookups']=[];consumer['activate'](im);predicted=dict(sha256=im.digest(),trace=consumer['trace'].copy(),lookups=consumer['lookups'].copy(),selected=im.word(0x29231a8),allocationCursor=im.word(0x29211e8))
 for k in actual:
  checks+=1
  if actual[k]!=predicted[k]:errors.append(dict(case=i,key=k,actual=actual[k],model=predicted[k]))
 if errors:
  for a,z in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=actual;rows.append(c);successful+=actual['allocationCursor'];failed+=sum(n.unpack('<I',0x2924b60+j*0x58)[0]==99999 for j in range(512))
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors[:8],activationEntries=consumer['entries'],constructionEntries=entries,authoredDeclarations=sum(len(c['expected']['lookups']) for c in rows),successfulAllocations=successful,restoredMarkers=failed,preparedEmitterCapacity=16,binarySha256=n.sha256,seconds=round(time.time()-start,3),producerWasFreshNativeExecution=False,producerSeedVerifiedAgainstPreviousFullNativeImage=True,fullImageBytes=sum(z for a,z in REGIONS),explicitAdapters=['5d92b0 scene query only'])
(B/'reports/world-phase22-20261013-composed-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase22-20261013-composed-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==D else 0) for a,z in REGIONS],publicationRegions=[dict(address=a,length=z) for a,z in publicationRegions],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
