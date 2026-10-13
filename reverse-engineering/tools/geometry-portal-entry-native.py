"""Unmodified portal entry through room selection, real child volumes and outputs."""
import importlib.util,json,struct,hashlib,math,gzip
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
def module(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=module('nx','native-x86.py');model=module('entry_model','geometry-portal-runtime-model.py');n=nx.NativeX86();f32=model.f32
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
base=n.DATA;scene=base;display=base+0x1000;rooms=base+0x2000;portals=base+0x4000;boxes=base+0x40000;flagsMemory=base+0x69000;overrideMemory=base+0x6b000;staleHeader=base+0x6c000;pointMemory=base+0x6d000;outMask=base+0x6e000;arena=base+0x80000
uv=json.loads((R/'geometry-uv-programs.json').read_text());sineBytes=(B/uv['sineTable']['file']).read_bytes();sine=list(struct.unpack('<32768f',sineBytes));n.write(0x29899a0,sineBytes);scale=n.unpack('<d',0x755d18)[0]
counts={'entries':0,'success':0,'noRoom':0,'disabled':0,'absentPortals':0,'absentRooms':0,'absentBounds':0,'volumeScalars':0,'roomOutputConsumers':0};errors=[];excluded=[];fixtures=[];sources=[];zeroSigns=0;callCounts={};calls=[];traversalEntries=[];digest=hashlib.sha256()
addresses=[0x600bd0,0x600c60,0x600cb0,0x5d92b0,0x5d9a00,0x5ee250,0x5ee940,0x5ee710,0x5d9140,0x5da2d0,0x5da330]
def hook(mu,address,size,_):
 callCounts[hex(address)]=callCounts.get(hex(address),0)+1;calls.append(address)
 if address==0x5ee940:
  v=n.unpack('<6I',mu.reg_read(UC_X86_REG_ESP));traversalEntries.append([(v[3]&65535)-(65536 if v[3]&32768 else 0),(v[4]&65535)-(65536 if v[4]&32768 else 0),v[5]])
 if address==0x5d9140 and n.unpack('<I',scene+0xdc)[0]>=16:raise RuntimeError('Refuse native17th header write')
for address in addresses:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def compare(actual,expected,context):
 digest.update(str((actual,expected)).encode())
 if actual!=expected and len(errors)<30:errors.append({'context':context,'native':actual,'expected':expected})
def scalars(actual,expected,context):
 global zeroSigns
 if len(actual)!=len(expected):raise ValueError('Unequal scalar counts')
 for i,(a,e)in enumerate(zip(actual,expected)):
  counts['volumeScalars']+=1
  if a==e==0 and struct.pack('<f',a)!=struct.pack('<f',e):zeroSigns+=1
  compare(a,e,[context,i])
def load_scene(data,render):
 n.write(scene,b'\0'*0x8000);pd=data['portalData'];n.pack('<4I',scene+0x6c,len(pd['portals']),portals,len(pd['rooms']),rooms);n.pack('<I',scene+0x110,display);n.pack('<I',scene+0xfc,boxes);n.pack('<2I',scene+0xf0,len(data['bounds']),len(data['bounds']));n.pack('<I',display+0x48,flagsMemory);n.pack('<I',display+0x74,0x4000);n.pack('<I',display+0x88,overrideMemory);cursor=base+0x8000
 for ri,r in enumerate(pd['rooms']):
  address=rooms+24*ri;n.pack('<I',address,cursor);n.pack('<h',address+12,len(r['instanceIndices']))
  for i in r['instanceIndices']:n.pack('<h',cursor,i);cursor+=2
  cursor=(cursor+3)&~3;n.pack('<I',address+4,cursor);n.write(address+14,bytes([len(r['planeEquations']),len(r['portalIndices'])]));n.pack('<I',address+16,r['flags']);n.write(address+20,bytes([r['priority']]))
  for p in r['planeEquations']:n.pack('<4f',cursor,*p);cursor+=16
  n.pack('<I',address+8,cursor)
  for i in r['portalIndices']:n.pack('<h',cursor,i);cursor+=2
  cursor=(cursor+3)&~3
 for pi,p in enumerate(pd['portals']):
  a=portals+32*pi;n.pack('<4fIhhh',a,*p['plane'],cursor,len(p['vertices']),p['frontRoom'],p['backRoom']);n.pack('<I',a+28,p['activeFlags'])
  for v in p['vertices']:n.pack('<3f',cursor,*v);cursor+=12
 if cursor>=boxes:raise ValueError('Authored lists exceed arena')
 for i,b in enumerate(data['bounds']):n.pack('<8f',boxes+32*i,*b['center'],0.,*b['extent'],0.)
 flags=[v['flags']for v in render['instances']];overrides=bytearray(625)
 for v in render['instances']:
  if v['portalVisibilityOverride']:overrides[v['index']>>3]|=1<<(v['index']&7)
 return flags,overrides
def aim_matrix(position,target):
 z=[target[k]-position[k]for k in range(3)];length=math.sqrt(sum(v*v for v in z));z=[v/length for v in z]if length>1e-8 else[0.,0.,1.]
 x=[z[2],0.,-z[0]];length=math.sqrt(sum(v*v for v in x));x=[v/length for v in x]if length>1e-8 else[1.,0.,0.]
 y=[z[1]*x[2]-z[2]*x[1],z[2]*x[0]-z[0]*x[2],z[0]*x[1]-z[1]*x[0]];return list(map(f32,x+[0.]+y+[0.]+z+[0.]+position+[1.]))
def projection_for(matrix,fov,aspect):
 import numpy as np
 i=model.angle_index(fov,scale);t=model.quotient(sine[(i>>1)&32767],sine[((i+0x4000)>>1)&32767]);p=np.array([aspect/t,0,0,0,0,1/t,0,0,0,0,1,1,0,0,0,0],dtype=float).reshape(4,4)
 return [f32(v)for v in (np.linalg.inv(np.array(matrix).reshape(4,4))@p).ravel()]
def read_volume(ptr):
 count,room=n.unpack('<hh',ptr+156);pp=n.unpack('<I',ptr+128)[0];return {'planes':[list(n.unpack('<4f',pp+16*i))for i in range(count)],'packed':list(n.unpack('<32f',ptr)),'min':list(n.unpack('<3f',ptr+132)),'max':list(n.unpack('<3f',ptr+144)),'room':room,'planePointer':pp,'planeBytes':n.read(pp,count*16).hex()}
def flat_volume(v):return [x for p in v['planes']for x in p]+v['packed']+v['min']+v['max']
def near_plane(matrix,near):
 normal=matrix[8:11];position=matrix[12:15];shifted=[model.x87.store(model.x87.add(model.x87.wide(position[k]),model.x87.mul(model.x87.wide(normal[k]),model.x87.wide(near))))for k in range(3)]
 return normal+[-model.dot(normal+[0.],shifted)]
selection=json.loads((R/'geometry-room-selection-fixtures.json').read_text())['authored'];index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};oldCopy=list(map(float,range(16)));oldPosition=[91.,92.,93.];oldEye=[-1.,2.,-3.,4.];oldNear=[5.,-6.,7.,-8.];staleVolume={'planes':[],'packed':[0.]*32,'min':[0.]*3,'max':[0.]*3,'room':-7}
for source in selection:
 row=index[source['source']];data=json.loads((B/row['report']).read_text());pd=data['portalData'];render=json.loads((B/'exports/geometry/scene-runtime'/(row['source']+'.json')).read_text())['renderState'];sourceFlags,sourceOverrides=load_scene(data,render);picks={}
 for p,r in zip(source['points'],source['nativeResults']):picks.setdefault(r,p)
 jobs=[(r,p,mode,override,0)for r,p in sorted(picks.items())for mode in [0,1]for override in [False,True]]
 for r in [-1,next((r for r in sorted(picks)if r>=0),-1)]:
  if r in picks:jobs.extend((r,picks[r],0,override,gate)for override in [False,True]for gate in [1,2,3,4])
 selectedRoots=set()
 for result,point,mode,override,gate in jobs:
  position=[f32(point[k]+[7.,-3.,11.][k])for k in range(3)]if override else list(point)
  target=[position[0],position[1],position[2]+1]
  if result>=0 and pd['rooms'][result]['portalIndices']:
   portal=pd['portals'][pd['rooms'][result]['portalIndices'][0]];target=[sum(v[k]for v in portal['vertices'])/len(portal['vertices'])for k in range(3)]
  matrix=aim_matrix(position,target);fov=f32(1. if mode==0 else 2.4);aspect=f32(.75);near=f32(.1 if mode==0 else 2.);projection=projection_for(matrix,fov,aspect);eye=matrix[8:11]+[-model.dot(matrix[8:11]+[0.],matrix[12:15])];nearPlane=near_plane(matrix,near);eligible=gate==0;success=eligible and result>=0;flags=sourceFlags if mode==0 else[1]*len(sourceFlags);overrides=sourceOverrides if mode==0 else bytes(625);active=[p['activeFlags']if mode==0 else p['activeFlags']|1 for p in pd['portals']];depth=len(pd['portals']);meta={'source':row['source'],'root':result,'point':point,'mode':mode,'override':override,'gate':gate}
  if success:
   initial=model.rectangle_volume([-1.]*3,[1.]*3,-2,matrix,fov,aspect,sine,scale,eye)
   try:expected=model.traverse(data,result,initial,matrix,fov,aspect,sine,scale,projection,eye,depth,flags,overrides,bytes(625),[r['flags']&~4 for r in pd['rooms']],active)
   except ValueError as e:excluded.append({**meta,'reason':str(e)});continue
  n.pack('<I',scene+0x6c,0 if gate==2 else len(pd['portals']));n.pack('<I',scene+0x74,0 if gate==3 else len(pd['rooms']));n.pack('<I',scene+0xf4,0 if gate==4 else len(data['bounds']));n.pack('<i',scene+0xe4,depth);n.pack('<I',scene+0xdc,1);n.pack('<i',scene+0xe0,0x12345678);n.write(scene+0x9c,b'\0'*64);n.pack('<I',scene+0x9c,staleHeader);n.write(staleHeader,b'\0'*160);n.pack('<h',staleHeader+158,-7);n.pack('<I',scene+0x13c,0)
  n.write(arena,b'\xcd'*0x60000);n.pack('<I',0x96d9c0,arena);n.pack('<I',0x966388,arena+0x60000);n.pack('<I',0x963e00,0);n.pack('<I',0x963f98,0);n.pack('<I',0x80ba58,0 if gate==1 else 1);n.pack('<i',0x80ba5c,-1);n.pack('<I',0x97398c,0);n.pack('<I',0x973990,pointMemory if override else 0);n.pack('<3f',pointMemory,*point);n.pack('<16f',0x9736e8,*matrix);n.pack('<3f',0x973728,fov,aspect,near);n.pack('<16f',0x80b888,*projection);n.pack('<16f',0x95fb78,*oldCopy);n.pack('<3f',0x971894,*oldPosition);n.pack('<4f',0x963f78,*oldEye);n.pack('<4f',0x971860,*oldNear);n.pack('<I',0x96e564,0);n.pack('<h',0x971abc,0x7777);n.pack('<16h',0x963f54,*([-1]*16));n.write(0x280a2f0,bytes([0xa5])*625);n.write(flagsMemory,bytes(flags));n.write(overrideMemory,overrides)
  for ri,r in enumerate(pd['rooms']):n.pack('<I',rooms+ri*24+16,r['flags']|4)
  for pi,value in enumerate(active):n.pack('<I',portals+pi*32+28,value)
  calls.clear();traversalEntries.clear();returned=n.call(0x5eeb30,[scene],count=6000000);count=n.unpack('<I',scene+0xdc)[0];volumes=[read_volume(p)for p in n.unpack('<'+'I'*count,scene+0x9c)];bits=n.read(0x280a2f0,625);entryCalls=list(calls)
  actual={'returned':returned,'selectedGlobal':n.unpack('<h',0x971abc)[0],'selectedHeader':n.unpack('<i',scene+0xe0)[0],'attached':n.unpack('<I',scene+0x13c)[0]==0x280a2f0,'cameraBound':n.unpack('<I',0x96e564)[0]==0x9736e8,'cameraCopy':list(n.unpack('<16f',0x95fb78)),'cachedPosition':list(n.unpack('<3f',0x971894)),'eyePlane':list(n.unpack('<4f',0x963f78)),'nearPlane':list(n.unpack('<4f',0x971860)),'bitsSHA256':hashlib.sha256(bits).hexdigest(),'roomFlags':[n.unpack('<I',rooms+ri*24+16)[0]for ri in range(len(pd['rooms']))],'entries':list(traversalEntries),'path':list(n.unpack('<16h',0x963f54)),'volumeRooms':[v['room']for v in volumes]}
  expectedBits=bytes(expected['bits'])if success else bytes(625)if eligible else bytes([255 if gate==1 else 0xa5])*625
  want={'returned':int(success),'selectedGlobal':result if eligible else 0x7777,'selectedHeader':result if eligible else 0x12345678,'attached':True,'cameraBound':eligible,'cameraCopy':matrix if eligible else oldCopy,'cachedPosition':matrix[12:15]if eligible else oldPosition,'eyePlane':eye if success else oldEye,'nearPlane':nearPlane if success else oldNear,'bitsSHA256':hashlib.sha256(expectedBits).hexdigest(),'roomFlags':expected['roomFlags']if success else[r['flags']|4 for r in pd['rooms']],'entries':expected['entries']if success else[],'path':expected['path']if success else[-1]*16,'volumeRooms':[v['room']for v in expected['volumes']]if success else[]if eligible else[-7]}
  compare(actual,want,meta);expectedVolumes=expected['volumes']if success else[]if eligible else[staleVolume]
  for vi,(a,e)in enumerate(zip(volumes,expectedVolumes)):scalars(flat_volume(a),flat_volume(e),[meta,'volume',vi])
  aliases=[next(j for j in range(i+1)if volumes[j]['planePointer']==v['planePointer'])for i,v in enumerate(volumes)]
  expectedAliases=[next(j for j in range(i+1)if expectedVolumes[j]['planes']is v['planes'])for i,v in enumerate(expectedVolumes)];compare(aliases,expectedAliases,[meta,'aliases'])
  if success:
   selectedRoots.add(result);queries=[n.call(0x5da2d0,[scene,ri])for ri in range(-2,len(pd['rooms'])+1)];n.write(outMask,bytes([0xa5])*(len(pd['rooms'])+16));n.call(0x5da330,[scene,outMask]);mask=bytearray(len(pd['rooms']));mask[result]=1
   for v in volumes:
    if v['room']>=0:mask[v['room']]=1
   compare(queries,[int(ri in actual['volumeRooms'])for ri in range(-2,len(pd['rooms'])+1)],[meta,'queries']);compare(n.read(outMask,len(mask)+16).hex(),(bytes(mask)+bytes([0xa5])*16).hex(),[meta,'mask']);actual['roomQueries']=queries;actual['roomMask']=n.read(outMask,len(mask)).hex();counts['roomOutputConsumers']+=len(queries)+1
  else:actual['roomQueries']=None;actual['roomMask']=None
  if not success:compare(entryCalls,[0x600bd0]+([0x600c60]if gate==1 else[0x600cb0,0x5d92b0]if eligible else[]),[meta,'gateCalls'])
  elif entryCalls[-1]!=0x5ee710:raise ValueError('Expected unmodified disabled debug-sphere branch')
  counts['entries']+=1;counts['success'if success else'noRoom'if eligible else['','disabled','absentPortals','absentRooms','absentBounds'][gate]]+=1
  fixtures.append({**meta,'world':matrix,'projection':projection,'fov':fov,'aspect':aspect,'near':near,'depthLimit':depth,'native':actual,'nativeVolumes':volumes,'nativeAliases':aliases})
 sources.append({'source':row['source'],'sha256':row['sha256'],'rooms':len(pd['rooms']),'portals':len(pd['portals']),'selectedRoots':sorted(selectedRoots),'roomSelectorsWithoutSample':[i for i in range(len(pd['rooms']))if i not in picks]});print('entry sources',len(sources),'cases',counts['entries'],'errors',len(errors),'excluded',len(excluded),flush=True)
 if errors:break
