"""Game-mode path callback bodies, preserving downstream service boundaries."""
import importlib.util,struct,json,random,itertools,copy
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=load('reinit','gameplay-reinitialization-verify.py');n=r.x.NativeX86();BASE=r.BASE;D=n.DATA;A=D;P=A+0x2c8;REF=D+0x2000;EDGE=D+0x4000;PATH=D+0x4100;NODES=D+0x5000;ATTACH=D+0x6000;CHAR=D+0x7000;TUNING=D+0x7100;QUERY=0x12345678
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_EAX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
modes=[(0x4078d0,0x407ad0,0x7ef2c0),(0x4813d0,0x481500,0x7fa2d0),(0x4cbba0,0x4cbda0,0x7fcf10)];tables={};handlers=set()
for address,end,table in modes:
 rows=[]
 for i in range(64):
  mask,entry=n.unpack('<II',table+i*8)
  if not entry:break
  rows.append([mask,entry]);handlers.add(entry)
 tables[address]=rows
events=[];options={};executed=set()
def ret(mu,value):
 sp=mu.reg_read(UC_X86_REG_ESP);mu.reg_write(UC_X86_REG_EAX,value&0xffffffff);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
def text(p):
 out=bytearray()
 while n.read(p,1)!=b'\0':out+=n.read(p,1);p+=1
 return out.decode('ascii')
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address in handlers:
  events.append(['handler',address,arg(0),arg(1),arg(2)]);change=options.get('mutation',{})
  if 'flags' in change:n.pack('<I',P+0x1e8,change['flags'])
  if 'actorFlags' in change:n.pack('<B',A+0x7c5,change['actorFlags'])
  if 'gate' in change:n.pack('<f',0x876ce4,r.f(change['gate']))
  if 'direction' in change:n.pack('<B',P+0x160,change['direction'])
  if 'requirements' in change:n.pack('<2I',EDGE,*change['requirements'])
  ret(mu,options.get('handlerReturn',0))
 elif address==0x52c790:events.append(['state',arg(0),text(arg(1))]);ret(mu,options.get('stateReturn',0))
 elif address==0x43c9a0:events.append(['tail',arg(0),arg(1),arg(2)]);ret(mu,options.get('tailReturn',0))
for address in handlers|{0x52c790,0x43c9a0}:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
for a,end,table in modes:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=a,end=end-1)
def setup(o):
 global events,options
 events=[];options=o;n.write(D,bytes(0x8000));actor=r.pattern(0x10d8,1);reference=r.pattern(0x10d8,1)
 r.put(actor,0x54,CHAR);r.put(actor,0xca4,ATTACH);r.put(actor,0x7b5,o.get('state',0),1);r.put(actor,0x7c5,o.get('actorFlags',0),1);r.put(actor,0xea4,o.get('link',0));r.put(actor,0x2c8+0x15c,EDGE);r.put(actor,0x2c8+0x158,PATH);r.put(actor,0x2c8+0x160,o.get('direction',0),1);r.put(actor,0x2c8+0x1f4,o.get('capabilities',0xffffffff));r.put(actor,0x2c8+0x1e8,o.get('flags',0));r.put(reference,0,A);r.put(reference,4,P);r.put(reference,0x292,o.get('referenceFlags',0x4321),2)
 n.write(A,actor);n.write(REF,reference);n.pack('<2I',EDGE,*o.get('requirements',[0,0]));n.pack('<BB',EDGE+0x10,*o.get('endpoints',[2,5]));n.pack('<I',PATH+0x7c,NODES);n.pack('<I',CHAR+0x24,TUNING);n.pack('<B',TUNING+0x90,o.get('tuning',0));n.pack('<I',ATTACH+8,o.get('attachment',0x1234));n.pack('<I',0x802278,o.get('specialMask',0x240));n.pack('<f',0x876ce4,r.f(o.get('gate',1)));return actor,reference
