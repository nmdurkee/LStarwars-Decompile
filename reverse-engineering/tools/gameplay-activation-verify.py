"""Activate/DeActivate with original lookup, base-state switch and deactivation body."""
import importlib.util,json,struct,copy,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('actors',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
n=a.n;BASE=a.BASE;D=a.D;SCRIPTS=D+0x60000;STATES=D+0x62000;ACTIONS=D+0x65000;NAMES=D+0x66000;WORLD=D+0x70000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
checks={};errors=[];vectors=[];helpers=[];executed=set();options={};uses={r['name']:r['uses'] for r in a.ledger['rows'] if r['kind']=='scp-action' and r['name'] in ['Activate','DeActivate']}
def packet(i):return a.actor(i)+0x2c8
def state(i):return STATES+i*0x40
def sid(p):return (p-STATES)//0x40 if p else -1
def scriptid(p):return (p-SCRIPTS)//0x100 if p else -1
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x41c120:
  ix=a.aid(arg(0));a.events.append(['reinitialize',ix,bool(arg(1))])
  if 'reinitializeGroup' in options:n.pack('<B',a.actor(ix)+0x378,options['reinitializeGroup'])
  a.ret(mu,0)
 elif address==0x4364e0:a.events.append(['destroyAttachment',a.aid(arg(0)),arg(1),arg(2)]);a.ret(mu,0)
 elif address==0x4882d0:a.events.append(['releaseControl',a.aid(arg(0)),arg(1)]);a.ret(mu,0)
 elif address==0x52c790:a.events.append(['state',a.aid(arg(0)-0x2c8) if arg(0) else -1,a.string(arg(1)) if arg(1) else None])
 executed.add(address)
for address in [0x41c120,0x4364e0,0x4882d0,0x52c790]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def trace(mu,address,size,user):executed.add(address)
for start,end in [(0x4442f0,0x444490),(0x444490,0x4445f0),(0x414bb0,0x414c50),(0x52c790,0x52c810)]:n.mu.hook_add(UC_HOOK_CODE,trace,begin=start,end=end-1)
def setup(tokens,o):
 global options
 options=o;c=a.context(o);a.setup(c,tokens);n.write(D+0x57000,bytes(0x29000));n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x2ae8,a.SYS)
 names=['Base','InActive','Other'];missing=o.get('missingStates',[])
 for i,name in enumerate(names):n.write(NAMES+i*64,('Hidden'+name if name in missing else name).encode()+b'\0')
 for sc in range(2):
  n.pack('<II',SCRIPTS+sc*0x100+0x10,state(sc*3),state(sc*3+2))
  for j in range(4):n.pack('<f',SCRIPTS+sc*0x100+0x1c+8*j,sc*10+j+.25)
  for j in range(3):n.pack('<I',state(sc*3+j),state(sc*3+j+1) if j<2 else 0);n.pack('<I',state(sc*3+j)+0x18,NAMES+64*j);n.pack('<I',state(sc*3+j)+0x10,ACTIONS if o.get('withAction',False) else 0)
 for i in range(8):
  p=packet(i);kind=o.get('scriptKinds',[1]*8)[i];group=o.get('groups',[0,1,2,3,16,2,1,255])[i];flags=o.get('scriptFlags',0x24);si=0 if kind==0 else 1
  n.pack('<IIIII',p,SCRIPTS,0 if kind==2 else SCRIPTS+si*0x100,state(si*3+2),ACTIONS+0x40,state(si*3+1));n.pack('<4f',p+0x14,9,8,7,6);n.pack('<f',p+0x24,3.5);n.pack('<I',p+0x50,flags);n.pack('<I',p+0x64,3);n.pack('<B',p+0xb0,group);n.pack('<H',p+0xb2,0x7654);n.pack('<BB',p+0xb4,7,9);n.pack('<f',p+0xb8,8.);n.pack('<II',p+0xbc,state(si*3+1),0x13572468);n.pack('<B',a.actor(i)+0x406,9);n.pack('<I',a.actor(i)+0xcd0,a.actor(o.get('attached',[-1]*8)[i]));n.pack('<B',a.SPAWN+i*0xa4+0x87,5)
 n.write(0x876847,bytes(o.get('counts',[(254+i)&255 for i in range(17)])))
 return c
