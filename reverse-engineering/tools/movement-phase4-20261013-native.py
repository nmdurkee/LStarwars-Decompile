"""GoToOrigin, FollowPath and formation intent using original x86 dependencies.
Callbacks are explicit; no computational function is replaced. Finite own-state oracle.
"""
import importlib.util,json,struct,itertools,hashlib,gzip,math,random,base64
from fractions import Fraction
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP
n=m.NativeX86();B=m.BASE;D=n.DATA;C=D;R=D+0x1000;P=D+0x2000;W=D+0x3000;S=D+0x4000;F=D+0x5000;O=D+0x6000;A=D+0x7000;T=D+0x8000;SIZE=0x10000;TOKEN=n.STOP+0x100;ORIGIN=n.STOP+0x110
SIN=0x29899a0;table=[struct.unpack('<f',struct.pack('<f',math.sin(i*2*math.pi/32768)))[0]for i in range(32768)];n.write(SIN,struct.pack('<32768f',*table))
events=[];opt={};vectors=[];groups={};errors=[];assertions=0
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
val=lambda v:struct.unpack('<f',struct.pack('<I',v))[0]
def quant(v,p):
 if not v:return Fraction(0)
 sign=-1 if v<0 else 1;nn=abs(v.numerator);dd=v.denominator;e=nn.bit_length()-dd.bit_length()
 if(nn<dd<<e if e>=0 else nn<<-e<dd):e-=1
 step=e-(p-1);a=nn<<-step if step<0 else nn;b=dd<<step if step>=0 else dd;q,r=divmod(a,b)
 if 2*r>b or(2*r==b and q&1):q+=1
 return sign*(Fraction(q<<step)if step>=0 else Fraction(q,1<<-step))
class X:
 def __init__(self,v,sign=False):self.v=Fraction(v);self.neg=self.v<0 or(not self.v and sign)
 @classmethod
 def fl(cls,v):return cls(float(v),bool(bits(v)&0x80000000))
 def __add__(self,b):return X(quant(self.v+b.v,64),self.neg and b.neg)
 def __neg__(self):return X(-self.v,not self.neg)
 def __sub__(self,b):return self+-b
 def __mul__(self,b):return X(quant(self.v*b.v,64),self.neg!=b.neg)
 def flstore(self):return val(0x80000000 if self.neg else 0)if not self.v else f32(float(quant(self.v,24)))
 def dblstore(self):return float(quant(self.v,53))
def readstr(p):
 a=bytearray()
 while True:
  c=n.read(p,1)[0];p+=1
  if c==0:return a.decode('ascii')
  a.append(c)
def ret(mu,v):
 sp=mu.reg_read(UC_X86_REG_ESP);to=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,v&0xffffffff);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,to)
def hook(mu,a,s,u):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==TOKEN:
  txt=readstr(n.unpack('<I',sp+4)[0]);mode={'walk':17,'run':34}.get(txt.lower());events.append(['token',txt,mode is not None])
  if mode is not None:n.pack('<B',n.unpack('<I',sp+8)[0],mode)
  ret(mu,int(mode is not None))
 elif a==ORIGIN:events.append(['origin',opt.get('origin',False)]);ret(mu,O if opt.get('origin')else 0)
 elif a==0x51d130:
  callback=n.unpack('<I',sp+4)[0];events.append(['schedule',hex(callback)])
  if opt.get('mutateFormation'):n.pack('<f',F+0x128,2.125);n.pack('<B',F+0x50,12)
  ret(mu,0)
