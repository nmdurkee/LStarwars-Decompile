"""Original52c320→52bcb0→rawscriptproducers plus real INCLUDE lifecycle and childfilebody; only final provider/file/symbol services."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase38-20261013-verify.py').read_text().split('\nfor file,flags')[0])
n=nm.NativeX86();P0=PARSER;P1=D+0x20000;LOCAL40=0x1000dff0;ROOTNAME=NAMES+0x1e00;rootHandle=0x12345678;childHandle=0x12345679;files40={};handles40={};fileEvents40=[]
segments+=[(D+0x20000,0x10000),(0x91ee88,4)]
def active40(parser):
 global PARSER
 PARSER=parser;lines.PARSER=parser;lines.LINE=rd(parser+0x50c);tokens.PARSER=parser;tokens.LINE=rd(parser+0x50c);tokens.TOKEN=rd(parser+0x510);countns.update(PARSER=parser,LINE=rd(parser+0x50c),TOKEN=rd(parser+0x510))
def read40(image,p,s,args):
 handle,buffer,requested=args;row=files40[handles40[handle]];data=row['text'].encode('latin1');position=row['position'];count=min(requested,config.get('chunk',4096),max(0,len(data)-position));count=0 if position>=config.get('failAfter',0x7fffffff)else count;image.write(buffer,data[position:position+count]);fileEvents40.append(dict(args=list(args),position=position,count=count));row['position']+=count;return count
lines.read_file=read40
def nextline(model):return lines.line(Image(),dict(binary=0,capacity=4096),{})
def provider40(name,args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];getText=lambda p:text(p)if model else native_text(p)
 entry=dict(name=name,args=args,globals=[read(p)for p in[0x922214,0x922218,0x92221c,0x92222c,0x922244,0x92223c,0x922240]])
 if name=='OpenParser':
  fileName=getText(args[2]);entry['fileName']=fileName;key='child'if fold(fileName)=='EXTRA.SCP'else 'root'if fold(fileName)==fold(config.get('rootName','root.scp'))else None;result=0 if key is None or config.get('failRoot')and key=='root'or config.get('failChild')and key=='child'else files40[key]['parser'];entry['result']=result;events.append(entry);return result
 if name=='Reopen':
  fileName=getText(args[0]);entry['fileName']=fileName;key='child'if fold(fileName)=='EXTRA.SCP'else 'root';result=files40[key]['handle'];files40[key]['position']=0;entry['result']=result;events.append(entry);return result
 events.append(entry)
 if name=='Seek':files40[handles40[args[0]]]['position']=args[1]
 return 0

def suspend40(parser):
 handle=rd(parser+4);signed=handle if handle<0x80000000 else handle-0x100000000
 if 0x400<=signed<0x800:return
 assert rb(parser+8)and handle;provider40('CloseHandle',[handle],True);wd(parser+4,0)
def resume40(parser):
 handle=rd(parser+4);signed=handle if handle<0x80000000 else handle-0x100000000
 if 0x400<=signed<0x800:return
 assert rb(parser+8);handle=provider40('Reopen',[parser+8,0,rd(0x91ee88),0],True);wd(parser+4,handle);position=rd(parser+0x524);provider40('Seek',[handle,position,0xffffffff if position&0x80000000 else 0,0],True);wd(parser+0x52c,(rd(parser+0x524)-1)&0xffffffff)
def copyname40(name,top,bottom):
 if not name:return 0
 size=len(name)+1;result=0
 if top and bottom and((rd(top)+size)&0xffffffff)<rd(bottom):result=(rd(top)+15)&0xfffffff0;wd(top,(result+size)&0xffffffff);zero36(result,size)
 for i,b in enumerate(name.encode('latin1')+b'\0'):
  if result+i not in shadow:raise KeyError(result+i)
  wb(result+i,b)
 return result

def filebody40(output,context,fileName,archive,top,bottom):
 parser=provider40('OpenParser',[archive,context,fileName],True)
 if not parser:events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[fileName]));return
 if not rd(output):
  script=0
  if top and bottom and((rd(top)+88)&0xffffffff)<rd(bottom):script=(rd(top)+15)&0xfffffff0;wd(top,(script+88)&0xffffffff);zero36(script,88)
  else:diag36()
  wd(output,script)
  if script:zero36(script,88);name=text(fileName);pos=fold(name).find('.SCP');name=name[:pos]if pos>=0 else name;copy=copyname40(name,top,bottom);wd(rd(output)+8,copy)
 previous=PARSER;active40(parser);populate31(rd(output));active40(previous);provider40('CloseParser',[parser],True)
def include38():
 bottom=rd(0x922218);script=rd(0x92221c);top=rd(0x922214);parser=PARSER;next_count();suspend40(parser);b=rd(0x922218);t=rd(0x922214);archive=rd(0x92223c);name=rd(parser+0x510);context=rd(0x922240);filebody40(0x92221c,context,name,archive,t,b);resume40(parser);active40(parser);wd(0x922214,top);wd(0x92221c,script);wd(0x922218,bottom)
def findstate40(name,script):
 node=rd(script+16)
 if not name:return 0
 while node:
  p=rd(node+24)
  if p and fold(text(name))==fold(text(p)):return node
  node=rd(node)
 return 0
def finalize40(context,archive,fileName,top,bottom):
 wd(0x92223c,archive);wd(0x922240,context)
 for i in range(4):shadow[LOCAL40+i]=0
 filebody40(LOCAL40,context,fileName,archive,top,bottom);script=rd(LOCAL40);wd(0x92223c,0);wd(0x922240,0)
 if not script:return 0
 state=rd(script+16)
 while state:
  node=rd(state+8)
  while node:
   result=findstate40(rd(node+32),script);name=rd(node+32);wd(node+36,result)
   if name and not result:events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[name,rd(script+8),rd(state+24)]))
   node=rd(node)
  other=rd(state)
  while other:
   if fold(text(rd(state+24)))==fold(text(rd(other+24))):events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[rd(state+24),rd(script+8)]))
   other=rd(other)
  state=rd(state)
 return script

def hook40(mu,address,size,data):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x513400:
  args=[n.unpack('<I',sp+4)[0],mu.reg_read(UC_X86_REG_EDI),mu.reg_read(UC_X86_REG_ESI)];value=provider40('OpenParser',args,False)
 elif address==0x4fa300:args=list(n.unpack('<I',sp+4));value=provider40('CloseParser',args,False)
 elif address in[0x4f99e0,0x4fa3f0,0x4f6de0]:name,count={0x4f99e0:('CloseHandle',1),0x4fa3f0:('Reopen',4),0x4f6de0:('Seek',4)}[address];value=provider40(name,list(n.unpack('<'+'I'*count,sp+4)),False)
 elif address==0x4fb550:
  args=list(n.unpack('<3I',sp+4));handle,buffer,requested=args;row=files40[handles40[handle]];payload=row['text'].encode('latin1');position=row['position'];value=min(requested,config.get('chunk',4096),max(0,len(payload)-position));value=0 if position>=config.get('failAfter',0x7fffffff)else value;n.write(buffer,payload[position:position+value]);fileEvents40.append(dict(args=args,position=position,count=value));row['position']+=value
 elif address in[CB,0x512850,0x512860,0x512870,0x4ef790]:
  ret=n.unpack('<I',sp)[0]
  if address in[0x512850,0x512860]and(ret in[0x52c41d,0x52c42c,0x52c3d9,0x52c3eb,0x52bd38,0x52bdc7,0x52bdce]):count=0 if ret==0x52bd38 else 2 if ret in[0x52c41d,0x52c42c]else 1 if ret in[0x52bdc7,0x52bdce]else 3;events.append(dict(name='Diagnostic',callback=address,args=list(n.unpack('<'+'I'*count,sp+4))))
  else:hook37(mu,address,size,data)
  return
 else:return
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook40)
def resetfiles40(c):
 global files40,handles40,fileEvents40
 h0=0x400 if c.get('archiveHandles')else rootHandle;h1=0x401 if c.get('archiveHandles')else childHandle
 files40={'root':dict(parser=P0,handle=h0,text=c['file'],position=0),'child':dict(parser=P1,handle=h1,text=c.get('includeFile',''),position=0)};handles40={h0:'root',h1:'child'};fileEvents40=[]
def state40():return dict(positions={key:row['position']for key,row in files40.items()},events=fileEvents40.copy())
def setup40(c):
 global PARSER
 PARSER=P0;setup26(c);n.write(D+0x20000,bytes(0x10000));n.pack('<I',0x91ee88,0xabcdef01);n.pack('<I',0x91eec4,0);n.pack('<I',0x922228,0);n.pack('<II',TOP,BANK+c.get('alignment',0),BANK+c.get('bankSize',0x4000));n.write(ROOTNAME,c.get('rootName','root.scp').encode('latin1')+b'\0');resetfiles40(c)
 for key,row in files40.items():
  parser=row['parser'];line=RAWLINE if key=='root'else P1+0x1000;token=TOKEN if key=='root'else P1+0x3000;refill=REFILL if key=='root'else P1+0x4000;n.write(parser,bytes(0x584));n.pack('<II',parser,refill,row['handle']);n.write(parser+8,(c.get('rootName','root.scp')if key=='root'else 'extra.scp').encode('latin1')+b'\0');n.pack('<4I',parser+0x50c,line,token,4096,512);n.pack('<I',parser+0x51c,0xffffffff);n.pack('<I',parser+0x52c,0xffffffff);n.pack('<I',parser+0x570,0xffffffff);n.pack('<I',parser+0x574,len(row['text'].encode('latin1')));n.pack('<I',parser+0x580,SINGLES)
def execute40(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,files40,handles40,fileEvents40
 config=c;setup40(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];symbolOrdinal=0;commandOrdinal=0;active40(P0);modelFault=False;want=0
 try:want=finalize40(0x12345678,0xabcdef01,ROOTNAME,TOP,BOTTOM)
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();ms=state40();events=[];symbolOrdinal=0;commandOrdinal=0;resetfiles40(c);nativeFault=False;got=0
 try:got=n.call(0x52c320,[ROOTNAME,TOP,BOTTOM],regs={UC_X86_REG_EAX:0xabcdef01,UC_X86_REG_ECX:0x12345678},count=12000000)
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy();ns=state40()
 for group,a,b in[('fault',nativeFault,modelFault),('return',0 if nativeFault else got,0 if modelFault else want),('images',nf,mf),('events',ne,me),('files',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(context=0x12345678,archive=0xabcdef01,fileName=ROOTNAME,top=TOP,bottom=BOTTOM,local=LOCAL40),initial=initial,fault=nativeFault,returnValue=0 if nativeFault else got,final=nf,nativeEvents=ne,nativeFiles=ns))
first=actions[0]['name'];baseFile='PARAM 0 alpha 3\nCONST LIMIT 2\nCONDITIONMACRO check\nIF Timer > missing goto BASE\n}\nACTIONMACRO act\n'+first+' one two\n}\nREFERENCESCRIPT\nScript=other Source=Level ReturnState=BASE\nCONDITIONS\nOnMacro check\n}\n}\nSTATE first\nCONDITIONS\nOnMacro check\nIF Param alpha == LIMIT goto BASE\n}\nACTIONS\nDoMacro act\n}\n}\nSTATE BASE\nACTIONS\n'+first+' three\n}\n}\n'
for file,chunk,handled in itertools.product(['',baseFile,'STATE BASE\n}\nSTATE base\n}\n','STATE one\nCONDITIONS\nIF Timer > 1 goto MISSING\n}\n}\n'],[1,17,4096],[False,True]):execute40(dict(file=file,chunk=chunk,callback=True,handled=handled))
rootInclude='CONST OLD 2\nINCLUDE extra.scp\nSTATE root\nCONDITIONS\nIF Timer > OLD goto BASE\n}\n}\nSTATE BASE\n}\n';childInclude='PARAM 2 gamma 7\nCONST NEW 3\nACTIONMACRO act\n'+first+' child\n}\nSTATE extra\nACTIONS\nDoMacro act\n}\n}\n'
for chunk,archiveHandles,failChild in itertools.product([1,17,4096],[False,True],[False,True]):execute40(dict(file=rootInclude,includeFile=childInclude,chunk=chunk,archiveHandles=archiveHandles,failChild=failChild,callback=True))
for mode in[0,1,2]:execute40(dict(file='STATE one\nCONDITIONS\nIF Timer > 1 goto MISSING\n}\n}\nSTATE ONE\n}\n',mode=mode))
for name in['root','ROOT.SCP','root.ScP.extra','','.scp']:execute40(dict(file='STATE BASE\n}\n',rootName=name))
for size,align in itertools.product([0,88,89,96,128,256],[0,1,15]):execute40(dict(file='STATE BASE\n}\n',bankSize=size,alignment=align))
execute40(dict(file=baseFile,failRoot=True));execute40(dict(file=rootInclude,includeFile=childInclude,chunk=1,failAfter=25))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,ports=['513400 preparedOpenParser','4fa300 finalCloseParser','4fb550 finalrawfilebytes','4f99e0Close/4fa3f0Reopen/4f6de0Seek finalfileIO','9238c0symbolcallback'],closure='52c320→52bcb0→5137a0 all8scriptcommands; INCLUDE actualsuspend/nestedfilebody/resume; finaltargets/duplicatechecks')
(nm.BASE/'reports/script-phase40-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase40-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
