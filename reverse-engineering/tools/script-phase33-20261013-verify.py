"""Original STATE producer, nested actualline/token/dispatch/tablepop; final nested producers supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase32-20261013-verify.py').read_text().split('\nfor slot,name')[0])
n=nm.NativeX86();stateCommands=[]
for at in range(0x8016f4,0x80171c,8):
 p,f=n.unpack('<II',at)
 if not p:break
 stateCommands.append((p,f,native_text(p)))
segments+=[(0x8016f4,0x2c),(0x753270,5)]+[(p,len(name)+1)for p,f,name in stateCommands];EXISTING=D+0x6000

def pop33():
 depth=rd(PARSER+0x570);depth=depth if depth<0x80000000 else depth-0x100000000
 if depth>=0:depth-=1;wd(PARSER+0x570,depth&0xffffffff)
 return depth&0xffffffff

def push33(table):
 depth=rd(PARSER+0x570);depth=depth if depth<0x80000000 else depth-0x100000000
 if depth<7:depth+=1;wd(PARSER+0x570,depth);wd(PARSER+0x530+depth*4,table);wd(PARSER+0x550+rd(PARSER+0x570)*4,0)
def leaf33(callback,model):
 global commandOrdinal
 commandOrdinal+=1;read=rd if model else lambda p:n.unpack('<I',p)[0];getText=lambda p:text(p)if model else native_text(p)
 events.append(dict(name='Command',callback=callback,parser=PARSER,token=getText(read(PARSER+0x510)),cursor=read(PARSER+0x520),globals=[read(p)for p in[0x922214,0x922218,0x92221c,0x92222c,0x922244]],stateGlobals=[read(p)for p in[0x922220,0x922230,0x922234]]))
 for p,size,v in config.get('patches',{}).get('Command#'+str(commandOrdinal),[]):
  if model:
   for i in range(size):wb(p+i,v>>(8*i))
  else:n.write(p,int(v).to_bytes(size,'little'))
def state33():
 if not rd(0x92221c):return
 if not next_count():return
 bottom=rd(0x922218);top=rd(0x922214);state=0
 if top and bottom and((rd(top)+36)&0xffffffff)<rd(bottom):
  state=(rd(top)+15)&0xfffffff0;wd(top,(state+36)&0xffffffff)
  for i in range(36):wb(state+i,0)
 else:events.append(dict(name='Diagnostic',callback=0x512850,args=[]))
 wd(0x922220,state);wd(0x92222c,(state+28)&0xffffffff)
 if not state:return
 for i in range(36):wb(state+i,0)
 name=copy_string(top,rd(PARSER+0x510),bottom);wd(rd(0x922220)+24,name);current=rd(0x922220);listp=rd(0x92221c)+16
 if name and fold(text(name))=='BASE':
  head=rd(listp);wd(current,head);wd(current+4,0)
  if head:wd(head+4,current)
  else:wd(listp+4,current)
  wd(listp,current)
 else:
  tail=rd(listp+4);wd(current,0);wd(current+4,tail)
  if tail:wd(tail,current)
  else:wd(listp,current)
  wd(listp+4,current)
 push33(0x8016f4)
 while nextline(True):token(True);live=rd(0x922220);wd(0x922230,(live+8)&0xffffffff);wd(0x922234,(live+16)&0xffffffff);dispatch31()
 pop33()
 for p in[0x92222c,0x922220,0x922230,0x922234]:wd(p,0)
def command31(callback,model):
 if callback==0x513540:state33()
 elif callback==0x5133f0:pop33()
 elif callback==0x5136c0:parameter32()
 elif callback==0x513730:constant32()
 else:leaf33(callback,model)
def hook33(mu,address,size,data):
 if address==0x4fb550:hook26(mu,address,size,data)
 elif address in[f for p,f,name in commands+stateCommands if f not in[0x513540,0x5133f0,0x5136c0,0x513730]]+[FALLBACK,SECONDARY]:
  sp=mu.reg_read(UC_X86_REG_ESP);leaf33(address,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0x12345678);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x512850:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];count=0 if ret==0x5135ba else 1;events.append(dict(name='Diagnostic',callback=address,args=list(n.unpack('<'+'I'*count,sp+4))))
n.mu.hook_add(UC_HOOK_CODE,hook33)
def execute33(c,method='State'):
 global config,shadow,events,checks,stream,parameters,commandOrdinal
 config=c;setup26(c);n.pack('<I',0x91eec4,FALLBACK if c.get('fallback',True)else 0);n.pack('<I',0x922244,0);n.pack('<I',0x92221c,0 if c.get('nullScript')else SCRIPT);n.pack('<I',TOP,BANK+c.get('alignment',0));n.pack('<I',BOTTOM,BANK+c.get('bankSize',0x4000));n.pack('<I',PARSER+0x570,c.get('depth',0)&0xffffffff)
 for i in range(8):n.pack('<I',PARSER+0x530+i*4,0x801720);n.pack('<I',PARSER+0x550+i*4,0)
 n.pack('<II',SCRIPT+16,EXISTING if c.get('existing')else 0,EXISTING if c.get('existing')else 0);n.write(EXISTING,bytes(0x80));n.pack('<I',EXISTING+24,NAMES+0x1800);n.write(NAMES+0x1800,b'existing\0')
 if method=='State':n.write(RAWLINE,c.get('line','base').encode('latin1')+b'\0');n.write(TOKEN,b'STATE\0');n.pack('<I',PARSER+0x520,0)
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];stream=fresh_stream();parameters=dict(text=c['file'],chunk=c.get('chunk',4096),failAfter=c.get('failAfter',0x7fffffff),capacity=4096,binary=0);commandOrdinal=0;modelFault=False;want=0
 try:
  if method=='Pipeline':populate31(SCRIPT)
  elif method=='Pop':want=pop33()
  else:state33()
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();ms=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0);events=[];stream=fresh_stream();commandOrdinal=0;nativeFault=False;got=0
 try:
  if method=='Pipeline':n.call(0x5137a0,[SCRIPT],regs={UC_X86_REG_EAX:TOP,UC_X86_REG_ECX:BOTTOM,UC_X86_REG_ESI:PARSER},count=8000000)
  else:
   got=n.call(0x4f11e0 if method=='Pop'else 0x513540,[PARSER],count=8000000)
   if method!='Pop':got=0
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy();ns=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0)
 for group,a,b in[('fault',nativeFault,modelFault),('return',0 if nativeFault else got,0 if modelFault else want),('images',nf,mf),('events',ne,me),('stream',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(parser=PARSER,script=SCRIPT,top=TOP,bottom=BOTTOM),initial=initial,fault=nativeFault,returnValue=0 if nativeFault else got,final=nf,nativeEvents=ne,nativeStream=ns))
for name,existing,align,file in itertools.product(['BASE','base','other','\xe0State','"a b"','""',''],[False,True],[0,1,15],['','CONDITIONS\nACTIONS\nREFERENCESCRIPT\n}\n']):execute33(dict(line=name,existing=existing,alignment=align,file=file))
for bankSize,align in itertools.product([0,36,37,40,48,49,64],[0,1,7,15]):execute33(dict(file='',bankSize=bankSize,alignment=align))
for depth,chunk in itertools.product([-1,0,6,7],[1,17,4096]):execute33(dict(file='CONDITIONS\n}\n',depth=depth,chunk=chunk))
files=['STATE first\n}\nSTATE BASE\n}\n','PARAM 0 alpha 1\nCONST VALUE 2\nSTATE alpha\nCONDITIONS\nACTIONS\nREFERENCESCRIPT\n}\nSTATE BASE\n}\n','STATE first\nUNKNOWN\n}\nCONST NUM 3\n','STATE \"\"\nPARAM 1 beta -0\n','STATE '+('x'*512)+'\n}\n']
for file,chunk in itertools.product(files,[1,17,4096]):execute33(dict(file=file,chunk=chunk,depth=-1),'Pipeline')
for c in[dict(file='',nullScript=True),dict(file='CONDITIONS\nACTIONS\n',patches={'Command#1':[[0x922220,4,EXISTING],[0x92222c,4,0]]}),dict(file='CONDITIONS\nACTIONS\n',patches={'Command#1':[[0x922230,4,0],[0x922234,4,0]]}),dict(file='}\nSTATE BASE\n}\n',existing=True)]:execute33(c)
for depth in[-2,-1,0,1,7,8,0x7fffffff,-2147483648]:execute33(dict(file='',depth=depth),'Pop')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,methods={method:sum(r['method']==method for r in cases)for method in['Pipeline','State','Pop']},ports=['4fb550 rawfile bytes','remaining state/script producers exceptSTATE/PARAM/CONST/popthunk'],newEntries=3)
(nm.BASE/'reports/script-phase33-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase33-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
