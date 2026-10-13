"""Unadapted original compact predicates and exact argument/guard provenance."""
import importlib.util,struct,json,gzip,itertools,base64,random,math
from fractions import Fraction
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;CRE=D;REF=D+0x1000;ACTOR=D+0x2000;TARGET=D+0x4000;PACKET=D+0x6000;LOC=D+0x8000;TURRET=D+0xa000;RESULT=D+0xc000;SIZE=0x10000;vectors=[];errors=[];groups={}
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
# Reuse sealed exact x87 quantizer, not Python3.14 compensated sum.
prefix=Path(__file__).with_name('movement-phase11-20261013-native.py').read_text();fragment=prefix[prefix.index('def quant('):prefix.index('def setup(')];exec(fragment)
FUNCS={'takeover':0x443610,'stuck':0x515790,'turret':0x440be0,'cheat':0x442b30,'opponentY':0x515580}
for j,va in enumerate(FUNCS.values()):
 stub=n.STOP+0x700+j*0x100;code=b'\xff\x74\x24\x14'*5;call=stub+len(code);code+=b'\xe8'+struct.pack('<i',va-(call+5))+b'\x83\xc4\x14\xd9\x1d'+struct.pack('<I',RESULT)+b'\xc3';n.write(stub,code)
def setup(c):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',CRE+0xd0,0 if c.get('missing')=='reference'else REF);n.pack('<I',REF,0 if c.get('missing')=='actor'else ACTOR);n.pack('<I',ACTOR+0xea4,0 if c.get('missing')=='target'else REF if c.get('alias')else TARGET);n.pack('<I',CRE+0xe4,0 if c.get('missing')=='opponent'else TARGET);n.pack('<I',PACKET+0xa4,0 if c.get('missing')=='locator'else LOC)
 n.pack('<3f',REF+0x5c,*c.get('position',[1.25,-2.5,3.75]));n.pack('<3f',ACTOR+0x5c,*c.get('actorPosition',[-10,20,30]));n.pack('<3f',TARGET+0x5c,*c.get('targetPosition',[4.125,5.25,-6.5]));n.pack('<I',REF+0x1d8,c.get('timeBits',0));n.pack('<H',TURRET+0x13a,c.get('turretFlags',0));n.pack('<f',LOC+0x14,c.get('locatorY',3.125));return bytearray(n.read(D,SIZE))
def oracle(k,c):
 missing=c.get('missing')
 if k=='cheat':return 0,False
 if k=='turret':return bits(0 if missing=='turret'or c.get('turretFlags',0)&0x30 else 1),False
 if k=='stuck':return(0 if missing in['creature','reference']else c.get('timeBits',0)),False
 if k=='takeover':
  if missing in['creature','reference','actor','target']:return 0x4e6e6b28,False
  a=c.get('position',[1.25,-2.5,3.75]);b=a if c.get('alias')else c.get('targetPosition',[4.125,5.25,-6.5]);v=[f32(x-y)for x,y in zip(b,a)];return bits(f32(math.sqrt(ordered_square(v)))),False
 if missing in['creature','opponent']:return 0x7f7fffff,False
 if not c.get('explicitLocator'):
  if missing=='packet':return None,True
  if missing=='locator':return 0x7f7fffff,False
 return bits(f32(c.get('targetPosition',[4.125,5.25,-6.5])[1]-c.get('locatorY',3.125))),False

def run(k,c,group):
 before=setup(c);want,wfault=oracle(k,c);fault=False;result=None;creature=0 if c.get('missing')=='creature'else CRE;packet=0 if c.get('missing')=='packet'else PACKET;fifth=(0 if c.get('missing')=='turret'else TURRET)if k=='turret'else LOC if c.get('explicitLocator')else 0
 try:n.call(n.STOP+0x700+list(FUNCS).index(k)*0x100,[0,packet,creature,0,fifth]);result=n.unpack('<I',RESULT)[0]
 except RuntimeError:fault=True
 after=n.read(D,SIZE);expected=bytearray(before)
 if not fault:struct.pack_into('<I',expected,RESULT-D,result)
 groups[group]=groups.get(group,0)+1
 if after!=expected or fault!=wfault or(not fault and result!=want):errors.append(dict(kind=k,input=c,result=[result,want],fault=[fault,wfault]))
 vectors.append(dict(kind=k,input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result,fault=fault))
for k,missing,explicit in itertools.product(FUNCS,[None,'creature','reference','actor','target','opponent','packet','locator','turret'],[False,True]):run(k,dict(missing=missing,explicitLocator=explicit),'guards-and-argument-slots')
for flag in range(65536):
 if flag<256 or flag&255 in[0,0x10,0x20,0x30,0xff]:run('turret',dict(turretFlags=flag),'lowbyte-flags-and-highbyte-preservation')
for b in[0,0x80000000,0x3f800000,0xbf800000,1,0x80000001,0x7f7fffff,0xff7fffff,0x7f800000,0xff800000]:run('stuck',dict(timeBits=b),'stored-time-raw-bits')
r=random.Random(20261014)
for j in range(512):
 c=dict(position=[f32(r.uniform(-1e5,1e5))for _ in range(3)],targetPosition=[f32(r.uniform(-1e5,1e5))for _ in range(3)],locatorY=f32(r.uniform(-1e5,1e5)),alias=j%4==0,explicitLocator=bool(j&1));run('takeover',c,'reference-position-distance');run('opponentY',c,'locator-height-rounding')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());names={'TakeOverRange':'takeover','StuckTime':'stuck','TurretAlive':'turret','CheatProgress':'cheat','OpponentToLocatorY':'opponentY'};authored={}
for row in ledger['rows']:
 if row['kind']=='scp-condition'and row['name']in names:
  authored[row['name']]=row['sourceUses']
  for use in row['uses']:run(names[row['name']],{},'authored-'+row['name'])
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=3*len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],faultCases=sum(v['fault']for v in vectors),authoredOccurrences=authored,nativeAdapters=0,limits=['Finite squared-distance inputs. Stored time finite/Inf rawbits; signaling/quietNaN hardware payload behavior excluded.','Valid actor/reference/locator/turret backing and explicit nullpacket fault; invalid arbitrary pointers excluded.','Original argument5 turret/locator carried through ABI wrappers; authored inputs are condition-body occurrences, not wholeSCP comparison execution.'])
(m.BASE/'reports/movement-phase12-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase12-20261013-fixtures.json.gz','wt',encoding='utf-8')as out:json.dump(dict(vectors=vectors),out,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=report['assertionGroups'],mismatches=len(errors),faultCases=report['faultCases'],errors=errors[:5])))
