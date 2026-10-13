import importlib.util,json,struct,hashlib,base64,random,time
from pathlib import Path
s=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86();B=nx.BASE;D=n.DATA;SC=D+0x1000;BACK=D+0x1800;OLD=D+0x3000;NEW=D+0x6000;NAMES=D+0x12000;QUERY=D+0x800;HANDLE=D+0x900;REGIONS=[(D,0x20000)]
U=lambda x:x&0xffffffff
S=lambda x:struct.unpack('<i',struct.pack('<I',U(x)))[0]
def patch(a,b):return dict(address=a,data=base64.b64encode(b).decode())
def wp(a,v):return patch(a,struct.pack('<I',U(v)))
def fixed(s):return s[:16].ljust(16,b'\0')
class Image:
 def __init__(self,c):self.data=bytearray(0x20000);self.regions={D:self.data};[self.write(p['address'],base64.b64decode(p['data'])) for p in c['writes']]
 def read(self,a,z):return bytes(self.data[a-D:a-D+z])
 def write(self,a,b):self.data[a-D:a-D+len(b)]=b
 def word(self,a,v=None):
  if v is None:return struct.unpack('<I',self.read(a,4))[0]
  self.write(a,struct.pack('<I',U(v)))
 def byte(self,a):return self.read(a,1)[0]
 def digest(self):return hashlib.sha256(self.data).hexdigest()
def count(m,scene):
 back=m.word(scene+0x110);return m.word(back+0x6c) if back else m.word(scene+0x24)
def build(m,dst,scene,index):
 if scene and dst:
  back=m.word(scene+0x110)
  if back and index<S(m.word(back+0x6c)):
   m.word(dst+4,0);m.word(dst,scene);back=m.word(scene+0x110);m.word(dst+8,U(index*208+m.word(back+0x70)));return
  if index<S(m.word(scene+0x24)):
   m.word(dst,scene);ptr=U(index*76+m.word(scene+0x28));m.word(dst+8,0);m.word(dst+4,ptr);return
 m.word(dst,0);m.word(dst+4,0);m.word(dst+8,0)
def valid(m,h):return int(bool(h and (m.word(h+4) or m.word(h+8))))
def name(m,h):
 if not h:return 0
 p=m.word(h+8)
 if p:return m.word(p+180)
 p=m.word(h+4);return m.word(p+68) if p else 0
def eq(a,b):
 for x,y in zip(a,b):
  if x!=y:return False
  if x==0:return True
 return True
def find(m,q,scene):return find_bytes(m,m.read(q,16),scene)
def find_bytes(m,a,scene):
 if not a[0]:return -1
 if eq(a,n.read(0x8101c4,16)):return 9999
 if not scene:return -1
 total=S(count(m,scene))
 for i in range(max(0,total)):
  back=m.word(scene+0x110);old=new=0
  if back and i<S(m.word(back+0x6c)):new=U(i*208+m.word(back+0x70))
  elif i<S(m.word(scene+0x24)):old=U(i*76+m.word(scene+0x28))
  if not(old or new):continue
  ptr=m.word(new+180) if new else m.word(old+68)
  if eq(a,m.read(ptr,16)):return i
 return -1
def seed(kind,oldCount=0,newCount=0,backend=False):
 c=dict(kind=kind,args=[],writes=[wp(SC+0x24,oldCount),wp(SC+0x28,OLD),wp(SC+0x110,BACK if backend else 0),wp(BACK+0x6c,newCount),wp(BACK+0x70,NEW),patch(HANDLE,b'\xa7'*12)])
 for i in range(64):c['writes'] += [patch(NAMES+i*32,fixed(('Sprite%02d'%i).encode())),wp(OLD+i*76+68,NAMES+i*32),wp(NEW+i*208+180,NAMES+i*32)]
 return c
rng=random.Random(20261013014);cases=[]
for back in [False,True]:
 for old in [-1,0,1,3,7,63]:
  for new in [-1,0,1,3,7,63]:
   c=seed('count',old,new,back);c['args']=[SC];cases.append(c)
   for index in [-1,0,1,2,7,62,63]:c=seed('build',old,new,back);c['args']=[HANDLE,SC,index];cases.append(c)
