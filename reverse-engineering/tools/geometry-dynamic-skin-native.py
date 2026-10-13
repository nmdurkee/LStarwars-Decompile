"""Full original5f0f00 -> shader -> skin/morph/ordinary writer composition."""
import ast,json,gzip,struct,hashlib,base64,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def prefix(file,stop):
 path=B/'tools'/file;nodes=[]
 for node in ast.parse(path.read_text()).body:
  if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id==stop for v in node.targets):break
  nodes.append(node)
 ns={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),ns);return ns
mp=prefix('animation-morph-packets-verify.py','cases')
ns=prefix('geometry-dynamic-submission-native.py','index');n=mp['n'];D=n.DATA;HIGH=D+0xe0000;SIZE=0x100000
ns['n']=n;ns['SIZE']=SIZE
for key in ['control','handle','header','owner','special','matrix','threshold','models','items','table','flags','bitset','overrides','shader','scale','translation','cache','output','combined','farLanes']:ns[key]+=0xe0000
for key in ['materials','records']:ns[key]=[p+0xe0000 for p in ns[key]]
for key,other in [('CONTROL','control'),('SCALE','scale'),('TRANS','translation')]:mp[key]=ns[other]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
def observe(mu,address,size,user):
 ns['calls'].append(address)
 if address==0x5e0530:
  sp=mu.reg_read(UC_X86_REG_ESP);ns['draws'].append(list(n.unpack('<2I',sp+4)))
 if address in [0x5e0200,0x5e02b0,0x5e0390]:ns['writers'].append(address)
for address in [0x6042e0,0x5fd220,0x607590,0x5e0530,0x5e0200,0x5e02b0,0x5e0390]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
u=ns['u'];w=ns['w'];cases=[];errors=[];counts=collections.Counter();expectedEvents=[];currentMesh=None;currentWeights=None
oldEvaluate=ns['os']['evaluate']
def packet(kind,b,args,uv):
 if not ns['activeOptions']['skin']:
  return oldEvaluate(kind,b,args,uv)
 for key,value in zip(['CONTROL','RECORD','CMD','SRC','CACHE','OUT','SCALE','TRANS'],args[:8]):mp[key]=value
 result,trace,events=mp['model'](b,currentMesh,currentWeights,args[9],uv);expectedEvents.extend(events);return result,0,trace
ns['os']['evaluate']=packet
# Retain the established normal model and runner, extending only the ABI inputs
# and expected selected writer. The original instructions remain unmodified.
source=(B/'tools/geometry-dynamic-submission-native.py').read_text();tree=ast.parse(source)
for node in tree.body:
 if isinstance(node,ast.FunctionDef)and node.name in ['model','run']:
  text=ast.get_source_segment(source,node)
  if node.name=='model':text=text.replace('0x5e02b0 if prefix else 0x5e0200','0x5e0390 if o[\'skin\'] else 0x5e02b0 if prefix else 0x5e0200')
  else:
   text=text.replace("0xfeedface,0,0","o['mode'],o['skin'],o['morph']").replace('count=500000','count=30000000')
   text=text.replace("'before':bytes(before).hex(),","'beforeZ':base64.b64encode(gzip.compress(bytes(before),mtime=0)).decode(),")
  exec(compile(text,'extended-normal-'+node.name,'exec'),ns)
ns['base64']=base64

def setup(mesh,index,authored,weights):
 # Construct a relocated64KiB normal scene region, then combine with the mesh
 # fixture. Its allocator arena is below the normal scene, in disjoint memory.
 old=ns['BASE'];ns['BASE']=HIGH;ns['ds']['BASE']=HIGH;ns['SIZE']=0x10000
 row=authored;before=bytes.fromhex(row['before']);minimum=list(struct.unpack_from('<3f',before,0x680));maximum=list(struct.unpack_from('<3f',before,0x690));matrix=list(struct.unpack_from('<16f',before,0x700));thresholds=[]
 for j in range(64):
  value=struct.unpack_from('<f',before,0x800+j*4)[0];thresholds.append(value)
  if value==0:break
 normal,o=ns['setup'](minimum,maximum,matrix,thresholds,index,1)
 ns['BASE']=old;ns['ds']['BASE']=old;ns['SIZE']=SIZE
 b=mp['initial'](mesh,weights,index,struct.pack('<16f',*matrix));b[HIGH-D:HIGH-D+0x10000]=normal
 w(b,ns['control'],mp['ARENA']+index%32)
 for ci in [4,8]:w(b,ns['items']+ci*16+4,mp['M'])
 # Ensure at least one accepted material per part while retaining native
 # linked gate filtering and alternate material bitset selection.
 o['filterMode']=0;o['globalOverride']=0;o['overrideTable']=0
 for material in ns['materials']:b[material-D+248:material-D+251]=bytes(3)
 return b,o

