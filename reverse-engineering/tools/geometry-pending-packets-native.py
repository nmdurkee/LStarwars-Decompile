"""Original5efff0 list finalization, real cache resets and source-derived ranges."""
import importlib.util,struct,json,gzip,hashlib,base64,collections,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
D=0x11000000;n.mu.mem_map(D,0x2000000);memory=bytearray();calls=[];cases=[];counts=collections.Counter();sources=[]
def hook(mu,address,size,user):calls.append(n.unpack('<I',mu.reg_read(UC_X86_REG_ESP)+4)[0])
n.mu.hook_add(UC_HOOK_CODE,hook,begin=0x5fca40,end=0x5fca40)
def u(b,p):return struct.unpack_from('<I',b,p-D)[0]
def h(b,p):return struct.unpack_from('<H',b,p-D)[0]
def w(b,p,value):struct.pack_into('<I',b,p-D,value&0xffffffff)
def alloc(size,index=0):
 p=(len(memory)+15)&~15;memory.extend(bytes(p-len(memory)));memory.extend(bytes(((i*37+index*19)^(i>>3))&255 for i in range(size)));return D+p
def reset(b,p):
 for offset,value in [(8,0),(0x14,0xffffffff),(0x20,0xffffffff)]:w(b,p+offset,value)
 for offset in [0x24,0x2c,0x2e,0x1e]:struct.pack_into('<H',b,p+offset-D,65535)
def terminate(b,p):b[p-D]=0x84;w(b,p+4,0);b[p+1-D]=4
def copy(b,destination,source,count):
 for i in range(count):w(b,destination+i*4,u(b,source+i*4))
def model(before,state):
 b=bytearray(before);s=json.loads(json.dumps(state));trace=[];control=s['allocator'];get=lambda p:u(b,p);put=lambda p,v:w(b,p,v)
 def reserve(alignment,size):
  p=(get(control)+alignment-1)&~(alignment-1);assert D<=p<=p+size<=D+len(b);put(control,p+size);return p
 table=reserve(16,s['reservationCount']*4+4);emitted=0;node=s['head'];seen=set()
 while node:
  assert node not in seen;seen.add(node);owner=get(node+0x1c);flags=get(owner+0x74)if owner else 0;selected=0
  if owner and flags&0x10:
   if flags&2:
    clone=reserve(4,36);payload=get(control);put(clone,get(node));put(clone+4,payload);put(clone+0x1c,get(node+0x1c));struct.pack_into('<2H',b,clone+0x20-D,h(b,node+0x20),h(b,node+0x22));pairs=0
    for i in range(h(b,node+0x20)):
     record=get(get(owner+0x54)+(h(b,node+0x22)+i)*4);first=get(record+16);tail=get(record+20)
     if tail==first:continue
     source=get(record+12);source+=16 if b[source+16-D]==0x80 else 48;copy(b,payload+pairs*32,source,4);copy(b,payload+pairs*32+16,first,4);pairs+=1;put(get(record+20)+4,payload+pairs*32);put(record+20,get(record+16));cache=get(record+8);reset(b,cache);trace.append(cache)
    terminate(b,payload+pairs*32);reserve(1,pairs*32+16);selected=clone
  elif get(node+0x14)&2==0 and(not owner or flags&6):selected=node
  if selected:assert emitted<=s['reservationCount'];put(table+emitted*4,selected);emitted+=1;put(selected+20,get(selected+20)|2)
  node=get(node+8)
 if emitted==0 and s['globalTail']==s['globalHead']:return b,s,-1,trace
 descriptor=reserve(4,24);s['descriptors'][s['count']]=descriptor;put(descriptor,emitted);put(descriptor+4,table)
 if s['globalTail']!=s['globalHead']:terminate(b,s['globalTail']);copy(b,descriptor+8,s['globalHead'],4);reset(b,s['globalCache']);trace.append(s['globalCache']);s['globalTail']=s['globalHead']
 else:terminate(b,descriptor+8)
 result=s['count'];s['count']+=1;return b,s,result,trace
