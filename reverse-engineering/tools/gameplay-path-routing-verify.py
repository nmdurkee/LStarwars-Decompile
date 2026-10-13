"""Original PC base/subroute next connection and distance/cache contracts."""
import importlib.util,json,gzip,struct,copy,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86();BASE=x.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
PATH=D;PACK=D+0x1000;DUMMY=D+0x2000;OUT=D+0x3000;NODES=D+0x10000;CNX=D+0x20000;ADJ=D+0x30000;ARENA=D+0x40000
MAX=struct.unpack('<f',struct.pack('<I',0x7f7fffff))[0];checks={};errors=[];executed=set();diagnostics=[];graphs=[];vectors=[]
def f(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def shift(v):return 1<<(v&255) if (v&255)<32 else 0
def trace(mu,addr,size,data):executed.add(addr)
for a,z in [(0x51a890,0x373),(0x51be90,0x290)]:n.mu.hook_add(UC_HOOK_CODE,trace,begin=a,end=a+z-1)
def diagnostic(mu,addr,size,data):
 sp=mu.reg_read(UC_X86_REG_ESP);group,start,dest=n.unpack('<III',sp+4);diagnostics.append([group-0x11110000,start,dest]);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_EAX,0)
n.mu.hook_add(UC_HOOK_CODE,diagnostic,begin=0x512860,end=0x512860)
def compact(doc,path):
 return dict(source=doc['source'],sha256=doc['sha256'],path=path['index'],name=path['name'],nodes=[dict(adj=p['connectionIndices'],member=p['unknownShortPair'][0],boundary=p['unknownShortPair'][1]) for p in path['points']],edges=[dict(a=e['to'],b=e['from'],mask=e['unknownShorts'][1],distance=e['distanceCandidates'][0]) for e in path['connections']],base=[bytes(255 if v is None else v['slot'] for v in row).hex() for row in path['routing']['nextHopRows']],groups=[dict(count=g['count3'],map=g['pointMap']['hex'],exits=g.get('list4',{}).get('hex',''),matrix=[g['matrix']['hex'][i*g['count3']*2:(i+1)*g['count3']*2] for i in range(g['count3'])]) for g in path['routingGroups']])
def decode(g):
 q=copy.deepcopy(g);q['base']=[list(bytes.fromhex(row)) if isinstance(row,str) else row for row in q['base']]
 for s in q['groups']:s['map']=list(bytes.fromhex(s['map']));s['exits']=list(bytes.fromhex(s['exits']));s['matrix']=[list(bytes.fromhex(row)) for row in s['matrix']]
 return q
def resetcache(q,o):
 for i,p in enumerate(q['nodes']):p['cache']=[o.get('cache0',255),o.get('cache1',255),f(10.25+i),f(20.5+i)]
def materialize(q):
 n.write(D,bytes(0x90000));arena=ARENA;adj=ADJ
 def alloc(data):
  nonlocal arena
  p=arena;n.write(p,data);arena=(arena+len(data)+3)&~3;assert arena<D+0x100000;return p
 def matrix(rows):
  addresses=[alloc(bytes(row)) for row in rows];return alloc(struct.pack('<'+'I'*len(addresses),*addresses))
 n.pack('<I',PATH+0x7c,NODES);n.pack('<I',PATH+0x80,CNX);n.pack('<I',PATH+0x84,matrix(q['base']));n.pack('<B',PATH+0x10,len(q['nodes']));n.pack('<B',PATH+0x14,len(q['groups']));groups=alloc(bytes(0x28*len(q['groups'])));n.pack('<I',PATH+0x88,groups)
 for j,g in enumerate(q['groups']):
  p=groups+j*0x28;n.pack('<I',p,0x11110000+j);n.pack('<I',p+4,alloc(bytes(g['map'])));n.pack('<I',p+0xc,alloc(bytes(g['exits'])));n.pack('<BB',p+0x10,g['count'],len(g['exits']));n.pack('<I',p+0x14,matrix(g['matrix']))
 for i,e in enumerate(q['edges']):n.pack('<BBHH',CNX+i*0x24+0x10,e['a'],e['b'],0,e['mask']);n.pack('<f',CNX+i*0x24+0x18,e['distance'])
 for i,p in enumerate(q['nodes']):
  at=NODES+i*0x5c;n.pack('<B',at+0x28,len(p['adj']));n.pack('<I',at+0x34,adj)
  for edge in p['adj']:n.pack('<I',adj,CNX+edge*0x24 if edge>=0 else 0);adj+=4
  n.pack('<HH',at+0x58,p['member'],p['boundary'])
 n.pack('<I',PACK+0x158,PATH)
def loadcache(q):
 for i,p in enumerate(q['nodes']):c=p['cache'];n.pack('<BB',NODES+i*0x5c+0x2e,c[0],c[1]);n.pack('<ff',NODES+i*0x5c+0x38,c[2],c[3])
