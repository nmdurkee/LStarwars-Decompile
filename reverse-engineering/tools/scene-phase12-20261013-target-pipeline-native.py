"""Single-backend original target/cache/state/refresh chain; only final COM edges adapted."""
import importlib.util,struct,json,gzip,random,copy,ast
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase12-20261013-target-pipeline'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86();W=x87.wide;A=x87.add;M=x87.mul;D=x87.div;S=x87.store;sub=lambda a,b:A(a,(-b[0],b[1]));f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0];words=lambda a:[word(v)for v in a];i32=lambda v:((v+0x80000000)&0xffffffff)-0x80000000
for file,names in [('scene-phase11-20261013-refresh-native.py',['trunc','position','physical','extent','setup','inputs','seed']),('scene-phase5-20261013-viewport-native.py',['readViewport','modelReset','auxiliary'])]:
 module=ast.parse((P/file).read_text());defs=[v for v in module.body if isinstance(v,ast.FunctionDef)and v.name in names];exec(compile(ast.Module(body=defs,type_ignores=[]),file,'exec'))
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
GLOBAL=0x29765c8;SURFACE=n.DATA+0x1000;DEVICEA=n.DATA+0x3000;DEVICEB=n.DATA+0x5000;VTA=n.DATA+0x4000;VTB=n.DATA+0x6000;TARGET=n.STOP+0x100;STATE=n.STOP+0x200;VIEWPORT=n.STOP+0x300
for device,vt in [(DEVICEA,VTA),(DEVICEB,VTB)]:
 n.pack('<I',device,vt)
 for offset,edge in [(0x94,TARGET),(0xe4,STATE),(0xbc,VIEWPORT)]:n.pack('<I',vt+offset,edge)
n.pack('<I',0x29a9c48,0);identity=list(n.unpack('<16f',0x806680));rng=random.Random(0x6e372012);checks=0;errors=[];sequences=[];events=[];plans=[];sourcePointer=None
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
w=lambda b,o,v:struct.pack_into('<I',b,o,v&0xffffffff)
ENUMS=[168,190,191,192,7,14,23,22,15,27,19,20]
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<20:errors.append({'label':label,'native':a,'expected':e})
def snap():return {'backendHex':n.read(GLOBAL,0x800).hex(),'surfaceHex':n.read(SURFACE,0x20).hex(),'configuration':n.unpack('<i',0x2974d1c)[0],'renderStates':{'enabled':n.read(0x8282b4,1)[0],'values':list(n.unpack('<12I',0x297c098)),'marker':n.unpack('<I',0x297c094)[0],'lastResult':n.unpack('<I',0x297bea0)[0]},'inputs':inputs(),'viewport':readViewport()}
def entry(mu,address,size,_):
 global sourcePointer
 sourcePointer=n.unpack('<I',mu.reg_read(UC_X86_REG_ESP)+4)[0]
def com(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret,device=n.unpack('<2I',sp);tag={TARGET:'target',STATE:'state',VIEWPORT:'viewport'}[address];args=list(n.unpack('<2I',sp+8))if address!=VIEWPORT else list(n.unpack('<6I',n.unpack('<I',sp+8)[0]));event={'edge':tag,'device':device,'arguments':args,'before':snap()}
 if address==VIEWPORT:event['sourceHex']=n.read(sourcePointer,24).hex()
 events.append(event);plan=plans[len(events)-1]
 for change in plan['backendChanges']:n.pack('<I',GLOBAL+change['offset'],change['word'])
 if address!=VIEWPORT:
  for change in plan['surfaceChanges']:n.pack('<I',SURFACE+change['offset'],change['word'])
  n.pack('<i',0x2974d1c,plan['configuration']);n.write(0x8282b4,bytes([plan['enabled']]))
  for change in plan['cacheChanges']:n.pack('<I',0x297c098+change['index']*4,change['word'])
  n.pack('<I',0x297c094,plan['marker']);n.pack('<I',0x297bea0,plan['lastResult']);n.pack('<2f',0x80e250,*plan['bias'])
 else:
  packet=n.unpack('<I',sp+8)[0]
  for change in plan['sourceChanges']:n.pack('<I',sourcePointer+change['index']*4,change['word'])
  for change in plan['argumentChanges']:n.pack('<I',packet+change['index']*4,change['word'])
 mu.reg_write(UC_X86_REG_EAX,plan['return']);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+(12 if address==VIEWPORT else 16));mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,entry,begin=0x6e2470,end=0x6e2470)
for edge in [TARGET,STATE,VIEWPORT]:n.mu.hook_add(UC_HOOK_CODE,com,begin=edge,end=edge)
def decode(s):
 t=copy.deepcopy(s);t['backend']=bytearray.fromhex(t.pop('backendHex'));t['surface']=bytearray.fromhex(t.pop('surfaceHex'));return t
