import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase24-20261013-verify.py');links={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),links)
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;PTR=D+0x1000;R=D+0x3000;R2=D+0x4000;FREE7=D+0x12000;FREE=D+0x13000;RETURN=D+0x14000;RETURNS=D+0x16000;PACKETS=D+0x18000
REGIONS=[(D,0x80000,167),(0x2961f00,0x400,167),(0x2921100,0x1200,167),(0x2923180,0x80,167),(0x2947b70,4,0),(0x2947d00,0x400,0),(0x2948e00,0x600,0),(0x8108e8,8,0),(0x292fa00,0x600,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];S16=rot['signed16'];S8=lambda v:v-256 if v&128 else v;S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
class Image(rot['Image']):
 def read(self,a,z):return super().read(U(a),z)
 def write(self,a,v):return super().write(U(a),v)
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
Slot=0x296209c;Packet=0x2961fec;ReturnTable=0x2923198;ReturnCount=0x2947b70
phys=lambda im,e:im.W(im.W(Slot)+S16(im.H(e+0x182))*4)
chunk=lambda e,i:U(e+0x100+i*4)
limit=lambda im:S(im.W(0x8108e8)+im.W(0x8108ec))
def find(im,base,max,value):
 for i in range(max if max>0 else 0):
  if im.W(base+i*0x64)==value:return i
 return -1
def enqueue(im,e,r,off):
 if im.B(e+0x2f6):links['priority'](im,U(im.W(Packet)+off),U(0x292fd30+S8(im.B(r+0x2f1))*4))
def snapshot(im,e,off):
 im.W(im.W(Packet)+off+8,0);dest=U(im.W(Packet)+off+12)
 for i in range(0,64,4):im.W(dest+i,im.W(e+0x40+i))
 x=im.W(e+0x190);im.W(im.W(Packet)+off+0x4c,x);im.W(im.W(Packet)+off+0x50,im.W(e+0x194));im.W(im.W(Packet)+off+0x54,im.W(e+0x198));im.H(im.W(Packet)+off+0x60,im.H(e+0x328))
def transfer(im,e):
 r=phys(im,e);delta=S16(im.H(e+0x18c))-S16(im.H(e+0x180))
 if not delta:return
 if delta>0:
  special=im.B(r+0x2e)==7;used=0x2947d84 if special else 0x2948e98;cap=0x8108ec if special else 0x8108e8;free=0x29211fc if special else 0x2921200
  if S(im.W(used)+delta)>=S(im.W(cap)):return
  for i in range(delta):
   old=S16(im.H(e+0x180));ptr=im.W(im.W(free)+(im.W(used)+i)*4);im.W(chunk(e,old+i),ptr)
   for j in range(12 if special else 32):
    p=im.W(chunk(e,S16(im.H(e+0x180))+i));im.W(p+0x2c+j*32,0);p=im.W(chunk(e,S16(im.H(e+0x180))+i));im.W(p+0x3c+j*32,0x47000000)
  if not im.H(e+0x180):
   lim=limit(im);base=im.W(Packet);index=find(im,base,lim,0)
   if index>=0:
    off=index*0x64;im.W(base+off,im.W(e+0x100));im.W(im.W(Packet)+off+4,r);im.W(im.W(Packet)+off+8,e);im.H(im.W(Packet)+off+0x60,im.H(e+0x328));enqueue(im,e,r,off)
  im.H(e+0x180,im.H(e+0x180)+delta)
  if im.H(e+0x180)==im.H(e+0x18c):im.H(e+0x186,im.H(e+0x18e))
  else:im.H(e+0x186,im.H(e+0x186)+(12 if special else 32))
  im.W(used,im.W(used)+delta);links['commands'](im,e+0x100,S16(im.H(e+0x180)));return
 if S(im.W(ReturnCount)-delta)>S(limit(im)*2):return
 assert im.W(0x2962058)==0;im.W(0x2962058,1)
 for i in range(delta,0):
  node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node,im.W(chunk(e,S16(im.H(e+0x180))+i)));node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node+8,7 if im.B(r+0x2e)==7 else 0)
  cb=im.B(r+0x2f1)==4;current=phys(im,e);frames=S8(im.B(current+0x410));product=N.word(im.W(current+0x414))*N(frames);clock=N.word(im.W(current+0xa4))+N.word(im.W(0x2962060 if cb else 0x296205c));value=(clock+product).store();node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node+4,value)
  node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);links['timed'](im,node,0x292fc00 if cb else 0x292fbfc);im.W(ReturnCount,im.W(ReturnCount)+1)
 current=S16(im.H(e+0x180));im.W(0x2962058,0)
 if delta==-current:
  lim=limit(im);base=im.W(Packet);first=im.W(e+0x100);index=find(im,base,lim,first)
  if index>=0:off=index*0x64;im.W(base+off+4,phys(im,e));snapshot(im,e,off)
 else:
  links['commands'](im,chunk(e,current+delta),-delta);lim=limit(im);base=im.W(Packet);index=find(im,base,lim,0)
  if index>=0:
   off=index*0x64;im.W(base+off,im.W(chunk(e,S16(im.H(e+0x180))+delta)));im.W(im.W(Packet)+off+4,phys(im,e));snapshot(im,e,off)
   if im.B(e+0x2f6):enqueue(im,e,phys(im,e),off)
 for i in range(delta,0):im.W(chunk(e,S16(im.H(e+0x180))+i),0)
 wanted=im.H(e+0x18e);count=im.H(e+0x18c);im.H(e+0x180,count);im.H(e+0x186,wanted)
 if wanted:links['commands'](im,e+0x100,S16(count))
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x683560,0x5ffea0,0x654e00,0x6551d0]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))
def seed(cur=0,wanted=1,typ=0):
 unit=12 if typ==7 else 32
 c=dict(emitter=EM,writes=[word(Slot,PTR),word(PTR+4,R),word(PTR-8,R2),half(EM+0x182,1),half(EM+0x180,cur),half(EM+0x18c,wanted),half(EM+0x18e,wanted*unit),half(EM+0x186,cur*unit),half(EM+0x328,30000),byte(EM+0x2f6,1),word(EM+0x190,bits(1.25)),word(EM+0x194,bits(-2.5)),word(EM+0x198,bits(-0.0)),word(0x29211fc,FREE7),word(0x2921200,FREE),word(ReturnTable,RETURN),word(Packet,PACKETS),word(ReturnCount,0),word(0x2947d84,0),word(0x2948e98,0),word(0x8108e8,32),word(0x8108ec,32),word(0x2962058,0),word(0x296205c,bits(10)),word(0x2962060,bits(20)),patch(0x292fa00,bytes(0x600)),word(EM+0xfc,D+0x78000),patch(EM+0x40,struct.pack('<16I',*[0x7f800001 if i==0 else i*0x01010101 for i in range(16)]))])
 for p in [R,R2]:c['writes'] += [byte(p+0x2e,typ),byte(p+0x2f1,0),byte(p+0x410,3),word(p+0x414,bits(0.25)),word(p+0xa4,bits(5))]
 for i in range(-4,64):c['writes'] += [word(FREE7+i*4,D+0x20000+(i+4)*0x500),word(FREE+i*4,D+0x40000+(i+4)*0x500)]
 for i in range(32):
  p=D+0x40000+(i+4)*0x500;c['writes'] += [word(EM+0x100+i*4,p)]
  if i<cur:c['writes'] += [byte(p,0x52 if i+1==cur else 0x4e),word(p+4,0 if i+1==cur else p+0x500)]
 for i in range(128):c['writes'] += [word(RETURN+i*4,RETURNS+i*0x20),word(RETURNS+i*0x20+4,bits(i*0.5)),word(RETURNS+i*0x20+0x10,0)]
 for i in range(64):c['writes'].append(word(PACKETS+i*0x64,0))
 if cur:c['writes'] += [word(PACKETS,D+0x40000+4*0x500),word(PACKETS+4,R),word(PACKETS+8,EM),half(PACKETS+0x60,30000),word(PACKETS+0x58,0),word(PACKETS+0x5c,0)]
 return c
