"""Original CameraCut command chain with real numeric, locator, scene and actor lookup."""
from pathlib import Path
# Reuse isolated camera-state setup/model definitions, not its test batch.
exec(compile(Path(__file__).with_name('native-camera-state-verify.py').read_text().split('vals=[')[0],str(Path(__file__).with_name('native-camera-state-verify.py')),'exec'))
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
state_setup=setup;state_model=model
SYS=D+0x4000;CRE=D+0x5000;PACK=D+0x6000;SCRIPT=D+0x6400;LOC=D+0x8000;ACT=D+0x10000;DEF=D+0x15000;NAMES=D+0x18000;ARGS=D+0x20000;TEXT=D+0x21000;W=D+0x30000;SCENE=D+0x31000;STATIC=D+0x32000;INSTANCE=D+0x33000;DISPLAY=D+0x34000;DYNAMIC=D+0x35000;OVERRIDE=D+0x36000
sine=struct.unpack('<32768f',(B/'references/native-animation-sine-table.f32').read_bytes());n.write(0x29899a0,struct.pack('<32768f',*sine));events=[];configured=[];allcalls={};rows=[];errors=[]
def text(p):return n.read(p,256).split(b'\0')[0].decode('latin1')
def cstr(s):return s.split('\0')[0]
def fold(s):return bytes(c-32 if 97<=c<=122 or c>=224 else c for c in cstr(s).encode('latin1'))
def ret(mu,value):
 sp=mu.reg_read(UC_X86_REG_ESP);ip=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ip)
def observe(mu,address,size,user):
 allcalls[hex(address)]=allcalls.get(hex(address),0)+1;sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x6e69ef:
  assert text(arg(1))=='Player%d';t='Player'+str(arg(2));n.write(arg(0),t.encode()+b'\0');ret(mu,len(t))
 elif address==0x5147c0:events.append(['number',text(arg(1))])
 elif address==0x51ac10:events.append(['locator',text(arg(1))])
 elif address==0x43c220:events.append(['character',text(arg(1))])
 elif address==0x5cf5b0:events.append(['scene',text(arg(2))])
 elif address==0x577880:configured.append(dict(camera=list(n.unpack('<3I',arg(0)))if arg(0)else None,target=list(n.unpack('<3I',arg(1)))if arg(1)else None,args=[arg(i)for i in range(2,10)],targetPointer=arg(1)))
for addr in [0x4509d0,0x5147c0,0x51ac10,0x43c220,0x5cf5b0,0x5cf510,0x5cf9e0,0x5b35a0,0x5b3620,0x5d6170,0x577880,0x6e69ef]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=addr,end=addr)
def f(x):return fl(bits(x))
def number(t):
 t=cstr(t);events_expected.append(['number',t]);low=t.lower()
 if 'param'in low:return 2.75
 if low in ['alpha','beta','gamma','delta']:return [2.75,1.5,3.,4.][['alpha','beta','gamma','delta'].index(low)]
 i=0;val=0.;den=1.
 if t.startswith('-'):i=1;den=-1.
 while i<len(t)and'0'<=t[i]<='9':val=f(f(val*10)+int(t[i]));i+=1
 if i<len(t)and t[i]=='.':
  i+=1
  while i<len(t)and'0'<=t[i]<='9':val=f(f(val*10)+int(t[i]));den=f(den*10);i+=1
 return f(val/den)
def defaults(tokens,**kw):
 o=dict(tokens=tokens,first=True,selfReference=True,callback=True,locatorName='loc',cameraLocatorName='cam',characterName='actor',sceneName='object',missingLocator=False,missingCharacter=False,missingScene=False,sceneMode='static',override='none',locator=[10.,20.,30.],cameraLocator=[-10.,-20.,-30.],actor=[40.,50.,60.],scene=[70.,80.,90.],overridePosition=[101.,102.,103.],currentCamera=[4.,5.,6.],state=base());o.update(kw);return o
