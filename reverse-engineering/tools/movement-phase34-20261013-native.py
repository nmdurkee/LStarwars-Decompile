"""Original complete prepared pod update, with only64d270 construction adapted."""
from pathlib import Path
import json,struct,gzip,base64,itertools,random
p=Path(__file__).with_name('movement-phase32-20261013-native.py');code=p.read_text().split('vectors=[];errors=[]')[0];q={'__file__':str(p)};exec(compile(code,str(p),'exec'),q)
q33p=Path(__file__).with_name('movement-phase33-20261013-native.py');q33={'__file__':str(q33p)};exec(compile(q33p.read_text().split('for offset in range')[0],str(q33p),'exec'),q33)
n=q['n'];m=q['m'];X=q['X'];f32=q['f32'];bits=q['bits'];D=q['D'];SIZE=q['SIZE'];POD=q['POD'];WORLD=q['WORLD'];GAME=q['GAME'];SCR=q['SCR'];ACT2=D+0x12000;TARG=D+0x14000;HANDLE=D+0xe000;TEMPLATE=D+0xf000;SCENE=D+0x17000;LEGACY=D+0x18000;HEADER=D+0x19000;TABLE=D+0x1a000;RECORD=D+0x1c000;MODERN=D+0x1d000;vectors=[];errors=[];cfg34={};events=[];counts={}
state={}
def mutation(c,put,pf,rand):
 mode=c.get('spawnMode',0)
 if mode in[1,4]:put(POD+0x90,ACT2)
 if mode in[3,4]:rand['center']=f32(2.125);rand['spread']=f32(.3125);rand['random']=0xabcdef01
 if mode==5:
  put(POD,0x3f000000);put(POD+0x30,0x41100000);put(POD+0x34,0xc0400000);put(POD+0x38,0x80000000)
 if mode==6:put(POD+0x88,0xffa51234)
def normalize_event(raw,matrix,direction):
 args=bytearray(raw);args[0:4]=bytes(4);args[8:12]=bytes(4);return dict(arguments=args.hex(),matrix=matrix.hex(),direction=direction.hex())
