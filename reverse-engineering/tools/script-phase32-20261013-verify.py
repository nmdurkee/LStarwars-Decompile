"""Original PARAM/CONST producers with actual token/numeric/bank children; unwrapped4f7fb0 EAX count."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase31-20261013-verify.py').read_text().split('\nfiles=')[0])
import inspect
countns=dict(tokens.__dict__);exec(inspect.getsource(tokens.next_token).replace('def next_token','def next_count')+'\n return count\n',countns);numbers=module('scalar_numbers','native-text-numbers-verify.py');remainingCommand=command31
n=nm.NativeX86()
def next_count():return countns['next_count'](Image())
def parameter32():
 if not rd(0x92221c):return
 next_count();name=text(rd(PARSER+0x510));slot=numbers.hexadecimal(name[1:])if name.startswith('$')else numbers.hexadecimal(name[2:])if name[:2].lower()=='0x'else numbers.decimal(name)
 if slot>3:return
 if not next_count():return
 result=copy_string(rd(0x922214),rd(PARSER+0x510),rd(0x922218));wd(rd(0x92221c)+24+slot*8,result);next_count();value=numbers.real(text(rd(PARSER+0x510)));wd(rd(0x92221c)+28+slot*8,value)
def constant32():
 current=rd(PARSER+0x510)
 if len(text(current))>=31:events.append(dict(name='Diagnostic',callback=0x512850,args=[rd(PARSER+0x510)]))
 next_count();source=rd(PARSER+0x510);target=(0x9220f0+rd(0x922244)*36)&0xffffffff
 for i in range(32):
  b=0 if i==31 else rb(source+i)
  wb(target+i,b)
  if not b:break
 next_count();value=numbers.real(text(rd(PARSER+0x510)));count=rd(0x922244);wd((0x922110+count*36)&0xffffffff,value);wd(0x922244,(count+1)&0xffffffff)
def command31(callback,model):
 if callback==0x5136c0:parameter32()
 elif callback==0x513730:constant32()
 else:remainingCommand(callback,model)
def hook32(mu,address,size,data):
 if address==0x4fb550:hook26(mu,address,size,data)
 elif address in[f for p,f,name in commands if f not in[0x5136c0,0x513730]]+[FALLBACK,SECONDARY]:hook31(mu,address,size,data)
 elif address==0x512850:sp=mu.reg_read(UC_X86_REG_ESP);events.append(dict(name='Diagnostic',callback=address,args=[n.unpack('<I',sp+4)[0]]))
n.mu.hook_add(UC_HOOK_CODE,hook32)
def execute32(c,method='Pipeline'):
 global config,shadow,events,checks,stream,parameters,commandOrdinal
 config=c;setup26(c);n.pack('<I',0x91eec4,0);n.pack('<I',0x922244,c.get('constantCount',0));n.pack('<I',0x92221c,0 if c.get('nullScript')else SCRIPT);n.pack('<I',TOP,BANK+c.get('alignment',0));n.pack('<I',BOTTOM,BANK+c.get('bankSize',0x4000))
 if method!='Pipeline':n.write(RAWLINE,c.get('line','').encode('latin1')+b'\0');n.write(TOKEN,c.get('current',method.upper()).encode('latin1')+b'\0');n.pack('<I',PARSER+0x520,0)
 if method=='Token':n.pack('<I',PARSER+0x518,c.get('capacity',512));n.pack('<I',PARSER+0x57c,SINGLES+0x80);n.write(SINGLES+0x80,c.get('separators','').encode('latin1')+b'\0');n.write(SINGLES,c.get('singles','{}').encode('latin1')+b'\0')
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];stream=fresh_stream();parameters=dict(text=c['file'],chunk=c.get('chunk',4096),failAfter=c.get('failAfter',0x7fffffff),capacity=4096,binary=0);commandOrdinal=0;want=0;modelFault=False
 try:
  if method=='Pipeline':populate31(SCRIPT)
  elif method=='Parameter':parameter32()
  elif method=='Constant':constant32()
  else:want=next_count()
 except(KeyError,ValueError):modelFault=True
 mf=snapshot(True);me=events.copy();ms=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0);events=[];stream=fresh_stream();commandOrdinal=0;nativeFault=False;got=0
 try:
  if method=='Pipeline':n.call(0x5137a0,[SCRIPT],regs={UC_X86_REG_EAX:TOP,UC_X86_REG_ECX:BOTTOM,UC_X86_REG_ESI:PARSER},count=8000000)
  else:
   got=n.call({'Parameter':0x5136c0,'Constant':0x513730,'Token':0x4f7fb0}[method],[PARSER],count=8000000)
   if method!='Token':got=0
 except RuntimeError:nativeFault=True
 nf=snapshot();ne=events.copy();ns=dict(position=stream['position'],events=stream['events'].copy(),binaryCalls=0)
 for group,a,b in[('fault',nativeFault,modelFault),('return',0 if nativeFault else got,0 if modelFault else want),('images',nf,mf),('events',ne,me),('stream',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(parser=PARSER,script=SCRIPT,top=TOP,bottom=BOTTOM),initial=initial,fault=nativeFault,returnValue=0 if nativeFault else got,final=nf,nativeEvents=ne,nativeStream=ns))
for slot,name,value in itertools.product(['0','1','2','3','4','-1','$3','0x2','4294967296',''],['value','""','a\xe0Name','"a b"'],['-0','.5','1.23456789','-12.25']):execute32(dict(file='',line=slot+' '+name+' '+value),'Parameter')
for name,value,count in itertools.product(['a','','""','q'*31,'z'*32,'s'*47,'\xe0Name'],['-0','12.375','+2','1e3'],[0,1,7,8]):execute32(dict(file='',line=name+' '+value,constantCount=count),'Constant')
for current in['x'*30,'x'*31,'x'*32]:execute32(dict(file='',line='a 3',current=current),'Constant')
for bankSize,align in itertools.product([0,1,5,6,7,16],[0,1,7,15]):execute32(dict(file='',line='1 value 2',bankSize=bankSize,alignment=align),'Parameter')
for nullScript in[False,True]:execute32(dict(file='',line='2 value -0',nullScript=nullScript),'Parameter')
for file,chunk in itertools.product(['PARAM 0 alpha 1.5\nPARAM 3 beta -0\nCONST A 2.25\nCONST B -.5\n','CONST abc 3\nPARAM 1 \"a b\" 9\n','PARAM 4 skip 8\nCONST VALUE +2\n','PARAM 0 \"\" 7\nCONST \"\" 3\n','PARAM $2 '+('x'*512)+' 3.75\n'],[1,17,4096]):execute32(dict(file=file,chunk=chunk))
for line,capacity,singles,sep in itertools.product(['',' ','a','""','"a b"','a""b','='+'a','x'*511,'y'*512,'z'*513,'w'*1025],[1,2,7,31,512],['{}','=',','],['',';']):execute32(dict(file='',line=line,capacity=capacity,singles=singles,separators=sep),'Token')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,methods={method:sum(r['method']==method for r in cases)for method in['Pipeline','Parameter','Constant','Token']},ports=['4fb550 rawfile bytes','remaining sixscriptcommands; actualPARAM/CONST ownbodies andparser/numbers/stringbank'],newEntries=2)
(nm.BASE/'reports/script-phase32-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase32-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
