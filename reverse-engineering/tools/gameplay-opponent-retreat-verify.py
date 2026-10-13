"""Original retreat command and actual expression parser with explicit token callback."""
import importlib.util,json,copy,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('movement',Path(__file__).with_name('gameplay-movement-verify.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
n=m.n;BASE=m.BASE;checks={};errors=[];vectors=[];executed=set();uses=next(r['uses'] for r in m.b.ledger['rows'] if r['name']=='RetreatFromOpponent')
from unicorn import UC_HOOK_CODE
def trace(mu,address,size,user):executed.add(address)
n.mu.hook_add(UC_HOOK_CODE,trace,begin=0x535d60,end=0x535e9f)
def snapshot():
 b=m.snapshot('FollowPlayer');return {k:b[k] for k in ['goal','mode','flags','point','radius','intentGoal','words']}
def run(tokens,o=None,first=True,source=None):
 o={'opponent':True,**(o or {})};c=m.setup('FollowPlayer',tokens,o)
 if not o.get('opponentController',True):n.pack('<I',m.b.actor(2)+4,0)
 if o.get('formation'):n.pack('<I',m.CRE+0x144,0xdeadbeef)
 before=snapshot();other=dict(point=c['pathPoints'][2],words=c['pathWords'][2],radius=m.bits(3.25))
 if 'opponentPoint' in o:n.pack('<3f',m.controller(2)+0x170,*o['opponentPoint']);other['point']=m.vec(o['opponentPoint'])
 if 'opponentRadius' in o:n.pack('<f',m.controller(2)+0x120,o['opponentRadius']);other['radius']=m.bits(o['opponentRadius'])
 result=n.call(0x535d60,[m.SYS,m.CALLER,m.CRE if c['creature'] else 0,m.ARGS,len(tokens),int(first)]);got=dict(result=result,state=snapshot(),events=m.b.events.copy());state=copy.deepcopy(before);ev=[]
 if c['creature']:
  if first:
   state['goal']=m.bits(1.)
   for token in tokens:
    mode={'walk':17,'run':34,'tiptoe':51}.get(token.lower()) if not o.get('noTokenCallback') else None
    if not o.get('noTokenCallback'):ev.append(['token',token,mode is not None])
    if mode is not None:state['mode']=mode
    else:
     ev.append(['expression',token]);state['goal']=m.bits(0. if token=='2.5___tail' else m.b.number(token))
  if o['opponent'] and o.get('opponentController',True):state.update(point=other['point'],words=other['words'],radius=other['radius'],intentGoal=state['goal'],flags=(state['flags']&0xfffffffa)|2)
 wanted=dict(result=0 if c['creature'] else 1,state=state,events=ev);kind='authored' if source else 'branches';checks[kind]=checks.get(kind,0)+1
 if got!=wanted:errors.append(dict(tokens=tokens,options=o,first=first,got=got,want=wanted))
 vectors.append(dict(tokens=tokens,options=o,first=first,source=source,before=before,opponent=other,native=got))
def main():
 for use in uses:
  for o,first in [({},True),({},False),({'reference':False,'worldObject':-1},True),({'opponentController':False},True)]:run(use['args'],o,first,{k:use[k] for k in ['source','line','state']})
 tokensets=[[],['walk'],['20','run'],['TipToe','50'],['alpha'],['param3'],['.25'],['-5'],['2.5___tail'],['+5'],['20','10']]
 for tokens,first,options in itertools.product(tokensets,[False,True],[{},dict(creature=False),dict(reference=False),dict(worldObject=-1),dict(opponent=False),dict(opponentController=False),dict(noTokenCallback=True),dict(formation=True)]):run(tokens,options,first)
 for flags,goal,radius in itertools.product([0,1,2,3,4,5,6,7,0x80000000,0xffffffff],[-5.,0.,.25,20.],[-1.,0.,3.25]):run([],dict(flags=flags,goal=goal,opponentRadius=radius,opponentPoint=[-3.,4.,2.5]),False)
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);instructions=[]
 for i in d.disasm(n.read(0x535d60,0x160),0x535d60):
  if i.mnemonic=='int3':break
  instructions.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:8],authoredOccurrences={'RetreatFromOpponent':len(uses)},method='Original0x535d60 and real514920 numeric-expression path execute unchanged; only registered movement-token callback is a deterministic walk/run/tiptoe fixture service. All49 shipped numeric argument lists execute four times each.',limits=['Full expression-language environment and movement-token callback mapping remain explicit services. Authored retreat operands are numeric constants.','Intent copies six raw path words and target-controller path point/radius; no pathfinding or position integration.','Formation pointer is intentionally not read by this inline setter; a poison pointer probe establishes bypass.','Managed core/replay compile only.'])
 (BASE/'reports/gameplay-opponent-retreat-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-opponent-retreat-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-opponent-retreat-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,entry='0x535d60',instructions=instructions),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
