"""Original4f0230 customEDI buffer allocator and4ff3b0/4ff430 Win32 wrappers; only final ReadFile/SetFilePointerEx callbacks supplied."""
import importlib.util,json,struct,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86();D=n.DATA;STREAM=D+0x1000;OLD=D+0x2000;OUT=D+0x3000;POOL=0x915fb0;COUNTER=0x91ee8c;HANDLES=0x8007a0;READAPI=n.STOP+0x700;SEEKAPI=n.STOP+0x800
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_EDI
segments=[(STREAM,0x2000),(OUT,0x1000),(POOL,0x1020),(COUNTER,4),(HANDLES-16,0x80),(0x7510e4,12)];shadow={};config={};events=[];checks=0;errors=[];cases=[]
def rb(p):return shadow[p]
def wb(p,v):
 if p not in shadow:raise KeyError(p)
 shadow[p]=v&255
def rd(p):return sum(rb((p+i)&0xffffffff)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):wb((p+i)&0xffffffff,v>>(8*i))
def signed(v):return v-0x100000000 if v&0x80000000 else v
def snap(model=False):return[dict(address=p,bytes=bytes(rb(p+i)for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def patches76(name,model):
 for p,size,v in config.get('patches',{}).get(name,[]):
  if model:
   for i in range(size):wb(p+i,v>>(8*i))
  else:n.write(p,int(v).to_bytes(size,'little'))
def api76(name,args,model):
 events.append(dict(name=name,args=args.copy()));patches76(name,model)
 if name=='ReadFile':
  count=min(args[2],config.get('payload',5),1024);data=bytes((i*31+7)&255 for i in range(count))
  if model:
   for i,b in enumerate(data):wb(args[1]+i,b)
  else:n.write(args[1],data)
  return config.get('readSuccess',1),config.get('readNumber',5)if config.get('readWrites',True)else 0
 return config.get('seekSuccess',1),config.get('seekPosition',[0x87654321,0x12345678])if config.get('seekWrites',True)else[0,0]
def read76(index,destination,count):
 handle=rd((HANDLES+(index<<2))&0xffffffff);success,number=api76('ReadFile',[handle,destination,count,0],True);return number
def seek76(index,low,high,origin):
 mode=0 if origin==0 else 1 if origin==1 else 2;handle=rd((HANDLES+(index<<2))&0xffffffff);success,value=api76('SetFilePointerEx',[handle,low,high,mode],True);return value if success else[0xffffffff,0xffffffff]
def acquire76(stream):
 counter=rd(COUNTER);minimum=counter;index=0
 for i in range(4):
  stamp=rd(POOL+i*0x408+4)
  if signed(stamp)<signed(minimum):minimum=stamp;index=i
 selected=POOL+index*0x408;old=rd(selected)
 if old:wd(old+0x38,0)
 wd(selected+4,counter);wd(selected,stream);cached=rd(stream+0x28);wd(COUNTER,(counter+1)&0xffffffff);wd(stream+0x38,selected)
 if not cached:return 0
 negative=(-cached)&0xffffffff;seek76(rd(stream),negative,0xffffffff if negative&0x80000000 else 0,1);return read76(rd(stream),selected+8,rd(stream+0x28))
def hook76(mu,address,size,data):
 if address not in[READAPI,SEEKAPI]:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<5I',sp+4));name='ReadFile'if address==READAPI else'SetFilePointerEx';normalized=[args[0],args[1],args[2],args[4]];success,value=api76(name,normalized,False)
 if name=='ReadFile':
  if config.get('readWrites',True):n.pack('<I',args[3],value)
 else:
  if config.get('seekWrites',True):n.pack('<2I',args[3],*value)
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,success);mu.reg_write(UC_X86_REG_ESP,sp+24);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook76)
def execute76(c):
 global shadow,config,events,checks
 config=c
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 n.pack('<I',0x7510e4,READAPI);n.pack('<I',0x7510ec,SEEKAPI);n.pack('<I',COUNTER,c.get('counter',5));n.pack('<I',STREAM,c.get('streamIndex',0));n.pack('<I',STREAM+0x28,c.get('cached',0));n.pack('<I',STREAM+0x38,0)
 for i in[-1]+list(range(16)):n.pack('<I',HANDLES+i*4,(0xf00d0000+i)&0xffffffff)
 for i in range(4):
  owner=0 if c.get('owner')=='null'else STREAM if c.get('owner')=='same'else 0xdeadbeef if c.get('owner')=='invalid'else OLD+i*0x80;n.pack('<II',POOL+i*0x408,owner,c.get('stamps',[1,2,3,4])[i]);n.pack('<I',OLD+i*0x80+0x38,POOL+i*0x408)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];method=c['method'];modelFault=False;wanted=[]
 if method=='Read':inputs=dict(index=c['index'],destination=OUT,count=c['count']);address=0x4ff3b0
 elif method=='Seek':inputs=dict(index=c['index'],low=c['low'],high=c['high'],origin=c['origin']);address=0x4ff430
 else:inputs=dict(stream=c.get('stream',STREAM));address=0x4f0230
 try:wanted=[read76(**inputs)]if method=='Read'else seek76(**inputs)if method=='Seek'else[acquire76(**inputs)]
 except KeyError:modelFault=True
 model=snap(True);me=events.copy();events=[];nativeFault=False;actual=[]
 try:
  value=n.call(address,[]if method=='Acquire'else list(inputs.values()),regs={UC_X86_REG_EDI:inputs['stream']}if method=='Acquire'else{});actual=[value,n.mu.reg_read(UC_X86_REG_EDX)]if method=='Seek'else[value]
 except RuntimeError:nativeFault=True
 final=snap();ne=events.copy()
 for group,a,b in [('fault',nativeFault,modelFault),('return',[]if nativeFault else actual,[]if modelFault else wanted),('images',final,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,fault=nativeFault,returnValue=[]if nativeFault else actual,final=final,nativeEvents=ne))
