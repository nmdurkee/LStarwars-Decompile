"""Bounded original PC grid visibility and dispatcher checks; no game/OS calls."""
import sys,struct,json,hashlib,random,math,importlib.util,gzip,itertools
from pathlib import Path
P=Path(__file__).resolve().parent; B=P.parent; R=B/'reports'; PREFIX='scene-visibility-20261013'
sys.path.insert(0,str(P/'python-packages'))
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86()
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
C=n.DATA;G=C+0x1000;T=C+0x2000;S=C+0x3000;CACHE=0x966390
errors=[];checks=0;cases=[];floors=[];integration=[];coordinates=[];crossGrid=[];counts={}
def check(a,e,label):
 global checks
 checks+=1
 if a!=e:errors.append({'label':label,'actual':a,'expected':e})
def floor(v):return math.floor(v)
def scaled(v,lo,scale):return x87.store(x87.mul(x87.add(x87.wide(v),x87.wide(-lo)),x87.wide(scale)))
def install(width=3,mode=1,size=16,stream=b''):
 n.write(C,bytes(0x100));n.pack('<I',C+12,G);n.write(G,bytes(0x100));n.pack('<I',G+4,width);n.pack('<6f',G+8,-2,0,-2,0,1,1);n.pack('<2I',G+0x20,mode,size);n.pack('<I',G+0x2c,T);n.pack('<9I',T,*([S]*9));n.write(S,stream);n.pack('<I',0x29a9c48,0)
def rle(length,rng):
 result=bytearray();stream=bytearray()
 while len(result)<length:
  k=rng.randint(1,min(63,length-len(result)));kind=rng.randrange(4)
  if rng.randrange(8)==0:stream.append(rng.randrange(4)) # valid zero-size token
  stream.append((k<<2)|kind)
  if kind<2:result.extend(bytes([0 if kind==0 else 255])*k)
  else:
   literal=bytes(rng.randrange(256)for _ in range(k));stream.extend(literal);result.extend(literal)
 return bytes(stream),bytes(result)
rng=random.Random(0x5d6f30)
# Original floor receives one float32 argument, omitted by pseudocode prototype.
values=[-2147483520.,2147483520.,-2.,-1.,-0.,0.,1.,2.,-.5,.5,-1.0000001192092896,.9999999403953552]+[f32(rng.uniform(-100000,100000))for _ in range(1000)]
for conversion in [0,1]:
 n.pack('<I',0x29a9c48,conversion)
 for v in values:
  a=n.call(0x5d6f00,[struct.unpack('<I',struct.pack('<f',v))[0]]);a=a-(1<<32)if a&0x80000000 else a;check(a,floor(v),['floor',conversion,v]);floors.append([conversion,v,a])
# RLE literal tags2/3, repeat tags0/1, zero-size tokens, raw/null masks,
# cache hit/miss, zero decoded size, out-of-grid preservation, and edge cells.
for k in range(640):
 length=[0,1,63,64,625][k]if k<5 else rng.randrange(626)
 stream,expected=rle(length,rng);install(size=length,stream=stream);n.write(CACHE-1,b'\xac'+bytes([0x77])*length+b'\xbd');n.pack('<i',0x80b9e4,-1);n.pack('<2I',C+0x24,0x11223344,0x55667788);n.pack('<I',0x973960,0xabcdef01);n.pack('<3f',0x973718,-1,123,-1)
 n.call(0x5d6f30,[C]);out=n.read(CACHE,length);check(out.hex(),expected.hex(),['rle',k]);check(n.read(CACHE-1,1).hex(),'ac',['leftCanary',k]);check(n.read(CACHE+length,1).hex(),'bd',['rightCanary',k]);check(n.unpack('<I',C+0x24)[0],CACHE,['cachePointer',k]);check(n.unpack('<I',0x973960)[0],1,['active',k]);check(n.unpack('<i',0x80b9e4)[0],4,['cacheIndex',k]);cases.append({'kind':'rle','streamHex':stream.hex(),'length':length,'outputHex':out.hex()})
 # Hit does not decode newly modified compressed bytes, even another grid object.
 n.write(S,b'\xff'*max(1,len(stream)));n.call(0x5d6f30,[C]);check(n.read(CACHE,length).hex(),expected.hex(),['sameCellHit',k])
