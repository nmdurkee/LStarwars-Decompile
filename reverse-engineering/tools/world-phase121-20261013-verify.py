import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x829ab4,8,0),(0x297c53c,8,0),(0x7511b0,0x18,0),(0x751154,4,0),(0x751190,4,0),(0x7511d0,4,0),(0x7510d8,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

A=0x10300000;BGET=A+0x100;GETTER=A+0x200;DECODER=A+0x300;MODULE=A+0x400;PROC=A+0x500;CACHESET=A+0x600;SETTER=A+0x700;LAST=A+0x800;RESTORE=A+0x900;THREAD=A+0xa00
n.mu.mem_map(A,0x1000)
for address in [A,BGET,GETTER,DECODER,MODULE,PROC,CACHESET,SETTER,LAST,RESTORE,THREAD]:n.write(address,b'\xc3')
trace=[];case={};counts={}
def service(im,address,args):
 key=hex(address);index=counts.get(key,0);counts[key]=index+1;trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 sequence=case.get('sequenceWrites',{}).get(key,[])
 if index<len(sequence):
  for p in sequence[index]:im.write(p['address'],base64.b64decode(p['data']))
 if address in [A,BGET]:values=case['aSequence'] if address==A else case['bSequence'];return values[min(index,len(values)-1)]
 if address==GETTER:return case['threadPointer']
 if address==DECODER:return args[0] if case['entry']=='noexit' else case['decoded']
 return {MODULE:case['module'],PROC:case['decodeTarget'],0x6f00d9:case['version'],CACHESET:case['cacheSetResult'],SETTER:case['setterResult'],0x6f07af:case['allocation'],0x751190:case['lastError'],0x7510d8:case['threadId']}.get(address,0)
def decode(im,encoded):
 slot=im.W(0x829ab8);target=im.W(0x7511bc);decoder=0;cached=False
 if service(im,target,[slot]):
  index=im.W(0x829ab4)
  if index!=0xffffffff:
   secondSlot=im.W(0x829ab8);getter=service(im,target,[secondSlot]);thread=service(im,getter,[index])
   if thread:decoder=im.W(thread+0x1fc);cached=True
 if not cached:
  module=service(im,im.W(0x751154),[0x777fd8])
  if module and service(im,0x6f00d9,[]):decoder=service(im,im.W(0x7511b0),[module,0x777fe8])
 return encoded if not decoder else service(im,decoder,[encoded])
def getter(im):
 slot=im.W(0x829ab8);pointer=service(im,im.W(0x7511bc),[slot])
 if not pointer:
  pointer=decode(im,im.W(0x297c53c));setSlot=im.W(0x829ab8);service(im,im.W(0x7511c4),[setSlot,pointer])
 return pointer
def closed(im,address,args):
 if address==0x6f024e:return getter(im)
 if address==0x6f01bc:return decode(im,args[0])
 return service(im,address,args)
p=Path(__file__).with_name('world-phase120-20261013-verify.py');tree=ast.parse(p.read_text());body=next(x for x in tree.body if isinstance(x,ast.FunctionDef) and x.name=='apply');caller=dict(globals(),service=closed);exec(compile(ast.Module(body=[body],type_ignores=[]),str(p),'exec'),caller)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI();entries={}
def observe(uc,a,z,user):
 if a in [0x6f024e,0x6f01bc,0x6f0395]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [A,BGET,GETTER,DECODER,MODULE,PROC,CACHESET,SETTER,LAST,RESTORE,THREAD,0x6f00d9,0x6f07af,0x6e7633,0x6f02d6]:return
 sp=uc.reg_read(UC_X86_REG_ESP);logical={LAST:0x751190,RESTORE:0x7511d0,THREAD:0x7510d8}.get(a,a);count={A:1,BGET:1,GETTER:1,DECODER:1,MODULE:1,PROC:2,CACHESET:2,SETTER:2,RESTORE:1,0x6f07af:2,0x6e7633:1,0x6f02d6:2}.get(a,0);args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,logical,args);cleanup=4+count*4 if a not in [0x6f00d9,0x6f07af,0x6e7633,0x6f02d6] else 4;uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+cleanup)
