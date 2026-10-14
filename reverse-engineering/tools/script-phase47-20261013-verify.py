"""Actual4fb7f0 retains4fb550 EAX high24, zero-initialized local lowbyte;4f12d0 EAXparser free."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
from unicorn.x86_const import UC_X86_REG_ECX
n=nm.NativeX86();segments=[(D,0x1000)];P47=D+0x100;config={}
def hook47(mu,address,size,data):
 if address!=0x4fb550:return
 sp=mu.reg_read(UC_X86_REG_ESP);handle,buffer,count=n.unpack('<3I',sp+4);assert handle==config['handle']and count==1
 if config['write']:n.write(buffer,bytes([config['byte']]))
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,config['result']);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook47)
def execute47(c,method):
 global config,shadow,checks
 config=c;n.write(D,bytes([0xa5])*0x1000);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};fault=False;want=0;parser=0 if c.get('nullParser')else P47
 if method=='Byte':want=(c['result']&0xffffff00)|(c['byte']if c['write']else 0)
 else:
  if parser:wd(parser,0)
  else:fault=True
 mf=snapshot(True);nfault=False;got=0
 try:got=n.call(0x4fb7f0,[c['handle']],regs={UC_X86_REG_ECX:c['ecx']})if method=='Byte'else n.call(0x4f12d0,regs={UC_X86_REG_EAX:parser})
 except RuntimeError:nfault=True
 if method=='Free':got=want=0
 nf=snapshot()
 for group,a,b in[('fault',nfault,fault),('return',got,want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(parser=parser),initial=initial,fault=nfault,returnValue=got,final=nf))
for result,byte,write,ecx,handle in itertools.product([0,1,0x100,0xffffff00,0x12345678],[0,1,127,128,255],[False,True],[0,0xff000000],[0,0x400,0x12345678]):execute47(dict(result=result,byte=byte,write=write,ecx=ecx,handle=handle),'Byte')
execute47({},'Free');execute47(dict(nullParser=True),'Free')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=['4fb550 singlebytecompilerlocal normalized rawEAX+survivingbyte'])
(nm.BASE/'reports/script-phase47-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase47-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
