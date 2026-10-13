"""Original-PC differential oracles for scene clocks and active group retirement."""
from pathlib import Path
import importlib.util,itertools,random,json,gzip,hashlib
s=importlib.util.spec_from_file_location('fixture',Path(__file__).with_name('scene-animation-update-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
n=f.n;B=f.B;rng=random.Random(0x5a1780);cases=[];errors=[];counts={};mismatches=0
def check(group,inputs,want,got):
 global mismatches
 def input_bits(v):
  if isinstance(v,dict):
   r={k:input_bits(x)for k,x in v.items()}
   for k,x in v.items():
    if isinstance(x,float):r[k+'Bits']=f.bits(x)
   return r
  return [input_bits(x)for x in v]if isinstance(v,list)else v
 counts[group]=counts.get(group,0)+1;cases.append({'group':group,'input':input_bits(inputs),'native':got})
 if want!=got:
  mismatches+=1
  if len(errors)<12:errors.append({'group':group,'input':inputs,'expected':want,'native':got})
def groups_case(groups,operation='update',selected=0):
 rows=f.setup_groups(groups);want=f.group_model(groups,operation,selected)
 n.call({'update':0x5a1780,'remove':0x5a0720,'reset':0x5a0fb0}[operation],[f.QUEUE if operation=='update'else f.GROUP+selected*64]);got=f.group_state(groups,rows)
 check('groups',{'groups':groups,'operation':operation,'selected':selected},want,got)
def scene_case(options,delta,source=None):
 f.setup_scene(options);want=f.scene_model(options,delta);n.call(0x5f4b90,[f.SCENE,f.bits(delta)]);got=f.scene_state(options);check('scene',{'options':options,'delta':delta,'source':source},want,got)

for flags,targetflags,start,end,frame,rate,kind in itertools.product([4,5,6,7],[0,1,8,9],[1.],[10.,1.,-10.],[-11.,1.,5.,10.,21.],[-1.,0.,1.],[0,1,2]):
 groups_case([{'flags':flags,'nodes':[{'start':start,'end':end,'frame':frame,'rate':rate,'targetFlags':targetflags,'kind':kind,'instanceFlags':0x456789ab,'displayFlags':0xa5a5a5a5}]}])
for k in range(400):
 groups=[]
 for gi in range(1+rng.randrange(3)):
  nodes=[]
  for j in range(rng.randrange(4)):
   nodes.append({'start':f.f32(rng.uniform(-100,100)),'end':f.f32(rng.uniform(-100,100)),'frame':f.f32(rng.uniform(-150,150)),'rate':f.f32(rng.uniform(-4,4)),'targetFlags':rng.randrange(1<<32),'present':rng.choice([True,False]),'kind':rng.randrange(3),'instanceFlags':rng.randrange(1<<32),'displayFlags':rng.randrange(1<<32)})
  groups.append({'nodes':nodes,'flags':(rng.randrange(65536)|4),'state':rng.randrange(-1,5)})
 groups_case(groups)
 for operation in ['remove','reset']:groups_case(groups,operation,k%len(groups))
for operation,queue,flags,present in itertools.product(['remove','reset'],[False,True],[0,1,2,3,4,5,6,7],[False,True]):
 if not queue and flags&4:continue
 groups_case([{'nodes':[{'start':10.,'end':-3.,'frame':-2.,'rate':-4.,'present':present,'targetFlags':0xf}], 'flags':flags,'queue':queue,'queued':bool(flags&4)}],operation)
for operation in ['update','remove','reset']:groups_case([{'flags':7,'nodes':[]}],operation)
for start,end,frame,rate,loop in itertools.product([0.,-0.],[0.,-0.],[0.,-0.],[0.,-0.],[0,8]):
 groups_case([{'flags':4,'nodes':[{'start':start,'end':end,'frame':frame,'rate':rate,'targetFlags':1|loop}]}])

def inst(frame=1.,flags=1,rate=1.,first=1.,interval=0.,previous=0.,displayFlags=2,index=0,cursor=0):return {'frame':frame,'flags':flags|(1<<22)|(cursor<<14),'rate':rate,'first':first,'interval':interval,'previous':previous,'displayFlags':displayFlags,'animationIndex':index}
track={'end':10,'times':[1.,4.,10.],'values':[1,0,1]}
for frame,rate,delta in itertools.product([0.,-0.],[0.,-0.],[1.,-1.,0.,-0.]):scene_case({'instances':[inst(frame,5,rate,5.)],'tracks':[track]},delta)
for flags,frame,rate,delta,interval in itertools.product(range(16),[-1.,1.,4.,10.,20.],[-2.,0.,1.],[0.,.5,2.],[0.,3.]):
 scene_case({'instances':[inst(frame,flags,rate,5.,interval)],'tracks':[track]},delta)
for k in range(1500):
 rows=[inst(f.f32(rng.uniform(-10,100)),rng.randrange(16),f.f32(rng.uniform(-5,5)),f.f32(rng.uniform(0,30)),f.f32(rng.uniform(0,10)),f.f32(rng.uniform(-1,25)),rng.randrange(1<<32),rng.randrange(2),rng.randrange(256))for _ in range(1+rng.randrange(3))]
 scene_case({'instances':rows,'tracks':[track],'dataCount':1,'owners':rng.choice([0,1,2,3]),'table':rng.choice([False,True,True])},f.f32(rng.uniform(-2,5)))
# Waiting retains the last processed instance's evaluation time, including zero
# for a first waiting instance. This is not its own previous evaluation time.
for previous,other,waitingfirst in itertools.product([-7.,0.,9.],[1.,6.,20.],[False,True]):
 a=inst(0.,5,1.,20.,previous=previous);b=inst(other,0,0.,previous=3.)
 scene_case({'instances':[a,b]if waitingfirst else[b,a],'tracks':[track]},1.)

authored=0
inventory=json.loads((B/'reports/animation-scene-state-export.json').read_text())
for row in inventory['results']:
 if not row['tracks']:continue
 data=json.loads((B/'exports/animation-scene-states'/(row['source']+'.json')).read_text())
 for t in data['states']:
  keys=t['keys'];authored+=1;track={'end':t['endFrame'],'times':[v['frame']for v in keys],'values':[v['value']for v in keys]}
  for delta,flags in itertools.product([0.,.5,1.,3.],[0,1,3,5,9,11]):
   scene_case({'instances':[inst(keys[0]['frame'],flags,1.,5.,1.)],'tracks':[track]},delta,{'source':row['source'],'track':t['index']})

# Real ANI5 clips: the original full temporal caller evaluates original curves,
# builds matrices and performs the copy/translation tail. Read-only hooks verify
# ordered evaluation/copy requests, in addition to the scalar/state outcomes.
authoredClips=[];source='LEVELS/EPISODE_I/NEGOTIATIONS/NEGOTIATIONS_A/NEGOTIATIONS_A_PC.GSC'
scene=json.loads((B/'exports/animation-scenes'/(source+'.json')).read_text())
for animation in scene['animations'][:12]:
 h=animation['header'];end=h['declaredEndFrame']or h['firstFrame']+h['frameCount'];clip={'source':source,'animationIndex':animation['index'],'sourceOffset':animation['sourceOffset'],'sourceSha256':scene['sourceSha256'],'end':end};authoredClips.append(clip)
 for flags,frame,delta in itertools.product([0,1,3,5,9,11],[1.,float(end),float(end)+2.],[0.,.5,2.]):
  scene_case({'instances':[inst(frame,flags,1.,5.,2.)],'clip':clip},delta,clip)
 for displayFlags,flags in itertools.product([0,2],[1,3,9,11]):
  state={'end':int(end),'times':[1.,float(end)/2,float(end)],'values':[1,0,1]}
  scene_case({'instances':[inst(float(end)/2,flags,1.,5.,2.,displayFlags=displayFlags)],'tracks':[state],'clip':clip},1.,clip)

# Consecutive temporal caller -> group update, with shared live target/special
# records and genuine delayed queue retirement. No reset between the40 frames.
for speed,loop,delta in itertools.product([-1.,1.],[0,8],[.5,1.,7.]):
 options={'instances':[inst(12. if speed<0 else 3.,1|loop,speed,1.,0.)],'tracks':[{'end':40,'times':[1.],'values':[1]}]}
 f.setup_scene(options);n.pack('<HiII',f.GROUP+10,4,4,0, f.QUEUE);n.pack('<I',f.GROUP+24,f.NODE);n.pack('<I',f.NODE,0);n.pack('<III',f.NODE+4,f.SCENE,0,f.DISPLAY);n.pack('<IIff',f.NODE+16,f.TARGET,1,3.,12.);n.pack('<I',f.DISPLAY+0xc4,f.TARGET);n.call(0x4f1310,[f.QUEUE,f.GROUP])
 for step in range(40):
  import copy
  before=copy.deepcopy(options);flags=n.unpack('<H',f.GROUP+10)[0];state=n.unpack('<i',f.GROUP+12)[0];queued=n.unpack('<I',f.QUEUE)[0]!=0
  clock=f.scene_model(before,delta);v=clock['instances'][0];node={'start':3.,'end':12.,'frame':f.value(v['frame']),'rate':speed,'targetFlags':v['flags'],'kind':2,'displayFlags':v['displayFlags']}
  groups=[{'nodes':[node],'flags':flags,'state':state,'queued':queued}];group=f.group_model(groups)
  want={'clock':{'instances':[dict(v,frame=group['targets'][0][0],flags=group['targets'][0][2],displayFlags=group['specials'][0][1])],'lookupPresent':True,'evaluations':[],'copies':[]},'group':group}
  f.evaluations.clear();f.poseEvaluations.clear();f.poseCopies.clear();n.call(0x5f4b90,[f.SCENE,f.bits(delta)]);n.call(0x5a1780,[f.QUEUE]);got={'clock':f.scene_state(options),'group':f.group_state(groups,[node])}
  check('chain',{'options':before,'flags':flags,'state':state,'queued':queued,'delta':delta,'step':step},want,got)
  live=got['clock']['instances'][0];options['instances'][0].update(frame=f.value(live['frame']),flags=live['flags'],previous=f.value(live['previous']),displayFlags=live['displayFlags'])

from capstone import Cs,CS_ARCH_X86,CS_MODE_32
d=Cs(CS_ARCH_X86,CS_MODE_32);addresses=[(0x5a0720,0x45),(0x5a0fb0,0x7d),(0x5a1780,0x2ed),(0x5f4b90,0x367),(0x5da480,0x9a),(0x5cfde0,0x31),(0x5cfd90,0x4f)]
assembly={'binarySha256':n.sha256,'procedures':[{'address':hex(a),'size':z,'sha256':hashlib.sha256(n.read(a,z)).hexdigest(),'instructions':[{'address':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str}for i in d.disasm(n.read(a,z),a)]}for a,z in addresses]}
(B/'reports/scene-animation-update-assembly.json').write_text(json.dumps(assembly,indent=2)+'\n')
out=B/'reports/scene-animation-update-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':n.sha256,'cases':cases},separators=(',',':')).encode(),mtime=0))
report={'binarySha256':n.sha256,'comparisons':len(cases),'groups':counts,'mismatches':mismatches,'examples':errors,'authoredStateTracks':authored,'authoredGeometryClips':authoredClips,'fixture':{'path':out.relative_to(B).as_posix(),'bytes':out.stat().st_size,'sha256':hashlib.sha256(out.read_bytes()).hexdigest()},'method':'Original full5a1780/5a0720/5a0fb0 and full5f4b90 with SALI-only and authored ANI5 animation slots. No instruction/callback replacement. Read-only hooks record552760,5ea390 and5c19d0 calls. Complete projected target/group/reference flags, queue order and matrix-evaluation/copy requests compared.','limits':['Group reevaluation executes original552760 missing-clip branch; its ordered pose requests are verified. The scene clock separately executes original curve/matrix/copy code on12 authored clips.','Portable pose matrix evaluation/copy remains an ordered work item; actual matrices are not reconstructed by this module. Existing independent scene-pose tests validate the decoded animation evaluator separately.','Finite inputs, positive repeat period and bounded int32 quotient only. Invalid pointers, NaNs, infinities, inconsistent intrusive queues and concurrent mutations excluded.','Portable managed execution pending; compilation is separate.']}
(B/'reports/scene-animation-update-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k!='examples'},indent=2));assert not mismatches
