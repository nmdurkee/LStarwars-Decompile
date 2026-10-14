"""Isolated original514920/514850/5147c0 and real parser; callback alone supplied."""
import importlib.util,json,struct,itertools,random,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));nm=importlib.util.module_from_spec(s);s.loader.exec_module(nm);n=nm.NativeX86()
s=importlib.util.spec_from_file_location('w',Path(__file__).with_name('animation-x87.py'));w=importlib.util.module_from_spec(s);s.loader.exec_module(w)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
D=n.DATA;P=D+0x1000;P2=D+0x1200;SCRIPT=D+0x2000;SCRIPT2=D+0x2200;TEXT=D+0x3000;NAMES=D+0x4000;OUT=D+0x5000;CB=n.STOP+0x600
segments=[(D,0x6000),(0x92224c,0x18),(0x9238c0,4),(0x95e5d4,4)]
config={};events=[];shadow={};ordinal=0;checks=0;errors=[];cases=[];traces=set()
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def rb(p):return shadow[p]
def wb(p,v):shadow[p]=v&255
def rd(p):return sum(rb(p+i)<<(8*i)for i in range(4))
def wd(p,v):
 for i in range(4):wb(p+i,v>>(8*i))
def text(p,model):
 read=rb if model else lambda p:n.unpack('<B',p)[0];s=[]
 while read(p):s.append(chr(read(p)));p+=1
 return ''.join(s)
def fold(s):return ''.join(chr((ord(c)-32)&255)if 97<=ord(c)<=122 or ord(c)>=224 else c for c in s)
def add(a,b):return fl(bits(a)&bits(b)&0x80000000)if a==0 and b==0 else w.store(w.add(w.wide(a),w.wide(b)))
def mul(a,b):return fl((bits(a)^bits(b))&0x80000000)if a==0 or b==0 else w.store(w.mul(w.wide(a),w.wide(b)))
def div(a,b):return fl((bits(a)^bits(b))&0x80000000)if a==0 else w.store(w.div(w.wide(a),w.wide(b)))
def number(s):
 i=0;v=0.;d=1.
 if s.startswith('-'):i=1;d=-1.
 while i<len(s)and '0'<=s[i]<='9':v=add(mul(v,10.),ord(s[i])-48);i+=1
 if i<len(s)and s[i]=='.':
  i+=1
  while i<len(s)and '0'<=s[i]<='9':d=mul(d,10.);v=add(mul(v,10.),ord(s[i])-48);i+=1
 return div(v,d)
def parameter(packet,name):
 if packet:
  if 'PARAM'in fold(name):return rd(packet+0x14)
  if rd(packet+4):
   for i in range(4):
    p=rd(rd(packet+4)+0x18+i*8)
    if p and fold(text(p,True))==fold(name):return rd(packet+0x14+i*4)
 return bits(number(name))
def port(name,creature,packet,model):
 global ordinal
 ordinal+=1;read=rd if model else lambda p:n.unpack('<I',p)[0]
 events.append(dict(name=name,creature=creature,packet=packet,globals=[read(0x92225c),read(0x922260)],parameters=[read(P+0x14+i*4)for i in range(4)]))
 for key in [name,name+'#'+str(ordinal)]:
  for p,size,v in config.get('patches',{}).get(key,[]):
   if model:
    for i in range(size):wb(p+i,v>>(8*i))
   else:n.write(p,int(v).to_bytes(size,'little'))
 value=config.get('symbolBits',{}).get(name,bits(config.get('symbol',7.25)))
 return config.get('handled',0),value

def hook(mu,address,size,data):
 if address in [0x514920,0x514850,0x5147c0,0x4f88e0,0x4f8420,0x4f8790,0x4f8830,0x4f8880,0x5b9dd0,0x6e6b90]:traces.add(hex(address))
 if address==CB:
  sp=mu.reg_read(UC_X86_REG_ESP);creature,packet,name,out=n.unpack('<4I',sp+4);handled,value=port(text(name,False),creature,packet,False);n.pack('<I',out,value);mu.reg_write(UC_X86_REG_EAX,handled);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address==0x4ef790:events.append(dict(error=True))
n.mu.hook_add(UC_HOOK_CODE,hook)
def resolve(name):
 lower=fold(name)
 if lower=='RAND':seed=(rd(0x95e5d4)*0x19660d+0x3c6ef35f)&0xffffffff;wd(0x95e5d4,seed);return bits((seed&0x7fffff)/(1<<23))
 if lower=='TRUE':return bits(1.)
 if lower=='FALSE':return 0
 if lower=='MAX':return 0x7f7fffff
 if rd(0x9238c0):
  packet=rd(0x922260);creature=rd(0x92225c);handled,value=port(name,creature,packet,True)
  if handled:return value
 return parameter(rd(0x922260),name)