authored=[r for r in json.loads(gzip.decompress((R/'geometry-dynamic-submission-fixtures.json.gz').read_bytes()))['cases']if r['label'][0]!='synthetic'and r['label'][2]==1]
def execute(mi,index,skin,weighted,visible):
 global currentMesh,currentWeights
 currentMesh=mp['meshes'][mi];currentWeights=[mp['f'].f32((j%7-2)*.125)for j in range(len(currentMesh['deltas']))]if weighted else None
 b,o=setup(currentMesh,index,authored[mi%len(authored)],currentWeights);skinAddress=D+0x10000+(index%4)*0x4000 if skin else 0
 if skin:b[skinAddress-D:skinAddress-D+len(mp['matrices'])]=mp['matrices']
 o.update(skin=skinAddress,morph=mp['WEIGHT']if weighted else 0,mode=[0,2,0xffffffff,0xfeedface][index%4],forcedVisibility=visible)
 ns['activeOptions']=o;mp['current']=currentMesh;expectedEvents.clear();mp['events'].clear();mp['calls'].clear();n.write(mp['BASEVERTEX'],currentMesh['vertices']);at=mp['DELTA']
 for delta in currentMesh['deltas']:
  if delta is not None:n.write(at,delta);at+=len(delta)+16
 ns['run'](b,o,['mesh',mi,index,skin,weighted]);case=ns['cases'][-1];case.update(mesh=mi,weights=None if currentWeights is None else[mp['f'].bits(v)for v in currentWeights],nativeEvents=mp['events'].copy(),sourceObject=authored[mi%len(authored)]['label'])
 if mp['events']!=expectedEvents:errors.append(dict(case=index,field='COM events',actual=mp['events'],expected=expectedEvents.copy()))
 assert u(n.read(D,SIZE),ns['control'])<HIGH
 counts['cases']+=1;counts['skinInputs']+=bool(skin);counts['morphInputs']+=weighted;counts['skinWrites']+=ns['writers'].count(0x5e0390);counts['locks']+=len(mp['events'])//2;counts['mode'+hex(o['mode'])]+=1
 if ns['errors']:errors.extend(ns['errors']);raise AssertionError(errors[:3])
 if errors:raise AssertionError(errors[:3])
for mi in range(len(mp['meshes'])):
 for mode in [0,1]:execute(mi,mi*2+mode,True,bool(mode),1)
 if mi%100==0:print('caller meshes',mi,'errors',len(errors),flush=True)
for i in range(128):execute(i,2000+i,bool(i&1),bool(i&2),[-1,0,1,2][i%4])
fp=R/'geometry-dynamic-skin-fixtures.json.gz';doc=dict(cases=ns['cases'],meshFixture=dict(file=str(mp['fixturePath'].relative_to(B)),sha256=hashlib.sha256(mp['fixturePath'].read_bytes()).hexdigest()),addresses={k:ns[k]for k in ['control','shader','scale','translation','cache','output','combined','farLanes']},meshAddresses={k:mp[k]for k in ['M','WEIGHT','GPU','VTABLE','TARGETS','BASEVERTEX','DELTA']})
fp.write_bytes(gzip.compress(json.dumps(doc,separators=(',',':')).encode(),mtime=0))
report=dict(schema='geometry-dynamic-skin-native-v1',passed=not errors,binarySHA256=n.sha256,counts=dict(counts),normalCounts=ns['counts'],authoredMeshes=sum('path'in m['source']for m in mp['meshes']),syntheticMeshes=sum('path'not in m['source']for m in mp['meshes']),sourceObjects=len(set(tuple(c['sourceObject'][:2])for c in ns['cases'])),sources=len(set(c['sourceObject'][0]for c in ns['cases'])),errors=errors,fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Original5f0f00 through actual scalar bounds, material selection, shader emission,5e0530 dispatcher and ordinary/prefix/skin/morph writers. Only successful COM virtual Lock/Unlock methods are supplied.','All authored670 morph meshes plus160 synthetic mesh descriptors, authored scene bounds/transforms/LOD tables combined with relocated controlled runtime records. Palette matrix bytes are opaque fixture patterns, not a live posed character.','Skin pointer relocates among four buffers; mode argument varies independently, including0 and2. Null skin with nonnull morph input still follows ordinary/prefix dispatch.','Zero shadows/sway/fade; same-layout material selection. Different-layout merge verified separately and exposed in the same portable overload, not combined in this batch.','Full1MiB persistent byteimage compared including mirrored scratch/shader/bounds state, except32-byte portable transient cache/output adapter. Successful capacities, finite active deformation, disjoint valid state.','CPU packet construction only. Managed compilation and runtime equality are separate; no managed/game/GPU process launched.'])
(R/'geometry-dynamic-skin-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not errors
