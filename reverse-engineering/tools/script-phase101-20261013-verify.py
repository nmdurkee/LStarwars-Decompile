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
for content101,order,buffered,chunk in itertools.product(['',normal,';comment\n'+normal,'INCLUDE extra.scp\n'+normal,packed],['le','be'],[0,7],[3,17]):
 execute101(dict(method='Body',files={'root.scp':wide101(content101,order),'extra.scp':'STATE EXTRA\n}\n'},order=order,wideText=content101,buffered=buffered,chunk=chunk,callback=True,seed=0x12345678))
for order,bodyWide,catalogPacked,buffered,chunk in itertools.product(['le','be'],[False,True],[False,True],[0,7],[3,17]):
 catalog=wide101((packed101('root')if catalogPacked else'root')+'\n',order);body=wide101(normal,order)if bodyWide else normal
 files={'script.txt':catalog,'root.scp':body,'r.scp':body,'.scp':body}
 execute101(dict(method='Catalog',files=files,order=order,bodyWide=bodyWide,catalogPacked=catalogPacked,buffered=buffered,chunk=chunk,callback=True,seed=0x12345678))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:12],managedExecution=False,newEntries=0,ports=['CreateFile','SetFilePointerEx','ReadFile','CloseHandle','boundedCRTcatalogFormatter','establishedScriptDiagnostics'],closure='Actual52c320 body and52c470 catalog through100 wide producers/completefilesystem while byte consumers remain original',summaries=[dict(method=c['context']['method'],order=c['context']['order'],summary=c['summary'])for c in cases[:8]])
(nm.BASE/'reports/script-phase101-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase101-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k not in['errors','summaries']}));print(json.dumps(errors[:8]));print(json.dumps([c['summary']for c in cases]))
