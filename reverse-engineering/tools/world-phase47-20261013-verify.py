import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
def load(num,marker):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);x={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index(marker)],str(p),'exec'),x);return x
rot=load(20,'cases=[];rng=');maths=load(36,'from unicorn import UC_HOOK_CODE');inv=load(44,'\nfrom unicorn import UC_HOOK_CODE')
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;R=D+0x3000;CHUNKS=D+0x20000;CALLBACK=0x10303000
REGIONS=[(D,0x80000,167),(0x810800,0x200,167),(0x29899a0,0x20000,0),(0x8065c0,64,0),(0x29a9c48,4,0)];rot['REGIONS']=REGIONS;rot['common']=[rot['patch'](0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes()),rot['patch'](0x8065c0,n.read(0x8065c0,64))];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];S16=rot['signed16'];S8=lambda v:v-256 if v&128 else v;S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
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
case={};trace=[]
def service(im,address,args):
 trace.append([address,args])
 if address==0x600260:im.W(args[0]+0x2a8,D+0x78000);return 0
 if address!=CALLBACK:raise ValueError('alias selected an unprepared attribute callback '+hex(address))
 e,r,p=args
 if case.get('mutateParticle'):im.W(p,bits(4));im.W(p+16,bits(-3))
 if case.get('mutateEmitter'):im.W(e+0x19c,bits(6));im.W(e+0x1ac,bits(7))
 if case.get('mutateRecord'):im.B(r+0x410,3);im.W(r+0x414,bits(0.75))
 if case.get('publishEarly'):im.W(r+0x2a8,D+0x79000)
 return 0
def nextRandom(im):
 s=U(im.W(0x810900)*1664525+1013904223);im.W(0x810900,s);return N((s&0x7fffff)/8388608)
def randomAxis(im,r,field,bias=False):
 rnd=nextRandom(im);value=(rnd+rnd)*N.word(im.W(r+field));value=value+N(-N.word(im.W(r+field)).v,not N.word(im.W(r+field)).neg)
 if bias:value=value+N.word(im.W(r+0x48))
 return value.store()
def select(im,e,r):
 cursor=S16(im.H(e+0x18a))
 if cursor>=S16(im.H(e+0x186)):im.H(e+0x18a,0)
 cursor=S16(im.H(e+0x18a));unit=12 if im.B(r+0x2e)==7 else 32;bank=abs(cursor)//unit*(1 if cursor>=0 else -1);within=cursor-bank*unit;p=U(im.W(e+0x100+bank*4)+(within+1)*32);im.H(e+0x18a,im.H(e+0x18a)+1);return p
def ftol(im,value):
 v=value.v
 if im.W(0x29a9c48):v=rot['quant'](v,53)
 q=abs(v.numerator)//v.denominator*(-1 if v<0 else 1);return q if -2147483648<=q<=2147483647 else -2147483648
def turnx(im,radius,yaw,pitch):
 sin=lambda a:N.word(im.W(0x29899a0+(((U(a)^0x80000000)-0x80000000>>1)&32767)*4));x=N.word(radius);z=N(0);ss=sin(pitch);cc=sin(pitch+16384);a=(cc*x+N(-(ss*z).v,not (ss*z).neg)).store();b=(x*ss+cc*z).store();x=N.word(a);ss=sin(yaw);cc=sin(yaw+16384);return [(ss*z+cc*x).store(),b,(z*cc+N(-(x*ss).v,not (x*ss).neg)).store()]
def valuesTransform(point,matrix):
 out=[0,0,0]
 for axis in [1,2]:out[axis]=(N.word(matrix[axis])*N.word(point[0])+N.word(matrix[4+axis])*N.word(point[1])+N.word(matrix[8+axis])*N.word(point[2])+N.word(matrix[12+axis])).store()
 out[0]=(N.word(matrix[4])*N.word(point[1])+N.word(point[0])*N.word(matrix[0])+N.word(matrix[8])*N.word(point[2])+N.word(matrix[12])).store();return out
