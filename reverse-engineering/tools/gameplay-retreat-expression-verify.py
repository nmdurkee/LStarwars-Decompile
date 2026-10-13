"""Original retreat plus unmodified expression parser, now independently modeled together."""
import importlib.util,json,copy,itertools
from pathlib import Path
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=module('retreat','gameplay-opponent-retreat-verify.py');e=module('expression','gameplay-expression-verify.py');m=r.m;n=m.n;BASE=m.BASE
checks={};errors=[];vectors=[];sequences=[]
def snapshot(tokens):
 return dict(state=r.snapshot(),rng=n.unpack('<I',0x95e5d4)[0],tokens=[m.b.string(n.unpack('<I',m.ARGS+4*i)[0]) for i in range(len(tokens))])
def call(tokens,o,first,before,other):
 m.b.events.clear();result=n.call(0x535d60,[m.SYS,m.CALLER,m.CRE if o.get('creature',True) else 0,m.ARGS,len(tokens),int(first)])
 got={**snapshot(tokens),'result':result,'events':m.b.events.copy()};want=copy.deepcopy(before);events=[]
 if o.get('creature',True):
  if first:
   want['state']['goal']=m.bits(1.)
   for index,text in enumerate(want['tokens']):
    mode={'walk':17,'run':34,'tiptoe':51}.get(text.lower()) if not o.get('noTokenCallback') else None
    if not o.get('noTokenCallback'):events.append(['token',text,mode is not None])
    if mode is not None:want['state']['mode']=mode;continue
    events.append(['expression',text]);parsed=e.Parser(text,dict(callback=False,seed=want['rng'])).run();want['tokens'][index]=parsed['text'];want['rng']=parsed['rng'];want['state']['goal']=parsed['value']
  if o.get('opponent',True) and o.get('opponentController',True):want['state'].update(point=other['point'],words=other['words'],radius=other['radius'],intentGoal=want['state']['goal'],flags=(want['state']['flags']&0xfffffffa)|2)
 want.update(result=0 if o.get('creature',True) else 1,events=events)
 return got,want
def run(tokens,o=None,first=True,source=None,ticks=1):
 o={'opponent':True,**(o or {})};c=m.setup('FollowPlayer',tokens,o)
 if not o.get('opponentController',True):n.pack('<I',m.b.actor(2)+4,0)
 before=snapshot(tokens);other=dict(point=c['pathPoints'][2],words=c['pathWords'][2],radius=m.bits(3.25));rows=[];old=copy.deepcopy(before)
 for tick in range(ticks):
  got,want=call(tokens,o,first,old,other);kind='persistent' if ticks>1 else 'authored' if source else 'branches';checks[kind]=checks.get(kind,0)+1
  if got!=want:errors.append(dict(tokens=tokens,options=o,first=first,tick=tick,got=got,want=want))
  rows.append(got);old={k:copy.deepcopy(want[k]) for k in ['state','rng','tokens']}
 row=dict(tokens=tokens,options=o,first=first,source=source,before=before,opponent=other,native=rows if ticks>1 else rows[0])
 (sequences if ticks>1 else vectors).append(row)
def main():
 for use in r.uses:
  for first in [False,True]:run(use['args'],first=first,source={k:use[k] for k in ['source','line','state']})
 token_sets=[[],['walk'],['2.5___tail'],['1+2'],['(1+2)/1'],['1alpha'],['alpha+beta*gamma'],['Rand+Rand'],['alpha beta'],['alpha\tbeta'],['(alpha'],['alpha+'],['alpha','run','Rand+Rand'],['Rand','Rand'],['-0'],['(-0)/1'],['20','run','2.5___tail']]
 for tokens,first,o in itertools.product(token_sets,[False,True],[{},dict(creature=False),dict(opponent=False),dict(opponentController=False),dict(noTokenCallback=True)]):run(tokens,o,first)
 for tokens in [['Rand','Rand+Rand'],['alpha beta'],['alpha\tbeta'],['2.5___tail'],['1+2'],['Rand Rand'],['run','alpha+beta']]:run(tokens,ticks=8)
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:8],authoredOccurrences=49,authoredUseCredit=0,newNativeMappings=0,method='Unmodified535d60 calls unmodified514920/514850 and original recursive parser. Independent retreat state model composes the independently tested expression model. Compares command result, copied intent, goal, movement flags, callback/evaluation order, RNG and mutated tokens. All49 authored argument lists replay first and subsequent calls.',limits=['Movement-token callback remains deterministic fixture/host adapter; no production callback registration claim.','Finite ASCII expressions with independent mutable token buffers; pointer-aliasing between argument entries is not represented.','The mixed-token behavior that previously needed observed-value fixtures is independently modeled through the reconstructed lexer in this separate suite. Do not reclassify the retained historical suite.','Managed composition/replay compiles only.'])
 (BASE/'reports/gameplay-retreat-expression-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-retreat-expression-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors,sequences=sequences),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
