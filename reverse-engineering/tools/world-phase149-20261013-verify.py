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




n.mu.mem_map(0xf1000000,0x10000);P=D+0x1000;Q=D+0x5000;HIGH=0xf1001000;entries={}
def blocks(im,out,src,length,eax):
 for at in range(0,(length>>7)*128,128):
  for half in [0,64]:im.write(U(out+at+half),im.read(U(src+at+half),64))
 return eax
def vector(im,out,src,length):
 sr=S(src)%16 if S(src)>=0 else -((-S(src))%16);dr=S(out)%16 if S(out)>=0 else -((-S(out))%16)
 if not(sr|dr):
  tail=length&127
  if length!=tail:blocks(im,out,src,length-tail,out)
  for i in range(tail):im.B(U(out+length-tail+i),im.B(U(src+length-tail+i)))
  return out
 if sr==dr:
  head=16-sr
  for i in range(head):im.B(U(out+i),im.B(U(src+i)))
  vector(im,U(out+head),U(src+head),U(length-head));return out
 words=length>>2
 for i in range(words):im.W(U(out+i*4),im.W(U(src+i*4)))
 for i in range(length&3):im.B(U(out+words*4+i),im.B(U(src+words*4+i)))
 return out
def apply(im,c):
 out,src,length=c['args']
 if c['entry']=='blocks':return blocks(im,out,src,length,c['eax'])
 if c['entry']=='vector':return vector(im,out,src,length)
 if out>src and out<U(src+length):
  for i in range(length-1,-1,-1):im.B(U(out+i),im.B(U(src+i)))
  return out
 if length>=256 and im.W(0x29a9c48) and (out&15)==(src&15):return vector(im,out,src,length)
 for i in range(length):im.B(U(out+i),im.B(U(src+i)))
 return out
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EFLAGS
def observe(uc,a,z,user):
 if a in [0x6eb0f0,0x6efff6,0x6eff6f]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe);rng=random.Random(20261013149);cases=[]
def seed(entry='move',out=Q,src=P,length=256,flag=1,eax=0xfedcba98):return dict(entry=entry,args=[out,src,length],eax=eax,writes=[patch(src,bytes(rng.getrandbits(8) for _ in range(max(length,1)+32))),word(0x29a9c48,flag)])
for offset in range(16):
 for length in [0,1,2,3,4,15,16,17,31,32,127,128,129,255,256,257,511,512,1024]:
  for delta in [-257,-128,-16,-1,0,1,16,128,257,0x4000]:
   cases.append(seed(out=P+0x400+offset+delta,src=P+0x400+offset,length=length,flag=offset%2))
for srcbase,outbase in [(P,Q),(HIGH,Q),(P,HIGH),(HIGH,HIGH+0x4000)]:
 for offset in range(16):
  for length in [32,127,128,129,256,257,512]:cases.append(seed('vector',outbase+offset,srcbase+offset,length))
for offsets in [(0,1),(1,0),(1,2),(2,3),(15,0)]:
 for length in [0,1,3,31,127,128,129,256,257]:cases.append(seed('vector',Q+offsets[0],P+offsets[1],length))
for length in [128,129,255,256,257,384,512]:
 for delta in [-128,-64,-16,0,16,64,128,0x4000]:
  for eax in [0,1,0xffffffff]:cases.append(seed('blocks',P+0x400+delta,P+0x400,length,eax=eax))
for out,src in [(0,0xffffffff),(0xffffffff,0),(0x80000000,0xffffffff)]:cases.append(dict(entry='move',args=[out,src,0],eax=0,writes=[word(0x29a9c48,1)]))
for i in range(256):
 src=rng.choice([P,HIGH])+rng.randrange(0x1000);out=src+rng.randrange(-256,512) if i%3 else Q+rng.randrange(16);cases.append(seed(out=out,src=src,length=rng.randrange(4096),flag=rng.randrange(2)))
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);expected=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call({'move':0x6eb0f0,'vector':0x6efff6,'blocks':0x6eff6f}[c['entry']],c['args'],regs={UC_X86_REG_EAX:c['eax']},count=1000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest();df=n.mu.reg_read(UC_X86_REG_EFLAGS)&0x400
 if rv!=expected or actual!=im.hash() or df:errors.append(dict(case=i,native=actual,model=im.hash(),nativeResult=rv,modelResult=expected,nativeDF=df));break
 c['expected']=dict(sha256=actual,result=rv);rows.append(c)
report=dict(status='qualified native proof passed; integration metadata deferred' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,originalBytesSha256=dict(move=hashlib.sha256(n.read(0x6eb0f0,99)+n.read(0x6eb154,31)+n.read(0x6eb174,7)+n.read(0x6eb188,41)+n.read(0x6eb1b4,35)+n.read(0x6eb1d8,29)+n.read(0x6eb218,74)+n.read(0x6eb274,7)+n.read(0x6eb27c,11)+n.read(0x6eb288,17)+n.read(0x6eb29c,23)+n.read(0x6eb2b4,38)+n.read(0x6eb2dc,9)+n.read(0x6eb2e8,31)+n.read(0x6eb314,33)+n.read(0x6eb338,39)+n.read(0x6eb360,49)+n.read(0x6eb3b4,74)+n.read(0x6eb410,7)+n.read(0x6eb418,13)+n.read(0x6eb428,19)+n.read(0x6eb43c,25)).hexdigest(),vector=hashlib.sha256(n.read(0x6efff6,227)).hexdigest(),blocks=hashlib.sha256(n.read(0x6eff6f,26)+n.read(0x6eff8f,103)).hexdigest()),moveSpanIncludingJumpTablesSha256=hashlib.sha256(n.read(0x6eb0f0,869)).hexdigest(),sourceSha256=hashlib.sha256((B/'reconstructed/gameplay/world-phase149-20261013-ptl-runtime-move.cs').read_bytes()).hexdigest(),domain='readable nonwrapped source/destination spans and DF0; move overlap in both directions; direct vector mismatched signed remainder DWORD fallback, same remainder head>=32 length; direct blocks positive count/aligned pointers and exact two64-byte staging halves; zero length move no dereference',nativeAdapters=[],syntheticExcluded=0,managedReplayExecuted=False,reaEvidenceIds=["ev_d03fd6af71385c24b5e5b2fedf4fa789665b046be08aa736714699d5d2cc1c30","ev_1dd10cc5c978380447c7a1f0f0716f755c0a4755a40a6c624a98714f58943ad1","ev_e99a7bd982b5e2ae4cca887ac40e4cd4e4e1da6206dcf3b0dbc52ba899152f23"],seconds=round(time.time()-start,3))
(B/'reports/world-phase149-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+chr(10))
if not errors:(B/'reports/world-phase149-20261013-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':')).encode(),mtime=0))
print(json.dumps(report));assert not errors
