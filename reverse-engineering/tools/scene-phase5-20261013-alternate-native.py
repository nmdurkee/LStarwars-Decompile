"""Original dirty viewport reset, pixel/depth transform and camera composition."""
import sys,json,gzip,struct,hashlib,random,math,importlib.util,ast
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase5-20261013-alternate'
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
from unicorn.x86_const import UC_X86_REG_ECX
copyCases=[];cameraCases=[];templateWords=list(n.unpack('<16I',0x8065c0));reference=n.DATA+0x70000;IN=n.DATA+0x80000;BUFFER=n.DATA+0x90000

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
 elif address==0x6e57b0:raise RuntimeError('Dirty viewport unexpectedly reached in clean alternate camera fixture')
 else:events.append({'edge':'lightState'if address==0x5ff840 else'renderCache'})
for a in[0x715718,0x6e56a0,0x6e57b0,0x5ff840,0x5fcc80]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def affine(left,right):
 out=[0.]*16;out[15]=1.
 for row in range(4):
  for col in range(3):
   a=left[row*4:row*4+3];b=[right[col],right[4+col],right[8+col]];exact=A(A(M(W(a[0]),W(b[0])),M(W(a[1]),W(b[1]))),M(W(a[2]),W(b[2])));approx=(float(a[0])*b[0]+float(a[1])*b[1])+float(a[2])*b[2]
   if row==3:exact=A(exact,W(right[12+col]));approx+=right[12+col]
   value=S(exact);out[row*4+col]=f32(approx)if value==0 and approx==0 else value
 return out

def alternate(camera,frame):
 if frame['mode']==0:
  view=inverse(camera)
  for column in range(3):
   for row in range(4):view[row*4+column]=f32(view[row*4+column]*camera[27+column])
  return view
 inverseCamera=inverse(camera);view=inverse(frame['reference'])
 if frame['mode']==1:
  raw=list(frame['templateWords']);raw[5]=0xbf800000;template=[struct.unpack('<f',struct.pack('<I',v))[0]for v in raw];view=affine(view,template)
 view=affine(view,frame['reference']);view=affine(view,inverseCamera);return view
def modelAlternate(state,camera,g,frame,restore=False):
 state['current']=list(camera);view=alternate(camera,frame)
 if g['orthographic']:
  proj=[0.]*16;proj[0]=f32(g['orthographicScale']*camera[17]);proj[5]=g['orthographicScale'];proj[10]=proj[15]=1.
 else:
  proj=projection(camera,g);proj[0]=f32(proj[0]*camera[22]);proj[5]=f32(proj[5]*camera[23]);proj[8]=f32(proj[8]+camera[20]);proj[9]=f32(proj[9]+camera[21])
 sym=clipping(camera,g,False);asym=clipping(camera,g,True)if g['cullingMode']==0 else state['matrices'].get('asymmetricCache',[0.]*16);primary=multiply(view,sym);secondary=multiply(view,sym if g['cullingMode']!=0 else asym);aux=g['auxiliary'];combined=multiply(view,proj);mappedCombined=multiply(combined,aux);mappedProjection=multiply(proj,aux)
 sin,cos=trig(camera[16]);tan=S(D(W(sin),W(cos)));width=S(D(W(tan),W(camera[17])));iw=S(D(M(W(g['sourceSize'][0]),W(width)),W(g['screenSize'][0])));ih=S(D(M(W(tan),W(g['sourceSize'][1])),W(g['screenSize'][1])));scales=[width,tan,iw,ih];edge=[0.]*16;edge[6]=cos;edge[10]=sin;edge[7]=-cos;edge[11]=sin;ratio=S(D(D(W(sin),W(cos)),W(camera[17])));square=S(A(M(W(ratio),W(ratio)),W(1)));normal=S(D(W(1),W(f32(math.sqrt(square)))));edge[0]=-normal;edge[1]=normal;edge[8]=f32(normal*ratio);edge[9]=edge[8]
 matrices={'view':view,'projection':proj,'clipTransform':g['clipTransform']if restore else state['matrices']['clipTransform'],'auxiliaryCopy':aux,'combined':combined,'secondary':secondary,'primary':primary,'symmetricCache':sym,'mappedCombined':mappedCombined,'mappedProjection':mappedProjection,'edgePlanes':edge,'asymmetricCache':asym}
 if restore:matrices['primary']=multiply(combined,g['clipTransform']);matrices['secondary']=list(matrices['primary'])
 state.update(matrices=matrices,scales=scales,frustum=ordinaryFrustum(view,camera,scales,g['template']),previousCullingMode=g['cullingMode'],passWord=1,resetWord=0)
 return state

