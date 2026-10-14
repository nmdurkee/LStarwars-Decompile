import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x30000,167),(0x2961f00,0x400,0),(0x2924b44,4,0),(0x8108e4,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
TABLE=D+0x1000;ALT=D+0x2000;FREE=D+0x5000;R=D+0x8000
def evict(im,c):
 if c['entry']==0x6579f0:im.W(0x8108e4,c['value']);return
 count=S(im.W(0x2962098));table=im.W(0x296209c);clocks=[im.W(0x296205c),im.W(0x2962060)];selected=0;maximum=0
 for i in range(1,count):
  record=im.W(table+i*4)
  if not record or not im.W(record+0x2a8):continue
  age=(N.word(clocks[im.B(record+0x2f1)==4])+N(-N.word(im.W(record+0x2ac)).v,not N.word(im.W(record+0x2ac)).neg)).store();value=F(age)
  if value>maximum:maximum=value;selected=i
 if not selected:return
 count=U(im.W(0x2924b44)-1);im.W(0x2924b44,count);record=im.W(table+selected*4);descriptor=im.W(record+0x2a8);im.W(im.W(0x2962090)+count*4,descriptor);record=im.W(im.W(0x296209c)+selected*4);im.W(record+0x2a8,0)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x6579f0,0x657e70]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(count=8):
 c=dict(entry=0x657e70,value=0,writes=[word(0x2962098,count),word(0x296209c,TABLE),word(0x296205c,bits(10)),word(0x2962060,bits(20)),word(0x2924b44,32),word(0x2962090,FREE)])
 for i in range(64):c['writes'] += [word(TABLE+i*4,R+i*0x500),word(ALT+i*4,R+0x20000),word(R+i*0x500+0x2a8,D+0x28000+i*0x40),word(R+i*0x500+0x2ac,bits(i)),byte(R+i*0x500+0x2f1,4 if i%2 else 0)]
 return c
cases=[seed(count) for count in [-1,0,1,2,3,4,5,6,7,8,9,31,32,63,64]]
for i in range(1,16):
 for mode in ['none','only','tie','future','equal','null']:
  c=seed(16)
  for j in range(1,16):
   c['writes'] += [word(R+j*0x500+0x2a8,0 if mode=='none' or mode=='only' and j!=i else D+0x28000+j*0x40),word(R+j*0x500+0x2ac,bits(-10 if mode=='tie' else 100 if mode=='future' else 20 if mode=='equal' else j))]
  if mode=='null':c['writes'].append(word(TABLE+i*4,0))
  cases.append(c)
for counter in [0,1,32,0xffffffff]:
 c=seed();c['writes'] += [word(0x2924b44,counter),word(0x2962090,U(FREE-U(counter-1)*4))];cases.append(c)
c=seed(2);c['writes'] += [word(0x2962090,U(0x296209c-31*4)),word(R+0x500+0x2a8,ALT),word(ALT+4,R+0x1000)];cases.append(c)
c=seed(2);c['writes'] += [word(0x2962090,U(TABLE+4-31*4))];cases.append(c)
rng=random.Random(2026101358)
for i in range(256):
 c=seed(rng.randrange(65));c['writes'] += [word(0x296205c,bits(rng.uniform(-100,100))),word(0x2962060,bits(rng.uniform(-100,100)))]
 for j in range(64):c['writes'] += [word(TABLE+j*4,0 if rng.randrange(5)==0 else R+j*0x500),word(R+j*0x500+0x2a8,0 if rng.randrange(5)==0 else D+0x28000+j*0x40),word(R+j*0x500+0x2ac,bits(rng.uniform(-100,100))),byte(R+j*0x500+0x2f1,rng.randrange(8))]
 cases.append(c)
for value in [0,0x80000000,0x7f800000,0xff800000,0x7fc12345,0xffffffff]+[rng.getrandbits(32) for i in range(256)]:c=seed();c.update(entry=0x6579f0,value=value);cases.append(c)
for clock,birth in [(0x7f7fffff,0xff7fffff),(0xff7fffff,0x7f7fffff),(0,0x80000000),(0x80000000,0),(1,0x80000001),(bits(10),bits(10))]:
 c=seed(2);c['writes'] += [word(0x296205c,clock),word(0x2962060,clock),word(R+0x500+0x2ac,birth)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);evict(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(c['entry'],[c['value']] if c['entry']==0x6579f0 else []);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():errors.append(dict(case=i,native=actual,model=im.hash()));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase58-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase58-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