cases=[]
for typ in [0,2,3,7,255]:
 for cur in [0,1,2,7,15,31]:
  for wanted in [0,1,2,3,7,15,16,31,32]:cases.append(seed(cur,wanted,typ))
for typ in range(256):cases.append(seed(0,2,typ))
for typ in [0,7]:
 for used in [-2,-1,0,1,31,32]:
  for capacity in [-2,-1,0,1,2,32]:
   c=seed(0,2,typ);c['writes'] += [word(0x2947d84 if typ==7 else 0x2948e98,used),word(0x8108ec if typ==7 else 0x8108e8,capacity)];cases.append(c)
for cur,wanted in [(0,2),(2,0),(3,1)]:
 for packets in ['free','full','missing','second']:
  for flag in [0,1]:
   c=seed(cur,wanted);c['writes'].append(byte(EM+0x2f6,flag))
   if packets=='full':
    for i in range(64):c['writes'].append(word(PACKETS+i*0x64,D+0x74000+i*8))
   elif packets=='missing':c['writes'].append(word(PACKETS,D+0x74000))
   elif packets=='second':c['writes'] += [word(PACKETS+0x64,D+0x40000+4*0x500),word(PACKETS,D+0x74000)]
   cases.append(c)
for bank in [0,1,4,127,128,255]:
 for frames in [0,1,127,128,255]:
  c=seed(3,1,7);c['writes'] += [byte(R+0x2f1,bank),byte(R+0x410,frames)];cases.append(c)
