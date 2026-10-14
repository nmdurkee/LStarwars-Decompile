"""Original per-file52bcb0 plus5137a0 loop; only transport/dispatch leaves supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase28-20261013-verify.py').read_text().split('\nfor flags,cached')[0])
from unicorn.x86_const import UC_X86_REG_EDI,UC_X86_REG_ESI
def wb(p,v):
 if p not in shadow:raise KeyError(p)
 shadow[p]=v&255
n=nm.NativeX86();segments=[(D,0x10000),(0x922214,0x38)];PARSER=D+0xe000;TOP=D+0xf100;BOTTOM=TOP+4;OUTPUT=TOP+8;BANK=D+0x2000;FILENAME=D+0xc000;ordinal={};lineIndex=0

def port30(name,args,model):
 global lineIndex
 ordinal[name]=ordinal.get(name,0)+1;read=rd if model else lambda p:n.unpack('<I',p)[0]
 events.append(dict(name=name,args=args,globals=[read(x)for x in[0x922214,0x922218,0x92221c,0x92222c,0x922244]]))
 for p,size,v in config.get('patches',{}).get(name+'#'+str(ordinal[name]),[]):
  if model:
   for i in range(size):wb(p+i,v>>(8*i))
  else:n.write(p,int(v).to_bytes(size,'little'))
 if name=='Open':return config.get('parser',PARSER)
 if name=='NextLine':lineIndex+=1;return PARSER+0x100 if lineIndex<=config.get('lines',0)else 0
 return 0

def hook30(mu,address,size,data):
 sp=mu.reg_read(UC_X86_REG_ESP);name=None;args=[]
 if address==0x513400:name='Open';args=[n.unpack('<I',sp+4)[0],mu.reg_read(UC_X86_REG_EDI),mu.reg_read(UC_X86_REG_ESI)]
 elif address==0x4fa300:name='Close';args=[n.unpack('<I',sp+4)[0]]
 elif address==0x4f10e0:name='PushTable';args=list(n.unpack('<II',sp+4))
 elif address==0x4fc5b0:name='NextLine';args=[n.unpack('<I',sp+4)[0]]
 elif address==0x4f7fb0:name='NextToken';args=[n.unpack('<I',sp+4)[0]]
 elif address==0x4fa020:name='Dispatch';args=[n.unpack('<I',sp+4)[0]]
 elif address in[0x512850,0x512860]:ret=n.unpack('<I',sp)[0];count=0 if ret==0x52bd38 else 1;events.append(dict(name='Diagnostic',callback=address,args=list(n.unpack('<'+'I'*count,sp+4))))
 if name:
  value=port30(name,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook30)
def populate30(parser,script,top,bottom):
 if not script:return
 wd(0x922214,top);wd(0x922218,bottom);wd(0x92221c,script);wd(0x922244,0);port30('PushTable',[parser,0x801720],True)
 while port30('NextLine',[parser],True):port30('NextToken',[parser],True);wd(0x92222c,(script+64)&0xffffffff);port30('Dispatch',[parser],True)
 for p in[0x922214,0x922218,0x92221c,0x92222c]:wd(p,0)
def parse30(output,context,fileName,archive,top,bottom):
 parser=port30('Open',[archive,context,fileName],True)
 if not parser:events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[fileName]));return
 if not rd(output):
  dest=0
  if top and bottom and(rd(top)+0x58)&0xffffffff<rd(bottom):
   dest=(rd(top)+15)&0xfffffff0;wd(top,(dest+0x58)&0xffffffff)
   for i in range(0x58):wb(dest+i,0)
  else:events.append(dict(name='Diagnostic',callback=0x512850,args=[]))
  wd(output,dest)
  if dest:
   for i in range(0x58):wb(dest+i,0)
   name=text(fileName,True);pos=fold(name).find('.SCP');name=name[:pos]if pos>=0 else name
   result=0
   if name:
    size=len(name)+1
    if top and bottom and(rd(top)+size)&0xffffffff<rd(bottom):
     result=(rd(top)+15)&0xfffffff0;wd(top,(result+size)&0xffffffff)
     for i in range(size):wb(result+i,0)
    for i,b in enumerate(name.encode('latin1')+b'\0'):wb(result+i,b)
   wd(rd(output)+8,result)
 populate30(parser,rd(output),top,bottom);port30('Close',[parser],True)

def execute30(c,method='Parse'):
 global config,shadow,events,ordinal,lineIndex,checks
 config=c;n.write(D,bytes([0xa5])*0x10000);n.write(0x922214,b''.join((0x11111111+i).to_bytes(4,'little')for i in range(14)));n.pack('<I',0x922248,c.get('mode',0));n.write(FILENAME,c.get('fileName','Example.scp').encode('latin1')+b'\0');n.pack('<III',TOP,BANK+c.get('alignment',0),BANK+c.get('bankSize',0x1000),c.get('existing',0));initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal={};lineIndex=0;modelFault=False;top=0 if c.get('nullTop')else TOP;bottom=0 if c.get('nullBottom')else BOTTOM
 try:
  if method=='Parse':parse30(OUTPUT,0x12345678,FILENAME,0xabcdef01,top,bottom)
  else:populate30(PARSER,c.get('script',SCOPED),top,bottom)
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();events=[];ordinal={};lineIndex=0;nativeFault=False
 try:
  if method=='Parse':n.call(0x52bcb0,[OUTPUT,0x12345678,FILENAME,0xabcdef01,top,bottom])
  else:n.call(0x5137a0,[c.get('script',SCOPED)],regs={UC_X86_REG_EAX:top,UC_X86_REG_ECX:bottom,UC_X86_REG_ESI:PARSER})
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in[('fault',nativeFault,modelFault),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,context=c,group=group,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(output=OUTPUT,context=0x12345678,fileName=FILENAME,archive=0xabcdef01,top=top,bottom=bottom,parser=PARSER,script=c.get('script',SCOPED)),initial=initial,fault=nativeFault,final=nf,nativeEvents=ne))
for name,align,lines in itertools.product(['Example.scp','UPPER.SCP','a.ScP.extra','plain','','.scp','x.scp.scp','a\xe0.scp','abc.scpX'],[0,1,7,15],[0,1,3]):execute30(dict(fileName=name,alignment=align,lines=lines))
for bankSize,align in itertools.product([0,0x58,0x59,0x5f,0x60,0x61,0x62,0x70],[0,1,7,15]):execute30(dict(bankSize=bankSize,alignment=align))
for parser,mode,existing,lines in itertools.product([0,PARSER],[0,1,2],[0,SCOPED],[0,2]):execute30(dict(parser=parser,mode=mode,existing=existing,lines=lines))
for c in[dict(nullTop=True),dict(nullBottom=True),dict(nullTop=True,existing=SCOPED,lines=1),dict(patches={'Open#1':[[OUTPUT,4,SCOPED]]},lines=1),dict(patches={'Dispatch#1':[[OUTPUT,4,GLOBAL],[0x922244,4,123],[0x922214,4,0]]},lines=3),dict(patches={'NextLine#1':[[0x92222c,4,0x87654321]],'NextToken#1':[[0x92222c,4,0xabcdef01]]},lines=2)]:execute30(c)
for script,lines in itertools.product([0,SCOPED],[0,1,3]):execute30(dict(script=script,lines=lines),'Populate')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,ports=['513400Open,4fa300Close','4f10e0PushTable,4fc5b0NextLine,4f7fb0NextToken,4fa020Dispatch'],abi='52bcb0 cdecl(output,context,fileName,archive,top,bottom);5137a0 EAXtop ECXbottom ESIparser cdecl(script)',nativeVoidReturnIgnored=True)
(nm.BASE/'reports/script-phase30-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase30-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
