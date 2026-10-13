"""Normal native camera producer through switch/restore and populated visibility preparation."""
import sys,json,gzip,struct,hashlib,random,math,importlib.util,ast
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase5-20261013'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86()
from unicorn import UC_HOOK_CODE,UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ESI
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0];words=lambda a:[word(v)for v in a]
defs=ast.parse((P/'scene-phase4-20261013-native.py').read_text());exec(compile(ast.Module(body=[v for v in defs.body if isinstance(v,ast.FunctionDef)and v.name in['modelBuild','modelTransform','classify']],type_ignores=[]),'phase4-oracles','exec'))
sineBytes=(B/'references/native-animation-sine-table.f32').read_bytes();sine=list(struct.unpack('<32768f',sineBytes));n.write(0x29899a0,sineBytes);angleScale=n.unpack('<d',0x755d18)[0]
W=x87.wide;M=x87.mul;A=x87.add;D=x87.div;S=x87.store
sub=lambda a,b:A(a,(-b[0],b[1]))
checks=0;errors=[];events=[];visits=[];lastWrites={};track=False;inverseCases=[];projectionCases=[];clipCases=[];frustumCases=[];cameraCases=[];dispatchCases=[];rng=random.Random(0x5ed540);initialContext=None
matrixKeys={'view':0x80b708,'projection':0x80b748,'clipTransform':0x80b788,'auxiliaryCopy':0x80b7c8,'combined':0x80b808,'secondary':0x80b848,'primary':0x80b888,'symmetricCache':0x80b8c8,'mappedCombined':0x80b908,'mappedProjection':0x80b948,'edgePlanes':0x80b988,'asymmetricCache':0x97ba90}
scaleAddresses=[0x966378,0x97313c,0x966270,0x96dce4]
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e:errors.append({'label':label,'native':a,'expected':e})
def readCamera():return {'currentWords':list(n.unpack('<30I',0x9736e8)),'baseWords':list(n.unpack('<30I',0x971b00)),'savedWords':list(n.unpack('<30I',0x973760)),'mode':n.unpack('<i',0x97394c)[0],'previousCullingMode':n.unpack('<i',0x973954)[0],'matrixWords':{k:list(n.unpack('<16I',a))for k,a in matrixKeys.items()},'scaleWords':[n.unpack('<I',a)[0]for a in scaleAddresses],'frustumHex':n.read(0x963fa0,336).hex(),'passWord':n.unpack('<I',0x971748)[0],'resetWord':n.unpack('<I',0x97175c)[0]}
def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x715718:
  ret,out,left,right=n.unpack('<4I',sp);a=n.unpack('<16f',left);b=n.unpack('<16f',right);n.pack('<16f',out,*multiply(a,b));events.append({'edge':'matrix','left':hex(left),'right':hex(right),'out':hex(out)});mu.reg_write(UC_X86_REG_EAX,out);mu.reg_write(UC_X86_REG_ESP,sp+16);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x6e56a0:
  ret,index,pointer=n.unpack('<3I',sp);events.append({'edge':'deviceTransform','index':index,'words':list(n.unpack('<16I',pointer))});mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address in(0x5ff840,0x5fcc80):events.append({'edge':'lightState'if address==0x5ff840 else'renderCache'})
 elif address==0x5d8b60:
  _,center,extent,far,individual=n.unpack('<5I',sp);scratch=((sp-4)&~15)-4;visits.append({'center':list(n.unpack('<3f',center)),'extent':list(n.unpack('<3f',extent)),'farWord':far,'individual':individual,'scratchWord':n.unpack('<I',scratch)[0],'scratchAddress':hex(scratch),'lastWriteBytes':[lastWrites.get(scratch+i)for i in range(4)]})
 elif address in(0x5d8e97,0x5d8f5e):visits[-1]['nativeResult']=mu.reg_read(UC_X86_REG_EAX)
 elif address==0x5d8fb0:
  events.append({'edge':'tree','camera':readCamera()})
