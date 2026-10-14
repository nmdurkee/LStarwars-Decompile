import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
def error(im,value):
 im.W(service(im,0x6ead5f,[]),value);service(im,0x6e9fc2,[0]*5);return value
def apply(im,c):
 entry=c['entry'];output,capacity,input=c['args'][:3];count=c['args'][3] if entry==0x702217 else None
 if entry==0x702217 and count==0 and output==0 and capacity==0:return 0
 if not output or not capacity:return error(im,22)
 if entry==0x702217 and count==0:im.B(output,0);return 0
 if not input:im.B(output,0);return error(im,22)
 cursor=output;remaining=capacity
 if entry==0x7021a6:
  while im.B(cursor):
   cursor=U(cursor+1);remaining=U(remaining-1)
   if not remaining:break
  if not remaining:im.B(output,0);return error(im,22)
 while True:
  value=im.B(input);input=U(input+1);im.B(cursor,value);cursor=U(cursor+1)
  if not value:break
  remaining=U(remaining-1)
  if not remaining:break
  if entry==0x702217 and count!=0xffffffff:
   count=U(count-1)
   if not count:im.B(cursor,0);break
 if remaining:return 0
 if entry==0x702217 and count==0xffffffff:im.B(U(output+capacity-1),0);return 80
 im.B(output,0);return error(im,34)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
 def write(self,a,v):n.write(U(a),v)
ni=NI()
def observe(uc,address,size,user):
 if address in [0x6f8503,0x7021a6,0x702217]:entries[hex(address)]=entries.get(hex(address),0)+1
 if address not in [0x6ead5f,0x6e9fc2]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if address==0x6ead5f else 5;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];value=service(ni,address,args);uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013159);cases=[]
def seed(entry,output,capacity,input,count=3):return dict(entry=entry,args=[output,capacity,input]+([count] if entry==0x702217 else []),errnoPointer=D+0x100,endpoint=0xfedcba98,writes=[word(D+0x100,0xa5a5a5a5),patch(D+0x1000,b'initial\0'+bytes(128)),patch(D+0x2000,b'source\0'+bytes(128))])
for entry in [0x6f8503,0x7021a6,0x702217]:
 for i in range(768):
  c=seed(entry,D+0x1000 if i%17 else 0,rng.choice([0,1,2,3,4,7,8,16,32,64,100]),D+0x2000 if i%19 else 0,rng.choice([0,1,2,3,7,16,64,100,0xffffffff]));c['writes'] += [patch(D+0x1000,bytes(rng.randrange(1,256) for _ in range(rng.randrange(100)))+bytes([0])),patch(D+0x2000,bytes(rng.randrange(1,256) for _ in range(rng.randrange(100)))+bytes([0]))];cases.append(c)
 for offset in [-16,-4,-1,0,1,4,16]:
  for capacity in [1,4,8,16,64]:
   c=seed(entry,D+0x2000+offset,capacity,D+0x2000,3);cases.append(c)
 for pointer in [D+0x1000,D+0x2000,D+0x100]:
  c=seed(entry,D+0x1000,1,D+0x2000,3);c['errnoPointer']=pointer;c['serviceWrites']={'0x6ead5f':[patch(D+0x2000,b'changed\0')],'0x6e9fc2':[word(D+0x108,0xabcdef01)]};cases.append(c)
for capacity in [0,1,0xffffffff]:
 for output in [0,D+0x1000]:cases.append(seed(0x702217,output,capacity,0,0))
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for address,size,fill in REGIONS:n.write(address,initial.read(address,size))
 result=n.call(c['entry'],c['args'],count=100000);actual=hashlib.sha256(b''.join(n.read(address,size) for address,size,fill in REGIONS)).hexdigest()
 if result!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=result,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(result=result,trace=trace,sha256=actual);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase159-20261013-ptl-runtime-secure-strings.cs').read_bytes()).hexdigest(),originalBodies=[dict(address=hex(a),length=z,sha256=hashlib.sha256(n.read(a,z)).hexdigest()) for a,z in [(0x6f8503,101),(0x7021a6,113),(0x702217,179)]],domain='complete byte-order copy/append/bounded copy, signed-null validation and unsigned capacities; prepared readable buffers, overlapping spans, unterminated bounded destination, null pointers, count-zero special case and truncation-80 policy, error pointer aliases and callback mutations; private count stack-word alias exposure excluded',nativeAdapters=['6ead5f errno pointer','6e9fc2 returning invalid parameter dispatcher'],reaEvidenceIds=["ev_50a9aa772058ebf501a1ecece3a013f9711a6886fd161aa53c3bbf8c31e86189","ev_58f4ab562045dafd69eb776dd800f572368cc44dc76b2ecaf46414b08a2a8c9e","ev_0f0606c6b81a28383708919779ff4eb62b722e37b7e3e6548433f0b57caf107b"],managedReplayExecuted=False,seconds=round(time.time()-start,3))
(B/'reports/world-phase159-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase159-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
