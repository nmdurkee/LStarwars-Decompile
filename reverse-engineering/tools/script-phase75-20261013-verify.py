"""Actual archive catalog through raw memory transport allocation/read/seek/size/close, all builtin binding/runtime. Archive metadata alone supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase73-20261013-verify.py').read_text().split('\ntable=')[0])
ARCH75=D+0x50000;ERROR=0x91eeb8;INFO75=0x1000a000;segments +=[(ARCH75,0x3000),(ERROR,4)]
s74=Path(__file__).with_name('script-phase74-20261013-verify.py').read_text();exec(s74[s74.index('\ndef fold74'):s74.index('\ndef execute74')])
memory73=final46
def final46(name,args,model):
 if name=='Find':return find74(*args)
 if name=='Information':
  for i in range(8):shadow[INFO75+i]=0
  try:
   assert information74(args[0],args[1],INFO75,INFO75+4)==1
   return[rd(INFO75),rd(INFO75+4)]
  finally:
   for i in range(8):shadow.pop(INFO75+i)
 return memory73(name,args,model)
n=nm.NativeX86()
def hook75(mu,address,size,data):
 if address in[0x6e69ef,CB,0x512850,0x512860,0x512870,0x4ef790]:hook46(mu,address,size,data)
 if address in[0x4fa5f0,0x4fa3f0,0x4ff120,0x6dee50,0x6dee40]:raise ValueError('Unexpectedfilesystem/CRT path '+hex(address))
n.mu.hook_add(UC_HOOK_CODE,hook75)
def execute75(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal
 config=c;setup69(c);n.write(TABLE,bytes(400));n.write(D+0x30000,bytes(0x8000));n.write(ARCH75,bytes(0x3000));n.pack('<I',ERROR,0xabcdef01);n.pack('<II',ARCH75,c['magic'],len(c['files']));first=ARCH75+(12 if c['magic']==0x12345678 else 24 if c['magic']==0x1234567a else 20)
 for i,(name,payload)in enumerate(c['files'].items()):
  data=D+0x30000+i*0x1000;namep=ARCH75+0x1000+i*0x100;n.write(data,payload.encode('latin1'));n.write(namep,name.encode('latin1')+b'\0');n.pack('<7I',first+i*28,namep-ARCH75,(data-ARCH75)&0xffffffff,len(payload),0,0,0,0)
 initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c);archive=ARCH75
 load46(archive,FOLDER46,TOP,BOTTOM,SYS69);bindsystem(SYS69);script=rd(SYS69+28);idle=rd(script+56);assert script and idle;bind(PACKET69,script,idle,0);result=evaluate69(0,SYS69,idle+8,ACTOR69,PACKET69);model=snapshot(True);me=events.copy();ms=state46();events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c)
 n.call(0x52c470,[archive,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);scriptN=n.unpack('<I',SYS69+28)[0];n.call(0x5143a0,[SYS69],count=6000000);idleN=n.unpack('<I',scriptN+56)[0];n.call(0x514640,[SYS69,ACTOR69,PACKET69,0,0,0,0,scriptN,idleN]);nativeResult=n.call(0x52c880,[SYS69,idleN+8,ACTOR69,PACKET69],regs={UC_X86_REG_EAX:0},count=4000000);final=snapshot();ne=events.copy();ns=state46()
 for group,a,b in [('images',final,model),('return',nativeResult,result),('events',ne,me),('adapterTrace',ns,ms)]:
  checks+=1
  if a!=b:
   e=dict(group=group,context=c)
   if group=='images':e['differences']=[dict(address=x['address'],native=x['bytes'],model=y['bytes'])for x,y in zip(a,b)if x!=y][:2]
   else:e.update(native=a,model=b)
   errors.append(e)
 cases.append(dict(context=c,inputs=dict(archive=archive,path=FOLDER46,top=TOP,bottom=BOTTOM,system=SYS69,actor=ACTOR69,packet=PACKET69),initial=initial,final=final,returnValue=nativeResult,script=scriptN,state=idleN,nativeEvents=ne,nativeFiles=ns))
table=json.loads((nm.BASE/'reports/script-phase24-20261013-native-fixtures.json').read_text())['builtinPredicates'];magics=[0x12345678,0x1234567a,0x12345679]
for row,magic in itertools.product(table,magics):
 arg=' 1'if row['name']in['AlwaysTrue','Param']else ' missing'if row['words'][2]else '';body='STATE BASE\nCONDITIONS\nIF '+row['name']+arg+' > 0 goto TARGET\n}\n}\nSTATE TARGET\n}\n';execute75(dict(predicate=row['name'],files={'script.txt':'root\n','root.scp':body},bom=False,magic=magic,archive=True,chunk=4096,seed=0x12345678,callback=True))
first=actions[0]['name'];base='PARAM 0 alpha 3\nCONST LIMIT 2\nSTATE BASE\nCONDITIONS\nIF Timer > LIMIT goto BASE\n}\nACTIONS\n'+first+' one two\n}\n}\n';child='DERIVEFROMSCRIPT\nScript=parent Source=Level\n}\nSTATE child\n}\n';include='INCLUDE extra.scp\nSTATE root\n}\n';scenarios=[{'script.txt':'root\n','root.scp':base},{'script.txt':'child\nparent\n','child.scp':child,'parent.scp':base},{'script.txt':'root\n','root.scp':include,'extra.scp':base},{'script.txt':'child\nparent\ngrand\n','child.scp':child,'parent.scp':'DERIVEFROMSCRIPT\nScript=grand Source=Level\n}\n','grand.scp':base}]
for files,bom,magic in itertools.product(scenarios,[False,True],magics):
 prefix='\xef\xbb\xbf'if bom else '';execute75(dict(predicate='catalogscenario',files={k:prefix+v for k,v in files.items()},bom=bom,magic=magic,archive=True,chunk=4096,seed=0x12345678,callback=True))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,descriptorRows=len(table),archiveHeaderLayouts=3,ports=['CRTboundedpathformatter6e69ef'],closure='ActualrawarchiveFind/Info→memoryOpen/read/seek/size/close→catalog/file/INCLUDE/inheritance→allbuiltin init/bind/runtime; archive/file/memory IO adapters absent')
(nm.BASE/'reports/script-phase75-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase75-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
