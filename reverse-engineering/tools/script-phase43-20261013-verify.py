"""Original52c470 scriptcatalog: normalizedtransport/token/filelocals, actuallist+513f20 inheritance includingretry."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase42-20261013-verify.py').read_text().split('\nfor parentStates,childStates')[0])
from unicorn.x86_const import UC_X86_REG_ECX
n=nm.NativeX86();CATALOG43=D+0x2800;FOLDER43=D+0x2900;TOKEN43=D+0x2a00;GRAND43=D+0x1c00;catalogLine=-1;parseOrdinal43=0;segments+=[(0x923874,4),(0x760448,11),(0x75ffd8,5)]
def port43(name,args,model):
 global parseOrdinal43
 read=rd if model else lambda p:n.unpack('<I',p)[0];events.append(dict(name=name,args=args,globals=[read(0x922248),read(0x923874)]))
 for p,size,v in config.get('patches',{}).get(name,[]):
  if model:
   for i in range(size):wb(p+i,v>>(8*i))
  else:n.write(p,int(v).to_bytes(size,'little'))
 if name=='Find':return config.get('entry',0x55)
 if name=='Information':return [D+0x9000,32]
 if name=='OpenMemory':return config.get('memoryHandle',0x400)
 if name=='OpenFile':return config.get('fileHandle',0x12345678)
 if name=='AttachParser':return config.get('parser',CATALOG43)
 if name=='ParseScript':values=config.get('results',[CHILD42,PARENT42]);value=values[min(parseOrdinal43,len(values)-1)];parseOrdinal43+=1;return value
 return 0

def line43(model):
 global catalogLine
 catalogLine+=1;events.append(dict(name='NextLine',args=[CATALOG43]));return 1 if catalogLine<len(config.get('names',['child','parent']))else 0
def token43(model):
 events.append(dict(name='NextToken',args=[CATALOG43]));value=config.get('names',['child','parent'])[catalogLine];payload=value.encode('latin1')+b'\0'
 if model:
  for i,b in enumerate(payload):wb(TOKEN43+i,b)
 else:n.write(TOKEN43,payload)
def load43(archive,path,top,bottom,system):
 listp=system+28 if system else 0x921ee8;handle=0;fallback=not archive;names=[]
 if archive:
  entry=port43('Find',[archive,0x760448],True)
  if entry:
   data,length=port43('Information',[archive,entry],True);handle=port43('OpenMemory',[data,length,0],True)
   if not handle:events.append(dict(name='Diagnostic',callback=0x512870,args=[]));fallback=True
  else:events.append(dict(name='Diagnostic',callback=0x512870 if rd(0x922248)==1 else 0x512850,args=[]));fallback=True
  if fallback and rd(0x923874)==1:events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[]))
 if fallback:handle=port43('OpenFile',[text(path)+chr(92)+'script.txt',0],True)
 if handle:
  parser=port43('AttachParser',[handle],True)
  if parser:
   while line43(True):token43(True);names.append(text(rd(parser+0x510))+'.scp')
   port43('FreeParser',[parser],True)
  port43('Close',[handle],True)
 for name in names:
  script=port43('ParseScript',[name,path,archive,top,bottom],True)
  if script:
   append36(listp,script)
   if system:wd(script+60,rd(script+60)|1)
 if system:
  while True:
   done=True;script=rd(system+28)
   while script:
    if not apply42(script,top,bottom,system):done=False
    script=rd(script)
   if done:return

def hook43(mu,address,size,data):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x6e69ef:dest,fmt,folder=n.unpack('<3I',sp+4);payload=(native_text(folder)+chr(92)+'script.txt').encode('latin1');n.write(dest,payload+b'\0');value=len(payload)
 elif address==0x4f9de0:value=port43('Find',list(n.unpack('<II',sp+4)),False)
 elif address==0x4f0f30:archive,entry,outData,outLength=n.unpack('<4I',sp+4);ptr,length=port43('Information',[archive,entry],False);n.pack('<I',outData,ptr);n.pack('<I',outLength,length);value=0
 elif address==0x4f02d0:value=port43('OpenMemory',list(n.unpack('<3I',sp+4)),False)
 elif address==0x4fa5f0:path,mode=n.unpack('<II',sp+4);value=port43('OpenFile',[native_text(path),mode],False)
 elif address==0x4fc750:value=port43('AttachParser',list(n.unpack('<I',sp+4)),False)
 elif address==0x4f12e0:value=port43('FreeParser',list(n.unpack('<I',sp+4)),False)
 elif address==0x4f99e0:value=port43('Close',list(n.unpack('<I',sp+4)),False)
 elif address==0x4fc5b0:value=line43(False)
 elif address==0x4f7fb0:token43(False);value=0
 elif address==0x52c320:name,top,bottom=n.unpack('<3I',sp+4);value=port43('ParseScript',[native_text(name),mu.reg_read(UC_X86_REG_EAX),mu.reg_read(UC_X86_REG_ECX),top,bottom],False)
 elif address in[0x512850,0x512860,0x512870]:
  ret=n.unpack('<I',sp)[0]
  if 0x52c470<=ret<0x52c6d0:events.append(dict(name='Diagnostic',callback=address,args=[]))
  else:hook42(mu,address,size,data)
  return
 else:return
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook43)
def setup43(c):
 setup42(dict(c,parentStates=c.get('parentStates',1),childStates=c.get('childStates',1),childFlags=6,childParameterMask=c.get('childParameterMask',15)));n.write(CATALOG43,bytes(0x584));n.pack('<I',CATALOG43+0x510,TOKEN43);n.write(FOLDER43,c.get('path','AI').encode('latin1')+b'\0');n.pack('<II',0x921ee8,0,0);n.pack('<II',SYS42+28,0,0);n.pack('<I',0x923874,c.get('warnings',0));n.pack('<I',0x922248,c.get('mode',0));n.pack('<II',CHILD42,0,0);n.pack('<II',PARENT42,0,0)
 if c.get('retry'):
  n.pack('<I',PARENT42+12,NAMES42+0x680);n.write(NAMES42+0x680,b'grand\0');n.pack('<I',PARENT42+60,6);n.write(GRAND43,bytes(0x58));n.pack('<I',GRAND43+8,NAMES42+0x680)
def execute43(c):
 global config,shadow,events,checks,catalogLine,parseOrdinal43
 config=c;setup43(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];catalogLine=-1;parseOrdinal43=0;archive=0 if c.get('nullArchive')else 0xaabbccdd;system=0 if c.get('globalMode')else SYS42;modelFault=False
 try:load43(archive,FOLDER43,TOP,BOTTOM,system)
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();events=[];catalogLine=-1;parseOrdinal43=0;nativeFault=False
 try:n.call(0x52c470,[archive,FOLDER43,TOP,BOTTOM,system],count=12000000)
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy()
 for group,a,b in[('fault',nativeFault,modelFault),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(archive=archive,path=FOLDER43,top=TOP,bottom=BOTTOM,system=system),initial=initial,fault=nativeFault,final=nf,nativeEvents=ne))
for globalMode,entry,memory,parser,mode,warnings in itertools.product([False,True],[0,0x55],[0,0x400],[0,CATALOG43],[0,1,2],[0,1,2]):execute43(dict(globalMode=globalMode,entry=entry,memoryHandle=memory,parser=parser,mode=mode,warnings=warnings))
for names,results in[([],[]),(['child'],[CHILD42]),(['parent'],[PARENT42]),(['child','parent'],[0,PARENT42]),(['child','parent'],[CHILD42,0]),(['already.scp',''],[CHILD42,PARENT42]),(['a'*15,'b'],[CHILD42,PARENT42])]:execute43(dict(names=names,results=results,nullArchive=True))
execute43(dict(names=['child','parent','grand'],results=[CHILD42,PARENT42,GRAND43],retry=True,nullArchive=True))
for path,handle in itertools.product(['','AI','C:\\Game\\AI'],[0,1]):execute43(dict(path=path,fileHandle=handle,nullArchive=True))
for patches in[{'Find':[[0x922248,4,1],[0x923874,4,1]]},{'OpenMemory':[[0x922248,4,2],[0x923874,4,2]]}]:execute43(dict(entry=0 if 'Find'in patches else 0x55,memoryHandle=0,patches=patches))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=1,abi='cdecl(archive,basePath,top,bottom,system)',ports=['archiveFind/Info/OpenMemory/Attach/OpenFile/FreeParser/Close','catalogline/token transport','52c320ParseScript compilerfilename normalized; actual513f20+copier children','unavailable6e69efCRTpath formatter normalized'])
(nm.BASE/'reports/script-phase43-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase43-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
