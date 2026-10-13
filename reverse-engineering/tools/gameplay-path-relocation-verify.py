"""Path relocation, floor snap and control reset; actual view arithmetic."""
import importlib.util,struct,json,copy,itertools,random
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
r=load('reinit','gameplay-reinitialization-verify.py');cm=load('wide','gameplay-path-corner-math-verify.py');view=load('view','native-locator-culling-verify.py');W=cm.W;n=r.x.NativeX86();BASE=r.BASE;D=n.DATA;A=D;REF=D+0x2000;PAD=D+0x4000;POINT=D+0x5000;WORLD=D+0x6000;LEVEL=D+0x6400;S=0x6c4;EPS=n.unpack('<d',0x751788)[0]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
events=[];options={};executed=set();helpers={};assembly=json.loads((BASE/'reports/gameplay-path-relocation-assembly.json').read_text())
def ret(mu,value):
 sp=mu.reg_read(UC_X86_REG_ESP);mu.reg_write(UC_X86_REG_EAX,value&0xffffffff);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x5728a0:events.append(['ground',n.unpack('<I',sp+4)[0]]);n.pack('<f',A+0x21c,r.f(options.get('groundHeight',2e6)));ret(mu,0)
 elif address==0x55e4a0:events.append(['reset',*n.unpack('<II',sp+4)]);ret(mu,0)
 elif address==0x4d1780:events.append(['alternate',*n.unpack('<II',sp+4)]);ret(mu,options.get('alternateReturn',0))
for a in [0x5728a0,0x55e4a0,0x4d1780]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
for fn in assembly['functions']:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:executed.add(p),begin=int(fn['address'],16),end=int(fn['endExclusive'],16)-1)
for a in [0x5d6620,0x55f450,0x54fa60]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:helpers.__setitem__(hex(p),helpers.get(hex(p),0)+1),begin=a,end=a)
def setup(o):
 global events,options
 events=[];options=o;n.write(D,bytes(0x7000));actor=r.pattern(0x10d8,1);reference=r.pattern(0x10d8,1);pad=bytearray((i*13+5)&255 for i in range(96));r.put(actor,0x398,A if o.get('aliasReference') else REF);r.put(actor,0xca4,PAD);r.put(actor,0x1f8,o.get('flags',0));r.put(actor,0x42e,o.get('pathFlags',1),1);r.put(actor,0x288,o.get('byte288',0),1);r.put(actor,0x7c5,o.get('byte7c5',0),1);r.put(actor,0xcd0,o.get('companion',0));r.put(actor,S+0x75e,o.get('controlFlags',0),1)
 for off,value in [(0xf10,o.get('delay',0)),(0x1e0,o.get('radius',1)),(0x21c,o.get('floor',3)),(0x17c,o.get('alternateHeight',4)),(0xff0,o.get('bottom',-.5)),(0xa8,o.get('scale',1)),(0x60,o.get('y',5))]:r.put(actor,off,r.bits(r.f(value)))
 r.put(pad,0x5a,o.get('padFlags',0xffff),2);n.write(A,actor);n.write(REF,reference);n.write(PAD,pad);n.pack('<3f',POINT+4,*[r.f(v) for v in o.get('point',[0,0,20])]);n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,LEVEL);n.pack('<I',LEVEL+0x64,o.get('worldFlags',0));n.pack('<I',0x80253c,o.get('random',12345));n.pack('<f',0x876ce4,r.f(o.get('gate',1)));n.pack('<3I',0x93d620,0x12345678,0xabcdef01,0xdeadbeef);n.pack('<3f',0x93b0cc,*[r.f(v) for v in o.get('velocity',[0,0,0])]);n.pack('<16f',0x80b708,*[r.f(v) for v in o.get('view',view.I)]);n.pack('<16f',0x80b988,*[r.f(v) for v in o.get('planes',view.PLANES)]);n.pack('<2f',0x973730,r.f(o.get('near',1)),r.f(o.get('far',10)));return dict(actor=actor,reference=reference,pad=pad,origin=[0x12345678,0xabcdef01,0xdeadbeef],random=o.get('random',12345))