for mode,pointer,x,z in itertools.product([0,1,2],[0,S],[-2.,-1.0000001192092896,-1.,0.,-2.000000238418579,.0000001192092896],[-2.,-1.,0.,.0000001192092896]):
 install(mode=mode,size=4,stream=b'\x10');n.pack('<9I',T,*([pointer]*9));n.pack('<i',0x80b9e4,-1);n.pack('<I',C+0x24,0x12345678);n.pack('<I',0x973960,0xabcdef01);n.pack('<3f',0x973718,x,0,z);n.write(CACHE,bytes([0x77])*4);n.call(0x5d6f30,[C]);inside=-2<=x<=0 and -2<=z<=0;ep=CACHE if inside and mode==1 and pointer else pointer if inside else 0x12345678;ea=int(pointer!=0)if inside else 0xabcdef01;check(n.unpack('<I',C+0x24)[0],ep,['selection',mode,pointer,x,z]);check(n.unpack('<I',0x973960)[0],ea,['activeSelection',mode,pointer,x,z]);ei=floor(scaled(z,-2.,1.))*3+floor(scaled(x,-2.,1.))if inside and mode==1 and pointer else -1;check(n.unpack('<i',0x80b9e4)[0],ei,['index',mode,pointer,x,z]);cases.append({'kind':'selection','mode':mode,'nonnull':bool(pointer),'x':x,'z':z,'expectedInside':inside,'nativePointer':n.unpack('<I',C+0x24)[0],'nativeActive':n.unpack('<I',0x973960)[0],'nativeCacheIndex':n.unpack('<i',0x80b9e4)[0]})
