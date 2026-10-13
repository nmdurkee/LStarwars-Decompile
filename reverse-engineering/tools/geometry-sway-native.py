"""Original5ec3d0 coefficients and5ec590 matrix mutation, both CRT paths."""
import importlib.util,json,struct,gzip,hashlib,math,random,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def mod(name,path):
 s=importlib.util.spec_from_file_location(name,B/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=mod('sway_native','tools/native-x86.py');x=mod('sway_wide','tools/animation-x87.py');n=nx.NativeX86();D=n.DATA;TABLE=(B/'references/native-animation-sine-table.f32').read_bytes();sine=struct.unpack('<32768f',TABLE);n.write(0x29899a0,TABLE)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];bits=lambda v:struct.unpack('<I',struct.pack('<f',v))[0];val=lambda v:struct.unpack('<f',struct.pack('<I',v))[0]
W=x.wide;mul=x.mul;add=x.add;div=x.div
def store(v,approx):
 out=x.store(v);return math.copysign(0.,approx)if out==0 and approx==0 else out
def angle(phase,negative,sse):
 product=phase*(-10430.3779296875 if negative else 10430.3779296875)
 if not -2**63<product<2**63:raise ValueError('Finite signed64-bit truncation domain exceeded')
 integer=math.trunc(product)
 if sse and not -2**31<=integer<2**31:return 0x80000000
 return integer&0xffffffff
def sample(phase,negative,sse,cosine,trace):
 a=angle(phase,negative,sse);trace.append(a);return sine[(((0x4000-a)&0xffffffff)if cosine else a)>>1&0x7fff]
def coefficients(a,seed,time,amp,rate,sse):
 aa=store(mul(div(W(a),W(65535.)),W(amp)),a/65535.*amp);rr=store(mul(div(W(seed),W(65535.)),W(rate)),seed/65535.*rate)
 state=(seed*0x19660d+0x3c6ef35f)&0xffffffff;r=val((state&0x7fffff)|0x3f800000)-1.;phase0=x.store(add(mul(W(r),W(3.1419999599456787)),mul(W(r),W(3.1419999599456787))));phase=store(add(mul(W(time),W(rr)),W(phase0)),time*rr+phase0);trace=[]
 def scaled(k):return store(mul(W(phase),W(k)),phase*k)
 cy1=sample(scaled(2.299999952316284),True,sse,True,trace);half=store(mul(W(cy1),W(.5)),cy1*.5)
 cy2=sample(scaled(4.400000095367432),True,sse,True,trace);quarter=store(mul(W(cy2),W(.25)),cy2*.25)
 sx1=sample(scaled(2.0999999046325684),False,sse,False,trace);halfs=store(mul(W(sx1),W(.5)),sx1*.5)
 sx2=sample(phase,False,sse,False,trace);sx3=sample(scaled(4.199999809265137),False,sse,False,trace);quarters=store(mul(W(sx3),W(.25)),sx3*.25)
 outx=store(mul(W(aa),add(add(W(halfs),W(sx2)),W(quarters))),aa*((halfs+sx2)+quarters));cy3=sample(scaled(1.100000023841858),True,sse,True,trace);outy=store(mul(add(add(W(cy3),W(half)),W(quarter)),W(aa)),((cy3+half)+quarter)*aa)
 return [outx,outy],trace
def mutate(before,out,source,coeff):
 b=bytearray(before)
 for i in range(16):b[out+i*4:out+i*4+4]=b[source+i*4:source+i*4+4]
 for i in range(4):
  v=[struct.unpack_from('<f',b,source+(i+j)*4)[0]for j in [0,4,8]];z=store(add(add(mul(W(v[0]),W(coeff[0])),W(v[1])),mul(W(v[2]),W(coeff[1]))),(v[0]*coeff[0]+v[1])+v[2]*coeff[1]);struct.pack_into('<f',b,out+(i+4)*4,z)
 return b