def encode(s):return dict(backendHex=s['backend'].hex(),surfaceHex=s['surface'].hex(),**{k:copy.deepcopy(s[k])for k in ['configuration','renderStates','inputs','viewport']})
def modelCom(s,tag,args,modelEvents,source=None,offset=0):
 event={'edge':tag,'device':u(s['backend'],4),'arguments':args[:],'before':encode(s)}
 if tag=='viewport':event['sourceHex']=source[offset:offset+24].hex()
 plan=plans[len(modelEvents)];modelEvents.append(event)
 for change in plan['backendChanges']:w(s['backend'],change['offset'],change['word'])
 if tag!='viewport':
  for change in plan['surfaceChanges']:w(s['surface'],change['offset'],change['word'])
  s['configuration']=plan['configuration'];rs=s['renderStates'];rs['enabled']=plan['enabled']
  for change in plan['cacheChanges']:rs['values'][change['index']]=change['word']
  rs['marker']=plan['marker'];rs['lastResult']=plan['lastResult'];s['inputs']['bias']=plan['bias'][:]
 else:
  for change in plan['sourceChanges']:w(source,offset+change['index']*4,change['word'])
 return plan['return']
def modelState(s,index,value,out):
 rs=s['renderStates']
 if rs['enabled'] and index in ENUMS:
  cache=ENUMS.index(index)
  if rs['values'][cache]==value:return cache
  rs['values'][cache]=value
 rs['marker']=0xffffffff;result=modelCom(s,'state',[index,value],out);rs['lastResult']=result;return result
def modelTarget(s,slot,handle,out):
 b=s['backend'];limit=(struct.unpack_from('<H',b,0xf8)[0]if u(b,0x638)==0 and s['configuration']>=2 else 1)-1
 if i32(slot)>limit:return slot
 offset=(0x6f0+slot*4)&0xffffffff
 if offset>len(b)-4:raise ValueError('Unresolved cache cell')
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
def modelPipeline(s,present,slot,out):
 b=s['backend'];surface=s['surface'];handle=u(surface,8)if present else 0
 def resize(width,height):
  c=s['inputs'];c['screen']=[width,height];c['origin']=[int(width/2),int(height/2)];return modelRefresh(s,out)
 if handle:
  result=modelTarget(s,slot,handle,out)
  return resize(*struct.unpack_from('<2H',surface,0x14))if slot==0 else result
 if slot:return modelTarget(s,slot,0,out)
 if u(b,0x638):modelTarget(s,0,u(b,0x6b0),out);modelState(s,168,0,out);w(b,0x6e8,u(b,0x6b0))
 else:modelTarget(s,0,u(b,0x6c4),out);w(b,0x6e8,u(b,0x6c4))
 return resize(i32(u(b,0x138)),i32(u(b,0x13c)))
def planSeed(case,index):
 changes=[]
 if case%5==0:changes=[{'offset':4,'word':DEVICEB if index%2==0 else DEVICEA},{'offset':0x638,'word':index%2},{'offset':0x138,'word':rng.randrange(0,3000)},{'offset':0x13c,'word':rng.randrange(0,2000)},{'offset':0x6b0,'word':rng.getrandbits(32)},{'offset':0x6c4,'word':rng.getrandbits(32)}]
 # These changes are also allowed at viewport edges; numeric viewport globals remain stable.
 return {'return':rng.choice([0,1,0x80004005,0xffffffff]),'backendChanges':changes,'surfaceChanges':[{'offset':0x14,'word':rng.randrange(0,4000)|(rng.randrange(0,4000)<<16)}]if case%3==0 else [],'configuration':rng.choice([-1,0,1,2,3]),'enabled':0 if case%7==0 else 1,'cacheChanges':[{'index':case%12,'word':rng.getrandbits(32)}]if case%4==0 else [],'marker':rng.getrandbits(32),'lastResult':rng.getrandbits(32),'bias':[f32(rng.uniform(-.5,.5))for _ in range(2)],'sourceChanges':[{'index':(case+index)%6,'word':rng.getrandbits(32)}]if case%5==0 else [],'argumentChanges':[{'index':(case+index+1)%6,'word':rng.getrandbits(32)}]if case%3==0 else []}
