import json,struct,hashlib,base64,time
from pathlib import Path
peer=Path(__file__).with_name('world-phase12-20261013-verify.py');s=peer.read_text();s=s[:s.rindex('cases=[];provenance=[]')];s=s.replace('for a in [0x64c300,0x64ae50,0x644000]:','for a in [0x64c300]:');ns={'__file__':str(peer)};exec(compile(s,str(peer),'exec'),ns)
runpeer=Path(__file__).with_name('world-phase13-20261013-verify.py');runtime={'__file__':str(runpeer)};s=runpeer.read_text();exec(compile(s[:s.index('rng=random.Random')],str(runpeer),'exec'),runtime)
n=ns['n'];B=ns['B'];D=ns['D'];REC=ns['REC'];io=ns['io'];IN=ns['IN'];REGIONS=ns['REGIONS']+[(0x8102e8,4),(0x291f714,12)];ns['REGIONS']=REGIONS;ns['ns']['REGIONS']=REGIONS;io['REGIONS']=REGIONS
class Image(ns['Image']):
 def F(self,a,v=None):
  if v is None:return struct.unpack('<f',self.read(a,4))[0]
  self.word(a,runtime['bits'](runtime['f32'](v)))
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
runtimeEvents=[];timingContexts=[];entryCounts={}
def observe(uc,a,z,data):
 entryCounts[hex(a)]=entryCounts.get(hex(a),0)+1
 if a not in [0x64ae50,0x644000]:return
 sp=uc.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4+i*4)[0]
 if a==0x64ae50:
  index=arg(0);runtimeEvents.append(['activate',index,arg(1)]);id=n.unpack('<I',IN+index*108+12)[0];r=REC+id*376
  timingContexts.append(dict(instance=index,id=id,rate=n.unpack('<f',r+204)[0],duration=n.unpack('<f',r+236)[0],variation=n.unpack('<f',r+240)[0],interval=n.unpack('<f',r+244)[0],intervalVariation=n.unpack('<f',r+248)[0]))
 else:runtimeEvents.append(['select',arg(0)])
for a in [0x64ae50,0x644000,0x5b9d90,0x6e6b90,0x5b3800]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def model_runtime(m,kind,args):
 runtimeEvents.append([kind]+args)
 if kind=='activate':runtime['activate'](m,args[0],struct.unpack('<f',struct.pack('<I',args[1]))[0])
 else:runtime['select'](m,struct.unpack('<f',struct.pack('<I',args[0]))[0])
ns['runtime']=model_runtime
spritepeer=Path(__file__).with_name('world-phase14-20261013-verify.py');sprites={'__file__':str(spritepeer)};spcode=spritepeer.read_text();exec(compile(spcode[:spcode.index('rng=random.Random')],str(spritepeer),'exec'),sprites)
SC=D+0x94000;ALT=D+0x94400;BACK=D+0x96000;OLD=D+0x98000;NEW=D+0x9d000;NAMES=D+0xaa000
catalog=[]
def gather(m,q,scene):
 if q[0] and q.split(b'\0',1)[0]!=b'NULL instance' and q not in catalog:catalog.append(q)
 return 9999 if q.split(b'\0',1)[0]==b'NULL instance' else -1
def bound_sprite(m,q,scene):
 ns['ns']['emit'](0x6488e0,q,scene);return sprites['find_bytes'](m,q,scene)
for addr in [0x5da840,0x5da860,0x5cfac0,0x5cfa50]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=addr,end=addr)
rows=[];fails=[];provenance=[];catalogEvidence=[];start=time.time()
for f in sorted((B/'extracted').rglob('*.PAR')):
 raw=f.read_bytes();path=str(f.relative_to(B)).replace('\\','/');c=ns['seed'](raw);c['authored']=path;provenance.append(dict(path=path,bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest()))
 # Local prepass extracts the exact raw16-byte binding requests from this unchanged authored input.
 catalog=[];ns['ns']['assetHash']=hashlib.sha256();ns['ns']['assetCounts']={};ns['ns']['sprite']=gather;io['current']=c;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;ns['load'](Image(c),c)
 catalog=[b'Unused catalog'.ljust(16,b'\0')]+catalog;assert len(catalog)<=256
 ns['ns']['sprite']=bound_sprite;c['catalogNamesB64']=[base64.b64encode(q).decode() for q in catalog]
 patch=ns['patch'];wp=ns['wp'];c['writes'] += [wp(0x29208d0+31*4,ALT),wp(0x291f688+31*4,0)]
 for sc,modern in [(SC,len(rows)%2==0),(ALT,len(rows)%2!=0)]:c['writes'] += [wp(sc+0x24,len(catalog)),wp(sc+0x28,OLD),wp(sc+0x110,BACK if modern else 0)]
 c['writes'] += [wp(BACK+0x6c,len(catalog)),wp(BACK+0x70,NEW)]
 for i,q in enumerate(catalog):c['writes'] += [patch(NAMES+i*16,q),wp(OLD+i*76+68,NAMES+i*16),wp(NEW+i*208+180,NAMES+i*16)]
 catalogEvidence.append(dict(path=path,count=len(catalog),sha256=hashlib.sha256(b''.join(catalog)).hexdigest(),primaryTable='backend' if len(rows)%2==0 else 'legacy'))
 m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 io['current']=c;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;ns['ns']['assetHash']=hashlib.sha256();ns['ns']['assetCounts']={};runtimeEvents=[]
 result=n.call(0x64c300,[io['PATH'],1,D+0x90000,1],count=100000000);vm=ns['vm']
 observed=dict(result=result,sha256=vm.digest(),assetSha256=ns['ns']['assetHash'].hexdigest(),assetCalls=ns['ns']['assetCounts'].copy(),runtime=runtimeEvents.copy(),trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;ns['ns']['assetHash']=hashlib.sha256();ns['ns']['assetCounts']={};runtimeEvents=[]
 try:
  predicted=ns['load'](m,c);prediction=dict(result=predicted,sha256=m.digest(),assetSha256=ns['ns']['assetHash'].hexdigest(),assetCalls=ns['ns']['assetCounts'].copy(),runtime=runtimeEvents.copy(),trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 except Exception as e:prediction=dict(error=str(e))
 if observed!=prediction:fails.append(dict(case=len(rows),path=path,observed=observed,prediction=prediction,contexts=timingContexts[-5:]));print(json.dumps(fails[-1]));break
 c['expected']=observed;rows.append(c)
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(fails),entryCalls=entryCounts,physicalAndAssetCalls=ns['ns']['totals'],authoredFiles=provenance,timingContexts=timingContexts,loadedCatalogs=catalogEvidence,seconds=round(time.time()-start,3),failures=fails)
(B/'reports/world-phase14-20261013-composed-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fails:(B/'reports/world-phase14-20261013-composed-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==REC else 0) for a,z in REGIONS],cases=rows),separators=(',',':'))+'\n')
print(json.dumps({k:v for k,v in report.items() if k not in ['timingContexts','authoredFiles']}));assert not fails
