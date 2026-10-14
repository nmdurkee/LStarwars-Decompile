"""Actual U32 scalar writer and raw block-begin→position/U32 twice; final write/seek only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase134-20261013-verify.py').read_text().split('\nfor h,align,current,cap,boolean,report')[0])
ENDIAN=0x91eea0;segments+=[(ENDIAN,8)];cases=[];checks=0;errors=[]
def scalar135(h,value):
 data=struct.pack('<I',value)
 if rd(ENDIAN):data=data[::-1]
 return write134(h,data,4)
def begin135(h,tag,flag):
 index=rd(DEPTH);wd(DEPTH,(index+1)&0xffffffff);p=STACK+index*16;position=position134(h);wd(p+8,position&0xffffffff);wd(p+12,position>>32);wd(p,tag);wd(p+4,0xffffffff if flag==1 else 1);scalar135(h,tag);return scalar135(h,tag)

def run135(c):
 global shadow,checks,events,config,ms,ns
 config=c
 for p,z in segments:n.write(p,bytes((i*37+11)&255 for i in range(z)))
 h=c['handle'];n.pack('<2I',DEPTH,c.get('depth',0),8);n.pack('<I',ENDIAN,c['endian']);data=DATA
 if 0x400<=h<0x1000:
  if c.get('alias')=='record':data=STACK+c.get('depth',0)*16+4
  if c.get('alias')=='endian':data=ENDIAN
  for i in range(20):n.pack('<I',TABLE+i*20+16,1 if i<h-0x400 else 0)
  assert n.call(0x4f02d0,[data,c.get('fileLength',64),c.get('mode',1)])==h;n.call(0x4f6de0,[h,c['current'],0,0])
 elif h<0x400:
  p=STREAM+(h-1)*64;n.pack('<2I',p+8,c['current'],c.get('currentHigh',0));n.pack('<I',p+44,c.get('buffered',0));n.pack('<I',HANDLES+(h-1)*4,0x12345678+h)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};initialFile=dict(position=c.get('physical',c['current']),bytes=bytes((i*37+11)&255 for i in range(64)).hex());ms=dict(position=initialFile['position'],bytes=bytearray.fromhex(initialFile['bytes']),seeks=0,writes=0);ns=dict(position=initialFile['position'],bytes=bytearray.fromhex(initialFile['bytes']),seeks=0,writes=0);events=[];wanted=scalar135(h,c['value'])if c['method']=='WriteU32'else begin135(h,c['value'],c['flag']);model=snap(True);me=events.copy();mf=fileState134(ms);events=[];actual=n.call(0x4f04b0 if c['method']=='WriteU32'else 0x4f6f00,[h,c['value']]if c['method']=='WriteU32'else[h,c['value'],c['flag']],count=4000000);final=snap();ne=events.copy();nf=fileState134(ns)
 for group,a,b in[('return',actual,wanted),('images',final,model),('events',ne,me),('file',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method=c['method'],context=c,inputs=dict(handle=h,value=c['value'],flag=c.get('flag',0),privateLocal=D+0x2000),initial=initial,initialFile=initialFile,final=final,returnValue=actual,nativeEvents=ne,finalFile=nf))
for method,h,value,endian,current in itertools.product(['WriteU32','Begin'],[1,64,0x400,0x413,0x1000,0x7fffffff],[0,0x01020304,0x80000000,0xffffffff],[0,1,0xffffffff],[0,1,16]):run135(dict(method=method,handle=h,value=value,endian=endian,current=current,fileLength=17,depth=0,flag=len(cases)%3,buffered=0,writeCap=[0,2,64][len(cases)%3],writeBoolean=len(cases)&1,reportWritten=bool(len(cases)&2)))
for depth,flag,buffered,high in itertools.product([0,1,63],[0,1,2,0xffffffff],[0,7],[0,1]):run135(dict(method='Begin',handle=1,value=0x12345678,endian=1,current=5,currentHigh=high,depth=depth,flag=flag,buffered=buffered,physical=5))
for alias,depth,value in itertools.product(['record','endian'],[0,1],[0,0x01020304,0xffffffff]):run135(dict(method='Begin',handle=0x400,value=value,endian=0,current=0,depth=depth,flag=1,alias=alias))
run135(dict(method='Begin',handle=1,value=0x01020304,endian=1,current=5,depth=0,flag=1,buffered=0,physical=5,patchOnSeek=[dict(ordinal=0,patches=[[DEPTH,7]])],patchOnWrite=[dict(ordinal=0,patches=[[ENDIAN,0]])]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],managedExecution=False,newEntries=1,rawEntryConsumers=['0x4f6f00'],ports=['SetFilePointerEx','WriteFile'],closure='Whole126byte4f04b0 scalarU32 writer (91eea0 endian flag)→actualmemory/Win32/CRTwrite; whole94byte rawbegin4f6f00→position→twoidenticaltagDWORDs, per-callendian/livealiases')
(nm.BASE/'reports/script-phase135-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase135-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
