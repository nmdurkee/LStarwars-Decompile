"""Original PC trigger readers, name binding and occupancy; no game/OS launch.
No native function/callback is replaced. Compact portable oracle, compile separately.
"""
import importlib.util, json, gzip, struct, itertools, random, re, hashlib
from pathlib import Path
def module(name, filename):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(filename));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=module('trigger_native','native-x86.py');wide=module('trigger_wide','animation-x87.py')
from unicorn.x86_const import UC_X86_REG_EDI
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=nx.NativeX86();B=nx.BASE;D=n.DATA
SYS=D;PROC=D+0x2000;CREATURE=D+0x3000;WORLD=D+0x4000;OWNER=D+0x8000;AREA=D+0xc000;FALLBACK=D+0xd000;TEXT=D+0xe000;OUT=D+0xf000;OBJECTS=D+0x20000;LIST=D+0x40000;COND=LIST+0x100;DEF=LIST+0x200
TRIG=(B/'references/native-animation-sine-table.f32').read_bytes();sine=struct.unpack('<32768f',TRIG);n.write(0x29899a0,TRIG)
ADDR={'InTriggerArea':0x514bd0,'PlayerInTriggerArea':0x514fb0,'Player2InTriggerArea':0x515010,'EitherPlayerInTriggerArea':0x515070}
report={'binarySha256':n.sha256,'checks':0,'mismatches':0,'groups':{},'errors':[]};fixtures={'conditions':[],'lookups':[],'producers':[]};rng=random.Random(0x43b7c0)
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def f32(x):return struct.unpack('<f',struct.pack('<f',x))[0]
def check(group,got,want,meta=None):
 report['checks']+=1;g=report['groups'].setdefault(group,{'checks':0,'mismatches':0});g['checks']+=1
 if got!=want:
  report['mismatches']+=1;g['mismatches']+=1
  if len(report['errors'])<12:report['errors'].append({'group':group,'native':got,'expected':want,'input':meta})
def float_call(address,args):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(address,args);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<I',OUT)[0]
def token(text):
 if text is None:return 0
 n.write(TEXT,text.encode('latin1')+b'\0');return TEXT
def folded(text):
 if text is None:return None
 return bytes(v-32 if 97<=v<=122 or v>=224 else v for v in text.encode('latin1'))
def lookup(names,operand,reader='find',system=True,count=None,meta=None):
 count=len(names)if count is None else count
 n.write(SYS,bytes(0x1400));n.pack('<iI',SYS+0x34,count,AREA)
 for i,name in enumerate(names):n.write(AREA+i*64,bytes(64));n.write(AREA+i*64,name.encode('latin1')+b'\0')
 target={'find':0x51acd0,'bindSelf':0x52d0b0,'bindPlayers':0x52d160}[reader]
 got=n.call(target,[SYS if system else 0,token(operand)]);got=(got-AREA)//64 if got else -1
 want=next((i for i,name in enumerate(names[:max(count,0)])if operand is not None and folded(name)==folded(operand)),-1)if system else -1
 check('lookup-'+reader,got,want,meta or {'names':names,'operand':operand,'count':count})
 fixtures['lookups'].append({'names':names,'operand':operand,'reader':reader,'system':system,'count':count,'nativeIndex':got,'source':meta});return got
def member(mask,index):
 low=1<<(index&31);high=0xffffffff if low==0x80000000 else 0
 return bool((mask[0]&low)|(mask[1]&high))
