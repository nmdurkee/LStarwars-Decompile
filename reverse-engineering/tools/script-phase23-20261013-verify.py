"""Actual513230/5132a0 rawload symbol flags with realparser and suppliedgamecallback."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase20-20261013-verify.py').read_text().split('\ntexts=')[0])
baseport=port
def port(name,creature,packet,model):
 read=rd if model else lambda p:n.unpack('<I',p)[0];flags=[read(p)for p in [0x92224c,0x922250,0x922254]];handled,value=baseport(name,creature,packet,model);events[-1]['flags']=flags;return config.get('handledNames',{}).get(name,handled),value
def resolve(name):
 wd(0x92224c,1);wd(0x922250,1);value=0
 if rd(0x9238c0):
  handled,value=port(name,0,0,True)
  if handled:wd(0x922250,0)
 return value
def execute23(c,method='Evaluate'):
 global config,events,ordinal,shadow,checks
 config=c;setup(c);n.pack('<III',0x92224c,42,43,44);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0;textp=c.get('textPointer',TEXT);fo=c.get('floatOutput',OUT);io=c.get('integerOutput',OUT+4)
 if method=='Evaluate':
  wd(0x92224c,0);wd(0x922250,0);wd(0x922254,0);want=Parser(textp).run()
  if rd(0x922250):wd(0x922254,1)
  wd(OUT+0x40,want)
 else:
  wd(0x92224c,1);wd(0x922250,1);value=0
  if rd(0x9238c0):
   handled,value=port(text(textp,True),0,0,True)
   if handled:wd(0x922250,0)
  want=0
  if fo:wd(fo,value)
  if io:v=fl(value);wd(io,0 if v>=2**63 or v< -(2**63)else int(v)&0xffffffff)
 modelEvents=events.copy();modelFinal=snapshot(True);events=[];ordinal=0
 if method=='Evaluate':n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(0x5132a0,[textp]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0]
 else:got=n.call(0x513230,[textp,fo,io])
 nativeEvents=events.copy();nativeFinal=snapshot()
 for group,a,b in [('return',got,want),('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(text=textp,floatOutput=fo,integerOutput=io),initial=initial,returnValue=got,final=nativeFinal,nativeEvents=nativeEvents))
texts=['','-0','1+2','1*2','1/2','(1+2)/1','alpha','alpha+beta','alpha-beta','alpha*beta','alpha/beta','-(alpha+beta)','alpha+','alpha*',';','alpha;beta','1alpha','alpha beta','alpha\tbeta','(1.2.3)/1','(.12345678+alpha)/2','--alpha','+alpha','1+Rand','Rand+Rand','max/2','alpha+custom','0/(-1)','((-0)+(-0))/1','(alpha','16777219/1','123456.789012345/1','param3','true','FALSE','max','_'*255]
for t,callback,handled in itertools.product(texts,[False,True],[0,1]):
 if not callback and t=='alpha/beta':continue
 execute23(dict(text=t,callback=callback,handled=handled))
rng=random.Random(0x5132a0)
for i in range(512):
 left=rng.choice(['alpha','beta','gamma','delta',str(rng.randrange(1,100)),f'{rng.randrange(1,100)}.{rng.randrange(1,10000):04}']);right=rng.choice(['alpha','beta','gamma','delta',str(rng.randrange(1,100))]);execute23(dict(text='('+left+rng.choice(['+','-','*','/'])+right+')/3'))
for name,callback,handled,outputs in itertools.product(['Rand','true','false','max','alpha','param3','-1.25','\xe0name'],[False,True],[0,1],[(0,0),(OUT,0),(0,OUT+4),(OUT,OUT+4),(OUT,OUT),(0x922250,0x92224c)]):execute23(dict(text=name,callback=callback,handled=handled,floatOutput=outputs[0],integerOutput=outputs[1]),'ResolveOutputs')
for a,b in itertools.product([0,1],[0,1]):execute23(dict(text='alpha+beta',handledNames={'alpha':a,'beta':b}))
for value in [0,0x80000000,bits(-1.75),bits(1.75),bits(2**63),bits(-(2**63)),0x7f7fffff]:execute23(dict(text='custom',symbolBits={'custom':value}),'ResolveOutputs')
for c in [dict(text='alpha+beta',patches={'alpha#1':[[0x9238c0,4,0]]}),dict(text='alpha+beta',patches={'alpha#1':[[TEXT+6,1,ord('1')],[TEXT+7,1,0]]}),dict(text='alpha',handled=0,patches={'alpha#1':[[0x922250,4,0]]}),dict(text='alpha',handled=1,patches={'alpha#1':[[0x922250,4,0xffffffff],[0x92224c,4,0],[0x922254,4,9]]}),dict(text='alpha',handled=0,patches={'alpha#1':[[0x922254,4,9]]}),dict(textPointer=0,callback=False),dict(textPointer=0x92224c,handled=1,floatOutput=0x922254),dict(text='custom',handled=0,patches={'custom#1':[[0x922250,4,0],[0x922254,4,7]]})]:execute23(c,'ResolveOutputs'if c.get('textPointer')is not None or c.get('text')=='custom'else'Evaluate')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],actualBodies=['0x513230','0x5132a0','0x4f8420','0x4f8790','0x4f8830','0x4f8880','0x4f88e0','0x6e6b90'],remainingPorts=['Game symbol callback9238c0'],limits=['Finite stored arithmetic and callbackresults; terminatinggrammar, bounded255identifier.','Raw context/loadflagglobals andcallbacks mutations compared; no runtime builtins orparamfallback onload.','Same-model oracle is separatefrommanaged replay; compiledsource execution remains unavailable.'])
(nm.BASE/'reports/script-phase23-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase23-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
