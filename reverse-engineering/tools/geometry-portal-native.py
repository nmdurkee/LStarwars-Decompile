"""Run original portal-facing/convex-clip predicate on every authored portal."""
import importlib.util,json,struct,hashlib,math
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx)
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX
n=nx.NativeX86();f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
ws=importlib.util.spec_from_file_location('x87',P/'animation-x87.py');x87=importlib.util.module_from_spec(ws);ws.loader.exec_module(x87)
def dot(plane,point):return x87.dot3_plus_constant(*point,*plane)
def classify(vertices,portalPlane,front,back,current,currentPriority,targetPriority,camera,clipPlanes):
 if currentPriority<targetPriority:
  d=dot(portalPlane,camera)
  if (back==current and d<0) or (front==current and d>0):return 0
 anyOutside=False
 for p in clipPlanes:
  outside=sum(dot(p,v)<0 for v in vertices)
  if outside==len(vertices):return 0
  if outside:anyOutside=True
 return 2 if anyOutside else 1

base=n.DATA;scene=base;rooms=base+0x1000;portal=base+0x10000;vertices=base+0x11000;context=base+0x20000;planes=base+0x21000
n.pack('<I',scene+0x78,rooms);n.pack('<I',context+0x80,planes)
fr=json.loads((B/'reports/geometry-clipping-native-validation.json').read_text());index=json.loads((B/'reports/geometry-scene-data-index.json').read_text())['rows']
worldSets=[]
for fixture in fr['planeFixtures']:
 v=struct.unpack('<84f',bytes.fromhex(fixture['blockHex']));outer=v[:16];nf=v[32:48]
 ps=[[outer[c],outer[4+c],outer[8+c],outer[12+c]]for c in range(4)]+[[nf[c],nf[4+c],nf[8+c],nf[12+c]]for c in range(2)]
 worldSets.append({'camera':fixture['camera']['matrix'][12:15],'planes':ps,'kind':'prepared-native-frustum'})
errors=[];counts={0:0,1:0,2:0};tests=0;portals=0;sources=[];digest=hashlib.sha256();cases=[]
def check(vertices0,plane,front,back,current,currentPriority,targetPriority,camera,ps,label):
 global tests
 target=back if current==front else front
 n.write(rooms+current*24+20,bytes([currentPriority]));n.write(rooms+target*24+20,bytes([targetPriority]));n.pack('<3f',0x971894,*camera)
 n.pack('<h',context+0x9c,len(ps))
 for i,p in enumerate(ps):n.pack('<4f',planes+i*16,*p)
 actual=n.call(0x5d9ce0,[portal,context,target],regs={UC_X86_REG_EAX:scene,UC_X86_REG_EDX:current})&255
 expected=classify(vertices0,plane,front,back,current,currentPriority,targetPriority,camera,ps)
 tests+=1;counts[actual]=counts.get(actual,0)+1;digest.update(struct.pack('<ii',actual,expected))
 if actual!=expected and len(errors)<50:errors.append({'context':label,'native':actual,'expected':expected})
 return actual
for row in index:
 if not row['portals']:continue
 data=json.loads((B/row['report']).read_text());pd=data['portalData'];sources.append({'source':row['source'],'sha256':row['sha256'],'portals':len(pd['portals'])})
 for pi,p in enumerate(pd['portals']):
  vv=p['vertices'];front=p['frontRoom'];back=p['backRoom'];pp=p['plane']
  if not (0<=front<len(pd['rooms']) and 0<=back<len(pd['rooms'])):raise ValueError('Portal room reference outside authored array')
  if len(vv)>300 or any(not math.isfinite(x)for v in vv for x in v):raise ValueError('Unbounded/nonfinite portal')
  n.write(portal,b'\0'*32);n.pack('<4f',portal,*pp);n.pack('<I3h',portal+16,vertices,len(vv),front,back)
  for vi,v in enumerate(vv):n.pack('<3f',vertices+vi*12,*v)
  center=[f32(sum(v[k]for v in vv)/len(vv))for k in range(3)]
  localSets=[{'kind':'zero-planes','camera':center,'planes':[]},{'kind':'all-outside','camera':center,'planes':[[0,0,0,-1]]},{'kind':'tangent','camera':center,'planes':[[0,0,0,0]]}]
  for axis in range(3):
   plane=[0.,0.,0.,-center[axis]];plane[axis]=1.;localSets.append({'kind':'axis-bisector','camera':center,'planes':[plane]})
  results=[]
  for current,target in sorted(set([(front,back),(back,front)])):
   priorities=[(pd['rooms'][current]['priority'],pd['rooms'][target]['priority'])]
   for pair in [(0,1),(1,0),(1,1)]:
    if pair not in priorities and (current!=target or pair[0]==pair[1]):priorities.append(pair)
   for cp,tp in priorities:
    for si,fixture in enumerate(worldSets+localSets):
     label={'source':row['source'],'portal':pi,'currentRoom':current,'priorities':[cp,tp],'set':si}
     result=check(vv,pp,front,back,current,cp,tp,fixture['camera'],fixture['planes'],label)
     results.append([current,cp,tp,si,result])
  cases.append({'source':row['source'],'index':pi,'address':p['address'],'plane':pp,'vertices':vv,'frontRoom':front,'backRoom':back,'localSets':localSets,'nativeResults':results});portals+=1
 print('portals',portals,'tests',tests,'errors',len(errors),flush=True)