n.mu.hook_add(UC_HOOK_CODE,hook)
def setup(meta,tokens):
 opt.clear();opt.update(meta);events.clear();n.write(D,bytes([0xa5])*SIZE)
 # Entire retained memory image, including pointers, preserves reference/object distinctions.
 n.pack('<I',C+0xd0,0 if meta.get('missing')=='reference'else R);n.pack('<I',R,0 if meta.get('missing')=='object'else D+0x9000)
 n.pack('<I',C+0x158,0 if meta.get('missing')=='path'else D+0xa000);n.pack('<I',C+0x15c,0 if meta.get('missing')=='node'else D+0xb000)
 n.pack('<I',C+0x144,F if meta.get('formation')else 0);n.pack('<I',F,R if meta.get('owner')else R+0x400);n.pack('<B',F+6,meta.get('count',4));n.pack('<B',F+8,meta.get('formationFlags8',0));n.pack('<B',F+0x50,meta.get('formationFlags',8));n.pack('<f',F+0x128,meta.get('spacing',1.25))
 n.pack('<I',C+0x1e8,meta.get('flags',0x80000003));n.pack('<B',C+0x149,meta.get('slot',1));n.pack('<B',C+0x14a,meta.get('row',0));n.pack('<B',C+0x13f,9)
 for j in range(4):
  q=F+0x54+j*0x34;n.pack('<6I',q,*[(0x7fc00001+j*16+k)&0xffffffff for k in range(6)]);n.pack('<3f',q+0x18,j+4.125,j-3.75,j*.5-1.25);n.pack('<I',q+0x24,meta.get('heading',12345)+j*16)
 n.pack('<f',F+0x128,meta.get('spacing',1.25))
 n.pack('<3f',C+0x14c,*meta.get('position',[4.,5.,6.]));n.pack('<f',C+0x180,meta.get('goal',.5));n.pack('<f',R+0x22c,meta.get('speed',.75));n.pack('<I',R+0x1f8,meta.get('refFlags',0x400));n.pack('<B',C+0x138,meta.get('spawn',0));n.pack('<I',W+0x18,S)
 n.pack('<3f',S+0x20,*meta.get('spawnPosition',[4.125,5.25,6.5]));n.pack('<I',S+0x2c,meta.get('heading',12345));n.pack('<6I',S+0x30,*[0x7fc00001+k for k in range(6)])
 n.pack('<3f',O,*meta.get('originPosition',[8.125,-2.5,1.375]));n.pack('<f',P+0x9c,meta.get('wait',0.));n.pack('<B',P+0x69,meta.get('xz',0));n.pack('<I',P+4,0)
 n.pack('<I',0x95e5d4,meta.get('seed',123));n.pack('<f',0x801c6c,.10000000149011612);n.pack('<I',0x9238b0,TOKEN if meta.get('tokenCallback',True)else 0);n.pack('<I',0x923908,ORIGIN if meta.get('originCallback',True)else 0);n.pack('<I',0x9238c0,0)
 cur=T
 for i,t in enumerate(tokens):n.write(cur,t.encode()+b'\0');n.pack('<I',A+4*i,cur);cur+=len(t)+4
 return bytearray(n.read(D,SIZE))
