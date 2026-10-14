import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x829ab4,8,0),(0x297c540,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

GET=0x10300000;SET=GET+0x100;LAST=GET+0x400;RESTORE=GET+0x500;THREAD=GET+0x600
n.mu.mem_map(GET,0x1000)
for address in [GET,SET,LAST,RESTORE,THREAD]:n.write(address,b'\xc3')
for address,target in [(0x751190,LAST),(0x7511d0,RESTORE),(0x7510d8,THREAD)]:n.write(address,struct.pack('<I',target))
trace=[];case={};counts={}
def service(im,address,args):
 key=hex(address);index=counts.get(key,0);counts[key]=index+1;trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 sequence=case.get('sequenceWrites',{}).get(key,[])
 if index<len(sequence):
  for p in sequence[index]:im.write(p['address'],base64.b64decode(p['data']))
 return {0x751190:case['lastError'],0x6f024e:GET,GET:case['existing'],0x6f07af:case['allocation'],0x6f01bc:SET,SET:case['setterResult'],0x7510d8:case['threadId']}.get(address,case.get('otherResult',0))
def apply(im,c):
 savedError=service(im,0x751190,[]);index=im.W(0x829ab4);get=service(im,0x6f024e,[]);pointer=service(im,get,[index])
 if not pointer:
  pointer=service(im,0x6f07af,[1,0x214])
  if pointer:
   setIndex=im.W(0x829ab4);encoded=im.W(0x297c540);setter=service(im,0x6f01bc,[encoded]);success=service(im,setter,[setIndex,pointer])
   if success:service(im,0x6f02d6,[pointer,0]);thread=service(im,0x7510d8,[]);im.W(pointer+4,0xffffffff);im.W(pointer,thread)
   else:service(im,0x6e7633,[pointer]);pointer=0
 service(im,0x7511d0,[savedError]);return pointer
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI();entries={}
def observe(uc,a,z,user):
 if a in [0x6f0395,0x6f040c]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [GET,SET,LAST,RESTORE,THREAD,0x6f024e,0x6f07af,0x6f01bc,0x6f02d6,0x6e7633,0x6ebd99]:return
 sp=uc.reg_read(UC_X86_REG_ESP);logical={LAST:0x751190,RESTORE:0x7511d0,THREAD:0x7510d8}.get(a,a);count={GET:1,SET:2,RESTORE:1,0x6f07af:2,0x6f01bc:1,0x6f02d6:2,0x6e7633:1,0x6ebd99:1}.get(a,0);args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,logical,args);cleanup=4+count*4 if a in [GET,SET,LAST,RESTORE,THREAD] else 4;uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+cleanup)
n.mu.hook_add(UC_HOOK_CODE,observe)
P=D+0x1000;rng=random.Random(20261013120);cases=[]
def seed(existing=0,allocation=P,setter=1):return dict(entry='noexit',existing=existing,allocation=allocation,setterResult=setter,lastError=0x12345678,threadId=0xabcdef01,otherResult=0xfedcba98,writes=[word(0x829ab4,7),word(0x297c540,0x24681357)])
for existing in [0,1,0xffffffff,0x80000000,P]:
 for allocation in [0,P,0x829ab4]:
  for setter in [0,1,0xffffffff]:cases.append(seed(existing,allocation,setter))
for i in range(512):
 c=seed(rng.choice([0,rng.getrandbits(32)]),rng.choice([0,P]),rng.getrandbits(32) if i%3 else 0);c.update(lastError=rng.getrandbits(32),threadId=rng.getrandbits(32));cases.append(c)
for address in [0x751190,0x6f024e,GET,0x6f07af,0x6f01bc,SET,0x6f02d6,0x7510d8,0x6e7633,0x7511d0]:
 for at in [0x829ab4,0x297c540,P,P+4]:
  c=seed(setter=0 if address==0x6e7633 else 1);c['serviceWrites']={hex(address):[word(at,0x11223344)]};cases.append(c)
for existing,allocation,setter in [(0,0,0),(0,P,0),(0,P,1),(P,0,0)]:
 c=seed(existing,allocation,setter);c['entry']='required';cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);expected=apply(im,c)
 if c['entry']=='required' and not expected:service(im,0x6ebd99,[16])
 expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f040c if c['entry']=='required' else 0x6f0395,count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,originalBytesSha256=hashlib.sha256(n.read(0x6f0395,119)).hexdigest(),binarySha256=n.sha256,domain='prepared readable freshallocated record; existing pointer returned without dereference; callback mutation order/index argument caching/free failure/error restoration; required wrapper fatal child is explicit suspension projection',reaEvidenceIds=["ev_be69ff8e8505726139f0a2b6e6e4bc6eaeace6971fde8df4df50e2ae1d6cc65d","ev_35f68ba9c4b662e25a6e7e243686b1e3d57422e8715899d592cd73a1323e0416","ev_a998fe9bc57cf27e1f747bd5d415c5322a2376773c4391d142a468f97e6482a9"],nativeAdapters=['GetLastError751190/SetLastError7511d0/GetCurrentThreadId7510d8','6f024e getter resolver/6f01bc pointer decoder','getter/setter dynamic stdcall endpoints','6f07af calloc/6e7633 free','6f02d6 initializer','6ebd99 fatal boundary for required caller'],syntheticExcluded=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase120-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase120-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
