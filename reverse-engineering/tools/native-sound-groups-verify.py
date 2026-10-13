import importlib.util,json,struct,gzip,hashlib,itertools,random,re,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('definitions',Path(__file__).with_name('native-sound-definition-verify.py'));d=importlib.util.module_from_spec(s);s.loader.exec_module(d);n=d.n;b=d.b;B=d.B;D=d.D;b.REGIONS=[(0x810364,4),(0x2920000,0x44000),(D,0x80000)]
from unicorn import UC_HOOK_CODE
RNG=0x810364;GROUPS=0x2920d88;MEMBERS=0x2921260
visited=set();findCalls=0
def observe(mu,a,z,u):
 global findCalls
 visited.add(a)
 if a==0x650dc0:findCalls+=1
for a,z in [(0x650c50,0x650dbf),(0x652010,0x6520af),(0x5b9e10,0x5b9e2f),(0x650dc0,0x650dc0)]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=z)
def short(m,a):return struct.unpack('<h',m.read(a,2))[0]
def half(m,a,v):m.write(a,struct.pack('<H',v&65535))
def signed(v):return v if v<0x80000000 else v-0x100000000
def create(m,sound):
 group=m.get(0x2962024);member=m.get(0x2962020)
 if group==128 or member==512:return -1
 g=GROUPS+group*8;half(m,g,member);half(m,g+2,1);half(m,g+4,0);half(m,m.get(0x2947b74)+sound*64+0x14,group);half(m,MEMBERS+member*2,sound);m.put(0x2962020,member+1);m.put(0x2962024,group+1);return group
def helper(m,p):
 kind=p['kind'];g=GROUPS+p['group']*8;start=short(m,g);count=short(m,g+2)
 if kind=='create':return create(m,p['sound'])
 if kind=='contains':return int(any(short(m,MEMBERS+i*2)==p['sound'] for i in range(start,start+count)))
 if kind=='count':return count
 if kind=='at':return short(m,MEMBERS+(start+p['ordinal'])*2)
 if kind=='random':v=(m.get(RNG)*0x19660d+0x3c6ef35f)&0xffffffff;m.put(RNG,v);return v
 if p['sequential']==0:
  v=(m.get(RNG)*0x19660d+0x3c6ef35f)&0xffffffff;m.put(RNG,v);selected=(v>>16)%(count&0xffffffff or 1)
 else:
  selected=short(m,g+4);next=((selected+1+32768)&65535)-32768;half(m,g+4,0 if count<=next else next)
 return short(m,MEMBERS+(start+selected)*2)
def find(m,name):
 head=m.get(0x292fda0)
 if not head:return -1
 index=short(m,head+(d.hash_name(name)&255)*2)
 while index!=-1:
  r=m.get(0x2947b74)+index*64;ptr=m.get(r)
  if ptr and d.text(m,ptr)[:32].upper()==name[:32].upper():return index
  index=short(m,r+0x10)
 return -1
def parse(m,p):
 group=-1;first=True;events=[];calls=0
 for i in range(len(p['tokens'])+1):
  t=p['tokens'][i]['text'] if i<len(p['tokens']) else '';at=d.TOKENS+i*256;m.text(at,t);m.put(d.PARSER+0x510,at);events.append(['next',i,t])
  if i==len(p['tokens']):break
  sound=find(m,t);calls+=1
  if first:
   if sound==-1:break
   group=create(m,sound);first=False
  else:
   sound=find(m,t);calls+=1
   if sound!=-1 and m.get(0x2962020)!=512:
    member=m.get(0x2962020);half(m,MEMBERS+member*2,sound);m.put(0x2962020,member+1);g=GROUPS+group*8;half(m,g+2,short(m,g+2)+1);half(m,g+4,0)
 return events,calls
def capture():
 m=b.Image(0)
 for a,size in b.REGIONS:m.r[a]=bytearray(n.read(a,size))
 return m
def load(m):
 for a,data in m.r.items():n.write(a,data)
def native_parse(p,address):
 global findCalls
 d.current=p;d.cursor=-1;d.events=[];findCalls=0;n.call(address,[d.PARSER],count=1000000);return copy.deepcopy(d.events),findCalls

