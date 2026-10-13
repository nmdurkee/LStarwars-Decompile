"""Independent targeted review of root's obstacle/scene controls. Native only.
No managed execution, and no edits to root-owned sources or shared ledgers.
"""
from pathlib import Path
import importlib.util, itertools, json, hashlib, copy, os, subprocess
p=Path(__file__).with_name('native-obstacle-fixture.py');s=importlib.util.spec_from_file_location('obstacle_review_fixture',p);f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
n=f.n;B=f.BASE;rows=[];mismatches=[]
def check(group,inputs,expected,actual):
 row={'group':group,'input':inputs,'expected':expected,'native':actual};rows.append(row)
 if expected!=actual:mismatches.append(row)

# Unlike the record initializers, this initializer returns the dereferenced object.
for name,missing in itertools.product([None,'','a','b','missing','nullobject','A\0b','\xe0'],[False,True]):
 f.setup(registryMissing=missing);p=0
 if name is not None:n.write(f.TEXT,name.encode('latin1')+b'\0');p=f.TEXT
 expected=0 if missing or name in [None,'missing','nullobject']else f.OBJECTS+(0x200 if name=='b'else 0)
 got=n.call(0x4409b0,[0,p]);check('object-initializer',{'name':name,'registryMissing':missing},expected,got)

# Exact Stop gate and no-effect paths with absent/aliased node targets.
for state,flags,present in itertools.product([-2147483648,-1,0,1,2,3,4,2147483647],[0,2,4,0xffff],[False,True]):
 nodes=[dict(start=1.,end=2.,frame=1.5,flags=0xffffffff),dict(start=3.,end=0.,frame=1.,flags=0xa5a5a5a5,present=present)]
 f.setup(state=state,controlFlags=flags,nodes=nodes);expected=f.state(nodes)
 if state in [1,3]:
  expected['targets'][0]['controlFlags']|=2;expected['targets'][0]['nodes'][0]['flags']&=0xfffffffe
  if present:expected['targets'][0]['nodes'][1]['flags']&=0xfffffffe
 got=n.call(0x5a1170,[f.ANIMS]);check('stop-state-and-flags',{'state':state,'flags':flags,'secondPresent':present},{'return':1,'state':expected},{'return':got,'state':f.state(nodes)})

# Validate both native reference fields in special outputs, non-Boolean includes,
# empty member counts, and that even unknown indices still refresh group state.
for index,include,count,reference in itertools.product([0,1,2,4,5,0x80000000,0xffffffff],[-2147483648,-1,0,1,2,2147483647],[0,1],['none','first','second']):
 nodes=[dict(start=2.,end=7.,frame=7.,flags=3,reference=False)]
 f.setup(nodes=nodes,memberCount=count,state=4,controlFlags=0,specialFlags=0)
 n.pack('<II',f.NODES+8,f.TARGETS if reference=='first'else 0,f.TARGETS if reference=='second'else 0)
 eligible=count!=0 and reference!='none'and include!=0
 expected={'value':int(index==0 or index==1)if eligible else 0,'state':2 if eligible else 4}
 got=n.call(0x5ae3a0,[f.RECORDS,index,include]);actual={'value':got,'state':n.unpack('<i',f.ANIMS+12)[0]}
 check('special-reference-and-side-effect',{'index':index,'include':include,'memberCount':count,'reference':reference},expected,actual)

# Queue order, duplicate suppression, and node aliases across two groups.
# Two different member records address the SAME target. State snapshots preserve
# the unused backing target record as well, so alias propagation cannot be faked.
for sequence,speed,frame,scale in itertools.product([[0,1],[1,0],[0,0],[1,1],[0,1,0,1]],[-2.,0.,.75],[-50.,5.,50.],[0.,.5,-1.]):
 nodes=[dict(start=0.,end=10.,frame=frame,flags=0xabcd0004,scale=scale,rate=3.),dict(start=100.,end=20.,frame=-200.,flags=0xdeadbeef,scale=9.,rate=4.)]
 f.setup(nodes=nodes,state=4,controlFlags=2);n.pack('<I',f.NODES+0x40+16,f.TARGETS);n.pack('<I',f.NODES+0x400+16,f.TARGETS);n.pack('<I',f.NODES+0x440+16,f.TARGETS)
 expected=f.state(nodes);target=expected['targets'][0]['nodes'][0]
 for which in sequence:
  group=expected['targets'][which];group['controlFlags']&=0xfffd
  for start,end in [(0.,10.),(100.,20.)]:
   direction=1 if start<=end else -1;v=f.value(target['frameBits']);target['flags']=(target['flags']|1)&0xfffffffb
   if v*direction<start*direction:target['frameBits']=f.bits(start)
   elif v*direction>end*direction:target['frameBits']=f.bits(end)
   target['rateBits']=f.bits((scale if scale!=0 else 1)*speed*direction)
  if not(group['controlFlags']&4):expected['queue'].append(which);group['controlFlags']|=4
  n.call(0x5a1030,[f.ANIMS+which*0x400,f.bits(speed),0])
 check('shared-target-and-queue',{'sequence':sequence,'speed':speed,'frame':frame,'scale':scale},expected,f.state(nodes))

