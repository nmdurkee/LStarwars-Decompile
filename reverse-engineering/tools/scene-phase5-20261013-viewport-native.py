"""Original dirty viewport reset, pixel/depth transform and camera composition."""
import sys,json,gzip,struct,hashlib,random,math,importlib.util,ast
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase5-20261013-viewport'
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
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e:errors.append({'label':label,'native':a,'expected':e})
def readViewport():return {'dirty':n.unpack('<I',0x95e674)[0],'correctionWords':[n.unpack('<I',a)[0]for a in[0x28492f8,0x981c48,0x992294,0x981c94]],'clipScaleWords':[n.unpack('<I',a)[0]for a in[0x963e40,0x963e44,0x963e48,0x963e4c]],'auxiliaryWords':list(n.unpack('<16I',0x971620)),'clipTransformWords':list(n.unpack('<16I',0x80ba68))}
def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if address==0x6e57b0:
  pointer=n.unpack('<I',sp+4)[0];events.append({'edge':'deviceViewport','words':list(n.unpack('<6I',pointer)),'stateAtService':readViewport()});mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x715718:
  out,left,right=n.unpack('<3I',sp+4);n.pack('<16f',out,*multiply(n.unpack('<16f',left),n.unpack('<16f',right)));events.append({'edge':'matrix'});mu.reg_write(UC_X86_REG_EAX,out);mu.reg_write(UC_X86_REG_ESP,sp+16);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x6e56a0:
  index,pointer=n.unpack('<2I',sp+4);events.append({'edge':'deviceTransform','index':index,'words':list(n.unpack('<16I',pointer))});mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 else:events.append({'edge':'lightState'if address==0x5ff840 else'renderCache'})
for a in[0x6e57b0,0x715718,0x6e56a0,0x5ff840,0x5fcc80]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def auxiliary(screen,depth):
 w=f32(screen[0]);h=f32(screen[1]);x=f32(w*.5);y=f32(h*.5);out=[0.]*16;out[0]=x;out[5]=-y;out[10]=f32(16777215.-depth);out[12]=f32(x+0.);out[13]=f32(y+0.);out[14]=depth;out[15]=1.;return out

def modelReset(before,c):
 if not before['dirty']:return dict(before),[]
 x,y,w,h=c['rectangle'];right=i32(x+w);bottom=i32(y+h);maxX=i32(c['screen'][0]<<4);maxY=i32(c['screen'][1]<<4);cw=w;ch=h;xx=x;yy=y;correction=[1.,1.,0.,0.]
 if right>=0 and x<maxX and bottom>=0 and y<maxY:
  if x<0:xx=0;cw=right
  if right>maxX:cw=i32(cw+i32(maxX-right))
  if y<0:yy=0;ch=bottom
  if bottom>maxY:ch=i32(ch+i32(maxY-bottom))
  if cw>0 and ch>0:
   denominatorX=f32(cw);denominatorY=f32(ch);correction=[S(D(W(w),W(denominatorX))),S(D(W(h),W(denominatorY))),S(D(W(i32(w-cw)),W(denominatorX))),S(D(W(-i32(h-ch)),W(denominatorY)))]
   if h==ch:correction[3]=-0.
   if x<0:correction[2]=-correction[2]
   if y<0:correction[3]=-correction[3]
  else:xx=yy=cw=ch=0
 else:xx=yy=cw=ch=0
 atService=dict(before);atService.update(dirty=0,correctionWords=words(correction));viewport=[(v>>4)&0xffffffff for v in[xx,yy,cw,ch]]+c['depthWords'];ranges=c['ranges'];clip=[0.]*4
 for axis,size in[(0,w),(1,h)]:
  lo=ranges[axis];hi=ranges[axis+2]
  if lo==0 and hi==1:clip[axis]=1.;clip[axis+2]=S(M(W(size),W(1/65536)))
  else:clip[axis]=clip[axis+2]=S(D(W(1),sub(W(hi),W(lo))))
 depth=struct.unpack('<f',struct.pack('<I',c['depthWords'][0]))[0];after=dict(atService);after.update(clipScaleWords=words(clip),auxiliaryWords=words(auxiliary(c['screen'],depth)),clipTransformWords=words(identity));return after,[{'edge':'deviceViewport','words':viewport,'stateAtService':atService}]
def setupViewport(c):
 n.pack('<2i',0x973900,*c['screen']);n.pack('<4i',0x963e10,*c['rectangle']);n.pack('<2I',0x963e20,*c['depthWords']);n.pack('<4f',0x963e30,*c['ranges']);n.pack('<I',0x95e674,c['dirty'])

