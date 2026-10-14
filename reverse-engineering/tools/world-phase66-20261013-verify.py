import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x40000,167),(0x2961f00,0x400,0),(0x292fbfc,8,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
TABLE=D+0x1000;EM=D+0x4000;R=D+0x8000;CHUNKS=D+0x10000;NODES=D+0x2000;DESC=D+0x30000
def sub(im,at):im.W(at,(N.word(im.W(at))+N(-800)).store())
def selected(im,r,bank):return bank==1 if im.B(r+0x2f1)==4 else bank==0
def rebase(im,c):
 bank=c['bank']
 if bank in [0,1]:
  head=0x292fbfc+bank*4;clock=0x296205c+bank*4;backup=0x2962064+bank*4;node=im.W(head);im.W(clock,im.W(backup))
  while node:sub(im,node+4);node=im.W(node+16)
 table=im.W(0x296209c);index=0;offset=0;base=im.W(0x29620a4) if S(im.W(0x2962094))>0 else 0
 while index<S(im.W(0x2962094)):
  physical=S16(im.H(base+offset+0x182));r=im.W(table+physical*4)
  if selected(im,r,bank):
   alternate=im.B(r+0x2e)==7;sub(im,base+offset+0x320)
   for field in [0x324,0x1e0,0x1dc,0x1e4]:base=im.W(0x29620a4);sub(im,base+offset+field)
   base=im.W(0x29620a4)
   for j in range(32):
    slot=offset+0x100+j*4
    if im.W(base+slot):
     for k in range(12 if alternate else 32):chunk=im.W(base+slot);sub(im,chunk+0x2c+k*32);base=im.W(0x29620a4)
   table=im.W(0x296209c)
  index+=1;offset=U(offset+0x330)
 i=1
 while i<S(im.W(0x2962098)):
  r=im.W(table+i*4)
  if r and selected(im,r,bank):
   sub(im,r+0x2ac);table=im.W(0x296209c);r=im.W(table+i*4);descriptor=im.W(r+0x2a8)
   if descriptor:sub(im,descriptor+0x14);table=im.W(0x296209c)
  i+=1
def tick(im,c):
 for bank in [0,1]:
  clock=0x296205c+bank*4;backup=0x2962064+bank*4;b=N.word(im.W(backup));current=N.word(im.W(clock))
  if (current+N(-1)).v>b.v:rebase(im,dict(bank=bank))
  elif current.v>900:im.W(backup,(b+N(-800)).store())
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x657a00,0x657dd0]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(bank=0,count=4,chunks=2):
 c=dict(bank=bank,writes=[word(0x29620a4,EM),word(0x296209c,TABLE),word(0x2962094,count),word(0x2962098,8),word(0x296205c,bits(1000)),word(0x2962060,bits(2000)),word(0x2962064,bits(200)),word(0x2962068,bits(1200)),word(0x292fbfc,NODES),word(0x292fc00,NODES+0x200)])
 for i in range(8):
  c['writes'] += [word(TABLE+i*4,R+i*0x500),word(R+i*0x500+0x2ac,bits(900+i*20)),word(R+i*0x500+0x2a8,DESC+i*0x80),word(DESC+i*0x80+0x14,bits(900+i*20)),byte(R+i*0x500+0x2f1,4 if i%2 else 0),byte(R+i*0x500+0x2e,7 if i%3==0 else 0)]
 for i in range(8):
  e=EM+i*0x330;c['writes'] += [half(e+0x182,i)]
  for field in [0x320,0x324,0x1e0,0x1dc,0x1e4]:c['writes'].append(word(e+field,bits(900+i*20)))
  for j in range(32):
   chunk=CHUNKS+(i*4+j)*0x440;c['writes'].append(word(e+0x100+j*4,chunk if j<chunks else 0))
   if j<chunks:
    for k in range(32):c['writes'].append(word(chunk+0x2c+k*32,bits(900+i*20+k)))
 for bank in [0,1]:
  for j in range(8):c['writes'] += [word(NODES+bank*0x200+j*0x20+4,bits(900+j*100)),word(NODES+bank*0x200+j*0x20+16,NODES+bank*0x200+(j+1)*0x20 if j<7 else 0)]
 return c
cases=[]
for current in [-1000,0,.5,1,1.0000001192092896,2,799,800,800.00006103515625,801,802,899,900,900.00006103515625,901,1601]:
 for backup in [-1000,0,.5,1,799,800,801,1600]:
  for bank in [0,1]:
   c=seed(0,2,1);c['writes'] += [word(0x296205c,bits(0)),word(0x2962060,bits(0)),word(0x2962064,bits(0)),word(0x2962068,bits(0)),word(0x296205c+bank*4,bits(current)),word(0x2962064+bank*4,bits(backup))];cases.append(c)
for current,backup in [(bits(1)-1,0),(bits(1),0),(bits(1)+1,0),(bits(800)-1,bits(800)),(bits(800),bits(800)),(bits(800)+1,bits(800)),(bits(900)-1,bits(900)),(bits(900),bits(900)),(bits(900)+1,bits(900)),(0x80000000,0),(0,0x80000000),(0x7f7fffff,0x7f7fffff),(0xff7fffff,0xff7fffff)]:
 c=seed(0,1,1);c['writes'] += [word(0x296205c,current),word(0x2962060,current),word(0x2962064,backup),word(0x2962068,backup)];cases.append(c)
rng=random.Random(2026101366)
for i in range(128):
 c=seed(0,rng.randrange(9),rng.randrange(5));c['writes'] += [word(0x296205c,bits(rng.uniform(-2000,2000))),word(0x2962060,bits(rng.uniform(-2000,2000))),word(0x2962064,bits(rng.uniform(-2000,2000))),word(0x2962068,bits(rng.uniform(-2000,2000)))];cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:tick(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x657dd0,[],count=2000000)
 except Exception as ex:errors.append(dict(case=i,nativeError=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase66-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase66-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
