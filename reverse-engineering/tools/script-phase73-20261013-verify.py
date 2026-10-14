"""Actual archive catalog through raw memory transport allocation/read/seek/size/close, all builtin binding/runtime. Archive metadata alone supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase69-20261013-verify.py').read_text().split('\ntable=')[0])
def signed(v):return v-0x100000000 if v&0x80000000 else v
TABLE=0x2983740;LOCAL73=0x1000b000;segments +=[(TABLE,400),(D+0x30000,0x8000)]
s71=Path(__file__).with_name('script-phase71-20261013-verify.py').read_text();exec(s71[s71.index('\ndef open71'):s71.index('\ndef setup71')])
s72=Path(__file__).with_name('script-phase72-20261013-verify.py').read_text();exec(s72[s72.index('\ndef sext'):s72.index('\ndef size72')]);exec(s72[s72.index('\ndef seek72'):s72.index('\ndef hook72')])
metadata73=final46
def final46(name,args,model):
 if name=='OpenMemory':return open71(*args)
 if name=='Close':return close72(args[0])
 if name=='Seek':return seek72(*args)
 if name=='Size':slot=TABLE+(args[0]-0x400)*20;return(rd(slot+4)-rd(slot))&0xffffffff
 if name in['Find','Information']:return metadata73(name,args,model)
 raise ValueError('Unexpected finalfile/OS path '+name)
def localread73(handle,count):
 for i in range(count):shadow[LOCAL73+i]=0
 try:
  read=read71(handle,LOCAL73,count);return read,sum(rb(LOCAL73+i)<<(8*i)for i in range(count))
 finally:
  for i in range(count):shadow.pop(LOCAL73+i)
def port45(name,args,model):
 if name=='Prefix':return localread73(args[0],2)[1]
 if name=='Byte':count,value=localread73(args[0],1);return(count&0xffffff00)|value
 return final46(name,args,model)
def read73(image,p,s,args):return read71(args[0],args[1],args[2])
lines.read_file=read73
n=nm.NativeX86()
def hook73(mu,address,size,data):
 if address in[0x6e69ef,0x4f9de0,0x4f0f30,CB,0x512850,0x512860,0x512870,0x4ef790]:hook46(mu,address,size,data)
 if address in[0x4fa5f0,0x4fa3f0,0x4ff120,0x6dee50,0x6dee40]:raise ValueError('Unexpectedfilesystem/CRT call '+hex(address))
n.mu.hook_add(UC_HOOK_CODE,hook73)
def execute73(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal
 config=c;setup69(c);n.write(TABLE,bytes(400));n.write(D+0x30000,bytes(0x8000))
 for i,payload in enumerate(c['files'].values()):n.write(D+0x30000+i*0x1000,payload.encode('latin1'))
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c);archive=0xaabbccdd
 load46(archive,FOLDER46,TOP,BOTTOM,SYS69);bindsystem(SYS69);script=rd(SYS69+28);idle=rd(script+56);assert script and idle;bind(PACKET69,script,idle,0);result=evaluate69(0,SYS69,idle+8,ACTOR69,PACKET69);model=snapshot(True);me=events.copy();ms=state46();events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c)
 n.call(0x52c470,[archive,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);scriptN=n.unpack('<I',SYS69+28)[0];n.call(0x5143a0,[SYS69],count=6000000);idleN=n.unpack('<I',scriptN+56)[0];n.call(0x514640,[SYS69,ACTOR69,PACKET69,0,0,0,0,scriptN,idleN]);nativeResult=n.call(0x52c880,[SYS69,idleN+8,ACTOR69,PACKET69],regs={UC_X86_REG_EAX:0},count=4000000);final=snapshot();ne=events.copy();ns=state46()
 for group,a,b in [('images',final,model),('return',nativeResult,result),('events',ne,me),('metadata',ns,ms)]:
  checks+=1
  if a!=b:
   e=dict(group=group,context=c)
   if group=='images':e['differences']=[dict(address=x['address'],native=x['bytes'],model=y['bytes'])for x,y in zip(a,b)if x!=y][:2]
   else:e.update(native=a,model=b)
   errors.append(e)
 cases.append(dict(context=c,inputs=dict(archive=archive,path=FOLDER46,top=TOP,bottom=BOTTOM,system=SYS69,actor=ACTOR69,packet=PACKET69),initial=initial,final=final,returnValue=nativeResult,script=scriptN,state=idleN,nativeEvents=ne,nativeFiles=ns))
table=json.loads((nm.BASE/'reports/script-phase24-20261013-native-fixtures.json').read_text())['builtinPredicates']
for row,bom in itertools.product(table,[False,True]):
 arg=' 1'if row['name']in['AlwaysTrue','Param']else ' missing'if row['words'][2]else '';body='STATE BASE\nCONDITIONS\nIF '+row['name']+arg+' > 0 goto TARGET\n}\n}\nSTATE TARGET\n}\n';prefix='\xef\xbb\xbf'if bom else '';execute73(dict(predicate=row['name'],files={'script.txt':prefix+'root\n','root.scp':prefix+body},bom=bom,archive=True,chunk=4096,seed=0x12345678,callback=True))
first=actions[0]['name'];base='PARAM 0 alpha 3\nCONST LIMIT 2\nSTATE BASE\nCONDITIONS\nIF Timer > LIMIT goto BASE\n}\nACTIONS\n'+first+' one two\n}\n}\n';child='DERIVEFROMSCRIPT\nScript=parent Source=Level\n}\nSTATE child\n}\n';include='INCLUDE extra.scp\nSTATE root\n}\n';scenarios=[{'script.txt':'root\n','root.scp':base},{'script.txt':'child\nparent\n','child.scp':child,'parent.scp':base},{'script.txt':'root\n','root.scp':include,'extra.scp':base},{'script.txt':'child\nparent\ngrand\n','child.scp':child,'parent.scp':'DERIVEFROMSCRIPT\nScript=grand Source=Level\n}\n','grand.scp':base}]
for files,bom in itertools.product(scenarios,[False,True]):
 prefix='\xef\xbb\xbf'if bom else '';execute73(dict(predicate='catalogscenario',files={k:prefix+v for k,v in files.items()},bom=bom,archive=True,chunk=4096,seed=0x12345678,callback=True))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,descriptorRows=len(table),ports=['archiveFind4f9de0','archiveInformation4f0f30','CRTboundedpathformatter6e69ef'],closure='Actualcatalog→provider→4f02d0/4fb550/4fb4f0/4f6de0/4f6c70/4f6b40/4f99e0/4f6bc0→fullfile/INCLUDE/inheritance→allbuiltin initializer/packetbind/runtime')
(nm.BASE/'reports/script-phase73-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase73-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