angles=[]
for address in [0x5ec45e,0x5ec499,0x5ec4dc,0x5ec4ff,0x5ec526,0x5ec561]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,user:angles.append(mu.reg_read(UC_X86_REG_EAX)),begin=address,end=address)
cases=[];errors=[];counts=collections.Counter();rng=random.Random(0x5ec590)
def execute(kind,a,seed,time,amp,rate,sse,matrix=None,overlap=None,origin=None):
 expected,trace=coefficients(a,seed,time,amp,rate,sse);before=bytearray((i*37+len(cases)*17)&255 for i in range(256));source=32;out=128 if overlap is None else source+overlap
 if matrix is not None:struct.pack_into('<16f',before,source,*matrix)
 n.write(D,before);n.pack('<I',0x97390c,time);n.pack('<f',0x80b6d8,amp);n.pack('<f',0x80b6dc,rate);n.pack('<I',0x29a9c48,int(sse));angles.clear()
 if kind=='coefficients':
  want=bytearray(before);struct.pack_into('<2f',want,0,*expected);n.call(0x5ec3d0,[D,D+4,a,seed])
 else:want=mutate(before,out,source,expected);n.call(0x5ec590,[D+out,D+source,a,seed])
 actual=n.read(D,len(before));counts[kind]+=1;counts['sse'if sse else'x87']+=1
 if actual!=want or angles!=trace:
  counts['mismatches']+=1
  if len(errors)<10:errors.append(dict(kind=kind,args=[a,seed,time,amp,rate,sse],overlap=overlap,offsets=[i for i,(v,w)in enumerate(zip(actual,want))if v!=w][:30],actual=actual.hex(),expected=want.hex(),nativeAngles=angles.copy(),expectedAngles=trace))
 cases.append(dict(kind=kind,a=a,seed=seed,time=time,amplitude=bits(amp),rate=bits(rate),sse=sse,before=bytes(before).hex(),source=source,out=out,nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeAngles=angles.copy(),sourceOrigin=origin))
 if errors:raise AssertionError(errors[:1])
for i in range(1024):
 a=[0,1,-1,32767,-32768,65535,-65535,2147483647,-2147483648][i%9];seed=[0,1,-1,32767,-32768,65535,-65535][i%7];time=[0,1,60,3600,1000000,0x7fffffff,0x80000000,0xffffffff][i%8];amp=[0.,-0.,1.,-1.,.125,8.][i%6];rate=[0.,-0.,1.,-1.,.125,8.][i//8%6]
 for sse in [False,True]:execute('coefficients',a,seed,time,amp,rate,sse)
rows=json.loads((R/'geometry-scene-data-index.json').read_text())['rows'];sources=[];authored=[]
for row in rows:
 data=json.loads((B/row['report']).read_text());specials=data['specialObjects']
 if not specials:continue
 raw=(B/'extracted'/row['source']).read_bytes();selected=[]
 for sp in specials:
  seed,a=struct.unpack_from('<hh',raw,sp['address']+0xc8)
  if a==0:continue
  matrix=list(struct.unpack_from('<16f',raw,sp['address']+64));proof=dict(source=row['source'],sha256=row['sha256'],special=sp['index'],offset=sp['address']);authored.append((a,seed,matrix,proof));selected.append(sp['index'])
 if selected:sources.append(dict(source=row['source'],sha256=hashlib.sha256(raw).hexdigest(),specials=selected));assert sources[-1]['sha256']==row['sha256']
for i,(a,seed,matrix,proof)in enumerate(authored):
 for sse in [False,True]:execute('matrix',a,seed,[0,60,3600,1000000,0xffffffff][i%5],1.,1.,sse,matrix,origin=proof)
 if i%200==0:print('sway authored',i,'errors',len(errors),flush=True)
for i in range(256):
 matrix=[f32(rng.uniform(-8,8))for _ in range(16)]if i>=64 else[-0. if i&(1<<(j%6))else 0. for j in range(16)]
 for overlap in [None,0,4,-4,16,-16]:execute('matrix',rng.randrange(-32768,32768),rng.randrange(-32768,32768),rng.getrandbits(32),1.,1.,bool(i&1),matrix,overlap,dict(synthetic=i,overlap=overlap))
fp=R/'geometry-sway-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(cases=cases,sineTable=dict(file='references/native-animation-sine-table.f32',sha256=hashlib.sha256(TABLE).hexdigest())),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-sway-native-v1',passed=not errors,binarySHA256=n.sha256,counts=dict(counts),authoredSpecials=len(authored),sources=sources,errors=errors,fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Original coefficient/matrix helpers, seeded float RNG, trigonometric lookup and both original CRT float-to-int branches execute unchanged. Observation hooks only.','Finite inputs, coefficient stores and matrix arithmetic; trig products strictly within signed64-bit range. Legacy x87 conversion truncates to64bits then low32 wraps; SSE mode uses signed32 conversion and returns80000000 on overflow.','All nonzero authored special+ca entries across the indexed1477 GSC/GHG carriers, exact source offsets/hashes, plus signed/time/magnitude/zero/overlap fixtures.','Matrix copy uses forward16DWORD copy before row mutation, preserving defined whole and partial aliasing. Undefined/out-of-range memory and GPU output excluded.','No managed/game process launch.'])
(R/'geometry-sway-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k not in ['sources','limits']},indent=2));assert not errors
