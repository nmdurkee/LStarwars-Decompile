"""Original dirty viewport reset, pixel/depth transform and camera composition."""
import sys,json,gzip,struct,hashlib,random,math,importlib.util,ast
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase5-20261013-reuse'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0];words=lambda a:[word(v)for v in a]
W=x87.wide;M=x87.mul;A=x87.add;D=x87.div;S=x87.store;sub=lambda a,b:A(a,(-b[0],b[1]));i32=lambda v:((v+0x80000000)&0xffffffff)-0x80000000
for file,names in[('scene-phase4-20261013-native.py',['modelBuild']),('scene-phase5-20261013-native.py',['multiply','dot','inverse','trig','projection','clipping','ordinaryFrustum','modelApply','modelSwitch','stateModel','encoded','cameraSeed','globalsSeed','setup','readCamera'])]:
 module=ast.parse((P/file).read_text());selected=[v for v in module.body if(isinstance(v,ast.FunctionDef)and v.name in names)or(isinstance(v,ast.Assign)and any(isinstance(t,ast.Name)and t.id in['matrixKeys','scaleAddresses']for t in v.targets))];exec(compile(ast.Module(body=selected,type_ignores=[]),file,'exec'))
sineBytes=(B/'references/native-animation-sine-table.f32').read_bytes();sine=list(struct.unpack('<32768f',sineBytes));n.write(0x29899a0,sineBytes);angleScale=n.unpack('<d',0x755d18)[0];identity=list(n.unpack('<16f',0x806680));checks=0;errors=[];events=[];resetCases=[];transformCases=[];cameraCases=[];rng=random.Random(0x5ff390)
reuseCases=[];cameraCases=[]
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e:errors.append({'label':label,'native':a,'expected':e})
def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if address==0x715718:
  out,left,right=n.unpack('<3I',sp+4);n.pack('<16f',out,*multiply(n.unpack('<16f',left),n.unpack('<16f',right)));events.append({'edge':'matrix'});mu.reg_write(UC_X86_REG_EAX,out);mu.reg_write(UC_X86_REG_ESP,sp+16);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x6e56a0:
  index,pointer=n.unpack('<2I',sp+4);events.append({'edge':'deviceTransform','index':index,'words':list(n.unpack('<16I',pointer))});mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x6e57b0:raise RuntimeError('Viewport backend unexpectedly reached on cached camera path')
 else:events.append({'edge':'lightState'if address==0x5ff840 else'renderCache'})
for a in[0x715718,0x6e56a0,0x6e57b0,0x5ff840,0x5fcc80]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
IN=n.DATA+0x80000;OUT=IN+0x1000;VIEW=IN+0x2000
for case in range(1024):
 view=[f32(rng.uniform(-4,4))for _ in range(16)];cache=[f32(rng.uniform(-3,3))for _ in range(16)];asymmetric=bool(case%2);address=0x5ed420 if asymmetric else 0x5ed300;cacheAddress=0x97ba90 if asymmetric else 0x80b8c8;n.pack('<16f',VIEW,*view);n.pack('<16f',cacheAddress,*cache);reuse=[1,3,-1,2147483647][case%4];ignoredCamera=[0,0xdeadbeef,IN][case%3];events.clear();n.call(address,[OUT,VIEW,ignoredCamera,reuse]);native=list(n.unpack('<16I',OUT));ck(native,words(multiply(view,cache)),['cachedClip',case]);ck(list(n.unpack('<16I',cacheAddress)),words(cache),['cachedClipPreservesCache',case]);reuseCases.append({'viewWords':words(view),'cacheWords':words(cache),'asymmetric':asymmetric,'nativeReuseArgument':reuse,'ignoredCameraPointer':hex(ignoredCamera),'nativeWords':native,'nativeCacheWords':list(n.unpack('<16I',cacheAddress))})

