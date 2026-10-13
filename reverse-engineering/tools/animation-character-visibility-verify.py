"""Whole original character visibility into scalar dynamic bounds classifier."""
from pathlib import Path
import importlib.util,ast,json,gzip,struct,hashlib,collections,random
B=Path(__file__).resolve().parent.parent
def module(name,path):
 s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
f=module('visibility_wide',B/'tools/animation-skeletal-fixture.py');x87=module('visibility_x87',B/'tools/animation-x87.py');n=f.p.nx.NativeX86();D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
ns={'x87':x87,'IDENTITY':f.IDENTITY}
# Reuse only the pure independently checked classifier model, never its native
# runner or report-writing top-level work. The dependency hash is in the report.
tree=ast.parse((B/'tools/geometry-dynamic-bounds-native.py').read_text())
for node in tree.body:
 if isinstance(node,ast.FunctionDef)and node.name in['dot','mul','points','classify']:exec(compile(ast.Module(body=[node],type_ignores=[]),'geometry-bounds-model','exec'),ns)
calls=[];inputs=[];pointOutputs=[];errors=[];cases=[];rigs=[];counts=collections.Counter();rng=random.Random(0x5da980)
def sha(b):return hashlib.sha256(b).hexdigest()
def words(values):return[f.bits(v)for v in values]
def observe(mu,a,size,user):
 calls.append(a);sp=mu.reg_read(UC_X86_REG_ESP)
 if a==0x6042e0:
  low,high,matrix,far,mode=n.unpack('<5I',sp+4);inputs.append(dict(low=list(n.unpack('<3I',low)),high=list(n.unpack('<3I',high)),matrix=None if matrix==0 else list(n.unpack('<16I',matrix)),far=far,mode=mode))
 elif a==0x603f10:pointOutputs.append(n.unpack('<I',sp+4)[0])
for a in[0x5da980,0x5b3800,0x5b3830,0x5b37b0,0x5b4960,0x6042e0,0x5b5430,0x603f10]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def store(v,approx):
 result=v.store()
 if f.bits(result)==0 and approx==0 and struct.pack('<d',approx)[-1]&128:return -0.
 return result
def preprocess(low,high,matrix,root,center):
 if not center:return low,high,matrix
 half=[store(f.W(store(f.W(b)-f.W(a),b-a))*f.W(.5),f.f32(b-a)*.5)for a,b in zip(low,high)];low=[-v for v in half];out=matrix.copy();x,y,z=root[12:15]
 for i in range(3):
  px=f.W(matrix[i])*f.W(x);py=f.W(matrix[4+i])*f.W(y);pz=f.W(matrix[8+i])*f.W(z);value=(pz+px)+py if i==0 else(pz+py)+px;approx=(matrix[8+i]*z+matrix[i]*x)+matrix[4+i]*y if i==0 else(matrix[8+i]*z+matrix[4+i]*y)+matrix[i]*x;out[12+i]=store(value+f.W(matrix[12+i]),approx+matrix[12+i])
 return low,half,out
beforeMatrix=[f.f32(i*.25-2)for i in range(16)];beforeFar=[-3.,-2.,-1.,0.]
def run(ri,case):
 r=rigs[ri];low,high,matrix=preprocess(r['minimum'],r['maximum'],case['world'],r['root'],case['center']);near,far,override,sx,sy,enabled=case['camera'];result,combined,points,repeated=ns['classify'](low,high,matrix,case['view'],near,far,override,0.,sx,sy,enabled);trace=[0x5da980]+([0x5b3800,0x5b3830,0x5b37b0,0x5b4960]if case['center']else[])+[0x6042e0]+([0x5b5430,0x603f10]if enabled and matrix is not None else[0x603f10]if enabled else[])
 want=dict(result=result,input=dict(low=words(low),high=words(high),matrix=None if matrix is None else words(matrix),far=0,mode=0),combined=words(combined if enabled else beforeMatrix),far=words(repeated if enabled else beforeFar),corners=words(points)if enabled else None,calls=trace)
 n.pack('<3f',D+0x1ac,*r['minimum']);n.pack('<3f',D+0x1b8,*r['maximum']);n.pack('<16f',D+0x1000,*(case['world']or f.IDENTITY));n.pack('<16f',D+0x2000,*r['root']);n.write(0x9739a8,bytes([int(case['center'])]));n.pack('<16f',0x80b708,*case['view']);n.pack('<2f',0x973730,near,far);n.pack('<f',0x97374c,override);n.pack('<f',0x966378,sx);n.pack('<f',0x97313c,sy);n.pack('<I',0x80e85c,enabled);n.pack('<I',0x297c0d0,0);n.pack('<16f',0x280c480,*beforeMatrix);n.pack('<4f',0x80e8f0,*beforeFar);calls.clear();inputs.clear();pointOutputs.clear();actual=n.call(0x5da980,[D,D+0x1000 if case['world']is not None else 0,D+0x2000],count=1000000);got=dict(result=actual,input=inputs[0],combined=list(n.unpack('<16I',0x280c480)),far=list(n.unpack('<4I',0x80e8f0)),corners=list(n.unpack('<24I',pointOutputs[0]))if pointOutputs else None,calls=calls.copy());counts['authored'if 'path'in r['source']else'synthetic']+=1
 if got!=want:
  counts['mismatches']+=1
  if len(errors)<10:errors.append(dict(rig=ri,state=case,expected=want,native=got))
 cases.append(dict(rig=ri,state=case,native=got))