def setup_command(o):
 state_setup(o['state']);n.write(SYS,bytes(0x34000));events.clear();configured.clear()
 n.pack('<II',SYS+0x24,2,LOC)
 for i,(name,v)in enumerate([(o['locatorName']if not o['missingLocator']else'absent',o['locator']),(o['cameraLocatorName'],o['cameraLocator'])]):
  assert len(name.encode('latin1'))<16;n.write(LOC+i*0x3c,cstr(name).encode('latin1')+b'\0');n.pack('<3f',LOC+i*0x3c+0x10,*v)
 n.pack('<I',CRE+0xd0,ACT if o['selfReference']else 0);n.pack('<I',ACT,ACT);n.pack('<I',ACT+0x54,DEF);n.pack('<I',ACT+0x1fc,1);n.pack('<3f',ACT+0x80,*o['actor']);n.pack('<I',DEF+0xc,NAMES);n.write(NAMES,(o['characterName']if not o['missingCharacter']else'absent').encode('latin1')+b'\0');n.pack('<II',0x93d500,1,ACT);n.pack('<I',0x923904,0x43c220 if o['callback']else 0);n.pack('<I',0x93d810,ACT);n.write(0x93d7f0,bytes(32));n.pack('<I',0x93d7f0,ACT)
 n.pack('<I',PACK+4,SCRIPT);n.pack('<4f',PACK+0x14,2.75,1.5,3.,4.)
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.pack('<I',SCRIPT+0x18+i*8,SCRIPT+0x80+i*32);n.write(SCRIPT+0x80+i*32,name.encode()+b'\0')
 n.pack('<I',0x802c54,W);n.pack('<I',W+0x13c,SCENE);n.pack('<I',0x97388c,0);n.pack('<3f',0x9736e8+0x30,*o['currentCamera'])
 n.pack('<II',SCENE+0x24,1,STATIC);n.pack('<I',SCENE+0x110,DISPLAY if o['sceneMode']=='dynamic'else 0);n.pack('<II',DISPLAY+0x6c,1,DYNAMIC);n.write(NAMES+256,(o['sceneName']if not o['missingScene']else'absent').encode('latin1')+b'\0');n.pack('<II',STATIC+0x40,INSTANCE,NAMES+256);n.pack('<I',DYNAMIC+0xb4,NAMES+256)
 n.pack('<3f',INSTANCE+0x30,*o['scene']);n.pack('<3f',DYNAMIC+0x70,*o['scene']);n.pack('<3f',OVERRIDE+0x30,*o['overridePosition']);override=OVERRIDE if o['override']=='valid'else 0xffffffff if o['override']=='minusone'else 0;n.pack('<I',INSTANCE+0x48,override);n.pack('<I',DYNAMIC+0xc4,override)
 for i,t in enumerate(o['tokens']):assert len(t)<255;n.pack('<I',ARGS+i*4,TEXT+i*256);n.write(TEXT+i*256,t.encode('latin1')+b'\0')
def locator(o,name):
 events_expected.append(['locator',name]);a=[(o['locatorName']if not o['missingLocator']else'absent',o['locator'],LOC+0x10),(o['cameraLocatorName'],o['cameraLocator'],LOC+0x4c)]
 return next(((v,p)for k,v,p in a if fold(k)==fold(name)),None)