# Stop null and control return values are API-visible even when nothing changes.
for address,args in [(0x5a1170,[0]),(0x5a1030,[0,f.bits(1.),1]),(0x5a11b0,[0,0xffffffff]),(0x5a11f0,[0]),(0x5a1230,[0])]:check('null-return',{'address':hex(address)},1,n.call(address,args))

from capstone import Cs,CS_ARCH_X86,CS_MODE_32
d=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for a,z in [(0x4409b0,0x2b),(0x5a1170,0x3c),(0x558780,0x93),(0x5ae3a0,0x75),(0x55a1b0,0x46),(0x5cfac0,0x24),(0x4f1310,0x29)]:
 assembly.append({'address':hex(a),'bytes':z,'sha256':hashlib.sha256(n.read(a,z)).hexdigest(),'instructions':[{'address':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str}for i in d.disasm(n.read(a,z),a)]})
(B/'reports/native-obstacle-review-assembly.json').write_text(json.dumps({'binarySha256':n.sha256,'procedures':assembly},indent=2)+'\n')
paths=['reconstructed/gameplay/SceneAnimationControls.cs','reconstructed/gameplay/ObstacleCommands.cs','tools/native-obstacle-fixture.py','tools/native-obstacle-review-verify.py','tools/native-obstacle-portable-verify.cs']
report={'binarySha256':n.sha256,'checks':len(rows),'mismatches':len(mismatches),'groups':{g:sum(r['group']==g for r in rows)for g in sorted(set(r['group']for r in rows))},'examples':mismatches[:12],'cases':rows,'sourceHashes':[{'path':p,'sha256':hashlib.sha256((B/p).read_bytes()).hexdigest()}for p in paths],'review':'No in-domain divergence found in the inspected source. Original-PC probes independently cover object initializer dereference, exact Stop state gate, alternate reference-validity field, unsupported-output refresh side effects, nonboolean include flags, shared targets and queue insertion order.','boundaries':['Named registry lookup remains the existing fixture adapter at0x55a020. No control/output/list function is replaced.','Malformed pointers/strings and inconsistent intrusive queues are excluded.','Managed C# was inspected but not executed. These are additional native checks, not a compiled differential pass.']}
compiler=Path(os.environ.get('WINDIR',r'C:\Windows'))/'Microsoft.NET/Framework64/v4.0.30319/csc.exe';build=B/'reconstructed/gameplay/obstacle-review-build';build.mkdir(parents=True,exist_ok=True)
sources=['reconstructed/animation/CharacterContexts.cs','reconstructed/animation/AnimationPlayback.cs','reconstructed/gameplay/FlowRuntime.cs','reconstructed/gameplay/SpecialGizmo.cs','reconstructed/gameplay/SceneAnimationControls.cs','reconstructed/gameplay/ObstacleCommands.cs','reconstructed/gameplay/SceneryNameBindings.cs','tools/native-obstacle-portable-verify.cs']
command=[str(compiler),'/nologo','/optimize+','/platform:anycpu','/target:exe','/main:ObstacleDifferential','/reference:System.Web.Extensions.dll','/out:'+str(build/'ObstacleReviewCompile.exe')]+[str(B/p)for p in sources]
compiled=subprocess.run(command,capture_output=True,text=True)
report['managedHarness']={'path':'tools/native-obstacle-portable-verify.cs','sha256':hashlib.sha256((B/'tools/native-obstacle-portable-verify.cs').read_bytes()).hexdigest(),'arguments':['reports/native-obstacle-vectors.json','<output.json>','reports/native-obstacle-review-tests.json'],'optionalReviewArgument':True,'preparedReviewCases':len(rows),'execution':'Not run. Existing Windows execution restriction respected.'}
report['compile']={'command':command,'exitCode':compiled.returncode,'stdout':compiled.stdout,'stderr':compiled.stderr,'sourceHashes':[{'path':p,'sha256':hashlib.sha256((B/p).read_bytes()).hexdigest()}for p in sources]}
if compiled.returncode==0:report['compile']['artifact']={'path':'reconstructed/gameplay/obstacle-review-build/ObstacleReviewCompile.exe','sha256':hashlib.sha256((build/'ObstacleReviewCompile.exe').read_bytes()).hexdigest()}
(B/'reports/native-obstacle-review-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict({k:report[k]for k in ['checks','mismatches','groups','examples']},compileExitCode=compiled.returncode,harnessSha256=report['managedHarness']['sha256']),indent=2));assert not mismatches and compiled.returncode==0,compiled.stdout
