import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,0),(0x7510ac,4,0),(0x297c548,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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




SLEEP=0x10300000;ALT=SLEEP+0x100;n.mu.mem_map(SLEEP,0x1000);n.write(SLEEP,b'\xc3');n.write(ALT,b'\xc3');trace=[];case={};counts={};entries={}
def service(im,a,args):
 index=counts.get(hex(a),0);counts[hex(a)]=index+1;trace.append([a,args])
 seq=case.get('sequenceWrites',{}).get(hex(a),[])
 if index<len(seq):
  for p in seq[index]:im.write(p['address'],base64.b64decode(p['data']))
 if a==0x6eae5c:
  values=case['results'];return values[min(index,len(values)-1)]
 return case['sleepResult']
def apply(im,c):
 delay=0
 while True:
  result=service(im,0x6eae5c,c['args']+[0])
  if result or not im.W(0x297c548):return result
  service(im,im.W(0x7510ac),[delay]);next=U(delay+1000)
  if next>im.W(0x297c548):next=0xffffffff
  delay=next
  if delay==0xffffffff:return result
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a==0x6f07af:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [SLEEP,ALT,0x6eae5c]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=3 if a==0x6eae5c else 1;args=list(n.unpack('<'+'I'*count,sp+4));rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4+(4 if a in [SLEEP,ALT] else 0))
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013128);cases=[]
def seed(limit=2500,results=[0,0,D+0x1000],args=[1,0x214]):return dict(args=args,results=results,sleepResult=0xfedcba98,writes=[word(0x7510ac,SLEEP),word(0x297c548,limit)])
for limit in [0,1,999,1000,1001,2000,2500,3000,0x7fffffff,0x80000000,0xffffffff]:
 for results in [[D+0x1000],[0,D+0x1000],[0,0,D+0x1000],[0,0,0,0,D+0x1000]]:
  for args in [[0,0],[1,0x214],[0xffffffff,0xffffffff],[0x80000000,2]]:cases.append(seed(limit,results,args))
for i in range(256):
 c=seed(rng.randrange(10000),[0]*rng.randrange(5)+[rng.randrange(1,0xffffffff)],[rng.getrandbits(32),rng.getrandbits(32)]);c['sleepResult']=rng.getrandbits(32);cases.append(c)
for address in [0x6eae5c,SLEEP]:
 for index in [0,1,2]:
  for at,value in [(0x297c548,0),(0x297c548,1000),(0x297c548,0xffffffff),(0x7510ac,ALT)]:
   c=seed(results=[0,0,0,D+0x1000]);c['sequenceWrites']={hex(address):[[] for _ in range(index)]+[[word(at,value)]]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f07af,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6f07af,72)).hexdigest(),domain='bounded terminating allocator result sequences; signed-free uint delay/limit semantics, fresh retry limit and sleep IAT across callback mutation; caller stack alias excluded',nativeAdapters=['6eae5c calloc implementation','Sleep Win32 endpoint'],syntheticExcluded=0,reaEvidenceIds=["ev_5d28f5d601db836f6efa03af05b62977cf4300057fe7565edf6f2433e55b4cf1"],seconds=round(time.time()-start,3))
(B/'reports/world-phase128-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase128-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
