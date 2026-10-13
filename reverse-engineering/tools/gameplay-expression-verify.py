"""Original PC expression wrapper/parser with explicit game-symbol callback."""
import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('actors',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
s=importlib.util.spec_from_file_location('wide',Path(__file__).with_name('animation-x87.py'));wide=importlib.util.module_from_spec(s);s.loader.exec_module(wide)
n=a.n;BASE=a.BASE;OUT=a.D+0x59000;CALLBACK=n.STOP+0x180;events=[];errors=[];vectors=[];symbol_vectors=[];identifier_vectors=[];sequence_vectors=[];checks={};options={};parser_pointer=None;excluded=[];executed=set()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_ECX
def f(x):return a.f(x)
def b(x):return a.bits(x)
def plus(x,y):return -0. if x==0 and y==0 and b(x)&b(y)&0x80000000 else wide.store(wide.add(wide.wide(x),wide.wide(y)))
def times(x,y):return (-0. if (b(x)^b(y))&0x80000000 else 0.) if x==0 or y==0 else wide.store(wide.mul(wide.wide(x),wide.wide(y)))
def divide(x,y):
 if y==0:raise ZeroDivisionError('nonfinite division')
 return (-0. if (b(x)^b(y))&0x80000000 else 0.) if x==0 else wide.store(wide.div(wide.wide(x),wide.wide(y)))
def hook(mu,address,size,user):
 global parser_pointer
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 if address==CALLBACK:
  name=a.string(arg(2));entry=options.get('symbols',{}).get(name.lower());handled=entry is not None
  events.append(['symbol',name,bool(arg(0)),bool(arg(1)),handled,b(entry) if handled else None])
  if handled:n.pack('<f',arg(3),entry)
  a.ret(mu,int(handled))
 elif address==0x4ef790:events.append(['error'])
 elif address==0x4f88fe:parser_pointer=mu.reg_read(UC_X86_REG_ECX)
for p in [CALLBACK,0x4ef790,0x4f88fe]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=p,end=p)
def trace(mu,address,size,user):executed.add(address)
RANGES=[(0x4f2770,0x4f2794,0x4f27e7),(0x4f8420,0x4f8708,0x4f8783),(0x4f8790,0x4f8803,0x4f8824),(0x4f8830,0x4f8880,0x4f8880),(0x4f8880,0x4f88d2,0x4f88d2),(0x4f88e0,0x4f8910,0x4f8910),(0x514850,0x51491e,0x51491e),(0x514920,0x514984,0x514984)]
for start,end,_ in RANGES:n.mu.hook_add(UC_HOOK_CODE,trace,begin=start,end=end-1)
class Parser:
 def __init__(self,text,o):self.text=list(text)+['\0'];self.index=0;self.kind=0;self.value=0.;self.hasValue=False;self.events=[];self.seed=o.get('seed',123);self.o=o;self.steps=0
 def symbol(self,name):
  low=name.lower()
  if low=='rand':self.seed=(self.seed*0x19660d+0x3c6ef35f)&0xffffffff;return (self.seed&0x7fffff)/(1<<23)
  if low=='true':return 1.
  if low=='false':return 0.
  if low=='max':return struct.unpack('<f',struct.pack('<I',0x7f7fffff))[0]
  if self.o.get('callback',True):
   entry=self.o.get('symbols',{}).get(low);self.events.append(['symbol',name,self.o.get('creature',True),self.o.get('packet',True),entry is not None,b(entry) if entry is not None else None])
   if entry is not None:return f(entry)
  return a.number(name) if self.o.get('packet',True) else f(a.number(name)) if name not in ['alpha','beta','gamma','delta'] and 'param' not in low else 0.
 def next(self):
  self.steps+=1
  if self.steps>256:raise ValueError('Nonterminating/too-deep native syntax excluded')
  while self.text[self.index] in [' ','\t']:self.text[self.index]=chr(ord(self.text[self.index])+1)
  c=self.text[self.index]
  if c=='\0':self.kind=6;return
  kinds={'+':0,'-':1,'*':2,'/':3,'(':4,')':5,';':6}
  if c in kinds:self.kind=kinds[c];self.index+=c!=';';return
  if c=='.' or c.isascii() and c.isdigit():
   self.kind=7;self.value=0.;self.hasValue=True;fraction=0.
   while self.text[self.index]=='.' or self.text[self.index].isascii() and self.text[self.index].isdigit():
    c=self.text[self.index];self.index+=1
    if c=='.':
     if fraction!=0:self.events.append(['error'])
     fraction=f(.1)
    elif fraction==0:self.value=plus(times(self.value,10.),float(ord(c)-48))
    else:self.value=wide.store(wide.add(wide.mul(wide.wide(ord(c)-48),wide.wide(fraction)),wide.wide(self.value)));fraction=divide(fraction,10.)
   return
  if c.isascii() and (c.isalpha() or c=='_'):
   start=self.index
   while self.text[self.index].isascii() and (self.text[self.index].isalnum() or self.text[self.index]=='_'):self.index+=1
   name=''.join(self.text[start:self.index]);self.kind=7;self.value=self.symbol(name);self.hasValue=True;return
  # Native leaves kind/value/index untouched on an unrecognized character.
 def factor(self):
  if self.kind==1:self.next();return -self.factor()
  if self.kind==4:
   self.next();value=self.expression()
   if self.kind!=5:self.events.append(['error'])
   self.next();return value
  if self.kind==6:return 1.
  if self.kind in [7,8]:
   if self.kind==8:self.events.append(['error'])
   self.next();return self.value
  self.events.append(['error']);return 0.
 def term(self):
  value=self.factor()
  while self.kind in [2,3]:
   op=self.kind;self.next();other=self.factor();value=times(value,other) if op==2 else divide(value,other)
  return value
 def expression(self):
  value=self.term()
  while self.kind in [0,1]:
   op=self.kind;self.next();other=self.term();value=plus(value,other if op==0 else -other)
  return value
 def run(self):
  fast=all(ord(c)<=0x39 and c!='/' for c in self.text[:-1])
  if fast:value=a.number(''.join(self.text[:-1])) # no packet names possible on this path
  else:self.next();value=self.expression()
  return dict(value=b(value),text=''.join(self.text[:-1]),rng=self.seed,events=self.events,slow=not fast,globalCreature=int(self.o.get('creature',True)) if not fast else self.o.get('beforeCreature',2),globalPacket=0 if not fast else self.o.get('beforePacket',2),parser=None if fast else dict(index=self.index,kind=self.kind,value=b(self.value) if self.hasValue else None))

