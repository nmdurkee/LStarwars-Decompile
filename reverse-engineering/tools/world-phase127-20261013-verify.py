import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,0),(0x829c00,0x400,0),(0x297c974,4,0),(0,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

P=D+0x1000;ERR=D+0xf000;trace=[];case={};entries={}
def service(im,a,args):
 trace.append([a,args])
 for p in case.get('serviceWrites',{}).get(hex(a),[]):im.write(p['address'],base64.b64decode(p['data']))
 return case['allocation'] if a==0x6f076f else case['initialized'] if a==0x6fd033 else ERR if a==0x6ead5f else case['endpoint']
def error(im):im.W(service(im,0x6ead5f,[]),12)
def apply(im,c):
 if not im.W(0x297c974):
  service(im,0x6f0bb8,[]);service(im,0x6f09f8,[30]);service(im,0x6ebde3,[255])
 slot=U(0x829c40+c['args'][0]*8)
 if im.W(slot):return 1
 p=service(im,0x6f076f,[24])
 if not p:error(im);return 0
 service(im,0x6f188a,[10]);result=1
 if not im.W(slot):
  if not service(im,0x6fd033,[p,4000]):service(im,0x6e7633,[p]);error(im);result=0
  else:im.W(slot,p)
 else:service(im,0x6e7633,[p])
 service(im,0x6f179a,[10]);return result
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
ni=NI()
def observe(uc,a,z,user):
 if a in [0x6f17c7,0x6f1881,0x6f0954,0x6f0999]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x6f0bb8,0x6f09f8,0x6ebde3,0x6f076f,0x6fd033,0x6ead5f,0x6f188a,0x6f179a,0x6e7633]:return
 sp=uc.reg_read(UC_X86_REG_ESP);count=0 if a in [0x6f0bb8,0x6ead5f] else 2 if a==0x6fd033 else 1;args=list(n.unpack('<'+'I'*count,sp+4)) if count else [];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,U(rv));uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013127);cases=[]
def seed(id=12,existing=0,allocation=P,initialized=1,heap=1):return dict(args=[id],allocation=allocation,initialized=initialized,endpoint=0xfedcba98,writes=[word(0x297c974,heap),word(U(0x829c40+id*8),existing),word(0,0xffffffff)])
for id in [0,1,10,12,31,0xffffffff,0x20000000,0x1fffffff]:
 for existing in [0,P,0xffffffff]:
  for allocation in [0,P]:
   for initialized in [0,1]:
    for heap in [0,1]:cases.append(seed(id,existing,allocation,initialized,heap))
for i in range(256):
 c=seed(rng.randrange(32),P if i%5==0 else 0,P if i%3 else 0,rng.getrandbits(32) if i%7 else 0);c['endpoint']=rng.getrandbits(32);cases.append(c)
for address in [0x6f0bb8,0x6f09f8,0x6ebde3,0x6f076f,0x6f188a,0x6fd033,0x6e7633,0x6ead5f,0x6f179a]:
 for initialized in [0,1]:
  for at,value in [(0x829ca0,P+0x100),(0x297c974,0),(P,0x12345678),(ERR,0xffffffff)]:
   c=seed(initialized=initialized,heap=0);c['serviceWrites']={hex(address):[word(at,value)]};cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f17c7,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=dict(initialize=hashlib.sha256(n.read(0x6f17c7,186)).hexdigest(),finallyThunk=hashlib.sha256(n.read(0x6f1881,9)).hexdigest()),finallyPrerequisiteDuplicateCredit=0,domain='normal no-exception prepared lock table/errno cells; publication race, allocation failure, cached allocation and slot, returning termination projection',nativeAdapters=['CRT allocate/free and critical initialization','CRT lock/unlock children','errno, exit/message children'],syntheticExcluded=0,reaEvidenceIds=["ev_cfcf0343e2530ade2519de63fba4e7036a39c03a76a04e0c38c75504dc86f1d4"],seconds=round(time.time()-start,3))
(B/'reports/world-phase127-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase127-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
