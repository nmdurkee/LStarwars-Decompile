"""Weapon and gravity commands with actual parser,numeric and RNG routines."""
from pathlib import Path
import math
from fractions import Fraction
p=Path(__file__).with_name('movement-phase13-20261013-native.py');exec(compile(p.read_text().split('for missing,first,callback,worldNull,tokens')[0],str(p),'exec'))
p4=Path(__file__).with_name('movement-phase4-20261013-native.py').read_text();exec(p4[p4.index('def quant('):p4.index('def readstr(')])
vectors=[];errors=[];groups={}
def parse(t,image):
 if'param'in t.lower():return val(struct.unpack_from('<I',image,P-D+0x14)[0])
 i=1 if t.startswith('-')else 0;divisor=-1. if i else 1.;value=0.
 while i<len(t)and'0'<=t[i]<='9':value=f32(f32(value*10)+int(t[i]));i+=1
 if i<len(t)and t[i]=='.':
  i+=1
  while i<len(t)and'0'<=t[i]<='9':divisor=f32(divisor*10);value=f32(f32(value*10)+int(t[i]));i+=1
 return f32(value/divisor)
def prepare(c,tokens):
 before,_=setup(c,tokens)
 for actor in[ACT,OTHER]:n.pack('<I',actor+0xe20,c.get('flags',0xa5a5a5a5));n.pack('<I',actor+0xeec,c.get('hold',0xdeadbeef));n.pack('<f',actor+0xd3c,-3.125);n.pack('<f',actor+0x1028,-7.25)
 n.pack('<I',0x95e5d4,c.get('seed',123));return bytearray(n.read(D,SIZE))
def oracle14(k,c,tokens,first,image):
 seed=c.get('seed',123);ev=[];actor=0 if c.get('missing')in['creature','reference','actor']else ACT
 def u(p):return struct.unpack_from('<I',image,p-D)[0]
 def put(p,v):struct.pack_into('<I',image,p-D,v&0xffffffff)
 if not first:return seed,ev
 if k=='weapon':
  enabled=True;keep=-1
  for t in tokens:
   lo=t.lower()
   if'character='in lo:
    name=t[lo.index('character=')+10:];ref=ALT if name.lower()in['alt','mutate','empty']else 0
    if c.get('callback',True):
     ev.append(['character',0 if c.get('worldNull')else W,name,ref]);put(ALT,0 if name.lower()=='empty'else OTHER)
     if name.lower()=='mutate':put(R,OTHER);put(P+0x14,bits(3.125));image[ROWS-D:ROWS-D+8]=b'Changed\0';put(W+0x24,2)
    else:ref=0
    actor=0 if ref==0 else u(ref)
   elif'keep_out='in lo:keep=int(t[lo.index('keep_out=')+9:].lower()=='true')
   elif lo=='false':enabled=False
  if actor:
   if enabled:
    put(actor+0xe20,u(actor+0xe20)|0x10000);put(actor+0xd3c,bits(1))
    if keep!=-1:put(actor+0xeec,(u(actor+0xeec)&~0x10)|(keep<<4))
   else:put(actor+0xe20,u(actor+0xe20)&~0x10000);put(actor+0xeec,u(actor+0xeec)&~0x10);put(actor+0xd3c,0)
 else:
  if not actor:return seed,ev
  put(actor+0xeec,u(actor+0xeec)&0x7fffffff);put(actor+0x1028,bits(1e9));mn=mx=f32(1e9)
  for t in tokens:
   lo=t.lower()
   if lo=='reset':continue
   if'min='in lo:mn=parse(t[lo.index('min=')+4:],image)
   elif'max='in lo:mx=parse(t[lo.index('max=')+4:],image)
   else:put(actor+0x1028,bits(parse(t,image)))
  if mn!=f32(1e9)and mx!=f32(1e9):
   seed=(seed*0x19660d+0x3c6ef35f)&0xffffffff;r=(seed&0x7fffff)/8388608;result=((X.fl(1)-X.fl(r))*X.fl(mn)+X.fl(mx)*X.fl(r)).flstore();put(actor+0x1028,bits(result))
 return seed,ev

