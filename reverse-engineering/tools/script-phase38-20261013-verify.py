"""Original derivation statement and INCLUDE wrapper; include child file/lifecycle leaves supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase37-20261013-verify.py').read_text().split('\nfor row in actions')[0])
n=nm.NativeX86();prior38=command31;includeOrdinals={}
def port38(name,args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];includeOrdinals[name]=includeOrdinals.get(name,0)+1;events.append(dict(name=name,args=args,globals=[read(p)for p in[0x922214,0x922218,0x92221c,0x92222c,0x922244]]))
 for p,size,value in config.get('includePatches',{}).get(name+'#'+str(includeOrdinals[name]),[]):
  if model:
   for i in range(size):wb(p+i,value>>(8*i))
  else:n.write(p,int(value).to_bytes(size,'little'))
 if name=='Parse':
  value=config.get('includedScript',SCRIPT)
  if model:wd(args[0],value)
  else:n.pack('<I',args[0],value)
def include38():
 bottom=rd(0x922218);script=rd(0x92221c);top=rd(0x922214);next_count();port38('Suspend',[PARSER],True);b=rd(0x922218);t=rd(0x922214);archive=rd(0x92223c);name=rd(PARSER+0x510);context=rd(0x922240);port38('Parse',[0x92221c,context,name,archive,t,b],True);port38('Resume',[PARSER],True);wd(0x922214,top);wd(0x92221c,script);wd(0x922218,bottom)
def derive38():
 script=rd(0x92221c)
 if not script or rd(script+12):return
 wd(script+60,rd(script+60)&0xfffffffb);stop=False
 while not stop and nextline(True):
  while next_count():
   ptr=rd(PARSER+0x510);name=text(ptr)
   if fold(name)=='}':stop=True;break
   found=fold(name).find('SCRIPT')
   if found>=0:
    bottom=rd(0x922218);top=rd(0x922214);parent=operand35((ptr+found+7)&0xffffffff,top,bottom);wd(rd(0x92221c)+12,parent);continue
   if 'SOURCE'in fold(name):
    if 'GLOBAL'in fold(name):p=rd(0x92221c)+60;wd(p,rd(p)&0xfffffffb)
    elif 'LEVEL'in fold(name):p=rd(0x92221c)+60;wd(p,rd(p)|4)
 script=rd(0x92221c)
 if rd(script+12):wd(script+60,rd(script+60)|2)
def command31(callback,model):
 if callback==0x513820:derive38()
 elif callback==0x52bf80:include38()
 else:prior38(callback,model)
def hook38(mu,address,size,data):
 if address in[0x4fa2c0,0x4fa810,0x52bcb0]:
  sp=mu.reg_read(UC_X86_REG_ESP);name={0x4fa2c0:'Suspend',0x4fa810:'Resume',0x52bcb0:'Parse'}[address];args=list(n.unpack('<'+'I'*(6 if name=='Parse'else 1),sp+4));port38(name,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x512850 and n.unpack('<I',mu.reg_read(UC_X86_REG_ESP))[0]==0x5138f2:diag36()
 elif address in[0x513820,0x52bf80]:pass
 else:hook37(mu,address,size,data)
n.mu.hook_add(UC_HOOK_CODE,hook38)
def execute38(c,method='Derive'):
 global config,shadow,events,checks,stream,parameters,commandOrdinal,includeOrdinals
 config=c;setup26(dict(c,flags=0));n.pack('<I',0x91eec4,FALLBACK if c.get('fallback',True)else 0);n.pack('<I',0x922244,0x13572468);n.pack('<I',TOP,BANK+c.get('alignment',0));n.pack('<I',BOTTOM,BANK+c.get('bankSize',0x4000));n.pack('<II',TOP+8,BANK+0x100,BANK+0x2000);n.pack('<I',SCRIPT+12,NAMES+0x1900 if c.get('existingParent')else 0);n.write(NAMES+0x1900,b'oldParent\0');n.pack('<I',SCRIPT+60,c.get('flags',0));n.pack('<I',0x92221c,0 if c.get('nullScript')else SCRIPT);n.pack('<I',PARSER+0x570,c.get('depth',-1)&0xffffffff);n.pack('<II',0x92223c,0xabcdef01,0x12345678)
 if c.get('nullTop'):n.pack('<I',0x922214,0)
 if c.get('nullBottom'):n.pack('<I',0x922218,0)
 if method=='Include':n.write(RAWLINE,c.get('line','extra.scp').encode('latin1')+b'\0');n.write(TOKEN,b'INCLUDE\0');n.pack('<I',PARSER+0x520,0)
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];stream=fresh_stream();parameters=dict(text=c['file'],chunk=c.get('chunk',4096),failAfter=c.get('failAfter',0x7fffffff),capacity=4096,binary=0);commandOrdinal=0;includeOrdinals={};modelFault=False
 try:
  if method=='Pipeline':populate31(SCRIPT)
  elif method=='Include':include38()
  else:derive38()
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();ms=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0);events=[];stream=fresh_stream();commandOrdinal=0;includeOrdinals={};nativeFault=False
 try:
  if method=='Pipeline':n.call(0x5137a0,[SCRIPT],regs={UC_X86_REG_EAX:TOP,UC_X86_REG_ECX:BOTTOM,UC_X86_REG_ESI:PARSER},count=8000000)
  else:n.call(0x52bf80 if method=='Include'else 0x513820,[PARSER],count=8000000)
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy();ns=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0)
 for group,a,b in[('fault',nativeFault,modelFault),('images',nf,mf),('events',ne,me),('stream',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(parser=PARSER,script=SCRIPT,top=TOP,bottom=BOTTOM),initial=initial,fault=nativeFault,final=nf,nativeEvents=ne,nativeStream=ns))
for file,flags,chunk in itertools.product(['Script=parent Source=Global\n}\n','Script=parent Source=Level\n}\n','Source=Level Source=Global Script=parent\n}\n','Source=Global Source=Level Script=parent\n}\n','Script=first Script=second Source=GlobalLevel\n}\n','Script=\n}\n','Source=Level\n}\n','xxScript=parent\n}\n','}\n'],[0,2,4,7,0xffffffff],[1,4096]):execute38(dict(file=file,flags=flags,chunk=chunk))
for size,align in itertools.product([0,1,7,8,16,32],[0,1,15]):execute38(dict(file='Script=parent\n}\n',bankSize=size,alignment=align))
for c in[dict(file='Script=parent\n}\n',existingParent=True,flags=7),dict(file='Script=parent\n}\n',nullScript=True),dict(file='Script=parent\n}\n',nullTop=True),dict(file='Script=parent\n}\n',nullBottom=True)]:execute38(c)
for line,returned in itertools.product(['extra.scp','"two words.scp"','""',''],[0,SCRIPT,SCRIPT+0x100]):execute38(dict(file='',line=line,includedScript=returned),'Include')
for patches in[{'Suspend#1':[[0x922214,4,TOP+8],[0x922218,4,TOP+12],[0x92223c,4,0],[0x922240,4,0xffffffff]]},{'Parse#1':[[TOP,4,BANK+0x300],[0x922214,4,0],[0x922218,4,0],[0x92222c,4,0],[0x922244,4,7]]},{'Resume#1':[[0x922214,4,0],[0x922218,4,0],[0x92221c,4,0],[0x922244,4,88]]}]:execute38(dict(file='',includePatches=patches),'Include')
for file,chunk in itertools.product(['DERIVEFROMSCRIPT\nScript=parent Source=Level\n}\nINCLUDE extra.scp\nPARAM 0 alpha 2\nSTATE BASE\nCONDITIONS\nIF Timer > 1\n}\nACTIONS\n'+actions[0]['name']+' token\n}\n}\n','DERIVEFROMSCRIPT\nScript=parent\n}\nDERIVEFROMSCRIPT\nScript=other\n}\nSTATE BASE\n}\n'],[1,17,4096]):execute38(dict(file=file,chunk=chunk),'Pipeline')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,methods={method:sum(r['method']==method for r in cases)for method in['Pipeline','Derive','Include']},newEntries=2,ports=['4fb550finalfilebytes','9238c0gamesymbol','4fa2c0Suspend,52bcb0nestedfileparser,4fa810Resume forINCLUDE'])
(nm.BASE/'reports/script-phase38-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase38-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
