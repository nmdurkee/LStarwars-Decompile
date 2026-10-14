"""Actual printf byte/repeat/span helpers, preserving full EAX, signed byte flush, aliases and caller slots."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_ESP,UC_X86_REG_EIP
D=n.DATA;FILE=D+0x100;BUFFER=D+0x300;SOURCE=D+0x400;COUNTER=D+0x600;ERR=D+0x700;SLOT=n.STACK+0xe004;shadow={};segments=[];events=[];config={};ordinal=0;cases=[];checks=0;errors=[]
def rd(p):return sum(shadow[p+i]<<(i*8)for i in range(4))
def wr(p,v,z=4):
 for i in range(z):
  if p+i not in shadow:raise KeyError(p+i)
  shadow[p+i]=(v>>(i*8))&255
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def port(address,args,model):
 global ordinal
 read=rd if model else lambda p:n.unpack('<I',p)[0];write=wr if model else lambda p,v:n.pack('<I',p,v)
 if address==0x6ead5f:events.append(dict(callback=address,args=[],errno=read(ERR)));return config.get('errnoPointer',ERR)
 ordinal+=1;events.append(dict(callback=address,args=args));write(ERR,config.get('errorValue',21));values=config.get('flushResults',[0xffffffff]);return values[min(ordinal-1,len(values)-1)]
def hook(mu,address,size,data):
 if address not in[0x6eecd9,0x6ead5f]:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<2I',sp+4))if address==0x6eecd9 else[];value=port(address,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
def emit(file,counter,eax):
 if shadow[file+12]&0x40 and not rd(file+8):wr(counter,(rd(counter)+1)&0xffffffff);return eax
 count=(rd(file+4)-1)&0xffffffff;wr(file+4,count)
 if not count&0x80000000:wr(rd(file),eax&255,1);wr(file,(rd(file)+1)&0xffffffff);eax&=255
 else:
  char=eax&255;eax=port(0x6eecd9,[(char if char<128 else char-256)&0xffffffff,file],True)
 wr(counter,rd(counter)|eax if eax==0xffffffff else(rd(counter)+1)&0xffffffff);return eax

def repeat(counter,charSlot,countSlot,fileSlot):
 eax=counter
 while rd(countSlot)!=0 and not rd(countSlot)&0x80000000:
  file=rd(fileSlot);eax=eax&0xffffff00|shadow[charSlot];wr(countSlot,(rd(countSlot)-1)&0xffffffff);eax=emit(file,counter,eax)
  if rd(counter)==0xffffffff:break
 return eax

def span(counter,source,file,countSlot):
 eax=counter
 if shadow[file+12]&0x40 and not rd(file+8):eax=rd(countSlot);wr(counter,(rd(counter)+eax)&0xffffffff);return eax
 while rd(countSlot)!=0 and not rd(countSlot)&0x80000000:
  eax=eax&0xffffff00|shadow[source];wr(countSlot,(rd(countSlot)-1)&0xffffffff);eax=emit(file,counter,eax);source=(source+1)&0xffffffff
  if rd(counter)==0xffffffff:
   eax=port(0x6ead5f,[],True)
   if rd(eax)!=42:break
   eax=emit(file,counter,eax&0xffffff00|0x3f)
 return eax

def execute(c):
 global config,shadow,segments,events,ordinal,checks
 config=c;method=c['method'];count=c.get('length',3);char=c.get('character',0xaabbcc41);file=FILE;counter=c.get('counter',COUNTER);source=c.get('source',SOURCE);n.write(D,bytes([0xcd])*0x1000);n.pack('<4I',FILE,c.get('destination',BUFFER),c.get('capacity',8),0 if c.get('nullBase')else BUFFER,c.get('flags',0x42));n.write(SOURCE,bytes([65,255,128,0,66,67,68,69]));n.pack('<I',ERR,c.get('errorValue',21))
 if counter and counter!=0xdead0000:n.pack('<I',counter,c.get('counterValue',0))
 args=[char,count&0xffffffff,file]if method=='Repeat'else[count&0xffffffff]if method=='Span'else[];n.pack('<3I',SLOT,*(args+[0]*(3-len(args))));segments=[(D,0x1000),(SLOT,12)];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0;mf=False;want=0
 try:want=emit(file,counter,char)if method=='Byte'else repeat(counter,SLOT,SLOT+4,SLOT+8)if method=='Repeat'else span(counter,source,file,SLOT)
 except KeyError:mf=True
 model=snap(True);me=events.copy();events=[];ordinal=0;nf=False;got=0
 regs={UC_X86_REG_EAX:char,UC_X86_REG_ECX:file,UC_X86_REG_ESI:counter}if method=='Byte'else{UC_X86_REG_EAX:counter}if method=='Repeat'else{UC_X86_REG_EAX:counter,UC_X86_REG_ECX:source,UC_X86_REG_EDI:file}
 try:got=n.call({'Byte':0x6eee39,'Repeat':0x6eee6c,'Span':0x6eee90}[method],args,regs=regs,count=500000)
 except RuntimeError:nf=True
 native=snap();ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:
   diff=[]
   if group=='images':
    for x,y in zip(a,b):
     for i,(aa,bb)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes']))):
      if aa!=bb:diff.append([hex(x['address']+i),aa,bb])
   errors.append(dict(group=group,context=c,native=a if group!='images'else diff[:16],model=b if group!='images'else'byte image'))
 cases.append(dict(context=c,inputs=dict(method=method,file=file,counter=counter,source=source,character=char,characterSlot=SLOT,countSlot=SLOT+4 if method=='Repeat'else SLOT,fileSlot=SLOT+8),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for method,capacity,flags,nullBase,character,length in itertools.product(['Byte','Repeat','Span'],[0,1,3,8,0x80000000],[0,0x40,0x42],[False,True],[0xaabbcc41,0xaabbccff],[-1,0,1,3]):execute(dict(method=method,capacity=capacity,flags=flags,nullBase=nullBase,character=character,length=length))
for method,counter in itertools.product(['Byte','Repeat','Span'],[0,FILE,FILE+4,FILE+8,FILE+12,ERR,0xdead0000]):execute(dict(method=method,counter=counter,counterValue=0,capacity=1))
for method in['Byte','Repeat','Span']:
 for c in[dict(capacity=0,flushResults=[0],errorValue=42),dict(capacity=0,flushResults=[0xffffffff,0],errorValue=42),dict(capacity=0,flushResults=[0xffffffff],errorValue=42),dict(capacity=0,errnoPointer=0),dict(capacity=0,length=0x7fffffff),dict(source=BUFFER,destination=BUFFER+1),dict(destination=FILE),dict(counterValue=0xffffffff),dict(length=-2147483648)]:execute(dict(method=method,**c))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=3,ports=['6EECD9 flush','6EAD5F errno getter'])
(nm.BASE/'reports/script-phase153-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase153-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
