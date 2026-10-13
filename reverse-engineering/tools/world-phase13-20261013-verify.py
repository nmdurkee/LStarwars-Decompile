import importlib.util,json,struct,hashlib,base64,random,time,math
from pathlib import Path
s=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86();B=nx.BASE
IN=0x291f7a8;REC=0x2913a58;TIME=0x2920a90;RNG=0x8102e8;SEL=0x2920888;PI=0x292096c;PR=0x2920970;ORIGIN=0x291f714
REGIONS=[(REC,128*376),(IN,40*108),(TIME,4),(RNG,4),(SEL,4),(PI,8),(ORIGIN,12)]
U=lambda x:x&0xffffffff
bits=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
def f32(x):
 try:return struct.unpack('<f',struct.pack('<f',x))[0]
 except OverflowError:return math.copysign(math.inf,x)
def patch(a,b):return dict(address=a,data=base64.b64encode(b).decode())
def wp(a,v):return patch(a,struct.pack('<I',U(v)))
def fp(a,v):return wp(a,bits(v))
class Image:
 def __init__(self,c):
  self.regions={a:bytearray(z) for a,z in REGIONS}
  for p in c['writes']:self.write(p['address'],base64.b64decode(p['data']))
 def at(self,a):
  for b,v in self.regions.items():
   if b<=a<b+len(v):return v,a-b
  raise ValueError(hex(a))
 def read(self,a,z):v,i=self.at(a);return bytes(v[i:i+z])
 def write(self,a,data):v,i=self.at(a);v[i:i+len(data)]=data
 def word(self,a,v=None):
  if v is None:return struct.unpack('<I',self.read(a,4))[0]
  self.write(a,struct.pack('<I',U(v)))
 def F(self,a,v=None):
  if v is None:return struct.unpack('<f',self.read(a,4))[0]
  self.word(a,bits(f32(v)))
 def digest(self):return hashlib.sha256(b''.join(self.read(a,z) for a,z in REGIONS)).hexdigest()
def fraction(m):
 v=U(m.word(RNG)*0x19660d+0x3c6ef35f);m.word(RNG,v);return (v&0x7fffff)/8388608.0
def activate(m,index,start):
 if index==-1:return
 at=IN+index*108;id=m.word(at+12)
 if id==0xffffffff:return
 r=REC+id*376;now=m.F(TIME);duration=m.F(r+236);variation=m.F(r+240);interval=m.F(r+244);iv=m.F(r+248)
 if variation==0 and iv==0:
  period=f32(interval+duration);cycle=f32(period*math.trunc(now/period));begin=f32(cycle+start);m.F(at+36,begin);m.F(at+40,begin+duration)
  if begin<now:
   guard=0
   while m.F(at+40)<now:
    if m.F(at+40)<=m.F(at+36):m.F(at+40,duration+m.F(at+36))
    else:m.F(at+36,m.F(at+40)+interval)
    guard+=1;assert guard<20000
    if not m.F(at+36)<now:break
 else:m.F(at+36,now);m.F(at+40,duration+m.F(at+36)+fraction(m)*variation)
 step=f32(1.0/m.F(r+204))
 m.F(at+32,m.F(at+36)-step if m.F(at+40)<now else step*math.trunc(now/step));m.F(at+56,now)
def distance(m,at):
 x,y,z=[f32(m.F(ORIGIN+i*4)-m.F(at+i*4)) for i in range(3)];return f32(y*y+x*x+z*z)
def select(m,threshold):
 selected=m.word(SEL)
 if selected!=0xffffffff and m.word(IN+selected*108+12)!=0xffffffff and distance(m,IN+selected*108)==0:return
 selected=-1;m.word(SEL,-1)
 for i in range(40):
  at=IN+i*108
  if m.word(at+12)==0xffffffff:continue
  d=distance(m,at)
  if threshold<0 or d<threshold:selected=i;m.word(SEL,i);threshold=d
 m.word(PI,0);m.word(PR,0)
 if selected!=-1:
  at=IN+selected*108;m.word(PI,at);id=m.word(at+12)
  if id!=0xffffffff:m.word(PR,REC+id*376)
def seed(kind,index=0):
 c=dict(kind=kind,index=index,writes=[wp(IN+i*108+12,-1) for i in range(40)]+[wp(SEL,-1),wp(PI,0x12345678),wp(PR,0xabcdef01)])
 return c
