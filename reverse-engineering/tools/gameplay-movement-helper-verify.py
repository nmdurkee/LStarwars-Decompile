"""Original-PC nullable intent writes, formation dispatch, and movement update chains."""
import importlib.util,json,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('movement',Path(__file__).with_name('gameplay-movement-verify.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
n=m.n;b=m.b;D=m.D;CRE=m.CRE
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
FORMATION=D+0x70000;POINT=D+0x71000;WORDS=D+0x71100
events=[];checks={};errors=[];vectors=[];chains=[]
def callback(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=n.unpack('<I',sp+4)[0]
 if address==0x51d130:events.append(['owner',hex(arg)])
 else:events.append(['formation',arg==CRE])
 b.ret(mu,0)
for address in [0x51d130,0x52fda0]:n.mu.hook_add(UC_HOOK_CODE,callback,begin=address,end=address)
def snapshot():
 return dict(point=list(n.unpack('<3I',CRE+0x1b4)),radius=n.unpack('<I',CRE+0x1c0)[0],goal=n.unpack('<I',CRE+0x1c4)[0],words=list(n.unpack('<6I',CRE+0x1cc)),flags=n.unpack('<I',CRE+0x1e8)[0])
def check(group,got,want,meta):
 checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(group=group,got=got,want=want,input=meta))
if __name__=='__main__':
 for formation,mode,haspoint,haswords,flags in itertools.product(['null','disabled','leader','member'],range(16),[False,True],[False,True],[0,7,0xa5a5a5a5,0xffffffff]):
  m.setup('GoToLocator',[],{});events.clear();n.pack('<I',CRE+0x1e8,flags);n.pack('<I',CRE+0x144,0 if formation=='null' else FORMATION);n.pack('<I',FORMATION,b.actor(0 if formation=='leader' else 1));n.pack('<B',FORMATION+0x50,0 if formation=='disabled' else 8)
  point=[0x80000000,0x3f800000,0xc0200000];words=[0,0xffffffff,0x12345678,0x89abcdef,13,17];radius=m.bits(2.5);goal=m.bits(-3.5);n.pack('<3I',POINT,*point);n.pack('<6I',WORDS,*words)
  before=snapshot();n.call(0x52fcb0,[CRE,POINT if haspoint else 0,radius,WORDS if haswords else 0,mode,goal]);got=snapshot();want=dict(before);expected=[]
  if formation in ['leader','member'] and mode in [1,4]:
   if formation=='leader':expected.append(['owner','0x51cbc0' if mode==1 else '0x51c6a0'])
   expected.append(['formation',True])
  else:
   mapped=1 if formation in ['leader','member'] and mode==5 else mode
   want.update(point=point if haspoint else before['point'],words=words if haswords else before['words'],radius=radius,goal=goal,flags=(flags&~7)|(mapped&7))
  meta=dict(formation=formation,mode=mode,hasPoint=haspoint,hasWords=haswords,flags=flags)
  check('SetIntent-state',got,want,meta);check('SetIntent-formation-dispatch',events,expected,meta)
  vectors.append(dict(input=meta,before=before,point=point,words=words,radius=radius,goal=goal,native=dict(state=got,events=list(events))))
 # Real retained packet/controller memory across first entry and later updates.
 for wait,delta,groundgate in itertools.product([0.,.1,.25],[.125,.05],[False,True]):
  tokens=['name','Target','waittime='+str(wait),'goalrange=1']+(['on_ground'] if groundgate else [])
  options=dict(position=[100.,100.,100.]);context=m.setup('GoToLocator',tokens,options);steps=[]
  for tick in range(9):
   if tick==1:
    target=n.unpack('<I',m.CALLER+0x6c)[0];position=list(n.unpack('<3I',target+0x10));n.pack('<3I',CRE+0x14c,*position);context['position']=position
   ground=0 if groundgate and tick==1 else 1;options['ground']=ground;n.pack('<B',b.actor(0)+0x281,ground);b.events.clear();before=m.snapshot('GoToLocator');value=n.call(0x536700,[m.SYS,m.CALLER,CRE,m.ARGS,len(tokens),int(tick==0),m.bits(delta)],count=1000000);got=dict(state=m.snapshot('GoToLocator'),events=list(b.events),result=value);want=m.model('GoToLocator',tokens,context,options,tick==0,m.f(delta),before)
   for key in got:check('GoToLocator-chain-'+key,got[key],want[key],dict(wait=wait,delta=delta,groundgate=groundgate,tick=tick))
   steps.append(dict(tick=tick,ground=ground,position=context['position'],first=tick==0,before=before,native=got))
   if value:break
  chains.append(dict(wait=wait,delta=delta,groundgate=groundgate,tokens=tokens,steps=steps))
 result=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:10],helperCases=len(vectors),retainedStateChains=len(chains),retainedStateSteps=sum(len(c['steps']) for c in chains),method='Original0x52fcb0 with real writes and explicit formation expansion callbacks; original0x536700 over retained memory across updates.',limits=['Formation owner dispatch and expansion are observed adapters, not implemented formation algorithms.','Chains move creature position explicitly to the selected target; no pathfinder or physics step is claimed.','Finite float domains and valid pointers; compiled managed comparison remains pending.'])
 (b.BASE/'reports/gameplay-movement-helper-tests.json').write_text(json.dumps(result,indent=2),encoding='utf8');(b.BASE/'reports/gameplay-movement-helper-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,helpers=vectors,chains=chains),separators=(',',':')),encoding='utf8');print(json.dumps(result))
 if errors:raise SystemExit(1)
