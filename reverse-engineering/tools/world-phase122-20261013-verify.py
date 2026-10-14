import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0x750f00,0x300,0),(0x82a000,0xa00,167),(0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

if not any(begin<=0<=end for begin,end,_ in n.mu.mem_regions()):n.mu.mem_map(0,0x1000)
MODULE=0x10300000;PROC_A=MODULE+0x100;PROC_B=MODULE+0x200;ATOMIC=MODULE+0x300
n.mu.mem_map(MODULE,0x1000)
for a in [MODULE,PROC_A,PROC_B,ATOMIC]:n.write(a,b'\xc3')
trace=[];case={};counts={}
def service(im,address,args):
 key=hex(address);index=counts.get(key,0);counts[key]=index+1;trace.append([address,args])
 for p in case.get('serviceWrites',{}).get(key,[]):im.write(p['address'],base64.b64decode(p['data']))
 sequence=case.get('sequenceWrites',{}).get(key,[])
 if index<len(sequence):
  for p in sequence[index]:im.write(p['address'],base64.b64decode(p['data']))
 if address==MODULE:return case['module']
 if address==0x6f00d9:return case['version']
 if address in [PROC_A,PROC_B]:return case['encode'] if args[1]==0x777fc8 else case['decode']
 if address==ATOMIC:im.W(args[0],U(im.W(args[0])+1));return im.W(args[0])
 if address==0x6f179a:return case['unlockResult']
 return 0
# The thunk returns the unlock endpoint's EAX unchanged.
def unlock(im):return service(im,0x6f179a,[12])
def apply(im,c):
 if c['entry']=='unlock':return unlock(im)
 record,locale=c['args'];module=service(im,im.W(0x751154),[0x777fd8]);im.W(record+0x5c,0x829b78);im.W(record+0x14,1)
 if module and service(im,0x6f00d9,[]):
  proc=im.W(0x7511b0);im.W(record+0x1f8,service(im,proc,[module,0x777fc8]));im.W(record+0x1fc,service(im,proc,[module,0x777fe8]))
 im.W(record+0x70,1);im.B(record+0xc8,0x43);im.B(record+0x14b,0x43);im.W(record+0x68,0x82a070);service(im,im.W(0x7511cc),[0x82a070]);service(im,0x6f188a,[12]);im.W(record+0x6c,locale)
 if not locale:im.W(record+0x6c,im.W(0x82a678))
 service(im,0x6facb1,[im.W(record+0x6c)]);return unlock(im)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
ni=NI();entries={}
def observe(uc,a,z,user):
 if a in [0x6f02d6,0x6f038c,0x6f0954,0x6f0999]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [MODULE,PROC_A,PROC_B,ATOMIC,0x6f00d9,0x6f188a,0x6f179a,0x6facb1]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=2 if a in [PROC_A,PROC_B] else 0 if a==0x6f00d9 else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);cleanup=4+count*4 if a in [MODULE,PROC_A,PROC_B,ATOMIC] else 4;uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+cleanup)
n.mu.hook_add(UC_HOOK_CODE,observe)
P=D+0x1000;L=D+0x3000;rng=random.Random(20261013122);cases=[]
def seed(record=P,locale=0,module=1,version=1):return dict(entry='initialize',args=[record,locale],module=module,version=version,encode=0x11223344,decode=0x55667788,unlockResult=0xfedcba98,writes=[patch(record,bytes([167])*0x214),word(0x751154,MODULE),word(0x7511b0,PROC_A),word(0x7511cc,ATOMIC),word(0x82a070,0xffffffff),word(0x82a678,L),word(0,0xffffffff)])
for record in [P,0x7511b0-0x1f8,0x82a070-0x68,0x82a678-0x6c]:
 for locale in [0,L,0xffffffff]:
  for module in [0,1,0xffffffff]:
   for version in [0,1,0xffffffff]:cases.append(seed(record,locale,module,version))
for i in range(512):
 c=seed(locale=rng.choice([0,rng.getrandbits(32)]),module=rng.getrandbits(32) if i%3 else 0,version=rng.getrandbits(32) if i%5 else 0);c.update(encode=rng.getrandbits(32),decode=rng.getrandbits(32),unlockResult=rng.getrandbits(32));cases.append(c)
for address in [MODULE,0x6f00d9,PROC_A,ATOMIC,0x6f188a,0x6facb1,0x6f179a]:
 for at,value in [(0x7511b0,PROC_B),(0x82a678,P),(P+0x6c,0xffffffff),(P+0x1f8,0),(P+0x1fc,0),(0x82a070,0xfffffffe)]:
  c=seed();c['serviceWrites']={hex(address):[word(at,value)]};cases.append(c)
for result in [0,1,0xffffffff,0x80000000,0x7fffffff]:
 c=seed();c['entry']='unlock';c['unlockResult']=result;cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f038c,[]) if c['entry']=='unlock' else n.call(0x6f02d6,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,originalBytesSha256=dict(initializer=hashlib.sha256(n.read(0x6f02d6,182)).hexdigest(),unlockThunk=hashlib.sha256(n.read(0x6f038c,9)).hexdigest()),binarySha256=n.sha256,domain='normal no-exception execution with readable record/IAT/process locale cells; cached GetProc target across field/IAT alias; interlocked mutation and locale fallback/lock ordering; FS0 chain restored by original frame prolog/epilog',sehPrerequisiteBytesSha256=dict(prolog=hashlib.sha256(n.read(0x6f0954,69)).hexdigest(),epilog=hashlib.sha256(n.read(0x6f0999,20)).hexdigest()),sehDuplicateAddressCredit=0,reaEvidenceIds=["ev_82844501f4ffada656c1f91c810a8ab9719a8a4fb791c7d55c80e118468dc328","ev_d93fd1520c2bf274681bfb3c966d4181ed912eb683962db392f0b71d22c11d75","ev_0a9240e93dcd563b3ea177a1ac6626088375a792578fa07b0939895b87bc9c31"],nativeAdapters=['module/procedure/interlocked Win32 endpoints','6f00d9 version predicate','6f188a/6f179a lock/unlock children','6facb1 locale addref'],syntheticExcluded=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase122-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase122-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
