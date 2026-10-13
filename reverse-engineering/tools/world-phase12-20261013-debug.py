import json,struct,hashlib,base64,time
from pathlib import Path
peer=Path(__file__).with_name('world-phase11-20261013-verify.py');ns={'__file__':str(peer)};src=peer.read_text();exec(compile(src[:src.rindex('cases=[];provenance=[]')],str(peer),'exec'),ns)
startgen=src.index('# Structured bounded records');endgen=src.index('for v in range(1,17):',startgen);exec(compile(src[startgen:endgen],str(peer),'exec'),ns)
n=ns['n'];B=ns['B'];D=ns['D'];REC=ns['REC'];io=ns['scope'];wp=ns['wp'];patch=ns['patch'];U=ns['U'];S=ns['S'];IN=0x291f7a8;BANKS=0x292089c;SCENES=0x29208d0;TOTALR=0x2920a94;TOTALI=0x2920a98
REGIONS=[(a,132 if a==SCENES else z) for a,z in ns['REGIONS']]+[(REC-376,376),(IN,40*108),(BANKS,32),(0x2920888,4),(0x292096c,8),(0x2920a90,12),(0x8109d0,4),(0x296292c,4)];ns['REGIONS']=REGIONS;io['REGIONS']=REGIONS
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
runtimeEvents=[];runtimeOptions=None;outerCalls=0
class Image(ns['Image']):
 def __init__(self,c):
  self.regions={a:bytearray([167 if a==REC else 0])*z for a,z in REGIONS}
  for p in c['writes']:self.write(p['address'],base64.b64decode(p['data']))
def sprite(m,q,scene):
 if scene:assert m.word(scene+0x110)==0 and m.word(scene+0x24)==0
 ns['emit'](0x6488e0,q,scene);return 9999 if q.split(b'\0',1)[0]==b'NULL instance' else -1
ns['sprite']=sprite
class Native(io['Native']):
 def half(self,a,v=None):
  if v is None:return n.unpack('<H',a)[0]
  n.pack('<H',a,v&65535)
vm=Native()
def runtime(m,kind,args):
 runtimeEvents.append([kind]+args)
 if kind=='activate':
  at=IN+args[0]*108;m.word(at+32,0);m.word(at+36,0x3f800000)
  if runtimeOptions.get('clearActivated'):m.word(at+12,0xffffffff)
  if runtimeOptions.get('countMutation'):m.word(TOTALI,7)
 else:
  m.word(0x2920888,0xffffffff);m.word(0x292096c,0);m.word(0x2920970,0)
  if runtimeOptions.get('selectMutation'):m.word(BANKS+4,0x777);m.word(0x8109d0,0x888)
def observe(uc,a,z,data):
 global outerCalls
 if a==0x64c300:outerCalls+=1;return
 sp=uc.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4+i*4)[0]
 runtime(vm,'activate' if a==0x64ae50 else 'select',[arg(0),arg(1)] if a==0x64ae50 else [arg(0)])
 uc.reg_write(UC_X86_REG_EAX,0);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