for index,count,success,writes,number in itertools.product([0,7,15,0xffffffff],[0,1,17,1024,0xffffffff],[0,1,2],[False,True],[0,7,0x80000000,0xffffffff]):execute76(dict(method='Read',index=index,count=count,readSuccess=success,readWrites=writes,readNumber=number))
for index,low,high,origin,success,writes in itertools.product([0,7,0xffffffff],[0,1,0xffffffff],[0,0x80000000],[0,1,2,0xffffffff],[0,1,2],[False,True]):execute76(dict(method='Seek',index=index,low=low,high=high,origin=origin,seekSuccess=success,seekWrites=writes))
stampSets=[[0,0,0,0],[1,2,3,4],[7,6,5,4],[0xffffffff,0,0x7fffffff,0x80000000],[0,0,0,0xffffffff]]
for counter,stamps,owner,cached in itertools.product([0,5,0x80000000,0x7fffffff,0xffffffff],stampSets,['null','old','same'],[0,1,17,1024,0xffffffff,0x80000000]):execute76(dict(method='Acquire',counter=counter,stamps=stamps,owner=owner,cached=cached))
for patches in[{'SetFilePointerEx':[[STREAM+0x28,4,0],[STREAM,4,7]]},{'SetFilePointerEx':[[STREAM+0x28,4,17],[STREAM+0x38,4,POOL+0x408],[HANDLES+7*4,4,0x12345678],[STREAM,4,7]]},{'ReadFile':[[COUNTER,4,0],[STREAM+0x38,4,0]]}]:execute76(dict(method='Acquire',cached=5,patches=patches))
for c in[dict(method='Acquire',stream=0),dict(method='Acquire',stream=0xdeadbeef),dict(method='Acquire',owner='invalid')]:execute76(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=3,ports=['ReadFileIAT7510e4','SetFilePointerExIAT7510ec'],closure='Original4f0230 signedstamp selection/owner eviction→4ff430/4ff3b0→finalWin32 callbacks only; wrappers execute originalbytes')
(nm.BASE/'reports/script-phase76-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase76-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
