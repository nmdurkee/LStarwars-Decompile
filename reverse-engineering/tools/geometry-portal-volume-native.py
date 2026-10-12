"""Original portal edge-volume construction, packing, shallow copy and rectangle overlap."""
import importlib.util,json,struct,hashlib,math,random,gzip,itertools
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
def module(name,path):
 s=importlib.util.spec_from_file_location(name,P/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=module('nx','native-x86.py');x87=module('x87','animation-x87.py');n=nx.NativeX86()
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESI,UC_X86_REG_EDI
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
dot=lambda p,q:x87.dot3_plus_constant(*q,*p)
def wide_dot(v,p):return x87.add(x87.add(x87.add(x87.mul(x87.wide(v[0]),x87.wide(p[0])),x87.mul(x87.wide(v[1]),x87.wide(p[1]))),x87.mul(x87.wide(v[2]),x87.wide(p[2]))),x87.wide(p[3]))
def edge_planes(vertices,plane,camera):
 result=[];flip=dot(plane,camera)>=0
 for i,v in enumerate(vertices):
  a=[f32(camera[k]-v[k])for k in range(3)];b=[f32(camera[k]-vertices[(i+1)%len(vertices)][k])for k in range(3)]
  cross=[dot([b[2],-b[1],0.,0.],[a[1],a[2],0.]),dot([b[0],-b[2],0.,0.],[a[2],a[0],0.]),dot([b[1],-b[0],0.,0.],[a[0],a[1],0.])]
  length=f32(math.sqrt(dot(cross+[0.],cross)));reciprocal=f32(1./length)if length>0 else 0.;normal=[f32(x*reciprocal)for x in cross];constant=dot(normal+[0.],camera)
  result.append([-x for x in normal]+[constant]if flip else normal+[-constant])
 return result
def projected(vertices,matrix):
 points=[]
 for v in vertices:
  w=dot([matrix[3],matrix[7],matrix[11],matrix[15]],v);inv=x87.store(x87.div(x87.wide(1.),x87.wide(w)))if w!=0 else 0.
  points.append([x87.store(x87.mul(wide_dot(v,[matrix[k],matrix[4+k],matrix[8+k],matrix[12+k]]),x87.wide(inv)))for k in range(3)])
 return [[min(1.,max(-1.,fn(p[k]for p in points)))for k in range(3)]for fn in [min,max]]
def packed(planes,eye):
 p=planes[:8]+[eye]*max(0,8-len(planes));return [p[(i//16)*4+i%4][i%16//4]for i in range(32)]
base=n.DATA;portal=base;verticesMemory=base+0x1000;listMemory=base+0x3000;counter=base+0x4000;sourceContext=base+0x6000;sourcePlanes=base+0x7000;arena=base+0x80000
def reset_arena(offset=0):
 n.write(arena,b'\xcd'*0x10000);n.pack('<I',0x96d9c0,arena+offset);n.pack('<I',0x966388,arena+0x10000);n.pack('<I',0x963e00,listMemory);n.pack('<I',0x963f98,counter);n.pack('<I',counter,0);n.write(listMemory,b'\0'*0x1000)
errors=[];counts={'authoredEdgeVolumes':0,'planeScalars':0,'packedScalars':0,'projectedScalars':0,'allocation':0,'copyAlias':0,'rectangleIntersection':0,'syntheticPacking':0};digest=hashlib.sha256();zeroSignDifferences=0;zeroSignComponents={};zeroSignExamples=[];cases=[]
def compare(kind,actual,expected,meta):
 counts[kind]+=1;digest.update(str((actual,expected)).encode())
 if actual!=expected and len(errors)<30:errors.append({'kind':kind,'context':meta,'native':actual,'expected':expected})
def floats(kind,actual,expected,meta):
 global zeroSignDifferences
 for i,(a,e)in enumerate(zip(actual,expected)):
  if a==e==0 and struct.pack('<f',a)!=struct.pack('<f',e):
   zeroSignDifferences+=1;component=kind+':'+('XYZW'[i%4]if kind=='planeScalars'else str(i));zeroSignComponents[component]=zeroSignComponents.get(component,0)+1
   if len(zeroSignExamples)<10:zeroSignExamples.append({**meta,'component':component,'nativeBits':struct.pack('<f',a).hex(),'pythonBits':struct.pack('<f',e).hex()})
  compare(kind,a,e,{**meta,'scalar':i})
fr=json.loads((R/'geometry-clipping-native-validation.json').read_text());cameras=[f['camera']['matrix'][12:15]for f in fr['planeFixtures']]
matrix=[1/1024.,0.,0.,0.,0.,1/1024.,0.,0.,0.,0.,1/1024.,0.,0.,0.,0.,1.];n.pack('<16f',0x80b888,*matrix)
rows=[r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']if r['portals']];sources=[]
for row in rows:
 pd=json.loads((B/row['report']).read_text())['portalData'];sources.append({'source':row['source'],'sha256':row['sha256'],'portals':len(pd['portals'])})
 for pi,p in enumerate(pd['portals']):
  vv=p['vertices'];pp=p['plane']
  if not 3<=len(vv)<=8:raise ValueError('Authored winding outside bounded packed-volume domain')
  n.write(portal,b'\0'*32);n.pack('<4fIh',portal,*pp,verticesMemory,len(vv))
  for i,v in enumerate(vv):n.pack('<3f',verticesMemory+12*i,*v)
  center=[f32(sum(v[k]for v in vv)/len(vv))for k in range(3)]
  localCameras=cameras+[center,vv[0]]
  for ci,camera in enumerate(localCameras):
   eye=[0.,0.,1.,f32(-camera[2])];reset_arena();n.pack('<3f',0x95fba8,*camera);n.pack('<4f',0x963f78,*eye)
   result=n.call(0x5da100,[p['backRoom']],regs={UC_X86_REG_ESI:portal},count=1000000);planePointer=n.unpack('<I',result+0x80)[0];actual=list(n.unpack('<'+'f'*(4*len(vv)),planePointer));expected=[c for plane in edge_planes(vv,pp,camera)for c in plane];meta={'source':row['source'],'portal':pi,'camera':ci}
   compare('authoredEdgeVolumes',(result,n.unpack('<h',result+0x9c)[0],n.unpack('<h',result+0x9e)[0],n.unpack('<I',counter)[0]),(arena,len(vv),p['backRoom'],1),meta)
   floats('planeScalars',actual,expected,meta);floats('packedScalars',n.unpack('<32f',result),packed([actual[i:i+4]for i in range(0,len(actual),4)],eye),meta)
   lo,hi=projected(vv,matrix);floats('projectedScalars',n.unpack('<6f',result+0x84),lo+hi,meta)
   cases.append({**meta,'nativePlanes':actual,'nativePlaneBytes':n.read(planePointer,16*len(vv)).hex(),'nativePacked':list(n.unpack('<32f',result)),'nativePackedBytes':n.read(result,128).hex(),'nativeProjectedMinMax':list(n.unpack('<6f',result+0x84))})
 print('sources',len(sources),'volumes',counts['authoredEdgeVolumes'],'errors',len(errors),flush=True)

rng=random.Random(0x5d9140)
for count in range(3,16):
 for repetition in range(16):
  planes=[[f32(rng.uniform(-50,50))for _ in range(4)]for i in range(count)];eye=[f32(rng.uniform(-50,50))for _ in range(4)];n.write(sourceContext,b'\xcd'*160);n.pack('<I',sourceContext+0x80,sourcePlanes);n.pack('<h',sourceContext+0x9c,count)
  for i,p in enumerate(planes):n.pack('<4f',sourcePlanes+16*i,*p)
  n.pack('<4f',0x963f78,*eye);before=n.read(sourceContext+128,32);n.call(0x5d9850,regs={UC_X86_REG_EAX:sourceContext})
  compare('syntheticPacking',[list(n.unpack('<32f',sourceContext)),n.read(sourceContext+128,32).hex()],[packed(planes,eye),before.hex()],{'planes':count,'repetition':repetition})
for count,offset in itertools.product(range(16),range(16)):
 reset_arena(offset);result=n.call(0x5d9140,regs={UC_X86_REG_EAX:count});planes=((arena+offset+15)&~15)+160
 compare('allocation',[result,n.unpack('<I',result+0x80)[0],n.unpack('<h',result+0x9c)[0],n.unpack('<I',0x96d9c0)[0],n.unpack('<I',counter)[0],n.unpack('<I',listMemory)[0]],[arena+offset,planes,count,planes+16*count,1,arena+offset],{'count':count,'alignmentOffset':offset})
 reset_arena(offset);header=bytearray(rng.randbytes(160));struct.pack_into('<I',header,0x80,sourcePlanes);struct.pack_into('<h',header,0x9c,count);n.write(sourceContext,header);planeBytes=rng.randbytes(16*count);n.write(sourcePlanes,planeBytes)
 result=n.call(0x5d91b0,[sourceContext]);actual=[n.read(result,160).hex(),n.read(sourcePlanes,16*count).hex(),n.read(planes,16*count).hex(),n.unpack('<I',0x96d9c0)[0]]
 compare('copyAlias',actual,[header.hex(),planeBytes.hex(),(b'\xcd'*(16*count)).hex(),planes+16*count],{'count':count,'alignmentOffset':offset})

# Direct rectangle helper ABI:ECX=minA,EDI=maxA,EDX=minB,ESI=maxB.
# Outputs are stack arguments(min,max); native only writes XY, preserving Z.
for case in range(2000):
 if case<625:
  a0,a1,b0,b1=list(itertools.product([-1.,-0.,0.,1.,2.],repeat=4))[case];loA=[a0,a0];hiA=[a1,a1];loB=[b0,b0];hiB=[b1,b1]
 else:
  values=[f32(rng.uniform(-2,2))for _ in range(8)];loA=values[:2];hiA=values[2:4];loB=values[4:6];hiB=values[6:]
 pointers=[base+0x100+i*16 for i in range(6)]
 for ptr,value in zip(pointers,[loA,hiA,loB,hiB,[123.,456.],[789.,987.]]):n.pack('<3f',ptr,*value,321.)
 actual=n.call(0x5da040,pointers[4:],regs={UC_X86_REG_ECX:pointers[0],UC_X86_REG_EDI:pointers[1],UC_X86_REG_EDX:pointers[2],UC_X86_REG_ESI:pointers[3]})
 expected=int(loA[0]<hiB[0]and loA[1]<hiB[1]and loB[0]<hiA[0]and loB[1]<hiA[1]);out=list(n.unpack('<3f',pointers[4]))+list(n.unpack('<3f',pointers[5]));want=([max(loA[i],loB[i])for i in range(2)]+[321.]+[min(hiA[i],hiB[i])for i in range(2)]+[321.])if expected else [123.,456.,321.,789.,987.,321.]
 compare('rectangleIntersection',[actual,out],[expected,want],{'case':case,'minA':loA,'maxA':hiA,'minB':loB,'maxB':hiB})
report={'schema':'original-portal-child-volume-v1','binarySHA256':n.sha256,'passed':not errors,'counts':counts,'errors':errors,'zeroSignDifferences':zeroSignDifferences,'resultSHA256':digest.hexdigest(),'sources':sources,'nativeFunctions':['0x5da100','0x5d9140','0x5d91b0','0x5d9850','0x5d9f50','0x5da040'],'cameras':cameras,'projectionMatrix':matrix,'fixturesFile':'geometry-portal-volume-fixtures.json.gz','scope':['All original child construction/allocator/math/projection/packing instructions execute unchanged with no return adapters.','Authored vertices/planes plus9 authored camera positions,portal centroid and first-vertex degenerate camera.','Exact numerical equality compared; IEEE signed-zero bit differences counted separately.','Allocator and shallow-copy cases include all16 byte alignments and plane counts0..15.','Rectangle cases include strict-touch boundaries,reversed bounds and signed zero.'],'limits':['Prepared diagonal projection fixture is not the recovered live camera producer.','Edge-volume source reconstruction excludes screen-projection owner/inversion cache unless explicitly mapped separately.','Allocator overflow and list capacity violations excluded.','No complete recursive traversal or GPU comparison; compiled managed equivalence pending.']}
report['signedZeroDetails']={'comparison':'original x86 versus Python integer-x87 arithmetic model; C# execution unknown','components':zeroSignComponents,'examples':zeroSignExamples,'preservation':'Original plane and packed-matrix byte hex retained per fixture; native JSON floating values also preserve signed zero.','limit':'Numeric equality only: exact IEEE sign bits at zero are not reproduced by the finite rational helper, which collapses zero sign.'}
(R/'geometry-portal-volume-native-validation.json').write_text(json.dumps(report,indent=2,allow_nan=False)+'\n')
with gzip.open(R/'geometry-portal-volume-fixtures.json.gz','wt',encoding='utf8')as f:json.dump({'sources':sources,'cameras':cameras,'projectionMatrix':matrix,'cases':cases},f,separators=(',',':'),allow_nan=False)
print(json.dumps({k:report[k]for k in ['passed','counts','zeroSignDifferences','errors']},indent=2))
if errors:raise SystemExit(1)
