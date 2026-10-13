"""Original billboard CPU packets and finite camera-facing payloads."""
from pathlib import Path
import importlib.util,struct,json,gzip,hashlib,random,collections,math
B=Path(__file__).resolve().parent.parent
def module(name,path):
 s=importlib.util.spec_from_file_location(name,B/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
f=module('billboard_math','tools/animation-skeletal-fixture.py');x=module('billboard_wide','tools/animation-x87.py');n=f.p.nx.NativeX86();D=n.DATA;SIZE=4096;CONTROL=D;OWNER=D+0x100;TABLE=D+0x200;RECORD=D+0x300;COMMAND=D+0x400;WORLD=D+0x600;RESOURCE=D+0x680;ORIGIN=D+0x690;OUTPUT=D+0x720;ARENA=D+0x800
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDI,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESI
calls=[];cases=[];errors=[];counts=collections.Counter();rng=random.Random(0x603610)
for address in[0x603610,0x5b3b00,0x5c0240,0x5edbb0,0x5edd10,0x5b3920,0x5b3b30,0x5e0490,0x603530,0x603970,0x603ad0,0x5e0530]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:calls.append(a),begin=address,end=address)
def sha(b):return hashlib.sha256(b).hexdigest()
def u(b,p):return struct.unpack_from('<I',b,p-D)[0]
def w(b,p,v):struct.pack_into('<I',b,p-D,v&0xffffffff)
def put(b,p,data):b[p-D:p-D+len(data)]=data
def pack(v):return struct.pack('<'+'f'*len(v),*v)
def zero(v,approx):
 z=v.store()
 return -0. if z==0 and approx==0 and struct.pack('<d',approx)[-1]&128 else z
def squared(v):return((f.W(v[1])*f.W(v[1])+f.W(v[0])*f.W(v[0]))+f.W(v[2])*f.W(v[2])).store()
def store_double(a):
 sig,e=a
 if not sig:return 0.
 sign=0x8000000000000000 if sig<0 else 0;sig=abs(sig);raw=e+1086;q=x.rounded(sig,1<<(11+max(0,1-raw)))
 if raw<=0:bits=sign|q
 else:
  if q==1<<53:q>>=1;raw+=1
  bits=sign|(0x7ff0000000000000 if raw>=2047 else(raw<<52)|(q&0xfffffffffffff))
 return struct.unpack('<d',struct.pack('<Q',bits))[0]
def cross(a,b):return[zero(f.W(a[p])*f.W(b[q])-f.W(a[q])*f.W(b[p]),a[p]*b[q]-a[q]*b[p])for p,q in[(1,2),(2,0),(0,1)]]
def face_camera(view,origin):
 m=[0.]*16;m[15]=1.
 for i in range(3):m[i]=-view[4*i];m[4+i]=view[4*i+1];m[8+i]=-view[4*i+2];m[12+i]=origin[i]
 return m
def face_axis(forward,axis):
 right=cross(forward,axis);length=f.f32(math.sqrt(squared(right)));inverse=0. if length<=0 else(f.W(1)/f.W(length)).store();right=[zero(f.W(inverse)*f.W(v),inverse*v)for v in right];z=cross(right,axis);return right+[0.]+axis+[0.]+z+[0.,0.,0.,0.,1.]
def initial(c):
 b=bytearray(SIZE)
 for i in range(0x800,SIZE):b[i]=(i*37+c['seed']*17)&255
 put(b,WORLD,pack(c['world']));w(b,RESOURCE,c['flags']);put(b,ORIGIN,pack(c['origin']));w(b,CONTROL,ARENA+c['seed']%16);w(b,RECORD,OWNER);w(b,OWNER+0x50,TABLE);w(b,TABLE,0x12345678);w(b,RECORD+0x14,D+0x780);w(b,RECORD+0x18,D+0x7a0);b[COMMAND-D]=0x8f;w(b,COMMAND+4,RESOURCE);put(b,OUTPUT,b'\xa5'*12);return b