for a in [0x64c300,0x64ae50,0x644000]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def load(m,c):
 kind=c['mode']&255;bank=0
 if kind:
  bank=1
  while m.word(BANKS+bank*4):
   bank+=1
   if bank>7:return 0xffffffff
 slot=0
 for i in range(c['sceneCount']):
  scene=m.word(D+0x90000+i*4)
  if not scene:continue
  while m.word(SCENES+slot*4):
   if slot>31:break
   slot+=1
  if slot<32:m.word(SCENES+slot*4,scene);m.word(0x291f688+slot*4,bank)
 m.word(io['MODE'],1)
 if not io['open_read'](m):return 0xffffffff
 version=ns['word'](m)
 if not 1<=version<=16:io['close_read'](m);return 0xffffffff
 requested=S(ns['word'](m));overflow=0
 if S(m.word(TOTALR))+requested>128:overflow=S(m.word(TOTALR))+requested-128;requested-=overflow
 recordslot=0
 for i in range(max(0,requested)):
  at=REC+recordslot*376
  while m.read(at,1)!=b'\0':recordslot+=1;at+=376
  ns['decode'](m,at,version,bank)
  if m.read(at,1)!=b'\0':m.word(TOTALR,m.word(TOTALR)+1);m.write(at+178,bytes([bank,kind]))
 # Native discarded record lives on stack and is not part of captured regions.
 scratch=D+0xe0000;m.regions[scratch]=bytearray(376)
 for i in range(max(0,overflow)):ns['decode'](m,scratch,version,bank)
 requested=S(ns['word'](m))
 if S(m.word(TOTALI))+requested>40:requested=40-S(m.word(TOTALI))
 instance=0
 for i in range(max(0,requested)):
  at=IN+instance*108
  while m.word(at+12)!=0xffffffff:instance+=1;at+=108
  for off in [0,4,8]:m.word(at+off,ns['word'](m))
  m.write(at+16,ns['name'](m));id=resolver(m,at+16,bank);m.word(at+12,id)
  for off in [48,46,44]:m.half(at+off,ns['half'](m))
  for off in [68,70]:m.half(at+off,0 if version<11 else ns['half'](m))
  m.write(at+50,bytes([bank]));m.write(at+60,b'\0');r=U(REC+id*376)
  for sound in range(4):
   if m.word(r+328+sound*4)!=0xffffffff and m.read(r+344+sound,1)!=b'\0':m.write(at+60,b'\x01');break
  if id!=0xffffffff:m.word(TOTALI,m.word(TOTALI)+1);runtime(m,'activate',[instance,0]);m.write(at+61,b'\x01')
 io['close_read'](m);runtime(m,'select',[0x3f800000]);m.word(BANKS+bank*4,1)
 if bank==0:m.word(0x2913a2c,1)
 if kind==0:m.word(0x296292c,bank)
 elif kind==1:m.word(0x8109d0,bank)
 return bank
# Exact64b020 model from sealed phase10; original function runs unmodified in native path.
def resolver(m,q,p):
 if m.read(q,1)==b'\0':return 0xffffffff
 if U(p-1)<7:
  for i in range(128):
   r=REC+i*376
   if m.read(r+178,1)[0]==p and ns['eq16'](m.read(q,16),m.read(r,16)):return i
 for i in range(128):
  r=REC+i*376
  if m.read(r+178,1)[0]==0:
   a=m.read(q,16);b=m.read(r,16);eq=True
   for x,y in zip(a,b):
    if x!=y:eq=False;break
    if not x or not y:break
   if eq:return i
 return 0xffffffff
def seed(payload,mode=1,sceneCount=1,existing=0,fullScenes=False,instances=0):
 c=ns['seed'](payload);c.update(mode=U(mode),sceneCount=sceneCount)
 c['writes'].extend([wp(TOTALR,existing),wp(TOTALI,instances),wp(0x2920888,0xffffffff),wp(0x8109d0,0xdeadbeef),wp(0x296292c,0x12345678)])
 for i in range(128):c['writes'].extend([patch(REC+i*376,b'\0'),patch(REC+i*376+144,b'\xff'*16)])
 for i in range(existing):c['writes'].extend([patch(REC+i*376,('existing'+str(i)).encode()+b'\0'),patch(REC+i*376+178,b'\x07')])
 for i in range(40):c['writes'].append(wp(IN+i*108+12,0xffffffff))
 for i in range(instances):c['writes'].append(wp(IN+i*108+12,0))
 for i in range(sceneCount):c['writes'].append(wp(D+0x90000+i*4,D+0x94000+i*0x400 if i%3!=2 else 0))
 if fullScenes:
  for i in range(33):c['writes'].append(wp(SCENES+i*4,D+0x94000))
 return c
cases=[];provenance=[]
for f in sorted((B/'extracted').rglob('*.PAR')):
 payload=f.read_bytes();p=str(f.relative_to(B)).replace('\\','/');provenance.append(dict(path=p,bytes=len(payload),sha256=hashlib.sha256(payload).hexdigest()));c=seed(payload);c['authored']=p;cases.append(c)
