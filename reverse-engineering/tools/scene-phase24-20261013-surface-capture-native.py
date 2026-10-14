"""Original surface readback caller; final COM, D3DX and debug allocator graphs explicit."""
import importlib.util,struct,json,gzip,random,copy
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase24-20261013-surface-capture'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');n=nx.NativeX86();x=load('x','animation-x87.py');W=x.wide;D=x.div
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_FPCW
B=0x29765c8;CACHE=0x297bea0;ASPECT=0x826494;SP=n.STACK+0xe000;OUT=n.DATA+0x8000;SRC=n.DATA+0x40010;DST=n.DATA+0x60010;CAPACITY=0x10000;DEVA=n.DATA+0x1000;DEVB=n.DATA+0x2000;VTA=n.DATA+0x3000;VTB=n.DATA+0x4000;RT=n.DATA+0x5000;OFF=n.DATA+0x6000;BUF=n.DATA+0x7000;OVT=n.DATA+0x9000;BVT=n.DATA+0xa000
EDGES={};counter=0
for kind,vt,offsets in [('device',VTA,{0x70:8,0x90:6,0x88:5,0x80:2}),('surface',OVT,{8:0}),('buffer',BVT,{8:0,0xc:0,0x10:0})]:
 for offset,count in offsets.items():edge=n.STOP+0x100+counter*0x40;counter+=1;EDGES[edge]=(kind,offset,count);n.pack('<I',vt+offset,edge)
