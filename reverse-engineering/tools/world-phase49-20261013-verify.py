import json,hashlib,struct,base64,gzip,time,math
from pathlib import Path
def load(num,marker):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);x={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index(marker)],str(p),'exec'),x);return x
base=load(37,'\ncases=[]');roots=load(48,'\nfrom unicorn import UC_HOOK_CODE');links=load(24,'\ncases=[]')
n=base['n'];B=base['B'];D=n.DATA;EM=base['EM'];R=base['R'];OUT=base['CHUNKS'];RETURN=D+0x12000;NODES=D+0x14000;U=base['U'];F=base['F'];N=base['N'];bits=base['bits'];patch=base['patch'];word=base['word'];half=base['half'];byte=base['byte'];S16=base['S16'];S=base['S'];Image=base['Image'];REGIONS=base['REGIONS']+[(0x2962000,0x400,0),(0x2947b00,0x200,0),(0x2923100,0x400,0),(0x292fa00,0x600,0)];base['rot']['REGIONS']=REGIONS
node=lambda im:im.W(im.W(0x2923198)+im.W(0x2947b70)*4)
def initialize(im,c):
 e=c['emitter'];r=c['record'];t=c['time']
 if S16(im.H(e+0x18a))>=S16(im.H(e+0x186)):im.H(e+0x18a,0)
 if im.B(r+0x2e)==7:return 0
 cursor=S16(im.H(e+0x18a));bank=abs(cursor)//32*(1 if cursor>=0 else -1);chunk=im.W(e+0x100+bank*4);p=U(chunk+(cursor-bank*32+1)*32);im.W(p+12,t);im.W(e+0x324,t);life=im.W(r+0xa4);im.W(p+28,((life&0x80000000)|0x7f800000) if not life&0x7fffffff else N(base['rot']['quant'](64/N.word(life).v,64),(life&0x80000000)!=0).store())
 point=base['maths']['transformwords'](im,[base['randomAxis'](im,r,0x58+i*4) for i in range(3)],e+0x80)
 for i in range(3):im.W(p+i*4,point[i])
 point=base['maths']['transformwords'](im,[base['randomAxis'](im,r,0x4c),base['randomAxis'](im,r,0x50,True),base['randomAxis'](im,r,0x54)],e+0x80)
 for i in range(3):im.W(p+16+i*4,point[i])
 displacement=(N.word(im.W(p+4))+N(-N.word(im.W(e+0x2e0)).v,not N.word(im.W(e+0x2e0)).neg)).store();ok,first,second,_=roots['values'](im.W(r+0xa0),im.W(p+20),displacement)
 if ok:
  maximum=first if F(first)>=F(second) else second
  if F(maximum)>0 and F(maximum)<F(im.W(r+0xa4)):
   assert not im.W(0x2962058);im.W(0x2962058,1);limit=S(im.W(0x8108e8)+im.W(0x8108ec));count=im.W(0x2947b70)
   if S(count)<limit:
    initial=im.W(im.W(0x2923198)+count*4);im.W(initial,chunk);im.W(node(im)+4,(N.word(maximum)+N.word(t)).store());im.W(node(im)+8,5);im.W(node(im)+12,0);im.H(node(im)+28,im.H(e+0x182));im.H(node(im)+32,0);im.H(node(im)+30,0);im.W(node(im)+36,im.W(e+0x2e0));im.W(node(im)+40,im.W(e+0x2e4));cursor=S16(im.H(e+0x18a));bank=abs(cursor)//32*(1 if cursor>=0 else -1);im.W(node(im)+20,cursor-bank*32);im.W(node(im)+24,maximum);links['timed'](im,node(im),0x292fbfc);im.W(0x2947b70,im.W(0x2947b70)+1)
   im.W(0x2962058,0)
 callback=im.W(e+0x1c4)
 if callback:base['service'](im,callback,[e,r,p])
 im.H(e+0x18a,im.H(e+0x18a)+1)
 for i in range(3):im.W(p+i*4,(N.word(im.W(e+0x19c+i*4))+N.word(im.W(p+i*4))).store())
 for i in range(3):im.W(p+16+i*4,(N.word(im.W(e+0x1a8+i*4))+N.word(im.W(p+16+i*4))).store())
 if not im.W(r+0x2a8):base['service'](im,0x600260,[r])
 return p
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x682290,0x653840,0x653940,0x6551d0,0x5c11d0,0x5b9d90,0x5c0240,0x6e9530]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(typ=0,cursor=0,active=32):
 c=base['seed'](typ,cursor,active,0,0x682290);c['writes'] += [word(R+0xa0,bits(0.25)),word(EM+0x2e0,bits(1)),word(EM+0x2e4,bits(0.9)),half(EM+0x182,1),word(0x8108e8,32),word(0x8108ec,32),word(0x2962058,0),word(0x2947b70,0),word(0x2923198,RETURN),word(0x292fbfc,0)]
 for i in range(-4,132):c['writes'] += [word(RETURN+i*4,NODES+(i+4)*0x40),word(NODES+(i+4)*0x40,0),word(NODES+(i+4)*0x40+16,0)]
 return c
