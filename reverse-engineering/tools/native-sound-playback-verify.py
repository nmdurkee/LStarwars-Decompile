import importlib.util,json,struct,gzip,hashlib,itertools,random,copy,math,re
from pathlib import Path
s=importlib.util.spec_from_file_location('groups',Path(__file__).with_name('native-sound-groups-verify.py'));g=importlib.util.module_from_spec(s);s.loader.exec_module(g);n=g.n;b=g.b;d=g.d;B=g.B;D=g.D
s=importlib.util.spec_from_file_location('rounding',Path(__file__).with_name('native-distance-rounding-verify.py'));q=importlib.util.module_from_spec(s);s.loader.exec_module(q);v=q.v
from fractions import Fraction as F
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
b.REGIONS=[(0x810300,0xb00),(0x9736e8,64),(0x2920000,0x44000),(0x2972c38,4),(D,0x80000)]
POSITION=D+0x68000;LISTENER=D+0x69000;CONTEXT=D+0x6a000;ALT=D+0x70000;RNG=0x810364
BACKENDS={0x6980c0:8,0x698040:9,0x698260:9,0x698210:9,0x698100:10}
def bits(x):return d.bits(x)
def flt(x):return d.flt(x)
def getf(m,a):return flt(m.get(a))
def putf(m,a,x):m.put(a,bits(x))
def div(a,b):return v.wide(F(a)/F(b))
def product(a,b,c=1.,divisor=1.):
 wide=div(v.mul(v.mul(a,b),c),divisor);value=q.store(wide)
 if value==0 and wide==0:value=flt((bits(a)^bits(b)^bits(c)^bits(divisor))&0x80000000)
 return value