cameraFixture=B/'reports/geometry-dynamic-bounds-fixtures.json.gz';cameraCases=[r for r in json.loads(gzip.decompress(cameraFixture.read_bytes()))['cases']if r['kind']=='box'];views=[]
for c in cameraCases:
 if c['view']not in views:views.append(c['view'])
def scenario(i,center):
 world=f.IDENTITY.copy();world[12:15]=[[0.,0.,5.],[20.,-4.,-2.],[-1.,1.,1.]][i%3];return dict(center=center,world=world,view=views[i%len(views)],camera=[f.f32(.1),1000.,[0.,5.,100.][i%3],1.,.75,0 if i%7==0 else 1])
for i in range(160):
 low=[f.f32(rng.uniform(-5,0))for _ in range(3)];high=[f.f32(rng.uniform(0,5))for _ in range(3)];root=[f.f32(rng.uniform(-2,2))for _ in range(16)];ri=len(rigs);rigs.append(dict(source={'synthetic':i},minimum=low,maximum=high,root=root))
 for center in[False,True]:
  c=scenario(i,center)
  if i%5==0 and not center:c['world']=None
  elif center:c['world']=[f.f32(rng.uniform(-2,2))for _ in range(16)]
  run(ri,c)
# Exact signed-zero bounds arithmetic and root offsets.
for mask in range(64):
 low=[-0. if mask&(1<<i)else 0. for i in range(3)];high=[-0. if mask&(1<<(i+3))else 0. for i in range(3)];root=f.IDENTITY.copy();root[12:15]=low;ri=len(rigs);rigs.append(dict(source={'syntheticZero':mask},minimum=low,maximum=high,root=root));run(ri,dict(center=True,world=root.copy(),view=f.IDENTITY.copy(),camera=[0.,10.,0.,1.,1.,1]))
authored=0
for row in json.loads((B/'reports/animation-export.json').read_text())['success']:
 if row['format']!='GHG-PC-hierarchy':continue
 decoded=json.loads((B/row['output']).read_text());raw=(B/'extracted'/row['path']).read_bytes();assert sha(raw)==row['sha256'];h=decoded['offsets']['header'];ri=len(rigs);rigs.append(dict(source=dict(path=row['path'],sha256=row['sha256']),minimum=list(struct.unpack_from('<3f',raw,h+0x1ac)),maximum=list(struct.unpack_from('<3f',raw,h+0x1b8)),root=list(struct.unpack_from('<16f',raw,decoded['offsets']['bind']))));authored+=1
 for i in range(4):
  for center in[False,True]:run(ri,scenario(i,center))
 if authored%100==0:print(authored,'character bounds',counts['mismatches'],'mismatches',flush=True)
for r in rigs:
 for k in['minimum','maximum','root']:r[k]=words(r[k])
for c in cases:
 s=c['state'];s['world']=None if s['world']is None else words(s['world']);s['view']=words(s['view']);s['camera']=words(s['camera'][:-1])+[s['camera'][-1]]
out=B/'reports/animation-character-visibility-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,beforeMatrix=words(beforeMatrix),beforeFar=words(beforeFar),rigs=rigs,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),mismatches=counts['mismatches'],examples=errors,authoredRigs=authored,fixture=dict(path=out.relative_to(B).as_posix(),bytes=out.stat().st_size,sha256=sha(out.read_bytes())),modelDependency=dict(path='tools/geometry-dynamic-bounds-native.py',sha256=sha((B/'tools/geometry-dynamic-bounds-native.py').read_bytes())),cameraFixture=dict(path=cameraFixture.relative_to(B).as_posix(),sha256=sha(cameraFixture.read_bytes())),method='Original5da980 andentire scalar6042e0 chain execute unchanged; hooks observepreprocessedbounds/matrix,cornerbuffer andcalls only. Classification,allstoredfloatwords andscratchpreservation compared.',limits=['Finite bounds/matrices/camera andfinite storedresults; scalar297c0d0=0,unsupported6042e0 fifthargument0.','centerOnRoot input mapsglobal9739a8. Alternate branch requiresvalidobjectworld andfirstjointmatrix.','No SIMD,camera production,liveactor schedule orGPU equivalence.'])
(B/'reports/animation-character-visibility-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not counts['mismatches']
