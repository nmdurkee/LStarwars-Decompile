"""Actual scale override command with timer/rate across repeated frame calls."""
from pathlib import Path
p=Path(__file__).with_name('movement-phase14-20261013-native.py');exec(compile(p.read_text().split('for k,missing,first,callback')[0],str(p),'exec'))
vectors=[];errors=[];groups={}
def prep15(c,tokens):
 prepare(c,tokens)
 for actor in[ACT,OTHER]:n.pack('<f',actor+0x102c,c.get('scale',-4.125))
 n.pack('<f',P+0x70,c.get('cachedTime',-2.5));n.pack('<f',P+0x74,c.get('cachedRate',3.125));n.pack('<f',0x925018,c.get('delta',.125));return bytearray(n.read(D,SIZE))
def oracle15(c,tokens,first,image):
 seed=c.get('seed',123);actor=0 if c.get('missing')in['creature','reference','actor']else ACT
 def u(p):return struct.unpack_from('<I',image,p-D)[0]
 def fl(p):return val(u(p))
 def put(p,v):struct.pack_into('<I',image,p-D,bits(v))
 if not actor:return 1,seed
 if first:
  mn=mx=value=f32(1e9);time=0.
  for t in tokens:
   lo=t.lower()
   if lo=='reset':value=f32(1e9)
   elif'min='in lo:mn=parse(t[lo.index('min=')+4:],image)
   elif'max='in lo:mx=parse(t[lo.index('max=')+4:],image)
   elif'time'in lo:time=parse(t[lo.index('time')+5:],image)
   else:value=parse(t,image)
  if mn!=f32(1e9)and mx!=f32(1e9):
   seed=(seed*0x19660d+0x3c6ef35f)&0xffffffff;r=(seed&0x7fffff)/8388608;value=((X.fl(1)-X.fl(r))*X.fl(mn)+X.fl(mx)*X.fl(r)).flstore()
  if time==0:put(actor+0x102c,value);return 1,seed
  put(P+0x70,time);dif=X.fl(value)-X.fl(fl(actor+0x102c));rate=X(quant(dif.v/X.fl(time).v,64),dif.neg!=X.fl(time).neg).flstore();put(P+0x74,rate)
 remaining=fl(P+0x70);delta=c.get('delta',.125)
 if remaining<=0:return 1,seed
 if delta<remaining:put(actor+0x102c,(X.fl(delta)*X.fl(fl(P+0x74))+X.fl(fl(actor+0x102c))).flstore());put(P+0x70,(X.fl(remaining)-X.fl(delta)).flstore());return 0,seed
 put(actor+0x102c,(X.fl(fl(P+0x74))*X.fl(remaining)+X.fl(fl(actor+0x102c))).flstore());put(P+0x70,0.);return 1,seed

def run15(c=None,tokens=None,first=True,group='synthetic',reuse=False):
 c=c or {};tokens=tokens or []
 if reuse:
  n.pack('<f',0x925018,c.get('delta',.125));before=bytearray(n.read(D,SIZE));c=dict(c,seed=n.unpack('<I',0x95e5d4)[0])
 else:before=prep15(c,tokens)
 expected=bytearray(before);want,seed=oracle15(c,tokens,first,expected);ret=n.call(0x44c750,[W,P,0 if c.get('missing')=='creature'else C,A,len(tokens),int(first)]);after=n.read(D,SIZE);rng=n.unpack('<I',0x95e5d4)[0];groups[group]=groups.get(group,0)+1
 if after!=expected or rng!=seed or ret!=want:errors.append(dict(input=c,tokens=tokens,first=first,result=[ret,want],rng=[rng,seed],diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:20]))
 vectors.append(dict(input=dict(c),tokens=tokens,first=first,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),rng=rng,result=ret))
forms=[[],['reset'],['2.5'],['time=1.5','2.5'],['time=-1.5','2.5'],['time=0','2.5'],['min=-2.5','max=3.75','time=1.5'],['2.5','reset'],['reset','2.5'],['runtime=1.5','2.5'],['timer=1.5','2.5'],['time=param3','min=-2.5','max=3.75'],['min=-0','max=-0'],['min=1000000000','max=3.75']]
for missing,first,delta,cachedTime,tokens in itertools.product([None,'creature','reference','actor'],[False,True],[-.125,0,.125,1.5],[-1,0,1.5],forms):run15(dict(missing=missing,delta=delta,cachedTime=cachedTime),tokens,first,'guards-token-time-order')
r=random.Random(20261017)
for j in range(256):run15(dict(seed=r.getrandbits(32),scale=f32(r.uniform(-1e4,1e4)),delta=f32(r.uniform(-1,3))),['min='+str(f32(r.uniform(-1e4,1e4))),'max='+str(f32(r.uniform(-1e4,1e4))),'time='+str(f32(r.uniform(.001,5)))],group='rate-rng-x87-frame-rounding')
for target,time,seed in itertools.product([-2.5,0,3.75],[.125,.5,1.5],[0,123]):
 tokens=[str(target),'time='+str(time)]
 for j,delta in enumerate([0.,-.125,.125,.25,.5,1.,0.,.125]):run15(dict(seed=seed,delta=delta,scale=-4.125),tokens,j==0,'repeated-frame-sequence',reuse=j!=0)
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());row=next(r for r in ledger['rows']if r['kind']=='scp-action'and r['name']=='SetScaleOverride')
for use in row['uses']:run15({},use.get('args',[]),group='authored-SetScaleOverride')
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=3*len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],authoredOccurrences=row['sourceUses'],repeatedSequences=18,repeatedSequenceSteps=144,nativeAdapters=0,limits=['Finite valid actor/packet/numeric inputs andfinite cached rates; timezero directset andnegative delta/time included.','Original parsing,numericresolver,floatRNG execute unchanged. Authored commandtokens retained; consumers/actual frame delta producer remain external.','NaN/Inf comparison/hardware semantics and invalid arbitrary pointers excluded.'])
(m.BASE/'reports/movement-phase15-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase15-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=report['assertionGroups'],mismatches=len(errors),errors=errors[:5])))
