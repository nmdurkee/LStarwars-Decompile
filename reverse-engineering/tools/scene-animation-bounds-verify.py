"""Bounded original-PC bounds differential evidence, including padding audit."""
from pathlib import Path
import importlib.util,itertools,random,json,gzip,hashlib,struct,time,base64
s=importlib.util.spec_from_file_location('f',Path(__file__).with_name('scene-animation-bounds-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
B=f.B;o=f.Oracle();rng=random.Random(0x5df480);cases=[];mismatches=0;errors=[];padding=[];start=time.time()
def check(inputs,source=None):
 global mismatches
 active=not inputs.get('notify',True)or bool(inputs.get('mode',2)and inputs.get('present',True)and inputs.get('scene',True)and inputs.get('descriptor',True)and inputs.get('gate',0x10000)&0x10000)
 matrix=inputs['matrix']if inputs.get('pointer',1)==1 else inputs['fallback'];center=inputs.get('center',False)
 want={'flags':inputs.get('flags',0)|(0x400 if active and inputs.get('notify',True)else 0),'record':f.calculate(matrix,inputs['lo'],inputs['hi'],center)if active else[0xa5a5a5a5]*8,'untargetedPreserved':True}
 got,raw=o.run(**inputs);data={k:[f.bits(x)for x in v]if k in ('matrix','fallback','lo','hi')else v for k,v in inputs.items()};cases.append({'kind':'bounds','input':data,'native':got,'source':source})
 if got!=want:
  mismatches+=1
  if len(errors)<12:errors.append({'input':data,'expected':want,'native':got,'raw':raw})
 return got,raw
identity=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.]
for i in range(2000):
 matrix=[f.f32(rng.uniform(-4,4))for _ in range(16)];fallback=[f.f32(rng.uniform(-4,4))for _ in range(16)];lo=[f.f32(rng.uniform(-100,100))for _ in range(3)];hi=[f.f32(v+rng.uniform(-3,10))for v in lo]
 check({'matrix':matrix,'fallback':fallback,'lo':lo,'hi':hi,'mode':1 if i&1 else 2,'pointer':[-1,0,1][i%3],'center':bool(i&2),'flags':rng.randrange(1<<32),'notify':bool(i&4)})
for mode,present,scene,descriptor,gate in itertools.product([0,1,2],[False,True],[False,True],[False,True],[0,1,0x10000,0x20000]):
 check({'matrix':identity,'fallback':identity,'lo':[-1.,-2.,-3.],'hi':[4.,5.,6.],'mode':mode,'present':present,'scene':scene,'descriptor':descriptor,'gate':gate,'flags':0x567890ab})
for center,pad in itertools.product([False,True],[0,0x12345678,0xdeadbeef]):
 _,raw=check({'matrix':identity,'fallback':identity,'lo':[0.,0.,0.],'hi':[2.,4.,6.],'center':center,'padding':pad});padding.append({'centerFormat':center,'stackWord':hex(pad),'rawOutput':raw})
for minusMatrix,minusLo,minusHi,center in itertools.product([False,True],repeat=4):
 check({'matrix':[-0. if minusMatrix else 0.]*16,'fallback':identity,'lo':[-0. if minusLo else 0.]*3,'hi':[-0. if minusHi else 0.]*3,'center':center})
poseClips=json.loads(gzip.decompress((B/'reports/scene-animation-pose-native-fixtures.json.gz').read_bytes()))['clips'][:120]
for i,row in enumerate(poseClips):
 raw=base64.b64decode(row['raw']);clip=f.p.Clip(raw);frame=f.f32(rng.uniform(1,16));previous=frame if i%3==0 else 0.;fallback=identity.copy();fallback[12:15]=[f.f32(rng.uniform(-100,100))for _ in range(3)];lo=[-1.,-2.,-3.];hi=[2.,3.,4.];center=bool(i&1);changed=frame!=previous
 cache=f.p.pose(clip.sample(f.f32(frame-1)),clip.flag)if changed else[0.]*16;target=cache.copy()if changed else identity.copy()
 if changed:
  for j in range(3):target[12+j]=(f.W(target[12+j])+f.W(fallback[12+j])).store()
 want={'target':[f.bits(v)for v in target],'cache':[f.bits(v)for v in cache],'previous':f.bits(frame if changed else previous),'flags':0x400 if changed else 0,'record':f.calculate(target,lo,hi,center)if changed else[0xa5a5a5a5]*8}
 got=o.pose_chain(raw,frame,previous,identity,fallback,lo,hi,center);inputs={'raw':row['raw'],'frame':f.bits(frame),'previous':f.bits(previous),'matrix':[f.bits(v)for v in identity],'fallback':[f.bits(v)for v in fallback],'lo':[f.bits(v)for v in lo],'hi':[f.bits(v)for v in hi],'center':center};cases.append({'kind':'poseChain','input':inputs,'native':got})
 if got!=want:
  mismatches+=1
  if len(errors)<12:errors.append({'kind':'poseChain','input':inputs,'expected':want,'native':got})
# Source-bound local boxes and transforms from every exported animated instance.
# The gate is deliberately enabled; this tests the producer's math, not whether
# source flags are later changed by the native level initialization lifecycle.
authored=0;files=0;unbound=[];catalog={row['source'].replace('\\','/'):row for row in json.loads((B/'reports/geometry-scene-data-index.json').read_text())['rows']}
for row in json.loads((B/'reports/animation-scene-export.json').read_text())['success']:
 source=row['path'].replace('\\','/');scene=json.loads((B/'exports/animation-scenes'/(source+'.json')).read_text())
 if not scene['instances']:continue
 geometry=json.loads((B/catalog[source]['report']).read_text());specials={s['index']:s for s in geometry['specialObjects']}
 with(B/'extracted'/source).open('rb')as raw:
  raw.seek(geometry['header']+0x110);at=geometry['header']+0x110+struct.unpack('<i',raw.read(4))[0];raw.seek(at+0x74);sourceFlags=struct.unpack('<I',raw.read(4))[0]
  for instance in scene['instances']:
   special=specials.get(instance['objectIndex'])
   if special is None:unbound.append({'source':source,'instance':instance['index'],'object':instance['objectIndex']});continue
   address=special['address'];raw.seek(address+0x40);fallback=list(struct.unpack('<16f',raw.read(64)));raw.seek(address+0x80);lo=list(struct.unpack('<3f',raw.read(12)));raw.seek(address+0x90);hi=list(struct.unpack('<3f',raw.read(12)))
   check({'matrix':instance['matrix'],'fallback':fallback,'lo':lo,'hi':hi,'center':bool(sourceFlags&0x4000),'gate':sourceFlags|0x10000}, {'path':source,'sourceSha256':scene['sourceSha256'],'instance':instance['index'],'specialOffset':address});authored+=1
 files+=1
 if files%30==0:print(files,'scene files',authored,'authored instances',mismatches,'mismatches',flush=True)
report={'binarySha256':o.n.sha256,'comparisons':len(cases),'mismatches':mismatches,'examples':errors,'authoredInstances':authored,'authoredFiles':files,'poseChainCases':120,'unboundInstances':unbound,'paddingAudit':padding,'elapsedSeconds':time.time()-start}
out=B/'reports/scene-animation-bounds-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':o.n.sha256,'cases':cases},separators=(',',':')).encode(),mtime=0));report['fixture']={'path':out.relative_to(B).as_posix(),'bytes':out.stat().st_size,'sha256':hashlib.sha256(out.read_bytes()).hexdigest()}
(B/'reports/scene-animation-bounds-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not mismatches
