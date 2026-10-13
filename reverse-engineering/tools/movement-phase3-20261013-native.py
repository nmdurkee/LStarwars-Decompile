"""Original BigJump action/request with retained full byte-image comparisons.
Only broader reset, clip selection/duration/invalidation and simple printf formatting
are boundary services. Control reset, locator lookup, heading and RNG execute native.
"""
import importlib.util,json,struct,itertools,hashlib,gzip,random
from fractions import Fraction
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=m.NativeX86();B=m.BASE;D=n.DATA;ACTOR=D;DEFINITION=D+0x2000;PAD=D+0x3000;WORLD=D+0x4000;CREATURE=D+0x5000;REFERENCE=D+0x6000;PACKET=D+0x7000;SCRIPT=D+0x8000;LOCATORS=D+0x10000;TOKENS=D+0x20000;TEXT=D+0x21000;TARGET=D+0x30000;SOUND=D+0x31000;DURATION_VALUE=D+0x32000;SELECT=n.STOP+0x100;DURATION_STUB=n.STOP+0x180;SIZE=0x10d8
angles=list(n.unpack('<513H',0x8066c8));events=[];captures={};options={}
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def val(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def signed(v):return v if v<0x80000000 else v-0x100000000
def word16(v):v&=65535;return v if v<32768 else v-65536
def frac(v):return Fraction(float(v))
def quant(v,precision):
 if not v:return Fraction(0)
 sign=-1 if v<0 else 1;n0=abs(v.numerator);d=v.denominator;e=n0.bit_length()-d.bit_length()
 if(n0<d<<e if e>=0 else n0<<-e<d):e-=1
 step=e-(precision-1);nn=n0<<-step if step<0 else n0;dd=d<<step if step>=0 else d;q,r=divmod(nn,dd)
 if 2*r>dd or(2*r==dd and q&1):q+=1
 return sign*(Fraction(q<<step)if step>=0 else Fraction(q,1<<-step))
def store(v,zero_sign=0):
 if not v:return val(zero_sign&0x80000000)
 return f32(float(quant(v,24)))
def product(a,b):return store(quant(frac(a)*frac(b),64),bits(a)^bits(b))
def subtraction(a,b):return store(quant(frac(a)-frac(b),64),bits(a)&(bits(b)^0x80000000))
def heading(x,z):
 if x==0:return 32768 if z<0 else 0
 if z==0:return 49152 if x<0 else 16384
 a,b=abs(x),abs(z);invert=b<a;ratio=quant(quant(frac(b if invert else a)*512,64)/frac(a if invert else b),64);ix=int(ratio);q=16384-angles[ix]if invert else angles[ix]
 return(q+32768 if z<0 else-q)if x<0 else(32768-q if z<0 else q)
def cstr(address):
 a=bytearray()
 for i in range(512):
  b=n.read(address+i,1)[0]
  if not b:return a.decode('ascii')
  a.append(b)
 raise ValueError('Prepared string did not terminate')
def return_int(mu,ret,sp,value):mu.reg_write(UC_X86_REG_EAX,value&0xffffffff);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
def hook(mu,address,size,user):
 if address==0x44661e:
  captures.setdefault('randomDraws',[]).append(signed(mu.reg_read(UC_X86_REG_EAX)));return
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if address==0x55e4a0:
  events.append(['reset',n.unpack('<I',sp+8)[0]])
  if options.get('mutate'):
   n.pack('<I',0x80283c,32);n.pack('<I',ACTOR+0xef0,0xabcdef01)
  return_int(mu,ret,sp,0)
 elif address==SELECT:
  events.append(['select',n.unpack('<B',ACTOR+0x7b5)[0],n.unpack('<B',ACTOR+0x7b4)[0]])
  if options.get('mutate'):n.pack('<h',ACTOR+0x1064,77)
  return_int(mu,ret,sp,options['animation'])
 elif address==0x62e040:
  a=n.unpack('<5I',sp+4);events.append(['duration',signed(a[0]),signed(a[1])]);mu.reg_write(UC_X86_REG_EIP,DURATION_STUB)
 elif address==0x62e650:
  events.append(['invalidate',n.unpack('<I',sp+4)[0]-ACTOR,n.unpack('<I',sp+8)[0]]);return_int(mu,ret,sp,0)
 elif address==0x547f30:
  events.append(['feedback',n.unpack('<I',sp+8)[0]])
  if options.get('mutate'):
   n.pack('<I',ACTOR+0x4b0,0x200);n.pack('<I',ACTOR+0x7bc,0x300)
  return # real sound selector executes; all prepared sound IDs are -1
 elif address==0x6e69ef:
  dest,fmt=n.unpack('<2I',sp+4);form=cstr(fmt)
  if form=='%s_%d':name,index=n.unpack('<2I',sp+12);output=cstr(name)+'_'+str(signed(index))
  elif form=='%s_%s':name,suffix=n.unpack('<2I',sp+12);output=cstr(name)+'_'+cstr(suffix)
  else:
   if'%'in form:raise ValueError('Unbound printf directive outside prepared domain')
   output=form
  if len(output)>63:raise ValueError('Prepared name outside native64-byte scratch')
  n.write(dest,output.encode()+b'\0');return_int(mu,ret,sp,len(output))
 elif address==0x51ac10:events.append(['lookup',cstr(n.unpack('<I',sp+8)[0])]);return
for va in [0x55e4a0,SELECT,0x62e040,0x62e650,0x547f30,0x6e69ef,0x51ac10,0x44661e]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=va,end=va)
n.write(DURATION_STUB,b'\xd9\x05'+struct.pack('<I',DURATION_VALUE)+b'\xc3')
ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());authored=next(r for r in ledger['rows']if r['kind']=='scp-action'and r['name']=='BigJumpToLocator')
names=['L','L_0','L_-128','L_3','L_Hero','A','B']+list(dict.fromkeys(t[5:]for u in authored['uses']for t in u['args']if t.startswith('name=')))
# Only native locator names fitting their16-byte field are allocated.
assert all(len(s)<16 for s in names)
records=[]
for i,name in enumerate(names):records.append({'name':name,'position':[bits(4.125+i*.25),bits(-7.875+i*.5),bits(-.5+i*.125)],'orientation':[(0x7fc00000+i*19+j*0x10203)&0xffffffff for j in range(6)]})
def setup(meta,tokens=None):
 n.write(D,bytes(0x33000));events.clear();captures.clear();options.clear();options.update(meta)
 n.pack('<I',ACTOR+0x54,DEFINITION);n.pack('<I',DEFINITION+4,meta.get('definitionFlags',0));n.pack('<I',DEFINITION+0xc,TEXT+0x1000);n.write(TEXT+0x1000,b'Hero\0')
 n.pack('<3f',ACTOR+0x5c,1.25,2.5,-3.75);n.pack('<f',ACTOR+0xff0,.6);n.pack('<f',ACTOR+0xa8,1.5)
 n.pack('<I',ACTOR+0xca4,PAD);n.pack('<H',PAD+0x5a,0xffff);n.pack('<I',ACTOR+0x7bc,0xffffffff);n.pack('<I',ACTOR+0xef0,0x12345678);n.pack('<I',ACTOR+0x4b0,0xa5a5a5a5)
 n.pack('<B',ACTOR+0x7b5,meta.get('initialContext',255));n.pack('<b',ACTOR+0x280,meta.get('index',-1));n.pack('<h',ACTOR+0x1064,-17)
 n.pack('<I',0x80283c,meta.get('context',31)&0xffffffff);n.pack('<h',0x804c0c,61);n.pack('<I',0x802d98,SELECT);n.pack('<I',0x80253c,meta.get('controlSeed',12345));n.pack('<I',0x8066c0,123)
 n.pack('<I',0x8020bc,SOUND)
 for offset in range(0x158,0x166,2):n.pack('<h',SOUND+offset,-1)
 n.pack('<f',DURATION_VALUE,val(meta.get('duration',bits(1.25))));n.pack('<3I',TARGET,*meta.get('position',records[0]['position']))
 n.pack('<I',REFERENCE,ACTOR);n.pack('<I',CREATURE+0xd0,REFERENCE);n.pack('<I',WORLD+0x24,len(records));n.pack('<I',WORLD+0x28,LOCATORS)
 for i,r in enumerate(records):
  p=LOCATORS+i*0x3c;n.write(p,r['name'].encode()+b'\0');n.pack('<3I',p+0x10,*r['position']);n.pack('<6I',p+0x20,*r['orientation'])
 selected=meta.get('selected',0);active=meta.get('active',5);n.pack('<I',PACKET+0xa4,0 if selected<0 else LOCATORS+selected*0x3c);n.pack('<I',PACKET+0x6c,0 if active<0 else LOCATORS+active*0x3c)
 n.pack('<I',PACKET+4,SCRIPT);n.pack('<4f',PACKET+0x14,.5,2,-1,7);n.pack('<I',SCRIPT+0x18,TEXT+0x1100);n.write(TEXT+0x1100,b'factor\0')
 if tokens is not None:
  cursor=TEXT
  for i,text in enumerate(tokens):n.write(cursor,text.encode()+b'\0');n.pack('<I',TOKENS+i*4,cursor);cursor+=len(text)+8
 return bytearray(n.read(ACTOR,SIZE))