def condition(name,index=0,masks=None,meta=None,comparison=None,**kw):
 state={'system':True,'areaTable':True,'player1':True,'player2':True,'creature':True,'object':True,'initialized':True,'fallback':False,'owner':True,'index':index,'fallbackIndex':1,'masks':masks or [[0,0],[0,0],[0,0]]};state.update(kw)
 n.write(SYS,bytes(0x1400));n.write(PROC,bytes(0x200));n.write(CREATURE,bytes(0x200));n.write(OWNER,bytes(0x100));n.write(AREA,bytes(64));n.write(FALLBACK,bytes(64))
 n.pack('<I',SYS+0x38,AREA if state['areaTable']else 0);n.pack('<II',SYS+0x138c,OBJECTS if state['player1']else 0,OBJECTS+0x10d8 if state['player2']else 0)
 n.pack('<I',CREATURE+0xd0,OBJECTS+2*0x10d8 if state['object']else 0);n.pack('<I',PROC+0xa0,FALLBACK if state['fallback']else 0)
 n.pack('<I',AREA+0x38,OWNER if state['owner']else 0);n.pack('<I',FALLBACK+0x38,OWNER+0x80 if state['owner']else 0)
 n.pack('<I',OWNER+0x38,(AREA-64*index)&0xffffffff);n.pack('<I',OWNER+0xb8,(FALLBACK-64*state['fallbackIndex'])&0xffffffff)
 for i,mask in enumerate(state['masks']):n.pack('<II',OBJECTS+i*0x10d8+0x2b0,*mask)
 initialized=AREA if state['initialized']else 0
 got=float_call(ADDR[name],[SYS if state['system']else 0,PROC,CREATURE if state['creature']else 0,0,initialized])
 active=state['initialized']or state['fallback'];idx=index if state['initialized']else state['fallbackIndex'];hits=[member(mask,idx)for mask in state['masks']]
 hit={'InTriggerArea':state['creature']and state['object']and hits[2],'PlayerInTriggerArea':state['system']and state['areaTable']and state['player1']and hits[0],'Player2InTriggerArea':state['system']and state['player2']and hits[1],'EitherPlayerInTriggerArea':state['system']and((state['player1']and hits[0])or(state['player2']and hits[1]))}[name]
 want=bits(float(bool(active and state['owner']and hit)));check('reader-'+name,got,want,meta or state)
 row={'command':name,'input':state,'nativeBits':got,'source':meta}
 if comparison:
  op,threshold=comparison;ops={'==':(0,lambda a,b:a==b),'<':(1,lambda a,b:a<b),'>':(2,lambda a,b:a>b),'<=':(3,lambda a,b:a<=b),'>=':(4,lambda a,b:a>=b),'!=':(5,lambda a,b:a!=b)}
  n.write(LIST,bytes(0x300));n.pack('<I',LIST,COND);n.pack('<f',COND+8,threshold);n.pack('<B',COND+12,ops[op][0]);n.pack('<I',COND+0x18,initialized);n.pack('<I',COND+0x1c,DEF);n.pack('<II',DEF,0,ADDR[name])
  from unicorn.x86_const import UC_X86_REG_EAX
  result=n.call(0x52c880,[SYS,LIST,CREATURE,PROC],regs={UC_X86_REG_EAX:0})!=0
  expected=ops[op][1](struct.unpack('<f',struct.pack('<I',got))[0],threshold);check('authored-literal-comparison',result,expected,meta)
  row['comparison']={'operator':op,'threshold':threshold,'native':result}
 fixtures['conditions'].append(row)
def area(index=0,yaw=0,position=(0.,0.,0.),extent=(1.,2.,1.),state=0xff):return {'index':index,'yaw':yaw,'position':list(position),'extent':list(extent),'state':state}
def obj(position=(0.,0.,0.),flags=0x1001,stateFlags=0,restricted=0,timer=0.,mask=(0,0)):
 return {'position':list(position),'flags':flags,'stateFlags':stateFlags,'restricted':restricted,'timer':timer,'mask':list(mask)}
