"""Actual CRT fileno/flsbuf, descriptor slot mutation and complete buffered/unbuffered branches."""
import importlib.util,json,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('nm',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_EDX
D=n.DATA;FILE=D+0x100;BUFFER=D+0x300;OTHER=D+0x400;ERR=D+0x500;IOB=D+0x1000;ROWS=D+0x2000;ARGS=n.STACK+0xe004;TABLE=0x29a9b40;shadow={};segments=[];events=[];config={};cases=[];errors=[];checks=0;activeFile=FILE
rd=lambda p:sum(shadow[p+i]<<(i*8)for i in range(4))
def wr(p,v,z=4):
 for i in range(z):
  if p+i not in shadow:raise KeyError(p+i)
  shadow[p+i]=(v>>(i*8))&255
def snap(model=False):return[dict(address=p,bytes=bytes(shadow[p+i]for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def port(address,args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];write=wr if model else lambda p,v,z=4:n.write(p,int(v&((1<<(8*z))-1)).to_bytes(z,'little'));event=dict(callback=address,args=args)
 if address==0x6f6461:event['bytes']=list(bytes(shadow[args[1]+i]for i in range(args[2])))if model else list(n.read(args[1],args[2]))
 events.append(event)
 if address==0x6ead5f:result=config.get('errnoPointer',ERR)
 elif address==0x6e9fc2:result=0
 elif address==0x6e81d7:result=config.get('iob',IOB)
 elif address==0x701ce5:result=config.get('terminal',0)
 elif address==0x701ca1:
  file=args[0];write(file+8,BUFFER);write(file,BUFFER);write(file+0x18,config.get('bufferSize',4));write(file+12,read(file+12)|8);result=0
 elif address==0x6f6461:result=config.get('written',args[2])
 elif address==0x701b88:result=config.get('seekResult',0)
 else:raise ValueError('Unknown child')
 for p,z,v in config.get('patches',{}).get(hex(address),[]):write(p,v,z)
 return result

def hook(mu,address,size,data):
 counts={0x6ead5f:0,0x6e9fc2:5,0x6e81d7:0,0x701ce5:1,0x701ca1:1,0x6f6461:3,0x701b88:4}
 if address not in counts:return
 sp=mu.reg_read(UC_X86_REG_ESP);argc=counts[address];args=list(n.unpack('<'+'I'*argc,sp+4))if argc else[];value=port(address,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value&0xffffffff)
 if address==0x701b88:mu.reg_write(UC_X86_REG_EDX,value>>32)
 mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
def fileno(file):
 if file:return rd(file+0x10)
 wr(port(0x6ead5f,[],True),22);port(0x6e9fc2,[0]*5,True);return 0xffffffff
def error(file):wr(file+12,rd(file+12)|0x20);return 0xffffffff
def flush():
 file=rd(ARGS+4);descriptor=fileno(file);wr(ARGS+4,descriptor);flags=rd(file+12)
 if not flags&0x82:wr(port(0x6ead5f,[],True),9);return error(file)
 if flags&0x40:wr(port(0x6ead5f,[],True),34);return error(file)
 if flags&1:
  wr(file+4,0)
  if not flags&0x10:wr(file+12,flags|0x20);return 0xffffffff
  wr(file,rd(file+8));wr(file+12,flags&0xfffffffe)
 flags=rd(file+12)&0xffffffef|2;wr(file+12,flags);wr(file+4,0);written=0
 if not flags&0x10c:
  standard=file==((port(0x6e81d7,[],True)+0x20)&0xffffffff)
  if not standard:standard=file==((port(0x6e81d7,[],True)+0x40)&0xffffffff)
  if not standard or not port(0x701ce5,[rd(ARGS+4)],True):port(0x701ca1,[file],True)
 if(rd(file+12)&0xffff)&0x108:
  base=rd(file+8);amount=(rd(file)-base)&0xffffffff;wr(file,(base+1)&0xffffffff);wr(file+4,(rd(file+0x18)-1)&0xffffffff)
  if amount and not amount&0x80000000:written=port(0x6f6461,[rd(ARGS+4),base,amount],True)
  else:
   descriptor=rd(ARGS+4)
   if descriptor in[0xffffffff,0xfffffffe]:row=0x829c00
   else:signed=descriptor if descriptor<0x80000000 else descriptor-0x100000000;row=rd((TABLE+(signed>>5)*4)&0xffffffff)+(descriptor&31)*0x38
   if shadow[row+4]&0x20 and port(0x701b88,[descriptor,0,0,2],True)==0xffffffffffffffff:return error(file)
  wr(rd(file+8),shadow[ARGS],1)
 else:amount=1;written=port(0x6f6461,[rd(ARGS+4),ARGS,1],True)
 return error(file)if written!=amount else rd(ARGS)&255

def execute(c):
 global config,shadow,segments,events,checks,activeFile
 config=c;method=c.get('method','Flush');file=c.get('file',FILE);activeFile=file;n.write(D,bytes(0x4000));n.write(ARGS,bytes(0x60));n.write(0x829c00,bytes(16));n.pack('<4I',TABLE-4,ROWS,ROWS,ROWS+0x700,ROWS+0xe00)
 for i in range(96):n.write(ROWS+i*0x38+4,bytes([c.get('descriptorFlags',0)]))
 n.write(0x829c04,bytes([c.get('descriptorFlags',0)]))
 if file:n.pack('<8I',file,(BUFFER+c.get('offset',0))&0xffffffff,123,BUFFER,c.get('flags',2),c.get('descriptor',0)&0xffffffff,0,c.get('bufferSize',4),0xabcdef01)
 n.pack('<I',ERR,0);n.pack('<2I',ARGS,file if method=='FileNo'else c.get('character',0xffffff80),file);segments=[(D,0x4000),(ARGS,0x60),(TABLE-4,16),(0x829c00,16)];initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];mf=False;want=0
 try:want=flush()if method=='Flush'else fileno(file)
 except KeyError:mf=True
 model=snap(True);me=events.copy();events=[];nf=False;got=0
 try:got=n.call(0x6eecd9,[c.get('character',0xffffff80),file])if method=='Flush'else n.call(0x6f3c74,[file])
 except RuntimeError:nf=True
 native=snap()
 ne=events.copy()
 for group,a,b in [('fault',nf,mf),('return',0 if nf else got,0 if mf else want),('images',native,model),('events',ne,me)]:
  checks+=1
  if a!=b:
   diff=[]
   if group=='images':
    for x,y in zip(a,b):
     for i,(aa,bb)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes']))):
      if aa!=bb:diff.append([hex(x['address']+i),aa,bb])
   errors.append(dict(group=group,context=c,native=a if group!='images'else diff[:16],model=b if group!='images'else'byte image'))
 cases.append(dict(context=c,inputs=dict(method=method,file=file,characterSlot=ARGS,fileSlot=ARGS+4),initial=initial,fault=nf,returnValue=0 if nf else got,final=native,nativeEvents=ne))
for flags,offset,descriptor,descFlags in itertools.product([0,1,2,3,0x11,0x12,0x42,0x80,0x100,0x108,0x118],[-1,0,2],[-2,-1,0,31,32],[0,0x20]):execute(dict(flags=flags,offset=offset,descriptor=descriptor,descriptorFlags=descFlags))
for c in[dict(file=0),dict(flags=0,errnoPointer=0),dict(flags=0x42,errnoPointer=0),dict(flags=0x108,offset=2,written=0),dict(flags=0x108,offset=0,descriptorFlags=0x20,seekResult=0xffffffffffffffff),dict(flags=2,file=IOB+0x20,terminal=1),dict(flags=2,file=IOB+0x40,terminal=0),dict(flags=4),dict(flags=0x108,offset=2,patches={'0x6f6461':[[FILE+8,4,OTHER],[ARGS,4,0xffffff52],[ARGS+4,4,31]]}),dict(flags=0x108,file=ARGS+4),dict(flags=0x42,patches={'0x6ead5f':[[FILE+12,4,0x80000000]]})]:execute(c)
for descriptor,file in itertools.product([-2,-1,0,31,32,0x7fffffff],[FILE,0]):execute(dict(method='FileNo',descriptor=descriptor,file=file))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=2,ports=['6EAD5F errno','6E9FC2 invalid','6E81D7 standardstreams','701CE5 isatty','701CA1 getbuf','6F6461 write','701B88 seek'])
(nm.BASE/'reports/script-phase155-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase155-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
