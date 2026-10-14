"""Actual size handle taxonomy and allocated-memory seek/close + public wrappers. CRTsize alone supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase71-20261013-verify.py').read_text().split('\nfor free,')[0])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_EIP,UC_X86_REG_ESP
COMP=0x297dc60;STREAM=0x8cea00;segments=[(TABLE,400),(COMP,0x300),(STREAM,0x1200)];config={};events=[]
def sext(v):return [v&0xffffffff,0xffffffff if v&0x80000000 else 0]
def size72(handle):
 if signed(handle)>=0x1000:events.append(dict(name='CrtSize',handle=(handle-0x1000)&0xffffffff));return sext(config['crtResult'])
 if signed(handle)>=0x800:
  slot=COMP+(handle-0x800)*48;return sext(rd(slot+28 if rd(slot+40)else slot+24))
 if signed(handle)>=0x400:
  slot=TABLE+(handle-0x400)*20;return sext((rd(slot+4)-rd(slot))&0xffffffff)
 slot=(0x8ceb28+((handle<<6)&0xffffffff))&0xffffffff;return [rd(slot),rd(slot+4)]
def seek72(handle,low,high,origin):
 slot=TABLE+(handle-0x400)*20;value=(rd(slot+8)+low if origin==1 else rd(slot+4)-low if origin==2 else rd(slot)+low)&0xffffffff;wd(slot+8,value);return sext((value-rd(slot))&0xffffffff)
def close72(handle):index=handle-0x400;wd(TABLE+index*20+16,0);return index*5
def hook72(mu,address,size,data):
 if address!=0x6dee40:return
 sp=mu.reg_read(UC_X86_REG_ESP);handle=n.unpack('<I',sp+4)[0];events.append(dict(name='CrtSize',handle=handle));mu.reg_write(UC_X86_REG_EAX,config['crtResult']);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,hook72)
def execute72(c):
 global shadow,checks,config,events
 config=c
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 method=c['method'];handle=c['handle']
 if method=='Size':
  if signed(handle)>=0x1000:pass
  elif signed(handle)>=0x800:n.pack('<II',COMP+(handle-0x800)*48+24,c['value0'],c['value1']);n.pack('<I',COMP+(handle-0x800)*48+40,c['flag'])
  elif signed(handle)>=0x400:n.pack('<II',TABLE+(handle-0x400)*20,c['base'],c['end'])
  else:n.pack('<II',(0x8ceb28+((handle<<6)&0xffffffff))&0xffffffff,c['value0'],c['value1'])
 else:n.pack('<5I',TABLE+(handle-0x400)*20,DATA,DATA+17,c.get('cursor',DATA+5),c.get('mode',0),c.get('live',1))
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[]
 if method=='Size':inputs=dict(handle=handle);want=size72(handle);address=0x4f6b40
 elif method in['Seek','PublicSeek']:inputs=dict(handle=handle,low=c['low'],high=c['high'],origin=c['origin']);want=seek72(**inputs);address=0x4f6de0 if method=='PublicSeek'else 0x4f6c70
 else:inputs=dict(handle=handle);want=[close72(handle)];address=0x4f99e0 if method=='PublicClose'else 0x4f6bc0
 model=snap(True);me=events.copy();events=[];eax=n.call(address,list(inputs.values()));actual=[eax,n.mu.reg_read(UC_X86_REG_EDX)]if method not in['Close','PublicClose']else[eax];final=snap();ne=events.copy()
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=inputs,initial=initial,returnValue=actual,final=final,nativeEvents=ne))
for index,base,end in itertools.product([0,7,19],[0,DATA,0xfffffff0],[0,DATA-1,DATA,DATA+17,0xffffffff]):execute72(dict(method='Size',handle=0x400+index,base=base,end=end))
for handle,flag,value0,value1 in itertools.product([0x800,0x803],[0,1,0xffffffff],[0,0x80000000,0xffffffff],[1,0x7fffffff,0xdeadbeef]):execute72(dict(method='Size',handle=handle,flag=flag,value0=value0,value1=value1))
for handle,value0,value1 in itertools.product([0,1,7,0xffffffff],[0,1,0xffffffff],[0,0x80000000,0xffffffff]):execute72(dict(method='Size',handle=handle,value0=value0,value1=value1))
for handle,value in itertools.product([0x1000,0x1001,0x7fffffff],[0,1,0x7fffffff,0x80000000,0xffffffff]):execute72(dict(method='Size',handle=handle,crtResult=value))
for method,index,low,high,origin,cursor in itertools.product(['Seek','PublicSeek'],[0,7,19],[0,1,0xffffffff,0x80000000,0x7fffffff],[0,0xffffffff,0x12345678],[0,1,2,3,0xffffffff],[DATA,DATA+5,0xfffffffc]):execute72(dict(method=method,handle=0x400+index,low=low,high=high,origin=origin,cursor=cursor))
for method,index,live,mode in itertools.product(['Close','PublicClose'],[0,7,19],[0,1,0xffffffff],[0,1]):execute72(dict(method=method,handle=0x400+index,live=live,mode=mode))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=3,ports=['CRTsize6dee40'],closure='Actual4f6b40 allsizebranches;4f6c70 memoryseek;4f6bc0 memoryclose; original4f6de0/4f99e0 memorycallerbranches')
(nm.BASE/'reports/script-phase72-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase72-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