def producer(a,objects,meta=None):
 initial=bytearray([0xa5]*64);struct.pack_into('<6fhB',initial,0x10,*a['position'],*a['extent'],a['yaw'],a['state']);n.write(AREA,initial)
 n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x2ae8,SYS);n.pack('<I',SYS+0x38,(AREA-a['index']*64)&0xffffffff);n.pack('<iI',0x93d500,len(objects),OBJECTS)
 raw=[];expected=[];state=a['state']&0xf8;angle=-a['yaw'];co=sine[((angle+0x4000)>>1)&0x7fff];si=sine[(angle>>1)&0x7fff]
 for i,o in enumerate(objects):
  r=bytearray([0x5a]*0x10d8);struct.pack_into('<3f',r,0x5c,*o['position']);struct.pack_into('<II',r,0x1f8,o['stateFlags'],o['flags']);r[0x28b]=o['restricted'];struct.pack_into('<f',r,0x1010,o['timer']);struct.pack_into('<II',r,0x2b0,*o['mask']);raw.append(r);n.write(OBJECTS+i*0x10d8,r)
  masks=o['mask'].copy();flags=o['flags']
  if flags&1 and flags&0x1000 and(o['restricted']==0 or o['timer']>0 or flags&0x80):
   x,y,z=[wide.store(wide.add(wide.wide(p),wide.wide(-q)))for p,q in zip(o['position'],a['position'])]
   lx=wide.store(wide.add(wide.mul(wide.wide(si),wide.wide(z)),wide.mul(wide.wide(co),wide.wide(x))))
   lz=wide.store(wide.add(wide.mul(wide.wide(z),wide.wide(co)),wide.mul(wide.wide(-x),wide.wide(si))))
   w,h,d=a['extent'];inside=-w<=lx<=w and f32(-.1)<=y<=h and -d<=lz<=d
   if inside:
    mask=1<<(a['index']&31);masks[0]|=mask
    if mask==0x80000000:masks[1]=0xffffffff
    if flags&0x80:state|=1
    if o['stateFlags']&1:state|=4
    elif not o['stateFlags']&4:state|=2
   else:
    shift=a['index']&255;mask=1<<shift if shift<64 else 0;masks[0]&=(~mask)&0xffffffff;masks[1]&=(~(mask>>32))&0xffffffff
  expected.append(masks)
 n.call(0x43b7c0,regs={UC_X86_REG_EDI:AREA})
 actualState=n.read(AREA+0x2a,1)[0];actualMasks=[list(n.unpack('<II',OBJECTS+i*0x10d8+0x2b0))for i in range(len(objects))]
 check('producer-state-and-masks',[actualState,actualMasks],[state,expected],meta or {'area':a,'objects':objects})
 initial[0x2a]=state;preserved=n.read(AREA,64)==bytes(initial)
 for i,r in enumerate(raw):struct.pack_into('<II',r,0x2b0,*expected[i]);preserved=preserved and n.read(OBJECTS+i*0x10d8,0x10d8)==bytes(r)
 check('producer-entire-record-write-bounds',preserved,True,meta)
 fixtures['producers'].append({'area':a,'objects':objects,'nativeState':actualState,'nativeMasks':actualMasks,'source':meta})

# Every single bit in both halves, crossed with 64 area indices and all readers.
for index,bit in itertools.product(range(64),range(64)):
 masks=[[1<<bit if bit<32 else 0,1<<(bit-32)if bit>=32 else 0]]*3
 for name in ADDR:condition(name,index,masks)
for index in [-257,-256,-33,-32,-1,64,95,127,255,256,257]:
 for mask in [[0,0],[1,0],[0x80000000,0],[0,1],[0,0xffffffff],[0xffffffff,0xffffffff]]:
  for name in ADDR:condition(name,index,[mask]*3)
gateKeys=['system','areaTable','player1','player2','creature','object','initialized','fallback','owner']
for values in itertools.product([False,True],repeat=len(gateKeys)):
 for name in ADDR:condition(name,31,[[0,1],[0,1],[0,1]],fallbackIndex=0,**dict(zip(gateKeys,values)))
for names in [['a','A','b'],['','b'],['\xff','\xdf'],['\xe0','\xc0'],['longername123456']]:
 for operand in [None,'','a','A','missing','\xff','\xdf','\xe0','longername123456']:
  for reader,system,count in itertools.product(['find','bindSelf','bindPlayers'],[False,True],[-1,0,len(names)]):lookup(names,operand,reader,system,count)
