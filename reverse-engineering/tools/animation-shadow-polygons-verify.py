"""Original complete polygon shadow writer and scalar transform helpers."""
from pathlib import Path
import ast,importlib.util,struct,json,gzip,base64,hashlib,random,math,collections
B=Path(__file__).resolve().parent.parent;R=B/'reports'
sp=importlib.util.spec_from_file_location('shadow_polygon_math',B/'tools/animation-skeletal-fixture.py');f=importlib.util.module_from_spec(sp);sp.loader.exec_module(f);n=f.p.nx.NativeX86();D=n.DATA;MATRIX=D;DIRECTION=D+0x100;NORMALS=D+0x1000;VERTICES=D+0x10000;STARTS=D+0x20000;COUNTS=D+0x21000;OUTPUT=D+0x30000;OUTPUT_SIZE=0xc0000;SIZE=0x100000;cases=[];shapes=[];counts=collections.Counter();rng=random.Random(0x5e4280)
wide={'f':f,'math':math};path=B/'tools/animation-character-bounds-verify.py'
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.ClassDef)and node.name=='W'or isinstance(node,ast.FunctionDef)and node.name=='store':exec(compile(ast.Module(body=[node],type_ignores=[]),'polygon-wide','exec'),wide)
W=wide['W'];S=wide['store'];bits=f.bits;value=f.value
def sha(b):return hashlib.sha256(b).hexdigest()
def raw(v):return struct.pack('<'+'f'*len(v),*v)
def words(v):return [bits(x)for x in v]
def put(b,p,v):b[p-D:p-D+len(v)]=v
def u32(b,p,v):struct.pack_into('<I',b,p-D,v&0xffffffff)
def transform(v,m,direction):
 out=[S(W(v[0])*W(m[i])+W(v[1])*W(m[4+i])+W(v[2])*W(m[8+i])+(W(0)if direction else W(v[3])*W(m[12+i])))for i in range(3 if direction else 4)]
 if direction:
  # No additional+0 operation in the native direction helper (zero sign).
  out=[S(W(v[0])*W(m[i])+W(v[1])*W(m[4+i])+W(v[2])*W(m[8+i]))for i in range(3)]+[v[3]]
 return out
def model(before,shape,matrix,direction,vertexCount,groupCount,generated):
 b=bytearray(before);first=0;accepted=0
 for normal,edgeCount in zip(shape['normals'][:shape['polygonCount']],shape['edges'][:shape['polygonCount']]):
  unordered=any(math.isnan(v)for v in normal)
  if not unordered:normal=transform(normal+[1.],matrix,True);dot=W(normal[0])*W(direction[0])+W(normal[1])*W(direction[1])+W(normal[2])*W(direction[2])
  if unordered or dot.w[0]<=0:
   accepted+=1
   if groupCount<250:u32(b,STARTS+groupCount*4,vertexCount);u32(b,COUNTS+groupCount*4,edgeCount);groupCount+=1
   for j in range(edgeCount):
    generated=(generated+6)&0xffffffff;a=transform(shape['vertices'][first+j]+[1.],matrix,False);v=transform(shape['vertices'][first+(j+1)%edgeCount]+[1.],matrix,False);ea=[S(W(a[k])+W(direction[k]))for k in range(3)];ev=[S(W(v[k])+W(direction[k]))for k in range(3)]
    for out in [a,ea,ev,v]:put(b,OUTPUT+vertexCount*16,raw(out[:3])+b'\xff'*4);vertexCount+=1
  first+=edgeCount
 return b,dict(vertexCount=vertexCount,groupCount=groupCount,generated=generated,accepted=accepted)
