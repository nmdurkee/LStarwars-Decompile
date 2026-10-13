"""Native material clone cache; constructor/refresh are explicit services."""
import importlib.util,json,struct,gzip,hashlib,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';sp=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx);n=nx.NativeX86();BASE=n.DATA;SIZE=0xb000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDI
container=BASE+0x100;source=BASE+0x400;layoutArray=BASE+0x800;templates=[BASE+0x2000+i*0x400 for i in range(3)];clones=[BASE+0x8000+i*0x300 for i in range(8)];calls=[];declarations=[];allocated=0;currentOptions={};errors=[];cases=[];sources=[];excluded=[];counts={'next':0,'node':0,'find':0,'ensure':0,'merge':0,'allocations':0,'declarationCacheCalls':0,'checkedBytes':0,'authoredMaterials':0}
def u(b,p):return struct.unpack_from('<I',b,p-BASE)[0]
def w(b,p,v):struct.pack_into('<I',b,p-BASE,v&0xffffffff)
def hh(b,p):return struct.unpack_from('<H',b,p-BASE)[0]
def wh(b,p,v):struct.pack_into('<H',b,p-BASE,v&65535)
def nextnode(b,c,previous):
 p=u(b,c+8 if not previous else previous-12);return p+16 if p else 0
def allocate(b,c,thread):
 p=u(b,c)
 if not p:return 0
 assert u(b,c+24)==thread
 q=u(b,p+4);w(b,c,q)
 if q:w(b,q+8,0)
 else:w(b,c+4,0)
 active=u(b,c+8);w(b,p+4,active)
 if active:w(b,active+8,p)
 else:w(b,c+12,p)
 w(b,p+8,0);wh(b,c+22,hh(b,c+22)+1);w(b,c+8,p);wh(b,p+14,hh(b,p+14)|1);return p+16
def find(b,replacement,layout):
 p=nextnode(b,container,0);seen=set()
 while p:
  assert p not in seen;seen.add(p)
  if u(b,p+4)==replacement and u(b,u(b,p)+0x1f0)==layout:return u(b,p)
  p=nextnode(b,container,p)
 return 0
def declaration(layout):return(layout^0x76543210)&0xffffffff
def refresh(b,clone,o):
 layout=u(b,clone+0x1f0);w(b,clone+0x1f0,layout^o['refreshXor']);wh(b,clone+0x2c0,o['counter']);w(b,clone+0x2b8,0xface1234)
def model(kind,before,a,o):
 b=bytearray(before);trace=[];count=0;ret=None
 def ensure(replacement,layouts,amount):
  nonlocal count
  current=replacement
  for i in range(max(0,amount)):
   layout=u(b,layouts+i*4)
   if find(b,current,layout):continue
   node=allocate(b,container,o['thread']);assert node
   clone=clones[count];count+=1;trace.append([0x5e4b20,1,1,o['typeWord']]);w(b,node,clone);w(b,node+4,current);w(b,node+8,layout);save28=u(b,clone+0x28);save2c=u(b,clone+0x2c);b[clone-BASE:clone-BASE+708]=b[current-BASE:current-BASE+708]
   wh(b,clone+0x1f6,0);wh(b,clone+0x1f4,0);w(b,clone+0x2c,save2c);w(b,clone+0x28,save28);wh(b,clone,hh(b,clone)|1);w(b,clone+0x1f0,layout);trace.append([0x7418c0,layout]);w(b,clone+0x2bc,declaration(layout));trace.append([0x601030,clone]);refresh(b,clone,o);wh(b,clone+0x2c0,hh(b,clone+0x2c0)+1)
 if kind=='next':ret=nextnode(b,container,a[0])
 elif kind=='node':ret=allocate(b,container,o['thread'])
 elif kind=='find':ret=find(b,a[0],a[1])
 elif kind=='ensure':ensure(a[0],a[1],a[2]if a[2]<0x80000000 else a[2]-0x100000000)
 else:
  ret=find(b,a[1],u(b,a[0]+0x1f0))
  if not ret:ensure(a[1],a[0]+0x1f0,1);ret=find(b,a[1],u(b,a[0]+0x1f0))
 return b,ret,trace,count
