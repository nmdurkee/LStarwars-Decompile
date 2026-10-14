import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;HEAD=D+0x800;TABLE=D+0x1000;NEW=D+0x3000;NODES=D+0x4000;PHYSICAL=D+0x10000
REGIONS=[(D,0x40000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word']
class Image(rot['Image']):
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
S8=lambda x:x-256 if x&128 else x
Type=lambda im,node:S8(im.B(U(im.W(node+4)+0x2e)))
def commands(im,table,count):
 p=im.W(U(table+count*4-4));im.B(p,0x52);im.W(p+4,0)
 for i in range(count-2,-1,-1):p=im.W(table+i*4);im.B(p,0x4e);im.W(p+4,im.W(table+(i+1)*4))
def priority(im,node,head):
 im.W(node+0x5c,0);im.W(node+0x58,0);previous=im.W(head)
 if not previous:im.W(head,node);return
 p=im.H(previous+0x60);next=im.W(previous+0x5c);incoming=im.H(node+0x60)
 if incoming>p or incoming==p and Type(im,node)<=Type(im,previous):im.W(node+0x5c,previous);im.W(previous+0x58,node);im.W(head,node);return
 while next:
  p=im.H(next+0x60)
  if incoming<p or incoming==p and Type(im,node)>Type(im,next):previous=next;next=im.W(next+0x5c)
  else:break
 im.W(previous+0x5c,node);im.W(node+0x58,previous)
 if next:im.W(node+0x5c,next);im.W(next+0x58,node)
def timed(im,node,head):
 cursor=head
 if im.W(cursor):
  while True:
   current=im.W(cursor)
   if not F(im.W(current+4))<F(im.W(node+4)):break
   cursor=current+0x10
   if not im.W(cursor):break
 old=im.W(cursor);im.W(node+0x10,old);im.W(cursor,node)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x5ffea0,0x654e00,0x6551d0]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(kind='priority',rows=None):
 rows=[(50000,0),(30000,7),(10000,255)] if rows is None else rows
 c=dict(kind=kind,node=NEW,head=HEAD,table=TABLE,count=3,writes=[word(HEAD,NODES if rows else 0),word(NEW+4,PHYSICAL),patch(NEW+0x60,struct.pack('<H',30000)),patch(PHYSICAL+0x2e,b'\x03')])
 for i,(prio,typ) in enumerate(rows):
  at=NODES+i*0x80;r=PHYSICAL+(i+1)*0x500;c['writes'] += [word(at+4,r),word(at+0x58,NODES+(i-1)*0x80 if i else 0),word(at+0x5c,NODES+(i+1)*0x80 if i+1<len(rows) else 0),patch(at+0x60,struct.pack('<H',prio)),patch(r+0x2e,bytes([typ]))]
 return c
cases=[]
for count in [-31,-2,-1,0,1,2,3,12,32,63]:
 c=seed('commands');c['count']=count
 for i in range(-32,64):c['writes'].append(word(TABLE+i*4,D+0x8000+(i+32)*0x80))
 cases.append(c)
for count in [1,2,3,12,32]:
 c=seed('commands');c['count']=count
 for i in range(-1,count):c['writes'].append(word(TABLE+i*4,D+0x8000))
 cases.append(c)
c=seed('commands');c['count']=2;c['writes'] += [word(TABLE,TABLE),word(TABLE+4,D+0x8000)];cases.append(c)
c=seed('commands');c['count']=3;c['writes'] += [word(TABLE,D+0x8000),word(TABLE+4,TABLE+8),word(TABLE+8,D+0x9000)];cases.append(c)
for count in [0,1,2,7,31]:
 for incoming in [0,1,10000,30000,32767,32768,50000,65535]:
  for typ in [0,7,127,128,255]:
   c=seed(rows=[(65535-i*2000,(i*31)&255) for i in range(count)]);c['writes'] += [patch(NEW+0x60,struct.pack('<H',incoming)),patch(PHYSICAL+0x2e,bytes([typ]))];cases.append(c)
for typ in range(256):
 c=seed(rows=[(30000,128),(30000,0),(30000,127)]);c['writes'] += [patch(PHYSICAL+0x2e,bytes([typ]))];cases.append(c)
rng=random.Random(2026101324)
for i in range(192):
 count=rng.randrange(32);rows=[(rng.randrange(65536),rng.randrange(256)) for _ in range(count)];c=seed(rows=rows);c['writes'] += [patch(NEW+0x60,struct.pack('<H',rng.randrange(65536))),patch(PHYSICAL+0x2e,bytes([rng.randrange(256)]))];cases.append(c)
for offset in [0x58,0x5c]:c=seed();c['head']=NEW+offset;cases.append(c)
c=seed();c['node']=NODES;cases.append(c)
for count in [0,1,2,7,31]:
 for incoming in [bits(-100),0x80000000,0,bits(1),bits(100),0x7f800000,0xff800000,0x7fc12345,0xffc12345]:
  c=seed('timed',[]);c['writes'] += [word(HEAD,NODES if count else 0),word(NEW+4,incoming)]
  for i in range(count):c['writes'] += [word(NODES+i*0x80+4,bits((i-count//2)*2)),word(NODES+i*0x80+0x10,NODES+(i+1)*0x80 if i+1<count else 0)]
  cases.append(c)
for incoming in [bits(-1),0,0x7f800000,0xff800000,0x7fc00001]:
 for current in [bits(-1),0,0x7f800000,0xff800000,0x7fc00001]:
  c=seed('timed',[]);c['writes'] += [word(HEAD,NODES),word(NEW+4,incoming),word(NODES+4,current),word(NODES+0x10,0)];cases.append(c)
for i in range(192):
 count=rng.randrange(32);c=seed('timed',[]);c['writes'] += [word(HEAD,NODES if count else 0),word(NEW+4,bits(rng.randrange(-20,20)/8))]
 for j in range(count):c['writes'] += [word(NODES+j*0x80+4,bits(rng.randrange(-20,20)/8)),word(NODES+j*0x80+0x10,NODES+(j+1)*0x80 if j+1<count else 0)]
 cases.append(c)
c=seed('timed',[]);c['head']=NEW+0x10;c['writes'] += [word(NEW+4,bits(0)),word(NEW+0x10,0)];cases.append(c)
c=seed('timed',[]);c['node']=NODES;c['writes'] += [word(HEAD,NODES),word(NODES+4,bits(1)),word(NODES+0x10,0)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);kind=c['kind']
 if kind=='commands':commands(im,c['table'],c['count'])
 elif kind=='priority':priority(im,c['node'],c['head'])
 else:timed(im,c['node'],c['head'])
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call({'commands':0x5ffea0,'priority':0x654e00,'timed':0x6551d0}[kind],[c['table'],U(c['count'])] if kind=='commands' else [c['node'],c['head']])
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,kind=kind,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase24-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase24-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
