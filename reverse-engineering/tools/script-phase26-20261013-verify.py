"""Original byte/refill, line/token reader and52b3f0 conditionproducer; only4fb550 fileI/O and game callback supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase25-20261013-verify.py').read_text().split('\nfor op,rhs')[0])
def module(name,file):
 spec=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod);return mod
lines=module('condition_lines','native-text-lines-verify.py');tokens=module('condition_tokens','native-text-tokens-verify.py');n=nm.NativeX86();REFILL=D+0xe000;RAWLINE=D+0x7000;TOKEN=TEXT;SINGLES=D+0x5800;HANDLE=0x12345678
lines.PARSER=PARSER;lines.BUFFER=REFILL;lines.LINE=RAWLINE;lines.HANDLE=HANDLE;tokens.PARSER=PARSER;tokens.LINE=RAWLINE;tokens.TOKEN=TOKEN
segments.append((0x88ab4c,4));stream={};parameters={}
class Image:
 def read(self,p,size):return bytes(rb(p+i)for i in range(size))
 def write(self,p,b):
  for i,v in enumerate(b):wb(p+i,v)
 def get(self,p):return rd(p)
 def put(self,p,v):wd(p,v)
 def text(self,p,value):self.write(p,value.encode('latin1')+b'\0')
def nextline(model):return lines.line(Image(),parameters,stream)
def token(model):tokens.next_token(Image())
def hook26(mu,address,size,data):
 if address==0x4fb550:
  sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<3I',sp+4));handle,buffer,requested=args;assert handle==HANDLE and buffer==REFILL;data=config['file'].encode('latin1');position=stream['position'];count=min(requested,config.get('chunk',4096),max(0,len(data)-position));count=0 if position>=config.get('failAfter',0x7fffffff)else count;n.write(buffer,data[position:position+count]);stream['events'].append(dict(args=args,position=position,count=count));stream['position']+=count;ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,count);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address in [CB,0x512850,0x512860,0x512870,0x4ef790]:hook25(mu,address,size,data)
n.mu.hook_add(UC_HOOK_CODE,hook26)
def setup26(c):
 setup25(c);n.write(PARSER,bytes(0x584));n.pack('<I',PARSER,REFILL);n.pack('<I',PARSER+4,HANDLE);n.pack('<4I',PARSER+0x50c,RAWLINE,TOKEN,4096,512);n.pack('<I',PARSER+0x51c,0xffffffff);n.pack('<I',PARSER+0x52c,0xffffffff);n.pack('<I',PARSER+0x570,0xffffffff);n.pack('<I',PARSER+0x574,len(c['file'].encode('latin1')));n.write(SINGLES,b'{}\0');n.pack('<I',PARSER+0x580,SINGLES);n.pack('<I',0x88ab4c,0x12345678)
def fresh_stream():return dict(position=0,events=[],binaryCalls=0)
def execute26(c):
 global config,shadow,events,ordinal,symbolOrdinal,lineIndex,tokenIndex,checks,stream,parameters
 config=c;setup26(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0;symbolOrdinal=0;lineIndex=-1;tokenIndex=0;stream=fresh_stream();parameters=dict(text=c['file'],chunk=c.get('chunk',4096),failAfter=c.get('failAfter',0x7fffffff),capacity=4096,binary=0);modelFault=False
 try:materialize()
 except(ValueError,KeyError):modelFault=True
 modelFinal=snapshot(True);modelEvents=events.copy();modelStream=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0);events=[];ordinal=0;symbolOrdinal=0;stream=fresh_stream();nativeFault=False
 try:n.call(0x52b3f0,[PARSER],count=8000000)
 except RuntimeError:nativeFault=True
 nativeFinal=snapshot();nativeEvents=events.copy();nativeStream=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0)
 for group,a,b in [('fault',nativeFault,modelFault),('images',nativeFinal,modelFinal),('services',nativeEvents,modelEvents),('stream',nativeStream,modelStream)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,initial=initial,fault=nativeFault,final=nativeFinal,nativeEvents=nativeEvents,nativeStream=nativeStream))
files=['','{\nIF AlwaysTrue = 1 and\n}\n',';comment only\n\nIF Timer <= param3 goto Base KeepBlockedMessages ;tail\r\n}\r\n','IF LocatorRange "extra argument" >= "symbol+2" and\nIF AlwaysTrue != 0 goto "Target State" KeepBlockedMessages\n}','IF AlwaysTrue = "symbol + beta" and\nIF AlwaysTrue = "true" and\n}','IF AlwaysTrue = 1 and\rIF AlwaysTrue = 2 and\r','IF AlwaysTrue = "" and\n}','OnMacro testMacro goto Base KeepBlockedMessages\n}\n','IF Unknown = 1 and\nbad\nIF AlwaysTrue = 2 and\n}','\t \n ;comment\nIF AlwaysTrue = "semi;colon" and\n}','\n'.join('IF '+r['name']+' = 1 and'for r in builtin)+'\n}','\n'.join(['IF AlwaysTrue = symbol and']*257)+'\n}']
for file,chunk,callback,handled in itertools.product(files,[1,17,4096],[False,True],[0,1]):execute26(dict(file=file,lines=[],chunk=chunk,callback=callback,handled=handled,macro=True))
for failAfter in [0,7,31]:execute26(dict(file='IF AlwaysTrue = 1 and\nIF Timer = 2 and\n}',lines=[],chunk=7,failAfter=failAfter))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),actualBodies=['0x52b3f0','0x4fc5b0','0x4fc2d0','0x4f7fb0','0x513990','0x512ea0','0x513100','0x5132f0','0x5132a0','0x4f8420'],remainingPorts=['4fb550 filebytes','9238c0 gamesymbol'],managedExecution=False)
(nm.BASE/'reports/script-phase26-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase26-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
