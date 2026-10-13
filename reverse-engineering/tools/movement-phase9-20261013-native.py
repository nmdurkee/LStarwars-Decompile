"""Actual SelectRandomSpline, scene lookups, full boundedASCII comparison and QRAND."""
import importlib.util,struct,json,gzip,itertools,base64,random
from pathlib import Path
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
n=m.NativeX86();D=n.DATA;WORLD=D;SCENE=D+0x1000;SPL=D+0x10000;TEXT=D+0x12000;ACT=D+0x20000;ARGS=D+0x6000;TOKENS=D+0x7000;OUT=D+0x9000;SIZE=0x40000;errors=[];vectors=[];groups={}
records=[{'name':''if j==0 else'S'+str(j),'flags':0x8001 if j%7==0 else j*3}for j in range(40)];records[4]['name']='s1';records[5]['name']='S10'
def si(v):return v if v<0x80000000 else v-0x100000000
def cmp(a,b,length):
 if a is None:return -1
 if b is None:return 1
 if length==0:return 0
 count=len(a)if length==-1 else len(b)if length==-2 else length;i=0
 while True:
  x=ord(a[i].upper())if i<len(a)else 0;y=ord(b[i].upper())if i<len(b)else 0
  if y<x:return 1
  if x<y:return -1
  i+=1;count-=1
  if x==0 or y==0 or count==0:return 0

def setup(meta,tokens):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',0x802c54,0 if meta.get('noWorld')else WORLD);n.pack('<I',WORLD+0x13c,0 if meta.get('noScene')else SCENE);n.pack('<iI',SCENE+0x30,meta.get('sceneCount',40),SPL)
 for j,r in enumerate(records):q=SPL+j*12;n.pack('<HHII',q,meta.get('recordFlags',{}).get(str(j),r['flags']),0x55aa,TEXT+j*0x40,D+0x30000+j*0x20);n.write(TEXT+j*0x40,r['name'].encode()+b'\0')
 count=meta.get('actorCount',4);n.pack('<iI',0x93d500,count,ACT)
 actors=meta.get('actors',[{'flags':0x1001,'disabled':0,'spline':1},{'flags':0x1001,'disabled':0,'spline':7},{'flags':1,'disabled':0,'spline':2},{'flags':0x1001,'disabled':1,'spline':3}])
 for j,r in enumerate(actors):q=ACT+j*0x10d8;n.pack('<I',q+0x1fc,r['flags']);n.pack('<B',q+0x28b,r['disabled']);n.pack('<I',q+0xe64,0 if r['spline']<0 else SPL+r['spline']*12)
 n.pack('<I',0x80253c,meta.get('seed',123));n.pack('<I',0x876d94,SPL+7*12)
 cur=TOKENS
 for j,t in enumerate(tokens):n.write(cur,t.encode()+b'\0');n.pack('<I',ARGS+j*4,cur);cur+=len(t)+4
 for p,t in[(D+0xa000,meta.get('a')),(D+0xa100,meta.get('b'))]:
  if t is not None:n.write(p,t.encode()+b'\0')
 return bytearray(n.read(D,SIZE))
