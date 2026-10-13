"""Original PC SetLocator, SnapToLocator, GotLocator and real linear lookup.
CRT formatting and named actor/terrain callbacks are explicit bounded adapters.
"""
import importlib.util,json,struct,itertools,random,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;CRE=D+0x2000;ACT=D+0x4000;PACK=D+0x8000;CALLER=D+0xc000;LOC=D+0x10000;ARGS=D+0x20000;TEXT=D+0x21000;NAMES=D+0x40000;ADAPTER=n.STOP+0x100;RESULT=D+0x50000
ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'))
uses={r['name']:r['uses'] for r in ledger['rows'] if r['name'] in ['SetLocator','SnapToLocator','GotLocator']}
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def f(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def u(v):return v&0xffffffff
def si(v):return (v+0x80000000)%0x100000000-0x80000000
def rng(v):
 x=si(v^0x75bd924);q=(abs(x)//0x1f31d)*(1 if x>=0 else -1);v=si(x*0x41a7-q*0x7fffffff)
 if v<0:v=si(v+0x7fffffff)
 return u(v^0x75bd924)
def number(t):
 if 'param' in t.lower():return 2.75
 if t.lower() in ['alpha','beta','gamma','delta']:return [2.75,1.5,3.,4.][['alpha','beta','gamma','delta'].index(t.lower())]
 i=0;value=0.;den=1.
 if t.startswith('-'):i=1;den=-1.
 while i<len(t) and t[i].isdigit() and ord(t[i])<128:value=f(f(value*10)+int(t[i]));i+=1
 if i<len(t) and t[i]=='.':
  i+=1
  while i<len(t) and t[i].isdigit() and ord(t[i])<128:den=f(den*10);value=f(f(value*10)+int(t[i]));i+=1
 return f(value/den)
def actor(i):return ACT+i*0x1100
def packet(i):return PACK+i*0x200
def idx(p):return (p-LOC)//0x3c if p else -1
def aid(p):return (p-ACT)//0x1100 if p else -1
def string(p):return n.read(p,256).split(b'\0')[0].decode('ascii')
events=[];checks={};errors=[];vectors=[];current={}
def ret(mu,value):
 sp=mu.reg_read(UC_X86_REG_ESP);ip=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,u(value));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ip)
def named(name):return -1 if name.lower().startswith('missing') else 1+sum(name.lower().encode())%2
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);a=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==0x6e69ef:
  fmt=string(a(1))
  if fmt=='%s_%d':text=string(a(2))+'_'+str(si(a(3)))
  elif fmt=='%s_%s':text=string(a(2))+'_'+string(a(3))
  elif '%' not in fmt:text=fmt
  else:raise ValueError('Unbounded format: '+fmt)
  assert len(text)<64;n.write(a(0),text.encode()+b'\0');ret(mu,len(text))
 elif address in [ADAPTER,0x440120]:
  name=string(a(1));events.append(['reference' if address==ADAPTER else 'object',name]);ix=named(name);ret(mu,actor(ix) if ix>=0 else 0)
 elif address==0x51ac10:events.append(['find',string(a(1))])
 elif address in [0x5728a0,0x572660]:events.append(['refresh' if address==0x5728a0 else 'terrain',aid(a(0))]);ret(mu,0)
for a in [0x6e69ef,ADAPTER,0x440120,0x51ac10,0x5728a0,0x572660]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
position_offsets=[0x5c,0x80,0x8c,0x98,0x1b4,0x1cc,0x10bc]
def context(tokens,options):
 names=['Original','duplicate','DUPLICATE'];base=[]
 for t in tokens:
  a=t.lower().find('name')
  if a>=0 and a+5<=len(t):base.append(t[a+5:])
 for name in base:
  if name.lower().startswith('missing'):continue
  for text in [name]+[name+'_'+x for x in ['0','1','2','4','-2','Self','Other','Third']]:
   # Actual locator record has only16 bytes before its position fields.
   if len(text)<=15 and text not in names:names.append(text)
 if options.get('gap'):
  names=[x for x in names if not x.endswith('_1')]
 records=[dict(name=name,position=[bits(10.+i),bits(20.+i),bits(30.+i)],heading=u(0x12340000+0x4321+i),orientation=[u(0x3f123400+i*16+j) for j in range(6)]) for i,name in enumerate(names)]
 if options.get('tie'):
  for r in records:r['position']=[bits(1.),bits(2.),bits(3.)]
 return dict(records=records,position=[bits(x) for x in options.get('position',[15.,25.,35.])],reference=options.get('reference',True),creature=options.get('creature',True),worldObject=options.get('worldObject',0),indices=options.get('indices',[4,-2,-1]),characterNames=options.get('characterNames',['Self','Other','Third']),callback=options.get('callback',True),selected=options.get('selected',1),spawnLocator=options.get('spawnLocator',0),seed=options.get('seed',1),resetVelocity=[bits(x) for x in options.get('resetVelocity',[0.,0.,0.])],players=options.get('players',[1,2]))
