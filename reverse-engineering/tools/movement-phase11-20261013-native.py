"""Actual range/trigger/music readers, including native fault guard ordering."""
import importlib.util,struct,json,gzip,itertools,base64,random,math
from fractions import Fraction
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;CRE=D;REF=D+0x1000;ACTOR=D+0x10000;OTHER=D+0x12000;WORLD=D+0x8000;PHYS=D+0x30000;RESULT=D+0x60000;SIZE=0x70000;vectors=[];errors=[];groups={}
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
for j,va in enumerate([0x443390,0x442d10,0x443dc0]):
 stub=n.STOP+0x200+j*0x100;code=b'\xff\x74\x24\x0c'*3;call=stub+len(code);code+=b'\xe8'+struct.pack('<i',va-(call+5))+b'\x83\xc4\x0c\xd9\x1d'+struct.pack('<I',RESULT)+b'\xc3';n.write(stub,code)
def quant(v,p):
 if not v:return Fraction(0)
 sign=-1 if v<0 else 1;nn=abs(v.numerator);dd=v.denominator;e=nn.bit_length()-dd.bit_length()
 if(nn<dd<<e if e>=0 else nn<<-e<dd):e-=1
 step=e-(p-1);a=nn<<-step if step<0 else nn;b=dd<<step if step>=0 else dd;q,r=divmod(a,b)
 if 2*r>b or(2*r==b and q&1):q+=1
 return sign*(Fraction(q<<step)if step>=0 else Fraction(q,1<<-step))

def ordered_square(v):
 terms=[quant(Fraction(float(x))*Fraction(float(x)),64)for x in v];wide=quant(quant(terms[0]+terms[1],64)+terms[2],64);return f32(float(quant(wide,24)))
def setup(meta):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',CRE+0xd0,0 if meta.get('missing')=='reference'else REF);n.pack('<I',REF,0 if meta.get('missing')=='actor'else ACTOR);n.pack('<I',ACTOR+0x10a8,0 if meta.get('attacker',1)<0 else ACTOR if meta.get('attacker',1)==0 else OTHER)
 n.pack('<3f',ACTOR+0x5c,*meta.get('position',[1.25,-2.5,3.75]));n.pack('<3f',OTHER+0x5c,*meta.get('attackerPosition',[4.125,5.25,-6.5]));n.pack('<I',0x802c54,0 if meta.get('worldNull')else WORLD);n.pack('<I',WORLD+0x4678,0 if meta.get('noPhysics')else PHYS)
 index=meta.get('index',0);block=meta.get('block',0);n.pack('<B',REF+0x28d,index);n.pack('<B',PHYS+0x42c0+index,meta.get('active',0));n.pack('<b',PHYS+0x4280+index,block);n.pack('<H',PHYS+block*0x214+0x20e,meta.get('state',1));n.pack('<B',0x8668d2,meta.get('music',0))
 return bytearray(n.read(D,SIZE))
def oracle(kind,meta):
 if kind=='music':return bits(1 if meta.get('music',0)else 0),False
 if kind=='range':
  if meta.get('missing')in['creature','reference']:return 0x4e6e6b28,False
  if meta.get('missing')=='actor':return None,True
  if meta.get('attacker',1)<0:return 0x4e6e6b28,False
  a=meta.get('position',[1.25,-2.5,3.75]);b=a if meta.get('attacker',1)==0 else meta.get('attackerPosition',[4.125,5.25,-6.5]);delta=[f32(x-y)for x,y in zip(a,b)];square=ordered_square(delta);return bits(f32(math.sqrt(square))),False
 if meta.get('worldNull'):return None,True
 if meta.get('noPhysics')or meta.get('missing')in['creature','reference']:return bits(0),False
 return bits(0 if meta.get('active',0)==255 or meta.get('state',1)==0 else 1),False

def run(kind,meta,group):
 before=setup(meta);want,wfault=oracle(kind,meta);fault=False;result=None;creature=0 if meta.get('missing')=='creature'else CRE
 try:n.call(n.STOP+0x200+['range','help','music'].index(kind)*0x100,[WORLD,0,creature]);result=n.unpack('<I',RESULT)[0]
 except RuntimeError:fault=True
 expected=bytearray(before)
 if not fault:struct.pack_into('<I',expected,RESULT-D,result)
 after=n.read(D,SIZE);groups[group]=groups.get(group,0)+1
 if after!=expected or fault!=wfault or(not fault and result!=want):errors.append({'kind':kind,'input':meta,'result':[result,want],'fault':[fault,wfault],'diff':[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12]})
 vectors.append({'kind':kind,'input':dict(meta),'before':base64.b64encode(gzip.compress(before)).decode(),'after':base64.b64encode(gzip.compress(after)).decode(),'result':result,'fault':fault})
for kind,missing in itertools.product(['range','help','music'],[None,'creature','reference','actor']):run(kind,{'missing':missing},'guard-structure')
for index,block,active,state,missing,worldNull,noPhys in itertools.product([0,127,128,255],[-128,-1,0,1,127],[0,128,254,255],[0,1,0x8000,0xffff],[None,'creature','reference'],[False,True],[False,True]):
 run('help',dict(index=index,block=block,active=active,state=state,missing=missing,worldNull=worldNull,noPhysics=noPhys),'signed-block-byte-index-gates')
for value in range(256):run('music',{'music':value},'all-music-byte-values')
for index in range(256):run('help',dict(index=index,block=index-128,active=0,state=1),'all-index-and-signed-block-bytes')
rr=random.Random(20261013)
for j in range(512):run('range',dict(position=[f32(rr.uniform(-1e5,1e5))for k in range(3)],attackerPosition=[f32(rr.uniform(-1e5,1e5))for k in range(3)],attacker=j%3-1),'last-attacker-distance-alias-rounding')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());authored={r['name']:r for r in ledger['rows']if r['kind']=='scp-condition'and r['name']in['LastAttackerRange','HelpWithTriggers','MusicOn']}
for name,row in authored.items():
 for use in row['uses']:run({'LastAttackerRange':'range','HelpWithTriggers':'help','MusicOn':'music'}[name],{},'authored-'+name)
report={'binarySha256':n.sha256,'cases':len(vectors),'assertionGroups':3*len(vectors),'groups':groups,'mismatches':len(errors),'errors':errors,'faultCases':sum(v['fault']for v in vectors),'authoredOccurrences':{k:r['sourceUses']for k,r in authored.items()},'method':'Original443390/442d10/443dc0 and actualdistance/sqrt helpers execute with no adapters. Floatreturns captured by explicit ABI wrappers; full458752byte image,fault,return checked. Native own-state/Python verification separate from C# replay.','limits':['Finite coordinate inputs and finite squared-distance domain. Prepared complete reference/actor/negative-block backing; explicit nullnative fault cases retained.','All256 music/index bytes andsignedblock boundarysamples; active slot255 is unique sentinel.','Authored condition forms are retained as body occurrence inputs; wholeSCP comparison/init execution is not claimed.','Current musicflag, trigger blocks and last-attacker pointer producers/consumers remain external.']}
(m.BASE/'reports/movement-phase11-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase11-20261013-fixtures.json.gz','wt',encoding='utf-8')as out:json.dump({'vectors':vectors},out,separators=(',',':'))
print(json.dumps({'cases':len(vectors),'checks':report['assertionGroups'],'mismatches':len(errors),'faultCases':report['faultCases'],'examples':errors[:5]}))
