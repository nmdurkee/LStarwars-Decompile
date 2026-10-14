"""Actual5137a0→tablepush/rawfileline/token/ordereddispatch; only final I/O and command callbacks supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase26-20261013-verify.py').read_text().split('\nfiles=')[0])
from unicorn.x86_const import UC_X86_REG_ESI,UC_X86_REG_ECX
n=nm.NativeX86();FALLBACK=n.STOP+0xa00;SECONDARY=n.STOP+0xb00;secondaryTable=D+0x5700;commandOrdinal=0
commands=[]
for at in range(0x801720,0x801768,8):
 p,f=n.unpack('<II',at)
 if not p:break
 commands.append((p,f,native_text(p)))
segments+=[(0x801720,0x48),(0x91eec4,4)]+[(p,len(name)+1)for p,f,name in commands]

def command31(callback,model):
 global commandOrdinal
 commandOrdinal+=1;read=rd if model else lambda p:n.unpack('<I',p)[0];getText=lambda p:text(p)if model else native_text(p)
 events.append(dict(name='Command',callback=callback,parser=PARSER,token=getText(read(PARSER+0x510)),cursor=read(PARSER+0x520),globals=[read(p)for p in[0x922214,0x922218,0x92221c,0x92222c,0x922244]]))
 for p,size,v in config.get('patches',{}).get('Command#'+str(commandOrdinal),[]):
  if model:
   for i in range(size):wb(p+i,v>>(8*i))
  else:n.write(p,int(v).to_bytes(size,'little'))

def hook31(mu,address,size,data):
 if address==0x4fb550:hook26(mu,address,size,data)
 elif address in[f for p,f,name in commands]+[FALLBACK,SECONDARY]:
  sp=mu.reg_read(UC_X86_REG_ESP);assert n.unpack('<I',sp+4)[0]==PARSER;command31(address,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0x12345678);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook31)
def dispatch31():
 name=text(rd(PARSER+0x510))
 if not name or name[0]==';':return
 depth=rd(PARSER+0x570);depth=depth if depth<0x80000000 else depth-0x100000000
 if depth>=0:
  for table in[rd(PARSER+0x530+depth*4),rd(PARSER+0x550+depth*4)]:
   if not table:continue
   at=table
   while rd(at):
    if fold(text(rd(at)))==fold(name):command31(rd(at+4),True);return
    at+=8
 fallback=rd(0x91eec4)
 if fallback:command31(fallback,True)
def populate31(script):
 if not script:return
 wd(0x922214,TOP);wd(0x922218,BOTTOM);wd(0x92221c,script);wd(0x922244,0)
 depth=rd(PARSER+0x570);depth=depth if depth<0x80000000 else depth-0x100000000
 if depth<7:
  depth+=1;wd(PARSER+0x570,depth);wd(PARSER+0x530+depth*4,0x801720);wd(PARSER+0x550+rd(PARSER+0x570)*4,0)
 while nextline(True):token(True);wd(0x92222c,(script+64)&0xffffffff);dispatch31()
 for p in[0x922214,0x922218,0x92221c,0x92222c]:wd(p,0)

def execute31(c):
 global config,shadow,events,checks,stream,parameters,commandOrdinal
 config=c;setup26(c);n.pack('<I',0x91eec4,FALLBACK if c.get('fallback',True)else 0);n.pack('<I',PARSER+0x570,c.get('depth',-1)&0xffffffff)
 for i in range(8):n.pack('<II',PARSER+0x530+i*4,0x801720,0x801720)
 # Reset secondary words separately; previousline above intentionally shares same offsets onlywithin primary array.
 for i in range(8):n.pack('<I',PARSER+0x550+i*4,secondaryTable if c.get('secondary')else 0)
 n.write(secondaryTable+0x40,b'UNKNOWN\0');n.pack('<4I',secondaryTable,secondaryTable+0x40,SECONDARY,0,0)
 n.pack('<I',0x922244,0x87654321);n.pack('<I',0x92222c,0xabcdef01);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];stream=fresh_stream();parameters=dict(text=c['file'],chunk=c.get('chunk',4096),failAfter=c.get('failAfter',0x7fffffff),capacity=4096,binary=0);commandOrdinal=0;script=0 if c.get('nullScript')else SCRIPT;modelFault=False
 try:populate31(script)
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();ms=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0);events=[];stream=fresh_stream();commandOrdinal=0;nativeFault=False
 try:n.call(0x5137a0,[script],regs={UC_X86_REG_EAX:TOP,UC_X86_REG_ECX:BOTTOM,UC_X86_REG_ESI:PARSER},count=8000000)
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy();ns=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0)
 for group,a,b in[('fault',nativeFault,modelFault),('images',nf,mf),('events',ne,me),('stream',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(parser=PARSER,script=script,top=TOP,bottom=BOTTOM),initial=initial,fault=nativeFault,final=nf,nativeEvents=ne,nativeStream=ns))
files=['','\n',';comment\n','STATE alpha\nPARAM one 3\nCONST TWO 4\nCONDITIONMACRO M\nACTIONMACRO A\nREFERENCESCRIPT\nDERIVEFROMSCRIPT P\nINCLUDE F\n','state x\rPARAM y\r\nUnknown z\n','"STATE" "a b"\nUnknown ";quoted"\n','  ;comment\nUNKNOWN x\nSTATE x\n','\n\tPARAM \"\"\n;skip\n','STATE;comment\n','Unknown\n','STATE '+('x'*4050)+'\nPARAM q\n']
for file,chunk,depth in itertools.product(files,[1,17,4096],[-1,0,6,7]):execute31(dict(file=file,chunk=chunk,depth=depth))
for fallback,secondary,depth in itertools.product([False,True],[False,True],[-1,7]):execute31(dict(file='UNKNOWN\nSTATE x\n',fallback=fallback,secondary=secondary,depth=depth))
for failAfter in[0,1,4,12,17,4096]:execute31(dict(file='STATE x\nUNKNOWN\nPARAM y\n',chunk=1,failAfter=failAfter))
for c in[dict(file='STATE x\nPARAM y\n',nullScript=True),dict(file='STATE x\nPARAM y\n',patches={'Command#1':[[0x92222c,4,0],[0x922214,4,0],[0x922244,4,99]]}),dict(file='STATE x\nUNKNOWN\n',patches={'Command#1':[[0x91eec4,4,0]]}),dict(file='STATE x\nPARAM y\n',patches={'Command#1':[[TOKEN,1,33]]})]:execute31(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,ports=['4fb550filetransport','eight originalscript commandcallbacks plus fallback/secondary'],closure='5137a0 actual4f10e0/4fc5b0/4fc2d0/4f7fb0/4fa020')
(nm.BASE/'reports/script-phase31-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase31-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
