"""Original52c320 customregister filewrapper; parseoutlocalnormalized, actualstatefind/compare children."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase28-20261013-verify.py').read_text().split('\nfor flags,cached')[0])
n=nm.NativeX86();PARSE=0x52bcb0;context29=0x12345678;archive29=0xabcdef01;parsedScript=SCOPED
segments+=[(0x92223c,8)]
def parse_port(args,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];events.append(dict(name='Parse',args=args,globals=[read(0x92223c),read(0x922240)]))
 for p,size,v in config.get('parsePatches',[]):
  if model:
   for i in range(size):wb(p+i,v>>(i*8))
  else:n.write(p,int(v).to_bytes(size,'little'))
 return config.get('returnedScript',SCOPED)
def hook29(mu,address,size,data):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==PARSE:
  output,context,fileName,archive,top,bottom=n.unpack('<6I',sp+4);result=parse_port([context,fileName,archive,top,bottom],False);n.pack('<I',output,result);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address in [0x512850,0x512860]:ret=n.unpack('<I',sp)[0];count=2 if ret in[0x52c41d,0x52c42c]else 3;diag(address,list(n.unpack('<'+'I'*count,sp+4)),False)
n.mu.hook_add(UC_HOOK_CODE,hook29)
def finalize29(context,archive,fileName,top,bottom):
 wd(0x92223c,archive);wd(0x922240,context);script=parse_port([context,fileName,archive,top,bottom],True);wd(0x92223c,0);wd(0x922240,0)
 if not script:return 0
 state=rd(script+16)
 while state:
  node=rd(state+8)
  while node:
   result=findstate(rd(node+32),script);name=rd(node+32);wd(node+36,result)
   if name and not result:diag(0x512860 if rd(0x922248)==1 else 0x512850,[name,rd(script+8),rd(state+24)],True)
   node=rd(node)
  other=rd(state)
  while other:
   if fold(text(rd(state+24),True))==fold(text(rd(other+24),True)):diag(0x512860 if rd(0x922248)==1 else 0x512850,[rd(state+24),rd(script+8)],True)
   other=rd(other)
  state=rd(state)
 return script

def execute29(c):
 global config,shadow,events,checks
 config=c;setup28(c);n.pack('<II',0x92223c,0x87654321,0x13572468)
 for i in range(3):node=CONDS+i*0x40;n.pack('<I',node+32,0 if c.get('nullTarget')else names[c.get('targetKey','base')]);n.pack('<I',node+36,0xdeadbeef)
 if c.get('duplicate'):n.pack('<I',STATES+0x80+24,names['base'])
 if c.get('empty'):n.pack('<I',SCOPED+16,0)
 if c.get('thirdState'):n.pack('<I',STATES+0x80,STATES+0x100);n.pack('<I',STATES+0x100+4,STATES+0x80);n.pack('<I',STATES+0x100+24,names['base'])
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];context=c.get('context',context29);archive=c.get('archive',archive29);fileName=names['scope'];top=SYS+0x1a00;bottom=top+4;want=0;modelFault=False
 try:want=finalize29(context,archive,fileName,top,bottom)
 except(KeyError,ValueError):modelFault=True
 modelFinal=snapshot(True);modelEvents=events.copy();events=[];nativeFault=False;got=0
 try:got=n.call(0x52c320,[fileName,top,bottom],regs={UC_X86_REG_EAX:archive,UC_X86_REG_ECX:context})
 except RuntimeError:nativeFault=True
 nativeFinal=snapshot();nativeEvents=events.copy()
 for group,a,b in [('fault',nativeFault,modelFault),('return',got if not nativeFault else 0,want if not modelFault else 0),('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(context=context,archive=archive,fileName=fileName,top=top,bottom=bottom),initial=initial,fault=nativeFault,returnValue=got if not nativeFault else 0,final=nativeFinal,nativeEvents=nativeEvents))
for mode,target,duplicate,nullTarget,third in itertools.product([0,1,2],['base','other','missing'],[False,True],[False,True],[False,True]):execute29(dict(mode=mode,targetKey=target,duplicate=duplicate,nullTarget=nullTarget,thirdState=third))
for returned in [0,SCOPED,GLOBAL,0x30000000]:execute29(dict(returnedScript=returned))
for context,archive in itertools.product([0,1,0xffffffff],[0,1,0xffffffff]):execute29(dict(context=context,archive=archive,empty=True))
for c in [dict(parsePatches=[[0x92223c,4,0],[0x922240,4,0xffffffff]]),dict(parsePatches=[[CONDS+32,4,names.get('missing',STRINGS+0x800)]]),dict(parsePatches=[[SCOPED+16,4,0]]),dict(parsePatches=[[0x922248,4,1]],targetKey='missing')]:execute29(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),abi='EAXarchive/ECXcontext,cdecl(fileName,top,bottom);52bcb0sixargs*out normalized',remainingPorts=['52bcb0 scriptfileparser;52c320 ownbody actual'],managedExecution=False)
(nm.BASE/'reports/script-phase29-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase29-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
