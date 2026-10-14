"""Original script recording serializer and512slot leaseallocator; only callbacks/publication supplied."""
import importlib.util,json,struct,itertools,random,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
D=n.DATA;REC=D+0x1000;VT=D+0x1100;ACTION=D+0x2000;DESC=D+0x2100;DESC2=D+0x2200;PTRS=D+0x2300;TOKENS=D+0x3000;OUT=D+0x4800;ACTOR=D+0x4900;MODE=D+0x4a00
POOL=0x28683e0;LIMIT=0x28febe0;STRIDE=0x4b4;CB=n.STOP+0x500
config={};events=[];shadow={};ordinal={};errors=[];cases=[];checks=0;poolOriginal=None;segments=[]
def rb(p):return shadow[p]
def wb(p,v):shadow[p]=v&255
def rd(p):return sum(rb(p+i)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):wb(p+i,v>>(i*8))
def half(p,v):wb(p,v>>8);wb(p+1,v)
def release(p):
 if p:count=rd(p+0x4b0);wd(p+0x4b0,count-1 if count>1 else 0)
def allocation():
 p=POOL
 while p!=LIMIT and rd(p+0x4b0):p+=STRIDE
 if p==LIMIT:p=0
 else:wd(p+0x4b0,1)
 return [1,p,config.get('start',32),config.get('start',32)]
def port(name,args,model):
 ordinal[name]=ordinal.get(name,0)+1;read=rd if model else lambda p:n.unpack('<I',p)[0];buffer=args[1]if name=='Publish'else(config.get('free',0)*STRIDE+POOL if config.get('free',0)<512 else 0)
 events.append(dict(name=name,args=args,observed=[read(0x9242c0),read(ACTION+0x10),read(ACTION+0xc),read(buffer+0x4b0)if buffer else 0,read(MODE+0x34)]))
 for key in [name,name+'#'+str(ordinal[name])]:
  for p,size,v in config.get('patches',{}).get(key,[]):
   if model:
    for i in range(size):wb(p+i,v>>(i*8))
   else:n.write(p,int(v).to_bytes(size,'little'))
 return config.get('allowed',1)if name=='Allowed'else config.get('identifier',0x12345678)
