"""Original123-byte sprintf own body with explicit output/error/flush children, no wrapper adapter."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
D=n.DATA;DEST=D+0x100;FORMAT=D+0x200;ERR=D+0x300;FILE=n.STACK+0xdfdc;ARGS=n.STACK+0xe00c;shadow={};segments=[];config={};events=[];cases=[];errors=[];checks=0
rd=lambda p:sum(shadow[p+i]<<(8*i)for i in range(4))
def wr(p,v,z=4):
 for i in range(z):
  if p+i not in shadow:raise KeyError(p+i)
  shadow[p+i]=(v>>(i*8))&255
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def port(address,args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0]
 write=wr if model else lambda p,v,z=4:n.write(p,int(v&((1<<(8*z))-1)).to_bytes(z,'little'))
 if address==0x6eef05:
  file,fmt,locale,arguments=args;events.append(dict(callback=address,args=args,header=[read(file+i*4)for i in range(8)]))
  output=bytes(config.get('output',[65,66,67]));dest=read(file)
  for i,b in enumerate(output):write(dest+i,b,1)
  write(file,config.get('outputPointer',dest+len(output)));write(file+4,config.get('outputCount',0x7ffffffc));return config.get('result',3)
 if address==0x6ead5f:events.append(dict(callback=address,args=[]));return config.get('errno',ERR)
 if address==0x6e9fc2:events.append(dict(callback=address,args=args,errno=read(ERR)));write(ERR,config.get('invalidValue',22));return 0
 if address==0x6eecd9:events.append(dict(callback=address,args=args,count=read(args[1]+4)));return config.get('flushResult',0xffffffff)
 raise ValueError('Unexpected child')
def hook(mu,address,size,data):
 if address not in[0x6eef05,0x6ead5f,0x6e9fc2,0x6eecd9]:return
 sp=mu.reg_read(UC_X86_REG_ESP);argc={0x6eef05:4,0x6ead5f:0,0x6e9fc2:5,0x6eecd9:2}[address];args=list(n.unpack('<'+'I'*argc,sp+4))if argc else[];value=port(address,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
# Fresh instance retains original flsbuf and fileno instead of the prior flush adapter.
n=nm.NativeX86()
def hook156(mu,address,size,data):
 if address not in[0x6eef05,0x6ead5f,0x6e9fc2]:return
 sp=mu.reg_read(UC_X86_REG_ESP);argc={0x6eef05:4,0x6ead5f:0,0x6e9fc2:5}[address];args=list(n.unpack('<'+'I'*argc,sp+4))if argc else[];value=port(address,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook156)
def actualflush156(file):
 descriptor=rd(file+0x10);flags=rd(file+12)
 if not flags&0x82:wr(port(0x6ead5f,[],True),9)
 elif flags&0x40:wr(port(0x6ead5f,[],True),34)
 else:raise ValueError('Unprepared nonstring stream')
 wr(file+12,rd(file+12)|0x20);return 0xffffffff

def execute156(c):
 global config,shadow,segments,events,checks
 config=c;n.write(D,bytes([0xcd])*0x500);n.write(FORMAT,b'%s_%d\0');n.write(FILE,bytes(random.Random(c.get('seed',1)).randrange(256)for _ in range(32)));n.pack('<3I',ARGS,0x11223344,0x55667788,0x99aabbcc);segments=[(D,0x500),(FILE,32),(ARGS,12)];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};destination=c.get('destination',DEST);format=c.get('format',FORMAT);events=[];mf=False;want=0
 try:
  if not format or not destination:
   error=port(0x6ead5f,[],True);wr(error,22);port(0x6e9fc2,[0]*5,True);want=0xffffffff
  else:
   wr(FILE+8,destination);wr(FILE,destination);wr(FILE+4,0x7fffffff);wr(FILE+12,0x42);want=port(0x6eef05,[FILE,format,0,ARGS],True);count=(rd(FILE+4)-1)&0xffffffff;wr(FILE+4,count)
   if count&0x80000000:actualflush156(FILE)
   else:wr(rd(FILE),0,1)
 except KeyError:mf=True
 model=snap(True);me=events.copy();events=[];nf=False;got=0
 try:got=n.call(0x6e69ef,[destination,format,0x11223344,0x55667788,0x99aabbcc])
 except RuntimeError:nf=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(destination=destination,format=format,arguments=ARGS,file=FILE),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for count,result,output in itertools.product([0,1,2,0x7fffffff,0x80000000,0xffffffff],[0,3,0xffffffff],[[],[65,66,67],[0,255,128,65]]):execute156(dict(outputCount=count,result=result,output=output))
for destination,format,errno in itertools.product([0,DEST],[0,FORMAT],[ERR,0,0xdead0000]):execute156(dict(destination=destination,format=format,errno=errno,invalidValue=123))
for pointer,count in itertools.product([0,DEST,DEST+0x20,FILE,FILE+4,0xdead0000],[0,1,0x80000000]):execute156(dict(outputPointer=pointer,outputCount=count))
for dest in[FILE,FILE+1,FILE+4,FILE+8,ERR]:execute156(dict(destination=dest,output=[]))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,ports=['6EEF05 output parser','6EAD5F errno getter','6E9FC2 invalid-parameter dispatch'],closure='actual6E69EF→actual6EECD9→actual6F3C74 string-stream error paths')
(nm.BASE/'reports/script-phase156-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase156-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
