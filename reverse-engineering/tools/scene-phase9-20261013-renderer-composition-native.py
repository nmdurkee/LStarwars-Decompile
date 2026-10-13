"""Original dirty viewport reset, pixel/depth transform and camera composition."""
import sys,json,gzip,struct,hashlib,random,math,importlib.util,ast
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase9-20261013-renderer-composition'
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
from unicorn import UC_HOOK_MEM_WRITE
pipelineCases=[];dispatchCases=[];visits=[];lastWrites={};track=False;currentTreeStage=None
for file,names in[('scene-phase5-20261013-viewport-native.py',['modelReset','readViewport','auxiliary']),('scene-phase5-20261013-alternate-native.py',['affine','alternate','modelAlternate']),('scene-phase4-20261013-native.py',['classify','modelTransform'])]:
 module=ast.parse((P/file).read_text());selected=[v for v in module.body if isinstance(v,ast.FunctionDef)and v.name in names];exec(compile(ast.Module(body=selected,type_ignores=[]),file,'exec'))
def modelCachedAlternate(state,camera,g,frame):
 state['current']=list(camera);view=alternate(camera,frame)
 matrices=state['matrices'];sym=matrices['symmetricCache'];asym=matrices['asymmetricCache'];proj=matrices['projection'];primary=multiply(view,sym);changed=g['cullingMode']!=state['previousCullingMode'];state['previousCullingMode']=g['cullingMode']
 if changed:
  if g['cullingMode']==0:asym=clipping(camera,g,True)
  else:sym=clipping(camera,g,False)
 secondary=multiply(view,asym if g['cullingMode']==0 else sym);aux=g['auxiliary'];combined=multiply(view,proj);mappedCombined=multiply(combined,aux);mappedProjection=multiply(proj,aux);out=dict(matrices);out.update(view=view,primary=primary,secondary=secondary,symmetricCache=sym,asymmetricCache=asym,auxiliaryCopy=list(aux),combined=combined,mappedCombined=mappedCombined,mappedProjection=mappedProjection)
 if changed:
  # Later EBPreset recomputes only derivedscales/edgeplanes/frustum, while the
  # earlier projection block was already skipped and stays byte-identical.
  temp={'matrices':dict(out)};modelAlternate(temp,camera,g,frame);out['edgePlanes']=temp['matrices']['edgePlanes'];state['scales']=temp['scales'];state['frustum']=temp['frustum']
 state.update(matrices=out,passWord=1,resetWord=0);return state,changed
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e:errors.append({'label':label,'native':a,'expected':e})
def hook(mu,address,size,_):
 global currentTreeStage
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if address==0x715718:
  out,left,right=n.unpack('<3I',sp+4);n.pack('<16f',out,*multiply(n.unpack('<16f',left),n.unpack('<16f',right)));events.append({'edge':'matrix'});mu.reg_write(UC_X86_REG_EAX,out);mu.reg_write(UC_X86_REG_ESP,sp+16);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x6e56a0:
  index,pointer=n.unpack('<2I',sp+4);events.append({'edge':'deviceTransform','index':index,'words':list(n.unpack('<16I',pointer))});mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x6e57b0:
  pointer=n.unpack('<I',sp+4)[0];events.append({'edge':'deviceViewport','words':list(n.unpack('<6I',pointer)),'stateAtService':readViewport()});mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x5d8fb0:currentTreeStage=readCamera();events.append({'edge':'tree','camera':currentTreeStage})
 elif address==0x5d8b60:
  _,center,extent,far,individual=n.unpack('<5I',sp);scratch=((sp-4)&~15)-4;visits.append({'center':list(n.unpack('<3f',center)),'extent':list(n.unpack('<3f',extent)),'farWord':far,'individual':individual,'scratchWord':n.unpack('<I',scratch)[0],'lastWriteBytes':[lastWrites.get(scratch+i)for i in range(4)]})
 elif address in(0x5d8e97,0x5d8f5e):visits[-1]['nativeResult']=mu.reg_read(UC_X86_REG_EAX)
 else:events.append({'edge':'lightState'if address==0x5ff840 else'renderCache'})
