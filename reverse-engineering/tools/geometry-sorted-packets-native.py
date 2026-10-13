"""Original sorted material command relinking and command append checks."""
import importlib.util,struct,json,hashlib,gzip,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
BASE=0x11000000;SIZE=0x2000000;n.mu.mem_map(BASE,SIZE);memory=bytearray();calls=[];errors=[];cases=[];sources=[];counts={'authored':0,'boundaries':0,'append':0,'checkedBytes':0,'shaderNoopCalls':0,'processedMaterials':0};digest=hashlib.sha256()
def u(b,p):return struct.unpack_from('<I',b,p)[0]
def h(b,p):return struct.unpack_from('<H',b,p)[0]
def w(b,p,v):struct.pack_into('<I',b,p,v&0xffffffff)
def seq(size,seed):return bytes(((i*37+seed*19)^(i>>3))&255 for i in range(size))
def alloc(size,seed=0):
 p=(len(memory)+15)&~15;memory.extend(bytes(p-len(memory)));memory.extend(seq(size,seed));return BASE+p
def read(p):return u(memory,p-BASE)
def write(p,v):w(memory,p-BASE,v)
def observe(mu,a,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==0x607590:calls.append([a,*n.unpack('<2I',sp+4)])
 else:calls.append([a])
for a in [0x5e0d00,0x5fca40,0x5fca70,0x5fca80,0x607590,0x5fd100,0x6034b0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def compare(a,e,label):
 counts['checkedBytes']+=len(a);digest.update(a);digest.update(e)
 if a!=e and len(errors)<20:errors.append({'context':label,'firstOffsets':[i for i,(x,y)in enumerate(zip(a,e))if x!=y][:16],'actualSize':len(a),'expectedSize':len(e)})
def resetctx(b,p):
 w(b,p+8,0);w(b,p+0x14,0xffffffff);w(b,p+0x20,0xffffffff)
 for o in [0x24,0x2c,0x2e,0x1e]:struct.pack_into('<H',b,p+o,65535)
def resetshader(b,p,g):
 for o in [0xf4,0x100,0x168,0x34,0x110,0x180,0x198]:w(b,p+o,0)
 resetctx(b,g)
def complete_model(before,head,registered,globalp):
 b=bytearray(before);get=lambda p:u(b,p-BASE);put=lambda p,v:w(b,p-BASE,v);trace=[[0x5e0d00],[0x5fca40]];lastShader=0;node=head;visited=set();processed=0
 while node:
  if node in visited:raise ValueError('Cyclic fixture')
  visited.add(node);owner=get(node+0x1c)
  if not owner:trace.append([0x5fca80])
  elif get(owner+0x74)&6:
   for j in range(h(b,node-BASE+0x20)):
    index=h(b,node-BASE+0x22)+j;record=get(get(owner+0x54)+index*4);control=get(record+0x0c)
    if b[control-BASE+1]:continue
    processed+=1;material=get(get(owner+0x50)+index*4);shader=get(owner+0x80)
    if not shader or not(get(owner+0x74)&4):lastShader=0
    elif get(record+0x14)!=get(record+0x10)or lastShader!=shader:
     trace.append([0x607590,record,shader])
     if get(get(record+8)+0x20)!=get(shader+0x20):raise ValueError('Fixture crosses unknown shader emission gate')
     lastShader=get(owner+0x80)
    first=get(record+0x10);tail=get(record+0x14);saved=get(record+0x18);slot=get(record+0x34);start=get(record+0x28+slot*4);current=get(record+0x30)
    if tail==first:
     if start==current:put(saved+4,saved+16)
     else:put(saved+4,start);b[current-BASE]=0x8d;b[current-BASE+1]=1;put(current+4,saved+16)
    else:
     for k in range(4):put(saved+k*4,get(first+k*4))
     if not(get(owner+0x74)&4):put(tail+4,get(control+4));put(record+0x14,get(record+0x10))
     else:
      if start!=current:put(tail+4,start);b[current-BASE]=0x8d;b[current-BASE+1]=1;put(current+4,saved+16)
      put(record+0x14,get(record+0x10))
    trace.append([0x5fca70]);mask=(get(owner+0x74)>>5)&255
    if mask and(mask&((get(material+0x44)>>14)&255)):
     b[control-BASE+1]=1;materialIndex=get(record+4);bp=get(owner+0x58+((get(owner+0x74)>>15)&1)*4)+materialIndex//8;b[bp-BASE]&=~(1<<(materialIndex&7))&255
  node=get(node+8)
 for owner in registered:
  shader=get(owner+0x80)
  if shader:trace.append([0x5fd100]);resetshader(b,shader-BASE,globalp-BASE)
 return bytes(b),trace,processed
def run_complete(label,head,registered,globalp,kind):
 before=bytes(memory);n.write(BASE,before);n.write(0x9868a0,before[globalp-BASE:globalp-BASE+420]);n.pack('<I',0x973ecc,head);n.pack('<I',0x9739b8,len(registered))
 for i,p in enumerate(registered):n.pack('<I',0x9739bc+i*4,p)
 expected,trace,processed=complete_model(before,head,registered,globalp);calls.clear();n.call(0x5e0d00,count=10000000);after=bytearray(n.read(BASE,len(before)));after[globalp-BASE:globalp-BASE+420]=n.read(0x9868a0,420);compare(bytes(after),expected,label);compare(json.dumps(calls).encode(),json.dumps(trace).encode(),[label,'callOrder']);counts[kind]+=1;counts['processedMaterials']+=processed;counts['shaderNoopCalls']+=sum(c[0]==0x607590 for c in calls);cases.append({'kind':'complete','label':label,'before':before.hex(),'head':head,'registered':registered,'global':globalp,'nativeSHA256':hashlib.sha256(after).hexdigest(),'nativeCalls':list(calls)})
def scene(spec,pattern,flags,shaderPresent=True):
 owner=alloc(0x94,pattern);table=alloc(len(spec['materials'])*4);records=alloc(len(spec['materials'])*4);shader=alloc(420,pattern+1)if shaderPresent else 0;bits=[alloc((len(spec['materials'])+7)//8+16,pattern+p)for p in range(2)]
 write(owner+0x4c,len(spec['materials']));write(owner+0x50,table);write(owner+0x54,records);write(owner+0x58,bits[0]);write(owner+0x5c,bits[1]);write(owner+0x74,flags);write(owner+0x80,shader)
 if shader:write(shader+0x20,0x87654321)
 for i,mflag in enumerate(spec['materials']):
  material=alloc(0x48,i);record=alloc(68,i+1);context=alloc(52,i+2);control=alloc(16,i+3);first=alloc(32,i+4);tail=alloc(16,i+5);saved=alloc(32,i+6);start0=alloc(32,i+7);start1=alloc(32,i+8);current=alloc(16,i+9);slot=(i+pattern)&1;chosen=[start0,start1][slot]
  write(material+0x44,mflag);write(table+i*4,material);write(records+i*4,record);write(record+4,spec['indices'][i]);write(record+8,context);write(context+0x20,0x87654321);write(record+0xc,control);write(record+0x10,first);write(record+0x14,first if(i+pattern)&2==0 else tail);write(record+0x18,saved);write(record+0x28,start0);write(record+0x2c,start1);write(record+0x30,chosen if(i+pattern)&4==0 else current);write(record+0x34,slot);memory[control-BASE+1]=[0,0,1,255][(i+pattern)%4]
 nodes=[]
 for i,(start,count)in enumerate(spec['ranges']):
  node=alloc(36,i);write(node+0x1c,owner);struct.pack_into('<2H',memory,node-BASE+0x20,count,start);nodes.append(node)
 for i,p in enumerate(nodes):write(p+8,nodes[i+1]if i+1<len(nodes)else 0)
 return owner,nodes
sourceRows=json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']
for si,sr in enumerate(sourceRows):
 raw=(B/'extracted'/sr['source']).read_bytes();render=json.loads((B/'exports/geometry/scene-runtime'/(sr['source']+'.json')).read_text())['renderState'];a=render['address']
 def ptr(q):
  d=struct.unpack_from('<i',raw,q)[0];return q+d if d else 0
 mc=u(raw,a+0x4c);mt=ptr(a+0x50);rt=ptr(a+0x54);dc=u(raw,a+0x60);dp=ptr(a+0x64);spec={'materials':[u(raw,ptr(mt+i*4)+0x44)for i in range(mc)],'indices':[u(raw,ptr(rt+i*4)+4)for i in range(mc)],'ranges':[(h(raw,dp+i*36+0x22),h(raw,dp+i*36+0x20))for i in range(dc)]}
 if any(start+count>mc for start,count in spec['ranges'])or any(i>=mc for i in spec['indices']):raise ValueError('Authored material range/index invalid')
 sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'materials':mc,'sortRecords':dc,'ranges':spec['ranges']})
 for pattern in range(4):
  memory=bytearray();gp=alloc(420,39);flags=[2,4,6,0][pattern]|0x4000|((pattern&1)<<15)|([0,1,0x55,255][pattern]<<5);owner,nodes=scene(spec,pattern,flags);run_complete([sr['source'],pattern],nodes[0]if nodes else 0,[owner],gp,'authored')
 if(si+1)%10==0:print('authored',si+1,flush=True)
# Synthetic ranges, cached-shader reuse across owners, dirty/control/mask gates.
for flags,shaderPresent,pattern in itertools.product([0,2,4,6,0x24,0x1fe4,0x2004,0x8004],[False,True],range(4)):
 memory=bytearray();gp=alloc(420,39);spec={'materials':[0,0x4000,0x3fc000,0x400000]*3,'indices':list(range(12)),'ranges':[(2,6),(0,0),(8,4),(0,2)]};o1,n1=scene(spec,pattern,flags,shaderPresent);o2,n2=scene(spec,pattern+1,flags^2,shaderPresent)
 # Exercise same shader identity across distinct owners; cache persists.
 if shaderPresent and pattern&1:write(o2+0x80,read(o1+0x80))
 free=alloc(36,67);write(free+0x1c,0);write(free+8,n2[0]);write(n1[-1]+8,free);run_complete(['boundary',flags,shaderPresent,pattern],n1[0],[o1,o2],gp,'boundaries')
# Original append helper; low byte of requested type, aligned allocation, explicit
# or inline resource, unchanged padding, tail write and pointer-control return.
for align,typeCode,payloadPresent in itertools.product(range(16),[0,0x94,0x1ff,0xffffffff],[False,True]):
 memory=bytearray();control=alloc(4,1);record=alloc(68,2);tail=alloc(16,3);saved=alloc(32,4);packet=alloc(96,5);payload=alloc(16,6)if payloadPresent else 0;write(control,packet+align);write(record+0x14,tail);write(record+0x18,saved);before=bytes(memory);expected=bytearray(before);new=(packet+align+15)&~15;w(expected,tail-BASE+4,new);expected[new-BASE]=typeCode&255;expected[new-BASE+1]=3;w(expected,new-BASE+4,payload or new+32);expected[new-BASE+16]=0x8d;expected[new-BASE+17]=1;w(expected,new-BASE+20,saved+16);w(expected,record-BASE+0x14,new+16);w(expected,control-BASE,new+32);expectedReturn=0 if payload else control;n.write(BASE,before);n.pack('<I',0x9736e0,control);calls.clear();ret=n.call(0x6034b0,args=[record,typeCode,payload]);after=n.read(BASE,len(before));compare(after,bytes(expected),['append',align,typeCode,payloadPresent]);compare(struct.pack('<I',ret),struct.pack('<I',expectedReturn),['appendReturn',align,typeCode,payloadPresent]);counts['append']+=1;cases.append({'kind':'append','before':before.hex(),'control':control,'record':record,'type':typeCode,'payload':payload,'nativeReturn':ret,'nativeSHA256':hashlib.sha256(after).hexdigest(),'nativeCalls':list(calls)})
fp=R/'geometry-sorted-packets-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-sorted-packets-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'resultSHA256':digest.hexdigest(),'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'boundaries':{'0x607590':'Original called unchanged; context+0x20 matches shader+0x20 so documented early-return gate is selected. Mutating shader emission branches excluded.','0x5fca70/0x5fca80':'Original instructions are literal returns and execute unchanged.','native':'All tested helpers execute unchanged; entry hooks only observe.','authored':'Material flags/index maps and ushort sort ranges are authored. Packet cursors and links are controlled valid runtime state; not a recorded live game frame.'},'limits':['Source coverage60 portal scenes only.','Finite acyclic lists; nonnegative in-range material indices and 0/1 packet slots.','No managed executable or GPU invocation.','Dynamic list flush and mutating shader cache emission remain separate.']}
(R/'geometry-sorted-packets-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in ['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))

