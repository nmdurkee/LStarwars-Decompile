"""Original513400 customEDIarchive/ESIfilename/cdeclpath; archiveinfo/memoryhandle/parser/fallback leaves normalized."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
n=nm.NativeX86();segments=[(D,0x10000),(0x922248,4),(0x923874,4)];FILE44=D+0x3000;PATH44=D+0x3200;archive44=0xaabbccdd

def provider44(name,args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];events.append(dict(name=name,args=args,globals=[read(0x922248),read(0x923874)]))
 for p,size,v in config.get('patches',{}).get(name,[]):
  if model:
   for i in range(size):wb(p+i,v>>(8*i))
  else:n.write(p,int(v).to_bytes(size,'little'))
 return {'Find':config.get('entry',0x55),'Information':[config.get('data',D+0x8000),config.get('length',17)],'OpenMemory':config.get('memoryHandle',0x400),'AttachParser':config.get('attached',D+0x4000),'OpenFileParser':config.get('fallback',D+0x4800)}[name]
def open44(basePath,archive,fileName):
 name=text(fileName)
 if '.SCP'not in fold(name):return 0
 path=text(basePath)+'\\'+name
 if archive:
  entry=provider44('Find',[archive,fileName],True)
  if entry:
   data,length=provider44('Information',[archive,entry],True);handle=provider44('OpenMemory',[data,length,0],True)
   if handle:return provider44('AttachParser',[handle],True)
   events.append(dict(name='Diagnostic',callback=0x512870,args=[fileName]))
  else:events.append(dict(name='Diagnostic',callback=0x512870 if rd(0x922248)==1 else 0x512850,args=[fileName]))
  if rd(0x923874):events.append(dict(name='Diagnostic',callback=0x512860 if rd(0x922248)==1 else 0x512850,args=[fileName]))
 return provider44('OpenFileParser',[path],True)
def hook44(mu,address,size,data):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x6e69ef:
  dest,fmt,pathPtr,namePtr=n.unpack('<4I',sp+4);payload=(native_text(pathPtr)+chr(92)+native_text(namePtr)).encode('latin1');n.write(dest,payload+b'\0');value=len(payload)
 elif address==0x4f9de0:value=provider44('Find',list(n.unpack('<II',sp+4)),False)
 elif address==0x4f0f30:
  archive,entry,outData,outLength=n.unpack('<4I',sp+4);ptr,length=provider44('Information',[archive,entry],False);n.pack('<I',outData,ptr);n.pack('<I',outLength,length);value=0
 elif address==0x4f02d0:value=provider44('OpenMemory',list(n.unpack('<3I',sp+4)),False)
 elif address==0x4fc750:value=provider44('AttachParser',list(n.unpack('<I',sp+4)),False)
 elif address==0x4fc860:value=provider44('OpenFileParser',[native_text(n.unpack('<I',sp+4)[0])],False)
 elif address in[0x512850,0x512860,0x512870]:events.append(dict(name='Diagnostic',callback=address,args=list(n.unpack('<I',sp+4))));return
 else:return
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook44)
def execute44(c):
 global config,shadow,events,checks
 config=c;n.write(D,bytes(0x10000));n.write(FILE44,c.get('fileName','root.scp').encode('latin1')+b'\0');n.write(PATH44,c.get('path','AI').encode('latin1')+b'\0');n.pack('<I',0x922248,c.get('mode',0));n.pack('<I',0x923874,c.get('warnings',0));initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];archive=0 if c.get('nullArchive')else archive44;want=open44(PATH44,archive,FILE44);mf=snapshot(True);me=events.copy();events=[];got=n.call(0x513400,[PATH44],regs={UC_X86_REG_EDI:archive,UC_X86_REG_ESI:FILE44});nf=snapshot();ne=events.copy()
 for group,a,b in[('return',got,want),('images',nf,mf),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(path=PATH44,archive=archive,fileName=FILE44),initial=initial,returnValue=got,final=nf,nativeEvents=ne))
for name,archive in itertools.product(['root.scp','ROOT.SCP','a.ScP.extra','.scp','root','','root.sc','x.scp.scp','\xe0.scp'],[False,True]):execute44(dict(fileName=name,nullArchive=not archive))
for entry,memory,attached,mode,warnings in itertools.product([0,0x55],[0,0x400],[0,D+0x4000],[0,1,2],[0,1,0xffffffff]):execute44(dict(entry=entry,memoryHandle=memory,attached=attached,mode=mode,warnings=warnings))
for path,name in itertools.product(['','AI','C:\\Game\\AI','p'*60],['root.scp','x'*59+'.scp']):
 if len(path)+1+len(name)<128:execute44(dict(path=path,fileName=name,nullArchive=True))
for patches in[{'Find':[[0x922248,4,1],[0x923874,4,1]]},{'OpenMemory':[[0x922248,4,2],[0x923874,4,0xffffffff]]},{'AttachParser':[[0x922248,4,3]]}]:execute44(dict(entry=0 if 'Find'in patches else 0x55,memoryHandle=0 if 'OpenMemory'in patches else 0x400,patches=patches))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,abi='customEDIarchive/ESIoriginalfilename,cdecl(basePath);EAXparser',ports=['4f9de0Find/4f0f30Information/4f02d0OpenMemory/4fc750Attach/4fc860OpenFileParser'],semanticCorrection='52c320 EAXbasePath/ECXarchive;92223cbasePath/922240archive; legacy earlier archive/context labels positionalopaque')
(nm.BASE/'reports/script-phase44-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase44-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