def model_request(image,meta,ev):
 global model_context,model_control
 def u32(p):return struct.unpack_from('<I',image,p)[0]
 def set32(p,x):struct.pack_into('<I',image,p,x&0xffffffff)
 def set16(p,x):struct.pack_into('<H',image,p,x&65535)
 def fl(p):return val(u32(p))
 def sf(p,x):set32(p,bits(x))
 if model_context==-1 or meta.get('definitionFlags',0)&0x200000:return 0
 ev.append(['reset',0])
 if meta.get('mutate'):model_context=32;set32(0xef0,0xabcdef01)
 S=0x6c4;set32(S+0xfc,0);image[S+0x100]=255;sf(S+0x678,1 if image[S+0x75e]&1 else 0);sf(S+0x67c,5);image[S+0xf1]=255
 for p in [0x76f,0xf5,0xf4,0xee,0x76e]:image[S+p]=0
 for p in [0x66c,0x674,0x664,0x65c,0x648,0x694,0x698,0x670,0x6d0,0x6e8,0x700,0x714,0x720,0x724,0x60c]:set32(S+p,0)
 set32(S+0x75c,u32(S+0x75c)&~0x400);model_control=(model_control*0x24cd+1)&65535;image[S+0x77d]=model_control>>15;set16(S+0xe8,0)
 for p in [0x74c,0x750,0x752]:set16(S+p,65535)
 image[0x7b4]=meta.get('mode',0)&255;image[0x7b5]=model_context&255;image[0x7b3]=1;ev.append(['select',image[0x7b5],image[0x7b4]])
 if meta.get('mutate'):set16(0x1064,77)
 animation=word16(meta.get('animation',-3));set16(0x7aa,animation);ev.append(['duration',word16(struct.unpack_from('<H',image,0x1064)[0]),animation]);duration=val(meta.get('duration',bits(1.25)));sf(0x784,duration)
 if duration==0:sf(0x784,1);set16(0x7aa,61)
 else:ev.append(['invalidate',8,0xffffffff])
 set32(0x748,u32(0x5c));sf(0x784,product(val(meta.get('speed',bits(1))),fl(0x784)));set32(0x74c,u32(0x60));set32(0x77c,0);set32(0x750,u32(0x64));position=meta.get('position',records[0]['position'])
 for i,v in enumerate(position):set32(0x754+i*4,v)
 sf(0x758,store(quant(frac(fl(0x758))-quant(frac(fl(0xff0))*frac(fl(0xa8)),64),64)))
 angle=heading(subtraction(val(position[0]),fl(0x748)),subtraction(val(position[2]),fl(0x750)))
 for p in[0x5a,0x58,0x27a]:set16(p,angle)
 set32(0xef0,u32(0xef0)^(((meta.get('directed',0)<<13)^u32(0xef0))&0x2000));ev.append(['feedback',2])
 if meta.get('mutate'):set32(0x4b0,0x200);set32(0x7bc,0x300)
 set32(0x4b0,u32(0x4b0)|0x2000000);factor=val(meta.get('factor',bits(1)));sf(0xf0c,factor);set32(0x44c,0);set32(0x7bc,u32(0x7bc)&0xfffffeff)
 if factor<0:set32(0xf0c,0)
 return 1
