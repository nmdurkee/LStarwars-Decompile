"""Original dynamic material packet constructor and range-refresh helpers."""
import importlib.util,json,gzip,struct,hashlib,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
BASE=0x11000000;n.mu.mem_map(BASE,0x2000000);memory=bytearray();calls=[];cases=[];errors=[];sources=[];counts={'setters':0,'constructors':0,'authoredRanges':0,'syntheticRanges':0,'rangeMatches':0,'checkedBytes':0};digest=hashlib.sha256()
def seq(size,seed):return bytes(((i*37+seed*19)^(i>>3))&255 for i in range(size))
def alloc(size,seed=0):
 p=(len(memory)+15)&~15;memory.extend(bytes(p-len(memory)));memory.extend(seq(size,seed));return BASE+p
def u(b,p):return struct.unpack_from('<I',b,p-BASE)[0]
def h(b,p):return struct.unpack_from('<H',b,p-BASE)[0]
def w(b,p,v):struct.pack_into('<I',b,p-BASE,v&0xffffffff)
def hs(x):return x-65536 if x>=32768 else x
def key(b,p):return (hs((h(b,p)<<4)&65535)>>8)*0x20000+hs(h(b,p+0x76))
def observe(mu,a,size,_):calls.append(a)
for a in [0x5de100,0x5de390,0x603440,0x603450,0x603460,0x603480,0x603490]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def compare(a,e,label):
 counts['checkedBytes']+=len(a);digest.update(a);digest.update(e)
 if a!=e and len(errors)<20:errors.append({'case':label,'actualSize':len(a),'expectedSize':len(e),'offsets':[i for i,(x,y)in enumerate(zip(a,e))if x!=y][:12]})
def setcommand(b,p,entry,material):
 b[p-BASE]=0x80 if entry==0x603460 else 0x87;b[p-BASE+1]=3 if entry==0x603460 else 0;w(b,p+4,material if entry==0x603460 else 0)
def run(entry,args,expected,expectedCalls,kind,meta,returnValue=None,commandCount=8):
 before=bytes(memory);n.write(BASE,before);n.pack('<I',0x80baa8,commandCount);calls.clear();ret=n.call(entry,args=args,count=3000000);after=n.read(BASE,len(before));compare(after,bytes(expected),[kind,meta]);compare(struct.pack('<'+'I'*len(calls),*calls),struct.pack('<'+'I'*len(expectedCalls),*expectedCalls),['calls',kind,meta])
 if returnValue is not None:compare(struct.pack('<I',ret),struct.pack('<I',returnValue),['return',kind,meta])
 counts[kind]+=1;cases.append({'entry':entry,'args':args,'before':before.hex(),'commandCount':commandCount,'nativeSHA256':hashlib.sha256(after).hexdigest(),'nativeCalls':list(calls),'nativeReturn':ret if returnValue is not None else None})
for entry,seed in itertools.product([0x603440,0x603450,0x603460,0x603480,0x603490],range(64)):
 memory=bytearray();packet=alloc(32,seed);material=alloc(120,seed+1);expected=bytearray(memory);setcommand(expected,packet,entry,material);run(entry,[packet,material],expected,[entry],'setters',[hex(entry),seed])
for commandCount,seed in itertools.product([1,2,6,8,16,255],range(16)):
 memory=bytearray();control=alloc(4,seed);material=alloc(120,seed+1);packet=alloc(160,seed+2);w(memory,control,packet+seed);expected=bytearray(memory);p=packet+seed;w(expected,control,p+128);expected[p-BASE]=0x85;expected[p-BASE+1]=1;w(expected,p+4,p+commandCount*16-16);trace=[0x5de100]
 for off,helper in [(16,0x603440),(32,0x603450),(48,0x603460),(64,0x603480),(80,0x603490)]:setcommand(expected,p+off,helper,material);trace.append(helper)
 expected[p-BASE+96]=0x8b;expected[p-BASE+97]=1;w(expected,p+100,p+commandCount*16-16);expected[p-BASE+112]=0x84;expected[p-BASE+113]=4;w(expected,p+116,0);run(0x5de100,[0xdeadbeef,material,control,0xbad0bad0],expected,trace,'constructors',[commandCount,seed],p,commandCount)