n.mu.hook_add(UC_HOOK_CODE,observe)
P=D+0x1000;rng=random.Random(20261013121);cases=[]
def seed(entry='decode',hit=False,index=7,thread=P,decodeTarget=DECODER,module=1,version=1):return dict(entry=entry,encoded=0x12345678,aSequence=[GETTER,GETTER] if hit else [0,0],bSequence=[GETTER,GETTER],threadPointer=thread,decodeTarget=decodeTarget,module=module,version=version,decoded=0xdeadbeef,cacheSetResult=1,setterResult=1,allocation=P,lastError=0x13579bdf,threadId=0x2468ace0,writes=[word(0x829ab4,index),word(0x829ab8,3),word(0x297c53c,GETTER),word(0x297c540,SETTER),word(0x7511bc,A),word(0x7511c4,CACHESET),word(0x751154,MODULE),word(0x7511b0,PROC),word(0x751190,LAST),word(0x7511d0,RESTORE),word(0x7510d8,THREAD),patch(P,bytes(0x214)),word(P+0x1fc,decodeTarget)])
for entry in ['decode','getter']:
 for hit in [False,True]:
  for index in [0,7,0xffffffff]:
   for thread in [0,P]:
    for target in [0,DECODER]:
     for module in [0,1]:
      for version in [0,1]:cases.append(seed(entry,hit,index,thread,target,module,version))
for i in range(512):
 c=seed(rng.choice(['decode','getter']),bool(i%2),rng.getrandbits(32),rng.choice([0,P]),rng.choice([0,DECODER]),rng.getrandbits(32) if i%3 else 0,rng.getrandbits(32) if i%5 else 0);c.update(encoded=rng.getrandbits(32),decoded=rng.getrandbits(32),cacheSetResult=rng.getrandbits(32));cases.append(c)
# Cached first TLS import target must survive a callback retargeting its IAT cell.
for entry in ['decode','getter']:
 for field,value in [(0x7511bc,BGET),(0x829ab4,0xffffffff),(0x829ab8,77),(P+0x1fc,0),(0x751154,MODULE),(0x7511b0,PROC)]:
  c=seed(entry,True);c['serviceWrites']={hex(A):[word(field,value)]};cases.append(c)
for entry in ['decode','getter']:
 for address in [MODULE,0x6f00d9,PROC,DECODER,CACHESET]:
  for field in [0x829ab4,0x829ab8,P+0x1fc]:
   c=seed(entry);c['serviceWrites']={hex(address):[word(field,0xffffffff)]};cases.append(c)
for hit in [False,True]:
 for thread in [0,P]:
  for allocation in [0,P]:
   for success in [0,1]:
    c=seed('noexit',hit,7,thread);c.update(allocation=allocation,setterResult=success);cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);expected=decode(im,c['encoded']) if c['entry']=='decode' else getter(im) if c['entry']=='getter' else caller['apply'](im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f01bc,[c['encoded']],count=1000000) if c['entry']=='decode' else n.call(0x6f024e if c['entry']=='getter' else 0x6f0395,count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,originalBytesSha256=dict(getter=hashlib.sha256(n.read(0x6f024e,50)).hexdigest(),decode=hashlib.sha256(n.read(0x6f01bc,110)).hexdigest()),binarySha256=n.sha256,domain='prepared readable thread/metadata/IAT cells; raw targets explicit stdcall endpoints; cached TLS import and pending index arguments; fallback module/version/procedure route and unchanged encoded identity path',reaEvidenceIds=["ev_35f68ba9c4b662e25a6e7e243686b1e3d57422e8715899d592cd73a1323e0416","ev_a998fe9bc57cf27e1f747bd5d415c5322a2376773c4391d142a468f97e6482a9","ev_be69ff8e8505726139f0a2b6e6e4bc6eaeace6971fde8df4df50e2ae1d6cc65d"],nativeAdapters=['TLS get/set and current getter/DecodePointer dynamic stdcall endpoints','GetModuleHandleW/GetProcAddress targets','6f00d9 OS version predicate initially explicit','calloc/free/ptd initializer and error/thread imports for noexit composition'],syntheticExcluded=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase121-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase121-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
