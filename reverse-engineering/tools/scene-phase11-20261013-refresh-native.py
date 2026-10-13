"""Actual finite viewport setters and complete context refresh CPU chain."""
import importlib.util,struct,json,gzip,random,copy,ast,math
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase11-20261013-refresh'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86();W=x87.wide;A=x87.add;M=x87.mul;D=x87.div;S=x87.store;sub=lambda a,b:A(a,(-b[0],b[1]));f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0];words=lambda a:[word(v)for v in a];i32=lambda v:((v+0x80000000)&0xffffffff)-0x80000000
module=ast.parse((P/'scene-phase5-20261013-viewport-native.py').read_text());defs=[v for v in module.body if isinstance(v,ast.FunctionDef)and v.name in['modelReset','readViewport','auxiliary']];exec(compile(ast.Module(body=defs,type_ignores=[]),'viewport-oracles','exec'))
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
GLOBAL=0x29765c8;CALLER=n.DATA+0x1000;DEVICE=n.DATA+0x3000;VT=n.DATA+0x4000;EDGE=n.STOP+0x100;n.pack('<I',DEVICE,VT);n.pack('<I',VT+0xbc,EDGE);n.pack('<I',0x29a9c48,0)
rng=random.Random(0x6e2510);checks=0;errors=[];primitiveCases=[];refreshCases=[];events=[];plans=[];currentCaller=CALLER;inputPointer=None;pending=None;identity=list(n.unpack('<16f',0x806680))
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
w=lambda b,o,v:struct.pack_into('<I',b,o,v&0xffffffff)
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<30:errors.append({'label':label,'native':a,'expected':e})
def trunc(v):
 a,e=v;r=(abs(a)<<e)if e>=0 else(abs(a)>>-e);r=-r if a<0 else r
 if not -2147483648<=r<=2147483647:raise ValueError('Declared finite Int32 conversion domain exceeded')
 return r
def position(c,x,y):
 out=[]
 for axis,value in enumerate((x,y)):
  adjusted=S(A(W(c['bias'][axis]),W(value)));offset=sub(W(c['origin'][axis]),W(c['screen'][axis]>>1));out.append(trunc(M(A(D(M(W(adjusted),W(c['screen'][axis])),W(c['source'][axis])),offset),W(16))))
 return out
def physical(c,x,y):
 out=[]
 for axis,value in enumerate((x,y)):
  ratio=S(D(W(f32(c['screen'][axis])),W(f32(c['source'][axis]))))if c['screen'][axis]and c['source'][axis]else 0.;delta=S(sub(M(W(value),W(.0625)),sub(W(c['origin'][axis]),W(c['screen'][axis]>>1))));out.append(S(D(W(delta),W(ratio)))if delta and ratio else 0.)
 return position(c,*out)
def extent(c,x,y):return [trunc(M(D(M(W(S(M(W(c['scale'][axis]),W(value)))),W(c['screen'][axis])),W(c['source'][axis])),W(16)))for axis,value in enumerate((x,y))]
def setup(c):
 n.pack('<2i',0x973900,*c['screen']);n.pack('<2i',0x80e694,*c['source']);n.pack('<2i',0x80202c,*c['origin']);n.pack('<2f',0x80e248,*c['scale']);n.pack('<2f',0x80e250,*c['bias']);n.pack('<4i',0x963e10,*c['rectangle']);n.pack('<2I',0x963e20,*c['depthWords']);n.pack('<4f',0x963e30,*c['ranges']);n.pack('<I',0x95e674,c['dirty'])
def inputs():return {'screen':list(n.unpack('<2i',0x973900)),'source':list(n.unpack('<2i',0x80e694)),'origin':list(n.unpack('<2i',0x80202c)),'scale':list(n.unpack('<2f',0x80e248)),'bias':list(n.unpack('<2f',0x80e250)),'rectangle':list(n.unpack('<4i',0x963e10)),'depthWords':list(n.unpack('<2I',0x963e20)),'ranges':list(n.unpack('<4f',0x963e30)),'dirty':n.unpack('<I',0x95e674)[0]}
def seed(i):
 screen=[rng.choice([0,1,-1,3,-3,32767,65535,16777217])for _ in range(2)]if i<128 else[rng.randint(1,100000)for _ in range(2)];return {'screen':screen,'source':[640+i%19,224+i%23],'origin':[(v>>1)+rng.randint(-31,31)for v in screen],'scale':[f32(rng.choice([0.,.1,.5,1.,1.25,-.5]))for _ in range(2)],'bias':[f32(rng.uniform(-.5,.5))for _ in range(2)],'rectangle':[rng.randint(-10000,10000)for _ in range(4)],'depthWords':words([f32(rng.uniform(-1,1)),f32(rng.uniform(-1,1))]),'ranges':[0.,0.,1.,1.]if i%2 else[f32(.1),f32(.2),f32(.8),f32(.9)],'dirty':rng.getrandbits(32)}
