"""Unmodified secondary volume/mask/cache functions, with exact float stores."""
from pathlib import Path
import importlib.util,json,gzip,struct,hashlib,collections,random,math
B=Path(__file__).resolve().parent.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('secondary_math',B/'tools/animation-skeletal-fixture.py');f=importlib.util.module_from_spec(s);s.loader.exec_module(f);n=f.p.nx.NativeX86();D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
LOW=D;HIGH=D+0x20;CONTEXT=D+0x1000;STRIDE=0x20000;calls=[];cases=[];errors=[];counts=collections.Counter();rng=random.Random(0x5ea6a0)
def sha(b):return hashlib.sha256(b).hexdigest()
def observe(mu,a,z,u):calls.append(hex(a))
for a in [0x5ea6a0,0x5c7050,0x5c6dc0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def distance(p,q):
 value=((f.W(p[0])*f.W(q[0])+f.W(p[1])*f.W(q[1]))+f.W(p[2])*f.W(q[2])).store();assert math.isfinite(value)
 value=(f.W(value)+f.W(q[3])).store();assert math.isfinite(value);return value
corners=[(0,0,0),(0,1,0),(1,1,0),(1,0,0),(0,0,1),(0,1,1),(1,1,1),(1,0,1)]
def volume(planes,low,high):return int(all(any(distance([high[i]if pick[i]else low[i]for i in range(3)],plane)>0 for pick in corners)for plane in planes))
def mask(volumes,low,high):
 out=0
 for i,p in enumerate(volumes):
  if volume(p,low,high):out|=1<<(i&31)
 return out

def context(at,volumes):
 n.write(at,bytes(max(0x720,len(volumes)*0x380)))
 for i,planes in enumerate(volumes):
  assert len(planes)<=12
  for j,p in enumerate(planes):n.pack('<4f',at+i*0x380+0x1a0+j*16,*p)
  n.pack('<I',at+i*0x380+0x260,len(planes))
 n.pack('<I',at+0x710,len(volumes))
def encoded(c):return [[[f.bits(x)for x in p]for p in planes]for planes in c]
def direct(kind,volumes,low,high,label):
 context(CONTEXT,volumes);n.pack('<3f',LOW,*low);n.pack('<3f',HIGH,*high);before=sha(n.read(D,0x20000));calls.clear()
 if kind=='volume':got=n.call(0x5c6dc0,[LOW,HIGH,0],regs={UC_X86_REG_ECX:CONTEXT})&255;expected=volume(volumes[0],low,high);trace=['0x5c6dc0']
 else:got=n.call(0x5c7050,[LOW,HIGH],regs={UC_X86_REG_ECX:CONTEXT},count=5000000);expected=mask(volumes,low,high);trace=['0x5c7050']+['0x5c6dc0']*len(volumes)
 after=sha(n.read(D,0x20000));assert before==after
 if got!=expected or calls!=trace:errors.append(dict(kind=kind,label=label,native=got,expected=expected,trace=calls.copy()));raise AssertionError(errors[-1])
 cases.append(dict(kind=kind,label=label,contexts=[encoded(volumes)],low=[f.bits(x)for x in low],high=[f.bits(x)for x in high],native=got));counts[kind]+=1

def cache(contexts,low,high,count,flag,refresh,initial,label,poison=False):
 for i,c in enumerate(contexts):context(CONTEXT+i*STRIDE,c)
 for i in range(count):n.pack('<I',0x96d9d0+i*4,0xdeadbeef if poison else CONTEXT+(i%len(contexts))*STRIDE)
 if low:n.pack('<3f',LOW,*low)
 if high:n.pack('<3f',HIGH,*high)
 n.pack('<I',0x966384,count);n.pack('<I',0x9715a0,flag);n.pack('<'+'I'*len(initial),0x96e550,*initial);before=sha(n.read(D,0x80000));calls.clear()
 got=n.call(0x5ea6a0,[LOW if low else 0xdead1111,HIGH if high else 0xdead2222,refresh&0xffffffff],count=10000000);actualFlag=n.unpack('<I',0x9715a0)[0];actual=list(n.unpack('<'+'I'*len(initial),0x96e550));expected=initial.copy();trace=['0x5ea6a0'];outflag=flag
 if refresh==0 and flag!=0:want=int(any(0<x<0x80000000 for x in initial[:count]))
 else:
  for i in range(count):
   c=contexts[i%len(contexts)];expected[i]=mask(c,low,high);trace+=['0x5c7050']+['0x5c6dc0']*len(c)
  want=int(any(0<x<0x80000000 for x in expected[:count]));outflag=1
 assert before==sha(n.read(D,0x80000))
 if (got,actualFlag,actual,calls)!=(want,outflag,expected,trace):errors.append(dict(label=label,native=[got,actualFlag,actual,calls.copy()],expected=[want,outflag,expected,trace]));raise AssertionError(errors[-1])
 cases.append(dict(kind='cache',label=label,contexts=[encoded(c)for c in contexts],low=[f.bits(x)for x in low],high=[f.bits(x)for x in high],count=count,flag=flag,refresh=refresh,initial=initial,native=got,nativeFlag=actualFlag,nativeMasks=actual,poisonContexts=poison));counts['cache']+=1;counts['cached']+=int(refresh==0 and flag!=0);counts['recomputed']+=int(refresh!=0 or flag==0)

# Reuse only authored plane/vertex data, not the prior portal predicate result.
portalPath='reports/geometry-portal-predicate-fixtures.json';portals=json.loads((B/portalPath).read_text())['portals'];worlds=json.loads((R/'geometry-portal-native-validation.json').read_text())['worldClipSets'];sources=[]
for i,p in enumerate(portals):
 low=[min(v[k]for v in p['vertices'])for k in range(3)];high=[max(v[k]for v in p['vertices'])for k in range(3)];plane=p['plane'];sets=[[],[plane],[[-x for x in plane]],worlds[i%len(worlds)]['planes'],[plane]+worlds[(i+1)%len(worlds)]['planes']]
 for j,planes in enumerate(sets):direct('volume',[planes],low,high,dict(source=p['source'],portal=p['index'],set=j))
 direct('mask',sets,high,low,dict(source=p['source'],portal=p['index'],set='reversed-endpoints-mask'))
 sources.append(dict(source=p['source'],portal=p['index']))
for i in range(512):
 low=[f.f32(rng.uniform(-1e4,1e4))for _ in range(3)];high=[f.f32(rng.uniform(-1e4,1e4))for _ in range(3)];planes=[[f.f32(rng.uniform(-10,10))for _ in range(4)]for _ in range(i%13)]
 direct('volume',[planes],low,high,dict(random=i))
# Point boxes expose the two float stores:1+2^-24 rounds to1 before adding-1.
values=[0.,-0.,2**-149,-2**-149,2**-126,-2**-126,1.,-1.,f.f32(1+2**-23),f.f32(1-2**-24),2**24,-2**24]
for i,x in enumerate(values):
 for j,y in enumerate(values):
  point=[x,y,0.];planes=[[1.,2**-24,0.,-x]];direct('volume',[planes],point,point,dict(rounding=[i,j]))
for count in [0,1,2,3,7,15,30,31,32,33,63,64,65,127,128]:
 for kind in range(4):
  vols=[[]if kind==0 or kind==1 and i==31 or kind==2 and i%3==0 else [[0.,0.,0.,-1.]]for i in range(count)]
  direct('mask',vols,[0.,0.,0.],[1.,1.,1.],dict(maskCount=count,pattern=kind))
contexts=[[],[[]],[[[0.,0.,0.,0.]]],[[]]*32]
for count in [0,1,2,3,4,8,32,128]:
 for flag in [0,1,0xffffffff,0x80000000]:
  for refresh in [0,1,-1,0x7fffffff]:
   initial=[rng.choice([0,1,0x7fffffff,0x80000000,0x80000001,0xffffffff])for _ in range(count+8)]
   cache(contexts,[0.,-0.,-2.],[1.,2.,3.],count,flag,refresh,initial,dict(count=count,flag=flag,refresh=refresh),poison=refresh==0 and flag!=0)
# Cached signed masks independently of computed volume layout.
for value in [0,1,0x7fffffff,0x80000000,0x80000001,0xffffffff]:
 for flag in [1,0x80000000,0xffffffff]:cache([],[],[],1,flag,0,[value,0xa5a5a5a5],dict(signedCache=value,flag=flag),poison=True)
fp=R/'animation-secondary-visibility-native-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')).encode(),mtime=0))
report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),authoredPortals=len(portals),mismatches=len(errors),examples=errors,fixture=dict(path=fp.relative_to(B).as_posix(),bytes=fp.stat().st_size,sha256=sha(fp.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in [portalPath,'reports/geometry-portal-native-validation.json','tools/animation-skeletal-fixture.py']],method='Unmodified5ea6a0/5c7050/5c6dc0 execute with no replacements. Compare boolean AL or full mask/EAX, shared flag, complete mask arrays including guards, exact nested-call order and unchanged persistent input memory. Plane model uses 64-significand intermediates and two separatefloat32 stores.',limits=['Finite endpoints/planes and finite stored arithmetic;0..12 planes per volume,0..128 volumes/contexts, valid disjoint records and nonnegative counts.','Authored portal planes/vertex bounds are input probes, not evidence of shipped secondary-volume construction.','No dynamic shadow packet generation or GPU behavior; managed replay compiled separately, execution pending.'])
(R/'animation-secondary-visibility-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not errors
