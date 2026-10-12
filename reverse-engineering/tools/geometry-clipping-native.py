"""Original PC frustum and portal-room predicates against authored bounds, planes and camera transforms."""
import importlib.util,json,struct,math,hashlib
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent
sp=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx)
ws=importlib.util.spec_from_file_location('x87',P/'animation-x87.py');x87=importlib.util.module_from_spec(ws);ws.loader.exec_module(x87)
import numpy as np
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
n=nx.NativeX86();f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0];bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
errors=[];outputHash=hashlib.sha256();counts={'frustum':0,'roomContains':0,'roomSelect':0};classes={0:0,1:0,2:0};restoreFailures=0;matrixCalls=0
def compare(kind,native,expected,context):
 counts[kind]+=1;outputHash.update(struct.pack('<ii',native,expected))
 if native!=expected and len(errors)<50:errors.append({'kind':kind,'native':native,'expected':expected,'context':context})

# Original plane builder invokes imported D3DXMatrixMultiply. Only that external
# API is replaced by an explicitly declared deterministic scalar matrix product.
# Predicate5d69a0 itself and room predicates execute with NO hooks/replacements.
preparing=False
def hook(mu,address,size,data):
 global matrixCalls
 if preparing and address==0x5c1240:
  stack=mu.reg_read(UC_X86_REG_ESP);ret,out,a,b=n.unpack('<4I',stack);aa=n.unpack('<16f',a);bb=n.unpack('<16f',b)
  product=[f32(sum(float(aa[i*4+k])*bb[k*4+j]for k in range(4)))for i in range(4)for j in range(4)]
  n.pack('<16f',out,*product);mu.reg_write(UC_X86_REG_EAX,out);mu.reg_write(UC_X86_REG_ESP,stack+4);mu.reg_write(UC_X86_REG_EIP,ret);matrixCalls+=1
n.mu.hook_add(UC_HOOK_CODE,hook)
def project(m,p,col,translation=True):return x87.dot3_plus_constant(*p,m[col],m[4+col],m[8+col],m[12+col]if translation else 0.)
def frustum(block,globalFar,center,extent,override):
 values=struct.unpack('<84f',block);outer=values[:16];inner=values[16:32];nf=list(values[32:48]);a=values[52:68];b=values[68:84]
 if override!=0:nf[12]=f32(override+f32(nf[12]-globalFar))
 d=[project(outer,center,j)for j in range(4)]+[project(nf,center,j)for j in range(2)]
 r=[project(a,extent,j,j<3)for j in range(4)]+[project(nf,extent,j,False)for j in [2,3]]
 if any(x < -y for x,y in zip(d,r)):return 0
 if any(d[j]<r[j]for j in range(4)):
  ds=[project(inner,center,j)for j in range(4)];rs=[project(b,extent,j)for j in range(4)]
  if any(x<y for x,y in zip(ds,rs)):return 2
 return 1

index=json.loads((B/'reports/geometry-scene-data-index.json').read_text())['rows']
selected=[]
for ep in ['EPISODE_I','EPISODE_II','EPISODE_III','EPISODE_IV','EPISODE_V','EPISODE_VI']:
 candidates=[r for r in index if ('LEVELS\\'+ep+'\\')in r['source'] and r['source'].endswith('.GSC') and r['bounds']]
 candidates.sort(key=lambda r:(-r['bounds'],r['source']));selected.append(candidates[0])
neg=next(r for r in index if r['source']=='LEVELS\\EPISODE_I\\NEGOTIATIONS\\NEGOTIATIONS_A\\NEGOTIATIONS_A_PC.GSC')
if neg not in selected:selected.append(neg)
bounds=[];sources=[]
for row in selected:
 data=json.loads((B/row['report']).read_text());allbounds=data['bounds'];chosen=allbounds if row==neg else allbounds[::max(1,math.ceil(len(allbounds)/256))]
 sources.append({'source':row['source'],'sourceSHA256':row['sha256'],'totalBounds':len(allbounds),'selectedIndices':[x['index']for x in chosen]})
 for bound in chosen:
  if any(not math.isfinite(v)for v in bound['center']+bound['extent'])or any(v<0 for v in bound['extent']):raise ValueError('Invalid authored bounds')
  bounds.append((row['source'],bound))