calls=[]
from unicorn import UC_HOOK_CODE
for a in [0x5c03e0,0x5c0490]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:calls.append(a),begin=a,end=a)
def check(shapeIndex,index,mode):
 shape=shapes[shapeIndex];matrix=shape.get('matrix',f.IDENTITY).copy();direction=[[0.,-4.,0.],[1.,-3.,2.],[0.,0.,0.],[-3.,1.,5.]][mode%4]
 if mode==1:matrix=[f.f32(rng.uniform(-2,2))for _ in range(16)]
 if mode==3:matrix=[-0. if(i+index)%2 else 0. for i in range(16)]
 vertexCount=[0,5,31][index%3];groupCount=[0,249,250,251,0xffffffff][index%5];generated=[0,0xfffffffc,0x80000000][index%3]
 b=bytearray(b'\xa5'*SIZE);put(b,MATRIX,raw(matrix));put(b,DIRECTION,raw(direction));assert len(shape['normals'])*16<0xf000 and len(shape['vertices'])*16<0x10000
 for i,(normal,edgeCount)in enumerate(zip(shape['normals'],shape['edges'])):put(b,NORMALS+i*16,raw(normal)+struct.pack('<i',edgeCount))
 for i,v in enumerate(shape['vertices']):put(b,VERTICES+i*16,raw(v)+struct.pack('<i',shape['polygonCount']if i==0 else 0))
 if not shape['vertices']:u32(b,VERTICES+12,shape['polygonCount'])
 want,output=model(b,shape,matrix,direction,vertexCount,groupCount,generated);n.write(D,b)
 for address,v in [(0x973fec,vertexCount),(0x973ff0,groupCount),(0x971878,generated),(0x963f88,STARTS),(0x96e568,COUNTS),(0x963f94,OUTPUT)]:n.pack('<I',address,v)
 calls.clear();n.call(0x5e4280,[MATRIX,NORMALS,VERTICES,DIRECTION],count=20000000);got=n.read(D,SIZE);actual=dict(vertexCount=n.unpack('<I',0x973fec)[0],groupCount=n.unpack('<I',0x973ff0)[0],generated=n.unpack('<I',0x971878)[0])
 if got!=want or actual!={k:v for k,v in output.items()if k!='accepted'}:raise AssertionError(dict(shape=shapeIndex,mode=mode,actual=actual,expected=output,offsets=[i for i,(a,b)in enumerate(zip(got,want))if a!=b][:30]))
 assert calls.count(0x5c0490)==max(shape['polygonCount'],0)and calls.count(0x5c03e0)==(actual['vertexCount']-vertexCount)//2
 cases.append(dict(kind='polygon',shape=shapeIndex,mode=mode,matrix=words(matrix),direction=words(direction),initial=dict(vertexCount=vertexCount,groupCount=groupCount,generated=generated),native=dict(actual,sha256=sha(got),pointCalls=calls.count(0x5c03e0),normalCalls=calls.count(0x5c0490))));counts['polygon']+=1;counts['vertices']+=actual['vertexCount']-vertexCount;counts['acceptedFaces']+=output['accepted'];counts['normalTransforms']+=calls.count(0x5c0490);counts['pointTransforms']+=calls.count(0x5c03e0)
for i in range(512):
 v=[f.f32(rng.uniform(-20,20))for _ in range(4)];matrix=[f.f32(rng.uniform(-20,20))for _ in range(16)]
 if i<64:v=[value([0,0x80000000,1,0x80000001][(i>>j*2)&3])for j in range(4)];matrix=[value([0,0x80000000,1,0x80000001][(i+j)%4])for j in range(16)]
 for direction in [False,True]:
  for alias in [False,True]:
   b=bytearray(b'\xa5'*512);put(b,MATRIX,raw(matrix));put(b,DIRECTION,raw(v));out=DIRECTION if alias else D+0x120;expected=bytearray(b);want=transform(v,matrix,direction);put(expected,out,raw(want));n.write(D,b);n.call(0x5c0490 if direction else 0x5c03e0,[out,DIRECTION,MATRIX]);got=n.read(D,512)
   assert got==expected,(i,direction,alias,list(n.unpack('<4I',out)),words(want));cases.append(dict(kind='direction'if direction else'point',vector=words(v),matrix=words(matrix),alias=alias,native=words(want)));counts['direction'if direction else'point']+=1
bindings=json.loads((R/'animation-shadow-queue-bindings.json').read_text());rigs=json.loads(gzip.decompress((R/'animation-shadow-queue-native-fixtures.json.gz').read_bytes()))['rigs'];rigByPath={r['source']['path']:r for r in rigs if'path'in r['source']};authoredRigs=set();groupCount=0
for entry in bindings['entries']:
 groups=[r for r in entry['records']if r['serialized'][5]and r['resolvedPointers'][2]]
 if not groups:continue
 rawSource=(B/'extracted'/entry['path']).read_bytes();assert sha(rawSource)==entry['sha256'];U=lambda p:struct.unpack_from('<I',rawSource,p)[0]
 def rel(p):
  offset=struct.unpack_from('<i',rawSource,p)[0];return p+offset if offset else 0
 nu=U(0)+4;pn=rel(nu+24);relocations={rel(pn+4+i*4)for i in range(U(pn))}
 for row in groups:
  p=row['resolvedPointers'][2];assert p in relocations and p+4 in relocations;normalPtr,vertexPtr=rel(p),rel(p+4);polygonCount=struct.unpack_from('<i',rawSource,vertexPtr+12)[0];assert 0<=polygonCount<=1000;normalRows=[];edges=[]
  for i in range(polygonCount):
   normal=list(struct.unpack_from('<3f',rawSource,normalPtr+i*16));edgeCount=struct.unpack_from('<i',rawSource,normalPtr+i*16+12)[0];assert 0<=edgeCount<=1000;normalRows.append(normal);edges.append(edgeCount)
  vertices=[list(struct.unpack_from('<3f',rawSource,vertexPtr+i*16))for i in range(sum(edges))];assert all(math.isfinite(x)for v in vertices for x in v)
  assert all(math.isfinite(x)or math.isnan(x)and bits(x)&0x400000 for v in normalRows for x in v)
  counts['authoredQuietNaNFaces']+=sum(any(math.isnan(x)for x in v)for v in normalRows)
  source=dict(path=entry['path'],sha256=entry['sha256'],bindingOffset=row['sourceOffset'],pairOffset=p,normalOffset=normalPtr,vertexOffset=vertexPtr,normalSha256=sha(rawSource[normalPtr:normalPtr+polygonCount*16]),vertexSha256=sha(rawSource[vertexPtr:vertexPtr+sum(edges)*16]))
  shape=dict(source=source,polygonCount=polygonCount,normals=normalRows,edges=edges,vertices=vertices,matrix=[value(v)for v in rigByPath[entry['path']]['joints'][row['serialized'][6]]]);si=len(shapes);shapes.append(shape);authoredRigs.add(entry['path']);groupCount+=1
  for mode in [0,1,2]:check(si,len(cases),mode)
 if len(authoredRigs)%25==0:print('authored rigs',len(authoredRigs),'groups',groupCount,'cases',len(cases),flush=True)
