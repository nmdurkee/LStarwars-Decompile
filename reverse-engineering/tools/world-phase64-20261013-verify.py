import json,hashlib,struct,base64,gzip,random,time,ast
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;REF=D+0x1000;FIFO=D+0x2000;TABLE=D+0x3000;EM=D+0x4000;R=D+0x18000;RETURN=D+0x1d000;NODES=D+0x1e000;PACKETS=D+0x22000;CHUNKS=D+0x10000;REGIONS=[(D,0x40000,167),(0x2961f00,0x400,0),(0x2921100,0x200,0),(0x2947b70,4,0),(0x2923180,0x80,0),(0x292fa00,0x600,0),(0x8108e8,8,0),(0x2947d00,0x200,0),(0x2948e00,0x200,0),(0x29899a0,0x20000,0)];rot['REGIONS']=REGIONS;rot['common']=[rot['patch'](0x29899a0,(B/'references/native-animation-sine-table.f32').read_bytes())];U=rot['U'];F=rot['F'];bits=rot['bits'];word=rot['word'];patch=rot['patch'];N=rot['N'];S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0];S16=lambda x:x-65536 if x&32768 else x;S8=lambda x:x-256 if x&128 else x
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
def functions(num):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);t=ast.parse(p.read_text());ctx=dict(U=U,F=F,S=S);exec(compile(ast.Module(body=[x for x in t.body if isinstance(x,ast.FunctionDef)],type_ignores=[]),str(p),'exec'),ctx);return ctx
links=functions(24);unlinks=functions(26)
from fractions import Fraction
TimeTenth=Fraction.from_float(0.10000000149011612)
def recycle(im,node):
 count=im.W(0x2947b70);table=im.W(0x2923198);count=U(count-1);im.W(0x2947b70,count);im.W(table+count*4,node)
def expire(im,node,alternate):
 at=0x2947d84 if alternate else 0x2948e98;table=im.W(0x29211fc if alternate else 0x2921200);count=U(im.W(at)-1);im.W(at,count);im.W(table+count*4,im.W(node))
 for i in range(12 if alternate else 32):im.W(im.W(node)+0x2c+i*32,0x501502f9);im.W(im.W(node)+0x3c+i*32,0x43000000)
 recycle(im,node);im.W(node,0)
def advance(im,node,head):im.W(node+4,(N.word(im.W(node+4))+N(TimeTenth)).store());links['timed'](im,node,head)
def process(im,c):
 bank=c['bank'];clock=F(im.W(0x2962060 if bank==1 else 0x296205c));head=U(0x292fbfc+bank*4);node=im.W(head);assert not im.W(0x2962058);im.W(0x2962058,1);iterations=0
 while node and F(im.W(node+4))<=clock:
  iterations+=1
  if iterations>1000:raise ValueError('unbounded staged time advance')
  im.W(head,im.W(node+16));tag=im.W(node+8);im.W(node+16,0)
  if tag in [3,8]:expire(im,node,tag==8)
  elif tag in [2,9]:links['commands'](im,node,1);im.W(node+8,3 if tag==2 else 8);advance(im,node,head)
  elif tag in [0,7]:
   capacity=S(im.W(0x8108e8)+im.W(0x8108ec))
   if capacity>0:
    packets=im.W(0x2961fec);chunk=im.W(node)
    for i in range(capacity):
     packet=packets+i*100
     if im.W(packet)==chunk:
      record=im.W(packet+4);bank=S8(im.B(record+0x2f1));unlinks['priority'](im,packet,U(0x292fd30+bank*4));offset=i*100;im.W(im.W(0x2961fec)+offset,0);im.W(im.W(0x2961fec)+offset+4,0);im.W(im.W(0x2961fec)+offset+8,0);break
   tag=im.W(node+8);im.W(node+4,(N.word(im.W(node+4))+N(TimeTenth)).store())
   if tag==0:im.W(node+8,2)
   elif tag==7:im.W(node+8,9)
   links['timed'](im,node,head)
  elif tag==1:retire(im,node,head)
  elif tag==5:quadraticBounce(im,node,head)
  elif tag==6:planeBounce(im,node)
  node=im.W(head)
 im.W(0x2962058,0)
