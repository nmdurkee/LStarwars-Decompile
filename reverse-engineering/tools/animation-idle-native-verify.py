"""Original complete PC idle helpers versus independent state reconstruction."""
import importlib.util,struct,random,json,hashlib,collections,itertools
from pathlib import Path
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
native=module('native','native-x86.py');idle=module('idle','animation-idle-model.py');packet=module('packet','animation-playback-model.py');n=native.NativeX86();BASE=native.BASE;f32=idle.f32
SIZE=0x10d8;O=n.DATA;C=O+0x2000;G=O+0x3000;M=O+0x4000;A=O+0x5000;D=O+0x6000;SET=O+0x7000;MAP=O+0x7100;HELD=O+0x8000;H=O+0x10000;DEF=O+0x20000
n.pack('<I',0x29130e4,SET);n.pack('<I',SET,1);n.pack('<I',SET+8,233);n.pack('<II',SET+0x18,M,MAP);n.pack('<II',M+8,D,A);n.pack('<I',C+0x24,G)
rng=random.Random(0x415370);counts=collections.Counter();errors=collections.Counter();examples=[];failures=[];oracleCounts=collections.Counter()
target=BASE/'reports/animation-idle-cases.bin';out=target.open('wb');out.write(b'AIDLE001'+struct.pack('<I',0))
def upload(clips,ctx,dt,state,o):
 n.write(A,bytes(233*4));n.write(D,bytes(233*4));n.pack('<h',MAP,0 if ctx['durationLookup']else -1);n.pack('<I',C+4,ctx['characterFlags']);n.pack('<B',G+0x116,ctx['variant']);n.pack('<B',HELD+0x7d,1 if ctx['throwHeld']else 0);n.pack('<I',0x80253c,state['seed']);n.pack('<f',0x29a99a4,state['blendOut']);n.pack('<f',0x925018,dt)
 struct.pack_into('<I',o.b,0x50,M if ctx['modelPresent']else 0);struct.pack_into('<I',o.b,0x54,C);struct.pack_into('<I',o.b,0xcc0,HELD if ctx['throwHeld']else 0);o.s16(0x1064,0)
 for i,c in clips.items():
  h=H+i*64;d=DEF+i*80;n.pack('<f',h,c['endFrame']);n.pack('<I',A+4*i,h);n.pack('<I',D+4*i,d);n.pack('<I',d+4,c['flags']);n.pack('<BB',d+12,c['minimum'],c['maximum']);n.pack('<ff',d+20,c['blendOut'],c['fps'])
 n.write(O,o.b)
def run(kind,o,clips,ctx,state,dt=0.,action=1,mode=1,group=None,record=True):
 upload(clips,ctx,dt,state,o);before=bytes(o.b);initial=dict(state);want=packet.Packet(before);expected=dict(state);ret=0
 if kind==0:ret=idle.base(want,clips,ctx);actualRet=n.call(0x415050,[O])
 elif kind==1:idle.reset(want,clips,ctx,expected,mode,action);n.call(0x4150d0,[O,mode,action]);actualRet=0
 elif kind==2:idle.choose(want,clips,ctx,expected,action);n.call(0x4151c0,[O,action],count=2000000);actualRet=0
 else:idle.update(want,clips,ctx,expected,dt);n.call(0x415370,[O],count=2000000);actualRet=0
 actual=n.read(O,SIZE);actualSeed=n.unpack('<I',0x80253c)[0];actualBlend=n.read(0x29a99a4,4);name=group or ['base','reset','variation','update'][kind];counts[name]+=1
 if actual!=want.b or actualSeed!=expected['seed']or actualBlend!=struct.pack('<f',expected['blendOut'])or actualRet!=ret:
  errors[name]+=1
  if len(examples)<20:examples.append({'kind':kind,'group':name,'case':counts[name]-1,'action':action,'mode':mode,'context':ctx,'state':initial,'dt':dt,'clips':clips,'before':before.hex(),'actual':actual.hex(),'expected':bytes(want.b).hex(),'actualSeed':actualSeed,'expectedSeed':expected['seed'],'actualBlend':actualBlend.hex(),'expectedBlend':struct.pack('<f',expected['blendOut']).hex(),'return':actualRet,'expectedReturn':ret,'firstDifferences':[hex(i)for i,(a,b)in enumerate(zip(actual,want.b))if a!=b][:16]})
 if record:
  out.write(struct.pack('<IiiIffIIIIII',kind,action,mode,initial['seed'],dt,initial['blendOut'],ctx['variant'],ctx['characterFlags'],ctx['throwHeld'],ctx['durationLookup'],ctx['modelPresent'],len(clips)))
  for i,c in sorted(clips.items()):out.write(struct.pack('<iIBB2xfff',i,c['flags'],c['minimum'],c['maximum'],c['endFrame'],c['fps'],c['blendOut']))
  out.write(before);out.write(actual);out.write(struct.pack('<iI',actualRet,actualSeed));out.write(actualBlend);oracleCounts[name]+=1
 return packet.Packet(actual),{'seed':actualSeed,'blendOut':struct.unpack('<f',actualBlend)[0]}
