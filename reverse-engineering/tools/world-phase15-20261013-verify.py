import importlib.util,json,struct,hashlib,base64,random,time
from pathlib import Path
s=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86();B=nx.BASE;D=n.DATA;Q=D+0x800;PT=D+0x1000;PR=D+0x2000;SN=D+0x10000;ST=D+0x20000;FLAGS=0x2924b10
REGIONS=[(D,0x40000),(0x2962098,8),(FLAGS-512,1024),(0x2947b74,4)]
U=lambda x:x&0xffffffff
S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0]
def patch(a,b):return dict(address=a,data=base64.b64encode(b).decode())
def wp(a,v):return patch(a,struct.pack('<I',U(v)))
def string(v):return v.split(b'\0',1)[0]+b'\0'
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
 def byte(self,a):return self.read(a,1)[0]
 def digest(self):return hashlib.sha256(b''.join(self.read(a,z) for a,z in REGIONS)).hexdigest()
def fold(v):
 if U(v+159)&255<26 or v>223:v=(v-32)&255
 return v if v<128 else v-256
def equal(m,r,q):
 i=0
 while True:
  a=fold(m.byte(r+i));b=fold(q[i])
  if a!=b:return False
  if a==0 or b==0:return True
  i+=1
def active(m,g):return m.word(U(FLAGS+g*4))!=0
def particle(m,q,p,fast,excluded):
 if q is None:return 0xffffffff
 wanted=p&255
 for phase in range(2 if fast else 3):
  if phase==0 and (wanted>=8 or not active(m,wanted)):continue
  for i in range(1,max(1,S(m.word(0x2962098)))):
   if not fast and i==excluded:continue
   r=m.word(m.word(0x296209c)+i*4)
   if not r:continue
   g=m.byte(r+17);eligible=g==wanted if phase==0 else g in [0,1] and active(m,g) if phase==1 else active(m,g if g<128 else g-256)
   if eligible and equal(m,r,q):return i
 return 0xffffffff
def compare(m,q,r,length):
 if q is None:return -1
 if not r:return 1
 if length==0:return 0
 count=length
 if length==-1:count=q.index(0)
 elif length==-2:
  count=0
  while m.byte(r+count):count+=1
 i=0
 while True:
  a=fold(q[i]);b=fold(m.byte(r+i))
  if a>b:return 1
  if a<b:return -1
  i+=1;count-=1
  if not a or not b or count==0:return 0
def sound(m,q,length):
 for i in range(1600):
  if compare(m,q,m.word(m.word(0x2947b74)+i*64),length)==0:return i
 return 0xffffffff
def seed(kind,q=b'Name',preferred=0,fast=False,excluded=0,length=16):return dict(kind=kind,query=None if q is None else base64.b64encode(string(q)).decode(),preferred=U(preferred),fast=fast,excluded=excluded,length=length,writes=[wp(0x296209c,PT),wp(0x2947b74,ST),patch(Q,string(q or b''))])
def entry(c,index,name,group):c['writes'] += [wp(PT+index*4,PR+index*64),patch(PR+index*64,string(name)),patch(PR+index*64+17,bytes([group&255]))]
def audio(c,index,name):c['writes'] += [wp(ST+index*64,SN+index*32),patch(SN+index*32,string(name))]
rng=random.Random(20261013015);cases=[]
for fast in [False,True]:
 for preferred in [0,1,2,7,8,255,256,0xffffffff]:
  for group in [0,1,2,7,8,127,128,255]:
   c=seed('particle',preferred=preferred,fast=fast);c['writes'] += [wp(0x2962098,4),wp(U(FLAGS+(group if group<128 else group-256)*4),1)];entry(c,1,b'name',group);entry(c,2,b'other',0);cases.append(c)
for j in range(500):
 c=seed('particle',q=rng.choice([None,b'',b'Name',b'NAME',b'Other',b'\xe1Raw',b'\xc1rAW']),preferred=rng.choice([0,1,2,7,8,255,0xffffffff]),fast=bool(j%2),excluded=rng.randrange(-1,20));size=rng.randrange(0,20);c['writes'].append(wp(0x2962098,size))
 for i in range(8):c['writes'].append(wp(FLAGS+i*4,rng.randrange(2)))
 for i in range(size):
  if rng.randrange(5):entry(c,i,rng.choice([b'',b'Name',b'Other',b'NO_MATCH',b'\xe1Raw',b'\xc1rAW']),rng.randrange(8))
 cases.append(c)
for count in [-1,0,1]:
 c=seed('particle');c['writes'] += [wp(0x2962098,count),wp(FLAGS,1)];entry(c,0,b'Name',0);cases.append(c)
for at in [0,1,7,99,1598,1599]:
 for length in [0,1,4,16,-1,-2,-3]:
  for q in [None,b'',b'Name',b'name',b'NameTail']:
   c=seed('sound',q=q,length=length);audio(c,at,b'Name');cases.append(c)
for q,name in [(b'\xe1Raw',b'\xc1rAW'),(b'PrefixQ',b'PrefixR'),(b'ABCDEFGHIJKLMNOP',b'abcdefghijklmnop'),(b'',b''),(b'Name',b'Other')]:
 for length in [0,1,6,16,-1,-2,-3]:
  c=seed('sound',q=q,length=length);audio(c,3,name);audio(c,7,q);cases.append(c)
for j in range(100):
 c=seed('sound',q=rng.choice([None,b'',b'Name',b'NAME',b'missing',b'Other']),length=rng.choice([0,1,4,16,-1,-2,-3]))
 for at in rng.sample(range(1600),rng.randrange(0,8)):audio(c,at,rng.choice([b'',b'Name',b'Other',b'name']))
 cases.append(c)
counts={};from unicorn import UC_HOOK_CODE
def observe(uc,a,z,data):counts[hex(a)]=counts.get(hex(a),0)+1
for a in [0x658330,0x658490,0x650e40,0x4f8b10,0x4f8b80,0x64fdb0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
rows=[];fails=[];start=time.time()
for index,c in enumerate(cases):
 m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 q=None if c['query'] is None else base64.b64decode(c['query']);address=Q if q is not None else 0
 if c['kind']=='particle':actual=n.call(0x658490 if c['fast'] else 0x658330,[address,c['preferred']]+([] if c['fast'] else [c['excluded']]),count=3000000);prediction=particle(m,q,c['preferred'],c['fast'],c['excluded'])
 else:actual=n.call(0x650e40,[address,c['length']],count=3000000);prediction=sound(m,q,c['length'])
 observed=dict(result=actual,sha256=hashlib.sha256(b''.join(n.read(a,z) for a,z in REGIONS)).hexdigest())
 if actual!=prediction or observed['sha256']!=m.digest():fails.append(dict(case=index,kind=c['kind'],observed=observed,prediction=prediction));print(json.dumps(fails[-1]));break
 c['expected']=observed;rows.append(c)
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(fails),entryCalls=counts,seconds=round(time.time()-start,3),failures=fails)
(B/'reports/world-phase15-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fails:(B/'reports/world-phase15-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=0) for a,z in REGIONS],cases=rows),separators=(',',':'))+'\n')
print(json.dumps(report));assert not fails