# Grid has no grid-identity key: same numeric cell reuses old bytes.
install(size=4,stream=b'\x11');n.pack('<3f',0x973718,-1,0,-1);n.pack('<i',0x80b9e4,-1);n.call(0x5d6f30,[C]);n.pack('<I',C+12,G+0x100);n.write(G+0x100,n.read(G,0x100));n.write(S,b'\x10');n.call(0x5d6f30,[C]);check(n.read(CACHE,4).hex(),'ffffffff','differentGridSameCellCacheHit');crossGrid.append({'firstStreamHex':'11','secondStreamHex':'10','decodedByteCount':4,'cameraX':-1.,'cameraZ':-1.,'nativeOutputHex':n.read(CACHE,4).hex(),'nativeCacheIndex':n.unpack('<i',0x80b9e4)[0],'nativePointer':n.unpack('<I',C+0x24)[0],'nativeActive':n.unpack('<I',0x973960)[0]})
# Non-unit scales retain the x87 subtraction/multiply then float32 spill.
coordinateCases=0
for k in range(256):
 install(width=17,mode=0,size=4,stream=b'');loX=f32(rng.uniform(-100000,0));loZ=f32(rng.uniform(-100000,0));sx=f32(rng.uniform(.01,8));sz=f32(rng.uniform(.01,8));x=f32(loX+rng.uniform(0,15)/sx);z=f32(loZ+rng.uniform(0,15)/sz);hiX=f32(loX+16/sx);hiZ=f32(loZ+16/sz);n.pack('<6f',G+8,loX,hiX,loZ,hiZ,sx,sz);n.pack('<289I',T,*[S+4*i for i in range(289)]);n.pack('<3f',0x973718,x,0,z);n.call(0x5d6f30,[C]);index=floor(scaled(z,loZ,sz))*17+floor(scaled(x,loX,sx));check(n.unpack('<I',C+0x24)[0],S+index*4,['coordinate',k]);coordinateCases+=1;coordinates.append({'width':17,'minimumX':loX,'maximumX':hiX,'minimumZ':loZ,'maximumZ':hiZ,'scaleX':sx,'scaleZ':sz,'cameraX':x,'cameraZ':z,'nativeCellIndex':(n.unpack('<I',C+0x24)[0]-S)//4,'expectedCellIndex':index,'nativeActive':n.unpack('<I',0x973960)[0]})
# Dispatcher adapters isolate camera switching and portal/tree callees only.
# Grid executes unchanged, including raw pointer/active writes.
seen=[]
def hook(mu,address,size,_):
 seen.append(hex(address));sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for address in [0x5d6900,0x5eeb30,0x5d8fb0,0x603cc0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
SC=C+0x10000
for workspace,visible,gridOn,gridPresent,portalOn,portalPresent,treeOn,treePresent in itertools.product([False,True],repeat=8):
 install(mode=0,size=4,stream=b'\xaa\xbb\xcc\xdd');n.write(SC,bytes([0x5a])*0x160);n.pack('<I',SC+0x1c,7);n.pack('<I',SC+0x128,0);n.pack('<I',SC+0x12c,G if gridPresent else 0);n.pack('<I',SC+0x134,0x1234 if treePresent else 0);n.pack('<I',SC+0x138,0x2345 if portalPresent else 0);n.pack('<I',SC+0x148,0xffffffff);n.pack('<3f',0x973718,-1,0,-1)
 for addr,v in [(0x80b6f4,visible),(0x80b6f8,gridOn),(0x80ba58,portalOn),(0x80ba14,treeOn),(0x973940,0),(0x97394c,0),(0x97393c,0)]:n.pack('<I',addr,int(v))
 seen.clear();before=n.read(SC,0x160);ret=n.call(0x5f3c80,[SC,0x77889900 if workspace else 0]);active=workspace and visible;portal=portalOn and portalPresent;tree=not portal and treeOn and treePresent;expectedCalls=[]if not active else['0x5d6900']+(['0x5eeb30']if portal else['0x5d8fb0']if tree else[]);check(seen,expectedCalls,['dispatcherCalls',len(integration)]);check(ret,SC+0x120 if active else 0,['return',len(integration)])
 if not active:check(n.read(SC,0x160).hex(),before.hex(),['inactivePreserves',len(integration)])
 else:
  check(n.unpack('<I',SC+0x120)[0],7,['count',len(integration)]);check(n.unpack('<I',SC+0x140)[0],0x77889900 if tree else 0,['workspace',len(integration)]);check(n.unpack('<I',SC+0x144)[0],S if gridOn and gridPresent else 0,['gridPointer',len(integration)]);check(n.unpack('<I',SC+0x148)[0],0xffffffea|int(tree),['flags',len(integration)])
 integration.append({'gates':[workspace,visible,gridOn,gridPresent,portalOn,portalPresent,treeOn,treePresent],'calls':list(seen),'nativeContextHex':n.read(SC+0x120,44).hex(),'return':ret})
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly={hex(a):[{'address':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str,'bytes':i.bytes.hex()}for i in md.disasm(n.read(a,size),a)]for a,size in [(0x5d6f00,0x24),(0x5d6f30,0x125),(0x5f3c80,0x150)]}
(R/(PREFIX+'-assembly.json')).write_text(json.dumps({'binarySHA256':n.sha256,'functions':assembly},indent=2)+'\n')
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt',encoding='utf8')as f:json.dump({'floors':floors,'grid':cases,'coordinates':coordinates,'crossGrid':crossGrid,'dispatcher':integration},f)
report={'schema':'bounded-original-grid-visibility-v1','passed':not errors,'binarySHA256':n.sha256,'checks':checks,'counts':{'floorCases':len(floors),'rleCases':640,'selectionCases':len(cases)-640,'dispatcherCases':len(integration),'crossGridCacheCases':1,'nonUnitCoordinateCases':coordinateCases},'errors':errors[:30],'bounds':'Synthetic finite float32 camera/grid inputs, signed32 floor range; decoded masks0..625 bytes and exact-length well-formed RLE. No authored grid assets claimed.','adapters':{'0x5d6900':'no-op camera switch only in dispatcher cases','0x5eeb30':'no-op portal entry only in dispatcher cases','0x5d8fb0':'no-op tree entry only in dispatcher cases','0x603cc0':'no-op camera restore only in dispatcher cases'},'nativeUnmodified':['0x5d6f00','0x5d6f30','0x6e6b90','0x6e6950','0x4ef660','0x5f3c80'],'retainedFixtureCounts':{'floor':len(floors),'grid':len(cases),'coordinates':len(coordinates),'crossGrid':len(crossGrid),'dispatcherEvidenceOnly':len(integration),'total':len(floors)+len(cases)+len(coordinates)+len(crossGrid)+len(integration),'portableReplayCases':len(floors)+len(cases)+len(coordinates)+len(crossGrid)},'fixture':PREFIX+'-native-fixtures.json.gz'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));sys.exit(0 if not errors else 1)