def global_tag(address,value,sentinel):
 pointer=n.unpack('<I',address)[0]
 return 0 if pointer==0 else 1 if pointer==value else 2 if pointer==sentinel else hex(pointer)
def run(text,o=None,kind='expressions',persistent=False):
 global options,parser_pointer
 options=o or {};c=a.context({})
 if not persistent:a.setup(c,[]);n.write(a.TEXT,text.encode()+b'\0');n.pack('<I',0x9238c0,CALLBACK if options.get('callback',True) else 0);n.pack('<I',0x95e5d4,options.get('seed',123));n.pack('<II',0x92225c,0x11111111,0x22222222)
 events.clear();parser_pointer=None
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(0x514920,[a.CRE if options.get('creature',True) else 0,a.PACK if options.get('packet',True) else 0,a.TEXT],count=200000);n.mu.emu_start(n.STOP,n.STOP+6)
 slow=parser_pointer is not None
 got=dict(value=n.unpack('<I',OUT)[0],text=n.read(a.TEXT,len(text)).decode(),rng=n.unpack('<I',0x95e5d4)[0],events=events.copy(),slow=slow,globalCreature=global_tag(0x92225c,a.CRE,0x11111111),globalPacket=global_tag(0x922260,a.PACK,0x22222222),parser=None if not slow else dict(index=n.unpack('<I',parser_pointer+0xc)[0],kind=n.unpack('<I',parser_pointer)[0],value=n.unpack('<I',parser_pointer+4)[0]))
 try:wanted=Parser(text,options).run()
 except ZeroDivisionError:excluded.append(dict(text=text,options=options,native=got,reason='nonfinite division result outside current portable arithmetic contract'));return
 if wanted['parser'] is not None and wanted['parser']['value'] is None:got['parser']['value']=None
 checks[kind]=checks.get(kind,0)+1
 if got!=wanted:errors.append(dict(text=text,options=options,got=got,want=wanted))
 result=dict(text=text,options=options,native=got)
 if not persistent:vectors.append(result)
 return result

def sequence(text,o,ticks):
 original=text;rows=[];state=dict(o)
 for tick in range(ticks):
  row=run(text,state,'persistent',tick!=0);rows.append(row['native']);g=row['native'];text=g['text'];state={**o,'seed':g['rng'],'beforeCreature':g['globalCreature'],'beforePacket':g['globalPacket']}
 # First tick was a standalone comparison, but is stored only in this sequence.
 vectors.pop();sequence_vectors.append(dict(text=original,options=o,ticks=ticks,native=rows))
