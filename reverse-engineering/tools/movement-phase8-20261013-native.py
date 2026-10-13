"""Original SetPathCnxFlag composes all unmodified flag/locator/edge callees; no adapters."""
import importlib.util,struct,json,gzip,itertools,base64
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;WORLD=D;LEVEL=D+0x1000;PATH=D+0x2000;NODES=D+0x3000;EDGES=D+0x4000;LIST=D+0x5000;ARGS=D+0x6000;TEXT=D+0x7000;SIZE=0x10000
errors=[];vectors=[];groups={}
names=[['JUMP','COMBATROLL','BATGLIDE','GRAPPLE','USEHATCH','HOVERTUBE','FORGOODIES','FORBADDIES','OBSTACLE','JUMP_NOW','DONT_JUMP_NOW'],['DBLJUMP','R2D2GLIDE','ZIPUP','USEHATCH','JARJARJUMP','HOVERTUBE','SWAMP','TAKEOVER','VEHICLE','PARTY','FORGOODIES','FORBADDIES','OBSTACLE','JUMP_NOW','DONT_JUMP_NOW','BLOCKAGE','JUMP','DONTTOGGLE','FULLTERRAIN'],['DBLJUMP','BIGJUMP','JUMP','GRAPPLE','CLIMB','NO_DEST_CHECK','JUMP_NOW','DONT_JUMP_NOW','FORGOODIES','FORBADDIES','OBSTACLE','WHIPSWING']]
values=[[1,2,4,8,16,64,128,256,0x20000000,0x400,0x800],[2,4,8,16,32,64,0x4000,0x8000,0x10000,0x20000,128,256,0x20000000,0x400,0x800,0x40000,1,0x80000,0x100000],[2,4,1,8,16,32,64,128,256,512,0x20000000,0x400]]
def mask(t,o):
 dialect=o.get('dialect',1);low=t.upper()
 if low in names[dialect]:return values[dialect][names[dialect].index(low)]
 return {'BLOCK':0x80000000,'BIGJUMP':o.get('bigJump',4),'REQUIRESPERMISSION':o.get('permission',0x1000000),'NO_DESTINATION_CHECK':o.get('noDestination',0x4000000)}.get(low,0)
def setup(o,tokens):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',WORLD+0x10,0 if o.get('gate')=='header'else LEVEL);n.pack('<B',LEVEL,0 if o.get('gate')=='inactive'else 1);n.pack('<I',LEVEL+8,0 if o.get('noPath')else PATH);n.pack('<B',PATH+0x10,o.get('nodeCount',3));n.pack('<I',PATH+0x7c,NODES)
 nodeNames=o.get('names',['A','B','C'])
 for j,name in enumerate(nodeNames):
  q=NODES+j*0x5c;n.pack('<I',q,0 if name is None else TEXT+0x1000+j*0x20)
  if name is not None:n.write(TEXT+0x1000+j*0x20,name.encode()+b'\0')
  n.pack('<B',q+0x28,o.get('edgeCount',3));n.pack('<I',q+0x34,LIST+j*16)
  for k in range(3):n.pack('<I',LIST+j*16+k*4,EDGES+k*0x40)
 endpoints=o.get('endpoints',[[0,1],[1,0],[2,1]])
 flags=o.get('flags',[[0xffffffff,0xa5a5a5a5],[0x12345678,0x87654321],[0,0xffffffff]])
 for j,(ends,words)in enumerate(zip(endpoints,flags)):n.pack('<II',EDGES+j*0x40,*words);n.pack('<BB',EDGES+j*0x40+0x10,*ends)
 dialect=o.get('dialect',1);n.pack('<I',0x876580,1 if dialect==2 else 0);n.pack('<I',0x7f39e4,1 if dialect==1 else 0)
 for addr,value in[(0x950d68,o.get('bigJump',4)),(0x950d6c,o.get('permission',0x1000000)),(0x950d70,o.get('noDestination',0x4000000)),(0x950d74,o.get('good',0x80)),(0x950d78,o.get('bad',0x100))]:n.pack('<I',addr,value)
 cur=TEXT
 for j,t in enumerate(tokens):n.write(cur,t.encode()+b'\0');n.pack('<I',ARGS+j*4,cur);cur+=len(t)+4
 return bytearray(n.read(D,SIZE))
def model(o,tokens,first,image):
 if o.get('gate')in['world','header','inactive']or not first or not tokens:return
 fromName=toName=None;on=opposite=0;both=False;enable=True
 for t in tokens:
  lo=t.lower()
  if'from'in lo:fromName=t[lo.index('from')+5:];continue
  if'to'in lo:toName=t[lo.index('to')+3:];continue
  flag=mask(t,o)
  if flag:
   on|=flag
   if flag==o.get('good',0x80):opposite|=o.get('bad',0x100)
   elif flag==o.get('bad',0x100):opposite|=o.get('good',0x80)
   elif flag==0x20000000:both=True
  elif lo=='bothways':both=True
  elif lo=='false':enable=False
 if fromName is None or toName is None or o.get('noPath'):return
 nodeNames=o.get('names',['A','B','C'])[:o.get('nodeCount',3)]
 def find(name):return next((j for j,v in enumerate(nodeNames)if v is not None and v.lower()==name.lower()),-1)
 a,b=find(fromName),find(toName)
 if a<0 or b<0 or a==b:return
 ends=o.get('endpoints',[[0,1],[1,0],[2,1]])[:o.get('edgeCount',3)];edge=side=None
 for j,(x,y)in enumerate(ends):
  if x==b:edge=j;side=1;break
  if y==b:edge=j;side=0;break
 if edge is None:return
 for direction in([side,1-side]if both else[side]):
  p=EDGES-D+edge*0x40+direction*4;old=struct.unpack_from('<I',image,p)[0];new=((old|on)&~opposite)if enable else old&~on;struct.pack_into('<I',image,p,new&0xffffffff)