def build(spec,index,flags,global_active):
 global memory
 memory=bytearray();control=alloc(16);cache=alloc(64,index);global_head=alloc(32,index+1);global_tail=alloc(16,index+2)if global_active else global_head;mc=spec['materials'];owner=alloc(128,index);table=alloc(mc*4,index)
 w(memory,owner+0x4c,mc);w(memory,owner+0x54,table);w(memory,owner+0x74,flags or 0)
 for i in range(mc):
  record=alloc(68,i);shader=alloc(64,i+1);command=alloc(64,i+2);first=alloc(16,i+3);tail=alloc(16,i+4)
  w(memory,table+i*4,record);w(memory,record+8,shader);w(memory,record+12,command);w(memory,record+16,first);w(memory,record+20,first if(i+index)%3==0 else tail);memory[command+16-D]=0x80 if(i+index)&1 else 0x81
 nodes=[]
 for i,(start,count)in enumerate(spec['ranges']):
  node=alloc(36,index+i);w(memory,node+0x1c,owner if flags is not None else 0);w(memory,node+0x14,0xabc00000|((i+index)%3==0)*2);struct.pack_into('<2H',memory,node+0x20-D,count,start);nodes.append(node)
 for i,p in enumerate(nodes):w(memory,p+8,nodes[i+1]if i+1<len(nodes)else 0)
 arena=alloc(0x1000+mc*80+len(nodes)*64,index+17);w(memory,control,arena+(index%32));state=dict(allocator=control,reservationCount=len(nodes)+index%4,head=nodes[0]if nodes else 0,globalCache=cache,globalHead=global_head,globalTail=global_tail,count=[0,7,23][index%3],descriptors=[0xa5000000+j*0x100 for j in range(24)])
 return bytes(memory),state
def execute(before,state,label):
 expected,s,ret,trace=model(before,state);n.write(D,before)
 for address,value in [(0x9736e0,state['allocator']),(0x973ec8,state['reservationCount']),(0x973ecc,state['head']),(0x973e78,state['globalCache']),(0x973e80,state['globalHead']),(0x973e84,state['globalTail']),(0x973ed0,state['count'])]:n.pack('<I',address,value)
 n.pack('<24I',0x973ed4,*state['descriptors']);calls.clear();actual_ret=n.call(0x5efff0,count=10000000);actual=n.read(D,len(before));actual_s=dict(state);actual_s.update(count=n.unpack('<I',0x973ed0)[0],globalTail=n.unpack('<I',0x973e84)[0],descriptors=list(n.unpack('<24I',0x973ed4)))
 assert actual==expected and actual_s==s and actual_ret==ret&0xffffffff and calls==trace,dict(label=label,nativeReturn=actual_ret,expectedReturn=ret,state=actual_s,want=s,calls=calls,trace=trace,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:15])
 counts['cases']+=1;counts['persistentBytes']+=len(before)+4*31;counts['cacheResets']+=len(trace);counts['emptyResults']+=ret==-1
 cases.append(dict(label=label,beforeZ=base64.b64encode(gzip.compress(before,mtime=0)).decode(),state=state,nativeState=actual_s,nativeReturn=ret,nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeResetCalls=trace));return actual,actual_s
for row in json.loads((R/'geometry-sorted-packets-native-validation.json').read_text())['sources']:
 raw=(B/'extracted'/row['source']).read_bytes();assert hashlib.sha256(raw).hexdigest()==row['sha256'];sources.append(row)
 for index,flags in enumerate([2,0x12,0x16,0x10]):
  before,state=build(row,index+len(sources),flags,index&1);execute(before,state,[row['source'],flags]);counts['sourceDerived']+=1
spec=dict(materials=12,ranges=[(2,6),(0,0),(8,4),(0,2),(0,12)])
for index,(flags,global_active)in enumerate(itertools.product([None,0,2,4,6,0x10,0x12,0x14,0x16,0xffffffff],[False,True])):
 for pattern in range(16):
  before,state=build(spec,index*16+pattern,flags,global_active);execute(before,state,['synthetic',flags,global_active,pattern]);counts['synthetic']+=1
for index in range(32):
 before,state=build(dict(materials=0,ranges=[]),index,None,index&1);execute(before,state,['empty-list',index]);counts['emptyList']+=1
# Repeated finalization exposes queued-node suppression and cloned-owner reuse.
for index in range(32):
 before,state=build(spec,index,[2,0x12][index&1],True);state['count']=0
 for step in range(5):before,state=execute(before,state,['sequence',index,step]);counts['sequence']+=1
fp=R/'geometry-pending-packets-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-pending-packets-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),sources=sources,errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Actual5efff0 and5fca40 execute unchanged. All ordinary/clone/skip/global-list/empty branches exercised with persistent-byte and ordered-reset comparisons.', 'Source-derived cases retain material counts and sort ranges from60 hash-verified scenes; flags, live packet payloads, arena and pointers are controlled. This is not actual loaded runtime state.', 'Finite acyclic linked nodes, disjoint valid metadata/arena and sufficient pointer/descriptor/command capacity. Pending index0..23; reservation covers selected nodes. All partial writes and untouched arena bytes retained.', 'Clone flags at+14 are ORed into existing arena bytes, not initialized. Empty results still consume the pointer-table reservation. Repeated material ranges expose sequential reset effects.', 'CPU packet structures only. GPU execution, complete frame scheduling and managed runtime equivalence remain unclaimed.'])
(R/'geometry-pending-packets-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k!='sources'},indent=2))