cameraPath='exports/cutscenes/LEVELS/EPISODE_V/ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.CU2.json';cr=json.loads((B/cameraPath).read_text());cameraFixtures=[]
for c in cr['cameras']['cameras']:
 cameraFixtures.append({'kind':'authored-CU2-transform','index':c['index'],'sourceOffset':c['sourceOffset'],'matrix':c['matrix']})
for pos in [[0,0,-10],[-30,5,0],[0,0,0]]:
 m=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,*pos,1.];cameraFixtures.append({'kind':'synthetic-camera','matrix':m})
planeFixtures=[];centerAddress=n.DATA;extentAddress=n.DATA+16;far=1000.
for ci,camera in enumerate(cameraFixtures):
 m=[f32(v)for v in camera['matrix']];view=[f32(v)for v in np.linalg.inv(np.array(m,dtype=np.float64).reshape(4,4)).ravel()]
 n.pack('<16f',0x80b708,*view);n.pack('<16f',0x9736e8,*m);n.pack('<2f',0x973730,.1,far)
 for address,value in [(0x966378,1.),(0x97313c,.75),(0x966270,.9),(0x96dce4,.65)]:n.pack('<f',address,value)
 preparing=True;n.call(0x5d5500);preparing=False;block=n.read(0x963fa0,336)
 planeFixtures.append({'camera':camera,'viewMatrixMethod':'float32-rounded NumPy inverse of authored/synthetic world transform; this inverse is fixture preparation, not native camera validation.','globalFar':far,'blockHex':block.hex(),'planeBlockSHA256':hashlib.sha256(block).hexdigest()})
 for source,bound in bounds:
  n.pack('<3f',centerAddress,*bound['center']);n.pack('<3f',extentAddress,*bound['extent'])
  for override in [0.,5.,100.,1000.]:
   result=n.call(0x5d69a0,[centerAddress,extentAddress,bits(override)]);expected=frustum(block,far,bound['center'],bound['extent'],override)
   compare('frustum',result,expected,{'camera':ci,'source':source,'bound':bound['index'],'override':override});classes[result]=classes.get(result,0)+1
   if n.read(0x963fa0,336)!=block:restoreFailures+=1
 print('frustum camera',ci,'cases',counts['frustum'],'errors',len(errors),flush=True)

# Exact tangency and near/far-only overlap fixtures use simple prepared planes.
outer=[1.,-1.,0.,0.,0.,0.,1.,-1.,0.,0.,0.,0.,1.,1.,1.,1.]
nf=[0.,0.,0.,0.,0.,0.,0.,0.,-1.,1.,1.,1.,10.,-.1,10.,.1]
absolute=[abs(v)if i<12 else 0. for i,v in enumerate(outer)]
simple=struct.pack('<84f',*(outer+outer+nf+[0.,0.,1.,-.1]+absolute+absolute));n.write(0x963fa0,simple);n.pack('<f',0x973734,10.)
boundaryFixtures=[]
for c in [[0,0,5],[1,0,5],[f32(1+2**-23),0,5],[-1,0,5],[0,1,5],[0,-1,5],[0,0,.1],[0,0,10],[0,0,11],[0,0,-1]]:
 for e in [[0,0,0],[.1,.1,.1],[1,1,1],[2,2,2]]:
  c=list(map(f32,c));e=list(map(f32,e));n.pack('<3f',centerAddress,*c);n.pack('<3f',extentAddress,*e)
  for override in [0.,1.,-1.,10.]:
   actual=n.call(0x5d69a0,[centerAddress,extentAddress,bits(override)]);expected=frustum(simple,10.,c,e,override);compare('frustum',actual,expected,{'syntheticBoundary':c,'extent':e,'override':override});boundaryFixtures.append({'center':c,'extent':e,'override':override,'native':actual});classes[actual]=classes.get(actual,0)+1

