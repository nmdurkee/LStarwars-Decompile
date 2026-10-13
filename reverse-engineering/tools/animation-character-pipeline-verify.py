"""Original layer -> visibility -> shadow queue composition; draw boundary explicit."""
from pathlib import Path
import ast,json,gzip,struct,hashlib,collections,random,importlib.util
B=Path(__file__).resolve().parent.parent
def sha(b):return hashlib.sha256(b).hexdigest()
def load(path):return json.loads(gzip.decompress((B/path).read_bytes()))
# Reuse setup and independently checked layer model, stopping before its runner.
# Remove its hook registration so both visibility and shadows execute unchanged.
basePath=B/'tools/animation-layer-submission-verify.py';tree=ast.parse(basePath.read_text());prefix=[]
for node in tree.body:
 if isinstance(node,ast.For)and isinstance(node.target,ast.Name)and node.target.id=='seed':break
 if isinstance(node,ast.For):continue
 prefix.append(node)
layer={'__file__':str(basePath)};exec(compile(ast.Module(body=prefix,type_ignores=[]),str(basePath),'exec'),layer)
n=layer['n'];f=layer['f'];D=n.DATA;ARENA=layer['ARENA'];ARENA_SIZE=layer['ARENA_SIZE'];QUEUE=0x9666b0;SIZE=280*104;BINDINGS=D+0x80000
def extract(path,names,namespace):
 for node in ast.parse((B/path).read_text()).body:
  if isinstance(node,ast.FunctionDef)and node.name in names:exec(compile(ast.Module(body=[node],type_ignores=[]),path,'exec'),namespace)
visibility={'f':f,'struct':struct};extract('tools/animation-character-visibility-verify.py',['store','preprocess'],visibility)
spec=importlib.util.spec_from_file_location('pipeline_x87',B/'tools/animation-x87.py');x87=importlib.util.module_from_spec(spec);spec.loader.exec_module(x87)
bounds={'x87':x87,'IDENTITY':f.IDENTITY};extract('tools/geometry-dynamic-bounds-native.py',['dot','mul','points','classify'],bounds)
shadow={'f':f,'struct':struct,'SIZE':SIZE,'sha':sha};extract('tools/animation-shadow-queue-verify.py',['matrixbytes','multiply','model'],shadow)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
rigs=[];cases=[];errors=[];counts=collections.Counter();events=[];active=None
beforeMatrix=[f.f32(i*.25-2)for i in range(16)];beforeFar=[-3.,-2.,-1.,0.]
def observe(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);c=active
 if address==0x5da980:events.append(dict(kind='visibility'))
 elif address==0x5ea6a0:
  low,high,mode=n.unpack('<3I',sp+4);events.append(dict(kind='secondary',low=list(n.unpack('<3I',low)),high=list(n.unpack('<3I',high)),mode=mode));layer['ret'](mu,c['secondaryResult'])
 elif address==0x5f9fa0:events.append(dict(kind='attachments',visible=n.unpack('<i',0x806ccc)[0]))
 elif address==0x5f0f00:
  handle,matrix,mode,skin,morph=n.unpack('<5I',sp+4);h=layer['identities'][handle];r=layer['rig'];events.append(dict(kind='submit',handle=h['identity'],mode=mode,transformSha256=sha(n.read(matrix,64)),skinAddress=skin,skinSha256=sha(n.read(skin,len(r['joints'])*64))if skin else None,morph=morph,visible=n.unpack('<i',0x806ccc)[0],shadowCount=n.unpack('<i',0x973fe8)[0],shadowSequence=n.unpack('<I',0x973fdc)[0],shadowFlag=n.unpack('<I',0x9718a4)[0]));n.pack('<I',layer['CONTROL'],n.unpack('<I',layer['CONTROL'])[0]+((h['identity']%3)*16 if c['allocation']else 0));n.pack('<I',0x973fdc,(n.unpack('<I',0x973fdc)[0]+(h['identity']%5 if c['mutateShadowSequence']else 0))&0xffffffff);layer['ret'](mu,h['return'])
