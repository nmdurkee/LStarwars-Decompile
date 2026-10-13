"""Original mixed billboard/mesh commands in source-matched character layers."""
from pathlib import Path
import ast,json,gzip,struct,hashlib,base64,collections,os
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def sha(b):return hashlib.sha256(b).hexdigest()
path=B/'tools/animation-character-billboard-packets-verify.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id=='limit'for v in node.targets):break
 nodes.append(node)
bbn={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),bbn)
ss=bbn['ss'];c=bbn['c'];g=bbn['g'];ns=bbn['ns'];mp=bbn['mp'];n=bbn['n'];f=c['f'];D=n.DATA;RESOURCE=bbn['RESOURCE'];oldBillboardPacket=bbn['packet'];rawCache={}
def packet(kind,b,args,uv):return oldBillboardPacket(kind,b,args,uv)if b[args[2]-D]==0x8f else g['packet'](kind,b,args,uv)
ns['os']['evaluate']=packet
source=(B/'tools/geometry-dynamic-shadow-native.py').read_text();node=next(node for node in ast.parse(source).body if isinstance(node,ast.FunctionDef)and node.name=='model');text=ast.get_source_segment(source,node).replace('0x5e02b0 if prefix else 0x5e0200',"0x5e0490 if b[cmd-D]==0x8f else 0x5e0390 if o['skin'] else 0x5e02b0 if prefix else 0x5e0200");exec(compile(text,'mixed-shadow-model','exec'),ss['sh'])
rows=[];tasks=[];matching={}
for i,mesh in enumerate(mp['meshes'][:-1]):
 p=mesh['source'].get('path','').replace('\\','/')
 if p:matching.setdefault(p,[]).append(i)
for row in bbn['rows']:
 p=row['source']['path'].replace('\\','/')
 if p not in matching:continue
 mi=matching[p][(len(rows)//2)%len(matching[p])]
 for reverse in [False,True]:tasks.append((mi,row,reverse));rows.append(row)
def setup(taskIndex,index,mode):
 mi,row,reverse=tasks[taskIndex];b,o,r,weights,handles,state=c['setup'](mi,index,5 if mode==5 else 1 if mode==6 else 0);origin=row['source'];p=origin['path']
 if p not in rawCache:rawCache[p]=(B/'extracted'/p).read_bytes();assert sha(rawCache[p])==origin['sha256']
 at=origin['resource'];ss['put'](b,RESOURCE,rawCache[p][at:at+16]);ci=8 if reverse else 4;b[ns['items']-D+ci*16]=0x8f;ns['w'](b,ns['items']+ci*16+4,RESOURCE)
 o['view']=[f.value(x)for x in row['view']];o['forward']=[f.value(x)for x in row['forward']];state['world']=row['world'];ss['put'](b,c['WORLD'],struct.pack('<16I',*row['world']));n.pack('<3f',0x973708,*o['forward']);bbn['active']=o
 return b,o,r,weights,handles,state
ss.update(billboardSetup=setup,billboardRows=rows,mixedTasks=tasks,cases=[],counts=collections.Counter(),rigs=set(),errors=[])
text=bbn['text'].replace("mesh=mp['meshes'][dummyIndex]","mesh=mp['meshes'][mixedTasks[mi][0]]").replace('dict(mesh=0,billboardSource=',"dict(mesh=mixedTasks[mi][0],billboardFirst=not mixedTasks[mi][2],billboardSource=")
assert "mesh=mp['meshes'][mixedTasks[mi][0]]"in text;exec(compile(text,'mixed-character-execute','exec'),ss)
limit=int(os.environ.get('CHARACTER_MIXED_LIMIT','0'))
for i,task in enumerate(tasks):
 for mode in [0,1,5,6]:ss['execute'](i,len(ss['cases']),mode)
 if(i+1)%12==0:print('mixed lists',i+1,'checks',len(ss['cases']),flush=True)
 if limit and i+1>=limit:break
counts=dict(ss['counts']);counts['billboardPackets']=sum(d[2]==0x5e0490 for c in ss['cases']for d in c['native']['draws']);counts['ordinaryPackets']=sum(d[2]==0x5e0200 for c in ss['cases']for d in c['native']['draws']);counts['prefixPackets']=sum(d[2]==0x5e02b0 for c in ss['cases']for d in c['native']['draws']);payload=[dict(r,joints=[[f.bits(v)for v in a]for a in r['joints']],inverse=[[f.bits(v)for v in a]for a in r['inverse']],minimum=[f.bits(v)for v in r['minimum']],maximum=[f.bits(v)for v in r['maximum']])for r in c['rigs']]
fp=R/'animation-character-mixed-packets-native-fixtures.json.gz';doc=dict(binarySha256=n.sha256,rigs=payload,meshFixture=dict(path=str(mp['fixturePath'].relative_to(B)),sha256=sha(mp['fixturePath'].read_bytes())),addresses={k:ns[k]for k in ['control','shader','scale','translation','cache','output','matrix','combined','farLanes']},maskMirror=ss['MASKS'],cases=ss['cases']);fp.write_bytes(gzip.compress(json.dumps(doc,separators=(',',':')).encode(),mtime=0))
deps=['tools/animation-character-billboard-packets-verify.py','tools/animation-character-shadow-packets-verify.py','tools/geometry-dynamic-shadow-native.py','tools/geometry-dynamic-skin-native.py','reports/animation-billboard-native-fixtures.json.gz',str(mp['fixturePath'].relative_to(B))]
report=dict(binarySha256=n.sha256,d3dx=c['dll'],comparisons=len(ss['cases']),counts=counts,authoredRigs=len(ss['rigs']),authoredMeshes=len(set(c['mesh']for c in ss['cases'])),authoredBillboardResources=len(set((c['billboardSource']['path'],c['billboardSource']['resource'])for c in ss['cases'])),mismatches=0,fixture=dict(path=fp.relative_to(B).as_posix(),bytes=fp.stat().st_size,sha256=sha(fp.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in deps],method='Complete original character/secondary/shadow chain with mixed82/8f command lists in both orders. Original normal/prefix/skin/morph/billboard writers and both shader emitters execute, only successful COM Lock/Unlock supplied. Whole1MiB persistent bytes, mirrored masks, layer matrix/palette/cursor, exact packet and destination-record order, and COM events compare.',limits=['Same-source authored rigid/smooth layer topology, billboard descriptors and selected meshes from two Mace Windu lightsabre GHGs. Runtime handle/material bindings controlled; exact loader association not claimed.','Finite scalar explicit camera inputs, inactive sway/fade, valid bounded memory. Weighted cases use one shadow volume to retain allocator capacity.','No GPU/live scheduler or managed executable launch.'])
(R/'animation-character-mixed-packets-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
