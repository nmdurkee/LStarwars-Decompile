"""Actual existence thunk/body through recovered close, with container search/open leaves explicit."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase87-20261013-verify.py').read_text().split('\nfor method,index')[0])
PATH=DATA;CON=D+0xf000;ROWS=D+0xf100;GLOBAL=0x91ee88;segments +=[(PATH,16),(CON,32),(ROWS,128),(GLOBAL,12)];cases=[];checks=0;errors=[]
def existsPort88(name,args,model):
 events.append(dict(name=name,args=args));write=wd if model else lambda p,v:n.pack('<I',p,v)
 for p,v in config.get('patches',{}).get(name,[]):write(p,v)
 return config['index']if name=='Find'else config['openHandle']
def exists88(path):
 if not path or not rb(path):return 0
 saved=rd(GLOBAL+8);container=rd(GLOBAL);wd(GLOBAL+8,0)
 if container:
  index=existsPort88('Find',[container,path],True)
  if signed(index)>=0:wd(GLOBAL+8,saved);return rd((rd(container+8)+(index<<4)+8)&0xffffffff)
 handle=existsPort88('Open',[path,0,container,1],True)
 if handle:publicClose87(handle)
 wd(GLOBAL+8,saved);return 1 if handle else 0
n=nm.NativeX86();n.pack('<I',0x7510e0,API);n.mu.hook_add(UC_HOOK_CODE,hook87)
def hook88(mu,address,size,data):
 if address not in[0x4f9aa0,0x4fa3f0]:return
 sp=mu.reg_read(UC_X86_REG_ESP);name='Find'if address==0x4f9aa0 else'Open';args=list(n.unpack('<2I'if name=='Find'else'<4I',sp+4));value=existsPort88(name,args,False);mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook88)
def execute88(c):
 global shadow,checks,config,events
 config=c
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 n.write(PATH,b'file.dat\0'+bytes(7));n.pack('<I',CON+8,ROWS);n.pack('<3I',GLOBAL,CON if c['container']else 0,0xabcdef01,c['saved']);n.pack('<I',TABLE+16,7)
 for i in range(8):n.pack('<I',ROWS+i*16+8,c['metadata'])
 handle=c['openHandle']
 if handle and handle<0x400:n.pack('<I',0x8007a0+(handle-1)*4,0x12345678);n.pack('<I',0x8ceb50+(handle-1)*64+56,POOL)
 elif 0x800<=handle<0x1000:record=COMP+(handle-0x800)*48;n.pack('<I',record,CONTAINER);n.pack('<II',record+32,1,7)
 path=0 if c.get('null')else PATH
 if c.get('empty'):n.write(PATH,b'\0')
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];want=exists88(path);model=snap(True);me=events.copy();events=[];actual=n.call(0x4ff120 if c['thunk']else 0x4fa610,[path]);final=snap();ne=events.copy()
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(path=path),initial=initial,returnValue=actual,final=final,nativeEvents=ne))
for thunk,container,index,handle,saved,metadata in itertools.product([False,True],[False,True],[0,3,0xffffffff],[0,1,0x400,0x800,0x1000],[0,0xffffffff],[0,17]):execute88(dict(thunk=thunk,container=container,index=index,openHandle=handle,saved=saved,metadata=metadata,apiResult=0))
for empty,null in[(True,False),(False,True)]:execute88(dict(thunk=True,container=True,index=0,openHandle=1,saved=0x12345678,metadata=17,empty=empty,null=null,apiResult=0))
execute88(dict(thunk=True,container=True,index=0,openHandle=0,saved=0x12345678,metadata=17,apiResult=0,patches={'Find':[[GLOBAL+8,7],[CON+8,ROWS+16]]}))
execute88(dict(thunk=False,container=False,index=0xffffffff,openHandle=0x400,saved=0x12345678,metadata=17,apiResult=0,patches={'Open':[[GLOBAL+8,7],[GLOBAL,0]]}))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=2,ports=['containerIndex4f9aa0','gameOpen4fa3f0','CloseHandleIAT7510e0','CRTclose6dee70'],closure='Whole4ff120→4fa610, actual4f99e0 close and memory/compressed/stream children; container search/open and final OS/CRT close explicit')
(nm.BASE/'reports/script-phase88-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase88-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
