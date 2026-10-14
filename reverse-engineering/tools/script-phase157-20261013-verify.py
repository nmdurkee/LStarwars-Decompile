"""Original invalid-parameter dispatcher36bytes. Tail arguments and mutation preserved; terminal fatal child explicitly simulated."""
import importlib.util,json,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
D=n.DATA;ARGS=n.STACK+0xe004;CALLBACK=n.STOP+0xc00;GLOBAL=0x297c19c;shadow={};events=[];segments=[];config={};cases=[];checks=0;errors=[]
rd=lambda p:sum(shadow[p+i]<<(i*8)for i in range(4))
def wr(p,v,z=4):
 for i in range(z):
  if p+i not in shadow:raise KeyError(p+i)
  shadow[p+i]=(v>>(i*8))&255
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def port(address,args,model):
 events.append(dict(callback=address,args=args));write=wr if model else lambda p,v,z=4:n.write(p,int(v&((1<<(8*z))-1)).to_bytes(z,'little'))
 for p,z,v in config.get('patches',{}).get(hex(address),[]):write(p,v,z)
 if address==0x6f01bc:return config.get('handler',CALLBACK)
 if address==0x6f8568:return config.get('reportResult',0)
 return config.get('result',0x12345678)
def hook(mu,address,size,data):
 if address not in[0x6f01bc,0x6f8568,CALLBACK,0x6e9e8e]:return
 sp=mu.reg_read(UC_X86_REG_ESP);argc=1 if address in[0x6f01bc,0x6f8568] else 5;args=list(n.unpack('<'+'I'*argc,sp+4));value=port(address,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
def execute(c):
 global config,shadow,segments,events,checks
 config=c;words=c.get('arguments',[1,2,3,4,5]);n.write(D,bytes(0x100));n.pack('<5I',ARGS,*words);n.pack('<I',GLOBAL,c.get('encoded',0xabcdef01));segments=[(D,0x100),(ARGS,20),(GLOBAL,4)];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];mf=False;want=0
 try:
  handler=port(0x6f01bc,[rd(GLOBAL)],True)
  if handler:want=port(handler,[rd(ARGS+i*4)for i in range(5)],True)
  else:port(0x6f8568,[2],True);want=port(0x6e9e8e,[rd(ARGS+i*4)for i in range(5)],True)
 except KeyError:mf=True
 model=snap(True);me=events.copy();events=[];nf=False;got=0
 try:got=n.call(0x6e9fc2,words)
 except RuntimeError:nf=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(arguments=ARGS),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for handler,encoded,words,result in itertools.product([0,CALLBACK],[0,1,0xffffffff,0x80000000,0xabcdef01],[[0]*5,[1,2,3,4,5],[0xffffffff,0x80000000,D,ARGS,GLOBAL]],[0,1,0xffffffff,0x12345678]):execute(dict(handler=handler,encoded=encoded,arguments=words,result=result))
for handler in[0,CALLBACK]:
 for stage in[0x6f01bc,0x6f8568]:execute(dict(handler=handler,patches={hex(stage):[[ARGS,4,0xfeedbeef],[ARGS+16,4,0xface1234],[GLOBAL,4,7]]}))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,ports=['6F01BC pointer decode','decoded user handler','6F8568 report','6E9E8E terminal fatal dispatch (return simulated)'])
(nm.BASE/'reports/script-phase157-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase157-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
