"""Original character layers through normal dynamic submission and real packets."""
from pathlib import Path
import ast,importlib.util,json,gzip,struct,base64,hashlib,collections,os
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def sha(b):return hashlib.sha256(b).hexdigest()
def load(path):return json.loads(gzip.decompress((B/path).read_bytes()))
# Reuse geometry setup and independent models; stop before its native runner.
path=B/'tools/geometry-dynamic-skin-native.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.For)and isinstance(node.target,ast.Name)and node.target.id=='mi':break
 nodes.append(node)
g={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),g)
n=g['n'];D=n.DATA;mp=g['mp'];ns=g['ns'];u=g['u'];w=g['w'];SIZE=g['SIZE'];HIGH=g['HIGH']
spec=importlib.util.spec_from_file_location('character_packet_math',B/'tools/animation-skeletal-fixture.py');f=importlib.util.module_from_spec(spec);spec.loader.exec_module(f);dll=f.load_original_d3dx(n)
layer={'f':f,'struct':struct}
for node in ast.parse((B/'tools/animation-layer-submission-verify.py').read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['multiply','packrows']:exec(compile(ast.Module(body=[node],type_ignores=[]),'layer-math','exec'),layer)
H=D+0x20000;WORLD=D+0x21000;JOINTS=D+0x22000;INVERSE=D+0x27000;LAYERS=D+0x2c000;ARRAYS=D+0x30000;HANDLES=D+0x3a000;MAP=D+0x3c000;MORPHS=D+0x3d000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
nativeLayers=[];currentRig=None

def observe(mu,address,size,user):
 if address==0x5f0f00:
  sp=mu.reg_read(UC_X86_REG_ESP);h,m,mode,skin,morph=n.unpack('<5I',sp+4)
  nativeLayers.append(dict(handle=h,mode=mode,matrix=sha(n.read(m,64)),skin=skin,palette=sha(n.read(skin,len(currentRig['joints'])*64))if skin else None,morph=morph,cursor=n.unpack('<I',ns['control'])[0],visible=n.unpack('<i',0x806ccc)[0],flag=n.unpack('<I',0x9715a0)[0]))
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x5f0f00,end=0x5f0f00)
rigFixture='reports/animation-layer-submission-native-fixtures.json.gz';allRigs=load(rigFixture)['rigs'];rigs=[];byPath={}
for r in allRigs:
 if 'path'not in r['source']:continue
 for key in ['joints','inverse']:r[key]=[[f.value(x)for x in a]for a in r[key]]
 for key in ['minimum','maximum']:r[key]=[f.value(x)for x in r[key]]
 byPath[r['source']['path']]=len(rigs);rigs.append(r)

def put(b,p,v):b[p-D:p-D+len(v)]=v