def setup(c,tokens):
 n.write(D,bytes(0x70000));events.clear();n.pack('<II',SYS+0x24,len(c['records']),LOC);n.pack('<I',CRE+0xd0,actor(0) if c['reference'] else 0);n.pack('<3I',CRE+0x14c,*c['position'])
 for j,r in enumerate(c['records']):
  p=LOC+j*0x3c;n.write(p,r['name'].encode()+b'\0');n.pack('<3I',p+0x10,*r['position']);n.pack('<I',p+0x1c,r['heading']);n.pack('<6I',p+0x20,*r['orientation'])
 for j in range(3):
  p=actor(j);n.pack('<I',p,actor(c['worldObject']) if j==0 and c['worldObject']>=0 else (0 if j==0 else p));n.pack('<I',p+4,packet(j));n.pack('<I',packet(j)+0xa4,LOC+c['selected']*0x3c if c['selected']>=0 else 0);n.pack('<I',p+0x36c,LOC+c['spawnLocator']*0x3c if c['spawnLocator']>=0 else 0);n.pack('<b',p+0x280,c['indices'][j])
  if c['characterNames'][j] is not None:n.pack('<I',p+0x54,NAMES+j*0x100);n.pack('<I',NAMES+j*0x100+0xc,NAMES+j*0x100+0x30);n.write(NAMES+j*0x100+0x30,c['characterNames'][j].encode()+b'\0')
  for off in position_offsets:n.pack('<3I',p+off,*[bits(j+off/16+x) for x in range(3)])
  n.pack('<3I',p+0x68,bits(8.),bits(9.),bits(10.));n.pack('<HH',p+0x58,0x1111,0x2222);n.pack('<H',p+0x27a,0x3333);n.pack('<6I',p+0x420,*range(6))
 n.pack('<I',CALLER+4,NAMES+0x800);n.pack('<4f',CALLER+0x14,2.75,1.5,3.,4.)
 for j,name in enumerate(['alpha','beta','gamma','delta']):n.pack('<I',NAMES+0x818+j*8,NAMES+0x900+j*32);n.write(NAMES+0x900+j*32,name.encode()+b'\0')
 for j,t in enumerate(tokens):n.pack('<I',ARGS+j*4,TEXT+j*256);n.write(TEXT+j*256,t.encode()+b'\0')
 n.pack('<I',0x923904,ADAPTER if c['callback'] else 0);n.pack('<I',0x8066c0,c['seed']);n.pack('<3I',0x93b0cc,*c['resetVelocity']);n.pack('<3I',0x93d620,0x1234,0x5678,0x9abc)
 for j,ix in enumerate(c['players']):n.pack('<I',0x93d7f0+4*j,actor(ix) if ix>=0 else 0)
def snapshot():
 return [dict(selected=idx(n.unpack('<I',packet(j)+0xa4)[0]),spawnLocator=idx(n.unpack('<I',actor(j)+0x36c)[0]),positions=[list(n.unpack('<3I',actor(j)+o)) for o in position_offsets],angles=[n.unpack('<H',actor(j)+o)[0] for o in [0x58,0x5a,0x27a]],orientation=list(n.unpack('<6I',actor(j)+0x420)),velocity=list(n.unpack('<3I',actor(j)+0x68))) for j in range(3)]
def model(command,tokens,c,before,first):
 out=json.loads(json.dumps(before));e=[];rs=c['seed'];global_origin=[0x1234,0x5678,0x9abc]
 def find(name):
  e.append(['find',name]);return next((i for i,r in enumerate(c['records']) if r['name'].lower()==name.lower()),-1)
 def formatname(name,actorix,indexed,personal,rand):
  nonlocal rs
  if indexed and c['indices'][actorix]!=-1:return name+'_'+str(c['indices'][actorix])
  if personal and c['characterNames'][actorix] is not None:return name+'_'+c['characterNames'][actorix]
  if rand:rs=rng(rs);return name+'_'+str(si(rs)%abs(rand))
  return name
 own=0 if c['creature'] and c['reference'] else -1
 if first and (command!='SetLocator' or tokens):
  target=own if command=='SetLocator' else (c['worldObject'] if own>=0 else -1);name=None;personal=indexed=nearest=False;rand=0;terrain=True
  for t in tokens:
   low=t.lower()
   if command=='SetLocator':
    if 'name=' in low:name=t[low.index('name=')+5:]
    elif low=='personal':personal=True
    elif low=='indexed':indexed=True
    elif low=='nearest':nearest=True
    elif 'random=' in low:rand=int(number(t[low.index('random=')+7:]))
    elif 'character=' in low and c['callback']:s=t[low.index('character=')+10:];e.append(['reference',s]);target=named(s)
   else:
    if 'name' in low:name=t[low.index('name')+5:]
    elif 'personal' in low:personal=True
    elif 'indexed' in low:indexed=True
    elif 'random' in low:rand=int(number(t[low.index('random')+9:]))
    elif 'character' in low:s=t[low.index('character')+10:];e.append(['object',s]);target=named(s)
    elif 'player=' in low:
     player=int(number(t[low.index('player=')+7:]))
     if player in [1,2]:target=c['players'][player-1]
    elif 'dont_check_terrain' in low:terrain=False
  if command=='SetLocator':
   selected=-1
   if name is not None:
    if nearest:
     best=1e9;j=0
     while True:
      ix=find(name+'_'+str(j));j+=1
      if ix<0:break
      d=[f(fl(a)-fl(b)) for a,b in zip(c['position'],c['records'][ix]['position'])];dist=f(sum(x*x for x in d))
      if dist<best:best=dist;selected=ix
    elif c['creature']:selected=find(formatname(name,0,indexed,personal,rand))
   if target>=0:out[target]['selected']=selected
  else:
   if target<0 and own>=0:target=c['worldObject']
   if target>=0:
    selected=out[target]['spawnLocator'] if name is None else find(formatname(name,target,indexed,personal,rand))
    if selected>=0:
     r=c['records'][selected];a=out[target];a['positions']=[list(r['position']) for _ in position_offsets];a['angles']=[r['heading']&65535]*3;a['orientation']=r['orientation'];a['velocity']=c['resetVelocity'];global_origin=r['position'];e.append(['refresh',target])
     if terrain:e.append(['terrain',target])
 return dict(actors=out,events=e,rng=rs,globalOrigin=global_origin,result=1)