def writeHook(mu,access,address,size,value,_):
 if track:
  for i in range(size):lastWrites[address+i]=hex(mu.reg_read(UC_X86_REG_EIP))
for a in[0x715718,0x6e56a0,0x5ff840,0x5fcc80,0x5d8b60,0x5d8e97,0x5d8f5e,0x5d8fb0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
n.mu.hook_add(UC_HOOK_MEM_WRITE,writeHook,begin=n.STACK,end=n.STACK+0xffff)
def multiply(a,b):
 out=[]
 for i in range(4):
  for j in range(4):
   total=0.
   for k in range(4):total+=float(a[i*4+k])*b[k*4+j]
   out.append(f32(total))
 return out
def dot(a,b,order=(0,1,2)):
 products=[M(W(a[i]),W(b[i]))for i in order];out=S(A(A(products[0],products[1]),products[2]))
 if all(x==0 or y==0 for x,y in zip(a,b))and all((word(x)^word(y))&0x80000000 for x,y in zip(a,b)):out=-0.
 return out

def modelTransform(view,local,direction,position):
 outer,inner=[multiply(view,a)for a in local];q=dot(direction,position,(1,0,2));return {'outer':outer,'inner':inner,'absOuter':[abs(v)for v in outer[:12]]+[0.]*4,'absInner':[abs(v)for v in inner[:12]]+[0.]*4,'depth':direction+[-q],'absDepth':[abs(v)for v in direction]+[0.]}

def inverse(camera):
 out=[0.]*16
 for i in range(3):
  for j in range(3):out[i*4+j]=camera[j*4+i]
 neg=[-camera[12+i]for i in range(3)];out[12]=dot(neg,[out[0],out[4],out[8]],(0,1,2));out[13]=dot(neg,[out[1],out[5],out[9]],(1,0,2));out[14]=dot(neg,[out[2],out[6],out[10]],(0,1,2));out[15]=1.;return out

def trig(fov):
 half=f32(fov*.5);angle=int(half*angleScale);return sine[(angle>>1)&32767],sine[((angle+16384)>>1)&32767]
def projection(camera,g):
 sin,cos=trig(camera[16]);cot=S(D(W(cos),W(sin)));ratio=S(D(W(camera[19]),sub(W(camera[19]),W(camera[18]))));out=[0.]*16;out[0]=f32(cot*camera[17]);out[5]=cot;out[10]=ratio;out[11]=1.;out[14]=f32(-ratio*camera[18]);out[0]=f32(out[0]*g['correction'][0]);out[5]=f32(out[5]*g['correction'][1]);out[8]=g['correction'][2];out[9]=g['correction'][3];return out

def clipping(camera,g,asymmetric):
 sin,cos=trig(camera[16]);cot=S(D(W(cos),W(sin)));near=camera[24]if camera[24]!=0 else camera[18];far=f32((camera[25]if camera[25]!=0 else camera[19])-g['farBias']);den=sub(W(far),W(near));sc=g['clipScales'][2:]if asymmetric else g['clipScales'][:2];out=[0.]*16
 out[0]=S(M(M(W(camera[17]),W(sc[0])),W(cot)))if asymmetric else S(M(M(W(camera[17]),W(cot)),W(sc[0])));out[5]=S(M(W(sc[1]),W(cot)));out[10]=S(D(A(W(near),W(far)),den));out[11]=1.;out[14]=S(D(M(M(W(far),W(-2)),W(near)),den));return out

def ordinaryFrustum(view,camera,scales,template):
 outer,inner=modelBuild(camera[18],scales,template)
 for a in[outer,inner]:
  for index in[6,7,8,9,10,11]:a[index]=-a[index]
 outer=multiply(view,outer);inner=multiply(view,inner);direction=camera[8:11];position=camera[12:15];q=dot(direction,position,(1,0,2));nc=f32(-q-camera[18]);fc=f32(camera[19]+q);nf=[0.]*16
 for i,v in enumerate(direction):nf[i*4:i*4+4]=[-v,v,abs(v),abs(v)]
 nf[12:16]=[fc,nc,abs(fc),abs(nc)];depth=direction+[nc];return b''.join(struct.pack('<'+str(len(a))+'f',*a)for a in[outer,inner,nf,depth,[abs(v)for v in outer[:12]]+[0.]*4,[abs(v)for v in inner[:12]]+[0.]*4])

def modelApply(state,camera,g,restore=False):
 state['current']=list(camera);view=inverse(camera)
 for col in range(3):
  for row in range(4):view[row*4+col]=f32(view[row*4+col]*camera[27+col])
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

def modelSwitch(state,requested,g):
 if requested!=state['mode']and state['mode']==0:state['base']=list(state['current'])
 if requested!=0:state['saved']=list(state['current']);modelApply(state,state['base'],g,True)
 state['mode']=requested;return state

def stateModel():
 a=readCamera();return {'current':list(n.unpack('<30f',0x9736e8)),'base':list(n.unpack('<30f',0x971b00)),'saved':list(n.unpack('<30f',0x973760)),'mode':a['mode'],'previousCullingMode':a['previousCullingMode'],'matrices':{k:list(n.unpack('<16f',v))for k,v in matrixKeys.items()},'scales':[n.unpack('<f',a)[0]for a in scaleAddresses],'frustum':n.read(0x963fa0,336),'passWord':a['passWord'],'resetWord':a['resetWord']}
def encoded(state):return {'currentWords':words(state['current']),'baseWords':words(state['base']),'savedWords':words(state['saved']),'mode':state['mode'],'previousCullingMode':state['previousCullingMode'],'matrixWords':{k:words(v)for k,v in state['matrices'].items()},'scaleWords':words(state['scales']),'frustumHex':state['frustum'].hex(),'passWord':state['passWord'],'resetWord':state['resetWord']}
def cameraSeed(index):
 yaw=.15*(index%11-5);c=f32(math.cos(yaw));s=f32(math.sin(yaw));return [c,0.,-s,0.,0.,1.,0.,0.,s,0.,c,0.,f32(index%7-3),f32(index%3-1),f32(index%5-2),1.,f32(.4+(index%13)*.1),f32(.8+(index%7)*.2),f32(.1+(index%5)*.2),f32(50+index%11*20),f32((index%5-2)*.05),f32((index%3-1)*.05),f32(.8+(index%3)*.1),f32(.8+(index%4)*.1),0.,0.,0.,f32(.8+(index%4)*.2),f32(.8+(index%3)*.2),f32(.8+(index%5)*.2)]
def globalsSeed(index):
 return {'correction':[f32(.75+(index%5)*.1),f32(.85+(index%4)*.1),f32((index%7-3)*.03),f32((index%5-2)*.02)],'clipScales':[f32(.8+(index%4)*.1),f32(.9+(index%3)*.1),f32(.7+(index%5)*.1),f32(.8+(index%4)*.1)],'farBias':f32(index%5*.25),'orthographic':bool(index%7==0),'orthographicScale':f32(.01+(index%5)*.005),'cullingMode':index%2,'previousCullingMode':1-index%2,'screenSize':[640+index%3*80,480+index%3*40],'sourceSize':[600+index%4*70,420+index%4*30],'template':[0.]*16,'auxiliary':[1. if i%5==0 else f32((index%3-1)*.02)for i in range(16)],'clipTransform':[1. if i%5==0 else f32((index%5-2)*.01)for i in range(16)]}
def setup(camera,g,base=None,saved=None,mode=0):
 n.pack('<30f',0x9736e8,*camera);n.pack('<30f',0x971b00,*(base or cameraSeed(31)));n.pack('<30f',0x973760,*(saved or cameraSeed(57)));n.pack('<16f',0x95e600,*g['template']);n.pack('<16f',0x971620,*g['auxiliary']);n.pack('<16f',0x80ba68,*g['clipTransform']);n.pack('<16f',0x80b788,*[f32((i-8)*.125)for i in range(16)]);n.pack('<16f',0x97ba90,*[f32((i-8)*.0625)for i in range(16)])
 for a,v in zip([0x28492f8,0x981c48,0x992294,0x981c94],g['correction']):n.pack('<f',a,v)
 for a,v in zip([0x963e40,0x963e44,0x963e48,0x963e4c],g['clipScales']):n.pack('<f',a,v)
 n.pack('<f',0x80b9c8,g['farBias']);n.pack('<f',0x80b9cc,g['orthographicScale'])
 for a,v in zip([0x973900,0x973904,0x80e69c,0x80e6a0],g['screenSize']+g['sourceSize']):n.pack('<i',a,v)
 for a,v in[(0x973944,0),(0x973958,int(g['orthographic'])),(0x973950,g['cullingMode']),(0x973954,g['previousCullingMode']),(0x95e674,0),(0x97394c,mode)]:n.pack('<i',a,v)
 n.write(0x80bbe0,b'\0\0')
IN=n.DATA+0x80000;OUT=IN+0x1000
for case in range(768):
 matrix=[f32(rng.uniform(-10,10))for _ in range(16)]
 if case<64:matrix=cameraSeed(case)[:16]
 n.pack('<16f',IN,*matrix);target=IN if case%3==0 else OUT;n.pack('<2I',OUT-4,0xabcd1234,0);n.call(0x5c0940,[target,IN]);native=list(n.unpack('<16I',target));ck(native,words(inverse(matrix)),['inverse',case]);inverseCases.append({'inputWords':words(matrix),'inPlace':target==IN,'nativeWords':native})
for case in range(512):
 camera=cameraSeed(case);g=globalsSeed(case);setup(camera,g);n.call(0x604a80,[0x80b748,word(camera[16]),word(camera[17]),word(camera[18]),word(camera[19])]);native=list(n.unpack('<16I',0x80b748));ck(native,words(projection(camera,g)),['projection',case]);projectionCases.append({'camera':camera,'globals':g,'nativeWords':native})
for case in range(512):
 camera=cameraSeed(case);g=globalsSeed(case)
 if case%4==0:camera[24]=f32(camera[18]+.1)
 if case%5==0:camera[25]=f32(camera[19]+10)
 setup(camera,g);n.pack('<30f',IN,*camera);view=inverse(camera);n.pack('<16f',OUT,*view)
 for asymmetric,address in[(False,0x5ed300),(True,0x5ed420)]:
  n.call(address,[OUT+0x100,OUT,IN,0]);cache=0x97ba90 if asymmetric else 0x80b8c8;actual=list(n.unpack('<16I',cache));expected=clipping(camera,g,asymmetric);ck(actual,words(expected),['clippingCache',case,asymmetric]);ck(list(n.unpack('<16I',OUT+0x100)),words(multiply(view,expected)),['clippingOutput',case,asymmetric]);clipCases.append({'camera':camera,'globals':g,'view':view,'asymmetric':asymmetric,'nativeCacheWords':actual,'nativeWords':list(n.unpack('<16I',OUT+0x100))})
for case in range(512):
 camera=cameraSeed(case);g=globalsSeed(case);setup(camera,g);view=[f32(rng.uniform(-3,3))for _ in range(16)];scales=[f32(rng.uniform(.1,2))for _ in range(4)];n.pack('<16f',0x80b708,*view)
 for a,v in zip(scaleAddresses,scales):n.pack('<f',a,v)
 n.call(0x5d5500);native=n.read(0x963fa0,336).hex();ck(native,ordinaryFrustum(view,camera,scales,g['template']).hex(),['ordinaryFrustum',case]);frustumCases.append({'camera':camera,'view':view,'scales':scales,'template':g['template'],'nativeHex':native})
for case in range(384):
 camera=cameraSeed(case);g=globalsSeed(case);setup(camera,g);n.pack('<30f',IN,*camera);before=readCamera();state=stateModel();events.clear();kind='apply'if case%3==0 else'restore'if case%3==1 else'switch';requested=[-1,0,1,2][case%4]
 if kind=='apply':n.call(0x5ed540,[IN,0]);modelApply(state,camera,g)
 elif kind=='restore':n.call(0x603cc0,[IN]);modelApply(state,camera,g,True)
 else:
  mode=[-1,0,1,2][case//4%4];n.pack('<i',0x97394c,mode);before=readCamera();state=stateModel();n.call(0x5d6900,[requested]);modelSwitch(state,requested,g)
 after=readCamera();expected=encoded(state);ck(after,expected,['camera',case,kind]);cameraCases.append({'kind':kind,'camera':camera,'globals':g,'requested':requested,'before':before,'native':after,'nativeEvents':list(events)})
# Full visibility dispatcher, including actual camera switch/restore and populated tree.
phase4=json.loads(gzip.decompress((R/'scene-phase4-20261013-native-fixtures.json.gz').read_bytes()));SC=n.DATA;TREE=SC+0x1000;NODES=SC+0x2000;NODEB=SC+0x3000;ITEMB=SC+0x5000;LIST=SC+0x7000;ROOTS=SC+0x8000;FARS=SC+0x9000;BITS=SC+0xa000
for case in range(192):
 original=phase4['composedCases'][case%192];tree=original['tree'];camera=cameraSeed(case);g=globalsSeed(case);setup(camera,g,base=cameraSeed(case+17),mode=case%3);n.pack('<30f',IN,*camera);n.call(0x603cc0,[IN]);mode=case%3;n.pack('<i',0x97394c,mode);requested=case//3%3;visible=case%13!=0;workspace=BITS if case%17 else 0;present=case%11!=0;enabled=case%7!=0
 n.write(SC,bytes(0x160));n.pack('<i',SC+0x1c,32);n.pack('<I',SC+0x134,TREE if present else 0);n.pack('<I',SC+0x148,0xc012);n.pack('<I',SC+0x140,0xabcdef);n.pack('<I',SC+0x144,0x12345678);n.pack('<i',SC+0x120,-7);n.pack('<I',0x973988,0x12345678)
 for a,v in[(0x80b6f4,int(visible)),(0x80b6f8,0),(0x80ba14,int(enabled)),(0x80ba58,0),(0x973940,requested),(0x973984,0)]:n.pack('<i',a,v)
 n.write(TREE,bytes(0x40));n.pack('<I',TREE+8,LIST);n.pack('<I',TREE+12,ITEMB);n.pack('<I',TREE+0x14,NODES);n.pack('<I',TREE+0x18,NODEB);n.pack('<H',TREE+0x1c,len(tree['roots']));n.pack('<I',TREE+0x20,ROOTS);n.pack('<I',TREE+0x24,FARS);n.pack('<32H',LIST,*tree['members']);n.pack('<5H',ROOTS,*tree['roots']);n.pack('<5f',FARS,*tree['far'])
 for i,v in enumerate(tree['nodes']):n.pack('<6H',NODES+12*i,*v)
 for addr,records in[(NODEB,tree['nodeBounds']),(ITEMB,tree['itemBounds'])]:
  for i,b in enumerate(records):n.pack('<8f',addr+32*i,*b['center'],0,*b['extent'],0)
 beforeBits=bytes.fromhex(original['beforeHex']);n.write(BITS,beforeBits);n.write(n.STACK,struct.pack('<f',[-100.,0.,1.,100.][case%4])*0x4000);events.clear();visits.clear();lastWrites.clear();beforeCamera=readCamera();beforeVisibility=bool(n.unpack('<I',0x97393c)[0]);state=stateModel();track=True;ret=n.call(0x5f3c80,[SC,workspace]);track=False;active=bool(workspace and visible);treeActive=active and present and enabled;flags=0xc012;count=-7;scratch=0xabcdef;pointer=0x12345678
 if active:
  modelSwitch(state,requested,g);flags&=0xffffffea;count=32;scratch=0;pointer=0
  if treeActive:scratch=workspace;flags|=17
  if state['mode']==1:modelApply(state,state['saved'],g,True)
 ck(bool(n.unpack('<I',0x97393c)[0]),True if active else beforeVisibility,['dispatcherVisibilityActive',case]);ck(bool(n.unpack('<I',0x973984)[0]),treeActive,['dispatcherPlanesInitialized',case]);ck(n.unpack('<I',0x973988)[0],SC+0x120 if treeActive else 0x12345678,['dispatcherCurrentTreeContext',case]);ck(readCamera(),encoded(state),['dispatcherCamera',case]);ck(ret,SC+0x120 if active else 0,['dispatcherReturn',case]);ck(list(n.unpack('<i',SC+0x120))+list(n.unpack('<3I',SC+0x140)),[count,scratch,pointer,flags],['dispatcherContext',case]);actualBits=n.read(BITS,8);bits=bytearray(beforeBits);at=0
 if treeActive:
  treeCamera=next(e['camera']for e in events if e['edge']=='tree');view=[struct.unpack('<f',struct.pack('<I',w))[0]for w in treeCamera['matrixWords']['view']];cam=[struct.unpack('<f',struct.pack('<I',w))[0]for w in treeCamera['currentWords']];scales=[struct.unpack('<f',struct.pack('<I',w))[0]for w in treeCamera['scaleWords']];p=modelTransform(view,modelBuild(cam[18],scales,g['template']),cam[8:11],cam[12:15]);p.update(near=cam[18],globalFar=cam[19])
  for ri in range(len(tree['roots'])-1,-1,-1):
   far=tree['far'][ri]or p['globalFar'];stack=[tree['roots'][ri]]
   while stack:
    node=tree['nodes'][stack.pop()];b=tree['nodeBounds'][node[0]];v=visits[at];at+=1;result=classify(p,b['center'],b['extent'],far,0,v['scratchWord']);ck(result,v['nativeResult'],['dispatcherNode',case,at])
    if result==0:continue
    if result==1:
     for i in tree['members'][node[5]:node[5]+node[1]]:bits[i>>2]|=1<<((i&3)*2)
    else:
     stack.extend(range(node[3],node[3]+node[2]))
     for li in range(node[5],node[5]+node[4]):
      b=tree['itemBounds'][li];v=visits[at];at+=1;result=classify(p,b['center'],b['extent'],far,1,v['scratchWord']);ck(result,v['nativeResult'],['dispatcherLeaf',case,at]);i=tree['members'][li];bits[i>>2]|=result<<((i&3)*2)
 ck(at,len(visits),['dispatcherVisits',case]);ck(actualBits.hex(),bits.hex(),['dispatcherBits',case]);dispatchCases.append({'camera':camera,'globals':g,'tree':tree,'mode':mode,'requested':requested,'visible':visible,'workspacePresent':bool(workspace),'present':present,'enabled':enabled,'workspaceToken':workspace,'beforeCamera':beforeCamera,'beforeVisibilityActive':beforeVisibility,'nativeVisibilityActive':bool(n.unpack('<I',0x97393c)[0]),'nativePlanesInitialized':bool(n.unpack('<I',0x973984)[0]),'nativeCurrentTreeContextChanged':n.unpack('<I',0x973988)[0]==SC+0x120,'nativeCamera':readCamera(),'beforeHex':beforeBits.hex(),'nativeHex':actualBits.hex(),'nativeContext':{'count':count,'scratch':scratch,'pointer':pointer,'flags':flags},'returned':bool(ret),'nativeVisits':list(visits),'nativeEvents':list(events)})
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly={hex(a):[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in md.disasm(n.read(a,size),a)]for a,size in[(0x5c0940,0xd4),(0x604a80,0xc8),(0x5ed300,0x11a),(0x5ed420,0x112),(0x5d5500,0x4ae),(0x5ed540,0x451),(0x603cc0,0x5b),(0x5d6900,0x51),(0x5f3c80,0xd8)]}
(R/(PREFIX+'-assembly.json')).write_text(json.dumps({'binarySHA256':n.sha256,'functions':assembly},indent=2)+'\n')
for cases in[projectionCases,clipCases,frustumCases,cameraCases,dispatchCases]:
 for c in cases:
  c['cameraWords']=words(c['camera'])
  if 'view'in c:c['viewWords']=words(c['view'])
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt',encoding='utf8')as f:json.dump({'sineFile':'references/native-animation-sine-table.f32','sineSHA256':hashlib.sha256(sineBytes).hexdigest(),'angleScale':angleScale,'inverseCases':inverseCases,'projectionCases':projectionCases,'clipCases':clipCases,'frustumCases':frustumCases,'cameraCases':cameraCases,'dispatchCases':dispatchCases},f)
counts={k:len(v)for k,v in[('inverseCases',inverseCases),('projectionCases',projectionCases),('clipCases',clipCases),('frustumCases',frustumCases),('cameraCases',cameraCases),('dispatchCases',dispatchCases)]};counts['retainedPortableReplayCases']=sum(counts.values());counts['nestedDispatcherPredicateCalls']=sum(len(c['nativeVisits'])for c in dispatchCases)
writerCounts={};wordCounts={}
for c in dispatchCases:
 for v in c['nativeVisits']:
  writers=','.join(sorted(set(x or'external seed'for x in v['lastWriteBytes'])));writerCounts[writers]=writerCounts.get(writers,0)+1;raw=hex(v['scratchWord']);wordCounts[raw]=wordCounts.get(raw,0)+1
report={'stackResidue':{'writerCounts':writerCounts,'wordCounts':wordCounts,'frameAddress':'0x1000de0c','note':'NativeX86 fixed entry ESP only; portable uses actual percall word. OriginalCRT sqrt call0x6e953b writes returnaddress0x6e9540 at this deeper caller lifetime on routes that switch camera before traversal; other routes retain external prior seed.'},'schema':'original-normal-camera-visibility-composition-v1','passed':not errors,'checks':checks,'counts':counts,'errors':errors[:30],'binarySHA256':n.sha256,'sineTable':{'file':'references/native-animation-sine-table.f32','sha256':hashlib.sha256(sineBytes).hexdigest()},'angleScale':angleScale,'adapters':{'0x715718':'Imported D3DXMatrixMultiply finite scalar adapter: sequential binary64 dot sum spilled tofloat32; original5c1240/5c0500 wrappers run unchanged. Platform CPU policy unresolved.','0x6e56a0':'Device SetTransform(index,matrix) recorded; GPU/backend operation not performed.'},'unchangedNative':['0x5c0940','0x604a80','0x5ed300','0x5ed420','0x5d5500','0x5ed540','0x603cc0','0x5d6900','0x5f3c80','0x5ff840','0x5fcc80','0x5d86f0','0x5d8950','0x5d8fb0','0x5d8e20','0x5d8b60'],'limits':['Normal camera conversion973944=0, viewportdirty95e674=0, Apply param2=0. Perspective and orthographic973958 branches; culling973950=0/nonzero.','Finite30-word camera/metadata, positive near/FOV/nonzeroaspect and valid finite denominators, int32-fitting angle conversion. No reflected/alternate camera matrix path or projection reuse claimed.','Camera light/render cache native helpers execute unchanged, but their renderer global byte outputs are excluded from portable numeric camera projection and represented by explicit host callbacks.','Original device transform service is recorded only; imported D3DX policy remains an explicit finite scalar adapter.','Populated synthetic resolved trees and exact finite fourth-radius word perpredicate. Authored loading and external stack history remain unresolved.','Complete visibility preparation route for grid/portal disabled; no complete frame submission/GPU/wholegame equivalence.','Native/Python own-state contract verified; compiled C# replay remains a separate validation step.'],'fixtureFile':PREFIX+'-native-fixtures.json.gz'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));sys.exit(0 if not errors else 1)