def setup(mi,index,mode):
 mesh=mp['meshes'][mi];r=rigs[byPath[mesh['source']['path']]];weights=[f.f32((i%7-2)*.125)for i in range(len(mesh['deltas']))]if mode==5 else None
 # Only use authored palette indexes that belong to this exact source rig.
 ids=list(mesh['descriptor'][10:18]);ids=ids[:ids.index(255)]if 255 in ids else ids
 assert all(i<len(r['joints'])for i in ids)
 b,o=g['setup'](mesh,index,g['authored'][mi%len(g['authored'])],weights)
 b[H-D:mp['ARENA']-D]=bytes(mp['ARENA']-H)
 world=f.IDENTITY.copy();world[12:15]=[1.25,-2.5,5.]
 if mode%4==3:world=[0.,1.,0.,0.,-1.,0.,0.,0.,0.,0.,1.,0.,1.25,-2.5,5.,1.]
 put(b,WORLD,layer['packrows']([world]));put(b,JOINTS,layer['packrows'](r['joints']));put(b,INVERSE,layer['packrows'](r['inverse']))
 w(b,H+0x168,len(r['joints']));w(b,H+0x174,INVERSE);w(b,H+0x190,len(r['layers']));w(b,H+0x194,LAYERS);put(b,H+0x1ac,struct.pack('<3f',*r['minimum']));put(b,H+0x1b8,struct.pack('<3f',*r['maximum']))
 handles={};ptr=ARRAYS
 def handle(h):
  if h is None:return 0
  key=h['identity']
  if key not in handles:
   at=HANDLES+len(handles)*12;handles[key]=at;w(b,at,ns['header']if h['scene']else 0);w(b,at+8,ns['special']if h['display']else 0)
  return handles[key]
 for i,l in enumerate(r['layers']):
  for key,off in [('rigid',4),('alternateRigid',12)]:
   if l[key]is not None:
    w(b,LAYERS+i*20+off,ptr)
    for h in l[key]:w(b,ptr,handle(h));ptr+=4
  for key,off in [('smooth',8),('alternateSmooth',16)]:w(b,LAYERS+i*20+off,handle(l[key]))
 assert ptr<HANDLES and HANDLES+len(handles)*12<MAP
 selected=list(range(len(r['layers'])))
 if mode==1:selected=list(reversed(selected))+[-1,len(selected),0,0]
 if mode==2:selected=None
 if mode==3:selected=[]
 if mode in [4,5,7]:selected=[i for i,l in enumerate(r['layers'])if l['smooth']is not None or l['alternateSmooth']is not None][:1]
 if selected is not None:put(b,MAP,struct.pack('<'+'h'*len(selected),*selected))
 if mode==7:
  for at in handles.values():w(b,at,0)
 count=len(selected)if selected is not None else 7
 morphs=[mp['WEIGHT']if weights is not None else 0 for i in range(max(count,1))]
 put(b,MORPHS,struct.pack('<'+'I'*len(morphs),*morphs))
 cached=[1,1,-1,1,0,1,-1][mode%7];o.update(forcedVisibility=cached,shadowMask=0xa5a5a5a5,skin=0,morph=0,mode=0)
 # Disabled character camera still runs original5da980 but deterministically
 # returns1, and leaves camera scratch unchanged. Enabled branch also tested.
 if mode==2:o['enabled']=0
 state=dict(world=[f.bits(x)for x in world],map=selected,count=count,morph=morphs,cached=cached,center=False)
 return b,o,r,weights,handles,state

def model(before,o,r,state,handles):
 b=bytearray(before);events=[];draws=[];visible=state['cached'];flag=o['shadowMask'];result=0
 world=[f.value(x)for x in state['world']]
 if visible==-1:
  visible,cm,pts,far=ns['bs']['classify'](r['minimum'],r['maximum'],world,o['view'],o['near'],o['far'],o['farOverride'],0.,o['sx'],o['sy'],o['enabled'])
  if o['enabled']:ns['storefloats'](b,ns['combined'],cm);ns['storefloats'](b,ns['farLanes'],far)
 if visible==0:return b,0,[],[],0
 def submit(h,matrix,mode,paletteAddress=0,palette=None,morph=0):
  nonlocal b,flag,result
  if h is None:return
  handle=handles[h['identity']]
  if not u(b,handle)or not u(b,handle+8):return
  raw=layer['packrows']([matrix]);events.append(dict(handle=handle,mode=mode,matrix=sha(raw),skin=paletteAddress,palette=sha(layer['packrows'](palette))if paletteAddress else None,morph=morph,cursor=u(b,ns['control']),visible=visible,flag=flag))
  put(b,ns['matrix'],raw);options=dict(o,handle=handle,matrix=ns['matrix'],forcedVisibility=visible,shadowMask=flag,skin=paletteAddress,morph=morph,mode=mode)
  ns['activeOptions']=options;mp['matrices']=layer['packrows'](palette)if palette is not None else b''
  b,ret,flag,emitted=ns['model'](b,options);draws.extend(emitted);result|=ret
 ids=[0]if state['map']is None and state['count']>0 else state['map'][:state['count']]
 for ordinal,index in enumerate(ids):
  if index<0 or index>=len(r['layers']):continue
  l=r['layers'][index];smooth=l['smooth']is not None or l['alternateSmooth']is not None;paletteAddress=0
  if smooth:paletteAddress=(u(b,ns['control'])+127)&~127;w(b,ns['control'],paletteAddress+len(r['joints'])*64)
  for key in ['rigid','alternateRigid']:
   if l[key]is not None:
    for j,h in enumerate(l[key]):
     if h is not None:submit(h,layer['multiply'](r['joints'][j],world),0)
  if smooth:
   palette=[layer['multiply'](a,c)for a,c in zip(r['inverse'],r['joints'])];put(b,paletteAddress,layer['packrows'](palette));submit(l['smooth'],world,2,paletteAddress,palette,state['morph'][ordinal]);submit(l['alternateSmooth'],world,2,paletteAddress,palette,state['morph'][ordinal])
 return b,result,events,draws,0

