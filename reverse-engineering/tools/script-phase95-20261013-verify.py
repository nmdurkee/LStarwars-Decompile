"""Whole filesystem parser open/BOM attach/close through real existence/game-open/read/seek/size/close, final platform+format ports only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase77-20261013-verify.py').read_text().split('\nfor handle,wanted')[0])
exec(Path(__file__).with_name('script-phase94-20261013-verify.py').read_text().split('\nfor type,mode')[0])
#Reuse exact parser own-body projection, replacing its former child ports with recovered compositions.
p45=Path(__file__).with_name('script-phase45-20261013-verify.py').read_text();exec(p45[p45.index('def zero45'):p45.index('def port45')]);exec(p45[p45.index('def attach45'):p45.index('def hook45')]);selected45=0
BOMTEMP=D+0x11000;POOL=0x915fb0;COUNTER=0x91ee8c;HANDLES=0x8007a0;PARSER=0x917850;BUFFER=0x8cab50;PGLOBAL=0x91eebc;OPTIONS=0x91ee88;READ=n.STOP+0x600;CLOSE=n.STOP+0x700;n.pack('<I',0x7510e4,READ);n.pack('<I',0x7510e0,CLOSE);segments +=[(POOL,0x1020),(COUNTER,4),(PARSER,0x1610),(BUFFER,0x4000),(PGLOBAL,8),(OPTIONS,4)];cases=[];checks=0;errors=[];backend=0;closeCount=0;fileBytes=b''
def port94(name,args,model):
 global backend,closeCount
 events.append(dict(name=name,args=args));write=wd if model else lambda p,v:n.pack('<I',p,v)
 for p,v in config.get('patches',{}).get(name,[]):write(p,v)
 if name=='CreateFile':backend=0;return 0x12345678
 if name=='CloseHandle':closeCount+=1;return 1
 return 0

def seekValue94(args,model):
 global seekOrdinal,backend
 port94('SetPointer',args,model);seekOrdinal+=1;offset=args[1]|(args[2]<<32);origin=args[3];backend=(offset if origin==0 else backend+offset if origin==1 else len(fileBytes)+offset)&((1<<64)-1);return[backend&0xffffffff,backend>>32]
def api76(name,args,model):
 global backend
 if name=='SetFilePointerEx':return 1,seekValue94(args,model)
 handle,destination,count,overlapped=args;normalized='private'if model and destination==BOMTEMP or not model and n.STACK<=destination<n.STACK+0x10000 else destination;port94('ReadFile',[handle,normalized,count,overlapped],model);chosen=min(count,max(0,len(fileBytes)-backend));payload=fileBytes[backend:backend+chosen]
 if model:
  for i,b in enumerate(payload):wb(destination+i,b)
 else:n.write(destination,payload)
 backend+=chosen;return 1,chosen

def hook95(mu,address,size,data):
 if address not in[READ,CLOSE]:return
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if address==READ:handle,destination,count,out,overlapped=n.unpack('<5I',sp+4);value,number=api76('ReadFile',[handle,destination,count,overlapped],False);n.pack('<I',out,number);clean=24
 else:value=port94('CloseHandle',[n.unpack('<I',sp+4)[0]],False);clean=8
 mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+clean);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook95)
def publicSeek95(handle,low,high,origin):
 index=handle-1;stream=0x8ceb50+index*64
 if rd(stream+44):
  offset=low|(high<<32);value=(q(stream+8)+offset if origin==1 else q(stream+24)-offset if origin==2 else offset)&((1<<64)-1);wq(stream+8,value);return value
 lo,hi=seek76(index,low,high,origin);return lo|(hi<<32)
def publicClose95(handle):
 index=handle-1;port94('CloseHandle',[rd(0x8007a0+index*4)],True);wd(0x8007a0+index*4,0xffffffff);stream=0x8ceb50+index*64;buffer=rd(stream+56)
 if buffer:wd(buffer,0)
 zero45(stream,64)
def exists95(path):
 if not path or not rb(path):return 0
 saved=rd(BUFFERFLAG);wd(BUFFERFLAG,0);assert rd(OPTIONS)==0;handle=gameOpen94(path,0,0,1)
 if handle:publicClose95(handle)
 wd(BUFFERFLAG,saved);return 1 if handle else 0
def port45(name,args,model):
 assert model
 if name=='Prefix':wb(BOMTEMP,0);wb(BOMTEMP+1,0);reader77(args[0],BOMTEMP,2);return rb(BOMTEMP)|(rb(BOMTEMP+1)<<8)
 if name=='Byte':wb(BOMTEMP,0);value=reader77(args[0],BOMTEMP,1);return(value&0xffffff00)|rb(BOMTEMP)
 if name=='Seek':return publicSeek95(*args)
 if name=='Size':return rd((0x8ceb28+(args[0]<<6))&0xffffffff)
 if name=='Exists':return exists95(args[0])
 if name=='Open':return gameOpen94(*args)
 if name=='Close':publicClose95(args[0]);return 0
 raise ValueError(name)
#The earlier gameOpen projection retains its no-argument seeking helper; keep its raw seek model in sync.
def rawSeek94(index,origin):return publicSeek95(index+1,0,0,origin)
#Reuse only setup statements of game-open fixtures, without executing their oracle runner.
p94=Path(__file__).with_name('script-phase94-20261013-verify.py').read_text();setup94=p94[p94.index(' config=c\n',p94.index('def execute94')):p94.index('initial=snap();',p94.index('def execute94'))];setup94='\n'.join(line[1:]if line.startswith(' ')else line for line in setup94.splitlines())
def execute95(c):
 global config,shadow,events,checks,backend,closeCount,fileBytes,seekOrdinal,pollCalls,selected45
 config=c;fileBytes=bytes.fromhex(c['data']);exec(setup94,globals(),dict(c=c));n.pack('<I',PGLOBAL,0 if c.get('cold')else PARSER);n.pack('<I',PGLOBAL+4,BUFFER);n.pack('<I',OPTIONS,0);n.pack('<I',COUNTER,5)
 for i in range(4):n.pack('<II',POOL+i*0x408,0,i+1);n.pack('<I',PARSER+i*0x584,0 if i in c.get('freeParsers',[0])else BUFFER+i*0x1000)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 for i in range(256):shadow[FILENAME+i]=0;shadow[LOCAL+i]=0
 shadow[BOMTEMP]=0;shadow[BOMTEMP+1]=0;events=[];backend=0;closeCount=0;seekOrdinal=0;pollCalls=0;selected45=0;want=openfile45(PATH)
 if c.get('close')and want:close45(want)
 model=snap(True);me=events.copy();mb=backend;mc=closeCount;ms=seekOrdinal;events=[];backend=0;closeCount=0;seekOrdinal=0;pollCalls=0;selected45=0;actual=n.call(0x4fc860,[PATH],count=12000000)
 if c.get('close')and actual:n.call(0x4fa300,[actual],count=12000000)
 final=snap();ne=events.copy();nb=backend;nc=closeCount;ns=seekOrdinal
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me),('hostState',[nb,nc,ns],[mb,mc,ms])]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[x for x,y in zip(a,b)if x!=y][:1],model=b if group!='images'else[y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(context=c,inputs=dict(path=PATH),initial=initial,returnValue=actual,final=final,nativeEvents=ne,hostState=dict(position=nb,closeCount=nc,seekOrdinal=ns)))
for data,buffered,close,freeParsers in itertools.product(['','ef','efbb','efbbbf4162','bbefbf4162','feff0041','fffe4100','416263'],[0,1,7],[False,True],[[0],[]]):execute95(dict(data=data,buffered=buffered,close=close,freeParsers=freeParsers,type=0,mode=0,free=0))
for data,cold,close,free in itertools.product(['efbbbf4162','416263'],[False,True],[False,True],[16,17]):execute95(dict(data=data,buffered=7,close=close,freeParsers=[3],cold=cold,type=0,mode=0,free=free))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=0,ports=['providerFormat','CreateFile','SetFilePointerEx','ReadFile','CloseHandle'],closure='Original4fc860→4ff120/4fa610→real4fa3f0/4f99e0, then real4fa3f0/4fc750/pool/prefix+byte/read/cache/memorycopy/seek/size/strncpy and optional4fa300→realclose; only finalplatform+format ports')
(nm.BASE/'reports/script-phase95-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase95-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