# Exhaust all byte fold inputs without treating Unicode case mapping as native.
for value in range(1,256):lookup([chr(value)],chr(value-32 if 97<=value<=122 or value>=224 else value))
for index in list(range(256))+[-257,-256,-1,256,257]:
 for p in [(0.,0.,0.),(3.,0.,0.)]:producer(area(index=index),[obj(position=p,mask=(0x13579bdf,0x2468ace0))])
for flags,restricted,timer,stateFlags in itertools.product([0,1,0x1000,0x1001,0x1081,0xffffffff],[0,1,255],[-1.,0.,1.],[0,1,4,5]):
 producer(area(state=0xaf),[obj(flags=flags,restricted=restricted,timer=timer,stateFlags=stateFlags,mask=(0,0x40))])
for yaw in range(-32768,32768,32):
 producer(area(index=yaw&63,yaw=yaw),[obj(position=(f32(rng.uniform(-2,2)),f32(rng.uniform(-.2,2.1)),f32(rng.uniform(-2,2))),mask=(0xffffffff,0xffffffff))])
for bound,axis in [(1.,0),(-1.,0),(f32(-.1),1),(2.,1),(1.,2),(-1.,2)]:
 for delta in [-1,0,1]:
  value=struct.unpack('<f',struct.pack('<I',bits(bound)+delta))[0];p=[0.,0.,0.];p[axis]=value;producer(area(),[obj(position=p,mask=(1,0))])
producer(area(),[])
producer(area(),[obj(flags=0x1081,stateFlags=1),obj(stateFlags=0),obj(position=(20.,20.,20.)),obj(flags=0)])

# Shipped AI2 fields are uploaded into explicit 64-byte runtime projections.
index=json.loads((B/'reports/gameplay-binary/index.json').read_text());carriers=[];authored=[]
for e in index['entries']:
 if e['type']!='AI2':continue
 decoded=json.loads(gzip.decompress((B.parent/e['output']).read_bytes()));triggers=decoded['triggers'];names=[v['name']for v in triggers];carriers.append({'source':e['source'],'sha256':e['sha256'],'names':names})
 for i,t in enumerate(triggers):
  meta={'source':e['source'],'sha256':e['sha256'],'trigger':t['name'],'index':i,'offset':t['offset']};authored.append(meta)
  for reader in ['find','bindSelf','bindPlayers']:lookup(names,t['name'],reader,meta=meta)
  a=area(i,t['angle']['raw'],t['position'],t['halfSize'],t['unknownBytes'][0]);x,y,z=a['position'];w,h,d=a['extent']
  # Center, above/below, and four world axes; no assumed ideal inverse transform.
  for delta in [(0,0,0),(0,h,0),(0,-.1,0),(0,h+1,0),(0,-1,0),(w+1,0,0),(-w-1,0,0),(0,0,d+1),(0,0,-d-1)]:
   p=tuple(f32(q+r)for q,r in zip((x,y,z),delta));producer(a,[obj(position=p,flags=0x1081,stateFlags=1,mask=(0xffffffff,0xffffffff))],meta)

ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());uses=[];omissions=[]
for row in ledger['rows']:
 if row['name']not in ADDR:continue
 for use in row['uses']:
  name=row['name'];quoted=re.findall(r'"([^"]*)"',use['text']);operand=quoted[0]if quoted else None
  parent=Path(use['source']).parent.as_posix().lower();matches=[c for c in carriers if Path(c['source']).parent.as_posix().lower()==parent]
  names=matches[0]['names']if len(matches)==1 else ['fixture_area'];status='same-directory authored AI2'if len(matches)==1 else 'no unique local AI2; synthetic binding only'
  got=lookup(names,operand,'bindSelf'if name=='InTriggerArea'else'bindPlayers',meta={'source':use['source'],'line':use['line'],'text':use['text'],'bindingScope':status})
  comparison=None;m=re.search(r'(==|!=|<=|>=|<|>)\s*(.*?)(?:\s+(?:goto|and|or)(?:\s|$)|$)',use['text'],re.I)
  if m and re.fullmatch(r'-?(?:\d+(?:\.\d*)?|\.\d+)',m[2]):comparison=(m[1],f32(float(m[2])))
  else:omissions.append({'source':use['source'],'line':use['line'],'text':use['text'],'reason':'Nonliteral or malformed comparison/control text'})
  meta={'source':use['source'],'line':use['line'],'text':use['text'],'operand':operand,'bindingScope':status,'bindingIndex':got}
  condition(name,max(got,0),[[1,0],[0,0],[1,0]],initialized=got>=0,fallback=operand is None,comparison=comparison,meta=meta);uses.append(meta)

