"""Actual target/depth restore/clear consumers and whole viewport refresh chain."""
import importlib.util,struct,json,gzip,random,copy,ast
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase14-20261013-target-reset'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86();W=x87.wide;A=x87.add;M=x87.mul;D=x87.div;S=x87.store;sub=lambda a,b:A(a,(-b[0],b[1]));f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0];words=lambda a:[word(v)for v in a];i32=lambda v:((v+0x80000000)&0xffffffff)-0x80000000
for file,names in [('scene-phase11-20261013-refresh-native.py',['trunc','position','physical','extent','setup','inputs','seed']),('scene-phase5-20261013-viewport-native.py',['readViewport','modelReset','auxiliary'])]:
 module=ast.parse((P/file).read_text());defs=[v for v in module.body if isinstance(v,ast.FunctionDef)and v.name in names];exec(compile(ast.Module(body=defs,type_ignores=[]),file,'exec'))
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
GLOBAL=0x29765c8;DEVICEA=n.DATA+0x3000;DEVICEB=n.DATA+0x5000;VTA=n.DATA+0x4000;VTB=n.DATA+0x6000;TARGET=n.STOP+0x100;DEPTH=n.STOP+0x200;VIEWPORT=n.STOP+0x300
for device,vt in [(DEVICEA,VTA),(DEVICEB,VTB)]:
 n.pack('<I',device,vt)
 for offset,edge in [(0x94,TARGET),(0x9c,DEPTH),(0xbc,VIEWPORT)]:n.pack('<I',vt+offset,edge)
n.pack('<I',0x29a9c48,0);identity=list(n.unpack('<16f',0x806680));rng=random.Random(0x6e365014);checks=0;errors=[];sequences=[];events=[];plans=[];sourcePointer=None
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
w=lambda b,o,v:struct.pack_into('<I',b,o,v&0xffffffff)
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<20:errors.append({'label':label,'native':a,'expected':e})
def caps():return {'firstEnabled':n.read(0x8264b8,1)[0],'secondEnabled':n.read(0x8264c4,1)[0],'firstMode':n.unpack('<I',0x8264b0)[0],'secondMode':n.unpack('<I',0x8264bc)[0]}
def writeCaps(c):
 n.write(0x8264b8,bytes([c['firstEnabled']]));n.write(0x8264c4,bytes([c['secondEnabled']]));n.pack('<I',0x8264b0,c['firstMode']);n.pack('<I',0x8264bc,c['secondMode'])
def snap():return {'backendHex':n.read(GLOBAL,0x800).hex(),'configuration':n.unpack('<i',0x2974d1c)[0],'capabilities':caps(),'inputs':inputs(),'viewport':readViewport()}
def entry(mu,address,size,_):
 global sourcePointer
 sourcePointer=n.unpack('<I',mu.reg_read(UC_X86_REG_ESP)+4)[0]
def com(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret,device=n.unpack('<2I',sp);tag={TARGET:'target',DEPTH:'depth',VIEWPORT:'viewport'}[address];args=list(n.unpack('<2I',sp+8))if address==TARGET else [n.unpack('<I',sp+8)[0]]if address==DEPTH else list(n.unpack('<6I',n.unpack('<I',sp+8)[0]));event={'edge':tag,'device':device,'arguments':args,'before':snap()}
 if address==VIEWPORT:event['sourceHex']=n.read(sourcePointer,24).hex()
 events.append(event);plan=plans[len(events)-1]
 for change in plan['backendChanges']:n.pack('<I',GLOBAL+change['offset'],change['word'])
 if address!=VIEWPORT:n.pack('<i',0x2974d1c,plan['configuration']);writeCaps(plan['capabilities']);n.pack('<2f',0x80e250,*plan['bias'])
 else:
  packet=n.unpack('<I',sp+8)[0]
  for change in plan['sourceChanges']:n.pack('<I',sourcePointer+change['index']*4,change['word'])
  for change in plan['argumentChanges']:n.pack('<I',packet+change['index']*4,change['word'])
 mu.reg_write(UC_X86_REG_EAX,plan['return']);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+(16 if address==TARGET else 12));mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,entry,begin=0x6e2470,end=0x6e2470)
for edge in [TARGET,DEPTH,VIEWPORT]:n.mu.hook_add(UC_HOOK_CODE,com,begin=edge,end=edge)
def decode(s):
 t=copy.deepcopy(s);t['backend']=bytearray.fromhex(t.pop('backendHex'));return t
