"""Original character layer submission with explicit cull/render boundaries."""
from pathlib import Path
import importlib.util,json,struct,hashlib,gzip,random,collections,itertools
B=Path(__file__).resolve().parent.parent
s=importlib.util.spec_from_file_location('layer_matrices',B/'tools/animation-skeletal-fixture.py');f=importlib.util.module_from_spec(s);s.loader.exec_module(f);n=f.p.nx.NativeX86();dll=f.load_original_d3dx(n);D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_EAX
H=D;WORLD=D+0x1000;JOINTS=D+0x2000;INVERSE=D+0x7000;LAYERS=D+0xc000;ARRAYS=D+0x10000;HANDLES=D+0x40000;MAP=D+0x50000;WEIGHTS=D+0x51000;CONTROL=D+0x52000;ARENA=0x30000000;ARENA_SIZE=0x200000;OUT=D+0x60000
n.mu.mem_map(ARENA,ARENA_SIZE);rng=random.Random(0x5f4ff0);events=[];calls=[];case=None;rig=None;identities={};errors=[];counts=collections.Counter();rigs=[];cases=[]
def sha(b):return hashlib.sha256(b).hexdigest()
def packrows(rows):return b''.join(struct.pack('<16f',*r)for r in rows)
def multiply(a,b):
 out=f.multiply(a,b)
 for r in range(4):
  for c in range(4):
   k=r*4+c
   if out[k]==0:out[k]= -0. if (((a[r*4]*b[c]+a[r*4+1]*b[c+4])+a[r*4+2]*b[c+8])+a[r*4+3]*b[c+12])<0 or struct.pack('<d',((a[r*4]*b[c]+a[r*4+1]*b[c+4])+a[r*4+2]*b[c+8])+a[r*4+3]*b[c+12])[-1]&128 else 0.
 return out
def point(p,m):
 out=[]
 for i in range(3):
  v=(((f.W(p[0])*f.W(m[i])+f.W(p[1])*f.W(m[4+i]))+f.W(p[2])*f.W(m[8+i]))+f.W(m[12+i])).store()
  if v==0:v=-0. if struct.pack('<d',((p[0]*m[i]+p[1]*m[4+i])+p[2]*m[8+i])+m[12+i])[-1]&128 else 0.
  out.append(v)
 return out
def ret(mu,value):
 sp=mu.reg_read(UC_X86_REG_ESP);mu.reg_write(UC_X86_REG_EAX,value&0xffffffff);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0])
def observe(mu,a,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);calls.append(a)
 if a==0x5da980:events.append(dict(kind='visibility'));ret(mu,case['resolved'])
 elif a==0x5ea6a0:
  low,high,mode=n.unpack('<3I',sp+4);events.append(dict(kind='secondary',low=list(n.unpack('<3I',low)),high=list(n.unpack('<3I',high)),mode=mode));ret(mu,case['secondaryResult'])
 elif a==0x5f9fa0:events.append(dict(kind='attachments',visible=n.unpack('<i',0x806ccc)[0]))
 elif a==0x5f0f00:
  handle,matrix,mode,skin,morph=n.unpack('<5I',sp+4);h=identities[handle];events.append(dict(kind='submit',handle=h['identity'],mode=mode,transformSha256=sha(n.read(matrix,64)),skinAddress=skin,skinSha256=sha(n.read(skin,len(rig['joints'])*64))if skin else None,morph=morph,visible=n.unpack('<i',0x806ccc)[0]));n.pack('<I',CONTROL,n.unpack('<I',CONTROL)[0]+(h['identity']%3)*16 if case['allocation']else n.unpack('<I',CONTROL)[0]);ret(mu,h['return'])