rng=random.Random(20261013013);cases=[]
for index,id in [(-1,0),(0,-1),(0,0),(1,7),(39,127)]:
 c=seed('activate',index);c['start']=bits(0);c['writes'] += [wp(IN+max(index,0)*108+12,id),fp(TIME,0),fp(REC+max(id,0)*376+204,4),fp(REC+max(id,0)*376+236,2),fp(REC+max(id,0)*376+244,1)];cases.append(c)
for t in [-16,-3,-0.5,-0.0,0,0.5,1,2,2.5,3,3.5,8,32,10000]:
 for dur,gap in [(2,1),(1,0),(0.5,0.25),(4,2),(0.25,1)]:
  for start in [-7,-1,0,0.5,3]:
   c=seed('activate');c['start']=bits(start);c['writes'] += [wp(IN+12,0),fp(TIME,t),fp(REC+204,4),fp(REC+236,dur),fp(REC+244,gap)];cases.append(c)
for j in range(600):
 index=rng.randrange(40);id=rng.randrange(128);r=REC+id*376;c=seed('activate',index);c['start']=bits(rng.randrange(-32,33)/4);c['writes'] += [wp(IN+index*108+12,id),fp(TIME,rng.randrange(-200,201)/4),fp(r+204,rng.choice([0.25,0.5,1,2,3,4,7,8,16,31])),fp(r+236,rng.randrange(-8,33)/4),fp(r+240,rng.choice([-4,-1,0,0.25,0.5,1,3])),fp(r+244,rng.randrange(1,17)/4),fp(r+248,rng.choice([0,1,-2])),wp(RNG,rng.getrandbits(32))]
 # Keep positive periodic duration and nonnegative gap; zero/negative duration can stall the original catch-up loop.
 m=Image(c)
 if m.F(r+240)==0 and m.F(r+248)==0 and m.F(r+236)<=0:c['writes'].append(fp(r+236,4))
 cases.append(c)
for j in range(700):
 c=seed('select');c['threshold']=bits(rng.choice([-1,-0.0,0,0.0625,1,4,100,math.inf,float('nan')]));c['writes'] += [fp(ORIGIN+i*4,rng.randrange(-8,9)/4) for i in range(3)]
 for i in rng.sample(range(40),rng.randrange(0,41)):
  c['writes'].append(wp(IN+i*108+12,rng.randrange(128)))
  c['writes'] += [fp(IN+i*108+k*4,rng.randrange(-16,17)/4) for k in range(3)]
 if j%4==0:c['writes'].append(wp(SEL,rng.randrange(40)))
 cases.append(c)
# Exact origin, stale pointer early-return, strict ties and threshold equality.
for chosen in [-1,0,17,39]:
 for threshold in [-1,0,1]:
  c=seed('select');c['threshold']=bits(threshold);c['writes'] += [wp(IN+12,0),wp(IN+17*108+12,2),wp(IN+39*108+12,3),wp(SEL,chosen)];cases.append(c)
for distanceValue in [0.5,1,2,math.inf,float('nan')]:
 for threshold in [-1,0,1,4,math.inf,float('nan')]:
  c=seed('select');c['threshold']=bits(threshold);c['writes'] += [wp(IN+12,1),fp(IN,distanceValue),wp(IN+108+12,2),fp(IN+108,distanceValue)];cases.append(c)
counts={};from unicorn import UC_HOOK_CODE
def observe(uc,a,z,data):counts[hex(a)]=counts.get(hex(a),0)+1
for a in [0x64ae50,0x644000,0x5b9d90,0x6e6b90,0x5b3800]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
rows=[];fails=[];started=time.time()
for index,c in enumerate(cases):
 m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 if c['kind']=='activate':n.call(0x64ae50,[c['index'],c['start']],count=500000);activate(m,c['index'],struct.unpack('<f',struct.pack('<I',c['start']))[0])
 else:n.call(0x644000,[c['threshold']],count=500000);select(m,struct.unpack('<f',struct.pack('<I',c['threshold']))[0])
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z in REGIONS)).hexdigest()
 if actual!=m.digest():
  fails.append(dict(case=index,kind=c['kind'],diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=m.read(a+j,4).hex()) for a,z in REGIONS for j in range(0,z,4) if n.read(a+j,4)!=m.read(a+j,4)][:20]));print(json.dumps(fails[-1]));break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(fails),entryCalls=counts,seconds=round(time.time()-started,3),failures=fails)
(B/'reports/world-phase13-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fails:(B/'reports/world-phase13-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z) for a,z in REGIONS],cases=rows),separators=(',',':'))+'\n')
print(json.dumps(report));assert not fails