cases=[]
for typ in [0,7]:
 for cursor in [-32768,-33,-1,0,1,31,32,1023,32767]:
  for active in [-1,0,1,32,1024,32767]:cases.append(seed(typ,cursor,active))
for acceleration in [0,0x80000000,bits(0.25),bits(1),bits(-1),bits(4)]:
 for velocity in [bits(-2),0,0x80000000,bits(0.5),bits(1),bits(4)]:
  for ground in [bits(-1),0,bits(1),bits(4)]:
   c=seed();c['writes'] += [word(R+0xa0,acceleration),patch(R+0x58,struct.pack('<3I',0,0,0)),patch(R+0x4c,struct.pack('<3I',0,0,0)),word(R+0x48,velocity),word(EM+0x2e0,ground)];cases.append(c)
for count in [-1,0,1,63,64,65]:
 for cap in [-1,0,1,32]:
  c=seed();c['writes'] += [word(0x2947b70,count),word(0x8108e8,cap),word(0x8108ec,0),patch(R+0x58,struct.pack('<3I',0,0,0)),patch(R+0x4c,struct.pack('<3I',0,0,0)),word(R+0x48,bits(1))];cases.append(c)
for feature in ['mutateParticle','mutateEmitter','mutateRecord','publishEarly']:
 c=seed();c[feature]=True;c['writes'] += [word(EM+0x1c4,base['CALLBACK'])];cases.append(c)
for alias in ['count-tag','cursor-ID','lock-next']:
 c=seed();c['writes'] += [patch(R+0x58,struct.pack('<3I',0,0,0)),patch(R+0x4c,struct.pack('<3I',0,0,0)),word(R+0x48,bits(1))]
 target=0x2947b70-8 if alias=='count-tag' else EM+0x18a-28 if alias=='cursor-ID' else 0x2962058-16;c['writes'] += [word(RETURN,target)];cases.append(c)
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 base['case']=c;base['trace']=[];im=Image(c)
 try:result=initialize(im,c)
 except (ValueError,OverflowError,ZeroDivisionError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 modelTrace=base['trace'][:];base['trace']=[];base['nativeTrace']=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:actualResult=n.call(0x682290,[c['emitter'],c['record'],c['time']],count=2000000)
 except Exception as ex:errors.append(dict(case=i,stage='native',error=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or base['nativeTrace']!=modelTrace or actualResult!=result:
  errors.append(dict(case=i,actual=actual,model=im.hash(),nativeTrace=base['nativeTrace'],modelTrace=modelTrace,actualResult=actualResult,modelResult=result))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual,trace=base['nativeTrace'],result=actualResult);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*3,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=['selected attribute callback','0x600260 descriptor publication'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase49-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase49-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
