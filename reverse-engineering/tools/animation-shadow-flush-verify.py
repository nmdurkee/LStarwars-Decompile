"""Legacy CPU render scheduling; graphics services are exact recording boundaries."""
from pathlib import Path
import importlib.util,json,gzip,struct,random,hashlib,collections
B=Path(__file__).resolve().parent.parent;R=B/'reports';s=importlib.util.spec_from_file_location('flush_native',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86();rng=random.Random(0x5f9da0);cases=[];counts=collections.Counter();events=[];post={};D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
ARITY={0x6e5700:1,0x6e5290:1,0x6e5340:2,0x6e5630:2,0x6e5670:3,0x6e56c0:1,0x6e5590:4,0x6e4980:3,0x6e49b0:4,0x6df8b0:0,0x5e4840:2}
def sha(b):return hashlib.sha256(b).hexdigest()
def boundary(mu,a,z,u):
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*ARITY[a],sp+4))if ARITY[a]else[];events.append(dict(entry=a,args=args))
 if a==0x5e4840:
  for address,key in[(0x973fec,'vertexCount'),(0x973ff0,'groupCount'),(0x971878,'generated')]:n.pack('<I',address,post[key])
 ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret);mu.reg_write(UC_X86_REG_EAX,0xa5a5a5a5)
for address in ARITY:n.mu.hook_add(UC_HOOK_CODE,boundary,begin=address,end=address)
def emit(out,entry,*args):out.append(dict(entry=entry,args=[v&0xffffffff for v in args]))
def overlay(e,out):
 emit(out,0x6e5700,0);emit(out,0x6e5290,0)
 for k,v in[(0x1b,1),(0xe,0),(0x89,0),(0x1d,0)]:emit(out,0x6e5340,k,v)
 emit(out,0x6e5630,0,0)
 for a,b,d in[(0,1,2),(0,2,0),(0,4,2),(0,5,0),(1,1,1),(1,4,1)]:emit(out,0x6e5670,a,b,d)
 for k,v in[(0x38,e['stencil'][0]),(0x37,e['stencil'][1]),(0x39,e['stencil'][2]),(7,0),(0x16,1),(0xab,1),(0x13,5),(0x14,6)]:emit(out,0x6e5340,k,v)
 emit(out,0x6e56c0,e['overlayShader']);emit(out,0x6e5590,0,e['overlayBuffer'],0,0x1c);emit(out,0x6e4980,6,0,2)
def draw(e,out,vc,gc):
 emit(out,0x6e56c0,e['volumeShader'])
 for k,v in[(0xe,0),(0x1b,1),(0x13,1),(0x14,2),(7,1),(0x36,1),(0x34,1),(0x38,8),(0x37,4),(0x39,1),(0x16,3)]:emit(out,0x6e5340,k,v)
 for passIndex in range(2):
  if passIndex:
   emit(out,0x6e5340,0x16,2);emit(out,0x6e5340,0x37,5)
  for i in range(0,vc,4):emit(out,0x6e49b0,6,2,0x963f94+i*16,16)
  for i in range(gc):emit(out,0x6e49b0,6,e['edges'][i]-2,0x963f94+e['starts'][i]*16,64)
def model(kind,e):
 out=[];result=dict(vertexCount=e['vertexCount'],groupCount=e['groupCount'],generated=e['generated'],queueCount=e['queueCount'])
 if kind=='overlay':overlay(e,out)
 elif kind=='draw':draw(e,out,result['vertexCount'],result['groupCount'])
 else:
  if e['enabled']and e['mode']==1 and e['queueCount']!=0:
   emit(out,0x6e5700,0);emit(out,0x6e5290,0);emit(out,0x6e5340,15,0);emit(out,0x6e5340,23,4);emit(out,0x6e5630,0,0);emit(out,0x6df8b0);emit(out,0x5e4840,128,0);result.update(e['post']);draw(e,out,result['vertexCount'],result['groupCount']);overlay(e,out)
   for k,v in[(7,1),(0x34,0),(14,1),(0x1b,0),(0x16,3)]:emit(out,0x6e5340,k,v)
   result['vertexCount']=0;result['groupCount']=0
  result['queueCount']=0
 return out,result
