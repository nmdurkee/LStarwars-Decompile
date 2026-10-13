"""Original target binding caller and concrete screen/origin writes."""
import importlib.util,struct,json,gzip,random,copy
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase10-20261013-bindings'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
CTX=n.DATA;SURFACE=CTX+0x1000;checks=0;errors=[];events=[];plan={};present=False;rng=random.Random(0x6e3720);cases=[]
edgeInts=[0,1,-1,3,-3,2147483647,-2147483648]
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<30:errors.append({'label':label,'native':a,'expected':e})
def read():return {'contextWidth':n.unpack('<i',CTX+0x138)[0],'contextHeight':n.unpack('<i',CTX+0x13c)[0],'flag':n.unpack('<I',CTX+0x638)[0],'primary':n.unpack('<I',CTX+0x6b0)[0],'secondary':n.unpack('<I',CTX+0x6c4)[0],'active':n.unpack('<I',CTX+0x6e8)[0],'surfaceHandle':n.unpack('<I',SURFACE+8)[0],'surfaceWidth':n.unpack('<H',SURFACE+0x14)[0],'surfaceHeight':n.unpack('<H',SURFACE+0x16)[0],'screen':list(n.unpack('<2i',0x973900)),'origin':list(n.unpack('<2i',0x80202c))}
def change(changes):
 for key,a,fmt in[('contextWidth',CTX+0x138,'i'),('contextHeight',CTX+0x13c,'i'),('flag',CTX+0x638,'I'),('primary',CTX+0x6b0,'I'),('secondary',CTX+0x6c4,'I'),('active',CTX+0x6e8,'I'),('surfaceHandle',SURFACE+8,'I'),('surfaceWidth',SURFACE+0x14,'H'),('surfaceHeight',SURFACE+0x16,'H')]:
  if key in changes:n.pack('<'+fmt,a,changes[key])
 for key,a in[('screen',0x973900),('origin',0x80202c)]:
  if key in changes:n.pack('<2i',a,*changes[key])
def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];edge={0x6e2880:'bind',0x6e5340:'state',0x6e2510:'refresh'}[address];item={'edge':edge,'before':read(),'this':mu.reg_read(UC_X86_REG_ECX)}
 if edge=='bind':item['args']=list(n.unpack('<2I',sp+4));cleanup=12
 elif edge=='state':item['args']=list(n.unpack('<2I',sp+4));cleanup=4
 else:item['args']=[];cleanup=4
 events.append(item);change(plan[edge]['changes']);mu.reg_write(UC_X86_REG_EAX,plan[edge]['return']);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+cleanup);mu.reg_write(UC_X86_REG_EIP,ret)
for address in(0x6e2880,0x6e5340,0x6e2510):n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def model(before,present,slot,plan):
 state=copy.deepcopy(before);expected=[]
 def service(edge,args):
  expected.append({'edge':edge,'args':args,'before':copy.deepcopy(state)});state.update(copy.deepcopy(plan[edge]['changes']));return plan[edge]['return']
 def resize(width,height):
  state['screen']=[width,height];state['origin']=[int(width/2),int(height/2)];return service('refresh',[])
 if present and state['surfaceHandle']:
  result=service('bind',[slot,state['surfaceHandle']])
  if slot==0:result=resize(state['surfaceWidth'],state['surfaceHeight'])
 elif slot==0:
  if state['flag']:
   service('bind',[0,state['primary']]);service('state',[0xa8,0]);state['active']=state['primary']
  else:service('bind',[0,state['secondary']]);state['active']=state['secondary']
  result=resize(state['contextWidth'],state['contextHeight'])
 else:result=service('bind',[slot,0])
 return state,expected,result
for i in range(2048):
 present=i%3!=0;slot=[0,0,1,0xffffffff,2][i%5];before={'contextWidth':rng.choice(edgeInts) if i<512 else rng.randint(-2147483648,2147483647),'contextHeight':rng.choice(edgeInts) if i<512 else rng.randint(-2147483648,2147483647),'flag':[0,1,0xffffffff][i//3%3],'primary':rng.getrandbits(32),'secondary':rng.getrandbits(32),'active':rng.getrandbits(32),'surfaceHandle':rng.getrandbits(32) if i%4 else 0,'surfaceWidth':rng.randrange(65536),'surfaceHeight':rng.randrange(65536),'screen':[rng.randint(-2147483648,2147483647)for _ in range(2)],'origin':[rng.randint(-2147483648,2147483647)for _ in range(2)]};n.write(CTX,bytes(0x700));n.write(SURFACE,bytes(0x20));change(before);plan={}
 for edge in('bind','state','refresh'):
  changes={}
  if i%4 in(1,2):
   if edge!='refresh':changes={'contextWidth':rng.choice(edgeInts) if i<512 else rng.randint(-2147483648,2147483647),'contextHeight':rng.choice(edgeInts) if i<512 else rng.randint(-2147483648,2147483647),'flag':rng.getrandbits(32),'primary':rng.getrandbits(32),'secondary':rng.getrandbits(32),'surfaceHandle':rng.getrandbits(32),'surfaceWidth':rng.randrange(65536),'surfaceHeight':rng.randrange(65536)}
   else:changes={'screen':[rng.randint(-2147483648,2147483647)for _ in range(2)],'origin':[rng.randint(-2147483648,2147483647)for _ in range(2)],'active':rng.getrandbits(32)}
  plan[edge]={'changes':changes,'return':rng.getrandbits(32)}
 expected,expectedEvents,expectedReturn=model(before,present,slot,plan);events.clear();result=n.call(0x6e3720,[SURFACE if present else 0,slot],regs={UC_X86_REG_ECX:CTX});ck(read(),expected,'binding complete owned state '+str(i));ck([{k:v for k,v in event.items()if k!='this'}for event in events],expectedEvents,'ordered service and receiver state '+str(i));ck(result,expectedReturn,'binding opaque return '+str(i));ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe00c,'thiscall ret8 '+str(i));ck(all(e['this']==CTX for e in events if e['edge']in('bind','refresh')),True,'explicit this reset '+str(i));cases.append({'before':before,'present':present,'slot':slot,'plan':plan,'native':read(),'nativeEvents':events[:],'nativeResult':result})
fixture={'cases':cases};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));report={'schema':'original-render-target-dimension-binding-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':{'bindingCases':2048,'retainedPortableReplayCases':2048,'serviceEvents':sum(len(c['nativeEvents'])for c in cases)},'adapters':{'0x6e2880':'Explicit target bind(slot,opaque handle), stdcall two args; modeled return and allowed caller-state mutation.','0x6e5340':'Explicit render state(index168,value0), cdecl two args; modeled return/mutation.','0x6e2510':'Explicit context refresh(this), opaque return and caller-state mutation; actual internal device viewport implementation unported.'},'limits':['Original complete6e3720 caller executes unchanged with concrete source field layouts and real screen/origin globals. Host calls are explicit services, not reconstructed device behavior.','Valid separate backend/surface records; surface width/height are unsigned16. Backend width/height all Int32 with signed truncating half.','Any nonzero slot retains original dimension/active writes gate, including0xffffffff. Surface-null or handle-zero fallbacks retained.','Callbacks may change fields before later reads; branch decisions and argument values retain original evaluation order. Register volatile clobbers and ret8 verified.','Literal source/origin/light references and original PE defaults provide binding evidence only; no exhaustive indirect writer or authored frame provenance claim.','Native/Python caller own-state differential passed; managed execution pending.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