def objectImage():
 o=packet.Packet(rng.randbytes(SIZE));o.b8(0xe22,rng.randrange(256));o.b8(0xe33,rng.randrange(3));o.s16(0x42,rng.choice([0,1,25,118,151,200]));o.s16(0x40,rng.choice([-1,0,1,25,118,151]));o.s16(0x2c4,rng.choice([1,25,118,151,200]));o.s16(0x2c6,rng.choice([-1,1,25,118,200]))
 for at in[0x2b8,0x2bc,0x2c0]:o.put(at,rng.choice([0,.25,.5,1,8,15])+rng.choice([0,0,.125]))
 return o
def clip():return {'flags':rng.choice([0,2,16,18,0x800,0x810,0x812]),'minimum':rng.choice([0,0,1,2,3,5,250]),'maximum':rng.choice([0,1,2,3,4,8,255]),'endFrame':f32(rng.choice([1,2,31,41,61,121])),'fps':f32(rng.choice([15,24,25,30,37.5,40,48,60])),'blendOut':f32(rng.choice([0,.1,.2,.5,1.]))}
def context():return {'modelPresent':True,'variant':rng.randrange(3),'characterFlags':rng.getrandbits(32),'throwHeld':bool(rng.randrange(4)==0),'durationLookup':bool(rng.randrange(5)!=0)}
def state():return {'seed':rng.randrange(65536),'blendOut':f32(rng.uniform(-1,2))}
try:
 for variant,flags,held,idleHas,altHas,weapon,stateByte in itertools.product([0,1],[0,128],[False,True],[False,True],[False,True],[0,1],[0,1,2]):
  ctx={'modelPresent':True,'variant':variant,'characterFlags':flags,'throwHeld':held,'durationLookup':True};a=idle.alternate(ctx);clips={}
  if idleHas:clips[1]=clip()
  if altHas:clips[a]=clip()
  o=objectImage();o.b8(0xe22,weapon);o.b8(0xe33,stateByte);run(0,o,clips,ctx,state())
 for kind,total in[(1,2400),(2,2400),(3,4800)]:
  for case in range(total):
   ctx=context();ctx['modelPresent']=kind!=3 or case%11!=0;clips={i:clip()for i in set([1,25,118]+rng.sample(range(233),rng.randrange(12)))if rng.randrange(4)};o=objectImage();action=rng.choice([1,25,118,151,200]);dt=f32(rng.choice([0,1/120,1/60,.1,.5]));run(kind,o,clips,ctx,state(),dt,action,rng.choice([-1,0,1,2,3]))
  print('synthetic',kind,dict(counts),dict(errors),flush=True)
 # Exhaust all LCG states in the no-clip random-delay branch. Keep only summary,
 # because full object images here would add over half a gigabyte of duplicate data.
 ctx={'modelPresent':True,'variant':0,'characterFlags':0,'throwHeld':False,'durationLookup':True};o=objectImage()
 for seed in range(65536):run(1,o,{},ctx,{'seed':seed,'blendOut':f32(.2)},action=1,mode=2,group='randomDelayAllSeeds',record=False)
 print('all random seeds',dict(counts),dict(errors),flush=True)
 # Real native-loaded definition tables for every source that has an idle variation.
 cat=json.loads((BASE/'reports/animation-playback-catalog-native.json').read_text());shared=json.loads((BASE/'reports/animation-playback-common-native.json').read_text());common={(r['source'],r['line']):r['clipSource']for r in shared['rows']if r['nativeResult']and r.get('clipSource')};sources=sorted(set(r['source']for r in cat['rows']if r['status']=='loaded'and r['flags']&16));authored=[]
 for source in sources:
  clips={};provenance=[]
  for row in cat['rows']:
   if row['status']!='loaded'or row['source']!=source:continue
   path=row['localClip']['source']if row['localClip']else common.get((source,row['line']))
   if not path or row['actionId']in clips:continue
   raw=(BASE/path).read_bytes();magic=struct.unpack_from('<I',raw)[0];end=sum(struct.unpack_from('<H',raw,x)[0]for x in(10,14))if magic in(0x414e4934,0x414e4935)else struct.unpack_from('<f',raw)[0];definition=bytes.fromhex(row['definitionHex']);c=dict(row['playback']);c.update({'minimum':definition[12],'maximum':definition[13],'flags':row['flags'],'endFrame':end});clips[row['actionId']]=c;provenance.append({'line':row['line'],'action':row['actionId'],'clip':path,'clipSha256':hashlib.sha256(raw).hexdigest(),'definitionSha256':row['definitionSha256']})
  if not clips:continue
  o=objectImage();o.s16(0x2c4,1);o.s16(0x2c6,-1);o.put(0x2b8,0);o.put(0x2bc,0);o.put(0x2c0,.5);ctx={'modelPresent':True,'variant':1,'characterFlags':0,'throwHeld':False,'durationLookup':True};st=state()
  for frame in range(360):
   o.s16(0x40,o.i16(0x42));o.s16(0x42,25 if frame%180>=90 else 1);o,st=run(3,o,clips,ctx,st,f32(1/30),group='authoredUpdate')
  authored.append({'source':source,'frames':360,'clips':provenance})