def owner(im,node):return im.W(node+12)
def addhalf(im,at,amount):im.H(at,im.H(at)+amount)
def retire(im,node,head):
 e=owner(im,node);physical=S16(im.H(e+0x182));record=im.W(im.W(0x296209c)+physical*4);count=S16(im.H(e+0x180));selected=0
 if count>0:
  chunk=im.W(node);cursor=e+0x100;i=0
  while i<S16(im.H(owner(im,node)+0x180)):
   if im.W(cursor)==chunk:selected=i;break
   i+=1;cursor+=4
 index=selected
 if index<count-1:
  offset=selected*4+0x100
  while index<S16(im.H(owner(im,node)+0x180))-1:e=owner(im,node);im.W(e+offset,im.W(e+offset+4));index+=1;offset+=4
 e=owner(im,node);im.W(e+0xfc+S16(im.H(e+0x180))*4,0);addhalf(im,owner(im,node)+0x180,-1);addhalf(im,owner(im,node)+0x18c,-1);addhalf(im,owner(im,node)+0x188,-1);e=owner(im,node)
 if S16(im.H(e+0x180))<=0:im.H(e+0x186,0);im.H(owner(im,node)+0x18e,0)
 else:
  unit=12 if im.B(record+0x2e)==7 else 32;addhalf(im,e+0x186,-unit);addhalf(im,owner(im,node)+0x18e,-unit);e=owner(im,node)
  if S16(im.H(e+0x18a))>(selected+1)*unit:addhalf(im,e+0x18a,-unit)
 e=owner(im,node)
 if S16(im.H(e+0x180))>0:links['commands'](im,e+0x100,S16(im.H(e+0x180)))
 else:
  for i in range(8):
   at=record+0x3d0+i*2;id=im.H(at)
   if id!=65535 and U(im.W(0x29620a4)+S16(id)*0x330)==owner(im,node):im.H(owner(im,node)+0x182,0);im.H(owner(im,node)+0x32a,65535);cursor=im.W(0x29211e8);fifo=im.W(0x2962084);cursor=U(cursor-1);im.W(0x29211e8,cursor);im.H(fifo+cursor*2,im.H(at));im.H(at,65535)
  im.W(owner(im,node)+0x100,0)
 if selected==0:
  capacity=S(im.W(0x8108e8)+im.W(0x8108ec))
  if capacity>0:
   packets=im.W(0x2961fec);chunk=im.W(node)
   for i in range(capacity):
    packet=packets+i*100
    if im.W(packet)==chunk:
     offset=i*100;im.W(packet,im.W(owner(im,node)+0x100))
     if S16(im.H(owner(im,node)+0x180))==0:bank=S8(im.B(record+0x2f1));unlinks['priority'](im,im.W(0x2961fec)+offset,U(0x292fd30+bank*4));im.W(im.W(0x2961fec)+offset+4,0);im.W(im.W(0x2961fec)+offset+8,0)
     break
 im.W(node+4,(N.word(im.W(node+4))+N(TimeTenth)).store());im.W(node+8,9 if im.B(record+0x2e)==7 else 2);links['timed'](im,node,head)
import math,ast
q=Path(__file__).with_name('world-phase48-20261013-verify.py');t=ast.parse(q.read_text());roots=dict(N=N,rot=rot,F=F,bits=bits,math=math);exec(compile(ast.Module(body=[x for x in t.body if isinstance(x,ast.FunctionDef)],type_ignores=[]),str(q),'exec'),roots)
def neg62(a):return N(-a.v,not a.neg)
def sub62(a,b):return a+neg62(b)
def quadraticBounce(im,node,head):
 record=im.W(im.W(0x296209c)+S16(im.H(node+0x1c))*4);p=U(im.W(node)+U(im.W(node+0x14)+1)*32);old=(N.word(im.W(p+0x14))*N.word(im.W(node+0x18))).store();product=N.word(im.W(record+0xa0))*N.word(im.W(node+0x18));doubled=product+product;sum=(N.word(im.W(p+0x14))+doubled).store();reflected=(neg62(N.word(im.W(node+0x28)))*N.word(sum)).store();velocity=sub62(N.word(reflected),doubled).store();im.W(p+0x14,velocity);newProduct=(N.word(velocity)*N.word(im.W(node+0x18))).store();y=sub62(N.word(im.W(p+4)),sub62(N.word(newProduct),N.word(old))).store();im.W(p+4,y);displacement=sub62(N.word(y),N.word(im.W(node+0x24))).store();ok,first,second,_=roots['values'](im.W(record+0xa0),im.W(p+0x14),displacement)
 if ok:
  maximum=first if F(first)>F(second) else second
  if F(maximum)<F(im.W(record+0xa4)):
   delta=sub62(N.word(maximum),N.word(im.W(node+0x18))).store();im.W(node+0x18,maximum)
   if F(delta)>F(0x3ca3d70a):im.W(node+4,(N.word(delta)+N.word(im.W(node+4))).store());links['timed'](im,node,head);return
 recycle(im,node);im.W(node,0)