def check(kind,got,want,meta):
 checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,got=got,want=want,input=meta))
def run(command,tokens,options=None,first=True,source=None):
 c=context(tokens,options or {});setup(c,tokens);before=snapshot();retvalue=n.call(0x445cf0 if command=='SetLocator' else 0x446060,[SYS,CALLER,CRE if c['creature'] else 0,ARGS,len(tokens),int(first)])
 got=dict(actors=snapshot(),events=list(events),rng=n.unpack('<I',0x8066c0)[0],globalOrigin=list(n.unpack('<3I',0x93d620)),result=retvalue);want=model(command,tokens,c,before,first)
 for key in got:check(command+'-'+key,got[key],want[key],dict(tokens=tokens,context=c,first=first,source=source))
 vectors.append(dict(command=command,tokens=tokens,context=c,first=first,source=source,before=before,native=got))

if __name__=='__main__':
 for command in ['SetLocator','SnapToLocator']:
  for tokens in [[],['name=Target'],['name=missing'],['ignored'],['name=One','name=Two'],['name=Target','indexed'],['name=Target','personal'],['name=Target','indexed','personal'],['name=Target','character=Other'],['name=Target','character=missing'],['name=Target','random=1234'],['name=Target','dont_check_terrain'],['name=Target','player=2'],['prefixNAME=Target','prefixindexed']]:
   for first in [False,True]:
    for options in [{},{'worldObject':1},{'callback':False},{'indices':[-1,-1,-1],'characterNames':[None,None,None]}]:run(command,tokens,options,first)
 for tokens in [['name=Near','nearest'],['name=Near','nearest','personal','indexed'],['name=Near','character=Other','nearest']]:
  for o in [{},{'gap':True},{'tie':True},{'position':[50000.,50000.,50000.]}]:run('SetLocator',tokens,o)
 for command in ['SetLocator','SnapToLocator']:
  for tokens in [[],['ignored'],['character=Other'],['name=Target']]:
   for o in [{'creature':False},{'worldObject':-1}]:run(command,tokens,o)
  for use in uses[command]:
   for options in [{},{'worldObject':1},{'callback':False}]:run(command,use['args'],options,source={k:use[k] for k in ['source','line','text']})
 # Original condition stores float return and tests real packet locator field.
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT))
 conditions=[]
 for use in uses['GotLocator']:
  for pointer in [0,LOC,0xdeadbeef]:
   n.pack('<I',PACK+0xa4,pointer);n.call(0x514ae0,[SYS,PACK]);n.mu.emu_start(n.STOP,n.STOP+6);value=n.unpack('<I',RESULT)[0];check('GotLocator-presence',value,bits(1. if pointer else 0.),use);conditions.append(dict(source=use['source'],line=use['line'],pointerPresent=bool(pointer),nativeBits=value))
 result=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:12],authoredOccurrences={k:len(v) for k,v in uses.items()},cases=len(vectors),conditionCases=len(conditions),method='Unmodified PC handlers, real ordered0x51ac10 lookup, native numeric/RNG and squared-distance helpers. Bounded CRT name-formatting, character binding and terrain callbacks are explicit adapters.',limits=['Synthetic locator and actor tables; not runtime source attachment or actual level reachability.','No format directives, overlong native name buffers, invalid actor packet pointers, or nonfinite/overflow numeric operands.','Snap terrain refresh/check internals are recorded callback boundaries, not reconstructed by this suite.','Condition cases establish pointer presence only, not locator validity or source condition-chain execution.','Compiled C# execution remains pending.'])
 (BASE/'reports/gameplay-locator-binding-tests.json').write_text(json.dumps(result,indent=2),encoding='utf8')
 (BASE/'reports/gameplay-locator-binding-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors,conditions=conditions),separators=(',',':')),encoding='utf8')
 print(json.dumps(result))
 if errors:raise SystemExit(1)
