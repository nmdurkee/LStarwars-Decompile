"""Original-PC bit-exact pose oracles; no managed execution or instruction replacement."""
from pathlib import Path
import importlib.util,struct,random,json,hashlib,gzip,base64,sys,time
s=importlib.util.spec_from_file_location('f',Path(__file__).with_name('scene-animation-pose-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
B=f.B;o=f.Oracle();rng=random.Random(0x5ea390);clips=[];cases=[];errors=[];mismatches=0;groups={};start=time.time()
def check(kind,inputs,expected,actual):
 global mismatches
 groups[kind]=groups.get(kind,0)+1;cases.append({'kind':kind,'input':inputs,'native':actual})
 if expected!=actual:
  mismatches+=1
  if len(errors)<20:errors.append({'kind':kind,'input':inputs,'expected':expected,'actual':actual})
def carrier(types,flags,seed):
 rand=random.Random(seed);constants=64;typesAt=constants+18;scaleAt=(typesAt+27+3)&~3;dynamic=[t for t in types if t<16];keys=scaleAt+8*len(dynamic);stride=sum(4 if t==6 else 8 for t in dynamic);flagAt=keys+6*stride;raw=bytearray(flagAt+20)
 struct.pack_into('<I6H',raw,0,0x414e4934,1,16,stride,16,9,0);struct.pack_into('<ff6I',raw,28,f.f32(rand.uniform(-10,0)),f.f32(rand.uniform(0,.01)),scaleAt if dynamic else 0,constants,typesAt,keys,flagAt,0)
 for i in range(9):struct.pack_into('<H',raw,constants+2*i,rand.randrange(65536));struct.pack_into('<H',raw,typesAt+2*i,types[i]);raw[typesAt+18+i]=rand.randrange(2)
 for i in range(len(dynamic)):struct.pack_into('<ff',raw,scaleAt+8*i,f.f32(rand.uniform(-.01,.01)),f.f32(rand.uniform(-10,10)))
 raw[keys:flagAt]=rand.randbytes(flagAt-keys);raw[flagAt]=flags;return bytes(raw)
def exercise(raw,frames,source):
 c=f.Clip(raw);ci=len(clips);clips.append({'raw':base64.b64encode(raw).decode(),'sha256':hashlib.sha256(raw).hexdigest(),'source':source});o.load(raw)
 for frame in frames:
  frame=f.f32(frame);v=c.sample(frame);check('scalar',{'clip':ci,'frame':f.bits(frame)},[f.bits(x)for x in v],o.sample(frame))
  poseframe=f.f32(frame+1);scalars=c.sample(f.f32(poseframe-1));check('pose',{'clip':ci,'frame':f.bits(poseframe)},[f.bits(x)for x in f.pose(scalars,c.flag)],o.pose(poseframe))
for i in range(200):
 types=[rng.choice([6,7,16+j])for j in range(9)];raw=carrier(types,i&15,i)
 exercise(raw,[-1,0,.25,1.75,2.5,3.3,7.999,15,18],{'synthetic':i})
# Rotation helper gets full integer-angle coverage rather than relying solely on authored clips.
for i in range(2000):
 angles=[rng.randrange(-(1<<31),1<<31)for _ in range(3)];o.n.pack('<3i',o.out,*angles);o.n.call(0x5b5300,[o.matrix,o.out]);check('rotation',{'angles':angles},[f.bits(v)for v in f.rotation(angles)],list(o.n.unpack('<16I',o.matrix)))
for i in range(160):
 matrix=[f.f32(rng.uniform(-1e4,1e4))for _ in range(16)];vector=[f.f32(rng.uniform(-1e4,1e4))for _ in range(3)]
 if i<16:
  matrix=[-0. if i&1 else 0.]*16;vector=[-0. if i&2 else 0.]*3
 for kind,address in [('scale',0x5b4c30),('translate',0x5b4900)]:
  expected=matrix.copy()
  if kind=='scale':
   for r in range(3):
    for c in range(3):expected[r*4+c]=(f.W(matrix[r*4+c])*f.W(vector[r])).store()
  else:
   for j in range(3):expected[12+j]=(f.W(matrix[12+j])+f.W(vector[j])).store()
  o.n.pack('<16f',o.matrix,*matrix);o.n.pack('<3f',o.out,*vector);o.n.call(address,[o.matrix,o.out]);check(kind,{'matrix':[f.bits(v)for v in matrix],'vector':[f.bits(v)for v in vector]},[f.bits(v)for v in expected],list(o.n.unpack('<16I',o.matrix)))
for angle in [0,1,-1,16383,16384,16385,32767,32768,32769,49151,49152,49153,65535,-65536]:
 for axis in range(3):
  angles=[0,0,0];angles[axis]=angle;o.n.pack('<3i',o.out,*angles);o.n.call(0x5b5300,[o.matrix,o.out]);check('rotation',{'angles':angles},[f.bits(v)for v in f.rotation(angles)],list(o.n.unpack('<16I',o.matrix)))
for i in range(240):
 ci=i%200;raw=base64.b64decode(clips[ci]['raw']);clip=f.Clip(raw);o.load(raw)
 frame=f.f32(rng.uniform(1,16));previous=frame if i%3==0 else 0.;base=[f.f32(rng.uniform(-1e3,1e3))for _ in range(3)];cached=[f.f32(rng.uniform(-1,1))for _ in range(16)];target=[f.f32(rng.uniform(-1,1))for _ in range(16)];kind=1 if i&1 else 2;present=i%5!=0;hasClip=i%7!=0
 for tick in (False,True):
  if tick and not present:continue
  changed=(tick or present)and hasClip and frame!=previous
  wantCache=f.pose(clip.sample(f.f32(frame-1)),clip.flag)if changed else cached
  wantTarget=[*wantCache]if hasClip and(tick or changed)else target
  if hasClip and(tick or changed):
   for j in range(3):wantTarget[12+j]=(f.W(wantTarget[12+j])+f.W(base[j])).store()
  want={'target':[f.bits(v)for v in wantTarget],'cache':[f.bits(v)for v in wantCache],'previous':f.bits(frame if changed else previous),'bounds':[],'otherTargetBytesPreserved':True}
  if changed and not tick:want['bounds']=[{'target':want['target'],'cache':want['cache']}]
  inputs={'clip':ci,'frame':f.bits(frame),'previous':f.bits(previous),'base':[f.bits(v)for v in base],'cached':[f.bits(v)for v in cached],'target':[f.bits(v)for v in target],'kind':kind,'present':present,'hasClip':hasClip}
  check('applyWork'if tick else'changedFrame',inputs,want,o.application(frame,previous,base,cached,target,kind,present,hasClip,tick))
limit=12 if '--quick'in sys.argv else None;processed=0
inventory=json.loads((B/'reports/animation-scene-export.json').read_text())['success']
for row in inventory:
 scene=json.loads((B/'exports/animation-scenes'/(row['path']+'.json')).read_text());raw=(B/'extracted'/row['path']).read_bytes()
 for a in scene['animations']:
  if a is None:continue
  h=a['header'];size=h['flagsOffset']+h['nodeCount']+max(16,2*h['keyStride']+8);payload=raw[a['sourceOffset']:a['sourceOffset']+size]
  frames=[float(h['firstFrame']),f.f32(h['firstFrame']+(h['frameCount']-1)*.371),float(h['firstFrame']+h['frameCount']-1)]
  exercise(payload,frames,{'path':row['path'],'animationIndex':a['index'],'offset':a['sourceOffset'],'carrierSha256':scene['sourceSha256']});processed+=1
  if limit and processed>=limit:break
 if limit and processed>=limit:break
 if processed and processed%500<100:print(processed,'authored',len(cases),'comparisons',mismatches,'mismatches',flush=True)
out=B/'reports/scene-animation-pose-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':o.n.sha256,'clips':clips,'cases':cases},separators=(',',':')).encode(),mtime=0))
report={'binarySha256':o.n.sha256,'comparisons':len(cases),'groups':groups,'mismatches':mismatches,'examples':errors,'authoredClips':processed,'syntheticClips':200,'fixture':{'path':out.relative_to(B).as_posix(),'sha256':hashlib.sha256(out.read_bytes()).hexdigest(),'bytes':out.stat().st_size},'elapsedSeconds':time.time()-start}
(B/'reports/scene-animation-pose-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not mismatches