for a in[0x5da980,0x5ea6a0,0x5f9fa0,0x5f0f00]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def original(ri,c):
 global active
 active=c;r=rigs[ri];layer['setup'](r,c);sc=c['shadow'];n.write(QUEUE,b'\xa5'*SIZE);n.pack('<i',0x973fe8,sc['count']);n.pack('<I',0x973fdc,sc['sequence']);n.pack('<I',0x9718a4,sc['flag']);n.write(0x8264c4,bytes([sc['enabled']]));n.pack('<i',0x8264bc,sc['mode']);n.pack('<I',0x80babc,sc['submissionEnabled']);n.pack('<4I',0x2854bf4,*sc['parameters']);n.pack('<2I',0x973fe0,*sc['distances']);n.pack('<I',D+0x19c,BINDINGS if r['bindings']is not None else 0);n.write(D+0x1a0,bytes([sc['suppress']]))
 if r['bindings']is not None:n.write(BINDINGS,b''.join(struct.pack('<3I4B',*b)for b in r['bindings']))
 near,far,override,sx,sy,enabled=c['camera'];n.write(0x9739a8,bytes([int(c['center'])]));n.pack('<16f',0x80b708,*c['view']);n.pack('<2f',0x973730,near,far);n.pack('<f',0x97374c,override);n.pack('<f',0x966378,sx);n.pack('<f',0x97313c,sy);n.pack('<I',0x80e85c,enabled);n.pack('<I',0x297c0d0,0);n.pack('<16f',0x280c480,*beforeMatrix);n.pack('<4f',0x80e8f0,*beforeFar);events.clear()
 result=n.call(0x5f4ff0,[D,layer['WORLD'],c['count']&0xffffffff,layer['MAP']if c['map']is not None else 0,layer['JOINTS'],layer['WEIGHTS']if c['morph']is not None else 0,0],count=20000000);end=n.unpack('<I',layer['CONTROL'])[0];assert ARENA<=end<=ARENA+ARENA_SIZE
 return dict(result=result,cached=n.unpack('<i',0x806ccc)[0],flag=n.unpack('<I',0x9715a0)[0],cursor=end,arenaSha256=sha(n.read(ARENA,end-ARENA)),events=events.copy(),combined=list(n.unpack('<16I',0x280c480)),far=list(n.unpack('<4I',0x80e8f0)),shadow=dict(count=n.unpack('<i',0x973fe8)[0],sequence=n.unpack('<I',0x973fdc)[0],flag=n.unpack('<I',0x9718a4)[0],queueSha256=sha(n.read(QUEUE,SIZE))))
def model(ri,c):
 r=rigs[ri];state=dict(c);combined=beforeMatrix;farLanes=beforeFar
 if c['cached']==-1:
  low,high,world=visibility['preprocess'](r['minimum'],r['maximum'],c['world'],r['joints'][0] if r['joints'] else None,c['center']);near,far,override,sx,sy,enabled=c['camera'];resolved,mat,pts,far4=bounds['classify'](low,high,world,c['view'],near,far,override,0.,sx,sy,enabled);state['resolved']=resolved
  if enabled:combined=mat;farLanes=far4
 else:state['resolved']=c['cached']
 base=layer['model'](r,state);base.pop('calls');shadowState=dict(c['shadow'],world=c['world']);attached=any(e['kind']=='attachments'for e in base['events'])
 if attached:s=shadow['model'](ri,shadowState);s.pop('calls')
 else:s=dict(count=shadowState['count'],sequence=shadowState['sequence'],flag=shadowState['flag'],queueSha256=sha(b'\xa5'*SIZE))
 for e in base['events']:
  if e['kind']=='submit':
   e.update(shadowCount=s['count'],shadowSequence=s['sequence'],shadowFlag=s['flag'])
   if c['mutateShadowSequence']:s['sequence']=(s['sequence']+e['handle']%5)&0xffffffff
 base.update(combined=[f.bits(x)for x in combined],far=[f.bits(x)for x in farLanes],shadow=s);return base
def check(kind,ri,c):
 got=original(ri,c);want=model(ri,c);counts[kind]+=1;counts['culled'if not any(e['kind']=='attachments'for e in got['events'])else'submitted']+=1
 if got!=want:
  counts['mismatches']+=1
  if len(errors)<10:errors.append(dict(rig=ri,state=c,expected=want,native=got))
 cases.append(dict(kind=kind,rig=ri,state=c,native=got))
layerFixture='reports/animation-layer-submission-native-fixtures.json.gz';shadowFixture='reports/animation-shadow-queue-native-fixtures.json.gz';visibilityFixture='reports/animation-character-visibility-native-fixtures.json.gz'
sourceRigs=load(layerFixture)['rigs'];shadowRigs={r['source']['path']:r for r in load(shadowFixture)['rigs']if'path'in r['source']};views=[]
for c in load(visibilityFixture)['cases']:
 v=c['state']['view']
 if v not in views:views.append(v)