def hook34(mu,a,size,user):
 if a in[0x4d9760,0x5cfac0,0x5b3c50,0x5b9dd0,0x49f630,0x5b3b30,0x5d02e0,0x5b4500,0x64d270]:counts[hex(a)]=counts.get(hex(a),0)+1
 if a==0x4d97a7:
  sp=mu.reg_read(m.UC_X86_REG_ESP);n.pack('<3I',sp+0x44,*cfg34.get('directionWords',[0x3f800000,0,0x40000000]))
 if a==0x64d270:
  sp=mu.reg_read(m.UC_X86_REG_ESP);arg=n.unpack('<I',sp+4)[0];mat=n.unpack('<I',arg)[0];dire=n.unpack('<I',arg+8)[0];events.append(normalize_event(n.read(arg,200),n.read(mat,64),n.read(dire,12)))
  live=dict(random=n.unpack('<I',0x95e5d4)[0],center=n.unpack('<f',0x7ffd08)[0],spread=n.unpack('<f',0x7ffd0c)[0]);mutation(cfg34,lambda p,v:n.pack('<I',p,v),lambda p,v:n.pack('<f',p,v),live);n.pack('<I',0x95e5d4,live['random']);n.pack('<f',0x7ffd08,live['center']);n.pack('<f',0x7ffd0c,live['spread']);mu.reg_write(m.UC_X86_REG_EAX,0);mu.reg_write(m.UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(m.UC_X86_REG_ESP,sp+4)
n.mu.hook_add(q['UC_HOOK_CODE'],hook34)
def setup34(c):
 global cfg34
 cfg34=c;q['setup32'](c);ACT=q['ACT'];n.write(ACT2,bytes(0x10d8));n.pack('<3f',ACT+0x5c,*c.get('actorPosition',[2.,3.,4.]));n.pack('<3f',ACT+0x80,*c.get('actorReference',[0.,0.,0.]));n.pack('<f',ACT+0x1090,c.get('projectileTimer',-.125));n.pack('<3f',TARG+0x80,*c.get('targetReference',[0.,0.,50.]));n.pack('<H',TARG+0x696,c.get('targetAngle',12345));n.pack('<I',0x93d810,0 if c.get('nullTarget')else TARG);n.pack('<I',0x87b08c,GAME if not c.get('wrongWorld')else 0);n.pack('<H',POD+0x88,0x1235 if c.get('wrongType')else 0x1234)
 legacy=LEGACY if c.get('legacy',True)and not c.get('invalidSprite')else 0;modern=MODERN if c.get('modern',True)and not c.get('invalidSprite')else 0;n.pack('<3I',0x881cc8,SCENE,legacy,modern);n.pack('<3I',HANDLE,SCENE,legacy,modern);n.pack('<I',LEGACY+0x40,HEADER);n.pack('<h',HEADER+0x40,3);n.pack('<I',SCENE+0x18,TABLE);n.pack('<I',TABLE+12,RECORD);n.pack('<f',RECORD+0x14,c.get('scale',2.5));n.pack('<4f',MODERN+0xa0,2.,3.,4.,.75)
 template=[(j*0x11111111+0x01234567)&0xffffffff for j in range(50)];n.pack('<50I',TEMPLATE,*template);n.pack('<50I',0x810210,*template)
 for p,k,v in[(0x7ffe28,'range',10.),(0x7ffe24,'amplitude',4.),(0x7fc024,'targetSpeed',1.5),(0x7ffd10,'projectileSpeed',12.),(0x7ffd14,'gravity',-9.8),(0x7ffe20,'rangeLimit',15.),(0x7ffd08,'timerCenter',1.),(0x7ffd0c,'timerSpread',.25)]:n.pack('<f',p,c.get(k,v))
 n.pack('<I',0x95e5d4,c.get('randomState',0x12345678));events.clear();counts.clear();return bytearray(n.read(D,SIZE))
def projectile34(c,img,commit):
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 def f(p):return struct.unpack_from('<f',img,p-D)[0]
 def pf(p,v):struct.pack_into('<f',img,p-D,v)
 def next_random():state['random']=(state['random']*0x19660d+0x3c6ef35f)&0xffffffff;return(state['random']&0x7fffff)/8388608.
 def sub(a,b):return(X.fl(a)-X.fl(b)).flstore()
 def add(o,a,b):
  for j in range(3):pf(o+j*4,(X.fl(f(a+j*4))+X.fl(f(b+j*4))).flstore())
 def rotate(v,angle):
  xyz=[f(v+j*4)for j in range(3)];rot=q['q22']['vy'](xyz,angle)
  pf(v,rot[0]);pf(v+8,rot[2])
 if c.get('wrongWorld')or not u(POD+0x90)or c.get('wrongType')or c.get('invalidSprite'):return
 actor=u(POD+0x90);pf(actor+0x1090,sub(f(actor+0x1090),f32(c.get('delta',f32(1/60)))))
 actor=u(POD+0x90)
 if not f(actor+0x1090)<0:return
 target=0 if c.get('nullTarget')else TARG;origin=SCR+0x200;difference=origin+0x10;landing=origin+0x20;velocity=origin+0x30;direction=origin+0x40;matrix=origin+0x80;arguments=origin+0xc0;put(origin,u(actor+0x5c));pf(origin+4,(X.fl(f(actor+0x60))+X.fl(1.)).flstore());put(origin+8,u(actor+0x64))
 if not target:return
 for j,v in enumerate(c.get('directionWords',[0x3f800000,0,0x40000000])):put(direction+j*4,v)
 ds=[sub(f(target+0x80+j*4),f(actor+0x80+j*4))for j in range(3)];x,y,z=map(X.fl,ds);distance=(x*x+y*y+z*z).flstore();radius=f32(c.get('range',10.));limit=f32(c.get('rangeLimit',15.))
 def aim():
  q33.update(A=origin,B=landing,V=velocity);q33['oracle']('aim',dict(output=direction,speed=f32(c.get('projectileSpeed',12.)),gravity=f32(c.get('gravity',-9.8)),delta=f32(c.get('delta',f32(1/60)))),img)
 if distance>float((X.fl(radius)*X.fl(4.)*X.fl(radius)).v):
  amplitude=X.fl(f32(c.get('amplitude',4.)));rand=next_random();pf(landing,(amplitude-(amplitude+amplitude)*X.fl(rand)).flstore());pf(landing+4,0);pf(landing+8,radius);rotate(landing,c.get('targetAngle',12345));add(landing,landing,TARG+0x80);pf(velocity,0);pf(velocity+4,0);pf(velocity+8,f32(c.get('targetSpeed',1.5)));rotate(velocity,c.get('targetAngle',12345));aim()
  if distance>float((X.fl(limit)*X.fl(limit)).v):
   pf(direction+4,0);unit=q['q20']['normal']([f(direction+j*4)for j in range(3)])
   for j,v in enumerate(unit):pf(direction+j*4,(X.fl(v)*X.fl(limit)).flstore())
   add(landing,origin,direction)
   for j in range(3):pf(velocity+j*4,0)
   aim()
 q33.update(A=origin);q33['oracle']('matrix',dict(output=matrix),img)
 for j in range(50):put(arguments+j*4,u(TEMPLATE+j*4))
 put(arguments,matrix);put(arguments+8,direction);q33.update(H=HANDLE,FRET=origin+0xf00);q33['oracle']('sprite',{},img);scale=f(origin+0xf00);pf(arguments+0x14,scale);pf(arguments+0x18,scale);put(arguments+0x24,0x881cc8);put(arguments+0x2c,0x29a);put(arguments+0x40,0x42cf20);pf(arguments+0x1c,f32(c.get('gravity',-9.8)));put(arguments+0x44,0x4d9710);pf(arguments+0x8c,f32(c.get('delta',f32(1/60))));pf(arguments+0xa4,5.);state['events'].append(normalize_event(bytes(img[arguments-D:arguments-D+200]),bytes(img[matrix-D:matrix-D+64]),bytes(img[direction-D:direction-D+12])));mutation(c,put,pf,state);rand=next_random();actor=u(POD+0x90);pf(actor+0x1090,((X.fl(state['center'])-X.fl(state['spread']))+(X.fl(state['spread'])+X.fl(state['spread']))*X.fl(rand)).flstore())
base_code=code[code.index('def oracle32('):];base_code=base_code.replace('def oracle32(','def oracle34(');last=base_code.rfind(' commit();return 1');base_code=base_code[:last]+base_code[last:].replace(' commit();return 1',' projectile34(c,img,commit);commit();return 1',1);q['projectile34']=projectile34;exec(compile(base_code,str(p),'exec'),q)
def run(c):
 before=setup34(c);before_random=n.unpack('<I',0x95e5d4)[0];expected=bytearray(before)+bytearray(0x100000-SIZE);state.clear();state.update(random=before_random,center=n.unpack('<f',0x7ffd08)[0],spread=n.unpack('<f',0x7ffd0c)[0],events=[]);ret=q['oracle34'](c,expected);actual=n.call(0x4d9760,[POD,WORLD],count=3000000);after=n.read(D,SIZE);rand=n.unpack('<I',0x95e5d4)[0];center=n.unpack('<I',0x7ffd08)[0];spread=n.unpack('<I',0x7ffd0c)[0];bad=[]
 if actual!=ret:bad.append('return')
 if after!=expected[:SIZE]:bad.append('image')
 if events!=state['events']:bad.append('events')
 if rand!=state['random']:bad.append('random')
 if center!=bits(state['center'])or spread!=bits(state['spread']):bad.append('lateGlobals')
 if bad:errors.append(dict(input=c,bad=bad,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12],events=events,expectedEvents=state['events']))
 vectors.append(dict(input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=actual,events=list(events),beforeRandom=before_random,afterRandom=rand,afterCenterBits=center,afterSpreadBits=spread,deltaBits=n.unpack('<I',0x925018)[0],lookAheadBits=n.unpack('<I',0x7f15e0)[0],nativeEntryCounts=dict(counts)))
