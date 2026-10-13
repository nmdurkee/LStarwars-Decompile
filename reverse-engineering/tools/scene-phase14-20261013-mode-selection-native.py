"""Original mode-table selection/mutation and finite unsigned aspect classifier."""
import importlib.util,struct,json,gzip,random,copy
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase14-20261013-mode-selection'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86();W=x87.wide;A=x87.add;D=x87.div;S=x87.store;sub=lambda a,b:A(a,(-b[0],b[1]));i32=lambda v:((v+0x80000000)&0xffffffff)-0x80000000;word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_ECX
rng=random.Random(0x6e1b7014);checks=0;errors=[];modeSequences=[];aspectCases=[]
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
w=lambda b,o,v:struct.pack_into('<I',b,o,v&0xffffffff)
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<20:errors.append({'label':label,'native':a,'expected':e})
def distance(candidate,requested):
 delta=i32(candidate-requested);sign=delta>>31;return i32((delta^sign)-sign)
def select(backend,modes,request):
 count=u(backend,0x618);out=bytearray(modes);chosen=0;best=[10000,10000,10000]
 for axis,value in enumerate(request):
  if axis==2 and value==0:continue
  for index in range(count):
   if any(i32(u(out,index*16+j*4))!=best[j]for j in range(axis)):continue
   candidate=i32(u(out,index*16+axis*4))
   if distance(candidate,value)<=distance(best[axis],value):chosen=index;best[axis]=candidate
 if backend[0x65c]:w(out,chosen*16,request[0]);w(out,chosen*16+4,request[1])
 return out,chosen
for case in range(2048):
 CTX=n.DATA+0x1000+case%4;TABLE=n.DATA+0x5000+case%4;backend=bytearray(rng.randbytes(0x700));modes=bytearray(rng.randbytes(32*16));count=case%33;w(backend,0x618,count);w(backend,0x61c,TABLE);backend[0x65c]=[0,1,255][case%3];request=[[-2147483648,2147483647,-1,0,1,640,10000,20000,2147483008][case%9],[-2147483648,2147483647,-1,0,1,480,10000,20000][case//9%8],[0,1,60,75,10000,-2147483648,2147483647][case//72%7]]if case<1024 else [i32(rng.getrandbits(32))for _ in range(3)]
 if case<1024:
  for index in range(32):
   for axis in range(3):w(modes,index*16+axis*4,[request[axis],i32(request[axis]-17),i32(request[axis]+17),10000,-2147483648,0][(case+index+axis)%6])
  if case%5==0:
   for index in range(32):
    for axis in range(3):w(modes,index*16+axis*4,request[axis])
 n.write(CTX,backend);n.write(TABLE,modes);n.pack('<I',CTX-4,0x12345678);n.pack('<I',CTX+0x700,0x87654321);n.pack('<I',TABLE-4,0x13579bdf);n.pack('<I',TABLE+len(modes),0x2468ace0);before={'backendHex':backend.hex(),'modesHex':modes.hex()};calls=[]
 for step in range(2):
  values=request if step==0 or case%3 else [i32(v+1)for v in request];expected,expectedResult=select(backend,modes,values);result=n.call(0x6e1b70,values,regs={UC_X86_REG_ECX:CTX});afterBackend=n.read(CTX,0x700);afterModes=n.read(TABLE,len(modes));ck(result,expectedResult,['mode selected index',case,step]);ck(afterBackend,bytes(backend),['backend preserved',case,step]);ck(afterModes,bytes(expected),['mode mutation/preserved words',case,step]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe010,['mode ret12',case,step]);ck([n.unpack('<I',a)[0]for a in [CTX-4,CTX+0x700,TABLE-4,TABLE+len(modes)]],[0x12345678,0x87654321,0x13579bdf,0x2468ace0],['mode image guards',case,step]);calls.append({'request':values,'nativeBackendHex':afterBackend.hex(),'nativeModesHex':afterModes.hex(),'nativeResult':result});modes=bytearray(expected)
 modeSequences.append({'before':before,'calls':calls})
targets=[n.unpack('<d',a)[0]for a in [0x75d168,0x776f48,0x76f8b0]];assert targets==[struct.unpack('<f',struct.pack('<I',v))[0]for v in [0x3faaaaab,0x3fe38e39,0x3fcccccd]]
def classify(width,height):
 ratio=S(D(W(width),W(height)));diffs=[abs(S(sub(W(ratio),W(v))))for v in targets];best=1000.;mode=0
 if diffs[0]<1000.:best=diffs[0]
 if diffs[1]<best:best=diffs[1];mode=1
 return (2 if diffs[2]<best else mode),[word(best),word(diffs[2])]
for case in range(4096):
 if case<256:
  width=[0,1,2,3,640,1920,2147483647,2147483648,4294967295][case%9];height=[1,2,3,224,480,1080,2147483647,2147483648,4294967295][case//9%9]
 elif case<2048:
  height=[1,3,10000,60000,16777217,1000000000,2147483647][case%7];target=(targets[0]+targets[2])*.5 if case%2 else (targets[1]+targets[2])*.5;width=max(0,min(0xffffffff,int(height*target)+(case//7%9)-4))
 else:width=rng.getrandbits(32);height=rng.randrange(1,0x100000000)
 expected,stackExpected=classify(width,height);result=n.call(0x6e1d00,[width,height]);stackWords=list(n.unpack('<2I',n.STACK+0xe004));ck(result,expected,['finite aspect class',case]);ck(stackWords,stackExpected,['exact overwritten argument words',case]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe00c,['aspect ret8',case]);aspectCases.append({'width':width,'height':height,'nativeResult':result,'nativeArgumentWords':stackWords})
fixture={'modeSequences':modeSequences,'aspectCases':aspectCases};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));counts={'modeSequences':2048,'modeCalls':4096,'aspectCases':4096,'retainedPortableReplayCases':8192,'unalignedModeReceiverSequences':1536,'preparedManagedAssertions':20480,'zeroCountModeSequences':sum(u(bytes.fromhex(c['before']['backendHex']),0x618)==0 for c in modeSequences)};report={'schema':'original-display-mode-cpu-helpers-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':counts,'adapters':{},'limits':['Original6e1b70 and6e1d00 execute unchanged, with no helper/arithmetic/COM adapters.','Mode count618 captured once, pointer61c bound to stable disjoint resolved16-byte records. Full raw signed integer values, wrapped subtraction/absolute value including INT_MIN,10000 sentinels and latest equal-distance selection preserved.','Zero count returns index0; if mutable65c is nonzero, physical record0 must still resolve and its width/height are updated. Opaque record refresh/format words and backend bytes preserved.','Aspect uses unsigned dimensions with nonzero height; actual ratio/difference float32 spills and widened float32 target constants retained. Return mode and overwritten argument words are compared. Portable stack diagnostics do not assign later original caller stack residue lifetime.','Mode enumeration, backend/device creation, capability/bootstrap globals, authored scene/frame binding and real GPU behavior remain external. Native/Python differential passed; managed execution pending.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report));raise SystemExit(0 if not errors else 1)
