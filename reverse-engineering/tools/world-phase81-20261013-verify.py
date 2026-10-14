import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x20000,167),(0x9736e0,64,167),(0x9738a4,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

SHADER=D+0x1000;CONTROL=D+0x2000;ARENA=D+0x4000;DESC=D+0x7000;SOURCE=D+0x8000
quiet=lambda w:w|0x400000 if w&0x7fffffff>0x7f800000 else w
def align(im):
 c=im.W(0x9736e0);im.W(c,(im.W(c)+15)&0xfffffff0);c=im.W(0x9736e0);return c,im.W(c)
def apply(im,c):
 e=c['entry'];s=c['shader']
 if e==0x5fcfd0 and not im.W(0x9738a4):return 0
 control,p=align(im)
 if e==0x5fcdf0:
  im.W(control,U(p+188));src=[0x38,0x68,0x44,0x74,0x50,0x80,0x5c];dest=[0,0x10,0x40,0x20,0x50,0x30,0x60]
  for a,b in zip(src,dest):
   for j in range(3):im.W(p+b+j*4,quiet(im.W(s+a+j*4)))
   im.W(p+b+12,0x3f800000)
  for j in range(16):im.W(p+0x70+j*4,im.W(s+0x90+j*4))
  for j in range(3):im.W(p+0xb0+j*4,im.W(s+0xd0+j*4))
 elif e==0x5fcef0:
  v=quiet(im.W(s+0xf8)) if im.W(s+0xf4) else 0x3f800000;im.W(p,v);im.W(control,U(p+4))
 elif e==0x5fcf30:im.W(p,im.W(s+0x194));im.W(control,U(im.W(control)+4))
 elif e==0x5fcf60:
  enabled=im.W(s+0x16c);im.W(p,enabled);im.W(control,U(im.W(control)+4));active=im.W(s+0x16c)!=0;current=im.W(control)
  if active:
   im.W(current,im.W(s+0x178));im.W(control,U(im.W(control)+4));v=quiet(im.W(s+0x170));current=im.W(control);im.W(current,v);current+=4;im.W(control,current);im.W(current,quiet(im.W(s+0x174)));current+=4;im.W(control,current);im.W(current,quiet(im.W(s+0x17c)));current+=4;im.W(control,current)
 else:
  d=im.W(0x9738a4);count=im.B(d);im.W(p,count);im.W(control,U(im.W(control)+4));d=im.W(0x9738a4);second=im.B(d+2);current=im.W(control);im.W(current,second);im.W(control,U(im.W(control)+4));d=im.W(0x9738a4);count=im.B(d);current=im.W(control);im.W(control,current+((count+3)//4)*16);d=im.W(0x9738a4);src=im.W(d+4)
  if im.B(d):
   i=0
   while True:
    value=S8(im.B(src));src+=1;im.W(current,bits(float(value)));current+=4;i+=1;d=im.W(0x9738a4)
    if i>=im.B(d):break
 return p
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x5fcdf0,0x5fcef0,0x5fcf30,0x5fcf60,0x5fcfd0]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(e,offset=0):
 return dict(entry=e,shader=SHADER,writes=[word(0x9736e0,CONTROL),word(CONTROL,ARENA+offset),patch(SHADER,struct.pack('<104f',*[i*.125 for i in range(104)])),word(SHADER+0xf4,1),word(SHADER+0x16c,1),word(0x9738a4,DESC),byte(DESC,3),byte(DESC+2,2),word(DESC+4,SOURCE),patch(SOURCE,bytes(range(256)))])
cases=[];rng=random.Random(2026101381)
for e in [0x5fcdf0,0x5fcef0,0x5fcf30,0x5fcf60,0x5fcfd0]:
 for offset in range(16):cases.append(seed(e,offset))
 if e!=0x5fcfd0:
  for shift in range(-64,257,16):
   c=seed(e);c['writes'] += [word(CONTROL,SHADER+shift)];cases.append(c)
for count in range(256):
 c=seed(0x5fcfd0);c['writes'] += [byte(DESC,count)];cases.append(c)
for w in [0,1,0xffffffff,0x80000000,0x7f800000,0xff800000,0x7fc00001,0x80000001,bits(1),bits(-1)]:
 for e in [0x5fcef0,0x5fcf60,0x5fcf30]:
  c=seed(e)
  if e==0x5fcef0:c['writes'] += [word(SHADER+0xf4,0 if w==0 else 1),word(SHADER+0xf8,w)]
  elif e==0x5fcf60:c['writes'] += [word(SHADER+0x16c,w),word(SHADER+0x170,w),word(SHADER+0x174,w),word(SHADER+0x17c,w)]
  else:c['writes'] += [word(SHADER+0x194,w)]
  # Consumed signalingNaN is outside original/Unicorn spill parity domain.
  if e!=0x5fcf30 and w&0x7fffffff>0x7f800000 and not w&0x400000:continue
  cases.append(c)
for i in range(128):
 c=seed(0x5fcdf0);c['writes'] += [patch(SHADER,struct.pack('<104f',*[rng.uniform(-100,100) for j in range(104)]))];cases.append(c)
for e,field in [(0x5fcef0,0xf4),(0x5fcf60,0x16c),(0x5fcf30,0x194)]:
 c=seed(e);c['shader']=CONTROL-field;c['writes'] += [patch(CONTROL+4,struct.pack('<4f',1,2,3,4))];cases.append(c)
c=seed(0x5fcfd0);c['writes'] += [word(0x9738a4,0)];cases.append(c)
c=seed(0x5fcfd0);c['writes'] += [word(0x9738a4,ARENA+8),byte(ARENA+8,3),byte(ARENA+10,2),word(ARENA+12,SOURCE),byte(SOURCE,1)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);pred=apply(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 rv=n.call(c['entry'],[c['shader']]);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if rv!=pred or actual!=im.hash():errors.append(dict(case=i,entry=hex(c['entry']),native=actual,model=im.hash(),nativeResult=rv,modelResult=pred));break
 c['expected']=dict(result=rv,sha256=actual);rows.append(c)
report=dict(status='sealed qualified raw refinement' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=0,consumedSignalingNaNDomain='excluded in floatspill fields; rawcopy fields retainallbits')
(B/'reports/world-phase81-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase81-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