record=ns['record'];packed=ns['packed_name']
def stream(v=16,records=2,instances=2,missing=False,swap=False):
 fmt='>' if swap else '<'
 out=struct.pack(fmt+'II',v,records)+b''.join(record(v,swap) for i in range(records))+struct.pack(fmt+'I',instances)
 for i in range(instances):
  out+=struct.pack(fmt+'III',0x3f800000+i,0x80000000,0x40000000)+packed('missing' if missing else 'RECORD')+struct.pack(fmt+'HHH',i,0x8000,0xffff)
  if v>=11:out+=struct.pack(fmt+'HH',0xabcd,0x8000)
 return out
for mode in [0,1,2,255,256,0xffffffff]:
 for refs in [0,1,5,34]:cases.append(seed(stream(),mode,refs))
for existing in [0,126,127,128]:
 for active in [0,39,40]:cases.append(seed(stream(records=3,instances=3),existing=existing,instances=active))
for full in [False,True]:cases.append(seed(stream(),sceneCount=3,fullScenes=full))
for mode in [0,1]:
 c=seed(stream(),mode);c['writes'].extend(wp(BANKS+i*4,1) for i in range(8));cases.append(c)
for data in [b'',struct.pack('<II',0,0),struct.pack('<II',17,0),struct.pack('<II',0xffffffff,0)]:cases.append(seed(data,sceneCount=4))
for ret in [0,0xffffffff]:c=seed(stream());c['openResult']=ret;cases.append(c)
for option in ['clearActivated','countMutation','selectMutation']:
 c=seed(stream(instances=4));c[option]=True;cases.append(c)
c=seed(stream(missing=True));c['writes'].append(patch(REC-376+344,b'\x01'));cases.append(c)
for version in range(1,17):
 for swapped in [False,True]:
  c=seed(stream(v=version,swap=swapped));c['writes'].append(wp(io['SWAP'],1 if swapped else 0));cases.append(c)
for mode in [0,1]:
 c=seed(stream(),mode);c['writes'].append(wp(BANKS,1));c['writes'].append(wp(BANKS+4,1));cases.append(c)
for payload in [struct.pack('<III',16,0xffffffff,0),struct.pack('<III',16,0,0xffffffff)]:cases.append(seed(payload))
c=seed(stream());c['writes'].append(wp(io['HANDLE'],1));cases.append(c)
c=seed(struct.pack('<II',16,1)+bytes(16)+record(16)[16:]+struct.pack('<I',0));cases.append(c)
cases=cases[:1]
rows=[];fails=[];start=time.time();decoded=0
for index,c in enumerate(cases):
 io['current']=c;runtimeOptions=c;m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;ns['assetHash']=hashlib.sha256();ns['assetCounts']={};runtimeEvents=[]
 ret=n.call(0x64c300,[io['PATH'],c['mode'],D+0x90000,c['sceneCount']],count=100000000)
 observed=dict(result=ret,sha256=vm.digest(),assetSha256=ns['assetHash'].hexdigest(),assetCalls=ns['assetCounts'].copy(),runtime=runtimeEvents.copy(),trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;ns['assetHash']=hashlib.sha256();ns['assetCounts']={};runtimeEvents=[]
 result=load(m,c);prediction=dict(result=result,sha256=m.digest(),assetSha256=ns['assetHash'].hexdigest(),assetCalls=ns['assetCounts'].copy(),runtime=runtimeEvents.copy(),trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 if observed!=prediction:fails.append(dict(case=index,observed=observed,prediction=prediction,diffs=[dict(address=hex(a+j),native=vm.read(a+j,4).hex(),model=m.read(a+j,4).hex()) for a,z in REGIONS for j in range(0,z,4) if vm.read(a+j,4)!=m.read(a+j,4)][:25]));print(json.dumps(fails[-1]));break
 c['expected']=observed;rows.append(c)
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(fails),outerCalls=outerCalls,nativeDecoderAndAssetCalls=ns['totals'],authoredFiles=provenance,seconds=round(time.time()-start,3),failures=fails)
(B/'reports/world-phase12-20261013-debug-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fails:(B/'reports/world-phase12-20261013-debug-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==REC else 0) for a,z in REGIONS],authoredFiles=provenance,cases=rows),separators=(',',':'))+'\n')
print(json.dumps({k:v for k,v in report.items() if k!='authoredFiles'}));assert not fails
