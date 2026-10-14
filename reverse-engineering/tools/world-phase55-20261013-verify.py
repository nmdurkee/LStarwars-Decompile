import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x30000,167),(0x2961f00,0x400,0),(0x2921100,0x200,0),(0x2947b70,4,0),(0x2923180,0x80,0),(0x292fbfc,8,0),(0x8108e8,8,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
class Image(rot['Image']):
 def read(self,a,z):return super().read(U(a),z)
 def write(self,a,v):return super().write(U(a),v)
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))
def functions(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);t=ast.parse(p.read_text());ctx=dict(U=U,F=F,S=S);exec(compile(ast.Module(body=[x for x in t.body if isinstance(x,ast.FunctionDef)],type_ignores=[]),str(p),'exec'),ctx);return ctx
links=functions(24);unlinks=functions(26)
def E(im,ref):return U(im.W(0x29620a4)+im.W(ref)*0x330)
def slot(im,ref,i):return U(E(im,ref)+0x100+i*4)
def node(im):return im.W(im.W(0x2923198)+im.W(0x2947b70)*4)
def release(im,c):
 ref=c['reference'];id=im.W(ref)
 if id==0xffffffff:return
 e=U(im.W(0x29620a4)+id*0x330)
 if im.B(e+0x185):return
 im.B(e+0x185,1);cursor=S(im.W(0x29211e8));limit=S(im.W(0x2962094))
 if cursor<limit:
  cached=im.W(ref);fifo=im.W(0x2962084)
  for i in range(cursor,limit):
   if S16(im.H(fifo+i*2))==S(cached):im.B(im.W(0x29620a4)+cached*0x330+0x185,0);im.W(ref,0xffffffff);return
 e=E(im,ref);physical=S16(im.H(e+0x182))
 if physical==0:im.B(e+0x185,0);return
 record=im.W(im.W(0x296209c)+physical*4)
 if im.H(e+0x180):
  assert not im.W(0x2962058);im.W(0x2962058,1);i=0
  while i<S16(im.H(E(im,ref)+0x180)):
   unlinks['cancel'](im,im.W(slot(im,ref,i)));at=node(im);im.W(at,im.W(slot(im,ref,i)));im.W(node(im)+8,7 if im.B(record+0x2e)==7 else 0);im.W(node(im)+12,0);bank=im.B(record+0x2f1)==4;live=im.W(im.W(0x296209c)+S16(im.H(E(im,ref)+0x182))*4);product=N.word(im.W(live+0x414))*N(S8(im.B(live+0x410)));sum=N.word(im.W(live+0xa4))+N.word(im.W(0x2962060 if bank else 0x296205c));im.W(node(im)+4,(sum+product).store());links['timed'](im,node(im),0x292fc00 if bank else 0x292fbfc);im.W(0x2947b70,im.W(0x2947b70)+1);i+=1
  im.W(0x2962058,0);capacity=S(im.W(0x8108e8)+im.W(0x8108ec))
  if capacity>0:
   packets=im.W(0x2961fec);chunk=im.W(slot(im,ref,0))
   for at in range(capacity):
    if im.W(packets+at*0x64)==chunk:
     offset=at*0x64;im.W(packets+offset+4,record);im.W(im.W(0x2961fec)+offset+8,0);source=E(im,ref)+0x40;dest=im.W(0x2961fec)+offset+12
     for j in range(16):im.W(dest+j*4,im.W(source+j*4))
     for j in range(3):value=im.W(E(im,ref)+0x190+j*4);im.W(im.W(0x2961fec)+offset+0x4c+j*4,value)
     break
 found=False
 for i in range(8):
  at=record+0x3d0+i*2
  if S16(im.H(at))==S(im.W(ref)):found=True;im.H(at,65535)
 if not found:
  e=E(im,ref);previous=im.W(e+0x1cc)
  if not previous:
   next=im.W(e+0x1c8);im.W(0x29620a8,next)
   if next:im.W(next+0x1cc,0)
  else:
   im.W(previous+0x1c8,im.W(e+0x1c8));next=im.W(e+0x1c8)
   if next:im.W(next+0x1cc,im.W(e+0x1cc))
  im.W(e+0x1cc,0);im.W(e+0x1c8,0)
 i=0
 while i<S16(im.H(E(im,ref)+0x180)):im.W(slot(im,ref,i),0);i+=1
 im.H(E(im,ref)+0x180,0);im.H(E(im,ref)+0x182,0);im.H(E(im,ref)+0x32a,65535);count=im.W(0x29211e8);free=im.W(0x2962084);count=U(count-1);im.W(0x29211e8,count);im.H(free+count*2,im.H(ref));im.B(E(im,ref)+0x185,0);im.W(ref,0xffffffff)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x683f50,0x655250,0x655210]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(chunks=2,typ=0,bank=0,match=-1):
 e=EM+0x330;c=dict(reference=REF,writes=[word(REF,1),word(0x29620a4,EM),word(0x29211e8,8),word(0x2962094,8),word(0x2962084,FIFO),word(0x296209c,TABLE),byte(e+0x185,0),half(e+0x182,1),half(e+0x180,chunks),half(e+0x32a,3),word(e+0x1c8,0),word(e+0x1cc,0),word(0x29620a8,e),word(TABLE+4,R),word(0x2962058,0),word(0x2947b70,0),word(0x2923198,RETURN),word(0x2961fec,PACKETS),word(0x8108e8,8),word(0x8108ec,8),byte(R+0x2e,typ),byte(R+0x2f1,bank),word(R+0xa4,bits(2)),byte(R+0x410,2),word(R+0x414,bits(.25)),word(0x296205c,bits(10)),word(0x2962060,bits(20)),word(0x292fbfc,0),word(0x292fc00,0),patch(e+0x40,struct.pack('<16f',*[i/16 for i in range(16)])),patch(e+0x190,struct.pack('<3f',1.25,-2.5,-0.0))])
 for i in range(16):c['writes'] += [half(FIFO+i*2,i),word(RETURN+i*4,NODES+i*0x40),word(NODES+i*0x40+16,0),word(PACKETS+i*0x64,CHUNKS if i==3 else 0)]
 for i in range(8):c['writes'] += [word(e+0x100+i*4,CHUNKS+i*0x400),half(R+0x3d0+i*2,1 if i==match else 65535)]
 return c