def initialize(im,c):
 e=c['emitter'];r=c['record'];t=c['time'];p=select(im,e,r);T=N.word(t);im.W(p+12,t);im.W(e+0x324,t);life=im.W(r+0xa4)
 im.W(p+28,((life&0x80000000)|0x7f800000) if not life&0x7fffffff else N(rot['quant'](64/N.word(life).v,64),(life&0x80000000)!=0).store())
 radial=bits(math.sqrt(float(nextRandom(im).v)));yaw=ftol(im,nextRandom(im)*N(65536));random=nextRandom(im);sampled=(random+random+N(-1)).store();pitch=S16(inv['inverse'](sampled,im.W(0x29a9c48))&65535);point=turnx(im,radial,yaw,pitch);matrix=[im.W(0x8065c0+i*4) for i in range(16)];matrix[0]=im.W(r+0x58);matrix[5]=im.W(r+0x5c);matrix[10]=im.W(r+0x60);point=valuesTransform(point,matrix);point=maths['transformwords'](im,point,e+0x80)
 for i in range(3):im.W(p+i*4,point[i])
 a=[randomAxis(im,r,0x4c),randomAxis(im,r,0x50,True),randomAxis(im,r,0x54)];point=maths['transformwords'](im,a,e+0x80)
 for i in range(3):im.W(p+16+i*4,point[i])
 callback=im.W(e+0x1c4)
 if callback:service(im,callback,[e,r,p])
 for i in range(3):im.W(p+i*4,(N.word(im.W(e+0x19c+i*4))+N.word(im.W(p+i*4))).store())
 for i in range(3):im.W(p+16+i*4,(N.word(im.W(e+0x1a8+i*4))+N.word(im.W(p+16+i*4))).store())
 if S8(im.B(r+0x410))>0:
  index=0
  while True:
   dest=select(im,e,r);index+=1
   for i in range(0,32,4):im.W(dest+i,im.W(p+i))
   im.W(dest+12,(N(index)*N.word(im.W(r+0x414))+N.word(im.W(dest+12))).store())
   if index>=S8(im.B(r+0x410)):break
 if not im.W(r+0x2a8):service(im,0x600260,[r])
 return p
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n.mu.mem_map(CALLBACK,0x1000);n.write(CALLBACK,b'\xc3');entries={};nativeTrace=[]
class NativeImage:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
 def H(self,a,v=None):
  if v is None:return n.unpack('<H',U(a))[0]
  n.write(U(a),struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return n.read(U(a),1)[0]
  n.write(U(a),bytes([v&255]))
NI=NativeImage()
def observe(uc,a,z,user):
 if a in [0x681f70,0x5c0240,0x6e9530,0x64fe20,0x64ff80,0x6e6b90,0x5b3690,0x5b3620,0x5c11d0,0x5b9d90]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x600260,CALLBACK]:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];args=list(n.unpack('<I' if a==0x600260 else '<3I',sp+4));start=len(trace);value=service(NI,a,args);nativeTrace.extend(trace[start:]);del trace[start:]
 uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(typ=0,cursor=0,active=32,frames=0,entry=0x681f70):
 c=dict(entry=entry,emitter=EM,record=R,time=bits(10),writes=[patch(EM,bytes(0x330)),half(EM+0x18a,cursor),half(EM+0x186,active),word(EM+0x1e0,bits(9)),word(R+0xa4,bits(5)),byte(R+0x2e,typ),byte(R+0x410,frames),word(R+0x414,bits(0.25)),word(R+0x2a8,0),word(EM+0x1c4,0),word(0x810900,0x12345678),patch(EM+0x80,struct.pack('<16f',1,0,0,0,0,1,0,0,0,0,1,0,0.125,-0.25,0.5,1)),patch(EM+0x19c,struct.pack('<3f',1.25,-2.5,-0.0)),patch(EM+0x1a8,struct.pack('<3f',0.5,0.25,-0.0)),patch(R+0x48,struct.pack('<10f',0.75,1,2,3,4,5,6,0.25,0.5,0.75))])
 for i in range(32):c['writes'] += [word(EM+0x100+i*4,CHUNKS+i*0x500)]
 # Negative signed cursors read preceding emitter words; prepare that exact route without normalizing them.
 unit=12 if typ==7 else 32
 if cursor<active and (cursor<0 or cursor>=unit*32):
  bank=abs(cursor)//unit*(1 if cursor>=0 else -1);c['writes'] += [word(EM+0x100+bank*4,CHUNKS)]
 return c
cases=[]
for entry in [0x681f70]:
 for typ in [0,7]:
  for cursor in [-32768,-33,-13,-12,-1,0,1,11,12,31,32,383,1023,32767]:
   for active in [-32768,-1,0,1,12,32,384,1024,32767]:cases.append(seed(typ,cursor,active,0,entry))
for frames in range(256):cases.append(seed(0,0,8,frames))
for rngState in [0,1,0xffffffff,0x80000000,0x007fffff,0x12345678]:
 for coef in [0,0x80000000,1,0x80000001,bits(0.5),bits(-3.75)]:
  c=seed();c['writes'] += [word(0x810900,rngState),patch(R+0x4c,struct.pack('<6I',*[coef]*6))];cases.append(c)
for life in [0,0x80000000,1,0x80000001,0x007fffff,0x00800000,bits(0.5),bits(-3.75),0x7f7fffff,0xff7fffff]:c=seed(frames=3);c['writes'] += [word(R+0xa4,life)];cases.append(c)
for feature in ['mutateParticle','mutateEmitter','mutateRecord','publishEarly']:
 c=seed();c[feature]=True;c['writes'] += [word(EM+0x1c4,CALLBACK)];cases.append(c)
# Record position fields can be overwritten by first particle stores before RNG velocity reads.
for offset in [0x48,0x4c,0x58,0x64,0xa4,0x2a8]:
 c=seed();c['writes'] += [word(EM+0x100,R+offset-32)];cases.append(c)
# Particle output overlaps emitter offsets, including the cached-time subtraction and later position additions.
for offset in [0x1e0,0x19c,0x1a8,0x80,0x324]:
 c=seed();c['writes'] += [word(EM+0x100,EM+offset-32)];cases.append(c)
for state in [0,1,0xffffffff,0x80000000,0x007fffff,0x12345678]:
 for radius in [0,0x80000000,1,0x80000001,bits(0.5),bits(-3.75),bits(1000)]:c=seed();c['writes'] += [word(0x810900,state),patch(R+0x58,struct.pack('<3I',radius,radius,radius))];cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c)
 try:result=initialize(im,c)
 except (ValueError,ZeroDivisionError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 except Exception as ex:errors.append(dict(case=i,stage='model',error=str(ex)));break
 modelTrace=trace[:];trace=[];nativeTrace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:actualResult=n.call(c['entry'],[c['emitter'],c['record'],c['time']],count=2000000)
 except Exception as ex:errors.append(dict(case=i,stage='native',error=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or nativeTrace!=modelTrace or actualResult!=result:
  errors.append(dict(case=i,actual=actual,model=im.hash(),nativeTrace=nativeTrace,modelTrace=modelTrace,actualResult=actualResult,modelResult=result))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual,trace=nativeTrace,result=actualResult);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=['selected attribute callback','0x600260 descriptor publication'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase47-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase47-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
