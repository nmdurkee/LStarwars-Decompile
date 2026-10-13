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
rows=[];fails=[];provenance=[];start=time.time()
for f in sorted((B/'extracted').rglob('*.PAR')):
 raw=f.read_bytes();path=str(f.relative_to(B)).replace('\\','/');c=ns['seed'](raw);c['authored']=path;provenance.append(dict(path=path,bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest()));m=Image(c)
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
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(fails),entryCalls=entryCounts,physicalAndAssetCalls=ns['ns']['totals'],authoredFiles=provenance,timingContexts=timingContexts,seconds=round(time.time()-start,3),failures=fails)
(B/'reports/world-phase13-20261013-composed-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fails:(B/'reports/world-phase13-20261013-composed-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==REC else 0) for a,z in REGIONS],cases=rows),separators=(',',':'))+'\n')
print(json.dumps({k:v for k,v in report.items() if k not in ['timingContexts','authoredFiles']}));assert not fails