def model(kind,meta,tokens,first,image):
 def u(p):return struct.unpack_from('<I',image,p-D)[0]
 def h(p):return struct.unpack_from('<H',image,p-D)[0]
 def su(p,v):struct.pack_into('<I',image,p-D,v&0xffffffff)
 def sh(p,v):struct.pack_into('<H',image,p-D,v&65535)
 seed=meta.get('seed',123);selected=SPL+7*12;count=0 if meta.get('noScene')else max(0,meta.get('sceneCount',40));inds=list(range(count))
 def exact(name):return next((j for j in inds if name is not None and records[j]['name'].lower()==name.lower()),None)
 def prefix(name,cap):return[j for j in inds if cmp(name,records[j]['name'],-1)==0][:max(0,cap)]
 if kind=='compare':return cmp(meta.get('a'),meta.get('b'),meta.get('length',-1)),seed,selected,False
 if kind=='find':j=exact(meta.get('a'));return 0 if j is None else SPL+j*12,seed,selected,False
 if kind=='prefix':
  found=prefix(meta.get('a'),meta.get('capacity',32))
  for j,ix in enumerate(found):su(OUT+j*4,SPL+ix*12)
  return len(found),seed,selected,False
 if not first:return 1,seed,selected,False
 selected=0;unused=False;candidates=[]
 for t in tokens:
  low=t.lower()
  if'splines='in low:
   if meta.get('noWorld'):return None,seed,selected,True
   candidates+=prefix(t[low.index('splines=')+8:],32-len(candidates))
  elif'spline='in low:
   if meta.get('noWorld'):return None,seed,selected,True
   j=exact(t[low.index('spline=')+7:])
   if j is not None and len(candidates)<32:candidates.append(j)
  elif'unused'in low:unused=True
 if candidates:
  if unused:
   eligible=[]
   for j in range(max(0,meta.get('actorCount',4))):
    q=ACT+j*0x10d8;f=u(q+0x1fc)
    if f&1 and f&0x1000 and image[q-D+0x28b]==0 and u(q+0xe64):eligible.append(u(q+0xe64));sh(u(q+0xe64),h(u(q+0xe64))|0x8000)
   candidates=[j for j in candidates if not h(SPL+j*12)&0x8000]
   for p in eligible:sh(p,h(p)&0x7fff)
  if candidates:seed=(seed*0x24cd+1)&65535;selected=SPL+candidates[seed//(65535//len(candidates)+1)]*12
 return 1,seed,selected,False

def run(kind,meta=None,tokens=None,first=True,group=None):
 meta=meta or {};tokens=tokens or [];before=setup(meta,tokens);expected=bytearray(before);want,wseed,wselected,wfault=model(kind,meta,tokens,first,expected);fault=False;result=None
 args={'select':[0,0,0,ARGS,len(tokens),int(first)],'find':[0 if meta.get('noScene')else SCENE,0 if meta.get('a')is None else D+0xa000],'prefix':[0 if meta.get('noScene')else SCENE,0 if meta.get('a')is None else D+0xa000,OUT,meta.get('capacity',32)],'compare':[0 if meta.get('a')is None else D+0xa000,0 if meta.get('b')is None else D+0xa100,meta.get('length',-1)]}[kind]
 try:result=n.call({'select':0x449f70,'find':0x5d0690,'prefix':0x5d0740,'compare':0x4f8b80}[kind],args)
 except RuntimeError:fault=True
 after=n.read(D,SIZE);seed=n.unpack('<I',0x80253c)[0];selected=n.unpack('<I',0x876d94)[0];g=group or kind;groups[g]=groups.get(g,0)+1
 if after!=expected or seed!=wseed or selected!=wselected or fault!=wfault or(not fault and result!=(want&0xffffffff)):errors.append({'kind':kind,'meta':meta,'tokens':tokens,'first':first,'return':[result,want],'seed':[seed,wseed],'selected':[selected,wselected],'fault':[fault,wfault],'diff':[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:25]})
 vectors.append({'kind':kind,'input':dict(meta),'tokens':tokens,'first':first,'before':base64.b64encode(gzip.compress(before)).decode(),'after':base64.b64encode(gzip.compress(after)).decode(),'seed':seed,'selected':selected,'fault':fault,'result':result})
for a,b,length in itertools.product([None,'','s','S1','S10','abc','ABCx'],[None,'','S','S1','S10','ab','abcx'],[-3,-2,-1,0,1,2,9]):run('compare',dict(a=a,b=b,length=length),group='ascii-length-null-compare')
for kind,a,noScene,count,capacity in itertools.product(['find','prefix'],[None,'','S','s1','S1*','Missing'],[False,True],[-1,0,4,40],[-1,0,1,32,40]):run(kind,dict(a=a,noScene=noScene,sceneCount=count,capacity=capacity),group='actual-scene-table-lookups')
for first,noWorld,noScene,seed,tokens in itertools.product([False,True],[False,True],[False,True],[0,1,65535,0xffffffff],[[],['unused'],['splines=S'],['spline=S1'],['splines=','unused'],['splines=S','unused'],['spline=S1','spline=S1','spline=S2'],['splines=S1','spline=S1','unused']]):run('select',dict(noWorld=noWorld,noScene=noScene,seed=seed),tokens,first,'selector-first-candidate-gates')
for flags,disabled,attached,count,preFlag in itertools.product([0,1,0x1000,0x1001],[0,1],[-1,1,2],[0,1,2,4],[0,0x8000]):
 actors=[dict(flags=flags,disabled=disabled,spline=attached),dict(flags=0x1001,disabled=0,spline=attached),dict(flags=0x1001,disabled=0,spline=3),dict(flags=0x1001,disabled=0,spline=7)]
 run('select',dict(actors=actors,actorCount=count,recordFlags={'1':preFlag|5}),['splines=S','unused'],group='unused-actor-eligibility-alias-cleanup')
for tokens in [['spline=S1']*40,['splines=S']*5,['splines=S','spline=S1','unused'],['unusedness','spline=unused'],['spline=S1','splines=S1','spline=S2'],['spline=Missing','splines=S*'],['splines=','spline=S1'],['spline=S7','unused']]:run('select',{},tokens,True,'capacity-ordered-prefix')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());authored=next(r for r in ledger['rows']if r['kind']=='scp-action'and r['name']=='SelectRandomSpline')
for u in authored['uses']:run('select',{},u['args'],True,'authored')
report={'binarySha256':n.sha256,'cases':len(vectors),'assertionGroups':5*len(vectors),'mismatches':len(errors),'errors':errors,'groups':groups,'authoredOccurrences':authored['sourceUses'],'method':'Actual449f70/5d0690/5d0740/4f8b80 and originalQRAND/stringfunctions execute without adapters. Complete262144byte image, RNG/selectedpointer/fault/return compared. C# replay separate and pending.','limits':['Prepared valid40entry scene table and4 dense actors with pointer identity/attached aliases; signedscene/actor count bounds and capacity32.','ASCII bounded compare domain includes null pointers,length0/-1/-2/other negative and prepared terminated strings. No malformed memory reads or extendedbyte case table claim.','Actor-array and scene/spline producers, selectedspline consumers, global worldpointer lifetime remain external.']}
(m.BASE/'reports/movement-phase9-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase9-20261013-fixtures.json.gz','wt',encoding='utf-8')as out:json.dump({'records':records,'vectors':vectors},out,separators=(',',':'))
print(json.dumps({'cases':len(vectors),'checks':report['assertionGroups'],'mismatches':len(errors),'examples':errors[:4]}))
