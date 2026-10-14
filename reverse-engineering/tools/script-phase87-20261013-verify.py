"""Actual stream and public close with final CloseHandle and CRT close ports only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase86-20261013-verify.py').read_text().split('\nfor method,parent')[0])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
HANDLES=0x800780;POOL=D+0xd000;segments=[(TABLE,400),(COMP,0x300),(CONTAINER,0x200),(0x8ceb10,0x400),(HANDLES,0x200),(POOL,64)];events=[];config={};cases=[];checks=0;errors=[]
def closePort87(name,args,model):
 events.append(dict(name=name,args=args));write=wd if model else lambda p,v:n.pack('<I',p,v)
 for p,v in config.get('patches',[]):write(p,v)
 return config.get('crtResult',0x89abcdef)if name=='CrtClose'else config['apiResult']
def stream87(index):
 slot=(0x8007a0+(index<<2))&0xffffffff;value=closePort87('CloseHandle',[rd(slot)],True);wd(slot,0xffffffff);return 1 if value==0 else 0
def publicClose87(handle):
 if signed(handle)>=0x1000:return closePort87('CrtClose',[handle-0x1000,0],True)
 if signed(handle)>=0x400:
  if handle>=0x800:return close86(handle)
  index=handle-0x400;wd(TABLE+index*20+16,0);return index*5
 index=(handle-1)&0xffffffff;stream87(index);stream=(0x8ceb50+(index<<6))&0xffffffff;buffer=rd(stream+56)
 if buffer:wd(buffer,0)
 for i in range(64):wb(stream+i,0)
 return stream
n=nm.NativeX86();API=n.STOP+0x100;n.pack('<I',0x7510e0,API)
def hook87(mu,address,size,data):
 if address not in[API,0x6dee70]:return
 sp=mu.reg_read(UC_X86_REG_ESP);name='CloseHandle'if address==API else'CrtClose';args=list(n.unpack('<I'if address==API else'<2I',sp+4));value=closePort87(name,args,False);mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+(8 if address==API else 4));mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook87)
def execute87(c):
 global shadow,checks,config,events
 config=c
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 handle=c['handle'];method=c['method'];index=c.get('index',(handle-1)&0xffffffff);stream=(0x8ceb50+(index<<6))&0xffffffff
 if method=='Stream'or signed(handle)<0x400:n.pack('<I',(0x8007a0+(index<<2))&0xffffffff,c.get('rawHandle',0x12345678));n.pack('<I',stream+56,POOL if c.get('buffer')else 0)
 elif handle<0x800:n.pack('<5I',TABLE+(handle-0x400)*20,DATA,DATA+17,DATA+5,0,7)
 elif handle<0x1000:record=COMP+(handle-0x800)*48;n.pack('<I',record,CONTAINER);n.pack('<II',record+32,7,9)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];want=stream87(index)if method=='Stream'else publicClose87(handle);model=snap(True);me=events.copy();events=[];actual=n.call(0x4ff380 if method=='Stream'else 0x4f99e0,[index if method=='Stream'else handle]);final=snap();ne=events.copy()
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(handle=handle,index=index),initial=initial,returnValue=actual,final=final,nativeEvents=ne))
for method,index,result,buffer,raw in itertools.product(['Stream','Close'],[0,1,7],[0,1,0xffffffff],[False,True],[0,0xffffffff,0x12345678]):execute87(dict(method=method,index=index,handle=index+1,apiResult=result,buffer=buffer,rawHandle=raw))
for handle in[0x400,0x407,0x413,0x800,0x803,0x1000,0x1007,0x7fffffff]:execute87(dict(method='Close',handle=handle,apiResult=0))
execute87(dict(method='Close',index=0,handle=1,apiResult=0,buffer=True,patches=[[0x8007a0,7],[0x8ceb50+56,POOL+16],[POOL+16,9]]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=2,ports=['CloseHandleIAT7510e0','CRTclose6dee70'],closure='Whole4f99e0 through actual4ff380/4f6bc0/memset; only final OS/CRT close normalized, negative retry impossible via actual stream child')
(nm.BASE/'reports/script-phase87-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase87-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