def writeHook(mu,access,address,size,value,_):
 if track:
  for i in range(size):lastWrites[address+i]=hex(mu.reg_read(UC_X86_REG_EIP))
for a in[0x715718,0x6e56a0,0x6e57b0,0x5ff840,0x5fcc80,0x5d8fb0,0x5d8b60,0x5d8e97,0x5d8f5e]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
n.mu.hook_add(UC_HOOK_MEM_WRITE,writeHook,begin=n.STACK,end=n.STACK+0xffff)
def updateGlobals(g,vp):
 out=dict(g)
 for key,wordsKey in[('correction','correctionWords'),('clipScales','clipScaleWords'),('auxiliary','auxiliaryWords'),('clipTransform','clipTransformWords')]:out[key]=[struct.unpack('<f',struct.pack('<I',v))[0]for v in vp[wordsKey]]
 return out

def modelPipeline(state,camera,g,frame,viewport,inputViewport,reuse=False,restore=False):
 if reuse:modelCachedAlternate(state,camera,g,frame);return state,g,viewport
 viewport,_=modelReset(viewport,inputViewport);g=updateGlobals(g,viewport);modelAlternate(state,camera,g,frame,restore);return state,g,viewport

def modelSwitchPipeline(state,requested,g,frame,viewport,inputViewport):
 if requested!=state['mode']and state['mode']==0:state['base']=list(state['current'])
 if requested!=0:
  state['saved']=list(state['current']);state,g,viewport=modelPipeline(state,state['base'],g,frame,viewport,inputViewport,restore=True)
 state['mode']=requested;return state,g,viewport