def model(before,o,mode):
 actor,reference=map(bytearray,before);attachment=o.get('attachment',0x1234);ev=[];req=o.get('requirements',[0,0]).copy();direction=o.get('direction',0);gate=r.f(o.get('gate',1));flags=o.get('flags',0);actorFlags=o.get('actorFlags',0)
 if o.get('state',0)==91:attachment|=o.get('specialMask',0x240)
 needed=req[direction]
 if needed and not needed&0x40000000:
  cap=o.get('capabilities',0xffffffff)&needed
  if mode!=0x4813d0 and needed&0x8000 and not o.get('tuning',0)&0x40 and o.get('link',0)==0 and o.get('state',0)!=60 and cap&0xffff7fff==0:ev.append(['state',P,'TakeOverJump']);return 1,actor,reference,attachment,ev
  if not cap or needed&0x98000000:
   actor[0x2c8+0x104:0x2c8+0x110]=reference[0x5c:0x68];r.put(actor,0x2c8+0x110,0);r.put(reference,0x292,struct.unpack_from('<H',reference,0x292)[0]|0x2000,2)
   if mode==0x4813d0:r.put(actor,0x2c8+0x139,0,1)
   return 1,actor,reference,attachment,ev
  for mask,entry in tables[mode]:
   if mask&cap:
    ev.append(['handler',entry,P,REF,QUERY]);change=o.get('mutation',{})
    if 'flags' in change:flags=change['flags'];r.put(actor,0x2c8+0x1e8,flags)
    if 'actorFlags' in change:actorFlags=change['actorFlags'];r.put(actor,0x7c5,actorFlags,1)
    if 'direction' in change:direction=change['direction'];r.put(actor,0x2c8+0x160,direction,1)
    if 'gate' in change:gate=r.f(change['gate'])
    if 'requirements' in change:req=change['requirements']
    if o.get('handlerReturn',0):return 1,actor,reference,attachment,ev
    break
 if flags&0x20000000 and not actorFlags&2 and gate>0 and not req[direction]&0xd8000000:ev.append(['tail',A,NODES+o.get('endpoints',[2,5])[int(direction==0)]*0x5c,0])
 return 0,actor,reference,attachment,ev
cases=[];errors=[];counts={}
def run(mode,o):
 before=setup(o);wanted,actor,reference,attachment,ev=model(before,o,mode);result=n.call(mode,[P,REF,QUERY]);got=dict(result=result,actor=r.changes(before[0],n.read(A,len(actor))),reference=r.changes(before[1],n.read(REF,len(reference))),attachment=n.unpack('<I',ATTACH+8)[0],events=events.copy());want=dict(result=wanted,actor=r.changes(before[0],actor),reference=r.changes(before[1],reference),attachment=attachment,events=ev);counts[hex(mode)]=counts.get(hex(mode),0)+1;cases.append(dict(mode=hex(mode),options=o,native=got))
 if got!=want:errors.append(dict(mode=hex(mode),options=o,got=got,want=want))
def main():
 for mode,end,table in modes:
  for bit,cap,flags in itertools.product([0]+[1<<i for i in range(32)]+[0xffffffff,0x8001,0x8004,0x20000004],[0,0xffffffff,1,0x8000],[0,0x20000000]):run(mode,dict(requirements=[bit,0],capabilities=cap,flags=flags))
  for state,tuning,link,retVal in itertools.product([0,60,91],[0,0x40],[0,1],[0,1,0xffffffff]):run(mode,dict(requirements=[0x8000,0],capabilities=0x8000,state=state,tuning=tuning,link=link,stateReturn=retVal,flags=0x20000000))
  for direction,flags,actorFlags,gate in itertools.product([0,1],[0,0x20000000],[0,2],[-1,0,1]):run(mode,dict(requirements=[0,0],direction=direction,flags=flags,actorFlags=actorFlags,gate=gate))
  for mask,entry in tables[mode]:
   for returnValue,mutation in itertools.product([0,1,0xffffffff],[{},dict(flags=0x20000000),dict(flags=0x20000000,actorFlags=2),dict(flags=0x20000000,gate=0),dict(flags=0x20000000,direction=1,requirements=[0,0]),dict(flags=0x20000000,requirements=[0x80000000,0])]):run(mode,dict(requirements=[mask,0],tuning=0x40,handlerReturn=returnValue,mutation=mutation))
  rng=random.Random(mode)
  for i in range(1024):run(mode,dict(requirements=[rng.getrandbits(32),rng.getrandbits(32)],capabilities=rng.getrandbits(32),direction=rng.randrange(2),state=rng.choice([0,60,91]),tuning=rng.randrange(256),link=rng.randrange(2),flags=rng.getrandbits(32),actorFlags=rng.randrange(256),gate=rng.choice([-1,0,1]),handlerReturn=rng.choice([0,1,0xffffffff]),attachment=rng.getrandbits(32),specialMask=rng.getrandbits(32)))
 assembly=[]
 for a,end,table in modes:
  ins=[]
  for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,end-a),a):
   if i.mnemonic=='int3':break
   ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed))
  assembly.append(dict(address=hex(a),endExclusive=hex(int(ins[-1]['address'],16)+len(bytes.fromhex(ins[-1]['bytes']))),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=len(cases),counts=counts,mismatches=len(errors),examples=errors[:5],instructionCoverage=dict(total=sum(len(s['instructions']) for s in assembly),executed=sum(i['executed'] for s in assembly for i in s['instructions']),missing=[i['address'] for s in assembly for i in s['instructions'] if not i['executed']]),boundaries=dict(state='52c790 receives unchanged TakeOverJump and ignores its return; independently recovered elsewhere',handlers='Actual original ordered mask tables, downstream handler return/state deltas provided explicitly',tail='43c9a0 event and ignored return; visibility and relocation side effects not implemented here'))
 (BASE/'reports/gameplay-path-dispatch-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-dispatch-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,tables={hex(k):v for k,v in tables.items()},cases=cases),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-dispatch-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,ranges=assembly),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