def model(image,kind,meta,tokens,first,delta):
 ev=[];seed=meta.get('seed',123)
 def u(off):return struct.unpack_from('<I',image,off)[0]
 def b(off):return image[off]
 def fl(off):return val(u(off))
 def setu(off,v):struct.pack_into('<I',image,off,v&0xffffffff)
 def setf(off,v):setu(off,bits(v))
 def v(off):return [fl(off+i*4)for i in range(3)]
 def sv(off,vec):
  for i,x in enumerate(vec):setf(off+i*4,x)
 def rot(vec,h):
  si=table[(h>>1)&32767];co=table[((h+0x4000)>>1)&32767];x,y,z=map(X.fl,vec)
  return[(X.fl(si)*z+X.fl(co)*x).flstore(),vec[1],(z*X.fl(co)-x*X.fl(si)).flstore()]
 def add(a,bv):return[(X.fl(x)+X.fl(y)).flstore()for x,y in zip(a,bv)]
 def formation():
  fo=u(0x144)-D;ix=b(0x14a)
  if b(fo+6)<=ix:return
  row=fo+0x54+ix*0x34;spacing=fl(fo+0x128);slot=b(0x149)
  if b(0x1eb)&1:x=0. if b(fo+8)&1 else -(X.fl(spacing)*X.fl(.5)).flstore()
  else:
   x=(X.fl(spacing)*X.fl((slot+1)//2)).flstore()
   if slot&1:x=-x
  if b(fo+0x50)&4:x=-x
  point=add(rot([x,0.,0.],u(row+0x24)),v(row+0x18));sv(0x1b4,point)
  image[0x1cc:0x1e4]=image[row:row+24];setu(0x1c0,0);setu(0x1c4,0);mode=1 if b(fo+0x50)&8 else 5;setu(0x1e8,((u(0x1e8)|8)&~7)|mode)
  sv(0x78,add(rot([0.,0.,100.],u(row+0x24)),v(row+0x18)));setu(0x1e4,C+0x78)
 def schedule(callback):
  ev.append(['schedule',hex(callback)])
  if meta.get('mutateFormation'):setf(F-D+0x128,2.125);image[F-D+0x50]=12
 def intent(point,words,goal):
  if u(0x144) and b(u(0x144)-D+0x50)&8:
   if u(u(0x144)-D)==u(0xd0):schedule(0x51cbc0)
   formation();return
  sv(0x1b4,point);image[0x1cc:0x1e4]=words;setu(0x1c0,0);setf(0x1c4,goal);setu(0x1e8,(u(0x1e8)&~7)|1)
 def draw():
  nonlocal seed
  seed=(seed*0x19660d+0x3c6ef35f)&0xffffffff;return(seed&0x7fffff)/8388608
 def evaluate(t):
  # This oracle domain is the original fast numeric parser only. Actual native expression executes.
  sign=-1 if t.startswith('-')else 1;t=t[1:]if t.startswith(('-','+'))else t;whole=0.;dec=0.;div=1.;after=False
  for ch in t:
   if ch=='.':after=True;continue
   if ch<'0'or ch>'9':break
   if after:dec=f32(dec*10+int(ch));div=f32(div*10)
   else:whole=f32(whole*10+int(ch))
  return f32(sign*(whole+f32(dec/div)))
 def token(t):
  if not meta.get('tokenCallback',True):return False
  mode={'walk':17,'run':34}.get(t.lower());ev.append(['token',t,mode is not None])
  if mode is not None:image[0x13f]=mode
  return mode is not None
 if kind=='formation':formation();return None,seed,ev
 missing=meta.get('missing')
 if missing in ['creature','reference']:return 1,seed,ev
 if kind=='follow':
  if not u(R-D):return 1,seed,ev
  if not u(0x158)or not u(0x15c):return 0,seed,ev
 else:
  if not u(0x158)or not u(0x15c)or not(u(R-D+0x1f8)&0x400)or b(0x138)==255:return 1,seed,ev
  origin=v(O-D)if meta.get('origin')and meta.get('originCallback',True)else v(S-D+0x20)
  if meta.get('originCallback',True):ev.append(['origin',bool(meta.get('origin',False))])
 mn=mx=0.
 if first:
  if kind=='origin':setf(0x180,.2)
  else:setu(0x188,0)
  for t in tokens:
   if token(t):continue
   lo=t.lower()
   keys=['waittime','mintime','maxtime']if kind=='origin'else['mintime','maxtime']
   key=next((k for k in keys if k in lo),None)
   if key:
    x=evaluate(t[lo.index(key)+len(key)+1:])
    if key=='mintime':mn=x
    elif key=='maxtime':mx=x
    else:setf(P-D+0x9c,x)
   elif kind=='origin'and lo=='xz_rangecheck':image[P-D+0x69]=1
   elif kind=='origin':
    key='goalrange';txt=t[lo.index(key)+10:]if key in lo else t;setf(0x180,evaluate(txt))
   else:setf(P-D+0x9c,evaluate(t))
  if kind=='origin'and fl(P-D+0x9c)==0:
   setf(P-D+0x9c,.01 if mx<=mn else (X.fl(draw())*(X.fl(mx)-X.fl(mn))+X.fl(mn)).flstore())
  elif kind=='follow'and mn<mx:
   a=(X.fl(1)-X.fl(draw()))*X.fl(mn);stored=a.dblstore();setf(P-D+0x9c,(X.fl(draw())*X.fl(mx)+X(stored)).flstore())
 if kind=='follow':
  fo=u(0x144)
  if not fo or not(b(fo-D+0x50)&8):setu(0x1c0,0);setf(0x1c4,fl(0x180));setu(0x1e8,(u(0x1e8)&~3)|4)
  else:
   if u(fo-D)==u(0xd0):schedule(0x51c6a0)
   formation()
  wait=fl(P-D+0x9c)
  if wait>0:
   wait=(X.fl(wait)-X.fl(delta)).flstore();setf(P-D+0x9c,wait);return int(wait<=0),seed,ev
  return 0,seed,ev
 intent(origin,image[S-D+0x30:S-D+0x48],fl(0x180))
 if first:sv(P-D+0x78,add(rot([0.,0.,1.],u(S-D+0x2c)),origin));return 0,seed,ev
 diff=[(X.fl(a)-X.fl(bv)).flstore()for a,bv in zip(v(0x14c),origin)]
 if b(P-D+0x69):diff[1]=0.
 x,y,z=map(X.fl,diff);distance=(x*x+y*y+z*z).flstore();base=(X.fl(.10000000149011612)+X.fl(fl(0x180))).flstore();th=(X.fl(delta)*X.fl(fl(R-D+0x22c))+X.fl(base)).flstore()
 if Fraction(distance)<(X.fl(th)*X.fl(th)).v:
  setu(0x1e4,P+0x78);wait=fl(P-D+0x9c)
  if wait<=0:return 1,seed,ev
  wait=(X.fl(wait)-X.fl(delta)).flstore();setf(P-D+0x9c,0. if wait<0 else wait)
 return 0,seed,ev

def run(kind,meta=None,tokens=None,first=False,delta=.125,group=None,reuse=False):
 global assertions
 meta=meta or {};tokens=tokens or [];group=group or kind
 if reuse:opt.clear();opt.update(meta);events.clear();before=bytearray(n.read(D,SIZE))
 else:before=setup(meta,tokens)
 expected=bytearray(before)
 want,wseed,wev=model(expected,kind,meta,tokens,first,delta)
 va={'origin':0x536330,'follow':0x536dc0,'formation':0x52fda0}[kind]
 args=[C]if kind=='formation'else[W,P,0 if meta.get('missing')=='creature'else C,A,len(tokens),int(first),bits(delta)]
 try:actual=n.call(va,args)
 except Exception as e:errors.append({'kind':kind,'meta':meta,'tokens':tokens,'error':str(e)});return
 after=n.read(D,SIZE);seed=n.unpack('<I',0x95e5d4)[0];ok=after==expected and seed==wseed and events==wev and(kind=='formation'or actual==want)
 groups[group]=groups.get(group,0)+1;assertions+=4 if kind!='formation'else 3
 if not ok:
  errors.append({'kind':kind,'meta':meta,'tokens':tokens,'result':[actual,want],'rng':[seed,wseed],'events':[events,wev],'diff':[[hex(i),after[i],expected[i]]for i in range(SIZE)if after[i]!=expected[i]][:30]})
 vectors.append({'kind':kind,'meta':dict(meta),'tokens':tokens,'first':first,'delta':bits(delta),'before':base64.b64encode(gzip.compress(before)).decode(),'after':base64.b64encode(gzip.compress(after)).decode(),'result':None if kind=='formation'else actual,'seed':seed,'events':list(events)})
# Guards, flags, formation byte boundaries, signed zero, full-word orientation copies.
for kind in ['origin','follow']:
 for missing in ['creature','reference','object','path','node',None]:
  for first in [False,True]:run(kind,{'missing':missing},['run','waittime=1']if kind=='origin'else['run','1'],first,group='guards')
for flags,slot,row,count,ff,f8,space,heading in itertools.product([0x80000003,0x81000007],[0,1,2,255],[0,3,4],[0,4],[0,4,8,12],[0,1],[0.,-0.,1.25,-2.125],[0,12345]):
 run('formation',dict(formation=True,flags=flags,slot=slot,row=row,count=count,formationFlags=ff,formationFlags8=f8,spacing=space,heading=heading),group='formation-byte-grid')
for kind in ['origin','follow']:
 for form,owner,mutate,first,wait,dt in itertools.product([False,True],[False,True],[False,True],[False,True],[-1.,0.,.125,.25,1.],[-.125,0.,.125,.25,2.]):
  run(kind,dict(formation=form,owner=owner,mutateFormation=mutate,wait=wait,flags=0x81000007),[],first,dt,group='composition-timing')
for kind in ['origin','follow']:
 for toks in [[],['mintime=1','maxtime=2'],['maxtime=2','mintime=1'],['mintime=2','maxtime=1'],['mintime=-1.25','maxtime=3.125'],['run','mintime=1','walk','maxtime=2','0.25'],['0','0.25','0'],['MINTIME=0.1','MAXTIME=0.2']]:
  for callback,seed in itertools.product([False,True],[0,123,0xffffffff]):run(kind,dict(tokenCallback=callback,seed=seed),toks,True,group='ordered-numeric-tokens')
for xz,origin,wait,dist,speed,goal,dt in itertools.product([0,1],[False,True],[-.25,0.,.125],[0.,.1,.25,.5,1.],[0.,.75],[0.,.2,.5],[0.,.125]):
 pos=[8.125+dist,-2.5+dist,1.375]if origin else[4.125+dist,5.25+dist,6.5]
 run('origin',dict(xz=xz,origin=origin,wait=wait,position=pos,speed=speed,goal=goal),delta=dt,group='range-timing')
ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());authored={r['name']:r for r in ledger['rows']if r['name']in['GoToOrigin','FollowPath']and r['kind']=='scp-action'}
for name,row in authored.items():
 for u in row['uses']:run('origin'if name=='GoToOrigin'else'follow',{},u['args'],True,group='authored-'+name)
for first,rf,spawn in itertools.product([False,True],[0,0x400,0xffffffff],[0,255]):run('origin',dict(refFlags=rf,spawn=spawn),first=first,group='origin-reference-spawn-gates')
for kind,form,wait in itertools.product(['origin','follow'],[False,True],[0.,.125,.5]):
 meta=dict(formation=form,owner=form,wait=wait,position=[4.125,5.25,6.5],seed=123)
 for step in range(8):
  if step:meta['seed']=n.unpack('<I',0x95e5d4)[0]
  run(kind,meta,[],step==0,.125,group='stateful-eight-call-sequence',reuse=step>0)
report={'binarySha256':n.sha256,'cases':len(vectors),'assertionGroups':assertions,'groups':groups,'errors':errors,'mismatches':len(errors),'authoredOccurrences':{k:v['sourceUses']for k,v in authored.items()},'method':'Original commands, formation and numeric expression/RNG/intent/yaw/distance dependencies execute; Python own-state oracle checked full65536-byte retained image plus RNG/callback order/command returns. C# prepared replay is separate and unexecuted.','adapters':['Movement-token callback modes walk17/run34; absent callback tested.','Origin-position callback returns prepared point or null, with callback absence.','0x51d130 scheduler dispatch captured as explicit callback boundary; selected cases mutate formation spacing/flags before actual expansion.','Runtime yaw table supplied as finite32768 float32 input; table producer not recovered here.'],'limits':['Finite fast numeric token parser and finite nonoverflowing vector/timing arithmetic; no malformed token memory/NaN exceptions claim.','Prepared valid formation rows0..3 and unsigned boundary early returns; valid nonnull memory pointers except guarded chains.','Resource/path/spawn/formation producers, scheduler body and movement consumers remain outside this contract.']}
(B/'reports/movement-phase4-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(B/'reports/movement-phase4-20261013-fixtures.json.gz','wt',encoding='utf-8')as out:json.dump({'table':[bits(v)for v in table],'cases':vectors},out,separators=(',',':'))
print(json.dumps({'cases':report['cases'],'assertionGroups':assertions,'mismatches':len(errors),'groups':groups,'examples':errors[:4]}))