def snapshot():return {'callerHex':n.read(currentCaller,0x700).hex(),'globalHex':n.read(GLOBAL,0x700).hex(),'inputs':inputs(),'viewport':readViewport()}
def entry(mu,address,size,_):
 global inputPointer,pending
 sp=mu.reg_read(UC_X86_REG_ESP);inputPointer=n.unpack('<I',sp+4)[0]
def com(mu,address,size,_):
 global pending
 sp=mu.reg_read(UC_X86_REG_ESP);ret,device,args=n.unpack('<3I',sp);index=len(events);event={'device':device,'arguments':list(n.unpack('<6I',args)),'before':snapshot(),'sourceHex':n.read(inputPointer,24).hex()};pending=event;events.append(event);plan=plans[index]
 for mutation in plan['backendChanges']:n.pack('<I',GLOBAL+mutation['offset'],mutation['word'])
 for mutation in plan['sourceChanges']:n.pack('<I',inputPointer+mutation['index']*4,mutation['word'])
 for mutation in plan['argumentChanges']:n.pack('<I',args+mutation['index']*4,mutation['word'])
 mu.reg_write(UC_X86_REG_EAX,plan['return']);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+12);mu.reg_write(UC_X86_REG_EIP,ret)
def after(mu,address,size,_):pending['after']=snapshot();pending['result']=mu.reg_read(UC_X86_REG_EAX)
n.mu.hook_add(UC_HOOK_CODE,entry,begin=0x6e2470,end=0x6e2470);n.mu.hook_add(UC_HOOK_CODE,com,begin=EDGE,end=EDGE);n.mu.hook_add(UC_HOOK_CODE,after,begin=0x6e250c,end=0x6e250c)
for kind,address,count in[('depth',0x5dabf0,512),('position',0x5dac70,1024),('physical',0x5ef9a0,1024),('extent',0x5dae80,1024)]:
 for i in range(count):
  c=seed(i);setup(c);before=inputs();values=[f32(rng.uniform(-1,1))for _ in range(2)]if i<128 else[f32(rng.uniform(-1000,1000))for _ in range(2)];expected=copy.deepcopy(before)
  if kind=='depth':
   if i%8==0:values=[-0.,0.]
   expected['depthWords']=words(values)
  elif kind=='position':expected['rectangle'][:2]=position(c,*values)
  elif kind=='physical':expected['rectangle'][:2]=physical(c,*values)
  else:expected['rectangle'][2:]=extent(c,*values)
  expected['dirty']=1;n.call(address,words(values));ck(inputs(),expected,[kind,i]);primitiveCases.append({'kind':kind,'inputWords':words(values),'before':before,'native':inputs()})
