"""Original0x5f3c80 stateful grid/portal/tree dispatcher fixtures, local only."""
import sys,json,gzip,struct,hashlib,itertools,importlib.util
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-next-20261013'
sys.path.insert(0,str(P/'python-packages'))
sp=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
SC=n.DATA;ALT=SC+0x1000;G=SC+0x2000;T=SC+0x3000;MASK=SC+0x4000;TREE=SC+0x5000;CACHE=0x966390
checks=0;errors=[];cases=[];sequences=[];events=[];observations=[];cfg={};counts={'portalEntriesExecuted':0,'gridEntriesExecuted':0,'treeAdapterCalls':0,'cameraSwitchAdapterCalls':0,'cameraRestoreAdapterCalls':0}
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e:errors.append({'label':label,'actual':a,'expected':e})
def readstate():
 p=n.unpack('<I',SC+0x144)[0];label='null'if p==0 else'cache'if p==CACHE else'raw'if p==MASK else'tree'if p==TREE else'sentinel'
 return {'contextCount':n.unpack('<i',SC+0x120)[0],'scratch':n.unpack('<i',SC+0x140)[0],'pointer':label,'contextFlags':n.unpack('<I',SC+0x148)[0],'visibilityActive':n.unpack('<I',0x97393c)[0]!=0,'gridActive':n.unpack('<I',0x973960)[0]!=0,'cacheIndex':n.unpack('<i',0x80b9e4)[0],'cacheHex':n.read(CACHE,4).hex(),'cameraMode':n.unpack('<i',0x97394c)[0],'cameraX':n.unpack('<f',0x973718)[0],'cameraZ':n.unpack('<f',0x973720)[0],'legacyCount':n.unpack('<i',SC+0x1c)[0],'alternateCount':n.unpack('<i',ALT+0x1c)[0]if n.unpack('<I',SC+0x128)[0]else None,'portalAttached':n.unpack('<I',SC+0x13c)[0]==0x280a2f0,'portalBitsSHA256':hashlib.sha256(n.read(0x280a2f0,625)).hexdigest()}
