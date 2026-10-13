"""Original retreat plus unmodified expression parser, now independently modeled together."""
import importlib.util,json,copy,itertools
from pathlib import Path
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=module('retreat','gameplay-opponent-retreat-verify.py');e=module('expression','gameplay-expression-verify.py');m=r.m;n=m.n;BASE=m.BASE
checks={};errors=[];vectors=[];sequences=[]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
def observe(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);text=m.b.string(n.unpack('<I',sp+4)[0]);m.b.events.append(['token',text,text.lower() in ['run','walk','tiptoe']])
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x43c0c0,end=0x43c0c0)
def snapshot(tokens):
 return dict(state=r.snapshot(),rng=n.unpack('<I',0x95e5d4)[0],tokens=[m.b.string(n.unpack('<I',m.ARGS+4*i)[0]) for i in range(len(tokens))])
def call(tokens,o,first,before,other):
 m.b.events.clear();result=n.call(0x535d60,[m.SYS,m.CALLER,m.CRE if o.get('creature',True) else 0,m.ARGS,len(tokens),int(first)])
 got={**snapshot(tokens),'result':result,'events':m.b.events.copy()};want=copy.deepcopy(before);events=[]
 if o.get('creature',True):
  if first:
   want['state']['goal']=m.bits(1.)
   for index,text in enumerate(want['tokens']):
    mode={'walk':1,'run':0,'tiptoe':2}.get(text.lower()) if not o.get('noTokenCallback') else None
    if not o.get('noTokenCallback'):events.append(['token',text,mode is not None])
    if mode is not None:want['state']['mode']=mode;continue
    events.append(['expression',text]);parsed=e.Parser(text,dict(callback=False,seed=want['rng'])).run();want['tokens'][index]=parsed['text'];want['rng']=parsed['rng'];want['state']['goal']=parsed['value']
  if o.get('opponent',True) and o.get('opponentController',True):want['state'].update(point=other['point'],words=other['words'],radius=other['radius'],intentGoal=want['state']['goal'],flags=(want['state']['flags']&0xfffffffa)|2)
 want.update(result=0 if o.get('creature',True) else 1,events=events)
 return got,want
def run(tokens,o=None,first=True,source=None,ticks=1):
 o={'opponent':True,**(o or {})};c=m.setup('FollowPlayer',tokens,o);n.pack('<I',0x9238b0,0x43c0c0)
 if not o.get('opponentController',True):n.pack('<I',m.b.actor(2)+4,0)
 before=snapshot(tokens);other=dict(point=c['pathPoints'][2],words=c['pathWords'][2],radius=m.bits(3.25));rows=[];old=copy.deepcopy(before)
 for tick in range(ticks):
  got,want=call(tokens,o,first,old,other);kind='persistent' if ticks>1 else 'authored' if source else 'branches';checks[kind]=checks.get(kind,0)+1
  if got!=want:errors.append(dict(tokens=tokens,options=o,first=first,tick=tick,got=got,want=want))
  rows.append(got);old={k:copy.deepcopy(want[k]) for k in ['state','rng','tokens']}
 row=dict(tokens=tokens,options=o,first=first,source=source,before=before,opponent=other,native=rows if ticks>1 else rows[0])
 (sequences if ticks>1 else vectors).append(row)
def main():
 token_sets=[['run'],['WALK'],['TiPtOe'],['run','20'],['Rand+Rand','walk'],['walk','2.5___tail'],['run','(1+2)/1'],['alpha beta','run'],['run','RUNNING'],['run','walk','tiptoe'],['tiptoe','1alpha'],['walk','param3']]
 for tokens,mode,o in itertools.product(token_sets,[0,1,2,9,255],[{},dict(opponent=False),dict(opponentController=False)]):run(tokens,{'mode':mode,**o})
 for tokens in [['run','Rand+Rand'],['alpha beta','walk'],['tiptoe','2.5___tail'],['run','walk','tiptoe']]:run(tokens,ticks=8)
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:8],authoredOccurrences=0,authoredUseCredit=0,newNativeMappings=0,method='Unmodified535d60 calls the actual registered43c0c0 movement-token callback and unmodified514920/514850 expression parser. The callback executes unchanged; its entry is observed only. Independent command/parser model compares intent state, result, token order, mode bytes, RNG and mutated text. Every input list includes at least one consumed production movement token.',limits=['No new native mapping:43c0c0 already belongs to FacingCommands.MovementToken. This is composition evidence.','Game symbol callback is null in these native fixtures. Finite ASCII text and independent argument buffers remain the parser bounds.','No navigation/path integration. Managed replay compiles only.'])
 (BASE/'reports/gameplay-retreat-token-composition-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-retreat-token-composition-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors,sequences=sequences),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
