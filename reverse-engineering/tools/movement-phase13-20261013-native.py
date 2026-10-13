"""SetForceBack and actual raw-global producer/clear, no computational adapters."""
import importlib.util,struct,json,gzip,itertools,base64,random
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP
n=m.NativeX86();D=n.DATA;C=D;R=D+0x1000;ACT=D+0x2000;P=D+0x4000;W=D+0x6000;ROWS=D+0x8000;ALT=D+0xa000;OTHER=D+0xb000;A=D+0xc000;T=D+0xd000;SIZE=0x10000;CB=n.STOP+0x100;vectors=[];errors=[];groups={};events=[];opt={}
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
val=lambda v:struct.unpack('<f',struct.pack('<I',v))[0]
def read(p):
 b=bytearray()
 while True:
  c=n.read(p,1)[0];p+=1
  if not c:return b.decode('ascii')
  b.append(c)
def hook(mu,a,s,u):
 if a!=CB:return
 sp=mu.reg_read(UC_X86_REG_ESP);world=n.unpack('<I',sp+4)[0];text=read(n.unpack('<I',sp+8)[0]);result=ALT if text.lower()in['alt','mutate','empty']else 0;events.append(['character',world,text,result])
 if text.lower()=='mutate':n.pack('<I',R,OTHER);n.pack('<f',P+0x14,3.125);n.write(ROWS,b'Changed\0');n.pack('<I',W+0x24,2)
 n.pack('<I',ALT,0 if text.lower()=='empty'else OTHER);to=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,to)
n.mu.hook_add(UC_HOOK_CODE,hook)
def setup(c,tokens):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',C+0xd0,0 if c.get('missing')=='reference'else R);n.pack('<I',R,0 if c.get('missing')=='actor'else ACT);n.pack('<I',ALT,OTHER);n.pack('<I',P+4,0);n.pack('<4f',P+0x14,.5,2.,-1.,7.);n.pack('<I',W+0x24,c.get('count',3));n.pack('<I',W+0x28,ROWS)
 for j,name in enumerate(['Alpha','Beta','ALPHA']):n.write(ROWS+j*0x3c,name.encode()+b'\0');n.pack('<3f',ROWS+j*0x3c+0x10,j+1.125,j+2.25,j+3.5)
 n.pack('<I',0x923904,CB if c.get('callback',True)else 0);n.pack('<2I',0x87b890,0x3f000000,0x3e800000);n.pack('<3I',0x87b8c8,0x12345678,0xabcdef00,0xdeadbeef);pos=T
 for j,t in enumerate(tokens):n.write(pos,t.encode()+b'\0');n.pack('<I',A+j*4,pos);pos+=len(t)+4
 events.clear();opt.clear();opt.update(c);return bytearray(n.read(D,SIZE)),n.read(0x87b890,8)+n.read(0x87b8c8,12)
def parse(t,image):
 if'param'in t.lower():return val(struct.unpack_from('<I',image,P-D+0x14)[0])
 sign=-1 if t.startswith('-')else 1;t=t[1:]if t.startswith(('-','+'))else t;whole=decimal=0.;divisor=1.;after=False
 for c in t:
  if c=='.':after=True;continue
  if c<'0'or c>'9':break
  if after:decimal=f32(decimal*10+int(c));divisor=f32(divisor*10)
  else:whole=f32(whole*10+int(c))
 return f32(sign*f32(whole+f32(decimal/divisor)))
def oracle(c,tokens,first,image,state):
 ev=[]
 if not first:return ev
 actor=0 if c.get('missing')in['creature','reference','actor']else ACT;point=kind=0;radius=1.5;enabled=True
 for t in tokens:
  lo=t.lower()
  if'character='in lo:
   name=t[lo.index('character=')+10:];ref=ALT if name.lower()in['alt','mutate','empty']else 0
   if c.get('callback',True):
    ev.append(['character',0 if c.get('worldNull')else W,name,ref]);struct.pack_into('<I',image,ALT-D,0 if name.lower()=='empty'else OTHER)
    if name.lower()=='mutate':struct.pack_into('<I',image,R-D,OTHER);struct.pack_into('<f',image,P-D+0x14,3.125);image[ROWS-D:ROWS-D+8]=b'Changed\0';struct.pack_into('<I',image,W-D+0x24,2)
   else:ref=0
   actor=0 if not ref else struct.unpack_from('<I',image,ref-D)[0]
  elif'locator='in lo:
   name=t[lo.index('locator=')+8:];count=struct.unpack_from('<i',image,W-D+0x24)[0]
   if not c.get('worldNull'):
    for j in range(count):
     p=ROWS-D+j*0x3c;nm=bytes(image[p:p+16]).split(b'\0')[0].decode('ascii')
     if nm.lower()==name.lower():point=ROWS+j*0x3c+0x10;break
  elif'radius='in lo:radius=parse(t[lo.index('radius=')+7:],image)
  elif lo=='false':enabled=False
  elif lo=='type=choke':kind=1
  elif lo=='type=droid':kind=2
  elif lo=='type=comboopponent':kind=3
 if not enabled:struct.pack_into('<2I',state,8,0,0)
 elif actor or point:struct.pack_into('<2I',state,0,bits(radius),bits(f32(radius*radius)));struct.pack_into('<3I',state,8,actor,(actor+0x80)&0xffffffff if actor else point,kind)
 return ev

