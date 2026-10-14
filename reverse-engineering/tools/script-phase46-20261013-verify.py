"""Actualcatalog→provider→pool/BOMattach→rawfiles/allcommands/INCLUDE→inheritance; finalIO only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase40-20261013-verify.py').read_text().split('\nfirst=actions')[0])
source41=Path(__file__).with_name('script-phase41-20261013-verify.py').read_text();exec(source41[source41.index('\ndef copy_macro'):source41.index('\ndef hook41')])
source42=Path(__file__).with_name('script-phase42-20261013-verify.py').read_text();exec(source42[source42.index('\ndef names_equal42'):source42.index('\ndef hook42')])
source45=Path(__file__).with_name('script-phase45-20261013-verify.py').read_text();exec(source45[source45.index('\ndef zero45'):source45.index('\ndef hook45')])
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_EDI,UC_X86_REG_ESI
n=nm.NativeX86();FOLDER46=D+0x2900;SYS46=D+0x1800;NAME46=0x1000c000;PATH46=0x1000c100;files46={};handles46={};io46=[];segments+=[(0x91eebc,8),(0x917850,0x1610),(0x8cab50,0x4000),(0x923874,4),(0x921ee8,8),(0x760448,11)];selected45=0

def final46(name,args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];string=lambda p:text(p)if model else native_text(p)
 if name=='Find':
  archive,p=args;key=string(p);io46.append(dict(name=name,args=[archive,key]));return next((i+1 for i,k in enumerate(files46)if fold(k)==fold(key)),0)if not config.get('archiveMiss')else 0
 if name=='Information':
  archive,entry=args;key=list(files46)[entry-1];io46.append(dict(name=name,args=args));return [D+0x30000+(entry-1)*0x1000,len(files46[key]['text'])]
 if name=='OpenMemory':
  data,length,mode=args;key=list(files46)[(data-D-0x30000)//0x1000];value=files46[key]['archiveHandle'];files46[key]['position']=0;handles46[value]=key;io46.append(dict(name=name,args=args,result=value));return value
 if name in ['Open','CatalogOpen','Exists']:
  p=args[0];value=string(p)if isinstance(p,int)else p;key=value.split(chr(92))[-1];key=next((k for k in files46 if fold(k)==fold(key)),None);result=0 if key is None else 1 if name=='Exists'else files46[key]['handle'];io46.append(dict(name=name,args=[value]+args[1:],result=result))
  if result and name!='Exists':files46[key]['position']=0;handles46[result]=key
  return result
 if name=='Close':io46.append(dict(name=name,args=args));return 0
 if name=='Size':value=len(files46[handles46[args[0]]]['text']);io46.append(dict(name=name,args=args,result=value));return value
 if name=='Seek':files46[handles46[args[0]]]['position']=args[1];io46.append(dict(name=name,args=args));return 0
 raise ValueError(name)
def bytes46(handle,requested):
 row=files46[handles46[handle]];pos=row['position'];data=row['text'].encode('latin1');count=min(requested,config.get('chunk',4096),max(0,len(data)-pos));row['position']+=count;io46.append(dict(name='Read',args=[handle,requested],position=pos,count=count));return data[pos:pos+count]
def read46(image,p,s,args):
 payload=bytes46(args[0],args[2]);image.write(args[1],payload);return len(payload)
lines.read_file=read46
def nextline(model):return lines.line(Image(),dict(binary=0,capacity=512),{})
def port45(name,args,model):
 if name=='Prefix':payload=bytes46(args[0],2);return int.from_bytes(payload+b'\0'*(2-len(payload)),'little')
 if name=='Byte':payload=bytes46(args[0],1);return payload[0]if payload else 0
 return final46(name,args,model)
def temp46(p,value,use):
 payload=value.encode('latin1')+b'\0'
 for i,b in enumerate(payload):shadow[p+i]=b
 try:
  start=len(events);result=use(p)
  for event in events[start:]:
   if event.get('name')=='Diagnostic':event['args']=[text(a)if 0x10000000<=a<0x10010000 else a for a in event['args']]
  return result
 finally:
  for i in range(len(payload)):shadow.pop(p+i)
def provider40(name,args,model):
 if name=='OpenParser':basePath,archive,fileName=args;nameText=text(fileName);path=text(basePath)+chr(92)+nameText
 else:
  if name=='CloseParser':return close45(args[0])
  return final46({'CloseHandle':'Close','Reopen':'Open','Seek':'Seek'}[name],args,model)
 if '.SCP'not in fold(nameText):return 0
 if archive:
  entry=final46('Find',[archive,fileName],True)
  if entry:
   data,length=final46('Information',[archive,entry],True);handle=final46('OpenMemory',[data,length,0],True)
   if handle:return attach45(handle)
   events.append(dict(name='Diagnostic',callback=0x512870,args=[fileName]))
  else:events.append(dict(name='Diagnostic',callback=0x512870 if rd(0x922248)==1 else 0x512850,args=[fileName]))
  if rd(0x923874):events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[fileName]))
 return temp46(PATH46,path,openfile45)
def load46(archive,path,top,bottom,system):
 handle=0;fallback=not archive;names=[]
 if archive:
  entry=final46('Find',[archive,0x760448],True)
  if entry:
   data,length=final46('Information',[archive,entry],True);handle=final46('OpenMemory',[data,length,0],True)
   if not handle:events.append(dict(name='Diagnostic',callback=0x512870,args=[]));fallback=True
  else:events.append(dict(name='Diagnostic',callback=0x512870 if rd(0x922248)==1 else 0x512850,args=[]));fallback=True
  if fallback and rd(0x923874)==1:events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[]))
 if fallback:handle=final46('CatalogOpen',[text(path)+chr(92)+'script.txt',0],True)
 if handle:
  parser=attach45(handle)
  if parser:
   active40(parser)
   while nextline(True):next_count();names.append(text(rd(parser+0x510))+'.scp')
   wd(parser,0)
  final46('Close',[handle],True)
 for name in names:
  script=temp46(NAME46,name,lambda p:finalize40(archive,path,p,top,bottom))
  if script:
   append36(system+28 if system else 0x921ee8,script)
   if system:wd(script+60,rd(script+60)|1)
 if system:
  for i in range(16):
   done=True;script=rd(system+28)
   while script:
    if not apply42(script,top,bottom,system):done=False
    script=rd(script)
   if done:return
  raise ValueError('preparedcycle')
def hook46(mu,address,size,data):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x6e69ef:
  dest,fmt,folder=n.unpack('<3I',sp+4);payload=native_text(folder)+chr(92)+('script.txt'if native_text(fmt)=='%s\\script.txt'else native_text(n.unpack('<I',sp+16)[0]));n.write(dest,payload.encode('latin1')+b'\0');value=len(payload)
 elif address==0x4f9de0:value=final46('Find',list(n.unpack('<2I',sp+4)),False)
 elif address==0x4f0f30:archive,entry,outData,outLength=n.unpack('<4I',sp+4);p,z=final46('Information',[archive,entry],False);n.pack('<I',outData,p);n.pack('<I',outLength,z);value=0
 elif address==0x4f02d0:value=final46('OpenMemory',list(n.unpack('<3I',sp+4)),False)
 elif address in[0x4fa5f0,0x4fa3f0,0x4ff120,0x4f99e0,0x4f6de0,0x4f6b40]:name,count={0x4fa5f0:('CatalogOpen',2),0x4fa3f0:('Open',4),0x4ff120:('Exists',1),0x4f99e0:('Close',1),0x4f6de0:('Seek',4),0x4f6b40:('Size',1)}[address];value=final46(name,list(n.unpack('<'+'I'*count,sp+4)),False)
 elif address==0x4fb550:handle,buffer,count=n.unpack('<3I',sp+4);payload=bytes46(handle,count);n.write(buffer,payload);value=len(payload)
 elif address in[CB,0x512850,0x512860,0x512870,0x4ef790]:
  if address==CB:hook37(mu,address,size,data);return
  ret=n.unpack('<I',sp)[0]
  if 0x52c470<=ret<0x52c6d0:count=0
  elif 0x513400<=ret<0x513540:count=1
  elif 0x513f20<=ret<0x514140:count=2 if ret in[0x514107,0x514126]else 3 if ret in[0x5140b7,0x5140be]else 0
  else:
   start=len(events);hook40(mu,address,size,data)
   for event in events[start:]:
    if event.get('name')=='Diagnostic':event['args']=[native_text(a)if 0x10000000<=a<0x10010000 else a for a in event['args']]
   return
  events.append(dict(name='Diagnostic',callback=address,args=[native_text(a)if 0x10000000<=a<0x10010000 else a for a in list(n.unpack('<'+'I'*count,sp+4))]));return
 else:return
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook46)
def reset46(c):
 global files46,handles46,io46
 files46={k:dict(text=v,position=0,handle=0x12345678+i,archiveHandle=0x400+i)for i,(k,v)in enumerate(c['files'].items())};handles46={};io46=[]
def setup46(c):
 setup40(dict(c,file='',bankSize=0x6000));n.write(0x917850,bytes(0x1610));n.write(0x8cab50,bytes(0x4000));n.pack('<II',0x91eebc,0,0);n.write(FOLDER46,b'AI\0');n.write(SYS46,bytes(0x30));n.pack('<II',0x921ee8,0,0);n.pack('<I',0x923874,0);n.pack('<I',0x91ee88,0xabcdef01)
def state46():return dict(positions={k:v['position']for k,v in files46.items()},io=io46.copy())
def execute46(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal
 config=c;setup46(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c);system=0 if c.get('globalMode')else SYS46;archive=0xaabbccdd if c.get('archive')else 0;modelFault=False
 try:load46(archive,FOLDER46,TOP,BOTTOM,system)
 except(KeyError,ValueError)as error:modelFault=str(error)
 mf=snapshot(True);me=events.copy();ms=state46();events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c);nativeFault=False
 try:n.call(0x52c470,[archive,FOLDER46,TOP,BOTTOM,system],count=24000000)
 except RuntimeError as error:nativeFault=str(error)
 nf=snapshot();ne=events.copy();ns=state46()
 for group,a,b in [('fault',bool(nativeFault),bool(modelFault)),('images',nf,mf),('events',ne,me),('files',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b,nativeFault=nativeFault,modelFault=modelFault))
 cases.append(dict(context=c,inputs=dict(archive=archive,path=FOLDER46,top=TOP,bottom=BOTTOM,system=system),initial=initial,fault=bool(nativeFault),final=nf,nativeEvents=ne,nativeFiles=ns))
first=actions[0]['name']
base='PARAM 0 alpha 3\nCONST LIMIT 2\nSTATE BASE\nCONDITIONS\nIF Timer > LIMIT goto BASE\n}\nACTIONS\n'+first+' one two\n}\n}\n'
child='DERIVEFROMSCRIPT\nScript=parent Source=Level\n}\nSTATE child\n}\n'
include='INCLUDE extra.scp\nSTATE root\n}\n'
scenarios=[{'script.txt':''},{'script.txt':'root\n','root.scp':base},{'script.txt':'child\nparent\n','child.scp':child,'parent.scp':base},{'script.txt':'root\n','root.scp':include,'extra.scp':base},{'script.txt':'root\nmissing\n','root.scp':'STATE BASE\n}\n'},{'script.txt':'child\nparent\ngrand\n','child.scp':child,'parent.scp':'DERIVEFROMSCRIPT\nScript=grand Source=Level\n}\n','grand.scp':base}]
for files,chunk,archive,globalMode in itertools.product(scenarios,[1,17,4096],[False,True],[False,True]):execute46(dict(files=files,chunk=chunk,archive=archive,globalMode=globalMode,callback=True))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,ports=['finalarchive/fileIO','CRTboundedpathformatter','symbolcallback'],closure='52c470→513400→4f1240/4fc750/4fc860→52c320/52bcb0/fullcommands/INCLUDE→513f20/513cc0')
(nm.BASE/'reports/script-phase46-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase46-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