def model(c,before):
 b=bytearray(before);kind=c['kind'];trace=[];result=None
 if kind=='resource':return bytes(b),c['resourceValue'],[0x603970]
 if kind=='camera':put(b,ARENA,pack(face_camera(c['view'],c['origin'])));return bytes(b),None,[0x5edbb0]
 if kind=='axis':put(b,ARENA,pack(face_axis(c['forward'],c['origin'])));return bytes(b),None,[0x5edd10,0x5b3920,0x5b3b30,0x5c0240,0x5b3920]
 if kind!='payload':
  if kind=='dispatch':trace.append(0x5e0530)
  trace.extend([0x5e0490,0x603530]);start=(u(b,CONTROL)+15)&~15;w(b,CONTROL,start+48);w(b,u(b,RECORD+0x14)+4,start);w(b,RECORD+0x24,start);tail=start+32;b[tail-D]=0x8d;b[tail-D+1]=1;w(b,tail+4,u(b,RECORD+0x18)+16);w(b,RECORD+0x14,tail)
 trace.extend([0x603610,0x5b3b00,0x5b3b00,0x5b3b00,0x5c0240]);p=(u(b,CONTROL)+3)&~3;put(b,p,pack(c['world']));sy=squared(c['world'][4:7]);sx=squared(c['world'][:3]);sz=squared(c['world'][8:11]);xy=store_double(x.add(x.wide(sx),x.wide(sy)));mean=x.store(x.mul(x.add(x.wide(sz),x.wide(xy)),x.wide(0.3333333432674408)));scale=f.f32(math.sqrt(mean));put(b,p+64,pack([scale]));w(b,CONTROL,p+132)
 if c['flags']==0:facing=face_camera(c['view'],[0.,0.,0.]);trace.append(0x5edbb0)
 else:facing=face_axis(c['forward'],c['world'][4:7]);trace.extend([0x5edd10,0x5b3920,0x5b3b30,0x5c0240,0x5b3920])
 put(b,p+68,pack(facing))
 if kind=='payload':result=p
 else:
  first=u(b,RECORD+0x24);b[first-D]=0x90;b[first-D+1]=3;w(b,first+4,p);w(b,OUTPUT,first);second=first+16;b[second-D]=0x8f;b[second-D+1]=3;w(b,second+4,RESOURCE);w(b,RECORD+0x24,second+16);w(b,OUTPUT+4,second);trace.extend([0x603970,0x603ad0]);alpha=f.value(c['alpha']);w(b,p+60,0 if alpha<0 else 0x3f800000 if alpha>1 else c['alpha'])
 return bytes(b),result,trace
def check(c):
 before=initial(c);expected,result,trace=model(c,before);n.write(D,before);n.pack('<I',0x9736e0,CONTROL);n.pack('<16f',0x80b708,*c['view']);n.pack('<3f',0x973708,*c['forward']);calls.clear();kind=c['kind']
 if kind=='payload':actualResult=n.call(0x603610,[CONTROL,WORLD,0x12345678,RESOURCE])
 elif kind=='camera':actualResult=n.call(0x5edbb0,[ARENA,ORIGIN])
 elif kind=='axis':actualResult=n.call(0x5edd10,[ARENA,ORIGIN])
 elif kind=='resource':actualResult=n.call(0x603970,[CONTROL,c['resourceValue'],WORLD])
 elif kind=='writer':actualResult=n.call(0x5e0490,[COMMAND,WORLD,c['alpha']],regs={UC_X86_REG_EAX:RECORD,UC_X86_REG_EDI:OUTPUT})
 else:actualResult=n.call(0x5e0530,[D+0x100,2,OUTPUT,0xdead0001,0xdead0002,0xdead0003,c['alpha'],0x80000000],regs={UC_X86_REG_ECX:COMMAND,UC_X86_REG_EDX:WORLD,UC_X86_REG_ESI:RECORD})
 actual=n.read(D,SIZE);counts[kind]+=1
 if actual!=expected or calls!=trace or(result is not None and actualResult!=result):
  counts['mismatches']+=1
  if len(errors)<10:errors.append(dict(case=c,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:24],nativeCalls=calls.copy(),expectedCalls=trace,nativeResult=actualResult,expectedResult=result))
 cases.append(dict(c,nativeSha256=sha(actual),nativeResult=actualResult if result is not None else None,calls=calls.copy()))