class Parser:
 def __init__(self,p):self.p=p;self.index=0;self.kind=None;self.value=0.;self.steps=0
 def at(self):return rb(self.p+self.index)
 def next(self):
  self.steps+=1
  if self.steps>256:raise ValueError('native nonprogress')
  while self.at()in [32,9]:wb(self.p+self.index,self.at()+1)
  c=self.at()
  if c==0:self.kind=6;return
  kind={43:0,45:1,42:2,47:3,40:4,41:5,59:6}.get(c)
  if kind is not None:self.kind=kind;self.index+=c!=59;return
  if c==46 or 48<=c<=57:
   self.kind=7;self.value=0.;fraction=0.
   while self.at()==46 or 48<=self.at()<=57:
    c=self.at();self.index+=1
    if c==46:
     if fraction:events.append(dict(error=True))
     fraction=fl(bits(.1))
    elif fraction==0:self.value=add(mul(self.value,10.),c-48)
    else:self.value=w.store(w.add(w.mul(w.wide(c-48),w.wide(fraction)),w.wide(self.value)));fraction=div(fraction,10.)
   return
  if 65<=c<=90 or 97<=c<=122 or c==95:
   name=[]
   while 65<=self.at()<=90 or 97<=self.at()<=122 or 48<=self.at()<=57 or self.at()==95:name.append(chr(self.at()));self.index+=1
   self.kind=7;self.value=fl(resolve(''.join(name)));return
  if self.kind is None:raise ValueError('uninitialized lexer')
 def factor(self):
  if self.kind==1:self.next();return -self.factor()
  if self.kind==4:
   self.next();v=self.expression()
   if self.kind!=5:events.append(dict(error=True))
   self.next();return v
  if self.kind==6:return 1.
  if self.kind in [7,8]:
   if self.kind==8:events.append(dict(error=True))
   self.next();return self.value
  events.append(dict(error=True));return 0.
 def term(self):
  v=self.factor()
  while self.kind in [2,3]:k=self.kind;self.next();rhs=self.factor();v=mul(v,rhs)if k==2 else div(v,rhs)
  return v
 def expression(self):
  v=self.term()
  while self.kind in [0,1]:k=self.kind;self.next();rhs=self.term();v=add(v,rhs if k==0 else -rhs)
  return v
 def run(self):self.next();return bits(self.expression())
def evaluate(creature,packet,p):
 s=text(p,True)
 if all(-45<=(ord(c)-256 if ord(c)>=128 else ord(c))<=57 and c!='/'for c in s):return bits(number(s))
 wd(0x922260,packet);wd(0x92225c,creature);v=Parser(p).run();wd(0x922260,0);return v
def setup(c):
 n.write(D,bytes(0x6000));n.pack('<III',0x92225c,c.get('oldCreature',0x11111111),c.get('oldPacket',P),0);n.pack('<I',0x9238c0,CB if c.get('callback',True)else 0);n.pack('<I',0x95e5d4,c.get('seed',123));n.write(TEXT,c.get('text','alpha').encode('latin1')+b'\0');n.pack('<I',P+4,SCRIPT);n.pack('<I',P2+4,SCRIPT2)
 for i,name in enumerate(c.get('names',['alpha','beta','gamma','delta'])):
  np=NAMES+i*0x100
  if name is not None:n.write(np,name.encode('latin1')+b'\0')
  n.pack('<I',SCRIPT+0x18+i*8,np if name is not None else 0);n.pack('<I',SCRIPT2+0x18+i*8,NAMES+(3-i)*0x100);n.pack('<I',P+0x14+i*4,c.get('parameters',[bits(2.75),bits(1.5),bits(3.),bits(4.)])[i]);n.pack('<I',P2+0x14+i*4,bits(20.+i))
 n.pack('<II',OUT,0x12345678,0x87654321)
 for p,size,value in c.get('initialPatches',[]):n.write(p,int(value).to_bytes(size,'little'))
def snapshot(model=False):return [dict(address=p,bytes=bytes(rb(p+i)for i in range(z)).hex()if model else n.read(p,z).hex())for p,z in segments]
def execute(c,method='Evaluate'):
 global config,events,ordinal,shadow,checks
 config=c;setup(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal=0;creature=c.get('creature',D+0x5800);packet=c.get('packet',P);textp=c.get('textPointer',TEXT);fo=c.get('floatOutput',OUT);io=c.get('integerOutput',OUT+4)
 if method=='Evaluate':want=evaluate(creature,packet,textp)
 elif method=='Parameter':want=0 if not textp else parameter(packet,text(textp,True))
 else:
  value=fl(resolve(text(textp,True)));want=0
  if fo:wd(fo,bits(value))
  if io:wd(io,0 if value>=2**63 or value< -(2**63)else int(value)&0xffffffff)
 modelEvents=events.copy();modelFinal=snapshot(True);events=[];ordinal=0
 if method=='Evaluate':n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(0x514920,[creature,packet,textp]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0];wd(OUT+0x40,want);modelFinal=snapshot(True)
 elif method=='Parameter':n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT+0x40));n.call(0x5147c0,[packet,textp]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT+0x40)[0];wd(OUT+0x40,want);modelFinal=snapshot(True)
 else:got=n.call(0x514850,[textp,fo,io])
 final=snapshot();nativeEvents=events.copy()
 for key,a,b in [('return',got,want),('images',final,modelFinal),('events',nativeEvents,modelEvents)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=key,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(creature=creature,packet=packet,text=textp,floatOutput=fo,integerOutput=io),initial=initial,returnValue=got,final=final,nativeEvents=nativeEvents))
