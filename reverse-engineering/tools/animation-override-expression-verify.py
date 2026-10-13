"""Original516980 -> original514920, including persistent token-zero mutation."""
from pathlib import Path
import importlib.util,json,struct,itertools,gzip,hashlib,collections
B=Path(__file__).resolve().parent.parent
s=importlib.util.spec_from_file_location('expression_model',B/'tools/gameplay-expression-verify.py');e=importlib.util.module_from_spec(s);s.loader.exec_module(e)
n=e.a.native.NativeX86();D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
O=D;P=D+0x2000;CHAR=D+0x3000;TABLE=D+0x4000;NAMES=D+0x20000;ARGS=D+0x40000;TEXT=D+0x41000;GLOBAL=D+0x50000;SCRIPT=D+0x51000
defs=[('idle',0),('walk',2),('jump',3)];events=[];cases=[];errors=[];counts=collections.Counter()
def text(p):return n.read(p,1024).split(b'\0')[0].decode('ascii')
def observe(mu,a,z,u):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==0x514920:events.append(['expression',text(n.unpack('<I',sp+12)[0])])
 elif a==0x62e000:events.append(['lookup',text(n.unpack('<I',sp+8)[0])])
 else:events.append(['error'])
for a in[0x514920,0x62e000,0x4ef790]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def lookup(q):return next((v for k,v in defs if k.lower()==q.lower()),-1)
def predict(tokens,c):
 tokens=tokens.copy();source=17;target=19;timer=e.b(3.25);seed=c['seed'];creature=packet=2;ev=[]
 if c['first'] and c['owner'] and c['world'] and c['packet']:
  source=target=-1
  for index in range(len(tokens)):
   t=tokens[index];low=t.lower()
   if low=='from=all':source=233;continue
   if 'from='in low:q=t[low.index('from=')+5:];ev.append(['lookup',q]);source=lookup(q);continue
   if 'to='in low:q=t[low.index('to=')+3:];ev.append(['lookup',q]);target=lookup(q);continue
   if c['processor']:
    ev.append(['expression',tokens[0]]);p=e.Parser(tokens[0],{'callback':False,'seed':seed,'beforeCreature':creature,'beforePacket':packet});r=p.run();tokens[0]=r['text'];seed=r['rng'];timer=r['value'];creature=r['globalCreature'];packet=r['globalPacket'];ev.extend(r['events'])
  if target==-1:source=-1
 return dict(result=1,source=source,target=target,timer=timer,tokens=tokens,seed=seed,creature=creature,packet=packet,events=ev)
def original(tokens,c):
 n.write(O,bytes(0x10d8));n.pack('<I',O,O if c['world']else 0);n.pack('<I',O+0x398,O if c['owner']else 0);n.pack('<I',O+0x54,CHAR);n.pack('<hh',O+0x3ee,17,19)
 n.write(P,bytes(0x100));n.pack('<I',P+4,SCRIPT);n.pack('<4f',P+0x14,2.75,1.5,3.,4.);n.pack('<f',P+0x9c,3.25);n.write(SCRIPT,bytes(0x100))
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.pack('<I',SCRIPT+0x18+i*8,SCRIPT+0x80+i*16);n.write(SCRIPT+0x80+i*16,name.encode()+b'\0')
 n.pack('<I',CHAR+0x10,TABLE);n.write(TABLE,bytes(4*76))
 for i,(name,value)in enumerate(defs):n.pack('<I',TABLE+i*76,NAMES+i*256);n.write(NAMES+i*256,name.encode()+b'\0');n.pack('<h',TABLE+i*76+8,value)
 n.pack('<I',0x29130e4,GLOBAL);n.pack('<I',GLOBAL+8,233);n.pack('<I',0x9238c0,0);n.pack('<I',0x95e5d4,c['seed']);n.pack('<II',0x92225c,0x11111111,0x22222222)
 for i,t in enumerate(tokens):n.pack('<I',ARGS+4*i,TEXT+1024*i);n.write(TEXT+1024*i,t.encode()+b'\0')
 events.clear();result=n.call(0x516980,[0,P if c['processor']else 0,O+0x2c8 if c['packet']else 0,ARGS,len(tokens),c['first'],0],count=500000)
 cg=n.unpack('<I',0x92225c)[0];pg=n.unpack('<I',0x922260)[0]
 return dict(result=result,source=n.unpack('<h',O+0x3ee)[0],target=n.unpack('<h',O+0x3f0)[0],timer=n.unpack('<I',P+0x9c)[0],tokens=[text(TEXT+1024*i)for i in range(len(tokens))],seed=n.unpack('<I',0x95e5d4)[0],creature=1 if cg==O+0x2c8 else 2 if cg==0x11111111 else hex(cg),packet=0 if pg==0 else 2 if pg==0x22222222 else hex(pg),events=events.copy())
expressions=['1+2','(1+2)','(1+2)/1','alpha','beta','param3','alpha+beta','alpha*beta','alpha/beta','(alpha+beta)/2','alpha+','alpha*','alpha beta','alpha\tbeta','Rand','Rand+Rand','Rand Rand','1+Rand','2.5___tail','1alpha','(1.2.3)/1','-0','(-0)/1','0/(-1)','true','false','max/2','missing','alpha;beta','(alpha']
gates=[{},dict(first=0),dict(first=-2),dict(processor=False),dict(owner=False),dict(world=False),dict(packet=False)]
for expression,suffix,gate,seed in itertools.product(expressions,[[],['to=walk'],['unused','unused','from=all','to=jump'],['to=walk','reset','from=idle','clear']],gates,[123,0xffffffff]):
 tokens=[expression]+suffix;c=dict(first=1,processor=True,owner=True,world=True,packet=True,seed=seed);c.update(gate);want=predict(tokens,c);got=original(tokens,c);counts['composition']+=1
 if want!=got:
  if len(errors)<12:errors.append(dict(tokens=tokens,state=c,expected=want,native=got))
  counts['mismatches']+=1
 cases.append(dict(tokens=tokens,state=c,native=got))
out=B/'reports/animation-override-expression-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(binarySha256=n.sha256,comparisons=len(cases),mismatches=counts['mismatches'],examples=errors,fixture=dict(path=out.relative_to(B).as_posix(),sha256=hashlib.sha256(out.read_bytes()).hexdigest(),bytes=out.stat().st_size),method='Original516980,62e000,514920 and recursive expression/parser/number/RNG helpers execute unchanged. No computational callee is replaced. Native callback9238c0 is null; token buffers retain mutations between repeated evaluations within the command.',limits=['Finite terminating ASCII expression domain of ScriptExpressions.','Definition names and packet parameter values are explicit fixture inputs.','No production game-symbol callback, actor playback or frame integration claim.'])
(B/'reports/animation-override-expression-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not counts['mismatches']
