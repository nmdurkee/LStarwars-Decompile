"""Original51f6b0 with actual next-route and distance/cache consumers."""
import importlib.util,json,copy,itertools,gzip
from pathlib import Path
s=importlib.util.spec_from_file_location('routing',Path(__file__).with_name('gameplay-path-routing-verify.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
n=r.n;BASE=r.BASE;OUT=r.OUT+16;graphs=[];cases=[];errors=[];executed=set()
from unicorn import UC_HOOK_CODE
n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:executed.add(a),begin=0x51f6b0,end=0x51f716)
def run(gid,q,o):
 r.resetcache(q,{});r.loadcache(q);before=r.caches(q);r.diagnostics=[];model=copy.deepcopy(q);diag=[];edge=o['edge'];current=r.CNX+0x24*edge if edge>=0 else 0;goal=current if o.get('same') else r.DUMMY;destination=o['destination'];direction=o['direction'];group=o['group'];words=[0xdeadbeef,0xcafebabe,0xfacefeed]
 n.pack('<I',r.PACK+0x15c,current);n.pack('<I',r.PACK+0x1d0,goal);n.pack('<I',r.PACK+0x17c,0 if destination is None else r.NODES+destination*0x5c);n.pack('<B',r.PACK+0x160,direction);n.pack('<B',r.PACK+0x13c,group);n.pack('<III',OUT,*words)
 result=n.call(0x51f6b0,[r.PACK,0 if o.get('nullOutput') else OUT]);got=dict(result=result,words=list(n.unpack('<III',OUT)),cache=r.changed(before,r.nativecaches(q)),diagnostics=r.diagnostics.copy());chosen=-1
 if current!=goal and edge>=0:
  start=q['edges'][edge]['b' if direction==0 else 'a'];chosen,out=r.next_edge(model,start,destination,group,r.PACK,diag)
  if chosen>=0 and not o.get('nullOutput'):words=q['positionWords'][q['edges'][chosen]['b' if out==0 else 'a']].copy()
 want=dict(result=int(chosen>=0),words=words,cache=r.changed(before,r.caches(model)),diagnostics=diag)
 if got!=want:errors.append(dict(graph=gid,options=o,got=got,want=want))
 cases.append(dict(graph=gid,options=o,native=got))
def main():
 original=json.loads((BASE/'reports/gameplay-path-routing-native-fixtures.json').read_text());positions={}
 for f in (BASE/'reports/gameplay-navigation/data').rglob('*.json.gz'):
  doc=json.loads(gzip.decompress(f.read_bytes()))
  for path in doc['paths']:positions[(doc['source'],path['index'])]=[[r.bits(v) for v in p['position']] for p in path['points']]
 for g in original['graphs']:
  if g.get('synthetic') and g['name']!='normal':continue
  g=copy.deepcopy(g);g['positionWords']=positions.get((g['source'],g['path']),[[0x3f800000+i,0x80000000,0x7fc00000+i] for i in range(len(g['nodes']))]);gid=len(graphs);graphs.append(g);q=r.decode(g);r.resetcache(q,{});r.materialize(q);q['_basePointer']=n.unpack('<I',r.PATH+0x84)[0]
  for i,w in enumerate(g['positionWords']):n.pack('<III',r.NODES+0x5c*i+4,*w)
  for edge,direction,destination,group in itertools.product(sorted(set([0,len(g['edges'])-1])),[0,1,2,255],[None,0,len(g['nodes'])-1],list(range(len(g['groups'])))+[255]):
   for null in [False,True]:run(gid,q,dict(edge=edge,direction=direction,destination=destination,group=group,nullOutput=null))
  for edge,same in itertools.product([-1,0],[False,True]):run(gid,q,dict(edge=edge,direction=0,destination=0,group=255,same=same))
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x51f6b0,0x67),0x51f6b0)]
 report=dict(binarySha256=n.sha256,checks=len(cases),mismatches=len(errors),examples=errors[:3],graphs=len(graphs),instructionCoverage=dict(total=len(ins),executed=sum(i['executed'] for i in ins),missing=[i['address'] for i in ins if not i['executed']]),method='Original51f6b0 calls actual51be90 and51a890. Optional independent output buffer, exact position word copies, current/goal identity gate, route caches and diagnostic events compared. Authored graph positions plus synthetic signed-zero/NaN raw copy payloads.')
 (BASE/'reports/gameplay-path-nextpoint-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-nextpoint-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,graphs=graphs,cases=cases),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-nextpoint-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,address='0x51f6b0',endExclusive='0x51f717',instructions=ins),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