def caches(q):return [[p['cache'][0],p['cache'][1],bits(p['cache'][2]),bits(p['cache'][3])] for p in q['nodes']]
def nativecaches(q):return [[*n.unpack('<BB',NODES+i*0x5c+0x2e),*n.unpack('<II',NODES+i*0x5c+0x38)] for i in range(len(q['nodes']))]
def changed(before,after):return [[i,row] for i,row in enumerate(after) if before[i]!=row]
def distance(q,start,dest,group,exclude,diag,depth=0):
 if q.get('noBase'):return MAX
 if start==dest:return 0.
 if depth>256:raise ValueError('recursive graph')
 first=q['nodes'][start];target=q['nodes'][dest];cache=not exclude and group==255
 if cache:
  c=first['cache']
  if c[0]==dest:return c[2]
  if c[1]==dest:return c[3]
  c[:]=[dest,c[0],0.,c[2]]
 def finish(v):
  if cache:first['cache'][2]=v
  return v
 sub=q['groups'][group] if group!=255 else None
 if sub is not None and not first['member']&shift(group):return MAX
 current=start;previous=-1;total=0.;seen=set()
 while current!=dest:
  if (current,previous) in seen:raise ValueError('nonterminating route')
  seen.add((current,previous));p=q['nodes'][current]
  if sub is None:slot=q['base'][current][dest]
  elif not target['member']&shift(group):
   best=MAX
   for exit in sub['exits']:
    a=0. if exit==start else distance(q,start,exit,group,0,diag,depth+1);b=0. if exit==dest else distance(q,exit,dest,255,shift(group),diag,depth+1);v=MAX if a==MAX or b==MAX else f(a+b);best=min(best,v)
   return finish(MAX if best==MAX else f(total+best))
  else:
   a=sub['map'][current];b=sub['map'][dest]
   if a>=sub['count'] or b>=sub['count']:diag.append([group,current,dest]);return finish(MAX)
   slot=sub['matrix'][a][b]
  if slot==255:return finish(MAX)
  edge=p['adj'][slot]
  if edge<0:return MAX
  e=q['edges'][edge]
  if exclude&e['mask']:return finish(MAX)
  if edge==previous:return finish(total)
  previous=edge;current=e['b'] if e['a']==current else e['a'];total=f(total+e['distance'])
 return finish(total)
def next_edge(q,start,dest,group,out,diag):
 if dest is None or not 0<=dest<=255:return -1,out
 p=q['nodes'][start];slot=q['base'][start][dest];result=p['adj'][slot] if slot<len(p['adj']) else -1
 if result>=0:out=int(q['edges'][result]['a']!=start)
 if group!=255:
  mask=shift(group)
  if not p['member']&mask:return -1,out
  if not p['boundary']&mask or (result>=0 and q['edges'][result]['mask']&mask):
   sub=q['groups'][group];result=-1;target=dest
   if not q['nodes'][dest]['member']&mask:
    best=MAX;target=0
    for exit in sub['exits']:
     a=distance(q,start,exit,group,0,diag);b=distance(q,exit,dest,255,mask,diag);v=MAX if a==MAX or b==MAX else f(a+b)
     if v<best:best=v;target=exit
    if best==MAX:return -1,out
   slot=sub['matrix'][sub['map'][start]][sub['map'][target]]
   if slot<len(p['adj']):result=p['adj'][slot];out=int(q['edges'][result]['a']!=start)
 return result,out
def run(gid,q,kind,start,dest,group=255,exclude=0,o=None):
 global diagnostics
 o=o or {};resetcache(q,o);loadcache(q);before=caches(q);diagnostics=[];model=copy.deepcopy(q);diag=[]
 if kind=='distance':
  n.pack('<I',PATH+0x84,0 if o.get('noBase') else q['_basePointer']);model['noBase']=bool(o.get('noBase'))
  n.call(0x51a890,[PATH,start,dest,group,exclude]);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.mu.emu_start(n.STOP,n.STOP+6,count=1);got=dict(value=n.unpack('<I',OUT)[0],cache=changed(before,nativecaches(q)),diagnostics=diagnostics);v=distance(model,start,dest,group,exclude,diag);want=dict(value=bits(v),cache=changed(before,caches(model)),diagnostics=diag)
 else:
  current=CNX+o['edge']*0x24 if 'edge' in o else DUMMY;actual_start=q['edges'][o['edge']]['b' if o.get('direction',0)==0 else 'a'] if 'edge' in o else start
  n.pack('<I',PATH+0x84,q['_basePointer']);n.pack('<BB',DUMMY+0x10,start,start);n.pack('<I',PACK+0x15c,0 if o.get('noCurrent') else current);n.pack('<I',PACK+0x17c,0 if dest is None else NODES+dest*0x5c);n.pack('<B',PACK+0x160,o.get('direction',0));n.pack('<B',PACK+0x13c,group);n.pack('<I',OUT,0xdeadbeef);value=n.call(0x51be90,[OUT],{UC_X86_REG_EAX:PACK});got=dict(value=(value-CNX)//0x24 if value else -1,direction=n.unpack('<I',OUT)[0],cache=changed(before,nativecaches(q)),diagnostics=diagnostics);edge,direction=(-1,0xdeadbeef) if o.get('noCurrent') else next_edge(model,actual_start,dest,group,0xdeadbeef,diag);want=dict(value=edge,direction=direction,cache=changed(before,caches(model)),diagnostics=diag)
 checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(graph=gid,kind=kind,start=start,destination=dest,group=group,exclude=exclude,options=o,got=got,want=want))
 vectors.append(dict(graph=gid,kind=kind,start=start,destination=dest,group=group,exclude=exclude,options=o,native=got))