def model_command(o):
 tokens=o['tokens'];q=dict(camera=True,target=True,extra=0,start=bits(0),end=bits(1e9),blendIn=bits(0),blendOut=bits(0),followTarget=False,followCamera=False,borders=1);v=json.loads(json.dumps(o['state']));before=snap();names={};tv=[1e9]*3;cv=[1e9]*3;dv=[0.]*3;current=False;rx=ry=0;distance=1.
 if not o['first']:return before,[]
 for raw in tokens:
  t=cstr(raw);low=fold(t).decode('latin1').lower()
  if low=='reset':
   q.update(camera=False,target=False,start=0,end=0,blendIn=0,blendOut=0,followTarget=False,borders=0);return state_model(v,'configure',q),[dict(camera=None,target=None,args=[0,0,0,0,0,0,0,0],targetPointer=0)]
  if low=='use_current_campos':current=True;continue
  if 'start_time='in low:q['start']=bits(number(t[low.index('start_time=')+11:]));continue
  if low=='end_time=infinite':q['end']=bits(1e9);continue
  found=False
  for key in ['end_time=','blend_in_time=','blend_out_time=','tgt_locator=','tgt_character=','tgt_obj=','cam_locator=','range=','roty=','rotx=']:
   if key not in low:continue
   s=t[low.index(key)+len(key):];found=True
   if key in ['end_time=','blend_in_time=','blend_out_time=']:q[{'end_time=':'end','blend_in_time=':'blendIn','blend_out_time=':'blendOut'}[key]]=bits(number(s))
   elif key in ['tgt_locator=','tgt_character=','tgt_obj=','cam_locator=']:names[key]=s
   elif key=='range=':distance=number(s)
   elif key=='roty=':ry=int(int(number(s))*182.04444885253906)
   else:rx=int(-int(number(s))*182.04444885253906)
   break
  if found:continue
  if low=='followtgt':q['followTarget']=True;continue
  for prefix,vec in [('dcampos_',dv),('campos_',cv),('tgtpos_',tv)]:
   for j,axis in enumerate('xyz'):
    key=prefix+axis+'='
    if key in low:vec[j]=number(t[low.index(key)+len(key):]);found=True;break
   if found:break
  if not found and low=='no_borders':q['borders']=0
 if 'tgt_locator='in names:
  target=locator(o,names['tgt_locator='])
  if target is None:return before,[]
  tv,ptr=target
 elif 'tgt_character='in names:
  name=names['tgt_character='];self_target=o['selfReference']and fold(name)==b'MYSELF'
  if not self_target:
   if not o['callback']:return before,[]
   events_expected.append(['character',name])
   if fold(name)not in [fold(o['characterName']if not o['missingCharacter']else'absent'),b'PLAYER',b'PLAYER0']:return before,[]
  tv=o['actor'];ptr=ACT+0x80
 elif 'tgt_obj='in names:
  name=names['tgt_obj='];events_expected.append(['scene',name])
  if fold(name)!=fold(o['sceneName']if not o['missingScene']else'absent'):return before,[]
  tv=o['overridePosition']if o['override']=='valid'else o['scene'];ptr=OVERRIDE+0x30 if o['override']=='valid'else DYNAMIC+0x70 if o['sceneMode']=='dynamic'else INSTANCE+0x30
 else:
  if 1e9 in tv:return before,[]
  assert not q['followTarget'];ptr=-1
 if current:cv=[f(a+b)for a,b in zip(o['currentCamera'],dv)]
 elif 1e9 in cv:
  camera=locator(o,names['cam_locator='])if'cam_locator='in names else None
  if camera is not None:cv=camera[0]
  else:
   sx,cx=sine[(rx>>1)&32767],sine[((rx+16384)>>1)&32767];sy,cy=sine[(ry>>1)&32767],sine[((ry+16384)>>1)&32767]
   x,y,z=0.,f(cx*0.-sx*distance),f(sx*0.+cx*distance);cv=[f(f(sy*z+cy*x)+tv[0]),f(y+tv[1]),f(f(cy*z-sy*x)+tv[2])]
 v['pointA']=[bits(x)for x in cv];v['pointZ']=[bits(x)for x in tv];expected=state_model(v,'configure',q);expected['followTarget']=ptr if q['followTarget']else 0
 event=dict(camera=v['pointA'],target=v['pointZ'],args=[0,q['start'],q['end'],q['blendIn'],q['blendOut'],int(q['followTarget']),0,q['borders']],targetPointer=ptr)
 return expected,[event]
def run_command(o,group='synthetic',source=None):
 global events_expected
 setup_command(o);events_expected=[];expected,configs=model_command(o);result=n.call(0x4509d0,[SYS,PACK,CRE,ARGS,len(o['tokens']),int(o['first'])],count=500000);actual=snap();cfg=json.loads(json.dumps(configured))
 if configs and configs[0]['targetPointer']==-1 and cfg:cfg[0]['targetPointer']=-1
 good=actual==expected and cfg==configs and events==events_expected and result==1
 row=dict(input=o,expected=dict(state=actual,events=list(events),configured=cfg,result=result),group=group)
 if source:row['source']=source
 if not good:errors.append(dict(index=len(rows),tokens=o['tokens'],stateDiff={k:[expected[k],actual[k]]for k in expected if expected[k]!=actual[k]},expectedEvents=events_expected,actualEvents=list(events),expectedConfig=configs,actualConfig=cfg))
 rows.append(row)
# Branch precedence, timing, reset order, source aliases, actual lookup miss paths.
for target in [['tgt_locator=loc'],['tgt_character=actor'],['tgt_character=myself'],['tgt_obj=object'],['tgtpos_x=1','tgtpos_y=2','tgtpos_z=3'],[],['tgtpos_x=1','tgtpos_y=2']]:
 for camera in [[],['cam_locator=cam'],['cam_locator=bad'],['campos_x=7','campos_y=8','campos_z=9'],['use_current_campos','dcampos_x=2.5','dcampos_y=-3','dcampos_z=4']]:
  for tail in [[],['start_time=-1','blend_in_time=0','no_borders'],['range=12.5','rotx=-27.9','roty=361.5'],['end_time=2','end_time=infinite'],['Reset'],['bAlend_in_time=9','FXollowTgt']]:
   for first in [False,True]:run_command(defaults(target+camera+tail,first=first))
