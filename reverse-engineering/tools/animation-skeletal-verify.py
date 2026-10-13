"""Exact original-PC Euler scalar and hierarchy checks, compact replay fixtures."""
from pathlib import Path
import importlib.util,json,gzip,base64,random,hashlib,struct,time,collections
s=importlib.util.spec_from_file_location('f',Path(__file__).with_name('animation-skeletal-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
B=f.B;o=f.Oracle();rng=random.Random(0x5e9d90);clips=[];rigs=[];cases=[];mismatches=0;errors=[];startTime=time.time();counts=collections.Counter()
def digest(rows):
 flat=[v for row in rows for v in row];return hashlib.sha256(struct.pack('<'+'I'*len(flat),*flat)).hexdigest()
def scalar(ci,c,frame,count=None,start=0):
 global mismatches
 if count is None:count=c.nodes
 v=c.sample(frame);want={'values':[[0xa5a5a5a5]*9 for _ in range(c.nodes)],'flags':[0xa5]*c.nodes,'quaternion':0,'return':0,'paddingPreserved':True}
 for j in range(start,start+min(count,c.nodes)):want['values'][j]=[f.bits(x)for x in v[j]];want['flags'][j]=c.raw[c.flags+j]
 got=o.sample(frame,count,start)
 if got!=want:
  mismatches+=1
  if len(errors)<12:errors.append({'kind':'scalar','clip':ci,'frame':frame,'count':count,'start':start,'native':got,'expected':want})
 cases.append({'kind':'scalar','clip':ci,'frame':f.bits(frame),'count':count,'start':start,'native':{'valuesSha256':digest(got['values']),'flags':got['flags'],'quaternion':got['quaternion'],'return':got['return'],'paddingPreserved':got['paddingPreserved']}});counts['scalar']+=1
 return v
def pose(v,flags,ji,clipCount=None,source=None):
 global mismatches
 js=rigs[ji]['joints'];got=o.pose(v,flags,js,clipCount);want=f.pose(v,flags,js,clipCount)
 if got!=want:
  mismatches+=1
  if len(errors)<12:errors.append({'kind':'pose','rig':ji,'values':v,'flags':flags,'native':got,'expected':want})
 cases.append({'kind':'pose','rig':ji,'values':[[f.bits(x)for x in row]for row in v],'flags':flags,'clipCount':len(v)if clipCount is None else clipCount,'source':source,'native':{'worldSha256':digest(got['world']),'scalesSha256':digest(got['scales'])}});counts['pose']+=1
def rig(js,source=None):
 rigs.append({'joints':js,'source':source});return len(rigs)-1
def carrier(seed):
 rand=random.Random(seed);n=3;flags=[rand.randrange(256)for _ in range(n)];types=[rand.choice([6,16+i])for i in range(n*9)];dynamic=sum(t==6 and bool(flags[i//9]&[2,1,8][i%9//3])for i,t in enumerate(types));constants=64;typesAt=constants+2*n*9;scaleAt=(typesAt+3*n*9+3)&~3;keys=scaleAt+8*dynamic;stride=4*dynamic;flagAt=keys+6*stride;raw=bytearray(flagAt+n+20)
 struct.pack_into('<I6H',raw,0,0x414e4934,n,1 if seed%8==0 else 16,stride,1 if seed%8==0 else 19,9,2);raw[17]=rand.randrange(256);raw[19]=(seed&127)*2;struct.pack_into('<ff6I',raw,28,-3.,.001,scaleAt if dynamic else 0,constants,typesAt,keys,flagAt,0)
 for i,t in enumerate(types):struct.pack_into('<H',raw,typesAt+2*i,t);struct.pack_into('<H',raw,constants+2*i,rand.randrange(65536));raw[typesAt+n*18+i]=rand.randrange(256)
 for i in range(dynamic):struct.pack_into('<ff',raw,scaleAt+8*i,f.f32(rand.uniform(-.03,.03)),f.f32(rand.uniform(-10,10)))
 raw[keys:flagAt]=rand.randbytes(flagAt-keys);raw[flagAt:flagAt+n]=bytes(flags);return bytes(raw)
def evaluate(ci,c,frame,ji):
 global mismatches
 js=rigs[ji]['joints'];want=f.pose(c.sample(f.f32(frame-1)),list(c.raw[c.flags:c.flags+c.nodes]),js);want['arenaRestored']=True;got=o.evaluate(c.raw,frame,js)
 if got!=want:
  mismatches+=1
  if len(errors)<12:errors.append({'kind':'evaluate','clip':ci,'rig':ji,'frame':frame,'native':got,'expected':want})
 cases.append({'kind':'evaluate','clip':ci,'rig':ji,'frame':f.bits(frame),'native':{'worldSha256':digest(got['world']),'scalesSha256':digest(got['scales']),'arenaRestored':got['arenaRestored']}});counts['evaluate']+=1
# Every low-seven-bit combination, roots and nonroots; parent zeros and root
# scale-reset are exercised separately. Bit0x80 has no observed consumer branch.
for flag in range(256):
 js=[{'parent':255,'bind':[f.f32(rng.uniform(-2,2))for _ in range(16)]},{'parent':0,'bind':[f.f32(rng.uniform(-2,2))for _ in range(16)]}];ji=rig(js)
 for zero in [False,True]:
  v=[[f.f32(rng.uniform(-3,3))for _ in range(9)]for _ in js]
  if zero:v[0][6+(flag%3)]=0.
  pose(v,[flag,flag^0x1b],ji)
for i in range(300):
 n=rng.randrange(1,12);js=[{'parent':255 if j==0 or rng.randrange(5)==0 else rng.randrange(j),'bind':[f.f32(rng.uniform(-2,2))for _ in range(16)]}for j in range(n)];ji=rig(js)
 v=[[f.f32(rng.uniform(-4,4))for _ in range(9)]for j in js];flags=[rng.randrange(256)for j in js];pose(v,flags,ji,rng.randrange(n+1))
for negative in [False,True]:
 v=[[-0. if negative else 0.]*9 for _ in range(2)];ji=rig([{'parent':255,'bind':f.IDENTITY},{'parent':0,'bind':f.IDENTITY}])
 for flag in range(128):pose(v,[flag,flag],ji)
for seed in range(128):
 raw=carrier(seed);c=f.Clip(raw);ci=len(clips);clips.append({'raw':base64.b64encode(raw).decode(),'source':{'synthetic':seed}});o.load(raw)
 for frame in [-1.,2.,2.3,3.7,4.9,6.05,10.37,20.,25.]:scalar(ci,c,f.f32(frame))
 scalar(ci,c,f.f32(8.9),1,1)
 ji=rig([{'parent':255 if i==0 else i-1,'bind':f.IDENTITY}for i in range(seed%5+1)])
 evaluate(ci,c,f.f32(8.3),ji)
inventory=json.loads((B/'reports/animation-export.json').read_text())['success'];byDir=collections.defaultdict(list);authoredClips=0
for row in inventory:
 if not row['format'].startswith('ANI'):continue
 raw=(B/'extracted'/row['path']).read_bytes();assert hashlib.sha256(raw).hexdigest()==row['sha256'];c=f.Clip(raw);ci=len(clips);clips.append({'raw':base64.b64encode(c.raw).decode(),'source':row['path'],'sourceSha256':row['sha256']});o.load(c.raw)
 byDir[str(Path(row['path']).parent)].append((ci,c));span=c.frames-1
 for frame in [c.first-1.,c.first+span*.317,c.first+span*.731,c.first+span+1.]:scalar(ci,c,f.f32(frame))
 if ci%17==0:
  scalar(ci,c,f.f32(c.first+span*.429),0,0);scalar(ci,c,f.f32(c.first+span*.429),c.nodes+7,0)
  st=c.nodes//3;scalar(ci,c,f.f32(c.first+span*.429),c.nodes-st,st)
 authoredClips+=1
 if authoredClips%200==0:print(authoredClips,'authored clips',mismatches,'mismatches',flush=True)
authoredRigs=0;rigClipPairs=0
for row in inventory:
 if row['format']!='GHG-PC-hierarchy':continue
 decoded=json.loads((B/row['output']).read_text());sourceRaw=(B/'extracted'/row['path']).read_bytes();assert hashlib.sha256(sourceRaw).hexdigest()==row['sha256']
 # Read source floats directly: JSON source metadata cannot retain signed zero.
 js=[{'parent':sourceRaw[j['sourceOffset']+0x50],'bind':list(struct.unpack_from('<16f',sourceRaw,j['sourceOffset']))}for j in decoded['joints']];ji=rig(js,{'path':row['path'],'sha256':row['sha256']});authoredRigs+=1
 options=byDir.get(str(Path(row['path']).parent),[]);matched=[r for r in options if r[1].nodes==len(js)]
 if matched:
  ci,c=matched[len(matched)//2];frame=f.f32(c.first+(c.frames-1)*.411);v=c.sample(frame);flags=list(c.raw[c.flags:c.flags+c.nodes]);pose(v,flags,ji,source={'clip':ci,'frame':f.bits(frame)});evaluate(ci,c,f.f32(frame+1),ji);rigClipPairs+=1
 else:
  # Authored bind matrices and parents remain evidence even when no same-folder
  # clip is available. Synthetic values are explicitly identified as such.
  v=[[0.,0.,0.,0.,0.,0.,1.,1.,1.]for _ in js];pose(v,[0x33]*len(js),ji,source={'syntheticPose':True})
print('Writing compact fixtures',len(cases),mismatches,flush=True)
# Convert authored/synthetic bind matrices to bit-pattern arrays for exact replay.
for row in rigs:
 for joint in row['joints']:joint['bind']=[f.bits(x)for x in joint['bind']]
out=B/'reports/animation-skeletal-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':o.n.sha256,'d3dx':o.dll,'clips':clips,'rigs':rigs,'cases':cases},separators=(',',':')).encode(),mtime=0))
report={'binarySha256':o.n.sha256,'d3dx':o.dll,'comparisons':len(cases),'counts':dict(counts),'mismatches':mismatches,'examples':errors,'authoredClips':authoredClips,'syntheticClips':128,'authoredRigs':authoredRigs,'sameFolderEqualCountRigClipPairs':rigClipPairs,'elapsedSeconds':time.time()-startTime,'fixture':{'path':out.relative_to(B).as_posix(),'bytes':out.stat().st_size,'sha256':hashlib.sha256(out.read_bytes()).hexdigest()}}
(B/'reports/animation-skeletal-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k!='examples'},indent=2));assert not mismatches
