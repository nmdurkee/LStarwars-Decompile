import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;SCENE=D+0x1000;VOLUMES=D+0x2000;LISTS=D+0x4000;POINT=D+0x6000;PLANES=D+0x8000;SIDES=D+0x18000
REGIONS=[(D,0x40000,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];signed16=rot['signed16']
class Image(rot['Image']):
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
visited=[]
def distance(im,plane,point):
 x=N.word(im.W(plane))*N.word(im.W(point));y=N.word(im.W(plane+4))*N.word(im.W(point+4));z=N.word(im.W(plane+8))*N.word(im.W(point+8));return F(((y+x)+z+N.word(im.W(plane+12))).store())
def contains(im,volume,point):
 visited.append([volume,point]);count=im.B(volume+14)
 if not count:return 1
 planes=im.W(volume+4)
 for i in range(count):
  if distance(im,planes+i*16,point)>0:return 0
 return 1
def select(im,scene,point):
 if not scene or not point:return 65535
 a=b=matched=0;count=S(im.W(scene+0x74))
 vol=lambda i:U(im.W(scene+0x78)+signed16(i)*24)
 for i in range(max(0,count)):
  if not contains(im,vol(i),point):continue
  va,vb=vol(a),vol(b)
  if matched==2:
   if im.B(va+0x14)<im.B(vb+0x14):a=i
   else:b=i
  if matched==0:a=i
  elif matched==1:b=i
  matched+=1;assert matched<=6
  if matched==2 and not(im.B(va+0x10)&1) and not(im.B(vb+0x10)&1):break
 if not matched:return 65535
 if matched==1:return a&65535
 va=vol(a);na=im.B(va+15)
 if not na:return 65535
 lista=im.W(va+8);vb=vol(b);nb=im.B(vb+15)
 for i in range(na):
  plane=im.H(lista+i*2)
  if not any(plane==im.H(im.W(vb+8)+j*2) for j in range(nb)):continue
  pp=U(im.W(scene+0x70)+signed16(plane)*32);return im.H(pp+(0x16 if distance(im,pp,point)<0 else 0x18))
 return 65535
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX
entries={};actualvisited=[]
def observe(uc,a,z,user):
 if a in [0x5d92b0,0x5d9220,0x5d9290,0x5c12e0]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a==0x5d9220:actualvisited.append([uc.reg_read(UC_X86_REG_EAX),uc.reg_read(UC_X86_REG_ECX)])
n.mu.hook_add(UC_HOOK_CODE,observe)
def plane(a,values):return patch(a,struct.pack('<4f',*values))
def seed(matching=[True,True],flags=None,priorities=None,lists=None):
 flags=[0]*len(matching) if flags is None else flags;priorities=[0]*len(matching) if priorities is None else priorities;lists=[[0] for _ in matching] if lists is None else lists
 c=dict(kind='query',scene=SCENE,point=POINT,volume=VOLUMES,writes=[word(SCENE+0x74,len(matching)),word(SCENE+0x78,VOLUMES),word(SCENE+0x70,SIDES),patch(POINT,struct.pack('<3f',0.5,0,-0.0)),plane(SIDES,[1,0,0,0]),patch(SIDES+0x16,struct.pack('<HH',2222,5555))])
 for i,match in enumerate(matching):
  v=VOLUMES+i*24;l=LISTS+i*512;c['writes'] += [word(v+4,PLANES+i*16),word(v+8,l),patch(v+14,bytes([1,len(lists[i])])),patch(v+0x10,bytes([flags[i]])),patch(v+0x14,bytes([priorities[i]])),plane(PLANES+i*16,[0,0,0,-1 if match else 1]),patch(l,struct.pack('<'+'H'*len(lists[i]),*lists[i]))]
 return c
cases=[]
for flags in [[0,0],[0,1],[1,0],[1,1]]:
 for masks in [[False,False],[True,False],[False,True],[True,True]]:
  for value in [-1,-0.0,0,1]:
   c=seed(masks,flags);c['writes'].append(patch(POINT,struct.pack('<3f',value,0,0)));cases.append(c)
for count in [-2147483648,-2,-1,0,1,2,31,127,255]:
 c=seed([False]*max(2,count));c['writes'].append(word(SCENE+0x74,count));cases.append(c)
for scene,point in [(0,POINT),(SCENE,0),(0,0)]:c=seed();c.update(scene=scene,point=point);cases.append(c)
for matching in [[True]*i for i in range(3,7)]+[[False,True,True,True],[False,False,True,True,True]]:
 for p in [[0,0],[1,2],[2,1],[255,0],[0,255],[255,255]]:
  c=seed(matching,[1]*len(matching),(p+[9]*len(matching))[:len(matching)]);cases.append(c)
for first in [[],[0],[1],[0,1],[1,0],[65535,0],[5,5,0],list(range(255))]:
 for second in [[],[0],[1],[1,0],[0,1],[65535,0],[5,0],[255]]:
  c=seed(lists=[first,second]);c['writes'] += [plane(SIDES+32,[0,0,0,-1]),patch(SIDES+32+0x16,struct.pack('<HH',1234,4321)),plane(SIDES-32,[0,0,0,1]),patch(SIDES-32+0x16,struct.pack('<HH',0,65535)),plane(SIDES+5*32,[0,0,0,-1]),patch(SIDES+5*32+0x16,struct.pack('<HH',32768,32767))];cases.append(c)
for planeid in [-32768,-32767,-2,-1,0,1,32767]:
 c=seed(lists=[[planeid&65535],[planeid&65535]]);c['writes'].append(word(SCENE+0x70,U(SIDES-planeid*32)));cases.append(c)
for count in [0,1,2,31,127,255]:
 for failing in [0,max(0,count-1),count]:
  c=seed([True]);c['kind']='contains';c['writes'].append(patch(VOLUMES+14,bytes([count])))
  for i in range(count):c['writes'].append(plane(PLANES+i*16,[0,0,0,1 if i==failing else -1]))
  cases.append(c)
c=seed([True]);c.update(kind='contains',point=0);c['writes'].append(patch(VOLUMES+14,b'\0'));cases.append(c)
rng=random.Random(2026101323)
choices=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0xff7fffff,bits(1),bits(-1),bits(0.125),bits(-3.75),bits(1024)]
for i in range(512):
 c=seed([True]);c['kind']='contains';c['writes'] += [patch(POINT,struct.pack('<3I',*[rng.choice(choices) for _ in range(3)])),patch(PLANES,struct.pack('<4I',*[rng.choice(choices) for _ in range(4)]))];cases.append(c)
