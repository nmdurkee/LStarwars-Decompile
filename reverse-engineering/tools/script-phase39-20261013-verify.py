"""Original parser suspend/resume, final virtual Open/Close/Seek and explicit Error EAX/ECX leaves."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
from unicorn.x86_const import UC_X86_REG_ECX
n=nm.NativeX86();segments=[(D,0x10000),(0x91ee88,4)];ordinals39={}
def port39(name,args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];ordinals39[name]=ordinals39.get(name,0)+1;events.append(dict(name=name,args=args,fields=[read(PARSER+4),read(PARSER+0x524),read(PARSER+0x52c)],options=read(0x91ee88)))
 for p,size,v in config.get('patches',{}).get(name+'#'+str(ordinals39[name]),[]):
  if model:
   for i in range(size):wb(p+i,v>>(8*i))
  else:n.write(p,int(v).to_bytes(size,'little'))
 if name=='Open':return config.get('openedHandle',0x12345678)
 if name=='Error':return config.get('errorEax',NAMES),config.get('errorEcx',0x87654321)
 return 0

def suspend39():
 handle=rd(PARSER+4);signed=handle if handle<0x80000000 else handle-0x100000000
 if 0x400<=signed<0x800:return
 if not rb(PARSER+8)or not handle:handle=port39('Error',[],True)[0]
 port39('Close',[handle],True);wd(PARSER+4,0)
def resume39():
 handle=rd(PARSER+4);signed=handle if handle<0x80000000 else handle-0x100000000
 if 0x400<=signed<0x800:return
 name=PARSER+8
 if not rb(PARSER+8):name=port39('Error',[],True)[0]
 handle=port39('Open',[name,0,rd(0x91ee88),0],True);wd(PARSER+4,handle)
 if not handle:handle=port39('Error',[],True)[1]
 position=rd(PARSER+0x524);port39('Seek',[handle,position,0xffffffff if position&0x80000000 else 0,0],True);wd(PARSER+0x52c,(rd(PARSER+0x524)-1)&0xffffffff)
def hook39(mu,address,size,data):
 counts={0x4ef790:('Error',0),0x4f99e0:('Close',1),0x4fa3f0:('Open',4),0x4f6de0:('Seek',4)}
 if address not in counts:return
 name,count=counts[address];sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*count,sp+4));value=port39(name,args,False);ret=n.unpack('<I',sp)[0]
 if name=='Error':mu.reg_write(UC_X86_REG_EAX,value[0]);mu.reg_write(UC_X86_REG_ECX,value[1])
 else:mu.reg_write(UC_X86_REG_EAX,value)
 mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook39)
def execute39(c,method):
 global config,shadow,events,checks,ordinals39
 config=c;n.write(D,bytes([0xa5])*0x10000);n.pack('<I',PARSER+4,c.get('handle',0x12345678));n.write(PARSER+8,c.get('fileName','script.scp').encode('latin1')+b'\0');n.pack('<I',PARSER+0x524,c.get('position',17));n.pack('<I',PARSER+0x52c,0xabcdef01);n.pack('<I',0x91ee88,c.get('options',0x87654321));n.write(NAMES,b'error.scp\0');initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinals39={};modelFault=False
 try:
  if method in['Suspend','RoundTrip']:suspend39()
  if method in['Resume','RoundTrip']:resume39()
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();events=[];ordinals39={};nativeFault=False
 try:
  if method in['Suspend','RoundTrip']:n.call(0x4fa2c0,[PARSER])
  if method in['Resume','RoundTrip']:n.call(0x4fa810,[PARSER])
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in[('fault',nativeFault,modelFault),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(parser=PARSER),initial=initial,fault=nativeFault,final=nf,nativeEvents=ne))
for method,handle,fileName in itertools.product(['Suspend','Resume','RoundTrip'],[0,1,0x3ff,0x400,0x401,0x7ff,0x800,0x12345678,0x7fffffff,0x80000000,0xffffffff],['','script.scp']):execute39(dict(handle=handle,fileName=fileName),method)
for method,position,opened in itertools.product(['Resume','RoundTrip'],[0,1,17,0x7fffffff,0x80000000,0xffffffff],[0,1,0x400,0xffffffff]):execute39(dict(position=position,openedHandle=opened),'Resume'if method=='Resume'else 'RoundTrip')
for patches,method in[({'Close#1':[[PARSER+4,4,99]]},'Suspend'),({'Error#1':[[0x91ee88,4,1],[PARSER+0x524,4,0xffffffff]]},'Resume'),({'Open#1':[[PARSER+4,4,0x77777777],[PARSER+0x524,4,123]]},'Resume'),({'Seek#1':[[PARSER+0x524,4,0],[PARSER+4,4,0x456789ab]]},'Resume')]:execute39(dict(fileName=''if 'Error#1'in patches else 'script.scp',patches=patches),method)
for eax,ecx in itertools.product([0,1,NAMES,0xffffffff],[0,1,0x88888888,0xffffffff]):execute39(dict(fileName='',openedHandle=0,errorEax=eax,errorEcx=ecx),'Resume')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,methods={method:sum(r['method']==method for r in cases)for method in['Suspend','Resume','RoundTrip']},newEntries=2,ports=['4ef790 ErrorEAX/ECX','4f99e0Close','4fa3f0Open','4f6de0Seek'])
(nm.BASE/'reports/script-phase39-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase39-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
