"""Actual byte primitives and path compaction; catalog wrapper executes real game open children."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase94-20261013-verify.py').read_text().split('\nfor type,mode')[0])
A96=D+0x70000;B96=D+0x71000;CONTEXT96=D+0x72000;segments +=[(A96,512),(B96,512),(CONTEXT96,32),(0x91ee88,4)];cases=[];checks=0;errors=[]
def length96(p):
 value=0
 while rb(p+value):value+=1
 return value

def copy96(destination,source):
 original=destination;c=rb(source)if source else 0;budget=0
 while c:
  budget+=1;assert budget<4096;source+=1;wb(destination,c);c=rb(source);destination+=1
 wb(destination,0);return destination-original

def append96(destination,source):
 cursor=destination+length96(destination)
 if not source:return cursor
 budget=0
 while True:
  budget+=1;assert budget<4096;c=rb(source);wb(cursor,c);c=rb(source);cursor+=1;source+=1
  if not c:return cursor

def compact96(context,path):
 input=path;output=path;budget=0
 if rb(path):
  while True:
   budget+=1;assert budget<4096;separator=rb(context+16)
   if rb(input)==separator and rb(input+1)==46 and rb(input+2)==46 and rb(input+3)==separator:
    output=input
    if input>path:
     while True:
      c=rb(output-1);output-=1
      if c==separator:input+=3;break
      if c==58:output+=1;input+=4;break
      if output<=path:break
   wb(output,rb(input));input+=1;output+=1
   if not rb(input):break
 wb(output,0);return output

def execute96(c):
 global config,shadow,events,checks,seekOrdinal,pollCalls
 config=c;method=c['method']
 if method=='CatalogOpen':
  p94=Path(__file__).with_name('script-phase94-20261013-verify.py').read_text();setup=p94[p94.index(' config=c\n',p94.index('def execute94')):p94.index('initial=snap();',p94.index('def execute94'))];setup='\n'.join(line[1:]if line.startswith(' ')else line for line in setup.splitlines());exec(setup,globals(),dict(c=c));n.pack('<I',0x91ee88,CON if c.get('container')else 0)
 else:
  for p,z in segments:n.write(p,bytes(z))
  n.write(A96,bytes.fromhex(c.get('a','616263'))+b'\0');n.write(B96,bytes.fromhex(c.get('b','78797a'))+b'\0');n.write(CONTEXT96+16,bytes([c.get('separator',92)]))
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];seekOrdinal=0;pollCalls=0
 if method=='Length':inputs=dict(text=A96);want=length96(A96);address=0x4f1ff0;args=[A96]
 elif method=='Copy':source=0 if c.get('null')else A96+c['alias']if 'alias'in c else B96;inputs=dict(destination=A96,source=source);want=copy96(A96,source);address=0x4f1f10;args=[A96,source]
 elif method=='Append':source=0 if c.get('null')else A96+c['alias']if 'alias'in c else B96;inputs=dict(destination=A96,source=source);want=append96(A96,source);address=0x4f1e80;args=[A96,source]
 elif method=='Compact':context=0 if c.get('nullContext')else CONTEXT96;inputs=dict(context=context,path=A96);want=compact96(context,A96);address=0x4efec0;args=[context,A96]
 else:
  for i in range(256):shadow[FILENAME+i]=0;shadow[LOCAL+i]=0
  inputs=dict(path=PATH,mode=c['mode']);want=gameOpen94(PATH,c['mode'],rd(0x91ee88),0);address=0x4fa5f0;args=[PATH,c['mode']]
 model=snap(True);me=events.copy();ms=seekOrdinal;events=[];seekOrdinal=0;actual=n.call(address,args,count=5000000);final=snap();ne=events.copy();ns=seekOrdinal
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me),('seekOrdinal',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[x for x,y in zip(a,b)if x!=y][:1],model=b if group!='images'else[y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,returnValue=actual,final=final,nativeEvents=ne,seekOrdinal=ns))
for a,b in itertools.product([b'',b'a',b'abc',b'\xff\xe0'],[b'',b'xyz',b'\xff\xe0']):
 for method in['Length','Copy','Append']:execute96(dict(method=method,a=a.hex(),b=b.hex()))
for method in['Copy','Append']:execute96(dict(method=method,a='616263',null=True))
for alias in[0,1,3]:execute96(dict(method='Copy',a='616263',alias=alias))
execute96(dict(method='Append',a='616263',alias=3))
paths=[b'',b'a',b'a\\b',b'a\\b\\..\\c',b'\\..\\a',b'a\\..\\b',b'C:a\\..\\b',b'C:\\a\\..\\b',b'root\\a\\..\\b\\..\\c',b'a/../b',b'C:a/../b',b'a\\..\\']
for path,separator in itertools.product(paths,[47,92]):execute96(dict(method='Compact',a=path.hex(),separator=separator))
execute96(dict(method='Compact',a='',nullContext=True))
for mode,container,found,type in itertools.product([0,1,2,3,0xffffffff],[False,True],[False,True],[0,1,2]):execute96(dict(method='CatalogOpen',mode=mode,container=container,containerFound=found,type=type))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=5,ports=['catalogOnlyProviderFormat/finalOS/CRT/critical/diagnostic'],closure='Original4f1ff0/4f1f10/4f1e80/4efec0 bodies no adapters; original4fa5f0→real4fa3f0/provider/container/open/seek/poll children')
(nm.BASE/'reports/script-phase96-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase96-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