def hook(mu,address,size,_):
 events.append(hex(address));sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if address==0x5d6f30:counts['gridEntriesExecuted']+=1;return
 if address==0x5eeb30:counts['portalEntriesExecuted']+=1;return
 if address==0x5d6900:
  counts['cameraSwitchAdapterCalls']+=1;arg=n.unpack('<i',sp+4)[0];ck(arg,cfg['requestedMode'],'cameraSwitchArgument');observations.append({'edge':'cameraSwitch','arg':arg,'before':readstate()});n.pack('<i',0x97394c,arg);n.pack('<3f',0x973718,cfg['cameraAfterX'],0,cfg['cameraAfterZ']);n.pack('<i',SC+0x1c,n.unpack('<i',SC+0x1c)[0]+2)
  if n.unpack('<I',SC+0x128)[0]:n.pack('<i',ALT+0x1c,n.unpack('<i',ALT+0x1c)[0]+3)
  n.pack('<3I',SC+0x140,0x22222222,MASK,0xf00f)
 elif address==0x5d8fb0:
  counts['treeAdapterCalls']+=1;args=n.unpack('<2I',sp+4);ck(list(args),[SC+0x120,SC],'treeArguments');observations.append({'edge':'tree','argumentsMatch':list(args)==[SC+0x120,SC],'before':readstate()});n.pack('<i',SC+0x120,n.unpack('<i',SC+0x120)[0]+5);n.pack('<3I',SC+0x140,0x33445566,TREE,0x120)
 elif address==0x603cc0:
  counts['cameraRestoreAdapterCalls']+=1;ck(n.unpack('<I',sp+4)[0],0x973760,'restoreArgument');observations.append({'edge':'restore','argumentMatches':n.unpack('<I',sp+4)[0]==0x973760,'before':readstate()});n.pack('<3f',0x973718,9,0,9)
 mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for a in[0x5d6900,0x5d6f30,0x5eeb30,0x5d8fb0,0x603cc0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def setup(c):
 n.write(SC,bytes(0x160));n.write(ALT,bytes(0x40));n.pack('<i',SC+0x1c,7);n.pack('<i',ALT+0x1c,11);n.pack('<I',SC+0x128,ALT if c['alternate']else 0);n.pack('<I',SC+0x12c,G if c['gridPresent']else 0);n.pack('<I',SC+0x134,0x1234 if c['treePresent']else 0);n.pack('<I',SC+0x138,0x2345 if c['portalPresent']else 0);n.pack('<i',SC+0x120,91);n.pack('<3I',SC+0x140,0x55667788,0x12345678,0xffffffff);n.pack('<I',SC+0x13c,0)
 n.write(G,bytes(0x40));n.pack('<I',G+4,3);n.pack('<6f',G+8,-2,0,-2,0,1,1);n.pack('<2I',G+0x20,c['storageMode'],4);n.pack('<I',G+0x2c,T);n.pack('<9I',T,*[MASK if c['nonnull']else 0]*9);n.write(MASK,bytes.fromhex(c['maskHex']));n.write(TREE,bytes.fromhex('c0ff3355'));n.write(CACHE,bytes.fromhex(c['initialCacheHex']));n.pack('<i',0x80b9e4,c['initialCacheIndex']);n.pack('<i',0x29a9c48,0)
 for addr,key in[(0x80b6f4,'visible'),(0x80b6f8,'gridEnabled'),(0x80ba58,'portalEnabled'),(0x80ba14,'treeEnabled'),(0x973940,'requestedMode'),(0x97394c,'initialMode'),(0x97393c,'initialVisibilityActive'),(0x973960,'initialGridActive')]:n.pack('<I',addr,int(c[key]))
 n.pack('<3f',0x973718,23,0,24);n.write(0x280a2f0,bytes([0xa5])*625)
def execute(c):
 global cfg
 cfg=c;events.clear();observations.clear();before=readstate();beforeBytes=n.read(SC,0x160);ret=n.call(0x5f3c80,[SC,c['workspace']]);after=readstate();active=c['workspace']!=0 and c['visible'];grid=active and c['gridEnabled']and c['gridPresent'];portal=active and c['portalEnabled']and c['portalPresent'];tree=active and not portal and c['treeEnabled']and c['treePresent'];restore=active and c['requestedMode']==1;expectedEvents=[]if not active else['0x5d6900']+(['0x5d6f30']if grid else[])+(['0x5eeb30']if portal else['0x5d8fb0']if tree else[])+(['0x603cc0']if restore else[]);ck(events,expectedEvents,['calls',len(cases)]);ck(ret,SC+0x120 if active else 0,['returned',len(cases)])
 expected=dict(before)
 if active:
  expected.update(contextCount=(before['alternateCount']+3 if c['alternate']else before['legacyCount']+2),scratch=0,pointer='null',contextFlags=0xf00a,visibilityActive=True,cameraMode=c['requestedMode'],cameraX=c['cameraAfterX'],cameraZ=c['cameraAfterZ'],legacyCount=before['legacyCount']+2,alternateCount=before['alternateCount']+3 if c['alternate']else None)
  if grid and -2<=c['cameraAfterX']<=0 and -2<=c['cameraAfterZ']<=0:
   expected.update(pointer='null'if not c['nonnull']else'cache'if c['storageMode']==1 else'raw',gridActive=c['nonnull'])
   if c['nonnull']and c['storageMode']==1:
    cell=int(c['cameraAfterZ']+2)*3+int(c['cameraAfterX']+2)
    if before['cacheIndex']!=cell:expected.update(cacheIndex=cell,cacheHex='ffffffff'if c['maskHex']=='11'else'00000000')
  if portal:expected['portalAttached']=True
  if tree:expected.update(contextCount=expected['contextCount']+5,scratch=0x33445566,pointer='tree',contextFlags=0x121)
  if restore:expected.update(cameraX=9.,cameraZ=9.)
 else:ck(n.read(SC,0x160).hex(),beforeBytes.hex(),['earlyPreservesSceneBytes',len(cases)])
 ck(after,expected,['state',len(cases)]);return{'input':dict(c),'before':before,'native':after,'returned':bool(ret),'calls':list(events),'serviceObservations':list(observations)}
for k,gates in enumerate(itertools.product([False,True],repeat=8)):
 workspace,visible,gridEnabled,gridPresent,portalEnabled,portalPresent,treeEnabled,treePresent=gates
 for mode in[0,1]:
  c=dict(workspace=0x77889900 if workspace else 0,visible=visible,gridEnabled=gridEnabled,gridPresent=gridPresent,portalEnabled=portalEnabled,portalPresent=portalPresent,treeEnabled=treeEnabled,treePresent=treePresent,alternate=bool(k&1),requestedMode=mode,initialMode=1-mode,initialVisibilityActive=bool(k&2),initialGridActive=bool(k&4),storageMode=k&1,nonnull=bool(k&8),maskHex='11'if k&1 else'aabbccdd',initialCacheHex='40414243',initialCacheIndex=4 if k&16 else -1,cameraAfterX=1. if k%3==0 else -1.,cameraAfterZ=-1.)
  setup(c);cases.append(execute(c))
# Stateful sequence keeps shared cache across distinct grids and early exits.
base=dict(workspace=0x77889900,visible=True,gridEnabled=True,gridPresent=True,portalEnabled=False,portalPresent=False,treeEnabled=False,treePresent=False,alternate=True,requestedMode=0,initialMode=0,initialVisibilityActive=False,initialGridActive=False,storageMode=1,nonnull=True,maskHex='11',initialCacheHex='01020304',initialCacheIndex=-1,cameraAfterX=-1.,cameraAfterZ=-1.);setup(base);steps=[]
for step in range(4):
 c=dict(base)
 if step==1:c['maskHex']='10';n.write(MASK,b'\x10');n.write(G+0x100,n.read(G,0x40));n.pack('<I',SC+0x12c,G+0x100)
 if step==2:c['workspace']=0
 if step==3:c['cameraAfterX']=1.;c['requestedMode']=1;n.pack('<i',0x973940,1)
 steps.append(execute(c))
sequences.append(steps)
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in md.disasm(n.read(0x5f3c80,0xd8),0x5f3c80)]
(R/(PREFIX+'-assembly.json')).write_text(json.dumps({'binarySHA256':n.sha256,'address':'0x5f3c80','instructions':assembly},indent=2)+'\n')
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt',encoding='utf8')as f:json.dump({'cases':cases,'sequences':sequences,'counts':{'individualCases':len(cases),'sequenceSteps':sum(map(len,sequences))}},f)
report={'schema':'original-stateful-visibility-dispatcher-v1','passed':not errors,'binarySHA256':n.sha256,'checks':checks,'counts':{**counts,'cases':len(cases),'sequenceSteps':sum(map(len,sequences))},'errors':errors[:30],'adapters':{'0x5d6900':'Stateful camera service setsmode/position,updates counts and initial context before native reset. No camera-matrix equivalence claimed.','0x5d8fb0':'Stateful tree service observes nativearguments/contextthen changescount/scratch/pointer/flags; actual tree traversal not claimed.','0x603cc0':'Stateful camera restore observes fixedglobalargument and changesposition; actual camera restore not claimed.'},'unchangedNative':['0x5f3c80','0x5d6f30','0x5d6f00','0x5eeb30','0x600bd0','0x6e6b90','0x6e6950'],'portalScope':'Actual portal entry executes empty required counts:visibilityattachment and preserved bits; recursion covered separately,not newly asserted here.','fixtureFile':PREFIX+'-native-fixtures.json.gz','retention':'Every case and sequence step retained including before/after, call order and service-edge observations.','portableReplayCases':len(cases)+sum(map(len,sequences)),'preparedManagedAssertions':5*(len(cases)+sum(map(len,sequences)))+sum(c['returned'] for c in cases)+sum(s['returned'] for seq in sequences for s in seq)+2*(sum(len(c['serviceObservations'])for c in cases)+sum(len(s['serviceObservations'])for seq in sequences for s in seq))}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));sys.exit(0 if not errors else 1)
