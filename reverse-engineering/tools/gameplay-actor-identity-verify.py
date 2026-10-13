"""Original IAm name binding and reference/character-name predicate."""
import importlib.util,json,struct,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('actors',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
n=a.n;BASE=a.BASE;RESULT=a.D+0x59000
uses=next(r['uses'] for r in a.ledger['rows'] if r['name']=='IAm')
checks=0;errors=[];vectors=[]
def floating(args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT));n.call(0x515750,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',RESULT)[0]
def run(operand,options=None,source=None):
 global checks
 o=options or {};c=a.context(o)
 if o.get('matchDefinition') and operand is not None:c['definitions'][0]['name']=operand
 a.setup(c,[]);ptr=0
 if operand is not None:n.write(a.TEXT,operand.encode()+b'\0');ptr=a.TEXT
 bound=a.aid(n.call(0x515730,[a.SYS if c['system'] else 0,ptr]));expectedBound=a.resolve_name(c,operand) if operand is not None and c['callback'] else -1
 initEvents=a.events.copy();expectedEvents=[['name',operand]] if operand is not None and c['callback'] else []
 initialized=o.get('boundOverride',bound)
 ref=c['reference'] if c['creature'] else -1
 # Initialization can be followed by global changes; it retains a reference.
 if 'primaryAfter' in o:n.pack('<I',0x93d810,a.actor(o['primaryAfter']))
 if o.get('noDefinition') and ref>=0:n.pack('<I',a.actor(ref)+0x54,0)
 if o.get('noDefinitionName') and ref>=0:n.pack('<I',a.DEF+c['actors'][ref]['definition']*0x4c+0xc,0)
 got=floating([a.SYS,a.PACK,a.CRE if c['creature'] else 0,ptr,a.actor(initialized)])
 match=ref>=0 and (ref==initialized or (not o.get('noDefinition') and not o.get('noDefinitionName') and operand is not None and c['definitions'][c['actors'][ref]['definition']]['name'].lower()==operand.lower()))
 native=dict(bound=bound,events=initEvents,value=got);wanted=dict(bound=expectedBound,events=expectedEvents,value=a.bits(float(match)));checks+=1
 if native!=wanted:errors.append(dict(operand=operand,options=o,got=native,want=wanted))
 vectors.append(dict(operand=operand,options=o,context=c,initialized=initialized,source=source,native=native))
def main():
 for row in uses:
  operand=row['args'][0] if row['args'] else None
  for options in [{},{'matchDefinition':True},{'matchDefinition':True,'callback':False},{'creature':False}]:run(operand,options,{k:row[k] for k in ['source','line','state']})
 for operand,reference,bound,noDef,noName in itertools.product([None,'','Alpha','alpha','Beta','player','player_2','Player0','missing'],[-1,0,1],[-1,0,1],[False,True],[False,True]):
  run(operand,dict(reference=reference,boundOverride=bound,noDefinition=noDef,noDefinitionName=noName))
 for operand,options in itertools.product(['player','player_2','Alpha','Beta','spawn0','order66'],[dict(callback=False),dict(system=False),dict(primaryAfter=7,reference=1),dict(actorOverrides={'0':dict(world=1)}),dict(actorOverrides={'0':dict(active=0)}),dict(count=0)]):run(operand,options)
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);assembly=dict(binarySha256=n.sha256,entry='0x515750',endExclusive='0x51578e',instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str) for i in d.disasm(n.read(0x515750,0x3e),0x515750)])
 (BASE/'reports/gameplay-actor-identity-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8')
 report=dict(binarySha256=n.sha256,checks=checks,mismatches=len(errors),examples=errors[:10],authoredOccurrences={'IAm':len(uses)},method='Original initializer0x515730, actual registered callback0x43c220 and predicate0x515750 execute unchanged. Predicate x87 return is captured to float32; only bounded CRT Player%d formatting is substituted.',limits=['Valid runtime reference identity and definitions; record allocation/lifetime are supplied.','ASCII operand/name comparisons; cached pointer identity persists across later player-global changes.','Core/replay compile only; no generated managed executable launch.'])
 (BASE/'reports/gameplay-actor-identity-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-actor-identity-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