def ranges(materialWords,nodeWords,label,kind):
 global memory
 memory=bytearray();scene=alloc(0x80,12);table=alloc(len(materialWords)*4,13);nodes=alloc(len(nodeWords)*36,14);w(memory,scene+0x50,table);w(memory,scene+0x60,len(nodeWords));w(memory,scene+0x64,nodes)
 for i,(tag,priority)in enumerate(materialWords):
  p=alloc(120,i);struct.pack_into('<H',memory,p-BASE,tag);struct.pack_into('<H',memory,p-BASE+0x76,priority);w(memory,table+i*4,p)
 for i,(order,count,first)in enumerate(nodeWords):
  p=nodes+i*36;w(memory,p,order);struct.pack_into('<2H',memory,p-BASE+0x20,count,first)
 expected=bytearray(memory);total=sum(count for order,count,first in nodeWords)
 if total>len(materialWords):raise ValueError('Range sum exceeds table')
 for i,(order,count,first)in enumerate(nodeWords):
  if count:
   for j in range(total):
    if(key(expected,u(expected,table+j*4))&0xffffffff)==order:
     struct.pack_into('<H',expected,nodes-BASE+i*36+0x22,j&65535);counts['rangeMatches']+=1;break
 run(0x5de390,[scene],expected,[0x5de390],kind,label)
for source in json.loads((R/'geometry-sorted-packets-native-validation.json').read_text())['sources']:
 raw=(B/'extracted'/source['source']).read_bytes();a=json.loads((B/'exports/geometry/scene-runtime'/(source['source']+'.json')).read_text())['renderState']['address']
 def ru(p):return struct.unpack_from('<I',raw,p)[0]
 def ptr(p):
  d=struct.unpack_from('<i',raw,p)[0];return p+d if d else 0
 mc=ru(a+0x4c);dc=ru(a+0x60);mt=ptr(a+0x50);dp=ptr(a+0x64);m=[(struct.unpack_from('<H',raw,ptr(mt+i*4))[0],struct.unpack_from('<H',raw,ptr(mt+i*4)+0x76)[0])for i in range(mc)];nodes=[(ru(dp+i*36),struct.unpack_from('<H',raw,dp+i*36+0x20)[0],struct.unpack_from('<H',raw,dp+i*36+0x22)[0])for i in range(dc)];sources.append({'source':source['source'],'materials':mc,'sortRecords':dc,'sha256':hashlib.sha256(raw).hexdigest()})
 ranges(m,nodes,[source['source'],'authored'],'authoredRanges');ranges(list(reversed(m)),nodes,[source['source'],'reversed-table'],'authoredRanges')
for seed in range(64):
 m=[((i*61+seed*271)&65535,(i*997+seed*809)&65535)for i in range(32)];order=lambda pair:((hs((pair[0]<<4)&65535)>>8)*0x20000+hs(pair[1]))&0xffffffff
 nodes=[(order(m[i]),[0,1,2,3][i%4],0xabcd)for i in range(16)];nodes[seed%16]=(0x7fffffff,nodes[seed%16][1],0xabcd);ranges(m,nodes,['synthetic',seed],'syntheticRanges')
fp=R/'geometry-dynamic-packets-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-dynamic-packets-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'errors':errors,'sources':sources,'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'resultSHA256':digest.hexdigest(),'originalCommandCount':8,'originalSavedIndex':6,'originalLinkIndex':7,'limits':['All original helpers execute unchanged; hooks observe only.','Constructor always reserves128bytes regardless of link-index constant; reference need not be inside the packet for this writer-only contract.','Range refresh sums unsigned16 counts,searches that many material pointers,and changes only first matching node start. Nonmatching starts remain unchanged.','Finite valid tables/pointers; no managed execution or GPU consumption.']}
(R/'geometry-dynamic-packets-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))

