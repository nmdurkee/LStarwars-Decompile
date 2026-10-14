"""Actual filesystem catalog/file parsing and builtin bind/runtime through complete game I/O, finalOS and bounded CRT formatting only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase69-20261013-verify.py').read_text().split('\ntable=json.loads')[0]);catalogSegments=segments.copy()
exec(Path(__file__).with_name('script-phase98-20261013-verify.py').read_text().split('\nfor data,buffered')[0]);ioSegments=segments.copy()
#All private source projections live outside captured public data, just as original compiler stack locals.
FILENAME=0x10009000;BOMTEMP=0x1000a000;LOCAL=0x1000b000;LOCAL97=0x10008000;PROVIDER=D+0x90000;segments=list(dict.fromkeys(catalogSegments+ioSegments+[(PROVIDER,0x234)]));cases=[];checks=0;errors=[];hostFiles={};hostOrdinal=0
#The original formatter and helpers execute; no provider-format hook exists.
def key99(name):
 last=bytes.fromhex(name).decode('latin1').split('\\')[-1]
 return next((k for k in config['files']if k.upper()==last.upper()),None)
def resetHost99():
 global hostFiles,hostOrdinal,seekOrdinal
 hostFiles={};hostOrdinal=0;seekOrdinal=0

def port94(name,args,model):
 global hostOrdinal
 events.append(dict(name=name,args=args))
 if name=='CreateFile':
  key=key99(args[0])
  if key is None:return 0xffffffff
  hostOrdinal+=1;handle=0xbeef0000+hostOrdinal;hostFiles[handle]=dict(key=key,position=0,closed=False);return handle
 if name=='CloseHandle':hostFiles[args[0]]['closed']=True;return 1
 return 0

def seekValue94(args,model):
 global seekOrdinal
 port94('SetPointer',args,model);seekOrdinal+=1;handle,low,high,origin=args;row=hostFiles[handle];offset=low|(high<<32);position=(offset if origin==0 else row['position']+offset if origin==1 else len(config['files'][row['key']])+offset)&((1<<64)-1);row['position']=position;return[position&0xffffffff,position>>32]
def api76(name,args,model):
 if name=='SetFilePointerEx':return 1,seekValue94(args,model)
 handle,destination,count,overlapped=args;normal='private'if model and destination==BOMTEMP or not model and n.STACK<=destination<n.STACK+0x10000 else destination;port94('ReadFile',[handle,normal,count,overlapped],model);row=hostFiles[handle];payload=config['files'][row['key']].encode('latin1');pos=row['position'];chosen=min(count,config.get('chunk',4096),max(0,len(payload)-pos));data=payload[pos:pos+chosen]
 if model:
  for i,b in enumerate(data):wb(destination+i,b)
 else:n.write(destination,data)
 row['position']+=chosen;return 1,chosen

def final46(name,args,model):
 assert model
 if name=='CatalogOpen':return temp46(PATH46,args[0],lambda p:gameOpen94(p,args[1],rd(OPTIONS),0))
 if name=='Open':return gameOpen94(*args)
 if name=='Exists':return exists95(args[0])
 if name=='Close':return publicClose95(args[0])
 if name=='Seek':return publicSeek95(*args)
 if name=='Size':return rd((0x8ceb28+(args[0]<<6))&0xffffffff)
 raise ValueError('Unexpected archive final port '+name)
def read46(image,p,s,args):return reader77(args[0],args[1],args[2])
lines.read_file=read46
#Original catalog helper diagnostics and bounded sprintf retain their established leaf contracts.
def hook99(mu,address,size,data):
 if address in[0x6e69ef,CB,0x512850,0x512860,0x512870,0x4ef790]:hook46(mu,address,size,data)
n.mu.hook_add(UC_HOOK_CODE,hook99)
def setup99(c):
 setup69(c);n.pack('<I',OPTIONS,0);n.pack('<I',BUFFERFLAG,c.get('buffered',7));n.pack('<I',FLAG,0);n.pack('<I',PCOUNT,0);n.pack('<I',DEFAULT,PROVIDER);n.write(PROVIDER,bytes(0x234));n.write(PROVIDER+16,b'\\');n.pack('<I',PROVIDER+0x22c,0x4ff130);n.write(0x75c044,b':\0\0\0');n.write(0x75ebd8,b';1\0\0');n.pack('<I',COUNTER,5)
 for i in range(64):n.pack('<I',0x8007a0+i*4,0xffffffff)
 n.write(STREAMS,bytes(4096));n.write(POOL,bytes(0x1020))
 for i in range(4):n.pack('<I',POOL+i*0x408+4,i+1)
def execute99(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal,selected45
 config=c;setup99(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 for p,z in[(FILENAME,256),(BOMTEMP,2),(LOCAL,256),(LOCAL97,512)]:
  for i in range(z):shadow[p+i]=0
 load46(0,FOLDER46,TOP,BOTTOM,SYS69);bindsystem(SYS69);script=rd(SYS69+28);assert script;idle=rd(script+56);assert idle;bind(PACKET69,script,idle,0);result=evaluate69(0,SYS69,idle+8,ACTOR69,PACKET69);model=snapshot(True);me=events.copy();mh={k:dict(v)for k,v in hostFiles.items()};events=[];symbolOrdinal=0;commandOrdinal=0;selected45=0;resetHost99()
 n.call(0x52c470,[0,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);scriptN=n.unpack('<I',SYS69+28)[0];n.call(0x5143a0,[SYS69],count=6000000);idleN=n.unpack('<I',scriptN+56)[0];n.call(0x514640,[SYS69,ACTOR69,PACKET69,0,0,0,0,scriptN,idleN]);nativeResult=n.call(0x52c880,[SYS69,idleN+8,ACTOR69,PACKET69],regs={UC_X86_REG_EAX:0},count=4000000);final=snapshot();ne=events.copy();nh=hostFiles.copy()
 for group,a,b in [('images',final,model),('return',nativeResult,result),('events',ne,me),('hostFiles',nh,mh)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[x for x,y in zip(a,b)if x!=y][:1],model=b if group!='images'else[y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(context=c,inputs=dict(archive=0,path=FOLDER46,top=TOP,bottom=BOTTOM,system=SYS69,actor=ACTOR69,packet=PACKET69),initial=initial,final=final,returnValue=nativeResult,script=scriptN,state=idleN,nativeEvents=ne,hostFiles={str(k):v for k,v in nh.items()}))
table=json.loads((nm.BASE/'reports/script-phase24-20261013-native-fixtures.json').read_text())['builtinPredicates']
for row,buffered,chunk in itertools.product(table,[0,7],[17]):
 arg=' 1'if row['name']in['AlwaysTrue','Param']else' missing'if row['words'][2]else'';body='STATE BASE\nCONDITIONS\nIF '+row['name']+arg+' > 0 goto TARGET\n}\n}\nSTATE TARGET\n}\n';execute99(dict(predicate=row['name'],files={'script.txt':'root\n','root.scp':body},archive=False,chunk=chunk,seed=0x12345678,callback=True,buffered=buffered))
first=actions[0]['name'];base='PARAM 0 alpha 3\nCONST LIMIT 2\nSTATE BASE\nCONDITIONS\nIF Timer > LIMIT goto BASE\n}\nACTIONS\n'+first+' one two\n}\n}\n';child='DERIVEFROMSCRIPT\nScript=parent Source=Level\n}\nSTATE child\n}\n';include='INCLUDE extra.scp\nSTATE root\n}\n';scenarios=[{'script.txt':'root\n','root.scp':base},{'script.txt':'child\nparent\n','child.scp':child,'parent.scp':base},{'script.txt':'root\n','root.scp':include,'extra.scp':base},{'script.txt':'child\nparent\ngrand\n','child.scp':child,'parent.scp':'DERIVEFROMSCRIPT\nScript=grand Source=Level\n}\n','grand.scp':base}]
for files,bom,buffered in itertools.product(scenarios,[False,True],[0,7]):
 prefix='\xef\xbb\xbf'if bom else'';execute99(dict(predicate='catalogscenario',files={k:prefix+v for k,v in files.items()},archive=False,chunk=17,seed=0x12345678,callback=True,buffered=buffered,bom=bom))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=0,ports=['CreateFile','SetFilePointerEx','ReadFile','CloseHandle','boundedCRTcatalogFormatter','establishedScriptDiagnostics'],closure='Filesystem catalog/file/parser/fullbuiltin init/bind/runtime through complete recovered gameI/O and default provider, finalplatform/CRTformat/diagnostic leaves only')
(nm.BASE/'reports/script-phase99-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase99-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
