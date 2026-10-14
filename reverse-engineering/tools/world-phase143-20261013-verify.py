import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x10000,167),(0xf1000000,0x10000,167),(0x29a9b10,8,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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




n.mu.mem_map(0xf1000000,0x10000);P=D+0x1000;HIGH=0xf1001000;cases=[];rng=random.Random(20261013143)
def apply(im,c):
 cursor=im.W(0x29a9b14);end=U(cursor+im.W(0x29a9b10)*20)
 while cursor<end:
  if U(c['args'][0]-im.W(cursor+12))<0x100000:return cursor
  cursor=U(cursor+20)
 return 0
def seed(base=P,count=3,pointer=0x20123456,blocks=[0x20000000,0x20100000,0x20200000]):return dict(args=[pointer],writes=[word(0x29a9b10,count),word(0x29a9b14,base)]+[word(base+20*i+12,b) for i,b in enumerate(blocks)])
for base in [P,HIGH]:
 for count in [0,1,2,3,0xffffffff,0xcccccccd,0xcccccccc,0x40000000,0x80000000]:
  for pointer in [0,0x20000000,0x200fffff,0x20100000,0x201fffff,0x20200000,0x20300000,0xffffffff]:cases.append(seed(base,count,pointer))
for base in [P,HIGH]:
 for pointer in [0,1,0xffffffff,0x80000000]:
  for delta in [0,1,0xfffff,0x100000,0xffffffff]:
   for slot in range(3):
    blocks=[U(pointer-0x200000)]*3;blocks[slot]=U(pointer-delta);cases.append(seed(base,3,pointer,blocks))
for i in range(512):
 blocks=[rng.getrandbits(32) for _ in range(5)];pointer=U(rng.choice(blocks)+rng.randrange(0x100001)) if i%3 else rng.getrandbits(32);cases.append(seed(rng.choice([P,HIGH]),rng.randrange(6),pointer,blocks))
for count in [0,0x40000000,0x80000000]:cases.append(dict(args=[0xffffffff],writes=[word(0x29a9b10,count),word(0x29a9b14,0)]))
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);expected=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(0x6f19a6,c['args'],count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=expected or actual!=im.hash():errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected));break
 c['expected']=dict(sha256=actual,result=rv);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,binarySha256=n.sha256,originalBytesSha256=hashlib.sha256(n.read(0x6f19a6,43)).hexdigest(),providerOwnedPrefixBytes=20,executedRawTailBytes=23,rawTailAdditionalAddressCredit=0,sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase143-20261013-ptl-small-pool-locate.cs').read_bytes()).hexdigest(),domain='prepared readable header rows for bounded wrapped physical-end scans; uint pointer and delta across 1MiB/wrap boundaries, zero/negative-like count skip, high unsigned table address, full original raw tail executed',nativeAdapters=[],syntheticExcluded=0,managedReplayExecuted=False,reaEvidenceIds=["ev_f126f0a7e59cf368ee0c772bebf13e25399c578f393fdcafc5f2bbce74d4b04c"],seconds=round(time.time()-start,3))
(B/'reports/world-phase143-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase143-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
