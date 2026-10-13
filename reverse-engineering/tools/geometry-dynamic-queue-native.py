"""Original dynamic material queue: finite add/remove/refcount/list state."""
import importlib.util,struct,json,gzip,hashlib,random
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
BASE=0x973dbc;memory=bytearray();cases=[];calls=[];errors=[];excluded=[];counts={'cases':0,'adds':0,'removes':0,'constructs':0,'refreshes':0,'checkedBytes':0};digest=hashlib.sha256()
def u(b,p):return struct.unpack_from('<I',b,p-BASE)[0]
def h(b,p):return struct.unpack_from('<H',b,p-BASE)[0]
def w(b,p,v):struct.pack_into('<I',b,p-BASE,v&0xffffffff)
def wh(b,p,v):struct.pack_into('<H',b,p-BASE,v&65535)
def signed(x):return x-0x100000000 if x>=0x80000000 else x
def hs(x):return x-65536 if x>=32768 else x
def key(b,p):return ((hs((h(b,p)<<4)&65535)>>8)*0x20000+hs(h(b,p+0x76)))&0xffffffff
def alloc(size):
 p=(len(memory)+15)&~15;memory.extend(bytes(p-len(memory)));memory.extend(bytes(size));return BASE+p
def observe(mu,a,size,_):calls.append(a)
for a in [0x5de440,0x5de390,0x5de100,0x603440,0x603450,0x603460,0x603480,0x603490,0x5c12e0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def compare(a,e,label):
 counts['checkedBytes']+=len(a);digest.update(a);digest.update(e)
 if a!=e and len(errors)<20:errors.append({'context':label,'offsets':[i for i,(x,y)in enumerate(zip(a,e))if x!=y][:20]})
def refresh(b,trace):
 trace.append(0x5de390);nodes=u(b,BASE+0x64);table=u(b,BASE+0x50);total=sum(h(b,nodes+i*36+0x20)for i in range(u(b,BASE+0x60)))
 for i in range(u(b,BASE+0x60)):
  node=nodes+i*36
  if h(b,node+0x20):
   for j in range(total):
    if key(b,u(b,table+j*4))==u(b,node):wh(b,node+0x22,j);break
def construct(b,p,material,trace):
 trace.extend([0x5de100,0x603440,0x603450,0x603460,0x603480,0x603490]);b[p-BASE]=0x85;b[p-BASE+1]=1;w(b,p+4,p+112)
 for off in [16,32,48,64,80]:b[p-BASE+off]=0x80 if off==48 else 0x87;b[p-BASE+off+1]=3 if off==48 else 0;w(b,p+off+4,material if off==48 else 0)
 b[p-BASE+96]=0x8b;b[p-BASE+97]=1;w(b,p+100,p+112);b[p-BASE+112]=0x84;b[p-BASE+113]=4;w(b,p+116,0)
def flush(before):
 b=bytearray(before);trace=[0x5de440];get=lambda off:u(b,BASE+off);put=lambda off,v:w(b,BASE+off,v)
 if not(get(0x90)or get(0x98)):return bytes(b),trace
 cap=get(0x4c);mt=get(0x50);rt=get(0x54);refs=get(0xa0);nodes=get(0x64);pool=get(0xa8);used=get(0xb0)
 def reindex():
  for i in range(cap):
   if b[refs-BASE+i]:w(b,u(b,u(b,mt+i*4)+0x3c)+4,i)
 for qi in range(get(0x98)):
  material=u(b,get(0x9c)+qi*4)
  if not u(b,material+0x3c):continue
  found=next((i for i in range(cap)if u(b,mt+i*4)==material),None)
  if found is None:continue
  b[refs-BASE+found]=(b[refs-BASE+found]-1)&255
  if b[refs-BASE+found]:continue
  order=key(b,material);si=-1
  for i in range(get(0x60)):
   if u(b,nodes+i*36)==order:si=i
  if si<0:raise ValueError('Missing removal sort record')
  node=nodes+si*36;command=u(b,u(b,material+0x3c)+0xc);removed=False
  if u(b,node+4)==command:w(b,node+4,u(b,command+116));removed=True
  else:
   for i in range(h(b,node+0x20)):
    candidate=u(b,u(b,u(b,mt+(h(b,node+0x22)+i)*4)+0x3c)+0xc)
    if u(b,candidate+116)==command:w(b,candidate+116,u(b,command+116));removed=True;break
  if removed:b[command-BASE+113]=4;w(b,command+116,0);b[command-BASE+112]=0x84
  for i in range(cap):
   if b[used-BASE+i]and command==pool+i*128:b[used-BASE+i]=0;break
  wh(b,node+0x20,h(b,node+0x20)-1)
  if h(b,node+0x20)==0:
   prev=0;current=get(0x110);seen=set()
   while current!=node:
    if not current or current in seen:raise ValueError('Removal node absent/cyclic')
    seen.add(current);prev=current;current=u(b,current+8)
   if not prev:put(0x110,u(b,current+8))
   else:w(b,prev+8,u(b,current+8))
   put(0x10c,get(0x10c)-1)
   for i in range(si,get(0x60)-1):
    for j in range(9):w(b,nodes+i*36+j*4,u(b,nodes+(i+1)*36+j*4))
   put(0x60,get(0x60)-1)
  saved=u(b,rt+found*4)
  for i in range(found,cap-1):w(b,mt+i*4,u(b,mt+(i+1)*4));w(b,rt+i*4,u(b,rt+(i+1)*4));b[refs-BASE+i]=b[refs-BASE+i+1]
  w(b,rt+(cap-1)*4,saved);b[refs-BASE+cap-1]=0;reindex();refresh(b,trace);w(b,material+0x3c,0)
 put(0x98,0)
 for qi in range(get(0x90)):
  material=u(b,get(0x94)+qi*4);found=next((i for i in range(cap)if u(b,mt+i*4)==material),None)
  if found is not None:b[refs-BASE+found]=(b[refs-BASE+found]+1)&255;continue
  free=next((i for i in range(cap)if b[refs-BASE+i]==0),None);slot=next((i for i in range(cap)if b[used-BASE+i]==0),None)
  if free is None or slot is None:raise ValueError('Capacity exhausted')
  b[used-BASE+slot]=1;order=key(b,material);si=-1
  for i in range(get(0x60)):
   if u(b,nodes+i*36)==order:si=i
  pos=next((i for i in range(cap)if b[refs-BASE+i]and signed(order)<=signed(key(b,u(b,mt+i*4)))),free);saved=u(b,rt+(cap-1)*4)
  for i in range(cap-2,pos-1,-1):w(b,mt+(i+1)*4,u(b,mt+i*4));w(b,rt+(i+1)*4,u(b,rt+i*4));b[refs-BASE+i+1]=b[refs-BASE+i]
  w(b,rt+pos*4,saved);b[refs-BASE+pos]=0;reindex();b[refs-BASE+pos]=1;record=u(b,rt+pos*4);w(b,material+0x3c,record);command=pool+slot*128;construct(b,command,material,trace);w(b,mt+pos*4,material);w(b,record+0xc,command);w(b,record+0x18,command+96);w(b,record,BASE);w(b,record+4,pos)
  if si<0:
   si=get(0x60)
   if si>=600:raise ValueError('Sort capacity exceeded')
   node=nodes+si*36;w(b,node,order);w(b,node+4,command);w(b,node+0x18,get(0xa4));wh(b,node+0x20,0);prev=0;current=get(0x110);seen=set()
   while current and signed(order)>signed(u(b,current)):
    if current in seen:raise ValueError('Insert list cyclic')
    seen.add(current);prev=current;current=u(b,current+8)
   w(b,node+8,current)
   if not prev:put(0x110,node)
   else:w(b,prev+8,node)
   put(0x10c,get(0x10c)+1);put(0x60,get(0x60)+1)
  else:
   node=nodes+si*36
   if pos==0 or key(b,u(b,mt+(pos-1)*4))!=order:
    b[command-BASE+112]=0x8d;w(b,command+116,u(b,node+4));b[command-BASE+113]=1;w(b,node+4,command)
   else:
    previous=u(b,u(b,u(b,mt+(pos-1)*4)+0x3c)+0xc);nextPointer=u(b,previous+116);b[command-BASE+112]=0x8d;w(b,command+116,nextPointer);b[command-BASE+113]=1;w(b,previous+116,command)
  wh(b,nodes+si*36+0x20,h(b,nodes+si*36+0x20)+1);refresh(b,trace)
 put(0x90,0);return bytes(b),trace
def setup(capacity,materials):
 global memory
 memory=bytearray(0x200);mt=alloc(capacity*4);rt=alloc(capacity*4);nodes=alloc(600*36);adds=alloc(300*4);removes=alloc(300*4);refs=alloc(capacity);pool=alloc(capacity*128);used=alloc(capacity)
 for off,value in [(0x4c,capacity),(0x50,mt),(0x54,rt),(0x60,0),(0x64,nodes),(0x94,adds),(0x9c,removes),(0xa0,refs),(0xa4,0x12345678),(0xa8,pool),(0xac,0),(0xb0,used)]:w(memory,BASE+off,value)
 for i in range(capacity):w(memory,rt+i*4,alloc(68))
 pointers=[]
 for layer,priority in materials:
  material=alloc(120);wh(memory,material,(layer&255)<<4);wh(memory,material+0x76,priority);pointers.append(material)
 return pointers
def run(adds,removes,materials,label):
 global memory
 addp=u(memory,BASE+0x94);remp=u(memory,BASE+0x9c)
 for i,ix in enumerate(adds):w(memory,addp+i*4,materials[ix])
 for i,ix in enumerate(removes):w(memory,remp+i*4,materials[ix])
 w(memory,BASE+0x90,len(adds));w(memory,BASE+0x98,len(removes));before=bytes(memory)
 try:expected,trace=flush(before)
 except ValueError as modelError:
  n.write(BASE,before);n.pack('<3I',0x80baa8,8,6,7);calls.clear()
  try:
   n.call(0x5de440,count=100000);errors.append({'context':label,'modelError':str(modelError),'native':'completed; model requires investigation'})
  except RuntimeError as nativeError:excluded.append({'context':label,'modelError':str(modelError),'nativeError':str(nativeError),'before':before.hex()})
  return False
 n.write(BASE,before);n.pack('<3I',0x80baa8,8,6,7);calls.clear();n.call(0x5de440,count=5000000);after=n.read(BASE,len(before));compare(after,expected,label);compare(struct.pack('<'+'I'*len(calls),*calls),struct.pack('<'+'I'*len(trace),*trace),['calls',label]);counts['cases']+=1;counts['adds']+=len(adds);counts['removes']+=len(removes);counts['constructs']+=calls.count(0x5de100);counts['refreshes']+=calls.count(0x5de390);cases.append({'label':label,'before':before.hex(),'nativeSHA256':hashlib.sha256(after).hexdigest(),'nativeCalls':list(calls)});memory=bytearray(after)
materials=[(-2,-32768),(-1,0),(0,0),(0,0),(0,1),(1,0),(127,32767),(-128,-1)]
sequences=[([0,1,2,3,4],[],[3,2,4],[]),([4,3,2,1,0],[],[0,1,3],[]),([2,3,2,3],[],[2,3,2,3],[]),([6,7,1,5],[],[5,7],[]),([1],[],[1],[1]),([2]*255,[],[],[3]),([2]*256,[],[],[])]
for si,(first,firstRemove,secondRemove,lastAdd)in enumerate(sequences):
 ptrs=setup(12,materials);run([],[],ptrs,[si,'empty']);run(first,firstRemove,ptrs,[si,'first']);run(lastAdd,secondRemove,ptrs,[si,'second'])
# Independent short sequences avoid inferring structural compaction validity
# beyond the exact reachable queue states. Every saved input is replayable.
rng=random.Random(90210)
for i in range(64):
 ptrs=setup(12,materials);selection=rng.sample(range(8),rng.randrange(1,8));run(selection,[],ptrs,['random',i,'insert']);repeated=[rng.choice(selection)for _ in range(rng.randrange(1,8))];run(repeated,[],ptrs,['random',i,'reference']);run([],repeated,ptrs,['random',i,'dereference'])
for capacity in [0,1,2,3,4,8,16,32,64]:
 ptrs=setup(capacity,materials);run([],list(range(8)),ptrs,['capacity',capacity,'unbound-removes'])
 if capacity:
  run([2],[],ptrs,['capacity',capacity,'insert']);run([2],[],ptrs,['capacity',capacity,'retain']);run([],[2,2],ptrs,['capacity',capacity,'remove']);run([2],[],ptrs,['capacity',capacity,'readd'])
 # A non-null attachment absent from the table is a no-op removal path.
 if capacity:
  ptrs=setup(capacity,materials);w(memory,ptrs[7]+0x3c,u(memory,u(memory,BASE+0x54)));run([],[7],ptrs,['capacity',capacity,'bound-absent'])
fp=R/'geometry-dynamic-queue-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases,'excludedUnsafe':excluded},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-dynamic-queue-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'errors':errors,'excludedUnsafeCases':[{k:v for k,v in row.items()if k!='before'}for row in excluded],'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'resultSHA256':digest.hexdigest(),'bounds':['Fixed original packet constants8/6/7. Tested slot capacities0/1/2/3/4/8/12/16/32/64 and eight material records; sort capacity600 is an original branch bound.','Valid nonnull material queues; free slot/packet availability; sorted-node removals reachable without invalid list traversal.','Original command constructor,setters,range refresh and entire queue execute unchanged. Only observation hooks.','No managed execution or GPU command consumption.']};(R/'geometry-dynamic-queue-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))

