"""Original room selection plus its bounded handoff into portal traversal."""
import importlib.util,json,struct,hashlib,random
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
def module(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=module('nx','native-x86.py');x87=module('x87','animation-x87.py');n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
scene=n.DATA;roomBase=scene+0x2000;portalBase=scene+0x8000;heapBase=scene+0x10000;pointAddress=scene+0xf0000;clipAddress=scene+0xe0000
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
dot=lambda p,q:x87.dot3_plus_constant(*q,*p)
contains=lambda room,p:all(dot(plane,p)<=0 for plane in room['planeEquations'])

def select(rooms,portals,p):
 if rooms is None or p is None:return -1,0,0
 first=second=0;matches=assertions=0
 for i,room in enumerate(rooms):
  if not contains(room,p):continue
  oldFirst,oldSecond=rooms[first],rooms[second]
  if matches==2:
   if oldFirst['priority']==oldSecond['priority']:assertions+=1
   if oldFirst['priority']<oldSecond['priority']:
    if not oldFirst['flags']&1:assertions+=1
    first=i
   else:
    if not oldSecond['flags']&1:assertions+=1
    second=i
  if matches==6:raise ValueError('Seventh native overlap overwrites return address; fixture excluded')
  if matches==0:first=i
  elif matches==1:second=i
  matches+=1
  if matches==2 and not oldFirst['flags']&1 and not oldSecond['flags']&1:break
 if matches==1:return first,assertions,matches
 if not matches:return -1,assertions,matches
 for pi in rooms[first]['portalIndices']:
  for pj in rooms[second]['portalIndices']:
   if pi==pj:
    portal=portals[pi]
    return (portal['backRoom']if dot(portal['plane'],p)>=0 else portal['frontRoom']),assertions,matches
 return -1,assertions,matches

def setup(rooms,portals):
 n.write(scene,b'\0'*0x1000);n.write(roomBase,b'\0'*0x6000);n.write(portalBase,b'\0'*0x8000)
 n.pack('<4I',scene+0x6c,len(portals),portalBase,len(rooms),roomBase)
 heap=heapBase
 for i,r in enumerate(rooms):
  addr=roomBase+i*24;planes=r['planeEquations'];indices=r['portalIndices']
  if len(planes)>255 or len(indices)>255:raise ValueError('Native byte counts exceeded')
  n.pack('<I',addr+4,heap)
  for p in planes:n.pack('<4f',heap,*p);heap+=16
  n.pack('<I',addr+8,heap)
  for pi in indices:n.pack('<h',heap,pi);heap+=2
  heap=(heap+3)&~3;n.write(addr+14,bytes([len(planes),len(indices)]));n.pack('<I',addr+16,r['flags']);n.write(addr+20,bytes([r['priority']]))
 for i,p in enumerate(portals):
  addr=portalBase+i*32;n.pack('<4f',addr,*p['plane']);n.pack('<2h',addr+22,p['frontRoom'],p['backRoom'])
 if heap>scene+0xd0000:raise ValueError('Fixture arena exhausted')

mode='select';nativeAsserts=0;nativeContains=0;events=[]
adapters={0x600bd0:1,0x600c60:1,0x600cb0:1,0x5d9a00:3,0x5ee250:0,0x5ee940:5,0x5ee710:0}
def hook(mu,address,size,_):
 global nativeAsserts,nativeContains
 if address==0x5c12e0:nativeAsserts+=1
 if address==0x5d9220:nativeContains+=1
 if mode=='entry' and address in adapters:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];args=list(n.unpack('<'+'I'*adapters[address],sp+4))if adapters[address]else[]
  events.append({'address':hex(address),'args':args});mu.reg_write(UC_X86_REG_EAX,clipAddress if address==0x5d9a00 else 0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
errors=[];digest=hashlib.sha256();stats={'authoredCases':0,'syntheticCases':0,'entryCases':0,'unsafeSyntheticCasesExcluded':0};classCounts={};overlaps={};sources=[];authoredFixtures=[];syntheticFixtures=[]
def check(rooms,portals,p,label,kind):
 global nativeAsserts
 wanted,asserts,matches=select(rooms,portals,p);before=nativeAsserts;n.pack('<3f',pointAddress,*p)
 actual=n.call(0x5d92b0,[scene,pointAddress]);actual=(actual&0xffff)-0x10000 if actual&0x8000 else actual&0xffff
 stats[kind]+=1;classCounts[str(actual)]=classCounts.get(str(actual),0)+1;overlaps[str(matches)]=overlaps.get(str(matches),0)+1;digest.update(struct.pack('<4i',actual,wanted,nativeAsserts-before,asserts))
 if actual!=wanted or nativeAsserts-before!=asserts:
  if len(errors)<40:errors.append({'context':label,'native':actual,'expected':wanted,'nativeNoOpAssertions':nativeAsserts-before,'expectedNoOpAssertions':asserts})
 return actual

roomFixtures=json.loads((R/'geometry-clipping-room-fixtures.json').read_text())['rooms'];pointBySource={}
for r in roomFixtures:pointBySource.setdefault(r['source'],set()).update(tuple(p)for p in r['points'])
index=json.loads((R/'geometry-scene-data-index.json').read_text())['rows'];authored=[]
for row in index:
 if not row['rooms']:continue
 d=json.loads((B/row['report']).read_text());pd=d['portalData'];rooms=pd['rooms'];portals=pd['portals'];setup(rooms,portals)
 points=pointBySource[row['source']]
 for portal in portals:
  vertices=portal['vertices'];center=[f32(sum(p[k]for p in vertices)/len(vertices))for k in range(3)]
  points.add(tuple(center))
  for side in [-1,1]:points.add(tuple(f32(center[k]+side*.001*portal['plane'][k])for k in range(3)))
 points=sorted(points);results=[check(rooms,portals,p,{'source':row['source'],'point':p},'authoredCases')for p in points]
 sources.append({'source':row['source'],'sha256':row['sha256'],'rooms':len(rooms),'portals':len(portals),'points':len(points)})
 authoredFixtures.append({'source':row['source'],'points':points,'nativeResults':results});authored.append((row,rooms,portals,points,results))
 print('authored sources',len(sources),'cases',stats['authoredCases'],'errors',len(errors),flush=True)

# Controlled overlapping rooms expose the exact first-two/third-match behavior.
rng=random.Random(0x5d92b0)
for case in range(2500):
 count=case%9;rooms=[]
 for i in range(count):
  rooms.append({'planeEquations':[[0.,0.,0.,-1. if rng.randrange(4)else 1.]],'portalIndices':rng.sample(range(4),rng.randrange(5)),'priority':rng.randrange(3),'flags':rng.randrange(2)})
 portals=[{'plane':[1.,0.,0.,float(i-2)],'frontRoom':0 if count else -1,'backRoom':count-1}for i in range(4)]
 point=[f32(rng.choice([-2,-1,0,1,2])),0.,0.]
 try:select(rooms,portals,point)
 except ValueError:stats['unsafeSyntheticCasesExcluded']+=1;continue
 setup(rooms,portals);result=check(rooms,portals,point,{'synthetic':case},'syntheticCases')
 syntheticFixtures.append({'rooms':rooms,'portals':portals,'point':point,'native':result})
for args in [(0,pointAddress),(scene,0),(0,0)]:
 result=n.call(0x5d92b0,args)&0xffff;stats['syntheticCases']+=1
 if result!=0xffff:errors.append({'nullArguments':args,'native':result})

# Original portal entry executes the selector unchanged. Peripheral visibility
# initializers, child-volume producer, debug renderer, recursion and finish are
# explicit no-op/record adapters; no whole-traversal equivalence is claimed.
mode='entry';entryFixtures=[]
for row,rooms,portals,points,results in authored:
 if not portals:continue
 picks=[]
 for want in [-1,0,1]:
  pair=next(((p,r)for p,r in zip(points,results)if (r==-1 if want==-1 else r>=0)),None)
  if pair and pair not in picks:picks.append(pair)
 if not picks:continue
 for p,result in picks:
  for override in [False,True]:
   for gate in range(5):
    setup(rooms,portals);n.pack('<I',scene+0xf4,0 if gate==4 else 1);n.pack('<I',0x80ba58,0 if gate==1 else 1)
    if gate==2:n.pack('<I',scene+0x6c,0)
    if gate==3:n.pack('<I',scene+0x74,0)
    for i,r in enumerate(rooms):n.pack('<I',roomBase+i*24+16,r['flags']|4)
    position=[12.,34.,56.]if override else list(p);matrix=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,*position,1.]
    n.pack('<16f',0x9736e8,*matrix);n.pack('<f',0x973730,.1);n.pack('<3f',pointAddress,*p);n.pack('<I',0x973990,pointAddress if override else 0);n.pack('<h',0x971abc,0x7777);n.pack('<i',scene+0xe0,0x12345678);n.pack('<I',scene+0xdc,0xabcdef01);events.clear()
    returned=n.call(0x5eeb30,[scene],count=1000000);eligible=gate==0;success=eligible and result!=-1
    expectedEvents=[0x600bd0]+([0x600c60]if gate==1 else [0x600cb0]if eligible else [])+([0x5d9a00,0x5ee250,0x5ee940,0x5ee710]if success else [])
    observed={'returned':returned,'selectedGlobal':n.unpack('<h',0x971abc)[0],'selectedHeader':n.unpack('<i',scene+0xe0)[0],'events':[int(e['address'],16)for e in events],'roomFlags':[n.unpack('<I',roomBase+i*24+16)[0]for i in range(len(rooms))]}
    expected={'returned':int(success),'selectedGlobal':result if eligible else 0x7777,'selectedHeader':result if eligible else 0x12345678,'events':expectedEvents,'roomFlags':[r['flags']if success else r['flags']|4 for r in rooms]}
    if eligible:
     observed.update(cameraCopy=n.read(0x95fb78,64).hex(),cachedPosition=list(n.unpack('<3f',0x971894)),resetCount=n.unpack('<I',scene+0xdc)[0]);expected.update(cameraCopy=struct.pack('<16f',*matrix).hex(),cachedPosition=position,resetCount=0)
    if success:
     traversal=next(e for e in events if e['address']==hex(0x5ee940));observed['traversalArgs']=traversal['args'];expected['traversalArgs']=[scene,clipAddress,result,0xffffffff,0]
    stats['entryCases']+=1
    if observed!=expected and len(errors)<40:errors.append({'entry':{'source':row['source'],'point':p,'gate':gate,'override':override},'native':observed,'expected':expected})
    entryFixtures.append({'source':row['source'],'point':p,'gate':gate,'overrideSelectionPoint':override,'native':observed})

