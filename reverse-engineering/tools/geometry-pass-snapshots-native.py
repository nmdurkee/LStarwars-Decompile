"""Whole original pass snapshot with actual pending packet finalization."""
import ast,struct,json,gzip,hashlib,base64,collections,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';path=B/'tools/geometry-pending-packets-native.py';tree=ast.parse(path.read_text());body=[]
for node in tree.body:
 if isinstance(node,ast.For) and isinstance(node.target,ast.Name)and node.target.id=='row':break
 body.append(node)
p={'__file__':str(path)};exec(compile(ast.Module(body=body,type_ignores=[]),str(path),'exec'),p);n=p['n'];D=p['D'];u=p['u'];w=p['w'];calls=p['calls'];SIZE=16*0x218;cases=[];counts=collections.Counter()
def run(before,state,current,snapshots,count,address,label):
 expected,s,index,trace=p['model'](before,state);expected_current=bytearray(current);expected_snapshots=bytearray(snapshots);struct.pack_into('<I',expected_current,0,index&0xffffffff)
 active,context,volume=struct.unpack_from('<3I',current,0x38)
 if active and index!=-1:
  if u(expected,context+0x808)==0:struct.pack_into('<I',expected_current,0x38,0)
  else:
   at=context+volume*0x380;entries=u(expected,at+0x374);assert volume<2 and entries<8;w(expected,at+0x354+entries*4,index);w(expected,at+0x374,entries+1)
  struct.pack_into('<I',expected_current,0,0xffffffff)
 expected_snapshots[count*0x218:(count+1)*0x218]=expected_current
 n.write(D,before);n.write(0x9718a0,current);n.write(0x9640f0,snapshots);n.pack('<I',0x95fbb8,count)
 for a,v in [(0x9736e0,state['allocator']),(0x973ec8,state['reservationCount']),(0x973ecc,state['head']),(0x973e78,state['globalCache']),(0x973e80,state['globalHead']),(0x973e84,state['globalTail']),(0x973ed0,state['count'])]:n.pack('<I',a,v)
 n.pack('<24I',0x973ed4,*state['descriptors']);calls.clear();n.call(address,[0xabcdef01],count=10000000);actual=n.read(D,len(before));actual_current=n.read(0x9718a0,0x218);actual_snapshots=n.read(0x9640f0,SIZE);actual_count=n.unpack('<I',0x95fbb8)[0];actual_s=dict(state);actual_s.update(count=n.unpack('<I',0x973ed0)[0],globalTail=n.unpack('<I',0x973e84)[0],descriptors=list(n.unpack('<24I',0x973ed4)))
 assert actual==expected and actual_current==expected_current and actual_snapshots==expected_snapshots and actual_count==count+1 and actual_s==s and calls==trace,dict(label=label,index=index,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:12])
 digest=hashlib.sha256(actual+actual_current+actual_snapshots).hexdigest();cases.append(dict(label=label,address=hex(address),beforeZ=base64.b64encode(gzip.compress(before,mtime=0)).decode(),state=state,current=current.hex(),snapshotsZ=base64.b64encode(gzip.compress(snapshots,mtime=0)).decode(),count=count,nativeState=actual_s,nativeCount=actual_count,nativeSHA256=digest,nativeResetCalls=trace));counts['cases']+=1;counts['persistentBytes']+=len(before)+0x218+SIZE+4+31*4;counts['emptyIndex']+=index==-1;counts['active']+=active!=0;counts['entry'+hex(address)]+=1;return actual,actual_s,actual_current,actual_snapshots,actual_count
def build(index,flags,global_active,active,enabled,volume,entry_count):
 before,state=p['build'](dict(materials=8,ranges=[(0,3),(3,5),(0,0)]),index,flags,global_active);context=p['alloc'](0x830,index);memory=p['memory'];w(memory,context+0x808,enabled)
 for v in range(2):w(memory,context+v*0x380+0x374,entry_count)
 before=bytes(memory);current=bytearray((i*37+index*13)&255 for i in range(0x218));snapshots=bytes((i*19+index*17)&255 for i in range(SIZE));native_index=p['model'](before,state)[2]
 if not active or native_index==-1:context=0xdeadbeef;volume=0xffffffff
 elif not enabled:volume=0xffffffff
 struct.pack_into('<3I',current,0x38,active,context,volume);return before,state,bytes(current),snapshots
for index,(flags,global_active,active,enabled,volume)in enumerate(itertools.product([None,0,2,0x10,0x12],[False,True],[0,1,0x80000000],[0,1,0xffffffff],[0,1])):
 before,state,current,snapshots=build(index,flags,global_active,active,enabled,volume,index%8)
 for address in [0x5f3950,0x5f39e0]:run(before,state,current,snapshots,index%16,address,[index,flags,global_active,active,enabled,volume])
for index in range(32):
 before,state,current,snapshots=build(index,0x12,True,1,1,index&1,0);state['count']=0;count=0
 for step in range(5):before,state,current,snapshots,count=run(before,state,current,snapshots,count,0x5f3950,['sequence',index,step])
fp=R/'geometry-pass-snapshots-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-pass-snapshots-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Original5f3950 and direct thunk5f39e0 execute actual5efff0/5fca40, with no computational stubs.', 'Complete current0x218-byte state and sixteen supplied snapshot slots are byte-compared. This is a validated fixture capacity, not an inferred universal native limit.', 'Active valid contexts use volume0/1 and pre-append count0..7 in eight slots+354..370. Disabled or empty-index cases preserve original context/volume short-circuit behavior.', 'Controlled exact layouts with all pending-list categories and160 sequential capture calls. Source-derived pending-list coverage remains in its independent native report.', 'CPU state/pending packet output only. GPU submission, resource lifecycle and managed runtime equality remain separate.'])
(R/'geometry-pass-snapshots-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
