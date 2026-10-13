"""Original full character and shadow path with authored GHG billboard records."""
from pathlib import Path
import ast,json,gzip,struct,hashlib,base64,collections,os
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def sha(b):return hashlib.sha256(b).hexdigest()
path=B/'tools/animation-character-shadow-packets-verify.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id=='cases'for v in node.targets):break
 nodes.append(node)
ss={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),ss)
c=ss['c'];g=c['g'];mp=c['mp'];n=c['n'];ns=c['ns'];f=c['f'];D=n.DATA;RESOURCE=D+0x1d000
bbpath=B/'tools/animation-billboard-verify.py';nodes=[]
for node in ast.parse(bbpath.read_text()).body:
 if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id=='authored'for v in node.targets):break
 nodes.append(node)
bb={'__file__':str(bbpath)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(bbpath),'exec'),bb);active=None
def packet(kind,b,args,uv):
 for key,value in zip(['CONTROL','RECORD','COMMAND','WORLD','CACHE','OUTPUT'],args[:6]):bb[key]=value
 bb['RESOURCE']=RESOURCE;case=dict(kind='writer',world=ns['floats'](b,args[3],16),view=active['view'],forward=active['forward'],flags=ns['u'](b,RESOURCE),alpha=args[8]);result,ret,trace=bb['model'](case,b);return result,ret,trace
ns['os']['evaluate']=packet
source=(B/'tools/geometry-dynamic-shadow-native.py').read_text()
node=next(node for node in ast.parse(source).body if isinstance(node,ast.FunctionDef)and node.name=='model');text=ast.get_source_segment(source,node).replace('0x5e02b0 if prefix else 0x5e0200','0x5e0490');exec(compile(text,'billboard-shadow-model','exec'),ss['sh'])
from unicorn import UC_HOOK_CODE
n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,user:ns['writers'].append(a),begin=0x5e0490,end=0x5e0490)
bbfixture='reports/animation-billboard-native-fixtures.json.gz';rows=[r for r in json.loads(gzip.decompress((B/bbfixture).read_bytes()))['cases']if r['kind']=='dispatch'and'path'in r['source']and r['source']['path'].upper().endswith('.GHG')];rawCache={}
# Unused mesh scaffolding initializes the common bounded memory image; opcode8f
# must bypass these fields and the poisoned morph identities in every draw.
dummy=dict(mp['meshes'][0]);dummy['descriptor']=bytearray(dummy['descriptor']);dummy['descriptor'][10:18]=b'\xff'*8;struct.pack_into('<II',dummy['descriptor'],40,0,0);dummy['vertices']=b'';dummy['deltas']=[];dummy['offset']=0;dummyIndex=len(mp['meshes']);mp['meshes'].append(dummy)
def setup(resourceIndex,index,mode):
 global active
 row=rows[resourceIndex];origin=row['source'];dummy['source']=dict(origin,path=origin['path'].replace('\\','/'));assert dummy['source']['path']in c['byPath'];b,o,r,weights,handles,state=c['setup'](dummyIndex,index,1 if mode==6 else 0)
 p=origin['path']
 if p not in rawCache:rawCache[p]=(B/'extracted'/p).read_bytes();assert sha(rawCache[p])==origin['sha256']
 address=origin['resource'];ss['put'](b,RESOURCE,rawCache[p][address:address+16])
 for ci in [4,8]:b[ns['items']-D+ci*16]=0x8f;ns['w'](b,ns['items']+ci*16+4,RESOURCE)
 o['view']=[f.value(x)for x in row['view']];o['forward']=[f.value(x)for x in row['forward']];state['world']=row['world'];ss['put'](b,c['WORLD'],struct.pack('<16I',*row['world']));state['morph']=[0xdead0003 for _ in state['morph']];ss['put'](b,c['MORPHS'],struct.pack('<'+'I'*len(state['morph']),*state['morph']));n.pack('<3f',0x973708,*o['forward']);active=o
 return b,o,r,weights,handles,state
ss.update(billboardSetup=setup,billboardRows=rows,dummyIndex=dummyIndex,cases=[],counts=collections.Counter(),rigs=set(),errors=[])
source=path.read_text();node=next(node for node in ast.parse(source).body if isinstance(node,ast.FunctionDef)and node.name=='execute');text=ast.get_source_segment(source,node)
old="b,o,r,weights,handles,state=c['setup'](mi,index,5 if mode==5 else 1 if mode==6 else 0);mesh=mp['meshes'][mi]";assert old in text;text=text.replace(old,"b,o,r,weights,handles,state=billboardSetup(mi,index,mode);mesh=mp['meshes'][dummyIndex]")
text=text.replace("dict(mesh=mi,rig=", "dict(mesh=0,billboardSource=billboardRows[mi]['source'],rig=")
exec(compile(text,'character-billboard-execute','exec'),ss)
limit=int(os.environ.get('CHARACTER_BILLBOARD_LIMIT','0'))
for i,row in enumerate(rows):
 for mode in [0,1,2,3,4,6,7]:ss['execute'](i,len(ss['cases']),mode)
 if(i+1)%12==0:print('billboard resources',i+1,'checks',len(ss['cases']),flush=True)
 if limit and i+1>=limit:break
counts=dict(ss['counts']);counts['billboardPackets']=counts['packets'];payload=[dict(r,joints=[[f.bits(v)for v in a]for a in r['joints']],inverse=[[f.bits(v)for v in a]for a in r['inverse']],minimum=[f.bits(v)for v in r['minimum']],maximum=[f.bits(v)for v in r['maximum']])for r in c['rigs']]
fp=R/'animation-character-billboard-packets-native-fixtures.json.gz';doc=dict(binarySha256=n.sha256,rigs=payload,meshFixture=dict(path=str(mp['fixturePath'].relative_to(B)),sha256=sha(mp['fixturePath'].read_bytes())),addresses={k:ns[k]for k in ['control','shader','scale','translation','cache','output','matrix','combined','farLanes']},maskMirror=ss['MASKS'],cases=ss['cases']);fp.write_bytes(gzip.compress(json.dumps(doc,separators=(',',':')).encode(),mtime=0))
deps=['tools/animation-character-shadow-packets-verify.py','tools/animation-character-packets-verify.py','tools/geometry-dynamic-shadow-native.py','tools/animation-billboard-verify.py',bbfixture,'reports/animation-layer-submission-native-fixtures.json.gz']
report=dict(binarySha256=n.sha256,d3dx=c['dll'],comparisons=len(ss['cases']),counts=counts,authoredRigs=len(ss['rigs']),authoredResources=min(len(rows),limit)if limit else len(rows),mismatches=0,fixture=dict(path=fp.relative_to(B).as_posix(),bytes=fp.stat().st_size,sha256=sha(fp.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in deps],method='Full original character5f4ff0 -> secondary/normal/shadow5f0f00 ->5e0530 ->5e0490 -> billboard basis/scale helpers. All original CPU code with observation hooks; COM callbacks installed by shared fixture but never invoked. Whole1MiB persistent image and mirrored masks, ordered record/writer tuples, layer matrix/palette hashes and shared flags/cursor compared.',limits=['All authored GHG billboard resource records use their source rig topology and bind matrices, with controlled scene/material bindings. Does not establish shipped per-layer loader association.','View/forward inputs are explicit fixtures; finite scalar results and disjoint allocator capacity.','Sway/fade, different-layout material merge and active legacy character shadow queue remain separate.','Unused mesh scaffolding is not an asserted billboard input; poisoned morph pointers verify opcode8f bypass. No GPU or managed executable launch.'])
(R/'animation-character-billboard-packets-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
