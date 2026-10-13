"""Original PC shadow queue producer; all matrix and queue instructions execute."""
from pathlib import Path
import importlib.util,struct,json,gzip,hashlib,random,collections
B=Path(__file__).resolve().parent.parent
s=importlib.util.spec_from_file_location('shadow_matrices',B/'tools/animation-skeletal-fixture.py');f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
n=f.p.nx.NativeX86();dll=f.load_original_d3dx(n);D=n.DATA;H=D;WORLD=D+0x1000;JOINTS=D+0x2000;BINDINGS=D+0x8000;QUEUE=0x9666b0;SIZE=280*104
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
rng=random.Random(0x5f9fa0);calls=[];cases=[];rigs=[];errors=[];counts=collections.Counter();authored=[]
def sha(b):return hashlib.sha256(b).hexdigest()
def matrixbytes(m):return struct.pack('<16f',*m)
def multiply(a,b):
 out=f.multiply(a,b)
 for r in range(4):
  for c in range(4):
   k=r*4+c
   if out[k]==0:
    approximate=((a[r*4]*b[c]+a[r*4+1]*b[c+4])+a[r*4+2]*b[c+8])+a[r*4+3]*b[c+12]
    if approximate==0:out[k]=-0. if struct.pack('<d',approximate)[-1]&128 else 0.
 return out