def original(before,o,r,state):
 global currentRig
 currentRig=r;n.write(D,before)
 for dst,src,size in [(0x9868a0,ns['shader'],420),(0x2857230,ns['scale'],64),(0x28571f0,ns['translation'],64),(0x280c480,ns['combined'],64),(0x80e8f0,ns['farLanes'],16)]:n.write(dst,before[src-D:src-D+size])
 for p,value in [(0x806ccc,state['cached']),(0x966384,0),(0x9738ec,o['forcedLod']),(0x9738f0,o['globalOverride']),(0x9738f4,o['overrideTable']),(0x9738a8,o['shadowMetadataDisabled']),(0x9715a0,o['shadowMask']),(0x2974d1c,o['filterMode']),(0x973890,o['overrideFirst']),(0x973894,0),(0x806b9c,o['overrideScalarWord']),(0x9736e0,ns['control']),(0x9738a4,0),(0x297dc00,0x12345678),(0x80e85c,o['enabled']),(0x297c0d0,0)]:n.pack('<I',p,value&0xffffffff)
 n.write(0x8264c4,b'\0');n.write(0x9739a8,b'\0');n.pack('<4I',0x80e258,*o['uv']);n.pack('<3f',0x973718,*o['camera']);n.pack('<16f',0x80b708,*o['view']);n.pack('<2f',0x973730,o['near'],o['far']);n.pack('<f',0x97374c,o['farOverride']);n.pack('<f',0x966378,o['sx']);n.pack('<f',0x97313c,o['sy'])
 nativeLayers.clear();ns['draws'].clear();ns['writers'].clear();ns['calls'].clear();mp['events'].clear();mp['calls'].clear()
 result=n.call(0x5f4ff0,[H,WORLD,state['count'],MAP if state['map']is not None else 0,JOINTS,MORPHS,0],count=100000000)
 actual=bytearray(n.read(D,SIZE))
 for dst,src,size in [(ns['shader'],0x9868a0,420),(ns['scale'],0x2857230,64),(ns['translation'],0x28571f0,64),(ns['combined'],0x280c480,64),(ns['farLanes'],0x80e8f0,16)]:put(actual,dst,n.read(src,size))
 return actual,dict(result=result,cached=n.unpack('<i',0x806ccc)[0],flag=n.unpack('<I',0x9715a0)[0],cursor=u(actual,ns['control']),layers=nativeLayers.copy(),draws=[d+[writer]for d,writer in zip(ns['draws'],ns['writers'])],events=mp['events'].copy())

cases=[];errors=[];counts=collections.Counter();usedRigs=set()
def execute(mi,index,mode):
 global currentRig
 b,o,r,weights,handles,state=setup(mi,index,mode);mesh=mp['meshes'][mi];g['currentMesh']=mesh;g['currentWeights']=weights;mp['current']=mesh;g['expectedEvents'].clear();want,ret,layers,draws,flag=model(b,o,r,state,handles);expectedEvents=g['expectedEvents'].copy()
 n.write(mp['BASEVERTEX'],mesh['vertices']);at=mp['DELTA']
 for delta in mesh['deltas']:
  if delta is not None:n.write(at,delta);at+=len(delta)+16
 got,actual=original(b,o,r,state)
 for p,size in [(ns['cache'],32),(ns['matrix'],64)]:put(want,p,bytes(size));put(got,p,bytes(size))
 expected=dict(result=ret&0xffffffff,cached=state['cached'],flag=flag,cursor=u(want,ns['control']),layers=layers,draws=draws,events=expectedEvents)
 if actual!=expected or got!=want:
  error=dict(mesh=mi,mode=mode,expected=expected,actual=actual,offsets=[i for i,(a,c)in enumerate(zip(got,want))if a!=c][:30]);errors.append(error);(R/'animation-character-packets-debug.json').write_text(json.dumps(error,indent=2));print('Differences:',error['offsets'],[k for k in expected if expected[k]!=actual[k]]);raise AssertionError('Chain mismatch')
 assert mp['ARENA']<=actual['cursor']<HIGH
 actual['sha256']=sha(got);cases.append(dict(mesh=mi,rig=byPath[mesh['source']['path']],index=index,mode=mode,state=state,options=o,handles=handles,beforeZ=base64.b64encode(gzip.compress(bytes(b),mtime=0)).decode(),native=actual))
 usedRigs.add(byPath[mesh['source']['path']]);counts['cases']+=1;counts['layerDraws']+=len(layers);counts['packets']+=len(draws);counts['skinPackets']+=sum(d[2]==0x5e0390 for d in draws);counts['ordinaryPackets']+=sum(d[2]==0x5e0200 for d in draws);counts['prefixPackets']+=sum(d[2]==0x5e02b0 for d in draws);counts['locks']+=len(expectedEvents)//2;counts['noLayerDraws']+=int(not layers);counts['visibilityQueries']+=state['cached']==-1

