"""Original52c880 through actual514920, not an expression port."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase20-20261013-verify.py').read_text().split('\ntexts=')[0])
LIST=D+0x5300;NODE=D+0x5400;DESC=D+0x5600;PRED=CB+0x10;ACTOR=D+0x5800;SYS=D+0x5900
from unicorn.x86_const import UC_X86_REG_EAX
def predicate(args,model):
 events.append(dict(name='Predicate',args=args));return config.get('left',bits(2.75))
def predhook(mu,address,size,data):
 if address!=PRED:return
 sp=mu.reg_read(UC_X86_REG_ESP);value=predicate(list(n.unpack('<5I',sp+4)),False);n.pack('<I',OUT+0x80,value);n.write(n.STOP+0x800,b'\xd9\x05'+struct.pack('<I',OUT+0x80)+b'\xc3');mu.reg_write(UC_X86_REG_EIP,n.STOP+0x800)
n.mu.hook_add(UC_HOOK_CODE,predhook)
for expression,left,handled,packetMutation in itertools.product(['alpha','alpha+beta','Rand','Rand+Rand','param3','true','max/2'],[bits(0.),bits(2.75),bits(1.)],[0,1],[False,True]):
 config=dict(text=expression,left=left,handled=handled)
 if packetMutation:config['patches']={'alpha#1':[[0x922260,4,P2]]}
 setup(config);n.pack('<I',LIST,NODE);n.pack('<I',NODE+0x1c,DESC);n.pack('<I',DESC+4,PRED);n.pack('<I',NODE+0x10,TEXT);n.pack('<H',NODE+0xe,8);n.write(P+0x38,b'\1\1');initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0
 leftValue=predicate([SYS,P,ACTOR,0,0],True);wd(OUT+0x80,leftValue);right=evaluate(ACTOR,P,TEXT);wd(P+0x28,right);want=NODE if fl(leftValue)==fl(right)else 0
 if not want and rb(P+0x39)and rb(P+0x38):right=evaluate(ACTOR,P,TEXT);wd(P+0x28,right)
 wb(P+0x39,0);wb(P+0x38,0);modelFinal=snapshot(True);modelEvents=events.copy();events=[];ordinal=0;got=n.call(0x52c880,[SYS,LIST,ACTOR,P],regs={UC_X86_REG_EAX:0});nativeFinal=snapshot();nativeEvents=events.copy()
 for key,a,b in [('return',got,want),('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents)]:
  checks+=1
  if a!=b:errors.append(dict(expression=expression,left=left,handled=handled,mutation=packetMutation,group=key,native=a,model=b))
 cases.append(dict(method='Conditions',context=config,inputs=dict(system=SYS,list=LIST,actor=ACTOR,packet=P),initial=initial,returnValue=got,final=nativeFinal,nativeEvents=nativeEvents))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],actualParent='0x52c880',actualExpression='0x514920',limits=['Dynamic predicate and game symbol callback supplied; condition evaluator, full expression bridge/parser, packet fallback, RNG execute real bytes.','Single terminal condition, bank0; phase19 retains broadcondition coverage. No new addresses or commands.'])
(nm.BASE/'reports/script-phase20-20261013-pipeline-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase20-20261013-pipeline-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
