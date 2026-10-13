"""Actual character -> secondary visibility -> shadow queue composition."""
from pathlib import Path
import ast,json,gzip,struct,hashlib,collections
B=Path(__file__).resolve().parent.parent;R=B/'reports';path=B/'tools/animation-character-pipeline-verify.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.For)and isinstance(node.target,ast.Tuple)and any(isinstance(x,ast.Name)and x.id=='ri'for x in node.target.elts):break
 if isinstance(node,ast.For)and isinstance(node.target,ast.Name)and node.target.id=='a':continue
 nodes.append(node)
p={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),p)
n=p['n'];f=p['f'];D=n.DATA;layer=p['layer'];rigs=p['rigs'];CONTEXT=D+0x90000;calls=[];cases=[];counts=collections.Counter()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP

def observe(mu,address,size,user):
 if address in [0x5c7050,0x5c6dc0]:calls.append(hex(address));return
 if address==0x5ea6a0:
  calls.append(hex(address));sp=mu.reg_read(UC_X86_REG_ESP);low,high,mode=n.unpack('<3I',sp+4);p['events'].append(dict(kind='secondary',low=list(n.unpack('<3I',low)),high=list(n.unpack('<3I',high)),mode=mode));return
 beforeFlag=n.unpack('<I',0x9715a0)[0];p['observe'](mu,address,size,user)
 if address in [0x5f9fa0,0x5f0f00]:p['events'][-1]['secondaryFlag']=beforeFlag
 if address==0x5f0f00:n.pack('<I',0x9715a0,[0,0xffffffff,1][p['events'][-1]['handle']%3])
for a in [0x5da980,0x5ea6a0,0x5c7050,0x5c6dc0,0x5f9fa0,0x5f0f00]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)

accepted=[[[0.,0.,0.,1.]]];rejected=[[[0.,0.,0.,0.]]];mixed=[[[0.,0.,0.,1.]],[[0.,0.,0.,-1.]]]
def prepare(c):
 contexts=c['secondary']['contexts']
 for i,volumes in enumerate(contexts):
  at=CONTEXT+i*0x1000;n.write(at,bytes(0x1000));n.pack('<I',at+0x710,len(volumes))
  for j,planes in enumerate(volumes):
   n.pack('<I',at+j*0x380+0x260,len(planes))
   for k,plane in enumerate(planes):n.pack('<4f',at+j*0x380+0x1a0+k*16,*plane)
  n.pack('<I',0x96d9d0+i*4,at)
 n.pack('<'+'I'*len(c['secondary']['initial']),0x96e550,*c['secondary']['initial'])

def check(ri,mode):
 r=rigs[ri];c=layer['context'](r,mode%3);c.update(center=False,camera=[f.f32(.1),1000.,0.,1.,.75,1],view=f.IDENTITY.copy(),cached=1 if mode==2 else 0,secondaryCount=0 if mode==3 else 1 if mode==1 else 3,mutateShadowSequence=bool(mode&1));c['shadow']=dict(count=279 if mode==2 else 0,sequence=0xfffffffe,flag=0xa5a5a5a5,enabled=1,mode=1,submissionEnabled=1,parameters=[0x12345678,0x81234567,0xabcdef01,0x807f0102],distances=[f.bits(-0.),f.bits(100.)],suppress=0)
 contexts=[rejected]if mode==1 else[accepted,rejected,mixed];initial=[0x80000000,0xa5a5a5a5,0xffffffff,0x12345678,0xdeadbeef];c['secondary']=dict(contexts=contexts,initial=initial)
 c['secondaryResult']=0 if mode in [1,3]else 1;prepare(c);calls.clear();got=p['original'](ri,c);got['masks']=list(n.unpack('<'+'I'*len(initial),0x96e550));got['secondaryCalls']=calls.copy()
 want=p['model'](ri,c);flag=1 if c['secondaryCount']>0 else 0xa5a5a5a5
 for e in want['events']:
  if e['kind']in ['attachments','submit']:e['secondaryFlag']=flag
  if e['kind']=='submit':flag=[0,0xffffffff,1][e['handle']%3]
 masks=initial.copy();trace=[]
 if c['secondaryCount']>0:
  trace.append('0x5ea6a0')
  for i in range(c['secondaryCount']):masks[i]=0 if contexts[i]==rejected else 1;trace+=['0x5c7050']+['0x5c6dc0']*len(contexts[i])
 want['masks']=masks;want['secondaryCalls']=trace
 assert got==want,dict(rig=ri,mode=mode,fields=[k for k in got if got[k]!=want[k]],native=got,expected=want)
 cases.append(dict(rig=ri,mode=mode,state=c,native=got));counts['cases']+=1;counts['authored'if'path'in r['source']else'synthetic']+=1;counts['draws']+=sum(e['kind']=='submit'for e in got['events']);counts['secondaryCalls']+=len(trace)>0;counts['mode'+str(mode)]+=1
for ri,r in enumerate(rigs):
 for mode in range(4):check(ri,mode)
 if (ri+1)%100==0:print('character secondary rigs',ri+1,flush=True)
payload=[]
for r in rigs:payload.append(dict(r,joints=[[f.bits(v)for v in m]for m in r['joints']],inverse=[[f.bits(v)for v in m]for m in r['inverse']],minimum=[f.bits(v)for v in r['minimum']],maximum=[f.bits(v)for v in r['maximum']]))
for c in cases:
 for key in ['world','view']:c['state'][key]=[f.bits(v)for v in c['state'][key]]
 c['state']['camera']=[f.bits(v)for v in c['state']['camera'][:-1]]+[c['state']['camera'][-1]]
 c['state']['secondary']['contexts']=[[[[f.bits(v)for v in plane]for plane in volume]for volume in context]for context in c['state']['secondary']['contexts']]
fp=R/'animation-character-secondary-native-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,arena=p['ARENA'],arenaSize=p['ARENA_SIZE'],beforeMatrix=[f.bits(v)for v in p['beforeMatrix']],beforeFar=[f.bits(v)for v in p['beforeFar']],rigs=payload,cases=cases),separators=(',',':')).encode(),mtime=0))
report=dict(binarySha256=n.sha256,d3dx=layer['dll'],comparisons=len(cases),counts=dict(counts),mismatches=0,fixture=dict(path=fp.relative_to(B).as_posix(),bytes=fp.stat().st_size,sha256=p['sha'](fp.read_bytes())),dependency=dict(path=str(path.relative_to(B)),sha256=p['sha'](path.read_bytes())),method='Original5f4ff0 invokes actual5ea6a0/5c7050/5c6dc0 and shadow queue/matrix routines. Only dynamic5f0f00 remains a bounded return/allocator/shadow-sequence/submission-flag adapter. Compare full queue/arena, masks and guards, ordered flag observations, output flags/cursor/cache and original nested predicate calls.',limits=['All688 authored rigs plus100 synthetic rigs, four branch states each; finite disjoint scalar/matrix domain.','Plane/cached-volume production is controlled fixture data, not a claim of authored secondary scene loading.','Dynamic5f0f00/shadow draw packets are external to this composition; real normal draw composition is proven separately by CharacterPacketPipeline.','Managed replay compiled only; no game or generated executable launched.'])
(R/'animation-character-secondary-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
