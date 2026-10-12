"""Original PC control helpers and bounded full AnimatePlayer, with compact gzip oracle."""
import importlib.util,struct,random,json,hashlib,collections,io,gzip
from pathlib import Path
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
native=module('native','native-x86.py');model=module('control','animation-control-model.py');n=native.NativeX86();BASE=native.BASE
P=n.DATA;Q=P+0x200;O=P+0x1000;M=P+0x3000;A=P+0x4000;D=P+0x5000;H=P+0x6000;DEF=P+0x12000;C=P+0x18000;G=P+0x19000;PAD=P+0x1a000
n.pack('<II',M+8,D,A);n.pack('<I',C+0x24,G)
rng=random.Random(0x62f0a0);f32=model.f32;bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
counts=collections.Counter();errors=collections.Counter();examples=[];failures=[];records=io.BytesIO();recordCount=0
def upload(clips):
 n.write(A,bytes(233*4));n.write(D,bytes(233*4))
 for i,c in clips.items():
  if c is None:continue
  h=H+64*i;d=DEF+80*i;n.pack('<I',A+4*i,h);n.pack('<I',D+4*i,d);n.pack('<f',h,c['endFrame']);n.pack('<I',d+4,c['flags']);n.pack('<fffff',d+0x10,c['blendIn'],c['blendOut'],c['fps'],c['movementReference'],c['rateCap'])
def clip():return {'endFrame':f32(rng.choice([1,2,16,31,61,121])),'flags':rng.choice([0,2,128,130]),'blendIn':f32(rng.choice([0,.03,.1,.2,.5])),'blendOut':f32(rng.choice([0,.03,.1,.2,.5])),'fps':f32(rng.choice([-30,0,15,24,30,48,60])),'movementReference':f32(rng.choice([0,.1,.3,.75,1,2])),'rateCap':f32(rng.choice([-60,-30,0,15,30,60]))}
def table():return {i:clip()if rng.randrange(5)else None for i in range(6)}
def clipBytes(clips):
 present=[(i,c)for i,c in clips.items()if c is not None];b=struct.pack('<I',len(present))
 for i,c in present:b+=struct.pack('<iI6f',i,c['flags'],*[c[k]for k in['endFrame','blendIn','blendOut','fps','movementReference','rateCap']])
 return b
def compare(group,actual,expected,kind,args,before,result=0,wantResult=0,record=True):
 global recordCount
 counts[group]+=1
 if actual!=expected or result!=wantResult:
  errors[group]+=1
  if len(examples)<16:examples.append({'group':group,'case':counts[group]-1,'before':before.hex(),'args':args.hex(),'actual':actual.hex(),'expected':bytes(expected).hex(),'result':result,'expectedResult':wantResult,'differences':[hex(i)for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:20]})
 if record:
  records.write(struct.pack('<II',kind,len(args)));records.write(args);records.write(struct.pack('<II',len(before),len(actual)));records.write(before);records.write(actual);records.write(struct.pack('<i',result));recordCount+=1
def packet(length=72):
 p=model.Packet(rng.randbytes(72))
 for at in[0,4,16,20]:p.put(at,rng.uniform(-3,140))
 p.put(8,rng.uniform(0,.6));p.put(12,rng.choice([.03,.1,.2,.5,1]));p.b8(49,rng.randrange(2))
 for at in[50,52,54,56,58]:p.s16(at,rng.choice([-1,0,1,2,3,4,5]))
 p.s16(66,-1)
 for at in[60,61,62]:p.b8(at,rng.randrange(2))
 if length==36:
  mini=model.Packet(bytes(36));model.full_to_mini(p,mini);return mini
 return p
