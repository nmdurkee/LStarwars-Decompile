"""Loaded catalog -> complete builtin binding -> actual52cc90 dispatcher/ref scanner/condition runtime, prepared action-free world."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase69-20261013-verify.py').read_text().split('\ntable=')[0])
spec70=importlib.util.spec_from_file_location('w70',Path(__file__).with_name('animation-x87.py'));w70=importlib.util.module_from_spec(spec70);spec70.loader.exec_module(w70)
inert_port69=port69
def port69(name,args,model):
 if name=='Predicate'and args[0]==0x514990:return rd(args[2]+0x24)
 return inert_port69(name,args,model)
def tick70(system,actor,packet,dt):
 old=rd(packet+0x24);x,y=fl(old),fl(dt);value=bits(w70.store(w70.add(w70.wide(x),w70.wide(y))))if x or y else old&dt&0x80000000;wd(packet+0x24,value)
 assert not rd(packet+0x64)and not rd(packet+0x10)and not rd(packet+0xc)
 script=rd(packet+4);state=rd(packet+8);assert script and state and not rd(script+0x40)and not rd(state+0x1c)
 match=evaluate69(0,system,state+8,actor,packet)
 if match:
  message=rw(match+0xe);flags=rd(packet+0x50);wd(packet+0x50,flags^(((message*2)^flags)&4));enter_script(packet,rd(match+0x24))
def execute70(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal
 config=c;setup69(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c);archive=0xaabbccdd if c['archive']else 0
 load46(archive,FOLDER46,TOP,BOTTOM,SYS69);bindsystem(SYS69);script=rd(SYS69+28);idle=rd(script+56);bind(PACKET69,script,idle,0);modelStages=[]
 for delta in c['deltaBits']:tick70(SYS69,ACTOR69,PACKET69,delta);modelStages.append(snapshot(True))
 me=events.copy();ms=state46();events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c);n.call(0x52c470,[archive,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);scriptN=n.unpack('<I',SYS69+28)[0];n.call(0x5143a0,[SYS69],count=6000000);idleN=n.unpack('<I',scriptN+56)[0];n.call(0x514640,[SYS69,ACTOR69,PACKET69,0,0,0,0,scriptN,idleN]);nativeStages=[]
 for delta in c['deltaBits']:n.call(0x52cc90,[SYS69,ACTOR69,ACTOR69,PACKET69,delta],count=6000000);nativeStages.append(snapshot())
 ne=events.copy();ns=state46()
 for i,(a,b)in enumerate(zip(nativeStages,modelStages)):
  checks+=1
  if a!=b:errors.append(dict(group='tick'+str(i),context=c,differences=[dict(address=x['address'],native=x['bytes'],model=y['bytes'])for x,y in zip(a,b)if x!=y][:2]))
 for group,a,b in [('events',ne,me),('files',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(archive=archive,path=FOLDER46,top=TOP,bottom=BOTTOM,system=SYS69,actor=ACTOR69,packet=PACKET69),initial=initial,final=nativeStages[-1],script=scriptN,initialState=idleN,finalState=n.unpack('<I',PACKET69+8)[0],nativeEvents=ne,nativeFiles=ns))
table=json.loads((nm.BASE/'reports/script-phase24-20261013-native-fixtures.json').read_text())['builtinPredicates']
for row,archive,deltas in itertools.product(table,[False,True],[[0,0],[bits(0.016),bits(0.016)],[bits(-0.016),bits(0.016)]]):
 arg=' 1'if row['name']in ['AlwaysTrue','Param']else ' missing'if row['words'][2]else ''
 body='STATE BASE\nCONDITIONS\nIF '+row['name']+arg+' > 0 goto TARGET\n}\n}\nSTATE TARGET\n}\n'
 execute70(dict(predicate=row['name'],files={'script.txt':'root\n','root.scp':body},archive=archive,chunk=4096,seed=0x12345678,callback=True,deltaBits=deltas))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,descriptorRows=len(table),tickCalls=sum(len(c['context']['deltaBits'])for c in cases),ports=['finalarchive/fileIO','CRTboundedpathformatter'],closure='Loadedcatalog→5143a0/all14initializers→514640→52cc90→actual52caf0/52c880/all48predicates/5145a0 state entry; no runtime adapters')
(nm.BASE/'reports/script-phase70-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase70-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