for r in sourceRigs:
 for key in['joints','inverse']:r[key]=[[f.value(v)for v in row]for row in r[key]]
 for key in['minimum','maximum']:r[key]=[f.value(v)for v in r[key]]
 if'path'in r['source']:r['bindings']=shadowRigs[r['source']['path']]['bindings']
 else:r['bindings']=[[0x11110000,0x22220000,0x33330000,1,2,3,0],[0,0,0,0,0,0,255]]if r['joints']else None
 rigs.append(r)
layer['rigs']=rigs;shadow['rigs']=rigs
for ri,r in enumerate(rigs):
 for mode in range(8):
  c=layer['context'](r,mode%3);c.update(center=bool(mode%2),camera=[f.f32(.1),1000.,0.,1.,.75,1],view=[f.value(x)for x in views[mode%len(views)]],cached=-1,secondaryCount=0,secondaryResult=1,mutateShadowSequence=bool(mode%2));c['world']=f.IDENTITY.copy();c['world'][12:15]=[0.,0.,5.]
  if not r['joints']:c['center']=False
  if mode==1:c['camera'][-1]=0 # Native disabled classifier returns1 and keeps scratch.
  if mode==2:c['cached']=1 # Cached visibility bypasses the camera entirely.
  if mode==3:c.update(cached=0,secondaryCount=1) # Secondary-only submission still queues shadows.
  if mode==4:c.update(cached=0,secondaryCount=0) # Early cull leaves all shadow state untouched.
  if mode==5:c.update(count=0) # Attachments precede layer selection even with no selected layers.
  if mode==6:c['world'][12]=100000.;c['camera'][3]=.01
  if mode==7:c.update(secondaryCount=1,allocation=True)
  c['shadow']=dict(count=[0,279,278,0,0,0,280,0][mode],sequence=0xfffffffe,flag=0xa5a5a5a5,enabled=0 if mode==7 and ri%2 else 1,mode=1,submissionEnabled=1,parameters=[0x12345678,0x81234567,0xabcdef01,0x807f0102],distances=[f.bits(-0.),f.bits(100.)],suppress=0)
  check('authored'if'path'in r['source']else'synthetic',ri,c)
 if (ri+1)%100==0:print(ri+1,'rigs;',counts['mismatches'],'mismatches',flush=True)
payload=[]
for r in rigs:payload.append(dict(r,joints=[[f.bits(v)for v in m]for m in r['joints']],inverse=[[f.bits(v)for v in m]for m in r['inverse']],minimum=[f.bits(v)for v in r['minimum']],maximum=[f.bits(v)for v in r['maximum']]))
for c in cases:
 for key in['world','view']:c['state'][key]=[f.bits(v)for v in c['state'][key]]
 c['state']['camera']=[f.bits(v)for v in c['state']['camera'][:-1]]+[c['state']['camera'][-1]]
out=B/'reports/animation-character-pipeline-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,arena=ARENA,arenaSize=ARENA_SIZE,beforeMatrix=[f.bits(v)for v in beforeMatrix],beforeFar=[f.bits(v)for v in beforeFar],rigs=payload,cases=cases),separators=(',',':')).encode(),mtime=0))
dependencies=[layerFixture,shadowFixture,visibilityFixture,'tools/animation-layer-submission-verify.py','tools/animation-shadow-queue-verify.py','tools/animation-character-visibility-verify.py','tools/geometry-dynamic-bounds-native.py','tools/animation-skeletal-fixture.py']
report=dict(binarySha256=n.sha256,d3dx=layer['dll'],comparisons=len(cases),counts=dict(counts),mismatches=counts['mismatches'],examples=errors,fixture=dict(path=out.relative_to(B).as_posix(),bytes=out.stat().st_size,sha256=sha(out.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Original 5f4ff0 ->5da980/6042e0 ->5f9fa0/5f9ed0 and all matrix helpers run together unchanged. Secondary visibility5ea6a0 and draw5f0f00 remain explicit test adapters. Draw callbacks observe queue state before mutating sequence and allocator. Verify ordered callbacks, palettes, arena contents/cursor, restored cache, submission flags, camera scratch and full shadow queue.',limits=['Finite scalar camera and original D3DX9_35 matrix policy; immutable authored hierarchy/joint inputs.','Draw callbacks are bounded observation/return/allocator/sequence effects, not a claim of full dynamic renderer/GPU behavior.','Secondary5ea6a0 remains external. Corner arrays are stack-local diagnostics and are not claimed as persistent after later native calls.','No live actor scheduling or final engine integration.'])
(B/'reports/animation-character-pipeline-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k not in['d3dx','dependencies','method','limits']},indent=2));assert counts['mismatches']==0

