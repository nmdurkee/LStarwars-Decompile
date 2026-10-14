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

DEST=D+0x1000;RUNTIME=D+0x2000;MAT=D+0x4000
def allowed(im,r,m):return not im.W(r+0x13c)&0x40000 and (im.W(m+0x40)>>14)&3 in [0,2]
def build(im,c):
 d,r,m,mode,fourth=c['args'];kind=mode&3;im.W(d+0x20,fourth);im.W(d,r);im.W(d+4,m);im.W(d+8,mode);im.W(d+12,kind);a=int(kind==0 and mode&0x10!=0 and allowed(im,r,m));im.W(d+16,a);b=int((kind!=0 or mode&0x10!=0) and allowed(im,r,m));im.W(d+24,b);third=int(kind==0 and mode&0x20!=0 and allowed(im,r,m));im.W(d+20,third)
 if im.W(m+0x40)&15==2:im.W(d+16,0);im.W(d+24,0)
 count=int(kind==0);im.W(d+28,count)
 if im.W(d+16) or kind==0 and im.B(r+0x1ba)&1:count+=1;im.W(d+28,count)
 if im.W(d+24):im.W(d+28,U(im.W(d+28)+1))
 if third:im.W(d+28,U(im.W(d+28)+1))
def values(im,c):
 d,r,m,mode,fourth=c['args'];kind=mode&3;a=int(kind==0 and mode&0x10!=0 and allowed(im,r,m));b=int((kind!=0 or mode&0x10!=0) and allowed(im,r,m));third=int(kind==0 and mode&0x20!=0 and allowed(im,r,m))
 if im.W(m+0x40)&15==2:a=0;b=0
 count=int(kind==0)+(1 if a or kind==0 and im.B(r+0x1ba)&1 else 0)+b+third
 return [r,m,mode,kind,a,third,b,count,fourth]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
entries={}
def observe(uc,a,z,user):
 if a==0x744320:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(mode=0):return dict(args=[DEST,RUNTIME,MAT,mode,0xdeadbeef],projection=True,writes=[word(RUNTIME+0x13c,0),byte(RUNTIME+0x1ba,0),word(MAT+0x40,0)])
cases=[];rng=random.Random(2026101389)
for mode in range(256):
 for gate in [0,0x40000]:
  for flags in [0,2,0x4000,0x8000,0xc000]:
   for bit in [0,1]:
    c=seed(mode);c['writes'] += [word(RUNTIME+0x13c,gate),byte(RUNTIME+0x1ba,bit),word(MAT+0x40,flags)];cases.append(c)
for destination in [MAT+0x40+shift for shift in range(-32,33,4)]+[RUNTIME+0x13c+shift for shift in range(-32,33,4)]+[RUNTIME+0x1ba+shift for shift in range(-32,33,4)]:
 for mode in [0,0x10,0x20,0x30,1,3]:
  c=seed(mode);c['args'][0]=destination;c['projection']=False;cases.append(c)
for i in range(256):
 c=seed(rng.getrandbits(32));c['args'][4]=rng.getrandbits(32);c['writes'] += [word(RUNTIME+0x13c,rng.getrandbits(32)),byte(RUNTIME+0x1ba,rng.randrange(256)),word(MAT+0x40,rng.getrandbits(32))];cases.append(c)
rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 im=Image(c);build(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 d,r,m,mode,fourth=c['args'];n.call(0x744320,[r,m,mode,fourth],regs={UC_X86_REG_ECX:d});actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest();checks+=1+c['projection']
 if actual!=im.hash() or c['projection'] and list(n.unpack('<9I',d))!=values(initial,c):errors.append(dict(case=i,native=actual,model=im.hash()));break
 c['expected']=dict(sha256=actual,key=list(n.unpack('<9I',d)));rows.append(c)
report=dict(status='sealed qualified' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase89-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase89-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
