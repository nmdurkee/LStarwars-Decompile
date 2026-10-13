"""Unchanged normal5f0f00 -> shader -> billboard dispatcher/writer/math."""
import ast,json,gzip,struct,hashlib,base64,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def prefix(file,stop):
 path=B/'tools'/file;nodes=[]
 for node in ast.parse(path.read_text()).body:
  if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id==stop for v in node.targets):break
  nodes.append(node)
 ns={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),ns);return ns
ns=prefix('geometry-dynamic-submission-native.py','index');bb=prefix('animation-billboard-verify.py','authored');n=ns['n'];D=n.DATA;RESOURCE=D+0x6800;u=ns['u'];w=ns['w'];active=None
from unicorn import UC_HOOK_CODE
n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,user:ns['writers'].append(a),begin=0x5e0490,end=0x5e0490)
def packet(kind,b,args,uv):
 for key,value in zip(['CONTROL','RECORD','COMMAND','WORLD','CACHE','OUTPUT'],args[:6]):bb[key]=value
 bb['RESOURCE']=RESOURCE;c=dict(kind='writer',world=ns['floats'](b,args[3],16),view=active['view'],forward=active['forward'],flags=u(b,RESOURCE),alpha=args[8]);result,ret,trace=bb['model'](c,b);return result,ret,trace
ns['os']['evaluate']=packet
source=(B/'tools/geometry-dynamic-submission-native.py').read_text()
for node in ast.parse(source).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['model','run']:
  text=ast.get_source_segment(source,node)
  if node.name=='model':text=text.replace('0x5e02b0 if prefix else 0x5e0200','0x5e0490')
  else:text=text.replace('0xfeedface,0,0',"o['mode'],o['skin'],o['morph']").replace("'before':bytes(before).hex(),","'beforeZ':base64.b64encode(gzip.compress(bytes(before),mtime=0)).decode(),")
  exec(compile(text,'billboard-normal-'+node.name,'exec'),ns)
ns['base64']=base64
normalRows=[r for r in json.loads(gzip.decompress((R/'geometry-dynamic-submission-fixtures.json.gz').read_bytes()))['cases']if r['label'][0]!='synthetic'and r['label'][2]==1]
billboardPath=R/'animation-billboard-native-fixtures.json.gz';rows=[r for r in json.loads(gzip.decompress(billboardPath.read_bytes()))['cases']if r['kind']=='dispatch'];rawCache={};counts=collections.Counter()
for index,c in enumerate(rows):
 normal=normalRows[index%len(normalRows)];old=bytes.fromhex(normal['before']);minimum=list(struct.unpack_from('<3f',old,0x680));maximum=list(struct.unpack_from('<3f',old,0x690));world=[struct.unpack('<f',struct.pack('<I',v))[0]for v in c['world']];thresholds=[]
 for j in range(64):
  value=struct.unpack_from('<f',old,0x800+j*4)[0];thresholds.append(value)
  if value==0:break
 b,o=ns['setup'](minimum,maximum,world,thresholds,index,1);o['forcedLod']=0;o['filterMode']=0;o['globalOverride']=0;o['overrideTable']=0
 for m in ns['materials']:b[m-D+248:m-D+251]=bytes(3)
 for ci in [4,8]:b[ns['items']-D+ci*16]=0x8f;w(b,ns['items']+ci*16+4,RESOURCE)
 if 'path'in c['source']:
  p=c['source']['path']
  if p not in rawCache:rawCache[p]=(B/'extracted'/p).read_bytes();assert hashlib.sha256(rawCache[p]).hexdigest()==c['source']['sha256']
  address=c['source']['resource'];b[RESOURCE-D:RESOURCE-D+16]=rawCache[p][address:address+16];counts['authoredResources']+=1
 else:w(b,RESOURCE,c['flags']);counts['syntheticResources']+=1
 o.update(view=[struct.unpack('<f',struct.pack('<I',v))[0]for v in c['view']],forward=[struct.unpack('<f',struct.pack('<I',v))[0]for v in c['forward']],skin=[0,0xdead0002][index%2],morph=[0xdead0003,0][index%2],mode=[0,2,0xffffffff][index%3]);active=o;n.pack('<3f',0x973708,*o['forward'])
 ns['run'](b,o,['billboard',index]);ns['cases'][-1].update(resource=RESOURCE,resourceSource=c['source'],sourceObject=normal['label'],nativeEvents=[]);counts['billboardWrites']+=ns['writers'].count(0x5e0490);counts['cases']+=1
 if ns['errors']:raise AssertionError(ns['errors'][:3])
 if index%200==0:print('billboard caller',index,'errors',len(ns['errors']),flush=True)
fp=R/'geometry-dynamic-billboard-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(cases=ns['cases'],addresses={k:ns[k]for k in ['control','shader','scale','translation','cache','output','combined','farLanes']},billboardFixture=dict(file=str(billboardPath.relative_to(B)),sha256=hashlib.sha256(billboardPath.read_bytes()).hexdigest())),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-dynamic-billboard-native-v1',passed=not ns['errors'],binarySHA256=n.sha256,counts=dict(counts),normalCounts=ns['counts'],authoredCarriers=len(rawCache),sourceObjects=len(set(tuple(c['sourceObject'][:2])for c in ns['cases'])),sources=len(set(c['sourceObject'][0]for c in ns['cases'])),errors=ns['errors'],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Full original normal5f0f00 -> shader emission ->5e0530 ->5e0490 ->603610/603970 and all original camera-facing/vector/sqrt helpers. Observation hooks only, no computational services.','All1367 authored billboard descriptor records across100carriers, source-bound world transforms (identity fallback explicitly retained where not associated), plus256 synthetic descriptors/worlds. Normal bounds/LOD from480 authored objects across60scenes; camera view/forward remain explicit fixtures.','Each case emits four actual billboard packets through linked material gates. Invalid nonnull skin/morph sentinels alternate with null pointers; billboard branch never reads those inputs.','Finite inputs/intermediates, forcedVisibility1, same-layout materials, zero shadows/sway/fade and successful disjoint allocator capacity. No different-layout material merge or live camera producer claim.','Whole64KiB persistent state including shader and scratch/bounds mirrors, excluding32-byte portable cache/output adapter; exact return, shadow mask and writer tuples compare.','CPU payload construction only. Backend/GPU billboard expansion, final image and managed runtime equality remain separate.'])
(R/'geometry-dynamic-billboard-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not ns['errors']