def run(c=None,tokens=None,first=True,group='synthetic'):
 c=c or {};tokens=tokens or [];before,sbefore=setup(c,tokens);expected=bytearray(before);state=bytearray(sbefore);ev=oracle(c,tokens,first,expected,state);result=n.call(0x451d50,[0 if c.get('worldNull')else W,P,0 if c.get('missing')=='creature'else C,A,len(tokens),int(first)]);after=n.read(D,SIZE);sa=n.read(0x87b890,8)+n.read(0x87b8c8,12);groups[group]=groups.get(group,0)+1
 if after!=expected or sa!=state or events!=ev or result!=1:errors.append(dict(input=c,tokens=tokens,first=first,returnValue=result,state=[sa.hex(),state.hex()],events=[events.copy(),ev],memoryMismatch=after!=expected))
 vectors.append(dict(input=dict(c),tokens=tokens,first=first,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),stateBefore=sbefore.hex(),stateAfter=sa.hex(),events=events.copy(),result=result))
for missing,first,callback,worldNull,tokens in itertools.product([None,'creature','reference','actor'],[False,True],[False,True],[False,True],[[],['FALSE'],['locator=Alpha'],['type=CHOKE'],['character=alt'],['character=empty']]):run(dict(missing=missing,callback=callback,worldNull=worldNull),tokens,first,'guards-state-raw-arguments')
forms=[['locator=alpha','locator=missing'],['character=missing','type=DROID'],['character=empty','locator=Beta'],['type=CHOKE','locator=Alpha'],['FALSE','type=DROID','character=alt'],['FALSE','TRUE'],['type=ComboOpponent','type=CHOKE'],['character=mutate','radius=param3','locator=Changed'],['radius=param3','character=mutate','locator=Alpha'],['radius=-12.9'],['xxradius=2.5'],['xcharacter=alt'],['locator=Beta','character=mutate','locator=missing'],['type=unknown'],['FALSE','radius=10']]
for missing,callback,tokens in itertools.product([None,'creature','actor'],[False,True],forms):run(dict(missing=missing,callback=callback),tokens,group='ordered-token-callback-mutation')
for radius in[-100000,-12.9,-1.5,-.1,0,.1,1.5,12.9,100000]:run({},['radius='+str(radius)],group='radius-squared-store')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());row=next(r for r in ledger['rows']if r['kind']=='scp-action'and r['name']=='SetForceBack')
for use in row['uses']:run({},use.get('args',[]),group='authored-SetForceBack')
# Direct state helpers preserve raw pointer bits and clear only two words.
rng=random.Random(20261015)
for j in range(256):
 c={};before,sbefore=setup(c,[]);actor=rng.getrandbits(32)if j%3 else 0;fallback=rng.getrandbits(32);extra=rng.getrandbits(32);radius=f32(rng.uniform(-1e6,1e6));state=bytearray(sbefore)
 n.call(0x4a4900,[actor,fallback,bits(radius),extra]);struct.pack_into('<2I',state,0,bits(radius),bits(f32(radius*radius)));struct.pack_into('<3I',state,8,actor,(actor+0x80)&0xffffffff if actor else fallback,extra);sa=n.read(0x87b890,8)+n.read(0x87b8c8,12);after=n.read(D,SIZE)
 if sa!=state or after!=before:errors.append(dict(kind='publish',input=[actor,fallback,bits(radius),extra]))
 vectors.append(dict(kind='publish',input=dict(actor=actor,fallback=fallback,radiusBits=bits(radius),extra=extra),before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),stateBefore=sbefore.hex(),stateAfter=sa.hex(),events=[],result=None));groups['direct-state-publisher']=groups.get('direct-state-publisher',0)+1
for j in range(32):
 before,sbefore=setup({},[]);n.pack('<3I',0x87b8c8,rng.getrandbits(32),rng.getrandbits(32),rng.getrandbits(32));sbefore=n.read(0x87b890,8)+n.read(0x87b8c8,12);state=bytearray(sbefore);struct.pack_into('<2I',state,8,0,0);n.call(0x4a48f0);sa=n.read(0x87b890,8)+n.read(0x87b8c8,12);after=n.read(D,SIZE)
 if sa!=state or after!=before:errors.append(dict(kind='clear'))
 vectors.append(dict(kind='clear',input={},before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),stateBefore=sbefore.hex(),stateAfter=sa.hex(),events=[],result=None));groups['direct-state-clear']=groups.get('direct-state-clear',0)+1
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=4*sum('kind'not in v for v in vectors)+2*sum('kind'in v for v in vectors),groups=groups,mismatches=len(errors),errors=errors[:20],authoredOccurrences=row['sourceUses'],nativeAdapters=['Terminal character-reference callback only; can mutate reference, numeric parameter and locator table. All parsing/numeric/lookup/publication/clear routines execute unchanged.'],limits=['Finite representable radius and radiusSquared; bounded valid ASCII tokens and prepared native table/packet backing.','Native command publishes(actor,locatorPoint,radius,type) raw argumentwords to4a4900; no invented semantic type/locator reinterpretation.','Authored occurrences are retained command tokens; no engine force consumer/frame side effects claimed.'])
(m.BASE/'reports/movement-phase13-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase13-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=report['assertionGroups'],mismatches=len(errors),errors=errors[:5])))