for target,radius,limit,timer,legacy in itertools.product([[0.,0.,1.],[0.,0.,20.],[0.,0.,21.],[0.,0.,50.]],[10.],[15.,100.],[-.125,0.,.25],[False,True]):run(dict(phase=1.,targetReference=target,range=radius,rangeLimit=limit,projectileTimer=timer,legacy=legacy))
for gate in['invalidSprite','nullTarget','wrongWorld','wrongType','inactive','nullActor']:
 for phase in[0.,1.]:run(dict(phase=phase,**{gate:True}))
for mode,angle in itertools.product([0,1,3,4,5,6],[0,16384,32768,49152,65535]):run(dict(phase=1.,spawnMode=mode,targetAngle=angle))
for freeze in[.125,1.]:run(dict(freeze=freeze,phase=1.))
for words in[[0,0,0],[0x80000000]*3,[0x7f812345,0x7fc54321,0xffffffff]]:run(dict(phase=1.,targetReference=[0.,0.,1.],directionWords=words))
r=random.Random(34)
for j in range(96):run(dict(phase=[.5,1.,1.25][j%3],position=[f32(r.uniform(-10,10))for _ in range(3)],velocity=[f32(r.uniform(-3,3))for _ in range(3)],actorPosition=[f32(r.uniform(-10,10))for _ in range(3)],actorReference=[f32(r.uniform(-10,10))for _ in range(3)],targetReference=[f32(r.uniform(-100,100))for _ in range(3)],targetAngle=r.randrange(65536),range=f32(r.uniform(1,30)),rangeLimit=f32(r.uniform(1,150)),amplitude=f32(r.uniform(-8,8)),projectileTimer=f32(r.uniform(-.25,.025)),projectileSpeed=f32(r.uniform(2,50)),gravity=f32(r.uniform(-20,20)),delta=f32(r.uniform(.001,.125)),randomState=r.randrange(2**32),spawnMode=[0,1,3,4,5,6][j%6],legacy=j%2==0))
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=len(vectors)*5,mismatches=len(errors),errors=errors[:5],constructorAdapters=['64d270']);(m.BASE/'reports/movement-phase34-20261013-draft-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:2])))
if errors:raise SystemExit('Pod frame mismatch; no sealed fixture')
report.update(status='Full prepared original pod update comparisons passed; managed replay pending');(m.BASE/'reports/movement-phase34-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase34-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(sineTable='reverse-engineering/references/native-animation-sine-table.f32',angles=q['q22']['angles'],vectors=vectors),f,separators=(',',':'))