# Each selected authored mesh is matched to its exact source skeleton;
# one full layer topology case per rig plus focused extra branch scenarios.
seen=set();limit=int(os.environ.get('CHARACTER_PACKET_LIMIT','0'))
for mi,mesh in enumerate(mp['meshes']):
 if 'path'not in mesh['source']:continue
 path=mesh['source']['path'];ri=byPath[path]
 if path not in seen:
  seen.add(path);execute(mi,len(cases),0)
  if len(seen)%50==0:print('rigs',len(seen),'cases',len(cases),flush=True)
  if len(seen)<=24:
   for mode in [1,2,3,4,5,6,7]:execute(mi,len(cases),mode)
 if path in seen and mi+1==len(mp['meshes']):print('character mesh',mi,'rigs',len(seen),'cases',len(cases),flush=True)
 if limit and len(seen)>=limit:break
payload=[]
for r in rigs:payload.append(dict(r,joints=[[f.bits(v)for v in a]for a in r['joints']],inverse=[[f.bits(v)for v in a]for a in r['inverse']],minimum=[f.bits(v)for v in r['minimum']],maximum=[f.bits(v)for v in r['maximum']]))
fp=R/'animation-character-packets-native-fixtures.json.gz';doc=dict(binarySha256=n.sha256,rigs=payload,meshFixture=dict(path=str(mp['fixturePath'].relative_to(B)),sha256=sha(mp['fixturePath'].read_bytes())),addresses={k:ns[k]for k in ['control','shader','scale','translation','cache','output','matrix','combined','farLanes']},cases=cases);fp.write_bytes(gzip.compress(json.dumps(doc,separators=(',',':')).encode(),mtime=0))
dependencies=['tools/geometry-dynamic-skin-native.py','tools/geometry-dynamic-submission-native.py','tools/animation-morph-packets-verify.py','tools/animation-layer-submission-verify.py',rigFixture,'reports/geometry-dynamic-submission-fixtures.json.gz',str(mp['fixturePath'].relative_to(B))]
report=dict(binarySha256=n.sha256,d3dx=dll,comparisons=len(cases),counts=dict(counts),authoredRigs=len(usedRigs),mismatches=0,fixture=dict(path=str(fp.relative_to(B)),bytes=fp.stat().st_size,sha256=sha(fp.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Original5f4ff0 ->5da980 ->5f0f00 -> material/shader helpers ->5e0530 -> ordinary/prefix/skin/morph writers. Original D3DX matrix code, original shadow producer globally disabled; only successful COM virtualLock/Unlock supplied. Independent models compare every persistent1MiB byte except32B transient packet scratch and64B host matrix scratch, shared cache/flags/cursor, draw order/palette hashes and COM events.',limits=['Authored bind matrices, full layer topology and source-matched skin mesh descriptors; controlled relocated scene/material bindings intentionally route each valid layer handle to the selected source mesh. This does not establish original per-layer mesh association.','Finite scalar camera/math, valid disjoint memory, successful buffer locking, no secondary visibility/dynamic shadows/sway/fade/billboard.','No live animation scheduler, graphics-device draw, or managed executable launch. Managed equivalence remains pending.'])
(R/'animation-character-packets-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