def normal62(im,angle):
 sine=N.word(im.W(0x29899a0+((angle>>1)&32767)*4));cosine=N.word(im.W(0x29899a0+(((angle+16384)>>1)&32767)*4));zero=N(0);one=N(1);return [(sine*zero+cosine*one).store(),0,sub62(zero*cosine,one*sine).store()]
def planeBounce(im,node):
 p=U(im.W(node)+U(im.W(node+0x14)+1)*32);normal=normal62(im,S16(im.H(node+0x20)));dot=(N.word(im.W(p+0x18))*N.word(normal[2])+N.word(im.W(p+0x10))*N.word(normal[0])).store();impulse=neg62(N.word(dot)*(N.word(im.W(node+0x28))+N(1))).store();oldX=(N.word(im.W(p+0x10))*N.word(im.W(node+0x18))).store();oldZ=(N.word(im.W(p+0x18))*N.word(im.W(node+0x18))).store();vx=(N.word(im.W(p+0x10))+N.word(impulse)*N.word(normal[0])).store();im.W(p+0x10,vx);vz=(N.word(impulse)*N.word(normal[2])+N.word(im.W(p+0x18))).store();im.W(p+0x18,vz);newZ=(N.word(vz)*N.word(im.W(node+0x18))).store();newX=(N.word(im.W(p+0x10))*N.word(im.W(node+0x18))).store();im.W(p,sub62(N.word(im.W(p)),sub62(N.word(newX),N.word(oldX))).store());im.W(p+8,sub62(N.word(im.W(p+8)),sub62(N.word(newZ),N.word(oldZ))).store());recycle(im,node);im.W(node,0)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x657110,0x5ffea0,0x654ea0,0x6551d0,0x653840,0x5c0240,0x5b3620]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
NODES=D+0x1000;CHUNKS=D+0x10000;RETURN=D+0x3000;FREE=D+0x4000;ALT=D+0x5000;PACKETS=D+0x6000;R=D+0x8000
def seed(tag=0,bank=0,length=1,clock=10):
 c=dict(bank=bank,writes=[word(0x292fbfc,NODES if bank==0 and length else 0),word(0x292fc00,NODES if bank==1 and length else 0),word(0x296205c,bits(clock)),word(0x2962060,bits(clock)),word(0x2962058,0),word(0x2947b70,32),word(0x2923198,RETURN),word(0x2948e98,32),word(0x2947d84,32),word(0x2921200,FREE),word(0x29211fc,ALT),word(0x8108e8,8),word(0x8108ec,8),word(0x2961fec,PACKETS),word(0x292fd30,PACKETS),word(0x292fd40,0)])
 for i in range(8):c['writes'] += [word(NODES+i*0x40,CHUNKS+i*0x500),word(NODES+i*0x40+4,bits(i/10)),word(NODES+i*0x40+8,tag),word(NODES+i*0x40+16,NODES+(i+1)*0x40 if i+1<length else 0)]
 for i in range(16):c['writes'] += [word(PACKETS+i*100,CHUNKS+i*0x500),word(PACKETS+i*100+4,R),word(PACKETS+i*100+8,0),word(PACKETS+i*100+0x58,PACKETS+(i-1)*100 if i else 0),word(PACKETS+i*100+0x5c,PACKETS+(i+1)*100 if i+1<16 else 0)]
 c['writes'] += [byte(R+0x2f1,0)]
 return c
EM=D+0x9000;TABLE=D+0x2000;FIFO=D+0x3800
baseSeed=seed
def attach(count=2,index=0,typ=0,bank=0,cursor=0,clock=0):
 c=baseSeed(1,bank,1,clock);c['writes'] += [word(NODES+12,EM),word(NODES,CHUNKS+index*0x500 if index>=0 else CHUNKS+0x9000),word(0x296209c,TABLE),word(TABLE+4,R),word(0x29620a4,EM-0x330),half(EM+0x182,1),half(EM+0x180,count),half(EM+0x18c,count),half(EM+0x188,count),half(EM+0x186,count*(12 if typ==7 else 32)),half(EM+0x18e,count*(12 if typ==7 else 32)),half(EM+0x18a,cursor),half(EM+0x32a,4),word(0x29211e8,8),word(0x2962084,FIFO),byte(R+0x2e,typ),byte(R+0x2f1,4 if bank else 0),word(0x292fd40,0),word(0x292fd30,0)]
 for i in range(8):c['writes'] += [word(EM+0x100+i*4,CHUNKS+i*0x500),half(R+0x3d0+i*2,1 if i==0 else 65535)]
 return c
