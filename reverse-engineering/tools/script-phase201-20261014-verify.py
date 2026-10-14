"""Entire raw path directory/stem entries and raw current-record getter; actual CRT children, no hooks."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
cases=[];checks=0;errors=[];COUNT=0x800464;RECORDS=0x90ff9c

def run201(method,payload,sa,da,alias=False):
 global checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x1000)));source=D+0x100+sa;n.write(source,payload+b'\0');text=payload.split(b'\0')[0];slash=text.rfind(b'\\');start=slash+1 if slash>=0 else 0
 if method=='Directory':start=0;length=slash+1 if slash>=0 else 0;address=0x4f0890
 else:
  dot=text.rfind(b'.');end=dot if dot>=0 else len(text);length=end-start;address=0x4f08d0
  if length<0:raise ValueError('extension-before-basename case outside prepared bound')
 destination=source+start if alias else D+0x800+da;before=n.read(D,0x1000);model=bytearray(before);model[destination-D:destination-D+length]=text[start:start+length];model[destination-D+length]=0;actual=n.call(address,[destination,source],count=1000000);after=n.read(D,0x1000)
 for group,a,b in [('return',actual,length),('images',after,bytes(model))]:
  checks+=1
  if a!=b:errors.append(dict(group=group,method=method,payload=payload.hex(),sourceAlignment=sa,destinationAlignment=da,alias=alias,native=a if group!='images'else [[hex(D+i),u,v]for i,(u,v)in enumerate(zip(a,b))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=method,inputs=dict(destination=destination,source=source),initial=[dict(address=D,bytes=before.hex())],final=[dict(address=D,bytes=after.hex())],returnValue=actual))
paths=[b'',b'a',b'a.txt',b'a.b.c',b'\\',b'c:\\',b'c:\\dir\\file.ext',b'c:\\dir\\file',b'file.',b'.hidden',b'../folder/name.ext',b'dir.name\\file.ext',b'foo\\.bar',bytes([255,128])+b'\\name.ext',b'abc\0ignored.ext',b'long\\'+b'a'*128+b'.ext']
for method,payload,sa,da,alias in itertools.product(['Directory','Stem'],paths,range(4),range(4),[False,True]):run201(method,payload,sa,da,alias)
for index,value in itertools.product([0,1,2,63],[0,1,0xffffffff,0x80000000]):
 n.pack('<I',COUNT,index);n.write(RECORDS,bytes((i*37+11)&255 for i in range(1024)));n.pack('<I',RECORDS+index*16,value);rows=[dict(address=COUNT,bytes=n.read(COUNT,4).hex()),dict(address=RECORDS,bytes=n.read(RECORDS,1024).hex())];actual=n.call(0x4f0880,[]);checks+=2;final=[dict(address=r['address'],bytes=n.read(r['address'],len(r['bytes'])//2).hex())for r in rows]
 if actual!=value or rows!=final:errors.append(dict(group='record',index=index,value=value,native=actual))
 cases.append(dict(method='Current',inputs={},initial=rows,final=final,returnValue=actual))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,ports=[],rawEntryConsumers=['0x4f0890','0x4f08d0','0x4f0880'],closure='Whole56-byte directory/91-byte stem bodies→actual strrchr45/strncpy292 plusraw15-byte indexed getter; prepared extension location anddisjoint/identical selected source')
(nm.BASE/'reports/script-phase201-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase201-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
