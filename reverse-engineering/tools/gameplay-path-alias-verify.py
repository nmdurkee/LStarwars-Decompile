"""Registered43c780 scene-reference aliases; original calls and path compositions."""
import importlib.util,json,itertools,copy,struct,random
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=load('refresh','gameplay-path-refresh-verify.py');n=r.r.x.NativeX86();BASE=r.BASE;D=n.DATA;TARGET=D+0x100;WORLD=D+0x40000;GROUPS=D+0x50000;NORMALS=D+0x10000;INSTANCES=D+0x14000;DISPLAYS=D+0x20000;CTX=0xabcdef12
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
def valid(a):return a is not None and bool(a[1] or a[2])
def same(a,b):return bool((a[1] and a[1]==b[1]) or (a[2] and a[2]==b[2]))
def resolve(ref,o):
 out=None if ref is None else ref.copy()
 if not valid(ref) or o.get('noGroups'):return 0,out
 for group in o.get('groups',[])[:max(0,o.get('count',len(o.get('groups',[]))))]:
  members=group['refs'][:max(0,group.get('count',len(group['refs'])))]
  if not any(same(ref,a) for a in members):continue
  for a in members:
   visible=a[0] and ((o.get('normalFlags',[0,1,0,1])[a[1]-1]&1) if a[1] else (o.get('displayFlags',[0,2,0,2])[a[2]-1]&2) if a[2] else False)
   if visible:return 1,a.copy()
  return 0,out
 return 0,out