report={'schema':'original-room-selection-and-portal-entry-v1','binarySHA256':n.sha256,'passed':not errors,'counts':stats,'selectedRoomCounts':classCounts,'encounteredMatchCounts':overlaps,'nativeContainmentCalls':nativeContains,'nativeNoOpAssertionCalls':nativeAsserts,'errors':errors,'resultSHA256':digest.hexdigest(),'sources':sources,'sourceCounts':{'rooms':sum(x['rooms']for x in sources),'portals':sum(x['portals']for x in sources)},'nativeFunctions':['0x5d92b0','0x5d9220','0x5c12e0','0x5eeb30'],'externalEntryAdapters':{hex(k):v for k,v in adapters.items()},'floatingPointModel':{'nativeControlWord':'0x037f','source':'tools/animation-x87.py'},'fixturesFile':'geometry-room-selection-fixtures.json','entryFixtures':entryFixtures,'limits':['Original selector and containment math execute without substitution; original5c12e0 is an observed empty debug hook.','All authored rooms have priority0 and flags0. Synthetic flags/priorities establish bounded extra branches.','Native local room-index array has six slots; a seventh stored overlapping match corrupts the return address and is excluded. Managed source guards this invalid domain.','Portal-entry initializers,child-volume producer,debug drawing,recursive traversal and finish are record-only adapters. Entry tests prove selection/gating/camera-copy/room-flag/handoff contracts only.','No complete portal visibility propagation,room loading,live camera update or GPU comparison.','Compiled managed execution remains independently pending.']}
(R/'geometry-room-selection-native-validation.json').write_text(json.dumps(report,indent=2,allow_nan=False)+'\n')
(R/'geometry-room-selection-fixtures.json').write_text(json.dumps({'schema':'room-selection-fixtures-v1','authored':authoredFixtures,'synthetic':syntheticFixtures},separators=(',',':'),allow_nan=False)+'\n')
print(json.dumps({k:report[k]for k in ['passed','counts','sourceCounts','encounteredMatchCounts','errors']},indent=2))
if errors:raise SystemExit(1)