for count in [2,3,4,5,6]:
 for k in range(64):
  match=[rng.choice([False,True]) for _ in range(count)];c=seed(match,[rng.randrange(256) for _ in match],[rng.randrange(256) for _ in match],[rng.sample([0,1,2,3],rng.randrange(5)) for _ in match]);
  for j in range(4):c['writes'] += [plane(SIDES+j*32,[rng.choice([-1,0,1]),0,0,rng.choice([-1,0,1])]),patch(SIDES+j*32+0x16,struct.pack('<HH',rng.randrange(65536),rng.randrange(65536)))]
  cases.append(c)
for point in [VOLUMES,LISTS,PLANES,SIDES]:c=seed();c['point']=point;cases.append(c)
for count in [-2147483648,-1,0,1,65535,65536,2147483647]:
 c=seed();c['kind']='count';c['writes'].append(word(SCENE+0x74,count));cases.append(c)
c=seed();c.update(kind='count',scene=0);cases.append(c)
rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 im=Image(c);visited=[];predicted=(im.H(c['scene']+0x74) if c['scene'] else 0) if c['kind']=='count' else contains(im,c['volume'],c['point']) if c['kind']=='contains' else select(im,c['scene'],c['point']);vis=visited.copy();initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 actualvisited=[]
 if c['kind']=='count':actual=n.call(0x5d9290,[c['scene']])&65535
 elif c['kind']=='contains':actual=n.call(0x5d9220,regs={UC_X86_REG_EAX:c['volume'],UC_X86_REG_ECX:c['point']})&65535
 else:actual=n.call(0x5d92b0,[c['scene'],c['point']])&65535
 h=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest();checks+=3
 if actual!=predicted or h!=im.hash() or actualvisited!=vis:errors.append(dict(case=i,actual=actual,model=predicted,nativeVisited=actualvisited,modelVisited=vis,actualHash=h,modelHash=im.hash()));break
 c['expected']=dict(result=actual,sha256=h,visited=actualvisited);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase23-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase23-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