def record(**kw):
 p=dict(bank=7,flags=0,pitch=22050,priority=0,group=-1,volume=16383,pan=0.,pitchRandom=0.,volumeRandom=0.,near=0.,far=0.,buzz=.25,strength=128,sustain=.5,release=.125);p.update(kw);w=[0]*16;w[1]=p['flags']|(p['bank']&32767);w[2]=p['pitch']&0xffffffff;w[3]=p['priority']&255;w[4]=(p['volume']&65535)<<16;w[5]=p['group']&65535
 for off,key in [(0x18,'pan'),(0x1c,'pitchRandom'),(0x20,'volumeRandom'),(0x24,'near'),(0x28,'far'),(0x2c,'buzz'),(0x34,'sustain'),(0x38,'release')]:w[off//4]=bits(p[key])
 w[12]=p['strength'];return w
def options(**kw):
 p=dict(id=0,records=[record(),record(bank=8),record(bank=9)],position=None,listener=[bits(1),bits(2),bits(3)],forward=[0,0,bits(1)],listenerPresent=True,contextPresent=True,contextVolume=bits(.75),fade=bits(.8),master=bits(.9),near=bits(2),far=bits(15),volume=bits(1),scale=bits(1),seed=1,cursor=0,mutation='none',label='synthetic');p.update(copy.deepcopy(kw));return p
def setup(p):
 m=d.setup(d.options([]));m.put(RNG,p['seed']);m.put(0x2972c38,LISTENER if p['listenerPresent'] else 0);m.put(0x2962b8c,CONTEXT if p['contextPresent'] else 0);m.put(CONTEXT+0x1ac,p['contextVolume']);m.put(0x81046c,p['fade']);m.put(0x810468,p['master']);m.put(0x810d9c,p['near']);m.put(0x810d98,p['far'])
 for i,w in enumerate(p['records']):m.write(d.RECORDS+i*64,struct.pack('<16I',*w));m.write(ALT+i*64,struct.pack('<16I',*w))
 for ptr in [LISTENER,0x9736e8]:m.write(ptr+0x30,struct.pack('<3I',*p['listener']));m.write(ptr+0x20,struct.pack('<3I',*p['forward']))
 if p['position'] is not None:m.write(POSITION,struct.pack('<3I',*p['position']))
 g.half(m,g.GROUPS,0);g.half(m,g.GROUPS+2,2);g.half(m,g.GROUPS+4,p['cursor']);g.half(m,g.MEMBERS,1);g.half(m,g.MEMBERS+2,2)
 return m
def listener(m):return m.get(0x2972c38) or 0x9736e8
def next_random(m):state=(m.get(RNG)*0x19660d+0x3c6ef35f)&0xffffffff;m.put(RNG,state);return (state&0x7fffff)/8388608.
def pitch(value,scale):return int(div(v.mul(v.mul(scale,value),3763),44100))
def mutate(m,p):
 if p['mutation']=='none':return
 m.put(0x810d9c,bits(111));m.put(0x810d98,bits(222));m.put(RNG,0xabcdef01)
 if p['position'] is not None:m.put(POSITION+4,bits(99))
 if p['mutation']=='clear-distance':
  for i in range(len(p['records'])):m.put(d.RECORDS+i*64+0x24,0);m.put(d.RECORDS+i*64+0x28,0)
 if p['mutation']=='redirect':m.put(0x2947b74,ALT)
def model(m,p):
 id=p['id'];ev=[]
 if id==-1:return ev
 r=m.get(0x2947b74)+id*64;flags=m.get(r+4)
 if flags&0xc0000:return ev
 priority=struct.unpack('<b',m.read(r+12,1))[0];group=g.short(m,r+0x14)
 if group!=-1:id=g.helper(m,dict(kind='select',group=group,sequential=(flags>>16)&1))
 offset=id*64;r=m.get(0x2947b74)+offset;flags=m.get(r+4);bank=g.signed((flags<<17)&0xffffffff)>>17;rate=pitch(g.signed(m.get(r+8)),1);pan=getf(m,r+0x18);buzz=m.get(r+0x2c);strength=m.get(r+0x30);sustain=m.get(r+0x34);release=m.get(r+0x38);loop=bool(flags&0x8000);oldNear=oldFar=0.
 if getf(m,r+0x24)!=0 or getf(m,r+0x28)!=0:
  oldNear=getf(m,0x810d9c);oldFar=getf(m,0x810d98);putf(m,0x810d9c,product(oldNear,getf(m,r+0x24),.5));putf(m,0x810d98,product(getf(m,r+0x28),oldFar,1,15))
 l=listener(m);audible=True
 if p['position'] is not None:
  x=v.add(getf(m,POSITION),-getf(m,l+0x30));y=v.add(getf(m,POSITION+4),-getf(m,l+0x34));z=v.add(getf(m,POSITION+8),-getf(m,l+0x38));squared=v.add(v.add(v.mul(x,x),v.mul(y,y)),v.mul(z,z));audible=squared<=v.mul(getf(m,0x810d98),getf(m,0x810d98))
 if audible:
  r=m.get(0x2947b74)+offset
  if flt(p['scale'])!=1:rate=pitch(g.signed(m.get(r+8)),flt(p['scale']))
  volume=q.store(v.mul(min(flt(p['volume']),1.),g.short(m,r+0x12)))
  if not m.get(r+4)&0x400000:volume=q.store(v.mul(getf(m,0x81046c),volume));volume=q.store(v.mul(getf(m,m.get(0x2962b8c)+0x1ac) if m.get(0x2962b8c) else 1.,volume))
  gain=int(v.mul(getf(m,0x810468),volume))
  if getf(m,r+0x1c)!=0:
   amount=q.store(v.mul(next_random(m),getf(m,r+0x1c)));state=(m.get(RNG)*0x19660d+0x3c6ef35f)&0xffffffff;m.put(RNG,state);factor=q.store(v.add(1,amount) if state&1 else v.add(1,-v.mul(amount,.5)));rate=int(v.mul(rate,factor))
   if m.get(r+4)&0x8000:rate=-rate
  if getf(m,r+0x20)!=0:factor=q.store(v.add(v.mul(next_random(m),getf(m,r+0x20)),1));gain=int(v.mul(factor,gain))
  if bank&0xffffffff<1600:
   left=right=gain;position=POSITION if p['position'] is not None else 0
   if not position:
    if pan>=0:left=int(v.mul(v.add(1,-pan),gain))
    if pan<=0:right=int(v.mul(v.add(pan,1),gain))
   if not position and loop:
    l=listener(m);position=0x2962b3c
    for i in range(3):
     a=getf(m,l+0x30+i*4);bval=getf(m,l+0x20+i*4);value=q.store(v.add(a,bval))
     if value==0 and a==0 and bval==0:value=flt((bits(a)&bits(bval))&0x80000000)
     putf(m,position+i*4,value)
   if position:target=0x698260 if loop else 0x698210 if priority==0 else 0x698100;args=[position,bank,left,right,rate,buzz,strength,sustain,release]+([priority] if priority!=0 and not loop else [])
   else:target=0x6980c0 if priority==0 else 0x698040;args=[bank,left,right,rate,buzz,strength,sustain,release]+([priority] if priority!=0 else [])
   ev.append(dict(target=target,args=[x&0xffffffff for x in args],position=list(struct.unpack('<3I',m.read(position,12))) if position else None,near=m.get(0x810d9c),far=m.get(0x810d98),seed=m.get(RNG)));mutate(m,p)
 r=m.get(0x2947b74)+offset
 if getf(m,r+0x24)!=0 or getf(m,r+0x28)!=0:putf(m,0x810d9c,oldNear);putf(m,0x810d98,oldFar)
 return ev
current=None;events=[];visited=set()
def observe(mu,a,size,user):
 if 0x650f20<=a<=0x651468:visited.add(a)
 if a not in BACKENDS:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*BACKENDS[a],sp+4));position=args[0] if a in [0x698260,0x698210,0x698100] else 0;events.append(dict(target=a,args=args,position=list(n.unpack('<3I',position)) if position else None,near=n.unpack('<I',0x810d9c)[0],far=n.unpack('<I',0x810d98)[0],seed=n.unpack('<I',RNG)[0]));
 if current['mutation']!='none':m=g.capture();mutate(m,current);g.load(m)
 mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x650f20,end=0x651468)
