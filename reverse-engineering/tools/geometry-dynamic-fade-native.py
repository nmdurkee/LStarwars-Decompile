"""Original normal caller fade gate and alpha forwarding into real writers."""
import ast,json,gzip,struct,hashlib,base64,math,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';path=B/'tools/geometry-dynamic-skin-native.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.For)and isinstance(node.target,ast.Name)and node.target.id=='mi':break
 nodes.append(node)
skin={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),skin)
ns=skin['ns'];mp=skin['mp'];n=skin['n'];D=n.DATA;SIZE=skin['SIZE'];u=ns['u'];w=ns['w'];x87=ns['x87'];f32=ns['f32'];bits=ns['bits'];fades=D+0xe6800
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
alphaWords=[];fadeInputs=[];expectedAlpha=[];expectedFade=[]
def fade(d,start,end):
 expectedFade.append([bits(d),bits(start),bits(end)])
 if end<=start:
  if d<=end*end:return 0.
  numerator=f32(math.sqrt(d))-end;denominator=start-end
  if denominator==0:return struct.unpack('<f',bytes.fromhex('0000c0ff'))[0]if numerator==0 else 1.
  value=f32(numerator/denominator);return 1. if value>1 else value
 if d<=start*start:return 1.
 value=f32((end-f32(math.sqrt(d)))/(end-start));return 0. if value<0 else value
