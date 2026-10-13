"""Original outer shadow selection596a30; math backend retained as explicit service."""
import ast,json,struct,gzip,hashlib,math,random,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';p=B/'tools/geometry-shadow-light-native.py';tree=ast.parse(p.read_text());body=[]
for node in tree.body:
 if isinstance(node,ast.Assign)and any(isinstance(t,ast.Name)and t.id=='cases'for t in node.targets):break
 body.append(node)
l={'__file__':str(p)};exec(compile(ast.Module(body=body,type_ignores=[]),str(p),'exec'),l);e=l['e'];v=l['v'];n=l['n'];x=l['x'];W=x.wide;add=x.add;mul=x.mul;div=x.div;store=l['store'];f32=l['f32'];D=n.DATA;SIZE=0x20000;WORLD=D+0x1000;INFO=D+0x7000;LIGHT=D+0x7800;MODEL=D+0x7900;DESC=D+0x7a00;PLAYERS=[D+0x8000,D+0x9000];CAM=D+0xa000;ALT=D+0xa100;FIXED=D+0xa200;CONTEXTS=[D+0x10000,D+0x11000];CUTMIRROR=D+0xc000;MIRROR=D+0x1f000;PROJECTION=MIRROR+0x100;VIEW=MIRROR+0x140
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_ESP
events=[];power=[]
def capture(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x5be630:power.append(dict(arguments=list(n.unpack('<2f',sp+4))))
 elif address==0x596e9c:power[-1]['result']=n.unpack('<f',sp+0x20)[0]
 elif address==0x5952c0:
  a,b,c=n.unpack('<3I',sp+4);events.append(dict(kind='view',context=mu.reg_read(UC_X86_REG_ECX),eye=list(n.unpack('<3f',a)),target=list(n.unpack('<3f',b)),up=list(n.unpack('<3f',c))))
 elif address==0x5e8950:
  camera,cuts,count=n.unpack('<3I',sp+4);events.append(dict(kind='extract',context=mu.reg_read(UC_X86_REG_ECX),camera=camera,cuts=list(n.unpack('<'+'f'*count,cuts))))
for address in [0x5be630,0x596e9c,0x5952c0,0x5e8950]:n.mu.hook_add(UC_HOOK_CODE,capture,begin=address,end=address)
def read(image,p,count):return list(struct.unpack_from('<'+'f'*count,image,p-D))
def word(image,p):return struct.unpack_from('<I',image,p-D)[0]
def write(image,p,values):struct.pack_into('<'+'f'*len(values),image,p-D,*values)
def put(image,p,value):struct.pack_into('<I',image,p-D,value&0xffffffff)
def arithmetic_subproduct(a,b,c):return store(add(W(a),mul(W(-b),W(c))),a-b*c)
def distance(a,b):
 d=[f32(a[i]-b[i])for i in range(3)];return f32(math.sqrt(v['dot'](d,d)))
constants=[n.unpack('<f',a)[0]for a in range(0x805100,0x805128,4)]
def model(before,config,powerResult):
 out=bytearray(before);mode=config['mode'];active=[i for i,p in enumerate(config['players'])if p and before[p+0x1fc-D]&0x80];height=read(before,MIRROR,1)[0];fixed=read(before,FIXED,20);ci=lambda offset:read(before,INFO+offset,3);light=read(before,LIGHT,13);r=constants[8];expectedEvents=[];unknown=[]
 if mode:
  target=[store(add(mul(W(fixed[j+8]),W(2)),W(fixed[j+12])),fixed[j+8]*2+fixed[j+12])for j in range(3)];height=-2.
 else:
  if not active:return out,[],[],None
  target=[0.,0.,0.]
  for i in active:target=[f32(target[j]+read(before,config['players'][i]+0x5c,3)[j])for j in range(3)]
  target=[f32(z*f32(1/len(active)))for z in target];height=light[12]
 write(out,MIRROR,[height])
 if not config['lightPresent']:return out,[],[],None
 offsetTarget=target.copy();offsetTarget[1]=f32(height+target[1]);override=bool(config['modelPresent']and config['modelFlag']and not config['descriptorFlag'])
 if mode:direction=light[:3];strength=light[3];fallback=False
 else:
  direction=config['seed'].copy();strength=-1.
  for i in active:
   actor=config['players'][i];direction=[f32(direction[j]+read(before,actor+0x5fc,3)[j])for j in range(3)];candidate=read(before,actor+0x608,1)[0]
   if strength<=candidate:strength=candidate
  if active:direction=[f32(z*f32(1/len(active)))for z in direction]
  fallback=not active or strength<0
  if not fallback:direction=v['normal']([f32(direction[j]+light[j])for j in range(3)])
 if fallback:
  position=ci(0x11c);first=[f32(position[0]-1.2000000476837158),constants[7],f32(position[2]-1.5)];second=first.copy()
 else:
  first=[arithmetic_subproduct(target[j],r,direction[j])for j in range(3)];second=[f32(target[0]+r*2),f32(target[1]+r*10),f32(target[2]+r*2)]
 if override:strength=.5
 selectedCamera=CAM
 if mode:forward=ci(0xd8);cameraPosition=ci(0xe8)
 elif config['alternate']:forward=fixed[8:11];cameraPosition=fixed[12:15];selectedCamera=ALT
 else:cameraPosition=ci(0x11c);forward=[f32(a-b)for a,b in zip(ci(0x128),cameraPosition)]
 forward=v['normal'](forward);factor=f32(min(1.,forward[1]+1.));separation=distance(cameraPosition,offsetTarget);far=16. if override else light[8];powerArgs=[factor,constants[6]];assert powerResult is not None
 end=store(add(W(separation),mul(W(powerResult),add(W(far),W(-separation)))),separation+powerResult*(far-separation));start=read(before,CAM+0x48,1)[0];cuts=[start,f32(start+constants[5]),end]if mode else[start,end];put(out,MIRROR+4,3 if mode else 1)
 ctx=CONTEXTS[0];write(out,ctx+0x80c,[strength if override else light[3],light[4],light[5]])
 for at in [0x100,0x480]:write(out,ctx+at,[light[7],light[6]]);write(out,ctx+at+0x10,[constants[1]])
 write(out,ctx+0x81c,[f32(end*constants[0]),end]);write(out,CONTEXTS[1]+0x80c,[strength]);write(out,CUTMIRROR,cuts)
 for ctx,eye in zip(CONTEXTS,[first,second]):
  matrix,direction=l['lookat'](eye,target,constants[2:5]);write(out,ctx+0x760,eye+[1.]);write(out,ctx+0x770,direction+[1.]);write(out,ctx+0x780,matrix);expectedEvents.extend([dict(kind='view',context=ctx,eye=eye,target=target,up=constants[2:5]),dict(kind='extract',context=ctx,camera=selectedCamera,cuts=cuts)]);e['CTX']=ctx;e['CAM']=selectedCamera;e['CUTS']=CUTMIRROR;e['PROJECTION']=PROJECTION;e['VIEW']=VIEW;out,padding,_=e['model'](out,len(cuts));unknown.extend(padding)
 return out,expectedEvents,unknown,powerArgs
cases=[];counts=collections.Counter()
def execute(index,mode,alternate,activeMask,negativeStrength,overrideKind=0,lightPresent=True,authoredMatrix=None):
 before=bytearray((i*37+index*13)&255 for i in range(SIZE));identity=authoredMatrix or [1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,5.,-20.,1.];write(before,CAM,identity+[1.,1.3333333730697632,.1,1000.]);alt=identity.copy();alt[12]=3.;write(before,ALT,alt+[.8,1.,.2,800.]);fixed=identity.copy();fixed[9]=[-.8,0.,.2][index%3];write(before,FIXED,fixed+[1.,1.,.1,1000.]);write(before,LIGHT,[.2,-.8,.3,.6,4.,.25,.001,.01,80.,0.,0.,0.,-2.]);write(before,INFO+0x11c,[f32((index-70)*.03125),5.,-20.]);write(before,INFO+0x128,[0.,[5.,-10.,10.][index%3],0.]);write(before,INFO+0xd8,[0.,[-.7,0.,.4][index%3],1.]);write(before,INFO+0xe8,[0.,5.,-20.]);write(before,MIRROR,[-2.]);put(before,MIRROR+4,0xa5a5a5a5);put(before,WORLD+0x5110,LIGHT if lightPresent else 0);put(before,WORLD+0x12c,MODEL if overrideKind else 0);put(before,WORLD+0x128,DESC);struct.pack_into('<H',before,MODEL+0x7a-D,0x100 if overrideKind in [1,2] else 0);put(before,DESC+0x64,0x400 if overrideKind==2 else 0);players=[]
 for j,actor in enumerate(PLAYERS):
  players.append(actor);before[actor+0x1fc-D]=0x80 if activeMask>>j&1 else 0;write(before,actor+0x5c,[float(j*2),5.+j,1.+j]);write(before,actor+0x5fc,[.1,-.6,.2]);write(before,actor+0x608,[-1. if negativeStrength else[0.,.5,1.][index%3]])
 config=dict(mode=mode,alternate=alternate,players=players,seed=[0.,0.,0.],modelPresent=bool(overrideKind),modelFlag=overrideKind in [1,2],descriptorFlag=overrideKind==2,lightPresent=lightPresent);n.write(D,before);n.write(0x9736e8,before[FIXED-D:FIXED-D+80]);n.pack('<I',0x802c54,WORLD);n.pack('<I',0x8021b4,INFO);n.pack('<2I',0x93d7f0,*players);n.pack('<3f',0x95e5c8,*config['seed']);n.pack('<I',0x951be8,mode);n.pack('<I',0x87b4d8,alternate);n.pack('<I',0x925164,CAM);n.pack('<I',0x2912e78,ALT);n.pack('<2I',0x955b38,*CONTEXTS);n.pack('<I',0x955b40,word(before,MIRROR+4));n.pack('<f',0x805124,-2.);n.write(e['NATIVE_PROJECTION'],before[PROJECTION-D:PROJECTION-D+64]);n.write(e['NATIVE_VIEW'],before[VIEW-D:VIEW-D+64]);n.pack('<I',0x8066c4,1);n.pack('<I',0x95e644,0);n.pack('<I',0x29a9c48,index&1);n.write(n.STACK,struct.pack('<I',0x12345678)*16384);events.clear();power.clear();n.call(0x596a30,count=3000000);actual=bytearray(n.read(D,SIZE));write(actual,MIRROR,[n.unpack('<f',0x805124)[0]]);put(actual,MIRROR+4,n.unpack('<I',0x955b40)[0]);actual[PROJECTION-D:PROJECTION-D+64]=n.read(e['NATIVE_PROJECTION'],64);actual[VIEW-D:VIEW-D+64]=n.read(e['NATIVE_VIEW'],64)
 if events:write(actual,CUTMIRROR,events[-1]['cuts'])
 expected,wantedEvents,unknown,powerArgs=model(before,config,power[0]['result']if power else None);padding=[word(actual,p+D)for p in unknown]
 for p in unknown:actual[p:p+4]=before[p:p+4]
 if actual!=expected or events!=wantedEvents or power and power[0]['arguments']!=powerArgs:raise AssertionError(dict(index=index,config=config,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:30],events=events,wantedEvents=wantedEvents,power=power,powerArgs=powerArgs))
 counts['cases']+=1;counts['persistentBytes']+=SIZE;counts['earlyReturn']+=not bool(events);counts['contextExtractions']+=sum(q['kind']=='extract'for q in events);cases.append(dict(index=index,before=bytes(before).hex(),config=config,nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeEvents=events.copy(),powerBoundary=power.copy(),undefinedWordOffsets=unknown,nativeUndefinedWords=padding))