GLOBAL=[(0x8264c4,'enabled','B'),(0x8264bc,'mode','i'),(0x973fe8,'queueCount','i'),(0x973fec,'vertexCount','I'),(0x973ff0,'groupCount','I'),(0x971878,'generated','I'),(0x2854c04,'volumeShader','I'),(0x2976c74,'overlayShader','I'),(0x2854bf0,'overlayBuffer','I')]
def setup(i):
 starts=[rng.getrandbits(32)for j in range(250)];edges=[rng.getrandbits(32)for j in range(250)];edges[:8]=[0,1,2,3,4,8,10,0xffffffff]
 return dict(enabled=[0,1,128,255][i%4],mode=[-1,0,1,2][i//4%4],queueCount=[0,-1,1,280][i//16%4],vertexCount=[0,4,16,40,128][i%5],groupCount=[0,1,2,5,249,250][i%6],generated=rng.getrandbits(32),stencil=[rng.getrandbits(32)for j in range(3)],volumeShader=rng.getrandbits(32),overlayShader=rng.getrandbits(32),overlayBuffer=rng.getrandbits(32),starts=starts,edges=edges,post=dict(vertexCount=[0,4,16,40][i%4],groupCount=[0,1,3,250][i%4],generated=rng.getrandbits(32)))
def check(kind,e):
 global post
 n.write(0x963f80,b'\xa5'*0x10100);n.pack('<250I',0x963f88,*e['starts']);n.pack('<250I',0x96e568,*e['edges'])
 for address,key,fmt in GLOBAL:n.pack('<'+fmt,address,e[key])
 n.pack('<3I',0x80e178,*e['stencil']);before=n.read(0x963f80,0x10100);outside=[(a,n.read(a,struct.calcsize(fmt)))for a,k,fmt in GLOBAL if a<0x963f80 or a>=0x974080]+[(0x80e178,n.read(0x80e178,12))];post=e['post'];events.clear();want,result=model(kind,e);entry={'draw':0x5f9c30,'overlay':0x5f9b20,'flush':0x5f9da0}[kind];n.call(entry,count=10000000);expected=bytearray(before)
 for a,k,fmt in[(0x973fec,'vertexCount','I'),(0x973ff0,'groupCount','I'),(0x971878,'generated','I'),(0x973fe8,'queueCount','i')]:struct.pack_into('<'+fmt,expected,a-0x963f80,result[k])
 actual=n.read(0x963f80,0x10100);assert events==want and actual==expected and all(n.read(a,len(b))==b for a,b in outside),(kind,len(cases))
 cases.append(dict(kind=kind,environment=e,native=dict(result,events=events.copy(),imageSha256=sha(actual))));counts[kind]+=1;counts['deviceEvents']+=sum(v['entry']!=0x5e4840 for v in events);counts['geometryServices']+=sum(v['entry']==0x5e4840 for v in events)
for i in range(512):check('draw',setup(i))
for i in range(128):check('overlay',setup(i))
for i in range(512):check('flush',setup(i))
for vc in[14000,13996]:
 for kind in['draw','flush']:
  e=setup(vc);e.update(enabled=255,mode=1,queueCount=1,vertexCount=vc,groupCount=250);e['post'].update(vertexCount=vc,groupCount=250);check(kind,e)
for i in range(1024):
 cursor=[0,1,2,3,0xfffffffc,0xfffffffd,0xfffffffe,0xffffffff][i]if i<8 else rng.getrandbits(32);n.write(D,b'\xa5'*64);n.pack('<I',D+16,cursor);n.call(0x5e28c0,[D+16]);start=((cursor+3)&0xffffffff)&0xfffffffc;want=dict(vertices=start,starts=(start+0x36b00)&0xffffffff,edges=(start+0x372d0)&0xffffffff,cursor=(start+0x37aa0)&0xffffffff);actual=dict(vertices=n.unpack('<I',0x963f94)[0],starts=n.unpack('<I',0x963f88)[0],edges=n.unpack('<I',0x96e568)[0],cursor=n.unpack('<I',D+16)[0]);expected=bytearray(b'\xa5'*64);struct.pack_into('<I',expected,16,want['cursor']);assert actual==want and n.read(D,64)==expected;cases.append(dict(kind='allocate',cursor=cursor,native=actual));counts['allocate']+=1
fixture=R/'animation-shadow-flush-native-fixtures.json.gz';fixture.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')).encode(),mtime=0))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
windows=[]
for address,size in[(0x5f9b20,0x10e),(0x5f9c30,0x165),(0x5f9da0,0xa7),(0x5e28c0,0x5b)]:
 data=n.read(address,size);windows.append(dict(address=hex(address),size=size,sha256=sha(data),instructions=[dict(address=hex(v.address),mnemonic=v.mnemonic,operands=v.op_str)for v in Cs(CS_ARCH_X86,CS_MODE_32).disasm(data,address)]))
(R/'animation-shadow-flush-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,windows=windows),indent=2)+'\n');report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),mismatches=0,fixture=dict(path=fixture.relative_to(B).as_posix(),sha256=sha(fixture.read_bytes()),bytes=fixture.stat().st_size),services={hex(k):v for k,v in ARITY.items()},method='Original CPU schedulers execute; exact device-wrapper and build-geometry calls are recorded at stated services. Compare full inline memory, unchanged external globals, ordered arguments, resets and allocation words. Geometry service applies explicit fixture counter changes; no actual GPU calls.',limits=['Device/cache services are recording boundaries and do not mutate tracked CPU state. Flush geometry service may change only vertex/group/generated counters.','Direct draw counts are bounded: vertexCount divisible by4 and at most14000, groupCount at most250; edge/start words retain full32-bit wrap semantics.','Draw scheduler uses immediate inline globals rather than allocated pointer contents. Preserve that original behavior; no assertion that this legacy GPU path is active or functional.','Allocate cursor is disjoint from global pointer slots; full32-bit cursor wrap allowed, allocation backing not dereferenced.','No managed or live graphics execution.']);(R/'animation-shadow-flush-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