def hook(mu,address,size,data):
 if address not in [CB,CB+0x10,0x60f190]:return
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==CB:name='Allowed';args=[];argc=0
 elif address==CB+0x10:name='Identifier';args=[mu.reg_read(UC_X86_REG_ECX),n.unpack('<I',sp+4)[0]];argc=1
 else:name='Publish';args=list(n.unpack('<5I',sp+4));argc=5
 value=port(name,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4+argc*4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
def model_record(recorder):
 mode,buffer,start,end=allocation();callback=rd(0x876d88)
 if callback and not port('Allowed',[],True):release(buffer);return
 callback=rd(rd(recorder)+0x30);identifier=port('Identifier',[recorder,ACTOR],True)&0xffff;descriptor=rd(ACTION+0x10);code=rb(descriptor+10)|(rb(descriptor+11)<<8);kind=rb(descriptor+9);count=rb(ACTION+12)
 if buffer:
  wb(buffer+end,1);end+=1;wb(buffer+end,kind);end+=1;half(buffer+end,code);end+=2;half(buffer+end,identifier);end+=2;wb(buffer+end,count);end+=1
 i=0
 while (rd(ACTION+12)-0x100000000 if rd(ACTION+12)>=0x80000000 else rd(ACTION+12))>i:
  token=rd(rd(ACTION+8)+i*4)
  if buffer:
   length=0
   while rb(token+length):length+=1
   wb(buffer+end,length)
   for j in range(length):wb(buffer+end+1+j,rb(token+j))
   end+=1+length
  i+=1
 if buffer:wd(buffer+0x4b0,rd(buffer+0x4b0)+1)
 else:wd(rd(0x28572e0)+0x34,0xa0001000)
 port('Publish',[mode,buffer,start,end,10],True);release(buffer)
def setup(c):
 global segments,poolOriginal
 n.write(D,bytes(0x5000));poolOriginal=bytearray([0x5a])*(LIMIT-POOL)
 for i in range(512):struct.pack_into('<I',poolOriginal,i*STRIDE+0x4b0,c.get('occupied',1))
 free=c.get('free',0)
 if free<512:struct.pack_into('<I',poolOriginal,free*STRIDE+0x4b0,0)
 n.write(POOL,poolOriginal);n.pack('<I',0x9242c0,0 if c.get('nullRecorder')else REC);n.pack('<I',0x876d88,CB if c.get('gate',False)else 0);n.pack('<I',0x28572e0,MODE);n.pack('<I',MODE+0x34,0x89abcdef);n.pack('<I',REC,VT);n.pack('<I',VT+0x30,CB+0x10);n.pack('<I',ACTION+8,PTRS);n.pack('<I',ACTION+0xc,c.get('count',len(c.get('tokens',['alpha','beta']))));n.pack('<I',ACTION+0x10,DESC);n.pack('<H',DESC+10,c.get('code',0x1234));n.write(DESC+9,bytes([c.get('kind',0xab)]));n.pack('<H',DESC2+10,0x9876);n.write(DESC2+9,b'\xef')
 for i,token in enumerate(c.get('tokens',['alpha','beta'])):p=TOKENS+i*0x500;n.write(p,token.encode('latin1')+b'\0');n.pack('<I',PTRS+i*4,p)
 n.write(OUT,b'\xcc'*16)
 segments=[(D,0x5000),(0x9242c0,4),(0x876d88,4),(0x28572e0,4)]+[(POOL+i*STRIDE+0x4b0,4)for i in range(512)]
 if free<512:segments.insert(1,(POOL+free*STRIDE,STRIDE))
 for p,size,value in c.get('initialPatches',[]):n.write(p,int(value).to_bytes(size,'little'))
def snapshot(model=False):return [dict(address=p,bytes=bytes(rb(p+i)for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def poolhash(model=False):
 if not model:return hashlib.sha256(n.read(POOL,LIMIT-POOL)).hexdigest()
 image=bytearray(poolOriginal)
 for p,value in shadow.items():
  if POOL<=p<LIMIT:image[p-POOL]=value
 return hashlib.sha256(image).hexdigest()
def execute(c,method='Emit'):
 global config,events,ordinal,shadow,checks
 config=c;setup(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal={}
 if method=='Allocate':lease=allocation();[wd(OUT+i*4,v)for i,v in enumerate(lease)]
 elif method=='Emit':
  if rd(0x9242c0):model_record(rd(0x9242c0))
 else:model_record(REC)
 modelFinal=snapshot(True);modelEvents=events.copy();modelHash=poolhash(True);events=[];ordinal={}
 if method=='Allocate':n.call(0x53d5d0,[c.get('start',32)],regs={UC_X86_REG_ECX:OUT})
 elif method=='Emit':n.call(0x53db30,[ACTION,ACTOR])
 else:n.call(0x53d940,[ACTION,ACTOR],regs={UC_X86_REG_ECX:REC})
 nativeFinal=snapshot();nativeEvents=events.copy();nativeHash=poolhash()
 for group,a,b in [('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents),('poolHash',nativeHash,modelHash)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,initial=initial,final=nativeFinal,nativeEvents=nativeEvents,poolSha256=nativeHash))
for free in range(513):execute(dict(free=free,start=(free*12345)&0xffffffff),'Allocate')
for occupied in [1,2,0x7fffffff,0x80000000,0xffffffff]:
 for free in [0,7,511,512]:execute(dict(free=free,occupied=occupied),'Allocate')
for free,gate,allowed,count in itertools.product([0,7,511,512],[False,True],[0,1],[0,2,0x80000000,0xffffffff]):execute(dict(free=free,gate=gate,allowed=allowed,count=count))
for identifier,code,kind in itertools.product([0,1,0xffff,0x10000,0xffffffff],[0,0xff,0x100,0xffff],[0,255]):execute(dict(identifier=identifier,code=code,kind=kind))
for size in [0,1,31,255,256,300,1000]:execute(dict(tokens=['x'*size]))
for c in [dict(nullRecorder=True),dict(gate=True,allowed=0),dict(free=512,count=2),dict(count=-1&0xffffffff),dict(tokens=['\xe0\xffraw',''])]:execute(c)
for name in ['Allowed','Identifier','Publish']:
 for value in [0,1,2,3,0x7fffffff,0x80000000,0xffffffff]:execute(dict(gate=True,patches={name:[[POOL+0x4b0,4,value]]}))
for c in [dict(gate=True,patches={'Allowed':[[0x9242c0,4,0],[ACTION+0x10,4,DESC2]]}),dict(patches={'Identifier':[[ACTION+0x10,4,DESC2],[ACTION+0xc,4,0]]}),dict(patches={'Identifier':[[ACTION+0xc,4,1],[PTRS,4,TOKENS+0x500]]}),dict(patches={'Identifier':[[0x9242c0,4,0]]}),dict(gate=True,allowed=0,patches={'Allowed':[[POOL+0x4b0,4,0xffffffff]]})]:execute(c)
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],actualBodies=['0x53db30','0x53d940','0x53d5d0','0x4ef660','0x4f1ff0','0x621180','0x60f2d0'],ports=['Optional876d88 gate','Recorder vtable30 actor identifier','60f190 packet transport'],limits=['Valid bounded mapped tokens/count, disjoint packet destinations and string/metadata sources.','All512slot counters and fullpool SHA compared. Poolpayloads initially5a; selectedrecord fullimage saved.','Transport and callbacks explicit; own serialization andallocator original bytes execute. Managed execution unperformed.'])
(nm.BASE/'reports/script-phase21-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase21-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