# Exact whole-body assembly ranges (supporting helpers are not extra mapped APIs).
dis=Cs(CS_ARCH_X86,CS_MODE_32)
ranges=[(0x43b7c0,0x178),(0x5b3620,0x6f),(0x5b3800,0x25),(0x6e69d0,0x1f),(0x514bd0,0x56),(0x514fb0,0x5c),(0x515010,0x56),(0x515070,0x8f),(0x51acd0,0x45),(0x52d0b0,0x1a),(0x52d160,0x1a)]
assembly={'binarySha256':n.sha256,'procedures':[{'address':hex(a),'bytes':z,'sha256':hashlib.sha256(n.read(a,z)).hexdigest(),'instructions':[{'address':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str}for i in dis.disasm(n.read(a,z),a)]}for a,z in ranges]}
(B/'reports/gameplay-trigger-assembly.json').write_text(json.dumps(assembly,indent=2)+'\n')
fixtures['binarySha256']=n.sha256;fixtures['sineTable']={'path':'references/native-animation-sine-table.f32','sha256':hashlib.sha256(TRIG).hexdigest()}
oracle=B/'reports/gameplay-trigger-native-fixtures.json.gz';oracle.write_bytes(gzip.compress(json.dumps(fixtures,separators=(',',':')).encode(),mtime=0))
report.update(fixtureCounts={k:len(fixtures[k])for k in ['conditions','lookups','producers']},fixture={'path':oracle.relative_to(B).as_posix(),'bytes':oracle.stat().st_size,'sha256':hashlib.sha256(oracle.read_bytes()).hexdigest()},sineTable=fixtures['sineTable'],authoredAreas=authored,authoredAreaCount=len(authored),authoredCarriers=len(carriers),authoredUses=uses,authoredUseCount=len(uses),comparisonOmissions=omissions,
 method='Original reader, initializer, lookup, occupancy, vector helpers, shift helper and SCP comparison bytes in isolated Unicorn. No callback substitutions. Sine bytes previously generated by original0x5bdd50. All occupancy cases also compare the full64-byte area and every full4312-byte object against expected writes. Prepared managed comparisons remain unexecuted.',
 limits=['Finite positions/extents/timers and a complete original sine table. NaNs, infinities, invalid raw pointers, concurrent mutation, and malformed unterminated names excluded.','TriggerSystem/TriggerArea/TriggerObject are explicit runtime projections, not the full loader or object lifetime implementation.','Producer scheduling in0x43b940 and global world/object-array population remain external. Eligibility-skipped objects preserve stale trigger masks.','Authored AI2 upload maps recovered file fields into runtime fields; native AI2 loading is not executed here. Source angle raw16bits is used, not BrickBench degree conversion.','Same-directory AI2 name resolution is source evidence only; shared scripts without a unique local carrier retain an explicit synthetic binding scope.','Managed core/harness compile separately; no generated managed executable is run.'])
(B/'reports/gameplay-trigger-tests.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps({k:report[k]for k in ['checks','mismatches','groups','fixtureCounts','fixture','authoredAreaCount','authoredCarriers','authoredUseCount','comparisonOmissions','errors']},indent=2));assert not report['mismatches']