texts=['','-0','+5','.5','1+2','1*2','1/2','(1+2)/1','alpha','alpha+beta','alpha-beta','alpha*beta','alpha/beta','-(alpha+beta)','alpha+','alpha*',';','alpha;beta','1alpha','alpha beta','alpha\tbeta','(1.2.3)/1','(.12345678+alpha)/2','--alpha','+alpha','1+Rand','Rand+Rand','max/2','Rand Rand','alpha+custom','0/(-1)','((-0)+(-0))/1','(alpha','16777219/1','123456.789012345/1','param3','prefixPaRaM99','true','FALSE','max','_'*255]
for t,callback,packet,handled in itertools.product(texts,[False,True],[0,P],[0,1]):
 if packet==0 and ('/beta'in t):continue
 execute(dict(text=t,callback=callback,packet=packet,handled=handled))
for byte in list(range(1,58))+list(range(0xd3,256)):
 if byte==47:continue
 execute(dict(text=chr(byte)+'12',callback=False))
rng=random.Random(0x514920)
for i in range(512):
 left=rng.choice(['alpha','beta','gamma','delta',str(rng.randrange(1,100)),f'{rng.randrange(1,100)}.{rng.randrange(1,10000):04}']);right=rng.choice(['alpha','beta','gamma','delta',str(rng.randrange(1,100))]);execute(dict(text='('+left+rng.choice(['+','-','*','/'])+right+')/3'))
for name,packet,callback,handled,outputs in itertools.product(['Rand','TRUE','false','max','alpha','beta','param3','prefixPaRaM99','missing','custom','-1.25','\xe0name'],[0,P],[False,True],[0,1],[(0,0),(OUT,0),(0,OUT+4),(OUT,OUT+4),(OUT,OUT),(0x922260,0x92225c)]):execute(dict(text=name,oldPacket=packet,callback=callback,handled=handled,floatOutput=outputs[0],integerOutput=outputs[1]),'ResolveOutputs')
for value in [0,0x80000000,bits(1.75),bits(-1.75),bits(2147483648.),bits(-2147483904.),bits(2**63),bits(-(2**63)),0x7f7fffff]:execute(dict(text='custom',handled=1,symbolBits={'custom':value}),'ResolveOutputs')
for name,packet in itertools.product(['alpha','beta','gamma','delta','param3','prefixPaRaM99','missing','2.75','-0','\xe0name'],[0,P]):execute(dict(text=name,packet=packet),'Parameter')
execute(dict(textPointer=0),'Parameter')
patches=[dict(text='alpha+beta',patches={'alpha#1':[[P+0x14,4,bits(10.)],[P+0x18,4,bits(11.)]]}),dict(text='alpha+beta',patches={'alpha#1':[[0x922260,4,P2]]}),dict(text='alpha+beta',patches={'alpha#1':[[0x92225c,4,0xabcdef01]]}),dict(text='alpha+beta',patches={'alpha#1':[[0x9238c0,4,0]]}),dict(text='alpha+beta',patches={'alpha#1':[[TEXT+6,1,ord('1')],[TEXT+7,1,0]]}),dict(text='alpha+beta',patches={'alpha#1':[[P+4,4,SCRIPT2]]}),dict(text='alpha+Rand',patches={'alpha#1':[[0x95e5d4,4,0xffffffff]]}),dict(text='alpha+beta',handled=1,patches={'alpha#1':[[0x922260,4,P2]]}),dict(text='alpha beta',patches={'alpha#1':[[TEXT+5,1,ord(';')]]})]
for c in patches:execute(c)
for name in ['ALPHA','Beta','GAMMA','delta','\xe0name']:
 execute(dict(text=name,names=['alpha','beta','gamma','\xc0NAME']),'Parameter')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:12],originalBodies=sorted(traces),managedExecution=False,limits=['Finite stored arithmetic and callback results, terminating grammar; unknown initial token and nonprogress malformed syntax excluded.','Native callback9238c0 alone supplied; parser, numeric, name comparisons, packet fallback, RNG and FTOL execute actual bytes.','Source/fixture managed replay prepared but unexecuted. Existing entry refinements, no new function count.'])
BASE=nm.BASE
(BASE/'reports/script-phase20-20261013-tests.json').write_text(json.dumps(report,indent=2));(BASE/'reports/script-phase20-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')))
print(json.dumps(report))
