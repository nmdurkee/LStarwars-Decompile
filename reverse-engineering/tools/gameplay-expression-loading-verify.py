"""Original load-time expression classifier and symbol resolver composition."""
import importlib.util,json,itertools,struct,random
from pathlib import Path
s=importlib.util.spec_from_file_location('expression',Path(__file__).with_name('gameplay-expression-verify.py'));e=importlib.util.module_from_spec(s);s.loader.exec_module(e)
n=e.n;a=e.a;BASE=e.BASE;CALLBACK=n.STOP+0x1a0;OUT=e.OUT;events=[];options={};checks={};errors=[];vectors=[];symbols=[];executed=set()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
def entry(value,handled=True):return dict(valueBits=e.b(value),handled=handled)
def hook(mu,address,size,user):
 if address==CALLBACK:
  sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0];name=a.string(arg(2));item=options.get('symbols',{}).get(name.lower());handled=item['handled'] if item else False
  events.append(['symbol',name,bool(arg(0)),bool(arg(1)),handled,item['valueBits'] if item else None])
  if item:n.pack('<I',arg(3),item['valueBits'])
  a.ret(mu,int(handled))
 elif address==0x4ef790:events.append(['error'])
 else:executed.add(address)
for start,end in [(CALLBACK,CALLBACK),(0x4ef790,0x4ef790),(0x513230,0x513296),(0x5132a0,0x5132ed)]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=start,end=end)
class Parser(e.Parser):
 def __init__(self,text,o):super().__init__(text,o);self.flags=[0,0,0]
 def symbol(self,name):
  self.flags[0]=1;self.flags[1]=1;value=0.
  if self.o.get('callback',True):
   item=self.o.get('symbols',{}).get(name.lower());handled=item['handled'] if item else False;self.events.append(['symbol',name,False,False,handled,item['valueBits'] if item else None])
   if item:value=struct.unpack('<f',struct.pack('<I',item['valueBits']))[0]
   if handled:self.flags[1]=0
  return value
def setup(text,o):
 global options
 options=o;a.setup(a.context({}),[]);n.write(a.TEXT,text.encode()+b'\0');n.pack('<I',0x9238c0,CALLBACK if o.get('callback',True) else 0);n.pack('<III',0x92224c,0x11,0x22,0x33);n.pack('<II',0x92225c,0x11111111,0x22222222);n.pack('<I',0x95e5d4,123);events.clear()
def run(text,o,kind='expressions'):
 setup(text,o);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(0x5132a0,[a.TEXT],count=200000);n.mu.emu_start(n.STOP,n.STOP+6)
 got=dict(value=n.unpack('<I',OUT)[0],flags=list(n.unpack('<III',0x92224c)),text=n.read(a.TEXT,len(text)).decode(),events=events.copy(),rng=n.unpack('<I',0x95e5d4)[0],runtimeGlobals=list(n.unpack('<II',0x92225c)))
 p=Parser(text,o);p.next();value=p.expression();p.flags[2]=int(p.flags[1]!=0);want=dict(value=e.b(value),flags=p.flags,text=''.join(p.text[:-1]),events=p.events,rng=123,runtimeGlobals=[0x11111111,0x22222222]);checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(text=text,options=o,got=got,want=want))
 vectors.append(dict(text=text,options=o,native=got))
def symbol(name,o,floatout,intout):
 setup(name,o);n.pack('<II',OUT,0x12345678,0x87654321);result=n.call(0x513230,[a.TEXT,OUT if floatout else 0,OUT+4 if intout else 0])
 got=dict(result=result,floatBits=n.unpack('<I',OUT)[0],integerBits=n.unpack('<I',OUT+4)[0],flags=list(n.unpack('<III',0x92224c)),events=events.copy());p=Parser('',o);p.flags=[0x11,0x22,0x33];value=p.symbol(name);integer=0 if value>=2**63 or value< -(2**63) else int(value)&0xffffffff;want=dict(result=0,floatBits=e.b(value) if floatout else 0x12345678,integerBits=integer if intout else 0x87654321,flags=p.flags,events=p.events);checks['symbolOutputs']=checks.get('symbolOutputs',0)+1
 if got!=want:errors.append(dict(name=name,options=o,floatOutput=floatout,integerOutput=intout,got=got,want=want))
 symbols.append(dict(name=name,options=o,floatOutput=floatout,integerOutput=intout,native=got))
def main():
 opts=[{},dict(callback=False),dict(symbols={'known':entry(2.75)}),dict(symbols={'known':entry(-1.5),'missing':entry(4,False)}),dict(symbols={'rand':entry(7.25),'true':entry(0),'false':entry(9)}),dict(symbols={'known':entry(-0.),'missing':entry(-1.75,False)})]
 texts=['',';','1+2','(1+2)','1*2','+5','known','missing','param3','Rand','true','FALSE','max','known+missing','missing+known','1known','1missing','known+','known missing','known\tmissing','(known','(1.2.3)/1','missing+known+missing','known+missing+known','-known','(-known)/1','known*0','1+Rand','Rand+known','known+Rand']
 for text,o in itertools.product(texts,opts):run(text,o)
 rng=random.Random(0x5132a0)
 for i in range(128):run('('+rng.choice(['known','missing','12.25','3'])+rng.choice(['+','-','*'])+rng.choice(['known','missing','2.75','17'])+')/3',rng.choice(opts),'generated')
 for name,o,fo,io in itertools.product(['known','missing','Rand','true'],opts,[False,True],[False,True]):symbol(name,o,fo,io)
 for value,handled in itertools.product([0.,-0.,1.75,-1.75,2147483648.,-2147483904.,2**63,-(2**63),3.4e38],[False,True]):symbol('custom',dict(symbols={'custom':entry(value,handled)}),True,True)
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
 for start,end in [(0x513230,0x513297),(0x5132a0,0x5132ee)]:
  instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in d.disasm(n.read(start,end-start),start)];functions.append(dict(address=hex(start),endExclusive=hex(end),instructions=instructions))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:8],newNativeMappings=2,authoredUseCredit=0,method='Unmodified5132a0 always calls the original recursive parser with actual513230; only optional game symbol production is a callback fixture. Compare float bits, symbol/error events, mutable text, all three classification globals, unchanged runtime pointer globals and unchanged RNG. Direct resolver cases exercise optional outputs and callback false-with-value behavior.',instructionCoverage={x['address']:dict(total=len(x['instructions']),executed=sum(i['executed'] for i in x['instructions'])) for x in functions},limits=['Finite terminating ASCII grammar shares ScriptExpressions bounds.','Game-specific symbol production remains external. No whole52b3f0 condition-loader reconstruction claim.','The unresolved flag tracks the LAST symbol, not any unresolved symbol; preserved as original behavior.','Managed core/replay compile only.'])
 (BASE/'reports/gameplay-expression-loading-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-expression-loading-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors,symbols=symbols),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-expression-loading-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