except Exception as e:failures.append(str(e));print('FAIL',e,flush=True)
out.seek(8);out.write(struct.pack('<I',sum(oracleCounts.values())));out.close()
report={'binarySha256':n.sha256,'entries':{'0x415050':'GetDefaultIdle','0x4150d0':'ResetCharacterIdle','0x4151c0':'NewCharacterIdle','0x415370':'UpdateCharacterIdle'},'counts':dict(counts),'totalComparisons':sum(counts.values()),'mismatches':sum(errors.values()),'mismatchCounts':dict(errors),'failures':failures,'examples':examples,'oracle':{'source':target.relative_to(BASE).as_posix(),'cases':sum(oracleCounts.values()),'counts':dict(oracleCounts),'sha256':hashlib.sha256(target.read_bytes()).hexdigest()},'authored':authored if'authored'in globals()else[],'method':'Original complete native helpers including RNG54fa60 and duration62e040/header5ca470 callees; no substitutions. Compare complete4312-byte object, return value, RNG state and global duration blend-out.','limits':['Finite clip metadata, valid action indices, bounded iteration; invalid pointers/NaNs not claimed.','Duration lookup validity is an explicit adapter state; missing mapping returns0 and preserves prior blend-out global as native does.','Authored table/request schedules are explicit fixtures, not a whole character configuration/load or live behavior equivalence claim.','Compiled C# behavioral verification pending Windows execution restriction.']}
(BASE/'reports/animation-idle-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items()if k not in['examples','authored']},indent=2))
if failures or errors:raise SystemExit(1)