for mode in [0,1]:
 for alternate in [0,1]:
  for activeMask in [0,1,2,3]:
   for negative in [False,True]:
    for override in [0,1,2,3]:execute(len(cases),mode,alternate,activeMask,negative,override)
cp='exports/cutscenes/LEVELS/EPISODE_V/ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.CU2.json'
for item in json.loads((B/cp).read_text())['cameras']['cameras']:
 for mode in [0,1]:
  for alternate in [0,1]:execute(len(cases),mode,alternate,3,False,1,authoredMatrix=item['matrix'])
for mode,mask in [(0,0),(1,0),(1,3)]:execute(len(cases),mode,0,mask,False,lightPresent=False)
fp=R/'geometry-shadow-selection-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,world=WORLD,info=INFO,light=LIGHT,model=MODEL,descriptor=DESC,camera=CAM,alternateCamera=ALT,fixedCamera=FIXED,contexts=CONTEXTS,cutMirror=CUTMIRROR,globalMirror=MIRROR,projection=PROJECTION,view=VIEW,constants=constants,cases=cases,sineTable=dict(file='references/native-animation-sine-table.f32',sha256=hashlib.sha256(v['ns']['TABLE']).hexdigest())),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-selection-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Original596a30,actual player queries/camera getters/vector/distance/CRTpower/lightsetup/extraction helpers execute unchanged; only passive observation hooks.','Power5be630 caller boundary is explicit: native arguments/result retained and supplied to portable caller model, not a claim of portable CRT/cache reconstruction.','Persistent finite validworld/model/light/camera/twocontext fixtures. Normal-mode activeplayers with nulllight dereferencebeforeguard is excluded; original earlyreturn cases separately covered.','Meaningful persistentbytes,globalheight/cutmask andcamera globalmatrixoutputs checked. Original temporary cuts are captured into an explicit fixturemirror; proven undefined extractionpadding normalized only.','Camera/light/actorrecords are controlled exactlayouts, not claimed runtimeentityloading. Managed comparison pending; originalwhole-frame scheduling/GPU excluded.']);(R/'geometry-shadow-selection-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))