def snapshot():
 rows=[]
 for i in range(8):
  p=packet(i);action=n.unpack('<I',p+0xc)[0]
  rows.append(dict(active=n.unpack('<I',a.actor(i)+0x1fc)[0],group=n.unpack('<B',p+0xb0)[0],phase=n.unpack('<B',a.actor(i)+0x406)[0],script=scriptid(n.unpack('<I',p+4)[0]),state=sid(n.unpack('<I',p+8)[0]),action=(action-ACTIONS)//0x40 if action else -1,pending=sid(n.unpack('<I',p+0x10)[0]),parameters=list(n.unpack('<4I',p+0x14)),flags=n.unpack('<I',p+0x50)[0],depth=n.unpack('<I',p+0x64)[0],blocked=n.unpack('<H',p+0xb2)[0],deadline=n.unpack('<I',p+0xb8)[0],deadlineState=sid(n.unpack('<I',p+0xbc)[0]),deadlineMarker=n.unpack('<B',p+0xb4)[0],conditionBank38=n.unpack('<B',p+0x38)[0],deadlineB5=n.unpack('<B',p+0xb5)[0],deadlineC0=n.unpack('<I',p+0xc0)[0]))
 return dict(actors=rows,counts=list(n.read(0x876847,17)),spawnPhase=[n.unpack('<B',a.SPAWN+i*0xa4+0x87)[0] for i in range(8)])
def delta(before,after):
 return {k:[[i,{f:v for f,v in row.items() if before[k][i][f]!=v}] for i,row in enumerate(after[k]) if row!=before[k][i]] if k=='actors' else [[i,v] for i,v in enumerate(after[k]) if v!=before[k][i]] for k in ['actors','counts','spawnPhase']}
def change(out,c,o,events,ix,name):
 events.append(['state',ix,name])
 if ix<0 or name is None:return False
 p=out['actors'][ix]
 if p['script']<0 or name.lower() not in ['base','inactive','other'] or name.lower() in [v.lower() for v in o.get('missingStates',[])]:return False
 target=['base','inactive','other'].index(name.lower());same=p['script']==0;oldflags=p['flags'];p.update(conditionBank38=1,state=target,action=0 if o.get('withAction') else -1,pending=-1,flags=(oldflags&~4)|(1 if o.get('withAction') else 0))
 if not same:p.update(script=0,parameters=[a.bits(i+.25) for i in range(4)],depth=0,deadline=0,deadlineState=-1,deadlineMarker=0,deadlineB5=0,deadlineC0=0,blocked=0)
 elif not oldflags&4:p['blocked']=0
 return True
def deactivate(out,c,o,events,ix):
 if ix<0:return
 link=o.get('attached',[-1]*8)[ix]
 if link>=0:events.append(['destroyAttachment',link,4,0] if not c['actors'][ix]['state'][0]&0x4000 else ['releaseControl',ix,1])
 out['actors'][ix]['active']&=~0x1000;slot=c['actors'][ix]['spawn']
 if slot!=255 and change(out,c,o,events,ix,'InActive'):out['actors'][ix]['phase']=0;out['spawnPhase'][slot]=2
 else:out['actors'][ix]['phase']=4
def activate(out,c,o,events,ix):
 if c['actors'][ix]['spawn']==255:out['actors'][ix]['active']|=0x1000;change(out,c,o,events,ix,'Base')
 else:
  events.append(['reinitialize',ix,c['system']])
  if 'reinitializeGroup' in o:out['actors'][ix]['group']=o['reinitializeGroup']
def model(command,tokens,c,o,first,before):
 out=copy.deepcopy(before);events=[]
 if first:
  target=c['actors'][c['reference']]['world'] if c['creature'] and c['reference']>=0 else -1;group=0
  for token in tokens:
   low=token.lower()
   if 'character=' in low:
    name=token[low.index('character=')+10:];ref=-1
    if c['callback']:events.append(['name',name]);ref=a.resolve_name(c,name)
    target=c['actors'][ref]['world'] if ref>=0 else -1
   elif 'set=' in low:
    value=a.number(token[low.index('set=')+4:]);word=0 if value>=2**63 or value< -(2**63) else int(value)&0xffffffff;group=word if 0<=word<=16 else 0
  isactivate=command=='Activate'
  selected=[i for i in range(c['count']) if out['actors'][i]['active']&(1 if isactivate else 0x1001)==(1 if isactivate else 0x1001) and out['actors'][i]['group']==group] if group else [target] if target>=0 else []
  for ix in selected:
   if isactivate:
    activate(out,c,o,events,ix);g=group or out['actors'][ix]['group']
    if 0<g<17:out['counts'][g]=(out['counts'][g]+1)&255
   else:deactivate(out,c,o,events,ix)
 return dict(result=1,delta=delta(before,out),events=events)
def run(command,tokens,o=None,first=True,source=None):
 o=o or {};c=setup(tokens,o);before=snapshot();result=n.call(0x4442f0 if command=='Activate' else 0x444490,[a.SYS if c['system'] else 0,a.PACK,a.CRE if c['creature'] else 0,a.ARGS,len(tokens),int(first)],count=200000);got=dict(result=result,delta=delta(before,snapshot()),events=a.events.copy());want=model(command,tokens,c,o,first,before);kind='authored' if source else command;checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(command=command,tokens=tokens,options=o,first=first,got=got,want=want))
 vectors.append(dict(command=command,tokens=tokens,options=o,first=first,source=source,native=got))
def helper(kind,ix,name=None,o=None):
 o=o or {};c=setup([],o);before=snapshot();out=copy.deepcopy(before);events=[]
 if kind=='baseState':
  if name is not None:n.write(a.TEXT,name.encode()+b'\0')
  result=n.call(0x52c790,[packet(ix) if ix>=0 else 0,a.TEXT if name is not None else 0]);wanted=int(change(out,c,o,events,ix,name))
 else:n.call(0x414bb0,[a.actor(ix)]);result=None;deactivate(out,c,o,events,ix);wanted=None
 got=dict(result=result,delta=delta(before,snapshot()),events=a.events.copy());want=dict(result=wanted,delta=delta(before,out),events=events);checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,index=ix,name=name,options=o,got=got,want=want))
 helpers.append(dict(kind=kind,index=ix,name=name,options=o,native=got))