cases=[seed()]
for chunks in [-2,-1,0,1,2,3,8]:
 for typ in [0,7]:
  for bank in [0,4]:
   for match in [-1,0,7]:cases.append(seed(chunks,typ,bank,match))
for index in range(8):
 c=seed();c['writes'] += [word(0x29211e8,index)];cases.append(c)
for busy in [0,1,127,255]:c=seed();c['writes'].append(byte(EM+0x330+0x185,busy));cases.append(c)
for id in [0xffffffff,0,1,7]:
 c=seed();c['writes'] += [word(REF,id),word(0x29620a4,U(EM+0x330-id*0x330))];cases.append(c)
c=seed();c['writes'] += [half(EM+0x330+0x182,0)];cases.append(c)
for frames in [-128,-1,0,1,2,127]:
 for delay in [0,0x80000000,bits(.25),bits(-.5)]:
  for bank in [0,4]:c=seed(bank=bank);c['writes'] += [byte(R+0x410,frames),word(R+0x414,delay)];cases.append(c)
for packet in range(-1,16):
 c=seed();c['writes'] += [word(PACKETS+3*0x64,0)];
 if packet>=0:c['writes'].append(word(PACKETS+packet*0x64,CHUNKS))
 cases.append(c)
for previous in [0,EM,EM+0x660]:
 for next in [0,EM,EM+0x660]:
  c=seed();c['writes'] += [word(EM+0x330+0x1cc,previous),word(EM+0x330+0x1c8,next)];cases.append(c)
for bank in [0,4]:
 c=seed(bank=bank);c['writes'] += [word(0x292fbfc if bank==0 else 0x292fc00,NODES),word(NODES,CHUNKS),word(NODES+4,bits(1)),word(NODES+16,NODES+0x40),word(NODES+0x40,CHUNKS+0x400),word(NODES+0x40+4,bits(2)),word(NODES+0x40+16,0),word(0x2947b70,2)];cases.append(c)
rng=random.Random(2026101355)
for i in range(512):
 c=seed(rng.randrange(9),rng.choice([0,7]),rng.choice([0,4]),rng.randrange(-1,8));c['writes'] += [word(R+0xa4,bits(rng.uniform(-32,32))),word(R+0x414,bits(rng.uniform(-4,4))),byte(R+0x410,rng.randrange(256)),word(0x296205c,bits(rng.uniform(-512,512))),word(0x2962060,bits(rng.uniform(-512,512)))];cases.append(c)
# Readable aliases: clearing the first chunk changes the caller ID; return tag overwrites its live counter; packet copies overlap forward.
c=seed();c['reference']=EM+0x330+0x100;c['writes'] += [word(c['reference'],1),half(EM+0x180,0),half(EM+0x182,1),byte(EM+0x185,0)];cases.append(c)
for shift in [-8,-4,0,4,8,16]:
 c=seed(chunks=1);packet=EM+0x330+0x40-12+shift;c['writes'] += [word(0x2961fec,packet),word(packet,CHUNKS)];cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:release(im,c)
 except (ValueError,OverflowError,ZeroDivisionError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x683f50,[c['reference']],count=1000000)
 except Exception as ex:errors.append(dict(case=i,nativeError=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase55-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase55-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
