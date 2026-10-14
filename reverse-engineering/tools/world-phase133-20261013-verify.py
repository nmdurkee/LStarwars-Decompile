import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0xf1000000,0x10000,167),(0x29a9c48,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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



n.mu.mem_map(0xf1000000,0x10000);P=D+0x1000;HIGH=0xf1001000;entries={}
def blocks(im,out,length,eax):im.write(out,bytes((length>>7)*128));return eax
def zero(im,out,length):
 rem=S(out)%16 if S(out)>=0 else -((-S(out))%16)
 if rem:
  head=16-rem;im.write(out,bytes(head));zero(im,U(out+head),U(length-head));return out
 tail=length&127
 if length!=tail:blocks(im,out,length-tail,out)
 if tail:im.write(U(out+length-tail),bytes(tail))
 return out
def apply(im,c):
 if c['entry']=='blocks':return blocks(im,*c['args'],c['eax'])
 if c['entry']=='zero':return zero(im,*c['args'])
 out,value,length=c['args'];b=value&255
 if not length:return out
 if not b and length>=256 and im.W(0x29a9c48):return zero(im,out,length)
 im.write(out,bytes([b])*length);return out
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX
def observe(uc,a,z,user):
 if a in [0x6e6950,0x6eec22,0x6eebcb]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013133);cases=[]
def seed(entry,args,flag=1,eax=0xfedcba98):return dict(entry=entry,args=args,eax=eax,writes=[word(0x29a9c48,flag)])
for base in [P,HIGH]:
 for offset in range(16):
  for length in [0,1,2,3,4,15,16,17,31,32,127,128,129,255,256,257,383,384,511,512]:
   for value in [0,1,255,0x100,0xffffffff]:cases.append(seed('fill',[base+offset,value,length],flag=1 if offset%2 else 0))
for base in [P,HIGH]:
 for offset in range(16):
  for length in [32,33,127,128,129,255,256,257,512]:cases.append(seed('zero',[base+offset,length]))
for length in [0,1,127,128,129,256,257]:cases.append(seed('zero',[P,length]))
for base in [P,HIGH]:
 for length in [128,129,255,256,257,384,511,512]:
  for eax in [0,1,0xffffffff,0x80000000]:cases.append(seed('blocks',[base,length],eax=eax))
for out in [0,0xffffffff,0x80000000]:cases.append(seed('fill',[out,0xffffffff,0]))
for i in range(256):cases.append(seed('fill',[rng.choice([P,HIGH])+rng.randrange(16),rng.getrandbits(32),rng.randrange(2048)],rng.getrandbits(32)))
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);expected=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 args=c['args'] if c['entry']!='zero' else [c['args'][0],0,c['args'][1]];rv=n.call({'fill':0x6e6950,'zero':0x6eec22,'blocks':0x6eebcb}[c['entry']],args,regs={UC_X86_REG_EAX:c['eax']},count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash():errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected));break
 c['expected']=dict(sha256=actual,result=rv);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=dict(fill=hashlib.sha256(n.read(0x6e6950,122)).hexdigest(),zero=hashlib.sha256(n.read(0x6eec22,143)).hexdigest(),blocks=hashlib.sha256(n.read(0x6eebcb,87)).hexdigest()),domain='readable output buffers low/high signed addresses; DF0; direct zero unaligned length at least32, direct block count positive and output16 aligned; zero-length fill no dereference; full original SSE2 loop unmodified',nativeAdapters=[],syntheticExcluded=0,reaEvidenceIds=["ev_249dd26b031171ee43ef8aef7bd97d813517e8aedad63e602371ddc28c3a48c5","ev_ae526d4c8ec35d767abe41585a45a35486c0babaa5f25da85904dedb783f6054","ev_0683a8a347c3cf1bb1c2edf8e5b7e70875f9dc3ad5332013222301785fa115ee"],seconds=round(time.time()-start,3))
(B/'reports/world-phase133-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase133-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