for address in[0x5f4ff0,0x5da980,0x5b30a0,0x5ea6a0,0x5f9fa0,0x5c0500,0x5c0350,0x5f0f00]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
def setup(r,c):
 global identities,case,rig
 rig=r;case=c;identities={};n.write(H,bytes(0x80000));n.write(ARENA,b'\xa5'*ARENA_SIZE);n.pack('<16f',WORLD,*c['world']);n.write(JOINTS,packrows(r['joints']));n.write(INVERSE,packrows(r['inverse']));n.pack('<I',H+0x168,len(r['joints']));n.pack('<I',H+0x174,INVERSE);n.pack('<II',H+0x190,len(r['layers']),LAYERS);n.pack('<3f',H+0x1ac,*r['minimum']);n.pack('<3f',H+0x1b8,*r['maximum']);pointer=ARRAYS;handleMap={}
 def handle(h):
  if h is None:return 0
  key=h['identity']
  if key not in handleMap:
   p=HANDLES+len(handleMap)*12;handleMap[key]=p;identities[p]=h;n.pack('<3I',p,h['scene'],0,h['display'])
  return handleMap[key]
 for i,layer in enumerate(r['layers']):
  for key,off in[('rigid',4),('alternateRigid',12)]:
   rows=layer[key]
   if rows is not None:
    n.pack('<I',LAYERS+20*i+off,pointer)
    for h in rows:n.pack('<I',pointer,handle(h));pointer+=4
  for key,off in[('smooth',8),('alternateSmooth',16)]:n.pack('<I',LAYERS+20*i+off,handle(layer[key]))
 assert pointer<HANDLES
 if c['map']is not None:n.pack('<'+'h'*len(c['map']),MAP,*c['map'])
 if c['morph']is not None:n.pack('<'+'I'*len(c['morph']),WEIGHTS,*c['morph'])
 n.pack('<I',0x9736e0,CONTROL);n.pack('<I',CONTROL,c['cursor']);n.pack('<i',0x806ccc,c['cached']);n.pack('<i',0x966384,c['secondaryCount']);n.pack('<I',0x9715a0,0xa5a5a5a5);n.write(0x8264c4,b'\0');calls.clear();events.clear()
def original(r,c):
 setup(r,c);result=n.call(0x5f4ff0,[H,WORLD,c['count']&0xffffffff,MAP if c['map']is not None else 0,JOINTS,WEIGHTS if c['morph']is not None else 0,0xdeadbeef],count=20000000);end=n.unpack('<I',CONTROL)[0];assert ARENA<=end<=ARENA+ARENA_SIZE
 return dict(result=result,cached=n.unpack('<i',0x806ccc)[0],flag=n.unpack('<I',0x9715a0)[0],cursor=end,arenaSha256=sha(n.read(ARENA,end-ARENA)),calls=calls.copy(),events=events.copy())
def model(r,c):
 ev=[];trace=[0x5f4ff0];visible=c['cached'];cursor=c['cursor'];arena=bytearray(b'\xa5'*ARENA_SIZE);flags=0
 if visible==-1:trace.append(0x5da980);ev.append(dict(kind='visibility'));visible=c['resolved']
 secondary=0
 if c['secondaryCount']>0:trace.extend([0x5b30a0,0x5b30a0,0x5ea6a0]);ev.append(dict(kind='secondary',low=[f.bits(x)for x in point(r['minimum'],c['world'])],high=[f.bits(x)for x in point(r['maximum'],c['world'])],mode=1));secondary=c['secondaryResult']
 if visible!=0 or secondary!=0:
  trace.append(0x5f9fa0);ev.append(dict(kind='attachments',visible=visible));ids=[0]if c['map']is None and c['count']>0 else[]if c['count']<=0 else c['map'][:c['count']]
  def submit(h,matrix,mode,paletteAddress=0,palette=None,morph=0):
   nonlocal flags,cursor
   if h is not None and h['scene']and h['display']:
    trace.append(0x5f0f00);flags|=h['return'];ev.append(dict(kind='submit',handle=h['identity'],mode=mode,transformSha256=sha(packrows([matrix])),skinAddress=paletteAddress,skinSha256=sha(packrows(palette))if paletteAddress else None,morph=morph,visible=visible));cursor+=(h['identity']%3)*16 if c['allocation']else 0
  for ordinal,index in enumerate(ids):
   if index<0 or index>=len(r['layers']):continue
   layer=r['layers'][index];smooth=layer['smooth']is not None or layer['alternateSmooth']is not None;paletteAddress=0
   if smooth:paletteAddress=(cursor+127)&~127;cursor=paletteAddress+len(r['joints'])*64
   morph=0 if c['morph']is None else c['morph'][ordinal]
   for group in['rigid','alternateRigid']:
    if layer[group]is not None:
     for j,h in enumerate(layer[group]):
      if h is not None:trace.append(0x5c0500);submit(h,multiply(r['joints'][j],c['world']),0)
   if smooth:
    trace.append(0x5c0350);palette=[multiply(a,b)for a,b in zip(r['inverse'],r['joints'])];raw=packrows(palette);arena[paletteAddress-ARENA:paletteAddress-ARENA+len(raw)]=raw;submit(layer['smooth'],c['world'],2,paletteAddress,palette,morph);submit(layer['alternateSmooth'],c['world'],2,paletteAddress,palette,morph)
 return dict(result=flags,cached=c['cached'],flag=0,cursor=cursor,arenaSha256=sha(arena[:cursor-ARENA]),calls=trace,events=ev)
