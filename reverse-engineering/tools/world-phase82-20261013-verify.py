import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x30000,0),(0x9736e0,64,0),(0x9738a4,4,0),(0x297dc00,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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

OWNER=D+0x1000;CONTROL=D+0x2000;CONTEXT=D+0x3000;SHADER=D+0x4000;DESC=D+0x6000;SOURCE=D+0x7000;ARENA=D+0x8000;PREV=D+0x18000;GEO=D+0x19000
quiet=lambda w:w|0x400000 if w&0x7fffffff>0x7f800000 else w
ctx=dict(bits=bits,rot=rot,N=N,U=U,F=F,struct=struct,S=S,S16=S16,S8=S8,base64=base64,quiet=quiet)
def model(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);t=ast.parse(p.read_text());selected=ast.Module(body=[x for x in t.body if isinstance(x,ast.FunctionDef)],type_ignores=[]);env=dict(ctx,__file__=str(p));exec(compile(selected,str(p),'exec'),env);return env
payload=model(81);command=model(80)
def matrix(im,s):
 local=[0]*16
 for i,field in [(0,0x154),(5,0x158),(10,0x15c),(11,0x160),(14,0x164)]:local[i]=quiet(im.W(s+field))
 control=im.W(0x9736e0);im.W(control,(im.W(control)+15)&0xfffffff0);control=im.W(0x9736e0);im.W(s+0x110,im.W(control));token=U((S16(im.H(s+0x2c))+5)*U(im.W(s+0x20)+13)+im.W(0x297dc00));im.W(im.W(control),token);im.W(control,U(im.W(control)+4));dest=im.W(control)
 for i in range(16):im.W(dest+i*4,im.W(s+0x114+i*4))
 im.W(control,U(im.W(control)+64));dest=im.W(control)
 for i in range(16):im.W(dest+i*4,local[i])
 im.W(control,U(im.W(control)+64));cursor=im.W(control)
 for i in range(4):
  v=quiet(im.W(s+0x184+i*4));cursor+=4
  if i!=3:im.W(control,cursor)
  im.W(cursor-4,v)
  if i==3:im.W(control,cursor)
def emit(im,c):
 o=c['owner'];s=c['shader']
 if not s or im.W(im.W(o+8)+0x20)==im.W(s+0x20):return
 keys=[0x24,0x2c,0x2e,0x1e,0x32,0x30];cache=[0x34,0x110,0x168,0x180,0x198,0];cmd=[0x94,0x9a,0xa6,0xa5,0xab,0xa9];helper=[0x5fcdf0,0,0x5fcf60,0x5fcef0,0x5fcf30,0x5fcfd0]
 for i,key in enumerate(keys):
  if im.H(im.W(o+8)+key)==im.H(s+key):continue
  if i==5:
   p=payload['apply'](im,dict(entry=helper[i],shader=s))
   if p:command['apply'](im,dict(record=o,type=cmd[i],payload=p))
  else:
   if not im.W(s+cache[i]):
    if i==1:matrix(im,s)
    else:p=payload['apply'](im,dict(entry=helper[i],shader=s));im.W(s+cache[i],p)
   command['apply'](im,dict(record=o,type=cmd[i],payload=im.W(s+cache[i])))
  context=im.W(o+8);im.H(context+key,im.H(s+key))
 context=im.W(o+8);im.W(context+0x20,im.W(s+0x20))
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x607590,0x6034b0,0x5fcdf0,0x5fcef0,0x5fcf30,0x5fcf60,0x5fcfd0,0x6e6950]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
keys=[0x24,0x2c,0x2e,0x1e,0x32,0x30];caches=[0x34,0x110,0x168,0x180,0x198]
def seed(mask=63,cached=False,count=3):
 c=dict(owner=OWNER,shader=SHADER,writes=[word(OWNER+8,CONTEXT),word(OWNER+0x14,PREV),word(OWNER+0x18,GEO),word(0x9736e0,CONTROL),word(CONTROL,ARENA+3),word(0x9738a4,DESC),word(0x297dc00,0x12345678),byte(DESC,count),byte(DESC+2,7),word(DESC+4,SOURCE),patch(SOURCE,bytes(range(256))),patch(SHADER,struct.pack('<104f',*[i*.125 for i in range(104)])),word(SHADER+0x20,1),word(CONTEXT+0x20,0),word(SHADER+0xf4,1),word(SHADER+0x16c,1)])
 for i,key in enumerate(keys):c['writes'] += [half(SHADER+key,i+1 if mask&(1<<i) else 0)]
 for field in caches:c['writes'] += [word(SHADER+field,0xdeadbeef if cached else 0)]
 return c
cases=[];rng=random.Random(2026101382)
for mask in range(64):
 for cached in [False,True]:
  for present in [False,True]:
   c=seed(mask,cached);c['writes'] += [word(0x9738a4,DESC if present else 0)];cases.append(c)
for count in range(256):cases.append(seed(32,False,count))
for i in range(128):
 c=seed(rng.randrange(64),bool(i&1),rng.randrange(256));c['writes'] += [word(SHADER+0x20,rng.getrandbits(32)),word(0x297dc00,rng.getrandbits(32)),word(CONTROL,ARENA+rng.randrange(16)),half(SHADER+0x2c,rng.getrandbits(16))];cases.append(c)
for shift in range(-40,41,2):
 c=seed();c['writes'] += [word(OWNER+8,SHADER+shift)];cases.append(c)
c=seed();c['shader']=0;c['owner']=0xffffffff;cases.append(c)
c=seed();c['writes'] += [word(CONTEXT+0x20,1)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);emit(im,c);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x607590,[c['owner'],c['shader']],count=10000000);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,native=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(at=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:12]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed qualified raw refinement' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=0)
(B/'reports/world-phase82-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase82-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