def main():
 rng=random.Random(0x51be90)
 for file in sorted((BASE/'reports/gameplay-navigation/data').rglob('*.json.gz')):
  doc=json.loads(gzip.decompress(file.read_bytes()))
  for path in doc['paths']:
   if not path['routingGroups']:continue
   graph=compact(doc,path);gid=len(graphs);graphs.append(graph);q=decode(graph);resetcache(q,{});materialize(q);q['_basePointer']=n.unpack('<I',PATH+0x84)[0];count=len(q['nodes']);groups=len(q['groups'])
   for group in range(groups):
    starts=[i for i,p in enumerate(q['nodes']) if p['member']&shift(group)];ends=[i for i,p in enumerate(q['nodes']) if not p['member']&shift(group)]
    pairs=set((a,b) for a in starts[:2]+starts[-2:] for b in starts[:2]+starts[-2:]+ends[:2]+ends[-2:])
    pairs.update((rng.randrange(count),rng.randrange(count)) for _ in range(24))
    for a,b in sorted(pairs):run(gid,q,'distance',a,b,group);run(gid,q,'next',a,b,group)
   for a,b in [(0,0),(0,count-1),(count-1,0),(count//2,count-1)]:
    for options in [{},{'cache0':b},{'cache1':b},{'noBase':True}]:run(gid,q,'distance',a,b,o=options)
    for ex in [1,2,0xffff]:run(gid,q,'distance',a,b,exclude=ex)
    run(gid,q,'next',a,b)
   for dest in [None,-1,256]:run(gid,q,'next',0,dest)
   run(gid,q,'next',0,count-1,o={'noCurrent':True})
   for edge,direction,group in itertools.product([0,len(q['edges'])-1],[0,1,2,255],[0,255]):run(gid,q,'next',0,count-1,group,o=dict(edge=edge,direction=direction))
 synthetic=dict(source='synthetic: three-node branch fixtures',sha256=None,path=0,name='synthetic',synthetic=True,nodes=[dict(adj=[0],member=1,boundary=0),dict(adj=[0,1],member=1,boundary=1),dict(adj=[1],member=0,boundary=0)],edges=[dict(a=0,b=1,mask=1,distance=1.25),dict(a=1,b=2,mask=0,distance=2.5)],base=['ff0000','00ff01','0000ff'],groups=[dict(count=2,map='0001ff',exits='01',matrix=['ff00','00ff'])])
 for variant in ['normal','invalidMap','nullEdge','repeatEdge','selfEdge']:
  g=copy.deepcopy(synthetic);g['name']=variant
  if variant=='invalidMap':g['groups'][0]['map']='0201ff'
  if variant=='nullEdge':g['nodes'][0]['adj']=[-1]
  if variant=='repeatEdge':g['base'][1]='00ff00'
  if variant=='selfEdge':g['edges'][0]['b']=0
  gid=len(graphs);graphs.append(g);q=decode(g);resetcache(q,{});materialize(q);q['_basePointer']=n.unpack('<I',PATH+0x84)[0]
  for dest in [1,2]:
   for group in ([255,0] if variant=='invalidMap' else [255]):run(gid,q,'distance',0,dest,group)
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
 for start,size in [(0x51a890,0x373),(0x51be90,0x290)]:
  ins=[]
  for i in d.disasm(n.read(start,size),start):
   if i.mnemonic=='int3':break
   ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed))
  functions.append(dict(address=hex(start),endExclusive=hex(int(ins[-1]['address'],16)+len(bytes.fromhex(ins[-1]['bytes']))),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:5],authoredGraphs=sum(not g.get('synthetic',False) for g in graphs),authoredSubroutes=sum(len(g['groups']) for g in graphs if not g.get('synthetic',False)),syntheticGraphs=sum(g.get('synthetic',False) for g in graphs),instructionCoverage={p['address']:dict(total=len(p['instructions']),executed=sum(i['executed'] for i in p['instructions']),missing=[i['address'] for i in p['instructions'] if not i['executed']]) for p in functions})
 (BASE/'reports/gameplay-path-routing-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-routing-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,graphs=graphs,cases=vectors),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-routing-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
