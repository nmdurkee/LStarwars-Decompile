"""Compact authored traversal replay. Prepare only unless an ordinary harness is requested."""
import argparse,gzip,json,struct,hashlib,subprocess,importlib.util
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';D=B/'reconstructed/geometry/fixtures';D.mkdir(exist_ok=True)
ap=argparse.ArgumentParser();ap.add_argument('--harness',type=Path);ap.add_argument('--module');ap.add_argument('--compare',type=Path);args=ap.parse_args()
s=importlib.util.spec_from_file_location('model',B/'tools/geometry-portal-runtime-model.py');model=importlib.util.module_from_spec(s);s.loader.exec_module(model)
reportNative=json.loads((R/'geometry-portal-runtime-native-validation.json').read_text());assert reportNative['passed']
with gzip.open(R/reportNative['fixtureFile'],'rt',encoding='utf8')as f:fixtures=json.load(f)
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};sources=reportNative['traversalSources'];buffer=bytearray(b'PTRV'+struct.pack('<I',len(sources)));sourceIds={}
for si,row in enumerate(sources):
 sourceIds[row['source']]=si;entry=index[row['source']]
 if row['sha256']!=entry['sha256']:raise ValueError('Source metadata changed')
 data=json.loads((B/entry['report']).read_text());pd=data['portalData'];render=json.loads((B/'exports/geometry/scene-runtime'/(row['source']+'.json')).read_text())['renderState'];buffer.extend(struct.pack('<III',len(data['bounds']),len(pd['rooms']),len(pd['portals'])))
 for b in data['bounds']:buffer.extend(struct.pack('<6f',*b['center'],*b['extent']))
 buffer.extend(bytes(v['flags']for v in render['instances']));overrides=bytearray(625)
 for v in render['instances']:
  if v['portalVisibilityOverride']:overrides[v['index']>>3]|=1<<(v['index']&7)
 buffer.extend(overrides)
 for r in pd['rooms']:
  buffer.extend(struct.pack('<IBII',r['flags']&~4,r['priority'],len(r['instanceIndices']),len(r['portalIndices'])))
  for i in r['instanceIndices']+r['portalIndices']:buffer.extend(struct.pack('<h',i))
 for p in pd['portals']:
  buffer.extend(struct.pack('<4fhhII',*p['plane'],p['frontRoom'],p['backRoom'],p['activeFlags'],len(p['vertices'])))
  for v in p['vertices']:buffer.extend(struct.pack('<3f',*v))
frames=[];frameIds={};cases=[]
for c in fixtures['traversal']:
 world=c['cameraMatrix'];projection=c['projection'];fov=model.f32(1. if c['mode']==0 else 2.4);eye=world[8:11]+[-model.dot(world[8:11]+[0.],world[12:15])];record=struct.pack('<38f',*world,*projection,fov,.75,*eye)
 if record not in frameIds:frameIds[record]=len(frames);frames.append(record)
 cases.append((sourceIds[c['source']],c['root'],c['mode'],c['depthLimit'],frameIds[record]))
buffer.extend(struct.pack('<I',len(frames)))
for frame in frames:buffer.extend(frame)
buffer.extend(struct.pack('<I',len(cases)))
for c in cases:buffer.extend(struct.pack('<IhBiI',*c))
inputPath=D/'portal-runtime.bin';outputPath=D/'portal-runtime-output.bin';inputPath.write_bytes(buffer)
report={'schema':'portal-runtime-managed-check-v1','nativeEvidence':'geometry-portal-runtime-native-validation.json','fixtureCount':len(cases),'sourceCount':len(sources),'frameCount':len(frames),'fixtureBytes':len(buffer),'fixtureSHA256':hashlib.sha256(buffer).hexdigest(),'status':'prepared-not-executed','scope':'Authored complete traversal: visibility hashes,room flags,entry order,paths,volume IDs/aliasing and numerical plane/bounds values. Native signed-zero bits retained but not required equal.','resultClaim':'No compiled-source equivalence until ordinary output is compared.'}
try:
 if args.harness:
  sinePath=B/reportNative['sineTable']['file'];result=subprocess.run([str(args.harness.resolve())]+([args.module]if args.module else[])+[str(inputPath),str(sinePath),str(outputPath)],capture_output=True,text=True,check=True);report['stdout']=result.stdout;report['stderr']=result.stderr;args.compare=outputPath
 if args.compare:
  output=args.compare.read_bytes();offset=0;errors=[];zeroSigns=0;scalarCount=0
  def take(fmt):
   global offset
   size=struct.calcsize(fmt)
   if offset+size>len(output):raise ValueError('Truncated compiled output')
   values=struct.unpack_from(fmt,output,offset);offset+=size;return values
  if take('<4sI')!=(b'PTRO',len(cases)):raise ValueError('Incorrect output header')
  def compare(a,e,context):
   if a!=e and len(errors)<30:errors.append({'context':context,'managed':a,'native':e})
  for ci,expected in enumerate(fixtures['traversal']):
   compare(take('<32s')[0].hex(),expected['nativeBitsSHA256'],[ci,'visibilityHash']);roomCount=len(expected['nativeRoomFlags']);compare(list(take('<'+'I'*roomCount)),expected['nativeRoomFlags'],[ci,'roomFlags']);entryCount=take('<I')[0]
   if entryCount>100000:raise ValueError('Unbounded compiled entry count')
   compare([list(take('<hhi'))for _ in range(entryCount)],expected['nativeEntries'],[ci,'entries']);compare(list(take('<16h')),expected['nativePath'],[ci,'path']);volumeCount=take('<I')[0]
   if volumeCount!=len(expected['nativeVolumes']):raise ValueError('Compiled volume count mismatch atcase'+str(ci))
   for vi,native in enumerate(expected['nativeVolumes']):
    room,alias,count=take('<hiI');compare([room,alias,count],[native['room'],expected['nativePlaneAliases'][vi],len(native['planes'])],[ci,vi,'volumeHeader'])
    if count>32767:raise ValueError('Unbounded compiled plane count')
    actual=list(take('<'+'f'*(count*4+38)));want=[v for p in native['planes']for v in p]+native['packed']+native['min']+native['max']
    for i,(a,e)in enumerate(zip(actual,want)):
     scalarCount+=1
     if a==e==0 and struct.pack('<f',a)!=struct.pack('<f',e):zeroSigns+=1
     compare(a,e,[ci,vi,'scalar',i])
  if offset!=len(output):raise ValueError('Trailing compiled output')
  report.update(status='passed'if not errors else'failed',errors=errors,scalarComparisons=scalarCount,signedZeroBitDifferences=zeroSigns,outputSHA256=hashlib.sha256(output).hexdigest(),resultClaim='Ordinary compiled traversal compared to saved original-PC results.')
except Exception as e:report.update(status='execution-or-comparison-failed',error=str(e))
(R/'geometry-portal-runtime-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
if report['status']in['failed','execution-or-comparison-failed']:raise SystemExit(1)
