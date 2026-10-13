"""Full original packet-to-pose dispatch with original default layer selector."""
from pathlib import Path
import importlib.util,json,gzip,base64,hashlib,struct,random,itertools,collections,time
s=importlib.util.spec_from_file_location('f',Path(__file__).with_name('animation-packet-pose-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
B=f.B;o=f.Oracle();rng=random.Random(0x62e290);started=time.time();base=json.loads(gzip.decompress((B/'reports/animation-skeletal-blend-native-fixtures.json.gz').read_bytes()));clips=base['clips'];decoded=[f.p.p.Clip(base64.b64decode(r['raw']))for r in clips];rigs=base['rigs'];cases=[];mismatches=0;errors=[];counts=collections.Counter()
def digest(rows):
 flat=[v for row in rows for v in row];return hashlib.sha256(struct.pack('<'+'I'*len(flat),*flat)).hexdigest()
def joints(ji):return[{'parent':j['parent'],'bind':[f.value(v)for v in j['bind']]}for j in rigs[ji]['joints']]
def packet(mode,a,b,current,frame=2.,af=3.,bf=4.,progress=.25,duration=1.):
 raw=bytearray(rng.randbytes(72));struct.pack_into('<6f',raw,0,frame,0.,progress,duration,af,bf);raw[0x31]=mode;struct.pack_into('<hhh',raw,0x32,a,b,current);return bytes(raw)
def check(raw,slots,ji,local,layerCount=1,mask=1,present=True):
 global mismatches
 js=joints(ji);raws=[None if x is None else decoded[x].raw for x in slots];request=f.select(raw,[x is not None for x in slots])if present and any(mask&(1<<i)for i in range(max(0,min(32,layerCount))))else None
 wantMatrix=[[0xa5a5a5a5]*16 for _ in js]
 if request is not None:
  if request['kind']=='bind':wantMatrix=f.bind(js,local)
  elif request['kind']=='single':
   clip=decoded[slots[request['clip']]];v=clip.sample(f.f32(f.value(request['frame'])-1));wantMatrix=f.p.p.pose(v,list(clip.raw[clip.flags:clip.flags+clip.nodes]),js)['world']
  else:
   a=decoded[slots[request['source']]];b=decoded[slots[request['target']]];initial=a.sample(f.f32(f.value(request['sourceFrame'])-1));out=f.p.blend(b,f.f32(f.value(request['targetFrame'])-1),initial,list(a.raw[a.flags:a.flags+a.nodes]),f.value(request['weight']),len(js));wantMatrix=f.p.p.pose([[f.value(v)for v in row]for row in out['values']],out['flags'],js,a.nodes)['world']
 got=o.dispatch(raw,raws,js,local,layerCount,mask,present);want={'matrices':wantMatrix,'requests':[]if request is None else[request],'packetPreserved':True,'arenaRestored':True}
 if got!=want:
  mismatches+=1
  if len(errors)<12:errors.append({'packet':raw.hex(),'slots':slots,'rig':ji,'expected':want,'native':got})
 cases.append({'kind':'dispatch','packet':raw.hex(),'slots':slots,'rig':ji,'local':[[f.bits(v)for v in row]for row in local],'layerCount':layerCount,'mask':mask,'present':present,'native':{'matricesSha256':digest(got['matrices']),'requests':got['requests'],'packetPreserved':got['packetPreserved'],'arenaRestored':got['arenaRestored']}});counts['dispatch']+=1
source=next(i for i,r in enumerate(clips)if r.get('source')=='CHARS/QUIGONJINN/BACKFLIP.AN3');target=next(i for i,r in enumerate(clips)if r.get('source')=='CHARS/QUIGONJINN/BLOCK1.AN3');assert decoded[source].nodes==decoded[target].nodes
ji=len(rigs);rigs.append({'joints':[{'parent':255,'bind':[f.bits(x)for x in f.p.p.IDENTITY]},{'parent':0,'bind':[f.bits(x)for x in f.p.p.IDENTITY]}],'source':{'synthetic':'two-joint packet selection hierarchy'}});local=[[f.f32(rng.uniform(-2,2))for _ in range(16)]for _ in range(2)]
for mode,a,b,current,presence in itertools.product([0,1,2,255],[-32768,-1,0,1,2,32767],[-32768,-1,0,1,2,32767],[-32768,-1,0,1,2,32767],range(4)):
 slots=[source if presence&1 else None,target if presence&2 else None];check(packet(mode,a,b,current),slots,ji,local)
for layerCount,mask,present in itertools.product([-1,0,1,2,31,32,33],[0,1,2,0x80000000,0xffffffff],[False,True]):check(packet(1,0,1,0),[source,target],ji,local,layerCount,mask,present)
for progress,duration in itertools.product([0.,-0.,.125,-.25,1.,2.,f.value(1)],[1.,-1.,3.,.0625,1e20]):check(packet(255,0,1,0,progress=progress,duration=f.f32(duration)),[source,target],ji,local)
for layerCount in [-1,0,1,2,15,16,31,32,33,100]:
 for mask in [0,1,2,0x80000000,0xffffffff]+[rng.randrange(1<<32)for _ in range(30)]:
  for present in [False,True]:
   got=o.layer_ids(layerCount,mask,present);want={'ids':[i for i in range(max(0,min(32,layerCount)))if mask&(1<<i)]if present else[],'untouchedTail':True}
   if got!=want:mismatches+=1;errors.append({'kind':'layers','expected':want,'native':got})
   cases.append({'kind':'layers','count':layerCount,'mask':mask,'present':present,'native':got});counts['layers']+=1
authoredBind=0;sourceLocals={};layerCounts={}
for idx,row in enumerate(rigs):
 src=row.get('source')
 if not src or 'path'not in src:continue
 path=src['path'];metadata=json.loads((B/'exports/animation'/(path+'.json')).read_text());raw=(B/'extracted'/path).read_bytes();assert hashlib.sha256(raw).hexdigest()==src['sha256'];n=len(row['joints']);at=metadata['offsets']['bind'];local=[list(struct.unpack_from('<16f',raw,at+64*i))for i in range(n)];sourceLocals[idx]=local;layerCounts[idx]=len(metadata['renderLayers'])
 check(packet(0,-1,-1,-1),[],idx,local,1,1);authoredBind+=1
pairs=0
for row in base['cases']:
 if row['kind']!='evaluate':continue
 idx=row['rig'];local=sourceLocals[idx];a=row['sourceClip'];b=row['targetClip'];af=f.value(row['sourceFrame']);bf=f.value(row['targetFrame']);mask=0xffffffff
 for mode,slots in [(1,[a,b]),(1,[a,None]),(1,[None,b]),(0,[a,b])]:check(packet(mode,0,1,1,frame=bf,af=af,bf=bf,progress=f.value(row['weight']),duration=1.),slots,idx,local,layerCounts[idx],mask)
 pairs+=1
 if pairs%100==0:print(pairs,'authored dispatch pairs',mismatches,'mismatches',flush=True)
out=B/'reports/animation-packet-pose-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':o.n.sha256,'d3dx':o.dll,'clips':clips,'rigs':rigs,'cases':cases},separators=(',',':')).encode(),mtime=0))
report={'binarySha256':o.n.sha256,'d3dx':o.dll,'comparisons':len(cases),'counts':dict(counts),'mismatches':mismatches,'examples':errors,'authoredBindHierarchies':authoredBind,'authoredDispatchClipPairs':pairs,'fixture':{'path':out.relative_to(B).as_posix(),'bytes':out.stat().st_size,'sha256':hashlib.sha256(out.read_bytes()).hexdigest()},'elapsedSeconds':time.time()-started};(B/'reports/animation-packet-pose-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k!='examples'},indent=2));assert not mismatches
