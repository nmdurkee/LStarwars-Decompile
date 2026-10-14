import json,hashlib,struct,base64,gzip,time,math
from pathlib import Path
p=Path(__file__).with_name('world-phase37-20261013-verify.py');base={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),base)
ip=Path(__file__).with_name('world-phase44-20261013-verify.py');inv={'__file__':str(ip)};it=ip.read_text();exec(compile(it[:it.index('\nfrom unicorn import UC_HOOK_CODE')],str(ip),'exec'),inv)
n=base['n'];B=base['B'];D=n.DATA;EM=base['EM'];R=base['R'];U=base['U'];F=base['F'];N=base['N'];bits=base['bits'];word=base['word'];patch=base['patch'];half=base['half'];byte=base['byte'];Image=base['Image'];S16=base['S16'];S8=base['S8'];REGIONS=base['REGIONS']+[(0x29899a0,0x20000,0),(0x296205c,4,0),(0x29a9c48,4,0)];base['rot']['REGIONS']=REGIONS;base['rot']['common']=[patch(0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes())]
def neg(a):return N(-a.v,not a.neg)
def sub(a,b):return a+neg(b)
def div(a,b):return N(base['rot']['quant'](a.v/b.v,64),a.neg!=b.neg)
def ftol(im,value):
 v=value.v
 if im.W(0x29a9c48):v=base['rot']['quant'](v,53)
 q=abs(v.numerator)//v.denominator*(-1 if v<0 else 1);return q if -2147483648<=q<=2147483647 else -2147483648
def rangeValue(im,r,spread,bias):
 rnd=base['nextRandom'](im);return sub((rnd+rnd)*N.word(im.W(r+spread)),N.word(im.W(r+spread)))+N.word(im.W(r+bias))
def turn(im,radius,azimuth,elevation):
 sin=lambda a:N.word(im.W(0x29899a0+((base['S'](U(a))>>1)&32767)*4));ss=sin(elevation);cc=sin(elevation+16384);x=N.word(radius);y=N.word(0);first=sub(cc*x,ss*y).store();second=(x*ss+cc*y).store();ss=sin(azimuth);cc=sin(azimuth+16384);x=N.word(first);z=N.word(0);return [(ss*z+cc*x).store(),second,sub(z*cc,x*ss).store()]
def reset(im,e):
 if S16(im.H(e+0x18a))>=S16(im.H(e+0x186)):im.H(e+0x18a,0)
def select32(im,e):
 cursor=S16(im.H(e+0x18a));bank=abs(cursor)//32*(1 if cursor>=0 else -1);within=cursor-bank*32;p=U(im.W(e+0x100+bank*4)+(within+1)*32);im.H(e+0x18a,cursor+1);return p
def initialize(im,c):
 e=c['emitter'];r=c['record'];t=c['time'];reset(im,e)
 if im.B(r+0x2e)==7:return 0
 p=select32(im,e);im.W(p+12,t);im.W(e+0x324,t);life=im.W(r+0xa4);im.W(p+28,((life&0x80000000)|0x7f800000) if not life&0x7fffffff else div(N(64),N.word(life)).store());elapsed=sub(N.word(t),N.word(im.W(e+0x1e0))).store();coordinates=[(N.word(im.W(r+0x64+i*4))*N.word(elapsed)).store() for i in range(3)];coordinates=[(N.word(coordinates[i])+N.word(im.W(r+0x58+i*4))).store() for i in range(3)];randomPhase=ftol(im,sub(base['nextRandom'](im)*N(65536),N(32768)));low=ftol(im,sub(N.word(coordinates[2]),N.word(im.W(r+0x54))));high=ftol(im,N.word(coordinates[2])+N.word(im.W(r+0x54)));sin=lambda a:N.word(im.W(0x29899a0+((base['S'](U(a))>>1)&32767)*4));lower=sin(low);upper=sin(high);sampled=(sub(upper,lower)*base['nextRandom'](im)+lower).store();elevation=S16(inv['inverse'](sampled,im.W(0x29a9c48))&65535);correction=ftol(im,(N.word(im.W(r+0x50))*N(randomPhase))*N(-0.000030517578125));azimuth=base['S'](U(ftol(im,N.word(coordinates[1]))-correction));radius=coordinates[0]
 point=base['maths']['transformwords'](im,turn(im,radius,azimuth,elevation),e+0x80)
 for i in range(3):im.W(p+i*4,point[i])
 radius=rangeValue(im,r,0x4c,0x48).store();point=base['maths']['transformwords'](im,turn(im,radius,azimuth,elevation),e+0x80)
 for i in range(3):im.W(p+16+i*4,point[i])
 callback=im.W(e+0x1c4)
 if callback:base['service'](im,callback,[e,r,p])
 for i in range(3):im.W(p+i*4,(N.word(im.W(e+0x19c+i*4))+N.word(im.W(p+i*4))).store())
 for i in range(3):im.W(p+16+i*4,(N.word(im.W(e+0x1a8+i*4))+N.word(im.W(p+16+i*4))).store())
 if S8(im.B(r+0x410))>0:
  index=0
  while True:
   reset(im,e);dest=select32(im,e)
   for i in range(0,32,4):im.W(dest+i,im.W(p+i))
   index+=1;im.W(dest+12,(N(index)*N.word(im.W(r+0x414))+N.word(im.W(dest+12))).store())
   if index>=S8(im.B(r+0x410)):break
 if not im.W(r+0x2a8):base['service'](im,0x600260,[r])
 return p
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x654270,0x64fe20,0x5c0240,0x6e9530,0x5b3690,0x5b3620,0x5c11d0,0x6e6b90,0x5b9d90]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
origService=base['service']
def service(im,address,args):
 result=origService(im,address,args)
 if address==base['CALLBACK'] and base['case'].get('mutateType'):im.B(args[1]+0x2e,7)
 if address==0x600260 and base['case'].get('mutateAngles'):im.W(args[0]+0x50,bits(0.75));im.W(args[0]+0x54,0x80000000)
 return result