def reset(z):
 a=z['actor'];p=z['pad'];r.put(a,S+0xfc,0);r.put(a,S+0x100,255,1);r.put(a,S+0x678,r.bits(1. if a[S+0x75e]&1 else 0.));r.put(a,S+0x67c,r.bits(5.));r.put(a,S+0xf1,255,1)
 for off in [0x76f,0xf5,0xf4,0xee,0x76e]:r.put(a,S+off,0,1)
 for off in [0x66c,0x674,0x664,0x65c,0x648,0x694,0x698,0x670,0x6d0,0x6e8,0x700,0x714,0x720,0x724,0x60c]:r.put(a,S+off,0)
 r.put(p,0x5a,r.h(p,0x5a)&0xffeb,2);r.put(a,S+0x75c,r.u(a,S+0x75c)&~0x400);z['random']=(z['random']*0x24cd+1)&65535;r.put(a,S+0x77d,z['random']>>15,1);r.put(a,S+0xe8,0,2)
 for off in [0x74c,0x750,0x752]:r.put(a,S+off,65535,2)
def floor(z,o,mode):
 a=z['actor'];f=lambda off:r.fl(r.u(a,off));height=f(0x21c)
 if height==2e6 or o.get('worldFlags',0)&0x40000:return 0
 def setheight(h):
  value=(W(h)-W(f(0xff0))*W(f(0xa8))+W(EPS)).store()
  for off in [0x60,0x9c,0x84]:r.put(a,off,r.bits(value))
 if mode==2:setheight(f(0x17c))
 accepted=mode==0 or (W(height)+W(EPS)-(W(f(0xff0))*W(f(0xa8))+W(f(0x60)))).exact[0]>=0
 if accepted:setheight(height)
 r.put(a,0x6c,0xbf800000);return int(accepted)
def model(before,o,kind):
 z=copy.deepcopy(before);a=z['actor'];ev=[]
 if kind=='reset':reset(z);return z,ev,None
 if kind=='floor':return z,ev,floor(z,o,o.get('mode',0))
 if r.u(a,0x1f8)&0x400 or not a[0x42e]&1 or not (r.fl(r.u(a,0xf10))>=1 or (a[0x288]==0 and not a[0x7c5]&2 and r.f(o.get('gate',1))>0)):return z,ev,0
 point=[r.f(v) for v in o.get('point',[0,0,20])];radius=r.fl(r.u(a,0x1e0));center=[point[0],(W(radius)+W(point[1])).store(),point[2]];v=dict(point=center,radius=radius,object=view.I,view=[r.f(x) for x in o.get('view',view.I)],planes=[r.f(x) for x in o.get('planes',view.PLANES)],near=r.f(o.get('near',1)),far=r.f(o.get('far',10)))
 if not view.outside(v):return z,ev,0
 if o.get('mode',0)!=0:
  ev.append(['alternate',A,POINT+4]);result=int(o.get('alternateReturn',0)!=0)
  if result:
   r.put(a,0x1090,0)
   for off in [0x1086,0x1087,0x401]:r.put(a,off,0,1)
  return z,ev,result
 reference=a if o.get('aliasReference') else z['reference']
 for i,value in enumerate(point):r.put(reference,0x5c+i*4,r.bits(value))
 for off in [0x98,0x80]:a[off:off+12]=reference[0x5c:0x68]
 z['origin']=[r.u(a,0x80+i*4) for i in range(3)];a[0x8c:0x98]=a[0x80:0x8c]
 for i,value in enumerate(o.get('velocity',[0,0,0])):r.put(a,0x68+i*4,r.bits(r.f(value)))
 ev.append(['ground',A]);r.put(a,0x21c,r.bits(r.f(o.get('groundHeight',2e6))));floor(z,o,0);r.put(a,0x1090,0)
 for off in [0x1086,0x1087,0x401]:r.put(a,off,0,1)
 if not r.u(a,0xcd0):ev.append(['reset',A,0]);reset(z)
 return z,ev,1