def main():
 for command,rows in uses.items():
  for row in rows:
   matches={};nextactor=1
   for token in row['args']:
    if 'character=' in token.lower():matches[str(nextactor)]={'spawnName':token[token.lower().index('character=')+10:]};nextactor+=1
   for first,o in [(False,{}),(True,{}),(True,dict(actorOverrides=matches,scriptKinds=[0]*8))]:run(command,row['args'],o,first,{k:row[k] for k in ['source','line','state'] if k in row})
 tokensets=[[],['set=1'],['set=2'],['set=16'],['set=17'],['set=-1'],['set=2.99'],['set=param3'],['set=alpha'],['set=4294967296'],['character=order66'],['character=missing'],['character=Player_2'],['character=Player7'],['character=missing','set=2'],['set=1','set=2'],['set=2','set=0'],['character=order66','character=missing']]
 opts=[{},dict(creature=False),dict(reference=-1),dict(callback=False),dict(count=0),dict(system=False),dict(actorOverrides={'0':dict(world=-1)}),dict(actorOverrides={'0':dict(world=1)}),dict(actorOverrides={'0':dict(spawn=255),'2':dict(spawn=255)}),dict(scriptKinds=[0]*8),dict(scriptKinds=[2]*8),dict(missingStates=['Base','InActive']),dict(withAction=True),dict(reinitializeGroup=5)]
 for command,tokens,o in itertools.product(uses,tokensets,opts):run(command,tokens,o)
 for active in [0,1,0x1000,0x1001,0xffffffff]:
  for command in uses:run(command,['set=2'],dict(groups=[2]*8,actorOverrides={str(i):dict(active=active,spawn=255 if i%2 else i) for i in range(8)},withAction=True,counts=[255]*17))
 for kind,name,flags,withAction in itertools.product([0,1,2],[None,'Base','InActive','iNaCtIvE','missing'],[0,4,0x24,0xffffffff],[False,True]):helper('baseState',0,name,dict(scriptKinds=[kind]*8,scriptFlags=flags,withAction=withAction))
 helper('baseState',-1,'Base');helper('deactivate',-1)
 for slot,attached,flag,kind,missing in itertools.product([0,255],[-1,7],[0,0x4000],[0,1,2],[False,True]):helper('deactivate',0,o=dict(actorOverrides={'0':dict(spawn=slot,flags=flag)},attached=[attached]+[-1]*7,scriptKinds=[kind]*8,missingStates=['InActive'] if missing else []))
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
 for start,size in [(0x4442f0,0x1a0),(0x444490,0x170),(0x414bb0,0xa0),(0x52c790,0x80)]:
  ins=[]
  for i in d.disasm(n.read(start,size),start):
   if i.mnemonic=='int3':break
   ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed))
  functions.append(dict(address=hex(start),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:8],authoredOccurrences={k:len(v) for k,v in uses.items()},method='Original4442f0/444490 execute actual43c220 name lookup, original packet numeric parser, original414bb0 and original52c790/512fc0/5145a0/514640 state helpers. Only spawn reinitialization41c120, attachment destruction4364e0 and release4882d0 are service fixtures. Actor/script/counter changes stored as sparse deltas.',instructionCoverage={x['address']:dict(total=len(x['instructions']),executed=sum(i['executed'] for i in x['instructions']),notExecuted=[i['address'] for i in x['instructions'] if not i['executed']]) for x in functions},limits=['Spawn lifecycle41c120, attachment destruction and player release remain explicit adapters; actual side effects are not fabricated.','ScriptMachine composition includes companion raw byte38/B5 and wordC0 updates. Their broader consumers remain outside this activation contract.','Resolved base script is required when current script is nonnull; malformed null-base native pointer access is excluded.','Managed source/replay compile only.'])
 (BASE/'reports/gameplay-activation-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-activation-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,typeNames=a.TYPE_NAMES,commands=vectors,helpers=helpers),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-activation-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
