"""Actual UTF16 BOM filesystem parser→wide line/token producers through concrete read/cache/formatter, finalOS APIs only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase98-20261013-verify.py').read_text().split('\nfor data,buffered')[0])
s48=Path(__file__).with_name('script-phase48-20261013-verify.py').read_text();exec(s48[s48.index('def rw'):s48.index('def execute48')]);s49=Path(__file__).with_name('script-phase49-20261013-verify.py').read_text();exec(s49[s49.index('def next49'):s49.index('def hook49')]);segments +=[(0x88ab4c,4)];cases=[];checks=0;errors=[]
def byte100():
 end=signed(rd(PARSER+0x52c));result=(end+1)&0xffffffff
 if signed(rd(PARSER+0x524))>end:
  total=signed(rd(PARSER+0x574))
  if signed(result)>total:return result&0xffffff00
  requested=min(4096,total-(0 if end<0 else end));value=reader77(rd(PARSER+4),rd(PARSER),requested);prior=rd(PARSER+0x52c);wd(PARSER+0x528,(prior+1)&0xffffffff);wd(PARSER+0x52c,(prior+value)&0xffffffff)
  if not value:return 0
 position=rd(PARSER+0x524);offset=(position-rd(PARSER+0x528))&0xffffffff;value=rb((rd(PARSER)+offset)&0xffffffff);wd(PARSER+0x524,(position+1)&0xffffffff);return(offset&0xffffff00)|value

def word49():
 first=byte100();second=byte100();return(second&0xffff0000)|((second&255)<<8)|(first&255)
def execute100(c):
 global config,shadow,events,checks,backend,closeCount,fileBytes,seekOrdinal,pollCalls,selected45,PARSER,P48
 config=c;fileBytes=bytes.fromhex(c['data']);exec(setup94,globals(),dict(c=c));n.pack('<I',PGLOBAL,0);n.pack('<I',PGLOBAL+4,BUFFER);n.pack('<I',OPTIONS,0);n.pack('<I',COUNTER,5)
 for i in range(4):n.pack('<II',POOL+i*0x408,0,i+1)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 for i in range(256):shadow[FILENAME+i]=0;shadow[LOCAL+i]=0
 shadow[BOMTEMP]=0;shadow[BOMTEMP+1]=0;events=[];backend=0;closeCount=0;seekOrdinal=0;pollCalls=0;selected45=0;PARSER=openfile45(PATH);P48=PARSER;wanted=[PARSER]
 for i in range(2):
  wanted.append(next49())
  for j in range(5):wanted.append(next48())
 if c.get('close'):close45(PARSER)
 model=snap(True);me=events.copy();mb=backend;mc=closeCount;ms=seekOrdinal;events=[];backend=0;closeCount=0;seekOrdinal=0;pollCalls=0;selected45=0;parser=n.call(0x4fc860,[PATH],count=12000000);actual=[parser]
 for i in range(2):
  actual.append(n.call(0x4fc5b0,[parser],count=12000000))
  for j in range(5):actual.append(n.call(0x4f7fb0,[parser],count=2000000))
 if c.get('close'):n.call(0x4fa300,[parser],count=2000000)
 final=snap();ne=events.copy();nb=backend;nc=closeCount;ns=seekOrdinal
 for group,a,b in [('returns',actual,wanted),('images',final,model),('events',ne,me),('hostState',[nb,nc,ns],[mb,mc,ms])]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[x for x,y in zip(a,b)if x!=y][:1],model=b if group!='images'else[y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(context=c,inputs=dict(path=PATH),initial=initial,returnValues=actual,final=final,nativeEvents=ne,hostState=dict(position=nb,closeCount=nc,seekOrdinal=ns)))
for text,order,chunk,buffered in itertools.product(['a b\n','"a""b" ;tail\r\nnext\n','\u03b1\u4e2d,\n','a\r\nb\n',' ;comment\nx\n'],['le','be'],[1,3,17],[0,7]):
 payload=(b'\xff\xfe'if order=='le'else b'\xfe\xff')+text.encode('utf-16'+order);execute100(dict(data=payload.hex(),text=text,order=order,chunk=chunk,buffered=buffered,close=bool(len(cases)&1),type=0,mode=0,free=0))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=0,ports=['CreateFile','SetFilePointerEx','ReadFile','CloseHandle'],closure='Whole4fc860/BOM attach/default formatter/fileIO→4fc5b0→actual4fc390/4fc360/4fc2d0/refill/buffer→4f7fb0→actual4f7df0, finalOS APIs only')
(nm.BASE/'reports/script-phase100-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase100-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
