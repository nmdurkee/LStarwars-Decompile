"""Complete original4f6de0 seek dispatch through actualmemory4f6c70 andrawWin32 wrapper4ff430; finalCRT/compressed/Win32 API values explicit."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase77-20261013-verify.py').read_text().split('\nfor handle,wanted')[0])
s72=Path(__file__).with_name('script-phase72-20261013-verify.py').read_text();exec(s72[s72.index('\ndef sext'):s72.index('\ndef size72')]);exec(s72[s72.index('\ndef seek72'):s72.index('\ndef hook72')])
def public_seek78(handle,low,high,origin):
 if signed(handle)>=0x1000:events.append(dict(name='CrtSeek',args=[handle-0x1000,low,origin,0]));return sext(config.get('crtResult',0))
 if signed(handle)>=0x400:
  sign=0xffffffff if low&0x80000000 else 0
  if handle>=0x800:events.append(dict(name='CompressedSeek',args=[handle,low,sign,origin]));return config.get('compressedResult',[0x87654321,0x12345678])
  return seek72(handle,low,sign,origin)
 index=(handle-1)&0xffffffff;stream=(0x8ceb50+(index<<6))&0xffffffff
 if rd(stream+0x2c):
  offset=low|(high<<32);value=(q(stream+8)+offset if origin==1 else q(stream+0x18)-offset if origin==2 else offset)&MASK64;wq(stream+8,value);return[value&0xffffffff,value>>32]
 return seek76(index,low,high,origin)
n=nm.NativeX86();n.mu.hook_add(UC_HOOK_CODE,hook76)
def hook78(mu,address,size,data):
 if address not in[0x6dee90,0x4f0ae0]:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<4I',sp+4));events.append(dict(name='CrtSeek'if address==0x6dee90 else'CompressedSeek',args=args));ret=n.unpack('<I',sp)[0];value=config.get('crtResult',0)if address==0x6dee90 else config.get('compressedResult',[0x87654321,0x12345678])[0];mu.reg_write(UC_X86_REG_EAX,value)
 if address==0x4f0ae0:mu.reg_write(UC_X86_REG_EDX,config.get('compressedResult',[0x87654321,0x12345678])[1])
 mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook78)
def execute78(c):
 global config,shadow,events,checks,backend
 config=c;handle=c['handle'];setup77(dict(c,wanted=0,size=2048))
 if 0x400<=handle<0x414:n.pack('<5I',TABLE+(handle-0x400)*20,MEMDATA,MEMDATA+17,MEMDATA+5,0,1)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];backend=0;want=public_seek78(handle,c['low'],c['high'],c['origin']);model=snap(True);me=events.copy();mb=backend;events=[];backend=0;value=n.call(0x4f6de0,[handle,c['low'],c['high'],c['origin']]);actual=[value,n.mu.reg_read(UC_X86_REG_EDX)];final=snap();ne=events.copy();nb=backend
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me),('hostPosition',nb,mb)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(handle=handle,low=c['low'],high=c['high'],origin=c['origin']),initial=initial,returnValue=actual,final=final,nativeEvents=ne,hostPosition=[nb&0xffffffff,nb>>32]))
for handle,low,high,origin,buffered in itertools.product([0,1,7,0x400,0x407,0x413,0x800,0x803,0xfff,0x1000,0x1007,0x7fffffff],[0,1,0xffffffff,0x80000000],[0,0xffffffff,0x12345678],[0,1,2,3,0xffffffff],[0,1]):execute78(dict(handle=handle,low=low,high=high,origin=origin,buffered=buffered,cache=0,position=7,crtResult=0x80000000,compressedResult=[0x89abcdef,0x10203040]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=['CRTseek6dee90','compressedSeek4f0ae0','SetFilePointerExIAT7510ec'],closure='Actual4f6de0 allbranches→4f6c70memory/4ff430Win32/buffered64bitcursor; highoffset drops forCRTandcompressed/memory children preserved')
(nm.BASE/'reports/script-phase78-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase78-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