for missing,callback,selfref in itertools.product([False,True],[False,True],[False,True]):
 for target in ['tgt_locator=loc','tgt_character=actor','tgt_character=myself','tgt_obj=object']:
  run_command(defaults([target,'FollowTgt','range=4'],missingLocator=missing,missingCharacter=missing,missingScene=missing,callback=callback,selfReference=selfref))
for mode,override in [('static','none'),('static','valid'),('dynamic','none'),('dynamic','valid'),('dynamic','minusone')]:
 for follow in [[],['FollowTgt']]:run_command(defaults(['tgt_obj=object']+follow,sceneMode=mode,override=override))
for opts in [['tgt_locator=loc','tgt_character=actor','tgt_obj=object'],['tgt_obj=object','tgt_character=actor','tgt_locator=bad'],['tgt_character=bad','tgt_obj=object','tgtpos_x=1','tgtpos_y=2','tgtpos_z=3'],['tgt_locator=loc','cam_locator=cam','campos_x=1','campos_y=2','campos_z=3'],['tgt_locator=bad','tgt_locator=loc'],['Reset\0junk'],['tgt_locator=loc','range=param0','roty=alpha']]:run_command(defaults(opts))
for angle in [-100000.,-721.9,-360.9,-180.5,-90.1,-1.9,-.9,0.,.9,1.9,89.9,90.,179.9,180.,359.9,360.9,721.9,100000.]:
 for distance in [0.,-0.,1.,-5.25,1e-6,1e6]:run_command(defaults(['tgt_locator=loc','rotx='+str(angle),'roty='+str(angle),'range='+str(distance)]))
ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());uses=next(r['uses']for r in ledger['rows']if r['name']=='CameraCut')
for use in uses:
 names={}
 for t in use['args']:
  for key,out in [('tgt_locator=','locatorName'),('cam_locator=','cameraLocatorName'),('tgt_character=','characterName'),('tgt_obj=','sceneName')]:
   if key in t.lower():names[out]=t[t.lower().index(key)+len(key):]
 for first in [True,False]:run_command(defaults(use['args'],first=first,**names),'authored',{k:use[k]for k in ['source','line','text']})
rotation=[]
r=random.Random(0x5b35a0)
for i in range(512):
 angle=r.randrange(-0x80000000,0x80000000);v=[f(r.uniform(-1000,1000))for _ in range(3)]
 if i<32:v=[fl([0,0x80000000,1,0x80000001][(i+j)%4])for j in range(3)]
 n.pack('<3f',A,*v);n.call(0x5b35a0,[A,A,angle]);actual=list(n.unpack('<3I',A));sx,cx=sine[(angle>>1)&32767],sine[((angle+16384)>>1)&32767];expected=[bits(v[0]),bits(cx*v[1]-sx*v[2]),bits(sx*v[1]+cx*v[2])]
 if actual!=expected:errors.append(dict(rotation=i,actual=actual,expected=expected))
 rotation.append(dict(input=[bits(x)for x in v],angle=angle,expected=actual))
report=dict(binarySha256=n.sha256,cases=len(rows),rotationCases=len(rotation),authoredUses=len(uses),mismatches=len(errors),examples=errors[:12],originalCalls=allcalls,adapters={'0x6e69ef':'Bounded CRT Player%d formatting only; all target/numeric/locator/scene/camera/math routines execute original instructions.'},limits=['Finite bounded decimal/parameter operands with integral angle conversion in Int32.','Explicit target plus FollowTgt is excluded due native stack-pointer lifetime; no shipped occurrence uses this combination.','Scene diagnostic-missing-name global disabled; static minusone transform and invalid backing pointers are excluded.','Position/lifetime/world records are prepared; this is not live camera motion or rendered output.','Compiled managed execution remains pending.'])
(B/'reports/native-camera-command-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-camera-command-vectors.json').write_text(json.dumps(dict(records=rows,rotation=rotation),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));raise SystemExit(bool(errors))