slots=[0,0,0,1,2,7,0xffffffff,0xfffffffe,0xfffffff0,0xffffffe0,0x80000000,0x80000001]
for kind,count in [('state',1024),('pipeline',1024)]:
 for case in range(count):
  c=seed(case);setup(c);b=bytearray(0x800)
  for offset in range(0,0x800,4):w(b,offset,rng.getrandbits(32))
  w(b,4,DEVICEA);w(b,0x138,[0,1,3,639,640,1920,-1,-3][case%8]);w(b,0x13c,[0,1,3,223,224,1080,-1,-3][case//8%8]);w(b,0x638,[0,1,0xffffffff][case%3]);struct.pack_into('<H',b,0xf8,[0,1,2,4,8][case//3%5]);n.write(GLOBAL,b);sf=bytearray(0x20);w(sf,8,rng.getrandbits(32)if case%3 else 0);w(sf,0x14,rng.randrange(0,65536)|(rng.randrange(0,65536)<<16));n.write(SURFACE,sf);n.pack('<i',0x2974d1c,[-1,0,1,2,3][case%5]);n.write(0x8282b4,bytes([0 if case%7==0 else 1]));rs=[rng.getrandbits(32)for _ in range(12)];index=(ENUMS+[0,6,8,193,0xffffffff,0x80000000])[case%18];value=rng.getrandbits(32)
  if index in ENUMS and case%4==0:rs[ENUMS.index(index)]=value
  n.pack('<12I',0x297c098,*rs);n.pack('<I',0x297c094,rng.getrandbits(32));n.pack('<I',0x297bea0,rng.getrandbits(32))
  for address in [0x80ba68,0x971620]:n.pack('<16f',address,*[f32(rng.uniform(-2,2))for _ in range(16)])
  for address in [0x28492f8,0x981c48,0x992294,0x981c94,0x963e40,0x963e44,0x963e48,0x963e4c]:n.pack('<f',address,f32(rng.uniform(-2,2)))
  n.pack('<16f',0x806680,*identity);before=snap();s=decode(before);calls=[];slot=slots[case%len(slots)];present=case%4!=0
  if kind=='pipeline' and case%6==0:
   handle=u(sf,8)if present else 0
   if slot==0 and not handle:handle=u(b,0x6b0 if u(b,0x638)else 0x6c4)
   off=(0x6f0+slot*4)&0xffffffff
   if off<=len(b)-4:w(b,off,handle);n.write(GLOBAL,b);before=snap();s=decode(before)
  for step in range(2):
   plans=[planSeed(case,j)for j in range(8)];out=[];events.clear();requestValue=value if step==0 or case%3 else rng.getrandbits(32)
   expectedResult=modelState(s,index,requestValue,out)if kind=='state' else modelPipeline(s,present,slot,out)
   result=n.call(0x6e5340,[index,requestValue])if kind=='state' else n.call(0x6e3720,[SURFACE if present else 0,slot],regs={UC_X86_REG_ECX:GLOBAL})
   after=snap();ck(after,encode(s),[kind,'complete state',case,step]);ck(events,out,[kind,'COM boundary order',case,step]);ck(result,expectedResult,[kind,'result',case,step]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+(0xe004 if kind=='state'else 0xe00c),[kind,'return ABI',case,step]);calls.append({'index':index,'value':requestValue,'slot':slot,'present':present,'plans':copy.deepcopy(plans),'native':after,'nativeEvents':copy.deepcopy(events),'nativeResult':result})
  sequences.append({'kind':kind,'before':before,'calls':calls})
fixture={'identityWords':words(identity),'deviceA':DEVICEA,'deviceB':DEVICEB,'sequences':sequences};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));counts={'stateSequences':1024,'pipelineSequences':1024,'retainedPortableReplayCases':4096,'COMCalls':sum(len(c['nativeEvents'])for seq in sequences for c in seq['calls'])};counts.update({tag+'COMCalls':sum(e['edge']==tag for seq in sequences for c in seq['calls']for e in c['nativeEvents'])for tag in ['target','state','viewport']});report={'schema':'original-single-backend-target-pipeline-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':counts,'adapters':{'vtable+0x94':'Final raw SetRenderTarget COM edge, opaque HRESULT and declared mutations.','vtable+0xe4':'Final raw SetRenderState COM edge, opaque HRESULT and declared mutations.','vtable+0xbc':'Final local-packet SetViewport COM edge, source/argument/backend mutations; no numeric viewport global mutation.'},'limits':['Original6e3720/6e2880/6e5340/6e2510 and viewport setters/reset/forwarders/CRT execute unchanged, sharing fixed backend29765c8. No intermediate callee/arithmetic/D3DX adapters.','Bounded resolved backend/surface/device lifetime and explicit initialization/configuration/cache globals. Signed negative/wrapped target slots retained where address resolves inside0x800 bytes.','Finite viewport setter/runtime arithmetic, nonzero source axes, mode0 converter and fitting Int32 results; numeric viewport globals stable at viewport COM edge. Raw packet/depth mutations remain opaque integer words.','Failures publish caches and do not cause rollback. COM mutations of target dimensions/flag/surface/cache/bias before refresh are read at their original points.','No authored frame initialization, hardware COM/GPU behavior or whole-world rendering claim. Native/Python differential passed; managed execution pending.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report));raise SystemExit(0 if not errors else 1)