base['service']=service
def seed(typ=0,cursor=0,active=32,frames=0):
 c=base['seed'](typ,cursor,active,frames,0x654270);c['writes'] += [word(R+0x50,bits(32768)),word(R+0x54,bits(32768)),word(R+0x5c,bits(16384)),word(R+0x60,bits(32768)),word(R+0x58,bits(3)),word(R+0x418,bits(4)),word(0x296205c,bits(20)),word(EM+0x320,bits(18))];return c
cases=[]
for typ in [0,7]:
 for cursor in [-32768,-33,-13,-1,0,1,11,12,31,32,1023,32767]:
  for active in [-1,0,1,32,1024,32767]:cases.append(seed(typ,cursor,active))
for frames in range(256):cases.append(seed(0,0,8,frames))
for ramp in [0,0x80000000,1,0x80000001,bits(1),bits(2),bits(4),bits(-2)]:
 for clock in [bits(10),bits(18),bits(19),bits(20),bits(22),bits(30)]:c=seed();c['writes'] += [word(R+0x418,ramp),word(0x296205c,clock)];cases.append(c)
for mode in [0,1]:
 for spread in [0,0x80000000,bits(1),bits(0.5),bits(65536),bits(-32768),bits(1e8)]:c=seed();c['writes'] += [word(R+0x50,spread),word(R+0x54,spread),word(0x29a9c48,mode)];cases.append(c)
for feature in ['mutateParticle','mutateEmitter','mutateRecord','publishEarly','mutateType']:
 c=seed(frames=3);c[feature]=True;c['writes'] += [word(EM+0x1c4,base['CALLBACK'])];cases.append(c)
for radius in [0,0x80000000,1,0x80000001,bits(1),bits(-3.75),0x007fffff,0x00800000]:c=seed();c['writes'] += [word(R+0x58,radius)];cases.append(c)
for offset in [0x48,0x4c,0x58,0xa4,0x2a8,0x418]:c=seed();c['writes'] += [word(EM+0x100,R+offset-32)];cases.append(c)
for first in [-32768,-1,0,1,32767]:
 for second in [-32768,-1,0,1,32767]:c=seed();c['writes'] += [half(EM+0x1d0,first),half(EM+0x1d2,second)];cases.append(c)
for advance in [0,0x80000000,bits(0.5),bits(-0.5),bits(65536.5),bits(-32768.5),bits(1e30)]:
 c=seed();c['writes'] += [word(R+0x50,advance),word(R+0x54,advance),half(EM+0x1d0,32767),half(EM+0x1d2,65535)];cases.append(c)
c=seed();c['mutateAngles']=True;c['writes'] += [half(EM+0x1d0,100),half(EM+0x1d2,200)];cases.append(c)
# A post-publication first-half store can modify the second advance operand through ordinary physical aliasing.
c=seed();c['record']=EM+0x1d0-0x54
# Relocate record preparation while keeping emitter/chunk/sine backing unchanged.
c['writes']=[{**p,'address':p['address']+c['record']-R} if R<=p['address']<R+0x440 else p for p in c['writes']];cases.append(c)
c=json.loads(json.dumps(cases[-1]));c['writes'] += [word(EM+0x1c4,0)];cases.append(c)
for spread in [bits(0),bits(1),bits(8192),bits(16384),bits(32768),bits(65536),bits(-16384)]:
 for center in [bits(0),bits(8192),bits(16384),bits(-8192),bits(65536)]:c=seed();c['writes'] += [word(R+0x54,spread),word(R+0x60,center)];cases.append(c)
for state in [0,1,0xffffffff,0x80000000,0x007fffff,0x12345678]:c=seed();c['writes'] += [word(0x810900,state),word(R+0x54,bits(16384)),word(R+0x60,0)];cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 base['case']=c;base['trace']=[];im=Image(c)
 try:result=initialize(im,c)
 except (ValueError,ZeroDivisionError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 modelTrace=base['trace'][:];base['trace']=[];base['nativeTrace']=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:actualResult=n.call(0x654270,[c['emitter'],c['record'],c['time']],count=2000000)
 except Exception as ex:errors.append(dict(case=i,stage='native',error=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or base['nativeTrace']!=modelTrace or actualResult!=result:
  errors.append(dict(case=i,actual=actual,model=im.hash(),nativeTrace=base['nativeTrace'],modelTrace=modelTrace,actualResult=actualResult,modelResult=result))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual,trace=base['nativeTrace'],result=actualResult);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=['selected attribute callback','0x600260 descriptor publication'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded,runtimeSineSha256=hashlib.sha256((B/'references/native-animation-sine-table.f32').read_bytes()).hexdigest())
(B/'reports/world-phase45-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase45-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=base['rot']['common'],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