for a in BACKENDS:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def main():
 global current,events
 rows=[];errors=[];cases=[];rng=random.Random(0x650f20)
 for id,flags in itertools.product([-1,0],[0,0x40000,0x80000,0xc0000]):cases.append(options(id=id,records=[record(flags=flags),record(),record()]))
 positions=[None,[bits(1),bits(2),bits(3)],[bits(16),bits(2),bits(3)],[bits(16)+1,bits(2),bits(3)],[bits(40),0,0]]
 for pos,flags,priority,vol,pan in itertools.product(positions,[0,0x8000,0x400000,0x408000],[-128,0,127],[-.25,0,.5,1,1.5],[-1,0,.5]):cases.append(options(position=pos,records=[record(flags=flags,priority=priority,pan=pan),record(),record()],volume=bits(vol)))
 for seed,scale,loop,mode,group in itertools.product([0,1,2,0xffffffff],[.25,1,1.5],[False,True],['none','restore','clear-distance','redirect'],[-1,0]):
  records=[record(group=group,flags=0x10000,priority=7),record(bank=3,flags=0x8000 if loop else 0,near=2,far=25,pitchRandom=.4,volumeRandom=-.7,pan=-.25),record(bank=4,near=1,far=10,pitchRandom=.3)]
  if group==-1:records[0]=records[1]
  cases.append(options(records=records,scale=bits(scale),seed=seed,mutation=mode,position=None if seed&1 else [0,0,0],cursor=seed&1))
 for value in [0.,-0.,1e-40,-1e-40,.99999994,1.00000012,5.,-5.]:
  for field in ['near','far','pitchRandom','volumeRandom','pan']:cases.append(options(records=[record(**{field:value}),record(),record()]))
 for bank in [-16384,-1,0,1599,1600,16383]:cases.append(options(records=[record(bank=bank),record(),record()]))
 for mode in [False,True]:
  for value in [0.,-0.,.25,1.,2.,-1.]:cases.append(options(listenerPresent=mode,contextPresent=mode,contextVolume=bits(value),master=bits(value),fade=bits(value),records=[record(flags=0x8000),record(),record()]))
 for lineNumber,line in enumerate((B/'extracted/AUDIO/AUDIO.CFG').read_text(encoding='latin1').splitlines(),1):
  line=line.split(';',1)[0].strip()
  if not re.match(r'^Sample\s',line,re.I):continue
  tokens=[a if a is not None and a!='' else c for a,c in re.findall(r'"([^"]*)"|([^\s]+)',line)][1:];p=d.options(tokens,index=3);m,_=d.model(p);words=list(struct.unpack('<16I',m.read(d.RECORDS+3*64,64)));cases.append(options(records=[words,record(),record()],position=None if lineNumber&1 else [bits(1),bits(2),bits(3)],seed=lineNumber,label='authored:'+str(lineNumber)))
 for index,p in enumerate(cases):
  current=p;events=[];m=setup(p);g.load(m);n.pack('<I',0x29a9c48,0);want=model(m,p);n.call(0x650f20,[p['id'],POSITION if p['position'] is not None else 0,p['volume'],p['scale']],count=1000000);actual=g.capture();bad=[]
  if events!=want:bad.append(dict(events=events,wantEvents=want))
  if actual.sha()!=m.sha():
   diff=[]
   for a,data in m.r.items():diff.extend(dict(address=hex(a+i),got=actual.r[a][i],want=value) for i,value in enumerate(data) if actual.r[a][i]!=value)
   bad.append(dict(differences=diff[:15]))
  if bad:errors.append(dict(index=index,input=p,bad=bad))
  rows.append(dict(kind='play',input=p,nativeSha=actual.sha(),events=events))
  if errors:break
 for kind,seed in itertools.product(['random','context','listener'],[0,1,0x80000000,0xffffffff]+[rng.getrandbits(32) for _ in range(128)]):
  p=options(seed=seed,contextPresent=bool(seed&1),listenerPresent=bool(seed&1),contextVolume=bits([-0.,.25,1.,-1.][seed%4]));current=p;events=[];m=setup(p);g.load(m)
  if kind=='listener':want=listener(m);got=n.call(0x696be0)
  else:
   value=next_random(m) if kind=='random' else getf(m,CONTEXT+0x1ac) if p['contextPresent'] else 1.;want=bits(value);m.put(D+0x62000,want);n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',D+0x62000));n.call(0x5b9d90 if kind=='random' else 0x6951c0,[RNG] if kind=='random' else []);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',D+0x62000)[0]
  actual=g.capture()
  if got!=want or actual.sha()!=m.sha():errors.append(dict(kind=kind,seed=seed,got=got,want=want))
  rows.append(dict(kind=kind,input=p,nativeSha=actual.sha(),result=got))
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),playbackCases=sum(r['kind']=='play' for r in rows),authoredRecordCases=sum(r['input']['label'].startswith('authored:') for r in rows),helperCases=sum(r['kind']!='play' for r in rows),backendCalls=sum(len(r.get('events',[])) for r in rows),visitedInstructions=len(visited),bytesComparedPerCase=sum(z for a,z in b.REGIONS),examples=errors[:2],method='Original650f20 with actual group selection, both RNG helpers, listener/context getters, x87 integer conversion mode0 and original vector addition. Only five final audio backend entrypoints are declared mutable services. Exact raw argument packets, call-time distance globals/random state/positions and whole prepared memory SHA256 compare.',limits=['Finite float32 inputs and stored intermediates, x87 integer results within signed32-bit domain; fallback CRT conversion mode0. Malformed pointers/cyclic groups/nonfinite arithmetic and conversion overflow excluded.','Sample fields and priority capture follow native order; group leader priority survives member substitution. Backend may mutate range fields, RNG, position and current record-base pointer; cleanup rereads current near/far.','1130 authored sample records derive from the independently checked sample handler; actual audio resources/device state are not loaded.','All CPU computation runs unchanged; audio backend calls698040/6980c0/698100/698210/698260 remain external. Managed replay pending.'])
 (B/'reports/native-sound-playback-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-playback-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,table=d.TABLEWORDS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