def check(kind,ri,c):
 want=model(rigs[ri],c);got=original(rigs[ri],c);counts[kind]+=1
 if want!=got:
  counts['mismatches']+=1
  if len(errors)<10:errors.append(dict(rig=ri,state=c,expected=want,native=got))
 cases.append(dict(kind=kind,rig=ri,state=c,native=got))
def context(r,mode=0):
 world=[0.,1.,0.,0.,-1.,0.,0.,0.,0.,0.,1.,0.,1.25,-2.5,4.75,1.];ids=list(range(len(r['layers'])));selected=ids if mode%3==0 else None if mode%3==1 else[-1]+list(reversed(ids))+[len(ids),0,0];count=len(selected)if selected is not None else 9
 if not r['layers']:selected=[];count=0
 return dict(world=world,map=selected,count=count,morph=None if mode==1 else[0x11000000+i*16 for i in range(max(count,1))],cached=[1,-1,0][mode%3],resolved=1,secondaryCount=1 if mode%3==2 else mode%2,secondaryResult=1,cursor=ARENA+mode%128,allocation=mode%3==2)
def synthetic(seed):
 jointCount=seed%9;layerCount=seed%6
 def matrix():return[f.f32(rng.uniform(-3,3))for _ in range(16)]
 def handle(index):return None if index%5==0 else dict(identity=seed*1000+index+1,scene=0 if index%7==0 else 1,display=0 if index%11==0 else 2,**{'return':1<<(index%31)})
 layers=[]
 for i in range(layerCount):layers.append(dict(rigid=None if i%3==0 else[handle(i*100+j)for j in range(jointCount)],alternateRigid=None if i%2==0 else[handle(i*100+j+20)for j in range(jointCount)],smooth=handle(i*100+51),alternateSmooth=handle(i*100+61)))
 return dict(source={'synthetic':seed},joints=[matrix()for _ in range(jointCount)],inverse=[matrix()for _ in range(jointCount)],minimum=[-1.,-2.,-3.],maximum=[1.,2.,3.],layers=layers)
for seed in range(100):
 r=synthetic(seed);ri=len(rigs);rigs.append(r)
 for mode in range(9):
  c=context(r,mode)
  if mode==3:c.update(cached=0,secondaryCount=0)
  if mode==4:c.update(cached=-1,resolved=0,secondaryCount=0)
  if mode==5:c.update(cached=-1,resolved=-2,secondaryCount=1,secondaryResult=0)
  if mode==6:c.update(count=0)
  if mode==7:c.update(count=-2)
  if mode==8:c.update(cached=0,secondaryCount=1,secondaryResult=0)
  check('synthetic',ri,c)
