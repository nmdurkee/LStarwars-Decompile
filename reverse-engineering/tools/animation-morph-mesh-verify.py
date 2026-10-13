"""Original603710 CPU deformation with explicit successful COM lock/unlock services."""
from pathlib import Path
import importlib.util,struct,json,base64,gzip,hashlib,random,collections,time
B=Path(__file__).resolve().parent.parent
s=importlib.util.spec_from_file_location('mesh_morph',B/'tools/animation-morph-fixture.py');f=importlib.util.module_from_spec(s);s.loader.exec_module(f);n=f.native.NativeX86();D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_EAX
M=D+0x100;WEIGHT=D+0x1000;MATRIX=D+0x2000;GPU=D+0x7000;VTABLE=D+0x8000;TARGETS=D+0x9000;CONTROL=D+0xa000;OUT=D+0xb000;BASEVERTEX=0x30000000;DELTA=0x31000000;ARENA=0x33000000
for at,size in[(BASEVERTEX,0x1000000),(DELTA,0x1000000),(ARENA,0x1000000)]:n.mu.mem_map(at,size)
LOCK=n.STOP+0x100;UNLOCK=n.STOP+0x200;events=[];current=None
def ret(mu,value,bytes):
 sp=mu.reg_read(UC_X86_REG_ESP);ip=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4+bytes);mu.reg_write(UC_X86_REG_EIP,ip)
