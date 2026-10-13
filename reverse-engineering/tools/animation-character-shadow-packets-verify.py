"""Original character layers -> secondary masks -> normal/shadow skin packets."""
from pathlib import Path
import ast,struct,json,gzip,base64,hashlib,collections,os
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def sha(b):return hashlib.sha256(b).hexdigest()
path=B/'tools/animation-character-packets-verify.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id=='cases'for v in node.targets):break
 nodes.append(node)
c={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),c)
n=c['n'];D=c['D'];SIZE=c['SIZE'];ns=c['ns'];g=c['g'];mp=c['mp'];f=c['f'];u=c['u'];w=c['w'];put=c['put'];MASKS=D+0x10000;CONTEXTS=[D+0x11000,D+0x16000];CACHE=D+0x1b000
# Reuse the independent shadow scheduler's arithmetic and packet composition.
# Its packet evaluator is the already recovered skin/morph-aware adapter.
shadowPath=B/'tools/geometry-dynamic-shadow-native.py';sh=dict(ns=ns,D=D,u=u,w=w,f32=ns['f32'],floats=ns['floats'],storefloats=ns['storefloats'],x=ns['x87'],MASKS=MASKS,expectedRecords=[])
for node in ast.parse(shadowPath.read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['planeDistance','secondary','shadowShader','model']:
  text=ast.get_source_segment(shadowPath.read_text(),node)
  if node.name=='model':text=text.replace('0x5e02b0 if prefix else 0x5e0200',"0x5e0390 if o['skin'] else 0x5e02b0 if prefix else 0x5e0200")
  exec(compile(text,'character-shadow-'+node.name,'exec'),sh)
expectedPacketRecords=[]
def dynamicModel(before,options):
 try:result=sh['model'](before,options)
 except Exception as error:
  tb=error.__traceback__
  while tb:
   values=tb.tb_frame.f_locals;print(tb.tb_frame.f_code.co_name,{k:hex(values[k])for k in ['record','material','ci','cmd','owner','context','modelAddress']if isinstance(values.get(k),int)},'cursor',hex(u(values['b'],ns['control']))if 'b'in values else'',flush=True);tb=tb.tb_next
  raise
 expectedPacketRecords.extend(sh['expectedRecords']);return result
ns['model']=dynamicModel;c['shadow']=sh;c['MASKS']=MASKS
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['model','original']:
  text=ast.get_source_segment(path.read_text(),node)
  if node.name=='model':
   text=text.replace('if visible==0:return b,0,[],[],0',"secondary=0\n if o['shadowCount']>0:secondary,flag=shadow['secondary'](b,o,ns['bs']['points'](r['minimum'],world),ns['bs']['points'](r['maximum'],world),0)\n if visible==0 and secondary==0:return b,0,[],[],0")
  else:
   text=text.replace('(0x966384,0)',"(0x966384,o['shadowCount'])")
   text=text.replace('nativeLayers.clear();',"n.pack('<8I',0x96e550,*o['initialMasks'])\n for i,p in enumerate(o['shadowContexts']):n.pack('<I',0x96d9d0+i*4,p)\n nativeLayers.clear();")
   text=text.replace('actual=bytearray(n.read(D,SIZE))',"actual=bytearray(n.read(D,SIZE));put(actual,MASKS,n.read(0x96e550,32))")
  exec(compile(text,'integrated-character-'+node.name,'exec'),c)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESI
observedRecords=[];nativeCalls=[]
def observe(mu,address,size,user):
 nativeCalls.append(address)
 if address==0x5e0530:observedRecords.append(mu.reg_read(UC_X86_REG_ESI))
for a in [0x5ea6a0,0x5c6dc0,0x607820,0x5e0530]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
cases=[];counts=collections.Counter();rigs=set();errors=[]
def execute(mi,index,mode):
 print('case',index,'mesh',mi,'mode',mode,flush=True)if os.environ.get('CHARACTER_SHADOW_DEBUG')else None
 b,o,r,weights,handles,state=c['setup'](mi,index,5 if mode==5 else 1 if mode==6 else 0);mesh=mp['meshes'][mi]
 visible=[1,0,-1,0,1,0,1,0][mode];state['cached']=visible;o['forcedVisibility']=visible
 o.update(shadowCount=0 if mode==7 else 1 if mode==5 else 2,shadowContexts=[]if mode==7 else CONTEXTS[:1]if mode==5 else CONTEXTS,initialMasks=[0xa5a5a5a5]*8,shadowMask=[0,1,0x80000000,0xffffffff][index%4],descriptor=0);state['secondaryCount']=o['shadowCount']
 b[ns['flags']-D+3]=0x20 if mode!=4 else 0;o['shadowMetadataDisabled']=int(index%19==0)
 for i,material in enumerate(ns['materials']):w(b,material+0x40,((i+index)%4)<<14);b[material-D+0x268]=(i+index)&1
 cache=CACHE
 for ci,context in enumerate(o['shadowContexts']):
  volumeCount=1 if mode==5 else 3 if ci else 4;put(b,context,bytes(0x4000));w(b,context+0x710,volumeCount)
  for vi in range(volumeCount):
   planes=[[0.,0.,0.,-1.]]if mode==3 or vi==1 else []if vi==0 else [[1.,0.,0.,64.]]if vi==2 else [[0.,1.,0.,-128.]]
   w(b,context+vi*0x380+0x260,len(planes))
   for pi,plane in enumerate(planes):put(b,context+vi*0x380+0x1a0+pi*16,struct.pack('<4f',*plane))
   for alternate in [0,1]:
    record=context+vi*0x380+0x2a4+alternate*0x44;w(b,record,0x12345678);w(b,record+4,0);w(b,record+8,cache);w(b,record+0x14,cache+0x40);w(b,record+0x18,cache+0x60);w(b,cache+0x20,index^0xffffffff);struct.pack_into('<H',b,cache-D+0x30,(index+vi+alternate)&65535);cache+=0x100
 for i,v in enumerate(o['initialMasks']):w(b,MASKS+i*4,v)
 assert cache<D+0x20000
 g['currentMesh']=mesh;g['currentWeights']=weights;mp['current']=mesh;g['expectedEvents'].clear();expectedPacketRecords.clear();want,ret,layers,draws,flag=c['model'](b,o,r,state,handles);expectedEvents=g['expectedEvents'].copy()
 n.write(mp['BASEVERTEX'],mesh['vertices']);at=mp['DELTA']
 for delta in mesh['deltas']:
  if delta is not None:n.write(at,delta);at+=len(delta)+16
 observedRecords.clear();nativeCalls.clear();got,actual=c['original'](b,o,r,state)
 for p,size in [(ns['cache'],32),(ns['matrix'],64)]:put(want,p,bytes(size));put(got,p,bytes(size))
 expected=dict(result=ret&0xffffffff,cached=state['cached'],flag=flag,cursor=u(want,ns['control']),layers=layers,draws=draws,events=expectedEvents)
 if actual!=expected or got!=want or observedRecords!=expectedPacketRecords:
  error=dict(mesh=mi,mode=mode,expected=expected,actual=actual,offsets=[i for i,(a,v)in enumerate(zip(got,want))if a!=v][:50]);(R/'animation-character-shadow-packets-debug.json').write_text(json.dumps(error,indent=2));print('mismatch',error['offsets'],[k for k in expected if expected[k]!=actual[k]]);raise AssertionError('Character shadow chain mismatch')
 assert mp['ARENA']<=actual['cursor']<c['HIGH'];actual.update(sha256=sha(got),records=observedRecords.copy());cases.append(dict(mesh=mi,rig=c['byPath'][mesh['source']['path']],index=index,mode=mode,state=state,options=o,handles=handles,beforeZ=base64.b64encode(gzip.compress(bytes(b),mtime=0)).decode(),native=actual))
 rigs.add(c['byPath'][mesh['source']['path']]);counts['cases']+=1;counts['layerDraws']+=len(layers);counts['packets']+=len(draws);counts['skinPackets']+=sum(d[2]==0x5e0390 for d in draws);counts['shadowPackets']+=sum(p not in ns['records']for p in observedRecords);counts['secondaryCalls']+=nativeCalls.count(0x5ea6a0);counts['volumeTests']+=nativeCalls.count(0x5c6dc0);counts['shadowShaderCalls']+=nativeCalls.count(0x607820);counts['locks']+=len(expectedEvents)//2;counts['zeroReturnWithPackets']+=int(ret==0 and bool(draws));counts['noLayerDraws']+=int(not layers)
seen=set();limit=int(os.environ.get('CHARACTER_SHADOW_LIMIT','0'))
for mi,mesh in enumerate(mp['meshes']):
 if 'path'not in mesh['source']or mesh['source']['path']in seen:continue
 seen.add(mesh['source']['path']);execute(mi,len(cases),0)
 if len(seen)<=24:
  for mode in range(1,8):execute(mi,len(cases),mode)
 if len(seen)%25==0:print('rigs',len(seen),'checks',len(cases),flush=True)
 if limit and len(seen)>=limit:break
payload=[dict(r,joints=[[f.bits(v)for v in a]for a in r['joints']],inverse=[[f.bits(v)for v in a]for a in r['inverse']],minimum=[f.bits(v)for v in r['minimum']],maximum=[f.bits(v)for v in r['maximum']])for r in c['rigs']]
fp=R/'animation-character-shadow-packets-native-fixtures.json.gz';doc=dict(binarySha256=n.sha256,rigs=payload,meshFixture=dict(path=str(mp['fixturePath'].relative_to(B)),sha256=sha(mp['fixturePath'].read_bytes())),addresses={k:ns[k]for k in ['control','shader','scale','translation','cache','output','matrix','combined','farLanes']},maskMirror=MASKS,cases=cases);fp.write_bytes(gzip.compress(json.dumps(doc,separators=(',',':')).encode(),mtime=0))
dependencies=['tools/animation-character-packets-verify.py','tools/geometry-dynamic-shadow-native.py','tools/geometry-dynamic-skin-native.py','tools/geometry-dynamic-submission-native.py',str(mp['fixturePath'].relative_to(B)),'reports/animation-layer-submission-native-fixtures.json.gz']
report=dict(binarySha256=n.sha256,d3dx=c['dll'],comparisons=len(cases),counts=dict(counts),authoredRigs=len(rigs),mismatches=0,fixture=dict(path=str(fp.relative_to(B)),bytes=fp.stat().st_size,sha256=sha(fp.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in dependencies],method='Actual original5f4ff0 through secondary predicates, full5f0f00 normal/shadow scheduler, both shader emitters, real skin/morph/ordinary/prefix packet writers and original D3DX matrix code. Only successful COM Lock/Unlock supplied. Every persistent1MiB byte including mirrored masks compared, excluding32B packet scratch and64B host matrix scratch; layer entry palette/matrix hashes, cursor/flags, packet order and COM events agree.',limits=['Controlled relocated handles bind full authored layer topology to one source-matched mesh; exact shipped layer-to-mesh loader association remains unproven.','Finite scalar valid state; shadow contexts/planes are controlled fixtures, not original volume producers.','Billboard, sway, fade, material merge and active character shadow-queue production remain separate.','No GPU/live scheduler or managed executable launch.'])
(R/'animation-character-shadow-packets-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