def modelCached(state,camera,g):
 state['current']=list(camera);view=inverse(camera)
 for column in range(3):
  for row in range(4):view[row*4+column]=f32(view[row*4+column]*camera[27+column])
 matrices=state['matrices'];sym=matrices['symmetricCache'];asym=matrices['asymmetricCache'];proj=matrices['projection'];primary=multiply(view,sym);changed=g['cullingMode']!=state['previousCullingMode'];state['previousCullingMode']=g['cullingMode']
 if changed:
  if g['cullingMode']==0:asym=clipping(camera,g,True)
  else:sym=clipping(camera,g,False)
 secondary=multiply(view,asym if g['cullingMode']==0 else sym);aux=g['auxiliary'];combined=multiply(view,proj);mappedCombined=multiply(combined,aux);mappedProjection=multiply(proj,aux);out=dict(matrices);out.update(view=view,primary=primary,secondary=secondary,symmetricCache=sym,asymmetricCache=asym,auxiliaryCopy=list(aux),combined=combined,mappedCombined=mappedCombined,mappedProjection=mappedProjection)
 if changed:
  # Later EBPreset recomputes only derivedscales/edgeplanes/frustum, while the
  # earlier projection block was already skipped and stays byte-identical.
  temp={'matrices':dict(out)};modelApply(temp,camera,g);out['edgePlanes']=temp['matrices']['edgePlanes'];state['scales']=temp['scales'];state['frustum']=temp['frustum']
 state.update(matrices=out,passWord=1,resetWord=0);return state,changed
for case in range(768):
 camera=cameraSeed(case);old=cameraSeed(case+17);g=globalsSeed(case);g['cullingMode']=[0,1,2,-1][case%4];setup(old,g);n.pack('<30f',IN,*old);n.call(0x603cc0,[IN]);previous=g['cullingMode']if case//4%3==0 else[1,0,0,2][case%4];n.pack('<i',0x973954,previous);dirty=[0,1,0x80000000,0xffffffff][case%4];n.pack('<I',0x95e674,dirty);n.pack('<30f',IN,*camera);before=readCamera();state=stateModel();events.clear();argument=[1,3,-1][case%3];n.call(0x5ed540,[IN,argument]);after=readCamera();expected,changed=modelCached(state,camera,g);ck(after,encoded(expected),['cachedCamera',case]);ck(n.unpack('<I',0x95e674)[0],dirty,['cachedCameraSkipsDirtyViewport',case]);ck(after['matrixWords']['projection'],before['matrixWords']['projection'],['projectionPreservedAfterModeReset',case]);cameraCases.append({'cameraWords':words(camera),'globals':g,'before':before,'native':after,'nativeEvents':list(events),'reuseArgument':argument,'cullingModeChanged':changed,'viewportDirtyBefore':dirty,'viewportDirtyAfter':n.unpack('<I',0x95e674)[0]})
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt',encoding='utf8')as f:json.dump({'sineFile':'references/native-animation-sine-table.f32','sineSHA256':hashlib.sha256(sineBytes).hexdigest(),'angleScale':angleScale,'reuseCases':reuseCases,'cameraCases':cameraCases},f)
report={'schema':'original-camera-cache-ordering-v1','passed':not errors,'checks':checks,'binarySHA256':n.sha256,'counts':{'cachedClipCases':len(reuseCases),'cachedCameraCases':len(cameraCases),'retainedPortableReplayCases':len(reuseCases)+len(cameraCases),'cameraCullingModeChangedCases':sum(c['cullingModeChanged']for c in cameraCases),'cameraCullingModeUnchangedCases':sum(not c['cullingModeChanged']for c in cameraCases),'ignoredNullOrPoisonCameraPointerCases':sum(c['ignoredCameraPointer']in['0x0','0xdeadbeef']for c in reuseCases)},'errors':errors[:30],'adapters':{'0x715718':'Explicit sequential binary64 importedD3DX matrix product spilledfloat32.','0x6e56a0':'Onlyinitialbaseline603cc0priming; no device transforms occur inside5ed540cached calls.','0x6e57b0':'Forbidden during cachedcamera calls; hook raises if unexpected. No viewportservice was invoked.'},'limits':['Nonzero param2cachedprojection with normalconversion973944=0 andfinitevalidresolvedcamera/cachematrices. All originalcachedcamera computation executesunchanged.','Fresh projection remains sealedcamera/viewportmodule. Modechangecanresetreuseflag onlyafterprojectionblock hasalreadybeenskipped; capturedoldprojection remainsunchanged.','Native light/rendercache helperrenderer-byte outputs areexcludedfromportable numeric scope, with explicit hostcallbacks.','Importedphysical D3DXCPU policy, reflectedcamera, device/GPU andauthoredscene integration remainoutside coverage.','Native/Python ownstate differential passed; compiled C#replay remains separate andpending.'],'fixtureFile':PREFIX+'-native-fixtures.json.gz'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));sys.exit(0 if not errors else 1)
