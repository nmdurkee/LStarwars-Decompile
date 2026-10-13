"""Independent exact Euler blends and full original two-clip wrapper."""
from pathlib import Path
import importlib.util,json,gzip,base64,hashlib,struct,random,collections,time
s=importlib.util.spec_from_file_location('f',Path(__file__).with_name('animation-skeletal-blend-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
B=f.B;o=f.Oracle();rng=random.Random(0x5cdd50);startTime=time.time();base=json.loads(gzip.decompress((B/'reports/animation-skeletal-native-fixtures.json.gz').read_bytes()));clips=base['clips'];rigs=base['rigs'];decoded=[f.p.Clip(base64.b64decode(row['raw']))for row in clips];cases=[];counts=collections.Counter();mismatches=0;errors=[]
def digest(rows):
 flat=[v for row in rows for v in row];return hashlib.sha256(struct.pack('<'+'I'*len(flat),*flat)).hexdigest()
def check_blend(ci,frame,values,flags,weight,count=None,start=0,root=True,recipe=None):
 global mismatches
 c=decoded[ci]
 if count is None:count=c.nodes
 want=f.blend(c,frame,values,flags,weight,count,start,root);got=o.blend(c.raw,frame,values,flags,weight,count,start,root)
 if want!=got:
  mismatches+=1
  if len(errors)<12:errors.append({'kind':'blend','clip':ci,'frame':frame,'weight':weight,'expected':want,'native':got})
 row={'kind':'blend','clip':ci,'frame':f.bits(frame),'weight':f.bits(weight),'count':count,'start':start,'root':root,'native':{'valuesSha256':digest(got['values']),'flags':got['flags'],'root':got['root'],'return':got['return'],'paddingPreserved':got['paddingPreserved'],'quaternion':got['quaternion']}}
 if recipe:row['initial']=recipe
 else:row['values']=[[f.bits(v)for v in a]for a in values];row['flags']=flags
 cases.append(row);counts['blend']+=1
def model_initial(ci,frame):
 c=decoded[ci];return c.sample(frame),list(c.raw[c.flags:c.flags+c.nodes])
def js(ji):return[{'parent':j['parent'],'bind':[f.value(v)for v in j['bind']]}for j in rigs[ji]['joints']]
def check_wrapper(a,af,b,bf,weight,ji,depth):
 global mismatches
 source,target=decoded[a],decoded[b];joints=js(ji);initial,flags=model_initial(a,f.f32(af-1));blended=f.blend(target,f.f32(bf-1),initial,flags,weight,len(joints));v=[[f.value(v)for v in row]for row in blended['values']]
 want=f.p.pose(v,blended['flags'],joints,source.nodes);want.update({'arenaRestored':True,'depthRestored':True,'globalRestored':True,'stackEntry':0});got=o.evaluate_blend(source.raw,af,target.raw,bf,weight,joints,depth)
 if want!=got:
  mismatches+=1
  if len(errors)<12:errors.append({'kind':'evaluate','source':a,'target':b,'rig':ji,'expected':want,'native':got})
 cases.append({'kind':'evaluate','sourceClip':a,'sourceFrame':f.bits(af),'targetClip':b,'targetFrame':f.bits(bf),'weight':f.bits(weight),'rig':ji,'depth':depth,'native':{'worldSha256':digest(got['world']),'scalesSha256':digest(got['scales']),'arenaRestored':got['arenaRestored'],'depthRestored':got['depthRestored'],'globalRestored':got['globalRestored'],'stackEntry':got['stackEntry']}});counts['evaluate']+=1
# Existing synthetic carriers vary every flag, active/inactive channel layout,
# ignored interpolation bytes and ignored headerconstantIndex.
synthetic=[i for i,r in enumerate(clips)if isinstance(r.get('source'),dict)and decoded[i].frames>1]
for i in range(700):
 ci=synthetic[i%len(synthetic)];c=decoded[ci];values=[[f.f32(rng.uniform(-1000,1000))for _ in range(9)]for _ in range(c.nodes)];flags=[rng.randrange(256)for _ in range(c.nodes)];weight=f.f32(rng.choice([0.,-0.,1.,.25,.5,.75,-2.,2.,rng.uniform(-3,3)]));frame=f.f32(rng.uniform(c.first-4,c.first+c.frames-1));start=i%c.nodes if i%7==0 else 0;count=0 if i%29==0 else c.nodes-start;check_blend(ci,frame,values,flags,weight,count,start,bool(i&1))
# Specific pi/turn boundaries and signedzero old values; each active rotation
# difference is placed immediately around the original threshold/conversion.
ci=next(i for i in synthetic if any(decoded[i].raw[decoded[i].flags+n]&1 for n in range(decoded[i].nodes)));c=decoded[ci];frame=5.;sample=c.sample(frame)
edges=[0.,-0.,f.value(f.bits(3.1415927410125732)-1),f.value(f.bits(3.1415927410125732)),f.value(f.bits(3.1415927410125732)+1),-3.1415927410125732,6.2831854820251465,-6.2831854820251465,12.566370964050293,200000.,-200000.]
for edge in edges:
 for weight in [-0.,0.,.5,1.,-1.,2.]:
  values=[[f.f32(v-edge)if 3<=i<6 else -0. for i,v in enumerate(row)]for row in sample];check_blend(ci,frame,values,[0]*c.nodes,f.f32(weight))
# Every authored carrier with a finite native denominator. Initial pose comes
# from the same carrier at another time; the replay calls the recovered sampler.
authored=0;skipped=[]
for ci,row in enumerate(clips):
 if not isinstance(row.get('source'),str):continue
 c=decoded[ci]
 if c.frames<=1:skipped.append({'path':row['source'],'sourceSha256':row['sourceSha256'],'reason':'Original blend path divides by frameCount-1; finite-domain module excludes frameCount1.'});continue
 initialFrame=f.f32(c.first+(c.frames-1)*.673);values,flags=model_initial(ci,initialFrame);recipe={'clip':ci,'frame':f.bits(initialFrame)}
 for fraction,weight in [(.213,.25),(.819,.75)]:check_blend(ci,f.f32(c.first+(c.frames-1)*fraction),values,flags,f.f32(weight),recipe=recipe)
 if authored%31==0:
  for weight in [0.,1.]:check_blend(ci,f.f32(c.first+c.frames-1),values,flags,weight,recipe=recipe)
 authored+=1
 if authored%300==0:print(authored,'authored blend clips',mismatches,'mismatches',flush=True)
# All same-folder equal-count rig/clip associations from the prior pose fixture,
# choosing a distinct target clip in that folder where one is present.
directories=collections.defaultdict(list)
for i,row in enumerate(clips):
 if isinstance(row.get('source'),str)and decoded[i].frames>1:directories[(str(Path(row['source']).parent),decoded[i].nodes)].append(i)
pairs=0
for row in base['cases']:
 if row['kind']!='pose' or not row.get('source')or 'clip'not in row['source']:continue
 a=row['source']['clip'];source=decoded[a];group=directories.get((str(Path(clips[a]['source']).parent),source.nodes))
 if not group:continue
 b=group[(group.index(a)+1)%len(group)]if a in group else group[0];target=decoded[b];af=f.f32(source.first+1+(source.frames-1)*.37);bf=f.f32(target.first+1+(target.frames-1)*.71);weight=f.f32(.413);check_wrapper(a,af,b,bf,weight,row['rig'],pairs%4);pairs+=1
out=B/'reports/animation-skeletal-blend-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':o.n.sha256,'d3dx':o.dll,'clips':clips,'rigs':rigs,'cases':cases},separators=(',',':')).encode(),mtime=0))
report={'binarySha256':o.n.sha256,'d3dx':o.dll,'comparisons':len(cases),'counts':dict(counts),'mismatches':mismatches,'examples':errors,'authoredBlendCarriers':authored,'skippedAuthoredCarriers':skipped,'sourceBoundWrapperPairs':pairs,'baseFixture':{'path':'reports/animation-skeletal-native-fixtures.json.gz','sha256':hashlib.sha256((B/'reports/animation-skeletal-native-fixtures.json.gz').read_bytes()).hexdigest()},'fixture':{'path':out.relative_to(B).as_posix(),'bytes':out.stat().st_size,'sha256':hashlib.sha256(out.read_bytes()).hexdigest()},'elapsedSeconds':time.time()-startTime};(B/'reports/animation-skeletal-blend-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k!='examples'},indent=2));assert not mismatches