def inputViewport(index,g):
 width,height=g['screenSize'];return {'screen':g['screenSize'],'rectangle':[[-1000,-1,0,17,width*16-1,width*16+1][index%6],[-500,-1,0,19,height*16-1,height*16+1][index//6%6],[500,width*8,width*16,width*32][index//36%4],[700,height*8,height*16,height*32][index//144%4]],'ranges':[0.,0.,1.,1.]if index%2 else[f32(.1),f32(.2),f32(.8),f32(.9)],'depthWords':[word(f32([0.,.25,1.][index%3])),[0x3f800000,0x7fc01234,0xffffffff][index%3]],'dirty':[0,1,0x80000000,0xffffffff][index//12%4]}
def setupProduct(index,mode):
 old=cameraSeed(index+17);g=globalsSeed(index);g['cullingMode']=[0,1,2,-1][index//24%4];setup(old,g,base=cameraSeed(index+61),saved=cameraSeed(index+91),mode=mode);n.pack('<30f',IN,*old);n.call(0x603cc0,[IN]);previous=g['cullingMode']if index//96%2 else 1-g['cullingMode'];n.pack('<i',0x973954,previous);frame={'mode':[0,1,2,-1][index%4],'reference':cameraSeed(index+31)[:16],'templateWords':words(identity)};frame['templateWords'][5]=0x7fc01234
 if index%3==0:frame['reference']=[f32(rng.uniform(-2,2))for _ in range(16)]
 n.pack('<i',0x973944,frame['mode']);n.pack('<16f',0x9730bc,*frame['reference']);n.pack('<16I',0x8065c0,*frame['templateWords']);vp=inputViewport(index,g);n.pack('<4i',0x963e10,*vp['rectangle']);n.pack('<2I',0x963e20,*vp['depthWords']);n.pack('<4f',0x963e30,*vp['ranges']);n.pack('<I',0x95e674,vp['dirty']);n.pack('<i',0x97394c,mode);return g,frame,vp
# Independent recovered renderer models, kept separate from camera arithmetic.
lightPolicy={'__file__':str(P/'scene-phase8-20261013-light-probe.py')};exec((P/'scene-phase8-20261013-light-probe.py').read_text().split('f=json.loads')[0],lightPolicy)
cachePolicy={'W':W,'A':A,'M':M,'D':D,'S':S,'f32':f32,'math':math,'unit':.0625};cacheAst=ast.parse((P/'scene-phase6-20261013-renderer-native.py').read_text());cacheDefs=[v for v in cacheAst.body if isinstance(v,ast.FunctionDef)and v.name in['sign','product','quotient','offsets','extents']];exec(compile(ast.Module(body=cacheDefs,type_ignores=[]),'renderer-oracles','exec'),cachePolicy)
rendererEvents=[];pendingRenderer={};beforeRenderer=None;rendererInputs=None;rendererLightGlobals=None
rendererRng=random.Random(0x5fcc10)
def readRenderer():return {'cameraImageHex':n.read(0x9869b0,0x84).hex(),'lightImageWords':list(n.unpack('<22I',0x986930)),'counter':n.unpack('<I',0x9868c0)[0],'cameraShortCounter':n.unpack('<H',0x9868cc)[0],'lightShortCounter':n.unpack('<H',0x9868c4)[0],'lightDirty':n.unpack('<I',0x9868d4)[0],'directionWords':list(n.unpack('<3I',0x80e9d8)),'colorWords':list(n.unpack('<4I',0x80e9c8))}
def readRendererInputs():return {'screen':list(n.unpack('<2i',0x973900)),'source':list(n.unpack('<2i',0x80e694)),'rectangle':list(n.unpack('<4i',0x963e10)),'origin':list(n.unpack('<2i',0x80202c))}
def rendererHook(mu,address,size,_):
 if address in(0x5ff840,0x5fcc80):
  edge='lightState'if address==0x5ff840 else'renderCache';before=readRenderer();expected=dict(before)
  if edge=='lightState':
   c={'cameraWords':list(n.unpack('<30I',0x9736e8)),'nativeDirectionWords':before['directionWords'],'aimWords':list(n.unpack('<3I',0x80e9bc)),'identityWords':list(n.unpack('<16I',0x806680))};matrix,vector=lightPolicy['model'](c);expected.update(lightImageWords=matrix+before['colorWords'][:3]+vector,lightShortCounter=(before['lightShortCounter']+1)&0xffff,lightDirty=0)
  else:
   image=bytearray.fromhex(before['cameraImageHex']);struct.pack_into('<I',image,0,0);struct.pack_into('<16I',image,4,*n.unpack('<16I',0x80b708));projectionWords=list(n.unpack('<16I',0x80b748));struct.pack_into('<5I',image,0x44,*[projectionWords[j]for j in(0,5,10,11,14)]);inputs=readRendererInputs();values=[]
   for pair in(cachePolicy['offsets'](inputs),cachePolicy['extents'](inputs)):
    for axis in range(2):
     value=S(M(W(pair[axis]),D(W(inputs['screen'][axis]),W(640. if axis==0 else 224.))));values.append(-0. if value==0 and cachePolicy['sign'](pair[axis])!=(inputs['screen'][axis]<0) else value)
   struct.pack_into('<4I',image,0x74,*[word(v)for v in values]);expected.update(cameraImageHex=image.hex(),cameraShortCounter=(before['cameraShortCounter']+1)&0xffff)
  expected['counter']=(before['counter']+1)&0xffffffff;pendingRenderer[edge]={'edge':edge,'before':before,'expected':expected}
 else:
  edge='lightState'if address==0x5ffb9c else'renderCache';item=pendingRenderer.pop(edge);after=readRenderer();ck(after,item['expected'],['composedCpuRenderer',len(rendererEvents),edge]);item.pop('expected');item['native']=after;rendererEvents.append(item)
for address in(0x5ff840,0x5fcc80,0x5ffb9c,0x5fcd55):n.mu.hook_add(UC_HOOK_CODE,rendererHook,begin=address,end=address)
_originalSetupProduct=setupProduct
def setupProduct(index,mode):
 global beforeRenderer,rendererInputs,rendererLightGlobals
 g,frame,vp=_originalSetupProduct(index,mode)
 n.pack('<2i',0x80e694,640+index%7,480+index%11);n.pack('<2i',0x80202c,index%31-15,index%37-18);n.pack('<3f',0x80e9d8,*[rendererRng.uniform(-8,8)for _ in range(3)]);n.pack('<3f',0x80e9bc,*[rendererRng.uniform(-4,4)for _ in range(3)]);n.pack('<4I',0x80e9c8,*[rendererRng.getrandbits(32)for _ in range(4)]);n.write(0x9869b0,bytes(rendererRng.getrandbits(8)for _ in range(0x84)));n.pack('<22I',0x986930,*[rendererRng.getrandbits(32)for _ in range(22)]);n.pack('<I',0x9868c0,rendererRng.getrandbits(32));n.pack('<H',0x9868cc,rendererRng.getrandbits(16));n.pack('<H',0x9868c4,rendererRng.getrandbits(16));n.pack('<I',0x9868d4,rendererRng.getrandbits(32));beforeRenderer=readRenderer();rendererInputs=readRendererInputs();rendererLightGlobals={'aimWords':list(n.unpack('<3I',0x80e9bc)),'identityWords':list(n.unpack('<16I',0x806680))};rendererEvents.clear();return g,frame,vp

IN=n.DATA+0x80000
for case in range(1152):
 mode=[0,1,2][case//192%3];g,frame,vp=setupProduct(case,mode);camera=cameraSeed(case);n.pack('<30f',IN,*camera);before=readCamera();beforeVp=readViewport();state=stateModel();events.clear();kind=['apply','restore','switch'][case%3];reuse=[0,1,-1][case//4%3];requested=[0,1,2,-1][case//12%4]
 if kind=='apply':n.call(0x5ed540,[IN,reuse]);state,eg,evp=modelPipeline(state,camera,g,frame,beforeVp,vp,reuse!=0)
 elif kind=='restore':n.call(0x603cc0,[IN]);state,eg,evp=modelPipeline(state,camera,g,frame,beforeVp,vp,restore=True)
 else:n.call(0x5d6900,[requested]);state,eg,evp=modelSwitchPipeline(state,requested,g,frame,beforeVp,vp)
 after=readCamera();afterVp=readViewport();ck(after,encoded(state),['pipelineNumericCamera',case]);ck(afterVp,evp,['pipelineViewport',case]);pipelineCases.append({'cameraWords':words(camera),'globals':g,'frame':{'mode':frame['mode'],'referenceWords':words(frame['reference']),'templateWords':frame['templateWords']},'viewportInput':vp,'before':before,'beforeViewport':beforeVp,'kind':kind,'reuseArgument':reuse,'requested':requested,'native':after,'nativeViewport':afterVp,'nativeEvents':list(events),'beforeRenderer':beforeRenderer,'rendererInputs':rendererInputs,'rendererLightGlobals':rendererLightGlobals,'nativeRenderer':readRenderer(),'nativeRendererEvents':list(rendererEvents)})
# Product-domain visibility dispatcher with actual populated tree and exact residue.
phase4=json.loads(gzip.decompress((R/'scene-phase4-20261013-native-fixtures.json.gz').read_bytes()));SC=n.DATA;TREE=SC+0x1000;NODES=SC+0x2000;NODEB=SC+0x3000;ITEMB=SC+0x5000;LIST=SC+0x7000;ROOTS=SC+0x8000;FARS=SC+0x9000;BITS=SC+0xa000
for case in range(192):
 mode=case%3;g,frame,vp=setupProduct(case+1000,mode);tree=phase4['composedCases'][case]['tree'];requested=case//3%3;visible=case%13!=0;workspace=BITS if case%17 else 0;present=case%11!=0;enabled=case%7!=0
 n.write(SC,bytes(0x160));n.pack('<i',SC+0x1c,32);n.pack('<I',SC+0x134,TREE if present else 0);n.pack('<I',SC+0x148,0xc012);n.pack('<I',SC+0x140,0xabcdef);n.pack('<I',SC+0x144,0x12345678);n.pack('<i',SC+0x120,-7);n.pack('<I',0x973988,0x12345678)
 for a,v in[(0x80b6f4,int(visible)),(0x80b6f8,0),(0x80ba14,int(enabled)),(0x80ba58,0),(0x973940,requested),(0x973984,0)]:n.pack('<i',a,v)
 n.write(TREE,bytes(0x40));n.pack('<I',TREE+8,LIST);n.pack('<I',TREE+12,ITEMB);n.pack('<I',TREE+0x14,NODES);n.pack('<I',TREE+0x18,NODEB);n.pack('<H',TREE+0x1c,len(tree['roots']));n.pack('<I',TREE+0x20,ROOTS);n.pack('<I',TREE+0x24,FARS);n.pack('<32H',LIST,*tree['members']);n.pack('<5H',ROOTS,*tree['roots']);n.pack('<5f',FARS,*tree['far'])
 for i,v in enumerate(tree['nodes']):n.pack('<6H',NODES+12*i,*v)
 for address,records in[(NODEB,tree['nodeBounds']),(ITEMB,tree['itemBounds'])]:
  for i,b in enumerate(records):n.pack('<8f',address+32*i,*b['center'],0,*b['extent'],0)
 beforeBits=bytes.fromhex(phase4['composedCases'][case]['beforeHex']);n.write(BITS,beforeBits);n.write(n.STACK,struct.pack('<f',[-100.,0.,1.,100.][case%4])*0x4000);events.clear();visits.clear();lastWrites.clear();currentTreeStage=None;before=readCamera();beforeVp=readViewport();beforeVisible=bool(n.unpack('<I',0x97393c)[0]);state=stateModel();track=True;ret=n.call(0x5f3c80,[SC,workspace]);track=False;active=bool(workspace and visible);treeActive=active and present and enabled;flags=0xc012;count=-7;scratch=0xabcdef;pointer=0x12345678;eg=g;evp=beforeVp;at=0;bits=bytearray(beforeBits)
 if active:
  state,eg,evp=modelSwitchPipeline(state,requested,g,frame,beforeVp,vp);flags&=0xffffffea;count=32;scratch=pointer=0
  if treeActive:
   ck(currentTreeStage,encoded(state),['dispatcherCameraAtTree',case]);scratch=workspace;flags|=17;cam=state['current'];p=modelTransform(state['matrices']['view'],modelBuild(cam[18],state['scales'],g['template']),cam[8:11],cam[12:15]);p.update(near=cam[18],globalFar=cam[19])
   for ri in range(len(tree['roots'])-1,-1,-1):
    far=tree['far'][ri]or p['globalFar'];stack=[tree['roots'][ri]]
    while stack:
     node=tree['nodes'][stack.pop()];b=tree['nodeBounds'][node[0]];v=visits[at];at+=1;result=classify(p,b['center'],b['extent'],far,0,v['scratchWord']);ck(result,v['nativeResult'],['dispatcherNode',case,at])
     if not result:continue
     if result==1:
      for i in tree['members'][node[5]:node[5]+node[1]]:bits[i>>2]|=1<<((i&3)*2)
     else:
      stack.extend(range(node[3],node[3]+node[2]))
      for li in range(node[5],node[5]+node[4]):
       b=tree['itemBounds'][li];v=visits[at];at+=1;result=classify(p,b['center'],b['extent'],far,1,v['scratchWord']);ck(result,v['nativeResult'],['dispatcherLeaf',case,at]);i=tree['members'][li];bits[i>>2]|=result<<((i&3)*2)
  if state['mode']==1:state,eg,evp=modelPipeline(state,state['saved'],eg,frame,evp,vp,restore=True)
 ck(readCamera(),encoded(state),['dispatcherNumericCamera',case]);ck(readViewport(),evp,['dispatcherViewport',case]);ck(ret,SC+0x120 if active else 0,['dispatcherReturn',case]);ck(list(n.unpack('<i',SC+0x120))+list(n.unpack('<3I',SC+0x140)),[count,scratch,pointer,flags],['dispatcherContext',case]);ck(n.read(BITS,8).hex(),bits.hex(),['dispatcherBits',case]);ck(at,len(visits),['dispatcherVisitCount',case]);ck(bool(n.unpack('<I',0x97393c)[0]),True if active else beforeVisible,['dispatcherVisibility',case]);ck(bool(n.unpack('<I',0x973984)[0]),treeActive,['dispatcherPlanesInit',case]);ck(n.unpack('<I',0x973988)[0],SC+0x120 if treeActive else 0x12345678,['dispatcherTreeContext',case]);dispatchCases.append({'globals':g,'frame':{'mode':frame['mode'],'referenceWords':words(frame['reference']),'templateWords':frame['templateWords']},'viewportInput':vp,'before':before,'beforeViewport':beforeVp,'tree':tree,'mode':mode,'requested':requested,'visible':visible,'workspaceToken':workspace,'present':present,'enabled':enabled,'beforeVisibilityActive':beforeVisible,'native':readCamera(),'nativeViewport':readViewport(),'nativeContext':{'count':count,'scratch':scratch,'pointer':pointer,'flags':flags},'nativeVisibilityActive':bool(n.unpack('<I',0x97393c)[0]),'nativePlanesInitialized':bool(n.unpack('<I',0x973984)[0]),'nativeCurrentTreeContextChanged':n.unpack('<I',0x973988)[0]==SC+0x120,'returned':bool(ret),'beforeHex':beforeBits.hex(),'nativeHex':n.read(BITS,8).hex(),'nativeVisits':list(visits),'nativeEvents':list(events),'beforeRenderer':beforeRenderer,'rendererInputs':rendererInputs,'rendererLightGlobals':rendererLightGlobals,'nativeRenderer':readRenderer(),'nativeRendererEvents':list(rendererEvents)})
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt',encoding='utf8')as f:json.dump({'sineFile':'references/native-animation-sine-table.f32','sineSHA256':hashlib.sha256(sineBytes).hexdigest(),'angleScale':angleScale,'identityWords':words(identity),'pipelineCases':pipelineCases,'dispatchCases':dispatchCases},f)
counts={'pipelineCases':len(pipelineCases),'dispatchCases':len(dispatchCases),'retainedPortableReplayCases':len(pipelineCases)+len(dispatchCases),'nestedDispatcherPredicates':sum(len(c['nativeVisits'])for c in dispatchCases),'cpuRendererEvents':sum(len(c['nativeRendererEvents'])for c in pipelineCases+dispatchCases),'setupCpuRendererEvents':2*(len(pipelineCases)+len(dispatchCases)),'applyCases':sum(c['kind']=='apply'for c in pipelineCases),'restoreCases':sum(c['kind']=='restore'for c in pipelineCases),'switchCases':sum(c['kind']=='switch'for c in pipelineCases)}
report={'schema':'original-camera-cpu-renderer-composition-v1','passed':not errors,'checks':checks,'binarySHA256':n.sha256,'counts':counts,'errors':errors[:30],'adapters':{'0x715718':'Explicit sequentialbinary64 importedD3DX product spilledfloat32; originalcamera/affine/tree routines unchanged.','0x6e56a0':'Recorded deviceview/projectiontransforms only.','0x6e57b0':'Recorded sixrawdeviceviewportwords andownstate atservice; noGPU operation.'},'limits':['Finitevalidresolvedcamera/reference/caches,normal andalternateconversionmodes,zero/nonzero projectionreuse,andclean/dirtyviewport combination withunchangeddeclared scalarD3DXpolicy.','No alternatecamera policy forinvalidarrays/nonfinite consumedarithmetic; rawunusedtemplate andseconddepthword remainopaque aspreviousmodules.','Recovered finite light and camera-cache producer byte outputs compose with shared uint counter and distinct ushort counters. Original routines execute unchanged; host runtime renderer inputs remain separate from camera SourceSize globals.','Actualpopulatedvisibilitydispatcher is grid/portaldisabled,validsynthetictree andexactfinite fourth-radiusresidue perpredicate. Externalpriorstack/author assets/fullrenderer remainopen.','Native/Python ownstate differential passed; managedexecution remains separate andpending.'],'fixtureFile':PREFIX+'-native-fixtures.json.gz'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));sys.exit(0 if not errors else 1)