# Every authored PORT room: true original plane containment with EAX room,
# ECX point; all plane floats and source-room indices retain provenance.
def contains(planes,point):return all(x87.dot3_plus_constant(*point,*p)<=0 for p in planes)
roomAddress=n.DATA+0x1000;planeAddress=n.DATA+0x1100;pointAddress=n.DATA+0x3000;roomSources=[];roomFixtures=[];authoredRooms=0
for row in index:
 if not row['rooms']:continue
 data=json.loads((B/row['report']).read_text());pd=data['portalData'];roomSources.append({'source':row['source'],'sha256':row['sha256'],'rooms':len(pd['rooms'])})
 for ri,room in enumerate(pd['rooms']):
  planes=room['planeEquations'];points=[]
  for bi in room['instanceIndices'][::max(1,len(room['instanceIndices'])//24)][:24]:points.append(data['bounds'][bi]['center'])
  for pi in room['portalIndices']:
   if pi<0 or pi>=len(pd['portals']):continue
   portal=pd['portals'][pi]
   for point in portal['vertices']:
    points.append(point)
    for direction in [-1.,1.]:points.append([f32(point[k]+direction*.001*portal['plane'][k])for k in range(3)])
  points+=[[0.,0.,0.]]+[c['matrix'][12:15]for c in cameraFixtures[:6]]
  unique={tuple(p)for p in points};n.write(roomAddress,b'\0'*24);n.pack('<I',roomAddress+4,planeAddress);n.write(roomAddress+14,bytes([len(planes)]))
  for i,p in enumerate(planes):n.pack('<4f',planeAddress+i*16,*p)
  outputs=[]
  for p in sorted(unique):
   n.pack('<3f',pointAddress,*p);actual=n.call(0x5d9220,regs={UC_X86_REG_EAX:roomAddress,UC_X86_REG_ECX:pointAddress})&0xffff;expected=int(contains(planes,p));compare('roomContains',actual,expected,{'source':row['source'],'room':ri,'point':p});outputs.append(actual)
  roomFixtures.append({'source':row['source'],'sourceRoomIndex':ri,'sourceAddress':room['address'],'planes':planes,'points':[list(p)for p in sorted(unique)],'nativeResults':outputs});authoredRooms+=1

report={'schema':'original-frustum-portal-contracts-v1','binarySHA256':n.sha256,'passed':not errors and restoreFailures==0,'counts':counts,'classificationCounts':classes,'authoredBounds':len(bounds),'boundsSources':sources,'authoredCameraSource':{'file':cameraPath,'sourceSHA256':cr['sourceSha256'],'cameraCount':len(cr['cameras']['cameras'])},'planeFixtures':planeFixtures,'boundaryFixtures':boundaryFixtures,'authoredRooms':authoredRooms,'portalSources':roomSources,'roomFixtureFile':'geometry-clipping-room-fixtures.json','planeRestoreFailures':restoreFailures,'errors':errors,'resultSHA256':outputHash.hexdigest(),'nativeFunctions':['0x5d5500','0x5d69a0','0x5b30a0','0x5d9220'],'scope':['Frustum and room-containment predicates execute original instructions with no replacement of their math, comparisons or return values.','Plane preparation runs original5d5500 with only imported D3DXMatrixMultiply delegated to an explicit scalar reference product; nine camera transforms include six authored CU2 records.','Camera view inversion and aperture/near/far selection are fixture preparation, not original camera-system reconstruction.','All authored PORT room plane arrays are exercised with source-bound object centers, portal vertices/normal perturbations and camera positions.'],'limits':['No original D3D pixel or camera-system equivalence asserted.','Full portal traversal, multiple-room priority selection and visibility bitset propagation remain separate work.','Compiled C# execution remains pending OS denial.']}
report['floatingPointModel']={'nativeControlWord':'0x037f','rounding':'nearest-even,64-significand x87 intermediates then explicitfloat32 store','source':'tools/animation-x87.py','sourceSHA256':hashlib.sha256((P/'animation-x87.py').read_bytes()).hexdigest()}
report['planeRestoreChecks']=len(bounds)*len(cameraFixtures)*4
(B/'reports/geometry-clipping-native-validation.json').write_text(json.dumps(report,indent=2,allow_nan=False)+'\n')
(B/'reports/geometry-clipping-room-fixtures.json').write_text(json.dumps({'schema':'authored-room-containment-fixtures-v1','rooms':roomFixtures},separators=(',',':'),allow_nan=False)+'\n')
print(json.dumps({k:report[k]for k in ['passed','counts','classificationCounts','authoredBounds','authoredRooms','planeRestoreFailures','errors']},indent=2),flush=True)
if not report['passed']:raise SystemExit(1)