for scene in [0,SC]:
 c=seed('build',1,1,True);c['args']=[HANDLE,scene,0];cases.append(c)
for h in [0,HANDLE]:
 for scene in [0,SC]:
  for old in [0,OLD]:
   for new in [0,NEW]:
    for kind in ['valid','name']:
     c=seed(kind,1,1,True);c['args']=[h];c['writes'] += [wp(HANDLE,scene),wp(HANDLE+4,old),wp(HANDLE+8,new)];cases.append(c)
# Aliased destination writes preserve native sequencing, including live table-base reloads.
for back in [False,True]:
 for dst in [SC,SC+0x20,SC+0x24,SC+0x28,SC+0x108,BACK+0x68,BACK+0x6c,BACK+0x70]:
  c=seed('build',3,3,back);c['args']=[dst,SC,0];cases.append(c)
for back in [False,True]:
 for size in [0,1,2,4,16,63]:
  for query in [b'',b'Sprite00',b'Sprite01',b'Sprite62',b'sprite00',b'NULL instance',b'NULL_instance',b'ABCDEFGHIJKLMNOP-tail',b'missing']:
   c=seed('find',size,size,back);c['args']=[QUERY,SC];c['writes'].append(patch(QUERY,fixed(query)));cases.append(c)
for j in range(450):
 size=rng.randrange(0,64);back=bool(j%2);c=seed('find',size,size,back);q=rng.randrange(64);c['args']=[QUERY,SC if j%7 else 0];c['writes'].append(patch(QUERY,fixed(('Sprite%02d'%q).encode())))
 if size and j%3==0:
  first=rng.randrange(size);c['writes'].append(wp((NEW+first*208+180) if back else (OLD+first*76+68),NAMES+q*32))
 cases.append(c)
for namebytes in [b'ABCDEFGHIJKLMNOP',b'CaseSensitive',b'NULL instance',b'\x80RawName',b'A\0junk',b'NULL instanceZ']:
 for back in [False,True]:
  c=seed('find',3,3,back);c['args']=[QUERY,SC];c['writes'] += [patch(QUERY,fixed(namebytes)),patch(NAMES+32,fixed(namebytes)),patch(NAMES+64,fixed(namebytes))];cases.append(c)
# A zero backend table base makes the first proxy invalid; do not dereference its name.
c=seed('find',0,1,True);c['args']=[QUERY,SC];c['writes'] += [patch(QUERY,fixed(b'missing')),wp(BACK+0x70,0)];cases.append(c)
counts={};from unicorn import UC_HOOK_CODE
def observe(uc,a,z,data):counts[hex(a)]=counts.get(hex(a),0)+1
for a in [0x6488e0,0x5da840,0x5da860,0x5cfac0,0x5cfa50,0x4f2130]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
entries=dict(find=0x6488e0,count=0x5da840,build=0x5da860,valid=0x5cfac0,name=0x5cfa50);rows=[];fails=[];start=time.time()
for index,c in enumerate(cases):
 m=Image(c);n.write(D,m.data);actual=n.call(entries[c['kind']],c['args'],count=3000000)
 result=None
 if c['kind']=='build':build(m,*c['args'])
 elif c['kind']=='find':result=U(find(m,*c['args']))
 else:result=U(globals()[c['kind']](m,*c['args']))
 observed=dict(sha256=hashlib.sha256(n.read(D,0x20000)).hexdigest(),result=actual if result is not None else None)
 prediction=dict(sha256=m.digest(),result=result)
 if observed!=prediction:fails.append(dict(case=index,kind=c['kind'],observed=observed,prediction=prediction));print(json.dumps(fails[-1]));break
 c['expected']=observed;rows.append(c)
report=dict(binarySha256=n.sha256,cases=len(rows),mismatches=len(fails),entryCalls=counts,seconds=round(time.time()-start,3),failures=fails)
(B/'reports/world-phase14-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fails:(B/'reports/world-phase14-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=0) for a,z in REGIONS],specialNameB64=base64.b64encode(n.read(0x8101c4,16)).decode(),cases=rows),separators=(',',':'))+'\n')
print(json.dumps(report));assert not fails
