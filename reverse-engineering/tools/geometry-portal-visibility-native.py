"""Original room-to-instance visibility propagation, with unmodified geometry predicates."""
import importlib.util,json,struct,hashlib,random,itertools,gzip,math
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
def module(name,path):
 s=importlib.util.spec_from_file_location(name,P/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=module('nx','native-x86.py');x87=module('x87','animation-x87.py');n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
scene=n.DATA;display=scene+0x1000;room=scene+0x2000;members=scene+0x3000;context=scene+0x6000;planeMemory=scene+0x6100
boxMemory=scene+0x10000;sphereMemory=scene+0x40000;flagsMemory=scene+0x55000;overrideMemory=scene+0x58000;legacyMemory=scene+0x60000
BITS=0x280a2f0;SIZE=625;f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0];dot=lambda p,q:x87.dot3_plus_constant(*q,*p)
def sphere(c,r,planes,eye):
 allInside=True
 for p in planes+[eye]:
  d=dot(p,c)
  if d < -r:return 0
  if not r<d:allInside=False
 return 1 if allInside else 2
def center_box(c,e,planes):
 return int(all(dot(p,c)>=-dot([abs(p[0]),abs(p[1]),abs(p[2]),0.],e)for p in planes))
def minmax_box(lo,hi,planes):
 vertices=list(itertools.product(*zip(lo,hi)));partial=False
 for p in planes:
  inside=sum(dot(p,v)>=0 for v in vertices)
  if not inside:return 0
  if inside!=8:partial=True
 return 2 if partial else 1
def bit(b,i):return bool(b[i>>3]&(1<<(i&7)))
def setbit(b,i):b[i>>3]|=1<<(i&7)
def propagate(ids,before,overrides,flags,modern,boxes,spheres,planes,eye):
 out=bytearray(before)
 for i in ids:
  if bit(out,i):continue
  accept=bit(overrides,i)
  if not accept:
   if modern:
    if not flags[i]&1:continue
    accept=bool(flags[i]&8)or bool(center_box(*boxes[i],planes))
   else:
    if flags[i]&8:accept=True
    else:
     s=sphere(*spheres[i],planes,eye);accept=s==1 or(s==2 and minmax_box(*boxes[i],planes)!=0)
  if accept:setbit(out,i)
 return bytes(out)
def setup(ids,boxes,spheres,flags,overrides,modern,planes,eye,before):
 n.write(scene,b'\0'*0x2000);n.pack('<I',scene+0x110,display);n.pack('<2I',scene+0xf8,sphereMemory,boxMemory);n.pack('<I',display+0x48,flagsMemory);n.pack('<I',display+0x74,0x4000 if modern else 0);n.pack('<I',display+0x88,overrideMemory)
 n.write(room,b'\0'*24);n.pack('<I',room,members);n.pack('<h',room+12,len(ids))
 for i,v in enumerate(ids):
  if not 0<=v<5000 or v>=len(boxes):raise ValueError('Invalid authored instance reference')
  n.pack('<h',members+2*i,v)
 n.write(flagsMemory,bytes(flags));n.write(overrideMemory,bytes(overrides));n.write(BITS,before+b'0123456789ABCDEF')
 for i,(a,b)in enumerate(boxes):n.pack('<4f4f',boxMemory+32*i,*a,0.,*b,0.)
 if spheres:
  for i,(c,r)in enumerate(spheres):n.pack('<4f',sphereMemory+16*i,*c,r)
 n.write(context,b'\0'*160);n.pack('<I',context+0x80,planeMemory);n.pack('<h',context+0x9c,len(planes))
 for i,p in enumerate(planes):n.pack('<4f',planeMemory+16*i,*p)
 n.pack('<4f',0x963f78,*eye)
counts={'authoredPropagation':0,'syntheticPropagation':0,'spherePredicate':0,'minMaxPredicate':0,'centerExtentPredicate':0,'initializationAndUnclippedRoom':0};errors=[];digest=hashlib.sha256();functionHits={}
def observe(mu,a,size,_):functionHits[hex(a)]=functionHits.get(hex(a),0)+1
for a in [0x5d94a0,0x5d9580,0x5d9770]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def compare(kind,actual,expected,meta):
 counts[kind]+=1;digest.update(str((actual,expected)).encode())
 if actual!=expected and len(errors)<30:errors.append({'kind':kind,'context':meta,'native':actual,'expected':expected})
fr=json.loads((R/'geometry-clipping-native-validation.json').read_text());clipSets=[]
for ci in [0,4,8]:
 fixture=fr['planeFixtures'][ci];matrix=struct.unpack('<84f',bytes.fromhex(fixture['blockHex']))[:16];camera=fixture['camera']['matrix'];normal=camera[8:11];position=camera[12:15]
 clipSets.append({'planes':[[matrix[k],matrix[k+4],matrix[k+8],matrix[k+12]]for k in range(4)],'cameraPlane':normal+[-dot(normal+[0.],position)],'sourceCameraFixture':ci})