report={'schema':'original-complete-portal-entry-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'errors':errors,'signedZeroDifferences':zeroSigns,'excludedUnsafeCases':excluded,'sources':sources,'sourceCounts':{'scenes':len(sources),'rooms':sum(s['rooms']for s in sources),'portals':sum(s['portals']for s in sources),'selectedRoots':sum(len(s['selectedRoots'])for s in sources)},'nativeCallCounts':callCounts,'resultSHA256':digest.hexdigest(),'fixtureFile':'geometry-portal-entry-fixtures.json.gz','sineTable':uv['sineTable'],'scope':['Original5eeb30 and every called CPU helper execute unchanged,including room selection,initial rectangle,recursive children,visibility and room-output consumers.','Hooks observe function entries and reject17th clip-header allocation; no code patches or return-value adapters.','Debug flags97398c=0 and80ba5c=-1 select original disabled debug branches.','Camera matrices,FOV,aspect,near and view/projection matrices are prepared finite inputs; this does not recover their live producer.'],'limits':['Modern display0x4000 only,matching all60 authored PORT scenes.','Original clip list limited16; unsafe cases preflight-excluded.','Selection fixtures cover400 of403 room outcomes; all403 room definitions and326 portals loaded. Three rooms are not selected by these prepared points.','Projection inverse-cache side effect is original during replay but omitted portable.','Numeric equality and state/byte contracts verified against Python; signed-zero bits may differ. Compiled C# execution remains pending.']}
(R/'geometry-portal-entry-native-validation.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(R/report['fixtureFile'],'wt',encoding='utf8')as f:json.dump({'cases':fixtures},f,separators=(',',':'))
print(json.dumps({k:report[k]for k in ['passed','counts','sourceCounts','errors','signedZeroDifferences']},indent=2))
if errors:raise SystemExit(1)
