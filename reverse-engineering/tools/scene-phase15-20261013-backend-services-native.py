"""Original backend service CPU helpers; final COM/critical-section edges only."""
import importlib.util,struct,json,gzip,random,copy
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase15-20261013-backend-services'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX
GLOBAL=0x29765c8;CACHE=0x297bea0;MARKERS=0x97f998;TABLE=0x8283e8;DEVICEA=n.DATA+0x3000;DEVICEB=n.DATA+0x5000;VTA=n.DATA+0x4000;VTB=n.DATA+0x6000
EDGES={n.STOP+0x100:0x114,n.STOP+0x180:0x134,n.STOP+0x200:0xac,n.STOP+0x280:0xc,n.STOP+0x300:0x14,n.STOP+0x380:0xe4,n.STOP+0x400:'enter',n.STOP+0x480:'exit'};ARGCOUNT={0x114:3,0x134:1,0xac:6,0xc:0,0x14:0,0xe4:2,'enter':1,'exit':1}
for device,vt in [(DEVICEA,VTA),(DEVICEB,VTB)]:
 n.pack('<I',device,vt)
 for edge,offset in EDGES.items():
  if isinstance(offset,int):n.pack('<I',vt+offset,edge)
n.pack('<I',0x7510b8,n.STOP+0x400);n.pack('<I',0x7510b4,n.STOP+0x480)
rng=random.Random(0x6e54e015);checks=0;errors=[];sequences=[];events=[];plan={};originalTable=n.read(TABLE,0x10c0);vids=[struct.unpack_from('<I',originalTable,i*16)[0]for i in range(267)];i32=lambda v:((v+0x80000000)&0xffffffff)-0x80000000
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
w=lambda b,o,v:struct.pack_into('<I',b,o,v&0xffffffff)
word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<20:errors.append({'label':label,'native':a,'expected':e})
def snap():return {'backendHex':n.read(GLOBAL,0x800).hex(),'cacheHex':n.read(CACHE,0x300).hex(),'markerHex':n.read(MARKERS,0x80).hex(),'enabled':n.read(0x8282b4,1)[0],'vendor':n.unpack('<I',0x2976b94)[0],'device':n.unpack('<I',0x2976b98)[0],'echoVendor':n.unpack('<I',0x8283e0)[0],'echoDevice':n.unpack('<I',0x8283e4)[0]}
def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];kind=EDGES[address];count=ARGCOUNT[kind];device=0 if isinstance(kind,str)else n.unpack('<I',sp+4)[0];args=list(n.unpack('<'+str(count)+'I',sp+(4 if isinstance(kind,str)else 8)))if count else [];events.append({'kind':kind,'device':device,'arguments':args,'before':snap()})
 for c in plan['backendChanges']:n.pack('<I',GLOBAL+c['offset'],c['word'])
 for c in plan['cacheChanges']:n.pack('<I',CACHE+c['offset'],c['word'])
 for c in plan['markerChanges']:n.pack('<I',MARKERS+c['offset'],c['word'])
 n.write(0x8282b4,bytes([plan['enabled']]));mu.reg_write(UC_X86_REG_EAX,plan['return']);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+4+(count+(0 if isinstance(kind,str)else 1))*4);mu.reg_write(UC_X86_REG_EIP,ret)
for edge in EDGES:n.mu.hook_add(UC_HOOK_CODE,hook,begin=edge,end=edge)
def decode(s):
 o=copy.deepcopy(s)
 for key in ['backend','cache','marker']:o[key]=bytearray.fromhex(o.pop(key+'Hex'))
 return o
def encode(s):return dict({k+'Hex':s[k].hex()for k in ['backend','cache','marker']},**{k:s[k]for k in ['enabled','vendor','device','echoVendor','echoDevice']})
def modelCom(s,kind,args,out):
 out.append({'kind':kind,'device':0 if isinstance(kind,str)else u(s['backend'],4),'arguments':args,'before':encode(s)})
 for c in plan['backendChanges']:w(s['backend'],c['offset'],c['word'])
 for c in plan['cacheChanges']:w(s['cache'],c['offset'],c['word'])
 for c in plan['markerChanges']:w(s['marker'],c['offset'],c['word'])
 s['enabled']=plan['enabled'];return plan['return']
