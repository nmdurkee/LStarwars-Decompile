"""Original character legacy queue before full normal/shadow packet draws."""
from pathlib import Path
import ast,json,gzip,struct,base64,hashlib,collections,os
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def sha(b):return hashlib.sha256(b).hexdigest()
path=B/'tools/animation-character-shadow-packets-verify.py';source=path.read_text();nodes=[]
for node in ast.parse(source).body:
 if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id=='cases'for v in node.targets):break
 nodes.append(node)
s={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),s)
c=s['c'];n=s['n'];D=s['D'];f=s['f'];ns=s['ns'];mp=s['mp'];g=s['g'];put=s['put'];w=s['w'];u=s['u'];SIZE=s['SIZE'];QUEUE=0x9666b0;QUEUE_SIZE=280*104;BINDINGS=D+0x1f000
bindingPath=R/'animation-shadow-queue-native-fixtures.json.gz';bindingDoc=json.loads(gzip.decompress(bindingPath.read_bytes()));bindingByPath={r['source']['path']:r for r in bindingDoc['rigs']if 'path'in r['source']}
for r in c['rigs']:
 bound=bindingByPath[r['source']['path']];assert bound['source']['sha256']==r['source']['sha256'];r['bindings']=bound['bindings']
q={'f':f,'struct':struct,'SIZE':QUEUE_SIZE,'sha':sha,'rigs':c['rigs']}
qpath=B/'tools/animation-shadow-queue-verify.py'
for node in ast.parse(qpath.read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['matrixbytes','multiply','model']:exec(compile(ast.Module(body=[node],type_ignores=[]),'queue-model','exec'),q)
queueCalls=[];drawQueue=[];expectedQueue=None;currentQueue=None
def snapshot():return dict(count=n.unpack('<i',0x973fe8)[0],sequence=n.unpack('<I',0x973fdc)[0],flag=n.unpack('<I',0x9718a4)[0],queueSha256=sha(n.read(QUEUE,QUEUE_SIZE)))
def emptySnapshot(v):return dict(count=v['count'],sequence=v['sequence'],flag=v['flag'],queueSha256=sha(b'\xa5'*QUEUE_SIZE),calls=[])
def initializeQueue():
 v=currentQueue;n.write(QUEUE,b'\xa5'*QUEUE_SIZE)
 for p,value in [(0x973fe8,v['count']),(0x973fdc,v['sequence']),(0x9718a4,v['flag']),(0x8264bc,v['mode']),(0x80babc,v['submissionEnabled'])]:n.pack('<I',p,value&0xffffffff)
 n.write(0x8264c4,bytes([v['enabled']]));n.pack('<4I',0x2854bf4,*v['parameters']);n.pack('<2I',0x973fe0,*v['distances']);queueCalls.clear();drawQueue.clear()
def predictQueue(r,state):
 global expectedQueue
 expectedQueue=q['model'](c['byPath'][r['source']['path']],dict(currentQueue,world=[f.value(v)for v in state['world']]))
c['initializeQueue']=initializeQueue;c['predictQueue']=predictQueue
# Recompile only our Python fixture/model with queue initialization enabled.
# All original executable bytes and computational native callees remain intact.
basePath=B/'tools/animation-character-packets-verify.py';base=basePath.read_text()
for node in ast.parse(base).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['model','original']:
  text=ast.get_source_segment(base,node)
  if node.name=='model':
   text=text.replace('if visible==0:return b,0,[],[],0',"secondary=0\n if o['shadowCount']>0:secondary,flag=shadow['secondary'](b,o,ns['bs']['points'](r['minimum'],world),ns['bs']['points'](r['maximum'],world),0)\n if visible==0 and secondary==0:return b,0,[],[],0\n predictQueue(r,state)")
  else:
   text=text.replace('(0x966384,0)',"(0x966384,o['shadowCount'])").replace("n.write(0x8264c4,b'\\0')",'initializeQueue()')
   text=text.replace('nativeLayers.clear();',"n.pack('<8I',0x96e550,*o['initialMasks'])\n for i,p in enumerate(o['shadowContexts']):n.pack('<I',0x96d9d0+i*4,p)\n nativeLayers.clear();")
   text=text.replace('actual=bytearray(n.read(D,SIZE))',"actual=bytearray(n.read(D,SIZE));put(actual,MASKS,n.read(0x96e550,32))")
  exec(compile(text,'queue-character-'+node.name,'exec'),c)
from unicorn import UC_HOOK_CODE
def observe(mu,address,size,user):
 if address==0x5f0f00:drawQueue.append(snapshot())
 else:queueCalls.append(address)
for address in [0x5f9fa0,0x5f9ed0,0x5f0f00]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
def prepareQueue(b,o,r,state,index,kind):
 global currentQueue,expectedQueue
 currentQueue=dict(count=137,sequence=[0,255,0xffffffff,0xfffffffe][index%4],flag=0xa5a5a5a5,enabled=1,mode=1,submissionEnabled=1,parameters=[0x81234567,0xabcdef01,0xff123456,((index%256)<<24)|0x765432],distances=[f.bits(-0. if index%2 else 0.),f.bits(float(index+100))],suppress=0)
 if kind=='empty':currentQueue['count']=0
 if kind=='near-full':currentQueue['count']=279
 if kind=='full':currentQueue['count']=280
 if kind=='disabled':currentQueue['enabled']=0
 if kind=='wrong-mode':currentQueue['mode']=-1
 if kind=='suppressed':currentQueue['suppress']=128
 if kind=='submission-disabled':currentQueue['submissionEnabled']=0
 if kind=='no-layers':state.update(map=[],count=0)
 if kind=='null-bindings':currentQueue['nullBindings']=True
 bindings=None if currentQueue.get('nullBindings')else r['bindings']
 w(b,c['H']+0x19c,BINDINGS if bindings is not None else 0);b[c['H']-D+0x1a0]=currentQueue['suppress']
 if bindings is not None:
  assert len(bindings)*16<0x1000;put(b,BINDINGS,b''.join(struct.pack('<3I4B',*v)for v in bindings))
 expectedQueue=emptySnapshot(currentQueue)
def verifyQueue(layers):
 actual=snapshot();expected={k:v for k,v in expectedQueue.items()if k!='calls'}
 calls=[a for a in expectedQueue['calls']if a in [0x5f9fa0,0x5f9ed0]]
 if actual!=expected or queueCalls!=calls or drawQueue!=[expected]*len(layers):raise AssertionError(dict(expected=expected,actual=actual,calls=queueCalls,wantedCalls=calls,drawCount=len(drawQueue),layerCount=len(layers)))
 return dict(actual,calls=queueCalls.copy(),beforeDraw=drawQueue.copy())
# Reuse the established full shadow fixture, adding exact source bindings and
# queue state before both evaluations, then checking it before every real draw.
for node in ast.parse(source).body:
 if isinstance(node,ast.FunctionDef)and node.name=='execute':
  text=ast.get_source_segment(source,node).replace('def execute(mi,index,mode):','def execute(mi,index,mode,kind):')
  text=text.replace('g[\'currentMesh\']=mesh;',"prepareQueue(b,o,r,state,index,kind)\n g['currentMesh']=mesh;")
  text=text.replace("actual.update(sha256=sha(got),records=observedRecords.copy())","actual.update(sha256=sha(got),records=observedRecords.copy(),queue=verifyQueue(layers))")
  text=text.replace('index=index,mode=mode,state=state','index=index,mode=mode,kind=kind,queue=dict(currentQueue),state=state')
  text=text.replace("counts['cases']+=1;","counts['cases']+=1;counts['queueEnqueues']+=queueCalls.count(0x5f9ed0);counts['queueCalled']+=queueCalls.count(0x5f9fa0);counts['queueBeforeDrawChecks']+=len(drawQueue);counts['kind:'+kind]+=1;counts['activeBoundCases']+=int(queueCalls.count(0x5f9ed0)>0);")
  text=text.replace("'animation-character-shadow-packets-debug.json'","'animation-character-queue-packets-debug.json'")
  s.update(prepareQueue=prepareQueue,verifyQueue=verifyQueue,currentQueue=currentQueue,queueCalls=queueCalls,drawQueue=drawQueue)
  # currentQueue is rebound each setup; expose an accessor in saved fixture.
  text=text.replace('queue=dict(currentQueue)','queue=dict(getCurrentQueue())')
  s['getCurrentQueue']=lambda:currentQueue
  exec(compile(text,'queue-packet-execute','exec'),s)
s.update(cases=[],counts=collections.Counter(),rigs=set(),errors=[])
seen=set();boundUsed=set();limit=int(os.environ.get('CHARACTER_QUEUE_LIMIT','0'))
for mi,mesh in enumerate(mp['meshes']):
 sourcePath=mesh['source'].get('path')
 if not sourcePath or sourcePath in seen:continue
 seen.add(sourcePath);s['execute'](mi,len(s['cases']),0,'populated')
 ri=c['byPath'][sourcePath]
 if c['rigs'][ri]['bindings']is not None:
  boundUsed.add(sourcePath)
  for kind in ['empty','near-full','full','disabled','wrong-mode','suppressed','submission-disabled','no-layers','culled','secondary-only']:
   s['execute'](mi,len(s['cases']),3 if kind=='culled'else 1 if kind=='secondary-only'else 0,kind)
 if len(seen)%25==0:print('rigs',len(seen),'bound',len(boundUsed),'checks',len(s['cases']),flush=True)
 if limit and len(seen)>=limit:break
payload=[dict(r,joints=[[f.bits(v)for v in a]for a in r['joints']],inverse=[[f.bits(v)for v in a]for a in r['inverse']],minimum=[f.bits(v)for v in r['minimum']],maximum=[f.bits(v)for v in r['maximum']])for r in c['rigs']]
fp=R/'animation-character-queue-packets-native-fixtures.json.gz';doc=dict(binarySha256=n.sha256,rigs=payload,meshFixture=dict(path=str(mp['fixturePath'].relative_to(B)),sha256=sha(mp['fixturePath'].read_bytes())),addresses={k:ns[k]for k in ['control','shader','scale','translation','cache','output','matrix','combined','farLanes']},maskMirror=s['MASKS'],cases=s['cases']);fp.write_bytes(gzip.compress(json.dumps(doc,separators=(',',':')).encode(),mtime=0))
dependencies=['tools/animation-character-shadow-packets-verify.py','tools/animation-character-packets-verify.py','tools/animation-shadow-queue-verify.py',str(bindingPath.relative_to(B)),str(mp['fixturePath'].relative_to(B))]
report=dict(binarySha256=n.sha256,d3dx=c['dll'],comparisons=len(s['cases']),counts=dict(s['counts']),authoredRigs=len(seen),authoredBoundRigs=len(boundUsed),authoredBindingGroups=sum(len(c['rigs'][c['byPath'][p]]['bindings'])-1 for p in boundUsed),bindingCatalogRigs=sum(r['bindings']is not None for r in bindingByPath.values()),mismatches=0,fixture=dict(path=str(fp.relative_to(B)),bytes=fp.stat().st_size,sha256=sha(fp.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Original5f4ff0 executes original legacy5f9fa0/5f9ed0 before actual normal/shadow dynamic packet calls. Original D3DX and packet writers execute; only successful COM Lock/Unlock is supplied. Entire persistent1MiB image plus entire29120-byte legacy queue, queue globals/call order, queue snapshot before every5f0f00 entry, layer/palette hashes, masks/cursor, packet order and COM events match independent models.',limits=['298 source-matched mesh rigs intersect42 of244 catalog rigs with shadow bindings;120 groups in that intersection. Exact shipped layer-to-mesh runtime loader association remains unproven; controlled handles route full authored topology to one source-matched mesh.','Queue initial populated slots contain preserved opaqueA5 bytes; this producer does not read or drain them. Shape pointers retain exact normalized authored offsets and are not dereferenced by this queue.','Finite scalar valid state; controlled shadow contexts and relocated scene/material records. Billboard/sway/fade have separate prior composition evidence and remain inactive in this sweep.','Two transient host-projection scratch regions remain excluded as in prior packet evidence. No graphics-device draw, queue drain, live scheduler or managed launch.'])
(R/'animation-character-queue-packets-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