for count in [0,1,31,63,64,65]:
 c=seed(1,0);c['writes'].append(word(ReturnCount,count));cases.append(c)
for id in [-32768,-2,-1,0,1,32767]:
 c=seed(1,0);c['writes'] += [half(EM+0x182,id),word(Slot,U(PTR-id*4)),word(PTR,R)];cases.append(c)
# Live pool counters can be overwritten by particle status initialization or priority clearing.
for typ in [0,7]:
 used=0x2947d84 if typ==7 else 0x2948e98;free=FREE7 if typ==7 else FREE
 c=seed(0,2,typ);c['writes'] += [word(used,1),word(free+4,used-0x2c)];cases.append(c)
 c=seed(0,2,typ);base=used-0x5c;c['writes'] += [word(used,1),word(Packet,base),word(base,0)];cases.append(c)
c=seed(1,2);c['writes'] += [word(FREE,EM+0x154),half(EM+0x186,5)];cases.append(c)
c=seed(0,2);base=Slot-8;c['writes'] += [word(Packet,base),word(base,0)];cases.append(c)
# A raw snapshot matrix copy retargets the global packet base; following position/size stores use the new base.
for cur,wanted in [(2,0),(3,1)]:
 c=seed(cur,wanted);base=Packet-12;c['writes'] += [word(Packet,base),word(base,D+0x40000+4*0x500 if wanted==0 else 0),word(EM+0x40,D+0x1c000)];cases.append(c)
# The timed node.next store may clear the busy lock, or queued chunk write may replace the current physical table entry.
c=seed(1,0);c['writes'].append(word(RETURN,0x2962058-0x10));cases.append(c)
c=seed(1,0);c['writes'].append(word(RETURN,PTR+4));cases.append(c)
for frames in range(256):
 c=seed(1,0);c['writes'] += [byte(R+0x410,frames),word(0x292fbfc,RETURNS+0x40)];cases.append(c)
for bank in range(256):
 c=seed(3,1);c['writes'] += [byte(R+0x2f1,bank),byte(EM+0x2f6,0)];cases.append(c)
for coeff in [0,0x80000000,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0xff7fffff,bits(0.5),bits(-3.75)]:
 for clock in [0,0x80000000,bits(1),bits(-1)]:
  c=seed(1,0);c['writes'] += [word(R+0x414,coeff),byte(R+0x410,127),word(R+0xa4,clock),word(0x296205c,clock),word(0x292fbfc,RETURNS+0x40)];cases.append(c)
c=seed(1,0);c['writes'] += [word(R+0x414,0x80000000),byte(R+0x410,0),word(R+0xa4,0x80000000),word(0x296205c,0x80000000)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);transfer(im,c['emitter']);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x683560,[c['emitter']],count=2000000)
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase25-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase25-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