def service(mu,a,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==LOCK:
  resource,offset,count,out,flags=n.unpack('<5I',sp+4);assert resource==GPU and offset==current['offset']and count==len(current['vertices']);events.append(['lock',offset,count,flags]);n.pack('<I',out,BASEVERTEX);ret(mu,0,20)
 else:assert n.unpack('<I',sp+4)[0]==GPU;events.append(['unlock']);ret(mu,0,4)
for a in[LOCK,UNLOCK]:n.mu.hook_add(UC_HOOK_CODE,service,begin=a,end=a)
matrices=bytes((i*17+j*3)&255 for i in range(256)for j in range(64));n.write(MATRIX,matrices);n.pack('<I',GPU,VTABLE);n.pack('<II',VTABLE+0x2c,LOCK,UNLOCK)
def sha(v):return hashlib.sha256(v).hexdigest()
def b64(v):return base64.b64encode(v).decode()
def u(raw,p):return struct.unpack_from('<I',raw,p)[0]
def vecbits(raw):return list(struct.unpack('<'+'I'*(len(raw)//4),raw))
def align(p):return(p+31)&~31
def snapshot(descriptorAddress,paletteAddress,cursor,source,descriptor,vertices,palette,ev):return{'descriptorAddress':descriptorAddress,'paletteAddress':paletteAddress,'nextCursor':cursor,'sourceDescriptor':source.hex(),'descriptor':descriptor.hex(),'verticesSha256':None if vertices is None else sha(vertices),'paletteSha256':sha(palette),'events':ev}
def model(mesh,weights,cursor):
 source=bytearray(mesh['descriptor']);raw=bytearray(source);targets=mesh['deltas'];count=u(raw,40);deform=weights is not None and count>0;vertices=None;events=[];address=M
 if deform:
  address=align(cursor);cursor=address+56;vertexAddress=align(cursor);cursor=vertexAddress+len(mesh['vertices']);struct.pack_into('<I',raw,52,vertexAddress);vertices=bytearray(mesh['vertices']);events=[['lock',mesh['offset'],len(vertices),16]];stride=struct.unpack_from('<H',raw,8)[0]
  for i in range(u(raw,24)):
   for j in range(count):
    delta=targets[j];weight=weights[j]
    if delta is None or weight==0:continue
    for k in range(3):
     at=i*stride+k*4;value=struct.unpack_from('<f',vertices,at)[0];d=struct.unpack_from('<f',delta,(i*3+k)*4)[0];v=(f.W(d)*f.W(weight)+f.W(value)).store();struct.pack_into('<f',vertices,at,v)
  events.append(['unlock'])
 else:struct.pack_into('<I',source,52,0);raw=source
 ids=[]
 for v in raw[10:18]:
  if v==255:break
  ids.append(v)
 palette=struct.pack('<I',len(ids))+b''.join(matrices[64*i:64*i+64]for i in ids);return snapshot(address,cursor,cursor+len(palette),source,raw,vertices,palette,events)
def original(mesh,weights,cursor,weightPointer=None):
 global current
 current=mesh;raw=mesh['descriptor'];n.write(M,raw);n.write(BASEVERTEX,mesh['vertices']);at=DELTA
 for j,delta in enumerate(mesh['deltas']):
  n.pack('<I',TARGETS+4*j,at if delta is not None else 0)
  if delta is not None:n.write(at,delta);at+=len(delta)+16
 assert at<DELTA+0x1000000
 if weights is not None:n.pack('<'+'f'*len(weights),WEIGHT+8,*weights)
 n.pack('<I',CONTROL,cursor);n.pack('<I',OUT,0xa5a5a5a5);events.clear();paletteAddress=n.call(0x603710,[CONTROL,MATRIX,(WEIGHT if weights is not None else 0)if weightPointer is None else weightPointer,M,OUT,0xdeadbeef],count=20000000);end=n.unpack('<I',CONTROL)[0];address=n.unpack('<I',OUT)[0];descriptor=n.read(address,56);deform=weights is not None and u(raw,40)!=0;vertices=n.read(u(descriptor,52),len(mesh['vertices']))if deform else None;palette=n.read(paletteAddress,end-paletteAddress)
 return snapshot(address,paletteAddress,end,n.read(M,56),descriptor,vertices,palette,events.copy())
meshes=[];cases=[];counts=collections.Counter();errors=[];rng=random.Random(0x603710);started=time.time();mismatches=0
def check(mi,weights,cursor,kind):
 global mismatches
 want=model(meshes[mi],weights,cursor);got=original(meshes[mi],weights,cursor);counts[kind]+=1
 if want!=got:
  mismatches+=1
  if len(errors)<10:errors.append({'mesh':mi,'expected':want,'native':got})
 cases.append({'mesh':mi,'weights':None if weights is None else[f.bits(v)for v in weights],'cursor':cursor,'native':got})
def descriptor(raw):
 out=bytearray(raw);struct.pack_into('<I',out,36,GPU);struct.pack_into('<I',out,44,TARGETS);return bytes(out)
for seed in range(160):
 verticesCount=seed%13;stride=rng.choice([12,16,20,32,48]);targets=seed%9;raw=bytearray(rng.randbytes(56));struct.pack_into('<H',raw,8,stride);raw[10:18]=bytes([rng.randrange(255)for _ in range(8)]);sentinel=seed%9
 if sentinel<8:raw[10+sentinel]=255
 struct.pack_into('<I',raw,20,seed%17);struct.pack_into('<I',raw,24,verticesCount);struct.pack_into('<I',raw,40,targets);vertices=bytearray(rng.randbytes(stride*verticesCount));deltas=[]
 for i in range(verticesCount):struct.pack_into('<3f',vertices,i*stride,*[f.f32(rng.uniform(-20,20))for _ in range(3)])
 for j in range(targets):deltas.append(None if rng.randrange(5)==0 else struct.pack('<'+'f'*(verticesCount*3),*[f.f32(rng.uniform(-5,5))for _ in range(verticesCount*3)]))
 mesh={'source':{'synthetic':seed},'descriptor':descriptor(raw),'vertices':bytes(vertices),'offset':u(raw,20)*stride,'deltas':deltas};mi=len(meshes);meshes.append(mesh)
 for weights in[None,[0.]*targets,[-0.]*targets,[f.f32(rng.uniform(-2,2))for _ in range(targets)]]:check(mi,weights,ARENA+seed%32,'synthetic')
batch=json.loads((B/'reports/animation-character-batch.json').read_text());characters=0;targetCount=0;vertexCount=0
for character in batch['success']:
 if not character['morphTargets']:continue
 path=B/'extracted'/character['path'];raw=path.read_bytes();assert sha(raw)==character['sha256'];scene=json.loads((B/character['output']/'source-metadata.json').read_text());characters+=1
 def ptr(at):v=struct.unpack_from('<i',raw,at)[0];return at+v if v else 0
 for mesh in scene['meshes']:
  if not mesh['dynamic']:continue
  at=mesh['address'];count=mesh['dynamic'];table=ptr(at+44);assert 0<table<=len(raw)-count*4;deltas=[]
  for j in range(count):
   p=ptr(table+j*4)
   if p:assert 0<=p<=len(raw)-mesh['vertexCount']*12
   deltas.append(raw[p:p+mesh['vertexCount']*12]if p else None)
  vb=scene['vertexBuffers'][mesh['vertexBuffer']];offset=mesh['vertexOffset']*mesh['stride'];start=vb['offset']+offset;vertices=raw[start:start+mesh['vertexCount']*mesh['stride']];mi=len(meshes);meshes.append({'source':{'path':character['path'],'sha256':character['sha256'],'mesh':mesh['index'],'meshAddress':at,'vertexOffset':start,'deltaTable':table},'descriptor':descriptor(raw[at:at+56]),'vertices':vertices,'offset':offset,'deltas':deltas});targetCount+=count;vertexCount+=mesh['vertexCount']
  for weights in[None,[0.]*count,[f.f32((j%7-2)*.125)for j in range(count)]]:check(mi,weights,ARENA+rng.randrange(32),'authored')
 if characters%50==0:print(characters,'characters',len(meshes),'meshes',mismatches,'mismatches',flush=True)
# Feed the actual pointer returned by original5d3a20 directly to original603710.
# Asset-export node/layer bindings select fixtures, not proof of the renderer itself.
helper=f.Oracle.__new__(f.Oracle);helper.n=n;helper.base=D+0x10000;helper.layersAt=D+0x81000;n.write(0x971760,bytes(i.bit_count()for i in range(256)))
clips=[];clipIds={};composedMeshes=set();compositionSkips=[]
for character in batch['success']:
 if not character['morphTargets']:continue
 gltf=json.loads((B/character['output']/'character.gltf').read_text());bindings=collections.defaultdict(set)
 for node in gltf['nodes']:
  if 'mesh'not in node:continue
  meta=gltf['meshes'][node['mesh']].get('extras',{})
  if meta.get('rigidJoint')is None and 'sourceMesh'in meta and 'sourceLayer'in node.get('extras',{}):bindings[meta['sourceMesh']].add(node['extras']['sourceLayer'])
 sources=sorted((B/'extracted'/character['path']).parent.glob('*.BSA'));available=[(path,f.Clip(path.read_bytes()))for path in sources]
 for mi,mesh in enumerate(meshes):
  if mesh['source'].get('path')!=character['path']:continue
  choices=[(path,clip,layer)for path,clip in available for layer in sorted(bindings[mesh['source']['mesh']])if layer<clip.nodes and len(mesh['deltas'])<=clip.channels]
  if not choices:compositionSkips.append({'mesh':mi,'source':mesh['source'],'reason':'No same-directory BSA compatible with decoded smooth layer and target count'});continue
  path,clip,layer=choices[0];key=path.relative_to(B).as_posix()
  if key not in clipIds:clipIds[key]=len(clips);clips.append({'path':key,'sha256':sha(clip.raw),'bytes':b64(clip.raw)})
  composedMeshes.add(mi)
  for frame in[1.,f.f32((clip.duration+1)*.5),clip.duration]:
   helper.prepare_pool([layer]);h=helper.upload(clip);table=n.call(0x5d3a20,[1,helper.layersAt,h,f.bits(frame)],count=2000000);weightPointer=n.unpack('<I',table)[0];nativeWeights=list(n.unpack('<'+'f'*clip.channels,weightPointer+8));weights=clip.layer(layer,frame);assert[f.bits(v)for v in nativeWeights]==[f.bits(v)for v in weights]
   cursor=ARENA+rng.randrange(32);want=model(mesh,weights,cursor);got=original(mesh,weights,cursor,weightPointer);counts['authoredBsaComposition']+=1
   if want!=got:
    mismatches+=1
    if len(errors)<10:errors.append({'mesh':mi,'clip':key,'layer':layer,'frame':frame,'expected':want,'native':got})
   cases.append({'mesh':mi,'weights':[f.bits(v)for v in nativeWeights],'cursor':cursor,'clip':clipIds[key],'layer':layer,'frame':f.bits(frame),'native':got})
payload=[{**r,'descriptor':b64(r['descriptor']),'vertices':b64(r['vertices']),'deltas':[None if d is None else b64(d)for d in r['deltas']]}for r in meshes];out=B/'reports/animation-morph-mesh-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':n.sha256,'meshAddress':M,'jointMatrices':b64(matrices),'meshes':payload,'clips':clips,'cases':cases},separators=(',',':')).encode(),mtime=0));report={'binarySha256':n.sha256,'comparisons':len(cases),'counts':dict(counts),'mismatches':mismatches,'examples':errors,'authoredCharacters':characters,'authoredMeshes':len(meshes)-160,'authoredTargets':targetCount,'authoredVertices':vertexCount,'composition':{'meshes':len(composedMeshes),'clips':len(clips),'skips':compositionSkips},'fixture':{'path':out.relative_to(B).as_posix(),'bytes':out.stat().st_size,'sha256':sha(out.read_bytes())},'elapsedSeconds':time.time()-started,'limits':['Original603710, memmove4ef660 and COM wrappers execute. Only successful Lock/Unlock virtual methods are adapter callbacks; no GPU or OS call occurs.','Authored BSA composition passes the original5d3a20 weight pointer directly into603710. Asset-export smooth-layer binding selects fixture inputs; full62fbf0/5f4ff0 renderer selection and live timing are not executed.','Descriptor/palette/vertex writes and allocator logical addresses checked; original allocation failure and device failure branches are outside scope.']};(B/'reports/animation-morph-mesh-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not mismatches