def run(o,tokens,first=True,group='synthetic'):
 before=setup(o,tokens);expected=bytearray(before);model(o,tokens,first,expected)
 result=n.call(0x4505d0,[0 if o.get('gate')=='world'else WORLD,0,0,ARGS,len(tokens),int(first)]);after=n.read(D,SIZE);groups[group]=groups.get(group,0)+1
 if after!=expected or result!=1:errors.append({'input':o,'tokens':tokens,'first':first,'result':result,'diff':[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:25]})
 vectors.append({'input':dict(o),'tokens':tokens,'first':first,'before':base64.b64encode(gzip.compress(before)).decode(),'after':base64.b64encode(gzip.compress(after)).decode(),'result':result})
for gate,first,tokens in itertools.product([None,'world','header','inactive'],[False,True],[[],['from=A','to=B','BLOCK'],['from=A','OBSTACLE'],['to=B'],['ignored']]):run({'gate':gate},tokens,first,'guard-gates')
allNames=sorted(set(sum(names,[])+['BLOCK','BIGJUMP','REQUIRESPERMISSION','NO_DESTINATION_CHECK','FALSE','TRUE','bothways','unknown']))
for dialect,token,first in itertools.product([0,1,2],allNames,[False,True]):run({'dialect':dialect},['from=A','to=B',token],first,'whole-token-dialects')
for dialect,both,enable,good,bad,tokens in itertools.product([0,1,2],[False,True],[False,True],[0x80,0x100,0x20000000],[0x100,0x80,0x20000000],[['FORGOODIES'],['FORBADDIES'],['FORGOODIES','FORBADDIES'],['OBSTACLE','FORGOODIES']]):
 run({'dialect':dialect,'good':good,'bad':bad},['from=A','to=B']+tokens+(['bothways']if both else[])+(['FALSE']if not enable else[]),group='opposite-mask-precedence')
for nodeCount,edgeCount,noPath,nm,endpoints in itertools.product([0,1,3],[0,1,3],[False,True],[['A','B','C'],[None,'B','A'],['A','A','C']],[ [[0,1],[1,0],[2,1]],[[1,1],[0,1],[2,2]],[[2,0],[0,2],[0,0]]]):
 run({'nodeCount':nodeCount,'edgeCount':edgeCount,'noPath':noPath,'names':nm,'endpoints':endpoints},['from=A','to=B','BLOCK','bothways'],group='ordered-edge-lookup')
for t in [['from=A','to=B','FALSE','TRUE'],['from=A','to=B','DONTTOGGLE'],['xxfrom=A','xxto=B','block'],['from=A','from=B','to=A','OBSTACLE'],['from=A','to=A','BLOCK'],['from=A','to=B','forgoodies','FORBADDIES'],['from=A','to=B','OBSTACLE','FALSE'],['from=A','to=B','BLOCK','from=Missing']]:run({},t,group='ordered-substrings')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());authored=next(r for r in ledger['rows']if r['kind']=='scp-action'and r['name']=='SetPathCnxFlag')
for u in authored['uses']:
 tokens=u['args'];fn=next((t[t.lower().index('from')+5:]for t in reversed(tokens)if'from'in t.lower()),'A');tn=next((t[t.lower().index('to')+3:]for t in reversed(tokens)if'to'in t.lower()),'B')
 # Actual authored names are allocated without text pre-normalization.
 if fn==tn:nodeNames=[fn,'Other','Third']
 else:nodeNames=[fn,tn,'Third']
 run({'names':nodeNames},tokens,True,'authored')
report={'binarySha256':n.sha256,'cases':len(vectors),'assertionGroups':2*len(vectors),'mismatches':len(errors),'errors':errors,'groups':groups,'authoredOccurrences':authored['sourceUses'],'method':'Original4505d0 with unchanged44d870/dialect readers/51ad80/51adf0 and string helpers. No adapters. Complete65536byte image andreturn1 checked. Portable projection composes already recovered navigation helpers.','limits':['Prepared valid ASCIIstrings and byte-counted path/adjacency backing. Native world/path allocation/loading and consumer scheduling remain external.','Three flag dialects and explicit global fallback/opposite masks; normal mode/global producer state is provided, not inferred.','Native parser from/to substring skips use valid prepared offsets; malformed unterminated or out-of-bounds strings excluded.']}
(m.BASE/'reports/movement-phase8-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase8-20261013-fixtures.json.gz','wt',encoding='utf-8')as out:json.dump({'vectors':vectors},out,separators=(',',':'))
print(json.dumps({'cases':len(vectors),'checks':2*len(vectors),'mismatches':len(errors),'examples':errors[:4]}))