def case(seed,world,flags,kind,source):return dict(seed=seed,world=world,flags=flags,kind=kind,source=source,view=[0.,0.,-1.,0.,0.,1.,0.,0.,1.,0.,0.,0.,4.,5.,6.,1.],forward=[f.f32(-.5),f.f32(.25),1.],origin=[f.f32(1.25),f.f32(-2.5),f.f32(3.75)],alpha=[0,0x80000000,0xbf800000,0x3e800000,0x3f800000,0x40000000][seed%6])
authored=[]
for row in json.loads((B/'reports/geometry-scene-data-index.json').read_text())['rows']:
 if not row.get('billboards'):continue
 raw=(B/'extracted'/row['source']).read_bytes();assert sha(raw)==row['sha256'];data=json.loads((B/row['report']).read_text())
 for resource in data['billboards']:
  commands={c['index']for c in data['commands']if c.get('billboard')==resource['index']};models={m['index']for m in data['models']if any(p['command']in commands for p in m['parts'])};specials=[sp for sp in data['specialObjects']if sp['model']in models];sp=specials[0]if specials else None;world=list(struct.unpack_from('<16f',raw,sp['address']+64))if sp else f.IDENTITY.copy();flags=struct.unpack_from('<I',raw,resource['address'])[0];proof=dict(path=row['source'],sha256=row['sha256'],resource=resource['address'],resourceSha256=sha(raw[resource['address']:resource['address']+16]),special=None if sp is None else sp['address'],transformChoice='first actual model-associated special'if sp else'identity fallback; no associated special');authored.append(proof)
  for kind in['payload','writer','dispatch']:check(case(len(authored),world,flags,kind,proof))
 if len(authored)%100<row['billboards']:print(len(authored),'authored resources;',counts['mismatches'],'mismatches',flush=True)
for i in range(256):
 world=[f.f32(rng.uniform(-5,5))for _ in range(16)]
 if i<64:world=[-0. if i&(1<<(j%6))else 0. for j in range(16)]
 for kind in['payload','writer','dispatch']:
  c=case(2000+i,world,[0,1,2,0xffffffff][i%4],kind,dict(synthetic=i))
  if i%5==0:c['forward']=world[4:7]
  check(c)
for i in range(128):
 c=case(i,f.IDENTITY.copy(),0,'camera',dict(helper=i));c['view']=[f.f32(rng.uniform(-3,3))for _ in range(16)];c['origin']=[-0. if i%7==0 else f.f32(rng.uniform(-3,3))for _ in range(3)];check(c);c=dict(c,kind='axis');check(c)
for i in range(64):c=case(i,f.IDENTITY.copy(),0,'resource',dict(identity=i));c['resourceValue']=rng.getrandbits(32);check(c)
for c in cases:
 for key in['world','view','forward','origin']:c[key]=[f.bits(v)for v in c[key]]
out=B/'reports/animation-billboard-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,base=D,size=SIZE,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),mismatches=counts['mismatches'],examples=errors,authoredCarriers=len({r['path']for r in authored}),authoredResources=len(authored),associatedTransformCount=sum(r['special']is not None for r in authored),fixture=dict(path=out.relative_to(B).as_posix(),bytes=out.stat().st_size,sha256=sha(out.read_bytes())),method='Original603610,5edbb0,5edd10,603970,5e0490 and billboard5e0530 path execute unchanged, including original CRT square root and all vector helpers. Observation hooks only; full4096-byte state, return pointers and nested calls compared.',limits=['Finite inputs and finite stored intermediates; successful bounded disjoint CPU allocation. SignalingNaNs excluded.','Resource vertex data is not consumed by these CPU helpers. No shader/GPU expansion or final rasterized image claim.','Native dispatcher billboard precedence executes despite invalid skin/morph/cache pointer sentinels, proving those inputs are not dereferenced in this branch.','Storedworld transforms are first actual model-associated special transforms when available, otherwise an explicitly labelled identity fixture. Camera fields are explicit test inputs, not claimed live runtime producers.']);(B/'reports/animation-billboard-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k not in['method','limits']},indent=2));assert not counts['mismatches']