def encode(s):return dict(backendHex=s['backend'].hex(),**{k:copy.deepcopy(s[k])for k in ['configuration','capabilities','inputs','viewport']})
def modelCom(s,tag,args,out,source=None,offset=0):
 event={'edge':tag,'device':u(s['backend'],4),'arguments':args[:],'before':encode(s)}
 if tag=='viewport':event['sourceHex']=source[offset:offset+24].hex()
 plan=plans[len(out)];out.append(event)
 for change in plan['backendChanges']:w(s['backend'],change['offset'],change['word'])
 if tag!='viewport':s['configuration']=plan['configuration'];s['capabilities']=copy.deepcopy(plan['capabilities']);s['inputs']['bias']=plan['bias'][:]
 else:
  for change in plan['sourceChanges']:w(source,offset+change['index']*4,change['word'])
 return plan['return']
def maximum(s):return (struct.unpack_from('<H',s['backend'],0xf8)[0]if u(s['backend'],0x638)==0 and s['configuration']>=2 else 1)-1
def modelTarget(s,slot,handle,out):
 b=s['backend']
 if slot>maximum(s):return slot
 offset=0x6f0+slot*4
 if u(b,offset)==handle:return slot
 w(b,offset,handle);return modelCom(s,'target',[slot,handle],out)
def modelViewport(s,source,offset,out):
 args=[u(source,offset+j*4)for j in range(6)];args[2]=min(args[2],s['inputs']['screen'][0]&0xffffffff);args[3]=min(args[3],s['inputs']['screen'][1]&0xffffffff);modelCom(s,'viewport',args,out,source,offset)
 for j in range(6):last=u(source,offset+j*4);w(s['backend'],0x170+j*4,last)
 return last
def modelRefresh(s,out):
 c=s['inputs'];b=s['backend']
 def full():
  for j,v in enumerate([0,0]+[v&0xffffffff for v in c['screen']]+[0,0x3f800000]):w(b,0x170+j*4,v)
 full();c['depthWords']=[0,0x3f800000];c['rectangle'][:2]=physical(c,0.,0.);c['rectangle'][2:]=extent(c,640.,224.);c['dirty']=1;s['viewport']['dirty']=1;after,resetEvents=modelReset(s['viewport'],c);s['viewport']=resetEvents[0]['stateAtService'];c['dirty']=0;temporary=bytearray(struct.pack('<6I',*resetEvents[0]['words']));modelViewport(s,temporary,0,out);s['viewport']=after;full();return modelViewport(s,b,0x170,out)
def modelResetConsumer(s,kind,out):
 b=s['backend']
 if kind=='restore':
  if u(b,0x638):modelTarget(s,0,u(b,0x6b0),out);w(b,0x6e8,u(b,0x6b0))
  else:
   for slot in range(4):
    if slot==0:
     offset=0x6c4 if u(b,0x6c4)else 0x6b0;modelTarget(s,0,u(b,offset),out);w(b,0x6e8,u(b,offset))
    else:
     c=s['capabilities'];multi=slot<=2 and((c['firstEnabled']and c['firstMode']==2)or(c['secondEnabled']and c['secondMode']==2));modelTarget(s,slot,u(b,0x6c4+slot*4)if multi else 0,out)
 else:
  modelTarget(s,0,u(b,0x6b0),out);w(b,0x6e8,u(b,0x6b0))
  for slot in range(1,4):
   offset=0x6f0+slot*4
   if slot<=maximum(s)and u(b,offset):w(b,offset,0);modelCom(s,'target',[slot,0],out)
 modelCom(s,'depth',[u(b,0x6ec)],out);width=i32(u(b,0x138));height=i32(u(b,0x13c));s['inputs']['screen']=[width,height];s['inputs']['origin']=[int(width/2),int(height/2)];return modelRefresh(s,out)