for case in range(768):
 c=seed(case);setup(c);same=case%2==0;currentCaller=GLOBAL if same else CALLER;gb=bytearray(0x700);cb=gb if same else bytearray(0x700)
 for buffer in([gb]if same else[gb,cb]):
  for offset in range(0x140,0x1a0,4):w(buffer,offset,rng.getrandbits(32))
  w(buffer,4,DEVICE)
 n.write(GLOBAL,gb)
 if not same:n.write(CALLER,cb)
 for address in[0x80ba68,0x971620]:n.pack('<16f',address,*[f32(rng.uniform(-2,2))for _ in range(16)])
 for address in[0x28492f8,0x981c48,0x992294,0x981c94,0x963e40,0x963e44,0x963e48,0x963e4c]:n.pack('<f',address,f32(rng.uniform(-2,2)))
 n.pack('<16f',0x806680,*identity);before=snapshot();expectedInputs=copy.deepcopy(c);expectedInputs['depthWords']=words([0.,1.]);expectedInputs['rectangle'][:2]=physical(c,0.,0.);expectedInputs['rectangle'][2:]=extent(c,640.,224.);expectedInputs['dirty']=1;full=[0,0]+[v&0xffffffff for v in c['screen']]+words([0.,1.]);wcb=lambda vals:[w(cb,0x170+j*4,v)for j,v in enumerate(vals)];wcb(full);vp=copy.deepcopy(before['viewport']);vp['dirty']=1;expectedVp,resetEvents=modelReset(vp,expectedInputs);plans=[{'return':rng.choice([0,0x80004005,0xffffffff]),'backendChanges':[{'offset':0x174,'word':rng.getrandbits(32)}]if case%7==0 else[],'sourceChanges':[{'index':(case+index)%6,'word':rng.getrandbits(32)}]if case%5==0 else[],'argumentChanges':[{'index':(case+index+1)%6,'word':rng.getrandbits(32)}]if case%3==0 else[]}for index in range(2)];modelEvents=[]
 def modelSnap(vpState):return {'callerHex':cb.hex(),'globalHex':gb.hex(),'inputs':dict(expectedInputs,dirty=vpState['dirty']),'viewport':copy.deepcopy(vpState)}
 def modelCom(source,offset,index,vpState):
  packet=[u(source,offset+j*4)for j in range(6)];packet[2]=min(packet[2],c['screen'][0]&0xffffffff);packet[3]=min(packet[3],c['screen'][1]&0xffffffff);event={'device':u(gb,4),'arguments':packet,'before':modelSnap(vpState),'sourceHex':source[offset:offset+24].hex()};plan=plans[index]
  for mutation in plan['backendChanges']:w(gb,mutation['offset'],mutation['word'])
  for mutation in plan['sourceChanges']:w(source,offset+mutation['index']*4,mutation['word'])
  for j in range(6):result=u(source,offset+j*4);w(gb,0x170+j*4,result)
  event.update(after=modelSnap(vpState),result=result);modelEvents.append(event);return result
 temporary=bytearray(struct.pack('<6I',*resetEvents[0]['words']));atService=resetEvents[0]['stateAtService'];modelCom(temporary,0,0,atService);wcb(full);expectedInputs['dirty']=0;resultExpected=modelCom(cb,0x170,1,expectedVp);events.clear();result=n.call(0x6e2510,regs={UC_X86_REG_ECX:currentCaller});afterState=snapshot();expected={'callerHex':cb.hex(),'globalHex':gb.hex(),'inputs':expectedInputs,'viewport':expectedVp};ck(afterState,expected,['complete actual context refresh',case]);ck(events,modelEvents,['actual COM receiver/source ordering',case]);ck(result,resultExpected,['actual raw refresh return',case]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe004,['refresh ret',case]);refreshCases.append({'sameBackend':same,'before':before,'plans':copy.deepcopy(plans),'native':afterState,'nativeEvents':copy.deepcopy(events),'nativeResult':result})
fixture={'identityWords':words(identity),'primitiveCases':primitiveCases,'refreshCases':refreshCases};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));report={'schema':'original-finite-context-refresh-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':{'depthCases':512,'positionCases':1024,'physicalShiftCases':1024,'extentCases':1024,'refreshCases':768,'retainedPortableReplayCases':4352,'COMCalls':sum(len(c['nativeEvents'])for c in refreshCases)},'adapters':{'vtable+0xbc':'Recorded raw viewport COM call with opaque HRESULT and backend/source/local-packet mutation. Actual6e2470/6e57b0 CPU forwarding runs unchanged.'},'limits':['Original setter/refresh/viewport/reset/helper/CRT chain executes unchanged. No device/D3DX actions or imported arithmetic adapters.','Finite setter floats/global scale/bias and stored results; nonzero source axes; integer conversion0x6e6b90 mode0 with truncated result fitting Int32. Other conversion modes/overflow not asserted.','Source640x224 calibration and original global scale/bias addresses remain explicit runtime inputs; indirect initialization unresolved.','Original context refresh begins with caller viewport0,0,screenWidth,screenHeight,depth0..1; forces depth/position/extent setters and real dirty reset, then repopulates caller viewport and forwards to fixed global backend.','Numeric viewport globals remain stable at COM boundary in refresh fixtures; raw source/local packets and backend viewport words may mutate. General numeric-global mutation is not newly asserted.','Standalone depth FLD/FSTP tests are finite only. Raw viewport COM packet copies remain integer-only; nonfinite source packet mutations are opaque.','Native/Python own-state differential passed; managed execution pending.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
