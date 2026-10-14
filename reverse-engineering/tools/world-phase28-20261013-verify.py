import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase24-20261013-verify.py');links={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),links)
p=Path(__file__).with_name('world-phase26-20261013-verify.py');unlinks={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),unlinks)
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;HEADS=0x292fd30;REPAIR=0x29620bc;UPDATE=0x29620c0;NODES=D+0x4000;PHYS=D+0x8000;OWNER=D+0x10000
REGIONS=[(D,0x20000,167),(HEADS,20,0),(REPAIR,8,0),(0x810900,0x100,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
class Image(rot['Image']):
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
head=lambda i:U(HEADS+i*4)
def choose(im,cursor):
 bank=start=S(im.W(cursor))
 if not im.W(head(bank)):
  while True:
   bank=S(bank+1)
   if bank>=5:bank=0
   if bank==start or im.W(head(bank)):break
  im.W(cursor,bank)
 return bank
def repair(im):
 left=S(im.W(0x810960)-1);im.W(0x810960,left)
 if left>0:return
 im.W(0x810960,6);bank=choose(im,REPAIR);h=head(bank);cur=im.W(h)
 while cur:
  next=im.W(cur+0x5c)
  if not next:return
  a,b=im.H(cur+0x60),im.H(next+0x60)
  if a<b or a==b and links['Type'](im,cur)>links['Type'](im,next):unlinks['priority'](im,next,h);links['priority'](im,next,h);return
  cur=next
def priority(size,w):
 d=F(w)
 if math.isnan(d) or d==float('-inf'):return 0
 if d==float('inf'):return 65535
 stored=F((N(size)+N.word(w)*N(25)).store())
 if stored>65535:stored=65535
 if not math.isfinite(stored) or stored<-2147483648 or stored>2147483647:return 0
 return int(stored)&65535
def recompute(im):
 left=S(im.W(0x810964)-1);im.W(0x810964,left)
 if left>0:return
 im.W(0x810964,6);selected=choose(im,UPDATE)
 if not im.W(head(selected)):return
 node=im.W(head(S(im.W(REPAIR))))
 while node:
  owner=im.W(node+8)
  if owner:
   size=im.H(owner+0x328);p=size if not im.B(owner+0x2f8) else priority(size,im.W(owner+0x31c));im.H(node+0x60,p)
  node=im.W(node+0x5c)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x654ef0,0x654fa0,0x654ea0,0x654e00]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))
def seed(kind='repair',mask=1):
 c=dict(kind=kind,writes=[word(REPAIR,0),word(UPDATE,0),word(0x810960,1),word(0x810964,1)])
 for bank in range(5):
  p=NODES+bank*0x400;c['writes'].append(word(head(bank),p if mask&(1<<bank) else 0))
  for j,(prio,typ) in enumerate([(30000,3),(40000,7),(20000,255)]):
   at=p+j*0x80;r=PHYS+(bank*3+j)*0x100;owner=OWNER+(bank*3+j)*0x400;c['writes'] += [word(at+4,r),word(at+8,owner),word(at+0x58,p+(j-1)*0x80 if j else 0),word(at+0x5c,p+(j+1)*0x80 if j<2 else 0),half(at+0x60,prio),byte(r+0x2e,typ),half(owner+0x328,10000+j),byte(owner+0x2f8,1),word(owner+0x31c,bits(bank+j*0.125))]
 return c
cases=[]
for kind in ['repair','recompute']:
 for mask in range(32):
  for first in range(5):
   for second in range(5):c=seed(kind,mask);c['writes'] += [word(REPAIR,first),word(UPDATE,second)];cases.append(c)
for kind in ['repair','recompute']:
 for timer in [-2147483648,-2,-1,0,1,2,6,7,2147483647]:
  c=seed(kind,31);c['writes'].append(word(0x810960 if kind=='repair' else 0x810964,timer));cases.append(c)
for typ in range(256):
 c=seed();c['writes'] += [half(NODES+0x60,30000),half(NODES+0x80+0x60,30000),byte(PHYS+0x2e,typ),byte(PHYS+0x100+0x2e,128)];cases.append(c)
for a,b in [(0,65535),(65535,0),(32767,32768),(32768,32767),(0,0),(65535,65535)]:
 c=seed();c['writes'] += [half(NODES+0x60,a),half(NODES+0x80+0x60,b)];cases.append(c)
for flag in range(256):
 c=seed('recompute');c['writes'].append(byte(OWNER+0x2f8,flag));cases.append(c)
for size in [0,1,32767,32768,65534,65535]:
 for d in [-1e20,-85899360,-85899345,-2622.0,-1,-0.0,0,0.125,1,2621.39990234375,2621.4,1e20]:
  c=seed('recompute');c['writes'] += [half(OWNER+0x328,size),word(OWNER+0x31c,bits(d))];cases.append(c)
for w in [0x7f800000,0xff800000,0x7fc00001,0xffc12345,0x7f800001,0xff800001,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0xff7fffff]:
 c=seed('recompute');c['writes'].append(word(OWNER+0x31c,w));cases.append(c)
for j in range(3):c=seed('recompute');c['writes'].append(word(NODES+j*0x80+8,0));cases.append(c)
rng=random.Random(2026101328)
for i in range(256):
 c=seed(rng.choice(['repair','recompute']),rng.randrange(32));c['writes'] += [word(REPAIR,rng.randrange(5)),word(UPDATE,rng.randrange(5))]
 for j in range(3):c['writes'] += [half(NODES+j*0x80+0x60,rng.randrange(65536)),byte(PHYS+j*0x100+0x2e,rng.randrange(256)),half(OWNER+j*0x400+0x328,rng.randrange(65536)),word(OWNER+j*0x400+0x31c,bits(rng.randrange(-5000,5000)/8))]
 cases.append(c)
# Countdown reset changes the first packet priority before comparison.
c=seed();node=0x810960-0x60;c['writes'] += [word(head(0),node),word(node+4,PHYS),word(node+0x58,0),word(node+0x5c,NODES+0x80),word(NODES+0x80+0x58,node),half(NODES+0x80+0x60,10)];cases.append(c)
# Recomputed priority changes a later node.next field; traversal follows the changed pointer.
c=seed('recompute');target=D+10000;c['writes'] += [half(OWNER+0x328,10000),word(OWNER+0x31c,0),word(NODES+0x5c,NODES+4),word(NODES+12,0),word(NODES+0x60,D),word(target+8,0),word(target+0x5c,0)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 if c['kind']=='repair':repair(im)
 else:recompute(im)
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x654ef0 if c['kind']=='repair' else 0x654fa0,count=1000000)
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,kind=c['kind'],actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase28-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase28-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