def hook(mu,a,size,user):calls.append(a)
for a in[0x5f9fa0,0x5c0500,0x5f9ed0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def common(c):
 n.write(QUEUE,b'\xa5'*SIZE);n.pack('<i',0x973fe8,c['count']);n.pack('<I',0x973fdc,c['sequence']);n.pack('<I',0x9718a4,c['flag']);n.write(0x8264c4,bytes([c['enabled']]));n.pack('<i',0x8264bc,c['mode']);n.pack('<I',0x80babc,c['submissionEnabled']);n.pack('<4I',0x2854bf4,*c['parameters']);n.pack('<2I',0x973fe0,*c['distances']);calls.clear()
def snapshot():return dict(count=n.unpack('<i',0x973fe8)[0],sequence=n.unpack('<I',0x973fdc)[0],flag=n.unpack('<I',0x9718a4)[0],queueSha256=sha(n.read(QUEUE,SIZE)),calls=calls.copy())
def original(ri,c,direct=None):
 common(c)
 if direct is not None:
  n.write(WORLD,bytes.fromhex(direct['matrix']));v=direct['binding'];n.call(0x5f9ed0,[WORLD,v[0],v[3],v[1],v[4],v[2],v[5]],count=100000)
 else:
  r=rigs[ri];n.write(H,bytes(0x1000));n.write(WORLD,matrixbytes(c['world']));n.write(JOINTS,b''.join(matrixbytes(m)for m in r['joints']));n.pack('<I',H+0x19c,BINDINGS if r['bindings']is not None else 0);n.write(H+0x1a0,bytes([c['suppress']]))
  if r['bindings']is not None:n.write(BINDINGS,b''.join(struct.pack('<3I4B',*row)for row in r['bindings']))
  n.call(0x5f9fa0,[H,WORLD,JOINTS],count=5000000)
 return snapshot()
def model(ri,c,direct=None):
 out=bytearray(b'\xa5'*SIZE);count=c['count'];sequence=c['sequence'];flag=c['flag'];trace=[]
 def enqueue(matrix,binding):
  nonlocal count,sequence
  trace.append(0x5f9ed0)
  if count>=280:return
  p=count*104;out[p:p+64]=matrix
  signed=struct.unpack('<b',bytes([c['parameters'][3]>>24]))[0]
  struct.pack_into('<3I3Ii2I4B',out,p+64,*binding[:3],*c['parameters'][:3],signed,*c['distances'],*binding[3:6],sequence&255)
  count+=1;sequence=(sequence+1)&0xffffffff
 if direct is not None:enqueue(bytes.fromhex(direct['matrix']),direct['binding'])
 else:
  trace.append(0x5f9fa0);r=rigs[ri]
  if c['enabled']and c['mode']==1 and r['bindings']is not None and not c['suppress']:
   for v in r['bindings']:
    if v[6]==255:break
    if count<280 and c['submissionEnabled']:
     trace.append(0x5c0500);enqueue(matrixbytes(multiply(r['joints'][v[6]],c['world'])),v);flag=1
 return dict(count=count,sequence=sequence,flag=flag,queueSha256=sha(out),calls=trace)
def check(kind,ri,c,direct=None):
 got=original(ri,c,direct);want=model(ri,c,direct);counts[kind]+=1
 if got!=want:
  counts['mismatches']+=1
  if len(errors)<10:errors.append(dict(kind=kind,rig=ri,state=c,direct=direct,expected=want,native=got))
 row=dict(kind=kind,rig=ri,state=dict(c),native=got)
 if direct is not None:row['direct']=direct
 cases.append(row)
def state(i=0):
 return dict(count=0,sequence=[0,255,0xffffffff,0xfffffffe][i%4],flag=0xa5a5a5a5,enabled=1,mode=1,submissionEnabled=1,parameters=[0x81234567,0xabcdef01,0xff123456,((i%256)<<24)|0x765432],distances=[f.bits(-0. if i%2 else 0.),f.bits(float(i+100))],world=[0.,1.,0.,0.,-1.,0.,0.,0.,0.,0.,1.,0.,1.25,-2.5,4.75,1.],suppress=0)
def scenarios(i):
 out=[]
 for k in range(14):
  c=state(i+k)
  if k==1:c['count']=279
  if k==2:c['count']=278
  if k==3:c['count']=280
  if k==4:c['count']=281
  if k==5:c['enabled']=0
  if k==6:c['mode']=0
  if k==7:c['mode']=-1
  if k==8:c['suppress']=128
  if k==9:c['submissionEnabled']=0
  if k==10:c.update(enabled=128,submissionEnabled=0x80000000)
  if k==11:c.update(count=2147483647)
  if k==12:c['world']=[-0. if(j+i)%2 else 0. for j in range(16)]
  if k==13:c['world']=[f.f32(rng.uniform(-10,10))for _ in range(16)]
  out.append(c)
 return out
for i in range(96):
 jointCount=1+i%12;joints=[[f.f32(rng.uniform(-4,4))for _ in range(16)]for j in range(jointCount)];records=[]
 for k in range(i%19):records.append([rng.getrandbits(32)for _ in range(3)]+[rng.randrange(256)for _ in range(3)]+[k%jointCount])
 records.append([0,0,0,0,0,0,255]);records.append([0,0,0,0,0,0,254]) # Must not read beyond the sentinel.
 if i%13==0:records=None
 ri=len(rigs);rigs.append(dict(source={'synthetic':i},joints=joints,bindings=records))
 for c in scenarios(i):check('synthetic',ri,c)
for row in json.loads((B/'reports/animation-export.json').read_text())['success']:
 if row['format']!='GHG-PC-hierarchy':continue
 raw=(B/'extracted'/row['path']).read_bytes();assert sha(raw)==row['sha256'];decoded=json.loads((B/row['output']).read_text());h=decoded['offsets']['header'];u=lambda p:struct.unpack_from('<I',raw,p)[0];si=lambda p:struct.unpack_from('<i',raw,p)[0];rel=lambda p:0 if si(p)==0 else p+si(p)
 nu=u(0)+4;pn=rel(nu+24);relocations={rel(pn+4+i*4)for i in range(u(pn))};records=None;p=rel(h+0x19c);proof=[];start=p
 if p:
  assert h+0x19c in relocations;records=[]
  while True:
   assert 0<=p<=len(raw)-16
   v=list(struct.unpack_from('<3I4B',raw,p))
   if v[6]==255:records.append(v);break
   assert v[6]<decoded['jointCount'];resolved=[];ranges=[]
   for k,stride in[(0,48),(1,64),(2,8)]:
    field=p+k*4;assert field in relocations;offset=rel(field)
    # The third consumer repeatedly reads one 8-byte pair, rather than advancing by count.
    size=(v[3+k]*stride if k<2 else 8)if offset else 0
    assert not offset or 0<=offset<=len(raw)-size
    resolved.append(offset);ranges.append(dict(offset=offset,bytes=size,sha256=sha(raw[offset:offset+size])if offset else None))
   proof.append(dict(sourceOffset=p,serialized=v,resolvedPointers=resolved,payloads=ranges));records.append(resolved+v[3:]);p+=16
   assert len(records)<10000
  counts['authoredBoundRigs']+=1;counts['authoredGroups']+=len(proof)
 joints=[]
 for i,joint in enumerate(decoded['joints']):
  local=list(struct.unpack_from('<16f',raw,decoded['offsets']['bind']+i*64));joints.append(local if joint['parent']is None else multiply(local,joints[joint['parent']]))
 ri=len(rigs);rigs.append(dict(source=dict(path=row['path'],sha256=row['sha256']),joints=joints,bindings=records));authored.append(dict(path=row['path'],sha256=row['sha256'],header=h,bindingOffset=start,suppress=raw[h+0x1a0],jointCount=decoded['jointCount'],records=proof,terminatorOffset=p if start else None))
 for c in scenarios(ri)[:12]:check('authored',ri,c)
 if len(authored)%100==0:print(len(authored),'authored rigs;',counts['mismatches'],'mismatches',flush=True)
for i in range(768):
 c=state(i);c['count']=[0,1,137,279,280,281,2147483647][i%7];c['parameters']=[rng.getrandbits(32),rng.getrandbits(32),rng.getrandbits(32),(i%256)<<24|rng.getrandbits(24)];c['distances']=[f.bits(f.f32(rng.uniform(-10000,10000))),[0,0x80000000,1,0x80000001,0x7f7fffff,0xff7fffff][i%6]]
 matrix=struct.pack('<16I',*[rng.getrandbits(32)for _ in range(16)]);direct=dict(matrix=matrix.hex(),binding=[rng.getrandbits(32)for _ in range(3)]+[rng.randrange(256)for _ in range(4)]);check('direct',None,c,direct)
payload=[]
for r in rigs:payload.append(dict(r,joints=[[f.bits(x)for x in m]for m in r['joints']]))
for c in cases:c['state']['world']=[f.bits(x)for x in c['state']['world']]
fixture=B/'reports/animation-shadow-queue-native-fixtures.json.gz';fixture.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,rigs=payload,cases=cases),separators=(',',':')).encode(),mtime=0))
assetPath=B/'reports/animation-shadow-queue-bindings.json';assetPath.write_text(json.dumps(dict(rigs=len(authored),nonemptyRigs=counts['authoredBoundRigs'],groups=counts['authoredGroups'],entries=authored),indent=2)+'\n')
report=dict(binarySha256=n.sha256,d3dx=dll,comparisons=len(cases),counts=dict(counts),mismatches=counts['mismatches'],examples=errors,fixture=dict(path=fixture.relative_to(B).as_posix(),bytes=fixture.stat().st_size,sha256=sha(fixture.read_bytes())),authoredBindings=dict(path=assetPath.relative_to(B).as_posix(),sha256=sha(assetPath.read_bytes())),method='Original 5f9fa0 and 5f9ed0 execute unchanged, including original 5c0500 and explicitly selected original D3DX9_35 scalar matrix body. Observation-only hooks record call order. Compare entire 29,120-byte queue, count, sequence and submission flag. No computational callbacks replaced.',limits=['Nonnegative queue count; finite joint/world arithmetic and float metadata. Direct matrix copy accepts arbitrary 64-bit-pattern bytes without arithmetic.','Disjoint source and queue storage; valid terminated bindings. Invalid source pointers, missing sentinel and allocation failures are excluded.','Authored pointer fields are proven PNTR relocations and normalized to source offsets; this queue does not dereference them. Full shadow-volume generation, GPU submission and renderer timing remain outside this scope.','Authored matrices are bind-world matrices prepared with explicit scalar arithmetic, not runtime clip scheduling.'])
(B/'reports/animation-shadow-queue-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k not in['d3dx','limits','method']},indent=2));assert counts['mismatches']==0
