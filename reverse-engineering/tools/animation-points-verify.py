"""Exact PC point-of-interest transforms, optional outputs and full packet tail."""
from pathlib import Path
import importlib.util,json,gzip,base64,hashlib,struct,random,itertools,collections,time
s=importlib.util.spec_from_file_location('f',Path(__file__).with_name('animation-points-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
B=f.B;o=f.Oracle();rng=random.Random(0x5daae0);started=time.time();models=[];cases=[];counts=collections.Counter();mismatches=0;errors=[];excluded=[]
def digest(rows):
 flat=[v for row in rows for v in row];return hashlib.sha256(struct.pack('<'+'I'*len(flat),*flat)).hexdigest()
def check(kind,inputs,want,got):
 global mismatches
 if want!=got:
  mismatches+=1
  if len(errors)<12:errors.append({'kind':kind,'input':inputs,'expected':want,'native':got})
 compressed={k:digest(v)if k in('positions','matrices')else v for k,v in got.items()}if isinstance(got,dict)else got;cases.append({'kind':kind,'input':inputs,'native':compressed});counts[kind]+=1
def normal_joint_world(joints,local):return[[f.value(v)for v in row]for row in f.p.bind(joints,local)]
def exercise_model(model,source=False):
 mi=len(models);models.append(model);bindings=model['bindings'];world=model['world'];jw=model['jointWorld']
 for pointIndex,point in enumerate(bindings['points']):
  direct=dict(bindings);direct['lookup']=[pointIndex];use255=point['joint']==255;matrices=jw+[f.p.p.p.IDENTITY]*(256-len(jw))if use255 else jw
  if use255:matrices[255]=model['slot255']
  check('point',{'model':mi,'point':pointIndex,'joint255Supplied':use255},[f.bits(x)for x in f.point(direct,0,world,matrices)],o.point(direct,0,world,matrices))
 for position,matrix in itertools.product([False,True],repeat=2):check('outputs',{'model':mi,'position':position,'matrix':matrix},f.outputs(bindings,world,jw,position,matrix),o.outputs(bindings,world,jw,position,matrix))
 return mi
for seed in range(80):
 m=lambda:[f.f32(rng.uniform(-4,4))for _ in range(16)];n=20;points=[{'matrix':m(),'joint':rng.randrange(4)}for _ in range(n)];lookup=rng.sample(range(n),16);enabled=[rng.choice([0,1,0x80000000,0xffffffff])for _ in range(16)];jw=[m()for _ in range(4)];world=m()
 if seed<8:
  world=[-0. if seed&1 else 0.]*16
  for point in points:point['matrix']=[-0. if seed&2 else 0.]*16
 bindings={'points':points,'lookup':lookup,'enabled':enabled};exercise_model({'source':{'synthetic':seed},'bindings':bindings,'world':world,'jointWorld':jw,'slot255':m()})
inventory=json.loads((B/'reports/animation-export.json').read_text())['success'];byPath={};authoredPoints=0;authoredRigs=0;missingLookup=0;point255=0
for row in inventory:
 if row['format']!='GHG-PC-hierarchy':continue
 metadata=json.loads((B/row['output']).read_text());raw=(B/'extracted'/row['path']).read_bytes();assert hashlib.sha256(raw).hexdigest()==row['sha256'];h=metadata['offsets']['header'];mapCount=struct.unpack_from('<I',raw,h+0x188)[0];rel=struct.unpack_from('<i',raw,h+0x18c)[0];lookup=list(raw[h+0x18c+rel:h+0x18c+rel+mapCount])if rel else[]
 points=[{'matrix':list(struct.unpack_from('<16f',raw,p['sourceOffset'])),'joint':raw[p['sourceOffset']+68]}for p in metadata['pointsOfInterest']];joints=[{'parent':raw[j['sourceOffset']+80],'bind':list(struct.unpack_from('<16f',raw,j['sourceOffset']))}for j in metadata['joints']];local=[list(struct.unpack_from('<16f',raw,metadata['offsets']['bind']+64*i))for i in range(len(joints))];jw=normal_joint_world(joints,local);enabled=[0]*16
 for i,at in enumerate(lookup[:16]):
  if at==255:missingLookup+=1;continue
  if points[at]['joint']>=len(jw):excluded.append({'path':row['path'],'logicalIndex':i,'point':at,'joint':points[at]['joint'],'reason':'No corresponding computed hierarchy matrix; output slot deliberately disabled in packet/output fixtures.'});continue
  enabled[i]=1<<(i%32)
 world=f.p.p.p.IDENTITY.copy();world[12:15]=[f.f32(rng.uniform(-100,100))for _ in range(3)];slot255=[f.f32(rng.uniform(-4,4))for _ in range(16)]
 model={'source':{'path':row['path'],'sha256':row['sha256']},'bindings':{'points':points,'lookup':lookup,'enabled':enabled},'world':world,'jointWorld':jw,'slot255':slot255,'joints':joints,'localBind':local,'layers':len(metadata['renderLayers'])};byPath[row['path']]=exercise_model(model,True);authoredPoints+=len(points);point255+=sum(p['joint']==255 for p in points);authoredRigs+=1
base=json.loads(gzip.decompress((B/'reports/animation-packet-pose-native-fixtures.json.gz').read_bytes()));clips=base['clips'];decoded=[f.p.p.p.Clip(base64.b64decode(r['raw']))for r in clips];seen=set();chains=0
for row in base['cases']:
 if row['kind']!='dispatch'or not row['slots']:continue
 src=base['rigs'][row['rig']].get('source')
 if not src or 'path'not in src or src['path']in seen:continue
 seen.add(src['path']);mi=byPath[src['path']];model=models[mi];packet=bytes.fromhex(row['packet']);slots=row['slots'];raws=[None if i is None else decoded[i].raw for i in slots];request=f.p.select(packet,[i is not None for i in slots]);joints=model['joints'];local=model['localBind'];bindings=model['bindings'];world=model['world']
 if request['kind']=='bind':jw=normal_joint_world(joints,local)
 elif request['kind']=='single':
  c=decoded[slots[request['clip']]];out=f.p.p.p.pose(c.sample(f.f32(f.value(request['frame'])-1)),list(c.raw[c.flags:c.flags+c.nodes]),joints);jw=[[f.value(v)for v in row]for row in out['world']]
 else:
  a=decoded[slots[request['source']]];b=decoded[slots[request['target']]];out=f.p.p.blend(b,f.f32(f.value(request['targetFrame'])-1),a.sample(f.f32(f.value(request['sourceFrame'])-1)),list(a.raw[a.flags:a.flags+a.nodes]),f.value(request['weight']),len(joints));out=f.p.p.p.pose([[f.value(v)for v in row]for row in out['values']],out['flags'],joints,a.nodes);jw=[[f.value(v)for v in row]for row in out['world']]
 for position,matrix,mask in [(True,True,0xffffffff),(False,True,0xffffffff),(True,False,0xffffffff),(True,True,0)]:
  active=bool(mask and model['layers']>0);want=f.outputs(bindings,world,jw,position,matrix)if active else{'positions':[[0xa5a5a5a5]*3 for _ in range(16)],'matrices':[[0xa5a5a5a5]*16 for _ in range(16)]};got=o.chain(packet,raws,joints,local,bindings,world,model['layers'],mask,position,matrix)
  # The parent skeletal matrices are an independent additional chain assertion.
  expectedSkeleton=[[f.bits(x)for x in row]for row in jw]if active else[[0xa5a5a5a5]*16 for _ in joints];want.update({'skeletalSha256':digest(expectedSkeleton),'packetPreserved':True,'arenaRestored':True});actual={'positions':got['positions'],'matrices':got['matrices'],'skeletalSha256':digest(got['skeletalMatrices']),'packetPreserved':got['packetPreserved'],'arenaRestored':got['arenaRestored']}
  check('packet',{'model':mi,'packet':row['packet'],'slots':slots,'position':position,'matrix':matrix,'mask':mask},want,actual);chains+=1
 if len(seen)%100==0:print(len(seen),'authored packet/POI bindings',mismatches,'mismatches',flush=True)
# Preserve every float bit in managed replay, including negative zero.
for model in models:
 model['world']=[f.bits(v)for v in model['world']];model['jointWorld']=[[f.bits(v)for v in row]for row in model['jointWorld']];model['slot255']=[f.bits(v)for v in model['slot255']]
 for point in model['bindings']['points']:point['matrix']=[f.bits(v)for v in point['matrix']]
 if 'joints'in model:
  for j in model['joints']:j['bind']=[f.bits(v)for v in j['bind']]
  model['localBind']=[[f.bits(v)for v in row]for row in model['localBind']]
out=B/'reports/animation-points-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':o.n.sha256,'d3dx':o.dll,'clips':clips,'models':models,'cases':cases},separators=(',',':')).encode(),mtime=0))
report={'binarySha256':o.n.sha256,'d3dx':o.dll,'comparisons':len(cases),'counts':dict(counts),'mismatches':mismatches,'examples':errors,'authoredPoints':authoredPoints,'authoredRigs':authoredRigs,'missingLookupEntries':missingLookup,'authoredJoint255Records':point255,'excludedOutputBindings':excluded,'packetCases':chains,'fixture':{'path':out.relative_to(B).as_posix(),'bytes':out.stat().st_size,'sha256':hashlib.sha256(out.read_bytes()).hexdigest()},'elapsedSeconds':time.time()-started};(B/'reports/animation-points-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k not in('examples','excludedOutputBindings')},indent=2));assert not mismatches