cases=[];errors=[];counts={}
def run(kind,o):
 before=setup(o);expected,ev,result=model(before,o,kind)
 if kind=='floor':value=n.call(0x572660,[A,o.get('mode',0)])
 elif kind=='reset':n.call(0x55e4e0,[A+S]);value=None
 else:value=n.call(0x43c9a0,[A,POINT,o.get('mode',0)])
 after=dict(actor=n.read(A,0x10d8),reference=n.read(REF,0x10d8),pad=n.read(PAD,96),origin=list(n.unpack('<3I',0x93d620)),random=n.unpack('<I',0x80253c)[0]);summary=lambda z,events,result:dict(result=result,actor=r.changes(before['actor'],z['actor']),reference=r.changes(before['reference'],z['reference']),pad=r.changes(before['pad'],z['pad']),origin=z['origin'],random=z['random'],events=events);got=summary(after,events,value);want=summary(expected,ev,result);counts[kind]=counts.get(kind,0)+1;cases.append(dict(kind=kind,options=o,native=got))
 if got!=want:errors.append(dict(kind=kind,options=o,got=got,want=want))
def main():
 for mode,height,flags,bottom,scale in itertools.product([0,1,2,3,0xffffffff],[2e6,0,3,5],[0,0x40000],[-.5,0,1],[.5,1,2]):run('floor',dict(mode=mode,floor=height,worldFlags=flags,bottom=bottom,scale=scale))
 for seed,flags,padFlags in itertools.product([0,1,12345,32767,65535,0xffffffff],[0,1,2,255],[0,0x14,0xffff]):run('reset',dict(random=seed,controlFlags=flags,padFlags=padFlags))
 for flags,path,delay,gate,b288,b7c5 in itertools.product([0,0x400],[0,1],[0,1,2],[-1,0,1],[0,1],[0,2]):run('relocate',dict(flags=flags,pathFlags=path,delay=delay,gate=gate,byte288=b288,byte7c5=b7c5))
 for point,mode,alternate,companion,alias,ground in itertools.product([[0,0,2],[0,0,20],[20,0,2]],[0,1,0xffffffff],[0,1,0xffffffff],[0,1],[False,True],[2e6,3]):run('relocate',dict(point=point,mode=mode,alternateReturn=alternate,companion=companion,aliasReference=alias,groundHeight=ground,velocity=[1.25,-.5,2.75]))
 rng=random.Random(0x43c9a0)
 for i in range(1024):run('floor',dict(mode=rng.choice([0,1,2,3]),floor=r.f(rng.uniform(-100,100)),bottom=r.f(rng.uniform(-3,3)),scale=r.f(rng.uniform(.01,10)),y=r.f(rng.uniform(-100,100)),alternateHeight=r.f(rng.uniform(-100,100))))
 for fn in assembly['functions']:
  for row in fn['instructions']:row['executed']=int(row['address'],16) in executed
 report=dict(binarySha256=n.sha256,checks=len(cases),counts=counts,mismatches=len(errors),examples=errors[:3],actualHelpers=helpers,instructionCoverage={fn['address']:dict(total=len(fn['instructions']),executed=sum(row['executed'] for row in fn['instructions']),missing=[row['address'] for row in fn['instructions'] if not row['executed']]) for fn in assembly['functions']},epsilonDouble=EPS,services=['5728a0 ground refresh','55e4a0 broader actor reset','4d1780 alternate relocation']);(BASE/'reports/gameplay-path-relocation-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-relocation-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-relocation-assembly.json').write_text(json.dumps(assembly,indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