for offset in [0x70,0x90,0x88,0x80]:n.pack('<I',VTB+offset,n.unpack('<I',VTA+offset)[0])
for token,vt in [(DEVA,VTA),(DEVB,VTB),(RT,OVT),(OFF,OVT),(BUF,BVT)]:n.pack('<I',token,vt)
EDGES[0x71572a]=('d3dx',0,5);EDGES[0x4eef40]=('allocate',0,3)
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def i32(v):return ((v+0x80000000)&0xffffffff)-0x80000000
def word(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def trunc(a):return (abs(a[0])<<a[1]if a[1]>=0 else abs(a[0])>>-a[1])*(-1 if a[0]<0 else 1)
case=0;events=[];scenario={};sizes=0;checks=0;errors=[];fixtures=[]
def snap():return {'backend':bytearray(n.read(B,0x800)),'cache':bytearray(n.read(CACHE,0x300)),'aspect':n.unpack('<I',ASPECT)[0],'output':n.unpack('<I',OUT)[0],'rt':n.unpack('<I',SP+4)[0],'off':n.unpack('<I',SP+8)[0],'buffer':n.unpack('<I',SP-8)[0],'source':bytearray(n.read(SRC-16,CAPACITY+32)),'destination':bytearray(n.read(DST-16,CAPACITY+32))}
def enc(s):return dict({k+'Hex':s[k].hex()for k in ['backend','cache','source','destination']},**{k:s[k]for k in ['aspect','output','rt','off','buffer']})
def dec(s):return dict({k:bytearray.fromhex(s[k+'Hex'])for k in ['backend','cache','source','destination']},**{k:s[k]for k in ['aspect','output','rt','off','buffer']})
def upload(s):
 n.write(B,s['backend']);n.write(CACHE,s['cache']);n.pack('<I',ASPECT,s['aspect']);n.pack('<I',OUT,s['output']);n.pack('<I',SP+4,s['rt']);n.pack('<I',SP+8,s['off']);n.pack('<I',SP-8,s['buffer']);n.write(SRC-16,s['source']);n.write(DST-16,s['destination'])
def service(s,kind,receiver,offset,args,out):
 global sizes
 # Retain image fingerprints before edges; full guarded images retained at final state.
 before=enc(s)
 for key in ['source','destination']:before[key+'Sha256']=__import__('hashlib').sha256(bytes.fromhex(before.pop(key+'Hex'))).hexdigest()
 out.append({'kind':kind,'receiver':receiver,'offset':offset,'arguments':args[:],'before':before})
 result=0
 stage={0x70:0,0x90:1,0x88:2,0x80:3}.get(offset)if kind=='device'else 4 if kind=='d3dx'else None
 if stage is not None:result=0x80004005 if scenario['fail']==stage else 0
 if kind=='device':
  if offset==0x70:s['rt']=0 if scenario['nullRt']else RT
  if offset==0x90:s['off']=0 if scenario['nullOff']else OFF
  if scenario['mutate']:
   w(s['backend'],4,DEVB if receiver==DEVA else DEVA);w(s['backend'],0x138,700+case);w(s['backend'],0x6e8,RT if case%2 else OFF);w(s['cache'],0,0x13570000+case)
 elif kind=='d3dx':s['buffer']=BUF
 elif kind=='allocate':result=0 if scenario['zeroAllocation']else DST
 elif kind=='buffer':
  if offset==0x10:
   result=scenario['sizes'][sizes];sizes+=1
   if sizes==2 and scenario['mutate']:w(s['source'],16,0x7f800001);w(s['source'],20,0xffc0deaf)
  elif offset==0xc:result=0 if scenario['zeroAllocation']else SRC
  elif offset==8:result=0xfedcba98
 elif kind=='surface':result=0xdeadbeef
 return result

def hook(mu,address,size,_):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];kind,off,count=EDGES[address];com=kind in ['device','surface','buffer'];receiver=n.unpack('<I',sp+4)[0]if com else 0;args=list(n.unpack('<'+str(count)+'I',sp+(8 if com else 4)))if count else [];state=snap();r=service(state,kind,receiver,off,args,events);upload(state);mu.reg_write(UC_X86_REG_EAX,r);mu.reg_write(UC_X86_REG_ECX,0xdeadbeef);mu.reg_write(UC_X86_REG_EDX,0xa5a5a5a5);mu.reg_write(UC_X86_REG_ESP,sp+4+(count+1)*4 if com else sp+24 if kind=='d3dx'else sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
lastCopy=None
def copyEntry(mu,address,size,_):
 global lastCopy
 sp=mu.reg_read(UC_X86_REG_ESP);lastCopy=list(n.unpack('<3I',sp+4))
n.mu.hook_add(UC_HOOK_CODE,copyEntry,begin=0x4ef660,end=0x4ef660)
for edge in EDGES:n.mu.hook_add(UC_HOOK_CODE,hook,begin=edge,end=edge)

def model(s,width,height,out):
 s['rt']=0;s['off']=0;result=0
 if width==0:width=u(s['backend'],0x138)
 if height==0:
  ratio=struct.unpack('<f',struct.pack('<I',u(s['backend'],0x630)))[0]if s['aspect']==3 else [struct.unpack('<f',struct.pack('<I',v))[0]for v in [0x3faaaaab,0x3fe38e39,0x3fcccccd]][s['aspect']]if s['aspect']<3 else struct.unpack('<f',struct.pack('<I',0x3faaaaab))[0];height=trunc(D(W(width),W(ratio)))&0xffffffff;s['buffer']=height
 def device(off,args):return service(s,'device',u(s['backend'],4),off,args,out)
 proceed=i32(device(0x70,[width,height,21,0,0,0,SP+4,0]))>=0 and s['rt']!=0
 if proceed:proceed=i32(device(0x90,[width,height,21,2,SP+8,0]))>=0 and s['off']!=0
 if proceed:proceed=i32(device(0x88,[u(s['backend'],0x6e8),0,s['rt'],0,2]))>=0
 if proceed:proceed=i32(device(0x80,[s['rt'],s['off']]))>=0
 if proceed:s['buffer']=0;proceed=i32(service(s,'d3dx',0,0,[SP-8,0,s['off'],0,0],out))>=0
 if proceed:
  amount=service(s,'buffer',s['buffer'],0x10,[],out);destination=service(s,'allocate',0,0,[amount,0x776f50,0x989],out);s['output']=destination;count=service(s,'buffer',s['buffer'],0x10,[],out);source=service(s,'buffer',s['buffer'],0xc,[],out)
  if count:assert source==SRC and destination==DST;s['destination'][16:16+count]=s['source'][16:16+count]
  result=service(s,'buffer',s['buffer'],0x10,[],out)
 if s['rt']:service(s,'surface',s['rt'],8,[],out);s['rt']=0
 if s['off']:service(s,'surface',s['off'],8,[],out);s['off']=0
 if s['buffer']:service(s,'buffer',s['buffer'],8,[],out)
 return result

def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<12:errors.append({'case':case,'label':label,'native':a,'model':e})
def retain(s,raw):
 if raw:return s
 out=dict(s)
 for key in ['source','destination']:
  b=bytes.fromhex(out.pop(key+'Hex'));out[key+'Sha256']=__import__('hashlib').sha256(b).hexdigest();out[key+'GuardHex']=(b[:16]+b[-16:]).hex()
 return out
rng=random.Random(0x6e28e024)
for case in range(1024):
 b=bytearray(rng.randbytes(0x800));cache=bytearray(rng.randbytes(0x300));w(b,4,DEVA);w(b,0x138,[640,1920,1,32768][case%4]);w(b,0x630,word([1,1.3333334,1.7777778,1.6][case%4]));w(b,0x6e8,RT);width=[0,1,640,32768,0x7fffffff,0xffffffff][case%6];height=[0,1,480,0xffffffff][case%4]
 if width==0xffffffff and height==0:height=1
 source=bytearray(rng.randbytes(CAPACITY+32));destination=bytearray([0xa7])*(CAPACITY+32);s={'backend':b,'cache':cache,'aspect':[0,1,2,3,4,0xffffffff][case%6],'output':rng.getrandbits(32),'rt':width,'off':height,'buffer':BUF if case%3==0 else 0,'source':source,'destination':destination};scenario={'fail':case%7 if case%7<5 else -1,'nullRt':case%17==0,'nullOff':case%19==0,'mutate':case%3==0,'zeroAllocation':case%11==0,'sizes':[[0,0,0x80000001],[64,32,65],[65536,65536,0xffffffff],[128,128,0]][case%4]};
 if scenario['zeroAllocation']:scenario['sizes'][1]=0
 if height==0:
  if case%16==0:width=BUF;s['aspect']=3;w(b,0x630,word(1))
  elif case%16==8:width=0;w(b,0x138,0)
  else:scenario['fail']=4 if scenario['fail']==4 else-1;scenario['nullRt']=False;scenario['nullOff']=False
 before=enc(s);upload(s);sizes=0;events=[];actual=n.call(0x6e28e0,[width,height,OUT],regs={UC_X86_REG_ECX:B},count=2000000);after=enc(snap());expected=dec(before);sizes=0;out=[];result=model(expected,width,height,out);ck(actual,result,'return');ck(after,enc(expected),'raw images guards output and argument/local boxes');ck(events,out,'ordered services and image fingerprints');ck(n.mu.reg_read(UC_X86_REG_ESP),SP+16,'thiscall ret12');ck(n.mu.reg_read(UC_X86_REG_FPCW),0x37f,'x87 control restored');fixtures.append({'case':case,'before':retain(before,case<16 or case%128==0),'width':width,'height':height,'scenario':copy.deepcopy(scenario),'events':events,'after':retain(after,case<16 or case%128==0),'rawGuardedBuffersRetained':case<16 or case%128==0,'return':actual})
report={'status':'passed'if not errors else'failed','binarySHA256':n.sha256,'calls':len(fixtures),'checks':checks,'failures':errors,'boundaryEvents':sum(len(z['events'])for z in fixtures),'fullRawBufferCases':sum(z['rawGuardedBuffersRetained']for z in fixtures),'bufferEvidence':'Every native/model full byte and guard comparison performed; every fixture/event retains buffer SHA256;23 representative cases also retain full raw guarded buffers. Exact deterministic source seed/tool replay retained.','scope':'Original6e28e0 and actual memcpy4ef660 unchanged. Final surface/device/buffer COM, D3DX save-to-memory71572a and debug allocator4eef40 explicit. Incoming buffer local entrySP-8 supplied as0/resolved SDK object for explicit height; computed-height FISTP64 low word overwrites it for height0. Early-failure pointer must resolve; successful D3DX clears/replaces it. No device/SDK/OS/game/managed launch.'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2))
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt')as f:json.dump({'report':report,'fixtures':fixtures},f,separators=(',',':'))
print(json.dumps({k:v for k,v in report.items()if k!='failures'},indent=2));print('failures',[(z['case'],z['label'])for z in errors]);raise SystemExit(bool(errors))
