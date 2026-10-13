"""Actual compact actor/global predicates with explicit null-fault order."""
import importlib.util,struct,json,gzip,itertools,base64,random
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;C=D;R=D+0x1000;ACT=D+0x2000;OTHER=D+0x4000;REC=D+0x6000;STATE=D+0x8000;RESULT=D+0xe000;SIZE=0x10000;vectors=[];errors=[];groups={}
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
FUNCS={'cutscene':0x4426a0,'race':0x443db0,'radio':0x443d70,'towed':0x443d80,'force':0x440b70,'ground':0x441860,'blocked':0x5156f0}
for j,va in enumerate(FUNCS.values()):
 stub=n.STOP+0x200+j*0x100;code=b'\xff\x74\x24\x14'*5;call=stub+len(code);code+=b'\xe8'+struct.pack('<i',va-(call+5))+b'\x83\xc4\x14\xd9\x1d'+struct.pack('<I',RESULT)+b'\xc3';n.write(stub,code)
def setup(c):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',C+0xd0,0 if c.get('missing')=='reference'else R);n.pack('<I',R,0 if c.get('missing')=='actor'else ACT);n.pack('<I',REC+4,0 if c.get('missing')=='state'else STATE);n.pack('<I',STATE+0x88,c.get('flags',0));n.pack('<I',C+0x1e8,c.get('flags',0));n.pack('<i',0x882a70,c.get('race',0));n.pack('<I',0x87b9d0,c.get('radio',0))
 for actor in[ACT,OTHER]:n.pack('<I',actor+0xef4,c.get('flags',0));n.pack('<B',actor+0x7b5,c.get('context',0));n.pack('<B',actor+0x281,c.get('ground1',0));n.pack('<B',actor+0x282,c.get('ground2',0))
 return bytearray(n.read(D,SIZE))
def oracle(k,c):
 missing=c.get('missing');flags=c.get('flags',0)
 if k=='status':return(0xffffffff if flags&0x1000 else 0),missing=='state'
 if k=='cutscene':return bits(1 if missing not in['record','state']and flags&0x1000 else 0),False
 if k=='race':return bits(c.get('race',0)),False
 if k=='radio':return bits(1 if c.get('radio',0)else 0),False
 if k=='blocked':return bits(1 if missing!='creature'and flags&0x400000 else 0),False
 if k=='towed':
  if missing=='creature':return 0,False
  if missing in['reference','actor']:return None,True
  return bits(1 if flags&0x200 else 0),False
 if k=='force':return bits(1 if(c.get('explicit')or missing not in['creature','reference','actor'])and c.get('context',0)==0x1b else 0),False
 return bits(1 if missing not in['creature','reference','actor']and(c.get('ground1',0)or c.get('ground2',0))else 0),False

def run(k,c,group):
 before=setup(c);want,wfault=oracle(k,c);fault=False;result=None
 try:
  if k=='status':result=n.call(0x500210,[0 if c.get('missing')=='state'else STATE])
  else:
   fifth=(0 if c.get('missing')=='record'else REC)if k=='cutscene'else OTHER if c.get('explicit')else 0;n.call(n.STOP+0x200+list(FUNCS).index(k)*0x100,[0,0,0 if c.get('missing')=='creature'else C,0,fifth]);result=n.unpack('<I',RESULT)[0]
 except RuntimeError:fault=True
 after=n.read(D,SIZE);expected=bytearray(before)
 if not fault and k!='status':struct.pack_into('<I',expected,RESULT-D,result)
 groups[group]=groups.get(group,0)+1
 if after!=expected or fault!=wfault or(not fault and result!=want):errors.append(dict(kind=k,input=c,result=[result,want],fault=[fault,wfault],memoryMismatch=after!=expected))
 vectors.append(dict(kind=k,input=dict(c),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=result,fault=fault))
for k,missing,explicit,flags in itertools.product(list(FUNCS)+['status'],[None,'creature','reference','actor','record','state'],[False,True],[0,0xffffffff,0x1000,0x200,0x400000]):run(k,dict(missing=missing,explicit=explicit,flags=flags,context=0x1b,ground1=1),'guard-argument-fault-order')
for value in range(256):
 run('force',dict(context=value),'all-context-bytes');run('ground',dict(ground1=value,ground2=0),'all-first-ground-bytes');run('ground',dict(ground1=0,ground2=value),'all-second-ground-bytes')
r=random.Random(20261018)
patterns=[0,0xffffffff]+[1<<j for j in range(32)]+[r.getrandbits(32)for j in range(128)]
for flag in patterns:
 for k in['cutscene','status','towed','blocked']:run(k,dict(flags=flag),'single-bit-and-correlated-random-flags')
for value in[-2147483648,-2147483647,-16777217,-16777216,-1,0,1,16777215,16777216,16777217,2147483646,2147483647]+[r.randrange(-2147483648,2147483648)for j in range(256)]:run('race',dict(race=value),'signed-int-f32-rounding')
for value in patterns:run('radio',dict(radio=value),'all-nonzero-radio-words')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());names={'CutSceneFinished':'cutscene','RaceLap':'race','CanHearRadio':'radio','BeingTowed':'towed','ForcePushing':'force','OnGround':'ground','PathBlocked':'blocked'};authored={}
for row in ledger['rows']:
 if row['kind']=='scp-condition'and row['name']in names:
  authored[row['name']]=row['sourceUses']
  for use in row['uses']:run(names[row['name']],{},'authored-'+row['name'])
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=3*len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],faultCases=sum(v['fault']for v in vectors),authoredOccurrences=authored,nativeAdapters=0,limits=['Valid complete record/actor backing plus explicit missingreference/actor/state nativefault cases. Arbitrary invalid pointers excluded.','All256 context and individualgroundbytes; signedint race boundaries andcorrelated bit/randomword families.','Authored condition-body occurrences retained; init/comparison andsource fieldproducer/frame binding remain external.'])
(m.BASE/'reports/movement-phase17-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase17-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=report['assertionGroups'],mismatches=len(errors),faultCases=report['faultCases'],errors=errors[:5])))