def symbol(name,o,floatout,intout):
 global options
 options=o;a.setup(a.context({}),[]);n.write(a.TEXT,name.encode()+b'\0');n.pack('<I',0x9238c0,CALLBACK if o.get('callback',True) else 0);n.pack('<I',0x95e5d4,o.get('seed',123));n.pack('<II',0x92225c,a.CRE if o.get('creature',True) else 0,a.PACK if o.get('packet',True) else 0);n.pack('<II',OUT,0x12345678,0x87654321);events.clear()
 result=n.call(0x514850,[a.TEXT,OUT if floatout else 0,OUT+4 if intout else 0]);got=dict(result=result,floatBits=n.unpack('<I',OUT)[0],integerBits=n.unpack('<I',OUT+4)[0],rng=n.unpack('<I',0x95e5d4)[0],events=events.copy());p=Parser('',o);value=p.symbol(name);integer=0 if value>=2**63 or value< -(2**63) else int(value)&0xffffffff;want=dict(result=0,floatBits=b(value) if floatout else 0x12345678,integerBits=integer if intout else 0x87654321,rng=p.seed,events=p.events);checks['symbolOutputs']=checks.get('symbolOutputs',0)+1
 if got!=want:errors.append(dict(name=name,options=o,floatOutput=floatout,integerOutput=intout,got=got,want=want))
 symbol_vectors.append(dict(name=name,options=o,floatOutput=floatout,integerOutput=intout,native=got))
def main():
 texts=['','1','-1','.5','+5','1+2','1*2','(1+2)','1/2','(1+2)/1','alpha','beta','param3','prefixPaRaM99','missing','true','FALSE','max','Rand','1+alpha','alpha+beta','alpha-beta','alpha*beta','alpha/beta','-(alpha+beta)','alpha+','alpha*',';','alpha;beta','1alpha','2.5___tail','alpha beta','alpha\tbeta','(1.2.3)/1','(.12345678+alpha)/2','alpha+beta*gamma','(alpha+beta)*gamma','--alpha','+alpha','alpha  +beta','1+Rand','Rand+Rand','max/2','alpha+custom','custom/2','-0','(-0)/1','0/(-1)','(-alpha)*0','0*(-alpha)','((-0)+(-0))/1','(alpha','/alpha','*alpha','16777217/1','16777219/1','123456.789012345/1','0.'+'0'*45+'123/1','_'*255]
 for text,o in itertools.product(texts,[{},dict(callback=False),dict(packet=False),dict(creature=False),dict(symbols={'custom':7.25,'alpha':-2.5})]):run(text,o)
 rng=random.Random(0x514920)
 for i in range(512):
  left=rng.choice(['alpha','beta','gamma','delta',str(rng.randrange(1,100)),f'{rng.randrange(1,100)}.{rng.randrange(1,10000):04}']);right=rng.choice(['alpha','beta','gamma','delta',str(rng.randrange(1,100))]);run('('+left+rng.choice(['+','-','*','/'])+right+')/3',kind='generated')
 for name,o,floatout,intout in itertools.product(['Rand','TRUE','false','max','alpha','param3','missing','custom'],[{},dict(callback=False),dict(packet=False),dict(creature=False),dict(symbols={'custom':-1.75,'alpha':4.25})],[False,True],[False,True]):symbol(name,o,floatout,intout)
 for value in [0.,-0.,1.75,-1.75,2147483648.,-2147483904.,2**63,-(2**63),3.4e38]:symbol('custom',dict(symbols={'custom':value}),True,True)
 for value in range(256):
  got=n.call(0x4f2770,[value]);want=int(48<=value<=57 or 65<=value<=90 or 97<=value<=122 or value==95);checks['identifierBytes']=checks.get('identifierBytes',0)+1
  if got!=want:errors.append(dict(byte=value,got=got,want=want))
  identifier_vectors.append(dict(value=value,native=got))
 for text in ['Rand+Rand','Rand Rand','alpha beta','alpha\tbeta','1+2','(-alpha)*0']:
  for options in [{},dict(packet=False,creature=False)]:sequence(text,options,8)
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:12],excludedProbes=excluded,method='Original514920 wrapper,514850 resolver and4f8420/8790/8830/8880/88e0 expression parser execute unchanged. Only game symbol callback9238c0 is supplied; error helper4ef790 executes its actual no-op. Independent mutable-buffer/parser model compares valuebits, lexer cursor/token/value, callbacks, RNG and buffer mutation. Uninitialized unused lexer value is not compared.',limits=['ASCII bounded identifiers and terminating finite arithmetic; unknown initial-token/uninitialized stack and divide-by-zero/nonfinite results excluded.','Game-symbol callback is supplied and remains an adapter; reserved Rand/true/false/max and packet parameters are real native logic.'])
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
 for start,end,tail in RANGES:
  instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in d.disasm(n.read(start,end-start),start)]
  functions.append(dict(address=hex(start),codeEndExclusive=hex(end),dataEndExclusive=hex(tail),instructions=instructions,tailBytes=n.read(end,tail-end).hex(),tailQualification='Jump/classifier tables, with one alignment NOP before the factor jump table; not executable instructions.' if tail>end else None))
 report['instructionCoverage']={x['address']:dict(total=len(x['instructions']),executed=sum(i['executed'] for i in x['instructions']),notExecuted=[i['address'] for i in x['instructions'] if not i['executed']]) for x in functions}
 (BASE/'reports/gameplay-expression-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-expression-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors,symbols=symbol_vectors,identifiers=identifier_vectors,sequences=sequence_vectors),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-expression-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
