"""Actual complete nested block begin/U32 payload/close lifecycle; final seek/write only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase135-20261013-verify.py').read_text().split('\nfor method,h,value,endian,current')[0])
cases=[];checks=0;errors=[]
def run136(c):
 global shadow,checks,events,config,ms,ns
 config=c
 for p,z in segments:n.write(p,bytes((i*37+11)&255 for i in range(z)))
 h=c['handle'];n.pack('<2I',DEPTH,0,c['alignment']);n.pack('<I',ENDIAN,c['endian'])
 if 0x400<=h<0x1000:
  for i in range(20):n.pack('<I',TABLE+i*20+16,1 if i<h-0x400 else 0)
  assert n.call(0x4f02d0,[DATA,128,1])==h;n.call(0x4f6de0,[h,c['current'],0,0])
 elif h<0x400:
  p=STREAM+(h-1)*64;n.pack('<2I',p+8,c['current'],c.get('currentHigh',0));n.pack('<I',p+44,c['buffered']);n.pack('<I',HANDLES+(h-1)*4,0x12345678+h)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};initialFile=dict(position=c['current'],bytes=bytes((i*37+11)&255 for i in range(64)).hex());ms=dict(position=initialFile['position'],bytes=bytearray.fromhex(initialFile['bytes']),seeks=0,writes=0);ns=dict(position=initialFile['position'],bytes=bytearray.fromhex(initialFile['bytes']),seeks=0,writes=0);events=[];wanted=[begin135(h,0x01020304,c['outerFlag']),scalar135(h,0xdeadbeef)]
 if c['nested']:wanted+=[begin135(h,0x55667788,c['innerFlag']),scalar135(h,0x12345678),close134(h)]
 wanted+=[scalar135(h,0x98765432),close134(h)];model=snap(True);me=events.copy();mf=fileState134(ms);events=[]
 def call(addr,args,wide=False):
  value=n.call(addr,args,count=4000000);return value|(n.mu.reg_read(UC_X86_REG_EDX)<<32)if wide else value
 actual=[call(0x4f6f00,[h,0x01020304,c['outerFlag']]),call(0x4f04b0,[h,0xdeadbeef])]
 if c['nested']:actual+=[call(0x4f6f00,[h,0x55667788,c['innerFlag']]),call(0x4f04b0,[h,0x12345678]),call(0x4f6f60,[h],True)]
 actual+=[call(0x4f04b0,[h,0x98765432]),call(0x4f6f60,[h],True)];final=snap();ne=events.copy();nf=fileState134(ns)
 for group,a,b in[('returns',actual,wanted),('images',final,model),('events',ne,me),('file',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(method='RoundTrip',context=c,inputs=dict(handle=h,privateLocal=D+0x2000),initial=initial,initialFile=initialFile,final=final,returns=actual,nativeEvents=ne,finalFile=nf))
for h,endian,align,nested,outerFlag,innerFlag in itertools.product([1,64,0x400,0x413,0x1000],[0,1],[4,8,12],[False,True],[0,1],[0,1]):run136(dict(handle=h,endian=endian,alignment=align,nested=nested,outerFlag=outerFlag,innerFlag=innerFlag,current=len(cases)&1,buffered=0,writeCap=64,writeBoolean=1,reportWritten=True))
for buffered,high,cap,boolean,report in itertools.product([0,7],[0,1],[0,2,64],[0,1],[False,True]):run136(dict(handle=1,endian=1,alignment=8,nested=True,outerFlag=0,innerFlag=1,current=1,currentHigh=high,buffered=buffered,writeCap=cap,writeBoolean=boolean,reportWritten=report))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],managedExecution=False,newEntries=0,ports=['SetFilePointerEx','WriteFile'],closure='Actual outer/inner4f6f00→full4f04b0 payload→inner/outer4f6f60→position/memory/Win32/CRTwrite/publicseek, exactnestedstack andmixedtag-endian/LElength bytes')
(nm.BASE/'reports/script-phase136-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase136-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