report={'binarySha256':n.sha256,'cases':0,'assertions':0,'errors':[],'groups':{},'vectors':[],'records':records,'angleTable':angles,'authoredOccurrences':0}
def compare(group,meta,before,result,image,want_events,want_result,active=None):
 actual=n.read(ACTOR,SIZE);wanted_pad=0xffeb if want_events and any(e[0]=='reset'for e in want_events)else 0xffff
 observed=[result,actual.hex(),n.unpack('<H',PAD+0x5a)[0],n.unpack('<I',0x80253c)[0],list(events)]
 expected=[want_result,bytes(image).hex(),wanted_pad,model_control,want_events]
 if active is not None:
  pointer=n.unpack('<I',PACKET+0x6c)[0];ix=-1 if pointer==0 else(pointer-LOCATORS)//0x3c;observed.append(ix);expected.append(active)
 report['cases']+=1;report['assertions']+=len(expected);report['groups'][group]=report['groups'].get(group,0)+1
 if observed!=expected:
  differing=[hex(i)for i,(a,b)in enumerate(zip(actual,image))if a!=b];report['errors'].append({'group':group,'input':meta,'byteDifferences':differing[:20],'actual':observed[:1]+observed[2:],'expected':expected[:1]+expected[2:]})
 report['vectors'].append({'group':group,'input':meta,'beforeActorHex':before.hex(),'native':observed,'randomDraws':captures.get('randomDraws',[])})