for case in range(1024):
 before=[rng.randrange(1<<32)for _ in range(64)];sourceOffset=20;destinationOffset=sourceOffset+[-16,-4,-1,0,1,4,16][case%7];n.pack('<64I',BUFFER,*before);expected=list(before)
 for i in range(16):expected[destinationOffset+i]=expected[sourceOffset+i]
 n.call(0x5c19d0,regs={UC_X86_REG_EAX:BUFFER+4*sourceOffset,UC_X86_REG_ECX:BUFFER+4*destinationOffset});native=list(n.unpack('<64I',BUFFER));ck(native,expected,['rawCopyOverlapImage',case]);copyCases.append({'beforeWords':before,'sourceOffset':sourceOffset,'destinationOffset':destinationOffset,'nativeWords':native})
for case in range(768):
 camera=cameraSeed(case);g=globalsSeed(case);frame={'mode':[0,1,2,-1][case%4],'reference':cameraSeed(case+31)[:16],'templateWords':list(templateWords)}
 if case%3==0:
  frame['reference']=[f32(rng.uniform(-2,2))for _ in range(16)]
 if frame['mode']!=1 and case%5==0:frame['templateWords']=[rng.randrange(1<<32)for _ in range(16)]
 else:
  # The native unconditionalY-diagonaloverwrite must erase this poisonword.
  frame['templateWords'][5]=0x7fc01234
 setup(camera,g);n.pack('<30f',IN,*camera);n.pack('<i',0x973944,frame['mode']);n.pack('<16f',0x9730bc,*frame['reference']);n.pack('<16I',0x8065c0,*frame['templateWords']);before=readCamera();state=stateModel();events.clear();n.call(0x5ed540,[IN,0]);after=readCamera();expected=modelAlternate(state,camera,g,frame);ck(after,encoded(expected),['alternateCamera',case]);cameraCases.append({'cameraWords':words(camera),'globals':g,'frame':{'mode':frame['mode'],'referenceWords':words(frame['reference']),'templateWords':frame['templateWords']},'before':before,'native':after,'nativeEvents':list(events)})
md=Cs(CS_ARCH_X86,CS_MODE_32);instructions=[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in md.disasm(n.read(0x5c19d0,0x100),0x5c19d0)];stop=next(i for i,v in enumerate(instructions)if v['mnemonic']=='ret');instructions=instructions[:stop+1];(R/(PREFIX+'-assembly.json')).write_text(json.dumps({'binarySHA256':n.sha256,'copyABI':{'sourceRegister':'EAX','destinationRegister':'ECX'},'copyInstructions':instructions,'cameraAssemblyDependency':'scene-phase5-20261013-assembly.json'},indent=2)+'\n')
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt',encoding='utf8')as f:json.dump({'sineFile':'references/native-animation-sine-table.f32','sineSHA256':hashlib.sha256(sineBytes).hexdigest(),'angleScale':angleScale,'copyCases':copyCases,'cameraCases':cameraCases},f)
report={'schema':'original-alternate-camera-view-v1','passed':not errors,'checks':checks,'binarySHA256':n.sha256,'counts':{'rawForwardCopyCases':len(copyCases),'cameraCases':len(cameraCases),'retainedPortableReplayCases':len(copyCases)+len(cameraCases),'normalCases':sum(c['frame']['mode']==0 for c in cameraCases),'YReflectionCases':sum(c['frame']['mode']==1 for c in cameraCases),'otherNonzeroModeCases':sum(c['frame']['mode']not in[0,1]for c in cameraCases)},'errors':errors[:30],'templateInitialWords':templateWords,'adapters':{'0x715718':'Explicit sequential binary64 importedD3DX matrix product spilledfloat32; original5b5430 CPU affine products executeunchanged.','0x6e56a0':'No calls insideApply-only camera fixtures; devicebackend stays external.'},'limits':['Freshparam2=0 andcleanviewport95e674=0. Mode0retainsnormalviewcolumnscales;nonzero view modesuseactualreference transformcompositionwithoutcolumnscales.','Finitecamera/reference/storednumeric outputs. Mode1templatefiniteafterunconditionalword5overwrite; unusedtemplatewords mayberawnonfinite inothernonzero modes.','Raw16-word copy retainsallbits andactualforward shifted-overlap behavior;valid64wordresolvedimageonly.','Normalfresh projection/frustum andrenderer services inheritprimarycamera limitations. Reflectedreuse anddirtyviewport composition notnewlyasserted here.','ImportedphysicalD3DXpolicy,unportedrenderer byte outputs,authoredworld andGPU remainseparate.','Native/Python ownstate differential passed; managedreplay remainsseparate andpending.'],'fixtureFile':PREFIX+'-native-fixtures.json.gz'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));sys.exit(0 if not errors else 1)