for i in range(128):
 pc=[0,-1,1,2,5][i%5];edgeCounts=[(i+j)%9 for j in range(max(pc,0))];shape=dict(source=dict(synthetic=i),polygonCount=pc,normals=[[f.f32(rng.uniform(-1,1))for _ in range(3)]for j in edgeCounts],edges=edgeCounts,vertices=[[f.f32(rng.uniform(-50,50))for _ in range(3)]for j in range(sum(edgeCounts))]);si=len(shapes);shapes.append(shape)
 for mode in range(4):check(si,len(cases),mode)
for i in range(24):
 normal=[1.,-2.,3.];normal[i%3]=value([0x7fc00000,0xffc00000,0x7fc00001,0xffc12345][i%4]);shape=dict(source=dict(quietNaNNormal=i),polygonCount=1,normals=[normal],edges=[3],vertices=[[0.,0.,0.],[1.,0.,0.],[0.,1.,0.]]);si=len(shapes);shapes.append(shape)
 for mode in range(4):check(si,len(cases),mode)
payload=[dict(s,normals=[words(v)for v in s['normals']],vertices=[words(v)for v in s['vertices']],matrix=words(s.get('matrix',f.IDENTITY)))for s in shapes]
fixture=R/'animation-shadow-polygons-native-fixtures.json.gz';fixture.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,shapes=payload,cases=cases),separators=(',',':')).encode(),mtime=0))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
assembly=[]
for a,z in [(0x5c03e0,0xa3),(0x5c0490,0x69),(0x5e4280,0x377)]:
 data=n.read(a,z);assembly.append(dict(address=hex(a),size=z,sha256=sha(data),instructions=[dict(address=hex(v.address),mnemonic=v.mnemonic,operands=v.op_str)for v in Cs(CS_ARCH_X86,CS_MODE_32).disasm(data,a)]))
(R/'animation-shadow-polygons-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,windows=assembly),indent=2)+'\n')
dependencies=['tools/animation-skeletal-fixture.py','tools/animation-x87.py','tools/animation-character-bounds-verify.py','reports/animation-shadow-queue-bindings.json','reports/animation-shadow-queue-native-fixtures.json.gz']
report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),authoredGroups=groupCount,authoredRigs=len(authoredRigs),mismatches=0,fixture=dict(path=str(fixture.relative_to(B)),bytes=fixture.stat().st_size,sha256=sha(fixture.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Original full5e4280 and its scalar5c03e0/5c0490 callees execute without callback replacement. Compare entire1MiB persistent fixture, vertex/group/generated counters and exact transform-call counts. Direct helpers include original in-place source/output probes and all output bits.',limits=['Finite vertices/matrices/direction and finite stored results. Face normals may additionally contain quietNaNs, which pass the native unordered comparison; four authored such faces and96 synthetic quietNaN probes are retained. Direct transform helpers remain finite-only. No arbitrary overlapping source/matrix/output memory.','Resolved nonnegative edge counts, backed polygon and vertex arrays, sufficient output capacity. Output group table saturates at250; vertex output continues.','Authored pair fields are verified PNTR relocations with bounded source payload hashes. This recovers CPU side quads; no cap generation, GPU draw or exact Unity rasterization claim.','Managed replay is prepared/compiled only; no generated managed executable launched.'])
(R/'animation-shadow-polygons-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
