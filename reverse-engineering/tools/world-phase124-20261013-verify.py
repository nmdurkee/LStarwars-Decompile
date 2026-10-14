import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,0),(0x7511cc,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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


A=0x10300000;B2=A+0x100;n.mu.mem_map(A,0x1000);n.write(A,b'\xc3');n.write(B2,b'\xc3');P=D+0x1000;REFS=D+0x3000
trace=[];case={};counts={};entries={}
def service(im,a,args):
 index=counts.get(hex(a),0);counts[hex(a)]=index+1;trace.append([a,args]);p=args[0];value=U(im.W(p)+1);im.W(p,value)
 seq=case.get('sequenceWrites',{}).get(hex(a),[])
 if index<len(seq):
  for w in seq[index]:im.write(w['address'],base64.b64decode(w['data']))
 return value
def apply(im,c):
 locale=c['args'][0];target=im.W(0x7511cc);service(im,target,[locale])
 for offset in [0xb0,0xb8,0xb4,0xc0]:
  p=im.W(locale+offset)
  if p:service(im,target,[p])
 row=locale+0x50
 for i in range(6):
  if im.W(row-8)!=0x82a598:
   p=im.W(row)
   if p:service(im,target,[p])
  if im.W(row-4):
   p=im.W(row+4)
   if p:service(im,target,[p])
  row+=16
 return service(im,target,[U(im.W(locale+0xd4)+0xb4)])
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
class NI:
 def write(self,a,v):n.write(a,v)
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
ni=NI()
def observe(uc,a,z,user):
 if a==0x6facb1:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [A,B2]:return
 sp=uc.reg_read(UC_X86_REG_ESP);args=[n.unpack('<I',sp+4)[0]];rv=service(ni,a,args);uc.reg_write(UC_X86_REG_EAX,rv);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+8)
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013124);cases=[]
def seed():
 writes=[word(0x7511cc,A),word(P,0xffffffff),word(P+0xd4,REFS)]
 for j,offset in enumerate([0xb0,0xb8,0xb4,0xc0]):writes.append(word(P+offset,REFS+j*4))
 for i in range(6):
  row=P+0x50+i*16;writes.extend([word(row-8,0),word(row-4,1),word(row,REFS+0x20+i*8),word(row+4,REFS+0x24+i*8)])
 return dict(args=[P],writes=writes)
for i in range(512):
 c=seed()
 for offset in [0xb0,0xb8,0xb4,0xc0]:c['writes'].append(word(P+offset,rng.choice([0,P,REFS+4*rng.randrange(40)])))
 for j in range(6):
  row=P+0x50+j*16;c['writes']+=[word(row-8,rng.choice([0,0x82a598,0xffffffff])),word(row-4,rng.choice([0,1,0xffffffff])),word(row,rng.choice([0,P,REFS+4*rng.randrange(40)])),word(row+4,rng.choice([0,P,REFS+4*rng.randrange(40)]))]
 c['writes']+=[word(REFS+4*j,rng.getrandbits(32)) for j in range(80)];cases.append(c)
for index in [0,1,3,5,9,13,16]:
 for at,value in [(0x7511cc,B2),(P+0xb8,0),(P+0xb4,REFS+0x90),(P+0x50,0),(P+0x58,0x82a598),(P+0x5c,0),(P+0xd4,P-0xb4),(P+0xd4,REFS+0x100)]:
  c=seed();c['sequenceWrites']={hex(A):[[] for _ in range(index)]+[[word(at,value)]]};cases.append(c)
for offset in [0,0x48,0x4c,0x50,0x54,0xb0,0xb4,0xb8,0xc0,0xd4]:
 c=seed();c['writes'].append(word(P+0xb0,P+offset));cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];counts={};im=Image(c);expected=apply(im,c);expectedTrace=trace[:];trace=[];counts={};initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6facb1,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash() or trace!=expectedTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeTrace=trace,modelTrace=expectedTrace));break
 c['expected']=dict(sha256=actual,result=rv,trace=trace);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,originalBytesSha256=hashlib.sha256(n.read(0x6facb1,134)).hexdigest(),binarySha256=n.sha256,domain='readable locale and reference cells; cached atomic IAT target across callback mutation; six fresh category pointer pairs and final unchecked d4+b4 reference',nativeAdapters=['InterlockedIncrement endpoint'],syntheticExcluded=0,reaEvidenceIds=["ev_90edd229cd47a87af512037bb1326feb076c2c8678ae42d3b08530e79237e9dc"],seconds=round(time.time()-start,3))
(B/'reports/world-phase124-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase124-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
