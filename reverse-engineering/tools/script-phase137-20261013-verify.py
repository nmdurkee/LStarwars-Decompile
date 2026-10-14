"""Original raw/string/F32/U32/U16/U8 writer family; actual children, final WriteFile only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase135-20261013-verify.py').read_text().split('\nfor method,h,value,endian,current')[0])
INPUT=D+0x800;cases=[];checks=0;errors=[];addresses={'Raw':0x4f03d0,'Single':0x4f0420,'U32Alternate':0x4f0530,'U16':0x4f05b0,'U16Alternate':0x4f0630,'U8':0x4f06b0,'U8Alternate':0x4f0700,'String':0x4f0750}
def scalar137(method,h,value):
 width=1 if method in['U8','U8Alternate']else 2 if method in['U16','U16Alternate']else 4
 data=(value&((1<<(width*8))-1)).to_bytes(width,'little')
 if width>1 and rd(ENDIAN):data=data[::-1]
 return write134(h,data,width)

def run137(c):
 global shadow,checks,events,config,ms,ns
 config=c
 for p,z in segments:n.write(p,bytes((i*37+11)&255 for i in range(z)))
 h=c['handle'];n.pack('<I',ENDIAN,c['endian']);payload=bytes.fromhex(c.get('payload',''));n.write(INPUT,payload+b'\0')
 if 0x400<=h<0x1000:
  for i in range(20):n.pack('<I',TABLE+i*20+16,1 if i<h-0x400 else 0)
  assert n.call(0x4f02d0,[DATA,c.get('fileLength',17),1])==h;n.call(0x4f6de0,[h,c['current'],0,0])
 elif h<0x400:n.pack('<I',HANDLES+(h-1)*4,0x12345678+h)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};initialFile=dict(position=c['current'],bytes=bytes((i*37+11)&255 for i in range(64)).hex());ms=dict(position=initialFile['position'],bytes=bytearray.fromhex(initialFile['bytes']),seeks=0,writes=0);ns=dict(position=initialFile['position'],bytes=bytearray.fromhex(initialFile['bytes']),seeks=0,writes=0);events=[];method=c['method']
 if method=='Raw':wanted=write134(h,bytes(rb(INPUT+i)for i in range(c['count'])),c['count']);args=[h,INPUT,c['count']]
 elif method=='String':length=0
 else:length=None
 if method=='String':
  while rb(INPUT+length):length+=1
  wanted=write134(h,bytes(rb(INPUT+i)for i in range(length)),length);args=[h,INPUT]
 elif method!='Raw':wanted=scalar137(method,h,c['value']);args=[h,c['value']]
 model=snap(True);me=events.copy();mf=fileState134(ms);events=[];actual=n.call(addresses[method],args,count=4000000);final=snap();ne=events.copy();nf=fileState134(ns)
 for group,a,b in[('return',actual,wanted),('images',final,model),('events',ne,me),('file',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=method,context=c,inputs=dict(handle=h,source=INPUT,value=c.get('value',0),count=c.get('count',0),privateLocal=D+0x2000),initial=initial,initialFile=initialFile,final=final,returnValue=actual,nativeEvents=ne,finalFile=nf))
values=[0,1,0x01020304,0x7fffffff,0x80000000,0xffffffff]
for method,h,value,endian,current in itertools.product(['U32Alternate','U16','U16Alternate','U8','U8Alternate'],[1,64,0x400,0x413,0x1000],values,[0,1,0xffffffff],[0,16]):run137(dict(method=method,handle=h,value=value,endian=endian,current=current,writeCap=[0,2,64][len(cases)%3],writeBoolean=len(cases)&1,reportWritten=bool(len(cases)&2)))
floatValues=[0,0x80000000,1,0x007fffff,0x3f800000,0xbf800000,0x7f800000,0xff800000,0x7fc12345,0xffffffff]
for h,value,endian,current in itertools.product([1,0x400,0x1000],floatValues,[0,1],[0,16]):run137(dict(method='Single',handle=h,value=value,endian=endian,current=current))
for method,h,count,current in itertools.product(['Raw','String'],[1,64,0x400,0x413,0x1000],[0,1,17,128],[0,16]):run137(dict(method=method,handle=h,count=count,current=current,endian=0xffffffff,payload=(b'A'*count).hex(),writeCap=[0,2,64][len(cases)%3],writeBoolean=len(cases)&1,reportWritten=bool(len(cases)&2)))
for method in['Raw','String']:run137(dict(method=method,handle=0x400,count=17,current=0,endian=0,payload=(b'abc\0def'+bytes([255])*10).hex()))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=3,rawEntryConsumers=['0x4f0420','0x4f05b0','0x4f0630','0x4f06b0','0x4f0700'],ports=['WriteFile'],closure='Whole raw03d0/string0750/U32alt0530 plusrawF32/U16/U8variants→actualmemory/Win32/CRTwrite; F32 finite/quiet-NaN prepared domain andper-callendian; finalOSonly')
(nm.BASE/'reports/script-phase137-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase137-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