def raw(a):return [a[0],NORMALS+(a[1]-1)*0x100 if a[1] else 0,DISPLAYS+(a[2]-1)*0x100 if a[2] else 0]
def logical(a):return [a[0],(a[1]-NORMALS)//0x100+1 if a[1] else 0,(a[2]-DISPLAYS)//0x100+1 if a[2] else 0]
def setup(o):
 n.write(D,bytes(0x60000));n.pack('<I',0x802c54,WORLD);n.pack('<Ii',WORLD+0x46b0,0 if o.get('noGroups') else GROUPS,o.get('count',len(o.get('groups',[]))))
 for i in range(4):n.pack('<I',NORMALS+i*0x100+0x40,INSTANCES+i*0x100);n.pack('<I',INSTANCES+i*0x100+0x44,o.get('normalFlags',[0,1,0,1])[i]);n.pack('<I',DISPLAYS+i*0x100+0xb8,o.get('displayFlags',[0,2,0,2])[i])
 at=GROUPS
 for group in o.get('groups',[]):
  refs=group['refs'];stride=4+len(refs)*12+group.get('padding',0);n.pack('<hh',at,group.get('count',len(refs)),stride)
  for j,a in enumerate(refs):n.pack('<3I',at+4+j*12,*raw(a))
  at+=stride
 if o.get('ref') is not None:n.pack('<3I',TARGET,*raw(o['ref']))
 return TARGET if o.get('ref') is not None else 0
ranges=[(0x43c780,0x43c7a0),(0x55fd40,0x55fe20),(0x5cfac0,0x5cfaf0),(0x5d0450,0x5d0480)];executed=set()
for a,end in ranges:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=a,end=end-1)
cases=[];errors=[];counts={};registration={}
def observe_callback(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);context,ref=r.n.unpack('<II',sp+4);r.events.append(['resolve',context,(ref-0x40-r.NODES)//0x5c])
r.n.mu.hook_add(UC_HOOK_CODE,observe_callback,begin=0x43c780,end=0x43c780)
def chain(o):
 before=r.setup(dict(o,visible=0,displayFlags=2));node=o.get('node',0);ref=[1,1,0];success,resolved=resolve(ref,dict(ref=ref,groups=o['aliasGroups'],normalFlags=[0]*4,displayFlags=[2]*4));world=r.D+0x40000;at=r.D+0x50000;r.n.pack('<I',0x802c54,world);r.n.pack('<Ii',world+0x46b0,at,len(o['aliasGroups']));r.n.pack('<I',0x9238d8,0x43c780)
 def words(a):return [a[0],r.NORMAL if a[1] else 0,r.DISPLAY if a[2] else 0]
 for g in o['aliasGroups']:
  stride=4+12*len(g['refs'])+g.get('padding',0);r.n.pack('<hh',at,g.get('count',len(g['refs'])),stride)
  for j,a in enumerate(g['refs']):r.n.pack('<3I',at+4+j*12,*words(a))
  at+=stride
 original=r.repair
 def repair(z,unused):
  if success:
   for j,value in enumerate(words(resolved)):r.r.put(z['nodes'][node],0x40+j*4,value)
 r.repair=repair
 try:expected,events=r.model(before,dict(o,visible=0,displayFlags=2,callback=True,resolve=bool(success)))
 finally:r.repair=original
 r.n.call(0x51af40,[r.CTX,r.PATH,r.NODES+node*0x5c]);after=dict(nodes=[r.n.read(r.NODES+i*0x5c,0x5c) for i in range(4)],edges=[r.n.read(r.EDGES+i*0x24,0x24) for i in range(len(before['edges']))],seen=r.n.read(r.PATH+0x18,32));got=r.summary(before,after,r.events);want=r.summary(before,expected,events);cases.append(dict(kind='refreshChain',options=o,native=got));counts['refreshChain']=counts.get('refreshChain',0)+1
 if got!=want:errors.append(dict(kind='refreshChain',options=o,got=got,want=want))
def run(o,kind='resolve'):
 ptr=setup(o)
 if kind=='valid':native=n.call(0x5cfac0,[ptr]);want=int(valid(o['ref']));got=native
 elif kind=='same':n.pack('<3I',TARGET+0x20,*raw(o['other']));got=n.call(0x5d0450,[ptr,TARGET+0x20]);want=int(same(o['ref'],o['other']))
 else:
  result,target=resolve(o['ref'],o);native=n.call(0x43c780,[CTX,ptr]) if kind=='callback' else n.call(0x55fd40,[WORLD,ptr]);got=dict(result=native,ref=logical(list(n.unpack('<3I',ptr))) if ptr else None);want=dict(result=result,ref=target)
 counts[kind]=counts.get(kind,0)+1;cases.append(dict(kind=kind,options=o,native=got))
 if got!=want:errors.append(dict(kind=kind,options=o,got=got,want=want))
def main():
 refs=[[s,a,b] for s,a,b in itertools.product([0,1,99],range(3),range(3))]
 for a in [None]+refs:run(dict(ref=a),'valid')
 for a,b in itertools.product(refs,repeat=2):run(dict(ref=a,other=b),'same')
 groups=[[],[dict(refs=[])],[dict(refs=[[1,1,0],[1,2,0]])],[dict(refs=[[1,1,0],[0,2,0],[1,0,2]])],[dict(refs=[[1,1,1],[1,2,0]],padding=12),dict(refs=[[1,1,0],[1,0,2]])],[dict(refs=[[1,1,0]]),dict(refs=[[1,1,0],[1,2,0]])],[dict(refs=[[1,1,0]],count=-1),dict(refs=[[1,1,0],[1,2,0]])]]
 for ref,gg,callback in itertools.product([None]+refs,groups,[False,True]):run(dict(ref=ref,groups=gg),'callback' if callback else 'resolve')
 for count,noGroups in itertools.product([-1,0,1,2],[False,True]):run(dict(ref=[1,1,0],groups=groups[4],count=count,noGroups=noGroups))
 rng=random.Random(0x55fd40)
 for _ in range(1024):
  gg=[dict(refs=[rng.choice(refs) for _ in range(rng.randrange(6))],padding=rng.randrange(4)*4) for _ in range(rng.randrange(5))];run(dict(ref=rng.choice(refs),groups=gg,normalFlags=[rng.randrange(4) for _ in range(4)],displayFlags=[rng.randrange(4) for _ in range(4)]),'callback')
 aliasGroups=[[],[dict(refs=[[1,1,0]])],[dict(refs=[[1,1,0],[1,0,1]])],[dict(refs=[[0,0,1],[1,1,0],[1,0,1]])],[dict(refs=[[1,1,0]]),dict(refs=[[1,1,0],[1,0,1]])],[dict(refs=[[1,0,1],[1,1,0]],padding=8)]]
 for groups,node,animated,flags in itertools.product(aliasGroups,[0,1],[0,1],[0,4]):chain(dict(aliasGroups=groups,node=node,animated=animated,flags=flags))
 for value in [0,0x43c780]:n.call(0x516ff0,[value]);registration[hex(value)]=hex(n.unpack('<I',0x9238d8)[0])
 assembly=[]
 for a,end in ranges:
  ins=[]
  for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,end-a),a):
   if i.mnemonic=='int3':break
   ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed))
  assembly.append(dict(address=hex(a),endExclusive=hex(int(ins[-1]['address'],16)+len(bytes.fromhex(ins[-1]['bytes']))),instructions=ins))
 registration['initializerCalls']=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x43c830,0x200),0x43c830) if '43c780' in i.op_str or '516ff0' in i.op_str]
 report=dict(binarySha256=n.sha256,checks=len(cases),counts=counts,mismatches=len(errors),examples=errors[:5],registration=registration,instructionCoverage=dict(total=sum(len(s['instructions']) for s in assembly),executed=sum(i['executed'] for s in assembly for i in s['instructions']),missing=[i['address'] for s in assembly for i in s['instructions'] if not i['executed']]))
 (BASE/'reports/gameplay-path-alias-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-alias-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-alias-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,ranges=assembly),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