def seed(index):
 screen=[[640,480],[1920,1080],[1,1],[0,0],[-1,480],[134217728,134217727],[2147483647,2147483647]][index%7];sx=i32(screen[0]<<4);sy=i32(screen[1]<<4);width=[-1,0,1,15,16,32,500,10000,16777217,2147483647][index%10];height=[-1,0,1,15,16,32,500,7000,16777219,2147483647][index//10%10];x=[-width-1,-width,-width+1,-1,0,1,i32(sx-1),sx,i32(sx+1)][index//100%9];y=[-height-1,-height,-height+1,-1,0,1,i32(sy-1),sy,i32(sy+1)][index//900%9];rectangle=[i32(x),i32(y),width,height]
 if index>=2048:
  screen=[640,480];rectangle=[rng.randrange(-20000,20001),rng.randrange(-14000,14001),rng.randrange(-1000,30001),rng.randrange(-1000,22001)]
 ranges=[[0.,0.,1.,1.],[.1,.2,.8,.9],[-.25,-.5,.75,.5],[1.,1.,-1.,-1.]][index%4];depth=f32([0.,1.,.25,16777215.,-1.,.1][index%6]);return {'screen':screen,'rectangle':rectangle,'ranges':[f32(v)for v in ranges],'depthWords':[word(depth),[0,0x3f800000,0x7fc01234,0xffffffff][index%4]],'dirty':0 if index%17==0 else[1,0xffffffff,0x80000000][index%3]}
for case in range(4096):
 c=seed(case);g=globalsSeed(case);setup(cameraSeed(case),g);setupViewport(c);before=readViewport();events.clear();n.call(0x5ff390);after=readViewport();expected,expectedEvents=modelReset(before,c);ck(after,expected,['resetImage',case]);ck(events,expectedEvents,['resetServiceOrderState',case]);resetCases.append({'input':c,'before':before,'native':after,'nativeEvents':list(events)})
for case in range(512):
 screen=[rng.randrange(-2147483648,2147483648),rng.randrange(-2147483648,2147483648)];depth=f32(rng.uniform(-100000,100000));n.pack('<2i',0x973900,*screen);n.pack('<f',0x963e20,depth);n.call(0x5ff2d0);native=list(n.unpack('<16I',0x971620));ck(native,words(auxiliary(screen,depth)),['auxiliary',case]);transformCases.append({'screen':screen,'depthWord':word(depth),'nativeWords':native})
IN=n.DATA+0x80000
for case in range(320):
 camera=cameraSeed(case);g=globalsSeed(case);setup(camera,g);c=seed(case+2048);c['screen']=g['screenSize'];setupViewport(c);n.pack('<30f',IN,*camera);before=readCamera();beforeViewport=readViewport();state=stateModel();events.clear();n.call(0x5ed540,[IN,0]);after=readCamera();afterViewport=readViewport();vp,ev=modelReset(beforeViewport,c);ck(afterViewport,vp,['cameraViewportImage',case]);updated=dict(g);updated['correction']=[struct.unpack('<f',struct.pack('<I',v))[0]for v in vp['correctionWords']];updated['clipScales']=[struct.unpack('<f',struct.pack('<I',v))[0]for v in vp['clipScaleWords']];updated['auxiliary']=[struct.unpack('<f',struct.pack('<I',v))[0]for v in vp['auxiliaryWords']];updated['clipTransform']=[struct.unpack('<f',struct.pack('<I',v))[0]for v in vp['clipTransformWords']];modelApply(state,camera,updated);ck(after,encoded(state),['cameraAfterViewport',case]);ck([e for e in events if e['edge']=='deviceViewport'],ev,['cameraViewportService',case]);cameraCases.append({'input':c,'cameraWords':words(camera),'globals':g,'beforeCamera':before,'beforeViewport':beforeViewport,'nativeCamera':after,'nativeViewport':afterViewport,'nativeEvents':list(events)})
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly={hex(a):[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in md.disasm(n.read(a,size),a)]for a,size in[(0x5ff390,0x2cb),(0x5ff2d0,0xb8),(0x5b44e0,0x15)]}
(R/(PREFIX+'-assembly.json')).write_text(json.dumps({'binarySHA256':n.sha256,'functions':assembly},indent=2)+'\n')
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt',encoding='utf8')as f:json.dump({'sineFile':'references/native-animation-sine-table.f32','sineSHA256':hashlib.sha256(sineBytes).hexdigest(),'angleScale':angleScale,'identityWords':words(identity),'resetCases':resetCases,'transformCases':transformCases,'cameraCases':cameraCases},f)
report={'schema':'original-dirty-viewport-camera-v1','passed':not errors,'checks':checks,'binarySHA256':n.sha256,'counts':{'resetCases':len(resetCases),'pixelDepthTransformCases':len(transformCases),'cameraCompositionCases':len(cameraCases),'retainedPortableReplayCases':len(resetCases)+len(transformCases)+len(cameraCases),'earlyCleanViewportCases':sum(c['input']['dirty']==0 for c in resetCases),'zeroViewportServices':sum(any(e['words'][2:4]==[0,0]for e in c['nativeEvents'])for c in resetCases)},'errors':errors[:30],'adapters':{'0x6e57b0':'Recorded six raw deviceviewport words and ownstate at boundary, with no GPU operation. Successfulservice return; caller ignores result.','0x715718':'Explicit sequential binary64 matrix multiply spilledfloat32, onlycamera composition.','0x6e56a0':'No calls in ApplyNormal-only composition; hook declared for dependency reuse and devicebackend remains external.'},'limits':['Int32 wrapping rectangle/screen operations, finite unequal non-default floatrange endpoints and finite minimumdepth. Second rawdepthword is copied opaquely, including quietNaN/FFFF patterns.','Zero/negative/overflowed screen sizes andempty clippedrectangles exercise nativecontrol boundaries, not successful physicaldevice viewport acceptance.','Camera composition inherits sealed normalcamera constraints, explicit D3DXpolicy and unported light/rendercache state outputs. No liveGPU/backend or fullframe equivalence.','Native/Python ownstate differential passed; managed replay remains separate and pending.'],'fixtureFile':PREFIX+'-native-fixtures.json.gz'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));sys.exit(0 if not errors else 1)
