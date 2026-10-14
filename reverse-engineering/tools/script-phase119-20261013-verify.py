"""Original raw current-provider user/save accessors→actual append+normalizer. No hooks."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase97-20261013-verify.py').read_text().split('\npaths=')[0]);n=nm.NativeX86()
from unicorn.x86_const import UC_X86_REG_EAX
P=D+0x2000;SRC=D+0x400;DST=D+0x800;EXE=D+0x1000;G=0x800478;E=0x800470;segments=[(D,0x4000),(G,4),(E,4),(FLAG,4),(0x75ea58,4),(0x75a204,4)];cases=[];checks=0;errors=[]

def users119(source):
 provider=rd(G)
 if rb(source):copy96(provider+0x12c,source);append96(provider+0x12c,0x75a204)
 else:
  copy96(provider+0x12c,0x75ea58);exe=rd(E)+5;provider=rd(G);out=provider+0x12c+length96(provider+0x12c);budget=0
  while rb(exe)!=46:
   wb(out,rb(exe));exe+=1;out+=1;budget+=1
   if budget>1024:raise ValueError('filename firstdot required')
  wb(out,92);wb(out+1,0)
 provider=rd(G);normalize90(provider,provider+0x12c)

def saved119(source,seed):
 provider=rd(G)
 if not rb(source):wb(provider+0x1ac,0);return seed&0xffffff00
 copy96(provider+0x1ac,source);return append96(rd(G)+0x1ac,0x75a204)

def getSaved119(destination):
 copy96(destination,rd(G)+0x4c);append96(destination,rd(G)+0x1ac);provider=rd(G);normalize90(provider,destination+length96(provider+0x4c))

def run119(c):
 global shadow,checks
 for p,z in segments:
  if p not in[0x75ea58,0x75a204]:n.write(p,b'\xa5'*z)
 n.pack('<I',G,P);n.pack('<I',E,EXE);n.pack('<I',FLAG,c['preserve']);n.write(P+16,bytes([c['separator']]));n.write(P+76,c['base'].encode('ascii')+b'\0');n.write(P+0x12c,b'oldUser/\0');n.write(P+0x1ac,c['saved'].encode('ascii')+b'\0');n.write(EXE,c['exe'].encode('ascii')+b'\0');text=c['text'].encode('latin1');n.write(SRC,text+b'\0');src=SRC;dst=DST
 if c['alias']=='same':
  if c['method']=='GetSaved':dst=P+76
  else:src=P+(0x12c if c['method']=='SetUser'else 0x1ac);n.write(src,text+b'\0')
 if c['alias']=='before':
  if c['method']=='GetSaved':dst=P+76-16
  else:src=P+(0x12c if c['method']=='SetUser'else 0x1ac)+16;n.write(src,text+b'\0')
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};method=c['method'];want=None
 if method=='SetUser':users119(src)
 elif method=='SetSaved':want=saved119(src,c['seed'])
 else:getSaved119(dst)
 model=snap(True);actual=n.call({'SetUser':0x4f69a0,'SetSaved':0x4f6af0,'GetSaved':0x4f6a60}[method],[dst if method=='GetSaved'else src],regs={UC_X86_REG_EAX:c['seed']},count=4000000);final=snap()
 groups=[('images',final,model)]
 if want is not None:groups.append(('return',actual,want))
 for group,a,b in groups:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group=='return'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:8],model=b if group=='return'else'diff'))
 cases.append(dict(method=method,context=c,inputs=dict(source=src,destination=dst,seed=c['seed']),initial=initial,final=final,returnValue=actual if want is not None else None,observedNativeEax=actual))
for method,text,sep,preserve,alias in itertools.product(['SetUser','SetSaved','GetSaved'],['','folder','folder/','folder\\','MiXeD/x','x'*127],[0,47,92,255],[0,1],['none','same','before']):run119(dict(method=method,text=text,separator=sep,preserve=preserve,alias=alias,base='Base/',saved='Save/Sub/',exe='00000SW_GAME.exe',seed=0xffffffff))
for exe in['00000.exe','00000A.exe','00000LongNameGame.dat','12345MiXeD.Name.exe']:
 for sep in[47,92]:run119(dict(method='SetUser',text='',separator=sep,preserve=0,alias='none',base='',saved='',exe=exe,seed=0x12345678))
for base,saved in itertools.product(['','BASE/', 'a'*127],['','save/','b'*128]):run119(dict(method='GetSaved',text='',separator=92,preserve=0,alias='none',base=base,saved=saved,exe='00000a.exe',seed=0))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,rawEntryConsumers=['0x4f69a0','0x4f6a60','0x4f6af0'],ports=[],closure='Whole raw user187byte/savegetter136byte/savesetter71byte accessors→real4f1e80append/4efdf0normalizer; explicitignored-return projection foruser/getter, nohooks')
(nm.BASE/'reports/script-phase119-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase119-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
