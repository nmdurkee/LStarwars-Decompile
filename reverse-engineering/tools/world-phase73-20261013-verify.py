import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x20000,0),(0x963f78,16,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

P=D+0x1000;REGION=D+0x2000;CAND=D+0x4000;PLANES=D+0x6000
identity=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]
def dot(im,plane,sphere):
 v=N.word(im.W(plane+4))*N.word(sphere[1])+N.word(im.W(plane))*N.word(sphere[0]);v=v+N.word(im.W(plane+8))*N.word(sphere[2]);return (v+N.word(im.W(plane+12))).store()
def sphere(im,point,candidate):
 count=S16(im.H(candidate+0x9c));outside=0;r=F(point[3])
 if count>0:
  plane=im.W(candidate+0x80)
  for i in range(count):
   d=F(dot(im,plane+i*16,point))
   if d< -r:return 0
   if d>r:outside+=1
 d=F(dot(im,0x963f78,point))
 if d< -r:return 0
 if d>r:outside+=1
 return 1 if outside==count+1 else 2
def apply(im,c):
 if c['entry']==0x5d94a0:return sphere(im,[im.W(c['point']+i*4) for i in range(4)],c['candidate'])
 region=c['region'];sel=c['selection']&65535
 if not im.W(region+0x6c) or S16(sel)==S(im.W(region+0xe0)):return 1
 count=S(im.W(region+0xdc));cursor=region+0x9c
 for i in range(count):
  candidate=im.W(cursor+i*4)
  if not candidate or im.H(candidate+0x9e)!=sel:continue
  v=sphere(im,[im.W(c['point']+j*4) for j in range(3)]+[c['radius']],candidate)
  if v:return v
 return 0
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x5da3b0,0x5d94a0]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(e=0x5d94a0):
 c=dict(entry=e,point=P,candidate=CAND,region=REGION,selection=7,radius=bits(1),writes=[patch(P,struct.pack('<4f',1,2,3,1)),word(REGION+0x6c,1),word(REGION+0xe0,0),word(REGION+0xdc,3),word(REGION+0x9c,CAND),word(REGION+0xa0,0),word(REGION+0xa4,CAND+0x200),word(CAND+0x80,PLANES),half(CAND+0x9c,3),half(CAND+0x9e,7),word(CAND+0x200+0x80,PLANES+0x100),half(CAND+0x200+0x9c,0),half(CAND+0x200+0x9e,7),patch(PLANES,struct.pack('<12f',1,0,0,0,0,1,0,0,0,0,1,0)),patch(0x963f78,struct.pack('<4f',0,1,0,0))]);return c
cases=[];rng=random.Random(2026101373)
for count in [-32768,-2,-1,0,1,2,3,4,8]:
 for radius in [-2,-1,-0.0,0,1,2]:
  for d in [-3,-2,-1,-0.0,0,1,2,3]:
   c=seed();c['writes'] += [half(CAND+0x9c,count),patch(P,struct.pack('<4f',d,d,d,radius))];cases.append(c)
for i in range(384):
 c=seed();count=rng.randrange(1,9);c['writes'] += [half(CAND+0x9c,count),patch(P,struct.pack('<4f',*[rng.uniform(-1e10,1e10) for j in range(4)])),patch(PLANES,struct.pack('<%df'%(count*4),*[rng.uniform(-1e10,1e10) for j in range(count*4)])),patch(0x963f78,struct.pack('<4f',*[rng.uniform(-1e10,1e10) for j in range(4)]))];cases.append(c)
for sel in [0,1,7,32767,32768,65535,0xffffffff]:
 for stored in [0,7,32767,32768,0xffffffff]:
  for gate in [0,1]:
   c=seed(0x5da3b0);c['selection']=sel;c['writes'] += [word(REGION+0x6c,gate),word(REGION+0xe0,stored)];cases.append(c)
for count in [-2147483648,-1,0,1,2,3,4]:
 for matched in [False,True]:
  for d in [-2,0,2]:
   c=seed(0x5da3b0);c['writes'] += [word(REGION+0xdc,count),half(CAND+0x9e,7 if matched else 8),patch(P,struct.pack('<3f',d,d,d))];cases.append(c)
for p in [0,0xffffffff,P]:
 c=seed(0x5da3b0);c['point']=p;c['radius']=0x7f800001;c['writes'] += [word(REGION+0x6c,0)];cases.append(c)
for shift in range(-8,9):
 c=seed();c['point']=PLANES+shift;c['writes'] += [patch(PLANES-8,struct.pack('<12I',*[bits(rng.uniform(-10,10)) for j in range(12)]))];
 # shifted bytes can produce nonfinite consumed values; finite prepared aliases only.
 im=Image(c)
 if all((im.W(c['point']+i*4)&0x7f800000)!=0x7f800000 for i in range(4)):cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);pred=apply(im,c)
 for a,z,_ in REGIONS:n.write(a,im.read(a,z))
 args=[c['point'],c['candidate']] if c['entry']==0x5d94a0 else [c['region'],c['point'],c['radius'],c['selection']]
 rv=n.call(c['entry'],args);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=pred or actual!=im.hash():errors.append(dict(case=i,entry=hex(c['entry']),native=rv,model=pred,image=actual,expected=im.hash()));break
 c['expected']=dict(result=rv,sha256=actual);rows.append(c)
report=dict(status='sealed finite prepared' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entryCounts=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase73-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase73-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
