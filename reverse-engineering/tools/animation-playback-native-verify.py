"""Original PC animation packet/timer verification with unmodified callees."""
import importlib.util,struct,random,json,hashlib,collections
from pathlib import Path
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
native=module('native','native-x86.py');model=module('playback','animation-playback-model.py');n=native.NativeX86();BASE=native.BASE
P=n.DATA;M=P+0x1000;A=P+0x2000;D=P+0x3000;H=P+0x4000;DEF=P+0x5000;OUT=P+0x8000
f32=model.f32;bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
n.pack('<II',M+8,D,A);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT))
rng=random.Random(0x62e9b0);counts=collections.Counter();errors=collections.Counter();examples=[];failures=[]
def upload(clips):
 for i,c in clips.items():
  if c is None:n.pack('<I',A+4*i,0);n.pack('<I',D+4*i,0);continue
  h=H+64*i;d=DEF+64*i;n.pack('<f',h,c['endFrame']);n.pack('<I',A+4*i,h);n.pack('<I',D+4*i,d);n.pack('<I',d+4,c['flags']);n.pack('<fffff',d+0x10,c['blendIn'],c['blendOut'],c['fps'],c['movementReference'],c['rateCap'])
def clip():return {'endFrame':f32(rng.choice([1,2,16,31,61,121])),'flags':rng.choice([0,2,128,130]),'blendIn':f32(rng.choice([0,.03,.1,.2,.5])),'blendOut':f32(rng.choice([0,.03,.1,.2,.5])),'fps':f32(rng.choice([-30,0,15,24,30,48,60])),'movementReference':f32(rng.choice([0,.1,.3,.75,1,2])),'rateCap':f32(rng.choice([-60,-30,0,15,30,60]))}
def compare(group,actual,want,case,details):
 counts[group]+=1
 if actual!=want:
  errors[group]+=1
  if len(examples)<15:examples.append({'group':group,'case':case,'details':details,'differences':[{'offset':hex(i),'actual':a,'expected':b}for i,(a,b)in enumerate(zip(actual,want))if a!=b][:12]})
try:
 for case in range(18000):
  c=clip();upload({0:c});p=model.Packet(rng.randbytes(72));p.b8(0x3e,rng.randrange(2));time=f32(rng.uniform(-10,150));step=f32(rng.choice([0,.1,.5,1,2,10,-.5]));speed=f32(rng.uniform(0,3));backmult=f32(rng.choice([0,.5,1,2]));backwards=rng.randrange(2);events=rng.randrange(2);n.write(P,p.b)
  expected=model.Packet(p.b);expectedTime=model.timer(expected,c,time,step,speed,events,0x3e,backwards,backmult)
  n.call(0x62e760,[P,bits(time),bits(step),bits(speed),events,P+0x3e,backwards,bits(backmult)],regs={native.UC_X86_REG_EAX:0,native.UC_X86_REG_EDI:M});n.mu.emu_start(n.STOP,n.STOP+6)
  actual=n.read(P,72)+n.read(OUT,4);want=bytes(expected.b)+struct.pack('<f',expectedTime)
  compare('timer',actual,want,case,{'clip':c,'time':time,'step':step,'speed':speed,'backmult':backmult,'backwards':backwards,'events':events})
 print('timer',dict(counts),dict(errors),flush=True)
 target=BASE/'reports/animation-playback-cases.bin';out=target.open('wb');out.write(b'APLAY001'+struct.pack('<I',16000))
 for case in range(16000):
  clips={i:clip()if rng.randrange(5)else None for i in range(6)};upload(clips)
  p=model.Packet(rng.randbytes(72))
  for at in [0,4,0x10,0x14]:p.put(at,rng.uniform(-3,140))
  p.put(8,rng.uniform(0,.6));p.put(12,rng.choice([.03,.1,.2,.5,1]));p.b8(0x31,rng.randrange(2))
  for at in [0x32,0x34,0x36,0x38,0x3a,0x42]:p.s16(at,rng.choice([-1,0,1,2,3,4,5]))
  if case%2==0:p.s16(0x42,-1)
  for at in [0x3c,0x3d,0x3e]:p.b8(at,rng.randrange(2))
  step=f32(rng.choice([0,.1,.5,1,2,8,-.5]));speed=f32(rng.uniform(-3,3));blendStep=f32(rng.choice([0,1/120,1/60,.1,.2]));backmult=f32(rng.choice([0,.5,1,2]));blendMode=rng.randrange(3)
  before=bytes(p.b);expected=model.Packet(before);model.update(expected,clips,step,speed,blendStep,backmult,blendMode)
  n.write(P,before);n.pack('<I',0x80fb90,blendMode);n.call(0x62e9b0,[M,P,bits(step),bits(speed),bits(blendStep),bits(backmult)],count=1000000);actual=n.read(P,72)
  compare('packet',actual,expected.b,case,{'clips':clips,'inputs':[step,speed,blendStep,backmult,blendMode],'before':before.hex(),'after':actual.hex(),'expected':bytes(expected.b).hex()})
  out.write(struct.pack('<4fI',step,speed,blendStep,backmult,blendMode))
  for i in range(6):
   c=clips[i];out.write(struct.pack('<II6f',int(c is not None),c['flags']if c else 0,*[c[k]if c else 0 for k in ['endFrame','blendIn','blendOut','fps','movementReference','rateCap']]))
  out.write(before);out.write(actual)
 out.close()
except Exception as e:failures.append(str(e))
report={'binarySha256':n.sha256,'entries':{'timer':'0x62e760 (AX=animation ID,EDI=model; remaining arguments cdecl)','packet':'0x62e9b0'},'counts':dict(counts),'cases':sum(counts.values()),'mismatches':sum(errors.values()),'mismatchCounts':dict(errors),'examples':examples,'failures':failures,'method':'Original native code/callees, no replacements, compared byte-for-byte with independent Python reconstruction. All72 packet bytes preserved/checked; timer returnfloat32 also checked.','limits':['Finite valid clip metadata and synthetic legacy-header endFrame, no live gameplay dispatch or authored schedule claim.','NaNs/invalid pointers, runtime-mutating animation callbacks and extreme iteration counts not covered.','Prepared C# oracle does not imply compiled C# equivalence.']}
if 'target'in globals()and target.exists():report['oracle']={'path':str(target.relative_to(BASE)),'sha256':hashlib.sha256(target.read_bytes()).hexdigest(),'recordBytes':356,'cases':16000}
(BASE/'reports/animation-playback-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items()if k!='examples'},indent=2));print(json.dumps(examples[:3],indent=2))
if failures or errors:raise SystemExit(1)