clipSets.append({'planes':[],'cameraPlane':[0.,0.,1.,0.],'sourceCameraFixture':None})
rows=[r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']if r['rooms']];sources=[];fixtures=[];referenced=0
for row in rows:
 data=json.loads((B/row['report']).read_text());runtime=json.loads((B/'exports/geometry/scene-runtime'/(row['source']+'.json')).read_text())['renderState'];bounds=data['bounds'];boxes=[(b['center'],b['extent'])for b in bounds];originalFlags=[i['flags']for i in runtime['instances']];originalOverrides=bytearray(SIZE)
 for i in runtime['instances']:
  if i['portalVisibilityOverride']:setbit(originalOverrides,i['index'])
 bn=next(c for c in data['chunks']if c['tag']=='BNDS')
 with (B/'extracted'/row['source']).open('rb')as f:f.seek(bn['payload']);boundsFlags,boundsCount=struct.unpack('<II',f.read(8))
 if boundsFlags!=0x80000001 or not runtime['flagsWord']&0x4000 or boundsCount!=len(boxes):raise ValueError('Unexpected authored bounds mode')
 sources.append({'source':row['source'],'sha256':row['sha256'],'bounds':len(boxes),'rooms':len(data['portalData']['rooms']),'boundsFlags':boundsFlags,'displayFlags':runtime['flagsWord']})
 for ri,r in enumerate(data['portalData']['rooms']):
  ids=r['instanceIndices'];referenced+=len(ids)
  for ci,clip in enumerate(clipSets):
   for mode in range(4):
    flags=originalFlags if mode==0 else [1 if mode==1 else 0 if mode==2 else 9 for i in boxes]
    override=originalOverrides if mode==0 else bytes([0x55])*SIZE if mode==2 else bytes(SIZE)
    before=bytes([0x24])*SIZE if mode==3 else bytes(SIZE)
    setup(ids,boxes,[],flags,override,True,clip['planes'],clip['cameraPlane'],before)
    n.call(0x600d00,[scene,room,context],count=2000000);actual=n.read(BITS,SIZE);expected=propagate(ids,before,override,flags,True,boxes,[],clip['planes'],clip['cameraPlane'])
    meta={'source':row['source'],'room':ri,'clipSet':ci,'mode':mode};compare('authoredPropagation',actual.hex(),expected.hex(),meta)
    if n.read(BITS+SIZE,16)!=b'0123456789ABCDEF':raise ValueError('Visibility buffer overrun')
    fixtures.append({**meta,'nativeBitsSHA256':hashlib.sha256(actual).hexdigest(),'newlyVisible':[i for i in set(ids)if bit(actual,i)and not bit(before,i)]})
 print('authored',len(sources),'room propagation',counts['authoredPropagation'],'errors',len(errors),flush=True)

# Synthetic alternate sphere/min-max branch; source PORT files all use modern
# center/extent mode. Byte flags, overrides and preexisting visibility are real.
rng=random.Random(0x600d00)
for case in range(1000):
 count=16;ids=rng.choices(range(count),k=rng.randrange(25));boxes=[];spheres=[]
 for i in range(count):
  c=[f32(rng.uniform(-10,10))for _ in range(3)];e=[f32(rng.uniform(0,3))for _ in range(3)];boxes.append(([f32(c[k]-e[k])for k in range(3)],[f32(c[k]+e[k])for k in range(3)]));spheres.append((c,f32(max(e))))
 flags=[rng.choice([0,1,8,9,255])for _ in range(count)];override=bytes([rng.randrange(256)for _ in range(2)])+bytes(SIZE-2);before=bytes([rng.randrange(256)for _ in range(2)])+bytes(SIZE-2);clip=clipSets[case%4]
 setup(ids,boxes,spheres,flags,override,False,clip['planes'],clip['cameraPlane'],before);n.call(0x600d00,[scene,room,context]);actual=n.read(BITS,SIZE);expected=propagate(ids,before,override,flags,False,boxes,spheres,clip['planes'],clip['cameraPlane']);compare('syntheticPropagation',actual.hex(),expected.hex(),{'case':case})

# Explicit tangent and fully-inside/outside geometry boundaries, including tiny
# authored coefficients and no clip planes. Results0/1/2 are preserved distinctly.
for c,e,planes,eye in itertools.product([[0.,0.,0.],[1.,0.,0.],[-1.,0.,0.],[0.,0.,1.]],[[0.,0.,0.],[1.,1.,1.],[.1,.2,.3]],[[],[[1.,0.,0.,0.]],[[1.,0.,0.,1.],[-1.,0.,0.,1.]],[[1.3146523088626138e-16,0.,-1.,0.]]],[[0.,0.,1.,0.],[0.,0.,1.,1.]]):
 e=list(map(f32,e));lo=[f32(c[i]-e[i])for i in range(3)];hi=[f32(c[i]+e[i])for i in range(3)];radius=max(e);setup([],[(c,e)],[(c,radius)],[1],bytes(SIZE),True,planes,eye,bytes(SIZE))
 actual=n.call(0x5d94a0,[sphereMemory,context])&255;compare('spherePredicate',actual,sphere(c,radius,planes,eye),{'center':c,'radius':radius,'planes':planes,'eye':eye})
 actual=n.call(0x5d9770,[boxMemory,boxMemory+16,context]);compare('centerExtentPredicate',actual,center_box(c,e,planes),{'center':c,'extent':e,'planes':planes})
 n.pack('<3f',boxMemory,*lo);n.pack('<3f',boxMemory+16,*hi);actual=n.call(0x5d9580,[boxMemory,boxMemory+16,planeMemory,len(planes)])&255;compare('minMaxPredicate',actual,minmax_box(lo,hi,planes),{'min':lo,'max':hi,'planes':planes})

# Verify fixed625-byte modern buffers and original legacy80-byte-instance flags.
for modern,count in itertools.product([False,True],[0,1,8,127,5000]):
 n.write(scene,b'\0'*0x2000);n.pack('<I',scene+0x110,display if modern else 0);n.pack('<II',scene+0x1c,count,legacyMemory)
 original=[rng.getrandbits(32)for _ in range(count)];initial=bytes([0xa5])*SIZE
 for address,enabled in [(0x600c60,True),(0x600cb0,False)]:
  n.write(BITS,initial+b'0123456789ABCDEF')
  for i,v in enumerate(original):n.pack('<I',legacyMemory+80*i+0x44,v)
  n.call(address,[scene],count=2000000);actual=n.read(BITS,SIZE).hex()if modern else[n.unpack('<I',legacyMemory+80*i+0x44)[0]for i in range(count)];expected=(bytes([255 if enabled else 0])*SIZE).hex()if modern else[(v|4)if enabled else(v&~4)for v in original];compare('initializationAndUnclippedRoom',actual,expected,{'function':hex(address),'modern':modern,'count':count})
  if n.read(BITS+SIZE,16)!=b'0123456789ABCDEF':raise ValueError('Clear/set buffer overrun')
 ids=list(range(0,count,max(1,count//13)));n.pack('<I',room,members);n.pack('<h',room+12,len(ids))
 for i,v in enumerate(ids):n.pack('<h',members+i*2,v)
 n.write(BITS,initial)
 for i,v in enumerate(original):n.pack('<I',legacyMemory+80*i+0x44,v)
 n.call(0x600be0,[room,scene]);expected=bytearray(initial)
 for i in ids:setbit(expected,i)
 actual=n.read(BITS,SIZE).hex()if modern else[n.unpack('<I',legacyMemory+80*i+0x44)[0]for i in range(count)];expected=expected.hex()if modern else[v|4 if i in ids else v for i,v in enumerate(original)];compare('initializationAndUnclippedRoom',actual,expected,{'function':'0x600be0','modern':modern,'count':count})
 n.pack('<I',scene+0x13c,0);n.call(0x600bd0,[scene]);compare('initializationAndUnclippedRoom',n.unpack('<I',scene+0x13c)[0],BITS,{'function':'0x600bd0'})

report={'schema':'original-portal-room-visibility-v1','binarySHA256':n.sha256,'passed':not errors,'counts':counts,'sources':sources,'authoredRoomMemberships':referenced,'nativePredicateCalls':functionHits,'errors':errors,'resultSHA256':digest.hexdigest(),'clipSets':clipSets,'fixtureFile':'geometry-portal-visibility-fixtures.json.gz','floatingPointModel':{'nativeControlWord':'0x037f','source':'tools/animation-x87.py'},'nativeFunctions':['0x600bd0','0x600be0','0x600c60','0x600cb0','0x600d00','0x5d94a0','0x5d9580','0x5d9770'],'limits':['All tested functions and their geometry math execute original instructions; entry hooks only count calls, with no result replacement.','All60 authored PORT scenes use BNDS0x80000001 and display flag0x4000; alternate sphere/min-max path uses explicit synthetic fixtures.','Visibility buffer is the original fixed625bytes/5000bits; valid instance IDs0..4999 only.','Clipped room propagation requires a nonnull display scene; legacy clear/set/unclipped branches are verified separately.','Prepared clip volumes are fixtures, not yet recovered child-volume construction or recursive traversal.','Compiled managed equivalence remains pending ordinary execution.']}
(R/'geometry-portal-visibility-native-validation.json').write_text(json.dumps(report,indent=2,allow_nan=False)+'\n')
with gzip.open(R/'geometry-portal-visibility-fixtures.json.gz','wt',encoding='utf8')as f:json.dump({'schema':'compact-authored-portal-visibility-fixtures-v1','sources':sources,'clipSets':clipSets,'cases':fixtures},f,separators=(',',':'),allow_nan=False)
print(json.dumps({k:report[k]for k in ['passed','counts','authoredRoomMemberships','nativePredicateCalls','errors']},indent=2))
if errors:raise SystemExit(1)
