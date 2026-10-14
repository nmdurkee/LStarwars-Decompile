"""Actual UTF16 filesystem body/catalog semantics; preserve original byte command/name consumers."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase99-20261013-verify.py').read_text().split('\ntable=json.loads')[0])
s100=Path(__file__).with_name('script-phase100-20261013-verify.py').read_text();exec(s100[s100.index('def byte100'):s100.index('def execute100')]);s48=Path(__file__).with_name('script-phase48-20261013-verify.py').read_text();exec(s48[s48.index('def rw'):s48.index('def execute48')]);s49=Path(__file__).with_name('script-phase49-20261013-verify.py').read_text();exec(s49[s49.index('def next49'):s49.index('def hook49')]);segments=list(dict.fromkeys(segments+[(0x88ab4c,4)]));cases=[];checks=0;errors=[]
oldline101=nextline;oldcount101=next_count

def nextline(model):return next49()if rb(PARSER+0x578)else oldline101(model)
def next_count():
 global P48
 P48=PARSER;return next48()if rb(PARSER+0x578)else oldcount101()
def token(model):next_count()
def dispatch31():
 p=rd(PARSER+0x510)
 if rb(PARSER+0x578):
  name='';i=0
  while rw(p+i*2):
   c=rw(p+i*2);name+=chr(c if c<256 else{0x2019:0x92,0x2013:0x96,0x2018:0x91,0x2026:0x85,0x2122:0x99}.get(c,63));i+=1
 else:name=text(p)
 if not name or name[0]==';':return
 depth=signed(rd(PARSER+0x570))
 if depth>=0:
  for table in[rd(PARSER+0x530+depth*4),rd(PARSER+0x550+depth*4)]:
   if not table:continue
   at=table
   while rd(at):
    if fold(text(rd(at)))==fold(name):command31(rd(at+4),True);return
    at+=8
 fallback=rd(0x91eec4)
 if fallback:command31(fallback,True)

def setup101(c):
 setup99(c);n.write(ROOTNAME,b'root.scp\0');n.pack('<I',0x91eec4,0)
def execute101(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,selected45,PARSER
 config=c;setup101(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 for p,z in[(FILENAME,256),(BOMTEMP,2),(LOCAL,256),(LOCAL97,512)]:
  for i in range(z):shadow[p+i]=0
 if c['method']=='Body':wanted=finalize40(0,FOLDER46,ROOTNAME,TOP,BOTTOM)
 else:load46(0,FOLDER46,TOP,BOTTOM,SYS69);wanted=rd(SYS69+28)
 model=snapshot(True);me=events.copy();mh={k:dict(v)for k,v in hostFiles.items()};events=[];symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 if c['method']=='Body':actual=n.call(0x52c320,[ROOTNAME,TOP,BOTTOM],regs={UC_X86_REG_EAX:FOLDER46,UC_X86_REG_ECX:0},count=24000000)
 else:n.call(0x52c470,[0,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);actual=n.unpack('<I',SYS69+28)[0]
 final=snapshot();ne=events.copy();nh={k:dict(v)for k,v in hostFiles.items()}
 for group,a,b in [('return',actual,wanted),('images',final,model),('events',ne,me),('hostFiles',nh,mh)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:16],model=b if group!='images'else'compactdiff'))
 scriptName=native_text(n.unpack('<I',actual+8)[0])if actual and n.unpack('<I',actual+8)[0]else'';state=n.unpack('<I',actual+16)[0]if actual else 0;stateNames=[]
 while state:stateNames.append(native_text(n.unpack('<I',state+24)[0]));state=n.unpack('<I',state)[0]
 cases.append(dict(context=c,inputs=dict(archive=0,path=FOLDER46,fileName=ROOTNAME,top=TOP,bottom=BOTTOM,system=SYS69),initial=initial,returnValue=actual,final=final,nativeEvents=ne,hostFiles={str(k):v for k,v in nh.items()},summary=dict(scriptName=scriptName,stateNames=stateNames)))
def wide101(text,order):return((b'\xff\xfe'if order=='le'else b'\xfe\xff')+text.encode('utf-16'+order)).decode('latin1')
def packed101(token):
 raw=token.encode('latin1');raw+=b'\0'if len(raw)&1 else b'';return raw.decode('utf-16le')
normal='STATE BASE\n}\nSTATE TARGET\n}\n';packed=packed101('STATE')+' '+packed101('BASE')+'\n}\n'+packed101('STATE')+' '+packed101('TARGET')+'\n}\n'
#Observed release diagnostics are RET-only, not application callbacks.
releaseDiagnostics102={0x4ef790,0x4ef7b0,0x512850,0x512860,0x512870}
oldhook102=hook46
def hook46(mu,address,size,data):
 if address in releaseDiagnostics102:return
 return oldhook102(mu,address,size,data)
#Fresh native instance excludes earlier diagnostic adapters; retain only final platform and bounded catalog formatting.
priorNative102=n;n=nm.NativeX86();pe102=struct.unpack_from('<I',n.blob,0x3c)[0];imageSize102=struct.unpack_from('<I',n.blob,pe102+24+56)[0];n.write(0x400000,priorNative102.read(0x400000,(imageSize102+4095)&~4095));n.write(n.STOP,priorNative102.read(priorNative102.STOP,4096))
oldfilehook102=hook94
def releaseFileHook102(mu,address,size,data):
 if address==0x4ef7b0:return
 return oldfilehook102(mu,address,size,data)
n.mu.hook_add(UC_HOOK_CODE,releaseFileHook102);n.mu.hook_add(UC_HOOK_CODE,hook95);n.mu.hook_add(UC_HOOK_CODE,hook99)
class ReleaseEvents102(list):
 def append(self,item):
  if item.get('name')!='Diagnostic':super().append(item)
def execute101(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,selected45,PARSER
 config=c;setup101(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 for p,z in[(FILENAME,256),(BOMTEMP,2),(LOCAL,256),(LOCAL97,512)]:
  for i in range(z):shadow[p+i]=0
 if c['method']=='Body':wanted=finalize40(0,FOLDER46,ROOTNAME,TOP,BOTTOM)
 else:load46(0,FOLDER46,TOP,BOTTOM,SYS69);wanted=rd(SYS69+28)
 model=snapshot(True);me=events.copy();mh={k:dict(v)for k,v in hostFiles.items()};events=ReleaseEvents102();symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 if c['method']=='Body':actual=n.call(0x52c320,[ROOTNAME,TOP,BOTTOM],regs={UC_X86_REG_EAX:FOLDER46,UC_X86_REG_ECX:0},count=24000000)
 else:n.call(0x52c470,[0,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);actual=n.unpack('<I',SYS69+28)[0]
 final=snapshot();ne=events.copy();nh={k:dict(v)for k,v in hostFiles.items()}
 for group,a,b in [('return',actual,wanted),('images',final,model),('events',ne,me),('hostFiles',nh,mh)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:16],model=b if group!='images'else'compactdiff'))
 scriptName=native_text(n.unpack('<I',actual+8)[0])if actual and n.unpack('<I',actual+8)[0]else'';state=n.unpack('<I',actual+16)[0]if actual else 0;stateNames=[]
 while state:stateNames.append(native_text(n.unpack('<I',state+24)[0]));state=n.unpack('<I',state)[0]
 cases.append(dict(context=c,inputs=dict(archive=0,path=FOLDER46,fileName=ROOTNAME,top=TOP,bottom=BOTTOM,system=SYS69),initial=initial,returnValue=actual,final=final,nativeEvents=ne,hostFiles={str(k):v for k,v in nh.items()},summary=dict(scriptName=scriptName,stateNames=stateNames)))

for content101,order,buffered,chunk in itertools.product(['',normal,';comment\n'+normal,'INCLUDE extra.scp\n'+normal,packed],['le','be'],[0,7],[3,17]):
 execute101(dict(method='Body',files={'root.scp':wide101(content101,order),'extra.scp':'STATE EXTRA\n}\n'},order=order,wideText=content101,buffered=buffered,chunk=chunk,callback=True,seed=0x12345678))
for order,bodyWide,catalogPacked,buffered,chunk in itertools.product(['le','be'],[False,True],[False,True],[0,7],[3,17]):
 catalog=wide101((packed101('root')if catalogPacked else'root')+'\n',order);body=wide101(normal,order)if bodyWide else normal
 files={'script.txt':catalog,'root.scp':body,'r.scp':body,'.scp':body}
 execute101(dict(method='Catalog',files=files,order=order,bodyWide=bodyWide,catalogPacked=catalogPacked,buffered=buffered,chunk=chunk,callback=True,seed=0x12345678))
for content102,mode102,buffered in itertools.product(['INCLUDE absent.scp\nSTATE BASE\n}\n','UNKNOWN token\nSTATE BASE\n}\n'],[0,1,2],[0,7]):
 execute101(dict(method='Body',files={'root.scp':wide101(content102,'le')},order='le',mode=mode102,buffered=buffered,chunk=3,callback=True,seed=0x12345678))
from unicorn.x86_const import UC_X86_REG_EBX,UC_X86_REG_EDX,UC_X86_REG_EBP,UC_X86_REG_EFLAGS
leafCases102=[]
for entry102,eax102,flags102,args102 in itertools.product(sorted(releaseDiagnostics102),[0,0x12345678,0xffffffff],[2,0x202,0x247],[[],[0],[0x10100000,0xffffffff,0x80000000,0x12345678]]):
 before102=snapshot();registers102={UC_X86_REG_EAX:eax102,UC_X86_REG_EBX:0x1234abcd,UC_X86_REG_ECX:0xffffffff,UC_X86_REG_EDX:0x80000000,UC_X86_REG_ESI:0xdeadbeef,UC_X86_REG_EDI:0x10123456,UC_X86_REG_EBP:0xabcdef01,UC_X86_REG_EFLAGS:flags102};result102=n.call(entry102,args102,regs=registers102,count=8);after102=snapshot();actualRegs102={r:n.mu.reg_read(r)for r in registers102}
 for group102,a102,b102 in [('registers',actualRegs102,registers102),('images',after102,before102)]:
  checks+=1
  if a102!=b102:errors.append(dict(group=group102,entry=entry102,native=a102,model=b102))
 leafCases102.append(dict(entry=entry102,eax=eax102,flags=flags102,args=args102,result=result102,registers=actualRegs102))

report=dict(binarySha256=n.sha256,nativeCases=len(cases)+len(leafCases102),semanticCases=len(cases),leafCases=len(leafCases102),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=5,ports=['CreateFile','SetFilePointerEx','ReadFile','CloseHandle','boundedCRTcatalogFormatter'],closure='Whole101 filesystem body/catalog with original five RET-only release diagnostic bodies, no diagnostic callbacks')
(nm.BASE/'reports/script-phase102-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase102-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases,leafCases=leafCases102),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:2]))
