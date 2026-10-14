"""Actual catalog/file parsing -> all builtin initialization -> packet bind -> actual condition evaluation. Prepared empty world; final IO only."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase46-20261013-verify.py').read_text().split('\nfirst=actions')[0])
SYS69=D+0x70000;ACTOR69=D+0x72000;PACKET69=D+0x73000;CTRL69=D+0x74000;P=PACKET69
segments += [(SYS69,0x1500),(ACTOR69,0x400),(PACKET69,0x100),(CTRL69,0x400),(0x753270,5),(0x757734,5),(0x923904,8),(0x95e5d4,4),(0x75ecf0,4),(0x760008,8),(0x760010,4)]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
old_text69=text
def text(p,model=True):return old_text69(p)if model else native_text(p)
s28=Path(__file__).with_name('script-phase28-20261013-verify.py').read_text();exec(s28[s28.index('\ndef findstate'):s28.index('\ndef defaultinit')]);exec(s28[s28.index('\ndef unlink'):s28.index('\ndef setup28')])
s18=Path(__file__).with_name('script-phase18-20261013-verify.py').read_text();exec(s18[s18.index('\ndef advance'):s18.index('\ndef rebind')])
def ascii_match(a,b):return bool(a and b)and fold(text(a))==fold(text(b))
def initialize(callback,system,argument,script):
 if callback==0x5149b0:return numbers.real(text(argument))if argument and text(argument)else 0x3f800000
 return 0
maxCallbacks69={0x514a00,0x514a50,0x514c30,0x514c80,0x514d50,0x514f50,0x515250,0x515270,0x5153c0,0x515450,0x5154e0,0x515530,0x515580,0x5155c0,0x515620}
def port69(name,args,model):
 if name=='Expression':return numbers.real(text(args[2]))
 callback,system,packet,actor,arg14,arg18=args
 if callback==0x5149f0:return arg18
 if callback==0x5157b0:return numbers.real(text(arg14))
 if callback==0x5149a0:
  state=(rd(0x95e5d4)*0x19660d+0x3c6ef35f)&0xffffffff;wd(0x95e5d4,state);return bits((state&0x7fffff)/8388608.)
 if callback in maxCallbacks69:return rd(0x75ecf0)
 if callback==0x515290:return rd(0x760010)
 return 0
s19=Path(__file__).with_name('script-phase19-20261013-verify.py').read_text();exec(s19[s19.index('\ndef slot'):s19.index('\ndef port')]);exec(s19[s19.index('\ndef expr'):s19.index('\ndef enter')].replace('expr(', 'expr69(').replace('finish(', 'finish69(').replace('evaluate(', 'evaluate69(').replace('port(', 'port69('))
def setup69(c):
 setup46(c)
 for p,z in [(SYS69,0x1500),(ACTOR69,0x400),(PACKET69,0x100),(CTRL69,0x400)]:n.write(p,bytes(z))
 n.pack('<I',ACTOR69+0xd0,CTRL69);n.pack('<B',ACTOR69+0x138,255);n.pack('<II',0x923904,0,0);n.pack('<I',0x95e5d4,c['seed'])
def execute69(c):
 global config,shadow,events,checks,symbolOrdinal,commandOrdinal
 config=c;setup69(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c);archive=0xaabbccdd if c['archive']else 0
 load46(archive,FOLDER46,TOP,BOTTOM,SYS69);modelStages=[snapshot(True)];script=rd(SYS69+28);bindsystem(SYS69);modelStages.append(snapshot(True));idle=rd(script+56);bind(PACKET69,script,idle,0);modelStages.append(snapshot(True));result=evaluate69(0,SYS69,idle+8,ACTOR69,PACKET69);modelStages.append(snapshot(True));me=events.copy();ms=state46()
 events=[];symbolOrdinal=0;commandOrdinal=0;reset46(c);n.call(0x52c470,[archive,FOLDER46,TOP,BOTTOM,SYS69],count=24000000);nativeStages=[snapshot()];scriptN=n.unpack('<I',SYS69+28)[0];n.call(0x5143a0,[SYS69],count=6000000);nativeStages.append(snapshot());idleN=n.unpack('<I',scriptN+56)[0];n.call(0x514640,[SYS69,ACTOR69,PACKET69,0,0,0,0,scriptN,idleN]);nativeStages.append(snapshot());nativeResult=n.call(0x52c880,[SYS69,idleN+8,ACTOR69,PACKET69],regs={UC_X86_REG_EAX:0},count=4000000);nativeStages.append(snapshot());ne=events.copy();ns=state46()
 groups=[('load',nativeStages[0],modelStages[0]),('initialize',nativeStages[1],modelStages[1]),('bind',nativeStages[2],modelStages[2]),('evaluate',nativeStages[3],modelStages[3]),('return',nativeResult,result),('events',ne,me),('files',ns,ms)]
 for group,a,b in groups:
  checks+=1
  if a!=b:
   detail=dict(group=group,context=c)
   if group in ['load','initialize','bind','evaluate']:detail['differences']=[dict(address=x['address'],native=x['bytes'],model=y['bytes'])for x,y in zip(a,b)if x!=y][:2]
   else:detail.update(native=a,model=b)
   errors.append(detail)
 cases.append(dict(context=c,inputs=dict(archive=archive,path=FOLDER46,top=TOP,bottom=BOTTOM,system=SYS69,actor=ACTOR69,packet=PACKET69),initial=initial,final=nativeStages[-1],returnValue=nativeResult,script=scriptN,state=idleN,nativeEvents=ne,nativeFiles=ns))
table=json.loads((nm.BASE/'reports/script-phase24-20261013-native-fixtures.json').read_text())['builtinPredicates']
for row,archive,chunk in itertools.product(table,[False,True],[17,4096]):
 arg=' 1'if row['name']in ['AlwaysTrue','Param']else ' missing'if row['words'][2]else ''
 body='STATE BASE\nCONDITIONS\nIF '+row['name']+arg+' > 0 goto TARGET\n}\n}\nSTATE TARGET\n}\n'
 execute69(dict(predicate=row['name'],files={'script.txt':'root\n','root.scp':body},archive=archive,chunk=chunk,seed=0x12345678,callback=True))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,descriptorRows=len(table),ports=['finalarchive/fileIO','CRTboundedpathformatter'],closure='52c470→513400/4f1240/fullfileproducers→5143a0/all14initializers→514640→52c880/all48predicates in preparedemptyworld')
(nm.BASE/'reports/script-phase69-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase69-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