def capSeed(i):return {'firstEnabled':[0,1,255][i%3],'secondEnabled':[0,1,128][i//3%3],'firstMode':[0,1,2,3,0xffffffff][i//9%5],'secondMode':[0,1,2,3,0x80000000][i//45%5]}
def planSeed(case,index):
 changes=[]
 if case%5==0:changes=[{'offset':4,'word':DEVICEB if index%2==0 else DEVICEA},{'offset':0x638,'word':index%2},{'offset':0x138,'word':rng.randrange(0,3000)},{'offset':0x13c,'word':rng.randrange(0,2000)},{'offset':0x6b0,'word':rng.getrandbits(32)},{'offset':0x6c4,'word':rng.getrandbits(32)},{'offset':0x6ec,'word':rng.getrandbits(32)}]
 if case%7==0:changes.append({'offset':0x6f0+((index+1)%4)*4,'word':rng.choice([0,rng.getrandbits(32)])})
 if case%11==0:changes.append({'offset':0xf8,'word':rng.choice([0,1,2,3,4,65535])})
 return {'return':rng.choice([0,1,0x80004005,0xffffffff]),'backendChanges':changes,'configuration':rng.choice([-1,0,1,2,3]),'capabilities':capSeed(case+index*29),'bias':[f32(rng.uniform(-.5,.5))for _ in range(2)],'sourceChanges':[{'index':(case+index)%6,'word':rng.getrandbits(32)}]if case%5==0 else [],'argumentChanges':[{'index':(case+index+1)%6,'word':rng.getrandbits(32)}]if case%3==0 else []}
for sequenceKind,count in [('restore',768),('clear',768),('mixed',256)]:
 for case in range(count):
  c=seed(case);setup(c);b=bytearray(rng.randbytes(0x800));w(b,4,DEVICEA);w(b,0x138,[0,1,3,639,640,1920,-1,-3][case%8]);w(b,0x13c,[0,1,3,223,224,1080,-1,-3][case//8%8]);w(b,0x638,[0,0,1,0xffffffff][case%4]);w(b,0x6c4,0 if case%3==0 else rng.getrandbits(32));struct.pack_into('<H',b,0xf8,[0,1,2,3,4,8,65535][case//4%7]);configuration=[-2147483648,-1,0,1,2,3,2147483647][case//28%7]
  for slot in range(4):w(b,0x6f0+slot*4,0 if(case+slot)%4==0 else u(b,0x6b0)if slot==0 and case%4==0 else rng.getrandbits(32))
  n.write(GLOBAL,b);n.pack('<i',0x2974d1c,configuration);writeCaps(capSeed(case))
  for address in [0x80ba68,0x971620]:n.pack('<16f',address,*[f32(rng.uniform(-2,2))for _ in range(16)])
  for address in [0x28492f8,0x981c48,0x992294,0x981c94,0x963e40,0x963e44,0x963e48,0x963e4c]:n.pack('<f',address,f32(rng.uniform(-2,2)))
  n.pack('<16f',0x806680,*identity);before=snap();s=decode(before);calls=[]
  for step in range(2):
   kind=sequenceKind if sequenceKind!='mixed' else ('restore'if(step+case)%2==0 else'clear');plans=[planSeed(case,j)for j in range(8)];out=[];events.clear();expectedResult=modelResetConsumer(s,kind,out);result=n.call(0x6e33a0 if kind=='restore'else 0x6e3650,regs={UC_X86_REG_ECX:GLOBAL});after=snap();ck(after,encode(s),[kind,'complete state',case,step]);ck(events,out,[kind,'all final COM boundary order',case,step]);ck(result,expectedResult,[kind,'tail refresh result',case,step]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe004,[kind,'tail return ABI',case,step]);calls.append({'kind':kind,'plans':copy.deepcopy(plans),'native':after,'nativeEvents':copy.deepcopy(events),'nativeResult':result})
  sequences.append({'kind':sequenceKind,'before':before,'calls':calls})
fixture={'identityWords':words(identity),'deviceA':DEVICEA,'deviceB':DEVICEB,'sequences':sequences};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));allCalls=[c for seq in sequences for c in seq['calls']];counts={'restoreCalls':sum(c['kind']=='restore'for c in allCalls),'clearAdditionalCalls':sum(c['kind']=='clear'for c in allCalls),'retainedPortableReplayCases':len(allCalls),'COMCalls':sum(len(c['nativeEvents'])for c in allCalls)};counts.update({tag+'COMCalls':sum(e['edge']==tag for c in allCalls for e in c['nativeEvents'])for tag in ['target','depth','viewport']});report={'schema':'original-target-depth-reset-consumers-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':counts,'adapters':{'vtable+0x94':'Final raw target COM call with opaque HRESULT and declared backend/configuration/capability/bias mutations.','vtable+0x9c':'Final raw depth-surface COM call with opaque HRESULT and declared backend/configuration/capability/bias mutations.','vtable+0xbc':'Final local viewport COM call, opaque HRESULT and raw source/argument/backend mutations; numeric viewport globals stable.'},'limits':['Original6e33a0/6e3650/6e2880/6e2510 and viewport setters/reset/forwarders/CRT run unchanged over one fixed backend29765c8. No intermediate helper or arithmetic adapters.','Restore selects initial flag branch once, then rereads capabilities and target cache gates per extra slot. Active handle is reread after initial target callback.','Clear-additional rereads signed configuration, current flag and ushort count per slot. Changed cache cells zero before direct COM; opaque HRESULT never causes rollback.','Depth target always forwarded after target calls; fresh backend dimensions then populate screen/origin globals and feed actual context refresh. Both callers tail-jump to actual refresh and return its final raw word.','Finite viewport numeric globals and fitting mode0 integer conversion; nonzero calibration source axes. Raw handles/cache/source packet words opaque, resolved device/image lifetimes supplied externally.','Device/capability/mode-table bootstrap, authored scene/frame binding and real COM/GPU actions remain external. Native/Python differential passed; managed execution pending.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report));raise SystemExit(0 if not errors else 1)