def main():
 rows=[];errors=[];groups={};rng=random.Random(0x650d10)
 def compare(kind,p,want,result=None,events=None,finds=None):
  actual=capture();bad=[]
  if actual.sha()!=want.sha():
   diffs=[]
   for a,data in want.r.items():diffs.extend(dict(address=hex(a+i),got=actual.r[a][i],want=v) for i,v in enumerate(data) if actual.r[a][i]!=v)
   bad.append(dict(differences=diffs[:12]))
  if result is not None and p.get('result')!=result:bad.append(dict(result=p.get('result'),want=result))
  if events is not None and d.events!=events:bad.append(dict(events=d.events,wantEvents=events))
  if finds is not None and findCalls!=finds:bad.append(dict(findCalls=findCalls,wantFindCalls=finds))
  if bad:errors.append(dict(kind=kind,input=p,bad=bad))
  rows.append(dict(kind=kind,input=p,nativeSha=actual.sha(),events=copy.deepcopy(d.events) if events is not None else None,findCalls=findCalls if finds is not None else None));groups[kind]=groups.get(kind,0)+1
 cases=[]
 for groupCount,memberCount,sound in itertools.product([0,1,127,128],[0,1,511,512],[0,3,1130]):cases.append(dict(kind='create',group=0,groupCount=groupCount,memberCount=memberCount,sound=sound))
 for count,start,sound in itertools.product([-5,0,1,5,31],[-1,0,7],[-32768,-1,0,3,32767]):cases.append(dict(kind='contains',group=2,count=count,start=start,sound=sound))
 for count in [-32768,-1,0,1,32767]:cases.append(dict(kind='count',group=3,count=count))
 for start,ordinal in itertools.product([-5,0,7],[-3,0,1,31]):cases.append(dict(kind='at',group=2,start=start,ordinal=ordinal))
 for count,cursor,sequential,seed in itertools.product([0,1,2,5,31],[-1,0,1,4,31,32767],[0,1,-1],[0,1,0x80000000,0xffffffff,0x12345678]):
  if sequential and cursor==32767:continue
  cases.append(dict(kind='select',group=1,count=count,cursor=cursor,sequential=sequential,seed=seed))
 for seed in [0,1,0x80000000,0xffffffff]+[rng.getrandbits(32) for _ in range(256)]:cases.append(dict(kind='random',group=0,seed=seed))
 for p in cases:
  p.setdefault('count',3);p.setdefault('start',0);p.setdefault('cursor',0);p.setdefault('seed',17);p.setdefault('groupCount',3);p.setdefault('memberCount',7);m=d.setup(d.options([]));m.put(RNG,p['seed']);m.put(0x2962024,p['groupCount']);m.put(0x2962020,p['memberCount']);g=GROUPS+p['group']*8;half(m,g,p['start']);half(m,g+2,p['count']);half(m,g+4,p['cursor'])
  for i in range(-8,80):half(m,MEMBERS+i*2,[-32768,-1,0,3,32767][(i+8)%5])
  load(m);want=helper(m,p);address={'create':0x650c50,'contains':0x650cd0,'select':0x650d10,'count':0x650d90,'at':0x650da0,'random':0x5b9e10}[p['kind']];args={'create':[p.get('sound')],'contains':[p['group'],p.get('sound')],'select':[p['group'],p.get('sequential')],'count':[p['group']],'at':[p['group'],p.get('ordinal')],'random':[RNG]}[p['kind']];result=n.call(address,args);p['result']=result if p['kind']=='random' else signed(result);compare('helper',p,m,want)
  if errors:break
 #Build actual searchable sound records and process the shipped declarations in order.
 initial=d.options([],index=0,seed=23);m=d.setup(initial);m.write(d.RECORDS,bytes(0x19000));m.write(d.BACKUP,bytes(0x19000));m.write(d.BANKS,bytes(0xaf00));m.put(0x2962024,0);m.put(0x2962020,0);m.put(RNG,1);load(m);stream=[]
 for lineNumber,line in enumerate((B/'extracted/AUDIO/AUDIO.CFG').read_text(encoding='latin1').splitlines(),1):
  line=line.split(';',1)[0].strip();tokens=[a if a is not None and a!='' else c for a,c in re.findall(r'"([^"]*)"|([^\s]+)',line)]
  if not tokens or tokens[0].lower() not in ['sample','group']:continue
  kind=tokens[0].lower();p=d.options(tokens[1:],index=m.get(0x296201c),label='authored:'+str(lineNumber));stream.append(dict(kind=kind,input=p))
  if kind=='sample':m,ev=d.model(p,m);expectedFinds=None
  else:ev,expectedFinds=parse(m,p)
  native_parse(p,0x6516a0 if kind=='sample' else 0x652010);compare('stream-'+kind,p,m,events=ev,finds=expectedFinds)
  if errors:break
 streamFinal=dict(soundCount=m.get(0x296201c),bankCount=m.get(0x2962014),nameCount=m.get(0x2962018),groupCount=m.get(0x2962024),memberCount=m.get(0x2962020))
 #Parser boundaries with actual CRC lookup, including original failed-create writes.
 for groupCount,memberCount,tokens in itertools.product([0,127,128],[0,511,512],[[],['missing'],['MenuSelect'],['MenuSelect','missing','MenuBack'],['MenuSelect','MenuBack','MenuMove']]):
  p=d.options(tokens);before=copy.deepcopy(m);before.put(0x2962024,groupCount);before.put(0x2962020,memberCount);load(before);ev,calls=parse(before,p);native_parse(p,0x652010);p.update(groupCount=groupCount,memberCount=memberCount);compare('parse',p,before,events=ev,finds=calls)
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,streamFinal=streamFinal,visitedInstructions=len(visited),bytesComparedPerCase=sum(z for a,z in b.REGIONS),examples=errors[:2],method='Original650c50/650cd0/650d10/650d90/650da0/5b9e10/652010 execute. Ordered shipped sample/group declarations compose original6516a0 and650dc0 with actual hash chains, group records and shared state. Only parser token/numeric readers remain explicit services. Complete prepared memory, exact returns, reader events and repeated native lookup count compare.',limits=['Valid readable signed-index backing and acyclic lookup chains; normal count caps128groups/512members plus equality-guard boundary cases. Negative offsets are represented only where backing bytes exist.','Full-table group creation returns-1; the original group parser may then update the preceding record when later valid members arrive. Preserved and tested, not repaired.','Authored sample/group lines are tokenized externally; native file scanner, audio loading/backend and random sample playback are not recovered by this batch.','Random state is exact uint32 LCG1664525/1013904223. Selection uses high16 bits modulo unsigned-converted signed count; zero count substitutes divisor1. Managed replay pending.'])
 (B/'reports/native-sound-groups-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-groups-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,table=d.TABLEWORDS,cases=rows,streamInitial=initial),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
