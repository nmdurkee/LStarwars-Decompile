"""Actual locator XZ/opponent and nearestplayer distance bodies."""
import importlib.util,struct,json,gzip,itertools,base64,random,math
from fractions import Fraction
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;C=D;P=D+0x1000;W=D+0x2000;OPP=D+0x4000;P1=D+0x6000;P2=D+0x8000;LOC=D+0xa000;RESULT=D+0xe000;SIZE=0x10000;vectors=[];errors=[];groups={}
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
prefix=Path(__file__).with_name('movement-phase11-20261013-native.py').read_text();exec(prefix[prefix.index('def quant('):prefix.index('def setup(')])
for j,va in enumerate([0x515530,0x515620]):
 stub=n.STOP+0x300+j*0x100;code=b'\xff\x74\x24\x14'*5;call=stub+len(code);code+=b'\xe8'+struct.pack('<i',va-(call+5))+b'\x83\xc4\x14\xd9\x1d'+struct.pack('<I',RESULT)+b'\xc3';n.write(stub,code)
def setup(c):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',C+0xe4,0 if c.get('missing')=='opponent'else OPP);n.pack('<I',C+0xd0,0 if c.get('missing')=='reference'else D+0x3000);n.pack('<I',D+0x3000,0);n.pack('<I',P+0xa4,0 if c.get('missing')=='locator'else LOC);n.pack('<I',W+0x138c,P1 if c.get('player1',True)else 0);n.pack('<I',W+0x1390,P1 if c.get('aliasPlayers')else P2 if c.get('player2',True)else 0)
 for address,key,default in[(OPP,'opponent',[1.25,-2.5,3.75]),(P1,'position1',[4.125,5.25,-6.5]),(P2,'position2',[-4.25,6.375,2.5])]:n.pack('<3f',address+0x5c,*c.get(key,default))
 n.pack('<3f',LOC+0x10,*c.get('locator',[3.125,4.25,-2.5]));return bytearray(n.read(D,SIZE))
def oracle(k,c):
 missing=c.get('missing')
 if missing=='creature'or(k=='nearest'and c.get('worldNull'))or(k=='xz'and missing=='opponent'):return 0x7f7fffff,False
 if not c.get('explicit'):
  if missing=='packet':return None,True
  if missing=='locator':return 0x7f7fffff,False
 locator=c.get('locator',[3.125,4.25,-2.5])
 def square(a,xz):return ordered_square([f32(a[j]-locator[j])if not xz or j!=1 else 0. for j in range(3)])
 if k=='xz':return bits(f32(math.sqrt(square(c.get('opponent',[1.25,-2.5,3.75]),True)))),False
 best=f32(3.4028234663852886e38)
 if c.get('player1',True):best=square(c.get('position1',[4.125,5.25,-6.5]),False)
 if c.get('aliasPlayers')or c.get('player2',True):
  other=square(c.get('position1',[4.125,5.25,-6.5])if c.get('aliasPlayers')else c.get('position2',[-4.25,6.375,2.5]),False)
  if other<best:best=other
 return bits(best if bits(best)==0x7f7fffff else f32(math.sqrt(best))),False

def run(k,c,group):
 before=setup(c);want,wfault=oracle(k,c);fault=False;result=None
 try:n.call(n.STOP+0x300+(k=='nearest')*0x100,[0 if c.get('worldNull')else W,0 if c.get('missing')=='packet'else P,0 if c.get('missing')=='creature'else C,0,LOC if c.get('explicit')else 0]);result=n.unpack('<I',RESULT)[0]
 except RuntimeError:fault=True
 after=n.read(D,SIZE);expected=bytearray(before)
 if not fault:struct.pack_into('<I',expected,RESULT-D,result)
 groups[group]=groups.get(group,0)+1
 if after!=expected or fault!=wfault or(not fault and result!=want):errors.append(dict(kind=k,input=c,result=[result,want],fault=[fault,wfault],memoryMismatch=after!=expected))
 vectors.append(dict(kind=k,input=dict(c),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result,fault=fault))
for k,missing,explicit,worldNull,p1,p2,alias in itertools.product(['xz','nearest'],[None,'creature','reference','opponent','packet','locator'],[False,True],[False,True],[False,True],[False,True],[False,True]):run(k,dict(missing=missing,explicit=explicit,worldNull=worldNull,player1=p1,player2=p2,aliasPlayers=alias),'guards-bound-locator-players-alias')
r=random.Random(20261019)
for j in range(512):
 c={key:[f32(r.uniform(-1e5,1e5))for v in range(3)]for key in['opponent','position1','position2','locator']};c['explicit']=bool(j&1);run('xz',c,'xz-difference-square-sqrt-rounding');run('nearest',c,'nearest-3d-min-square-before-sqrt')
for k in['xz','nearest']:
 for c in[dict(opponent=[0,10000,0],position1=[0,10000,0],position2=[0,20000,0],locator=[0,0,0]),dict(opponent=[0,-0.,0],position1=[0,0,0],position2=[0,0,0],locator=[0,0,0]),dict(player1=False,player2=False),dict(position1=[3,4,0],position2=[5,0,0],locator=[0,0,0])]:run(k,c,'xz-yignored-nearest-3d-tie-sentinel')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());names={'OpponentToLocatorXZ':'xz','NearestPlayerToLocator':'nearest'};authored={}
for row in ledger['rows']:
 if row['kind']=='scp-condition'and row['name']in names:
  authored[row['name']]=row['sourceUses']
  for use in row['uses']:run(names[row['name']],{},'authored-'+row['name'])
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=3*len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],faultCases=sum(v['fault']for v in vectors),authoredOccurrences=authored,nativeAdapters=0,limits=['Finite coordinates andfinite squared-distance domain withvalid actor/locator/world backing; explicit nullpacket faults retained.','Nearestplayer uses fullXYZ distance and compares squaredvalues before sqrt; opponentXZ ignoresY. No selfreference/object gate, distinctfrom existing nearestplayer-range condition.','Original helper/sqrt bodies execute unchanged; C# composes existing spatial numeric sources. Authored condition-body uses retained, loader/init/comparison andplayer/locator producers external.'])
(m.BASE/'reports/movement-phase18-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase18-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=report['assertionGroups'],mismatches=len(errors),faultCases=report['faultCases'],errors=errors[:5])))
