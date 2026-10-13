"""Original OverrideAnimation/FindAnimIX and embedded AnimatePlayer gate checks.
No original computational routine or expression evaluator is replaced.
"""
from pathlib import Path
import importlib.util,json,struct,random,itertools,gzip,hashlib,collections
B=Path(__file__).resolve().parent.parent
s=importlib.util.spec_from_file_location('override_native',B/'tools/native-x86.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
O=D;P=D+0x2000;CHAR=D+0x3000;TABLE=D+0x4000;NAMES=D+0x20000;ARGS=D+0x40000;TEXT=D+0x41000;GLOBAL=D+0x50000;SCRIPT=D+0x51000;RETURN=D+0x52000
bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
flt=lambda v:struct.unpack('<f',struct.pack('<I',v))[0]
f32=lambda v:flt(bits(v))
i16=lambda v:(v+32768)%65536-32768
def sha(v):return hashlib.sha256(v).hexdigest()
def text(p):return n.read(p,1024).split(b'\0')[0].decode('latin1')if p else None
events=[]
def observe(mu,a,z,u):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==0x514920:events.append(['expression',text(n.unpack('<I',sp+12)[0])])
 elif a==0x62e000:events.append(['lookup',text(n.unpack('<I',sp+8)[0])])
for a in[0x514920,0x62e000]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def fold(v):return bytes(c-32 if 97<=c<=122 or c>=224 else c for c in v.encode('latin1'))
def lookup(defs,q):
 if defs is None or q is None:return -1
 for row in defs:
  if row is None or row['name'] is None:break
  if fold(row['name'])==fold(q):return i16(row['action'])
 return -1
def number(q):
 if q.lower()=='true':return 1.
 if q.lower() in ['alpha','param0','param1']:return 2.75
 if q.lower()=='beta':return -1.5
 # Fixtures deliberately avoid arbitrary expression grammar and overflow.
 at=1 if q.startswith('-')else 0;den=-1. if at else 1.;value=0.
 while at<len(q)and'0'<=q[at]<='9':value=f32(value*10+int(q[at]));at+=1
 if at<len(q)and q[at]=='.':
  at+=1
  while at<len(q)and'0'<=q[at]<='9':value=f32(value*10+int(q[at]));den=f32(den*10);at+=1
 return f32(value/den)
tables=[];cases=[];errors=[];counts=collections.Counter();rng=random.Random(0x516980)
base=bytes([0xa5])*0x10d8
def upload(defs):
 n.write(CHAR,bytes(0x100));n.write(TABLE,bytes(0x18000));n.pack('<I',CHAR+0x10,TABLE if defs is not None else 0)
 if defs is not None:
  for i,row in enumerate(defs):
   if row is None or row['name']is None:break
   t=NAMES+i*256;n.write(t,row['name'].encode('latin1')+b'\0');n.pack('<I',TABLE+76*i,t);n.pack('<H',TABLE+76*i+8,row['action']&65535)
def initial(c):
 actor=bytearray(base)
 for off,v in[(0,O if c['world']else 0),(0x50,0),(0x54,CHAR if c['definitions']else 0),(0x1f8,0x40000),(0x398,O if c['owner']else 0)]:struct.pack_into('<I',actor,off,v)
 for off,v in[(0x3ee,c['from']),(0x3f0,c['to']),(0x42,c['requested']),(0x3e,123),(0x40,456),(0x7ee,-234),(0x7f0,-345)]:struct.pack_into('<h',actor,off,v)
 struct.pack_into('<b',actor,0x7b5,c['context']);processor=bytearray(0x100);struct.pack_into('<I',processor,4,SCRIPT);struct.pack_into('<ff',processor,0x14,2.75,-1.5);struct.pack_into('<I',processor,0x9c,c['timer'])
 return actor,processor
def snapshot(actor,processor,ret,ev):
 return {'from':struct.unpack_from('<h',actor,0x3ee)[0],'to':struct.unpack_from('<h',actor,0x3f0)[0],'timer':struct.unpack_from('<I',processor,0x9c)[0],'requested':struct.unpack_from('<h',actor,0x42)[0],'previous':struct.unpack_from('<h',actor,0x40)[0],'miniPrevious':struct.unpack_from('<h',actor,0x7f0)[0],'result':ret,'events':ev,'actorSha256':sha(actor),'processorSha256':sha(processor)}
def predict(c,defs,tokens):
 actor,processor=initial(c);ev=[]
 if c['packet']and c['owner']and c['world']and c['first']:
  source=target=-1
  for t in tokens[:max(0,c['count'])]:
   low=fold(t)
   if low==b'FROM=ALL':source=i16(c['total']);continue
   at=low.find(b'FROM=')
   if at>=0:q=t[at+5:];ev.append(['lookup',q]);source=lookup(defs if c['definitions']else None,q);continue
   at=low.find(b'TO=')
   if at>=0:q=t[at+3:];ev.append(['lookup',q]);target=lookup(defs if c['definitions']else None,q);continue
   if c['processor']:ev.append(['expression',tokens[0]]);struct.pack_into('<I',processor,0x9c,bits(number(tokens[0])))
  if target==-1:source=-1
  struct.pack_into('<hh',actor,0x3ee,source,target)
 if c['consume']:
  actor[0x40:0x42]=actor[0x3e:0x40];actor[0x7f0:0x7f2]=actor[0x7ee:0x7f0];source,target=struct.unpack_from('<hh',actor,0x3ee);requested=struct.unpack_from('<h',actor,0x42)[0]
  if source!=-1 and((source==233 and c['context']!=28)or source==requested):struct.pack_into('<h',actor,0x42,target)
 return snapshot(actor,processor,1,ev)
def run(c,defs,tokens):
 upload(defs);actor,processor=initial(c);n.write(O,actor);n.write(P,processor);n.write(SCRIPT,bytes(128));n.pack('<I',SCRIPT+0x18,SCRIPT+0x80);n.pack('<I',SCRIPT+0x20,SCRIPT+0x90);n.write(SCRIPT+0x80,b'alpha\0');n.write(SCRIPT+0x90,b'beta\0')
 n.pack('<I',0x29130e4,GLOBAL);n.pack('<I',GLOBAL+8,c['total']&0xffffffff);n.pack('<I',0x9238c0,0)
 for i,t in enumerate(tokens):n.pack('<I',ARGS+i*4,TEXT+i*1024);n.write(TEXT+i*1024,t.encode('latin1')+b'\0')
 events.clear();result=n.call(0x516980,[0,P if c['processor']else 0,O+0x2c8 if c['packet']else 0,ARGS,c['count'],c['first'],0],count=300000)
 if c['consume']:n.call(0x418ca0,[O])
 return snapshot(n.read(O,len(base)),n.read(P,0x100),result,events.copy())
def check(kind,inputs,want,actual):
 counts[kind]+=1
 if want!=actual:
  if len(errors)<15:errors.append({'kind':kind,'input':inputs,'expected':want,'native':actual})
  counts['mismatches']+=1
 cases.append({'kind':kind,'input':inputs,'native':actual})
def context(**kw):
 c={'packet':True,'owner':True,'world':True,'first':1,'definitions':True,'processor':True,'count':0,'from':17,'to':19,'requested':0,'context':0,'total':233,'timer':bits(3.25),'consume':False};c.update(kw);return c
def exercise(tokens,tableIndex=0,origin=None,**kw):
 options={'count':len(tokens)};options.update(kw);c=context(**options);inp={'state':c,'table':tableIndex,'tokens':tokens,'expressionValue':bits(number(tokens[0]))if tokens else 0}
 if origin:inp['origin']=origin
 check('commandChain'if c['consume']else'command',inp,predict(c,tables[tableIndex],tokens),run(c,tables[tableIndex],tokens))
synthetic=[{'name':name,'action':a}for name,a in [('idle',0),('walk',2),('jump',3),('all',7),('duplicate',4),('DUPLICATE',9),('to=walk',11),('',12),('negative',-1),('wide',32767),('high',-32768),('\xe0',9),('\xc0',10)]];tables.append(synthetic)
tokensets=[[],['from=all','to=walk'],['reset'],['from=idle'],['to=jump'],['To=walk','from=all'],['xfrom=all','to=walk'],['from=idle','to=walk','to=missing'],['from=idle','from=jump','to=walk'],['from=to=walk','to=jump'],['from=idle','to=','reset','default'],['1.25','reset','to=jump'],['alpha','unused','to=walk'],['param1','unused','to=walk'],['to=negative','from=all'],['FROM=ALL ','to=walk'],['from=\xe0','to=high']]
for tokens,gate in itertools.product(tokensets,[{}, {'packet':False},{'owner':False},{'world':False},{'first':0},{'first':-5},{'definitions':False},{'processor':False},{'count':-1},{'total':65535},{'total':65536}]):exercise(tokens,**gate)
pool=['from=All','from=idle','FROM=jump','prefrom=walk','to=walk','TO=jump','to=duplicate','to=missing','reset','clear','default','2.75','-0.5','alpha','param1','true','false','to=negative']
for i in range(2400):
 tokens=[rng.choice(pool)for _ in range(rng.randrange(7))];exercise(tokens,requested=rng.choice([-1,0,2,3,233]),context=rng.choice([0,28,29,-1]),total=rng.choice([233,5,65535,65536]),processor=bool(rng.randrange(2)),consume=bool(i%2))
# Every authored token occurrence is retained. Definitions below are deliberate
# fixture bindings, not a claim that those names resolve for a live character.
scripts=json.loads((B/'reports/gameplay-catalog/scripts.json').read_text());uses=[]
def walk(v,source=None):
 if isinstance(v,dict):
  source=v.get('source',source)
  if v.get('key','').lower()=='overrideanimation':uses.append({'source':source,'line':v['line'],'tokens':v['args']})
  for x in v.values():walk(x,source)
 elif isinstance(v,list):
  for x in v:walk(x,source)
walk(scripts)
for use in uses:
 defs=synthetic.copy()
 for t in use['tokens']:
  low=fold(t)
  for key in[b'FROM=',b'TO=']:
   at=low.find(key)
   if at>=0 and lookup(defs,t[at+len(key):])==-1:defs.append({'name':t[at+len(key):],'action':20+len(defs)})
 tables.append(defs);index=len(tables)-1
 for consume,contextValue,first in [(False,0,1),(True,0,1),(True,28,1),(True,0,0)]:exercise(use['tokens'],index,use,consume=consume,context=contextValue,first=first)
# Source catalog is only the definition-table adapter here. Lookup itself runs
# original76-byte rows. No claim is made about unresolved loader/default state.
catalog=json.loads((B/'reports/animation-playback-catalog-native.json').read_text());authoredDefinitions=0;groups={}
for row in catalog['rows']:
 if row['status']=='loaded':groups.setdefault(row['source'],[]).append(row)
for source,rows in groups.items():
 assert sha((B.parent/source).read_bytes())==rows[0]['sourceSha256']
 defs=[{'name':a['nativeName'],'action':a['actionId']}for a in rows]
 tables.append(defs);ti=len(tables)-1;upload(defs)
 for row in defs:
  for query in[row['name'],row['name'].swapcase()]:
   n.write(TEXT,query.encode('latin1')+b'\0');actual=i16(n.call(0x62e000,[CHAR,TEXT])&65535);check('lookup',{'table':ti,'query':query,'origin':source},lookup(defs,query),actual)
  authoredDefinitions+=1
for defs in[None,[],synthetic,[{'name':'first','action':1},{'name':None,'action':2},{'name':'later','action':3}]]:
 tables.append(defs);ti=len(tables)-1;upload(defs)
 for q in['idle','duplicate','','later','high','\xe0','\xc0','missing',None]:
  if q is not None:n.write(TEXT,q.encode('latin1')+b'\0')
  actual=i16(n.call(0x62e000,[CHAR if defs is not None else 0,TEXT if q is not None else 0])&65535);check('lookup',{'table':ti,'query':q},lookup(defs,q),actual)
out=B/'reports/animation-script-override-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':n.sha256,'addresses':{'actor':O,'character':CHAR,'script':SCRIPT},'tables':tables,'cases':cases},separators=(',',':')).encode(),mtime=0));report={'binarySha256':n.sha256,'comparisons':len(cases),'counts':dict(counts),'mismatches':counts['mismatches'],'examples':errors,'authoredUses':len(uses),'authoredDefinitions':authoredDefinitions,'uses':uses,'fixture':{'path':out.relative_to(B).as_posix(),'sha256':sha(out.read_bytes()),'bytes':out.stat().st_size},'serviceBoundaries':['Portable expression evaluator514920 is supplied; all native fixtures execute its original implementation with null custom callback, finite numeric/boolean/local-parameter or unknown identifiers.','Authored command name bindings and catalog-derived lookup tables are fixture inputs; no live character selection/loading inferred.','Command-to418ca0 chain suppresses selection callback and uses no model, verifying exact override and bookkeeping before native early return.']};(B/'reports/animation-script-override-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k not in('examples','uses')},indent=2));print(json.dumps(errors[:2],indent=2));assert not counts['mismatches']
