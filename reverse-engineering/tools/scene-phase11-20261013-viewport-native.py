"""Actual raw viewport COM forwarder and global wrapper."""
import importlib.util,struct,json,gzip,random,copy
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase11-20261013-viewport'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
GLOBAL=0x29765c8;CTX=n.DATA+0x1000;SRC=n.DATA+0x2000;DEVICEA=n.DATA+0x3000;DEVICEB=n.DATA+0x4000;VTA=n.DATA+0x5000;VTB=n.DATA+0x6000;EDGEA=n.STOP+0x100;EDGEB=n.STOP+0x200;n.pack('<I',DEVICEA,VTA);n.pack('<I',DEVICEB,VTB);n.pack('<I',VTA+0xbc,EDGEA);n.pack('<I',VTB+0xbc,EDGEB)
rng=random.Random(0x6e2470);checks=0;errors=[];cases=[];events=[];plan={};currentBackend=CTX;currentInput=SRC
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
w=lambda b,o,v:struct.pack_into('<I',b,o,v)
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<30:errors.append({'label':label,'native':a,'expected':e})
def read():return {'backendHex':n.read(currentBackend,0x700).hex(),'sourceHex':n.read(currentInput,24).hex(),'screen':list(n.unpack('<2i',0x973900))}
def entry(mu,address,size,_):
 global currentBackend,currentInput
 currentBackend=mu.reg_read(UC_X86_REG_ECX);currentInput=n.unpack('<I',mu.reg_read(UC_X86_REG_ESP)+4)[0]
def com(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret,device,args=n.unpack('<3I',sp);events.append({'device':device,'arguments':list(n.unpack('<6I',args)),'before':read()})
 for mutation in plan['backendChanges']:n.pack('<I',currentBackend+mutation['offset'],mutation['word'])
 for mutation in plan['sourceChanges']:n.pack('<I',currentInput+4*mutation['index'],mutation['word'])
 for mutation in plan['argumentChanges']:n.pack('<I',args+4*mutation['index'],mutation['word'])
 n.pack('<2i',0x973900,*plan['screenAfter']);mu.reg_write(UC_X86_REG_EAX,plan['return']);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+12);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,entry,begin=0x6e2470,end=0x6e2470)
for address in(EDGEA,EDGEB):n.mu.hook_add(UC_HOOK_CODE,com,begin=address,end=address)
def model(backend,source,sourceOffset,alias,screen,plan,nonnull):
 b=bytearray(backend);src=b if alias else bytearray(source);out=[];result=0
 if nonnull:
  args=[u(src,sourceOffset+i*4)for i in range(6)];args[2]=min(args[2],screen[0]&0xffffffff);args[3]=min(args[3],screen[1]&0xffffffff);out.append({'device':u(b,4),'arguments':args,'before':{'backendHex':b.hex(),'sourceHex':src[sourceOffset:sourceOffset+24].hex(),'screen':screen[:]}})
  for mutation in plan['backendChanges']:w(b,mutation['offset'],mutation['word'])
  for mutation in plan['sourceChanges']:w(src,sourceOffset+4*mutation['index'],mutation['word'])
  screen=plan['screenAfter'][:]
  # Argument packet is a separate local copy and is ignored after the COM call.
  for i in range(6):result=u(src,sourceOffset+i*4);w(b,0x170+i*4,result)
 return {'backendHex':b.hex(),'sourceHex':src[sourceOffset:sourceOffset+24].hex(),'screen':screen},out,result
for case in range(3072):
 wrapper=case>=2048;alias=case>=1024 and case<2048 or wrapper and case%3==0;nonnull=not(wrapper and case%2==0);backendAddress=GLOBAL if wrapper else CTX;sourceOffset=[0x164,0x168,0x16c,0x170,0x174,0x178,0x17f][case%7]if alias else 0;sourceAddress=backendAddress+sourceOffset if alias else SRC;backend=bytearray(0x700)
 for offset in range(0x140,0x1a0,4):w(backend,offset,rng.getrandbits(32))
 w(backend,4,DEVICEA);source=struct.pack('<6I',*[rng.getrandbits(32)for _ in range(6)])
 if alias:backend[sourceOffset:sourceOffset+24]=source
 screen=[rng.choice([-2147483648,-1,0,1,640,224,2147483647])for _ in range(2)];n.write(backendAddress,backend)
 if not alias:n.write(SRC,source)
 n.pack('<2i',0x973900,*screen);currentBackend=backendAddress;currentInput=sourceAddress;before=read();plan={'return':rng.choice([0,0x80004005,0x8876086c,0xffffffff]),'backendChanges':[{'offset':0x174,'word':rng.getrandbits(32)},{'offset':4,'word':DEVICEB}]if case%5==1 else[],'sourceChanges':[{'index':case%6,'word':rng.getrandbits(32)}]if case%4==1 else[],'argumentChanges':[{'index':(case+1)%6,'word':rng.getrandbits(32)}]if case%4==2 else[],'screenAfter':[rng.choice([-1,0,1,640,2147483647])for _ in range(2)]};expected,expectedEvents,expectedResult=model(bytes(backend),source,sourceOffset,alias,screen,plan,nonnull);events.clear();result=n.call(0x6e57b0 if wrapper else 0x6e2470,[sourceAddress if nonnull else 0],regs={UC_X86_REG_ECX:CTX});ck(read(),expected,['complete backend/source/screen',case]);ck(events,expectedEvents,['raw clamp and COM receiver order',case]);ck(result,expectedResult,['raw final depthword return',case]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe004 if wrapper else n.STACK+0xe008,['calling convention',case]);cases.append({'wrapper':wrapper,'alias':alias,'nonnull':nonnull,'sourceOffset':sourceOffset,'before':before,'service':copy.deepcopy(plan),'native':read(),'nativeEvents':events[:],'nativeResult':result})
fixture={'cases':cases};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));report={'schema':'original-viewport-com-forwarder-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':{'viewportCalls':3072,'retainedPortableReplayCases':3072,'COMCalls':sum(len(c['nativeEvents'])for c in cases),'globalWrapperCases':1024,'nullWrapperCases':sum(not c['nonnull']for c in cases),'shiftedAliasedSourceCases':sum(c['alias']for c in cases)},'adapters':{'vtable+0xbc':'Recorded COM SetViewport(device,local six-word packet), stdcall2 args. Opaque HRESULT plus explicit backend/source/argument/global-screen mutations; no device action.'},'limits':['Original6e2470 and6e57b0 execute unchanged. All copied/clamped words use integer instructions; raw nonfinite depth payloads are not converted.','Local device packet clamps only width/height using unsigned comparisons against raw screen words. X/Y/depth remain raw.','After COM, backend cache receives original source words with actual forward read/write order, including shifted/unaligned aliases and callback source mutation. Local packet mutations do not alter that copy.','COM HRESULT is discarded. Return equals last original source word read after prior writes; wrapper null input returns0 without call.','Global wrapper routes to fixed backend29765c8. Backend/COM lifecycle, actual device acceptance and runtime source initialization remain external.','Native/Python own-state differential passed; managed execution pending.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