def model(s,kind,args,records,out):
 if kind=='sampler':
  stage,type,value=args;enabled=s['enabled'];offset=(0x20+stage*8)&0xffffffff;w(s['marker'],offset,0xffffffff);w(s['marker'],(offset+4)&0xffffffff,0xffffffff)
  if enabled and stage<8 and i32(type)<14 and type!=4:
   at=(0x34+stage*56+type*4)&0xffffffff
   if u(s['cache'],at)==value:return stage
   w(s['cache'],at,value)
  result=modelCom(s,0x114,args,out);w(s['cache'],0,result);return result
 if kind=='render':
  enums=[168,190,191,192,7,14,23,22,15,27,19,20];type,value=args
  if s['enabled']and type in enums:
   index=enums.index(type);at=0x1f8+index*4
   if u(s['cache'],at)==value:return index
   w(s['cache'],at,value)
  w(s['cache'],0x1f4,0xffffffff);result=modelCom(s,0xe4,args,out);w(s['cache'],0,result);return result
 if kind=='vendor':
  w(s['cache'],0x2d8,1);s['echoVendor']=s['vendor'];s['echoDevice']=s['device'];selected=0
  if s['vendor']==0x10de and s['device']!=0xffffffff:
   for index in range(len(records)//16):
    value=u(records,index*16)
    if value==0xffffffff or selected:break
    if value==s['device']:selected=TABLE+index*16
   if not selected:selected=0x8294a8
  w(s['cache'],0x2dc,selected);return 0
 if kind in ['enter','exit']:
  index=args[0]
  return index if ((index-1)&0xffffffff)>11 else modelCom(s,kind,[0x91ef70+index*24],out)
 offset={'shader':0x134,'clear':0xac,'status':0xc,'end':0x14}[kind];result=modelCom(s,offset,args,out)
 if kind!='status':w(s['cache'],0,result)
 return result
stages=list(range(8))+[0xffffffff,0xfffffffc,0x20000000,0x40000003,0x80000007]
functions={'sampler':(0x6e54e0,1024),'render':(0x6e5340,512),'vendor':(0x6e66b0,512),'shader':(0x6e5570,256),'clear':(0x6e45e0,256),'status':(0x6e5850,256),'end':(0x6e4a40,256),'enter':(0x4ffaa0,256),'exit':(0x4ffac0,256)}
for kind,(address,count)in functions.items():
 for case in range(count):
  backend=bytearray(rng.randbytes(0x800));cache=bytearray(rng.randbytes(0x300));markers=bytearray(rng.randbytes(0x80));w(backend,4,DEVICEA);n.write(GLOBAL,backend);n.write(CACHE,cache);n.write(MARKERS,markers);n.write(0x8282b4,bytes([0 if case%5==0 else 1]));vendor=[0x10de,0,0x1002,0x8086][case%4];device=vids[case%len(vids)]if case%3 else [0xffffffff,0xfedcba98,vids[0]][case//3%3];n.pack('<I',0x2976b94,vendor);n.pack('<I',0x2976b98,device);n.pack('<I',0x8283e0,rng.getrandbits(32));n.pack('<I',0x8283e4,rng.getrandbits(32));records=bytearray(originalTable)
  if kind=='vendor'and case%7==0:w(records,(case%267)*16,0xffffffff)
  n.write(TABLE,records)
  if kind=='sampler':
   stage=stages[case%len(stages)];type=([-13,-12,-1,0,4,5,6,7,13,14,2147483647][case//len(stages)%11]if stage==0 else -13-stage*14 if case%7==0 and stage<8 else [0,4,5,6,7,13,14,2147483647][case//len(stages)%8])&0xffffffff;args=[stage,type,rng.getrandbits(32)];at=(0x34+stage*56+type*4)&0xffffffff
   if case%4==0 and stage<8 and i32(type)<14 and type!=4:w(cache,at,args[2]);n.write(CACHE,cache)
  elif kind=='render':args=[[168,190,191,192,7,14,23,22,15,27,19,20,0,193,0xffffffff][case%15],rng.getrandbits(32)]
  elif kind=='clear':args=[rng.getrandbits(32)for _ in range(6)];args[4]=word([-0.,0.,1.,-.1,2.,16777217.][case%6])
  elif kind in ['shader','enter','exit']:args=[rng.getrandbits(32)]if kind=='shader'else [[0,1,2,3,4,5,6,7,8,9,10,11,12,13,0xffffffff,0x80000000][case%16]]
  else:args=[]
  before=snap();s=decode(before);calls=[]
  for step in range(2):
   request=args[:]
   if step and kind in ['sampler','render','shader']and case%3==0:request[-1]=rng.getrandbits(32)
   plan={'return':rng.choice([0,1,0x80004005,0xffffffff]),'enabled':0 if case%7==0 else 1,'backendChanges':[{'offset':4,'word':DEVICEB if step==0 else DEVICEA}]if case%5==0 else [],'cacheChanges':[{'offset':0,'word':rng.getrandbits(32)},{'offset':0x1f4,'word':rng.getrandbits(32)}]if case%4==0 else [],'markerChanges':[{'offset':case%32*4,'word':rng.getrandbits(32)}]if case%3==0 else []};expectedEvents=[];expectedResult=model(s,kind,request,records,expectedEvents);events.clear();result=n.call(address,request);after=snap();ck(after,encode(s),[kind,'all owned images/globals',case,step]);ck(events,expectedEvents,[kind,'actual host edge',case,step]);ck(result,expectedResult,[kind,'opaque/cache result',case,step]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe004,[kind,'cdecl ret',case,step]);ck(n.read(TABLE,len(records)),bytes(records),[kind,'vendor table preserved',case,step]);calls.append({'arguments':request,'service':copy.deepcopy(plan),'native':after,'nativeEvents':copy.deepcopy(events),'nativeResult':result})
  sequences.append({'kind':kind,'before':before,'recordsHex':records.hex(),'calls':calls})
fixture={'sequences':sequences,'originalVendorTableHex':originalTable.hex()};(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));counts={'sequences':len(sequences),'retainedNativeCalls':sum(len(c['calls'])for c in sequences),'hostCalls':sum(len(call['nativeEvents'])for seq in sequences for call in seq['calls'])};report={'schema':'original-backend-service-cpu-dependencies-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':counts,'adapters':{'final COM':'Raw device calls at vtable offsets0x114/0x134/0xac/0xc/0x14/0xe4; opaque return and declared backend/cache/marker/enabled mutations. No device operations.','critical-section imports':'Enter/LeaveCriticalSection raw original object token, opaque result; no OS lock operation.'},'limits':['Original CPU helper bodies execute unchanged; final COM/OS boundaries only.','Sampler marker addresses and cache scaling wrap32bits. Only resolved marker/cache cells retained, including negative types/negative stages and large wrapped stage aliases. Marker invalidation is unconditional even for cache hits.','Status uniquely preserves LastResult except callback mutation; other wrappers store opaque result after callback. Clear depth finite only under original FLD/FSTP; other arguments raw.','Vendor matching uses original267-record table and sentinel, echoes IDs, writes flag1 and original selected record address or8294a8 fallback. Runtime IDs/table lifetime explicit.','Critical index1..12 dispatches original resolved object91ef70+index*24; outside range returns raw index with no OS call.','Native/model comparison passed; library compile and source replay are separate. No managed/game launch or live settings/device action.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report));raise SystemExit(0 if not errors else 1)