inventory=json.loads((B/'reports/animation-export.json').read_text())['success'];authored=0
for row in inventory:
 if row['format']!='GHG-PC-hierarchy':continue
 decoded=json.loads((B/row['output']).read_text());raw=(B/'extracted'/row['path']).read_bytes();assert sha(raw)==row['sha256'];joints=[];inverse=[];h=decoded['offsets']['header']
 for i,joint in enumerate(decoded['joints']):
  local=list(struct.unpack_from('<16f',raw,decoded['offsets']['bind']+i*64));joints.append(local if joint['parent']is None else multiply(local,joints[joint['parent']]));inverse.append(list(struct.unpack_from('<16f',raw,decoded['offsets']['inverse']+i*64)))
 def handle(v):return None if v is None else dict(identity=v['handle'],scene=v['scene'],display=v['displaySpecial'],**{'return':1<<((v['handle']//12)%31)})
 layers=[dict(rigid=None if l['rigid']is None else[handle(x)for x in l['rigid']],alternateRigid=None if l['alternateRigid']is None else[handle(x)for x in l['alternateRigid']],smooth=handle(l['smooth']),alternateSmooth=handle(l['alternateSmooth']))for l in decoded['renderLayers']];r=dict(source=dict(path=row['path'],sha256=row['sha256']),joints=joints,inverse=inverse,minimum=list(struct.unpack_from('<3f',raw,h+0x1ac)),maximum=list(struct.unpack_from('<3f',raw,h+0x1b8)),layers=layers);ri=len(rigs);rigs.append(r);authored+=1
 for mode in range(3):check('authored',ri,context(r,mode))
 if authored%100==0:print(authored,'authored rigs',counts['mismatches'],'mismatches',flush=True)
# Direct wrapper checks preserve all output matrix bits, independent of renderer.
for ri,r in enumerate(rigs):
 setup(r,context(r));expected=packrows([multiply(a,b)for a,b in zip(r['inverse'],r['joints'])]);n.write(OUT,b'\xa5'*max(64,len(expected)));n.call(0x5c0350,[OUT,INVERSE,JOINTS,len(r['joints'])],count=2000000);got=sha(n.read(OUT,len(expected)));want=sha(expected);counts['skinWrapper']+=1
 if got!=want:counts['mismatches']+=1;errors.append(dict(kind='skinWrapper',rig=ri,expected=want,native=got))
 cases.append(dict(kind='skinWrapper',rig=ri,native=got))
 if r['joints']:
  n.call(0x5c0500,[OUT,JOINTS,WORLD],count=100000);got=sha(n.read(OUT,64));want=sha(packrows([multiply(r['joints'][0],context(r)['world'])]));counts['rigidWrapper']+=1
  if got!=want:counts['mismatches']+=1;errors.append(dict(kind='rigidWrapper',rig=ri,expected=want,native=got))
  cases.append(dict(kind='rigidWrapper',rig=ri,world=context(r)['world'],native=got))
payload=[]
for r in rigs:payload.append(dict(r,joints=[[f.bits(v)for v in m]for m in r['joints']],inverse=[[f.bits(v)for v in m]for m in r['inverse']],minimum=[f.bits(v)for v in r['minimum']],maximum=[f.bits(v)for v in r['maximum']]))
for c in cases:
 if 'state'in c:c['state']['world']=[f.bits(v)for v in c['state']['world']]
 if 'world'in c:c['world']=[f.bits(v)for v in c['world']]
out=B/'reports/animation-layer-submission-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,arena=ARENA,arenaSize=ARENA_SIZE,rigs=payload,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(binarySha256=n.sha256,d3dx=dll,comparisons=len(cases),counts=dict(counts),mismatches=counts['mismatches'],examples=errors[:10],authoredRigs=authored,fixture=dict(path=out.relative_to(B).as_posix(),bytes=out.stat().st_size,sha256=sha(out.read_bytes())),method='Original5f4ff0,5c0350,5c0500,point transforms and explicitly selected originalD3DX9_35 scalar implementation execute. Visibility5da980/secondary5ea6a0 anddynamic5f0f00 are bounded service callbacks; attachments5f9fa0 executes its original globally disabled branch. Output call order,matrix bits via hashes,palette bytes,arena cursor,visibility state andreturn flags compared. Selected callbacks advance the shared arena cursor, validating reservation before rigid submission and later reads.',limits=['Finite disjoint matrix arrays andvalid layer records; counts0..256.','Visibility anddynamic rendering consumers remain adapters; no fullrender/GPU/shadow equivalence.','Authored bind-world input matrices derive from hash-boundlocal binds with the same explicit scalar policy; clip scheduling is notclaimed.','Callback mutation of hierarchy/jointarrays excluded. Allocator increments are explicit syntheticservice effects, not full downstreampacketallocation integration.'])
(B/'reports/animation-layer-submission-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not counts['mismatches']