def bounce(tag=5,acceleration=.25,vy=1,height=1,time=.5,coefficient=.5,angle=8192,bank=0,clock=0):
 c=baseSeed(tag,bank,1,clock);c['writes'] += [word(0x296209c,TABLE),word(TABLE+4,R),half(NODES+0x1c,1),word(NODES+0x14,0),word(NODES+0x18,bits(time)),word(NODES+0x24,bits(0)),word(NODES+0x28,bits(coefficient)),half(NODES+0x20,angle),word(R+0xa0,bits(acceleration)),word(R+0xa4,bits(10)),patch(CHUNKS+32,struct.pack('<8f',1.25,height,-2.5,0,.75,vy,-1.25,4))];return c
cases=[bounce(5,a,vy,y,t,k) for a in [0,-1,.25,1,4] for vy in [-8,-1,0,.1,1,8] for y in [-1,0,1,5] for t in [0,.1,.5,1] for k in [0,.25,1]]
for angle in [-32768,-24576,-16384,-8192,-1,0,1,8192,16384,24576,32767]:
 for coefficient in [-1,0,.25,.5,1,2]:
  for sampledTime in [0,.1,.5,1]:cases.append(bounce(6,coefficient=coefficient,angle=angle,time=sampledTime))
rng=random.Random(2026101362)
for i in range(256):
 c=bounce(rng.choice([5,6]),rng.uniform(-4,4),rng.uniform(-8,8),rng.uniform(-4,4),rng.uniform(-1,2),rng.uniform(-1,2),rng.randrange(-32768,32768),rng.randrange(2));c['writes'].append(word(R+0xa4,bits(rng.uniform(.01,20))));cases.append(c)
for bounceTag in [5,6]:
 for nextTag in [0,1,2,3,7,8,9,10]:
  for clock in [0,1]:
   a=attach(2,1,0,0,64,clock);c=bounce(bounceTag,clock=clock);c['writes']=a['writes']+c['writes']+[word(NODES+16,NODES+0x40),word(NODES+0x40,CHUNKS+0x500),word(NODES+0x40+4,bits(0)),word(NODES+0x40+8,nextTag),word(NODES+0x40+12,EM),word(NODES+0x40+16,0)];cases.append(c)
# New X velocity overwrites the live bounce-time operand before later Z/new-product reads.
c=bounce(6,time=.5,angle=8192);c['writes'] += [word(NODES,NODES+8-32)];cases.append(c)
c=bounce(5,time=.5,coefficient=.5);c['writes'] += [word(NODES,NODES+4-32)];cases.append(c)
# Retained previous prepared fixtures are independently recomputed here; no edits to sealed inputs.
for previous in [60,61]:
 prior=json.loads(gzip.decompress((B/('reports/world-phase%d-20261013-vectors.json.gz'%previous)).read_bytes()))
 cases.extend(prior['cases'])
for tag in [0,2,7,9]:
 for bank in [0,1]:
  c=baseSeed(tag,bank,1,-0.10000000149011612);c['writes'].append(word(NODES+4,0xbdcccccd));c['literalCounterexample']=True;cases.append(c)
for bank in [0,1]:
 c=attach(2,1,0,bank,64,-0.10000000149011612);c['writes'].append(word(NODES+4,0xbdcccccd));c['literalCounterexample']=True;cases.append(c)
rows=[];errors=[];excluded=[];literalDifferences=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 try:process(im,c)
 except (ValueError,OverflowError) as ex:excluded.append(dict(case=i,reason=str(ex)));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x657110,[c['bank']],count=2000000)
 except Exception as ex:errors.append(dict(case=i,nativeError=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:10]))
  break
 if c.get('literalCounterexample'):
  TimeTenth=Fraction.from_float(0.1);old=Image(c);process(old,c);TimeTenth=Fraction.from_float(0.10000000149011612)
  if old.hash()!=actual:literalDifferences.append(dict(case=i,nativeSha256=actual,oldTrueDoubleModelSha256=old.hash(),nativeDeadlineWord=hex(n.unpack('<I',NODES+4)[0]),oldTrueDoubleDeadlineWord=hex(old.W(NODES+4))))
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded,oldLiteralCounterexamples=literalDifferences,exactTenthDoubleHex="000000a09999b93f")
(B/'reports/world-phase64-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase64-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],common=rot['common'],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
