import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;PTR=D+0x1000;FREE=D+0x2000;ALT=D+0x3000;EM=D+0x6000;R=D+0x8000;HEAD=0x29620a8;REGIONS=[(D,0x40000,167),(0x2961f00,0x400,167),(0x2924b44,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];word=rot['word'];patch=rot['patch'];Image=rot['Image'];S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
def recycle(im):
 i=1
 if S(im.W(0x2962098))<=1:return
 table=im.W(0x296209c)
 while True:
  r=im.W(U(table+i*4))
  if r and im.W(U(r+0x2a8)):
   count=U(im.W(0x2924b44)-1);free=im.W(0x2962090);im.W(0x2924b44,count);r=im.W(U(table+i*4));descriptor=im.W(U(r+0x2a8));im.W(U(free+count*4),descriptor);r=im.W(U(im.W(0x296209c)+i*4));im.W(U(r+0x2a8),0);table=im.W(0x296209c)
  i+=1
  if i>=S(im.W(0x2962098)):break
def mask(im,id,value):im.B(U(im.W(0x29620a4)+id*0x330+0x1da),value)
def prepend(im,e):
 h=im.W(HEAD)
 if h:im.W(U(h+0x1cc),e);h=im.W(HEAD)
 im.W(U(e+0x1c8),h);im.W(HEAD,e)
def unlink(im,e):
 previous=im.W(U(e+0x1cc))
 if not previous:
  next=im.W(U(e+0x1c8));im.W(HEAD,next)
  if next:im.W(U(next+0x1cc),0)
 else:
  next=im.W(U(e+0x1c8));im.W(U(previous+0x1c8),next);next=im.W(U(e+0x1c8))
  if next:im.W(U(next+0x1cc),im.W(U(e+0x1cc)))
 im.W(U(e+0x1c8),0);im.W(U(e+0x1cc),0)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x655380,0x655fc0,0x655fe0,0x656010]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(kind='recycle'):
 c=dict(kind=kind,id=0,value=7,emitter=EM,writes=[word(0x2962098,32),word(0x296209c,PTR),word(0x2962090,FREE),word(0x2924b44,64),word(0x29620a4,EM),word(HEAD,0),word(EM+0x1c8,0),word(EM+0x1cc,0)])
 for i in range(64):c['writes'] += [word(PTR+i*4,R+i*0x500),word(R+i*0x500+0x2a8,D+0x3f000+i*4)]
 return c
cases=[]
for cap in [-2147483648,-1,0,1,2,7,31,64]:
 for pattern in ['none','all','even','null']:
  c=seed();c['writes'].append(word(0x2962098,cap))
  for i in range(64):
   if pattern=='none' or pattern=='even' and i%2:c['writes'].append(word(R+i*0x500+0x2a8,0))
   if pattern=='null' and i%2:c['writes'].append(word(PTR+i*4,0))
  cases.append(c)
for count in [0,1,2,31,64,0xffffffff]:
 c=seed();c['writes'] += [word(0x2962098,2),word(0x2924b44,count),word(0x2962090,U(FREE-U(count-1)*4))];cases.append(c)
c=seed();c['writes'] += [word(0x2962098,3),word(0x2924b44,1),word(0x2962090,0x296209c),word(R+0x500+0x2a8,ALT),word(ALT+4,R+0x1000),word(ALT+8,0)];cases.append(c)
c=seed();c['writes'] += [word(PTR+4,0x2962098-0x2a8)];cases.append(c)
for id in [0xffffffff,0xfffffffe,0xffff8000,0,1,31,0x7fffffff,0x80000000]:
 for value in [0,1,127,128,255,0xffffffff,0x12345678]:
  c=seed('mask');c.update(id=id,value=value);c['writes'].append(word(0x29620a4,U(EM-id*0x330)));cases.append(c)
for value in range(256):c=seed('mask');c['value']=value;cases.append(c)
c=seed('mask');c['value']=255;c['writes'].append(word(0x29620a4,0x29620a4-0x1da));cases.append(c)
for h in [0,EM,EM+0x330,EM+0x660,HEAD-0x1cc]:
 c=seed('prepend');c['writes'].append(word(HEAD,h));cases.append(c)
for previous in [0,EM,EM-4,EM+0x330]:
 for next in [0,EM,EM+0x330,EM+0x660]:
  c=seed('unlink');c['writes'] += [word(HEAD,EM+0x330),word(EM+0x1cc,previous),word(EM+0x1c8,next)];cases.append(c)
rng=random.Random(2026101332)
for i in range(128):
 kind=rng.choice(['prepend','unlink']);c=seed(kind);c['writes'] += [word(HEAD,rng.choice([0,EM,EM+0x330,EM+0x660])),word(EM+0x1cc,rng.choice([0,EM,EM+0x330,EM+0x660])),word(EM+0x1c8,rng.choice([0,EM,EM+0x330,EM+0x660]))];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 if c['kind']=='recycle':recycle(im)
 elif c['kind']=='mask':mask(im,c['id'],c['value'])
 elif c['kind']=='prepend':prepend(im,c['emitter'])
 else:unlink(im,c['emitter'])
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(dict(recycle=0x655380,mask=0x655fc0,prepend=0x655fe0,unlink=0x656010)[c['kind']],[] if c['kind']=='recycle' else [c['id'],c['value']] if c['kind']=='mask' else [c['emitter']])
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():errors.append(dict(case=i,kind=c['kind'],actual=actual,model=im.hash()));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase32-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase32-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