for context,definition,duration,factor,speed,directed,mode in itertools.product([-1,31,287],[0,0x200000],[0,1.25],[-2,-0.,.5],[0,1,2],[0,1,2],[0,255]):
 meta={'context':context,'definitionFlags':definition,'duration':bits(duration),'factor':bits(factor),'speed':bits(speed),'directed':directed,'mode':mode,'animation':-3,'controlSeed':[0,1,12345,65535][report['cases']%4]};before=setup(meta);image=bytearray(before);ev=[];model_context=context;model_control=meta['controlSeed'];expected=model_request(image,meta,ev);result=n.call(0x561e20,[ACTOR,TARGET,directed,bits(factor),bits(speed),mode]);compare('Request',meta,before,result,image,ev,expected)
for pos,duration,mutation in itertools.product([[bits(x),bits(2.5),bits(z)]for x,z in [(1.25,-3.75),(0,0),(-10,1),(1,-10),(1.2500001192092896,-3.750000238418579)]],[0,1.25],[0,1]):
 meta={'context':31,'duration':bits(duration),'factor':bits(.5),'speed':bits(1),'animation':-32768,'position':pos,'mutate':mutation,'controlSeed':12345};before=setup(meta);image=bytearray(before);ev=[];model_context=31;model_control=12345;expected=model_request(image,meta,ev);result=n.call(0x561e20,[ACTOR,TARGET,0,bits(.5),bits(1),0]);compare('RequestComposition',meta,before,result,image,ev,expected)
def numeric(s):
 s=s.split('\0')[0]
 if 'param'in s.lower():return .5
 if s.lower()=='factor':return .5
 i=0;v=0.;div=1.
 if s.startswith('-'):div=-1.;i=1
 while i<len(s)and'0'<=s[i]<='9':v=f32(f32(v*10)+ord(s[i])-48);i+=1
 if i<len(s)and s[i]=='.':
  i+=1
  while i<len(s)and'0'<=s[i]<='9':div=f32(div*10);v=f32(f32(v*10)+ord(s[i])-48);i+=1
 return f32(v/div)
