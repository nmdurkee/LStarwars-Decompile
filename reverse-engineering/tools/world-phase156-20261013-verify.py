import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x297c190,4,0),(0x829580,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

trace=[];case={};entries={}
def service(im,address,args):
 trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(hex(address),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['errnoPointer'] if address==0x6ead5f else case['endpoint']
def mode(im,value):
 if S(value)>=0 and value<=3:
  old=im.W(0x297c190)
  if value!=3:im.W(0x297c190,value)
  return old
 im.W(service(im,0x6ead5f,[]),22);service(im,0x6e9fc2,[0]*5);return 0xffffffff
def apply(im,c):
 if c['entry']==0x7022ca:return mode(im,c['args'][0])
 if c['entry']==0x702310:im.W(0x829580,c['args'][0]);return None
 if c['entry']==0x70231a:return im.W(0x829580)
 if mode(im,3)!=1 and (mode(im,3)!=0 or im.W(0x829580)!=1):return None
 service(im,0x6f09f8,[252]);service(im,0x6f09f8,[255]);return None
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
 def write(self,a,v):n.write(U(a),v)
ni=NI()
def observe(uc,address,size,user):
 if address in [0x6f0bb8,0x7022ca,0x702310,0x70231a]:entries[hex(address)]=entries.get(hex(address),0)+1
 if address not in [0x6ead5f,0x6e9fc2,0x6f09f8]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if address==0x6ead5f else 5 if address==0x6e9fc2 else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];value=service(ni,address,args);uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013156);cases=[]
def seed(entry,value=0,old=0,app=0):return dict(entry=entry,args=[value] if entry in [0x7022ca,0x702310] else [],errnoPointer=D+0x100,endpoint=0xfedcba98,writes=[word(0x297c190,old),word(0x829580,app),word(D+0x100,0xa5a5a5a5)])
for entry in [0x7022ca,0x702310,0x70231a,0x6f0bb8]:
 for i in range(192):cases.append(seed(entry,rng.choice([0,1,2,3,4,0x7fffffff,0x80000000,0xffffffff,rng.getrandbits(32)]),rng.choice([0,1,2,3,0xffffffff,rng.getrandbits(32)]),rng.choice([0,1,2,3,0xffffffff,rng.getrandbits(32)])))
for pointer in [D+0x100,0x297c190,0x829580]:
 for value in [4,0x80000000,0xffffffff]:
  c=seed(0x7022ca,value,1,1);c['errnoPointer']=pointer;c['serviceWrites']={'0x6ead5f':[word(0x297c190,2)],'0x6e9fc2':[word(0x829580,0x34567890)]};cases.append(c)
for modeValue in [0,1]:
 c=seed(0x6f0bb8,old=modeValue,app=1);c['serviceWrites']={'0x6f09f8':[word(0x297c190,2),word(0x829580,0)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for address,size,fill in REGIONS:n.write(address,initial.read(address,size))
 result=n.call(c['entry'],c['args'],count=100000);actualResult=result if c['entry'] in [0x7022ca,0x70231a] else None;actual=hashlib.sha256(b''.join(n.read(address,size) for address,size,fill in REGIONS)).hexdigest()
 if actualResult!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=actualResult,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(result=actualResult,trace=trace,sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase156-20261013-ptl-runtime-diagnostic-policy.cs').read_bytes()).hexdigest(),originalBodies=[dict(address=hex(a),length=z,sha256=hashlib.sha256(n.read(a,z)).hexdigest()) for a,z in [(0x6f0bb8,57),(0x7022ca,70),(0x702310,10),(0x70231a,6)]],domain='complete original banner/mode bodies and raw application-type accessor bytes; signed mode validation, query/replace, returning invalid-parameter endpoint, errno aliases, cached banner decision through writer callback mutations; void incidental EAX excluded',nativeAdapters=['6ead5f errno pointer','6e9fc2 returning invalid parameter dispatcher','6f09f8 error writer'],reaEvidenceIds=["ev_288ef2b0f066521902e299a07820c40cd11171584cbecd55daa2ac36ae44decb","ev_e26950b0c8afdccd768980e787198755d2ec263bc292df590cc4db23b5fe133a"],rawAccessorEvidence='Ghidra function manager did not expose 702310/70231a; exact PE bytes and native execution retained without claiming live function-manager evidence',managedReplayExecuted=False,seconds=round(time.time()-start,3))
(B/'reports/world-phase156-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase156-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