def skip(mu,value=0):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret);mu.reg_write(UC_X86_REG_EAX,value)
def hook(mu,address,size,_):
 global allocated
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x5e4b20:
  calls.append([address,n.unpack('<I',sp+4)[0],mu.reg_read(UC_X86_REG_ECX),mu.reg_read(UC_X86_REG_EAX)]);clone=clones[allocated];allocated+=1;skip(mu,clone)
 elif address==0x601030:
  clone=n.unpack('<I',sp+4)[0];calls.append([address,clone]);b=bytearray(n.read(BASE,SIZE));refresh(b,clone,currentOptions);n.write(BASE,b);skip(mu)
 else:layout=n.unpack('<I',sp+4)[0];calls.append([address,layout]);declarations.append(layout)
for address in[0x5e4b20,0x601030,0x7418c0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def setup(raw,seed,active=0,free=8):
 b=bytearray(SIZE)
 for ti,p in enumerate(templates):b[p-BASE:p-BASE+708]=raw
 for i,p in enumerate(clones):b[p-BASE:p-BASE+708]=bytes([0xcd])*708;w(b,p+0x28,templates[(i+1)%3]);w(b,p+0x2c,0xaabb0000+i)
 nodes=[BASE+0x1000+i*0x40 for i in range(free)];used=[BASE+0x1800+i*0x40 for i in range(active)]
 for group,headOff,tailOff in[(nodes,0,4),(used,8,12)]:
  w(b,container+headOff,group[0]if group else 0);w(b,container+tailOff,group[-1]if group else 0)
  for i,p in enumerate(group):w(b,p+4,group[i+1]if i+1<len(group)else 0);w(b,p+8,group[i-1]if i else 0);wh(b,p+14,0xa004+i)
 for i,p in enumerate(used):
  clone=BASE+0x6000+i*0x300;w(b,p+16,clone);w(b,p+20,templates[i%3]);w(b,p+24,0xdeadbeef);w(b,clone+0x1f0,[0,0xffffffff,0x80000000,7][i%4])
 thread=(0x76540000+seed)&0xffffffff;w(b,container+24,thread);wh(b,container+22,65535 if seed&1 else active);o={'thread':thread,'typeWord':(0xa5000000+seed)&0xffffffff,'refreshXor':0,'counter':[0,1,65535,32767][seed%4]};w(b,source+0x1f0,struct.unpack_from('<I',raw,0x1f0)[0]);w(b,layoutArray,11);w(b,layoutArray+4,22);w(b,layoutArray+8,33);return b,o
def prepare(b,o):
 global allocated,currentOptions
 currentOptions=o;allocated=0;calls.clear();declarations.clear();n.write(BASE,b);n.pack('<I',0x973ff8,container);n.pack('<I',0x973ff4,o['typeWord']);n.pack('<I',0x297ad54,o['thread']);keys=sorted(set([u(b,source+0x1f0)]+[u(b,layoutArray+i*4)for i in range(3)]+[u(b,t+0x1f0)for t in templates]));n.pack('<I',0x297cc70,len(keys));n.write(0x297cc78,b''.join(struct.pack('<2I',key,declaration(key))for key in keys));return keys
def run(kind,b,a,o,label):
 expected,ret,trace,allocatedExpected=model(kind,b,a,o);keys=prepare(b,o);entry={'next':0x547580,'node':0x5471c0,'find':0x5e4ee0,'ensure':0x5e4f30,'merge':0x5e5020}[kind]
 if kind=='next':actualRet=n.call(entry,args=[container,a[0]])
 elif kind=='node':actualRet=n.call(entry,args=[container])
 elif kind=='find':actualRet=n.call(entry,args=[a[1]],regs={UC_X86_REG_EDI:a[0]})
 else:actualRet=n.call(entry,args=a)
 actual=n.read(BASE,SIZE)
 for field,av,ev in[('memory',actual,bytes(expected)),('return',actualRet if ret is not None else None,ret),('services',calls,trace),('allocations',allocated,allocatedExpected),('declarationCount',n.unpack('<I',0x297cc70)[0],len(keys))]:
  if av!=ev and len(errors)<20:errors.append({'kind':kind,'label':label,'field':field,'native':av if field!='memory'else None,'model':ev if field!='memory'else None,'offsets':[i for i,(v,x)in enumerate(zip(av,ev))if v!=x][:20]if field=='memory'else None})
 counts[kind]+=1;counts['checkedBytes']+=SIZE;counts['allocations']+=allocated;counts['declarationCacheCalls']+=len(declarations);cases.append({'kind':kind,'label':label,'before':bytes(b).hex(),'args':a,'options':o,'nativeSHA256':hashlib.sha256(actual).hexdigest(),'nativeReturn':actualRet if ret is not None else None,'nativeServices':list(calls)})
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
for si,sr in enumerate(json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']):
 raw=(B/'extracted'/sr['source']).read_bytes();data=json.loads((B/index[sr['source']]['report']).read_text());ms=[m for m in data['materials']if m['recordSize']==708];selected=ms[::max(1,len(ms)//8)][:8];indices=[]
 for mi,mat in enumerate(selected):
  template=raw[mat['address']:mat['address']+708];b,o=setup(template,si*8+mi);run('merge',b,[source,templates[0]],o,[sr['source'],mat['index'],'miss']);expected,_,_,_=model('merge',b,[source,templates[0]],o);run('merge',expected,[source,templates[0]],o,[sr['source'],mat['index'],'hit']);indices.append(mat['index']);counts['authoredMaterials']+=1
 sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'materialIndices':indices})
 if(si+1)%10==0:print('clone sources',si+1,'errors',len(errors),flush=True)
 if errors:break
raw=bytes(708)
for active,free,seed in itertools.product([0,1,4],[0,1,8],[0,1,65535]):
 b,o=setup(raw,seed,active,free);run('node',b,[],o,['list',active,free,seed]);run('next',b,[0],o,['first',active,free,seed])
 for i in range(active):run('next',b,[BASE+0x1800+i*0x40+16],o,['next',active,i,seed])
 for replacement,layout in itertools.product(templates+[0],[0,7,0xffffffff,0x80000000,0xdeadbeef]):run('find',b,[replacement,layout],o,['find',active,replacement,layout,seed])
for count,seed,change in itertools.product([0,1,2,3,-1],[0,1,65535],[0,1]):
 b,o=setup(raw,seed);o['refreshXor']=change;run('ensure',b,[templates[0],layoutArray,count&0xffffffff],o,['ensure',count,seed,change])
# Native callback can change clone layout, so Merge's second lookup may return0.
for seed in range(8):b,o=setup(raw,seed);o['refreshXor']=1;run('merge',b,[source,templates[0]],o,['changedLayout',seed])
# Two outstanding call arguments make5e4f9a [esp+18] a local, not the
# earlier replacement argument. Zero allocator+28 must not change template.
b,o=setup(raw,0);w(b,clones[0]+0x28,0);run('ensure',b,[templates[0],layoutArray,3],o,['zeroPreserved28MultiLayout'])
fp=R/'geometry-material-clone-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases,'excluded':excluded},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-material-clone-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'excluded':[{'kind':x['kind'],'error':x['error'],'reason':x['reason']}for x in excluded],'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'limits':['Original547580/5471c0/5e4ee0/5e4f30/5e5020 execute unchanged, including original thunk5476b0. Same-thread list branch excludes synchronization callbacks.','Material constructor5e4b20 and shader refresh601030 are explicit controlled mutable services; their arguments/order are checked. No constructor/shader implementation claim.','Original7418c0 and741860 execute real prepopulated declaration-cache hits; no device creation. Cache count stays unchanged.','Authored708-byte material records supply exact copy bytes; raw pointers inside copied data are opaque at the service boundary, not a full relocation claim.','Successful finite disjoint template/clone images, bounded counts, acyclic lists and sufficient cache/material capacity. Exhausted AllocateNode standalone return0 checked.','Stack-depth audit confirms replacement remains constant across multiple layouts; zero allocator+28 regression tested. No managed/game/GPU launch.']};(R/'geometry-material-clone-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','excluded','fixtureBytes']}));raise SystemExit(bool(errors))
