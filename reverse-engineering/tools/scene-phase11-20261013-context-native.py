"""Original render target cache caller with signed/wrapping slot indexing."""
import importlib.util,struct,json,gzip,random,copy
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase11-20261013-context'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
CTX=n.DATA+0x1000;DEVICEA=n.DATA+0x2000;DEVICEB=n.DATA+0x3000;VTA=n.DATA+0x4000;VTB=n.DATA+0x5000;EDGEA=n.STOP+0x100;EDGEB=n.STOP+0x200;n.pack('<I',DEVICEA,VTA);n.pack('<I',DEVICEB,VTB);n.pack('<I',VTA+0x94,EDGEA);n.pack('<I',VTB+0x94,EDGEB)
rng=random.Random(0x6e2880);checks=0;errors=[];events=[];plan={};sequences=[];i32=lambda v:((v+0x80000000)&0xffffffff)-0x80000000
configAddress=0x2974d1c
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
w=lambda b,o,v:struct.pack_into('<I',b,o,v)
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<30:errors.append({'label':label,'native':a,'expected':e})
def read():return {'imageHex':n.read(CTX,0x800).hex(),'configuration':n.unpack('<i',configAddress)[0]}
def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret,device,slot,handle=n.unpack('<4I',sp);events.append({'device':device,'slot':slot,'handle':handle,'before':read(),'edge':'A'if address==EDGEA else'B'})
 for change in plan['changes']:n.pack('<I',CTX+change['offset'],change['word'])
 n.pack('<i',configAddress,plan['configurationAfter']);mu.reg_write(UC_X86_REG_EAX,plan['return']);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+16);mu.reg_write(UC_X86_REG_EIP,ret)
for address in(EDGEA,EDGEB):n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def model(image,configuration,slot,handle,plan):
 b=bytearray(image);outEvents=[];result=slot;limit=(struct.unpack_from('<H',b,0xf8)[0]if u(b,0x638)==0 and configuration>=2 else 1)-1
 if i32(slot)<=limit:
  offset=(0x6f0+slot*4)&0xffffffff
  if offset>len(b)-4:raise ValueError('Unresolved native target cache image')
  if u(b,offset)!=handle:
   w(b,offset,handle);device=u(b,4);outEvents.append({'device':device,'slot':slot,'handle':handle,'before':{'imageHex':b.hex(),'configuration':configuration},'edge':'A'if device==DEVICEA else'B'})
   for change in plan['changes']:w(b,change['offset'],change['word'])
   configuration=plan['configurationAfter'];result=plan['return']
 return bytes(b),configuration,outEvents,result
aliasOffsets=[0,4,0xf8,0x638,0x6b0,0x6e8,0x6ec,0x6f0,0x6f4,0x70c]
slots=[0,1,2,3,7,9,65535,0x7fffffff,0x80000000,0x80000001,0xc0000000,0xffffffff,0xfffffffe,0xffffffe0]+[(((o-0x6f0)&0xffffffff)//4)|0x80000000 for o in aliasOffsets]
for case in range(2048):
 image=bytearray(0x800)
 for offset in range(0x660,0x720,4):w(image,offset,rng.getrandbits(32))
 w(image,4,DEVICEA);w(image,0x638,[0,1,0xffffffff][case%3]);struct.pack_into('<H',image,0xf8,[0,1,2,4,8,65535][case//3%6]);configuration=[-2147483648,-1,0,1,2,3,2147483647][case//18%7];slot=slots[case%len(slots)];offset=(0x6f0+slot*4)&0xffffffff;handle=DEVICEB if offset==4 else rng.getrandbits(32)
 if case%4==0 and offset<=len(image)-4:handle=u(image,offset)
 n.write(CTX,image);n.pack('<i',configAddress,configuration);n.pack('<I',CTX-4,0x12345678);n.pack('<I',CTX+0x800,0x87654321);before={'imageHex':image.hex(),'configuration':configuration};calls=[]
 for step in range(2):
  requestHandle=handle if step==0 or case%3 else (DEVICEA if offset==4 else rng.getrandbits(32));changes=[]
  if case%5==1:changes=[{'offset':0x638,'word':rng.choice([0,1,0xffffffff])},{'offset':0xf8,'word':rng.getrandbits(32)},{'offset':4,'word':rng.choice([DEVICEA,DEVICEB])}]
  if case%5==2 and offset<=len(image)-4:changes=[{'offset':offset,'word':DEVICEA if offset==4 else rng.getrandbits(32)}]
  plan={'return':rng.choice([0,1,0x80004005,0x8876086c,0xffffffff]),'changes':changes,'configurationAfter':rng.choice([-1,0,1,2,3])};expectedImage,expectedConfiguration,expectedEvents,expectedReturn=model(image,configuration,slot,requestHandle,plan);events.clear();result=n.call(0x6e2880,[slot,requestHandle],regs={UC_X86_REG_ECX:CTX});after=read();ck(after,{'imageHex':expectedImage.hex(),'configuration':expectedConfiguration},['owned image/configuration',case,step]);ck(events,expectedEvents,['COM cache publication and mutation order',case,step]);ck(result,expectedReturn,['opaque/no-op result',case,step]);ck([n.unpack('<I',CTX-4)[0],n.unpack('<I',CTX+0x800)[0]],[0x12345678,0x87654321],['resolved image guards',case,step]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe00c,['ret8',case,step]);calls.append({'slot':slot,'handle':requestHandle,'service':copy.deepcopy(plan),'native':after,'nativeEvents':events[:],'nativeResult':result});image=bytearray(expectedImage);configuration=expectedConfiguration
 sequences.append({'before':before,'calls':calls})
fixture={'deviceA':DEVICEA,'deviceB':DEVICEB,'sequences':sequences};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));deviceEvents=sum(len(call['nativeEvents'])for sequence in sequences for call in sequence['calls']);failedSuppressed=sum(1 for sequence in sequences if sequence['calls'][0]['nativeEvents']and sequence['calls'][0]['nativeResult']&0x80000000 and not sequence['calls'][1]['nativeEvents']and sequence['calls'][0]['slot']==sequence['calls'][1]['slot']and sequence['calls'][0]['handle']==sequence['calls'][1]['handle']);report={'schema':'original-target-cache-caller-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':{'sequences':2048,'targetCalls':4096,'retainedPortableReplayCases':4096,'COMCalls':deviceEvents,'failedCallsSuppressedOnRepeat':failedSuppressed},'adapters':{'vtable+0x94':'Recorded COM SetRenderTarget(device,raw slot,opaque handle), stdcall3 args; declared opaque HRESULT and backend/configuration mutations. No device action.'},'limits':['Original6e2880 executes unchanged. Finite/float conversion is irrelevant: every cache operand is raw integer data.','Slot limit uses signed comparison; address scaling/addition wraps at32bits. Only calls whose selected cell resolves inside supplied0x800-byte backend image are retained, including negative and wrapped aliases.','Configuration global2974d1c, backend flag638 and ushort countf8 control max slot. Above-limit and same-handle calls return raw slot with no COM call.','Handle is cached before COM dispatch. HRESULT is returned without rollback; callback mutation remains visible, and device pointer is read after cache write.','Backend/COM object lifetime, device implementation, source dimension initialization and authored frame setup remain external.','Native/Python own-state differential passed; managed execution pending.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
