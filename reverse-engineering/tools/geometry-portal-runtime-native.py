"""Unmodified original projection/FOV/partial-portal and recursive traversal replay."""
import importlib.util,json,struct,hashlib,math,gzip,itertools,random
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
def module(name,path):
 s=importlib.util.spec_from_file_location(name,P/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=module('nx','native-x86.py');model=module('portal_model','geometry-portal-runtime-model.py');n=nx.NativeX86();f32=model.f32
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
base=n.DATA;scene=base;display=base+0x1000;roomMemory=base+0x2000;portalMemory=base+0x4000;boxMemory=base+0x40000;flagsMemory=base+0x69000;overrideMemory=base+0x6b000;cameraMemory=base+0x6c000;parentMemory=base+0x6d000;scratch=base+0x6e000;arena=base+0x80000
uv=json.loads((R/'geometry-uv-programs.json').read_text());sineBytes=(B/uv['sineTable']['file']).read_bytes();sine=list(struct.unpack('<32768f',sineBytes));n.write(0x29899a0,sineBytes);angleScale=n.unpack('<d',0x755d18)[0]
counts={'projection':0,'rectangularVolumes':0,'partialPortals':0,'traversal':0,'childVolumeScalars':0};errors=[];zeroSigns=0;digest=hashlib.sha256();fixtures={'projection':[],'rectangles':[],'partial':[],'traversal':[]};partialClasses={0:0,1:0,4:0};recording=False;entries=[];callCounts={}
def hook(mu,address,size,_):
 if not recording:return
 callCounts[hex(address)]=callCounts.get(hex(address),0)+1
 if address==0x5ee940:
  values=n.unpack('<6I',mu.reg_read(UC_X86_REG_ESP));a,b,depth=values[3:6];entries.append([a if a<32768 else (a&65535)-65536,b if b<32768 else (b&65535)-65536,depth])
 if address==0x5d9140 and n.unpack('<I',scene+0xdc)[0]>=16:raise RuntimeError('Refuse native clip-list corruption')
for address in [0x5ee940,0x5d9ce0,0x5ee750,0x5da100,0x5d9a00,0x5d91b0,0x600be0,0x600d00,0x5d9140]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def compare(kind,actual,expected,meta):
 counts[kind]+=1;digest.update(str((actual,expected)).encode())
 if actual!=expected and len(errors)<30:errors.append({'kind':kind,'context':meta,'native':actual,'expected':expected})
def floats(actual,expected,meta):
 global zeroSigns
 for i,(a,e)in enumerate(zip(actual,expected)):
  if a==e==0 and struct.pack('<f',a)!=struct.pack('<f',e):zeroSigns+=1
  compare('childVolumeScalars',a,e,{**meta,'scalar':i})
def reset_arena():
 n.write(arena,b'\xcd'*0x60000);n.pack('<I',0x96d9c0,arena);n.pack('<I',0x966388,arena+0x60000);n.pack('<I',0x963e00,scene+0x9c);n.pack('<I',0x963f98,scene+0xdc);n.pack('<I',scene+0xdc,0);n.write(scene+0x9c,b'\0'*64)
def set_camera(matrix,fov,aspect,projection,eye):
 n.pack('<16f',cameraMemory,*matrix);n.pack('<2f',cameraMemory+64,fov,aspect);n.pack('<I',0x96e564,cameraMemory);n.pack('<16f',0x95fb78,*matrix);n.pack('<3f',0x971894,*matrix[12:15]);n.pack('<16f',0x80b888,*projection);n.pack('<4f',0x963f78,*eye);n.pack('<I',0x97398c,0)
def read_volume(ptr):
 count,room=n.unpack('<hh',ptr+0x9c);pp=n.unpack('<I',ptr+0x80)[0];planes=[list(n.unpack('<4f',pp+16*i))for i in range(count)]
 return {'planes':planes,'min':list(n.unpack('<3f',ptr+0x84)),'max':list(n.unpack('<3f',ptr+0x90)),'room':room,'packed':list(n.unpack('<32f',ptr)),'planePointer':pp,'planeBytes':n.read(pp,count*16).hex()}
def check_volume(actual,expected,meta):
 floats([v for p in actual['planes']for v in p]+actual['packed']+actual['min']+actual['max'],[v for p in expected['planes']for v in p]+expected['packed']+expected['min']+expected['max'],meta)
 if len(actual['planes'])!=len(expected['planes'])or actual['room']!=expected['room']:raise ValueError('Child volume count or room differs')
def rectangle_native(lo,hi,room):
 n.pack('<3f',scratch,*lo);n.pack('<3f',scratch+16,*hi);return n.call(0x5d9a00,[scratch,scratch+16,room],count=1000000)
index=[r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']if r['rooms']];cache={};sourceDepth={}
for row in index:
 data=json.loads((B/row['report']).read_text());cache[row['source']]=data
 with (B/'extracted'/row['source']).open('rb')as f:f.seek(data['header']+0xe4);sourceDepth[row['source']]=struct.unpack('<i',f.read(4))[0]
allPortals=[(row['source'],pi,p)for row in index for pi,p in enumerate(cache[row['source']]['portalData']['portals'])]
fr=json.loads((R/'geometry-clipping-native-validation.json').read_text());cameraMatrices=[f['camera']['matrix']for f in fr['planeFixtures']]
identity=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.]
projections=[identity,[1/1024.,0.,0.,0.,0.,1/1024.,0.,0.,0.,0.,1/1024.,0.,0.,0.,0.,1.],[.5,.1,0.,0.,-.2,.25,0.,0.,.1,0.,.1,.05,0.,0.,0.,1.],[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,1.,0.,0.,0.,0.]]
projections=[list(map(f32,m))for m in projections]
def put_portal(p,address=portalMemory,vertices=scratch+0x100):
 n.write(address,b'\0'*32);n.pack('<4fIhhh',address,*p['plane'],vertices,len(p['vertices']),p['frontRoom'],p['backRoom']);n.pack('<I',address+0x1c,p['activeFlags'])
 for i,v in enumerate(p['vertices']):n.pack('<3f',vertices+12*i,*v)
for source,pi,p in allPortals:
 put_portal(p)
 for mi,matrix in enumerate(projections):
  n.pack('<16f',0x80b888,*matrix);n.call(0x5d9f50,[portalMemory,scratch,scratch+16],count=1000000);lo,hi=model.project_bounds(p['vertices'],matrix);actual=list(n.unpack('<3f',scratch+16))+list(n.unpack('<3f',scratch));meta={'source':source,'portal':pi,'projection':mi};compare('projection',actual,lo+hi,meta);fixtures['projection'].append({**meta,'native':actual})
print('projection',counts['projection'],'errors',len(errors),flush=True)
rectangles=[([-1.,-1.,-1.],[1.,1.,1.]),([-.25,-.5,0.],[.5,.75,1.]),([0.,0.,-.5],[0.,0.,.5]),([.5,1.,0.],[-.5,-1.,0.])]
for ci,matrix in enumerate(cameraMatrices):
 eye=matrix[8:11]+[-model.dot(matrix[8:11]+[0.],matrix[12:15])]
 for fov,aspect,(lo,hi)in itertools.product([f32(.3),f32(1.),f32(1.57),f32(2.4)],[f32(.5),f32(.75),f32(4/3)],rectangles):
  reset_arena();set_camera(matrix,fov,aspect,projections[1],eye);ptr=rectangle_native(lo,hi,2);actual=read_volume(ptr);expected=model.rectangle_volume(lo,hi,2,matrix,fov,aspect,sine,angleScale,eye);meta={'camera':ci,'fov':fov,'aspect':aspect,'min':lo,'max':hi};compare('rectangularVolumes',[ptr,n.unpack('<I',scene+0xdc)[0]],[arena,1],meta);check_volume(actual,expected,meta);fixtures['rectangles'].append({**meta,'native':actual})
print('rectangular volumes',counts['rectangularVolumes'],'errors',len(errors),flush=True)
for source,pi,p in allPortals:
 put_portal(p);center=[f32(sum(v[k]for v in p['vertices'])/len(p['vertices']))for k in range(3)];matrix=list(identity);matrix[12:15]=center
 eyes=[[0.,0.,0.,1.],[0.,0.,0.,-1.],[0.,0.,0.,0.]]
 for axis in range(3):eye=[0.,0.,0.,-center[axis]];eye[axis]=1.;eyes.append(eye)
 for ei,eye in enumerate(eyes):
  for small in [False,True]:
   reset_arena();set_camera(matrix,1.,.75,projections[1],eye);lo,hi=([-1.,-1.,-1.],[1.,1.,1.])if not small else([f32(-.0001),f32(-.0001),-1.],[f32(.0001),f32(.0001),1.]);parent=model.rectangle_volume(lo,hi,-2,matrix,1.,.75,sine,angleScale,eye);parentPtr=rectangle_native(lo,hi,-2);n.pack('<I',scratch+40,0x12345678)
   actual=n.call(0x5ee750,[portalMemory,roomMemory,p['backRoom'],parentPtr,scratch+40],count=1000000);expected,child=model.partial(p,parent,p['backRoom'],matrix,1.,.75,sine,angleScale,projections[1],eye);meta={'source':source,'portal':pi,'eye':ei,'small':small};compare('partialPortals',actual,expected,meta);partialClasses[actual]=partialClasses.get(actual,0)+1
   if actual==1:
    output=read_volume(n.unpack('<I',scratch+40)[0]);check_volume(output,child,meta)
   else:
    output=None
    if n.unpack('<I',scratch+40)[0]!=0x12345678:raise ValueError('Rejected/straddling partial helper changed output pointer')
   fixtures['partial'].append({**meta,'nativeResult':actual,'nativeVolume':output})
print('partial',counts['partialPortals'],'classes',partialClasses,'errors',len(errors),flush=True)

def load_scene(data,render):
 n.write(scene,b'\0'*0x8000);pd=data['portalData'];n.pack('<II',scene+0x6c,len(pd['portals']),portalMemory);n.pack('<II',scene+0x74,len(pd['rooms']),roomMemory);n.pack('<I',scene+0x110,display);n.pack('<I',scene+0xfc,boxMemory);n.pack('<II',scene+0xf0,len(data['bounds']),len(data['bounds']));n.pack('<I',display+0x48,flagsMemory);n.pack('<I',display+0x74,0x4000);n.pack('<I',display+0x88,overrideMemory)
 cursor=base+0x8000
 for ri,r in enumerate(pd['rooms']):
  address=roomMemory+24*ri;n.pack('<I',address,cursor);n.pack('<h',address+12,len(r['instanceIndices']))
  for i in r['instanceIndices']:n.pack('<h',cursor,i);cursor+=2
  cursor=(cursor+3)&~3;n.pack('<I',address+4,cursor);n.write(address+14,bytes([len(r['planeEquations']),len(r['portalIndices'])]));n.pack('<I',address+16,r['flags']);n.write(address+20,bytes([r['priority']]))
  for p in r['planeEquations']:n.pack('<4f',cursor,*p);cursor+=16
  n.pack('<I',address+8,cursor)
  for i in r['portalIndices']:n.pack('<h',cursor,i);cursor+=2
  cursor=(cursor+3)&~3
 for pi,p in enumerate(pd['portals']):put_portal(p,portalMemory+32*pi,cursor);cursor+=12*len(p['vertices'])
 if cursor>=boxMemory:raise ValueError('Authored lists exceed isolated fixture allocation')
 for i,b in enumerate(data['bounds']):n.pack('<4f4f',boxMemory+32*i,*b['center'],0.,*b['extent'],0.)
 originalFlags=[x['flags']for x in render['instances']];overrides=bytearray(625)
 for x in render['instances']:
  if x['portalVisibilityOverride']:overrides[x['index']>>3]|=1<<(x['index']&7)
 return originalFlags,overrides
def aim_matrix(position,target):
 z=[target[k]-position[k]for k in range(3)];length=math.sqrt(sum(v*v for v in z))
 if length<1e-8:z=[0.,0.,1.]
 else:z=[v/length for v in z]
 x=[z[2],0.,-z[0]];length=math.sqrt(sum(v*v for v in x))
 if length<1e-8:x=[1.,0.,0.]
 else:x=[v/length for v in x]
 y=[z[1]*x[2]-z[2]*x[1],z[2]*x[0]-z[0]*x[2],z[0]*x[1]-z[1]*x[0]]
 return list(map(f32,x+[0.]+y+[0.]+z+[0.]+position+[1.]))
def projection_for(matrix,fov,aspect):
 # Explicit prepared view/projection fixture, not the original camera producer.
 import numpy as np
 i=model.angle_index(fov,angleScale);t=model.quotient(sine[(i>>1)&32767],sine[((i+0x4000)>>1)&32767]);perspective=np.array([aspect/t,0,0,0,0,1/t,0,0,0,0,1,1,0,0,0,0],dtype=float).reshape(4,4)
 view=np.linalg.inv(np.array(matrix,dtype=float).reshape(4,4));return [f32(v)for v in (view@perspective).ravel()]
excluded=[];sourceCoverage=[];traversalSummary={'entries':0,'markedRooms':0,'allocatedVolumes':0,'maximumVolumes':0,'classificationResults':{},'partialResults':{}};recording=True
for row in index:
 data=cache[row['source']];pd=data['portalData'];render=json.loads((B/'exports/geometry/scene-runtime'/(row['source']+'.json')).read_text())['renderState'];sourceFlags,sourceOverrides=load_scene(data,render);covered=[]
 for root,r in enumerate(pd['rooms']):
  if r['portalIndices']:
   portal=pd['portals'][r['portalIndices'][0]];target=[sum(v[k]for v in portal['vertices'])/len(portal['vertices'])for k in range(3)]
  else:target=[0.,0.,1.]
  position=list(data['bounds'][r['instanceIndices'][0]]['center'])if r['instanceIndices']else[target[k]-[0.,0.,1.][k]for k in range(3)]
  localMatrices=[aim_matrix(position,target),aim_matrix(target,[target[k]+portal['plane'][k]for k in range(3)])if r['portalIndices']else aim_matrix(position,[position[0]+1,position[1],position[2]])]
  for ci,matrix in enumerate(localMatrices):
   eye=matrix[8:11]+[-model.dot(matrix[8:11]+[0.],matrix[12:15])]
   for mode,depth in itertools.product([0,1],sorted(set([0,1,4,15,len(pd['portals'])]))):
    fov=f32(1. if mode==0 else 2.4);aspect=f32(.75);projection=projection_for(matrix,fov,aspect);flags=sourceFlags if mode==0 else[1]*len(sourceFlags);overrides=sourceOverrides if mode==0 else bytes(625);active=[p['activeFlags']if mode==0 else p['activeFlags']|1 for p in pd['portals']];before=bytes(625);roomFlags=[r['flags']&~4 for r in pd['rooms']];initial=model.rectangle_volume([-1.]*3,[1.]*3,-2,matrix,fov,aspect,sine,angleScale,eye);meta={'source':row['source'],'root':root,'camera':ci,'mode':mode,'depthLimit':depth,'loaderDefaultDepth':depth==len(pd['portals'])}
    try:expected=model.traverse(data,root,initial,matrix,fov,aspect,sine,angleScale,projection,eye,depth,flags,overrides,before,roomFlags,active)
    except ValueError as e:excluded.append({**meta,'reason':str(e)});continue
    reset_arena();set_camera(matrix,fov,aspect,projection,eye);n.pack('<i',scene+0xe4,depth);n.pack('<h',0x971abc,root);n.pack('<16h',0x963f54,*([-1]*16));n.write(0x280a2f0,before);n.write(flagsMemory,bytes(flags));n.write(overrideMemory,overrides)
    for ri,flagsValue in enumerate(roomFlags):n.pack('<I',roomMemory+24*ri+16,flagsValue)
    for pi,activeValue in enumerate(active):n.pack('<I',portalMemory+32*pi+28,activeValue)
    first=rectangle_native([-1.]*3,[1.]*3,-2);entries.clear();n.call(0x5ee940,[scene,first,root,0xffffffff,0],count=5000000)
    count=n.unpack('<I',scene+0xdc)[0];pointers=list(n.unpack('<'+'I'*count,scene+0x9c));volumes=[read_volume(p)for p in pointers];actual={'bits':n.read(0x280a2f0,625).hex(),'roomFlags':[n.unpack('<I',roomMemory+24*ri+16)[0]for ri in range(len(pd['rooms']))],'entries':list(entries),'path':list(n.unpack('<16h',0x963f54)),'volumeRooms':[v['room']for v in volumes]};want={'bits':bytes(expected['bits']).hex(),'roomFlags':expected['roomFlags'],'entries':expected['entries'],'path':expected['path'],'volumeRooms':[v['room']for v in expected['volumes']]};compare('traversal',actual,want,meta)
    if len(volumes)!=len(expected['volumes']):raise ValueError('Traversal volume count mismatch')
    for vi,(a,e)in enumerate(zip(volumes,expected['volumes'])):check_volume(a,e,{**meta,'volume':vi})
    aliases=[next(j for j in range(i+1)if volumes[j]['planePointer']==v['planePointer'])for i,v in enumerate(volumes)];expectedAliases=[next(j for j in range(i+1)if expected['volumes'][j]['planes']is v['planes'])for i,v in enumerate(expected['volumes'])]
    if aliases!=expectedAliases:raise ValueError('Traversal shallow-copy plane alias mismatch')
    fixtures['traversal'].append({**meta,'cameraMatrix':matrix,'projection':projection,'nativeBitsSHA256':hashlib.sha256(n.read(0x280a2f0,625)).hexdigest(),'nativeRoomFlags':actual['roomFlags'],'nativeEntries':actual['entries'],'nativePath':actual['path'],'nativeVolumeRooms':actual['volumeRooms'],'nativePlaneAliases':aliases,'nativeVolumes':volumes});covered.append(root)
    traversalSummary['entries']+=len(entries);traversalSummary['markedRooms']+=len(expected['visits']);traversalSummary['allocatedVolumes']+=count;traversalSummary['maximumVolumes']=max(traversalSummary['maximumVolumes'],count)
    for result in expected['classifications']:key=str(result[-1]);traversalSummary['classificationResults'][key]=traversalSummary['classificationResults'].get(key,0)+1
    for result in expected['partialResults']:key=str(result[-1]);traversalSummary['partialResults'][key]=traversalSummary['partialResults'].get(key,0)+1
  if errors:break
 sourceCoverage.append({'source':row['source'],'sha256':row['sha256'],'rooms':len(pd['rooms']),'portals':len(pd['portals']),'coveredRoots':sorted(set(covered)),'serializedDepthLimit':sourceDepth[row['source']]})
 print('traversal sources',len(sourceCoverage),'cases',counts['traversal'],'excluded',len(excluded),'errors',len(errors),flush=True)
 if errors:break
recording=False

report={'schema':'original-recursive-portal-runtime-v1','binarySHA256':n.sha256,'passed':not errors,'counts':counts,'errors':errors,'signedZeroDifferences':zeroSigns,'resultSHA256':digest.hexdigest(),'partialResults':partialClasses,'nativeCallCounts':callCounts,'angleScale':angleScale,'sineTable':uv['sineTable'],'cameraMatrices':cameraMatrices,'projectionFixtures':projections,'sourceDepth':sourceDepth,'limits':['Prepared camera/projection data is explicit fixture input, not live camera-system equivalence.','Original projection computes an inverse cache as a side effect; that cache has not been ported.','Exact finite numerical equality only; shared rational arithmetic can collapse signed-zero bits.','No managed execution or GPU results claimed.'],'fixtureFile':'geometry-portal-runtime-fixtures.json.gz'}
report['traversalSummary']=traversalSummary;report['traversalSources']=sourceCoverage;report['excludedUnsafeCases']=excluded;report['traversalLimits']=['Only modern display mode0x4000, as used by all authored PORT scenes.','Serialized GSNH+e4 is0,but original load finalizer602550 calls5d9130 with GSNH+6c portal count. That loader-default depth is covered alongside explicit0/1/4/15 fixtures; later overrides remain separate.','Original16-entry header pointer list enforced; model preflights unsafe volume counts and excludes those cases before native writes.','Debug rendering flag0x97398c is0; original debug functions execute their normal disabled branch.','Original recursive,geometry,volume,projection,bitset and flag instructions execute unchanged; hooks only observe calls and guard list capacity.']
(R/'geometry-portal-runtime-native-validation.json').write_text(json.dumps(report,indent=2,allow_nan=False)+'\n')
with gzip.open(R/'geometry-portal-runtime-fixtures.json.gz','wt',encoding='utf8')as f:json.dump(fixtures,f,separators=(',',':'),allow_nan=False)
print(json.dumps({k:report[k]for k in ['passed','counts','partialResults','errors']},indent=2))
if errors:raise SystemExit(1)