try:
 for kind,address in[(0,0x62efb0),(1,0x62f030)]:
  for case in range(1200):
   mini=model.Packet(rng.randbytes(36));full=model.Packet(rng.randbytes(72));before=bytes(mini.b+full.b);n.write(P,mini.b);n.write(Q,full.b)
   if kind==0:model.mini_to_full(mini,full);n.call(address,[P,Q])
   else:model.full_to_mini(full,mini);n.call(address,[Q,P])
   compare(['miniToFull','fullToMini'][kind],n.read(P,36)+n.read(Q,72),mini.b+full.b,kind,b'',before)
 print('conversions',dict(counts),dict(errors),flush=True)
 for case in range(12000):
  clips=table();upload(clips);p=packet(36);before=bytes(p.b);expected=model.Packet(before)
  step=f32(rng.choice([0,.1,.5,1,2,8,-.5]));speed=f32(rng.uniform(-3,3));blend=f32(rng.choice([0,1/120,1/60,.1,.2]));mode=rng.randrange(3)
  model.update_mini(expected,clips,step,speed,blend,mode);n.write(P,before);n.pack('<I',0x80fb90,mode)
  # Vary the otherwise-uninitialized temporary packet tail. Only fields written
  # by conversion may affect the compact result; original callee stays intact.
  n.write(n.STACK+0xd000,rng.randbytes(0x1000));n.call(0x62f0a0,[M,P,bits(step),bits(speed),bits(blend)],count=1000000)
  compare('updateMini',n.read(P,36),expected.b,2,struct.pack('<3fI',step,speed,blend,mode)+clipBytes(clips),before)
 print('mini',dict(counts),dict(errors),flush=True)
 for case in range(8000):
  p=packet();p.b8(49,rng.choice([0,1,2,255]));source=rng.choice([-1,0,1,2,3,4,5]);target=rng.choice([-1,0,1,2,3,4,5]);present=bool(rng.randrange(2));available=[bool(rng.randrange(2))for _ in range(6)]
  if case%3==0:p.s16(50,source);p.s16(52,target)
  for i,v in enumerate(available):n.pack('<I',A+4*i,H if v else 0)
  before=bytes(p.b);n.write(P,before);result=n.call(0x62f100,[M if present else 0,P,source,target]);want=int(model.blending(p,source,target,present,available))
  args=struct.pack('<iiII',source,target,present,sum(1<<i for i,v in enumerate(available)if v));compare('blendPredicate',n.read(P,72),before,3,args,before,result,want)
 for case in range(5000):
  p=model.Packet(rng.randbytes(72));p.b8(49,rng.choice([0,1,2,255]));before=bytes(p.b);n.write(P,before);result=n.call(0x62f1a0,[P]);result=struct.unpack('<i',struct.pack('<I',result))[0]
  compare('currentAction',n.read(P,72),before,4,b'',before,result,model.current(p))
 print('queries',dict(counts),dict(errors),flush=True)
 # Bounded full AnimatePlayer: callback-suppression bit set; ordinary character,
 # no speed-special case, no context45 multiplier, action95 absent, effect flags
 # 0x100/0x400/0x800 absent. Original weapon/footstep helpers execute no-op paths.
 n.pack('<h',0x7f1a50,-1)
 for case in range(6000):
  clips={i:clip()for i in range(6)}
  if case%2:clips[1]=None
  upload(clips);o=model.Packet(bytes(0x10d8));o.b[8:80]=packet().b
  # The real wrapper's weapon consumer dereferences active definitions even
  # when dt=0. Keep incoming source/target/current IDs bound to definitions.
  if clips[1]is None:
   for at in[0x3a,0x3c,0x3e]:
    if o.i16(at)==1:o.s16(at,0)
  def u32(at,v):struct.pack_into('<I',o.b,at,v)
  u32(0x50,M if case%13 else 0);u32(0x54,C);u32(0xca4,PAD);u32(0x1f8,0x40000);u32(0xef0,0x4000 if rng.randrange(2)else 0);o.b8(0x7b5,rng.choice([0,28,255]));o.b8(0x28b,rng.choice([0,0,0,1,2]));o.put(0x100c,rng.choice([0.,1.]));o.s16(0x3ee,rng.choice([-1,233,0,1,3]));o.s16(0x3f0,rng.choice([-1,0,1,2,3,4,5]));o.s16(0x1064,0);o.s16(0x7ee,rng.randrange(-32768,32768));o.s16(0x7f0,rng.randrange(-32768,32768))
  for at in[0x68,0x70,0xf30,0xf38]:o.put(at,rng.uniform(-2,2))
  # Nonzero sentinels outside the known write set test preservation too.
  for at in[0x123,0x666,0x9aa,0x10ab]:o.b[at:at+12]=rng.randbytes(12)
  ctx={'seconds':f32(rng.choice([0,1/120,1/60,1/30,.1])),'inputMagnitude':f32(rng.uniform(-2,3)),'movementSpeed':f32(rng.uniform(-2,3)),'backwardsMultiplier':f32(rng.choice([0,.5,1,2])),'gameFlags':rng.choice([0,0x100000]),'blendMode':rng.randrange(3)}
  n.pack('<f',0x925018,ctx['seconds']);n.pack('<I',0x80fb90,ctx['blendMode']);n.pack('<I',G+0x90,ctx['gameFlags']);n.pack('<f',G+0x20,ctx['backwardsMultiplier']);n.pack('<f',PAD+0x28,ctx['inputMagnitude']);n.pack('<f',PAD+0x34,ctx['movementSpeed']);before=bytes(o.b);expected=model.Packet(before);model.player(expected,clips,ctx);n.write(O,before);n.call(0x418ca0,[O],count=1000000)
  args=struct.pack('<4fII',ctx['seconds'],ctx['inputMagnitude'],ctx['movementSpeed'],ctx['backwardsMultiplier'],ctx['gameFlags'],ctx['blendMode'])+clipBytes(clips);compare('playerNoEvents',n.read(O,0x10d8),expected.b,5,args,before)
 print('player',dict(counts),dict(errors),flush=True)
 # Actual native-loaded Qui-Gon definitions, resolved shipped local/common AN3.
 catalog=json.loads((BASE/'reports/animation-playback-catalog-native.json').read_text());common=json.loads((BASE/'reports/animation-playback-common-native.json').read_text());shared={(r['source'],r['line']):r['clipSource']for r in common['rows']if r['nativeResult']and r.get('clipSource')};authored=[]
 sources=sorted(set(r['source']for r in catalog['rows']if r['status']=='loaded'and any(k in r['source'].upper()for k in['QUIGON','YODA/YODA.TXT','R2D2/R2D2.TXT'])))
 for source in sources:
  clips={};provenance=[]
  for row in catalog['rows']:
   if row['status']!='loaded'or row['source']!=source or row['actionId']in clips:continue
   path=row['localClip']['source']if row['localClip']else shared.get((source,row['line']))
   if not path:continue
   raw=(BASE/path).read_bytes();magic=struct.unpack_from('<I',raw)[0]
   if magic not in(0x414e4934,0x414e4935):continue
   end=sum(struct.unpack_from('<H',raw,x)[0]for x in(10,14));c=dict(row['playback']);c['flags']=row['flags'];c['endFrame']=end;clips[row['actionId']]=c;provenance.append({'action':row['actionId'],'line':row['line'],'clip':path,'clipSha256':hashlib.sha256(raw).hexdigest(),'definitionSha256':row['definitionSha256']})
  if not clips:continue
  upload(clips);p=model.Packet(bytes(36));p.s16(30,-1);p.s16(32,-1);p.s16(34,-1);p.put(0,1);actions=sorted(clips)
  for frame in range(480):
   p.s16(32,p.i16(30));p.s16(34,actions[(frame//24)%len(actions)]);step=f32(1.);speed=f32(-.5 if frame%120>=60 else .5);blend=f32(1/30);mode=(frame//160)%3;before=bytes(p.b);expected=model.Packet(before);model.update_mini(expected,clips,step,speed,blend,mode);n.write(P,before);n.pack('<I',0x80fb90,mode);n.call(0x62f0a0,[M,P,bits(step),bits(speed),bits(blend)],count=1000000);actual=n.read(P,36);compare('authoredMini',actual,expected.b,2,struct.pack('<3fI',step,speed,blend,mode)+clipBytes(clips),before);p=model.Packet(actual)
  authored.append({'source':source,'frames':480,'clips':provenance})
except Exception as e:failures.append(str(e));print('FAIL',e,flush=True)
target=BASE/'reports/animation-control-cases.bin.gz';raw=b'ACTRL001'+struct.pack('<I',recordCount)+records.getvalue();target.write_bytes(gzip.compress(raw,compresslevel=9,mtime=0))
report={'binarySha256':n.sha256,'entrypoints':{'0x62efb0':'MiniToFull','0x62f030':'FullToMini','0x62f0a0':'UpdateMiniAnimPacket','0x62f100':'IsBlendingFromTo','0x62f1a0':'CurrentAction','0x418ca0':'AnimatePlayer callback-suppressed, no speed-special/force-rate/wake/weapon/footstep side effects branch'},'counts':dict(counts),'totalComparisons':sum(counts.values()),'mismatches':sum(errors.values()),'mismatchCounts':dict(errors),'examples':examples,'failures':failures,'authored':authored if'authored'in globals()else[],'oracle':{'path':target.relative_to(BASE).as_posix(),'cases':recordCount,'compressedBytes':target.stat().st_size,'uncompressedBytes':len(raw),'sha256':hashlib.sha256(target.read_bytes()).hexdigest()},'method':'Original native helpers and all invoked callees; no callbacks replaced, no instruction patches or native API hooks. Byte-exact output comparisons against independent Python model. Main player tests compare all4312 object bytes with unknown-field sentinels. Compact gzip oracle preserves before/after and arguments.','limits':['Resolved finite valid model/clip data; invalid native pointers/NaNs and unbounded frame iteration are excluded.','Main player branch has API flag0x40000, no context45 multiplier, non-special character ID, no active action95 randomization, no clip flags0x100/0x400/0x800. Original effect helpers execute their inactive branches.','Authored compact-packet schedule is a fixture, not live gameplay scheduling.','Managed source differential execution pending Windows restriction; compilation is not equivalence.']}
(BASE/'reports/animation-control-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items()if k not in['examples','authored']},indent=2))
if failures or errors:raise SystemExit(1)