def jump_action(meta,tokens,group='ToLocator',auth=None):
 global model_context,model_control
 before=setup(meta,tokens);image=bytearray(before);ev=[];model_context=meta.get('context',31);model_control=meta.get('controlSeed',12345);active=meta.get('active',5);selected=meta.get('selected',0);gate=meta.get('gate',3);first=meta.get('first',1);creature=CREATURE
 if gate==0:creature=0
 elif gate==1:n.pack('<I',CREATURE+0xd0,0)
 elif gate==2:n.pack('<I',REFERENCE,0)
 if gate!=3:done=1
 else:
  if first:
   active=selected;name=None;personal=False;indexed=False;random_count=0;factor=1
   for t in tokens:
    t=t.split('\0')[0];low=t.lower()
    if 'name'in low:name=t[low.index('name')+5:]
    elif 'personal'in low:personal=True
    elif 'indexed'in low:indexed=True
    elif 'random'in low:random_count=int(numeric(t[low.index('random')+9:]))
    elif 'jump_factor='in low:factor=numeric(t[low.index('jump_factor=')+12:]);factor=max(factor,0)
   if name is not None:
    index=meta.get('index',-1)
    if indexed and index!=-1:name=name+'_'+str(index)
    elif personal:name=name+'_Hero'
    elif random_count:
     seed=123^0x75bd924;k=(abs(signed(seed))//0x1f31d)*(-1 if signed(seed)<0 else 1);r=(seed*0x41a7-k*0x7fffffff)&0xffffffff
     if signed(r)<0:r=(r+0x7fffffff)&0xffffffff
     draw=signed(r^0x75bd924);remainder=draw-int(draw/random_count)*random_count;name=name+'_'+str(remainder)
    ev.append(['lookup',name]);active=next((i for i,r in enumerate(records)if r['name'].lower()==name.lower()),-1)
   if active>=0:
    req={**meta,'position':records[active]['position'],'factor':bits(factor),'speed':bits(1),'mode':0,'directed':0};model_request(image,req,ev)
    for i,v in enumerate(records[active]['orientation']):struct.pack_into('<I',image,0x420+i*4,v)
    for i,v in enumerate(records[active]['position']):struct.pack_into('<I',image,0x438+i*4,v)
  done=int(image[0x7b5]!=31)
 result=n.call(0x446450,[WORLD,PACKET,creature,TOKENS,len(tokens),first],count=1000000);input={**meta,'tokens':tokens}
 if auth:input['authored']=auth
 compare(group,input,before,result,image,ev,done,active)
sets=[[],['name=L'],['name=Missing'],['name=L','jump_factor=-2'],['name=L','jump_factor=param3'],['name=L','personal'],['name=L','indexed'],['name=L','randomix=3'],['name=A','name=B'],['xname=L'],['jump_factor=.5'],['.5'],['name=L','personalindexed'],['name=L','indexed','personal'],['name=L','jump_factor=0.5\0FALSE']]
for first,gate,selected,context,index,tokens in itertools.product([0,1],range(4),[-1,0],[31,-1],[-128,-1,3],sets):
 meta={'first':first,'gate':gate,'selected':selected,'active':5,'initialContext':context&255,'context':31,'index':index,'animation':-3,'duration':bits(1.25),'controlSeed':12345};jump_action(meta,tokens)
for use in authored['uses']:
 meta={'first':1,'gate':3,'selected':0,'active':5,'initialContext':255,'context':31,'index':-1,'animation':-3,'duration':bits(1.25),'controlSeed':12345};jump_action(meta,use['args'],'AuthoredBigJump',use);report['authoredOccurrences']+=1
report['method']='Original446450 action and561e20 request;55e4e0 control reset,54fa60/5b9e90 RNG,51ac10 locator lookup,5be2d0/5be030 heading,547f30 muted feedback selector execute unchanged. Broader reset/clip metadata services and basic bounded printf formatting adapted. Whole actor+pad byte comparisons, argument/event order and completion return.'
report['adapters']=[{'address':'0x55e4a0','behavior':'Records broad reset; optional explicit actor/global mutations.'},{'address':hex(SELECT),'behavior':'Prepared animation selector, optional model mutation.'},{'address':'0x62e040','behavior':'Prepared float32 duration returned via literal x87-load stub.'},{'address':'0x62e650','behavior':'Records actor+8 invalidation boundary.'},{'address':'0x6e69ef','behavior':'Bounded basic printf name formatting; no format directives in plain name.'}]
report['limits']=['Finite positions,durations,speed factors and arithmetic; valid loaded actor/reference/pad/definition/locator images.','Explicit clip/reset boundaries, sound IDs-1 so native feedback selector performs no actual playback.','All87 cataloged authored forms exercised against prepared matching locator names, not original scene positions/reachability.','Original printf undefined format/overflow behavior and fixed random substring skips past terminator excluded.','Original native/Python own-state contract verified; C# compiled replay remains separate and pending.']
report['sourceEvidence']=[{'address':hex(va),'path':'decompiled/corpus-expanded/FUN_'+hex(va)[2:]+'.c','sha256':hashlib.sha256((B/('decompiled/corpus-expanded/FUN_'+hex(va)[2:]+'.c')).read_bytes()).hexdigest()}for va in[0x446450,0x561e20]]
report['returnCorrection']='Original4466d6..4466e4 computesactorcontextbyte!=31; Ghidra pseudocode incorrectly declaresvoid and omitscompletionresult.'
report['toolSha256']=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
with gzip.open(B/'reports/movement-phase3-20261013-fixtures.json.gz','wb')as f:f.write((json.dumps(report,separators=(',',':'))+'\n').encode())
summary={k:v for k,v in report.items()if k not in['vectors','angleTable','records']};(B/'reports/movement-phase3-20261013-tests.json').write_text(json.dumps(summary,indent=2)+'\n')
assembly={hex(va):[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(va,size),va)]for va,size in[(0x446450,0x2ba),(0x561e20,0x1e9)]};(B/'reports/movement-phase3-20261013-assembly.json').write_text(json.dumps(assembly,indent=2)+'\n')
print(json.dumps({k:summary[k]for k in['cases','assertions','groups','authoredOccurrences','errors']}));raise SystemExit(bool(report['errors']))