# Counts0..9 exercise original unrolled groups and scalar tails, including
# degenerate zero-vertex behavior and exactly tangent signed-zero planes.
boundary=[]
for count in range(10):
 vv=[[f32(i-4),f32(i%3-1),0.]for i in range(count)];pp=[0.,0.,1.,0.]
 n.write(portal,b'\0'*32);n.pack('<4f',portal,*pp);n.pack('<I3h',portal+16,vertices,count,0,1)
 for vi,v in enumerate(vv):n.pack('<3f',vertices+vi*12,*v)
 for ps in [[],[[0,0,0,0]],[[0,0,0,-0.]],[[1,0,0,0]],[[0,0,1,0]],[[0,0,0,-1]],[[0,0,0,1]],[[1,0,0,4],[-1,0,0,4]]]:
  for current in [0,1]:
   for camera in [[0.,0.,-1.],[0.,0.,0.],[0.,0.,1.]]:
    for cp,tp in [(0,0),(0,1),(1,0)]:
     label={'boundaryVertexCount':count,'currentRoom':current,'camera':camera,'priorities':[cp,tp],'planes':ps}
     result=check(vv,pp,0,1,current,cp,tp,camera,ps,label);boundary.append({**label,'native':result})
report={'schema':'original-portal-clip-predicate-v1','binarySHA256':n.sha256,'nativeFunction':'0x5d9ce0','passed':not errors,'tests':tests,'authoredPortals':portals,'classificationCounts':counts,'errors':errors,'resultSHA256':digest.hexdigest(),'sources':sources,'worldClipSets':worldSets,'boundaryCases':boundary,'fixturesFile':'geometry-portal-predicate-fixtures.json','scope':['Unmodified original0x5d9ce0 executes with no callback or floating-point replacement.','All authored portal planes/vertices/room IDs used; source priorities plus explicit up/down/equal priority fixtures.','Nine prepared frustum clip sets and six local degenerate/bisector fixtures; both traversal directions.','Original vertex-plane expressions round tofloat32 before comparison; zero is accepted.'],'limits':['Does not produce clipped portal silhouettes or child clipping volumes.','Does not implement full recursive traversal, room selection or visibility-bit propagation.','Authored portal records copied into bounded fixture memory; native archive load/relocation is not rerun here.','Compiled C# equivalence remains pending.']}
report['floatingPointModel']={'nativeControlWord':'0x037f','rounding':'nearest-even,64-significand x87 intermediates then explicitfloat32 store','source':'tools/animation-x87.py','sourceSHA256':hashlib.sha256((P/'animation-x87.py').read_bytes()).hexdigest()}
report['selfLinkedPortals']=[{'source':p['source'],'index':p['index']}for p in cases if p['frontRoom']==p['backRoom']]
(B/'reports/geometry-portal-native-validation.json').write_text(json.dumps(report,indent=2,allow_nan=False)+'\n')
(B/'reports/geometry-portal-predicate-fixtures.json').write_text(json.dumps({'schema':'authored-portal-clip-fixtures-v1','portals':cases},separators=(',',':'),allow_nan=False)+'\n')
print(json.dumps({k:report[k]for k in ['passed','tests','authoredPortals','classificationCounts','errors']},indent=2))
if errors:raise SystemExit(1)