def run14(k,c=None,tokens=None,first=True,group='synthetic'):
 c=c or {};tokens=tokens or [];before=prepare(c,tokens);expected=bytearray(before);seed,ev=oracle14(k,c,tokens,first,expected);result=n.call(0x44efc0 if k=='weapon'else 0x44c5f0,[0 if c.get('worldNull')else W,P,0 if c.get('missing')=='creature'else C,A,len(tokens),int(first)]);after=n.read(D,SIZE);rng=n.unpack('<I',0x95e5d4)[0];groups[group]=groups.get(group,0)+1
 if after!=expected or rng!=seed or events!=ev or result!=1:errors.append(dict(kind=k,input=c,tokens=tokens,first=first,result=result,rng=[rng,seed],events=[events.copy(),ev],diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:20]))
 vectors.append(dict(kind=k,input=dict(c),tokens=tokens,first=first,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),rng=rng,events=events.copy(),result=result))
for k,missing,first,callback in itertools.product(['weapon','gravity'],[None,'creature','reference','actor'],[False,True],[False,True]):run14(k,dict(missing=missing,callback=callback),[],first,'guards')
weapon=[[],['FALSE'],['FALSE','TRUE'],['keep_out=TRUE'],['keep_out=FALSE'],['keep_out=unknown'],['keep_out=TRUE','keep_out=FALSE'],['character=alt','FALSE'],['FALSE','character=alt'],['character=empty','keep_out=TRUE'],['character=mutate'],['character=missing'],['xkeep_out=TRUE'],['keep_out=TRUEx']]
for missing,callback,hold,tokens in itertools.product([None,'creature','actor'],[False,True],[0,0xffffffff,0xdeadbeef],weapon):run14('weapon',dict(missing=missing,callback=callback,hold=hold),tokens,group='weapon-token-order-holdbit-callback')
gravity=[[],['reset'],['12.9'],['min=-2.5'],['max=3.75'],['min=-2.5','max=3.75'],['min=3.75','max=-2.5'],['12.9','reset'],['reset','-12.9'],['min=1e9','max=3.75'],['min=1000000000','max=3.75'],['min=-2.5','max=1000000000'],['min=param3','max=7'],['xxmin=-2.5','max=3.75'],['min=0','max=0'],['min=-2.5','max=3.75','12.9'],['min=-0','max=-0'],['min=-0','max=0'],['min=0','max=-0']]
for first,hold,seed,tokens in itertools.product([False,True],[0,0xffffffff,0xdeadbeef],[0,1,123,0xffffffff],gravity):run14('gravity',dict(hold=hold,seed=seed),tokens,first,'gravity-sentinel-single-rng-reset')
r=random.Random(20261016)
for j in range(256):run14('gravity',dict(seed=r.getrandbits(32)),['min='+str(f32(r.uniform(-1e5,1e5))),'max='+str(f32(r.uniform(-1e5,1e5)))],group='gravity-x87-random-rounding')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());authored={}
for row in ledger['rows']:
 if row['kind']=='scp-action'and row['name']in['SnapWeaponOut','SetGravityHeight']:
  authored[row['name']]=row['sourceUses']
  for use in row['uses']:run14('weapon'if row['name']=='SnapWeaponOut'else'gravity',{},use.get('args',[]),group='authored-'+row['name'])
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=4*len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],authoredOccurrences=authored,nativeAdapters=['Terminal character-reference callback only forweapon; native parsers/numericresolver/RNG execute unchanged.'],limits=['Finite numeric inputs representable inF32 and finite blended heights; valid packet and actor backing.','UnorderedNaN/sNaN hardware handling and arbitrary invalid pointers excluded.','Authored commandtokens retained; actual weapon/gravity consumers and physics/frame integration remain external.'])
(m.BASE/'reports/movement-phase14-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase14-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=report['assertionGroups'],mismatches=len(errors),errors=errors[:5])))