def observe(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x5df7b0:fadeInputs.append(list(n.unpack('<3I',sp+4)))
 else:alphaWords.append(n.unpack('<I',sp+28)[0])
for address in [0x5df7b0,0x5e0530]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
ns['fade']=fade;ns['expectedAlpha']=expectedAlpha
source=(B/'tools/geometry-dynamic-submission-native.py').read_text();node=next(x for x in ast.parse(source).body if isinstance(x,ast.FunctionDef)and x.name=='model');text=ast.get_source_segment(source,node)
text=text.replace('modelAddress=u(b,sp+0xb0)+lod*12;w(b,cache,0)', '''modelAddress=u(b,sp+0xb0)+lod*12;alpha=1.
 if u(b,owner+12)and b[flags-BASE+3]&64:
  alpha=fade(distance,*floats(b,u(b,owner+12)+24,2))
  if alpha==0:return b,0,shadow,emitted
 w(b,cache,0)''')
text=text.replace('0x3f800000,meta];b[:],ret,trace=', 'bits(alpha),meta];expectedAlpha.append(bits(alpha));b[:],ret,trace=')
text=text.replace('0x5e02b0 if prefix else 0x5e0200',"0x5e0390 if o['skin'] else 0x5e02b0 if prefix else 0x5e0200")
exec(compile(text,'fade-normal-model','exec'),ns)
prior=json.loads(gzip.decompress((R/'geometry-dynamic-skin-fixtures.json.gz').read_bytes()));errors=[];counts=collections.Counter();runtime={};scenes={};sourceIndex={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
def pairFor(c):
 source,index,unused=c['sourceObject']
 if source not in runtime:
  runtime[source]=json.loads((B/'exports/geometry/scene-runtime'/(source+'.json')).read_text())['renderState'];scenes[source]=json.loads((B/sourceIndex[source]['report']).read_text())
 special=scenes[source]['specialObjects'][index];bound=special['boundsIndex'];return runtime[source]['instances'][bound]['fade']
def execute(c,label,pair,active=True,pointer=True,synthetic=None,skinOverride=None):
 b=bytearray(gzip.decompress(base64.b64decode(c['beforeZ'])));o=dict(c['options']);mi=c['mesh'];mesh=mp['meshes'][mi];weights=None if c['weights']is None else[struct.unpack('<f',struct.pack('<I',v))[0]for v in c['weights']]
 skin['currentMesh']=mesh;skin['currentWeights']=weights;mp['current']=mesh;ns['activeOptions']=o;w(b,ns['owner']+12,fades if pointer else 0);ns['storefloats'](b,fades+24,pair);b[ns['flags']-D+3]=(b[ns['flags']-D+3]&~64)|(64 if active else 0);o['forcedVisibility']=1
 if skinOverride is not None:o['skin']=skinOverride
 if synthetic is not None:
  ns['storefloats'](b,ns['special']+0x80,[0.,0.,0.]);ns['storefloats'](b,ns['special']+0x90,[0.,0.,0.]);ns['storefloats'](b,o['matrix'],ns['IDENTITY']);o['camera']=synthetic
 skin['expectedEvents'].clear();mp['events'].clear();mp['calls'].clear();expectedAlpha.clear();expectedFade.clear();alphaWords.clear();fadeInputs.clear();n.write(mp['BASEVERTEX'],mesh['vertices']);at=mp['DELTA']
 for delta in mesh['deltas']:
  if delta is not None:n.write(at,delta);at+=len(delta)+16
 ns['run'](b,o,label);row=ns['cases'][-1];row.update(mesh=mi,weights=c['weights'],nativeEvents=mp['events'].copy(),sourceObject=c['sourceObject'],fadePair=pair,nativeFadeInputs=fadeInputs.copy(),nativeAlphaWords=alphaWords.copy())
 if mp['events']!=skin['expectedEvents']or alphaWords!=expectedAlpha or fadeInputs!=expectedFade:errors.append(dict(label=label,events=mp['events'],expectedEvents=skin['expectedEvents'].copy(),nativeAlpha=alphaWords.copy(),expectedAlpha=expectedAlpha.copy(),nativeFade=fadeInputs.copy(),expectedFade=expectedFade.copy()))
 counts['cases']+=1;counts['fadeCalls']+=len(fadeInputs);counts['zeroFadeReturns']+=bool(fadeInputs and not alphaWords);counts['skinWrites']+=ns['writers'].count(0x5e0390);counts['ordinaryWrites']+=ns['writers'].count(0x5e0200);counts['prefixWrites']+=ns['writers'].count(0x5e02b0);counts['nonunitForwarded']+=sum(v!=0x3f800000 for v in alphaWords);counts['nanForwarded']+=sum((v&0x7fffffff)>0x7f800000 for v in alphaWords)
 if ns['errors']:errors.extend(ns['errors']);raise AssertionError(errors[:3])
 if errors:raise AssertionError(errors[:3])
for mi in range(830):
 c=prior['cases'][mi*2+(mi&1)];execute(c,['authored',mi],pairFor(c),skinOverride=0 if mi%3==0 else None)
 if mi%100==0:print('fade meshes',mi,'errors',len(errors),flush=True)
pairs=[(0.,1.),(1.,0.),(2.,8.),(12.,3.),(4.,4.),(.1,.3),(.3,.1),(-2.,3.),(-3.,-1.)]
for i in range(256):
 c=prior['cases'][(i%128)*2+(i&1)];pair=[f32(v)for v in pairs[i%len(pairs)]];camera=[float([0,1,2,3,4,5,8,12][i%8]),0.,0.]
 if i%16==0:pair=[4.,4.];camera=[4.,2**-10,2**-10]
 execute(c,['edge',i],pair,active=i%13!=1,pointer=i%13!=2,synthetic=camera,skinOverride=0 if i%3==0 else None)
fp=R/'geometry-dynamic-fade-fixtures.json.gz';doc={k:prior[k]for k in ['meshFixture','addresses','meshAddresses']};doc['cases']=ns['cases'];fp.write_bytes(gzip.compress(json.dumps(doc,separators=(',',':')).encode(),mtime=0))
report=dict(schema='geometry-dynamic-fade-native-v1',passed=not errors,binarySHA256=n.sha256,counts=dict(counts),normalCounts=ns['counts'],authoredMeshes=670,syntheticMeshes=160,sourceObjects=len(set(tuple(c['sourceObject'][:2])for c in ns['cases'])),sources=len(runtime),errors=errors,fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Full original5f0f00 and5df7b0/sqrt execute unchanged, including shader and actual selected packet writer. Only successful COM virtual methods are supplied when deforming.','All670 authored morph meshes plus160 synthetic meshes,480 authored object min/max/matrices/LOD/fade pairs across60scenes; runtime fade flag enabled explicitly to exercise pairs.256 targeted finite endpoint/gating cases.','Exact zero fade returns0 before cache initialization, shader reset, shadow-mask cleanup or packet production. Equal endpoints can yield original negative quietNaN; bit pattern and forwarded alpha retained.','Ordinary/prefix writers use forwarded fade alpha; skin writer receives metadata but not alpha and forces1.0. Null skin with nonnull morph uses ordinary/prefix.','Finite start/end/distance inputs; this validates the existing numeric model at these fixtures, not every finite arithmetic midpoint. No shadows/sway/billboards/SIMD or different-layout merge in this batch.','Persistent1MiB image except32-byte portable cache/output scratch, fade arguments, alpha words and COM events compare. No managed/game/GPU launch.'])
(R/'geometry-dynamic-fade-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not errors
